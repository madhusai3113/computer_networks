#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<fcntl.h>

main()
{
	int sockfd,fd,len,i,k,p[2];int b,l;
	struct sockaddr_in sa,ca; 
	len=sizeof(sa);
	//standards
	sockfd = socket(AF_INET,SOCK_STREAM,0); 
	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=INADDR_ANY;
	sa.sin_port=999;
	
	//conn
	i=bind(sockfd,(struct sockaddr *) &sa,len);
	printf("(%d,%d)\n",sockfd,i);
	listen(sockfd,5);
	
	fd = accept(sockfd,(struct sockaddr*)&ca,&len);
	
	
	//sending 
	printf("Give two no: to client");
	scanf("%d%d",&p[0],&p[1]);
	send(fd,&p,8,0);
	
	//recieve
	
	recv(fd,&l,8,0);
	printf("client sent %d\n",l);
		
	//sending
	l=2*l;
	send(fd,&l,8,0);
}
