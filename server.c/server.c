/*
 * server.c
 *
 *  Created on: Jan 22, 2016
 *      Author: Viral
 */
#include <stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include <netdb.h>
#include<stdlib.h>

#define backlog=10;

int main(int argc, char * argv[])
{
	struct sockaddr_in serv_addr, client_addr;

	char buff[1025];
	int sockfd=0,newfd=0;

	sockfd=socket(PF_INET,SOCK_STREAM,0);
	memset(&serv_addr,'0',sizeof(serv_addr));
	memset(buff,'0',sizeof(buff));

	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_port=htons(5000);

	bind(sockfd,(struct sockaddr*)& serv_addr,sizeof(serv_addr));

	listen(sockfd,backlog);

	while(1)
	{
		newfd=accept(sockfd,(struct sockaddr*)&client_addr,sizeof(client_addr));

		read(newfd,buff,255);
		printf("here is the msg %s\n",buff);
		write(newfd,"i got you msg",18);
		close(newfd);
	}
	return 0;
}























}
