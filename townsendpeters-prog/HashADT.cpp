// File description goes here

#include "HashADT.h"


//*********************************************************************
// FUNCTION: 		CalculateLoadFactor()
// DESCRIPTION: 	calculates the load factor for a hash table given the hashtable's size
// INPUT:
// 	Parameters: 	hashTableSize - size of hashtable
// OUTPUT:
// 	Return Val: 	loadFactor - calculated load factor for hashtable
// IMPLEMENTED BY: 	Neil Townsend
//**********************************************************************

double CalculateLoadFactor(int hashTableSize)
{
    double loadFactor;                          //the calculated load factor for the hashtable
    
    //calculates the load factor by dividing the number of values stored in the table by the size of the table
    loadFactor = static_cast<double>(RANDOM_ARRAY_UNIQUE_VALUES) / hashTableSize;
    
    //returns calculated load factor
    return loadFactor;
}
