#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<fcntl.h>

main()
{
	int sockfd,fd,len,i,k,p[2];int b;
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
	printf("[%d]\n",fd);

	recv(fd,&p,8,0);
	printf("client sent %d and %d\n",p[0],p[1]);
	
	
}
