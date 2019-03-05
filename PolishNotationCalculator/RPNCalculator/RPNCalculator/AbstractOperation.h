#pragma once

#include "Operation.h"

class AbstractOperation : public Operation
{
private: 
	char operation_type;
public:
	// Constructor that sets the operation_type variable to op_type
	AbstractOperation(char op_type) : operation_type(op_type) { }
	
	// PRE: child operation object must exist
	// RETURN: The operation_type of the child
	char get_code() override { 
		return operation_type; 
	};

	// Empty Destructor as we aren't allocating memory
	~AbstractOperation() { };
};