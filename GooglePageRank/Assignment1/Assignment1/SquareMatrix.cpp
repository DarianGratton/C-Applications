#include "SquareMatrix.h"

#include <iomanip>

// Constructs a SquareMatrix of size 1 x 1
SquareMatrix::SquareMatrix() : AbstractMatrix(1)
{
	size = 1;

	matrix = new double[1];
	matrix[0] = 0;
}

// Constructs a SquareMatrix from another matrix array
SquareMatrix::SquareMatrix(double connect_matrix[], int _size) : AbstractMatrix(_size)
{
	size = _size;

	matrix = new double[size];
	for (int i = 0; i < size; i++) {
		matrix[i] = connect_matrix[i];
	}
}

// Copy Constructor
SquareMatrix::SquareMatrix(const SquareMatrix & original) : AbstractMatrix(original.size), size(original.size)
{
	matrix = new double[size];
	for (int i = 0; i < size; ++i) {
		matrix[i] = original.matrix[i];
	}
}

// Destructor
SquareMatrix::~SquareMatrix()
{
	delete[] matrix;
}

// PRE: Matrix object must exist and the row# and column# 
//      must exist
// POST: gets the value of the integer in the location at row#
//       and column#
// RETURN: integer at row# and column#
double SquareMatrix::get_value(int row, int column) const
{
	int sqrt_size = (int)sqrt(get_size());
	return matrix[(row * sqrt_size) + column];
}

// PRE: Matrix object must exist and the row# and column# 
//      must exist
// POST: Sets the location in the array at row#, column# 
//       to value
void SquareMatrix::set_value(int row, int column, double value)
{
	int sqrt_size = (int)sqrt(get_size());
	matrix[(row * sqrt_size) + column] = value;
}

// PRE: The SquareMatrix called on must be a web matrix
//	    that contains only 0s and 1s
// POST: Creates a probability matrix that tells the user
//       the probability of each link for being clicked on a site 
// RETURN: A new SquareMatrix with probablity values
SquareMatrix SquareMatrix::probability()
{
	SquareMatrix importance(matrix, size);
	int root = (int)sqrt(size);

	for (int i = 0; i < root; ++i) {

		double linkCount = 0.0;

		for (int j = i, k = 0; j < size; j = j + root, ++k) {
			if (get_value(i, k) == 1) {
				linkCount++;
			}
		}

		if (linkCount != 0) {
			double importanceNum = 1.0 / linkCount;

			for (int j = i, k = 0; j < size; j = j + root, ++k) {
				if (get_value(i, k) == 1) {
					importance.matrix[j] = importanceNum;
				}
			}
		}
		else {

			double importanceNum = 1.0 / root;

			for (int j = i; j < size; j = j + root) {
				importance.matrix[j] = importanceNum;
			}
		}
	}

	return importance;
}

// PRE: SquareMatrix object must exist
// POST: A Q matrix in which each element is 1/n
// RETURN: A new SquareMatrix object in which each elment
//		   is 1/n
SquareMatrix SquareMatrix::matrixQ()
{
	SquareMatrix matrixQ(matrix, size);
	int root = (int)sqrt(size);
	double stochasticNum = 1.0 / root;

	for (int i = 0; i < root; ++i) {
		for (int j = 0; j < root; ++j) {
			matrixQ.set_value(i, j, stochasticNum);
		}
	}

	return matrixQ;
}

// PRE: The SquareMatrix called on must be a web matrix
//	    that contains only 0s and 1s
// POST: A transition matrix that calculated using the formula
//		 M = 0.85 * probability matrix + (1 - 0.85) * Q matrix
// RETURN: A new SquareMatrix that is a transition matrix 
SquareMatrix SquareMatrix::transition()
{
	SquareMatrix probability = this->probability();
	SquareMatrix matrixQ = this->matrixQ();
	SquareMatrix transition(matrix, size);

	for (int i = 0; i < size; i++) {
		probability.matrix[i] *= p;
	}

	double difference = 1.0 - p;
	for (int i = 0; i < size; ++i) {
		matrixQ.matrix[i] *= difference;
	}

	for (int i = 0; i < size; ++i) {
		transition.matrix[i] = matrixQ.matrix[i] + probability.matrix[i];
	}

	return transition;
}

// PRE: SquareMatrix object must exist
// POST: Prints out the elements of a matrix to a stream
// RETURN: The out stream
std::ostream & operator<<(std::ostream & os, const SquareMatrix & matrix)
{
	int root = (int)sqrt(matrix.size);

	for (int i = 0; i < matrix.size; ++i) {
		if (i % root == 0 && i != 0) {
			os << std::endl;
		}
		os << std::setw(10) << matrix.matrix[i];
	}
	os << std::endl;

	return os;
}
