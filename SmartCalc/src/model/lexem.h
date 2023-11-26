#ifndef CPP3_SMART_CALC_V20_LEXEM_H_
#define CPP3_SMART_CALC_V20_LEXEM_H_

namespace s21 {

enum LexemeType {
  kdefault = -1,
  knumber = 0,
  kx = 1,
  kplus = 2,
  kminus = 3,
  kmult = 4,
  kdiv = 5,
  kexponent = 6,
  kmod = 7,
  kcos = 8,
  ksin = 9,
  ktan = 10,
  kacos = 11,
  kasin = 12,
  katan = 13,
  ksqrt = 14,
  kln = 15,
  klog = 16,
  kopenbracket = 20,
  kclosebracket = 21
};

struct Lexeme {
  double value;
  int priority;
  LexemeType type;

  explicit Lexeme(double value, int priority, LexemeType type);
};

}  // namespace s21
#endif  // CPP3_SMART_CALC_V20_LEXEM_H_