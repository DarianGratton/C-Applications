#pragma once

#include "AbstractOperation.h"

class DivisionOperation : public AbstractOperation
{
public:
	static constexpr char DIVISION_CODE = '/';

	// Constructor that passes the DIVISION_CODE char to the parent constructor
	DivisionOperation() : AbstractOperation(DIVISION_CODE) { };

	// PRE: object must be DivisionOperation
	// POST: takes two integers from the stack and adds them 
	// RETURN: The sum of the 2 integers divided
	int perform(int x, int y) override {
		return x / y;
	}

	// Empty virtual destructor
	virtual inline ~DivisionOperation() { };
};