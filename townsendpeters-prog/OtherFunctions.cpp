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