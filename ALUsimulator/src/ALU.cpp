/*

Name: Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: ALU.cpp

Date: 9/5/13

*/

#include "ALU.h"
#include <climits>


//place the value into the indicated register.
//The interpretation of 'value' depends on the character prefix:
void ALU::LD (int Register, char prefix, int value) {
	//load the contents of the indicated register into the designated register
	if (prefix == '0') {
		regSet.set( Register, regSet.get(value).get_i());
	}

	//load the numerical value into the register
	if (prefix == '#') {
		regSet.set(Register, new int(value));
	}

	//use the contents of the indicated register as a memory address
	//load the contents of that memory location into the register.
	if (prefix == '@') {
		regSet.set( Register, new int (memory.read( *(int*)regSet.get(value).raw )));
	}
}

//Add the value in register2 to Register1.
//If the result exceeds the value that can be stored in a register set the carry flag to 1
void ALU::ADD(int Register1, int Register2) {
	int temp1 = *regSet.get(Register1).get_i();
	int temp2 = *regSet.get(Register2).get_i();
	if (temp1 += temp2 > INT_MAX)
		regSet.get(Register1).flag_carry=true;
	regSet.set(Register1, new int(temp1+temp2));
}

//Subtract the value in Register2 from Register1.
//If the result is negative set the negative flag on register1 to 1
void ALU::SUB(int Register1, int Register2) {
	int temp1 = *regSet.get(Register1).get_i();
	int temp2 = *regSet.get(Register2).get_i();
	if (temp1 - temp2 > INT_MAX)
		regSet.get(Register1).flag_negative=true;
	regSet.set(Register1, new int(temp1-temp2));
}


//Multiply the value in Register1 by Register2,
//place any overflow in Register3 and set the carry flag on register1
void ALU::MUL(int Register1, int Register2, int Register3) {
	int temp1 = *regSet.get(Register1).get_i();
	int temp2 = *regSet.get(Register2).get_i();
	if (temp1 * temp2 > INT_MAX) {
		regSet.set(Register3, new int(temp1*temp2-INT_MAX));
		regSet.get(Register1).flag_carry=true;
	}
	regSet.set(Register1, new int(temp1*temp2));
}

//Divide the value in Register1 by Register2, place any remainder in Register3
void ALU::DIV(int Register1, int Register2, int Register3) {
	int temp1 = *regSet.get(Register1).get_i();
	int temp2 = *regSet.get(Register2).get_i();
	regSet.set(Register3, new int(temp1 % temp2));
	regSet.set(Register1, new int(temp1/temp2));
}

//Retrieve the contents of Register2 and use its value as the address in memory
//where the contents of Register1 should be stored.
void ALU::STO(int Register1, int Register2) {
	memory.write(*regSet.get(Register2).get_i() , *regSet.get(Register1).get_i());

}
