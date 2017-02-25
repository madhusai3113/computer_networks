#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<fcntl.h>

main()
{
	int sockfd,fd,len,i,k,p;char b[200];
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
	recv(fd,&p,4,0);
	printf("client sent %d\n",p);
	
	//sending
	k=2*p;
	send(fd,&k,4,0);
	
}
