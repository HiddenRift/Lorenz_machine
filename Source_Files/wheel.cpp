#include "stdafx.h"
#include "wheel.h"

wheel::wheel(string pinSet, int pinSetting)
{
	// implementation code should be added here
	// pinsetting is current pin
	int numPins = pinSet.length();
	for (size_t i = 0; i < numPins; i++)
	{
		// push pinsetting to vector
		// if char in pinset at i is (char)0, push a (int) 0 else push 1
		this->pins.push_back((pinSet.at(i) == '0') ? 0 : 1);
	}

	// test if pinsetting exists
	if (pinSetting > pinSet.length())
	{
		throw("Error: pinSetting out of range");
	}
	this->pinSetting = pinSetting;
}

void wheel::rotate()
{
	// implementation code should be added here
	this->pinSetting = (++this->pinSetting) % this->pins.size();
}

int wheel::getCurrentPin()
{
	// implementation code should be added here
	// you should also change the return statement
	// where appropriate
	return this->pins[this->pinSetting];
}
