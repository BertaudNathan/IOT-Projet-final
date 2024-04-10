#include <irrigationSystem.h>
#define uS_TO_S_FACTOR 1000000
#define TIME_TO_SLEEP  1
// Rest of the code...

IrrigationSystem::IrrigationSystem()
{
    motor = Motor(255, 3, 5, 2);
    humidityCaptor = HumidityCaptor(A10);
    status = WAITING;
}

void IrrigationSystem::start()
{
    if (status == WAITING)
    {
        if (irrigate())
        {
            status = IRRIGATING;
        }
        esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR*3600*24*3);  //sleep for three day
    }
    if (status == IRRIGATING)
    {
        motor.stop();
        status = WAITING;
    }
}

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
Motor IrrigationSystem::getMotor()
{
    return motor;
}

HumidityCaptor IrrigationSystem::getHumidityCaptor()
{
    return humidityCaptor;
}