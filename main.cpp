#include <iostream> 
#include "funcs.h"
#include "time.h"
int main()
{
    Time t = { 17, 45 }; // intializine a time with the name of "t"
    Time u = { 22, 3 };  // making a class of hour and mintues with name of "u"

    std::cout << minutesSinceMidnight(t) << std::endl;

    std::cout << minutesUntil(u,t) << std::endl;

    return 0;
}