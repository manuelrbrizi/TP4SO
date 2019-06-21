#include <stdio.h>
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h>
#include "challenges.h"
#include <errno.h>

#define SIZE 1024

char * des = "--- DESAFIO ---\n";
char * res = "Respuesta correcta:";
char * inc = "Respuesta incorrecta:";

// Challenge entendido\n
void challenge1(int sockfd) 
{ 
    char * buff = malloc(1024);
    int n; 
    while(1){ 
        system("clear");
        printf("Bienvenidos al Himalaya, escribi \"entendido\\n\" y conoce tu destino\n" ); 
        bzero(buff, SIZE); 
        
        int last = recv(sockfd, buff, SIZE,0);

        if(strcmp(buff,"entendido\n") == 0){
            printf("%s %s\n", res, buff);
            sleep(1);
            return;
        }

        else{
            printf("%s %s\n", inc, buff);
            sleep(1);
            system("clear");
        }
    } 
} 

//Challenge Telefono
void challenge2(int sockfd){
    char * buff = malloc(1024);
    
    while(1){ 
        system("clear");
        printf("%s", des);
        char * str = "# [D \\033[A \\033[A \\033[D \\033[B \\033[C \\033[B \\033[D *\n";
        printf("%s", str);
        bzero(buff, SIZE); 
        
        int last = recv(sockfd, buff, SIZE, 0);

        if(strcmp(buff,"#0854780*\n") == 0){
            printf("%s %s\n", res, buff);
            sleep(1);
            return;
        }
        else{
            printf("%s %s\n", inc, buff);
            sleep(1);
            system("clear");
        }
    }
}

//Challenge nokia
void challenge3(int sockfd){
    char * buff = malloc(1024);
    
    while(1){
        system("clear"); 
        printf("%s", des);
        printf("https://vocaroo.com/i/s19015zmR4t8\n");
        bzero(buff, SIZE); 
        
        int last = recv(sockfd, buff, SIZE, 0);
        
        if(strcmp(buff, "nokia\n") == 0){
            printf("%s %s\n", res, buff);
            sleep(1);
            return;
        }

        else{
            printf("%s %s\n", inc, buff);
            sleep(1);
            system("clear");
        }
    }
}

//Challenge EBADF
void challenge4(int sockfd){ 
    system("clear");
    char * str = "easter_egg";
    char * buff = malloc(1024);
    write(5, "La respuesta a este desafio es cabeza de calabaza\n", 51);
    
    while(1){
        printf("%s", des);
        printf("EBADF.. abrelo y verás\n");
        bzero(buff, SIZE); 
        
        int last = recv(sockfd, buff, SIZE, 0);

        if(strcmp(buff, "cabeza de calabaza\n") == 0){
            printf("%s %s\n", res, buff);
            sleep(1);
            return;
        }

        else{
            printf("%s %s\n", inc, buff);
            sleep(1);
            system("clear");
        }
    }
}

//Challenge .runme
void challenge5(int sockfd){
    char * buff = malloc(1024);

    while(1){
        system("clear");
        printf("%s", des);
        printf(".data .bss .comment ? .shstrtab .symtab .strtab\n");
        bzero(buff, SIZE); 
        
        int last = recv(sockfd, buff, SIZE, 0);

        if(strcmp(buff,".runme\n") == 0){
            printf("%s %s\n", res, buff);
            sleep(1);
            return;
        }

        else{
            printf("%s %s\n", inc, buff);
            sleep(1);
            system("clear");
        }
    }
}

//Challenge easter_egg
void challenge6(int sockfd){
    char * buff = malloc(1024);

    while(1){
        system("clear");
        printf("%s", des);
        printf("respuesta = strings[64]\n");
        bzero(buff, SIZE); 
        
        int last = recv(sockfd, buff, SIZE, 0);

        if(strcmp(buff, "easter_egg\n") == 0){
            printf("%s %s\n", res, buff);
            sleep(1);
            return;
        }

        else{
            printf("%s %s\n", inc, buff);
            sleep(1);
            system("clear");
        }
    }
}

//Challenge mixed fds
void challenge7(int sockfd){
    char * str = "la respuesta a este acertijo es indeterminado\0";
    char * letras = "abcdefghijklmnopqrstuvwxyz\0";
    int pos = 0;
    int opt = rand()%4;
    int ran = rand()%26;
    char * buff = malloc(1);
    system("clear");
    
    while(1){
        printf("%s", des);
        printf("mixed fds\n");
        while(pos < strlen(str)){

            if(opt == 0){
                write(1, str+pos, 1);
                pos++;
            }

            else{
                write(2, letras+ran, 1);
            }

            opt = rand()%4;
            ran = rand()%26;
        }

        printf("\n");
        int last = recv(sockfd, buff, SIZE, 0);

        if(strcmp(buff, "indeterminado\n") == 0){
            printf("%s %s\n", res, buff);
            sleep(1);
            return;
        }

        else{
            printf("%s %s\n", inc, buff);
            sleep(1);
            system("clear");
        }
    }
}

//Challenge this is awesome
void challenge8(int sockfd){
    char * buff = malloc(1024);

    while(1){
        system("clear");
        printf("%s", des);
        printf("Tango Hotel India Sierra India Sierra Alfa Whiskey Echo Sierra Oscar Mike Echo\n");
        bzero(buff, SIZE); 
        
        int last = recv(sockfd, buff, SIZE, 0);
        
        if(strcmp(buff,"this is awesome\n") == 0){
            printf("%s %s\n", res, buff);
            sleep(1);
            return;
        }

        else{
            printf("%s %s\n", inc, buff);
            sleep(1);
            system("clear");
        }
    }
}

//Challenge quine
void challenge9(int sockfd){
    system("clear");
    printf("%s", des); 

    //int num = system("gcc quine.c -o quine 2>&1");    //Como el de mixed fds redireccionas la stderr esto es como para que no desaparezca
    int num = system("gcc quine.c -o quine");           //Si tenes redireccionado stderr no vas a ver el error de gcc, asi funciona el server original

    if(num == 0){
        printf("Bien, pudiste meter codigo!\n");
        num = system("./quine | diff - quine.c");
        if(num){
            printf("Perdiste\n");
        }
        else{
            printf("Ganaste\n" );
            sleep(1);
            return;
        }
    }
    else{
        printf("Perdiste\n");
    }
    while(1);    
}

//Challenge gdb
void gdbme(int sockfd){
    char * buff = malloc(1024);
    int i;

    while(1){
        i = 12345;
        system("clear");
        printf("%s", des);
        printf("b gdbme y encontrá el valor mágico\n");
        bzero(buff, SIZE); 
        
        if(i == 0){
            printf("la respuesta es gdb rules\n");
        }

        int last = recv(sockfd, buff, SIZE, 0);
        
        if(strcmp(buff,"gdb rules\n") == 0){
            printf("%s %s\n", res, buff);
            sleep(1);
            return;
        }

        else{
            printf("%s %s\n", inc, buff);
            sleep(1);
            system("clear");
        }
    }
}

//Challenge /lib
void challenge11(int sockfd){
    char * buff = malloc(1024);

    while(1){
        system("clear");
        printf("%s", des);
        printf("/lib/x86_64-linux-gnu/libc-2.19.so ?\n");
        bzero(buff, SIZE); 
        
        int last = recv(sockfd, buff, SIZE, 0);


        
        if(strcmp(buff,"/lib/x86_64-linux-gnu/ld-2.19.so\n") == 0){
            printf("%s %s\n", res, buff);
            sleep(1);
            return;
        }

        else{
            printf("%s %s\n", inc, buff);
            sleep(1);
            system("clear");
        }
    }
}