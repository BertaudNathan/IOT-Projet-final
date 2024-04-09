#ifndef DATEGESTION_H
#define DATEGESTION_H
#include <iostream>
#include <ctime>


 class DateGestion
{
    public:
        DateGestion();
        bool Has3daysPassed();
        double timeDifference(time_t date1, time_t date2);
        time_t getLastIrrigationDate();
        void setLastIrrigationDate(time_t date);
    private:
        time_t lastIrrigationDate;
        time_t currentDate;



        





};

#endif