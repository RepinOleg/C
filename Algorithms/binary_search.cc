#include <iostream>
#include <vector>

/* Функция бинарного поиска, работает с отсортированным массивом */

int binary_search(std::vector<int>& arr, int desired_value) {
  int low_element = 0, high_element = arr.size() - 1;

  while (low_element <= high_element) {
    /* Делим массив пополам*/

    int middle_element = (low_element + high_element) / 2;

    /* Проверяем где находится искомый элемент массива и сужаем границы массива
     */
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
