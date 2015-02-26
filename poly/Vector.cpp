#include "Vector.h"
#include "stdafx.h"

int Vector::i = 0;		// Set Vector count to 0

// Define friend functions

const Vector operator+(const float & num, const Vector & v)
	{ return Vector( (num + v.X),(num + v.Y) ); }				// adds a float to a Vector
const Vector operator+(const Vector & v, const float & num)
	{ return Vector( (v.X + num),(v.Y + num) ); }				// adds a Vector to a float
const Vector operator+(const Vector & v1, const Vector & v2)
	{ return Vector( (v1.X + v2.X),(v1.Y + v2.Y) );	}			// adds a Vector to a Vector
const Vector operator-(const float & num, const Vector & v)
	{ return Vector( (num - v.X),(num - v.Y) );	}				// subtracts a Vector from a float
const Vector operator-(const Vector & v, const float & num)
	{ return Vector( (v.X - num),(v.Y - num) );	}				// subtracts a float from a Vector
const Vector operator-(const Vector & v1, const Vector & v2)
	{ return Vector( (v1.X - v2.X),(v1.Y - v2.Y) );	}			// subtracts a Vector from a Vector
const Vector operator*(const float & num, const Vector & v)
	{ return Vector( (num * v.X),(num * v.Y) );	}				// multiplies a float by a Vector
const Vector operator*(const Vector & v, const float & num)
	{ return Vector( (v.X * num),(v.Y * num) );	}				// multiplies a Vector by a float
const Vector operator*(const Vector & v1, const Vector & v2)
	{ return Vector( (v1.X * v2.X),(v1.Y * v2.Y) );	}			// multiplies a Vector by a Vector
const Vector operator/(const float & num, const Vector & v) {
	if (v.X != 0 && v.Y != 0)
		return Vector( (num / v.X),(num / v.Y) );
	else
		throw "Divide by Zero!";
}																// divides a float by a Vector
const Vector operator/(const Vector & v, const float & num) {
	if (num != 0)
		return Vector( (v.X / num),(v.Y / num) );
	else
		throw "Divide by Zero!";								
}																// divides a Vector by a float
const Vector operator/(const Vector & v1, const Vector & v2) {
	if (v2.X != 0 && v2.Y !=0)
		return Vector( (v1.X / v2.X),(v1.Y / v2.Y) );
	else
		throw "Divide by Zero!";								
}	 															// divides a Vector by a Vector

inline const Vector abs(const Vector & v)
	{ return Vector(abs(v.X), abs(v.Y)); }								// Returns the absolute value of a Vector
inline const float dot(const Vector & v1, const Vector & v2)
	{ return v1.X * v2.X + v1.Y * v2.Y; }								// Returns the dot product of two Vectors
inline const float perproduct_R(const Vector & v1, const Vector & v2)
	{ return dot(v1, v2.normal_R()); }									// Returns the Rigth perpendicular product of two Vectors
inline const float perproduct_L(const Vector & v1, const Vector & v2)
	{ return dot(v1, v2.normal_L()); }									// Returns the Left perpendicular product of two Vectors
inline const Vector project(const Vector & v1, const Vector & v2)
	{ return Vector(v2.unit() * dot(v1, v2.unit())); }					// Returns the Vector of v1 projected onto v2
const float angle(const Vector & v1, const Vector & v2) {
	float cosine = dot( v1.unit(), v2.unit() );
	// rounding errors might make dotproduct out of range for cosine
	if (cosine > 1) cosine = 1;
	else if (cosine < -1) cosine = -1;
 
	if ( perproduct_L(v1, v2) < 0 )
		return -acos(cosine);
	else
		return acos(cosine);
}																		// Returns the angle between two Vectors
ostream & operator<<(ostream & os, const Vector & V) {
	return os << '(' << V.X << ',' << V.Y << ')';
}


// Returns the angle of this Vector
const float Vector::angle() const {
	return	  X < 0 && Y > 0 ? atan(Y/X) * (180/M_PI) + 180
			: X < 0 && Y < 0 ? atan(Y/X) * (180/M_PI) + 180
			: X > 0 && Y < 0 ? atan(Y/X) * (180/M_PI) + 360
			: atan(Y/X) * (180/M_PI);
}
// Returns the length of this Vector
inline const float Vector::length() const {
	return sqrt(X*X + Y*Y);
}
// Returns the left-hand normal Vector of this Vector
const Vector Vector::normal_L() const {
	return Vector(Y,-X);
}
// Returns the right-hand normal Vector of this Vector
const Vector Vector::normal_R() const {
	return Vector(-Y,X);
}
// Returns the unit Vector of this Vector
const Vector Vector::unit() const {
	return *this / length();
}
// Sets the Vector's angle
void Vector::angle(const float ang) {
	float a = length();
	X = a * cos(ang * (M_PI / 180));
	Y = a * sin(ang * (M_PI / 180));
}
// Sets the Vector's length
void Vector::length(const float len) {
	Vector u = unit();
	X = Vector(u * len).X;
	Y = Vector(u * len).Y;
}
// Sets the coordinates of a Vector
inline void Vector::coords(const float & X_COORD, const float & Y_COORD) {
	X = X_COORD;
	Y = Y_COORD;
}