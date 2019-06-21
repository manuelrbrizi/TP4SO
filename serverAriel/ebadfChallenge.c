#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


//Esto se usa para el Challenge de EBADF y el de mixed fds

int main (){

	int pipefd[2];
	pipe(pipefd);


    if (fork()) {

    	char * buff = malloc(1024);
	    while(1) {
	    	bzero(buff,1024);
		    read(pipefd[0], buff, 1024);
		   	printf("%s\n", buff);			//Te da la respuesta del challenge de EBADF

	    }

    }
    else{
    	

    	dup2(pipefd[1], 5);		//Redirecciono el fd 5

    	int fd = open("/dev/null",O_WRONLY | O_CREAT, 0666); 	// Redireciono stderr para que se vayan las letras malas del mixed fds
    	dup2(fd,2);												// El problema es que no te muestra el error de gcc con quine

		execl("server", "server",(char *) NULL);



		exit(0);
    }



}