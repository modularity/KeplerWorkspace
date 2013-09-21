/*

Name: Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: ALUsimulator.cpp

Date: 9/5/13

*/

#include "RegisterSet.h"
#include "IllegalArgumentException.h"
#include "Memory.h"
#include "CTAMemory.h"
#include "ALU.h"
#include <iostream>
using namespace std;

int main() {

	try {
		ALU alu;

		cout << "load into reg" << endl;
		alu.LD (1, '#', 1);
		alu.LD (2, '#', 2);
		alu.LD(3, '#', 3);
		alu.LD(4, '#', 4);
		alu.LD(5, '#', 5);
		//cout << "load into out of bounds reg" << endl;
		//alu.LD (532, ' ', 12);

		cout << "reg1=1, reg2=2, 1+2=3" << endl;
		alu.ADD(1, 2);
		alu.STO(1, 5);
		cout << alu.memory.read(5) << endl;
		cout << "reg3=3, reg4=4, 3+4=7" << endl;
		alu.ADD(3, 4);
		alu.STO(3, 5);
		cout << alu.memory.read(5) << endl;


		cout << "reg1=3, reg2=2, 3-2=1" << endl;
		alu.SUB(1, 2);
		alu.STO(1, 5);
		cout << alu.memory.read(5) << endl;
		cout << "reg3=7, reg4=4, 7-4=3" << endl;
		alu.SUB(3, 4);
		alu.STO(3, 5);
		cout << alu.memory.read(5) << endl;

		cout << "reg1=1, reg2=2, 1*2=2" << endl;
		alu.MUL(1, 2, 5);
		alu.STO(1, 5);
		cout << alu.memory.read(5) << endl;
		cout << "reg3=3, reg4=4, 3*4=12" << endl;
		alu.MUL(3, 4, 6);
		alu.STO(3, 5);
		cout << alu.memory.read(5) << endl;


		cout << "reg1=2, reg2=2, 2/2=1" << endl;
		alu.DIV(1, 2, 7);
		alu.STO(1, 5);
		cout << alu.memory.read(5) << endl;
		cout << "reg3=12, reg4=4, 12/4=3" << endl;
		alu.DIV(3, 4, 7);
		alu.STO(3, 5);
		cout << alu.memory.read(5) << endl;


		/*
		Memory mem;
		cout << "read prewrite" << endl;
		cout << mem.read(0) << endl;
		cout << "read after writing: 20" << endl;
		mem.write(0, 20);
		cout << mem.read(0) << endl;
		cout << "read after writing: 40" << endl;
		mem.write(1, 40);
		cout << mem.read(1) << endl;
		mem.write(3, 10);
		cout << "read after writing: 20 40 0 10" << endl;
		cout << mem.read(0) << " ";
		cout << mem.read(1) << " ";
		cout << mem.read(2) << " ";
		cout << mem.read(3) << endl;
		cout << "write out of bounds" << endl;
		mem.write(532, 30);
		cout << "read out of bounds" << endl;
		mem.read(516);
*/

	} catch (IllegalArgumentException &e) { cout << " "<< e.what(); }
	return 0;
}

