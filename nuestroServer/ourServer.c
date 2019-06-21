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

char * data = ".data";
char * bss = ".bss";
char * comment = ".comment";
char * runme = ".runme";
char * shstrtab = ".shstrtab";
char * symtab = ".symtab";
char * strtab = ".strtab";

int main(){ 
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        //printf("socket creation failed...\n");                        // Print para debuggear
        exit(0); 
    } 
    else{
        printf("Socket successfully created..\n");                      // Print para debuggear
    }
    bzero(&servaddr, sizeof(servaddr)); 

    // Setteo de opciones para que el server se pueda volver a levantar cuando se cierra mal
    // Tambien te deja tener varios servers abiertos al mismo tiempo
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) < 0){
        //printf("setsockopt(SO_REUSEADDR) failed");                    // Print para debuggear
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &(int){ 1 }, sizeof(int)) < 0){
        //printf("setsockopt(SO_REUSEPORT) failed");                    // Print para debuggear
    }
  
    // Assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        //printf("socket bind failed...\n");                            // Print para debuggear
        exit(0); 
    } 
    else{
        //printf("Socket successfully binded..\n");                     // Print para debuggear
    }
  
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        //printf("Listen failed...\n");                                 // Print para debuggear
        exit(0); 
    } 
    else{
        //printf("Server listening..\n");                               // Print para debuggear
    }
    len = sizeof(cli); 
  
    // Accept the data packet from client and verification 
    connfd = accept(sockfd, (SA*)&cli, &len); 
    if (connfd < 0) { 
        //printf("server acccept failed...\n");                         // Print para debuggear
        exit(0); 
    } 

    challenge1(connfd);

    challenge2(connfd);

    challenge3(connfd);

    challenge4(connfd);

    challenge5(connfd);

    challenge6(connfd);

    challenge7(connfd);

    challenge8(connfd);

    challenge9(connfd);

    gdbme(connfd);

    challenge11(connfd);


  
    close(sockfd); 
} 


