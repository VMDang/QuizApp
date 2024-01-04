CFLAGS = -c -Wall -lcrypto -lssl
CC = g++
LIB = -lm
comunicate = ../comunicate/server.cpp
M_user = ../../Model/User.cpp
M_room = ../../Model/Room.cpp
M_question = ../../Model/Question.cpp
M_option = ../../Model/Option.cpp
M_answer = ../../Model/Answer.cpp
M_category = ../../Model/Category.cpp
C_auth = AuthController.cpp
C_room = RoomController.cpp
C_category = CategoryController.cpp
C_answer = AnswerController.cpp
C_question = QuestionController.cpp
C_registration = RegistrationController.cpp
M_ur = ../../Model/UserRoom.cpp
M_rq = ../../Model/RoomQuestion.cpp
manager = ServerManager.cpp

all: server

debug: CFLAGS += -g
debug: server

server: server.o
	${CC} server.cpp  ${comunicate} ${M_user} ${M_room} ${M_question} ${M_option} ${M_answer} ${M_category} ${M_ur} ${M_rq} ${C_auth} ${C_room} ${C_category} ${C_answer} ${C_question} ${C_registration} ${manager} -o server -pthread

server.o: server.cpp
	${CC} $(CFLAGS) server.cpp

clean:
	rm -f *.o *~