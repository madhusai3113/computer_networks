#include<stdio.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<fcntl.h>

main()
{
int sockfd,i, length_b,k;
char a[50];
  struct sockaddr_in sa,da,ta;
  length_b=sizeof(ta);
	 
  /*Create UDP socket*/
  sockfd = socket(AF_INET,SOCK_DGRAM,0);

  /*Configure settings in address struct*/	
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = INADDR_ANY;
	sa.sin_port=6003;
	
	/*binding */
	i= bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));
	printf("connection established %d,%d\n",sockfd,i);
	

	/*receiving a message */
	printf("ready to recieve......\n");
	recvfrom(sockfd,a,50,0,(struct sockaddr *)&ta,&length_b);
	printf("a file \"%s\" is requested   from port : : %d\n",a,ta.sin_port);
	
		
	/*sending a messege */
	
	
sendto(sockfd,"fuck you ass",50,0,(struct sockaddr *)&ta,sizeof(ta));
	
}
