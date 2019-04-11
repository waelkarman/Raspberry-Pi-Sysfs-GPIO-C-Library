//Copyright (c) 2019, Alex Mous
//Licensed under the Creative Commons Attribution-ShareAlike 4.0 International (CC-BY-4.0)

//Header file for GPIO.cpp

#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

class GPIO {
private:
	const char *_direction; //Pin direction; either "out" or "in"
	int _level; //Current pin level (in direction="out" mode)
	const char *pin_num; //Holds the pin number

public:
	GPIO(const char *pin);
	int setupPin(int create); //Setup pin (ARGS create: whether to create or destroy pin (1 for create, 0 for destroy))
	int setDirection(const char *direction); //Set pin direction (ARGS direction: either "out" for output or "in" for input)
	int readValue(std::string *level); //Read current value of the pin
	int writeValue(int level); //Write pin (only works if _direction is "out"
};
