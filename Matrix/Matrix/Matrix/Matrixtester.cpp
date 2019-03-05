#include "Matrix.h"

#include <iostream>
#include <ostream>

using namespace std;

int main(int argc, const int argv[]) {
	cout << "Default constructor: " << endl;
	Matrix a;
	cout << a << endl;

	cout << "Constructor that takes a n: " << endl;
	Matrix b(4);
	cout << b << endl;

	cout << "Constructor that takes a ary and a size: " << endl;
	int wrong_size[] = { 1, 2, 3 };
	Matrix c(wrong_size, 3);
	cout << c << endl;

	int right_size[] = { 1, 2, 3, 9 };
	Matrix r(right_size, 4);
	cout << r << endl;

	cout << "Function to change matrix into an identity: " << endl;
	Matrix identity = b.identity();
	cout << identity << endl;

	b.set_value(0, 0, -1);
	b.get_value(0, 0);
	b.clear();

	cout << "Comparison overloads: " << endl;
	Matrix d;
	Matrix e;

	if (e == d) { 
		cout << "e and d matrices are equal" << endl; 
	}
	if (d >= e) { 
		cout << "d is greater than e" << endl; 
	}

	Matrix k(3);
	int test[] = { 1, 2, 3, 9, 2, 3, 4, 5, 6 };
	Matrix l(test, 9);

	if (k != l) {
		cout << "k and l matrices are not equal" << endl;
	}

	cout << endl;

	cout << "Increment and Decrement overloads: " << endl;
	cout << l << endl;
	l++;
	cout << l << endl;
	++l;
	cout << l << endl;
	l--;
	cout << l << endl;
	--l;
	cout << l << endl;

	cout << "Assignment overload: " << endl;
	cout << e << endl;
	e = l;
	cout << e << endl;

	cout << "Add and Subtract overload: " << endl;
	int array1[] = { 1, 2, 3, 9 };
	int array2[] = { 3, 4, 2, 10 };
	Matrix a1(array1, 4);
	Matrix a2(array2, 4);
	a1 = a1 + a2;
	cout << a1 << endl;
	a1 += a2;
	cout << a1 << endl;
	a1 = a1 - a2;
	cout << a1 << endl;
	a1 -= a2;
	cout << a1 << endl;

	system("pause");
}