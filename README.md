# Overview
I have a bit of an obsession with plants. This repository contains the work I've done to find ways to track one more piece of information about my plants: weight, or at least something proportional to weight. The theory is that I can identify two things from tracking weight over time: the growth of the plant itself and how much water is in the soil.

# Contents
* Schematic Files
* PCB Layout
* Arduino Sketches
  * Peripheral Sketch for ATTiny85
  * Controller Sketch for microcontroller of your choice

# Theory of Operation
The weight PCB features an integrated strain gauge in a Wheatstone Bridge configuration with a microcontroller (ATTiny85) that reads the voltage (using 10-bit ADC) at two points in the Wheatstone Bridge. The differences in those voltages is directly related to the change in resistance of the strain gauge, which in turn is directly related to the extension or compression of the strain gauge. The ATTiny85 acts as an I2C device with address 0x10 and sends both voltage values (as uint16_t's split into two bytes each) upon request.

# To Do
* The current PCB doesn't feature a current-limiting resistor for the Wheatstone Bridge as a whole, so I've bodged one in to my test board. A current limiting resistor pad should be added to the next spin of the board.
* Communication with the strain gauge board needs to be encapsulated in a class, much like in many Adafruit sensor libraries.
* The strain gauge needs testing and may need an ADC with higher resolution to resolve the small differences.
* I don't like the look of the current strain gauge and will likely tweak it to be more evenly spaced in the next board spin.
* It may make sense to use an internet-connected microcontroller (ESP32 or ESP8266) to store weight values in a remote database.
