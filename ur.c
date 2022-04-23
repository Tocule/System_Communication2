#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFLEN 1024
#define LISTENPORT 1234

int main(int argc,char *argv[])
{
  
  if(argc!=2)
  {
	printf("Invalid Arguments\n");
	exit(0);
  }
  
  int sockfd, len, n;
  char buffer[BUFLEN];
  struct sockaddr_in receiverAddr, senderAddr;

  if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
  {
    perror("socket system call failed");
    exit(EXIT_FAILURE);
  }

  memset(&receiverAddr, 0, sizeof(receiverAddr));
  memset(&senderAddr, 0, sizeof(senderAddr));
  short PORTNO=(short)atoi(argv[1]);
  receiverAddr.sin_family = AF_INET;
  receiverAddr.sin_addr.s_addr = INADDR_ANY;
  receiverAddr.sin_port = htons(PORTNO);

  if(bind(sockfd, (const struct sockaddr *)&receiverAddr, sizeof(receiverAddr)) < 0)
  {
    perror("bind syscall failed");
    exit(EXIT_FAILURE);
  }
  len = sizeof(senderAddr);
  n = recvfrom(sockfd, (char *)buffer, BUFLEN, MSG_WAITALL, (struct sockaddr *) &senderAddr, &len);
  buffer[n] = '\0';
  return 0;
}

