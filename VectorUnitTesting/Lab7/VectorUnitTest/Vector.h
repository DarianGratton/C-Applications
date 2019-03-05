#pragma once

#include <vector>

using namespace std;

class Vector {
private:
public:
	Vector() { }

	int sum(const vector<int>& v);
	int max(const vector<int>& v);
	int min(const vector<int>& v);
	double average(const vector<int>& v);
};