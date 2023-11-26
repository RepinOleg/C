#include "plot.h"

#include "./ui_plot.h"

Plot::Plot(QWidget *parent) : QDialog(parent), ui_(new Ui::Plot) {
  ui_->setupUi(this);
}

Plot::~Plot() { delete ui_; }

void Plot::PlotGraph(char *str, double xMax, double xMin, double yMax,
                     double yMin) {
  ui_->widget->clearGraphs();
  strcpy(tmp_str, str);
  ui_->widget->xAxis->setRange(xMin, xMax);
  ui_->widget->yAxis->setRange(yMin, yMax);
  step_ = (xMax - xMin) / 2000;
  for (tmp_X_ = xMin; tmp_X_ <= xMax; tmp_X_ += step_) {
    double yVector = 0;
    yVector = control_->Calculation(str, tmp_X_);
    x_.push_back(tmp_X_);
    y_.push_back(yVector);
  }
  QPen pen;
  ui_->widget->addGraph();
  ui_->widget->addGraph()->setPen(pen);
  ui_->widget->graph(0)->addData(x_, y_);
  ui_->widget->setBackground(QColor(128, 128, 128));
  ui_->widget->xAxis->setLabel("X");
  ui_->widget->yAxis->setLabel("Y");
  ui_->widget->setInteraction(QCP::iRangeDrag, true);
  ui_->widget->replot();

  x_.clear();
  y_.clear();
}

// void Plot::PlotGraph() { Plot::PlotGraph(tmp_str, xMax, xMin, yMax, yMin); }
