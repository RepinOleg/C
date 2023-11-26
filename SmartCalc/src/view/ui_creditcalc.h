/********************************************************************************
** Form generated from reading UI file 'Creditcalc.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CPP3_SMART_CALC_V20_UI_CREDITCALC_H
#define CPP3_SMART_CALC_V20_UI_CREDITCALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_CreditCalc {
 public:
  QLabel *label_2;
  QLineEdit *bid_value;
  QLabel *label_3;
  QComboBox *term;
  QPushButton *calculate;
  QLabel *label_4;
  QLabel *label_5;
  QLabel *monthly_payment;
  QLabel *label_7;
  QLabel *overpayment;
  QLabel *label_9;
  QLabel *total_amount;
  QRadioButton *radioButton_Annuin;
  QRadioButton *radioButton_diff;
  QLabel *label;
  QLineEdit *sum_value;

  void setupUi(QDialog *CreditCalc) {
    if (CreditCalc->objectName().isEmpty())
      CreditCalc->setObjectName(QString::fromUtf8("CreditCalc"));
    CreditCalc->resize(403, 534);
    CreditCalc->setStyleSheet(
        QString::fromUtf8("background-color: rgb(105, 105, 105);"));
    label_2 = new QLabel(CreditCalc);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(240, 140, 68, 17));
    label_2->setAlignment(Qt::AlignLeading | Qt::AlignLeft | Qt::AlignVCenter);
    bid_value = new QLineEdit(CreditCalc);
    bid_value->setObjectName(QString::fromUtf8("bid_value"));
    bid_value->setGeometry(QRect(240, 164, 141, 37));
    QFont font;
    font.setPointSize(14);
    bid_value->setFont(font);
    bid_value->setStyleSheet(
        QString::fromUtf8("color: rgb(255, 255, 255);\n"
                          "background-color: rgb(154, 153, 150);"));
    bid_value->setAlignment(Qt::AlignLeading | Qt::AlignLeft |
                            Qt::AlignVCenter);
    label_3 = new QLabel(CreditCalc);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(30, 140, 36, 17));
    term = new QComboBox(CreditCalc);
    term->addItem(QString());
    term->addItem(QString());
    term->addItem(QString());
    term->addItem(QString());
    term->addItem(QString());
    term->addItem(QString());
    term->addItem(QString());
    term->addItem(QString());
    term->addItem(QString());
    term->addItem(QString());
    term->addItem(QString());
    term->addItem(QString());
    term->addItem(QString());
    term->addItem(QString());
    term->addItem(QString());
    term->addItem(QString());
    term->addItem(QString());
    term->addItem(QString());
    term->setObjectName(QString::fromUtf8("term"));
    term->setGeometry(QRect(30, 167, 121, 30));
    term->setFont(font);
    term->setStyleSheet(
        QString::fromUtf8("background-color: rgb(154, 153, 150);"));
    calculate = new QPushButton(CreditCalc);
    calculate->setObjectName(QString::fromUtf8("calculate"));
    calculate->setGeometry(QRect(30, 280, 351, 25));
    calculate->setStyleSheet(
        QString::fromUtf8("color: rgb(255, 255, 255);\n"
                          "background-color: rgb(154, 153, 150);"));
    label_4 = new QLabel(CreditCalc);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(40, 340, 181, 41));
    QFont font1;
    font1.setPointSize(12);
    font1.setBold(true);
    label_4->setFont(font1);
    label_5 = new QLabel(CreditCalc);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(40, 390, 161, 41));
    QFont font2;
    font2.setPointSize(11);
    label_5->setFont(font2);
    monthly_payment = new QLabel(CreditCalc);
    monthly_payment->setObjectName(QString::fromUtf8("monthly_payment"));
    monthly_payment->setGeometry(QRect(210, 400, 171, 20));
    monthly_payment->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                                  Qt::AlignVCenter);
    label_7 = new QLabel(CreditCalc);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setGeometry(QRect(40, 440, 161, 41));
    overpayment = new QLabel(CreditCalc);
    overpayment->setObjectName(QString::fromUtf8("overpayment"));
    overpayment->setGeometry(QRect(210, 450, 171, 20));
    overpayment->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                              Qt::AlignVCenter);
    label_9 = new QLabel(CreditCalc);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    label_9->setGeometry(QRect(40, 490, 161, 41));
    total_amount = new QLabel(CreditCalc);
    total_amount->setObjectName(QString::fromUtf8("total_amount"));
    total_amount->setGeometry(QRect(210, 500, 171, 20));
    total_amount->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                               Qt::AlignVCenter);
    radioButton_Annuin = new QRadioButton(CreditCalc);
    radioButton_Annuin->setObjectName(QString::fromUtf8("radioButton_Annuin"));
    radioButton_Annuin->setGeometry(QRect(30, 230, 112, 23));
    radioButton_diff = new QRadioButton(CreditCalc);
    radioButton_diff->setObjectName(QString::fromUtf8("radioButton_diff"));
    radioButton_diff->setGeometry(QRect(201, 230, 191, 23));
    label = new QLabel(CreditCalc);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(30, 30, 141, 21));
    label->setAlignment(Qt::AlignLeading | Qt::AlignLeft | Qt::AlignVCenter);
    sum_value = new QLineEdit(CreditCalc);
    sum_value->setObjectName(QString::fromUtf8("sum_value"));
    sum_value->setGeometry(QRect(30, 65, 351, 51));
    sum_value->setFont(font);
    sum_value->setStyleSheet(
        QString::fromUtf8("color: rgb(255, 255, 255);\n"
                          "background-color: rgb(154, 153, 150);"));
    sum_value->setAlignment(Qt::AlignLeading | Qt::AlignLeft |
                            Qt::AlignVCenter);

    retranslateUi(CreditCalc);

    QMetaObject::connectSlotsByName(CreditCalc);
  }  // setupUi

  void retranslateUi(QDialog *CreditCalc) {
    CreditCalc->setWindowTitle(
        QCoreApplication::translate("CreditCalc", "Dialog", nullptr));
    label_2->setText(QCoreApplication::translate(
        "CreditCalc", "\320\241\321\202\320\260\320\262\320\272\320\260, %",
        nullptr));
    bid_value->setText(
        QCoreApplication::translate("CreditCalc", "10", nullptr));
    label_3->setText(QCoreApplication::translate(
        "CreditCalc", "\320\241\321\200\320\276\320\272", nullptr));
    term->setItemText(
        0, QCoreApplication::translate(
               "CreditCalc", "1 \320\274\320\265\321\201\321\217\321\206",
               nullptr));
    term->setItemText(
        1, QCoreApplication::translate(
               "CreditCalc",
               "3 \320\274\320\265\321\201\321\217\321\206\320\260", nullptr));
    term->setItemText(
        2, QCoreApplication::translate(
               "CreditCalc",
               "6 \320\274\320\265\321\201\321\217\321\206\320\265\320\262",
               nullptr));
    term->setItemText(
        3, QCoreApplication::translate(
               "CreditCalc",
               "9 \320\274\320\265\321\201\321\217\321\206\320\265\320\262",
               nullptr));
    term->setItemText(
        4, QCoreApplication::translate("CreditCalc",
                                       "1 \320\263\320\276\320\264", nullptr));
    term->setItemText(
        5, QCoreApplication::translate(
               "CreditCalc", "1,5 \320\263\320\276\320\264\320\260", nullptr));
    term->setItemText(
        6, QCoreApplication::translate(
               "CreditCalc", "2 \320\263\320\276\320\264\320\260", nullptr));
    term->setItemText(
        7, QCoreApplication::translate(
               "CreditCalc", "3 \320\263\320\276\320\264\320\260", nullptr));
    term->setItemText(
        8, QCoreApplication::translate(
               "CreditCalc", "4 \320\263\320\276\320\264\320\260", nullptr));
    term->setItemText(
        9, QCoreApplication::translate("CreditCalc",
                                       "5 \320\273\320\265\321\202", nullptr));
    term->setItemText(
        10, QCoreApplication::translate("CreditCalc",
                                        "6 \320\273\320\265\321\202", nullptr));
    term->setItemText(
        11, QCoreApplication::translate("CreditCalc",
                                        "7 \320\273\320\265\321\202", nullptr));
    term->setItemText(
        12, QCoreApplication::translate(
                "CreditCalc", "10 \320\273\320\265\321\202", nullptr));
    term->setItemText(
        13, QCoreApplication::translate(
                "CreditCalc", "15 \320\273\320\265\321\202", nullptr));
    term->setItemText(
        14, QCoreApplication::translate(
                "CreditCalc", "20 \320\273\320\265\321\202", nullptr));
    term->setItemText(
        15, QCoreApplication::translate(
                "CreditCalc", "25 \320\273\320\265\321\202", nullptr));
    term->setItemText(
        16, QCoreApplication::translate(
                "CreditCalc", "30 \320\273\320\265\321\202", nullptr));
    term->setItemText(
        17, QCoreApplication::translate(
                "CreditCalc", "50 \320\273\320\265\321\202", nullptr));

    calculate->setText(
        QCoreApplication::translate("CreditCalc",
                                    "\320\240\320\260\321\201\321\201\321\207"
                                    "\320\270\321\202\320\260\321\202\321\214",
                                    nullptr));
    label_4->setText(QCoreApplication::translate(
        "CreditCalc",
        "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321"
        "\202\321\213 "
        "\321\200\320\260\321\201\321\207\320\265\321\202\320\260:",
        nullptr));
    label_5->setText(QCoreApplication::translate(
        "CreditCalc",
        "\320\225\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320"
        "\275\321\213\320\271 \320\277\320\273\320\260\321\202\320\265\320\266",
        nullptr));
    monthly_payment->setText(
        QCoreApplication::translate("CreditCalc", "0", nullptr));
    label_7->setText(QCoreApplication::translate(
        "CreditCalc",
        "\320\237\320\265\321\200\320\265\320\277\320\273\320\260\321\202\320"
        "\260 \320\277\320\276 "
        "\320\272\321\200\320\265\320\264\320\270\321\202\321\203",
        nullptr));
    overpayment->setText(
        QCoreApplication::translate("CreditCalc", "0", nullptr));
    label_9->setText(QCoreApplication::translate(
        "CreditCalc",
        "\320\236\320\261\321\211\320\260\321\217 "
        "\320\262\321\213\320\277\320\273\320\260\321\202\320\260",
        nullptr));
    total_amount->setText(
        QCoreApplication::translate("CreditCalc", "0", nullptr));
    radioButton_Annuin->setText(QCoreApplication::translate(
        "CreditCalc",
        "\320\260\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320"
        "\275\321\213\320\271",
        nullptr));
    radioButton_diff->setText(QCoreApplication::translate(
        "CreditCalc",
        "\320\264\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321"
        "\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213"
        "\320\271",
        nullptr));
    label->setText(QCoreApplication::translate(
        "CreditCalc",
        "\320\241\321\203\320\274\320\274\320\260 "
        "\320\272\321\200\320\265\320\264\320\270\321\202\320\260",
        nullptr));
    sum_value->setText(
        QCoreApplication::translate("CreditCalc", "100000", nullptr));
  }  // retranslateUi
};

namespace Ui {
class CreditCalc : public Ui_CreditCalc {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // CPP3_SMART_CALC_V20_UI_CREDITCALC_H
