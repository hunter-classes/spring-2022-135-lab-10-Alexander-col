#pragma once 
#include "time.h"
#include "movie.h"
#include "timeslot.h"

// Below are the function that were povided by the lab website
void printTime(Time time);
void printMovie(Movie mv);
// These are the functions for Task A
int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);

// Here is the funciton of Task B
Time addMinutes(Time time0, int min);

// Here is the function of Task C 
std::string getTimeSlot(TimeSlot ts);

// void printTimeSlot(TimeSlot ts);

// Here is the func of Task D
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
