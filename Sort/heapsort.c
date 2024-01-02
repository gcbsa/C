#include <stdio.h>
#include "lib_sort.h"

void heap(int array[], int index_node, int size){
  int index_max_child = 2*index_node+1;

  if(index_max_child < size){
    if(index_max_child+1 < size && array[index_max_child] < array[index_max_child+1])
      index_max_child++;

    if(array[index_max_child] > array[index_node]){
      swap(array, index_node, index_max_child);
      heap(array, index_max_child, size);
    }
  }

  return;
}

void heapsort(int array[], int size){
  for(int i = size/2; i > 0; i--)
    heap(array, i-1, size);

  for(int i = size-1; i > 0; i--){
    swap(array, 0, i);
    heap(array, 0, --size);
  }
  
  return;
}