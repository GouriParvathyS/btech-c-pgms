//cliet
#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<pthread.h>
#include<fcntl.h>

#define WSIZE 2
int sockfd, up = -1, low = 0, g;
void * senddata() {
  char ch = 'd';
  while (1) {
    up++;
    while ((up - low) > WSIZE) {
      printf("congestion.... \n");
      sleep(1);
    }
    printf("Data sent : %d\n", up);
    write(sockfd, & ch, 1);
    write(sockfd, & up, 1);
    sleep(1);
  }
}
void * recvdata() {
  char c;
  char ch = 'd';
  while (1) {
    read(sockfd, & c, 1);
    read(sockfd, & g, 1);
    if (c == 'a') {
      printf("Data acknowledged : %d\n", g);
      low++;
    } else if (c == 'c') {
      printf("Data %d corrupted, sending again\n", g);
      write(sockfd, & ch, 1);
      write(sockfd, & g, 1);
    }
    sleep(1);
  }
}
int main() {
  pthread_t s, r;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = 8888;
  server.sin_addr.s_addr = INADDR_ANY;
  connect(sockfd, (struct sockaddr * ) & server, sizeof(server));
  pthread_create( & s, 0, senddata, 0);
  sleep(1);
  pthread_create( & r, 0, recvdata, 0);
  sleep(1);
  while (1);
}


// server
#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<pthread.h>

int main() {
  int g = 0, p, f = -1;
  char ch, ca = 'a', can = 'c';
  struct sockaddr_in server, client;
  int len = sizeof(client);
  server.sin_family = AF_INET;
  server.sin_port = 8888;
  server.sin_addr.s_addr = INADDR_ANY;

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  bind(sockfd, (struct sockaddr * ) & server, sizeof(server));
  listen(sockfd, 5);
  printf("Server is waiting...... \n");
  int newfd = accept(sockfd, (struct sockaddr * ) & client, & len);

  while (1) {
    read(newfd, & ch, 1);
    read(newfd, & g, 1);
    if (ch == 'd') {
      int k = rand();
      if (k % 3 == 0) {
        printf("Data %d corrupted\n", g);
        write(newfd, & can, 1);
        write(newfd, & g, 1);
        sleep(2);
      } else {
        printf("Data received : %d\n", g);
        write(newfd, & ca, 1);
        write(newfd, & g, 1);
        printf("Data acknowledged : %d\n", g);
        f = g;
        sleep(2);
      }
    }
  }
}

