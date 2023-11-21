#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

//Error code definitions
#define SUCCESS 0;
#define FAIL -1;

//Base operatins

//Handle operations
void swap(int array[], int index_a, int index_b);
void fill(int array[], int size);
void shuffle(int array[], int size);

//Fetch operations
int binary_search(int array[], int high, int key);
int recursive_binary_search(int array[], int low, int high, int key);

//View operations
void print(int array[], int size);

#endif
