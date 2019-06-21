all: cliente ebadfChallenge

cliente: cliente.c
	gcc -o cliente cliente.c

ebadfChallenge: ebadfChallenge.c
	gcc -o ebadfChallenge ebadfChallenge.c

.PHONY: clean
clean:
	rm -rf *.o cliente ebadfChallenge quine