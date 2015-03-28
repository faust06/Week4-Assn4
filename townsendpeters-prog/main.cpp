//program heading goes here

#include "Common.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
	bool noMemory = false;									// handles memory allocation and allows for graceful exit of program
	char runAgainChoice = '-';								// handles amount of testing that user wants to conduct, y to continue and n to stop
    int hashTableSize = 0,									// size of hash table as defined by user
		menuChoice = 0,										// handles user input for menu options
		randomArray[RANDOM_ARRAY_UNIQUE_VALUES] = {0},		// initalize randomArray to 5000 cells
    	*openHashTbl = NULL,								// initialize pointer for hash table
    	*idxStatusList = NULL;								// initialize pointer for corresponding index list for hash table
    chnArray *chnHashTbl = NULL;							// initialize pointer for chained hash table type
    
    // put random numbers into an array for use in every test
    InitializeRandomArray(randomArray);
    
    //**************************DEBUG*******************************
    //for(int checkNum = 0; checkNum < RANDOM_ARRAY_UNIQUE_VALUES; checkNum++){
    	
    // 	cout << "randomArray[" << checkNum << "]: " << randomArray[checkNum] << endl;
    	
	//} // end for
    //**************************DEBUG*********************************
    
    do{
    	
    	//asks user for size of hash table to be used
    	hashTableSize = GetTableSize();
    	
    	//display menu for user and get menu choice
    	menuChoice = GetMenuChoice();
    	
    	//*************DEBUG*********************
    	cout << endl << "hashTableSize: " << hashTableSize << endl;
    	cout << endl << "Load Factor: " << CalculateLoadFactor(20000) << endl;
		
    	//****************************************
    	
    	switch (menuChoice){
    		
    		case MENU_QUADRATIC:

    			// Initialize our hashtable and corresponding index list
    			// Check for memory alloc fail
  				try {
	
					InitializeOpenTbl(openHashTbl, idxStatusList, hashTableSize);
		
				} catch (bad_alloc& ex){
		
					cerr << "Memory allocation failure -- hash table / index were not fully initialized.";
					noMemory = true; 
				
				} // end try catch 
				
				OpenHTInsertValues(menuChoice, openHashTbl, randomArray, idxStatusList, hashTableSize);
				
    			break;    			

    		case MENU_DOUBLE:
    			
     			// Initialize our hashtable and corresponding index list
    			// Check for memory alloc fail
  				try {
	
					InitializeOpenTbl(openHashTbl, idxStatusList, hashTableSize);
		
				} catch (bad_alloc& ex){
		
					cerr << "Memory allocation failure -- hash table / index were not fully initialized.";
					noMemory = true; 
				
				} // end try catch 

				OpenHTInsertValues(menuChoice, openHashTbl, randomArray, idxStatusList, hashTableSize);
				
    			break;
    			
    		case MENU_CHAINED:
 
     			// Initialize our hashtable and corresponding index list
    			// Check for memory alloc fail
  				try {
	
					InitializeOpenTbl(openHashTbl, idxStatusList, hashTableSize);
		
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
