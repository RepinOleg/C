#ifndef CPP3_SMART_CALC_V20_CALCULATOR_CONTROLLER_H_
#define CPP3_SMART_CALC_V20_CALCULATOR_CONTROLLER_H_

#include "../model/calculator_model.h"
#include "../model/credit_model.h"
namespace s21 {
class Controller {
 public:
  Controller(CalcModel* calc) : calcmodel_(calc) {}
  double Calculation(const std::string& str, double x);
  bool Validation(const std::string& str);

  std::unordered_map<std::string, double> CreditCalculation(double sum,
                                                            double bid,
                                                            double months,
                                                            bool f);

 private:
  CreditCalc* creditmodel_;
  Validator* validationstr_;
  CalcModel* calcmodel_;
};
}  // namespace s21

#endif