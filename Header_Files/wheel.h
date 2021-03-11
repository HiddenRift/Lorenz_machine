#ifndef WHEEL_H
#define WHEEL_H

#include <vector>
#include <string>
using namespace std;

// This class models a wheel within the lorenz machine encryptor device
class wheel
{
private:
	vector<int> pins; // all wheel pins
	int pinSetting; // the current pin

public:
	// constructors
	wheel() {}  // default constructor
	wheel(string pinSet, int pinSetting = 0);
	
	// rotate the wheel by a single pin setting
	void rotate();

	// get the wheel's current pin value (0 or 1)
	int getCurrentPin();
};

#endif