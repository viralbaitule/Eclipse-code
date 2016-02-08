/*
 * client.c
 *
 *  Created on: Jan 22, 2016
 *      Author: Viral
 */
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpainet.h>
#include<string.h>
#include <netdb.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int portno;
	struct sockaddr_in serv_addr;
	int sockfd,
	char buff[1025];
	char rbuff[1025];
	memset(&serv_addr,'0',sizeof(serv_addr));
	memset(buff,'0',sizeof(buff));
	portno=atoi(argv[2]);

	sockfd=socket(PF_INET,SOCK_STREAM,0);

	serv_addr.sin_family= AF_INET;
	serv_addr.sin_port=htons(portno);

	connect(sockfd,(struct sockaddr *)&serv_addr, sizeof(serv_addr));
	printf("Enter the msg:");
	fget(buff,255,stdin);
	write(sockfd,buff,strlen(buff));

	read(sockfd,rbuff,255);
	printf("%s\n",rbuff);
	close(sockfd);
	return 0;
}
