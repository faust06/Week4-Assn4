// Header description goes here

//Include Guards
#ifndef townsendpeters_prog_Common_h
#define townsendpeters_prog_Common_h

//includes for program
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "HashADT.h"
#include "OtherFunctions.h"

//constants
const int   MINIMUM_HASH_TABLE_SIZE = 6700,                     //smallest hashtable size that can be used
            UNIQUE_VALUES = 5000,                               //number of unique values in array containing random values
            RANDOM_ARRAY_SEARCH_DIVISON = 2,                    //amount of sections that random array will be divided into for searching purposes
            MIN_RANDOM_VALUE = 1,                               //smallest random value that can be placed into array
            MAX_RANDOM_VALUE = 30000;                           //largest random value that can be placed into array

//structs
struct hashNode {
    int value;
    hashNode *next;
};


#endif
