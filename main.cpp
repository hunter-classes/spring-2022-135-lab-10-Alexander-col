#include <iostream> 
#include "funcs.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"
int main()
{
    Time t = { 17, 45 }; // intializine a time with the name of "t"
    Time u = { 22, 3 };  // making a class of hour and mintues with name of "u"
    Time c = { 8, 10 }; // made another class that came from website
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"Scott Pilgrim vs. the World", ACTION, 112};
    Movie movie4 = {"Jujutsu Kaisen 0: The Movie", ACTION, 105};
    Movie movie5 = {"Spider-Man: No Way Home", ACTION, 148};


    // Here is to check if Task A pt.1 is working
    std::cout << "\n---------------------Task A ---------------------" << std::endl;

    std::cout << "17 hours and 45 mintues equals: ";;
    std::cout << minutesSinceMidnight(t) << " mintues" << std::endl;

    // Here is to check if Task A pt.2 is working
    std::cout << "2 hours and 3 mins, and 17 hours and 45 mins, is a distance of: ";
    std::cout << minutesUntil(u,t) << " mintues " << std::endl;

    // Here is to check if Task B is working
    std::cout << "\n---------------------Task B ---------------------" << std::endl;

    std::cout << "8 hours and 10 minutes with 75 mintues added gives the new time of ";
    c = addMinutes(c, 75);
    std::cout << c.h << ":" << c.m << std::endl;
    
    // Here is to check if Task C is working
    std::cout << "\n---------------------Task C ---------------------" << std::endl;

    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie2, {16, 45}}; 
    TimeSlot later = {movie3, {9, 15}};  
    TimeSlot much_later = {movie4, {12, 15}}; 
    TimeSlot final = {movie5, {16, 45}}; 
    TimeSlot intersecter = {movie2, {9,30}};
    
    std::cout << std::endl;
    std::cout << getTimeSlot(morning) << std::endl;
    std::cout << getTimeSlot(daytime) << std::endl;
    std::cout << getTimeSlot(evening) << std::endl;
    std::cout << getTimeSlot(later) << std::endl;
    std::cout << getTimeSlot(much_later) << std::endl;
    std::cout << getTimeSlot(final) << std::endl;

    std::cout << "\n---------------------Task D ---------------------" << std::endl;

    std::cout << "the movie of " << final.movie.title << "ends so that the following movie can begin" << std::endl;
    std::cout << getTimeSlot(final) << std::endl;
    TimeSlot xr = scheduleAfter(final, movie3);
    std::cout << getTimeSlot(xr) << std::endl;
    TimeSlot xo = scheduleAfter(xr,movie1);
    std::cout << getTimeSlot(xo) << std::endl;

    std::cout << "\n---------------------Task E ---------------------" << std::endl;
    std::cout << "Two of the same timeslots are entred so the will ooverlap:" << std::endl;
    std::cout << timeOverlap(morning, morning) << std::endl;
    std::cout << "Two much more spread out non over laping time slots are entered:" << std::endl;
    std::cout << timeOverlap(morning, final) << std::endl;
    std::cout << "Two diffrent overlaping TimeSlots are entred" << std::endl;
    std::cout << timeOverlap(later, intersecter) << std::endl;
   


    return 0;
}