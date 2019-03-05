#pragma once

#include "AbstractOperation.h"

class MultiplicationOperation : public AbstractOperation
{
public:
	static constexpr char MULTIPLICATION_CODE = '*';

	// Constructor that passes the MULTIPLICATION_CODE char to the parent constructor
	MultiplicationOperation() : AbstractOperation(MULTIPLICATION_CODE) { };

	// PRE: object must be MultiplicationOperation
	// POST: takes two integers from the stack and adds them 
	// RETURN: The product of the 2 integers
	int perform(int x, int y) override {
		return x * y;
	}
	
	// Empty virtual destructor
	virtual inline ~MultiplicationOperation() { };
};