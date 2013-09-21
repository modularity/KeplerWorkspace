/*

Name: Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Memory.h

Date: 9/10/13

*/


#include "CTAMemory.h"
#include "IllegalArgumentException.h"
#include <iostream>
using namespace std;


	//creates a new instance of Memory
	//even-address odd-content
	CTAMemory::CTAMemory() {
		startAddrCache = 0;
		mem = new Memory();
		for (int i=0; i < CACHECAP; i++) {
			cache[i]=0;
		}
	}

	//Memory passed as reference to share
	CTAMemory::CTAMemory(Memory* memory) {
		startAddrCache = 0;
		mem = memory;
	}

	// If the contents of the memory address is in the cache it is returned.
	// If the contents are not in the cache, it is first brought into the cache then returned.
	//store the value at the memory address indicated.
	void CTAMemory::write(unsigned int address, int value) {
		if ( startAddrCache <= address && address <= startAddrCache+CACHECAP )
			cache[address-startAddrCache] = value;
		else updateCache(address);
	}


	// If the memory address is in the cache, the value is stored in the cache.
	// If the memory address is not in the cache, it is first brought into the cache and then the value is stored in the cache.
	//return the value(registertype) stored at the indicated address.


	int CTAMemory::read(unsigned int address) {
		int content = -1;
		if ( startAddrCache <= address && address <= startAddrCache+CACHECAP )
			content = cache[address-startAddrCache];
		else content = updateCache(address);
		return content;
	}

	//updates cache starting with the given memory address
	//returns the content at that address
	int CTAMemory::updateCache(unsigned int address) {
		int currCap = address+CACHECAP;
		int count = 0;
		for (int addr = address; addr < currCap; addr++) {
			while (addr <= mem->MEMSIZE ) {
				cache[count] = mem->read(addr);
				count++;
			}
		}
		return cache[0];
	}

	//Destructor
	CTAMemory::~CTAMemory() {
		//deallocate Memory
		delete mem;
	}
