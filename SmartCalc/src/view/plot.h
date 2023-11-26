#ifndef CPP3_SMART_CALC_V20_PLOT_H
#define CPP3_SMART_CALC_V20_PLOT_H

#include <QDialog>

#include "../controller/controller.h"
#include "QVector"
#include "qcustomplot.h"
namespace Ui {
class Plot;
}

class Plot : public QDialog {
  Q_OBJECT

 public:
  explicit Plot(QWidget *parent = nullptr);
  explicit Plot(s21::Controller *c) : control_(c) {}
  void PlotGraph(char *str, double xMax, double xMin, double yMax, double yMin);
  ~Plot();

  //  public slots:

  // void PlotGraph();

 private:
  Ui::Plot *ui_;
  double xBegin_, xEnd_, step_, tmp_X_;
  char tmp_str[300];
  QString text_str_;
  QVector<double> x_, y_;
  s21::Controller *control_;
};

#endif  // CPP3_SMART_CALC_V20_PLOT_H
