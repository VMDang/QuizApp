CFLAGS = -c -Wall -lcrypto -lssl
CC = g++
LIB = -lm

all: server

debug: CFLAGS += -g
debug: server

server: server.o
	${CC} server.cpp ../comunicate/server.cpp ../../Model/User.cpp AuthController.cpp -o server -pthread

server.o: server.cpp
	${CC} $(CFLAGS) server.cpp

clean:
	rm -f *.o *~