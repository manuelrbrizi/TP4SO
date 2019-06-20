#include <stdio.h>
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h>
#define PORT 23423 
#define SIZE 1024
#define SA struct sockaddr 
  
// Function designed for chat between client and server. 
void challenge1(int sockfd); 
void challengex(int sockfd);

void func(int sockfd) 
{ 
    char * buff = malloc(1024);
    int n; 
    // infinite loop for chat 
    for(int i =0;i<12;i++){ 
        //clear buffer
        bzero(buff, SIZE); 
  
        // read the message from client and copy it in buffer 
        read(sockfd, buff, sizeof(buff)); 
        // print buffer which contains the client contents 
        printf("From client: %s\t To client : ", buff); 
        bzero(buff, SIZE); 
        n = 0; 
        // copy server message in the buffer 
        while ((buff[n++] = getchar()) != '\n') 
            ; 
  
        // and send that buffer to client 
        write(sockfd, buff, sizeof(buff)); 
  
        // if msg contains "Exit" then server exit and chat ended. 
        if (strncmp("exit", buff, 4) == 0) { 
            printf("Server Exit...\n"); 
            break; 
        } 
    } 
} 
  
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
    challenge1(connfd);
  
    // After chatting close the socket 
    close(sockfd); 
} 

void challenge1(int sockfd) 
{ 
    char * buff = malloc(1024);
    int n; 
    // infinite loop for chat 
        while(1){ 
        //clear buffer
            printf("Bienvenidos al Himalaya, pone \"entendido\\n\" porque se pudre\n" ); 
        bzero(buff, SIZE); 
        
        // read the message from client and copy it in buffer 
        int last = recv(sockfd, buff, SIZE,0);
     
        printf("%s\n", buff);

        // print buffer which contains the client contents 
        
        if(strcmp(buff,"entendido\n") == 0){
            printf("Bien, sabes escribir\n");
            challengex(sockfd);
            break;
        }
        else{
            printf("Que se siente que tus papas sean primos?\n");
            sleep(1);
            system("clear");
        }


    } 


} 

void challengex(int sockfd){



        printf("Este es el de quine amigo\n" ); 

        int num = system("gcc quine.c -o quine");
        if(num == 0){
            num = system("./quine | diff - quine.c");
            if(num){
                printf("Perdiste\n");
            }
            else{
                printf("Ganaste\n" );
            }
        }
        else{
            printf("Perdiste\n");
        }


    //}

        
 


        
}