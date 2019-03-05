#include "Vector.h"

#include <iostream>
#include <ostream>

using namespace std;

int main() {
	Vector a;
	cout << a << endl;

	Vector b(123.23, 23.4, 32);
	cout << b << endl;

	cout << "Getters and Setters: " << endl;
	a.set_X(4);
	cout << a.get_X() << " " << a.get_Y() << " " << a.get_Z() << endl;
	a.set_Y(2);
	a.set_Z(3);
	cout << a << endl;

	cout << "Increment and Decrementors: " << endl;
	cout << b << endl;
	b++;
	cout << b << endl;
	++b;
	cout << b << endl;
	b--;
	cout << b << endl;
	--b;
	cout << b << endl;

	cout << "Assignment: " << endl;
	cout << b << endl;
	b = a;
	cout << b << endl;

	cout << "+ and - operators: " << endl;
	cout << a << endl;
	a += b;
	cout << a << endl;

	cout << "* operator: " << endl;
	a *=(3.0);
	cout << a << endl;
	a = a * (3.0);
	cout << a << endl;
	
	cout << "* operator dot product: " << endl;
	double dot{ 0 };
	dot = a * b;
	cout << dot << endl;
	
	system("pause");
}