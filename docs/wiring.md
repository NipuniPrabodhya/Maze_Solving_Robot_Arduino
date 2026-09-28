# Wiring Guide

This document explains the wiring connections for the Arduino wall maze solving robot.

## 1. Motor Connections to L298N

| L298N Pin | Connect To |
|---|---|
| OUT1 | Left motor wire 1 |
| OUT2 | Left motor wire 2 |
| OUT3 | Right motor wire 1 |
| OUT4 | Right motor wire 2 |

If a motor rotates in the opposite direction, swap that motor's two wires.

## 2. L298N to Arduino Uno

| L298N Pin | Arduino Uno Pin |
|---|---|
| ENA | D5 |
| IN1 | D8 |
| IN2 | D9 |
| IN3 | D10 |
| IN4 | D11 |
| ENB | D6 |
| GND | GND |

ENA and ENB are used for motor speed control using PWM.

## 3. Power Connections

| L298N Pin | Connect To |
|---|---|
| 12V | Battery positive |
| GND | Battery negative |
| GND | Arduino GND |
| 5V | Do not connect first during USB testing |

Important: Arduino GND, L298N GND, and battery negative must be connected together.

For safe testing:

```text
Laptop USB → Arduino Uno
Battery pack → L298N motor power

Do not power motors only from the Arduino USB cable.
4. Ultrasonic Sensor Connections
The robot uses three HC-SR04 ultrasonic sensors: front, left, and right.
Front Sensor
HC-SR04 Pin	Arduino Uno Pin
VCC	5V
GND	GND
TRIG	D2
ECHO	D3


Left Sensor
HC-SR04 Pin	Arduino Uno Pin
VCC	5V
GND	GND
TRIG	D4
ECHO	D7


Right Sensor
HC-SR04 Pin	Arduino Uno Pin
VCC	5V
GND	GND
TRIG	D12
ECHO	D13


5. Sensor Placement
          Front Ultrasonic Sensor
                    ↑

Left Ultrasonic Sensor ← Robot → Right Ultrasonic Sensor

          Left Motor        Right Motor

6. Full Pin Summary
Function	Arduino Pin
Motor ENA	D5
Motor IN1	D8
Motor IN2	D9
Motor ENB	D6
Motor IN3	D10
Motor IN4	D11
Front TRIG	D2
Front ECHO	D3
Left TRIG	D4
Left ECHO	D7
Right TRIG	D12
Right ECHO	D13