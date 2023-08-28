#include "s21_grep.h"

int main(int argc, char **argv) {
  int numbers_files = 0;
  flags f = {0};
  if (argc > 2) {
    char find_strings[SIZE_OF_STRING];
    if (parser(argc, argv, &f, find_strings, &numbers_files)) {
      for (int i = numbers_files; i < argc; i++) {
        open_file(i, argc, argv, f, find_strings, numbers_files);
      }
    }
  } else if (argc == 1)
    fprintf(stderr, "Usage: grep [OPTION]... PATTERNS [FILE]...\n");
  return 0;
}

int parser(int c, char **argv, flags *f, char *str, int *n) {
  int opt = 0, error = 1, count_f = 0, count_e = 0;
  while (-1 != (opt = getopt_long(c, argv, "e:ivclnf:ohs?", 0, 0))) {
    if (opt == 'e') {
      f->opt_e = 1;
      if (count_e == 0)
        strcpy(str, optarg);
      else {
        strcat(str, "|");
        strcat(str, optarg);
      }
      count_e += 1;
    } else if (opt == 'i') {
      f->opt_i = 1;
    } else if (opt == 'v') {
      f->opt_v = 1;
    } else if (opt == 'c') {
      f->opt_c = 1;
    } else if (opt == 'l') {
      f->opt_l = 1;
    } else if (opt == 'n') {
      f->opt_n = 1;
    } else if (opt == 'f' && count_f < 1) {
      f->opt_f = 1;
      count_f += 1;
      if (!flag_f(optarg, str, count_e)) {
        fprintf(stderr, "grep: %s: No such file or directory\n", argv[optind]);
        error = 0;
        break;
      }
    } else if (opt == 'o') {
      f->opt_o = 1;
    } else if (opt == 'h') {
      f->opt_h = 1;
    } else if (opt == 's') {
      f->opt_s = 1;
    } else {
      fprintf(stderr, "usage: cat [-eivcln] [file...]\n");
      error = 0;
      break;
    }
  }
  if (f->opt_e == 0 && f->opt_f == 0) {
    strcpy(str, argv[optind]);
    *n = optind + 1;
  } else
    *n = optind;
  return error;
}

int search(char *tmp, flags f, char *str, char *coincidences[]) {
  int count = 0, rt = 0;
  regex_t regex;
  int regflag = 0, ret = 0;
  if (f.opt_i)
    regflag = REG_ICASE;
  else if (f.opt_e || f.opt_f)
    regflag = REG_EXTENDED;
  regcomp(&regex, str, regflag);
  size_t len_coincid = 0, str_len = strlen(tmp);
  regmatch_t coincid;
  while ((ret = regexec(&regex, tmp + len_coincid, 1, &coincid, 0)) == 0) {
    int len = coincid.rm_eo - coincid.rm_so;
    if (f.opt_o && !f.opt_v) {
      coincidences[count] = malloc(len + 1);
      memcpy(coincidences[count], tmp + coincid.rm_so + len_coincid, len);
      coincidences[count][len] = '\0';
      count++;
    }
    rt += 1;
    len_coincid += coincid.rm_eo;
    if (len_coincid >= str_len) break;
  }
  regfree(&regex);
  return f.opt_v ? !rt : rt;
}

int flag_f(char *filename, char *str, int k) {
  int err = 1;
  FILE *file = fopen(filename, "r");
  if (file != NULL) {
    size_t len = 0;
    ssize_t str_len = 0;
    char *pattern = NULL;
    int count = 0;
    while ((str_len = getline(&pattern, &len, file)) != -1) {
      if (strcmp(pattern, "\n") == 0) pattern[0] = '.';
      if (pattern[strlen(pattern) - 1] == '\n')
        pattern[strlen(pattern) - 1] = '\0';
      if (count < 1 && k < 1) {
        strcpy(str, pattern);
        count += 1;
      } else {
        strcat(str, "|");
        strcat(str, pattern);
      }
      str[strcspn(str, "\r\n")] = '\0';
    }
    fclose(file);
    free(pattern);
  } else
    err = 0;
  return err;
}

void open_file(int n, int argc, char **argv, flags f, char *str,
               int index_first_file) {
  FILE *file = fopen(argv[n], "r");
  if (file != NULL) {
    grep(str, f, argv, argc, n, file, index_first_file);
    fclose(file);
  } else if (!f.opt_s && file == NULL)
    fprintf(stderr, "grep: %s: No such file or directory\n", argv[n]);
}

void grep(char *str, flags f, char **argv, int argc, int n, FILE *file,
          int i_f_f) {
  char *tmp = NULL;
  int all_str = 0, find_str = 0;
  size_t len = 0;
  ssize_t tmp_len = 0;
  while ((tmp_len = getline(&tmp, &len, file)) > 0) {
    all_str += 1;
    char *coincidences[SIZE_OF_STRING] = {NULL};
    if (search(tmp, f, str, coincidences)) {
      find_str += 1;
      if (find_str > 0 && f.opt_l) break;
      if (!f.opt_c) {
        if (!f.opt_h) print_file_name(argv, argc, i_f_f, n);
        if (f.opt_n) print_number_of_str(all_str);
        if (f.opt_o && !f.opt_v) {
          for (int i = 0; coincidences[i]; i++) {
            printf("%s\n", coincidences[i]);
          }
        } else
          tmp[(strlen(tmp) - 1)] == '\n' ? printf("%s", tmp)
                                         : printf("%s\n", tmp);
      }
      for (int i = 0; coincidences[i]; i++) free(coincidences[i]);
    }
  }
  if (!f.opt_h && f.opt_l && i_f_f < argc - 1 && f.opt_c)
    print_file_name(argv, argc, i_f_f, n);
  if (f.opt_c && !f.opt_h && i_f_f < argc - 1 && !f.opt_l)
    print_header_with_flag_c(argv, n);
  print_count_found_str(f, find_str);
  print_with_flag_l(f, argv, n, find_str);
  free(tmp);
}

void print_file_name(char **argv, int argc, int index_1_file, int n) {
  if (index_1_file < argc - 1) printf("%s:", argv[n]);
}

void print_number_of_str(int count_of_all_str) {
  printf("%d:", count_of_all_str);
}

void print_header_with_flag_c(char **argv, int n) { printf("%s:", argv[n]); }

void print_count_found_str(flags f, int count) {
  if (f.opt_c) printf("%d\n", count);
}

void print_with_flag_l(flags f, char **argv, int n, int find_str) {
  if (f.opt_l && find_str) printf("%s\n", argv[n]);
}