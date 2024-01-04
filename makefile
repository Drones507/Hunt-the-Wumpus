CC=g++ -std=c++11 -g
exe=hunt

all: $(exe)

$(exe): main.o game.o room.o event.o armor.o bats.o stalactites.o gold.o wumpus.o
	$(CC) $^ -o $(exe)

main.o: main.cpp
	$(CC) -c main.cpp

game.o: game.cpp game.h
	$(CC) -c game.cpp

room.o: room.cpp room.h
	$(CC) -c room.cpp

event.o: event.cpp event.h
	$(CC) -c event.cpp

armor.o: armor.cpp armor.h
	$(CC) -c armor.cpp

bats.o: bats.cpp bats.h
	$(CC) -c bats.cpp

stalactites.o: stalactites.cpp stalactites.h
	$(CC) -c stalactites.cpp

gold.o: gold.cpp gold.h
	$(CC) -c gold.cpp

wumpus.o: wumpus.cpp wumpus.h
	$(CC) -c wumpus.cpp
clean:
	rm -f *.o $(exe)
