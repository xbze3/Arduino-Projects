# Dual Motor Joystick Control with Laser Activation

## Overview

This project uses a joystick to control a servo motor (Y-axis) and a stepper motor (X-axis). A laser module is activated while the system is operational. It demonstrates a versatile setup that integrates joystick-based control for both motor types.

## Components

-   Arduino board
-   Servo motor (connected to pin 9)
-   Stepper motor 28BYJ-48 with ULN2003 driver (connected to pins 2, 3, 4, 5)
-   Joystick (X-axis connected to A0, Y-axis connected to A1)
-   Laser module (connected to pin 4)

## Pin Configuration

-   **VRX (X-axis of joystick)**: A0
-   **VRY (Y-axis of joystick)**: A1
-   **Laser**: Pin 4
-   **Servo Motor**: Pin 9
-   **Stepper Motor**: Pins 2, 3, 4, 5

## Features

-   **Stepper Motor Control (X-axis)**: Move the joystick left or right to rotate the stepper motor.
-   **Servo Motor Control (Y-axis)**: Move the joystick up or down to adjust the servo motor's angle.
-   **Laser Activation**: Laser remains on during motor operation.
-   **Serial Output**: Debug information is printed to the serial monitor.

## Circuit Diagram

1. Connect the joystick X-axis to A0 and Y-axis to A1.
2. Connect the servo motor's control wire to pin 9.
3. Wire the ULN2003 driver to the stepper motor and connect the driver pins to 2, 3, 4, and 5 on the Arduino.
4. Connect the laser module to pin 4.

## Usage Instructions

1. Upload the code to your Arduino board.
2. Open the serial monitor at 9600 baud.
3. Move the joystick:
    - **X-axis (left/right)** controls the stepper motor.
    - **Y-axis (up/down)** controls the servo motor.
4. The laser will automatically activate when the system is running.

## Code Functionality

-   **Servo Control:** The joystick Y-axis adjusts the servo angle, constrained between 0 and 180 degrees.
-   **Stepper Control:** The joystick X-axis controls the stepper motor, incrementing or decrementing steps based on movement direction.
-   **Dead Zones:** Dead zones prevent small unintended movements from joystick snap-back.
-   **Laser Activation:** The laser is always on during active joystick input.

## Improvements

-   Add a button to toggle laser activation.
-   Implement more sophisticated speed control for the motors.
-   Integrate additional features, such as motor position memory.
