// File description goes here

#include "OtherFunctions.h"



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

		std::cout << std::endl << "HASHING PROGRAM OF AWESOMENESS\n" << std::endl
			 	  << "1 - Quadratic Probing Hashing\n"
			 	  << "2 - Double Hashing\n"
			 	  << "3 - Chained Hashing\n" << std::endl
			 	  << "Enter Menu Option (1/2/3): ";
		 	  
		std::cin >> menuChoice;

		// if not a number
		if(std::cin.fail()){
			
			std::cout << std::endl << "invalid character -- ignoring line" << std::endl;
			std::cin.clear();	// clear cin stream
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');	// numbers only
						
		} else if (menuChoice > MENU_CHAINED && menuChoice < MENU_QUADRATIC){
		
			std::cout << std::endl << "Must choose option 1, 2, or 3." << std::endl;
		
		}// end if else if		
	
	}while(menuChoice != MENU_QUADRATIC && menuChoice != MENU_DOUBLE && menuChoice != MENU_CHAINED);
	
	std::cout << std::endl;
	
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
	
		std::cout << "Please enter a hash table size (min val of 6700): ";
	
		std::cin >> userNum;
	
		// if not a number
		if(std::cin.fail()){
			
			std::cout << std::endl << "invalid character -- ignoring line" << std::endl;
			std::cin.clear();	// clear cin stream
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');	// numbers only
						
		} else if (userNum < HASH_TABLE_MINIMUM_SIZE){
		
			std::cout << std::endl << "Table size must be >= 6700." << std::endl;
		
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
	
		std::cout << std::endl << "Do you want to conduct another hashing test?(Y/N): ";
	
		std::cin >> userChar;
		
		userChar = toupper(userChar);
		
		//debug
		std::cout << std::endl << "userChar: " << userChar << std::endl;	
		system("PAUSE");
	
		// if not a number
		if(userChar != EXIT_PROGRAM && userChar != CONT_PROGRAM){
			
			std::cout << std::endl << "invalid character -- ignoring line" << std::endl;
			std::cin.clear();	// clear cin stream
			std::cin.ignore(std::numeric_limits<char>::max(), '\n');	// char only
						
		} // end if
	
	}while(userChar != CONT_PROGRAM && userChar != EXIT_PROGRAM); // end do while
	
	return userChar;
	
}
