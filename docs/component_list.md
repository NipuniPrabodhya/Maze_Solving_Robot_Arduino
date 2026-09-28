# Component List

This document lists the main hardware components required for the Arduino wall maze solving robot.

| Component | Quantity | Purpose |
|---|---:|---|
| Arduino Uno | 1 | Main microcontroller for controlling the robot |
| L298N Motor Driver Module | 1 | Controls the speed and direction of the DC motors |
| DC Gear Motors | 2 | Provides movement for the robot |
| Wheels | 2 | Attached to the DC motors |
| Caster Wheel | 1 | Provides balance support for the robot chassis |
| HC-SR04 Ultrasonic Sensors | 3 | Detects walls in front, left, and right directions |
| Robot Chassis | 1 | Holds all robot components together |
| Battery Pack | 1 | Provides power to the motors |
| Jumper Wires | Several | Used for circuit connections |
| USB Cable | 1 | Used to upload code to the Arduino Uno |
| Power Switch | 1 | Optional switch for turning the robot on and off |

## Main Sensor Setup

The robot uses three ultrasonic sensors:

- Front sensor: detects obstacles in front of the robot
- Left sensor: detects the left wall
- Right sensor: detects the right wall

## Motor Setup

The robot uses two DC motors:

- Left motor
- Right motor

These motors are controlled using the L298N motor driver module.