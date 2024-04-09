#ifndef HUMIDITY_CAPTOR_H
#define HUMIDITY_CAPTOR_H

#include <Arduino.h>
#include <DHT.h> // Add the missing include path for the DHT library

class HumidityCaptor {
    private:
        int OutputPin; // Pin number for the humidity captor
        DHT mydht;

    public:

        HumidityCaptor();
        HumidityCaptor(int pin);// Initialize the DHT object with the pin number and the sensor type (DHT11)
    
        void begin();

        float getHumidity();

        float getTemperature();
};

#endif // HUMIDITY_CAPTOR_H