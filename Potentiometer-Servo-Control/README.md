# Servo Control Using Potentiometer

This project demonstrates how to use a potentiometer to control the position of a servo motor. The servo's angle is adjusted based on the potentiometer value, which is mapped from 0° to 180°. A laser is activated while the system is running.

## Components

-   Arduino board
-   Servo motor (e.g., SG90)
-   Potentiometer
-   Laser module
-   Connecting wires

## Features

-   Servo position controlled by potentiometer
-   Laser activation during operation
-   Serial monitor output showing potentiometer value and servo angle

## Wiring

| Component     | Arduino Pin (Mega) |
| ------------- | ------------------ |
| Potentiometer | A0                 |
| Servo         | D9                 |
| Laser         | D4                 |

## Usage

1. Connect the components as per the wiring table.
2. Upload the code to your Arduino.
3. Rotate the potentiometer to control the servo position.
4. The laser will turn on while the system is active.
