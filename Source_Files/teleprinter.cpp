#include "stdafx.h"
#include "teleprinter.h"
#include <ctype.h>

teleprinter::teleprinter(lorenzMachine encryptionDevice)
{
	// implementation code should be added here
	this->charToBaudot['*'] = 0x00;
	this->charToBaudot[' '] = 0x04;
	this->charToBaudot['Q'] = 0x17;
	this->charToBaudot['W'] = 0x13;
	this->charToBaudot['E'] = 0x01;
	this->charToBaudot['R'] = 0x0A;
	this->charToBaudot['T'] = 0x10;
	this->charToBaudot['Y'] = 0x15;
	this->charToBaudot['U'] = 0x07;
	this->charToBaudot['I'] = 0x06;
	this->charToBaudot['O'] = 0x18;
	this->charToBaudot['P'] = 0x16;
	this->charToBaudot['A'] = 0x03;
	this->charToBaudot['S'] = 0x05;
	this->charToBaudot['D'] = 0x09;
	this->charToBaudot['F'] = 0x0D;
	this->charToBaudot['G'] = 0x1A;
	this->charToBaudot['H'] = 0x14;
	this->charToBaudot['J'] = 0x0B;
	this->charToBaudot['K'] = 0x0F;
	this->charToBaudot['L'] = 0x12;
	this->charToBaudot['Z'] = 0x11;
	this->charToBaudot['X'] = 0x1D;
	this->charToBaudot['C'] = 0x0E;
	this->charToBaudot['V'] = 0x1E;
	this->charToBaudot['B'] = 0x19;
	this->charToBaudot['N'] = 0x0C;
	this->charToBaudot['M'] = 0x1C;
	this->charToBaudot[','] = 0x08;
	this->charToBaudot['-'] = 0x02;
	this->charToBaudot['!'] = 0x1B;
	this->charToBaudot['.'] = 0x1F;

	this->baudotToChar[0x00] = '*';
	this->baudotToChar[0x04] = ' ';
	this->baudotToChar[0x17] = 'Q';
	this->baudotToChar[0x13] = 'W';
	this->baudotToChar[0x01] = 'E';
	this->baudotToChar[0x0A] = 'R';
	this->baudotToChar[0x10] = 'T';
	this->baudotToChar[0x15] = 'Y';
	this->baudotToChar[0x07] = 'U';
	this->baudotToChar[0x06] = 'I';
	this->baudotToChar[0x18] = 'O';
	this->baudotToChar[0x16] = 'P';
	this->baudotToChar[0x03] = 'A';
	this->baudotToChar[0x05] = 'S';
	this->baudotToChar[0x09] = 'D';
	this->baudotToChar[0x0D] = 'F';
	this->baudotToChar[0x1A] = 'G';
	this->baudotToChar[0x14] = 'H';
	this->baudotToChar[0x0B] = 'J';
	this->baudotToChar[0x0F] = 'K';
	this->baudotToChar[0x12] = 'L';
	this->baudotToChar[0x11] = 'Z';
	this->baudotToChar[0x1D] = 'X';
	this->baudotToChar[0x0E] = 'C';
	this->baudotToChar[0x1E] = 'V';
	this->baudotToChar[0x19] = 'B';
	this->baudotToChar[0x0C] = 'N';
	this->baudotToChar[0x1C] = 'M';
	this->baudotToChar[0x08] = ',';
	this->baudotToChar[0x02] = '-';
	this->baudotToChar[0x1B] = '!';
	this->baudotToChar[0x1F] = '.';
	this->encryptor = encryptionDevice;
}

int teleprinter::getBaudotFromChar(char c)
{
	// implementation code should be added here
	// you should also change the return statement
	// where appropriate


	return this->charToBaudot[toupper(c)];
}

char teleprinter::getCharFromBaudot(int b)
{
	// implementation code should be added here
	// you should also change the return statement
	// where appropriate

	return this->baudotToChar[b];
}

string teleprinter::encryptMessage(string message)
{
	// implementation code should be added here
	// you should also change the return statement
	// where appropriate
	size_t msgLength = message.length();
	string encryptedmsg = "";
	char encryptedChar;

	for (size_t i = 0; i < msgLength; i++)
	{
		encryptedChar = message.at(i);
		encryptedChar = getBaudotFromChar(encryptedChar);
		encryptedChar = this->encryptor.encryptChar(encryptedChar);
		// enc char now hols baudot int
		encryptedChar = getCharFromBaudot(encryptedChar);
		//now holds ascii code

		//now append to string
		encryptedmsg.push_back(encryptedChar);
		//encryptedmsg.append(getCharFromBaudot(this->encryptor.encryptChar(getBaudotFromChar(message.at(i)))));

	}
	return encryptedmsg;
}