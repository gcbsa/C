#ifndef BINARY_SEARCH_H_INCLUDED
#define BINARY_SEARCH_H_INCLUDED

//Error code definitions
#define SUCCESS 0;
#define FAIL -1;

//Iteractive implementation
int binary_search_it(int array[], int high, int key);

//Recursive implementation
int binary_search_rc(int array[], int low, int high, int key);

#endif