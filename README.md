# Arduino-Based-Temperature-Warning-System
This is a temperature alarm project that uses an Arduino board and a thermistor to monitor the temperature, and activate an alarm and cooling fan when the temperature exceeds a certain threshold.
# Getting Started
# Prerequisites
To build and run this project, you will need:

An Arduino board (tested with Arduino Uno)
A thermistor
A 10 kΩ resistor
A 5 V cooling fan
A push button
Jumper wires
A breadboard
Arduino IDE (or other compatible IDE)

# Installing
Clone this repository to your local machine.
Connect the components as shown in the circuit diagram (TODO: add circuit diagram).
Open the Arduino sketch file (temp_alarm.ino) in the Arduino IDE.
Select the appropriate board and port from the Tools menu.
Upload the sketch to the Arduino board.

# Usage
Power up the Arduino board.
Monitor the temperature readings in the serial monitor of the Arduino IDE.
When the temperature exceeds 53°C, the cooling fan will turn on at 33% speed for 3 seconds.
Press the push button to stop the program.
