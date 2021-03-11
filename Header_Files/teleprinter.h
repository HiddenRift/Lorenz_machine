#ifndef TELEPRINTER_H
#define TELEPRINTER_H

#include <string>
#include <map>
using namespace std;

#include "lorenzMachine.h"

// This class models the teleprinter used in the Lorenz SZ40 Encryption Machine
class teleprinter
{
private:
	map<char, int> charToBaudot; // mapping between ASCII char and baudot code
	map<int, char> baudotToChar; // mapping between baudot code and ASCII char
	lorenzMachine encryptor; // an instance of the lorenz machine class

	// find the 5bit baudot code for a given ASCII char
	int getBaudotFromChar(char c);

	// find the ASCII char for a given 5bit baudot code
	char getCharFromBaudot(int b);

public:
	// constructors
	teleprinter() {} // default constructor
	teleprinter(lorenzMachine encryptionDevice);
	
	// encrypt a given message using the Lorenz Machine
	string encryptMessage(string message);
};

#endif