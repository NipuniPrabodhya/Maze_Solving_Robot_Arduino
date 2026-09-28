# Maze Solving Algorithm

This document explains the basic maze solving logic used in the Arduino wall maze solving robot.

## 1. Algorithm Type

The robot uses the **left-hand wall following algorithm**.

This means the robot gives first priority to the left side when deciding where to move inside the maze.

The robot checks the available paths using three ultrasonic sensors:

- Left sensor
- Front sensor
- Right sensor

## 2. Sensor Inputs

| Sensor | Purpose |
|---|---|
| Left ultrasonic sensor | Checks whether the left side is free or blocked |
| Front ultrasonic sensor | Checks whether there is an obstacle in front |
| Right ultrasonic sensor | Checks whether the right side is free or blocked |

## 3. Movement Decision Logic

| Priority | Condition | Robot Action |
|---:|---|---|
| 1 | Left side is free | Turn left |
| 2 | Left side is blocked and front side is free | Move forward |
| 3 | Left and front sides are blocked, but right side is free | Turn right |
| 4 | Left, front, and right sides are blocked | Turn back |

## 4. Pseudocode

```text
Read left distance
Read front distance
Read right distance

If left distance is greater than wall limit:
    Turn left

Else if front distance is greater than wall limit:
    Move forward

Else if right distance is greater than wall limit:
    Turn right

Else:
    Turn back
```

## 5. Wall Limit

The wall limit is the minimum distance used to decide whether a path is blocked or free.

For this project, the wall limit is set to:

| Parameter | Value |
|---|---:|
| Wall limit | 20 cm |

## 6. Distance Decision Table

| Distance Reading | Meaning |
|---|---|
| Less than or equal to 20 cm | Wall detected |
| Greater than 20 cm | Path is free |

## 7. Example 1: Left Path Free

| Sensor | Distance |
|---|---:|
| Left | 35 cm |
| Front | 10 cm |
| Right | 15 cm |

### Decision

The robot will **turn left** because the left side is free.

## 8. Example 2: Front Path Free

| Sensor | Distance |
|---|---:|
| Left | 12 cm |
| Front | 40 cm |
| Right | 18 cm |

### Decision

The robot will **move forward** because the left side is blocked, but the front side is free.

## 9. Example 3: Right Path Free

| Sensor | Distance |
|---|---:|
| Left | 10 cm |
| Front | 15 cm |
| Right | 35 cm |

### Decision

The robot will **turn right** because the left and front sides are blocked, but the right side is free.

## 10. Example 4: Dead End

| Sensor | Distance |
|---|---:|
| Left | 8 cm |
| Front | 10 cm |
| Right | 9 cm |

### Decision

The robot will **turn back** because all three directions are blocked.

## 11. Algorithm Flow

| Step | Action |
|---:|---|
| 1 | Read distance from left sensor |
| 2 | Read distance from front sensor |
| 3 | Read distance from right sensor |
| 4 | Compare each distance with the wall limit |
| 5 | Select movement based on left-hand rule |
| 6 | Move the robot |
| 7 | Repeat the process |

## 12. Advantages of Left-Hand Rule

| Advantage | Explanation |
|---|---|
| Simple logic | Easy to implement using Arduino |
| Low memory usage | Does not need to store the full maze |
| Suitable for beginners | Works well for basic wall maze robots |
| Uses basic sensors | Can be implemented using ultrasonic sensors |

## 13. Limitations

| Limitation | Explanation |
|---|---|
| Not always shortest path | The robot may take a longer route |
| Depends on maze design | Works best when maze walls are connected |
| Turning accuracy needed | Inaccurate turns can affect navigation |
| Sensor noise | Ultrasonic readings may sometimes fluctuate |

## 14. Future Improvements

| Improvement | Purpose |
|---|---|
| PID control | Improve smooth movement |
| Wheel encoders | Improve turning accuracy |
| Shortest path algorithm | Find the shortest route after learning the maze |
| Better distance sensors | Improve wall detection accuracy |
| Speed control tuning | Improve stability inside the maze |

## 15. Summary

The maze solving robot uses three ultrasonic sensors to detect walls on the left, front, and right sides. Based on the left-hand wall following algorithm, the robot gives priority to turning left, then moving forward, then turning right, and finally turning back when it reaches a dead end.