#pragma once

#include "AdditionOperation.h"
#include "DivisionOperation.h"
#include "MultiplicationOperation.h"
#include "SubtractionOperation.h"

#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPNCalculator {
private:
	int result;
	std::stack<int> stack;

	// PRE: Char inserted must be '+', '-', '/', or '*'
	// POST: Checks the operation passed in as an parameter and returns
	//		 a new operation object depending on the operation
	// RETURN: a new operation object based on the inserted operation 
	Operation * operation_type(char operation) {
		switch (operation) {
		case AdditionOperation::ADDITION_CODE:
			return new AdditionOperation;

		case MultiplicationOperation::MULTIPLICATION_CODE:
			return new MultiplicationOperation;

		case SubtractionOperation::SUBTRACTION_CODE:
			return new SubtractionOperation;

		case DivisionOperation::DIVISION_CODE:
			return new DivisionOperation;
		}
	}

	// PRE: stack needs to have 2 <= n objects
	// POST: pops the top two numbers from the stack and applies the operation
	//		 then pushes result back on the stackS
	void perform(Operation * operation) {
		int x = stack.top();
		stack.pop();
		int y = stack.top();
		stack.pop();
		int num = operation->perform(x, y);
		stack.push(num);
	}

	// PRE: formula must be in polish notation
	// POST: Checks the inputed formula to see if it is a valid formula in polish notation
	// RETURN: True if formula is valid, false if invalid
	bool valid_formula(std::string formula) {
		int stack_size = 0;
		char prev = NULL;
		
		for (int i = 0; i < formula.length(); ++i) {
			if (!(isdigit(prev) && isdigit(formula[i]))) {
				if (isdigit(formula[i])) {
					++stack_size;
				}
				else if (formula[i] == '+' || formula[i] == '-'
					|| formula[i] == '*' || formula[i] == '/') {
					--stack_size;
				}
			}
			prev = formula[i];
		}

		return stack_size == 1;
	}

public: 

	// PRE: formula must be in polish notation 
	// POST: takes a inputed polish notation formula and returns the result
	//       of it
	// RETURN: the result of the formula
	int process_formula(std::string formula) {

		if (!valid_formula(formula)) {
			std::cout << "Not valid formula" << std::endl;
			return -1;
		}

		std::istringstream iss(formula);
		while (!iss.eof()) {
			std::string operand;
			iss >> operand;

			std::istringstream iss2(operand);
			iss2.str(operand);

			int num;
			iss2 >> num;

			if (iss2.fail()) {
				perform(operation_type(operand[0]));
			} else {
				stack.push(num);
			}
		}

		result = stack.top();
		return result;
	}

};