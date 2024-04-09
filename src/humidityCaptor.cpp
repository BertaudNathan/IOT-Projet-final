#include <humidityCaptor.h>
#include <DHT.h>

HumidityCaptor::HumidityCaptor() :  OutputPin(A0),mydht(DHT(OutputPin, DHT11)){}

HumidityCaptor::HumidityCaptor(int pin): OutputPin(pin),mydht(DHT(OutputPin, DHT11)){
}

void HumidityCaptor::begin()
{
    mydht.begin();
}

float HumidityCaptor::getHumidity()
{
    return mydht.readHumidity();
}

float HumidityCaptor::getTemperature()
{
    return mydht.readTemperature();
}