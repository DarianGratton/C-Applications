#pragma once

#include <ostream>

using namespace std;

class Time {
private:
	static constexpr int HOUR_CEILING = 23;
	static constexpr int MIN_CEILING = 59;
	int hour;
	int minute;
public:
	Time(int hour = 0, int minutes = 0);

	// Use compiler-generated copy constructor, destructor, and assignment
	// operator because we are just storing two primitive data members
	
	int getHour() const;
	int getMinute() const;

	static bool is_valid_time(int hour, int minute);

	friend bool operator==(const Time& lhs, const Time& rhs);
	friend bool operator!=(const Time& lhs, const Time& rhs);
	friend bool operator<(const Time& lhs, const Time& rhs);
	friend bool operator>(const Time& lhs, const Time& rhs);
	friend bool operator>=(const Time& lhs, const Time& rhs);
	friend bool operator<=(const Time& lhs, const Time& rhs);

	friend std::ostream& operator<<(std::ostream& os, const Time& time);
};