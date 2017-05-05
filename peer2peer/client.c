#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<fcntl.h>





main()
{
	int sockfd,len,i;char q[200];char a[100];
	struct sockaddr_in sa; 
	len=sizeof(sa);
	sockfd = socket(AF_INET,SOCK_STREAM,0); 
	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=inet_addr("127.0.0.1");
	sa.sin_port=6001;
	

	i=connect(sockfd,(struct sockaddr *) &sa,len);
	printf("(%d,%d)\n",sockfd,i);
	
	printf("Give a file name");
	scanf("%s",a);
	send(sockfd,a,100,0);
	

	recv(sockfd,q,50,0);
	printf("server sent :: %s\n",q);
	//printf("IP address is: %s\n", inet_ntoa(sa.sin_addr));
		
	close(sockfd);
	char qew[77];
	scanf("%s",qew);
	
	//new connection for file download lol----------------------------------------------------------
	
	
	int sockfd1, length1,m1;
	char rep_msg[50],k1[50];
  struct sockaddr_in sa1,da1,ta1;
	length1=sizeof(sa1);
	 
  /*Create UDP socket*/
  sockfd1 = socket(AF_INET,SOCK_DGRAM,0);

  /*Configure settings in address struct*/	
	ta1.sin_family = AF_INET;
	da1.sin_addr.s_addr = inet_addr(q);
 	da1.sin_family = AF_INET;
	da1.sin_port=6003;

	/*sending a messege */
	
	printf("requesting file from peer2\n");
	sendto(sockfd1,"abc",50,0,(struct sockaddr *)&da1,length1);

	/*receiving a message */

	recvfrom(sockfd1,rep_msg,50,0,(struct sockaddr *)&ta1,&length1);
	printf("\nreceived message :: %s  from port :: %d\n",rep_msg,ta1.sin_port);
	
}
