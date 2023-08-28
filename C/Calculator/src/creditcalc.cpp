#include "creditcalc.h"

#include "ui_creditcalc.h"

extern "C" {
#include "s21_smart_calc.h"
}
creditCalc::creditCalc(QWidget *parent)
    : QDialog(parent), ui(new Ui::creditCalc) {
  ui->setupUi(this);
  connect(ui->calculate, SIGNAL(clicked()), this, SLOT(on_calculate_clicked()));
}

creditCalc::~creditCalc() { delete ui; }

void creditCalc::on_calculate_clicked() {
  double sumValue = ui->sum_value->text().toDouble();
  double bid = ui->bid_value->text().toDouble();
  int i_term = ui->term->currentIndex();
  double months = 0;
  switch (i_term) {
    case 0:
      months = 1;
      break;
    case 1:
      months = 3;
      break;
    case 2:
      months = 6;
      break;
    case 3:
      months = 9;
      break;
    case 4:
      months = 12;
      break;
    case 5:
      months = 18;
      break;
    case 6:
      months = 24;
      break;
    case 7:
      months = 36;
      break;
    case 8:
      months = 48;
      break;
    case 9:
      months = 60;
      break;
    case 10:
      months = 72;
      break;
    case 11:
      months = 84;
      break;
    case 12:
      months = 120;
      break;
    case 13:
      months = 180;
      break;
    case 14:
      months = 240;
      break;
    case 15:
      months = 300;
      break;
    case 16:
      months = 360;
      break;
    case 17:
      months = 600;
      break;
  }
  double total = 0, diff = 0, platezh = 0, percentPerMonth = (bid / 12) / 100;
  if (sumValue > 0 && bid > 0 && bid < 1000) {
    if (ui->radioButton_Annuin->isChecked()) {
      platezh =
          sumValue * (percentPerMonth * pow((1 + percentPerMonth), months) /
                      (pow((1 + percentPerMonth), months) - 1));
      total = platezh * months;
      diff = total - sumValue;

      QString payment = QString::number(platezh, 'f', 2);
      ui->monthly_payment->setText(payment);
      QString totalSum = QString::number(total, 'f', 2);
      ui->total_amount->setText(totalSum);
      QString diff_final = QString::number(diff, 'f', 2);
      ui->overpayment->setText(diff_final);
    } else if (ui->radioButton_diff->isChecked()) {
      double part_of_duty = sumValue / months;

      double first =
          part_of_duty + (sumValue - part_of_duty * 0) * percentPerMonth;
      double last = part_of_duty +
                    (sumValue - part_of_duty * (months - 1)) * percentPerMonth;

      for (int countMonth = 0; countMonth < (int)months; countMonth++) {
        total += part_of_duty +
                 (sumValue - part_of_duty * countMonth) * percentPerMonth;
      }
      diff = total - sumValue;

      QString payment = QString::number(first, 'f', 2);
      payment += " ... ";
      payment += QString::number(last, 'f', 2);
      ui->monthly_payment->setText(payment);
      QString totalSum = QString::number(total, 'f', 2);
      ui->total_amount->setText(totalSum);
      QString diff_final = QString::number(diff, 'f', 2);
      ui->overpayment->setText(diff_final);
    }
  }
}
