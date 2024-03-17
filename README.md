Codebase for Wemos (d1 r1) microcontroler.
<br/>
This is for PHSI's science week competition (grade 11 sy 2023-2024)

## Codebase structure
`src` -> contains the main loop where every peice of the codebase comes together
<br/>
`lib` -> contains all necessary code abstraction so that the main loop won't be polluted with code.
<br/>
`include` -> contains all third party libraries that's not found in the platform.io registry.

## What does this codebase do?
### Controls the slave arduino.
The wemos board will send instruction to the slave arduino for it to perform.

### Sensor fusion
The ultrasonic sensors(HC-SR04), soil moisture sensor and most importantly the esp8266 module are connected to the wemos board. This code will handle all of the data ultrasonic sensors and soil moisture sensor sends to do the necessary procedures.

### Wireless communication
When it's time to read the soil moisutre content, it'll send the data thru wifi to a computer application where further analysis.