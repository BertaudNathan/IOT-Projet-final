

#include <motor.h>



Motor::Motor()
{
    this->speed = 80;
    this->forwardPin = 3;
    this->reversePin = 5;
    this->bridgePin = 2;
    pinMode(forwardPin, OUTPUT);
    pinMode(reversePin, OUTPUT);
    pinMode(bridgePin, OUTPUT);
}

Motor::Motor(int speed, int forwardPin, int reversePin, int bridgePin)
{
    this->speed = speed;
    this->forwardPin = forwardPin;
    this->reversePin = reversePin;
    this->bridgePin = bridgePin;
    pinMode(forwardPin, OUTPUT);
    pinMode(reversePin, OUTPUT);
    pinMode(bridgePin, OUTPUT);
}

void Motor::forward(int delayValue)
{
    digitalWrite(bridgePin, HIGH);
    digitalWrite(forwardPin, HIGH);
    digitalWrite(reversePin, LOW);
    analogWrite(bridgePin, speed);
    delay(delayValue);
}
void Motor::backward(int delayValue)
{
    digitalWrite(bridgePin, HIGH);
    digitalWrite(forwardPin, LOW);
    digitalWrite(reversePin, HIGH);
    analogWrite(bridgePin, speed);
    delay(delayValue);
}

void Motor::stop()
{
    digitalWrite(bridgePin, LOW);
    digitalWrite(forwardPin, LOW);
    digitalWrite(reversePin, LOW);
}

void Motor::setSpeed(int speed)
{
    this->speed = speed;
}
int Motor::getSpeed()
{
    return speed;
}
