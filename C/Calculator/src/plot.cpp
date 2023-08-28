#include "plot.h"

#include "./ui_plot.h"
#include "qcustomplot.h"

extern "C" {
#include "s21_smart_calc.h"
}
Plot::Plot(QWidget *parent) : QDialog(parent), ui(new Ui::Plot) {
  ui->setupUi(this);
}

Plot::~Plot() { delete ui; }

void Plot::PlotGraph(char *str, double xMax, double xMin, double yMax,
                     double yMin) {
  ui->widget->clearGraphs();
  strcpy(tmp_str, str);

  ui->widget->xAxis->setRange(xMin, xMax);
  ui->widget->yAxis->setRange(yMin, yMax);

  step = (xMax - xMin) / ((xMax - xMin) * 10);
  for (tmp_X = xMin; tmp_X <= xMax; tmp_X += step) {
    double yVector = 0;
    s21_smart_calc(str, &yVector, tmp_X);
    x.push_back(tmp_X);
    y.push_back(yVector);
  }
  QPen pen;
  ui->widget->addGraph();
  ui->widget->addGraph()->setPen(pen);
  ui->widget->graph(0)->addData(x, y);
  ui->widget->setBackground(QColor(128, 128, 128));
  ui->widget->xAxis->setLabel("X");
  ui->widget->yAxis->setLabel("Y");
  ui->widget->setInteraction(QCP::iRangeDrag, true);
  ui->widget->replot();

  x.clear();
  y.clear();
}

void Plot::PlotGraph() { Plot::PlotGraph(tmp_str, xMax, xMin, yMax, yMin); }
