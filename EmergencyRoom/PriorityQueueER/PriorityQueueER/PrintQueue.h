#pragma once

// The print_queue template is built for the Patient priority_queue,
// it's goal is to print the contents in the queue in a clean manner.
template<typename T> void print_queue(T q) {
	while (!q.empty()) {
		std::cout << "Name: " 
			<<  q.top().getFirstName()
			<< " " << q.top().getMiddleName()
			<< " " << q.top().getLastName();
		std::cout << " / Health Number: " << q.top().getHealthcareNum();
		std::cout << " / Category: " << q.top().getCategory();
		std::cout << " / Admission Time: " << q.top().getRegistrationTime();
		std::cout << endl;
		q.pop();
	}
	std::cout << '\n';
}
