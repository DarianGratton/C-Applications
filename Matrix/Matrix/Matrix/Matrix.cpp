#include "Matrix.h"

#include <iostream>
#include <iomanip>
#include <ostream>

using namespace std;

Matrix::Matrix()
{
	matrix_size = 1;
	
	matrix = new int[1];
	matrix[0] = 0;
}

Matrix::Matrix(const int n)
{
	int n_sqrt = n * n;
	matrix_size = n_sqrt;

	matrix = new int[n_sqrt];
	for (int i = 0; i < n_sqrt; i++) {
		matrix[i] = 0;
	}
}

Matrix::Matrix(const int ary[], int size)
{
	if (!is_perfect_square(size)) {
		cout << "Size of array is not perfect square" << endl;
		cout << "Matrix couldn't be constructed" << endl;
		return;
	}

	matrix_size = size;
	matrix = new int[size];

	for (int i = 0; i < size; i++) {
		matrix[i] = ary[i];
	}
}

Matrix::Matrix(const Matrix & obj) : matrix_size(obj.matrix_size)
{
	matrix = new int[matrix_size];
	for (int i = 0; i < matrix_size; ++i) {
		 matrix[i] = obj.matrix[i];
	}
}

Matrix::~Matrix()
{
	delete[] matrix;
}

void Matrix::set_value(int row, int column, int value)
{
	int sqrt_size = (int) sqrt(get_size());
	matrix[(row * sqrt_size) + column] = value;
}

int Matrix::get_value(int row, int column)
{
	int sqrt_size = (int) sqrt(get_size());
	return matrix[(row * sqrt_size) + column];
}

int Matrix::get_size()
{
	return matrix_size;
}

void Matrix::clear()
{
	for (int i = 0; i < get_size(); ++i) {
		matrix[i] = 0;
	}
}

Matrix Matrix::identity()
{
	int size_sqrt = (int) sqrt(matrix_size);
	Matrix identity(size_sqrt);

	for (int i = 0; i < size_sqrt; ++i) {
		for (int j = 0; j < size_sqrt; ++j) {
			if (i == j) {
				identity.set_value(i, j, 1);
			}
			else {
				identity.set_value(i, j, 0);
			}
		}
	}
	return identity;
}

bool Matrix::is_perfect_square(int n) {
	if (n < 0) {
		return false;
	}
	int root = (int) round(sqrt(n));
	return n == root * root;
}

std::ostream & operator<<(std::ostream & out, const Matrix& matrix_obj)
{
	int root = (int) sqrt(matrix_obj.matrix_size);
	
	for (int i = 0; i < matrix_obj.matrix_size; ++i) {
		if (i % root == 0 && i != 0) {
			out << endl;
		}
		out << setw(3) << matrix_obj.matrix[i];
	}
	out << endl;

	return out;
}

bool operator==(const Matrix & lhs, const Matrix & rhs)
{
	if (lhs.matrix_size != rhs.matrix_size) {
		return false;
	}

	for (int i = 0; i < lhs.matrix_size; ++i) {
		if (lhs.matrix[i] != rhs.matrix[i]) {
			return false;
		}
	}

	return true; 
}

bool operator!=(const Matrix & lhs, const Matrix & rhs)
{
	if (lhs.matrix_size != rhs.matrix_size) {
		return true;
	}

	for (int i = 0; i < lhs.matrix_size; ++i) {
		if (lhs.matrix[i] != rhs.matrix[i]) {
			return true;
		}
	}

	return false;
}

bool operator<(const Matrix & lhs, const Matrix & rhs)
{
	return lhs.matrix_size < rhs.matrix_size;
}

bool operator>(const Matrix & lhs, const Matrix & rhs)
{
	return lhs.matrix_size > rhs.matrix_size;
}

bool operator<=(const Matrix & lhs, const Matrix & rhs)
{
	return lhs.matrix_size <= rhs.matrix_size;
}

bool operator>=(const Matrix & lhs, const Matrix & rhs)
{
	return lhs.matrix_size >= rhs.matrix_size;
}

void swap(Matrix & first, Matrix & second)
{
	using std::swap;
	swap(first.matrix_size, second.matrix_size);
	swap(first.matrix, second.matrix);
}

Matrix operator+(Matrix lhs, const Matrix & rhs)
{
	for (int i = 0; i < lhs.matrix_size; ++i) {
		lhs.matrix[i] += rhs.matrix[i];
	}

	return lhs;
}

Matrix operator-(Matrix lhs, const Matrix & rhs)
{
	for (int i = 0; i < lhs.matrix_size; ++i) {
		lhs.matrix[i] -= rhs.matrix[i];
	}

	return lhs;
}
