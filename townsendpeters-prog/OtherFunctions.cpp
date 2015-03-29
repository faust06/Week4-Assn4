// File description goes here

#include "OtherFunctions.h"
#include "Common.h"

using namespace std;

//*********************************************************************
// FUNCTION: 		CalculateAvg()
// DESCRIPTION: 	calculates the average number of searches that were made to an item
//                  with the given collision resolution method
// INPUT:
// 	Parameters: 	totalSearches - total number of searches that were performed
// OUTPUT:
// 	Return Val: 	avg - average number of searches for each item
// IMPLEMENTED BY: 	Neil Townsend
//**********************************************************************
double CalculateAverage(int totalSearches)
{
    double avg;                             //average searches performed per value in given hashtable

    //calculates average by dividing the total searches by the number of values that were searched for
    //ensures that the returned value is a double by static casting the total searches as a double
    avg = static_cast<double>(totalSearches) / (RANDOM_ARRAY_UNIQUE_VALUES / RANDOM_ARRAY_SEARCH_DIVISION);
    
    return avg;
}

//*********************************************************************
// FUNCTION: 		CalculateKnuthAvg()
// DESCRIPTION: 	Calculates the Knuth average for the predicted number
//                  of searches for each item in a hash table
// INPUT:
// 	Parameters: 	totalSearches - total number of searches performed
//                  testNum - current test being performed
//                  loadFactor - load factor for given hashtable
// OUTPUT:
// 	Return Val: 	kAvg - knuth predicted average of searches for each item
// CALLS TO:        log()
// IMPLEMENTED BY: 	Neil Townsend
//**********************************************************************
double CalculateKnuthAverage(int totalSearches, int testNum, double loadFactor)
{
    double kAvg;                            //predicted knuth average for collision resolution method
    
    //calculates the Knuth predicted average for a given collision resolution method depending on the test being run
    switch (testNum) {
        case TEST_QUADRATIC_PROBING: kAvg = 1 - log(1 - loadFactor) - (loadFactor / 2);
            break;
        case TEST_DOUBLE_HASHING: kAvg = (-log(1 - loadFactor)) / loadFactor;
            break;
        case TEST_SEPARATE_CHAINING: kAvg = 1 + (loadFactor / 2);
            break;
        default:
            break;
    }
    
    return kAvg;
}

//*********************************************************************
// FUNCTION: 		RandomNum
// DESCRIPTION: 	Returns random integer between 1 - 30,000
//
//OUTPUT:
//  Return Val:		rNum - random integer between 1 - 30,000
//
// IMPLEMENTED BY: 	Chad Peters
//**********************************************************************

int RandomNum(){
	
	int rNum = 0;
	
	// (rand() % 30,000 - 1 + 1) + 1
	rNum = (random() % (RANDOM_ARRAY_VALUE_MAX - RANDOM_ARRAY_VALUE_MIN + RANDOM_ARRAY_VALUE_MIN))
	        + RANDOM_ARRAY_VALUE_MIN;
	
	return rNum;
	
}


//*********************************************************************
// FUNCTION: 		GetMenuChoice
// DESCRIPTION: 	Gets menu choice from user and error checks it
//INPUT:
//					menuChoice - number entered by user
//OUTPUT:
//  Return Val:		menuChoice - error checked number
// IMPLEMENTED BY: 	Chad Peters
//**********************************************************************

int GetMenuChoice(){
	
	int menuChoice = 0;

do{
		cout << endl << "COLLISION RESOLUTION ANALYSIS PROGRAM\n" << endl
                  << "Please choose a collision resolution method:\n"
			 	  << "1 - Quadratic Probing Hashing\n"
			 	  << "2 - Double Hashing\n"
			 	  << "3 - Chained Hashing\n" << endl
			 	  << "Enter Menu Option (1/2/3): ";
		cin >> menuChoice;

		// if not a number
		if(cin.fail()){
			cout << endl << "invalid character -- ignoring line" << endl;
			cin.clear();	// clear cin stream
			cin.ignore(numeric_limits<int>::max(), '\n');	// numbers only
		}
        else if (menuChoice > MENU_CHAINED && menuChoice < MENU_QUADRATIC){
			cout << endl << "Must choose option 1, 2, or 3." << endl;
		}// end if else if		

	}while(menuChoice != MENU_QUADRATIC && menuChoice != MENU_DOUBLE && menuChoice != MENU_CHAINED);
	
	cout << endl;
	
	return menuChoice;
}

//*********************************************************************
// FUNCTION: 		GetTableSize
// DESCRIPTION: 	Gets hash table size from user and error checks
//					user input
//INPUT:
//					userNum - number entered by user
//OUTPUT:
//  Return Val:		userNum - error checked number
// IMPLEMENTED BY: 	Chad Peters
//**********************************************************************
int GetTableSize(){
	int userNum = 0;
	
    // error check user input for >= 6700 hash table size
	do{
		cout << "Please enter a hash table size (min val of 6700): ";
		cin >> userNum;
	
		// if not a number
		if(cin.fail()){
			cout << endl << "invalid character -- ignoring line" << endl;
			cin.clear();	// clear cin stream
			cin.ignore(numeric_limits<int>::max(), '\n');	// numbers only
		}
        else if (userNum < HASH_TABLE_MINIMUM_SIZE){
			cout << endl << "Table size must be >= 6700." << endl;
		}// end if else if	
	
	}while(!(userNum >= HASH_TABLE_MINIMUM_SIZE)); // end while
	
	return userNum;
}

//*********************************************************************
// FUNCTION: 		KeepTesting
// DESCRIPTION: 	Gets char from user to see if user wants to continue hash testing and error
//					checks user input
//INPUT:
//					userChar - char entered by user
////OUTPUT:
//  Return Val:		userChar - error checked char
//// IMPLEMENTED BY: 	Chad Peters
//**********************************************************************
char KeepTesting(){
	char userChar = '-';
	
	//USED AT END TO CONTINUE OR QUIT
   	// error check user input for Y or N
	do{
		cout << endl << "Do you want to conduct another hashing test?(Y/N): ";
		cin >> userChar;
		userChar = toupper(userChar);
		
		//debug
		cout << endl << "userChar: " << userChar << endl;	
		system("PAUSE");
	
		// if not a number
		if(userChar != EXIT_PROGRAM && userChar != CONT_PROGRAM){
			cout << endl << "invalid character -- ignoring line" << endl;
			cin.clear();	// clear cin stream
			cin.ignore(numeric_limits<char>::max(), '\n');	// char only
		} // end if
	
	}while(userChar != CONT_PROGRAM && userChar != EXIT_PROGRAM); // end do while
	
	return userChar;
}

//**********************************************************************
// FUNCTION: 		DuplicateValue
// DESCRIPTION: 	Searches through random array to make sure that
//					new random value does not already exist in array.
//INPUT:
//					randomArray[] - array containing random integers
//					between the values of 1 - 30,000
//					searchValue - new value to search through array for
//OUTPUT:
//  Return Val:		dupFound - boolean for whether there is a duplicate
//					value
// IMPLEMENTED BY: 	Chad Peters
//**********************************************************************
bool DuplicateValue(int randomArray[], int arrayCounter, int searchValue){
	int i = 0;
	bool dupFound = false;
	
	while(i < arrayCounter && !dupFound){
		// change dupFound to true if duplicate num is found
		if(searchValue == randomArray[i]){
			dupFound = true;
		} // end if
        
		i++;	// increment loop counter
	} // end while
	
	return dupFound;
	
}

//*********************************************************************
// FUNCTION: 		InitializeRandomArray
// DESCRIPTION: 	Initializes random array with 5000 random values
//INPUT:
//					randomArray[] - empty array
//OUTPUT:
//  Return Val:		randomArray[] - array of random integers between the 
//                                  range of 1 - 30,000 -- no duplicates
//CALLS TO:			RandomNum()
//					DuplicateValue()
// IMPLEMENTED BY: 	Chad Peters
//**********************************************************************
void InitializeRandomArray(int randomArray[]){
	int rNum = 0;
    
	//seeds random number generator with system clock
	srandom(time(NULL));
    
	for(int arrayCounter = 0; arrayCounter < RANDOM_ARRAY_UNIQUE_VALUES; arrayCounter++){
		// get random num
		rNum = RandomNum();

		// first time no dupes, so add to array
		if( arrayCounter == 0){
			randomArray[arrayCounter] = rNum;
		} // end if
		
		if(!DuplicateValue(randomArray, arrayCounter, rNum)){
			// if no dupes add random int to array
			randomArray[arrayCounter] = rNum;
		}
        else {
			// if dupe is found subtract from arrayCounter to ensure array will be filled
			arrayCounter--;
		}// end if else
        
	} // end for	
}

//*********************************************************************
// FUNCTION: 		DisplayResults()
// DESCRIPTION: 	Displays results of collision resolution method to the user
// INPUT:
//					hashTableSize - size of hashtable given by user
//                  totalSearches - the total number of searches needed to find half the random values
//                  avg - the average number of searches needed per value
//                  kAvg - the predicted average number of searches needed per value
// CALLS TO:        CalculateLoadFactor()
// IMPLEMENTED BY: 	Neil Townsend
//**********************************************************************
void DisplayResults(int testNum, int hashTableSize, int totalSearches, double avg, double kAvg)
{
    //sets number of decimal places
    cout << fixed << showpoint << setprecision(OUTPUT_SIG_DIGS);
    
    //displays results to user
    cout << RANDOM_ARRAY_UNIQUE_VALUES << " values loaded into a " << hashTableSize << " element hash table" << endl;
    cout << "Load Factor: " << CalculateLoadFactor(hashTableSize) << endl << endl;
    
    cout << "Results of searching for " << RANDOM_ARRAY_UNIQUE_VALUES / RANDOM_ARRAY_SEARCH_DIVISION << " items:" << endl << endl;
    
    cout << "     ";
    switch (testNum) {
        case TEST_QUADRATIC_PROBING: cout << "Quadratic Probing" << endl;
            break;
        case TEST_DOUBLE_HASHING: cout << "Double Hashing" << endl;
            break;
        case TEST_SEPARATE_CHAINING: cout << "Chained Hashing" <<endl;
            break;
        default:
            break;
    }
    
    cout << setw(OUTPUT_TOTAL_SEARCH_FIELD) << totalSearches << " items examined (avg = " << avg << " items examined per search)" << endl;
    cout << setw(OUTPUT_TOTAL_SEARCH_FIELD) << "vs" << " Knuth predicted avg = " << kAvg << " items examined per search" << endl;
    
}

//*********************************************************************
// FUNCTION: 		InitializeTable()
// DESCRIPTION: 	Initializes and fills a hashtable using the selected collision resolution method
// INPUT:
//                  testNum - collision resolution method selected by the user
//                  openHashTable - pointer to open address hashtable
//                  chnHashTable - pointer to chained hashing hashtable
//                  randomArray - array containing random values
//                  idxStatusList - pointer to array containing status of open addressing hashtable indices
//					hashTableSize - size of hashtable given by user
// OUTPUT:
//  Return Value:   noMemory - boolean to check whether memory is full
//  Parameters:     openHashTable - pointer to open address hashtable
//                  chnHashTable - pointer to chained hashing hashtable
//                  idxStatusList - pointer to array containing status of open addressing hashtable indices
// CALLS TO:        InitializeOpenTbl()
//                  OpenHTInsertValues()
//                  InitializeChnTbl()
//                  ChainHTInsertValues()
// IMPLEMENTED BY: 	Neil Townsend
//**********************************************************************
bool InitializeTable(int testNum, int* &openHashTable, struct chnArray* &chnHashTable, int randomArray[], int* &idxStatusList, int hashTableSize)
{
    bool noMemory = false;                      //boolean to check whether or not memory is full
    
    switch (testNum) {
        case MENU_QUADRATIC:
        case MENU_DOUBLE:
            // Initialize our hashtable and corresponding index list
            // Check for memory alloc fail
            try {
                InitializeOpenTbl(openHashTable, idxStatusList, hashTableSize);
            } catch (bad_alloc& ex){
                cerr << "Memory allocation failure -- open addressing hashtable was not fully initialized.";
                noMemory = true;
            } // end try catch
            
            //if memory is not full, continues to value insertion
            if (!noMemory){
                //inserts values into open address hash table
                OpenHTInsertValues(testNum, openHashTable, randomArray, idxStatusList, hashTableSize);
                
            }
            break;
            
        case MENU_CHAINED:
            // Initialize our hashtable and corresponding index list
            // Check for memory alloc fail
            try {
                InitializeChnTbl(chnHashTable, hashTableSize);
            } catch (bad_alloc& ex){
                cerr << "Memory allocation failure -- chained hashtable was not fully initialized.";
                noMemory = true;
            } // end try catch
            
            if (!noMemory) {
                //inserts values into separate chaining hash table
                ChainHTInsertValues(chnHashTable, randomArray, hashTableSize);
            }
            break;
            
        default:
            break;
    }
    
    //returns whether or not memory is full
    return noMemory;
}

//*********************************************************************
// FUNCTION: 		DestroyTables()
// DESCRIPTION: 	deletes dynamically allocated memory for hashtables after a test has been run
// INPUT:
//                  openHashTable - pointer to hashtable used for open addressing
//                  chnHashTable - pointer to hashtable used for chain hashing
//                  idxStatusList - pointer to array used for status of open addressing indices
// OUTPUT:
//  Parameters:     openHashTable - pointer to open address hashtable
//                  chnHashTable - pointer to chained hashing hashtable
//                  idxStatusList - pointer to array containing status of open addressing hashtable indices
// IMPLEMENTED BY: 	Neil Townsend
//**********************************************************************
void DestroyTables(int testNum, int* &openHashTable, struct chnArray* chnHashTable, int* &idxStatusList)
{
    
    switch (testNum) {
        case TEST_QUADRATIC_PROBING:
        case TEST_DOUBLE_HASHING:
            //deletes open addressing hashtable and reassigns pointer to NULL
            delete openHashTable;
            openHashTable = NULL;
            
            //deletes open addressing status list and reassigns pointer to NULL
            delete idxStatusList;
            idxStatusList = NULL;
            break;
        case TEST_SEPARATE_CHAINING:
            //deletes chain hashing hashtable and reassigns pointer to NULL
            delete chnHashTable;
            chnHashTable = NULL;
        default:
            break;
    }
}










