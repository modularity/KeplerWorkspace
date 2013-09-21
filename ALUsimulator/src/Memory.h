/*

Name: Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Memory.h

Date: 9/5/13

*/


#pragma once

class Memory {

public:
	static const int MEMSIZE = 512;

	Memory();
	//store the value at the memory address indicated.
	void write(unsigned int address, int value);

	//return the value(registertype) stored at the indicated address.
	int read(unsigned int address);

private:
	int addresses[MEMSIZE];

};


