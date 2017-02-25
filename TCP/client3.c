#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<fcntl.h>

main()
{
	int sockfd,fd,len,i;int q;
	int a[2];
	struct sockaddr_in sa,ca; 
	len=sizeof(sa);
	sockfd = socket(AF_INET,SOCK_STREAM,0); 
	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=inet_addr("127.0.0.1");
	sa.sin_port=999;
	

	i=connect(sockfd,(struct sockaddr *) &sa,len);
	printf("(%d,%d)\n",sockfd,i);
	
	
	
	printf("Give a number for server");
	scanf("%d%d",&a[0],&a[1]);
	send(sockfd,a,8,0);
	

}
