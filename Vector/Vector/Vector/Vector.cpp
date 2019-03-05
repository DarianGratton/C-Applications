#include "Vector.h"

using namespace std;

// PRE: 
// POST:
// RETURN: 
Vector::Vector(double xval, double yval, double zval)
{
	x = xval;
	y = yval;
	z = zval;
}

// PRE: Vector object must exist
// POST: Gets the integer x 
// RETURN: The value of the integer x 
double Vector::get_X()
{
	return x;
}

// PRE: Vector object must exist
// POST: Gets the integer y 
// RETURN: The value of the integer y  
double Vector::get_Y()
{
	return y;
}

// PRE: Vector object must exist
// POST: Gets the integer z
// RETURN: The value of the integer z 
double Vector::get_Z()
{
	return z;
}

// PRE: Vector object must exist
// POST: Sets the value of integer x
void Vector::set_X(double xval)
{
	x = xval;
}

// PRE: Vector object must exist
// POST: Sets the value of integer y 
void Vector::set_Y(double yval)
{
	y = yval;
}

// PRE: Vector object must exist
// POST: Sets the value of integer z 
void Vector::set_Z(double zval)
{
	z = zval;
}

// PRE: Vector object must exist
// POST: Sets all values in the Vector to 0
void Vector::clear()
{
	x = 0;
	y = 0;
	z = 0;
}

// PRE: Vector object must exist
// POST: Increments each values in the Vector
// RETURN: The current Vector with incremented values
Vector & Vector::operator++()
{
	++x;
	++y;
	++z;

	return *this;
}

// PRE: Vector object must exist
// POST: Increments each values in the Vector
// RETURN: The current Vector with incremented values
Vector Vector::operator++(int)
{
	Vector V(*this);
	++(*this);
	return V;
}

// PRE: Vector object must exist
// POST: Decrements each values in the Vector
// RETURN: The current Vector with decremented values
Vector & Vector::operator--()
{
	--x;
	--y;
	--z;

	return *this;
}

// PRE: Vector object must exist
// POST: Decrements each values in the Vector
// RETURN: The current Vector with decremented values
Vector Vector::operator--(int)
{
	Vector V(*this);
	--(*this);
	return V;
}

// PRE: Objects being assigned are Vectors
// POST: Makes the Vector on the left hand side the same
//		 as the one the right hand side
// RETURN: The left hand side Vector but with the x, y, z
//         values the same as the right hand side one
Vector & Vector::operator=(Vector rhs)
{
	swap(*this, rhs);
	return *this;
}

// PRE: Object being inserted must be a Vector object
// POST: Outputs the values of the coordinates in the Vector object
// RETURN: The x, y, z coordinates of the Vector Object
std::ostream & operator<<(std::ostream & out, const Vector & vector)
{
	out << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")" << endl;
	return out;
}

// PRE: Vector's x, y, or z must not be null
// POST: Swap x, y, and z values between the first and second Vectors
void swap(Vector & first, Vector & second)
{
	using std::swap;
	swap(first.x, second.x);
	swap(first.y, second.y);
	swap(first.z, second.z);
}

// PRE: Vector's x, y, or z must not be null
// POST: Adds the values of the integers in the lhs
//       Vector with the corresponding integers in the
//       rhs Vector
// RETURN: The lhs Vector with added x, y, z values
Vector operator+(Vector lhs, const Vector & rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	lhs.z += rhs.z;

	return lhs;
}

// PRE: Vector's x, y, or z must not be null
// POST: Substracts the values of the integers in the lhs
//       Vector with the corresponding integers in the
//       rhs Vector
// RETURN: The lhs Vector with subtracted x, y, z values
Vector operator-(Vector lhs, const Vector & rhs)
{
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
	lhs.z -= rhs.z;

	return lhs;
}

// PRE: Vector's x, y, or z must not be null
// POST: Muliples the values of the integers in the lhs
//       Vector with a inputed double value
// RETURN: The lhs Vector with multiple x, y, z values
Vector operator*(Vector & lhs, double value)
{
	lhs.x *= value;
	lhs.y *= value;
	lhs.z *= value;

	return lhs;
}

// PRE: Vector's x, y, or z must not be null
// POST: The dot product of two vectors
// RETURN: The dot product of two vectors
double operator*(Vector & lhs, const Vector & rhs)
{
	double dotProduct = 0;

	lhs.x *= rhs.x;
	lhs.y *= rhs.y;
	lhs.z *= rhs.z;

	dotProduct = lhs.x + lhs.y + lhs.z;
	return dotProduct;
}
