#include "stdafx.h"
#include "wheelGroup.h"

wheelGroup::wheelGroup(wheel wheel1, wheel wheel2, wheel wheel3, wheel wheel4, wheel wheel5)
{
	// implementation code should be added here
	
	/*this->wheels.push_back(wheel1);
	this->wheels.push_back(wheel2);
	this->wheels.push_back(wheel3);
	this->wheels.push_back(wheel4);
	this->wheels.push_back(wheel5);*/

	
	this->wheels.push_back(wheel5);
	this->wheels.push_back(wheel4);
	this->wheels.push_back(wheel3);
	this->wheels.push_back(wheel2);
	this->wheels.push_back(wheel1);
	
}

void wheelGroup::rotate()
{
	// get total wheels
	size_t totalWheels = this->wheels.size();
	// rotate each wheel once
	for (size_t wheelnum = 0; wheelnum < totalWheels; wheelnum++)
	{
		this->wheels[wheelnum].rotate();
	}
}

int wheelGroup::getCurrentPins()
{
	// implementation code should be added here
	// you should also change the return statement
	// where appropriate
	// loop  though and  build binary int
	int currentPins = 0;
	int temp = 0;
	//size_t totalWheels = this->wheels.size();
	for (int wheelnum = this->wheels.size()-1; wheelnum >= 0; wheelnum--)
	{
		temp = this->wheels[wheelnum].getCurrentPin();
		if (temp == 1)
		{
			//test this
			currentPins = currentPins | (temp << wheelnum);
			//currentPins = (currentPins | temp) << 1;
			// assembles int as 01234
			// nums representing the wheel the value comes from
		}
	}

	return currentPins;
}
