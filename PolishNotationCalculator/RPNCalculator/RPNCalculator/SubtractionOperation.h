#pragma once

#include "AbstractOperation.h"

class SubtractionOperation : public AbstractOperation
{
public:
	static constexpr char SUBTRACTION_CODE = '-';

	// Constructor that passes the SUBTRACTION_CODE char to the parent constructor
	SubtractionOperation() : AbstractOperation(SUBTRACTION_CODE) { };

	// PRE: object must be SubtractionOperation
	// POST: takes two integers from the stack and adds them 
	// RETURN: The difference of the 2 integers
	int perform(int x, int y) override {
		return x - y;
	}

	// Empty virtual destructor
	virtual inline ~SubtractionOperation() { };
};