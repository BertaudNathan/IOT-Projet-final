#include <humidityCaptor.h>
#include <DHT.h> // Include the DHT library

HumidityCaptor::HumidityCaptor() :  OutputPin(A0),mydht(DHT(OutputPin, DHT11)){}

HumidityCaptor::HumidityCaptor(int pin): OutputPin(pin),mydht(DHT(OutputPin, DHT11)){
}

void HumidityCaptor::begin()
{
    mydht.begin(); // Initialize the DHT sensor
}

float HumidityCaptor::getHumidity()
{
    return mydht.readHumidity(); // Read and return the humidity value
}

float HumidityCaptor::getTemperature()
{
    return mydht.readTemperature(); // Read and return the temperature value
}