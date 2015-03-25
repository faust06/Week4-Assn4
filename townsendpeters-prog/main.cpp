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
    	
    	// proceed to create and allocate memory for array of ints for hash table - QUADRATIC OR DOUBLE HASHING ONLY
    	if(menuChoice == MENU_QUADRATIC || menuChoice == MENU_DOUBLE){
    	
    		// do quadratic open addressing
    		if(menuChoice == MENU_QUADRATIC){
    			
    			cout << endl << "Open Addressing Hash Table -- Quadratic Probing initiatied. . ." << endl;
    			
    			// code stuff goes here
    			// more code stuff here
    			
			} // end if
			
			if(menuChoice == MENU_DOUBLE){
				
    			cout << endl << "Open Addressing Hash Table -- Double Hashing initiatied. . ." << endl;
    			
    			// code stuff goes here
    			// more code stuff here				
				
			}
    	
    		hashTableSize = GetTableSize();
		
			//debug
			cout << endl << "hashTableSize: " << hashTableSize << endl;
			cout << endl << "Load Factor: " << CalculateLoadFactor(20000) << endl;
	
			// Initialize our hashtable and corresponding index list
			// Check for memory alloc fail
			try {
	
				InitializeOpenTbl(openHashTbl, idxStatusList, hashTableSize);
		
			} catch (bad_alloc& ex){
		
				cerr << "Memory allocation failure -- hash table / index were not fully initialized.";
				noMemory = true; 
			
			} // end try catch
		
		} // end if
		
    	// proceed to create and allocate memory for array of ints linked with data nodes as hash table - CHAINING ONLY		
		if(menuChoice == MENU_CHAINED){

				
   			cout << endl << "Chained Hash Table -- Separate Chaining initiatied. . ." << endl;
    			
   			// code stuff goes here
   			// more code stuff here				

			
  			hashTableSize = GetTableSize();				

			//debug
			cout << endl << "hashTableSize: " << hashTableSize << endl;
			cout << endl << "Load Factor: " << CalculateLoadFactor(20000) << endl;
			
			// Initialize our hashtable and corresponding index list
			// Check for memory alloc fail
			try {
	
				InitializeChnTbl(chnHashTbl, hashTableSize);
		
			} catch (bad_alloc& ex){
		
				cerr << "Memory allocation failure -- hash table / index were not fully initialized.";
				noMemory = true; 
			
			} // end try catch
			
		} // end if

		
		
		// check if user wants to continue testing or quit
		runAgainChoice = KeepTesting();
	
	// if memory fails
	}while(!noMemory && runAgainChoice != EXIT_PROGRAM);
    	
    return 0;
}
