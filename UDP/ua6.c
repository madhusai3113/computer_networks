#include <stdio.h>
#include <sys/socket.h>	
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include<fcntl.h>

int main(){
  int sockfd, length,m1,m3,m2,k,in1,in2;
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
	int tc=0;
	printf("Give  number to send\n");
	scanf("%d",&in1);
	sendto(sockfd,&in1,4,0,(struct sockaddr *)&da,length);
	scanf("%d",&in2);
	sendto(sockfd,&in2,4,0,(struct sockaddr *)&da,length);
	
}
	
