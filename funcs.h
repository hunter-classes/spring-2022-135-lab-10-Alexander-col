#pragma once 
#include "time.h"
void printTime(Time time);

// These are the functions for Task A
int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);

// Here is the funciton of Task B
Time addMinutes(Time time0, int min);