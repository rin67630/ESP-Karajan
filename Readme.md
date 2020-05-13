
When your ESP-Based project is becoming complex and you have to deal with several concurring tasks like
- a menu (serial, over buttons/USB, or IR -remote)
- computation and data processing tasks
- a display (OLED, LCD or LED...
- a report on serial port
- a wireless communication

then your program becomes like a symphonic orchestra and you need a director.
In hommage to Herber von Karajan, I have written that framework that helps me to develop on Arduino IDE
and keep the overview. That development aims to structure your work and discharge you from the task of
managing the wifi, the NTP connection* and the time/ticks management

(*) The wifi and NTP connections are based on my other work NatLibESP https://github.com/rin67630/NatLibESP

The collaborative scheduler takes care to distribute the slow tasks evenly so not everything happens at the beginning of every second.


The Arduino IDE provides tabs to split the program into well structured subparts, so you can jump easily during development between every subpart:

a) the declarations, constants, variables & includes
b) the different functions used in the program
c) the setup activities
d) the menu
e) the data processing
f) the display
g) the serial reports
h) the wireless processes
k) and finally the scheduler itself which will periodically start the routines listed from d) to h).

Additonally two tabs with comments only are added for convenience: 

x_ReadMe and y_ParkedCode, where you can put reminders and code examples.

The Scheduler itself is in tab K_loop.
The aim is to process the menu as fast as possible to be reactive enough, especially for IR processing which cannot suffer delays,
The data processing is provided at 125mS and one second paces
The display, serial and wireless sub processes are provided at a one second pace
Finally but not least the code runs without modification on an ESP8266 or ESP32 altogether without requiring any specific library to be installed.

Enjoy!
