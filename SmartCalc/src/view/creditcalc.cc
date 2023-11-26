#include "creditcalc.h"

#include "ui_creditcalc.h"

CreditCalc::CreditCalc(QWidget* parent)
    : QDialog(parent), ui_(new Ui::CreditCalc) {
  ui_->setupUi(this);
  connect(ui_->calculate, SIGNAL(clicked()), this,
          SLOT(on_calculate_clicked()));
}

CreditCalc::~CreditCalc() { delete ui_; }

void CreditCalc::on_calculate_clicked() {
  double sumValue = ui_->sum_value->text().toDouble();
  double bid = ui_->bid_value->text().toDouble();
  int i_term = ui_->term->currentIndex();
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

  bool type_credit = false;
  if (ui_->radioButton_diff->isChecked()) type_credit = true;

  std::unordered_map<std::string, double> result =
      control_->CreditCalculation(sumValue, bid, months, type_credit);

  if (!type_credit) {
    QString payment = QString::number(result.at("payment"), 'f', 2);
    ui_->monthly_payment->setText(payment);
    QString totalSum = QString::number(result.at("total"), 'f', 2);
    ui_->total_amount->setText(totalSum);
    QString diff_final = QString::number(result.at("diff"), 'f', 2);
    ui_->overpayment->setText(diff_final);
  } else {
    QString payment = QString::number(result.at("first_payment"), 'f', 2);
    payment += " ... ";
    payment += QString::number(result.at("last_payment"), 'f', 2);
    ui_->monthly_payment->setText(payment);
    QString totalSum = QString::number(result.at("total"), 'f', 2);
    ui_->total_amount->setText(totalSum);
    QString diff_final = QString::number(result.at("diff"), 'f', 2);
    ui_->overpayment->setText(diff_final);
  }
}
