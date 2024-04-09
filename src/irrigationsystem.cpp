#include <irrigationSystem.h>


IrrigationSystem::IrrigationSystem()
{
    motor = Motor(255, 3, 5, 2);
    humidityCaptor = HumidityCaptor(A10);
    dateGestion = DateGestion();
}


void IrrigationSystem::irrigate()
{

    if (humidityCaptor.getHumidity() < 60 && dateGestion.Has3daysPassed())
    {
        motor.forward(5000);
        delay(2000);
        motor.backward(5000);
        dateGestion.setLastIrrigationDate(time(0));
    }
}
Motor IrrigationSystem::getMotor()
{
    return motor;
}

HumidityCaptor IrrigationSystem::getHumidityCaptor()
{
    return humidityCaptor;
}

time_t IrrigationSystem::getLastIrrigationDate()
{
    return dateGestion.getLastIrrigationDate();
}


