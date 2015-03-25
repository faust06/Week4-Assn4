//program heading goes here

#include "Common.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
	bool noMemory = false;				// handles memory allocation and allows for graceful exit of program
	char runAgainChoice = ' ';			// handles amount of testing that user wants to conduct, y to continue and n to stop
    int hashTableSize = 0;				// size of hash table as defined by user
	int menuChoice = 0;					// handles user input for menu options
    int *openHashTbl = NULL;			// initialize pointer for hash table
    int *idxStatusList = NULL;			// initialize pointer for corresponding index list for hash table
    chnArray *chnHashTbl = NULL;		// initialize pointer for chained hash table type
    
    do{
    	// display menu for user and get menu choice
    	menuChoice = GetMenuChoice();
        
        hashTableSize = GetTableSize();
        cout << endl << "hashTableSize: " << hashTableSize << endl;
        cout << endl << "Load Factor: " << CalculateLoadFactor(20000) << endl;
        
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
                break;
                
            default:
                break;
        }
        
		// check if user wants to continue testing or quit
		runAgainChoice = KeepTesting();
	
	// if memory fails
	}while(!noMemory && runAgainChoice != EXIT_PROGRAM);
    	
    return 0;
}
