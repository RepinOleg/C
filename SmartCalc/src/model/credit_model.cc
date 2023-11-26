#include "credit_model.h"

#include <iostream>
namespace s21 {
std::unordered_map<std::string, double> CreditCalc::CreditCalculation(
    double sum_value, double bid, double months, bool flag) {
  double percentPerMonth = (bid / 12) / 100;
  std::unordered_map<std::string, double> result;
  double total = 0;
  if (sum_value > 0 && bid > 0 && bid < 1000) {
    if (!flag) {
      double payment =
          sum_value *
          (percentPerMonth * std::pow((1 + percentPerMonth), months) /
           (std::pow((1 + percentPerMonth), months) - 1));
      total = payment * months;
      result.insert(std::make_pair("diff", total - sum_value));
      result.insert(std::make_pair("payment", payment));
      result.insert(std::make_pair("total", total));
    } else if (flag) {
      double part_of_duty = sum_value / months;

      double first_payment =
          part_of_duty + (sum_value - part_of_duty * 0) * percentPerMonth;
      double last_payment =
          part_of_duty +
          (sum_value - part_of_duty * (months - 1)) * percentPerMonth;

      for (int countMonth = 0; countMonth < (int)months; countMonth++) {
        total += part_of_duty +
                 (sum_value - part_of_duty * countMonth) * percentPerMonth;
      }
      result.insert(std::make_pair("diff", total - sum_value));
      result.insert(std::make_pair("first_payment", first_payment));
      result.insert(std::make_pair("last_payment", last_payment));
      result.insert(std::make_pair("total", total));
    }
  }
  return result;
}
}  // namespace s21