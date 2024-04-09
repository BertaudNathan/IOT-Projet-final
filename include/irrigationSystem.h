#ifndef IRRIGATION_SYSTEM_H
#define IRRIGATION_SYSTEM_H

#include "motor.h"
#include <Arduino.h>
#include "humidityCaptor.h"
#include <iostream>
#include <ctime>
#include "DateGestion.h"

class IrrigationSystem {
    // Add class members and methods here
    public :
        IrrigationSystem();
        void irrigate();
        Motor getMotor();
        HumidityCaptor getHumidityCaptor();
        time_t getLastIrrigationDate();
        DateGestion getDateGestion();

        

    private :
        Motor motor;
        HumidityCaptor humidityCaptor;
        DateGestion dateGestion;



};

#endif // IRRIGATION_SYSTEM_H