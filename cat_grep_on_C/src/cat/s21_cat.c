#include "s21_cat.h"

int main(int argc, char **argv) {
  flags f = {0};
  if (parser(argc, argv, &f)) open_file(argc, argv, f);
  return 0;
}

int parser(int argc, char **argv, flags *f) {
  int ret = 1;
  if (argc > 1) {
    int count = 1;
    while (count < argc) {
      if ((argv[count][0]) == '-') {
        if (argv[count][1] == '-') {
          if (!long_flags(f, argv, count)) {
            ret = 0;
            break;
          }
        } else {
          if (!short_flags(argv, count, f)) {
            ret = 0;
            break;
          }
        }
      }
      count++;
    }
  }
  return ret;
}

int long_flags(flags *f, char **argv, int count) {
  int ret = 1;
  if (strcmp("--number-nonblank", argv[count]) == 0) {
    f->opt_b = 1;
  } else if (strcmp("--number", argv[count]) == 0) {
    f->opt_n = 1;
  } else if (strcmp("--squeeze-blank", argv[count]) == 0) {
    f->opt_s = 1;
  } else {
    fprintf(stderr, "cat: unrecognized option '%s'\n", argv[count]);
    ret = 0;
  }
  memset(argv[count], '\0', strlen(argv[count]));
  return ret;
}

int short_flags(char **argv, int count, flags *f) {
  int ret = 1;
  for (size_t i = 1; i < strlen(argv[count]); i++) {
    if (argv[count][i] == 's') {
      f->opt_s = 1;
    } else if (argv[count][i] == 'e') {
      f->opt_e = 1, f->opt_v = 1;
    } else if (argv[count][i] == 'b') {
      f->opt_b = 1;
    } else if (argv[count][i] == 'n') {
      f->opt_n = 1;
    } else if (argv[count][i] == 't') {
      f->opt_t = 1, f->opt_v = 1;
    } else if (argv[count][i] == 'v') {
      f->opt_v = 1;
    } else if (argv[count][i] == 'E') {
      f->opt_e = 1;
    } else if (argv[count][i] == 'T') {
      f->opt_t = 1;
    } else {
      fprintf(stderr,
              "cat: illegal option -- '%c'\nusage: cat [-benstuv] [file "
              "...]\n",
              argv[count][i]);
      ret = 0;
      break;
    }
    memset(argv[count], '\0', strlen(argv[count]));
  }
  return ret;
}

void open_file(int argc, char **argv, flags f) {
  int count = 1, count_lines = 0;
  int sec_count = 1;
  while (count < argc) {
    if (*argv[count] != '\0') {
      FILE *file = fopen(argv[count], "r");
      if (file != NULL) {
        char next_char = '\0';
        char first_ch;
        if ((first_ch = getc(file)) != EOF) {
          if ((f.opt_n && !f.opt_b) || (f.opt_b && first_ch != '\n')) {
            printf("%6d\t", sec_count);
            sec_count++;
          }
          while ((next_char = getc(file)) != EOF) {
            if (f.opt_s) {
              flag_s(first_ch, &next_char, file, f, &sec_count, &count_lines);
            } else if (f.opt_e)
              if (first_ch == '\n') printf("$");
            print(first_ch, f);
            if (f.opt_n || f.opt_b)
              flag_b_n(first_ch, next_char, &sec_count, f);
            first_ch = next_char;
          }
          if (first_ch != -1) print(first_ch, f);
        }
        fclose(file);
      } else
        fprintf(stderr, "cat: %s: No such file or directory\n", argv[count]);
    }
    count++;
  }
}

void print(char ch, flags f) {
  flag_v(ch, f);
  if (!f.opt_e && !f.opt_t && !f.opt_v) printf("%c", ch);
}

void flag_s(char first_char, char *next_char, FILE *file, flags f,
            int *sec_count, int *count_lines) {
  *count_lines += 1;
  if (first_char == '\n' && *next_char == '\n') {
    if (f.opt_e == 1) printf("$");
    if (*count_lines > 1) printf("\n");
    if (f.opt_n && !f.opt_b) {
      printf("%6d\t", *sec_count);
      *sec_count += 1;
    }
    if (f.opt_e) printf("$");
    while (*next_char == '\n') *next_char = getc(file);
  } else if (first_char == '\n')
    if (f.opt_e) printf("$");
}

void flag_b_n(char ch, char ch_2, int *sec_count, flags f) {
  if (f.opt_n && f.opt_b == 0) {
    if (ch == '\n' && ch_2 != EOF) {
      printf("%6d\t", *sec_count);
      *sec_count += 1;
    }
  } else if (f.opt_b == 1 && ch_2 != EOF) {
    if (ch == '\n' && ch_2 != '\n') {
      printf("%6d\t", *sec_count);
      *sec_count += 1;
    }
  }
}

void flag_v(char ch, flags f) {
  if ((f.opt_e && f.opt_v && !f.opt_t) || (f.opt_v && !f.opt_e && !f.opt_t)) {
    if ((ch >= 0 && ch < 32) && (ch != 10 && ch != 9)) {
      printf("^%c", ch + 64);
    } else if (ch == 127) {
      printf("^%c", ch - 64);
    } else
      printf("%c", ch);
  } else if (f.opt_e && !f.opt_v)
    printf("%c", ch);
  if (f.opt_t && f.opt_v) {
    if ((ch >= 0 && ch < 32) && ch != 10) {
      printf("^%c", ch + 64);
    } else if (ch == 127) {
      printf("^%c", ch - 64);
    } else
      printf("%c", ch);
  } else if (f.opt_t == 1 && f.opt_v == 0) {
    if (ch == 9)
      printf("^%c", ch + 64);
    else
      printf("%c", ch);
  }
}
