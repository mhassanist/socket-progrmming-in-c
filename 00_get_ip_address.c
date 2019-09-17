#include<stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main (){

	int status;
	struct addrinfo hints;
	struct addrinfo *servinfo; // point to the results
	
	memset(&hints, 0, sizeof hints); // empty struct
	
	hints.ai_family 	= AF_UNSPEC; // IPv4 or IPv6
	hints.ai_socktype 	= SOCK_STREAM; // TCP stream sockets
	hints.ai_flags 		= AI_PASSIVE; // fill in my IP for me
	
	char* node = "127.0.0.1";
	char* port = "3490";
	
	if ((status = getaddrinfo(node, port, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
		exit(1);
	}
	
	struct sockaddr_in* ipSocketAddr = (struct sockaddr_in*)servinfo->ai_addr;
	char *ip = inet_ntoa(ipSocketAddr->sin_addr);

	printf("\n%s\n",ip );
	
	// servinfo now points to a linked list of 1 or more struct addrinfos
	// ... do everything until you don't need servinfo anymore ....
	freeaddrinfo(servinfo); 

}
