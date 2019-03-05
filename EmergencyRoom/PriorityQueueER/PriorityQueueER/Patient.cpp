#include <iostream>

#include "Patient.h"

using namespace std;

// POST: The Default constructor for the Patient class.
//		 It asks the users for their input on the Patients
//		 information and sets the user Patients variables to the input.
Patient::Patient()
{
	// Gets the Nurses inputs for the patients name
	cout << "Last Name: ";
	cin >> last_name;
	cout << "First Name: ";
	cin >> first_name;
	cout << "Middle Name: ";
	cin >> middle_name;
	
	// Function for getting the Nurses inputs for the Date of birth
	promptForDateOfBirth();

	// Gets the Nurses inputs for the healthcare number
	cout << "Personal healthcare number: ";
	cin >> healthcare_num;

	// Function for getting the Nurses inputs for registration time
	promptForRegistrationTime();

	// Gets the Nurses inputs for the patient's symptoms
	cout << "Main Symptom(s) (one line): ";
	cin >> symptoms;

	// Gets the Nurses inputs for the patient's category
	bool cat_set = false;
	int cat_num = 0;
	while (!cat_set) {
		cout << "Category number: ";
		cin >> cat_num;
		try {
			setCategory(cat_num);
			cat_set = true;
		}
		catch (const std::invalid_argument& e) {
			cout << e.what() << endl;
		}
	}
}

// Constructor that sets all the instance variables through the parameters
Patient::Patient(string first_name, string middle_name, string last_name, 
	Date date_of_birth, int health_num, Time admission_time, string symptoms, Category category) 
	: first_name(first_name), middle_name(middle_name), last_name(last_name),
	date_of_birth(date_of_birth), healthcare_num(health_num), registration_time(admission_time), 
	symptoms(symptoms), category(category) { }

// PRE: N/A
// POST: Gets the Patients first name
// RETURN: A string containing the Patients first name
string Patient::getFirstName() const
{
	return first_name;
}

// PRE: N/A
// POST: Gets the Patients middle name
// RETURN: A string containing the Patients middle name
string Patient::getMiddleName() const
{
	return middle_name;
}

// PRE: N/A
// POST: Gets the Patients last name
// RETURN: A string containing the Patients last name
string Patient::getLastName() const
{
	return last_name;
}

// PRE: N/A
// POST: Gets the Patients date of birth
// RETURN: A Date object containing the Date Of Birth of
//		   the Patient.
Date Patient::getDateOfBirth() const
{
	return date_of_birth;
}

// PRE: N/A
// POST: Gets the Patient's healthcare number
// RETURN: A integer containing the Patients healthcare number
int Patient::getHealthcareNum() const
{
	return healthcare_num;
}

// PRE: N/A
// POST: Gets the Patient's registration time
// RETURN: A Time object containing the Patient's admission time
Time Patient::getRegistrationTime() const
{
	return registration_time;
}

// PRE: N/A
// POST: Gets the Patient's symptoms
// RETURN: A string containing the Patient's symptoms
string Patient::getSymptoms() const
{
	return symptoms;
}

// PRE: N/A
// POST: Gets the Patient's category number
// RETURN: A integer for the category from 1 to 6 with 1 being the most 
//         severe and 6 being the least severe
int Patient::getCategory() const
{
	return static_cast<int>(category);
}

// PRE: Date information entered must be a valid date
// POST: Prompts the user to enter in the Patient's Date
//       of Birth, year, day and month then set the date 
//		 of birth to the new Date object 
void Patient::promptForDateOfBirth()
{
	int year{ 0 }, month{ 0 }, day{ 0 };
	while (!Date::is_valid_date(year, month, day)) {
		cout << "Year of birth: ";
		cin >> year;
		cout << "Month of birth: ";
		cin >> month;
		cout << "Day of birth: ";
		cin >> day;
		if (!Date::is_valid_date(year, month, day) || cin.fail()) {
			cerr << "Invalid Date. Please try again" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	Date date(year, month, day);
	date_of_birth = date;
}

// PRE: N/A
// POST: Sets the healthcare_num to the parameter number
void Patient::setHealthcareNum(int number)
{
	healthcare_num = number;
}

// PRE: Time entered must be a valid time on the 24 hour clock
// POST: Prompts the user to enter the Patient's hospital admission
//		 time and sets the registation time to it.
void Patient::promptForRegistrationTime()
{
	int hour{ INT_MAX };
	int minutes{ INT_MAX };
	while (!Time::is_valid_time(hour, minutes)) {
		cout << "Time admitted (hour [space] minutes): ";
		cin >> hour >> minutes;
		if (!Time::is_valid_time(hour, minutes) || cin.fail()) {
			cerr << "Invalid Time. Please try again" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	Time time(hour, minutes);
	registration_time = time;
}

// PRE: Number must be between 1 and 6 corresponding to the 6 categories
// POST: Sets the category to one of the 6 categories
void Patient::setCategory(int number)
{
	if (number >= 1 && number <= 6) {
		category = static_cast<Category>(number);
	} else {
		throw std::invalid_argument("Category: invalid argument");
	}
}

// PRE: Category entered must be between 1 and 6
// POST: Prompts the user to enter in the Patient's category
//		 and then sets the variable for it.
void Patient::promptNewCatagory()
{
	int cat_num = 0;
	cout << "New Category number: ";
	cin >> cat_num;
	try {
		setCategory(cat_num);
	} catch (const std::invalid_argument& e) {
		cout << e.what() << endl;
		return;
	}
}

// PRE: Object being inserted must be a Patient
// POST: Outputs the information of the Patient 
// RETURN: The information of the Patient to the output stream
std::ostream & operator<<(std::ostream & os, const Patient & patient)
{
	os << "Name: " << patient.first_name << " " << patient.middle_name << " " << patient.last_name << endl;
	os << "Date of Birth: " << patient.date_of_birth << endl;
	os << "Personal healthcare number: " << patient.healthcare_num << endl;
	os << "Time admitted: " << patient.registration_time << endl;
	os << "Category num: " << patient.getCategory() << endl;
	os << endl;

	return os;
}
