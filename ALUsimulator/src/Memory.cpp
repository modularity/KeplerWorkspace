/*

Name: Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Memory.cpp

Date: 9/5/13

*/

#include "Memory.h"
#include "IllegalArgumentException.h"

/*
 * simulates a flat memory space of 512 addresses.

This class should provide two methods:

write(unsigned int address, registertype value) - store the value at the memory address indicated.

registertype read(unsigned int address) - return the value stored at the indicated address.

Any attempt to access an invalid address should throw IllegalArgumentException.
 *
 */

Memory::Memory() {
	//init - unsigned int addresses[512];
	for (int i = 0; i < MEMSIZE; i++)
		addresses[i] = 0;
}

//store the value at the memory address indicated.
void Memory::write(unsigned int address, int value) {
	if (address < 512)
		addresses[address] = value;

	else throw IllegalArgumentException("Invalid address\n");
}

//return the value(registertype) stored at the indicated address.
int Memory::read(unsigned int address) {
	if (address < 512)
		return addresses[address];
	else throw IllegalArgumentException("Invalid address\n");
}


