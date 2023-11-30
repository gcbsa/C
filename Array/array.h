#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

//Error code definitions
#define SUCCESS 0;
#define FAIL -1;
#define INVALID_POINTER -2;
#define OUT_OF_MEMORY -3;

//Type definition
typedef struct array Array;

//Base operatins
Array * create(int space);
int destroy(Array ** array);
int resize(Array * array, int new_space);

//Handle operations
int assign(Array * array, int index, int value);
int swap(Array * array, int index_a, int index_b);
int fill(Array * array, int max_value);
int shuffle(Array * array);
int reverse(Array * array);

//Fetch operations
int retrieve(Array * array, int index, int * value);
int search(Array * array, int * index, int value);
int len(Array * array);
int min(Array * array, int * value);
int max(Array * array, int * value);

//View operations
int print(Array * array);

#endif
