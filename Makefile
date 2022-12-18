GAWsock1    :   GAWsock1.o
	cc -o GAWsock1 GAWsock1.o
GAWsock1.o  :   GAWsock1.c
	cc -c GAWsock1.c

GAWsock2    :   GAWsock2.o
	cc -o GAWsock2 GAWsock2.o
GAWsock2.o  :   GAWsock2.c
	cc -c GAWsock2.c

GAWsock3    :   GAWsock3.o
	cc -o GAWsock3 GAWsock3.o
GAWsock3.o  :   GAWsock3.c
	cc -c GAWsock3.c

GAWsock4    :   GAWsock4.o
	cc -o GAWsock4 GAWsock4.o
GAWsock4.o  :   GAWsock4.c
	cc -c GAWsock4.c

all	: GAWsock1 GAWsock2 GAWsock3 GAWsock4
	
clean :
	rm	GAWsock1 GAWsock1.o \
		GAWsock2 GAWsock2.o \
		GAWsock3 GAWsock3.o \
		GAWsock4 GAWsock4.o \
