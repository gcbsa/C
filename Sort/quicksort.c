#include <stdio.h>
#include "lib_sort.h"

void quicksort(int array[], int low, int high){
	if(high - low < 1) return;

	int pivot = (array[low] < array[high] ? array[low] : array[high]);
	if(high - low > 1)
		pivot = (array[high/2] > pivot ? array[high/2] : pivot);

	int low_it = low, high_it = high;
	for(int cur_it = low_it; cur_it <= high_it; cur_it++){
		if(array[cur_it] < pivot)
			swap(array, cur_it, low_it++);
		else if(array[cur_it] > pivot)
			swap(array, cur_it--, high_it--);
	}

	quicksort(array, low, low_it-1);
	quicksort(array, high_it+1, high);

	return;
}
