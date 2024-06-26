#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {

public:

    Motor(int speed, int forwardPin, int reversePin, int bridgePin);
    Motor();

    void forward(int delayValue);
    void backward(int delayValue);
    void stop();
    void setSpeed(int speed);
    int getSpeed(); 

private:
    int speed;
    int forwardPin;
    int reversePin;
    int bridgePin;

};

#endif // MOTOR_H
