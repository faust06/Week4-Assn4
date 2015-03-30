//*********************************************************************
// CODE FILENAME:   HashADT.cpp
// DESCRIPTION:     file containing the implementation for functions defined in HashADT.h
//                  or exit the program.
// CLASS/TERM:      2015 Spring 8 week Section 2
// DESIGNER:        Neil Townsend and Chad Peters
// FUNCTIONS        HashValue()                 Calculates hash value of a number using modulo division
//                  CalculateLoadFactor()       Calculates the load factor of a hashtable
//                  InitializeOpenTbl()         allocates and initializes a hashtable to use for open addressing
//                  InitializeChnTbl()          allocates and initializes a hashtable to use for chained hashing
//                  HashSearching()             searches through a selected hashtable and calculates average and predicted average searches
//                  FindOpenValue()             finds values in an open addressing hashtable
//                  SearchQuadValue()           searches for a given value in a hashtable using quadratic probing collision resolution
//                  SearchDoubleHashValue()     searches for a given value in a hashtable using double hashing collision resolution
//                  FindChainValue()            finds values in a chain hashing hashtable
//                  QuadraticProbe()            resolves collision when placing values into a hashtable using quadratic probing
//                  DoubleHashValue()           resolves collision when placing values into a hashtable using double hashing
//                  OpenHTInsertValues()        inserts values into an open addressing hashtable
//                  ChainProbe()                resolves collision when placing values into a hashtable using chained hashing
//                  ChainHTInsertValues()       inserts values into a chained hashing hashtable
//**********************************************************************

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
// OUTPUT:
// 	Return Val: 	chnHashTbl - initialized array of ints for hash table
//					passed back by reference
// IMPLEMENTED BY: 	Chad Peters
//**********************************************************************
void InitializeChnTbl(struct chnArray* &chnHashTbl, int hashTableSize)
{
	// allocate memory for array OF POINTERS
	chnHashTbl = new (nothrow) chnArray[hashTableSize];

	// initialize all cells in chnTable to 0
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
int HashSearching(int testNum, int randomArray[], int *openHashTable, struct chnArray *chnHashTable, int hashTableSize, int *idxStatusList, double &avg, double &kAvg)
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
    
    return totalSearches;
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
int FindOpenValue(int testNum, int randomArray[],int *openHashTable,int *idxStatusList, int hashTableSize)
{
    int totalSearches = 0;                  //total number of searches needed to find values in the hash table
    int randomSearches = 0;                 //how many random values have been searched for
    
    switch (testNum) {
        case TEST_QUADRATIC_PROBING:
            //calculates total searches needed for quadratic collision resolution
            do {
                //calculates searches needed for each value
                totalSearches += SearchQuadValue(openHashTable, randomArray[randomSearches], hashTableSize);
                
                //increases search counter
                randomSearches += RANDOM_ARRAY_SEARCH_DIVISION;
                
            } while (randomSearches < RANDOM_ARRAY_UNIQUE_VALUES);
            break;
        case TEST_DOUBLE_HASHING:
            //calculates total searches needed for double hashing collision resolution
            do {
                //calculates searches needed for each value
                totalSearches += SearchDoubleHashValue(openHashTable, randomArray[randomSearches], hashTableSize);
                
                //increases search counter
                randomSearches += RANDOM_ARRAY_SEARCH_DIVISION;
                
            } while (randomSearches < RANDOM_ARRAY_UNIQUE_VALUES);
            break;
            
        default:
            break;
    }

    
    
    return totalSearches;
}

//*********************************************************************
// FUNCTION: 		searchQuadValue()
// DESCRIPTION: 	calculates quadratic probe value and number of time that hashtable
//                  had to be searched for the value to be found
// INPUT:
// 	Parameters:     openHashTable[] - hash table array of integers for open addressing
//                  hashValue - initial hash value
//					hashTableSize - size of hash table from user
// OUTPUT:
// 	Return Value: 	totalSearches - total number of searches needed to find all values
// CALLS TO:        HashValue()
// IMPLEMENTED BY: 	Neil Townsend
//**********************************************************************
int SearchQuadValue(int *openHashTable, int initialValue, int hashTableSize)
{
    int totalSearches = 0;              //number of times array was searched for value
    int probeNum = PROBE_NUM_START;		//collision counter for quadratic probe
    int nextAddress = 0;				//next index in which to search for initialValue
    int tempAddress = 0;				//previous index searched
    
    tempAddress = HashValue(initialValue, hashTableSize);
    
    //checks to see if the value is in the hashed index
    if (openHashTable[tempAddress] == initialValue) {
        totalSearches += 1;
    }
    //if there was a previous collision, value is searched for
    else {
        //continue searching through indices until value is found
        do {
            //calculates next index in which to look
            nextAddress = (probeNum * probeNum) + tempAddress;
            
            //makes sure that nextAddress is withing the bounds of the hash table
            if(nextAddress >= hashTableSize) {
                nextAddress = nextAddress % hashTableSize;
            }
            
            tempAddress = nextAddress;
            probeNum++;
            
            //increases search counter
            totalSearches += 1;
            
        }while(openHashTable[nextAddress] != initialValue);
    }
    
    //returns number of searches needed to find value
    return totalSearches;
}

//*********************************************************************
// FUNCTION: 		searchDoubleHashValue()
// DESCRIPTION: 	calculates Double Hash value and number of times that hashtable
//                  had to be searched for the value to be found
// INPUT:
// 	Parameters:     openHashTable[] - hash table array of integers for open addressing
//                  hashValue - initial hash value
//					hashTableSize - size of hash table from user
// OUTPUT:
// 	Return Value: 	totalSearches - total number of searches needed to find all values
// CALLS TO:        HashValue()
// IMPLEMENTED BY: 	Neil Townsend
//**********************************************************************
int SearchDoubleHashValue(int *openHashTable, int initialValue, int hashTableSize)
{
    int totalSearches = 0;                      //number of times array was searched for value
    int rehashInitialVal = 0;                   //rehash value for new index
    int nextAddress = 0;                        //next index in which to search for initialValue
    
    //calculates hash value of initialValue to find starting index
    nextAddress = HashValue(initialValue, hashTableSize);
    
    if (openHashTable[nextAddress] == initialValue) {
        totalSearches += 1;
    }
    else {
        do {
        //calculates next index to search by creating a double hash of the first hash
        // secondary rehash formula (key % (table size - 2)) + 1
        rehashInitialVal = (initialValue % (hashTableSize - SECONDARY_HASH_SUB_VAL)) + SECONDARY_HASH_ADD_VAL;
        nextAddress = (nextAddress + rehashInitialVal); // %hashTableSize	// assign the nextAddress

        //makes sure next address is not past end of hashtable
        if(nextAddress > hashTableSize){
            nextAddress = nextAddress % hashTableSize;
        }
            
        //increases search count
        totalSearches += 1;
        
        }while(openHashTable[nextAddress] != initialValue);
    }

    //returns number of searches needed to find value
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
    int totalSearches = 0,                  //total number of searches needed to find a value in the hash table
        nextAddress = 0,                    //next address in which to search for number
        randomSearches = 0;                 //number of searches used so far
    hashNode *current;                      //used to search through linked list at a hashed index
    
    do {
        //calculates initial hash value for number
        nextAddress = HashValue(randomArray[randomSearches], hashTableSize);

        //starts at first node in linked list for hashed value
        current = chnHashTable[nextAddress].link;
        
        //continues searching nodes until value is found
        while(current->value != randomArray[randomSearches]) {
            current = current->next;
            totalSearches += 1;
        }
        
        //increases search counter to account for initial hash
        totalSearches += 1;
        
        //increases random array search value so that half the values are searched
        randomSearches += RANDOM_ARRAY_SEARCH_DIVISION;
        
    }while (randomSearches < RANDOM_ARRAY_UNIQUE_VALUES);
    
    return totalSearches;
}

//**********************************************************************
// FUNCTION: 		QuadraticProbe
// DESCRIPTION: 	Resolves collisions in an open addressing hash table
//					by quadratic probe values. Used to avoid primary
//					clustering. Used for test 1 collision resolution.
//INPUT:
//					openHashTbl[] - hash table array of integers for open addressing
//					hashVal - hashed value from the initial value from random array
//					hashTableSize - size of hash table from user
//OUTPUT:
//  Return Val:		finalAddress - new index in which to place value
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
        
        //if end of array is reached, rolls back around to the beginning
        if(nextAddress >= hashTableSize) {
            nextAddress = nextAddress % hashTableSize;
        }
					
		// if idx is full
		if(openHashTbl[nextAddress] != 0){

            tempAddress = nextAddress;
            probeNum++;
        }
        else if(openHashTbl[nextAddress] == 0){
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
//					openHashTbl[] - hash table array of integers for open addressing
//					hashValue - initial hashed value
//					initialValue - integer value from random array
//					hashTableSize - size of hash table from user
//OUTPUT:
//  Return Val:		finalAddress - double hashed value to be used for
//					array index
// IMPLEMENTED BY: 	Chad Peters
//**********************************************************************
int DoubleHashValue(int openHashTbl[], int hashValue, int initialValue, int hashTableSize){
	
	int rehashInitialVal = 0;
	int nextAddress = hashValue;
	int finalAddress = 0;
    bool found = false;

            // find next address since previous address doesn't work
            // secondary rehash formula (key % (table size - 2)) + 1
	rehashInitialVal = (initialValue % (hashTableSize - SECONDARY_HASH_SUB_VAL)) + SECONDARY_HASH_ADD_VAL;
				
	do {
		if(openHashTbl[nextAddress] != 0){
            
            //continue to re-add the rehash and mod until an open spot is found
            nextAddress += rehashInitialVal;
            nextAddress %= hashTableSize;
                            
            // return to beginning at different pos to continue searching for empty spot
            if(nextAddress > hashTableSize){
                nextAddress = nextAddress % hashTableSize;
            } // end if
		}
        else if(openHashTbl[nextAddress] == 0){
			// when nextAddress is finally empty create the final address
			finalAddress = nextAddress;
            found = true;
		}// end if else
	
	// continue to loop unless finalAddress has a value other than 0	
	}while(!found);
	
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
//					menuChoice -    type of collision method defined by user
//					openHashTbl[] - hash table array of integers for open 
//                                  addressing passed by reference
//					randomArray[] - random array of integers
//					idxStatusList[] -   array list correlating with filled
//                                      data in hash table passed by reference
//					hashTableSize - size of hash table from user
//
//OUTPUT:
//  Return Val:		openHashTbl[] - full hash table with random integers
//                                  from randomArray passed by reference
//					idxStatusList[] -   array list correlating with
//                                      filled data in hash table passed by reference
//CALLS TO:			HashValue()
//                  QuadraticProbe()
//                  DoubleHashValue()
//	
// IMPLEMENTED BY: 	Chad Peters
//**********************************************************************
void OpenHTInsertValues(int menuChoice, int* &openHashTbl, int randomArray[], int* &idxStatusList, int hashTableSize){
	int initialValue = 0,				// placeholder for each initial value to be hashed
		arrayCounter = 0,				// random array counter
		hashVal = 0,					// hashed initial value
		finalAddress = 0;				// final hash table cell address after collision resolution

    //******DEBUG***********
    ofstream dataOut;
    string filename = "testfile.txt";
    //******DEBUG***********
    
    do {
        //picks the next value from randomArray
        initialValue = randomArray[arrayCounter];
        arrayCounter++;
        
        //creates hash value of random value
        hashVal = HashValue(initialValue, hashTableSize);
        
        //checks to see if value can be placed directly into hashtable
        if(idxStatusList[hashVal] == 0){
            
            openHashTbl[hashVal] = initialValue;
            idxStatusList[hashVal] = DATA_IN_CELL;
        }
        //if value cannot be placed directly, resolves collision with user's choice of open addressing resolution
        else {
            switch (menuChoice) {
                case MENU_QUADRATIC: finalAddress = QuadraticProbe(openHashTbl, hashVal, hashTableSize);
                    break;
                case MENU_DOUBLE: finalAddress = DoubleHashValue(openHashTbl, hashVal, initialValue,  hashTableSize);
                default:
                    break;
            }
            
            openHashTbl[finalAddress] = initialValue;
            idxStatusList[finalAddress] = DATA_IN_CELL;
        } // end if else
        
        //continues until all random values has been placed
    }while(arrayCounter < RANDOM_ARRAY_UNIQUE_VALUES);
    
    //**************************DEBUG******************************
    dataOut.open("/Users/nrtownsend/Desktop/openHashDebug.txt");
    for(int checkNum = 0; checkNum < hashTableSize; checkNum++){
        
        dataOut << "openHashTbl[" << checkNum << "]: " << openHashTbl[checkNum] << "\n";
        
    } // end for
    dataOut.close();
    //**************************DEBUG*********************************
}

//*********************************************************************
// FUNCTION: 		ChainProbe()
// DESCRIPTION: 	Inserts value into the appropriate node of a separate chaining hashtable index
// INPUT:
//					chnHashTbl[] - hash table array of nodes
//					randomArray[] - random array of integers
//					randomValue - value that is being placed into hashtable
// OUTPUT:
//  Return value:   noMemory - boolean to check whether memory could be allocated
// IMPLEMENTED BY: 	Neil Townsend
//**********************************************************************
bool ChainProbe(struct chnArray *chnHashTable, int newHashValue, int randomValue)
{
    hashNode *current;                              //current node in hash table index
    hashNode *newNode;                              //new node to place into chnHashTable
    bool noMemory = false;                                  //boolean to check memory allocation
    
    //allocates memory for new node
    newNode = new (nothrow) hashNode;
    
    //as long as memory could be allocated, inserts value onto end of linked list
    if(newNode != NULL) {
        //assigns the new value to new node
        newNode->value = randomValue;
        newNode->next = NULL;
        
        //starts at beginning of chnHashTable index chain
        current = chnHashTable[newHashValue].link;
        
        //checks to see if chain is empty, otherwise continues until last node of chain is found
        if (current == NULL) {
            chnHashTable[newHashValue].link = newNode;
        }
        else {
            //finds end of chain for current index
            while (current->next != NULL) {
                current = current->next;
            }
            
            //inserts new node onto the end of the chain
            current->next = newNode;
        }
    }
    //if memory could not be allocated, error message displayed and function exited
    else {
        noMemory = true;
        cout << "Error - cannot allocate memory. Separate chaining cannot be tested" << endl;
    }
    
    return noMemory;
}


//*********************************************************************
// FUNCTION: 		ChainHTInsertValues
// DESCRIPTION: 	Inserts random integer values from randomArray into a separate chaining table
//                  and resolves collisions using separate chaining
// INPUT:
//					chnHashTbl[] - hash table array of nodes
//					randomArray[] - random array of integers
//					hashTableSize - size of hash table from user
// OUTPUT:
//  Return Value:   noMemory - boolean to test memory allocation
// CALLS TO:		HashValue()
//                  ChainProbe()
// IMPLEMENTED BY: 	Neil Townsend
//**********************************************************************
bool ChainHTInsertValues(struct chnArray *chnHashTable, int randomArray[], int hashTableSize)
{
    int newHashValue = 0;                           //hash value for current number
    bool noMemory = false;                          //boolean to test memory availability
    
    //loops through entire random array, placing value into chained hash table
    for(int insertCounter = 0; (insertCounter < RANDOM_ARRAY_UNIQUE_VALUES) && (!noMemory); insertCounter++) {
        
        //gets hash value for current random value being inserted into hash table
        newHashValue = HashValue(randomArray[insertCounter], hashTableSize);
        
        //inserts hash value into chain table at appropriate node
        noMemory = ChainProbe(chnHashTable, newHashValue, randomArray[insertCounter]);
    }
    
    //**************************DEBUG******************************
    ofstream dataOut;
    hashNode *current;
    dataOut.open("/Users/nrtownsend/Desktop/chnHashDebug.txt");
    for(int checkNum = 0; checkNum < hashTableSize; checkNum++){
        
        dataOut << "chnHashTbl[" << checkNum << "]: ";
        
        current = chnHashTable[checkNum].link;
        
        if (current == NULL) {
            dataOut << " 0 " << endl;
        }
        else {
            while (current != NULL) {
                dataOut << current->value << " and ";
                current = current->next;
            }
            dataOut << endl;
        }
        
        
    } // end for
    dataOut.close();
    //**************************DEBUG*********************************
    
    return noMemory;
}

















