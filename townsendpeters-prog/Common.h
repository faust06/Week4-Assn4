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
const int   HASH_TABLE_MINIMUM_SIZE = 6700,                     //smallest hashtable size that can be used
            RANDOM_ARRAY_UNIQUE_VALUES = 5000,                  //number of unique values in array containing random values
            RANDOM_ARRAY_SEARCH_DIVISION = 2,                    //amount of sections that random array will be divided into for searching purposes
            RANDOM_ARRAY_VALUE_MIN = 1,                         //smallest random value that can be placed into array
            RANDOM_ARRAY_VALUE_MAX = 30000;                     //largest random value that can be placed into array

//structs
struct hashNode {
    int value;
    hashNode *next;
};


#endif
