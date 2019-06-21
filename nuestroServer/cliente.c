#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define PORT 23423 
#define SIZE 1024


//Fuertemente inspirado en Geeks for Geeks
int main(int argc, char const *argv[]) 
{ 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 

    char buffer[SIZE];
    char msg[SIZE];

    //Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    }
    int i=0;
    char c;

    
    //Responde a todas las preguntas del servidor automaticamente

    // write(sock , "entendido\n" , 10);
    // sleep(1);

    // write(sock , "#0854780*\n" ,10 );
    // sleep(1);

    // write(sock , "nokia\n" , 6);
    // sleep(1);

    // write(sock , "cabeza de calabaza\n" , 19);
    // sleep(1);

    // write(sock , "easter_egg\n" , 11);
    // sleep(1);

    // write(sock , ".runme\n" , 7);
    // sleep(1);

    // write(sock , "indeterminado\n" , 14);
    // sleep(1);

    // write(sock , "this is awesome\n" , 16);
    // sleep(1);

    // write(sock , "cachiporra\n" , 11);
    // sleep(1);

    // write(sock , "gdb rules\n" , 10);
    // sleep(1);

    // write(sock , "/lib/x86_64-linux-gnu/ld-2.19.so\n" , 33);




    while(1){
        i=0;
        while((c = getchar()) != '\n'){
            msg[i] = c;
            i++;
        }
        msg[i] = '\n';
        write(sock , msg , strlen(msg));
        bzero(msg,1024);

    }

    return 0; 
} 
