#include "calculator_model.h"

namespace s21 {
double CalcModel::MainCalculation(const std::string& str, double x) {
  this->Parser(str, x);
  this->PolishNotation();
  this->Calculation();
  return this->get_answer();
}

void CalcModel::Parser(const std::string& str, double x) {
  int l = str.length();
  for (int i = 0; i < l;) {
    if (isdigit(str[i])) {
      main_stack.push(Lexeme(ParserNumber(str, i), 0, knumber));
    } else if (std::strchr("+-/*^()", str[i])) {
      ParserOperations(str, i);
      ++i;
    } else if (std::strchr("cstalm", str[i])) {
      ParserFunc(str, i);
    } else if (str[i] == 'x') {
      main_stack.push(Lexeme(x, 0, knumber));
      ++i;
    }
  }
}

double CalcModel::ParserNumber(const std::string& str, int& i) {
  std::string tmp;
  int k = 0;
  for (; isdigit(str[i]) || str[i] == '.'; ++i, ++k) {
    tmp[k] = str[i];
  }
  tmp[k] = '\0';
  double result = stod(tmp);
  return result;
}

void CalcModel::ParserOperations(const std::string& str, int i) {
  switch (str[i]) {
    case '+':
      if (i > 0 &&
          (isdigit(str[i - 1]) || str[i - 1] == 'x' || str[i - 1] == ')'))
        main_stack.push(Lexeme(0, 1, kplus));
      break;
    case '-':
      if (i > 0 &&
          (isdigit(str[i - 1]) || str[i - 1] == 'x' || str[i - 1] == ')')) {
        main_stack.push(Lexeme(0, 1, kminus));
      } else {
        main_stack.push(Lexeme(0, 0, knumber));
        main_stack.push(Lexeme(0, 1, kminus));
      }
      break;
    case '/':
      main_stack.push(Lexeme(0, 2, kdiv));
      break;
    case '*':
      main_stack.push(Lexeme(0, 2, kmult));
      break;
    case '^':
      main_stack.push(Lexeme(0, 3, kexponent));
      break;
    case '(':
      main_stack.push(Lexeme(0, -1, kopenbracket));
      break;
    case ')':
      main_stack.push(Lexeme(0, -1, kclosebracket));
      break;
  }
}

void CalcModel::ParserFunc(const std::string& str, int& i) {
  if (str[i] == 'm') {
    main_stack.push(Lexeme(0, 3, kmod));
    i += 3;
  } else if (str[i] == 'c') {
    main_stack.push(Lexeme(0, 4, kcos));
    i += 3;
  } else if (str[i] == 'l' && str[i + 1] == 'n') {
    main_stack.push(Lexeme(0, 4, kln));
    i += 2;
  } else if (str[i] == 'l' && str[i + 1] == 'o') {
    main_stack.push(Lexeme(0, 4, klog));
    i += 3;
  } else if (str[i] == 's' && str[i + 1] == 'q') {
    main_stack.push(Lexeme(0, 4, ksqrt));
    i += 4;
  } else if (str[i] == 's' && str[i + 1] == 'i') {
    main_stack.push(Lexeme(0, 4, ksin));
    i += 3;
  } else if (str[i] == 't') {
    main_stack.push(Lexeme(0, 4, ktan));
    i += 3;
  } else if (str[i] == 'a') {
    switch (str[i + 1]) {
      case 'c':
        main_stack.push(Lexeme(0, 4, kacos));
        i += 4;
        break;
      case 's':
        main_stack.push(Lexeme(0, 4, kasin));
        i += 4;
        break;
      case 't':
        main_stack.push(Lexeme(0, 4, katan));
        i += 4;
        break;
    }
  }
}

void CalcModel::PolishNotation() {
  ReverseStack();

  // Временный стэк для хранения результата
  std::stack<Lexeme> tmp_stack;

  /* Алгоритм перевода выражения в обратную польскую нотацию*/

  while (!main_stack.empty()) {
    /* Обновляем ссылки */
    std::stack<Lexeme>::reference p_main = main_stack.top();
    std::stack<Lexeme>::reference p_helpfull = helpfull_stack.top();

    // Число в стэк
    if (p_main.type == knumber) {
      tmp_stack.push(main_stack.top());

    } else if (p_main.priority > 0 && p_main.priority < 5) {
      // операция в стэк с операциями
      while (!helpfull_stack.empty() &&
             p_main.priority <= p_helpfull.priority) {
        tmp_stack.push(helpfull_stack.top());
        helpfull_stack.pop();
        if (!helpfull_stack.empty()) p_helpfull = helpfull_stack.top();
      }
      helpfull_stack.push(main_stack.top());

    } else if (p_main.type == kopenbracket) {
      helpfull_stack.push(main_stack.top());
    } else if (p_main.type == kclosebracket) {
      while (p_helpfull.type != kopenbracket && !helpfull_stack.empty()) {
        tmp_stack.push(helpfull_stack.top());
        helpfull_stack.pop();
        if (!helpfull_stack.empty()) p_helpfull = helpfull_stack.top();
      }

      helpfull_stack.pop();
      if (!helpfull_stack.empty()) p_helpfull = helpfull_stack.top();
      if (!helpfull_stack.empty() && p_helpfull.priority == 4) {
        tmp_stack.push(helpfull_stack.top());
        helpfull_stack.pop();
      }
    }

    /* Удаляем элемент из вершины стэка */
    main_stack.pop();
  }
  /* Все что осталось в стэке с операциями пушим в основной стэк */
  while (!helpfull_stack.empty()) {
    tmp_stack.push(helpfull_stack.top());
    helpfull_stack.pop();
  }

  main_stack = tmp_stack;
  ReverseStack();
}

void CalcModel::Calculation() {
  while (!main_stack.empty()) {
    std::stack<Lexeme>::reference p_math = helpfull_stack.top();
    std::stack<Lexeme>::reference p_main = main_stack.top();
    if (!p_main.priority) {
      helpfull_stack.push(p_main);
    } else if (p_main.priority > 0 && p_main.priority < 4) {
      double x = p_math.value;
      helpfull_stack.pop();
      p_math = helpfull_stack.top();
      double y = p_math.value;
      helpfull_stack.pop();
      switch (p_main.type) {
        case kplus:
          helpfull_stack.push(Lexeme(y + x, 0, knumber));
          break;
        case kminus:
          helpfull_stack.push(Lexeme(y - x, 0, knumber));
          break;
        case kmult:
          helpfull_stack.push(Lexeme(y * x, 0, knumber));
          break;
        case kdiv:
          helpfull_stack.push(Lexeme(y / x, 0, knumber));
          break;
        case kexponent:
          helpfull_stack.push(Lexeme(std::pow(y, x), 0, knumber));
          break;
        case kmod:
          helpfull_stack.push(Lexeme(std::fmod(y, x), 0, knumber));
          break;
        default:
          break;
      }
    } else if (p_main.priority == 4) {
      double x = p_math.value;
      helpfull_stack.pop();
      switch (p_main.type) {
        case kcos:
          helpfull_stack.push(Lexeme(std::cos(x), 0, knumber));
          break;
        case ksin:
          helpfull_stack.push(Lexeme(std::sin(x), 0, knumber));
          break;
        case ktan:
          helpfull_stack.push(Lexeme(std::tan(x), 0, knumber));
          break;
        case kacos:
          helpfull_stack.push(Lexeme(std::acos(x), 0, knumber));
          break;
        case kasin:
          helpfull_stack.push(Lexeme(std::asin(x), 0, knumber));
          break;
        case katan:
          helpfull_stack.push(Lexeme(std::atan(x), 0, knumber));
          break;
        case ksqrt:
          helpfull_stack.push(Lexeme(std::sqrt(x), 0, knumber));
          break;
        case klog:
          helpfull_stack.push(Lexeme(std::log10(x), 0, knumber));
          break;
        case kln:
          helpfull_stack.push(Lexeme(std::log(x), 0, knumber));
          break;
        default:
          break;
      }
    }
    main_stack.pop();
  }
  if (!helpfull_stack.empty()) {
    std::stack<Lexeme>::reference res = helpfull_stack.top();
    answer_ = res.value;
  }
}

void CalcModel::ReverseStack() {
  std::stack<Lexeme> tmp;
  while (!main_stack.empty()) {
    tmp.push(main_stack.top());
    main_stack.pop();
  }
  main_stack = tmp;
}

bool Validator::Validation(const std::string& str) {
  if (str.length() > 255) return false;
  if (!isdigit(str[str.length() - 1]) && str[str.length() - 1] != 'x' &&
      str[str.length() - 1] != ')')
    return false;

  int brackets = 0;
  for (std::size_t i = 0; i < str.length(); ++i) {
    if (isdigit(str[i])) {
      int count_dot = 0;
      while (i < str.length() && (isdigit(str[i]) || str[i] == '.')) {
        if (str[i] == '.') ++count_dot;
        ++i;
        if (count_dot > 1) return false;
      }
    }
    if (str[i] == '(')
      ++brackets;
    else if (str[i] == ')')
      --brackets;
  }
  if (brackets) return false;
  return true;
}
}  // namespace s21