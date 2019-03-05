#pragma once

#include <string>
#include <iostream>
#include <queue>

#include "Category.h"
#include "Date.h"
#include "Time.h"

using namespace std;

class Patient {
private:
	string first_name;
	string middle_name;
	string last_name;
	Date date_of_birth;
	int healthcare_num;
	Time registration_time;
	string symptoms;
	Category category;
public:
	Patient();
	Patient(string, string, string, Date, int, Time, string, Category);
	
	string getFirstName() const;
	string getMiddleName() const;
	string getLastName() const;
	Date getDateOfBirth() const;
	int getHealthcareNum() const;
	Time getRegistrationTime() const;
	string getSymptoms() const;
	int getCategory() const;
	
	void promptForDateOfBirth();
	void setHealthcareNum(int number);
	void promptForRegistrationTime();
	void setCategory(int number);

	void promptNewCatagory();

	friend std::ostream& operator<<(std::ostream& os, const Patient& patient);
};
