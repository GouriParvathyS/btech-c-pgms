//client
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<pthread.h>

int sockfd, m, n, s = -1, g = 0;
void * senddata() {
  char ch = 'd';
  while (1) {
    s++;
    write(sockfd, & ch, 1);
    write(sockfd, & s, 1);
    printf("Send data %d\n", s);
    sleep(1);
  }
}

void * receivedata() {
  char ca;
  while (1) {
    n = read(sockfd, & ca, 1);
    m = read(sockfd, & g, 1);
    if (ca == 'a') {
      printf("Ack %d Received\n", g);
      sleep(1);
    } else if (ca == 'c') {
      printf("Sending again\n");
      s = g - 1;
    }
  }
}

main() {
  pthread_t s, r;
  struct sockaddr_in cliaddr;
  cliaddr.sin_family = PF_INET;
  cliaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  cliaddr.sin_port = htons(8084);
  sockfd = socket(PF_INET, SOCK_STREAM, 0);
  connect(sockfd, (struct sockaddr * ) & cliaddr, sizeof(cliaddr));
  printf("Connecting to server	\n");
  pthread_create( & s, 0, senddata, 0);
  sleep(1);
  pthread_create( & r, 0, receivedata, 0);
  sleep(1);
  while (1);

}


//server
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<pthread.h>


main() {
  int sockfd, newsockfd, clilen, g = 0, n, m, p = 0, f = -1, k;
  char ca = 'a', can = 'c', ch;
  struct sockaddr_in serv_addr, cli_addr;
  serv_addr.sin_family = PF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(8084);
  sockfd = socket(PF_INET, SOCK_STREAM, 0);
  bind(sockfd, (struct sockaddr * ) & serv_addr, sizeof(serv_addr));
  listen(sockfd, 5);
  printf("Server is waiting	\n");
  clilen = sizeof(cli_addr);
  newsockfd = accept(sockfd, (struct sockaddr * ) & cli_addr, & clilen);
  while (1) {
    n = read(newsockfd, & ch, 1);
    m = read(newsockfd, & g, 1);
    if (ch = 'd') {
      k = rand();
      if (k % 3 == 0) {
        if (g == f + 1) {
          printf("Data %d Corrupted\n", g);
          write(newsockfd, & can, 1);
          write(newsockfd, & g, 1);
          sleep(2);
        } else {
          printf("Discarded data %d\n", g);
        }
      } else {
        p = f + 1;
        if (g == p) {
          printf("Data %d received\n", g);
          write(newsockfd, & ca, 1);
          write(newsockfd, & g, 1);
          printf("Data %d acknowledged\n", g);
          f = g;
        } else
          printf("Discarded data %d\n", g);

        sleep(2);
      }
    }
  }
}

