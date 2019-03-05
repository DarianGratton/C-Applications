#include "RankCalculator.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

	// Opens file
	ifstream fin;
	fin.open("connectivity.txt");

	// Check if file opened correctly
	if (!fin) {
		cerr << "Unable to open file" << endl;
		exit(1);
	}

	// Extract the matrix and store it in a object
	double num;
	int numbers_size{ 0 };
	vector<double> numbers;
	while (fin >> num) {
		numbers.push_back(num);
		numbers_size++;
	}

	double * connect_matrix = new double[numbers_size];
	for (int i = 0; i < numbers_size; ++i) {
		connect_matrix[i] = numbers[i];
	}

	SquareMatrix web(connect_matrix, numbers_size);
	delete[] connect_matrix;
	cout << web << endl;

	// File closed
	fin.close();

	cout << "Create transition matrix" << endl;
	SquareMatrix transition = web.transition();
	cout << transition << endl;

	cout << "Create rank matrix" << endl;
	RankCalculator rank_cal;
	RankMatrix rank = rank_cal.rank(transition);
	cout << rank << endl;

	cout << "Calculate rank matrix values" << endl;
	rank_cal.calculateRank(rank);
	cout << rank << endl;

	ofstream fout;
	fout.open("Rank.txt", ios::trunc);
	fout << rank;

	fout.close(); 

	system("pause");
	return 0;
}