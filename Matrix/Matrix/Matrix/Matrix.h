#pragma once

#include <iostream>
#include <new>
#include <ostream>

class Matrix {
private:
	int * matrix;
	int matrix_size;
public:
	// Default constructor
	Matrix();

	// PRE: n > 0
	// POST: a newly created matrix of size n * n
	Matrix(const int n);

	// Constructor that accepts an array of int and the 
	// size of the array.
	// PRE: ary size must not be 0 and size must be a perfect square
	// POST: a newly created Matrix with the element from the array
	Matrix(const int ary[], int size);

	// Copy constructor
	Matrix(const Matrix& matrix_original);

	// Destructor
	~Matrix();

	// PRE: Matrix object must exist and the row# and column# 
	//      must exist
	// POST: Sets the location in the array at row#, column# 
	//       to value
	void set_value(int row, int column, int value);

	// PRE: Matrix object must exist and the row# and column# 
	//      must exist
	// POST: gets the value of the integer in the location at row#
	//       and column#
	// RETURN: integer at row# and column#
	int  get_value(int row, int column);

	// PRE: Matrix object must exist
	// POST: gets the size of the matrix
	// RETURN: the size of the matrix
	int  get_size(); 
	
	// PRE: Matrix object must exist
	// POST: sets all values int the Matrix array to 0
	void clear();

	// PRE: n >= 0
	// POST: Checks the integer inputed to see if it is an perfect 
	//		 square
	// RETURN: return true if n is a perfect square, false if it is not
	bool is_perfect_square(int n);

	// PRE: Matrix object must exist
	// POST: Creates an new identity matrix based off the current Matrix
	// RETURN: an newly created identity matrix whose size is the same
	//         as the current Matrix
	Matrix identity();
	
	// PRE: Object being inserted must be a Matrix
	// POST: Outputs the elements in the Matrix array
	// RETURN: The elements in the matrix array to the output stream
	friend std::ostream& operator << (std::ostream& out, const Matrix& matrix1);

	// PRE: Objects being compared must be Matrices
	// POST: Checks if the Matrices are the same size and contain the
	//		 same elements
	// RETURN: true if the Matrices are the same else false
	friend bool operator == (const Matrix& lhs, const Matrix& rhs);

	// PRE: Objects being compared must be Matrices
	// POST: Checks if the Matrices are the same size and contain the
	//		 same elements
	// RETURN: false if the Matrices are the same else true
	friend bool operator != (const Matrix& lhs, const Matrix& rhs);

	// PRE: Objects being compared must be Matrices
	// POST: Checks if the Matrix is smaller than the Matrix being
	//		 compared
	// RETURN: true if the Matrix is smaller than the Matrix being
	//         compared else false
	friend bool operator <  (const Matrix& lhs, const Matrix& rhs);

	// PRE: Objects being compared must be Matrices
	// POST: Checks if the Matrix is bigger than the Matrix being
	//		 compared
	// RETURN: true if the Matrix is bigger than the Matrix being
	//         compared else false
	friend bool operator >  (const Matrix& lhs, const Matrix& rhs);

	// PRE: Objects being compared must be Matrices
	// POST: Checks if the Matrix is smaller than or equal to the 
	//		 Matrix being compared
	// RETURN: true if the Matrix is smaller than or equal to the
	//         Matrix being compared else false
	friend bool operator <= (const Matrix& lhs, const Matrix& rhs);

	// PRE: Objects being compared must be Matrices
	// POST: Checks if the Matrix is bigger than or equal to the 
	//		 Matrix being compared
	// RETURN: true if the Matrix is bigger than or equal to the
	//         Matrix being compared else false
	friend bool operator >= (const Matrix& lhs, const Matrix& rhs);

	// PRE: Matrix must not be empty
	// POST: Increments each element in the Matrix
	// RETURN: The current Matrix with incremented elements
	Matrix & operator++()
	{
		for (int i = 0; i < matrix_size; i++) {
			++matrix[i];
		}

		return *this;
	}

	// PRE: Matrix must not be empty
	// POST: Increments each element in the Matrix
	// RETURN: The current Matrix with incremented elements
	Matrix operator++(int)
	{
		Matrix M(*this);

		++(*this);

		return M;
	}

	// PRE: Matrix must not be empty
	// POST: Decrements each element in the Matrix
	// RETURN: The current Matrix with decremented elements
	Matrix & operator--()
	{
		for (int i = 0; i < matrix_size; i++) {
			--matrix[i];
		}

		return *this;
	}

	// PRE: Matrix must not be empty
	// POST: Decrements each element in the Matrix
	// RETURN: The current Matrix with decremented elements
	Matrix operator--(int)
	{
		Matrix M(*this);

		--(*this);

		return M;
	}

	// PRE: Objects being compared are Matrices
	// POST: Makes the Matrix on the left hand side the same as the 
	//	     one on the right hand side
	// RETURN: The current Matrix but with the same elements as the
	//		   right hand side
	Matrix& operator=(Matrix rhs)
	{
		swap(*this, rhs);
		return *this;
	}

	// PRE: Matrices must both have their size recorded with the
	//      matrix_size variable
	// POST: Swaped elements between the first and second Matrices
	friend void swap(Matrix& first, Matrix& second);

	// PRE: Matrices must be the same size
	// POST: The Matrices elements added together
	// RETURN: The current array but with added elements
	Matrix& operator+=(const Matrix & rhs)
	{
		for (int i = 0; i < this->matrix_size; ++i) {
			this->matrix[i] += rhs.matrix[i];
		}

		return *this;
	}

	// PRE: Matrices must be the same size
	// POST: The Matrices elements added together
	// RETURN: The left hand side array but with added elements
	friend Matrix operator+(Matrix lhs, const Matrix& rhs);

	// PRE: Matrices must be the same size
	// POST: The Matrices elements subtracted together
	// RETURN: The current array but with subtracted elements
	Matrix& operator-=(const Matrix & rhs)
	{
		for (int i = 0; i < this->matrix_size; ++i) {
			this->matrix[i] -= rhs.matrix[i];
		}

		return *this;
	}

	// PRE: Matrices must be the same size
	// POST: The Matrices elements subtracted together
	// RETURN: The left hand side array but with subtracted elements
	friend Matrix operator-(Matrix lhs, const Matrix& rhs);
};