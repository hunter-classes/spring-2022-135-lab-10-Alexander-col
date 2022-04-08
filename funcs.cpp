#include <iostream>
#include "funcs.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"

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

Time addMinutes(Time time0, int min)
{
    time0.m += min;

    if (time0.m >= 60)
    {
        time0.h = time0.h + (time0.m/60);
        time0.m = (time0.m%60);
        return {time0.h, time0.m};
    }

    return {time0.h, time0.m};
}

// Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]

// void printTimeSlot(TimeSlot ts)
// {
//     std::cout << ts.movie.title << ts.movie.
// }

void printMovie(Movie mv){
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
}
// Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]
std::string getTimeSlot(TimeSlot ts)
{
    std::string output = " ";
        std::string g;
    switch (ts.movie.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    output = ts.movie.title + " " + g + " (" + std::to_string(ts.movie.duration) + " min)" + " [starts at ";
    output +=  std::to_string(ts.startTime.h) + ":" + std::to_string(ts.startTime.m);
    output +=  ", ends by ";
    ts.startTime = addMinutes(ts.startTime, ts.movie.duration);
    output +=  std::to_string(ts.startTime.h) + ":" + std::to_string(ts.startTime.m);
    output += "]";

    return output;
}
// Here is the the bottoom for D
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    TimeSlot next = {nextMovie, {ts.startTime.h, ts.startTime.m}};
    next.startTime.m = (ts.movie.duration + next.startTime.m);
    next.startTime.h = ((ts.startTime.h) + (next.startTime.m/60));
    next.startTime.m = next.startTime.m % 60;

    return next;



}