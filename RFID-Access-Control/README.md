# RFID Access Control with LED Feedback

This project demonstrates how to use an RFID reader to grant or deny access based on a predefined card ID. The system uses LEDs to provide visual feedback: a green LED for granted access, a red LED for denied access, and a yellow LED indicating that the system is active.

## Components

-   Arduino board (e.g., Elegoo Mega)
-   RC522 RFID module
-   Green, Yellow, Red LEDs
-   220-ohm resistors (for LEDs)
-   Connecting wires

## Features

-   RFID card detection
-   Access granted/denied with LEDs
-   Serial monitor feedback

## Wiring

| Component  | Arduino Pin (Mega) |
| ---------- | ------------------ |
| RFID SDA   | D9                 |
| RFID SCK   | D52                |
| RFID MOSI  | D51                |
| RFID MISO  | D50                |
| RFID RST   | D8                 |
| Green LED  | D5                 |
| Yellow LED | D4                 |
| Red LED    | D3                 |

## Usage

1. Connect the components as per the wiring table.
2. Upload the code to your Arduino.
3. Place your RFID card near the reader.
