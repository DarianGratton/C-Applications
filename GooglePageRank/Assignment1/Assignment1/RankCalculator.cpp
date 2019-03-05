#include "RankCalculator.h"

// PRE: The matrix inputted must be a transition matrix (M)
// POST: Multiplys the inputted matrix M by a newly created RankMatrix
//       with the same height as the matrix M and then multiply M by the result
// RETURN: A new RankMatrix with new values 
RankMatrix RankCalculator::rank(SquareMatrix & transition)
{
	int root = (int)sqrt(transition.get_size());
	RankMatrix rank(root);
	RankMatrix temp(root);
	double sum = 0;

	for (int i = 0; i < root; ++i) {

		sum = 0.0;

		for (int j = 0; j < root; ++j) {
			sum += transition.get_value(i, j)
				* rank.get_value(j);
		}

		temp.set_value(i, sum);
	}

	return temp;
}

// PRE: Inputted RankMatrix should be one put through
//		the rank method
// POST: Takes the sum of all the values in the RankMatrix
//       and divides the each of the original values by it
// RETURN: A updated RankMatrix with proper link ranks
void RankCalculator::calculateRank(RankMatrix & rank)
{
	double sum = 0.0;
	double result = 0.0;

	for (int i = 0; i < rank.get_size(); ++i) {
		sum += rank.get_value(i);
	}

	for (int i = 0; i < rank.get_size(); ++i) {
		result = rank.get_value(i) / sum;
		rank.set_value(i, result);
	}
}
