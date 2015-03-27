// File description goes here

#include "HashADT.h"
#include "Common.h"

using namespace std;

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
//					idxStatusList - array the same size as hash table indicating
//                                  that the corresponding position in the hasht able is empty
//                                  (0, empty, 1, full, -1, removed)
//					hashTableSize - size of hash table from user
//
// OUTPUT:
// 	Parameters: 	openHashTbl - initialized array of ints for hash table
//					idxStatusList - initialized array of corresponding ints
//                                  as indicators for hash table (0, empty, 1, full, -1, removed)
//                                  passed back by reference
// IMPLEMENTED BY: 	Chad Peters
//**********************************************************************
void InitializeOpenTbl(int* &openHashTbl, int* &idxStatusList, int hashTableSize)
{

	// allocate memory for arrays
	openHashTbl = new (nothrow) int[hashTableSize];
	idxStatusList = new (nothrow) int[hashTableSize];

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
//					hashTableSize - size of hash table from user
//
// OUTPUT:
// 	Parameters: 	chnHashTbl - initialized array of ints for hash table
//					passed back by reference
//
// IMPLEMENTED BY: 	Chad Peters
//**********************************************************************
void InitializeChnTbl(struct chnArray *chnHashTbl, int hashTableSize)
{

	// allocate memory for array OF POINTERS
	chnHashTbl = new (nothrow) chnArray[hashTableSize];

	// initialize all cells in openHashTable and idxStatusList to 0	
	for(int i = 0; i < hashTableSize; i++){
	
		chnHashTbl[i].link = NULL;
		
	} // end for
}

//*********************************************************************
// FUNCTION: 		HashSearching()
// DESCRIPTION: 	checks to see which test is being run and calls the appropriate search function, then calculates the
//                  average number of searches per value as well as the predicted number of searches per value
// INPUT:
// 	Parameters:     testNum - test number that is currently being run
//                  randomArray - random array containing unique integers
//                  openHashTbl - hash table array of integers for open addressing
//                  chnHashTbl - hash table array of pointers for chained hashing
//					hashTableSize - size of hash table from user
//					idxStatusList - array the same size as hash table indicating
//                                  that the corresponding position in the hashtable is empty
//                                  (0, empty, 1, full, -1, removed)
//                  avg - average number of searches needed to find a value
//                  kAvg - predicted number of searches needed to find a value
// OUTPUT:
// 	Parameters: 	avg - average number of searches needed to find a value
//                  kAvg - predicted number of searches needed to find a value
// CALLS TO:        FindChainValue()
//                  FindOpenValue()
//                  CalculateAvg()
//                  CalculateKnuthAvg()
//                  CalculateLoadFactor()
// IMPLEMENTED BY: 	Neil Townsend
//**********************************************************************
void HashSearching(int testNum, int randomArray[], int *openHashTable, struct chnArray *chnHashTable, int hashTableSize, int *idxStatusList, double &avg, double &kAvg)
{
    int totalSearches;                      //total number of searches to find values in a given hash table
    
    //checks which test is being run and calls the appropriate function
    switch (testNum) {
        case TEST_QUADRATIC_PROBING:
        case TEST_DOUBLE_HASHING: totalSearches = FindOpenValue(testNum, randomArray, openHashTable, idxStatusList, hashTableSize);
            break;
        case TEST_SEPARATE_CHAINING: totalSearches = FindChainValue(randomArray, chnHashTable, hashTableSize);
            break;
        default:
            break;
    }
    
    avg = CalculateAverage(totalSearches);
    kAvg = CalculateKnuthAverage(totalSearches, testNum, CalculateLoadFactor(hashTableSize));
}

//*********************************************************************
// FUNCTION: 		FindOpenValue()
// DESCRIPTION: 	controlling function that finds values in hash table and counts
//                  how many searches were needed to find all the values
// INPUT:
// 	Parameters:     testNum - test number that is currently being run
//                  randomArray - random array containing unique integers
//                  openHashTbl - hash table array of integers for open addressing
//					idxStatusList - array the same size as hash table indicating
//                                  that the corresponding position in the hashtable is empty
//                                  (0, empty, 1, full, -1, removed)
//					hashTableSize - size of hash table from user
// OUTPUT:
// 	Return Value: 	totalSearches - total number of searches needed to find all values
// CALLS TO:        HashValue()
//                  DoubleHashValue()
//                  QuadraticProbe()
// IMPLEMENTED BY: 	Neil Townsend
//**********************************************************************
int FindOpenValue(int testNum,int randomArray[],int *openHashTable,int *idxStatusList, int hashTableSize)
{
    int totalSearches = 0;                  //total number of searches needed to find values in the hash table
    
    
    
    return totalSearches;
}

//*********************************************************************
// FUNCTION: 		FindChainValue()
// DESCRIPTION: 	controlling function that finds values in hash table and counts
//                  how many searches were needed to find all the values
// INPUT:
// 	Parameters:     randomArray - random array containing unique integers
//                  chnHashTbl - hash table array of integers for open addressing
//					hashTableSize - size of hash table from user
// OUTPUT:
// 	Return Value: 	totalSearches - total number of searches needed to find all values
// CALLS TO:        HashValue()
// IMPLEMENTED BY: 	Neil Townsend
//**********************************************************************
int FindChainValue(int randomArray[], struct chnArray *chnHashTable, int hashTableSize)
{
    int totalSearches = 0;                  //total number of searches needed to find values in the hash table
    
    
    
    return totalSearches;
}






