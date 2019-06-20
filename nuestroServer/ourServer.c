#include <stdio.h>
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h>
#include "challenges.h"

#define PORT 23423 
#define SIZE 1024
#define SA struct sockaddr 
  
// Function designed for chat between client and server. 

char * data = ".data";
char * bss = ".bss";
char * comment = ".comment";
char * runme = ".runme";
char * shstrtab = ".shstrtab";
char * symtab = ".symtab";
char * strtab = ".strtab";

  
// Gracias por tanto Geeks for Geeks
int main() 
{ 
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) < 0)
        printf("setsockopt(SO_REUSEADDR) failed");

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &(int){ 1 }, sizeof(int)) < 0)
        printf("setsockopt(SO_REUSEPORT) failed");
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
  
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    len = sizeof(cli); 
  
    // Accept the data packet from client and verification 
    connfd = accept(sockfd, (SA*)&cli, &len); 
    if (connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    
        //printf("server acccept the client...\n"); 
  
    // Function for chatting between client and server 
    //func(connfd); 
    // challenge1(connfd);

    // challenge2(connfd);

    // challenge3(connfd);
 //   challenge4(connfd);

   // challenge5(connfd);

    //challenge6(connfd);

    //challenge7(connfd);

    //challenge8(connfd);

    challenge9(connfd);

    challenge10(connfd);

    challenge11(connfd);


  
    // After chatting close the socket 
    close(sockfd); 
} 


