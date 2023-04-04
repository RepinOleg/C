#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = S21_ERROR_MATRIX;
  if (A && result && !s21_check_matrix(A)) {
    if ((A->rows == A->columns) && A->rows > 1) {
      res = S21_OK;
      double determinant = 0.0;
      s21_determinant(A, &determinant);
      if (determinant != 0.0) {
        s21_create_matrix(A->rows, A->columns, result);
        matrix_t minor_matrix, transpose_matrix;
        s21_calc_complements(A, &minor_matrix);
        s21_transpose(&minor_matrix, &transpose_matrix);
        for (int i = 0; i < A->rows; ++i) {
          for (int j = 0; j < A->columns; ++j) {
            result->matrix[i][j] = transpose_matrix.matrix[i][j] / determinant;
          }
        }
        s21_remove_matrix(&minor_matrix);
        s21_remove_matrix(&transpose_matrix);
      } else
        res = S21_ERROR_CALCULATION;
    } else
      res = S21_ERROR_CALCULATION;
  }
  return res;
}