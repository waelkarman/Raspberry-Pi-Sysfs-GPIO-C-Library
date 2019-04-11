
all: GPIO.cpp
	gcc -fPIC -c GPIO.cpp -o GPIO.o
	gcc -shared -o libGPIO.so GPIO.o
	install -m 755 -p libGPIO.so /usr/lib/
	install -m 644 -p GPIO.h /usr/include/
	rm -f GPIO.o
	rm -f libGPIO.so

clean:
	rm -f /usr/include/GPIO.h
	rm -f /usr/lib/libGPIO.so

