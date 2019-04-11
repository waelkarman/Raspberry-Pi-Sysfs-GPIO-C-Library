
all: GPIO.cpp
	gcc -fPIC -c GPIO.cpp -o GPIO.o
	gcc -shared -o libGPIO.so GPIO.o
	rm GPIO.o

clean:
	rm libGPIO.so

