#include <motor.h>


/**
 * @brief Default constructor for Motor class.
 */
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

/**
 * @brief Construct a new Motor object with specific parameters.
 * 
 * @param speed the speed of the motor.
 * @param forwardPin the pin where the motor is connected to the esp32 board.
 * @param reversePin the pin where the motor is connected to the esp32 board.
 * @param bridgePin the pin where the motor is connected to the esp32 board.
 */
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

/**
 * @brief Move the motor forward.
 * 
 * @param delayValue the time value in milliseconds during which the motor will move.
 */
void Motor::forward(int delayValue)
{
    digitalWrite(bridgePin, HIGH);
    analogWrite(reversePin, LOW);
    analogWrite(forwardPin, speed);
    delay(delayValue);
    digitalWrite(bridgePin, LOW);
}

/**
 * @brief Move the motor backward.
 * 
 * @param delayValue the time value in milliseconds during which the motor will move.
 */
void Motor::backward(int delayValue)
{
    digitalWrite(bridgePin, HIGH);
    analogWrite(forwardPin, LOW);
    analogWrite(reversePin, speed);
    delay(delayValue);
    digitalWrite(bridgePin, LOW);
}

/**
 * @brief Stop the motor.
 * 
 */
void Motor::stop()
{
    digitalWrite(bridgePin, LOW);
    digitalWrite(forwardPin, LOW);
    digitalWrite(reversePin, LOW);
}

/**
 * @brief Set the speed of the motor.
 * 
 * @param speed the speed of the motor.
 */
void Motor::setSpeed(int speed)
{
    this->speed = speed;
}

/**
 * @brief Get the speed of the motor.
 * 
 * @return int the speed of the motor.
 */
int Motor::getSpeed()
{
    return speed;
}
