/*
 * Servo Control Using Potentiometer
 * ================================
 * This project uses a potentiometer to control the position of a servo motor.
 * The servo's position is mapped based on the potentiometer value (0-1023),
 * and the position is adjusted from 0° to 180°.
 * A laser is turned on while the system is active.
 * 
 * Components:
 * - Arduino board
 * - Servo motor (connected to pin 9)
 * - Potentiometer (connected to analog pin A0)
 * - Laser module (connected to pin 4)
 *
 * Author: xbze3
 */

#include <Servo.h>

// Pin Definitions
const char POT_PIN = A0;  // Potentiometer input pin (Analog)
const int laserPin = 4;   // Laser control pin (Digital)

// Create Servo object
Servo myServo;

void setup() {
  Serial.begin(9600);         // Start serial communication
  myServo.attach(9);         // Attach servo to pin 9 (change as needed)
  pinMode(laserPin, OUTPUT); // Set laser pin as output
}

void loop() {
  int analogValue = analogRead(POT_PIN);  // Read potentiometer value (0-1023)
  digitalWrite(laserPin, HIGH);           // Turn on laser while system is active

  // Map the potentiometer value to servo angle (0° to 180°)
  int servoAngle = map(analogValue, 0, 1023, 0, 180);

  // Move the servo to the mapped angle
  myServo.write(servoAngle);

  // Output the potentiometer value and corresponding servo angle to Serial Monitor
  Serial.print("Analog Value: ");
  Serial.print(analogValue);
  Serial.print(" -> Servo Angle: ");
  Serial.println(servoAngle);

  delay(15); // Small delay for stability
}
