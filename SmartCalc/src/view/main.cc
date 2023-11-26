#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::CalcModel model;
  s21::Controller control(&model);
  MainWindow w(&control);
  w.setWindowTitle("Smart_calc 2.0");
  w.show();
  return a.exec();
}
