#ifndef NGONH
#define NGONH
#include "bSqr.h"
using namespace System;
using namespace System::IO;

class nGon {
private:
	static int i;					// Count the number of nGons made

// Declare private variables
	float r;						// The radius of the nGon
	float a;						// The angle of the nGon
	float s;						// The number of sides of the nGon
	bSqr* p;						// Contains the coordinates of every point on the nGon
	Vector center;					// The center / position of the nGon
	float ia;						// The internal angle of the nGon
	Vector iv;						// The internal Vector of the nGon. It builds the nGon
	float arcAng;					// the angle of the arc that the nGon is built around
	//char** files;					// contains array of full paths of all files in the nGon

// Private Member Functions : Modifiers
	void makePoints();				// builds the nGon using variables
public:
// Constructors and Deconstructor
	nGon(const Vector & pos = Vector(0,0), const float radius = 48, const float angle = 270, int sides = 3, float arc = 360) : center(pos), iv(1,1) {
		r = radius > 0 ? radius : 1;
		a = angle;
		s = sides > 0 ? sides : 1;
		p = new bSqr[s];
			
			//files = new char* [s];
			// http://msdn2.microsoft.com/en-us/library/07wt70x2.aspx
			//files = Directory::GetFiles("C:\\Documents and Settings\\Karl\\My Documents\\Visual Studio 2005\\Projects\\poly\\poly\\Test Folder\\");

			/*for (int n = 0; n < max; n++) {
				files[n] = new char [wordwidth];
				
			}*/
		
		i++;
		
		if (arc < 1) arcAng = 1; else if (arc > 360) arcAng = 360; else arcAng = arc;
		
		makePoints();
	}
	nGon(const nGon & n) : center(n.center), iv(n.iv) {
		ia = n.ia;
		r = n.r;
		a = n.a;
		s = n.s;
		arcAng = n.arcAng;
		makePoints();
		i++;
	}
	~nGon() { delete [] p; /*delete [] files;*/ i--; }

// Public Member Functions : Selectors
	const float radius() const { return r; }		// returns the radius of the nGon
	const float angle() const { return a; }			// returns the angle of the nGon
	const int sides() const { return s; }			// returns the number of sides the nGon has
	const Vector pos() const { return center; }		// returns the center / position of the nGon
	const float arcAngle() const { return arcAng; }
	static const int count() { return i; }			// Returns the number of nGons made

// Publice Member Functions : Modifiers
	bSqr* points() { return p; }					// returns the coordinates of every point on the nGon
	void radius(const float RADIUS);				// sets the radius of the nGon and rebuilds
	void angle(const float ANGLE);					// sets the angle of the nGon and rebuilds
	void sides(const int SIDES);					// sets the number of sides the nGon has and rebuilds
	void pos(const Vector & POS);					// sets the center / position of the nGon and rebuilds
	void arcAngle(const float ARCANGLE);
};
#endif