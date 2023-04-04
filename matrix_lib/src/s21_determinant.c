#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res = S21_ERROR_MATRIX;
  if (A && !s21_check_matrix(A)) {
    if (A->rows == A->columns) {
      res = S21_OK;
      *result = det(A, A->rows);
    } else
      res = S21_ERROR_CALCULATION;
  }
  return res;
}

void s21_matrix_without_row_column(matrix_t *A, int size, int column,
                                   matrix_t *minor) {
  for (int i = 0; i < size - 1; i++) {
    int offsetrow = 1, offsetcolumn = 0;
    for (int j = 0; j < size - 1; j++) {
      if (j == column) offsetcolumn = 1;
      minor->matrix[i][j] = A->matrix[i + offsetrow][j + offsetcolumn];
    }
  }
}

double det(matrix_t *A, int rows) {
  double determinant = 0.0;
  int k = 1, l = A->rows - 1;
  if (rows == 2) {
    determinant = (A->matrix[0][0] * A->matrix[1][1]) -
                  (A->matrix[0][1] * A->matrix[1][0]);
  } else if (rows == 1) {
    determinant = A->matrix[0][0];
  } else {
    matrix_t tmp_matrix;
    s21_create_matrix(rows - 1, rows - 1, &tmp_matrix);
    for (int i = 0; i < rows; i++) {
      s21_matrix_without_row_column(A, rows, i, &tmp_matrix);
      determinant += (k * A->matrix[0][i] * det(&tmp_matrix, l));
      k = -k;
    }
    s21_remove_matrix(&tmp_matrix);
  }
  return determinant;
}