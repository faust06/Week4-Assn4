// Header description goes here

//include guards
#ifndef __townsendpeters_prog__HashADT__
#define __townsendpeters_prog__HashADT__

#include "Common.h"

int HashValue(int , int );
double CalculateLoadFactor(int );
void InitializeOpenTbl(int* & ,int* & , int);
void InitializeChnTbl(struct chnArray* , int );
void HashSearching(int, int [], int * , struct chnArray * , int , int *, double & , double & );
int FindOpenValue(int ,int [],int * ,int * , int );
int FindChainValue(int [], struct chnArray *, int );



#endif /* defined(__townsendpeters_prog__HashADT__) */
