#ifndef CPP3_SMART_CALC_V20_MAINWINDOW_H
#define CPP3_SMART_CALC_V20_MAINWINDOW_H

#include <QMainWindow>

#include "../controller/controller.h"
#include "creditcalc.h"
#include "plot.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(s21::Controller *c, QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui_;
  CreditCalc *windowCredit_;
  Plot *windowPlot_;
  s21::Controller *control_;

 private slots:
  void s21_digit_numbers();
  void s21_equal();
  void s21_operations();
  void s21_functions();
  void s21_deleteAll();
  void s21_deleteChar();
  void s21_credit_calc();
  void s21_graph();
};
#endif  // MAINWINDOW_H
