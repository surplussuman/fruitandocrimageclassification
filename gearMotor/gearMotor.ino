// // Define pin numbers
// const int IN1 = 5; // Pin connected to IN1 on the motor driver
// const int IN2 = 6; // Pin connected to IN2 on the motor driver

// void setup() {
//   // Set the motor control pins as outputs
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);
// }

// void loop() {
//   // Rotate motor in one direction
//   digitalWrite(IN1, HIGH);  
//   digitalWrite(IN2, LOW);
//   delay(2000); // Run for 2 seconds

//   // Stop the motor
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, LOW);
//   delay(1000); // Wait for 1 second

//   // Rotate motor in the opposite direction
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, HIGH);
//   delay(2000); // Run for 2 seconds

//   // Stop the motor
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, LOW);
//   delay(1000); // Wait for 1 second
// }


#include <Servo.h>

const int motorPin1 = 5; // Gear motor control pin 1
const int motorPin2 = 6; // Gear motor control pin 2
const int servoPin = 9;  // Servo control pin

Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  myServo.attach(servoPin);
  myServo.write(0); // Start position of the servo
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    
    switch (command) {
      case 'R': // Run motor
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
        break;
      case 'S': // Stop motor
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
        break;
      case 'A': // Activate servo
        myServo.write(90); // Move servo to 90 degrees
        delay(1000); // Wait for 1 second
        myServo.write(0); // Return to start position
        break;
    }
  }
}
