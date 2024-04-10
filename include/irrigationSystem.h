#ifndef IRRIGATION_SYSTEM_H
#define IRRIGATION_SYSTEM_H

#include "motor.h"
#include <Arduino.h>
#include "humidityCaptor.h"
#include <iostream>

enum Status { WAITING, IRRIGATING };

class IrrigationSystem {

    public :
        IrrigationSystem();
        bool irrigate();
        Motor getMotor();
        HumidityCaptor getHumidityCaptor();
        void start();

        

    private :
        Status status;
        Motor motor;
        HumidityCaptor humidityCaptor;



};

#endif // IRRIGATION_SYSTEM_H