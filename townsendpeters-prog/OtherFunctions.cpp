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
// FUNCTION: 		GetMenuChoice
// DESCRIPTION: 	Gets menu choice from user and error checks it
//INPUT:
//					menuChoice - number entered by user
//
//OUTPUT:
//  Return Val:		menuChoice - error checked number
//
// IMPLEMENTED BY: 	Chad Peters
//**********************************************************************

int GetMenuChoice(){
	
	int menuChoice = 0;

do{

		cout << endl << "COLLISION RESOLUTION ANALYSIS PROGRAM\n" << endl
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
						
		} else if (menuChoice > MENU_CHAINED && menuChoice < MENU_QUADRATIC){
		
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
//
//OUTPUT:
//  Return Val:		userNum - error checked number
//
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
						
		} else if (userNum < HASH_TABLE_MINIMUM_SIZE){
		
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
//
//OUTPUT:
//  Return Val:		userChar - error checked char
//
// IMPLEMENTED BY: 	Chad Peters
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

//*********************************************************************
// FUNCTION: 		RandomNum()
// DESCRIPTION: 	generates a random number between RANDOM_ARRAY_VALUE_MIN and RANDOM_ARRAY_VALUE_MAX
// OUTPUT:
// 	Return Val: 	newRandomNum
// IMPLEMENTED BY: 	Neil Townsend
//**********************************************************************
int RandomNum()
{
    int newRandomNum = 0;                           //randomly generated number

    //generates random number within acceptable ranges
    newRandomNum = random() % RANDOM_ARRAY_VALUE_MAX + RANDOM_ARRAY_VALUE_MIN;
    
    //returns new random number
    return newRandomNum;
}

//*********************************************************************
// FUNCTION: 		InitializeRandomArray()
// DESCRIPTION: 	initializes the random array with RANDOM_ARRAY_UNIQUE_VALUES worth of random values
// INPUT:
// 	Parameters: 	randomArray[] - array that will contain unique random values
// OUTPUT:
// 	Parameters: 	randomArray[] - array that will contain unique random values
// CALLS TO:        RandomNum()
//                  DuplicateValue()
// IMPLEMENTED BY: 	Neil Townsend
//**********************************************************************
bool DuplicateValue(int randomArray[], int newRandomNum, int randomCount)
{
    bool dupFound = false;                          //boolean to check whether newRandomNum already exists
                                                    //in randomArray
    
    //checks all of randomArray to see if newRandomNum already exists
    for(int dupCounter = 0; dupCounter < randomCount; dupCounter++) {
        if(randomArray[dupCounter] == newRandomNum) {
            dupFound = true;
        }
    }
    
    //returns boolean for whether or not newRandomNum is unique
    return dupFound;
}
//*********************************************************************
// FUNCTION: 		InitializeRandomArray()
// DESCRIPTION: 	initializes the random array with RANDOM_ARRAY_UNIQUE_VALUES worth of random values
// INPUT:
// 	Parameters: 	randomArray[] - array that will contain unique random values
// OUTPUT:
// 	Parameters: 	randomArray[] - array that will contain unique random values
// CALLS TO:        RandomNum()
//                  DuplicateValue()
// IMPLEMENTED BY: 	Neil Townsend
//**********************************************************************
void InitializeRandomArray(int randomArray[])
{
    int newRandomNum = 0;                          //randomly generated num to place into array if unique
    
    //seeds random number generator with the current time
    srandom(time(NULL));
    
    //fills randomArray with unique random values
    for(int randomCount = 0; randomCount < RANDOM_ARRAY_UNIQUE_VALUES; randomCount++) {
        do {
            //generates new random num
            newRandomNum = RandomNum();
        
            //checks to make sure value does not already exist in array
            if(!DuplicateValue(randomArray, newRandomNum, randomCount)) {
                randomArray[randomCount] = newRandomNum;
                cout << "Inserting new value: " << newRandomNum << " into index " << randomCount << endl;
            }
        }while(randomArray[randomCount] == 0);
    }
}




















