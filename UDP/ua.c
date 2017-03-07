#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include<fcntl.h>

int main(){
  int sockfd, length,m,k;
  struct sockaddr_in sa,da,ta;
	length=sizeof(sa);
	 
  /*Create UDP socket*/
  sockfd = socket(AF_INET,SOCK_DGRAM,0);

  /*Configure settings in address struct*/	
	ta.sin_family = AF_INET;
	da.sin_addr.s_addr = inet_addr("127.0.0.1");
 	da.sin_family = AF_INET;
	da.sin_port=6001;

	/*sending a messege */
	
	printf("Give a number to send\n");
	scanf("%d",&m);
	sendto(sockfd,&m,4,0,(struct sockaddr *)&da,length);

	/*receiving a message */

	recvfrom(sockfd,&k,4,0,(struct sockaddr *)&ta,&length);
	printf("\nreceived message :: %d  from port :: %d\n",k,ta.sin_port);
	
}
	
