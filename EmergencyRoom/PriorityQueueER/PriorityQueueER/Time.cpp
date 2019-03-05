#include "Time.h"

// Constructs a Time object
Time::Time(int hour, int minutes) : hour(hour), minute(minutes) { 

	if (!is_valid_time(hour, minutes)) {
		throw std::invalid_argument("Time::Time(int, int): invalid argument");
	}

}

// PRE: N/A
// POST: Gets the hour of the time
// RETURN: The hour of the time
int Time::getHour() const
{
	return hour;
}

// PRE: N/A
// POST: Gets the hour of the time
// RETURN: The minutes of the time
int Time::getMinute() const
{
	return minute;
}

// PRE: Time entered should be on the 24 hour 
// POST: Checks the hour and minute inputed to see if they conform within the 
//		 24 hour clock cycle
// RETURN: False if the time is invalid, true if the time is correct
bool Time::is_valid_time(int hour, int minute)
{
	if (hour < 0 || hour > HOUR_CEILING) {
		return false;
	}
	if (minute < 0 || minute > MIN_CEILING) {
		return false;
	}
	return true;
}

// PRE: Objects being compared must be Time objects
// POST: Checks if the Times hours and minutes are equal
// RETURN: true if the Times hours and minutes are equal, false otherwise
bool operator==(const Time & lhs, const Time & rhs)
{
	return lhs.hour == rhs.hour && lhs.minute == rhs.minute;
}

// PRE: Objects being compared must be Time objects
// POST: Checks if the Times hours and minutes are not equal
// RETURN: false if the Times hours and minutes are equal, true otherwise
bool operator!=(const Time & lhs, const Time & rhs)
{
	return !operator==(lhs, rhs);
}

// PRE: Objects being compared must be Time objects
// POST: Checks if the Time is bigger than the Time being
//		 compared
// RETURN: true if the Time is bigger than the Time being
//         compared else false
bool operator<(const Time & lhs, const Time & rhs)
{
	return lhs.hour < rhs.hour || lhs.minute < rhs.minute;
}

// PRE: Objects being compared must be Time objects
// POST: Checks if the Time is smaller than the Time being
//		 compared
// RETURN: true if the Time is smaller than the Time being
//         compared else false
bool operator>(const Time & lhs, const Time & rhs)
{
	return lhs.hour > rhs.hour || lhs.minute > rhs.minute;;
}

// PRE: Objects being compared must be Time objects
// POST: Checks if the Time is smaller than or equal to the Time being
//		 compared
// RETURN: true if the Time is smaller than or equal to the Time being
//         compared else false
bool operator>=(const Time & lhs, const Time & rhs)
{
	return lhs.hour >= rhs.hour || lhs.minute >= rhs.minute;;
}

// PRE: Objects being compared must be Time objects
// POST: Checks if the Time is bigger than or equal to the Time being
//		 compared
// RETURN: true if the Time is bigger than or equal to the Time being
//         compared else false
bool operator<=(const Time & lhs, const Time & rhs)
{
	return lhs.hour <= rhs.hour || lhs.minute <= rhs.minute;;
}

// PRE: Object being inserted must be a Time object
// POST: Outputs the time stored in the Time object 
// RETURN: The time stored in the Time object to the output stream
std::ostream & operator<<(std::ostream & os, const Time & time)
{
	os << time.hour << ":" << time.minute;

	return os;
}
