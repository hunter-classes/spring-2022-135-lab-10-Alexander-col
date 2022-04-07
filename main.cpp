#include <iostream> 
#include "funcs.h"
#include "time.h"
int main()
{
    Time t = { 17, 45 }; // intializine a time with the name of "t"
    Time u = { 22, 3 };  // making a class of hour and mintues with name of "u"
    Time c = { 8, 10 }; // made another class that came from website

    //Here is to check if Task A pt.1 is working
    std::cout << minutesSinceMidnight(t) << std::endl;

    //Here is to check if Task A pt.2 is working
    std::cout << minutesUntil(u,t) << std::endl;

    //Here is to check if Task B is working
    c = addMinutes(c, 75);
    std::cout << c.h << ":" << c.m << std::endl;

    return 0;
}