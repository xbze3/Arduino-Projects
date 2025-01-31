/*
 * Servo Joystick Control with Laser Activation
 * =============================================
 * This project uses a joystick to control the movement of a servo motor.
 * A laser is turned on while the system is active.
 * 
 * Components:
 * - Arduino board
 * - Servo motor (connected to pin 9)
 * - Joystick (X-axis connected to A0)
 * - Laser module (connected to pin 4)
 *
 * Author: xbze3
 */

#include <Servo.h>

// Pin Definitions
const int VRX_PIN = A0;         // Joystick X-axis pin
const int LASER_PIN = 4;        // Laser control pin
const int SERVO_PIN = 9;        // Servo control pin

// Constants
const int DEAD_ZONE = 100;      // Dead zone to ignore joystick snap-back
const int MOVE_STEP = 1;        // Step size for servo movement
const int SERVO_MIN = 0;        // Minimum servo angle
const int SERVO_MAX = 180;      // Maximum servo angle

Servo myServo;                  // Servo instance
int servoAngle = 90;            // Initial servo angle (center position)

void setup() {
  Serial.begin(9600);
  myServo.attach(SERVO_PIN);    // Attach servo to pin 9
  myServo.write(servoAngle);    // Initialize servo position
  pinMode(LASER_PIN, OUTPUT);   // Set laser pin as output
  digitalWrite(LASER_PIN, LOW); // Start with laser off
}

void loop() {
  int xValue = analogRead(VRX_PIN); // Read joystick X-axis value
  digitalWrite(LASER_PIN, HIGH);    // Turn laser on

  // Detect joystick movement outside the dead zone
  if (xValue < (512 - DEAD_ZONE)) {
    // Joystick pushed left, move servo left
    servoAngle = max(SERVO_MIN, servoAngle - MOVE_STEP);
    myServo.write(servoAngle);
    Serial.print("Move Left: ");
    Serial.println(servoAngle);
  } 
  else if (xValue > (512 + DEAD_ZONE)) {
    // Joystick pushed right, move servo right
    servoAngle = min(SERVO_MAX, servoAngle + MOVE_STEP);
    myServo.write(servoAngle);
    Serial.print("Move Right: ");
    Serial.println(servoAngle);
  }

  delay(30); // Reduce polling frequency
}
