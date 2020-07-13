## Description
This program uses interrupts to detect when a switch is pressed or
released.

By utilizing the basic knowledge of a buzzer,buttons, leds, and interrupts
displaied on the demos, the program will execute different functionalities using the MSP430.

## First Button
The first switch will cause for the red led light to turn on and if pressed
again the green led light will turn on while turrning off the other. Youll be
able to alternate each light by pressing the switch.

## Second Button
The second switch will initally turn on both led lights at the same time. When
pressed again, the lights will become dimmer. This is done by using the watch
dog timer and turnning the leds on and off at a speed that the human eye does
not percieve. Finally, if the button is pressed again it will exit out of loop
and completely turn off both leds.

## Third Button
Third switch will play a short tune by using the buzzer and setting a list of
different frequencies which will make a different tone when played.

## Fourth Button
Finally, the last switch will play a different note each time pressed. More
specifically it will play the notes C, D, E, F, G, A, and B.
