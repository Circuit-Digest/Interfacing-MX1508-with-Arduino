/*
This is a quick demo sketch for controlling N20 Type DC motor using the MX1508 breakout board.
We will control one motor and drive it forward and reverse.
To keep it simple, no user input is used.
Motor maximum voltage is 3.3V.

Pin connections (Arduino UNO):
6  To Motor Controller Port IN2 (Backward)
5  To Motor Controller Port IN1 (Forward)

Features:
- Drive motor forward and reverse
- Adjustable speed and duration
*/

// Define pin connections and settings
const int ForwardPin = 6;   // Pin for forward motor control
const int BackwardPin = 5;  // Pin for backward motor control
const long ActionTime = 200; // Duration for motor action (milliseconds)
const int MaxSpeed = 110;    // Maximum speed (0-255)
bool DirectionFlag = true; // Direction flag for motor control

void setup() {
  // Set motor control pins as outputs
  pinMode(ForwardPin, OUTPUT);
  pinMode(BackwardPin, OUTPUT);
}

void loop() {
  if (DirectionFlag) {
    // Drive motor forward
    analogWrite(ForwardPin, MaxSpeed);  // Send instructions to forward motor pin
    delay(ActionTime);                  // Wait for specified action time
    analogWrite(ForwardPin, 0);         // Stop motor
    DirectionFlag = !DirectionFlag;     // Toggle direction flag
    delay(20);                          // Short delay before changing direction
  } else {
    // Drive motor backward
    analogWrite(BackwardPin, MaxSpeed); // Send instructions to backward motor pin
    delay(ActionTime);                  // Wait for specified action time
    analogWrite(BackwardPin, 0);        // Stop motor
    DirectionFlag = !DirectionFlag;     // Toggle direction flag
    delay(20);                          // Short delay before changing direction
  }
}
