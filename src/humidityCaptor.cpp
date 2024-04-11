#include <humidityCaptor.h>
#include <DHT.h>

/**
 * @brief Construct a new Humidity Captor object on default pin A0.
 * 
 */
HumidityCaptor::HumidityCaptor() :  OutputPin(A0),mydht(DHT(OutputPin, DHT11)){}

/**
 * @brief Construct a new Humidity Captor object on a specific pin.
 * 
 * @param pin the pin whete it is connected on esp32 board.
 */
HumidityCaptor::HumidityCaptor(int pin): OutputPin(pin),mydht(DHT(OutputPin, DHT11)){
}

/**
 * @brief Initialize the dht sensor.
 */
void HumidityCaptor::begin()
{
    mydht.begin();
}

/**
 * @brief Get the humidity value as a percentage.
 * 
 * @return float the humidity value.
 */
float HumidityCaptor::getHumidity()
{
    return mydht.readHumidity();
}

/**
 * @brief Get the temperature value in celsius.
 * 
 * @return float the temperature value.
 */
float HumidityCaptor::getTemperature()
{
    return mydht.readTemperature();
}