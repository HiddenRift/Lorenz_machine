#ifndef LORENZMACHINE_H
#define LORENZMACHINE_H

#include "wheel.h"
#include "wheelGroup.h"

// This class models the main encyption device within the Lorenz SZ40 Machine
class lorenzMachine
{
private:
	wheel m37; // the m37 motor wheel
	wheel m61; // the m61 motor wheel
	wheelGroup psi; // the psi group of wheels
	wheelGroup chi; // the chi group of wheels
	
	// apply the wheel rotation algorithm to generate a pseudo random sequence
	void rotateWheels();
	
	// generate an encryption key using the psi and chi wheels
	int makeKey();

public:
	// constructors
	lorenzMachine() {} // default constructor
	lorenzMachine(wheelGroup chi, wheelGroup psi, wheel m37, wheel m61);

	// encrypt a given baudot-encoded character
	int encryptChar(int baudotChar);
};

#endif