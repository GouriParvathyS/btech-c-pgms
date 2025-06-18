#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
void main(){
int server,newsock;
struct sockaddr_in servAddr;
struct sockaddr_storage store;
socklen_t addr_size;
char buffer[1024];


server=socket(AF_INET,SOCK_STREAM,0);

servAddr.sin_family=AF_INET;
servAddr.sin_port=htons(6265);
servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    
    if(bind(server,(struct sockaddr *)&servAddr,sizeof(servAddr))<0){
        printf("Binding failed\n");
        exit(1);
    }
    if(listen(server,5)==0){
        printf("Listening...\n");
    }
    else{
        printf("Error in listening\n");
        exit(1);
    }
    addr_size=sizeof(store);
    newsock=accept(server,(struct sockaddr *)&store,&addr_size);
    while(1){
        memset (buffer ,0 ,sizeof(buffer));
        recv(newsock,buffer,1024,0);
        buffer[strcspn(buffer,"\n")]=0;
        printf("%s\n",buffer);
        if(strcmp(buffer,"exit")==0){
            break;
        }
        memset (buffer ,0 ,sizeof(buffer));
        printf("Server: ");
        fgets(buffer,1024,stdin);
        buffer[strcspn(buffer,"\n")]=0;
        send(newsock,buffer,strlen(buffer),0);
        if(strcmp(buffer,"exit")==0){
            break;
        }

    }
    close(newsock);
    close(server);

}
#include <stdio.h>
#include <stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
void main(){
int client;
struct sockaddr_in servAddr;
socklen_t addr_size;
char buffer[1024];


    client=socket(AF_INET,SOCK_STREAM,0);
    if(client<0){
        printf("Socket creation failed\n");
        exit(1);
    }
    servAddr.sin_family=AF_INET;
    servAddr.sin_port=htons(6265);
    servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    
    connect(client,(struct sockaddr *)&servAddr,sizeof(servAddr))
    while(1){
        memset(buffer,0,sizeof(buffer));
        printf("Client: ");
        fgets(buffer,1024,stdin);
        buffer[strcspn(buffer,"\n")]=0;
        send(client,buffer,strlen(buffer),0);
        if(strcmp(buffer,"exit")==0){
            break;
        }
        memset(buffer,0,sizeof(buffer));
        recv(client,buffer,1024,0);
        buffer[strcspn(buffer,"\n")]=0;     
        printf("%s\n",buffer);
        if(strcmp(buffer,"exit")==0){
            break;
        }
    }
    close(client);

}