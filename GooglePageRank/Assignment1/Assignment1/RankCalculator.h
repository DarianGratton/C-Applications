#pragma once

#include "RankMatrix.h"
#include "SquareMatrix.h"

#include <stack>

class RankCalculator 
{
public:
	RankMatrix rank(SquareMatrix & transition);
	void calculateRank(RankMatrix & rank);
};