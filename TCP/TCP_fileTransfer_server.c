#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
	int sockfd,newsockfd,len_sockfd,portno,clilen;
	struct sockaddr_in serv_addr,cli_addr;
	char buffer[256],buff[1000];
	int n;
	
	/* First call to socket() function */
	sockfd  = socket(AF_INET,SOCK_STREAM,0);
	
	if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }
 	
 	/* Initialize socket structure */
   bzero((char *) &serv_addr, sizeof(serv_addr));
   portno = 5002;
   
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(portno);
   
    /* Now bind the host address using bind() call.*/
   if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
      perror("ERROR on binding");
      exit(1);
   }
   
   
    /* Now start listening for the clients, here process will
      * go in sleep mode and will wait for the incoming connection
   */
   
   listen(sockfd,5);
   clilen = sizeof(cli_addr);
     
     
      /* Accept actual connection from the client */
   newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
	
   if (newsockfd < 0) {
      perror("ERROR on accept");
      exit(1);
   }
   
   /* send a file */

   FILE *fp;
   fp = fopen("test.txt","r");
   fgets(buff, 255, (FILE*)fp);
   printf("%s\n", buff );
   send(newsockfd,buff,1000,0);
   fclose(fp);
   return 0;
   
}
