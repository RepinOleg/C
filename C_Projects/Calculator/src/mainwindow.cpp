#include "mainwindow.h"

#include <QLabel>
#include <QPixmap>
#include <QString>

#include "./ui_mainwindow.h"

extern "C" {
#include "s21_smart_calc.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setlocale(LC_NUMERIC, "C");

  windowPlot = new Plot(this);
  windowCredit = new creditCalc(this);
  connect(ui->pushButton_zero, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui->pushButton_one, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui->pushButton_two, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui->pushButton_three, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui->pushButton_four, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui->pushButton_five, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui->pushButton_six, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui->pushButton_seven, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui->pushButton_eight, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui->pushButton_nine, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));

  connect(ui->pushButton_X, SIGNAL(clicked()), this, SLOT(s21_operations()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(s21_operations()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(s21_operations()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(s21_operations()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(s21_operations()));
  connect(ui->pushButton_closebracket, SIGNAL(clicked()), this,
          SLOT(s21_operations()));
  connect(ui->pushButton_openbracket, SIGNAL(clicked()), this,
          SLOT(s21_operations()));
  connect(ui->pushButton_degree, SIGNAL(clicked()), this,
          SLOT(s21_operations()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(s21_operations()));
  connect(ui->pushButton_divide, SIGNAL(clicked()), this,
          SLOT(s21_operations()));

  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(s21_functions()));

  connect(ui->pushButton_clear, SIGNAL(clicked()), this, SLOT(s21_deleteAll()));
  connect(ui->pushButton_CE, SIGNAL(clicked()), this, SLOT(s21_deleteChar()));

  connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(s21_equal()));
  connect(ui->pushButton_plot, SIGNAL(clicked()), this, SLOT(s21_graph()));
  connect(ui->pushButton_creditCalc, SIGNAL(clicked()), this,
          SLOT(s21_credit_calc()));
}

MainWindow::~MainWindow() { delete ui; }
void MainWindow::s21_deleteAll() {
  QString newLabel;
  ui->result_show->setText(newLabel);
}

void MainWindow::s21_deleteChar() {
  QString new_label = ui->result_show->text();
  new_label.resize(new_label.size() - 1);
  ui->result_show->setText(new_label);
}
void MainWindow::s21_digit_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label = ui->result_show->text() + button->text();
  ui->result_show->setText(new_label);
}

void MainWindow::s21_operations() {
  QPushButton *button = (QPushButton *)sender();

  QString new_label;
  new_label = ui->result_show->text();
  if (!(ui->result_show->text().endsWith("+")) &&
      !(ui->result_show->text().endsWith("-")) &&
      !(ui->result_show->text().endsWith("*")) &&
      !(ui->result_show->text().endsWith("/")) &&
      !(ui->result_show->text().endsWith("^")) &&
      !(ui->result_show->text().endsWith(".")) &&
      !(ui->result_show->text().endsWith("%"))) {
    if (button->text() == "+") {
      new_label += "+";
    } else if (button->text() == "-") {
      new_label += "-";
    }
    if (!ui->result_show->text().isEmpty()) {
      if (button->text() == "*") {
        new_label += "*";
      } else if (button->text() == "/") {
        new_label += "/";
      } else if (button->text() == "^") {
        new_label += "^";
      } else if (button->text() == "mod") {
        new_label += "%";
      } else if (button->text() == "/") {
        new_label += "/";
      } else if (button->text() == ".") {
        new_label += ".";
      }
    }
  }
  if (button->text() == "(") {
    new_label += "(";
  } else if (button->text() == ")" &&
             (!(ui->result_show->text().endsWith("(")))) {
    new_label += ")";
  } else if (button->text() == "x") {
    new_label += "x";
  }
  ui->result_show->setText(new_label);
}

void MainWindow::s21_functions() {
  QPushButton *button = (QPushButton *)sender();

  QString new_label = ui->result_show->text();
  new_label += button->text();
  new_label += "(";
  ui->result_show->setText(new_label);
}

void MainWindow::s21_graph() {
  QString label = ui->result_show->text();
  QByteArray arr = label.toLocal8Bit();
  char *str = arr.data();
  double xMin = ui->Xmin->text().toDouble();
  double xMax = ui->Xmax->text().toDouble();
  double yMin = ui->Ymin->text().toDouble();
  double yMax = ui->Ymax->text().toDouble();
  double million = 1000000;
  if (xMax > million || yMax > million || yMin < -million || xMin < -million) {
    ui->result_show->setText("Invalid input");
  } else if (xMin > xMax || yMin > yMax) {
    ui->result_show->setText("Invalid input");
  } else {
    windowPlot->PlotGraph(str, xMax, xMin, yMax, yMin);
    windowPlot->setWindowTitle("Graph");
    windowPlot->show();
  }
}

void MainWindow::s21_credit_calc() {
  windowCredit->setWindowTitle("Credit calculator");
  windowCredit->show();
}

void MainWindow::s21_equal() {
  QString label = ui->result_show->text();
  QByteArray arr = label.toLocal8Bit();
  char *str = arr.data();
  double result;
  if (strlen(str) > 1 && strlen(str) <= 255) {
    double x_value = ui->x_value->text().toDouble();
    if (!s21_smart_calc(str, &result, x_value)) {
      QString res = QString::number(result, 'g', 11);
      ui->result_show->setText(res);
    } else {
      ui->result_show->setText("Invalid input");
    }
  } else {
    ui->result_show->setText("Invalid input");
  }
}
