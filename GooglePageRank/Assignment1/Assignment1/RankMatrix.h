#pragma once

#include "AbstractMatrix.h"

// A RankMatrix is a Matrix that is n x 1 big and is filled with 1s
class RankMatrix : public AbstractMatrix
{
private:
	constexpr static int ASCII_OFFSET = 65;
	double * matrix;
	int size;
public:
	RankMatrix();
	RankMatrix(const int height);
	RankMatrix(const RankMatrix& original);
	~RankMatrix();

	double get_value(int index);

	void set_value(int index, double value);

	friend std::ostream & operator<<(std::ostream & os, const RankMatrix& matrix);
};