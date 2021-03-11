#include "stdafx.h"
#include "lorenzMachine.h"

lorenzMachine::lorenzMachine(wheelGroup chi, wheelGroup psi, wheel m37, wheel m61)
{
	// implementation code should be added here
	this->chi = chi;
	this->psi = psi;
	this->m37 = m37;
	this->m61 = m61;
}

int lorenzMachine::encryptChar(int baudotChar)
{
	// make key
	int key = makeKey();
	rotateWheels();

	return key ^ baudotChar;
}

void lorenzMachine::rotateWheels()
{
	// implementation code should be added here
	if (this->m37.getCurrentPin() == 1) {
		this->psi.rotate();
	}
	if (this->m61.getCurrentPin() == 1) {
		this->m37.rotate();
	}
	this->m61.rotate();
	this->chi.rotate();
}

int lorenzMachine::makeKey()
{
	// implementation code should be added here
	// you should also change the return statement
	// where appropriate
	return this->psi.getCurrentPins() ^ this->chi.getCurrentPins();
}