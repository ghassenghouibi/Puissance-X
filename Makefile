.PHONY: clean, mrproper

CC = g++
CFLAGS = -W -Wall -std=c++14 -pthread
 

all: main.o jeu.o alpha-beta.o 
	$(CC) main.o jeu.o alpha-beta.o -o PuissanceX

main.o: main.cpp
	$(CC) -c main.cpp -o main.o $(CFLAGS)

jeu.o: jeu.cpp jeu.hpp
	$(CC) -c jeu.cpp -o jeu.o $(CFLAGS)

alpha-beta.o: alpha-beta.cpp alpha-beta.hpp
	$(CC) -c alpha-beta.cpp -o alpha-beta.o $(CFLAGS)

clean:
	rm -rf *.o