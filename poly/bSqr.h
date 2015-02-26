#ifndef BSQRH
#define BSQRH
#include "Vector.h"

class bSqr {
private:
// Static Variables
	static int i;							// Counts number of bSqrs made

// Private Variable Declarations
	Vector center;							// The center of the bSqr
	float size;								// Size of bSqr
	Vector corners[4];						// The four corners of the bSqr (0 is lower left. Continues clockwise)

// Private Member Functions : Modifiers
	void update() {
		corners[0] = center - size/2;
		corners[1] = Vector(center.X - size/2, center.Y + size/2);
		corners[2] = center + size/2;
		corners[3] = Vector(center.X + size/2, center.Y - size/2);
	}

public:
// Constructors and Deconstructor
	bSqr(const Vector & CENTER = Vector(0,0), const float & SIZE = 32) : center(CENTER), size(SIZE) {
		bSqr::i++;
		update();
	}
	bSqr(const bSqr & other) {
		bSqr::i++;
		*this = other;
	}
	~bSqr() {
		bSqr::i--;
	}

// Public Member Functions : Selectors
	const float Size() const { return size; }
	const Vector & Center() const { return center; }
	const Vector* Corners() const { return corners; }
	static const int count() { return i; }		// Returns the number of bSqrs made

	const bool isOverlapped(const float X, const float Y) const {
		if ( Y < corners[1].Y && Y > corners[0].Y ) {
			if ( X < corners[2].X && X > corners[1].X )
				return true;
			else
				return false;
		}
		else
			return false;
	}

// Public Member Functions : Modifiers
	void Size(const float SIZE) { size = SIZE; update(); }
	void Center(const Vector & CENTER) { center = CENTER; update(); }
};
	
#endif