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
        randomArray[RANDOM_ARRAY_UNIQUE_VALUES] = {0};      //array that will contain random values
    chnArray *chnHashTbl = NULL;                            // initialize pointer for chained hash table type
    
    //initializes randomArray with unique values
    InitializeRandomArray(randomArray);
    
    /*for(int checkNum = 0; checkNum < RANDOM_ARRAY_UNIQUE_VALUES; checkNum++) {
        cout << randomArray[checkNum] << endl;
    }*/
    
    //asks user which type of test they would like to run
    do{
    	// display menu for user and get menu choice
    	menuChoice = GetMenuChoice();
        
        //asks user for size of hash table to be used
        hashTableSize = GetTableSize();
        
        //***************DEBUG******************
        cout << endl << "hashTableSize: " << hashTableSize << endl;
        cout << endl << "Load Factor: " << CalculateLoadFactor(hashTableSize) << endl;
        //**************************************
        
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
        
        runAgainChoice = KeepTesting();
   
	}while(!noMemory && runAgainChoice != EXIT_PROGRAM);

    return 0;
}
