#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = S21_ERROR_MATRIX;
  matrix_t minor_of_number;
  if (A && result && !s21_check_matrix(A)) {
    if ((A->rows == A->columns) && A->rows > 1) {
      s21_create_matrix(A->rows, A->columns, result);
      res = S21_OK;
      s21_create_matrix(A->rows - 1, A->columns - 1, &minor_of_number);
      for (int k = 0; k < A->rows; k++) {
        for (int j = 0; j < A->columns; j++) {
          double minor = 0.0, k_j = k + j;
          s21_matrix_minor(A, k, j, &minor_of_number);
          s21_determinant(&minor_of_number, &minor);
          result->matrix[k][j] = minor * pow(-1.0, k_j);
        }
      }
      s21_remove_matrix(&minor_of_number);
    } else
      res = S21_ERROR_CALCULATION;
  }
  return res;
}

void s21_matrix_minor(matrix_t *A, int row, int column,
                      matrix_t *minor_of_number) {
  int x = 0, y = 0;
  for (int i = 0; i < A->rows; i++) {
    if (row == i) continue;
    for (int j = 0; j < A->rows; j++) {
      if (column == j) continue;
      minor_of_number->matrix[x][y] = A->matrix[i][j];
      y++;
    }
    x++;
    y = 0;
  }
}