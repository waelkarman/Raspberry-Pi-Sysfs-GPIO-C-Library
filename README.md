# Raspberry-Pi-Sysfs-GPIO-C-Library
<h3>A C/C++ library to setup, read and write the GPIO pins on the Raspberry Pi through the Sysfs interface</h3>

<h3> Dependencies </h3>
Requires string.h to run the readValue function

<br>
<h3> Installing </h3>
Run <strong>make</strong> to compile and install the GPIO library. To build the example code, run <strong> make examples.</strong> Run <strong> make clean </strong> to uninstall the library and remove the compiled example code. Note: the make commands need to be run with root permissions. 
<br>
<h3> Compiling </h3>
Once you have run <strong> make </strong> to install the GPIO library system-wide, just run <strong> g++ YOUR_FILE.cpp -o YOUR_FILE -lGPIO </strong> to compile YOUR_FILE.cpp into an executable.
<br>
<h3>Code Reference</h3>
&ensp;&ensp;&ensp;&ensp; Functions
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; setupPin(int create)
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; Runs setup for the pin that wasspecified when creating the GPIO object
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; <strong>create</strong> should be either 1 to enable/create the pin and 0 to disable/free the pin
<br>
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; setDirection(int direction)
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; Sets the pin direction (either as an input or an output).
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; <strong>direction</strong> should be either 0 to create an input or 1 to create an output.
<br>
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; readValue(std::string *level)
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; Reads the current value of the pin. Note: readValue issues an error if the pin was set as an output with setDirection().
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; <strong>level</strong> should be a std::string variable. Run the function with readValue(&YOUR_OUTPUT_VARIABLE)
<br>
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; writeValue(int level)
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; Writes a new voltage to the pin. Note: writeValue issues an error if the pin was set as an input with setDirection().
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; <strong>level</strong> should either 1 for HIGH voltage level or 0 for LOW voltage level

<br>
<h3> Example Code </h3>
Both the uncompiled and compiled code will be in the Examples folder (run <strong> make examples </strong> to compile the examples).

```
//Copyright (c) 2019, Alex Mous
//Licensed under the Creative Commons Attribution-ShareAlike 4.0 International (CC-BY-4.0)

//Example code for writing a GPIO pin
//Set GPIO pin number GPIO_PIN as an output with the value HIGH, wait 5 seconds, and write the value LOW and disable the pin
//Change #define GPIO_PIN to a different number to use a different GPIO pin

#include "GPIO.h"
#include <iostream>
#include <string.h>

#define GPIO_PIN "18" //GPIO pin (BCM number) used as an output

int main() {
	std::cout << "GPIO library example: Writing a GPIO pin\n";

	int status; //Create a status variable

	GPIO gpio_test(GPIO_PIN); //Create a GPIO object

	status = gpio_test.setupPin(1); //Create pin
	if (status != 0) return 1; //Return error code

	status = gpio_test.setDirection(1); //Set pin direction
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

```


```
//Copyright (c) 2019, Alex Mous
//Licensed under the Creative Commons Attribution-ShareAlike 4.0 International (CC-BY-4.0)

//Example code for reading a GPIO pin
//Set GPIO pin number GPIO_PIN as an input and read the current value
//Change #define GPIO_PIN to a different number to use a different GPIO pin

#include "GPIO.h"
#include <iostream>
#include <string>

#define GPIO_PIN "18" //GPIO pin (BCM number) used as an input

int main() {
	std::cout << "GPIO library example: Reading a GPIO pin\n";

	int status; //Create a status variable

	GPIO gpio_test(GPIO_PIN); //Create a GPIO object

	status = gpio_test.setupPin(1); //Create pin
	if (status != 0) return 1; //Return error code

	status = gpio_test.setDirection(0); //Set pin direction
	if (status != 0) return 1; //Return error code

	std::string res;
	status = gpio_test.readValue(&res); //Set pin value
	if (status != 0) return 1; //Return error code

	if (res == "1") {
		std::cout << "GPIO pin " << GPIO_PIN << " is HIGH\n";

	}
	else {
		std::cout << "GPIO pin " << GPIO_PIN << " is LOW\n";
	}

	status = gpio_test.setupPin(0); //Disable pin
	if (status != 0) return 1; //Return error code

	return 0; //Return default code
}
```

<h3> License </h3>
All code and files are licensed under the Creative Commons Attribution-ShareAlike 4.0 International (CC-BY-4.0). Copyright (c) 2019, Alex Mous

