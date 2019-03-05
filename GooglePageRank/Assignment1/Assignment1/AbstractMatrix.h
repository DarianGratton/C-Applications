#pragma once

#include "Matrix.h"

#include <ostream>

class AbstractMatrix : public Matrix 
{
private:
	int size;
public:
	constexpr static double p{ 0.85 };

	// Default constructor of the AbstractMatrix class
	AbstractMatrix(int matrix_size) : size(matrix_size) { }	

	// Destructor
	~AbstractMatrix() { }

	// PRE: N/A
	// POST: Gets the size of the matrix
	// RETURN: The size of the matrix
	int get_size() const override {
		return size;
	}
};