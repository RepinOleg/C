#ifndef CPP3_SMART_CALC_V20_CALCULATOR_MODEL_H_
#define CPP3_SMART_CALC_V20_CALCULATOR_MODEL_H_

#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>

#include "lexem.h"

namespace s21 {
class CalcModel {
 public:
  CalcModel() {}
  double MainCalculation(const std::string& str, double x);
  double get_answer() { return answer_; }

 private:
  std::stack<Lexeme> main_stack;
  std::stack<Lexeme> helpfull_stack;
  void Parser(const std::string& str, double x);
  void ParserFunc(const std::string& str, int& i);
  double ParserNumber(const std::string& str, int& i);
  void ParserOperations(const std::string& str, int i);
  void PolishNotation();
  void ReverseStack();
  void Calculation();

  double answer_;
};

class Validator {
 public:
  bool Validation(const std::string& str);
};
}  // namespace s21

#endif  //  CPP3_SMART_CALC_V20_CALCULATOR_MODEL_H_