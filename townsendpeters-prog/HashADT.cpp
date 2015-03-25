// File description goes here

#include "HashADT.h"
#include "Common.h"


//*********************************************************************
// FUNCTION: 		CalculateLoadFactor()
// DESCRIPTION: 	calculates the load factor for a hash table given the hashtable's size
// INPUT:
// 	Parameters: 	hashTableSize - size of hashtable
// OUTPUT:
// 	Return Val: 	loadFactor - calculated load factor for hashtable
// IMPLEMENTED BY: 	Neil Townsend
//**********************************************************************

double CalculateLoadFactor(int hashTableSize)
{
    double loadFactor;                          //the calculated load factor for the hashtable
    
    //calculates the load factor by dividing the number of values stored in the table by the size of the table
    loadFactor = static_cast<double>(RANDOM_ARRAY_UNIQUE_VALUES) / hashTableSize;
    
    //returns calculated load factor
    return loadFactor;
}


//*********************************************************************
// FUNCTION: 		InitializeOpenTbl()
// DESCRIPTION: 	Initializes hash table as array of integers for open addressing
// INPUT:
// 	Parameters: 	openHashTbl - hash table array of integers for open addressing
//
//					idxStatusList - array the same size as hash table indicating
//					that the corresponding position in the hasht able is empty
//					(0, empty, 1, full, -1, removed)
//
//					hashTableSize - size of hash table from user
//
// OUTPUT:
// 	Return Val: 	openHashTbl - initialized array of ints for hash table
//					passed back by reference
//
//					idxStatusList - initialized array of corresponding ints
//					as indicators for hash table (0, empty, 1, full, -1, removed)
//					passed back by reference
//
// IMPLEMENTED BY: 	Chad Peters
//**********************************************************************

void InitializeOpenTbl(int* &openHashTbl, int* &idxStatusList, int hashTableSize)
{

	// allocate memory for arrays
	openHashTbl = new (std::nothrow) int[hashTableSize];
	idxStatusList = new (std::nothrow) int[hashTableSize];

	// initialize all cells in openHashTable and idxStatusList to 0	
	for(int i = 0; i < hashTableSize; i++){
	
		openHashTbl[i] = 0;
		idxStatusList[i] = 0;
		
	} // end for
	
}

//*********************************************************************
// FUNCTION: 		InitializeChnTbl()
// DESCRIPTION: 	Initializes hash table as array of pointers
// INPUT:
// 	Parameters: 	chnHashTbl - hash table array of pointers for chained hashing
//
//					hashTableSize - size of hash table from user
//
// OUTPUT:
// 	Return Val: 	chnHashTbl - initialized array of ints for hash table
//					passed back by reference
//
//
// IMPLEMENTED BY: 	Chad Peters
//**********************************************************************

chnArray *InitializeChnTbl(chnArray* &chnHashTbl, int hashTableSize)
{

	// allocate memory for array OF POINTERS
	chnHashTbl = new (std::nothrow) chnArray[hashTableSize];

	// initialize all cells in openHashTable and idxStatusList to 0	
	for(int i = 0; i < hashTableSize; i++){
	
		chnHashTbl[i].link = NULL;
		
	} // end for
	
}
