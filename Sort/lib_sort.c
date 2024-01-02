void swap(int array[], int index_a, int index_b){
  int temp = array[index_a];
  array[index_a] = array[index_b];
  array[index_b] = temp;

  return;
}