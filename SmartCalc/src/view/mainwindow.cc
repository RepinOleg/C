#include "mainwindow.h"

#include <QLabel>
#include <QPixmap>
#include <QString>

#include "./ui_mainwindow.h"
MainWindow::MainWindow(s21::Controller *c, QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow), control_(c) {
  ui_->setupUi(this);
  setlocale(LC_NUMERIC, "C");
  windowPlot_ = new Plot(control_);
  windowCredit_ = new CreditCalc(control_);

  connect(ui_->pushButton_zero, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui_->pushButton_one, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui_->pushButton_two, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui_->pushButton_three, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui_->pushButton_four, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui_->pushButton_five, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui_->pushButton_six, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui_->pushButton_seven, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui_->pushButton_eight, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));
  connect(ui_->pushButton_nine, SIGNAL(clicked()), this,
          SLOT(s21_digit_numbers()));

  connect(ui_->pushButton_X, SIGNAL(clicked()), this, SLOT(s21_operations()));
  connect(ui_->pushButton_plus, SIGNAL(clicked()), this,
          SLOT(s21_operations()));
  connect(ui_->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(s21_operations()));
  connect(ui_->pushButton_mult, SIGNAL(clicked()), this,
          SLOT(s21_operations()));
  connect(ui_->pushButton_mod, SIGNAL(clicked()), this, SLOT(s21_operations()));
  connect(ui_->pushButton_closebracket, SIGNAL(clicked()), this,
          SLOT(s21_operations()));
  connect(ui_->pushButton_openbracket, SIGNAL(clicked()), this,
          SLOT(s21_operations()));
  connect(ui_->pushButton_degree, SIGNAL(clicked()), this,
          SLOT(s21_operations()));
  connect(ui_->pushButton_dot, SIGNAL(clicked()), this, SLOT(s21_operations()));
  connect(ui_->pushButton_divide, SIGNAL(clicked()), this,
          SLOT(s21_operations()));

  connect(ui_->pushButton_sin, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui_->pushButton_cos, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui_->pushButton_asin, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui_->pushButton_atan, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui_->pushButton_tan, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui_->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui_->pushButton_log, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui_->pushButton_ln, SIGNAL(clicked()), this, SLOT(s21_functions()));
  connect(ui_->pushButton_acos, SIGNAL(clicked()), this, SLOT(s21_functions()));

  connect(ui_->pushButton_clear, SIGNAL(clicked()), this,
          SLOT(s21_deleteAll()));
  connect(ui_->pushButton_CE, SIGNAL(clicked()), this, SLOT(s21_deleteChar()));

  connect(ui_->pushButton_equal, SIGNAL(clicked()), this, SLOT(s21_equal()));
  connect(ui_->pushButton_plot, SIGNAL(clicked()), this, SLOT(s21_graph()));
  connect(ui_->pushButton_creditCalc, SIGNAL(clicked()), this,
          SLOT(s21_credit_calc()));
}

MainWindow::~MainWindow() { delete ui_; }

void MainWindow::s21_deleteAll() {
  QString newLabel;
  ui_->result_show->setText(newLabel);
}

void MainWindow::s21_deleteChar() {
  QString new_label = ui_->result_show->text();
  new_label.resize(new_label.size() - 1);
  ui_->result_show->setText(new_label);
}
void MainWindow::s21_digit_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label = ui_->result_show->text() + button->text();
  ui_->result_show->setText(new_label);
}

void MainWindow::s21_operations() {
  QPushButton *button = (QPushButton *)sender();

  QString new_label;
  new_label = ui_->result_show->text();
  if (!(ui_->result_show->text().endsWith("+")) &&
      !(ui_->result_show->text().endsWith("-")) &&
      !(ui_->result_show->text().endsWith("*")) &&
      !(ui_->result_show->text().endsWith("/")) &&
      !(ui_->result_show->text().endsWith("^")) &&
      !(ui_->result_show->text().endsWith(".")) &&
      !(ui_->result_show->text().endsWith("%"))) {
    if (button->text() == "+") {
      new_label += "+";
    } else if (button->text() == "-") {
      new_label += "-";
    }
    if (!ui_->result_show->text().isEmpty()) {
      if (button->text() == "*") {
        new_label += "*";
      } else if (button->text() == "/") {
        new_label += "/";
      } else if (button->text() == "^") {
        new_label += "^";
      } else if (button->text() == "mod") {
        new_label += "mod";
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
             (!(ui_->result_show->text().endsWith("(")))) {
    new_label += ")";
  } else if (button->text() == "x") {
    new_label += "x";
  }
  ui_->result_show->setText(new_label);
}

void MainWindow::s21_functions() {
  QPushButton *button = (QPushButton *)sender();

  QString new_label = ui_->result_show->text();
  new_label += button->text();
  new_label += "(";
  ui_->result_show->setText(new_label);
}

void MainWindow::s21_graph() {
  QString label = ui_->result_show->text();
  QByteArray arr = label.toLocal8Bit();
  char *str = arr.data();
  double xMin = ui_->Xmin->text().toDouble();
  double xMax = ui_->Xmax->text().toDouble();
  double yMin = ui_->Ymin->text().toDouble();
  double yMax = ui_->Ymax->text().toDouble();
  double million = 1000000;
  if (xMax > million || yMax > million || yMin < -million || xMin < -million) {
    ui_->result_show->setText("Invalid input");
  } else if (xMin > xMax || yMin > yMax) {
    ui_->result_show->setText("Invalid input");
  } else {
    windowPlot_->PlotGraph(str, xMax, xMin, yMax, yMin);
    windowPlot_->setWindowTitle("Graph");
    windowPlot_->show();
  }
}

void MainWindow::s21_credit_calc() {
  windowCredit_->setWindowTitle("Credit calculator");
  windowCredit_->show();
}

void MainWindow::s21_equal() {
  QString label = ui_->result_show->text();
  std::string str = label.toStdString();

  double x_value = ui_->x_value->text().toDouble();
  if (control_->Validation(str)) {
    double result = control_->Calculation(str, x_value);
    QString res = QString::number(result, 'g', 11);
    ui_->result_show->setText(res);
  } else {
    ui_->result_show->setText("Invalid input");
  }
}
