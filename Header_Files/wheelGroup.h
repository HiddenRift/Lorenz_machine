#ifndef WHEELGROUP_H
#define WHEELGROUP_H

#include "wheel.h"
#include <vector>
using std::vector;

// This class models the group of 5 wheels used for the psi and chi
class wheelGroup
{
private:
	vector<wheel> wheels; // all wheels in the group

public:
	// constructors
	wheelGroup(){} // default constructor
	wheelGroup(wheel wheel1, wheel wheel2, wheel wheel3, wheel wheel4, wheel wheel5);
	
	// rotate all wheels in the group
	void rotate();
	
	// get the current pins for all wheels in the group
	int getCurrentPins();
};

#endif