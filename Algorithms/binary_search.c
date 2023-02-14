#include <stdio.h>
int binary_search(int *arr, int desired_value, int len_of_array);
int main(void) {
  int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  int x = binary_search(arr, 15, 15);
  printf("%d\n", x);
  return 0;
}
int binary_search(int arr[], int desired_value, int len_of_array) {
  int low_element = 0;
  int high_element = len_of_array - 1;
  while (low_element <= high_element) {
    int middle_element = (low_element + high_element) / 2;
    if (arr[middle_element] == desired_value) {
      return middle_element;
    } else if (arr[middle_element] > desired_value) {
      high_element = middle_element - 1;
    } else {
      low_element = middle_element + 1;
    }
  }
  return -1;
}