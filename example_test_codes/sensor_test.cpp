#include <Arduino.h>

// Ultrasonic Sensor Pins
#define FRONT_TRIG 2
#define FRONT_ECHO 3

#define LEFT_TRIG 4
#define LEFT_ECHO 7

#define RIGHT_TRIG 12
#define RIGHT_ECHO 13

long getDistance(int trigPin, int echoPin);

void setup() {
  Serial.begin(9600);

  pinMode(FRONT_TRIG, OUTPUT);
  pinMode(FRONT_ECHO, INPUT);

  pinMode(LEFT_TRIG, OUTPUT);
  pinMode(LEFT_ECHO, INPUT);

  pinMode(RIGHT_TRIG, OUTPUT);
  pinMode(RIGHT_ECHO, INPUT);

  Serial.println("Ultrasonic Sensor Test Started");
}

void loop() {
  long leftDistance = getDistance(LEFT_TRIG, LEFT_ECHO);
  long frontDistance = getDistance(FRONT_TRIG, FRONT_ECHO);
  long rightDistance = getDistance(RIGHT_TRIG, RIGHT_ECHO);

  Serial.print("LEFT: ");
  Serial.print(leftDistance);
  Serial.print(" cm   |   FRONT: ");
  Serial.print(frontDistance);
  Serial.print(" cm   |   RIGHT: ");
  Serial.print(rightDistance);
  Serial.println(" cm");

  delay(500);
}

long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    return 999; // No object detected / out of range
  }

  long distance = duration * 0.034 / 2;
  return distance;
}