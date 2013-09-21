/*

Name: Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: ALU.h

Date: 9/5/13

*/

#pragma once
//#include "Memory.h"
#include "CTAMemory.h"
#include "RegisterSet.h"

class ALU {

private:
	RegisterSet regSet;

public:
	//Memory memory;
	CTAMemory memory;

	//place the value into the indicated register.
	//The interpretation of 'value' depends on the character prefix:
	//\\A)  '0' (no -prefix) - load contents of indicated register into designated register)
	//B) '#' prefix:  (ex.#1234) load the numerical value (1234) into the register.
	//C) '@'prefix - (ex. @2) - use the contents of the indicated register (ex. register 2)
	//as a memory address load the contents of that memory location into the register.
	void LD (int Register, char prefix, int value);

	//Add the value in register2 to Register1.
	//If the result exceeds the value that can be stored in a register set the carry flag to 1
	void ADD(int Register1, int Register2);

	//Subtract the value in Register2 from Register1.
	//If the result is negative set the negative flag on register1 to 1
	void SUB(int Register1, int Register2);


	//Multiply the value in Register1 by Register2,
	//place any overflow in Register3 and set the carry flag on register1
	void MUL(int Register1, int Register2, int Register3);

	//Divide the value in Register1 by Register2, place any remainder in Register3
	void DIV(int Register1, int Register2, int Register3);

	//Retrieve the contents of Register2 and use its value as the address in memory
	//where the contents of Register1 should be stored.
	void STO(int Register1, int Register2);

};
