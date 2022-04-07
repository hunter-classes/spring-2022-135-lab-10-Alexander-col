#include <iostream>
#include "funcs.h"

void printTime(Time time) 
{
    std::cout << time.h << ":" << time.m;
}

int minutesSinceMidnight(Time time)
{
    int answer = (time.m + (time.h * 60));

    return answer;
}


int minutesUntil(Time earlier, Time later)
{
    int answer = ((earlier.h * 60) + earlier.m) - ((later.h * 60) + later.m);
    return answer;
}

