#include <Servo.h>

int ledPin = 13;  // LED connected to digital pin 13
Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  servo1.attach(9);  // Attach servo to pin 9
  servo2.attach(10); // Attach servo to pin 10
  servo1.write(0); // Set the first servo angle
    servo2.write(0); // Set the second servo angle

    delay(15); // Delay to allow the servo to reach the desired position
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {
      digitalWrite(ledPin, HIGH);
      servo1.write(90); // Set the first servo angle
    servo2.write(180); // Set the second servo angle

    delay(15); // Delay to allow the servo to reach the desired position
    } else if (command == '0') {
      digitalWrite(ledPin, LOW);
      servo1.write(0); // Set the first servo angle
    servo2.write(0); // Set the second servo angle

    delay(15); // Delay to allow the servo to reach the desired position
    }
  }
}