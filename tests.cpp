#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("minutesSinceMidnight test cases")
{
	CHECK(minutesSinceMidnight({0, 50}) == 50);
	CHECK(minutesSinceMidnight({11, 10}) == 670);

}
TEST_CASE("minutesUntil test cases")
{
	CHECK(minutesUntil({10, 25}, {13, 40}) == 195);
	CHECK(minutesUntil({10, 25}, {10, 40}) == 15);

}
TEST_CASE("addMinutes test cases")
{
	Time a = addMinutes({8, 10}, 75);
	CHECK(a.h == 9);
	CHECK(a.m == 25);
	a = addMinutes({0, 0}, 60);
	CHECK(a.h == 1);
	CHECK(a.m == 0);
}

TEST_CASE("getTimeSlot() tests")
{
	Movie m  = {"Back to the Future", COMEDY, 120};
	TimeSlot t = {m, {1, 20}};
	CHECK(getTimeSlot(t) == "Back to the Future COMEDY (120 min) [starts at 1:20, ends by 3:20]");

}
TEST_CASE("scheduleAfter() tests")
{
	Movie m = {"Back to the Future", COMEDY, 116};
	Movie mv = {"Black Panther", ACTION, 134};
	TimeSlot morning = {m, {9, 15}};
	TimeSlot morning2 = {mv, {10, 30}};
	CHECK(getTimeSlot(scheduleAfter(morning, mv)) == "Black Panther ACTION (134 min) [starts at 11:11, ends by 13:25]");
}
TEST_CASE("Testing timeOverlap")
{
	  Movie movie1 = {"Back to the Future", COMEDY, 116};
	  Movie movie2 = {"Black Panther", ACTION, 134};
	  TimeSlot morning = {movie1, {9, 15}};
	  TimeSlot morning2 = {movie2, {10, 30}};
	  CHECK(timeOverlap(morning, morning2));
	  morning.startTime = {4, 4};
}