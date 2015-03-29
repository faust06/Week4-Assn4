//*********************************************************************
// CODE FILENAME:   HashADT.h
// DESCRIPTION:     header file containing function definitions to be used in
//                  townsendpeters-assn3-prog.cpp
//                  Functions defined in this header file are all used in the creation and
//                  use a hashtable data type.
//                  or exit the program.
// CLASS/TERM:      2015 Spring 8 week Section 2
// DESIGNER:        Neil Townsend and Chad Peters
// FUNCTIONS        HashValue()                 Calculates hash value of a number using modulo division
//                  CalculateLoadFactor()       Calculates the load factor of a hashtable
//                  InitializeOpenTbl()         allocates and initializes a hashtable to use for open addressing
//                  InitializeChnTbl()          allocates and initializes a hashtable to use for chained hashing
//                  HashSearching()             searches through a selected hashtable and calculates average and predicted average searches
//                  FindOpenValue()             finds values in an open addressing hashtable
//                  SearchQuadValue()           searches for a given value in a hashtable using quadratic probing collision resolution
//                  SearchDoubleHashValue()     searches for a given value in a hashtable using double hashing collision resolution
//                  FindChainValue()            finds values in a chain hashing hashtable
//                  QuadraticProbe()            resolves collision when placing values into a hashtable using quadratic probing
//                  DoubleHashValue()           resolves collision when placing values into a hashtable using double hashing
//                  OpenHTInsertValues()        inserts values into an open addressing hashtable
//                  ChainProbe()                resolves collision when placing values into a hashtable using chained hashing
//                  ChainHTInsertValues()       inserts values into a chained hashing hashtable
//**********************************************************************

//include guards
#ifndef __townsendpeters_prog__HashADT__
#define __townsendpeters_prog__HashADT__

#include "Common.h"

int HashValue(int , int );
double CalculateLoadFactor(int );
void InitializeOpenTbl(int* & ,int* & , int);
void InitializeChnTbl(struct chnArray* & , int );
int HashSearching(int, int [], int * , struct chnArray * , int , int *, double & , double & );
int FindOpenValue(int ,int [],int * ,int * , int );
int SearchQuadValue(int *, int , int );
int SearchDoubleHashValue(int *, int , int );
int FindChainValue(int [], struct chnArray *, int );
int QuadraticProbe(int [] , int, int );
int DoubleHashValue(int [], int, int , int );
void OpenHTInsertValues(int , int* & , int [] , int* &, int );
void ChainProbe(struct chnArray *, int , int );
void ChainHTInsertValues(struct chnArray *, int [], int );


#endif /* defined(__townsendpeters_prog__HashADT__) */
