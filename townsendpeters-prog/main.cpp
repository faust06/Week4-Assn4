//program heading goes here

#include "Common.h"

using namespace std;

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
        
    //asks user which type of test they would like to run
    do{
        //initializes randomArray with unique values
        InitializeRandomArray(randomArray);
        
    	// display menu for user and get menu choice
    	menuChoice = GetMenuChoice();
        
        //asks user for size of hash table to be used
        hashTableSize = GetTableSize();
        
        switch (menuChoice) {
            case MENU_QUADRATIC:
            case MENU_DOUBLE:
                    // Initialize our hashtable and corresponding index list
                    // Check for memory alloc fail
                    try {
                        InitializeOpenTbl(openHashTbl, idxStatusList, hashTableSize);
                    } catch (bad_alloc& ex){
                        cerr << "Memory allocation failure -- hash table / index were not fully initialized.";
                        noMemory = true;
                    } // end try catch
                
                    //inserts values into open address hash table
                    OpenHTInsertValues(menuChoice, openHashTbl, randomArray, idxStatusList, hashTableSize);
                
                break;
                
            case MENU_CHAINED:
                    // Initialize our hashtable and corresponding index list
                    // Check for memory alloc fail
                    try {
                        InitializeChnTbl(chnHashTbl, hashTableSize);
                    } catch (bad_alloc& ex){
                        cerr << "Memory allocation failure -- hash table / index were not fully initialized.";
                        noMemory = true;
                    } // end try catch
            
                    //inserts values into separate chaining hash table
                    ChainHTInsertValues(chnHashTbl, randomArray, hashTableSize);
                
                break;
                
            default:
                break;
        }
        
        //finds the average and predicted average number of searches for a selected collision resolution method
        totalSearches = HashSearching(menuChoice, randomArray, openHashTbl, chnHashTbl, hashTableSize, idxStatusList, avg, kAvg);
        
        //displays results to user
        DisplayResults(menuChoice, hashTableSize, totalSearches, avg, kAvg);
        
        runAgainChoice = KeepTesting();
   
	}while(!noMemory && runAgainChoice != EXIT_PROGRAM);

    return 0;
}
