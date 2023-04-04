#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = S21_OK;
  if (!result) {
    res = S21_ERROR_MATRIX;
  } else {
    result->columns = columns;
    result->rows = rows;
    result->matrix = calloc(rows, sizeof(double *));
    if (!s21_check_matrix(result)) {
      for (int i = 0; i < rows; ++i) {
        result->matrix[i] = calloc(columns, sizeof(double));
      }
      res = S21_OK;
    } else {
      s21_free_matrix(result);
      res = S21_ERROR_MATRIX;
    }
  }
  return res;
}

int s21_check_matrix(matrix_t *A) {
  int res = S21_OK;
  if (A) {
    if (A->rows < 1 || A->columns < 1 || !A->matrix) res = S21_ERROR_MATRIX;
  } else
    res = S21_ERROR_MATRIX;
  return res;
}

void s21_free_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; ++i) {
    free(A->matrix[i]);
  }
  free(A->matrix);
  A->matrix = NULL;
}