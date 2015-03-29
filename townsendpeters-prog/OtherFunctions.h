//*********************************************************************
// CODE FILENAME:   OtherFunctions.h
// DESCRIPTION:     Header file containing the definitions for other functions needed for use
//                  in townsendpeters-assn3-prog.cpp. These functions aid in the calculation of
//                  efficacy for different collision resolution methods used with hashtables
// CLASS/TERM:      2015 Spring 8 week Section 2
// DESIGNER:        Neil Townsend and Chad Peters
// FUNCTIONS        CalculateAverage()          calculates the average number of searches per item in a hashtable
//                  CalculateKnuthAverage()     calculates the predicted average number of searches per item in a hashtable
//                  GetMenuChoice()             asks the user which collision resolution method they would like to test
//                  GetTableSize()              asks the user how large of a hashtable they would like to use for testing
//                  KeepTesting()               asks the user if they would like to run another collision resolution test
//                  RandomNum()                 generates a random number within a range of acceptable values
//                  DuplicateValue()            checks to see if the randomly generated number is unique
//                  InitializeRandomArray()     fills an array with unique random values
//                  DisplayResults()            displays results of collision resolution method to user
//                  InitializeTable()           handles allocation and initialization of hashtable to match user's choice
//                  DestroyTables()             frees up memory that was dynamically allocated for each test
//**********************************************************************

//include guards
#ifndef __townsendpeters_prog__OtherFunctions__
#define __townsendpeters_prog__OtherFunctions__

#include "Common.h"

double CalculateAverage(int );
double CalculateKnuthAverage(int , int , double );
int GetMenuChoice();
int GetTableSize();
char KeepTesting();
int RandomNum();
bool DuplicateValue(int [], int , int );
void InitializeRandomArray(int []);
void DisplayResults(int , int , int , double , double );
bool InitializeTable(int , int* & , struct chnArray* & , int [], int* & , int );
void DestroyTables(int, int* &, struct chnArray* , int* &);



#endif /* defined(__townsendpeters_prog__OtherFunctions__) */
