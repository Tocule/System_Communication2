#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define BUFLEN 1024

int main(int argc,char *argv[])
{ 
  FILE *fp1,*fp2;
  fp1=fopen("ur.c","r");
  fp2=fopen("ut.c","w");
  int sockfd, len, n;
  char buffer[BUFLEN];
  struct sockaddr_in receiverAddr, senderAddr;
   char c;   
   char PORTNO[6];
   long length;  
   char sentence1[50];
   char sentence2[50];
   int choice;
   char message[20];
    if(argc==2)
    {   
	do
	{	
	     printf("***Menu***\n");
	     printf("1.Check Messages\n");
	     printf("2.Send Message\n");
	     printf("3.Exit\n");
	     choice=(int)atoi(argv[1]);
	     switch(choice)
	     {
		     case 1 : 
			      printf("Enter the port no\n");
		 	      scanf("%s",PORTNO);
			      c=fgetc(fp1);
			      while(c!=EOF)
			      {
				 fputc(c,fp2);
	   			 c=fgetc(fp1);
			      }
			      fseek(fp2,1101,SEEK_SET);
                              char sentence1[50]="printf(\"data received: %s\",buffer);";
			      char sentence3[10]="return 0;";
			      char sentence4[5]="}";
			      fprintf(fp2,"%s\n",sentence1);
			      fprintf(fp2,"  %s\n",sentence3);
			      fprintf(fp2,"%s\n",sentence4);
			      rewind(fp2);
			      system("cc ut.c -o ut");
			      execlp("./ut","./ut",PORTNO,NULL);
			      printf("Do you want to Exit Press 3\n");
			      scanf("%d",&choice);
			      break;


		     case 2:
			      printf("Enter the port no\n");
			      scanf("%s",PORTNO);
			      printf("Enter the message\n");
			      scanf("%s",message);
			      printf("Message Sent\n");
			      execlp("./us","./us",PORTNO,message,NULL);
			      break;

		     case 3 : printf("You have Exited\n");
			      break;
	    }

 	}while(choice!=3);
    
    }
    else
    {
	printf("Invalid numer of Arguments\n");
        printf("You need two arguments ./up [option]\n");
	printf("Menu for your reference\n");
	printf("***Menu***\n");
        printf("1.Check Messages\n");
        printf("2.Send Message\n");
        printf("3.Exit\n");
     }
     return 0;
}	

