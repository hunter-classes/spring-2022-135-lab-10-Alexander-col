#include <iostream> 
#include "funcs.h"
#include "time.h"
int main()
{
    Time t = { 17, 45 }; // intializine a time with the name of "t"

    std::cout << minutesSinceMidnight(t) << std::endl;

    return 0;
}