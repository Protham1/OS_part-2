
#ifndef CACHE_H
#define CACHE_H

#include <cstdint>
#include <math.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <bitset>
#include <sstream>
#include <stdio.h>
#include <unordered_map>
#include <list>
#include <algorithm> //for finding in a list

using namespace std;

namespace G 
{
class Cache {

	typedef bitset<32> bits;
	
	struct mem_address 
	{
		bits mem;
		bits tag;
		bits index;
		bits offset;
	};
	
	typedef mem_address* entry;
	typedef bits tagentry;
	
	private:
		/*User input values*/
		int capacity;
		int block_size;
		int assoc;
		
		/*Calculated values*/
		int blocks;
		int sets;
		int offset;
		int index;
		int tag;
		int memoryLength;
		int hits;
		int misses;
		int blocksfilled;

		/*Cache storage*/
		vector<bits> memory; //Stores the entire memory from example.trc
		vector<list<tagentry>> tagCache; //Stores the entire cache as a vector of lists(sets)
		vector<list<tagentry>::iterator> tagIt; //Stores the iterators for each set
		unordered_map<bits, mem_address*> mapCache; //Experimental
		
		mem_address* bank; //Array of structures representing each memory address
		
		/*Member functions*/
		int bitsToInt(bits& h);
		bits getTag(bits& h);
		bits getIndex(bits& h);
		bits getOffset(bits& h);
		bits hexToBin(string& s);
		void createCache();
		
		/*LRU Functions*/
		void checkEntry(mem_address& adr);
		void deleteMemEntry(mem_address*& adr);
		void printSet(list<tagentry>& l);
	
	public:
		/*Constructor and Destructor*/
		Cache(int& C, int& b, int& N);
		~Cache();
		
		void readMemory();
		void testMem();
};
}

#endif
