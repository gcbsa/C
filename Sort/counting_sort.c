#include <stdio.h>

void counting_sort(int array[], int size){
  int max_number = array[size-1];
  for(int i = 0; i < size-1; i++)
    if(array[i] > max_number)
      max_number = array[i];

  int counting_array[max_number+1];
  for(int i = 0; i < max_number; i++)
    counting_array[i] = 0;

  for(int i = 0; i < size; i++)
    counting_array[array[i]]++;
  
  int index_original_array = 0;
  for(int i = 0; i < max_number; i++){
    for(int j = 0; j < counting_array[i]; j++)
      array[j+index_original_array] = i;

    index_original_array+=counting_array[i];
  }

  return;
}
