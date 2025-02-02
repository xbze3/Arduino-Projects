/*
 * Dual Motor Joystick Control with Laser Activation
 * ==================================================
 * This project uses a joystick to control a servo motor (Y-axis) and a stepper motor (X-axis).
 * A laser is activated while the system is in operation.
 * 
 * Components:
 * - Arduino board
 * - Servo motor (connected to pin 9)
 * - Stepper motor 28BYJ-48 with ULN2003 driver (connected to pins 2, 3, 4, 5)
 * - Joystick (X-axis connected to A0, Y-axis connected to A1)
 * - Laser module (connected to pin 4)
 *
 * Author: xbze3
 */

#include <Servo.h>
#include <Stepper.h>

// Pin Definitions
const int VRX_PIN = A0;         // Joystick X-axis pin (Stepper control)
const int VRY_PIN = A1;         // Joystick Y-axis pin (Servo control)
const int LASER_PIN = 7;        // Laser control pin
const int SERVO_PIN = 9;        // Servo control pin
const int STEPPER_PINS[4] = {2, 4, 3, 5}; // Stepper control pins

// Constants
const int DEAD_ZONE = 50;       // Dead zone for joystick movement
const int STEP_SIZE = 10;       // Step size for stepper motor commands
const int stepsPerRevolution = 2048; // Steps per revolution for stepper motor

const int SERVO_DEAD_ZONE = 100; // Dead zone for joystick Y-axis
const int MOVE_STEP = 1;         // Step size for servo movement
const int SERVO_MIN = 0;         // Minimum servo angle
const int SERVO_MAX = 180;       // Maximum servo angle

// Instances
Servo myServo;                  // Servo instance
Stepper myStepper(stepsPerRevolution, STEPPER_PINS[0], STEPPER_PINS[1], STEPPER_PINS[2], STEPPER_PINS[3]); // Stepper instance

// Variables
int servoAngle = 90;            // Initial servo angle (center position)
int motorPosition = 0;          // Current stepper motor position

void setup() {
  Serial.begin(9600);

  // Setup Servo
  myServo.attach(SERVO_PIN);
  myServo.write(servoAngle);    // Initialize servo position

  // Setup Stepper
  myStepper.setSpeed(15);       // Set stepper motor speed in RPM

  // Setup Laser
  pinMode(LASER_PIN, OUTPUT);
  digitalWrite(LASER_PIN, LOW); // Start with laser off

  Serial.println("Dual motor joystick control with laser activation started...");
}

void loop() {
  // Read joystick values
  int xValue = analogRead(VRX_PIN); // Joystick X-axis for stepper
  int yValue = analogRead(VRY_PIN); // Joystick Y-axis for servo

  // Turn laser on during operation
  digitalWrite(LASER_PIN, HIGH);

  // Stepper Motor Control (X-axis)
  if (xValue < (512 - DEAD_ZONE)) {
    Serial.println("Joystick Left: Moving stepper left");
    motorPosition += STEP_SIZE;   // Inverted direction logic
    myStepper.step(STEP_SIZE);
  } 
  else if (xValue > (512 + DEAD_ZONE)) {
    Serial.println("Joystick Right: Moving stepper right");
    motorPosition -= STEP_SIZE;   // Inverted direction logic
    myStepper.step(-STEP_SIZE);
  }

  // Servo Motor Control (Y-axis)
  if (yValue < (512 - SERVO_DEAD_ZONE)) {
    // Joystick pushed up, move servo left
    servoAngle = max(SERVO_MIN, servoAngle - MOVE_STEP);
    myServo.write(servoAngle);
    Serial.print("Move Up: ");
    Serial.println(servoAngle);
  } 
  else if (yValue > (512 + SERVO_DEAD_ZONE)) {
    // Joystick pushed down, move servo right
    servoAngle = min(SERVO_MAX, servoAngle + MOVE_STEP);
    myServo.write(servoAngle);
    Serial.print("Move Down: ");
    Serial.println(servoAngle);
  }

  delay(30); // Short delay to stabilize readings
}
