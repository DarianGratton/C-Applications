#pragma once

#include <iostream>
#include <ostream>

class Vector {
private:
	double x;
	double y;
	double z;
public:
	Vector() : x{ 0 }, y{ 0 }, z{ 0 } { }
	Vector(double xval, double yval, double zval);
	~Vector() { }

	double get_X();
	double get_Y();
	double get_Z();

	void set_X(double);
	void set_Y(double);
	void set_Z(double);
	void clear();

	friend std::ostream& operator<<(std::ostream& out, const Vector& vector);

	Vector& operator++();
	Vector operator++(int);
	Vector& operator--();
	Vector operator--(int);

	Vector& operator=(Vector rhs);
	friend void swap(Vector& first, Vector& second);

	// PRE: Vector's x, y, or z must not be null
	// POST: Adds the values of the integers in the lhs
	//       Vector with the corresponding integers in the
	//       rhs Vector
	// RETURN: The lhs Vector with added x, y, z values
	Vector& operator+=(const Vector& rhs) {
		
		this->x += rhs.x;
		this->y += rhs.y;
		this->z += rhs.z;

		return *this;
	}
	friend Vector operator+(Vector lhs, const Vector& rhs);

	// PRE: Vector's x, y, or z must not be null
	// POST: Substracts the values of the integers in the lhs
	//       Vector with the corresponding integers in the
	//       rhs Vector
	// RETURN: The lhs Vector with subtracted x, y, z values
	Vector& operator-=(const Vector& rhs) {
		
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;

		return *this;
	}
	friend Vector operator-(Vector lhs, const Vector& rhs);

	// PRE: Vector's x, y, or z must not be null
	// POST: Muliples the values of the integers in the lhs
	//       Vector with a inputed double value
	// RETURN: The lhs Vector with multiple x, y, z values
	Vector& operator*=(double value) {
		x *= value;
		y *= value;
		z *= value;

		return *this;
	}
	friend Vector operator*(Vector& lhs, double value);
	friend double operator*(Vector& lhs, const Vector& rhs);
};