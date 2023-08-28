#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <creditcalc.h>
#include <plot.h>

#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  Plot *windowPlot;
  creditCalc *windowCredit;

 private slots:
  void s21_digit_numbers();
  void s21_equal();
  void s21_operations();
  void s21_functions();
  void s21_deleteAll();
  void s21_deleteChar();
  void s21_graph();
  void s21_credit_calc();
};
#endif  // MAINWINDOW_H
