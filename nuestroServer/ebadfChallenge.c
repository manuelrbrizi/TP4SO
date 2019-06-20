#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main (){

	int pipefd[2];
	pipe(pipefd);


    if (fork()) {

    	char * buff = malloc(1024);
    	//printf("fd0:%d fd1:%d\n",pipefd[0],pipefd[1]);
	    while(1) {
	    	//sleep(1);
	    	bzero(buff,1024);
		    read(pipefd[0], buff, 1024);
		   	//printf("%s\n", buff);

	    }

    }
    else{
    	
    	dup2(pipefd[1], 2);

    	dup2(pipefd[1], 5);

		execl("ourServer", "ourServer",(char *) NULL);

		exit(0);
    }



}