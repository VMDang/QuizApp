CFLAGS = -c -Wall -lcrypto -lssl
CC = g++
LIB = -lm
comunicate = ../comunicate/server.cpp
M_user = ../../Model/User.cpp
M_room = ../../Model/Room.cpp
C_auth = AuthController.cpp
C_room = RoomController.cpp
M_userroom = ../../Model/UserRoom.cpp

all: server

debug: CFLAGS += -g
debug: server

server: server.o
	${CC} server.cpp ${comunicate} ${M_user} ${M_room} ${M_userroom} ${C_auth} ${C_room} ${R}  -o server -pthread

server.o: server.cpp
	${CC} $(CFLAGS) server.cpp

clean:
	rm -f *.o *~