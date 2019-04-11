all: Read.cpp Write.cpp
	g++ Read.cpp -o Read -I../ -L../ -lGPIO
	g++ Write.cpp -o Write -I../ -L../ -lGPIO

run: all


clean:
	rm Read
	rm Write

