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
