//============================================================================
// Name        : RegisterSet.cpp
// Author      : Lauren Kroll
// Version     :
// Copyright   : C
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "RegisterSet.h"
#include "IllegalArgumentException.h"
#include <iostream>
using namespace std;

int main() {

	try {
		RegisterSet rs;
		int* sample;
		sample = (int*)rs.get(2);
		cout << sample << endl;
		cout << *sample << endl;

		RegisterSet('i', 4);
		rs.set(3, new int(4) );
		int* x = (int*)rs.get(3);
		cout << x << endl;
		cout << *x << endl;
		//rs.set(0, new int(12) );
		rs.reset();


		RegisterSet('d', 4);
		rs.set(3, new double(4.4231) );
		double* y = (double*)rs.get(3);
		cout << y << endl;
		cout << *y << endl;

		RegisterSet('v', 32, 4);
		rs.set(3, new float(3.52) );
		float* z = (float*)rs.get(3);
		cout << z << endl;
		cout << *z << endl;

	} catch (IllegalArgumentException &e) {
		cout << " "<< e.what();
	}
	return 0;
}
