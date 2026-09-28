// #include <Arduino.h>

// // ----------------------
// // Motor Pin Definitions
// // ----------------------
// constexpr uint8_t ENA = 5;
// constexpr uint8_t IN1 = 8;
// constexpr uint8_t IN2 = 9;

// constexpr uint8_t ENB = 6;
// constexpr uint8_t IN3 = 10;
// constexpr uint8_t IN4 = 11;

// // Motor Speed (0 - 255)
// constexpr uint8_t MOTOR_SPEED = 180;

// // Function Prototypes
// void forward();
// void backward();
// void turnLeft();
// void turnRight();
// void stopRobot();

// void setup()
// {
//     pinMode(ENA, OUTPUT);
//     pinMode(IN1, OUTPUT);
//     pinMode(IN2, OUTPUT);

//     pinMode(ENB, OUTPUT);
//     pinMode(IN3, OUTPUT);
//     pinMode(IN4, OUTPUT);

//     Serial.begin(115200);

//     stopRobot();
// }

// void loop()
// {
//     Serial.println("Forward");
//     forward();
//     delay(2000);

//     stopRobot();
//     delay(1000);

//     Serial.println("Backward");
//     backward();
//     delay(2000);

//     stopRobot();
//     delay(1000);

//     Serial.println("Left");
//     turnLeft();
//     delay(1000);

//     stopRobot();
//     delay(1000);

//     Serial.println("Right");
//     turnRight();
//     delay(1000);

//     stopRobot();
//     delay(2000);
// }

// void forward()
// {
//     analogWrite(ENA, MOTOR_SPEED);
//     analogWrite(ENB, MOTOR_SPEED);

//     digitalWrite(IN1, HIGH);
//     digitalWrite(IN2, LOW);

//     digitalWrite(IN3, HIGH);
//     digitalWrite(IN4, LOW);
// }

// void backward()
// {
//     analogWrite(ENA, MOTOR_SPEED);
//     analogWrite(ENB, MOTOR_SPEED);

//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, HIGH);

//     digitalWrite(IN3, LOW);
//     digitalWrite(IN4, HIGH);
// }

// void turnLeft()
// {
//     analogWrite(ENA, MOTOR_SPEED);
//     analogWrite(ENB, MOTOR_SPEED);

//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, HIGH);

//     digitalWrite(IN3, HIGH);
//     digitalWrite(IN4, LOW);
// }

// void turnRight()
// {
//     analogWrite(ENA, MOTOR_SPEED);
//     analogWrite(ENB, MOTOR_SPEED);

//     digitalWrite(IN1, HIGH);
//     digitalWrite(IN2, LOW);

//     digitalWrite(IN3, LOW);
//     digitalWrite(IN4, HIGH);
// }

// void stopRobot()
// {
//     analogWrite(ENA, 0);
//     analogWrite(ENB, 0);

//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, LOW);

//     digitalWrite(IN3, LOW);
//     digitalWrite(IN4, LOW);
// } 


//sensor code
// #include <Arduino.h>

// const int trigPin = 9;
// const int echoPin = 10;

// void setup() {
//     Serial.begin(9600);

//     pinMode(trigPin, OUTPUT);
//     pinMode(echoPin, INPUT);

//     digitalWrite(trigPin, LOW);

//     Serial.println("Ultrasonic Sensor Test");
// }

// void loop() {
//     // Send ultrasonic pulse
//     digitalWrite(trigPin, LOW);
//     delayMicroseconds(2);

//     digitalWrite(trigPin, HIGH);
//     delayMicroseconds(10);

//     digitalWrite(trigPin, LOW);

//     // Read echo
//     long duration = pulseIn(echoPin, HIGH, 30000);

//     if (duration == 0) {
//         Serial.println("No object detected");
//     } else {
//         float distance = duration * 0.0343 / 2.0;

//         Serial.print("Distance: ");
//         Serial.print(distance);
//         Serial.println(" cm");
//     }

//     delay(500);
// }



//motor test
// #include <Arduino.h>

// // LEFT MOTOR
// #define ENA 5
// #define IN1 7
// #define IN2 8

// // RIGHT MOTOR
// #define ENB 6
// #define IN3 9
// #define IN4 10

// int motorSpeed = 180;   // 0 - 255

// void forward() {
//     // Left motor forward
//     digitalWrite(IN1, HIGH);
//     digitalWrite(IN2, LOW);

//     // Right motor forward
//     digitalWrite(IN3, HIGH);
//     digitalWrite(IN4, LOW);

//     analogWrite(ENA, motorSpeed);
//     analogWrite(ENB, motorSpeed);
// }

// void backward() {
//     // Left motor backward
//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, HIGH);

//     // Right motor backward
//     digitalWrite(IN3, LOW);
//     digitalWrite(IN4, HIGH);

//     analogWrite(ENA, motorSpeed);
//     analogWrite(ENB, motorSpeed);
// }

// void turnLeft() {
//     // Left motor backward
//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, HIGH);

//     // Right motor forward
//     digitalWrite(IN3, HIGH);
//     digitalWrite(IN4, LOW);

//     analogWrite(ENA, motorSpeed);
//     analogWrite(ENB, motorSpeed);
// }

// void turnRight() {
//     // Left motor forward
//     digitalWrite(IN1, HIGH);
//     digitalWrite(IN2, LOW);

//     // Right motor backward
//     digitalWrite(IN3, LOW);
//     digitalWrite(IN4, HIGH);

//     analogWrite(ENA, motorSpeed);
//     analogWrite(ENB, motorSpeed);
// }

// void stopMotors() {
//     analogWrite(ENA, 0);
//     analogWrite(ENB, 0);

//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, LOW);
//     digitalWrite(IN3, LOW);
//     digitalWrite(IN4, LOW);
// }

// void setup() {
//     Serial.begin(9600);

//     pinMode(ENA, OUTPUT);
//     pinMode(IN1, OUTPUT);
//     pinMode(IN2, OUTPUT);

//     pinMode(ENB, OUTPUT);
//     pinMode(IN3, OUTPUT);
//     pinMode(IN4, OUTPUT);

//     stopMotors();

//     Serial.println("Motor Test Starting...");
// }

// void loop() {

//     Serial.println("FORWARD");
//     forward();
//     delay(2000);

//     Serial.println("STOP");
//     stopMotors();
//     delay(1000);

//     Serial.println("BACKWARD");
//     backward();
//     delay(2000);

//     Serial.println("STOP");
//     stopMotors();
//     delay(1000);

//     Serial.println("TURN LEFT");
//     turnLeft();
//     delay(1500);

//     Serial.println("STOP");
//     stopMotors();
//     delay(1000);

//     Serial.println("TURN RIGHT");
//     turnRight();
//     delay(1500);

//     Serial.println("STOP");
//     stopMotors();
//     delay(3000);
// }


//3 sensor check
// 

//object folowwing robot
// #include <Arduino.h>

// // =====================================================
// // HC-SR04 ULTRASONIC SENSOR PINS
// // =====================================================

// // Front sensor
// #define FRONT_TRIG 2
// #define FRONT_ECHO 3

// // Left sensor
// #define LEFT_TRIG 4
// #define LEFT_ECHO 11

// // Right sensor
// #define RIGHT_TRIG 12
// #define RIGHT_ECHO 13


// // =====================================================
// // L298N MOTOR DRIVER PINS
// // =====================================================

// // Left motor
// #define ENA 5
// #define IN1 7
// #define IN2 8

// // Right motor
// #define ENB 6
// #define IN3 9
// #define IN4 10


// // =====================================================
// // OBJECT FOLLOWING SETTINGS
// // =====================================================

// // Stop if object is closer than this
// const float STOP_DISTANCE = 7.0;       // cm

// // Follow object only up to this distance
// const float FOLLOW_DISTANCE = 20.0;    // cm

// // Motor speeds (0 - 255)
// const int FORWARD_SPEED = 150;
// const int TURN_SPEED = 145;


// // =====================================================
// // READ DISTANCE
// // =====================================================

// float readDistance(int trigPin, int echoPin)
// {
//     // Make sure trigger starts LOW
//     digitalWrite(trigPin, LOW);
//     delayMicroseconds(2);

//     // Send 10 microsecond pulse
//     digitalWrite(trigPin, HIGH);
//     delayMicroseconds(10);
//     digitalWrite(trigPin, LOW);

//     // Read echo
//     unsigned long duration =
//         pulseIn(echoPin, HIGH, 25000);

//     // No echo detected
//     if (duration == 0)
//     {
//         return 999.0;
//     }

//     // Convert time to distance in cm
//     float distance =
//         (duration * 0.0343) / 2.0;

//     return distance;
// }


// // =====================================================
// // STOP
// // =====================================================

// void stopRobot()
// {
//     analogWrite(ENA, 0);
//     analogWrite(ENB, 0);

//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, LOW);

//     digitalWrite(IN3, LOW);
//     digitalWrite(IN4, LOW);
// }


// // =====================================================
// // FORWARD
// // =====================================================

// void moveForward()
// {
//     // Left motor forward
//     digitalWrite(IN1, HIGH);
//     digitalWrite(IN2, LOW);

//     // Right motor forward
//     digitalWrite(IN3, HIGH);
//     digitalWrite(IN4, LOW);

//     analogWrite(ENA, FORWARD_SPEED);
//     analogWrite(ENB, FORWARD_SPEED);
// }


// // =====================================================
// // TURN LEFT
// // =====================================================

// void turnLeft()
// {
//     // Stop left motor
//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, LOW);

//     // Right motor forward
//     digitalWrite(IN3, HIGH);
//     digitalWrite(IN4, LOW);

//     analogWrite(ENA, 0);
//     analogWrite(ENB, TURN_SPEED);
// }


// // =====================================================
// // TURN RIGHT
// // =====================================================

// void turnRight()
// {
//     // Left motor forward
//     digitalWrite(IN1, HIGH);
//     digitalWrite(IN2, LOW);

//     // Stop right motor
//     digitalWrite(IN3, LOW);
//     digitalWrite(IN4, LOW);

//     analogWrite(ENA, TURN_SPEED);
//     analogWrite(ENB, 0);
// }


// // =====================================================
// // SETUP
// // =====================================================

// void setup()
// {
//     Serial.begin(9600);

//     // Front sensor
//     pinMode(FRONT_TRIG, OUTPUT);
//     pinMode(FRONT_ECHO, INPUT);

//     // Left sensor
//     pinMode(LEFT_TRIG, OUTPUT);
//     pinMode(LEFT_ECHO, INPUT);

//     // Right sensor
//     pinMode(RIGHT_TRIG, OUTPUT);
//     pinMode(RIGHT_ECHO, INPUT);

//     // Motor driver
//     pinMode(ENA, OUTPUT);
//     pinMode(IN1, OUTPUT);
//     pinMode(IN2, OUTPUT);

//     pinMode(ENB, OUTPUT);
//     pinMode(IN3, OUTPUT);
//     pinMode(IN4, OUTPUT);

//     // Start safely
//     stopRobot();

//     Serial.println("============================");
//     Serial.println(" OBJECT FOLLOWING ROBOT");
//     Serial.println(" Detection range: 7 - 20 cm");
//     Serial.println("============================");
// }


// // =====================================================
// // MAIN LOOP
// // =====================================================

// void loop()
// {
//     // -----------------------------------------
//     // Read FRONT sensor
//     // -----------------------------------------
//     float front =
//         readDistance(FRONT_TRIG, FRONT_ECHO);

//     delay(50);


//     // -----------------------------------------
//     // Read LEFT sensor
//     // -----------------------------------------
//     float left =
//         readDistance(LEFT_TRIG, LEFT_ECHO);

//     delay(50);


//     // -----------------------------------------
//     // Read RIGHT sensor
//     // -----------------------------------------
//     float right =
//         readDistance(RIGHT_TRIG, RIGHT_ECHO);

//     delay(50);


//     // -----------------------------------------
//     // Display sensor readings
//     // -----------------------------------------

//     Serial.print("LEFT: ");
//     Serial.print(left, 1);
//     Serial.print(" cm");

//     Serial.print(" | FRONT: ");
//     Serial.print(front, 1);
//     Serial.print(" cm");

//     Serial.print(" | RIGHT: ");
//     Serial.print(right, 1);
//     Serial.print(" cm");

//     Serial.print(" | ACTION: ");


//     // =================================================
//     // OBJECT FOLLOWING LOGIC
//     // =================================================


//     // -----------------------------------------
//     // 1. Object TOO CLOSE in front
//     // -----------------------------------------
//     if (front < STOP_DISTANCE)
//     {
//         stopRobot();

//         Serial.println("STOP - TOO CLOSE");
//     }


//     // -----------------------------------------
//     // 2. Object in FRONT
//     // -----------------------------------------
//     else if (front >= STOP_DISTANCE &&
//              front <= FOLLOW_DISTANCE)
//     {
//         moveForward();

//         Serial.println("FORWARD");
//     }


//     // -----------------------------------------
//     // 3. Object on LEFT
//     // -----------------------------------------
//     else if (left >= STOP_DISTANCE &&
//              left <= FOLLOW_DISTANCE &&
//              left < right)
//     {
//         turnLeft();

//         Serial.println("TURN LEFT");
//     }


//     // -----------------------------------------
//     // 4. Object on RIGHT
//     // -----------------------------------------
//     else if (right >= STOP_DISTANCE &&
//              right <= FOLLOW_DISTANCE)
//     {
//         turnRight();

//         Serial.println("TURN RIGHT");
//     }


//     // -----------------------------------------
//     // 5. Nothing detected within 20 cm
//     // -----------------------------------------
//     else
//     {
//         stopRobot();

//         Serial.println("NO OBJECT - STOP");
//     }


//     delay(50);
// }


#include <Arduino.h>

// ==============================
// L298N PIN CONNECTIONS
// ==============================

// Left Motor
#define ENA 5
#define IN1 7
#define IN2 8

// Right Motor
#define ENB 6
#define IN3 9
#define IN4 10

// Motor speed: 0 - 255
const int MOTOR_SPEED = 160;


// ==============================
// STOP
// ==============================

void stopMotors()
{
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}


// ==============================
// FORWARD
// ==============================

void moveForward()
{
    // Left motor forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    // Right motor forward
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    analogWrite(ENA, MOTOR_SPEED);
    analogWrite(ENB, MOTOR_SPEED);
}


// ==============================
// BACKWARD
// ==============================

void moveBackward()
{
    // Left motor backward
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    // Right motor backward
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    analogWrite(ENA, MOTOR_SPEED);
    analogWrite(ENB, MOTOR_SPEED);
}


// ==============================
// LEFT - SPIN TURN
// ==============================

void turnLeft()
{
    // Left motor backward
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    // Right motor forward
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    analogWrite(ENA, MOTOR_SPEED);
    analogWrite(ENB, MOTOR_SPEED);
}


// ==============================
// RIGHT - SPIN TURN
// ==============================

void turnRight()
{
    // Left motor forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    // Right motor backward
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    analogWrite(ENA, MOTOR_SPEED);
    analogWrite(ENB, MOTOR_SPEED);
}


// ==============================
// SETUP
// ==============================

void setup()
{
    Serial.begin(9600);

    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    stopMotors();

    Serial.println("Motor Test Started");
}


// ==============================
// LOOP
// ==============================

void loop()
{
    // FORWARD
    Serial.println("FORWARD");

    moveForward();

    delay(2000);

    stopMotors();

    delay(1000);


    // BACKWARD
    Serial.println("BACKWARD");

    moveBackward();

    delay(2000);

    stopMotors();

    delay(1000);


    // LEFT
    Serial.println("LEFT");

    turnLeft();

    delay(1500);

    stopMotors();

    delay(1000);


    // RIGHT
    Serial.println("RIGHT");

    turnRight();

    delay(1500);

    stopMotors();

    delay(1000);


    // FINISHED
    Serial.println("TEST COMPLETE");

    stopMotors();

    delay(3000);
}