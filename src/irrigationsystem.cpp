#include <irrigationSystem.h>
#define uS_TO_S_FACTOR 1000000
#define TIME_TO_SLEEP  1
// Rest of the code...


/**
 * @brief Construct a new Irrigation System object.
 */
IrrigationSystem::IrrigationSystem()
{
    motor = Motor(18, 3, 5, 2);
    humidityCaptor = HumidityCaptor(A10);
    status = WAITING;
}


/**
 * @brief Start the irrigation system.
 */
void IrrigationSystem::start()
{
    if (status == WAITING)
    {
        if (irrigate())
        {
            status = IRRIGATING;
        }
    }
    if (status == IRRIGATING)
    {
        motor.stop();
        status = WAITING;
        esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR*3600*24*3);  //sleep for three day
    }
}

/**
 * @brief Irrigate the plant if the humidity is below 60%.
 * 
 * @return true if the plant is irrigated.
 * @return false if the plant is not irrigated.
 */
bool IrrigationSystem::irrigate()
{

    if (humidityCaptor.getHumidity() < 60)
    {
        motor.forward(5000);
        delay(2000);
        motor.backward(5000);
        return true;
    }
    return false;
}

/**
 * @brief Get the Motor object.
 * 
 * @return Motor the motor object.
 */
Motor IrrigationSystem::getMotor()
{
    return motor;
}


/**
 * @brief Get the Humidity Captor object.
 * 
 * @return HumidityCaptor the humidity captor object.
 */
HumidityCaptor IrrigationSystem::getHumidityCaptor()
{
    return humidityCaptor;
}