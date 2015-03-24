// Header description goes here

//Include Guards
#ifndef townsendpeters_prog_Common_h
#define townsendpeters_prog_Common_h

//includes for program
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include "HashADT.h"
#include "OtherFunctions.h"

//constants
const int   HASH_TABLE_MINIMUM_SIZE = 6700,                     //smallest hashtable size that can be used
            RANDOM_ARRAY_UNIQUE_VALUES = 250,                  //number of unique values in array containing random values
            RANDOM_ARRAY_SEARCH_DIVISION = 2,                   //amount of sections that random array will be divided into for searching purposes
            RANDOM_ARRAY_VALUE_MIN = 1,                         //smallest random value that can be placed into array
            RANDOM_ARRAY_VALUE_MAX = 30000,                     //largest random value that can be placed into array
            TEST_QUADRATIC_PROBING = 1,                         //test number for quadratic probing collision resolution
            TEST_DOUBLE_HASHING = 2,                            //test number for double hasing collision resolution
            TEST_SEPARATE_CHAINING = 3;                         //test number for separate chaining hashtable

//structs
struct hashNode {
    int value;
    hashNode *next;
};


#endif
