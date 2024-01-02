#include "binary_search.h"

//Iteractive implementation
int binary_search_it(int array[], int high, int key){
    int low = 0;

    do{
        int mid = (high+low)/2;
        if(key < array[mid])
            high = mid-1;
        else if (key > array[mid])
            low = mid+1;
        else
            return SUCCESS;
    }while(low <= high);

    return FAIL;
}

//Recursive implementation
int binary_search_rc(int array[], int low, int high, int key){
    if(low > high)
        return FAIL;

    int mid = (high+low)/2;
    if(key < array[mid])
        return binary_search_rc(array, low, mid-1, key);
    else if(key > array[mid])
        return binary_search_rc(array, mid+1, high, key);
    else
        return SUCCESS;
}