#include "RPNCalculator.h"

#include <string>
#include <istream>
#include <iostream>

int main() {
	int result = -1;
	while (result == -1) {
		std::cout << "Enter your formula:\n";
		std::string formula;
		std::getline(std::cin, formula);
		std::cout << "You entered " << formula << std::endl;
		RPNCalculator calculator;
		result = calculator.process_formula(formula);
		std::cout << "The result is:\n";
		std::cout << result << std::endl;
		std::cout << std::endl;
	}	
	system("pause");
}