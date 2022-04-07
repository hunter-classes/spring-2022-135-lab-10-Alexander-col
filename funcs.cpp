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

// int minutesUntil(Time time)
// {
//     int total_mins = 1440
//     int min
// }

