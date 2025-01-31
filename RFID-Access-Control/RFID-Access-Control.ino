/*
 * RFID Access Control with LED Feedback
 * ====================================
 * This project uses an RFID reader to grant or deny access based on a predefined card ID.
 * If the detected card ID matches the known card, access is granted with a green LED;
 * otherwise, access is denied with a red LED.
 * 
 * Components:
 * - Arduino board
 * - RC522 RFID module
 * - Green, Yellow, Red LEDs
 *
 * Author: xbze3
 */

#include <SPI.h>
#include <RFID.h>

// Pin Definitions for Elegoo Mega
#define SDA_DIO 9           // RFID SDA (SS) Pin
#define RESET_DIO 8         // RFID RESET Pin
#define GREEN_LED 5         // Green LED Pin (Access granted)
#define YELLOW_LED 4        // Yellow LED Pin (Status)
#define RED_LED 3           // Red LED Pin (Access denied)

// Initialize RFID object
RFID RC522(SDA_DIO, RESET_DIO);

// Predefined card ID to compare
int knownCardID[5] = {0, 0, 0, 0, 0};  // Replace these values with your card's serial numbers

void setup() {
  Serial.begin(9600);    // Start serial communication
  SPI.begin();           // Start the SPI bus
  RC522.init();          // Initialize RFID module

  // Set LED pins as outputs
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  Serial.println("Place your RFID card near the reader...");
}

void loop() {
  digitalWrite(YELLOW_LED, HIGH);  // Turn on Yellow LED indicating readiness

  // Check if a card is detected
  if (RC522.isCard()) {
    RC522.readCardSerial();  // Read card serial number
    Serial.print("Card detected: ");
    
    bool isMatch = true;

    // Display and compare detected card ID
    for (int i = 0; i < 5; i++) {
      Serial.print(RC522.serNum[i], DEC);
      Serial.print(" ");
      
      // Compare the detected card ID with the known card ID
      if (RC522.serNum[i] != knownCardID[i]) {
        isMatch = false;
      }
    }
    Serial.println();

    // LED feedback based on comparison
    if (isMatch) {
      Serial.println("Access granted!");
      digitalWrite(GREEN_LED, HIGH);    // Turn on Green LED
      digitalWrite(YELLOW_LED, LOW);    // Turn off Yellow LED
      delay(5000);                      // Keep Green LED on for 5 seconds
    } else {
      Serial.println("Access denied!");
      digitalWrite(RED_LED, HIGH);      // Turn on Red LED
      digitalWrite(YELLOW_LED, LOW);    // Turn off Yellow LED
      delay(5000);                      // Keep Red LED on for 5 seconds
    }

    // Turn off all LEDs after the delay
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, LOW);
  }
}
