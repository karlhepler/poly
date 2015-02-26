#ifndef VECTORH
#define VECTORH
#define _USE_MATH_DEFINES
#include "math.h"
#include <iostream>
using namespace std;

class Vector {
private:
	static int i;						// Used to count the number of Vectors made
public:
// Public Variable Declarations
	float X;							// X coordinate
	float Y;							// Y coordinate

// Constructors and Deconstructor
	Vector(float X_COORD = 0, float Y_COORD = 0) : X(X_COORD), Y(Y_COORD) { i++; }
	Vector(const Vector & v) { X = v.X; Y = v.Y; i++; }
	~Vector() { i--; }

// Public Member Functions : Selectors
	static const int count() { return i; }		// Returns the number of Vectors made

	const float angle() const;					// Returns the angle of this Vector
	inline const float length() const;			// Returns the length of this Vector
	const Vector normal_L() const;				// Returns the left-hand normal Vector of this Vector
	const Vector normal_R() const;				// Returns the right-hand normal Vector of this Vector
	const Vector unit() const;					// Returns the unit Vector of this Vector

// Public Member Functions : Modifiers
	void angle(const float);											// Sets the Vector's angle
	void length(const float);											// Sets the Vector's length
	inline void coords(const float & X_COORD, const float & Y_COORD);	// Sets the coordinates of a Vector

// Public Member Functions : Operator Overloads
	Vector & operator=(const Vector & other) { X = other.X; Y = other.Y; return *this;}	// assignment with Vector
	Vector & operator=(const float & num) { X = num; Y = num; return *this; }			// assignment with float
	Vector & operator+=(const Vector & other) { return *this = *this + other; }			// add and update with Vector
	Vector & operator+=(const float & num) { return *this = *this + num; }				// add and update with float
	Vector & operator-=(const Vector & other) { return *this = *this - other; }			// subtract and update with Vector
	Vector & operator-=(const float & num) { return *this = *this - num; }				// subtract and update with float
	Vector & operator/=(const Vector & other) { return *this = *this / other; }			// divide and update with Vector
	Vector & operator/=(const float & num) { return *this = *this / num; }				// divide and update with float
	Vector & operator*=(const Vector & other) { return *this = *this * other; }			// multiply and update with Vector
	Vector & operator*=(const float & num) { return *this = *this * num; }				// multiply and update with float
	Vector & operator++(int) { return *this = *this + 1; }								// postfix (num++)
	Vector & operator--(int) { return *this = *this - 1; }								// postfix (num--)												
	Vector & operator-() { X = -X; Y = -Y; return *this; }								// negation

	const bool operator>(const Vector & other) const {
		return this->X > other.X && this->Y > other.Y ? true : false; }
	const bool operator<(const Vector & other) const {
		return this->X < other.X && this->Y < other.Y ? true : false; }
	const bool operator==(const Vector & other) const {
		return this->X == other.X && this->Y == other.Y ? true : false; }
	const bool operator!=(const Vector & other) const {
		return this->X != other.X && this->Y != other.Y ? true : false; }

// Friends
	friend const Vector operator+(const float &, const Vector &);
	friend const Vector operator+(const Vector &, const float &);
	friend const Vector operator+(const Vector &, const Vector &);
	friend const Vector operator-(const float &, const Vector &);
	friend const Vector operator-(const Vector &, const float &);
	friend const Vector operator-(const Vector &, const Vector &);
	friend const Vector operator*(const float &, const Vector &);
	friend const Vector operator*(const Vector &, const float &);
	friend const Vector operator*(const Vector &, const Vector &);
	friend const Vector operator/(const float &, const Vector &);
	friend const Vector operator/(const Vector &, const float &);
	friend const Vector operator/(const Vector &, const Vector &);
	friend const Vector abs(const Vector &);
	friend const float dot(const Vector &, const Vector &);
	friend const float perproduct_R(const Vector &, const Vector &);
	friend const float perproduct_L(const Vector &, const Vector &);
	friend const Vector project(const Vector &, const Vector &);
	friend const float angle(const Vector & v1, const Vector & v2);
	friend const float det(const Vector & v1, const Vector & v2);
	friend ostream & operator<<(ostream & os, const Vector & V);
};
#endif