#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = S21_ERROR_MATRIX;
  if (result && A && B && !s21_check_matrix(A) && !s21_check_matrix(B)) {
    s21_create_matrix(A->rows, B->columns, result);
    if (A->rows == B->columns) {
      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < B->columns; ++j) {
          result->matrix[i][j] = 0;
          for (int k = 0; k < B->rows; ++k) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
      res = S21_OK;
    } else
      res = S21_ERROR_CALCULATION;
  }
  return res;
}