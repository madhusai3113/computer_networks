#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include<fcntl.h>

int main(){
  int sockfd,i, length_b1, length_b2, length_b3,a1,a2,a3,k;
  struct sockaddr_in sa,da,ta1,ta2,ta3;
  length_b1=sizeof(ta1);
  length_b2=sizeof(ta2);
  length_b3=sizeof(ta3);
	 
  /*Create UDP socket*/
  sockfd = socket(AF_INET,SOCK_DGRAM,0);

  /*Configure settings in address struct*/	
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = INADDR_ANY;
	sa.sin_port=6001;
	
	/*binding */
	i= bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));
	printf("connection established %d,%d\n",sockfd,i);
	

	/*receiving a message */
	int tr=0;
	printf("ready to recieve......\n");
	
	recvfrom(sockfd,&a1,4,0,(struct sockaddr *)&ta1,&length_b1);
	printf("received message :: %d  from port : : %d\n",a1,ta1.sin_port);

	recvfrom(sockfd,&a2,4,0,(struct sockaddr *)&ta2,&length_b2);
	printf("received message :: %d  from port : : %d\n",a2,ta2.sin_port);

	recvfrom(sockfd,&a3,4,0,(struct sockaddr *)&ta3,&length_b3);
	printf("received message :: %d  from port : : %d\n",a3,ta3.sin_port);
	
	a1=*a2+*a3;
	printf("%d %d %d\n",a1,a2,a3);
	printf("sending back some message\n");
	sendto(sockfd,&a1,4,0,(struct sockaddr *)&ta1,sizeof(ta1));
	sendto(sockfd,&a2,4,0,(struct sockaddr *)&ta1,sizeof(ta1));
	sendto(sockfd,&a3,4,0,(struct sockaddr *)&ta1,sizeof(ta1));

	sendto(sockfd,&a1,4,0,(struct sockaddr *)&ta2,sizeof(ta2));
	sendto(sockfd,&a2,4,0,(struct sockaddr *)&ta2,sizeof(ta2));
	sendto(sockfd,&a3,4,0,(struct sockaddr *)&ta2,sizeof(ta2));

	sendto(sockfd,&a1,4,0,(struct sockaddr *)&ta3,sizeof(ta3));
	sendto(sockfd,&a2,4,0,(struct sockaddr *)&ta3,sizeof(ta3));
	sendto(sockfd,&a3,4,0,(struct sockaddr *)&ta3,sizeof(ta3));

	
}
	
