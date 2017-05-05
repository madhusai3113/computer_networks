#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<fcntl.h>

main()
{
char *file[] = {"abc", "def"};
char *ip[] = {"127.0.0.1","127.0.0.1"}; 

	int sockfd,fd,len,i;char b[200],p[100];
	 struct sockaddr_in sa,ca; 
	 len=sizeof(sa);
	 //standards
	sockfd = socket(AF_INET,SOCK_STREAM,0); 
	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=INADDR_ANY;
	sa.sin_port=6001;
	
	//conn
	i=bind(sockfd,(struct sockaddr *) &sa,len);
	printf("(%d,%d)\n",sockfd,i);
	listen(sockfd,5);
	
	//receive
	fd = accept(sockfd,(struct sockaddr*)&ca,&len);
	printf("[%d]\n",fd);
	recv(fd,p,50,0);
	printf("peer wants %s\n",p);
	
		
	if(*p==*file[0]){
	//sending
	printf("\n");
	send(fd,ip[0],50,0);
	}
	else if(p==file[1]){
	//sending
	printf("\n ");
	send(fd,ip[1],50,0);
	}
	else{
	//sending
	printf("\n ");
	send(fd,"file not found",50,0);
	}
	//printf("IP address is: %s\n", inet_ntoa(sa.sin_addr));
	//printf("IP address is: %s\n", inet_ntoa(ca.sin_addr));
	close(sockfd);
}
