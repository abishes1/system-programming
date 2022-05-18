//The program to create a test UDP server 
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define ADDRSERV "127.0.0.1"
#define PORTNO 8025
#define MAX 256
using namespace std;


int main() {
	struct sockaddr_in servaddr, cliaddr;
	char smsg[MAX] = "Hello from server to client";
	char cmsg[MAX];
	int sockfd,mlen,slen;//Initialising sock filedescriptor, message length, structure length
	socklen_t clen;
	slen = sizeof(sockaddr_in);
	memset(&servaddr,0,slen);
	memset(&cliaddr,0,slen);
	memset(cmsg,0,MAX);


	servaddr.sin_family = AF_INET;//To use internet family of addressing
	//servaddr.sin_addr.s_addr = inet_addr(ADDRSERV);
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORTNO);


	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	bind(sockfd,(struct sockaddr *)&servaddr,slen);
	listen(sockfd,5);
	mlen=recvfrom(sockfd,(char *)cmsg,MAX,MSG_WAITALL,(struct sockaddr *)&cliaddr,&clen);
	cout << cmsg << endl;
	mlen=sendto(sockfd,(char *)smsg,strlen(smsg),MSG_CONFIRM,(struct sockaddr *)&cliaddr,clen);
	cout << "Message sent from the server" << endl;
}

	




