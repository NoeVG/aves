#Macros
CC = g++
CPPFLAGS = -g -std=c++11
SRC = src/main.cpp
OBJ = src/main.o

#Reglas explicitas
all:	$(OBJ)
			$(CC) $(CPPFLAGS) -o bin/ave $(OBJ)
clean:
	$(RM) $(OBJ) bin/ave

main.o: src/main.cpp
