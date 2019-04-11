# Raspberry-Pi-Sysfs-GPIO-C-Library
<h3>A C/C++ library to setup, read and write the GPIO pins on the Raspberry Pi through the Sysfs interface</h3>
<br>
<h4> Dependencies </h4>
Requires string.h to run the readValue function

<br>
<h4> Compiling </h4>
Run <strong>make</strong> with root permission to compile the and install library.

<br>
<h4>Code Reference</h4>
<br> &ensp;&ensp;&ensp;&ensp; Functions
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; setupPin(int create)
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; Runs setup for the pin that wasspecified when creating the GPIO object
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; <strong>create</strong> should be either 1 to enable/create the pin and 0 to disable/free the pin
<br>
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; setDirection(const char \*direction)
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; Sets the pin direction (either as an input or an output).
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; <strong>direction</strong> should be either "in" to create an input or "out" to create an output.
<br>
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; readValue(std::string \*level)
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; Reads the current value of the pin. Note: readValue issues an error if the pin was set as an output with setDirection().
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; <strong>level</strong> should be a std::string variable. Run the function with readValue(&YOUR_OUTPUT_VARIABLE)
<br>
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; writeValue(int level)
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; Writes a new voltage to the pin. Note: writeValue issues an error if the pin was set as an input with setDirection().
<br> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp; <strong>level</strong> should either 1 for HIGH voltage level or 0 for LOW voltage level

<br>
<h4> Example Code </h4>
<h5> Set GPIO pin number 18 as an output with the value HIGH. </h5>

```

```

<h5> Set GPIO pin number 18 as an input and read the current value. </h5>

```

```

<h4> License </h4>
<br> All code and files are licensed under the Creative Commons Attribution-ShareAlike 4.0 International (CC-BY-4.0). Copyright (c) 2019, Alex Mous

