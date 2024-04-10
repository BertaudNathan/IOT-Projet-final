#include <motor.h>



Motor::Motor()
{
    this->speed = 18;  // the perimeter of the motor is 1 cm. if the power is 18, the motor will move the 15 cm between water and flower pot in 10 seconds (value tried and tested)
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
    analogWrite(reversePin, LOW);
    analogWrite(forwardPin, speed);
    delay(delayValue);
    digitalWrite(bridgePin, LOW);
}
void Motor::backward(int delayValue)
{
    digitalWrite(bridgePin, HIGH);
    analogWrite(forwardPin, LOW);
    analogWrite(reversePin, speed);
    delay(delayValue);
    digitalWrite(bridgePin, LOW);
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
