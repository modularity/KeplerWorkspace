/*

Name: Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Memory.h

Date: 9/10/13

*/

#pragma once
#include "Memory.h"
/*
 *
Implement a Tiered memory class with a 64 byte cache.  Implement the following methods.

RD - If the contents of the memory address is in the cache it is returned.
If the contents are not in the cache, it is first brought into the cache then returned.

STO - if the memory address is in the cache, the value is stored in the cache.
If the memory address is not in the cache, it is first brought into the cache and then the value is stored in the cache.

If during any LD/STO operation the cache is dirty,
the cache is synchronized with memory before the LD/STO operation is performed.
 *
 */

class CTAMemory {
private:
	//64 byte cache
	static const int CACHECAP = 16;
	//reference to instance of Memory
	Memory* mem;
	//records start of current cache
	unsigned int startAddrCache;
	//stores content from addresses in memory
	int cache[CACHECAP];

	//updates cache starting with the given memory address
	//returns the content at that address
	int updateCache(unsigned int address);

public:

	//creates a new reference of Memory
	CTAMemory();

	//Memory passed as reference to share
	CTAMemory(Memory* memory);

	//Destructor
	~CTAMemory();

	// If the contents of the memory address is in the cache it is returned.
	// If the contents are not in the cache, it is first brought into the cache then returned.
	//store the value at the memory address indicated.
	void write(unsigned int address, int value);


	// If the memory address is in the cache, the value is stored in the cache.
	// If the memory address is not in the cache, it is first brought into the cache and then the value is stored in the cache.
	//return the value(registertype) stored at the indicated address.
	int read(unsigned int address);

};
