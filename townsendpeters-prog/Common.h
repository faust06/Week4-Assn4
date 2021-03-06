//*********************************************************************
// CODE FILENAME:   common.h
// DESCRIPTION:     header file containing constants and data structure definitions to be used in
//                  townsendpeters-assn3-prog.cpp
// CLASS/TERM:      2015 Spring 8 week Section 2
// DESIGNER:        Neil Townsend and Chad Peters
//**********************************************************************

//Include Guards
#ifndef townsendpeters_prog_Common_h
#define townsendpeters_prog_Common_h

//includes for program
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <limits>
#include "HashADT.h"
#include "OtherFunctions.h"

//constants
const int   HASH_TABLE_MINIMUM_SIZE = 6700,                     //smallest hashtable size that can be used
            RANDOM_ARRAY_UNIQUE_VALUES = 5000,                  //number of unique values in array containing random values
            RANDOM_ARRAY_SEARCH_DIVISION = 2,                   //amount of sections that random array will be divided into for searching purposes
            RANDOM_ARRAY_VALUE_MIN = 1,                         //smallest random value that can be placed into array
            RANDOM_ARRAY_VALUE_MAX = 30000,                     //largest random value that can be placed into array
            TEST_QUADRATIC_PROBING = 1,                         //test number for quadratic probing collision resolution
            TEST_DOUBLE_HASHING = 2,                            //test number for double hasing collision resolution
            TEST_SEPARATE_CHAINING = 3,                         //test number for separate chaining hashtable
            MENU_QUADRATIC = 1,                                 //menu option for quadratic hashing
            MENU_DOUBLE = 2,                                    //menu option for double hashing
            MENU_CHAINED = 3,                                   //menu option for chained hashing
            PROBE_NUM_START = 1,                                //used for collision checking; starts probe number at 1
            SECONDARY_HASH_SUB_VAL = 2,                         //used in secondary hash formula to subtract with
            SECONDARY_HASH_ADD_VAL = 1,                         //used in secondary hash formula to add with
            DATA_IN_CELL = 1,                                   //used for open addressing hash table index list
            OUTPUT_SIG_DIGS = 3,                                //number of significant digits when displaying results
            OUTPUT_TOTAL_SEARCH_FIELD = 12;                     //output field for displaying total searches

const char 	EXIT_PROGRAM = 'N',                                 //user can enter N to exit program after each test
            CONT_PROGRAM = 'Y';                                 //user can enter Y to continue program after each test

//structs
struct hashNode {
    int value;
    hashNode *next;
};

struct chnArray {
    hashNode *link;
};


#endif
