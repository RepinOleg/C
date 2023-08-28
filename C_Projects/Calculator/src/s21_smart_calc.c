#include "s21_smart_calc.h"

int s21_smart_calc(char *str, double *answer, double x) {
  int error = OK;
  Node *list = NULL, *polish_notation = NULL;
  if (!s21_check_expression(str)) {
    s21_tokenization(str, &list, x);
    s21_reversePolishNotation(list, &polish_notation);
    s21_resultCalculation(polish_notation, answer);
    s21_clean(&polish_notation);
    s21_clean(&list);
  } else
    error = ERROR;
  return error;
}

void s21_tokenization(char *str, Node **p_list, double x) {
  Node *list = *p_list;
  for (int i = 0; str[i] != '\0'; ++i) {
    // число
    if (isdigit(str[i])) {
      char *buff = calloc(SIZE_OF_ARRAY, sizeof(char));
      int count_digit = 0;
      // копируем в строку все числа пока число не кончится
      for (; isdigit(str[i]) || str[i] == '.'; ++i, ++count_digit) {
        buff[count_digit] = str[i];
      }
      i--;
      // переводим число из строки в double и отправляем в список
      s21_Push(&list, atof(buff), 0, type_number);
      free(buff);
    } else if (strchr("+-/*^()", str[i])) {
      switch (str[i]) {
        case '+':
          if (i > 0 && ((isdigit(str[i - 1]) || (str[i - 1] == 'x')) ||
                        str[i - 1] == ')')) {
            s21_Push(&list, 0, 1, type_plus);
          }
          break;
        case '-':
          // бинарный минус
          if (i > 0 && ((isdigit(str[i - 1]) || (str[i - 1] == 'x')) ||
                        str[i - 1] == ')')) {
            s21_Push(&list, 0, 1, type_minus);
          } else {
            // унарный минус
            s21_Push(&list, 0, 0, type_number);
            s21_Push(&list, 0, 1, type_minus);
          }
          break;
        case '/':
          s21_Push(&list, 0, 2, type_div);
          break;
        case '*':
          s21_Push(&list, 0, 2, type_mult);
          break;
        case '^':
          s21_Push(&list, 0, 3, type_exponent);
          break;
        case '(':
          s21_Push(&list, 0, -1, type_openbracket);
          break;
        case ')':
          s21_Push(&list, 0, -1, type_closebracket);
          break;
      }
    } else if (strchr("cstalm", str[i])) {
      char buff[SIZE_OF_ARRAY];
      int count_buff = 0;

      while (str[i] != '\0' && strchr("cosintaqrlgmd", str[i])) {
        buff[count_buff++] = str[i++];
      }
      buff[count_buff] = '\0';
      i--;
      char all_functions[SIZE_OF_ARRAY][SIZE_OF_ARRAY] = {
          "mod",  "cos",  "sin",  "tan", "acos",
          "asin", "atan", "sqrt", "ln",  "log"};
      char *second_str = buff;
      for (int j = 0; j < 10; j++) {
        char *first_str = all_functions[j];
        if (strstr(first_str, second_str)) {
          if (j == 0)
            s21_Push(&list, 0, 2, type_mod);
          else
            s21_Push(&list, 0, 4, j + 7);
          break;
        }
      }
    } else if (str[i] == 'x') {
      s21_Push(&list, x, 0, type_number);
    }
  }
  s21_Reverse(&list);
  *p_list = list;
}

void s21_reversePolishNotation(Node *list, Node **polish_not) {
  Node *tmp_list = list, *polish_notation = *polish_not, *helpfull_stack = NULL;
  while (tmp_list != NULL) {
    // если это число, кладем в стэк
    if (!tmp_list->priority) {
      s21_Push(&polish_notation, tmp_list->value, 0, type_number);

    } else if (tmp_list->priority > 0 && tmp_list->priority < 5) {
      // если это операция, и ее приоритет выше чем у предыдущей операции то
      // кладем ее в стэк, иначе забираем из стэка предыдущую
      while (helpfull_stack != NULL &&
             (tmp_list->priority <= helpfull_stack->priority)) {
        s21_Push(&polish_notation, 0, helpfull_stack->priority,
                 helpfull_stack->type);
        s21_Pop(&helpfull_stack);
      }
      s21_Push(&helpfull_stack, 0, tmp_list->priority, tmp_list->type);

    } else if (tmp_list->type == type_openbracket) {
      // если открывающаяся скобка, то просто кладем в стэк операций
      s21_Push(&helpfull_stack, 0, tmp_list->priority, tmp_list->type);

    } else if (tmp_list->type == type_closebracket) {
      // если закрывающаяся то достаем все из стэка с операциями и кладем в
      // основной стэк пока не встретим открывающуюся скобку
      while (helpfull_stack->type != type_openbracket &&
             helpfull_stack != NULL) {
        s21_Push(&polish_notation, 0, helpfull_stack->priority,
                 helpfull_stack->type);
        s21_Pop(&helpfull_stack);
      }
      s21_Pop(&helpfull_stack);
      // если после открывающейся скобки идет функция, также перекладываем ее в
      // основной стэк
      if (helpfull_stack != NULL) {
        if (helpfull_stack->priority == 4) {
          s21_Push(&polish_notation, 0, helpfull_stack->priority,
                   helpfull_stack->type);
          s21_Pop(&helpfull_stack);
        }
      }
    }
    // двигаемся по первоначальному списку
    tmp_list = tmp_list->next;
  }

  // если что-то осталось в стэке с операциями, кладем в основной стэк
  while (helpfull_stack != NULL) {
    s21_Push(&polish_notation, 0, helpfull_stack->priority,
             helpfull_stack->type);
    s21_Pop(&helpfull_stack);
  }
  // разворачиваем список для дальнейшей работы
  s21_Reverse(&polish_notation);
  *polish_not = polish_notation;
}

void s21_resultCalculation(Node *polish_notation, double *answer) {
  Node *maths_stack = NULL, *tmp_polish = polish_notation;
  while (tmp_polish != NULL) {
    if (!tmp_polish->priority) {
      s21_Push(&maths_stack, tmp_polish->value, tmp_polish->priority,
               tmp_polish->type);
    } else if (tmp_polish->priority >= 1 && tmp_polish->priority < 4) {
      double a = s21_Pop(&maths_stack);
      double b = s21_Pop(&maths_stack);
      switch (tmp_polish->type) {
        case type_plus:
          s21_Push(&maths_stack, a + b, 0, type_number);
          break;
        case type_minus:
          s21_Push(&maths_stack, b - a, 0, type_number);
          break;
        case type_mult:
          s21_Push(&maths_stack, a * b, 0, type_number);
          break;
        case type_div:
          s21_Push(&maths_stack, b / a, 0, type_number);
          break;
        case type_exponent:
          s21_Push(&maths_stack, pow(b, a), 0, type_number);
          break;
        case type_mod:
          s21_Push(&maths_stack, fmod(b, a), 0, type_number);
          break;
        default:
          break;
      }
    } else if (tmp_polish->priority == 4) {
      double number = s21_Pop(&maths_stack);
      switch (tmp_polish->type) {
        case type_cos:
          s21_Push(&maths_stack, cos(number), 0, type_number);
          break;
        case type_sin:
          s21_Push(&maths_stack, sin(number), 0, type_number);
          break;
        case type_tan:
          s21_Push(&maths_stack, tan(number), 0, type_number);
          break;
        case type_acos:
          s21_Push(&maths_stack, acos(number), 0, type_number);
          break;
        case type_asin:
          s21_Push(&maths_stack, asin(number), 0, type_number);
          break;
        case type_atan:
          s21_Push(&maths_stack, atan(number), 0, type_number);
          break;
        case type_sqrt:
          s21_Push(&maths_stack, sqrt(number), 0, type_number);
          break;
        case type_ln:
          s21_Push(&maths_stack, log(number), 0, type_number);
          break;
        case type_log:
          s21_Push(&maths_stack, log10(number), 0, type_number);
          break;
        default:
          break;
      }
    }
    tmp_polish = tmp_polish->next;
  }
  if (maths_stack != NULL) *answer = s21_Pop(&maths_stack);
}

void s21_clean(Node **p_list) {
  Node *list = *p_list;
  while (list != NULL) {
    s21_Pop(&list);
  }
}

void s21_Reverse(Node **p_list) {
  if (*p_list != NULL) {
    Node *list = *p_list, *next, *prev = NULL;
    while (list) {
      next = list->next;  // указатель next указывает на следующую  ноду
      list->next = prev;  // указатель ноды который указывал на следующий
                          // элемент теперь указывает на предыдущий
      prev = list;  // указатель созданный нами теперь указывает на текущую
                    // ноду как на прошлый элемент списка
      list = next;  // текущий указатель теперь указывает на следующий элемент
                    // списка
    }
    *p_list = prev;  // в конце устанавливаем указатель p_list на новый
  }
}

void s21_Push(Node **p_list, double value, int priority, lexem_type type) {
  Node *p = malloc(sizeof(Node));
  p->value = value;
  p->priority = priority;
  p->type = type;
  p->next = *p_list;
  *p_list = p;
}

// приходит указатель на указатель
double s21_Pop(Node **p_list) {
  // создаем указатель который указывает туда же куда указатель p_list
  Node *p = *p_list;
  // забираем значение
  double res = p->value;
  // зануляем все значения
  p->priority = 0;
  p->type = 0;
  // пришедший указатель теперь указывает на следующий элемент списка
  *p_list = p->next;
  // освобождаем пришедший элемент
  free(p);
  // возвращаем число
  return res;
}

// void s21_print_list(Node *list) {
//   for (Node *p = list; p != NULL; p = p->next) {
//     printf("%lf ", p->value);
//   }
//   printf("\n");
// }

int s21_check_expression(char *str) {
  int result = ERROR, open_bracket = 0, close_bracket = 0;
  for (int i = 0; str[i] != '\0'; ++i) {
    if (str[i] == '(')  // проверка скобочек
      open_bracket++;
    else if (str[i] == ')')
      close_bracket++;
  }
  int len = strlen(str) - 1;
  if ((open_bracket == close_bracket) &&
      (isdigit(str[len]) || str[len] == ')' || str[len] == 'x'))
    result = OK;

  return result;
}
