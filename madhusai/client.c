#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<fcntl.h>

main()
{
	int sockfd,len,i,a;char q[200];
	struct sockaddr_in sa; 
	len=sizeof(sa);
	sockfd = socket(AF_INET,SOCK_STREAM,0); 
	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=inet_addr("127.0.0.1");
	sa.sin_port=6001;
	

	i=connect(sockfd,(struct sockaddr *) &sa,len);
	printf("(%d,%d)\n",sockfd,i);
	
	printf("Give a number for server");
	scanf("%d",&a);
	send(sockfd,&a,4,0);
	

	recv(sockfd,q,50,0);
	printf("server sent %s\n",q);
	

}
