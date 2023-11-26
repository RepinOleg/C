/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CPP3_SMART_CALC_V20_UI_MAINWINDOW_H
#define CPP3_SMART_CALC_V20_UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QWidget *centralwidget;
  QLabel *result_show;
  QPushButton *pushButton_seven;
  QPushButton *pushButton_eight;
  QPushButton *pushButton_nine;
  QPushButton *pushButton_mult;
  QPushButton *pushButton_four;
  QPushButton *pushButton_five;
  QPushButton *pushButton_six;
  QPushButton *pushButton_minus;
  QPushButton *pushButton_dot;
  QPushButton *pushButton_equal;
  QPushButton *pushButton_one;
  QPushButton *pushButton_plus;
  QPushButton *pushButton_two;
  QPushButton *pushButton_three;
  QPushButton *pushButton_zero;
  QPushButton *pushButton_openbracket;
  QPushButton *pushButton_clear;
  QPushButton *pushButton_closebracket;
  QPushButton *pushButton_mod;
  QPushButton *pushButton_ln;
  QPushButton *pushButton_log;
  QPushButton *pushButton_tan;
  QPushButton *pushButton_cos;
  QPushButton *pushButton_sin;
  QPushButton *pushButton_acos;
  QPushButton *pushButton_atan;
  QPushButton *pushButton_asin;
  QPushButton *pushButton_sqrt;
  QPushButton *pushButton_degree;
  QPushButton *pushButton_divide;
  QPushButton *pushButton_plot;
  QLabel *label_5;
  QPushButton *pushButton_X;
  QPushButton *pushButton_CE;
  QLineEdit *Xmin;
  QLineEdit *Ymin;
  QLineEdit *Xmax;
  QLineEdit *Ymax;
  QLabel *label_2;
  QLabel *label;
  QLabel *label_4;
  QLabel *label_3;
  QLineEdit *x_value;
  QPushButton *pushButton_creditCalc;
  QMenuBar *menuBar;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(687, 526);
    MainWindow->setStyleSheet(
        QString::fromUtf8("QMainWindow{\n"
                          "    background-color: rgb(105, 105, 105);\n"
                          "    width: 10px; /* when vertical */\n"
                          "    height: 10px; /* when horizontal */\n"
                          "}"));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    result_show = new QLabel(centralwidget);
    result_show->setObjectName(QString::fromUtf8("result_show"));
    result_show->setGeometry(QRect(15, 20, 511, 61));
    QFont font;
    font.setPointSize(20);
    result_show->setFont(font);
    result_show->setStyleSheet(QString::fromUtf8(
        "QLabel {\n"
        "	qproperty-alignment: 'AlignVCenter | AlignRight';\n"
        "	 background-color: rgb(105, 105, 105);\n"
        "	color: white\n"
        "}\n"
        "\n"
        ""));
    result_show->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                              Qt::AlignVCenter);
    pushButton_seven = new QPushButton(centralwidget);
    pushButton_seven->setObjectName(QString::fromUtf8("pushButton_seven"));
    pushButton_seven->setGeometry(QRect(240, 190, 61, 61));
    QFont font1;
    font1.setPointSize(18);
    pushButton_seven->setFont(font1);
    pushButton_seven->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(215, 215, 215);\n"
        "  color: white; \n"
        "  border: 1px solid gray;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #FF7832, stop: 1 "
        "#FF9739);\n"
        "}"));
    pushButton_eight = new QPushButton(centralwidget);
    pushButton_eight->setObjectName(QString::fromUtf8("pushButton_eight"));
    pushButton_eight->setGeometry(QRect(315, 190, 61, 61));
    pushButton_eight->setFont(font1);
    pushButton_eight->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(215, 215, 215);\n"
        "  color: white; \n"
        "  border: 1px solid gray;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #FF7832, stop: 1 "
        "#FF9739);\n"
        "}"));
    pushButton_nine = new QPushButton(centralwidget);
    pushButton_nine->setObjectName(QString::fromUtf8("pushButton_nine"));
    pushButton_nine->setGeometry(QRect(390, 190, 61, 61));
    pushButton_nine->setFont(font1);
    pushButton_nine->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(215, 215, 215);\n"
        "  color: white; \n"
        "  border: 1px solid gray;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #FF7832, stop: 1 "
        "#FF9739);\n"
        "}"));
    pushButton_mult = new QPushButton(centralwidget);
    pushButton_mult->setObjectName(QString::fromUtf8("pushButton_mult"));
    pushButton_mult->setGeometry(QRect(465, 190, 61, 61));
    QFont font2;
    font2.setPointSize(15);
    pushButton_mult->setFont(font2);
    pushButton_mult->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(255, 151, 57);\n"
        "  color: white; \n"
        "  border: 1px solid gray;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #FF7832, stop: 1 "
        "#FF9739);\n"
        "}"));
    pushButton_four = new QPushButton(centralwidget);
    pushButton_four->setObjectName(QString::fromUtf8("pushButton_four"));
    pushButton_four->setGeometry(QRect(240, 270, 61, 61));
    pushButton_four->setFont(font1);
    pushButton_four->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(215, 215, 215);\n"
        "  color: white; \n"
        "  border: 1px solid gray;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #FF7832, stop: 1 "
        "#FF9739);\n"
        "}"));
    pushButton_five = new QPushButton(centralwidget);
    pushButton_five->setObjectName(QString::fromUtf8("pushButton_five"));
    pushButton_five->setGeometry(QRect(315, 270, 61, 61));
    pushButton_five->setFont(font1);
    pushButton_five->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(215, 215, 215);\n"
        "  color: white; \n"
        "  border: 1px solid gray;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #FF7832, stop: 1 "
        "#FF9739);\n"
        "}"));
    pushButton_six = new QPushButton(centralwidget);
    pushButton_six->setObjectName(QString::fromUtf8("pushButton_six"));
    pushButton_six->setGeometry(QRect(390, 270, 61, 61));
    pushButton_six->setFont(font1);
    pushButton_six->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(215, 215, 215);\n"
        "  color: white; \n"
        "  border: 1px solid gray;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #FF7832, stop: 1 "
        "#FF9739);\n"
        "}"));
    pushButton_minus = new QPushButton(centralwidget);
    pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
    pushButton_minus->setGeometry(QRect(465, 270, 61, 61));
    pushButton_minus->setFont(font2);
    pushButton_minus->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(255, 151, 57);\n"
        "  color: white; \n"
        "  border: 1px solid gray;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #FF7832, stop: 1 "
        "#FF9739);\n"
        "}"));
    pushButton_dot = new QPushButton(centralwidget);
    pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
    pushButton_dot->setGeometry(QRect(390, 430, 61, 61));
    QFont font3;
    font3.setPointSize(14);
    pushButton_dot->setFont(font3);
    pushButton_dot->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(215, 215, 215);\n"
        "  border: 1px solid gray;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #BEBEBE, stop: 1 "
        "#D7D7D7);\n"
        "}"));
    pushButton_equal = new QPushButton(centralwidget);
    pushButton_equal->setObjectName(QString::fromUtf8("pushButton_equal"));
    pushButton_equal->setGeometry(QRect(465, 430, 61, 61));
    pushButton_equal->setFont(font2);
    pushButton_equal->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(255, 151, 57);\n"
        "  color: white; \n"
        "  border: 1px solid gray;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #FF7832, stop: 1 "
        "#FF9739);\n"
        "}"));
    pushButton_one = new QPushButton(centralwidget);
    pushButton_one->setObjectName(QString::fromUtf8("pushButton_one"));
    pushButton_one->setGeometry(QRect(240, 350, 61, 61));
    pushButton_one->setFont(font1);
    pushButton_one->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(215, 215, 215);\n"
        "  color: white; \n"
        "  border: 1px solid gray;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #FF7832, stop: 1 "
        "#FF9739);\n"
        "}"));
    pushButton_plus = new QPushButton(centralwidget);
    pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
    pushButton_plus->setGeometry(QRect(465, 350, 61, 61));
    pushButton_plus->setFont(font2);
    pushButton_plus->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(255, 151, 57);\n"
        "  color: white; \n"
        "  border: 1px solid gray;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #FF7832, stop: 1 "
        "#FF9739);\n"
        "}"));
    pushButton_two = new QPushButton(centralwidget);
    pushButton_two->setObjectName(QString::fromUtf8("pushButton_two"));
    pushButton_two->setGeometry(QRect(315, 350, 61, 61));
    pushButton_two->setFont(font1);
    pushButton_two->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(215, 215, 215);\n"
        "  color: white; \n"
        "  border: 1px solid gray;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #FF7832, stop: 1 "
        "#FF9739);\n"
        "}"));
    pushButton_three = new QPushButton(centralwidget);
    pushButton_three->setObjectName(QString::fromUtf8("pushButton_three"));
    pushButton_three->setGeometry(QRect(390, 350, 61, 61));
    pushButton_three->setFont(font1);
    pushButton_three->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(215, 215, 215);\n"
        "  color: white; \n"
        "  border: 1px solid gray;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #FF7832, stop: 1 "
        "#FF9739);\n"
        "}"));
    pushButton_zero = new QPushButton(centralwidget);
    pushButton_zero->setObjectName(QString::fromUtf8("pushButton_zero"));
    pushButton_zero->setGeometry(QRect(315, 430, 61, 61));
    pushButton_zero->setFont(font1);
    pushButton_zero->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(215, 215, 215);\n"
        "  color: white; \n"
        "  border: 1px solid gray;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #FF7832, stop: 1 "
        "#FF9739);\n"
        "}"));
    pushButton_openbracket = new QPushButton(centralwidget);
    pushButton_openbracket->setObjectName(
        QString::fromUtf8("pushButton_openbracket"));
    pushButton_openbracket->setGeometry(QRect(90, 190, 61, 61));
    QFont font4;
    font4.setPointSize(13);
    pushButton_openbracket->setFont(font4);
    pushButton_openbracket->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(190, 190, 190);\n"
        "  border: 1px solid gray;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #BEBEBE, stop: 1 "
        "#D7D7D7);\n"
        "}"));
    pushButton_clear = new QPushButton(centralwidget);
    pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
    pushButton_clear->setGeometry(QRect(15, 110, 211, 61));
    pushButton_clear->setFont(font2);
    pushButton_clear->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: white;\n"
        "  color: rgb(255,151, 57); \n"
        "  border: 1px solid gray;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #FF7832, stop: 1 "
        "#FF9739);\n"
        "}"));
    pushButton_closebracket = new QPushButton(centralwidget);
    pushButton_closebracket->setObjectName(
        QString::fromUtf8("pushButton_closebracket"));
    pushButton_closebracket->setGeometry(QRect(165, 190, 61, 61));
    pushButton_closebracket->setFont(font4);
    pushButton_closebracket->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(190, 190, 190);\n"
        "  border: 1px solid gray;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #BEBEBE, stop: 1 "
        "#D7D7D7);\n"
        "}"));
    pushButton_mod = new QPushButton(centralwidget);
    pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
    pushButton_mod->setGeometry(QRect(240, 430, 61, 61));
    pushButton_mod->setFont(font4);
    pushButton_mod->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(190, 190, 190);\n"
        "  color: black; \n"
        "  border: 1px solid gray;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #FF7832, stop: 1 "
        "#FF9739);\n"
        "}"));
    pushButton_ln = new QPushButton(centralwidget);
    pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
    pushButton_ln->setGeometry(QRect(90, 270, 61, 61));
    pushButton_ln->setFont(font4);
    pushButton_ln->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(190, 190, 190);\n"
        "  border: 1px solid gray;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #BEBEBE, stop: 1 "
        "#D7D7D7);\n"
        "}"));
    pushButton_log = new QPushButton(centralwidget);
    pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
    pushButton_log->setGeometry(QRect(165, 270, 61, 61));
    pushButton_log->setFont(font4);
    pushButton_log->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(190, 190, 190);\n"
        "  border: 1px solid gray;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #BEBEBE, stop: 1 "
        "#D7D7D7);\n"
        "}"));
    pushButton_tan = new QPushButton(centralwidget);
    pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
    pushButton_tan->setGeometry(QRect(165, 350, 61, 61));
    pushButton_tan->setFont(font4);
    pushButton_tan->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(190, 190, 190);\n"
        "  border: 1px solid gray;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #BEBEBE, stop: 1 "
        "#D7D7D7);\n"
        "}"));
    pushButton_cos = new QPushButton(centralwidget);
    pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
    pushButton_cos->setGeometry(QRect(165, 430, 61, 61));
    pushButton_cos->setFont(font4);
    pushButton_cos->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(190, 190, 190);\n"
        "  border: 1px solid gray;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #BEBEBE, stop: 1 "
        "#D7D7D7);\n"
        "}"));
    pushButton_sin = new QPushButton(centralwidget);
    pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
    pushButton_sin->setGeometry(QRect(90, 430, 61, 61));
    pushButton_sin->setFont(font4);
    pushButton_sin->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(190, 190, 190);\n"
        "  border: 1px solid gray;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #BEBEBE, stop: 1 "
        "#D7D7D7);\n"
        "}"));
    pushButton_acos = new QPushButton(centralwidget);
    pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
    pushButton_acos->setGeometry(QRect(15, 430, 61, 61));
    pushButton_acos->setFont(font4);
    pushButton_acos->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(190, 190, 190);\n"
        "  border: 1px solid gray;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #BEBEBE, stop: 1 "
        "#D7D7D7);\n"
        "}"));
    pushButton_atan = new QPushButton(centralwidget);
    pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
    pushButton_atan->setGeometry(QRect(15, 270, 61, 61));
    pushButton_atan->setFont(font4);
    pushButton_atan->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(190, 190, 190);\n"
        "  border: 1px solid gray;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #BEBEBE, stop: 1 "
        "#D7D7D7);\n"
        "}"));
    pushButton_asin = new QPushButton(centralwidget);
    pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
    pushButton_asin->setGeometry(QRect(15, 350, 61, 61));
    pushButton_asin->setFont(font4);
    pushButton_asin->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(190, 190, 190);\n"
        "  border: 1px solid gray;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #BEBEBE, stop: 1 "
        "#D7D7D7);\n"
        "}"));
    pushButton_sqrt = new QPushButton(centralwidget);
    pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
    pushButton_sqrt->setGeometry(QRect(90, 350, 61, 61));
    pushButton_sqrt->setFont(font4);
    pushButton_sqrt->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(190, 190, 190);\n"
        "  border: 1px solid gray;\n"
        "}\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #BEBEBE, stop: 1 "
        "#D7D7D7);\n"
        "}"));
    pushButton_degree = new QPushButton(centralwidget);
    pushButton_degree->setObjectName(QString::fromUtf8("pushButton_degree"));
    pushButton_degree->setGeometry(QRect(15, 190, 61, 61));
    pushButton_degree->setFont(font4);
    pushButton_degree->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(190, 190, 190);\n"
        "  color: black; \n"
        "  border: 1px solid gray;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #FF7832, stop: 1 "
        "#FF9739);\n"
        "}"));
    pushButton_divide = new QPushButton(centralwidget);
    pushButton_divide->setObjectName(QString::fromUtf8("pushButton_divide"));
    pushButton_divide->setGeometry(QRect(465, 110, 61, 61));
    pushButton_divide->setFont(font4);
    pushButton_divide->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: rgb(255, 151, 57);\n"
        "  color: white; \n"
        "  border: 1px solid gray;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #FF7832, stop: 1 "
        "#FF9739);\n"
        "}"));
    pushButton_plot = new QPushButton(centralwidget);
    pushButton_plot->setObjectName(QString::fromUtf8("pushButton_plot"));
    pushButton_plot->setGeometry(QRect(550, 110, 130, 61));
    pushButton_plot->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "  background-color: rgb(120, 120, 120);\n"
                          "  color: rgb(255,151, 57); \n"
                          "}\n"
                          ""));
    label_5 = new QLabel(centralwidget);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(530, 200, 46, 41));
    pushButton_X = new QPushButton(centralwidget);
    pushButton_X->setObjectName(QString::fromUtf8("pushButton_X"));
    pushButton_X->setGeometry(QRect(390, 110, 61, 61));
    QFont font5;
    font5.setPointSize(16);
    font5.setBold(true);
    pushButton_X->setFont(font5);
    pushButton_X->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "  background-color: rgb(120, 120, 120);\n"
                          "  color: rgb(255,151, 57); \n"
                          "}\n"
                          ""));
    pushButton_CE = new QPushButton(centralwidget);
    pushButton_CE->setObjectName(QString::fromUtf8("pushButton_CE"));
    pushButton_CE->setGeometry(QRect(240, 110, 136, 61));
    pushButton_CE->setFont(font3);
    pushButton_CE->setStyleSheet(QString::fromUtf8(
        "QPushButton {\n"
        "  background-color: white;\n"
        "  color: rgb(255,151, 57); \n"
        "  border: 1px solid gray;\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
        "                                      stop: 0 #FF7832, stop: 1 "
        "#FF9739);\n"
        "}"));
    Xmin = new QLineEdit(centralwidget);
    Xmin->setObjectName(QString::fromUtf8("Xmin"));
    Xmin->setGeometry(QRect(600, 280, 80, 23));
    Xmin->setLayoutDirection(Qt::RightToLeft);
    Xmin->setStyleSheet(
        QString::fromUtf8("QLineEdit {\n"
                          "     border: 2px solid gray;\n"
                          "     border-radius: 10px;\n"
                          "     padding: 0 8px;\n"
                          "     background: gray;\n"
                          "     selection-background-color: darkgray;\n"
                          "color: white\n"
                          " }"));
    Xmin->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
    Ymin = new QLineEdit(centralwidget);
    Ymin->setObjectName(QString::fromUtf8("Ymin"));
    Ymin->setGeometry(QRect(600, 400, 80, 23));
    Ymin->setLayoutDirection(Qt::RightToLeft);
    Ymin->setStyleSheet(
        QString::fromUtf8("QLineEdit {\n"
                          "     border: 2px solid gray;\n"
                          "     border-radius: 10px;\n"
                          "     padding: 0 8px;\n"
                          "     background: gray;\n"
                          "     selection-background-color: darkgray;\n"
                          "color: white\n"
                          " }"));
    Ymin->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
    Xmax = new QLineEdit(centralwidget);
    Xmax->setObjectName(QString::fromUtf8("Xmax"));
    Xmax->setGeometry(QRect(600, 340, 80, 23));
    Xmax->setStyleSheet(
        QString::fromUtf8("QLineEdit {\n"
                          "     border: 2px solid gray;\n"
                          "     border-radius: 10px;\n"
                          "     padding: 0 8px;\n"
                          "     background: gray;\n"
                          "     selection-background-color: darkgray;\n"
                          "color: white\n"
                          " }"));
    Xmax->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
    Ymax = new QLineEdit(centralwidget);
    Ymax->setObjectName(QString::fromUtf8("Ymax"));
    Ymax->setGeometry(QRect(600, 460, 80, 23));
    Ymax->setStyleSheet(
        QString::fromUtf8("QLineEdit {\n"
                          "     border: 2px solid gray;\n"
                          "     border-radius: 10px;\n"
                          "     padding: 0 8px;\n"
                          "     background: gray;\n"
                          "     selection-background-color: darkgray;\n"
                          "color: white\n"
                          " }"));
    Ymax->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
    label_2 = new QLabel(centralwidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(530, 400, 64, 21));
    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(530, 280, 64, 21));
    label_4 = new QLabel(centralwidget);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(530, 460, 64, 21));
    label_3 = new QLabel(centralwidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(530, 340, 64, 21));
    x_value = new QLineEdit(centralwidget);
    x_value->setObjectName(QString::fromUtf8("x_value"));
    x_value->setGeometry(QRect(600, 200, 80, 41));
    x_value->setStyleSheet(
        QString::fromUtf8("QLineEdit {\n"
                          "     border: 2px solid gray;\n"
                          "     border-radius: 10px;\n"
                          "     padding: 0 8px;\n"
                          "     background: gray;\n"
                          "     selection-background-color: darkgray;\n"
                          "color: white\n"
                          " }"));
    x_value->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                          Qt::AlignVCenter);
    pushButton_creditCalc = new QPushButton(centralwidget);
    pushButton_creditCalc->setObjectName(
        QString::fromUtf8("pushButton_creditCalc"));
    pushButton_creditCalc->setGeometry(QRect(550, 30, 130, 61));
    pushButton_creditCalc->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "  background-color: rgb(120, 120, 120);\n"
                          "  color: rgb(255,151, 57); \n"
                          "}\n"
                          ""));
    MainWindow->setCentralWidget(centralwidget);
    menuBar = new QMenuBar(MainWindow);
    menuBar->setObjectName(QString::fromUtf8("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 687, 22));
    MainWindow->setMenuBar(menuBar);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  }  // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(
        QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    result_show->setText(QString());
    pushButton_seven->setText(
        QCoreApplication::translate("MainWindow", "7", nullptr));
    pushButton_eight->setText(
        QCoreApplication::translate("MainWindow", "8", nullptr));
    pushButton_nine->setText(
        QCoreApplication::translate("MainWindow", "9", nullptr));
    pushButton_mult->setText(
        QCoreApplication::translate("MainWindow", "*", nullptr));
    pushButton_four->setText(
        QCoreApplication::translate("MainWindow", "4", nullptr));
    pushButton_five->setText(
        QCoreApplication::translate("MainWindow", "5", nullptr));
    pushButton_six->setText(
        QCoreApplication::translate("MainWindow", "6", nullptr));
    pushButton_minus->setText(
        QCoreApplication::translate("MainWindow", "-", nullptr));
    pushButton_dot->setText(
        QCoreApplication::translate("MainWindow", ".", nullptr));
    pushButton_equal->setText(
        QCoreApplication::translate("MainWindow", "=", nullptr));
    pushButton_one->setText(
        QCoreApplication::translate("MainWindow", "1", nullptr));
    pushButton_plus->setText(
        QCoreApplication::translate("MainWindow", "+", nullptr));
    pushButton_two->setText(
        QCoreApplication::translate("MainWindow", "2", nullptr));
    pushButton_three->setText(
        QCoreApplication::translate("MainWindow", "3", nullptr));
    pushButton_zero->setText(
        QCoreApplication::translate("MainWindow", "0", nullptr));
    pushButton_openbracket->setText(
        QCoreApplication::translate("MainWindow", "(", nullptr));
    pushButton_clear->setText(
        QCoreApplication::translate("MainWindow", "AC", nullptr));
    pushButton_closebracket->setText(
        QCoreApplication::translate("MainWindow", ")", nullptr));
    pushButton_mod->setText(
        QCoreApplication::translate("MainWindow", "mod", nullptr));
    pushButton_ln->setText(
        QCoreApplication::translate("MainWindow", "ln", nullptr));
    pushButton_log->setText(
        QCoreApplication::translate("MainWindow", "log", nullptr));
    pushButton_tan->setText(
        QCoreApplication::translate("MainWindow", "tan", nullptr));
    pushButton_cos->setText(
        QCoreApplication::translate("MainWindow", "cos", nullptr));
    pushButton_sin->setText(
        QCoreApplication::translate("MainWindow", "sin", nullptr));
    pushButton_acos->setText(
        QCoreApplication::translate("MainWindow", "acos", nullptr));
    pushButton_atan->setText(
        QCoreApplication::translate("MainWindow", "atan", nullptr));
    pushButton_asin->setText(
        QCoreApplication::translate("MainWindow", "asin", nullptr));
    pushButton_sqrt->setText(
        QCoreApplication::translate("MainWindow", "sqrt", nullptr));
    pushButton_degree->setText(
        QCoreApplication::translate("MainWindow", "^", nullptr));
    pushButton_divide->setText(
        QCoreApplication::translate("MainWindow", "/", nullptr));
    pushButton_plot->setText(
        QCoreApplication::translate("MainWindow", "Graphic", nullptr));
    label_5->setText(
        QCoreApplication::translate("MainWindow", "      X = ", nullptr));
    pushButton_X->setText(
        QCoreApplication::translate("MainWindow", "x", nullptr));
    pushButton_CE->setText(
        QCoreApplication::translate("MainWindow", "CE", nullptr));
    Xmin->setText(QCoreApplication::translate("MainWindow", "-10", nullptr));
    Ymin->setText(QCoreApplication::translate("MainWindow", "-10", nullptr));
    Xmax->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
    Ymax->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
    label_2->setText(
        QCoreApplication::translate("MainWindow", "     Ymin =", nullptr));
    label->setText(
        QCoreApplication::translate("MainWindow", "     Xmin =", nullptr));
    label_4->setText(
        QCoreApplication::translate("MainWindow", "    Ymax =", nullptr));
    label_3->setText(
        QCoreApplication::translate("MainWindow", "    Xmax =", nullptr));
    x_value->setText(
        QCoreApplication::translate("MainWindow", "          0", nullptr));
    pushButton_creditCalc->setText(
        QCoreApplication::translate("MainWindow", "Credit calc", nullptr));
  }  // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // CPP3_SMART_CALC_V20_UI_MAINWINDOW_H
