#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define S21_OK 0
#define S21_ERROR_MATRIX 1
#define S21_ERROR_CALCULATION 2
#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

//               ---=== common functions ===---
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

//                 ---=== main functions ===---
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

//              ---=== secondary functions ===---
void s21_matrix_without_row_column(matrix_t *A, int size, int column,
                                   matrix_t *minor);
void s21_matrix_minor(matrix_t *A, int row, int column,
                      matrix_t *minor_of_number);
double det(matrix_t *A, int rows);
int s21_check_matrix(matrix_t *A);
void s21_free_matrix(matrix_t *A);
void s21_print_matrix(matrix_t *A);
