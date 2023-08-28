#ifndef CAT_H
#define CAT_H

#include <stdio.h>
#include <string.h>

typedef struct {
  int opt_s, opt_e, opt_b, opt_n, opt_t, opt_v;
} flags;

int parser(int argc, char **argv, flags *f);
int long_flags(flags *f, char **argv, int count);
int short_flags(char **argv, int count, flags *f);
void open_file(int argc, char **argv, flags f);
void flag_s(char first_char, char *next_char, FILE *file, flags f,
            int *sec_count, int *count_lines);
void flag_b_n(char ch, char ch_2, int *sec_count, flags f);
void flag_v(char ch, flags f);
void print(char ch, flags f);

#endif  // CAT_H