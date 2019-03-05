#include "RankMatrix.h"

#include <iomanip>

// Constructs a RankMatrix object that is size 1 x 1
RankMatrix::RankMatrix() : AbstractMatrix(1)
{
	size = 1;

	matrix = new double[1];
	matrix[0] = 1;
}

// Constructs a RankMatrix object that is size n x 1 
RankMatrix::RankMatrix(const int height) : AbstractMatrix(height)
{
	size = height;

	matrix = new double[size];
	for (int i = 0; i < size; i++) {
		matrix[i] = 1;
	}
}

// Copy Constructor
RankMatrix::RankMatrix(const RankMatrix & original) : AbstractMatrix(original.size), size(original.size)
{
	matrix = new double[size];
	for (int i = 0; i < size; ++i) {
		matrix[i] = original.matrix[i];
	}
}

// Destructor
RankMatrix::~RankMatrix()
{
	delete[] matrix;
}

// PRE: Matrix cannot be empty
// POST: Gets the value at the inputed index
// RETURN: The value at that index
double RankMatrix::get_value(int index)
{
	return matrix[index];
}

// PRE: Matrix cannot be empty
// POST: Sets the value at the inputed index to the inputted value
void RankMatrix::set_value(int index, double value)
{
	matrix[index] = value;
}

// PRE: RankMatrix object must exist
// POST: Prints the RankMatrix to the stream 
// RETURNS: The out stream
std::ostream & operator<<(std::ostream & os, const RankMatrix & matrix)
{
	for (int i = 0; i < matrix.size; ++i) {
		int let = i + matrix.ASCII_OFFSET;
		char letter = let;
		os << letter << " = " << std::setprecision(4) << matrix.matrix[i] << "\n";
	}

	return os;
}
