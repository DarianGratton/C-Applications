#pragma once

#include "AbstractOperation.h"

class AdditionOperation : public AbstractOperation 
{
public:
	static constexpr char ADDITION_CODE = '+';

	// Constructor that passes the ADDITION_CODE char to the parent constructor
	AdditionOperation() : AbstractOperation(ADDITION_CODE) { };

	// PRE: object must be AdditionOperation
	// POST: takes two integers from the stack and adds them 
	// RETURN: The sum of the 2 integers
	int perform(int x, int y) override {
		return x + y;
	}

	// Empty virtual destructor 
	virtual inline ~AdditionOperation() { };
};