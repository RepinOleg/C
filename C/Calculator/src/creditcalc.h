#ifndef CREDITCALC_H
#define CREDITCALC_H

#include <QDialog>

namespace Ui {
class creditCalc;
}

class creditCalc : public QDialog {
  Q_OBJECT

 public:
  explicit creditCalc(QWidget *parent = nullptr);
  ~creditCalc();

 private slots:
  void on_calculate_clicked();

 private:
  Ui::creditCalc *ui;
};

#endif  // CREDITCALC_H
