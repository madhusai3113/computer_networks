#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include<fcntl.h>

int main(){
  int sockfd,i, length_b,a,k;
  struct sockaddr_in sa,da,ta;
  length_b=sizeof(ta);
	 
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
	while(tr<1){
	recvfrom(sockfd,&a,4,0,(struct sockaddr *)&ta,&length_b);
	printf("received %dst message :: %d  from port : : %d\n",tr+1,a,ta.sin_port);
	tr++;
	}
	
	
}
	
