// ============================================================
// Bluetooth Controlled 4-Wheel Robot Car
// Controller  : Arduino
// Motor Driver: Adafruit Motor Shield V1
// Bluetooth   : HC-05 / HC-06
// Library     : AFMotor
// ============================================================

#include <AFMotor.h>

// ---------------- Motor Configuration ----------------

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

// ---------------- Global Variables ----------------

char command;
const int SPEED = 255;

// ============================================================
// SETUP
// ============================================================

void setup()
{
  Serial.begin(9600);
}

// ============================================================
// MAIN LOOP
// ============================================================

void loop()
{
  if (Serial.available() > 0)
  {
    command = Serial.read();

    // Stop motors before executing a new command
    Stop();

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
  }
}

// ============================================================
// FORWARD
// ============================================================

void forward()
{
  motor1.setSpeed(SPEED);
  motor2.setSpeed(SPEED);
  motor3.setSpeed(SPEED);
  motor4.setSpeed(SPEED);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

// ============================================================
// BACKWARD
// ============================================================

void backward()
{
  motor1.setSpeed(SPEED);
  motor2.setSpeed(SPEED);
  motor3.setSpeed(SPEED);
  motor4.setSpeed(SPEED);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

// ============================================================
// LEFT
// ============================================================

void left()
{
  motor1.setSpeed(SPEED);
  motor2.setSpeed(SPEED);
  motor3.setSpeed(SPEED);
  motor4.setSpeed(SPEED);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

// ============================================================
// RIGHT
// ============================================================

void right()
{
  motor1.setSpeed(SPEED);
  motor2.setSpeed(SPEED);
  motor3.setSpeed(SPEED);
  motor4.setSpeed(SPEED);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

// ============================================================
// STOP
// ============================================================

void Stop()
{
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}