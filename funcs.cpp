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
    int answer = ((later.h * 60) + later.m) - ((earlier.h * 60) + earlier.m) ;
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

int is_smaller(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    else if (a < b)
    {
        return a;
    }
    else
    {
        return a;
    }
}

int is_bigger(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else if (a < b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
bool timeOverlap(TimeSlot ts1, TimeSlot ts2) // Could run a for loop to hit every single mintue of the day and see if it matches return 
{
    int ts1_start = minutesSinceMidnight(ts1.startTime);
    int ts1_end = ts1_start + ts1.movie.duration;

    int ts2_start = minutesSinceMidnight(ts2.startTime);
    int ts2_end = ts2_start + ts2.movie.duration;

    int loop_start = is_smaller(ts1_start, ts2_start);
    int loop_end = is_bigger(ts1_end, ts2_end);

    for (int i = loop_start; i != loop_end; i++)
    {
        if ((i > ts1_start && i < ts1_end) && (i > ts2_start && i < ts2_end))
        return true; 
    }
    return false;

}