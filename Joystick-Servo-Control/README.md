# Servo Joystick Control with Laser Activation

This project demonstrates how to control a servo motor using a joystick on an Arduino. The laser module turns on while the system is active.

## Components

-   Arduino board
-   Joystick module
-   Servo motor
-   Laser module
-   Connecting wires

## Features

-   Smooth servo control with joystick input
-   Dead zone filtering to prevent snap-back
-   Laser activation during operation

## Wiring

| Component       | Arduino Pin |
| --------------- | ----------- |
| Joystick X-axis | A0          |
| Servo           | 9           |
| Laser           | 4           |

## Usage

1. Connect the components as per the wiring table.
2. Upload the code to your Arduino.
3. Move the joystick to control the servo.
