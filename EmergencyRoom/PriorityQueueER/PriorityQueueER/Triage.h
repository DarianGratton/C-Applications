#pragma once

// Triage struct is an comparator class built for the patient priority_queue
// sorts patients by the category or if equal the registration time. 
struct Triage {
	bool operator()(const Patient & patient1, const Patient & patient2) {
		if (patient1.getCategory() == patient2.getCategory()) {
			return patient1.getRegistrationTime() > patient2.getRegistrationTime();
		}
		return patient1.getCategory() > patient2.getCategory();
	}
};