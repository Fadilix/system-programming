#include <stdio.h>

void insert_into_array(int array[], int n_of_values, int v_to_insert) {
  int j;
  for (j = n_of_values; (j > 0) && (array[j - 1] > n_of_values); j--) {
    array[j] = array[j - 1];
  }
  array[j] = v_to_insert;
}

int main() {
  int array[100] = {2, 5, 8, 17, 19, 23};
  int to_insert = 13;
  int current_size_of_array = 6;

  insert_into_array(array, current_size_of_array, to_insert);
  ++current_size_of_array;

  for (int i = 0; i < current_size_of_array; i++) {
    printf("%d\n", array[i]);
  }

  return 0;
}
