#ifndef CPP3_SMART_CALC_V20_CREDITCALC_H
#define CPP3_SMART_CALC_V20_CREDITCALC_H

#include <QDialog>

#include "../controller/controller.h"

namespace Ui {
class CreditCalc;
}

class CreditCalc : public QDialog {
  Q_OBJECT

 public:
  explicit CreditCalc(QWidget *parent = nullptr);
  explicit CreditCalc(s21::Controller *c) : control_(c) {}
  ~CreditCalc();

 private slots:
  void on_calculate_clicked();

 private:
  Ui::CreditCalc *ui_;
  s21::Controller *control_;
};

#endif  // CPP3_SMART_CALC_V20_CREDITCALC_H
