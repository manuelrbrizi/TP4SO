#include <stdio.h>
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h>
#include "ebadf.h"
#define PORT 23423 
#define SIZE 1024
#define SA struct sockaddr 
  
// Function designed for chat between client and server. 
void challenge1(int sockfd); 
void challenge2(int sockfd);
void challenge2bis(int sockfd);
void challenge3(int sockfd); 
void challenge4(int sockfd);
void challenge5(int sockfd);
void challenge6(int sockfd);
void mixedfds(int sockfd); 
void ebadf(int sockfd);
void challengex(int sockfd);
char * data = ".data";
char * bss = ".bss";
char * comment = ".comment";
char * runme = ".runme";
char * shstrtab = ".shstrtab";
char * symtab = ".symtab";
char * strtab = ".strtab";

void func(int sockfd) 
{ 
    char * buff = malloc(1024);
    int n, i; 
    // infinite loop for chat 
    for(i =0;i<12;i++){ 
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
            system("clear");
            printf("Bienvenidos al Himalaya, pone \"entendido\\n\" porque se pudre\n" ); 
        bzero(buff, SIZE); 
        
        // read the message from client and copy it in buffer 
        int last = recv(sockfd, buff, SIZE,0);
        //printf("%s\n", buff);

        // print buffer which contains the client contents 
        
        if(strcmp(buff,"entendido\n") == 0){
            printf("Bien, sabes escribir\n");
            challenge2bis(sockfd);
            break;
        }
        else{
            printf("Que se siente que tus papas sean primos?\n");
            sleep(1);
        }
    } 
} 

void challenge2bis(int sockfd){
    char * buff = malloc(1024);
    
    while(1){ 
        system("clear");
        printf("--- DESAFIO ---\n");
        char * str = "# [D \033[A \033[A \033[D \033[B \033[C \033[B \033[D *\n";
        printf(str);
        bzero(buff, SIZE); 
        
        // read the message from client and copy it in buffer 
        int last = recv(sockfd, buff, SIZE, 0);

        // print buffer which contains the client contents 
        //printf("%s\n", buff);
        
        if(strcmp(buff,"#0854780*\n") == 0){
            printf("Respuesta correcta: %s\n", buff);
            sleep(1);
            challenge2(sockfd);
            break;
        }
        else{
            printf("Respuesta incorrecta: %s\n", buff);
            sleep(1);
            system("clear");
        }
    }
}

void challenge2(int sockfd){
    char * buff = malloc(1024);
    
    while(1){
        system("clear"); 
        printf("--- DESAFIO ---\n");
        printf("https://vocaroo.com/i/s19015zmR4t8\n");
        bzero(buff, SIZE); 
        
        // read the message from client and copy it in buffer 
        int last = recv(sockfd, buff, SIZE, 0);

        // print buffer which contains the client contents 
        //printf("%s\n", buff);
        
        if(strcmp(buff,"nokia\n") == 0){
            printf("Respuesta correcta: %s\n", buff);
            sleep(1);
            ebadf(sockfd);
            break;
        }
        else{
            printf("Respuesta incorrecta: %s\n", buff);
            sleep(1);
            system("clear");
        }
    }
}

void ebadf(int sockfd){
    char * str = "easter_egg";
    char * buff = malloc(1024);
    write(5, "cabeza de calabaza\n", 20);
    
    while(1){
        system("clear");
        printf("--- DESAFIO ---\n");
        printf("EBADF.. abrelo y verás\n");
        bzero(buff, SIZE); 
        
        // read the message from client and copy it in buffer 
        int last = recv(sockfd, buff, SIZE, 0);

        // print buffer which contains the client contents 
        //printf("%s\n", buff);
        
        if(strcmp(buff,"cabeza de calabaza\n") == 0){
            printf("Respuesta correcta: %s\n", buff);
            sleep(1);
            challenge3(sockfd);
            break;
        }

        else{
            printf("Respuesta incorrecta: %s\n", buff);
            sleep(1);
            system("clear");
        }
    }
}

void challenge3(int sockfd){
    char * buff = malloc(1024);

    while(1){
        system("clear");
        printf("--- DESAFIO ---\n");
        printf(".data .bss .comment ? .shstrtab .symtab .strtab\n");
        bzero(buff, SIZE); 
        
        // read the message from client and copy it in buffer 
        int last = recv(sockfd, buff, SIZE, 0);

        // print buffer which contains the client contents 
        //printf("%s\n", buff);
        
        if(strcmp(buff,".runme\n") == 0){
            printf("Respuesta correcta: %s\n", buff);
            sleep(1);
            challenge4(sockfd);
            break;
        }

        else{
            printf("Respuesta incorrecta: %s\n", buff);
            sleep(1);
            system("clear");
        }
    }
}

void challenge4(int sockfd){
    char * buff = malloc(1024);

    while(1){
        system("clear");
        printf("--- DESAFIO ---\n");
        printf("respuesta = strings[HAY QUE PONER EL INDICE CORRECTO]\n");
        bzero(buff, SIZE); 
        
        // read the message from client and copy it in buffer 
        int last = recv(sockfd, buff, SIZE, 0);

        // print buffer which contains the client contents 
        //printf("%s\n", buff);
        
        if(strcmp(buff,"easter_egg\n") == 0){
            printf("Respuesta correcta: %s\n", buff);
            sleep(1);
            mixedfds(sockfd);
            break;
        }

        else{
            printf("Respuesta incorrecta: %s\n", buff);
            sleep(1);
            system("clear");
        }
    }
}

//me gustaría que se pueda leer una cantidad azarosa pero no tengo time
void mixedfds(int sockfd){
    char * buff = malloc(1024);
    char * str1 = "la respuesta es indeterminado";
    char * str2 = "bolaenlaingledenlemildolaresaesehombreyaganoelconcursomegustaestetpesbastanteentetenido";
    char * str = malloc(1024);
    int i, j, k;

    for(i = 0; i < 100; i++){
        for(j = 0; j < 100; j++){

        }
    }

    

    while(1){
        system("clear");
        printf("--- DESAFIO ---\n");
        printf("%s\n", str);
        bzero(buff, SIZE); 
        
        // read the message from client and copy it in buffer 
        int last = recv(sockfd, buff, SIZE, 0);

        // print buffer which contains the client contents 
        //printf("%s\n", buff);
        
        if(strcmp(buff,"indeterminado\n") == 0){
            printf("Respuesta correcta: %s\n", buff);
            sleep(1);
            challenge5(sockfd);
            break;
        }

        else{
            printf("Respuesta incorrecta: %s\n", buff);
            sleep(1);
            system("clear");
        }
    }
}

void challenge5(int sockfd){
    char * buff = malloc(1024);

    while(1){
        system("clear");
        printf("--- DESAFIO ---\n");
        printf("Tango Hotel India Sierra India Sierra Alfa Whiskey Echo Sierra Oscar Mike Echo\n");
        bzero(buff, SIZE); 
        
        // read the message from client and copy it in buffer 
        int last = recv(sockfd, buff, SIZE, 0);

        // print buffer which contains the client contents 
        //printf("%s\n", buff);
        
        if(strcmp(buff,"this is awesome\n") == 0){
            printf("Respuesta correcta: %s\n", buff);
            sleep(1);
            challengex(sockfd);
            break;
        }

        else{
            printf("Respuesta incorrecta: %s\n", buff);
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
                challenge6(sockfd);
            }
        }
        else{
            printf("Perdiste\n");
        }    
}


void challenge6(int sockfd){
    char * buff = malloc(1024);
    int i;

    while(1){
        i = 12345;
        system("clear");
        printf("--- DESAFIO ---\n");
        printf("b gdbme y encontrá el valor mágico\n");
        bzero(buff, SIZE); 
        
        // read the message from client and copy it in buffer
        if(i == 0){
            printf("la respuesta es gdb rules\n");
        }

        int last = recv(sockfd, buff, SIZE, 0);

        // print buffer which contains the client contents 
        //printf("%s\n", buff);
        
        if(strcmp(buff,"gdb rules\n") == 0){
            printf("Respuesta correcta: %s\n", buff);
            sleep(1);
            challengex(sockfd);
            break;
        }

        else{
            printf("Respuesta incorrecta: %s\n", buff);
            sleep(1);
            system("clear");
        }
    }
}

void challenge7(int sockfd){
    char * buff = malloc(1024);

    while(1){
        system("clear");
        printf("--- DESAFIO ---\n");
        printf("/lib/x86_64-linux-gnu/libc-2.19.so ?\n");
        bzero(buff, SIZE); 
        
        // read the message from client and copy it in buffer 
        int last = recv(sockfd, buff, SIZE, 0);

        // print buffer which contains the client contents 
        //printf("%s\n", buff);
        
        if(strcmp(buff,"/lib/x86_64-linux-gnu/ld-2.19.so\n") == 0){
            printf("Respuesta correcta: %s\n", buff);
            sleep(1);
            challengex(sockfd);
            break;
        }

        else{
            printf("Respuesta incorrecta: %s\n", buff);
            sleep(1);
            system("clear");
        }
    }
}

