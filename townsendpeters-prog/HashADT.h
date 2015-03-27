// Header description goes here

//include guards
#ifndef __townsendpeters_prog__HashADT__
#define __townsendpeters_prog__HashADT__

#include "Common.h"

double CalculateLoadFactor(int );
void InitializeOpenTbl(int* & ,int* & , int);
void InitializeChnTbl(struct chnArray* , int );
void HashSearching(int, int [], int * , struct chnArray * , int , int *, double & , double & );


#endif /* defined(__townsendpeters_prog__HashADT__) */
