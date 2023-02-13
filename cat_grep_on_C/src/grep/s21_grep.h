#ifndef S21_GREP_H
#define s21_GREP_H

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _D_GNU_SOURCE
#define SIZE_OF_STRING 8200

typedef struct flags {
  int opt_e, opt_i, opt_v, opt_c, opt_l, opt_n, opt_f, opt_o, opt_h, opt_s;
} flags;

int parser(int c, char **argv, flags *f, char *str, int *n);
void print_with_flag_l(flags f, char **argv, int n, int find_str);
void print_count_found_str(flags f, int count);
void print_header_with_flag_c(char **argv, int n);
void print_number_of_str(int count_of_all_str);
int search(char *tmp, flags f, char *patterns, char *coincidences[]);
void print_file_name(char **argv, int argc, int index_1_file, int n);
void open_file(int n, int argc, char **argv, flags f, char *str,
               int index_first_file);
int flag_f(char *filename, char *str, int k);
void grep(char *str, flags f, char **argv, int argc, int n, FILE *file,
          int i_f_f);

#endif  // S_21_GREP_H