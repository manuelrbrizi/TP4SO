all: cliente ourServer ebadfChallenge

cliente: cliente.c
	gcc -o cliente cliente.c

ourServer: ourServer.c challenges.c
	gcc -o ourServer ourServer.c challenges.c

ebadfChallenge: ebadfChallenge.c
	gcc -o ebadfChallenge ebadfChallenge.c
	
.PHONY: clean
clean:
	rm -rf *.o cliente ebadfChallenge ourServer