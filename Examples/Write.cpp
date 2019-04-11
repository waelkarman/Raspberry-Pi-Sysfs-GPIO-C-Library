//Copyright (c) 2019, Alex Mous
//Licensed under the Creative Commons Attribution-ShareAlike 4.0 International (CC-BY-4.0)

//Example code for writing a GPIO pin

#include "GPIO.h"
#include <iostream>
#include <string.h>

#define GPIO_PIN 18

int main() {
	std::cout << "GPIO library example: Reading a GPIO pin\n";

	int status; //Create a status variable

	GPIO gpio_test("18"); //Create a GPIO object

	status = gpio_test.setupPin(1); //Create pin
	if (status != 0) return 1; //Return error code

	status = gpio_test.setDirection("out"); //Set pin direction
	if (status != 0) return 1; //Return error code

	std::cout << "Wrote GPIO pin " << GPIO_PIN << " HIGH\n";
	status = gpio_test.writeValue(1); //Set pin value
	if (status != 0) return 1; //Return error code

	sleep(5); //Wait five seconds

	std::cout << "Wrote GPIO pin " << GPIO_PIN << " LOW\n";
	status = gpio_test.writeValue(0); //Set pin value
	if (status != 0) return 1; //Return error code

	status = gpio_test.setupPin(0); //Create pin
	if (status != 0) return 1; //Return error code

	return 0; //Return default code
}
