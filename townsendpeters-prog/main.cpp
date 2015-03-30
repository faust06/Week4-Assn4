//*********************************************************************
// CODE FILENAME:   townsendpeters-assn3-prog.cpp
// DESCRIPTION:     Program analyzes hashtable collision resolution methods.
//                  Program asks the user what type of collision resolution they would like to test
//                  as well as the size of hashtable they would like to use. Program then fills a hashtable
//                  with unique random values and then search for half of these values in the hashtable.
//                  An analysis of the average number as well as a predicted average number of searches for the
//                  collision resolution method is then displayed to the user. The user can then opt to run another test
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
//                  CalculateAverage()          calculates the average number of searches per item in a hashtable
//                  CalculateKnuthAverage()     calculates the predicted average number of searches per item in a hashtable
//                  GetMenuChoice()             asks the user which collision resolution method they would like to test
//                  GetTableSize()              asks the user how large of a hashtable they would like to use for testing
//                  KeepTesting()               asks the user if they would like to run another collision resolution test
//                  RandomNum()                 generates a random number within a range of acceptable values
//                  DuplicateValue()            checks to see if the randomly generated number is unique
//                  InitializeRandomArray()     fills an array with unique random values
//                  DisplayResults()            displays results of collision resolution method to user
//                  InitializeTable()           handles allocation and initialization of hashtable to match user's choice
//                  DestroyTables()             frees up memory that was dynamically allocated for each test
//**********************************************************************
#include "Common.h"

using namespace std;


//**************************************************************************
// FUNCTION:  main
// DESCRIP:   Driver for program. Initializes variables and calls applicable
//            functions to initialize and fill hash tables. It also calculates
//			  and displays hashing analysis information. The program will loop
//			  until the user no longer wants to run hashing analysis.
// INPUT:
//		Parameters:  argc - number of arguments entered on command line
//                   *argv[] - array containing each argument
// OUTPUT:
//		Return Value: 0 on success
//CALLS TO:	    InitializeRandomArray()
//				GetMenuChoice()
//				GetTableSize()
//				InitializeTable()
//				HashSearching()
//				DisplayResults()
//				DestroyTables()
//				KeepTesting()
//**************************************************************************
int main(int argc, const char * argv[]) {
	bool noMemory = false;                                  // handles memory allocation and allows for graceful exit of program
	char runAgainChoice = ' ';                              // handles amount of testing that user wants to conduct, y to continue and n to stop
    int hashTableSize = 0,                                  // size of hash table as defined by user
        menuChoice = 0,                                     // handles user input for menu options
        *openHashTbl = NULL,                                // initialize pointer for hash table
        *idxStatusList = NULL,                              // initialize pointer for corresponding index list for hash table
        randomArray[RANDOM_ARRAY_UNIQUE_VALUES] = {0},      // array that will contain random values
        totalSearches = 0;                                  // total number of searches performed to find half the random values
    double  avg = 0,                                        // average number of searches for a collision resolution method
            kAvg = 0;                                       // predicted average number of searches for a collision resolution method
    chnArray *chnHashTbl = NULL;                            // initialize pointer for chained hash table type
    
    do{
        //initializes randomArray with unique values
        InitializeRandomArray(randomArray);
        
    	// display menu for user and get menu choice
    	menuChoice = GetMenuChoice();
        
        //asks user for size of hash table to be used
        hashTableSize = GetTableSize();
        
        //initializes hashtable with selected collision resolution method
        noMemory = InitializeTable(menuChoice, openHashTbl, chnHashTbl, randomArray, idxStatusList, hashTableSize);
        
        if (!noMemory) {
            //finds the average and predicted average number of searches for a selected collision resolution method
            totalSearches = HashSearching(menuChoice, randomArray, openHashTbl, chnHashTbl, hashTableSize, idxStatusList, avg, kAvg);
            
            //displays results to user
            DisplayResults(menuChoice, hashTableSize, totalSearches, avg, kAvg);
            
            //frees up dynamically allocated memory from test
            DestroyTables(menuChoice, openHashTbl, chnHashTbl, idxStatusList);
            
            //asks user if they would like to run another test
            runAgainChoice = KeepTesting();
        }

   
	}while(!noMemory && runAgainChoice != EXIT_PROGRAM);

    return 0;
}
