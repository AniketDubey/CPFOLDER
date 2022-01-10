#include <stdio.h> // std input and output lib
#include <stdlib.h> // memory allocation functions
#include <string.h> // contains string functions
#include <errno.h> // macros for reporting and retrieving error conditions through error codes
#include <time.h> //date and time functions
#include <unistd.h> //contains various constants
#include <sys/types.h> //for derived types
#include <arpa/net.h> // defines in_addr structure
#include <sys/socket.h> // for socket creation
#include <netinet/in.h> // for internet domain addresses
 
int main()
{
    time_t clock;
	char dataSending[1025]; // packet	
	int clintListn = 0, clintConnt = 0;
	struct sockaddr_in ipOfServer;
	clintListn = socket(AF_INET, SOCK_STREAM, 0); // creating socket, SOCK_STREAM means TCP 
	memset(&ipOfServer, '0', sizeof(ipOfServer));
	memset(dataSending, '0', sizeof(dataSending));
	ipOfServer.sin_family = AF_INET;
	ipOfServer.sin_addr.s_addr = htonl(INADDR_ANY);
	ipOfServer.sin_port = htons(2017); 		// this is the port number of running server
	bind(clintListn, (struct sockaddr*)&ipOfServer , sizeof(ipOfServer));	//to bind socket to ipOfServer
	listen(clintListn , 20);	//max client number is seet to 20
 
	while(1)
	{
		printf("\n\nHi,Iam running server.Some Client hit me\n"); // processing of client req
		clintConnt = accept(clintListn, (struct sockaddr*)NULL, NULL);	//waiting for client req
 
		clock = time(NULL);
		snprintf(dataSending, sizeof(dataSending), "%.24s\r\n", ctime(&clock)); // Printing date and timewhen req is accepted
		write(clintConnt, dataSending, strlen(dataSending));
 
        close(clintConnt);
        sleep(1);
     }
 
     return 0;
}

