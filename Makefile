CC = g++
EXE_FILE=gofish

all: $(EXE_FILE)

$(EXE_FILE):gofish.cpp game.o player.o hand.o deck.o card.o
	$(CC) gofish.cpp game.o player.o hand.o deck.o card.o -o $(EXE_FILE)

game.o: game.cpp game.hpp
	$(CC) -c game.cpp
player.o: player.cpp player.hpp
	$(CC) -c player.cpp
hand.o: hand.cpp hand.hpp
	$(CC) -c hand.cpp
deck.o: deck.cpp deck.hpp
	$(CC) -c deck.cpp
card.o: card.cpp card.hpp
	$(CC) -c card.cpp
clean:
	rm -f *.o $(BIN)
