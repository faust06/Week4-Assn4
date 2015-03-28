// File description goes here

#include "HashADT.h"
#include "Common.h"

using namespace std;

//*********************************************************************
// FUNCTION: 		HashValue()
// DESCRIPTION: 	calculates the initial hash value by using modulo-division
// INPUT:
// 	Parameters: 	initialValue - initial value to be hashed
//                  HashTableSize - size of hash table used to hash initial value
// OUTPUT:
// 	Return Val: 	hashVal - hashed value of initialValue to use for hashtable index
// IMPLEMENTED BY: 	Neil Townsend
//**********************************************************************
int HashValue(int initialValue, int hashTableSize)
{
    int hashVal;                                //hashed value of initialValue
    
    //calculates the initial hash value by using modulo-division
    hashVal = initialValue % hashTableSize;
    
    //returns initial hash value
    return hashVal;
}

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

//**********************************************************************
// FUNCTION: 		QuadraticProbe
// DESCRIPTION: 	Resolves collisions in an open addressing hash table
//					by quadratic probe values. Used to avoid primary
//					clustering. Used for test 1 collision resolution.
//INPUT:
//					openHashTbl[] - hash table array of integers for open 
//					addressing
//
//					hashVal - hashed value from the initial value from random array
//
//					hashTableSize - size of hash table from user
//
//OUTPUT:
//  Return Val:		finalAddress - new index in which to place value
//
//	
// IMPLEMENTED BY: 	Chad Peters
//**********************************************************************

int QuadraticProbe(int openHashTbl[], int hashVal, int hashTableSize){
	
	int probeNum = PROBE_NUM_START;		// starts probe at 1 because there is already a collision
	int nextAddress = 0;				// tries another idx address to store initialValue
	int finalAddress = 0;				// final idx address
	int tempAddress = 0;				// temp placeholder for collision addresses
	
	tempAddress = hashVal;
	
	do {
		
		//change idx
		nextAddress = (probeNum * probeNum) + tempAddress;
					
		// if idx is full or the new address is the same as the initialValue
		if(openHashTbl[nextAddress] != 0){
			
			tempAddress = nextAddress;
			probeNum++;
			
		}else if(openHashTbl[nextAddress] == 0){
			
			finalAddress = nextAddress % hashTableSize;
			
		}
		
	}while(finalAddress == 0);
	
	return finalAddress;
}

//*********************************************************************
// FUNCTION: 		DoubleHashValue
// DESCRIPTION: 	Creates a double hash of given value if the previously
//					hashed value is a duplicate in an open addressing hash
//					table. Used for test 2 collision resolution
//
//INPUT:
//					openHashTbl[] - hash table array of integers for open 
//					addressing
//
//					hashValue - initial hashed value
//
//					initialValue - integer value from random array
//
//					hashTableSize - size of hash table from user
//
//OUTPUT:
//  Return Val:		finalAddress - double hashed value to be used for
//					array index
//
//	
// IMPLEMENTED BY: 	Chad Peters
//**********************************************************************
int DoubleHashValue(int openHashTbl[], int hashValue, int initialValue, int hashTableSize){
	
	int rehashInitialVal = 0;
	int nextAddress = 0;
	int finalAddress = 0;
		
	// find next address since initial address doesn't work	
	// secondary rehash formula (key % (table size - 2)) + 1
	rehashInitialVal = (initialValue % (hashTableSize - SECONDARY_HASH_SUB_VAL)) + SECONDARY_HASH_ADD_VAL;
	nextAddress = (hashValue + rehashInitialVal) % hashTableSize;	// assign the nextAddress		
				
	do {		

		if(openHashTbl[nextAddress] != 0){
			
			// keep checking the nth pos for an empty spot
			nextAddress += rehashInitialVal; 
			
			// return to beginning at different pos to continue searching for empty spot
			if(nextAddress > hashTableSize){
				
				nextAddress -= hashTableSize;
				
			} // end if
		
		} else if(openHashTbl[nextAddress] == 0){
		
			// when nextAddress is finally empty create the final address
			finalAddress = nextAddress;
		
		}// end if else
	
	// continue to loop unless finalAddress has a value other than 0	
	}while(finalAddress == 0);	
	
	return finalAddress;

}

//*********************************************************************
// FUNCTION: 		OpenHTInsertValues
// DESCRIPTION: 	Inserts random integer values from randomArray
//					into open hash tables and resolves collisions
//					by either QuadraticProbing or DoubleHashing. Arrays
//					and hash tables are modified by reference.
//
//INPUT:
//					menuChoice - type of collision method defined by user
//
//					openHashTbl[] - hash table array of integers for open 
//					addressing passed by reference
//
//					randomArray[] - random array of integers
//
//					idxStatusList[] - array list correlating with filled
//					data in hash table passed by reference
//
//					hashTableSize - size of hash table from user
//
//OUTPUT:
//  Return Val:		openHashTbl[] - full hash table with random integers
//					from randomArray passed by reference
//
//					idxStatusList[] - array list correlating with
//					filled data in hash table passed by reference
//
//CALLS TO:			HashValue()
//				QuadraticProbe()
//				DoubleHashValue()
//	
// IMPLEMENTED BY: 	Chad Peters
//**********************************************************************

void OpenHTInsertValues(char menuChoice, int* &openHashTbl, int randomArray[], int* &idxStatusList, int hashTableSize){

	int initialValue = 0,				// placeholder for each initial value to be hashed
		arrayCounter = 0,				// random array counter
		hashVal = 0,					// hashed initial value
		finalAddress = 0;				// final hash table cell address after collision resolution

    //******DEBUG***********
    ofstream dataOut;
    string filename = "testfile.txt";
    //******DEBUG***********
    
	if(menuChoice == MENU_QUADRATIC){
	
		do {
				
			initialValue = randomArray[arrayCounter];
			arrayCounter++;
				
			hashVal = HashValue(initialValue, hashTableSize);
		
			if(idxStatusList[hashVal] == 0){
				
				openHashTbl[hashVal] = initialValue;
				idxStatusList[hashVal] = DATA_IN_CELL;
					
			} else {

				finalAddress = QuadraticProbe(openHashTbl, hashVal,  hashTableSize);
				
				openHashTbl[finalAddress] = initialValue;
				idxStatusList[finalAddress] = DATA_IN_CELL;
					
			} // end if else
				
		}while(arrayCounter < RANDOM_ARRAY_UNIQUE_VALUES);
	
    	//**************************DEBUG******************************
    	dataOut.open(filename.c_str());
    	for(int checkNum = 0; checkNum < hashTableSize; checkNum++){
    	
    	 	dataOut << "openHashTbl[" << checkNum << "]: " << openHashTbl[checkNum] << "\n";

		} // end for
		dataOut.close();
    	//**************************DEBUG*********************************
    			
    	arrayCounter = 0;
		
	} else if(menuChoice == MENU_DOUBLE){
		
		do {
				
			initialValue = randomArray[arrayCounter];
			arrayCounter++;
				
			hashVal = HashValue(initialValue, hashTableSize);
			
			if(idxStatusList[hashVal] == 0){
				
				openHashTbl[hashVal] = initialValue;
				idxStatusList[hashVal] = DATA_IN_CELL;
				
			} else {

				finalAddress = DoubleHashValue(openHashTbl, hashVal, initialValue,  hashTableSize);
				
				openHashTbl[finalAddress] = initialValue;
				idxStatusList[finalAddress] = DATA_IN_CELL;
					
			} // end if else
				
		}while(arrayCounter < RANDOM_ARRAY_UNIQUE_VALUES);

		//**************************DEBUG******************************
		dataOut.open(filename.c_str());
		for(int checkNum = 0; checkNum < hashTableSize; checkNum++){
    	
    	 	dataOut << "openHashTbl[" << checkNum << "]: " << openHashTbl[checkNum] << "\n";

		} // end for
		dataOut.close();
  		//**************************DEBUG*********************************
    			
  		arrayCounter = 0;		
		
	} // end if else if
	
}