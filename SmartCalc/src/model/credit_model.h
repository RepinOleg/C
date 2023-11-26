#ifndef CPP3_SMART_CALC_V20_CALCULATOR_CREDIT_MODEL_H_
#define CPP3_SMART_CALC_V20_CALCULATOR_CREDIT_MODEL_H_
#include <cmath>
#include <string>
#include <unordered_map>

namespace s21 {
class CreditCalc {
 public:
  std::unordered_map<std::string, double> CreditCalculation(double sum,
                                                            double bid,
                                                            double months,
                                                            bool f);
};
}  // namespace s21

#endif  //  CPP3_SMART_CALC_V20_CALCULATOR_CREDIT_MODEL_H_