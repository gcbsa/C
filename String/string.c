#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "string.h"

//Base operations

//Handle operations
void fill(char string[], int size) {
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    
    srand(time(NULL));
    for(int i = 0; i < size - 1; i++)
        string[i] = characters[rand() % 62];
    string[size-1] = '\0';
  
    return;
}

void lower(char string[]){
	for(int i = 0; string[i] != '\0'; i++)
		string[i] = tolower(string[i]);

	return;
}

void upper(char string[]){
	for(int i = 0; string[i] != '\0'; i++)
		string[i] = toupper(string[i]);

	return;
}

//Fetch operations

//View operations
void print(int string[], int size){
	for(int i = 0; i < size - 1; i++)
		printf("%c", string[i]);
	printf("%c\n", string[size-1]);

	return;
}	
