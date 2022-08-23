Karajan is a  powerfull and versatile collaborative scheduler for Arduinos / ESP modules.


When your ESP-Based project is becoming complex and you have to deal with several concurring tasks like
- a menu (serial, over buttons/USB, or IR -remote)
- computation and data processing tasks
- a display (OLED, LCD or LED...
- a report on serial port
- a wireless communication
then your program becomes like a symphonic orchestra and you need a director to get everyting in pace.
In hommage to Herbert von Karajan, I have written that framework that helps me to develop on the Arduino IDE
and keep the overview. 
That development aims to structure your work and discharge you from the task of managing the wifi, the NTP connection* and 
the time/ticks management

The collaborative scheduler takes care to distribute the slow tasks evenly so not everything happens at the beginning of every second.
https://www.cjoint.com/doc/20_05/JEntw5QrfVX_Karajan.jpg

The Arduino IDE provides tabs to split the program into well structured subparts, so you can jump easily during development between every subpart:

a) the declarations, constants, variables & includes  
b) the different functions used in the program  
c) the setup activities  
d) the menu  
e) the data processing  
f) Subsequent statistics  
g) the display  
h) the serial reports  
i) the wireless processes  
k) and finally the scheduler itself which will periodically start the routines listed from d) to i).

The Scheduler itself is in tab K_loop.
it will provide global variables like:
NewMinute 
MinuteExpiring 
NewHour 
HourExpiring 
NewDay 
DayExpiring 
which you can use to do things on the beginning or on the end of a minute, hour, day.

The global variables Second, Minute, Hour, Day, Month, Year are provided as well.

The scheduler provides also a Job report that tells you how long each task took:
Job Timing

GracePause: 000  
Job Durations(mS) Current - Max  
Menu:000 - 000  
Fast:007 - 007  
Slow:000 - 000  
Stat:000 - 001  
Disp:000 - 000  
Seri:003 - 000  
Wifi:000 - 000  

The aim is to process the menu as fast as possible to be reactive enough, especially for IR processing which cannot suffer delays,  
The data processing is provided at 125mS and one second paces  
The display, serial and wireless sub processes are provided at a one second pace but each one shifted by 125mS to distribute the load evently.  

The scheduler is intended to work together with https://tinger.io , a very versatile dashboard service, that works without needing a MQTT broker and can be extremely fast, not limited by the usual minute pace of MQTT.  
The drawback is that if the internet communication is not perfect or the server is busy, the process my be stuck and you device may ger unresponsive.  
For that reason the handshake with thinger (which should take only microsecondes) is monitored and if it takes more than 500mS, the communication will be interrupted for 100 seconds, letting you use the menu, display, and compute data further. That is the optional GracePause.  

Finally but not least the code runs without modification on an ESP8266 or ESP32 altogether without requiring any specific library to be installed.  

Some examples of Karajan used operatively:
https://github.com/rin67630/Sound-pressure-level-meter-Booster  
https://github.com/rin67630/Drok-Juntek-on-steroids  


Enjoy!
