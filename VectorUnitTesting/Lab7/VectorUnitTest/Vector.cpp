#include "Vector.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// PRE: N/A
// POST: Adds all the elements in the vector together
// RETURN: The sum of all the elements in the vector
int Vector::sum(const vector<int>& v)
{
	return accumulate(v.begin(), v.end(), 0);
}

// PRE: Vector must not be empty
// POST: Finds the max element in the vector
// RETURN: The max element in the vector
int Vector::max(const vector<int>& v)
{
	if (v.empty()) {
		return 0;
	}
	return *max_element(begin(v), end(v));
}

// PRE: Vector must not be empty
// POST: Finds the min element in the vector
// RETURN: The min element in the vector
int Vector::min(const vector<int>& v)
{
	if (v.empty()) {
		return 0;
	}
	return *min_element(begin(v), end(v));
}

// PRE: Vector must not be empty
// POST: Calls the sum function to get the sum of
//		 the elements and divides it by the size of the vector
// RETURN: The average of all the elements in the vector
double Vector::average(const vector<int>& v)
{
	if (v.empty()) {
		return 0;
	}
	return sum(v) / v.size();
}
