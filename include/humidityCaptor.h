#ifndef HUMIDITY_CAPTOR_H
#define HUMIDITY_CAPTOR_H

#include <Arduino.h>
#include <DHT.h>

class HumidityCaptor {
    private:
        int OutputPin;
        DHT mydht;

    public:

        HumidityCaptor();
        HumidityCaptor(int pin);
    
        void begin();

        float getHumidity();

        float getTemperature();
};

#endif // HUMIDITY_CAPTOR_H