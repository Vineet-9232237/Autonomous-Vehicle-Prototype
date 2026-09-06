# Autonomous-Vehicle-Prototype

A four-wheel robotic vehicle prototype developed using **Arduino Uno, DC motors, Adafruit Motor Shield V1, and HC-05/HC-06 Bluetooth communication**. The project focuses on implementing vehicle movement, directional control, motor interfacing, and wireless command-based navigation.

The prototype demonstrates fundamental concepts used in **autonomous vehicles and mobile robotics**, including motor control, embedded programming, wireless communication, and directional decision-making.

## 📌 Project Overview

The vehicle is designed as a four-wheel robotic platform controlled by an Arduino microcontroller.

The **Arduino Uno** processes movement commands received through the **HC-05/HC-06 Bluetooth module** and controls four DC motors using the **Adafruit Motor Shield V1**.

The vehicle supports:

* Forward movement
* Backward movement
* Left turning
* Right turning
* Stop control

The project was developed as a prototype platform for understanding the hardware and control concepts involved in robotic and autonomous vehicles.

## ⚙️ Key Features

* Four-wheel robotic vehicle configuration
* Bluetooth-based wireless control
* Four DC motor control
* Independent motor direction control
* PWM-based motor speed control
* Forward and reverse movement
* Differential turning mechanism
* Emergency stop functionality
* Arduino-based embedded control

## 🧰 Hardware Components

| Component                      |    Quantity | Function                       |
| ------------------------------ | ----------: | ------------------------------ |
| Arduino Uno                    |           1 | Main microcontroller           |
| Adafruit Motor Shield V1       |           1 | Four-channel DC motor control  |
| DC Motors                      |           4 | Vehicle propulsion             |
| HC-05 / HC-06 Bluetooth Module |           1 | Wireless command communication |
| Robot Chassis                  |           1 | Vehicle structure              |
| Wheels                         |           4 | Vehicle movement               |
| Battery / Power Supply         |           1 | Power source                   |
| Jumper Wires                   | As required | Electrical connections         |

## 💻 Technologies & Tools

* **Arduino Uno**
* **Embedded C/C++**
* **Arduino IDE**
* **AFMotor Library**
* **HC-05 / HC-06 Bluetooth**
* **Adafruit Motor Shield V1**
* **DC Motor Control**
* **PWM Motor Speed Control**
* **Serial Communication**

## 🔌 System Architecture

```text
              Smartphone
                  │
             Bluetooth
                  │
            HC-05 / HC-06
                  │
             Serial Data
                  │
                  ▼
             Arduino Uno
                  │
                  ▼
       Adafruit Motor Shield V1
          ┌───────┼───────┐
          │       │       │
       Motor 1 Motor 2 Motor 3 Motor 4
          │       │       │       │
          └───────┴───────┴───────┘
                    │
                    ▼
             4-Wheel Vehicle
```

## 🎮 Control Commands

The Arduino receives single-character commands through Bluetooth.

| Command | Action        |
| ------- | ------------- |
| `F`     | Move Forward  |
| `B`     | Move Backward |
| `L`     | Turn Left     |
| `R`     | Turn Right    |
| `S`     | Stop          |

### Forward

All four motors rotate in the forward direction.

```text
Motor 1 → FORWARD
Motor 2 → FORWARD
Motor 3 → FORWARD
Motor 4 → FORWARD
```

### Backward

All four motors rotate in the reverse direction.

```text
Motor 1 → BACKWARD
Motor 2 → BACKWARD
Motor 3 → BACKWARD
Motor 4 → BACKWARD
```

### Left Turn

The motors on one side rotate backward while the motors on the other side rotate forward, producing a differential turning motion.

```text
Motor 1 → BACKWARD
Motor 2 → BACKWARD
Motor 3 → FORWARD
Motor 4 → FORWARD
```

### Right Turn

The motor directions are reversed relative to the left-turn operation.

```text
Motor 1 → FORWARD
Motor 2 → FORWARD
Motor 3 → BACKWARD
Motor 4 → BACKWARD
```

### Stop

All motors are released when the stop command is received.

```text
Motor 1 → RELEASE
Motor 2 → RELEASE
Motor 3 → RELEASE
Motor 4 → RELEASE
```

## 🧠 Working Principle

The system uses **serial Bluetooth communication** to receive commands from a paired smartphone or Bluetooth controller.

The Arduino continuously checks whether data is available:

```cpp
if (Serial.available() > 0)
{
    command = Serial.read();
}
```

Once a command is received, the program first stops the motors and then executes the corresponding movement function.

A `switch-case` control structure determines the required movement:

```cpp
switch (command)
{
    case 'F':
        forward();
        break;

    case 'B':
        backward();
        break;

    case 'L':
        left();
        break;

    case 'R':
        right();
        break;

    case 'S':
        Stop();
        break;
}
```

Motor speed is controlled using:

```cpp
const int SPEED = 255;
```

The **AFMotor library** is used to interface the Arduino with the Adafruit Motor Shield and control the four DC motors.

## 🔄 Control Flow

```text
             START
               │
               ▼
       Initialize Arduino
               │
               ▼
       Initialize Serial
               │
               ▼
      Check Bluetooth Data
               │
         Data Available?
          /          \
        NO            YES
        │              │
        │              ▼
        │        Read Command
        │              │
        │              ▼
        │         Stop Motors
        │              │
        │              ▼
        │       Identify Command
        │              │
        │       ┌──────┼──────┐
        │       ▼      ▼      ▼
        │    Forward  Turn   Stop
        │       │      │      │
        └───────┴──────┴──────┘
                    │
                    ▼
                 Repeat
```


## 🎯 Learning Outcomes

Through this project, the following concepts were implemented and explored:

* Embedded system programming
* Arduino microcontroller interfacing
* DC motor control
* Motor driver interfacing
* Bluetooth communication
* Serial communication
* PWM-based speed control
* Differential-drive steering
* Robotic vehicle control
* Hardware-software integration
* Basic navigation logic

## 🚀 Future Improvements

The prototype can be further developed into a more autonomous vehicle by integrating additional sensors and control algorithms.

Possible upgrades include:

* **HC-SR04 ultrasonic sensors** for real-time obstacle detection
* Automatic obstacle avoidance
* Line-following sensors
* Wheel encoders for feedback control
* Variable-speed control
* Autonomous navigation
* Camera-based object detection
* ESP32-based wireless telemetry
* Path planning and navigation algorithms

## ⚠️ Note

The current uploaded Arduino implementation primarily demonstrates **Bluetooth-based vehicle control and motor interfacing**. The autonomous obstacle-detection functionality can be incorporated as a future extension using ultrasonic sensors and additional control logic.



## 👨‍💻 Author

**Vineet Pal**

Electrical & Electronics Engineering

Areas of Interest:
**Embedded Systems | Robotics | Power Electronics | IoT | Electric Vehicles**

---

⭐ If you found this project useful, consider giving the repository a star!
