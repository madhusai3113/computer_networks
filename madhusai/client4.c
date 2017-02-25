#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<fcntl.h>

main()
{
	int sockfd,fd,len,i;int q[2],l,k;
	
	struct sockaddr_in sa,ca; 
	len=sizeof(sa);
	sockfd = socket(AF_INET,SOCK_STREAM,0); 
	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=inet_addr("127.0.0.1");
	sa.sin_port=999;
	

	i=connect(sockfd,(struct sockaddr *) &sa,len);
	printf("(%d,%d)\n",sockfd,i);
	
	
	
	//recieving
	recv(sockfd,&q,8,0);
	printf("server sent: %d and %d\n",q[0],q[1]);
	
	//sending
	l=q[0]+q[1];
	send(sockfd,&l,8,0);
	
	//recieve
	recv(sockfd,&k,4,0);
	printf("server sent: %d\n",k);

}
