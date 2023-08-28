#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = S21_ERROR_MATRIX;
  if (result && A && B && !s21_check_matrix(A) && !s21_check_matrix(B)) {
    s21_create_matrix(A->rows, A->columns, result);
    if (A->columns == B->columns && A->rows == B->rows) {
      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
      res = S21_OK;
    } else
      res = S21_ERROR_CALCULATION;
  }
  return res;
}