#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"


//Structure definition
struct array{
	int size;
	int * data;
};

//Base operations
Array * create(int space){
	Array * new_array = (Array *)malloc(sizeof(Array));

	if(new_array != NULL){
		new_array->data = (int *)malloc(space*sizeof(int));
        new_array->size = space;
	}

	return new_array;
}

Array * clone(Array * original){
    Array * clone = NULL;
    if(original != NULL)
        if((clone = create(original->size)) != NULL)
            for(int i = 0; i < clone->size; i++)
                assign(clone, i, original->data[i]);

    return clone;
}

int destroy(Array ** array){
	if(*array == NULL) return INVALID_POINTER;

	free((*array)->data);
	free(*array);
	*array = NULL;
	
	return SUCCESS;
}

int resize(Array * array, int new_space){
    if(array == NULL) return INVALID_POINTER;

    int * temp = (int *)realloc(array->data, new_space * sizeof(int));
    if (temp != NULL)
        array->data = temp;
    else return OUT_OF_MEMORY;

    array->size = new_space;

    return SUCCESS;
}

//Handle operations)
int assign(Array * array, int index, int value){
    if(array == NULL || array->data == NULL) return INVALID_POINTER;
    
    if(index < 0 || index >= array->size) return FAIL;

    array->data[index] = value;

    return SUCCESS;
}

int swap(Array * array, int index_a, int index_b){
    if(array == NULL || array->data == NULL) return INVALID_POINTER;

    if(index_a < 0 || index_a >= array->size || index_b < 0 || index_b >= array->size || index_a == index_b) return FAIL;

    int temp = array->data[index_a];
    array->data[index_a] = array->data[index_b];
    array->data[index_b] = temp;

    return SUCCESS;
}

int fill(Array * array, int max_value) {
    if(array == NULL || array->data == NULL) return INVALID_POINTER;

    srand(time(NULL));
    for (int i = 0; i < array->size; i++)
        array->data[i] = rand() % max_value;
  
    return SUCCESS;
}

int shuffle(Array * array){
    if(array == NULL || array->data == NULL) return INVALID_POINTER;

    srand(time(NULL));
    for(int i = 0; i < array->size; i++)
        swap(array, i, rand() % array->size);
  
    return SUCCESS;
}

int reverse(Array * array){
	if(array == NULL || array->data == NULL) return INVALID_POINTER;

	if(array->size < 2) return FAIL;

	for(int i = 0; (array->size/2)-i; i++)
		swap(array, i, array->size-1-i);
	
	return SUCCESS;
}

//Fetch operations
int retrieve(Array * array, int index, int * value){
    if(array == NULL || array->data == NULL) return INVALID_POINTER;

    if(index < 0 || index >= array->size) return FAIL;

    *value = array->data[index];

    return SUCCESS;
}

int search(Array * array, int * index, int value){
    if(array == NULL || array->data == NULL) return INVALID_POINTER;

    for(*index = 0; *index < array->size; (*index)++)
        if(array->data[*index] == value)
            return SUCCESS;
    
    *index = -1;
    return FAIL;
}

int len(Array * array){
    if(array == NULL || array->data == NULL) return INVALID_POINTER;

    return array->size;
}

int min(Array * array, int * value){
    if(array == NULL || array->data == NULL) return INVALID_POINTER;

    *value = array->data[0];
    for(int i = 1; i < array->size; i++)
        if(array->data[i] < *value)
            *value = array->data[i];

    return SUCCESS;
}

int max(Array * array, int * value){
    if(array == NULL || array->data == NULL) return INVALID_POINTER;

    *value = array->data[0];
    for(int i = 1; i < array->size; i++)
        if(array->data[i] > *value)
            *value = array->data[i];

    return SUCCESS;
}

//View operations
int print(Array * array){
    if(array == NULL || array->data == NULL) return INVALID_POINTER;

    for(int i = 0; i < array->size - 1; i++)
        printf("[%d] ", array->data[i]);
    printf("[%d]\n", array->data[array->size-1]);

    return SUCCESS;
}
