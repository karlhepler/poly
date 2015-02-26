#include "nGon.h"
#include "stdafx.h"

int nGon::i = 0;		// Set nGon count to 0	

// builds the nGon using variables
void nGon::makePoints() {
	ia = arcAng == 360 ? arcAng / s : arcAng / (s-1);				// if it's anything OTHER THAN 360 degrees, subtract 1 side
	iv.angle(a);						// set internal vector's angle to a
	iv.length(r);						// set internal vector's length to r

	for (int n = 0; n < s; n++) {
		p[n].Center( Vector(iv.X + center.X, iv.Y + center.Y) );
		iv.angle( iv.angle() + ia );
	}
}
// sets the radius of the nGon and rebuilds
void nGon::radius(const float RADIUS) {
	r = RADIUS > 0 ? RADIUS : 1;
	makePoints();
}			
// sets the angle of the nGon and rebuilds
void nGon::angle(const float ANGLE) {
	a = ANGLE;
	makePoints();
}
// sets the number of sides the nGon has and rebuilds
void nGon::sides(const int SIDES) {
	s = SIDES > 0 ? SIDES : 1;
	makePoints();
}
// sets the center / position of the nGon and rebuilds
void nGon::pos(const Vector & POS) {
	center = POS;
	makePoints();
}
void nGon::arcAngle(const float ARCANGLE) {
	if (ARCANGLE < 1) arcAng = 1; else if (ARCANGLE > 360) arcAng = 360; else arcAng = ARCANGLE;
	makePoints();
}