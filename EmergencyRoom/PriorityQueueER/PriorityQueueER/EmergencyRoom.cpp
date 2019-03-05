#include <iostream>
#include <istream>
#include <queue>
#include <fstream>

#include "Patient.h"
#include "Triage.h"
#include "PrintQueue.h"

using namespace std;

static void menu();
void changeCatagory(std::priority_queue<Patient, std::vector<Patient>, Triage> & patients, int health_num);
void savePatientList(std::priority_queue<Patient, std::vector<Patient>, Triage> patients);
std::priority_queue<Patient, std::vector<Patient>, Triage> loadPatientList();

int main() {
	
	int choice = 0;
	std::priority_queue<Patient, std::vector<Patient>, Triage> patients;
	while (choice != 7) {
		menu();
		cout << "Please enter a number from the menu: ";
		cin >> choice;

		if (!cin.fail()) {
			switch (choice) {
			case 1:
			{
				cout << endl;
				cout << "Add new patient" << endl;
				Patient p;
				patients.push(p);
				cout << endl;
				break;
			}
			case 2:
			{
				cout << endl;
				if (!patients.empty()) {
					cout << "Next Patient: " << endl;
					cout << patients.top() << endl;
					patients.pop();
				}
				else {
					cerr << "There doesn't seem to be any Patients in the list" << endl;
					cout << endl;
				}
				break;
			}
			case 3:
			{
				int health_num;
				cout << endl;
				cout << "Please enter the healthcare number of the Patient: ";
				cin >> health_num;
				if (cin.fail()) {
					cout << "Invalid number" << endl;
					cout << endl;
					cin.clear();
					cin.ignore();
				}
				else {
					changeCatagory(patients, health_num);
					cout << endl;
				}
				break;
			}
			case 4:
			{
				savePatientList(patients);
				break;
			}
			case 5:
				patients = loadPatientList();
				break;
			case 6:
				cout << endl;
				print_queue(patients);
				break;
			case 7:
				exit(1);
			default:
				cout << "Invalid choice" << endl;
				cout << endl;
				continue;
			}
		} else {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid choice" << endl;
			cout << endl;
		}
	}

	return 0;
}

// PRE: N/A
// POST: Prints a comprehensive list of all the options on the menu.
static void menu() {
	cout << "ER Menu" << "\n";
	cout << "1. Add new patient" << "\n";
	cout << "2. Get next patient" << "\n";
	cout << "3. Change patient category" << "\n";
	cout << "4. Save patient list" << "\n";
	cout << "5. Load patient list" << "\n";
	cout << "6. Print patient list" << "\n";
	cout << "7. Exit program" << "\n";
}

// PRE: The priority queue entered should not be empty
// POST: Tries to finds the patient of the health number given and
//       if found, prompts the user to change the Patient's priority
void changeCatagory(std::priority_queue<Patient, std::vector<Patient>, Triage> & patients, int health_num) {
	
	bool found = false;
	std::vector<Patient> temp_patients;
	while (!patients.empty()) {
		temp_patients.push_back(patients.top());
		patients.pop();
	}

	std::vector<Patient>::iterator it;
	for (it = temp_patients.begin(); it != temp_patients.end(); ++it) {
		if (it->getHealthcareNum() == health_num) {
			it->promptNewCatagory();
			found = true;
			break;
		}
	}

	if (!found) {
		cout << "Health Number not Found" << endl;
	}

	for (int i = 0; i < temp_patients.size(); ++i) {
		patients.push(temp_patients[i]);
	}
}

// PRE: Patients priority_queue should not be empty
// POST: Save the patients in the priority queue 
//       to a plaintext file called patients.txt
void savePatientList(std::priority_queue<Patient, std::vector<Patient>, Triage> patients) {
	ofstream fout;
	fout.open("patient.txt", ios_base::out | ios_base::trunc);
	while (!patients.empty()) {
		fout << patients.top().getFirstName() << " ";
		fout << patients.top().getMiddleName() << " ";
		fout << patients.top().getLastName() << " ";
		fout << patients.top().getDateOfBirth().get_year() << " ";
		fout << patients.top().getDateOfBirth().get_month() << " ";
		fout << patients.top().getDateOfBirth().get_day() << " ";
		fout << patients.top().getHealthcareNum() << " ";
		fout << patients.top().getRegistrationTime().getHour() << " ";
		fout << patients.top().getRegistrationTime().getMinute() << " ";
		fout << patients.top().getSymptoms() << " ";
		fout << patients.top().getCategory() << " ";
		fout << "endline" << endl;
		fout << endl;
		patients.pop();
	}
	fout << endl;
	fout.close();
	cout << "\nSave Completed" << endl;
	cout << endl;
}

// PRE: Patient.txt must only be created through the save method
// POST: Loads the contents from the file patients.txt and stores the contents 
//       back into a priority queue. If there is no contents in the patients.txt file
//		 the priority queue returned will be empty
std::priority_queue<Patient, std::vector<Patient>, Triage> loadPatientList() {
	
	string line;
	std::priority_queue<Patient, std::vector<Patient>, Triage> patients;
	ifstream fin;
	fin.open("patient.txt");
	if (!fin.is_open()) {
		cout << "File failed to open" << endl;
		return patients;
	} 

	while (getline(fin, line) && line != "") {
		
		size_t pos = 0;
		vector<string> patient_info;
		while ((pos = line.find(" ")) != string::npos) {
			string temp = line.substr(0, pos);
			patient_info.push_back(temp);
			line.erase(0, pos + 1);
		}

		Date new_date(atoi(patient_info[3].c_str()), atoi(patient_info[4].c_str()), atoi(patient_info[5].c_str()));
		Time new_time(atoi(patient_info[7].c_str()), atoi(patient_info[8].c_str())); 
		int number = atoi(patient_info[10].c_str());
		Category c = static_cast<Category>(number);
		Patient new_patient(patient_info[0], patient_info[1], patient_info[2], 
			new_date, atoi(patient_info[6].c_str()), new_time, patient_info[9], c);
		patients.push(new_patient);
	}

	fin.close();
	cout << "\nLoad Completed" << endl;
	cout << endl;

	return patients;
}
