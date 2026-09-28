#include <Arduino.h>

// Ultrasonic Sensor Pins
#define FRONT_TRIG 2
#define FRONT_ECHO 3

#define LEFT_TRIG 4
#define LEFT_ECHO 7

#define RIGHT_TRIG 12
#define RIGHT_ECHO 13

// L298N Motor Driver Pins
#define ENA 5
#define IN1 8
#define IN2 9

#define ENB 6
#define IN3 10
#define IN4 11

// Settings
int motorSpeed = 160;       // Speed range: 0 - 255
int wallLimit = 20;         // Distance in cm to decide wall/free path

// Function declarations
long getDistance(int trigPin, int echoPin);
void forward();
void backward();
void turnLeft();
void turnRight();
void turnBack();
void stopRobot();

void setup() {
  Serial.begin(9600);

  // Ultrasonic sensor pins
  pinMode(FRONT_TRIG, OUTPUT);
  pinMode(FRONT_ECHO, INPUT);

  pinMode(LEFT_TRIG, OUTPUT);
  pinMode(LEFT_ECHO, INPUT);

  pinMode(RIGHT_TRIG, OUTPUT);
  pinMode(RIGHT_ECHO, INPUT);

  // Motor driver pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopRobot();

  Serial.println("Maze Solving Robot Started");
}

void loop() {
  long leftDistance = getDistance(LEFT_TRIG, LEFT_ECHO);
  delay(50);

  long frontDistance = getDistance(FRONT_TRIG, FRONT_ECHO);
  delay(50);

  long rightDistance = getDistance(RIGHT_TRIG, RIGHT_ECHO);
  delay(50);

  Serial.print("LEFT: ");
  Serial.print(leftDistance);
  Serial.print(" cm   |   FRONT: ");
  Serial.print(frontDistance);
  Serial.print(" cm   |   RIGHT: ");
  Serial.print(rightDistance);
  Serial.println(" cm");

  // Left-hand wall following algorithm
  if (leftDistance > wallLimit) {
    stopRobot();
    delay(100);

    turnLeft();
    delay(450);

    stopRobot();
    delay(100);
  }
  else if (frontDistance > wallLimit) {
    forward();
  }
  else if (rightDistance > wallLimit) {
    stopRobot();
    delay(100);

    turnRight();
    delay(450);

    stopRobot();
    delay(100);
  }
  else {
    stopRobot();
    delay(100);

    turnBack();
    delay(850);

    stopRobot();
    delay(100);
  }
}

long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    return 999; // No object detected
  }

  long distance = duration * 0.034 / 2;
  return distance;
}

void forward() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  // Left motor backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Right motor forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  // Left motor forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right motor backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnBack() {
  turnRight();
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}