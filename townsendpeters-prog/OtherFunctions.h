// Header description goes here

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
int RandomNum();
void DisplayResults(int , int , int , double , double );
bool InitializeTable(int , int* & , struct chnArray* & , int [], int* & , int );
void DestroyTables(int, int* &, struct chnArray* , int* &);



#endif /* defined(__townsendpeters_prog__OtherFunctions__) */
