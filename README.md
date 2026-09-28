# Maze Solving Robot Arduino

This project is an Arduino-based wall maze solving robot developed using PlatformIO. The robot uses two DC motors, an L298N motor driver, and ultrasonic sensors to detect walls and navigate through a maze.

## Project Objective

The objective of this project is to build an autonomous robot car that can solve a wall maze using sensor-based decision making.

## Components Used

- Arduino Uno
- L298N motor driver module
- 2 DC gear motors
- 2 wheels
- 1 caster wheel
- 3 HC-SR04 ultrasonic sensors
- Robot chassis
- Battery pack
- Jumper wires
- USB cable

## Features

- Motor control using L298N motor driver
- Wall detection using ultrasonic sensors
- Left, front, and right distance measurement
- Basic wall-following maze solving logic
- PlatformIO-based project structure

## Maze Solving Logic

The robot uses the left-hand wall following algorithm:

1. If the left side is free, turn left.
2. Else if the front side is free, move forward.
3. Else if the right side is free, turn right.
4. Else turn back.

## Project Structure

```text
Maze Solving Robot/
│
├── include/
├── lib/
├── src/
│   └── main.cpp
├── test/
├── platformio.ini
├── README.md
└── .gitignore