#ifndef S21_SMART_CALC_H
#define S21_SMART_CALC_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_ARRAY 300
#define ERROR 1
#define OK 0

typedef enum {
  type_number = 0,
  type_x = 1,
  type_plus = 2,
  type_minus = 3,
  type_mult = 4,
  type_div = 5,
  type_exponent = 6,
  type_mod = 7,
  type_cos = 8,
  type_sin = 9,
  type_tan = 10,
  type_acos = 11,
  type_asin = 12,
  type_atan = 13,
  type_sqrt = 14,
  type_ln = 15,
  type_log = 16,
  type_openbracket = 20,
  type_closebracket = 21
} lexem_type;

typedef struct Node Node;

struct Node {
  double value;
  int priority;
  lexem_type type;
  Node *next;
};

void s21_Push(Node **p_list, double value, int priority, lexem_type type);
double s21_Pop(Node **p_list);
int s21_smart_calc(char *str, double *answer, double x);
void s21_tokenization(char *str, Node **p_list, double x);
void s21_reversePolishNotation(Node *list, Node **polish_not);
void s21_resultCalculation(Node *polish_notation, double *answer);
// void s21_print_list(Node *list);
int s21_check_expression(char *str);
void s21_Reverse(Node **p_list);
void s21_clean(Node **p_list);

#endif  // S21_SMART_CALC_H
