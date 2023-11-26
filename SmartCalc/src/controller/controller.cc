#include "controller.h"

namespace s21 {
double Controller::Calculation(const std::string& str, double x) {
  return calcmodel_->MainCalculation(str, x);
}

std::unordered_map<std::string, double> Controller::CreditCalculation(
    double sum, double bid, double months, bool f) {
  return creditmodel_->CreditCalculation(sum, bid, months, f);
}
bool Controller::Validation(const std::string& str) {
  return validationstr_->Validation(str);
}
}  // namespace s21
