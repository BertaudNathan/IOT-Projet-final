#include <ctime>
#include <iostream>
#include "DateGestion.h"


DateGestion::DateGestion(){
    currentDate = time(0);
    lastIrrigationDate = currentDate;
}

double DateGestion::timeDifference(time_t date1, time_t date2){
    return difftime(date1, date2);
}

bool DateGestion::Has3daysPassed(){
    if (timeDifference(currentDate, lastIrrigationDate) > 259200){
        return true;
    }
    else{
        return false;
    }
}

time_t DateGestion::getLastIrrigationDate(){
    return lastIrrigationDate;
}

void DateGestion::setLastIrrigationDate(time_t date){
    lastIrrigationDate = date;
}