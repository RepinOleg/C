#ifndef PLOT_H
#define PLOT_H

#include <QDialog>

#include "QVector"

extern "C" {
#include "s21_smart_calc.h"
}

namespace Ui {
class Plot;
}

class Plot : public QDialog {
  Q_OBJECT

 public:
  explicit Plot(QWidget *parent = nullptr);
  void PlotGraph(char *str, double xMax, double xMin, double yMax, double yMin);
  ~Plot();

 public slots:

  void PlotGraph();

 private:
  Ui::Plot *ui;
  double xBegin, xEnd, step, tmp_X, xMax, xMin, yMax, yMin;
  char tmp_str[300];
  QString text_str;
  QVector<double> x, y;
};

#endif  // PLOT_H
