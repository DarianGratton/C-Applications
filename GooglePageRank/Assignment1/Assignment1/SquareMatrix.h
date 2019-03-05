#pragma once

#include "AbstractMatrix.h"

class SquareMatrix : public AbstractMatrix
{
private:
	double * matrix;
	int size;
public:
	SquareMatrix();
	SquareMatrix(double connect_matrix[], int size);
	SquareMatrix(const SquareMatrix& original);
	~SquareMatrix();

	double get_value(int row, int column) const;

	void set_value(int row, int column, double value);

	SquareMatrix probability();
	SquareMatrix matrixQ();
	SquareMatrix transition();

	friend std::ostream & operator<<(std::ostream & os, const SquareMatrix& matrix);
};