#include <iostream> 
#include "funcs.h"
#include "time.h"
int main()
{
    // std::cout << "Hello World!" << std::endl;
    // std::cout << "intial push to start lab" << std::endl;
    // std::cout << "Looking forward to start this time lab!" << std::endl;

    Time now;    // creates a new variable (or object)
    now.h = 17;  // assigns its hours field
    now.m = 45;  // assigns its minutes field 
    printTime(now);
    return 0;
}