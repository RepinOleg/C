/********************************************************************************
** Form generated from reading UI file 'plot.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CPP3_SMART_CALC_V20_UI_PLOT_H
#define CPP3_SMART_CALC_V20_UI_PLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>

#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Plot {
 public:
  QGridLayout *gridLayout;
  QCustomPlot *widget;

  void setupUi(QDialog *Plot) {
    if (Plot->objectName().isEmpty())
      Plot->setObjectName(QString::fromUtf8("Plot"));
    Plot->resize(772, 466);
    gridLayout = new QGridLayout(Plot);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    widget = new QCustomPlot(Plot);
    widget->setObjectName(QString::fromUtf8("widget"));

    gridLayout->addWidget(widget, 0, 0, 1, 1);

    retranslateUi(Plot);

    QMetaObject::connectSlotsByName(Plot);
  }  // setupUi

  void retranslateUi(QDialog *Plot) {
    Plot->setWindowTitle(
        QCoreApplication::translate("Plot", "Dialog", nullptr));
  }  // retranslateUi
};

namespace Ui {
class Plot : public Ui_Plot {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // CPP3_SMART_CALC_V20_UI_PLOT_H
