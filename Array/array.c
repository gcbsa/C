#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

//Base operations

//Handle operations
void swap(int array[], int index_a, int index_b){
    int temp = array[index_a];
    array[index_a] = array[index_b];
    array[index_b] = temp;

    return;
}

void fill(int array[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        array[i] = rand() % 1000;
  
    return;
}

void shuffle(int array[], int size){
    srand(time(NULL));
    for(int i = 0; i < size; i++)
        swap(array, i, rand() % size);
  
    return;
}

//Fetch operations
int binary_search(int array[], int high, int key){
    int low = 0; 
    
    do{
        int mid = (high+low)/2;
        
        if(key < array[mid])
            high = mid-1;
        else if (key > array[mid])
            low = mid+1;
        else
            return mid;
        
    }while(low <= high);

    return FAIL;
}

int recursive_binary_search(int array[], int low, int high, int key){
    if(low > high)
        return FAIL;

    int mid = (high+low)/2;
    if(key < array[mid])
        return recursive_binary_search(array, low, mid-1, key);
    else if(key > array[mid])
        return recursive_binary_search(array, mid+1, high, key);
    else
        return mid;
}

//View operations
void print(int array[], int size){
    for(int i = 0; i < size - 1; i++)
        printf("[%d] ", array[i]);
    printf("[%d]\n", array[size-1]);

    return;
}


