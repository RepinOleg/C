/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

#include "Headers/ModelViewerWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QWidget *centralwidget;
  QLabel *label;
  QLabel *label_2;
  QLabel *label_3;
  QLabel *FileName;
  QLabel *Amount_vertices;
  QLabel *Amount_edges;
  QPushButton *button_findFile;
  QPushButton *button_GIF;
  QPushButton *button_Screen;
  QLabel *label_6;
  QSlider *xMove;
  QSlider *yMove;
  QSlider *zMove;
  QLabel *label_7;
  QLabel *label_8;
  QLabel *label_9;
  QLabel *label_10;
  QLabel *label_11;
  QLabel *label_12;
  QSlider *xRotate;
  QSlider *yRotate;
  QSlider *zRotate;
  QSlider *scaling;
  QComboBox *projection;
  QLabel *label_4;
  QLabel *label_5;
  QComboBox *TypeEdges;
  QLabel *label_14;
  QComboBox *DisplayMetod;
  ModelViewerWidget *widget_modelViewer;
  QSlider *DepthEdges;
  QLabel *label_15;
  QPushButton *BackColor;
  QLabel *label_16;
  QPushButton *EdgesColor;
  QFrame *line;
  QFrame *line_2;
  QFrame *line_3;
  QFrame *line_4;
  QFrame *line_5;
  QFrame *line_6;
  QFrame *line_7;
  QFrame *line_8;
  QFrame *line_9;
  QFrame *line_10;
  QFrame *line_11;
  QFrame *line_12;
  QFrame *line_13;
  QFrame *line_14;
  QPushButton *VertexColor;
  QSlider *VertexDepth;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(1400, 800);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(1015, 5, 100, 25));
    QFont font;
    font.setPointSize(14);
    label->setFont(font);
    label_2 = new QLabel(centralwidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(1015, 40, 150, 25));
    QFont font1;
    font1.setPointSize(13);
    label_2->setFont(font1);
    label_3 = new QLabel(centralwidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(1015, 75, 150, 25));
    label_3->setFont(font1);
    FileName = new QLabel(centralwidget);
    FileName->setObjectName(QString::fromUtf8("FileName"));
    FileName->setGeometry(QRect(1180, 5, 200, 25));
    QFont font2;
    font2.setPointSize(15);
    FileName->setFont(font2);
    FileName->setAlignment(Qt::AlignCenter);
    Amount_vertices = new QLabel(centralwidget);
    Amount_vertices->setObjectName(QString::fromUtf8("Amount_vertices"));
    Amount_vertices->setGeometry(QRect(1180, 40, 200, 25));
    Amount_vertices->setFont(font);
    Amount_vertices->setAlignment(Qt::AlignCenter);
    Amount_edges = new QLabel(centralwidget);
    Amount_edges->setObjectName(QString::fromUtf8("Amount_edges"));
    Amount_edges->setGeometry(QRect(1180, 75, 200, 25));
    Amount_edges->setFont(font);
    Amount_edges->setAlignment(Qt::AlignCenter);
    button_findFile = new QPushButton(centralwidget);
    button_findFile->setObjectName(QString::fromUtf8("button_findFile"));
    button_findFile->setGeometry(QRect(1010, 120, 380, 35));
    button_GIF = new QPushButton(centralwidget);
    button_GIF->setObjectName(QString::fromUtf8("button_GIF"));
    button_GIF->setGeometry(QRect(1010, 155, 190, 25));
    button_Screen = new QPushButton(centralwidget);
    button_Screen->setObjectName(QString::fromUtf8("button_Screen"));
    button_Screen->setGeometry(QRect(1200, 155, 190, 25));
    label_6 = new QLabel(centralwidget);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setGeometry(QRect(1010, 492, 67, 17));
    xMove = new QSlider(centralwidget);
    xMove->setObjectName(QString::fromUtf8("xMove"));
    xMove->setGeometry(QRect(1030, 274, 360, 16));
    xMove->setMinimum(-10);
    xMove->setMaximum(10);
    xMove->setPageStep(10);
    xMove->setOrientation(Qt::Horizontal);
    yMove = new QSlider(centralwidget);
    yMove->setObjectName(QString::fromUtf8("yMove"));
    yMove->setGeometry(QRect(1030, 304, 360, 16));
    yMove->setMinimum(-10);
    yMove->setMaximum(10);
    yMove->setOrientation(Qt::Horizontal);
    zMove = new QSlider(centralwidget);
    zMove->setObjectName(QString::fromUtf8("zMove"));
    zMove->setGeometry(QRect(1030, 334, 360, 16));
    zMove->setMinimum(-10);
    zMove->setMaximum(10);
    zMove->setOrientation(Qt::Horizontal);
    label_7 = new QLabel(centralwidget);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setGeometry(QRect(1015, 273, 16, 17));
    label_8 = new QLabel(centralwidget);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    label_8->setGeometry(QRect(1015, 303, 16, 17));
    label_9 = new QLabel(centralwidget);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    label_9->setGeometry(QRect(1015, 333, 16, 17));
    label_10 = new QLabel(centralwidget);
    label_10->setObjectName(QString::fromUtf8("label_10"));
    label_10->setGeometry(QRect(1010, 381, 20, 17));
    label_11 = new QLabel(centralwidget);
    label_11->setObjectName(QString::fromUtf8("label_11"));
    label_11->setGeometry(QRect(1010, 411, 20, 17));
    label_12 = new QLabel(centralwidget);
    label_12->setObjectName(QString::fromUtf8("label_12"));
    label_12->setGeometry(QRect(1010, 441, 18, 17));
    xRotate = new QSlider(centralwidget);
    xRotate->setObjectName(QString::fromUtf8("xRotate"));
    xRotate->setGeometry(QRect(1030, 382, 360, 16));
    xRotate->setMinimum(-100);
    xRotate->setMaximum(100);
    xRotate->setOrientation(Qt::Horizontal);
    yRotate = new QSlider(centralwidget);
    yRotate->setObjectName(QString::fromUtf8("yRotate"));
    yRotate->setGeometry(QRect(1030, 412, 360, 16));
    yRotate->setMinimum(-100);
    yRotate->setMaximum(100);
    yRotate->setOrientation(Qt::Horizontal);
    zRotate = new QSlider(centralwidget);
    zRotate->setObjectName(QString::fromUtf8("zRotate"));
    zRotate->setGeometry(QRect(1030, 442, 360, 16));
    zRotate->setMinimum(-100);
    zRotate->setMaximum(100);
    zRotate->setOrientation(Qt::Horizontal);
    scaling = new QSlider(centralwidget);
    scaling->setObjectName(QString::fromUtf8("scaling"));
    scaling->setGeometry(QRect(1010, 512, 380, 16));
    scaling->setMinimum(-100);
    scaling->setMaximum(100);
    scaling->setOrientation(Qt::Horizontal);
    projection = new QComboBox(centralwidget);
    projection->addItem(QString());
    projection->addItem(QString());
    projection->setObjectName(QString::fromUtf8("projection"));
    projection->setGeometry(QRect(1214, 211, 82, 25));
    label_4 = new QLabel(centralwidget);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(1130, 215, 71, 17));
    label_5 = new QLabel(centralwidget);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(1016, 578, 61, 17));
    QFont font3;
    font3.setPointSize(12);
    label_5->setFont(font3);
    TypeEdges = new QComboBox(centralwidget);
    TypeEdges->addItem(QString());
    TypeEdges->addItem(QString());
    TypeEdges->addItem(QString());
    TypeEdges->setObjectName(QString::fromUtf8("TypeEdges"));
    TypeEdges->setGeometry(QRect(1300, 576, 79, 25));
    TypeEdges->setLayoutDirection(Qt::RightToLeft);
    label_14 = new QLabel(centralwidget);
    label_14->setObjectName(QString::fromUtf8("label_14"));
    label_14->setGeometry(QRect(1015, 666, 161, 17));
    DisplayMetod = new QComboBox(centralwidget);
    DisplayMetod->addItem(QString());
    DisplayMetod->addItem(QString());
    DisplayMetod->addItem(QString());
    DisplayMetod->setObjectName(QString::fromUtf8("DisplayMetod"));
    DisplayMetod->setGeometry(QRect(1300, 666, 80, 25));
    DisplayMetod->setLayoutDirection(Qt::RightToLeft);
    widget_modelViewer = new ModelViewerWidget(centralwidget);
    widget_modelViewer->setObjectName(QString::fromUtf8("widget_modelViewer"));
    widget_modelViewer->setGeometry(QRect(10, 0, 975, 800));
    DepthEdges = new QSlider(centralwidget);
    DepthEdges->setObjectName(QString::fromUtf8("DepthEdges"));
    DepthEdges->setGeometry(QRect(1010, 605, 231, 16));
    DepthEdges->setMinimum(1);
    DepthEdges->setMaximum(7);
    DepthEdges->setOrientation(Qt::Horizontal);
    label_15 = new QLabel(centralwidget);
    label_15->setObjectName(QString::fromUtf8("label_15"));
    label_15->setGeometry(QRect(1011, 753, 119, 17));
    BackColor = new QPushButton(centralwidget);
    BackColor->setObjectName(QString::fromUtf8("BackColor"));
    BackColor->setGeometry(QRect(1300, 753, 80, 25));
    label_16 = new QLabel(centralwidget);
    label_16->setObjectName(QString::fromUtf8("label_16"));
    label_16->setGeometry(QRect(1030, 802, 93, 17));
    EdgesColor = new QPushButton(centralwidget);
    EdgesColor->setObjectName(QString::fromUtf8("EdgesColor"));
    EdgesColor->setGeometry(QRect(1300, 606, 80, 25));
    EdgesColor->setLayoutDirection(Qt::RightToLeft);
    line = new QFrame(centralwidget);
    line->setObjectName(QString::fromUtf8("line"));
    line->setGeometry(QRect(1010, 472, 371, 16));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    line_2 = new QFrame(centralwidget);
    line_2->setObjectName(QString::fromUtf8("line_2"));
    line_2->setGeometry(QRect(1010, 362, 371, 16));
    line_2->setFrameShape(QFrame::HLine);
    line_2->setFrameShadow(QFrame::Sunken);
    line_3 = new QFrame(centralwidget);
    line_3->setObjectName(QString::fromUtf8("line_3"));
    line_3->setGeometry(QRect(990, 570, 20, 68));
    line_3->setFrameShape(QFrame::VLine);
    line_3->setFrameShadow(QFrame::Sunken);
    line_4 = new QFrame(centralwidget);
    line_4->setObjectName(QString::fromUtf8("line_4"));
    line_4->setGeometry(QRect(1000, 560, 391, 20));
    line_4->setFrameShape(QFrame::HLine);
    line_4->setFrameShadow(QFrame::Sunken);
    line_5 = new QFrame(centralwidget);
    line_5->setObjectName(QString::fromUtf8("line_5"));
    line_5->setGeometry(QRect(1000, 630, 391, 20));
    line_5->setFrameShape(QFrame::HLine);
    line_5->setFrameShadow(QFrame::Sunken);
    line_6 = new QFrame(centralwidget);
    line_6->setObjectName(QString::fromUtf8("line_6"));
    line_6->setGeometry(QRect(1380, 570, 20, 68));
    line_6->setFrameShape(QFrame::VLine);
    line_6->setFrameShadow(QFrame::Sunken);
    line_7 = new QFrame(centralwidget);
    line_7->setObjectName(QString::fromUtf8("line_7"));
    line_7->setGeometry(QRect(1010, 190, 380, 20));
    line_7->setFrameShape(QFrame::HLine);
    line_7->setFrameShadow(QFrame::Sunken);
    line_8 = new QFrame(centralwidget);
    line_8->setObjectName(QString::fromUtf8("line_8"));
    line_8->setGeometry(QRect(1380, 200, 20, 45));
    line_8->setFrameShape(QFrame::VLine);
    line_8->setFrameShadow(QFrame::Sunken);
    line_9 = new QFrame(centralwidget);
    line_9->setObjectName(QString::fromUtf8("line_9"));
    line_9->setGeometry(QRect(1010, 236, 380, 20));
    line_9->setFrameShape(QFrame::HLine);
    line_9->setFrameShadow(QFrame::Sunken);
    line_10 = new QFrame(centralwidget);
    line_10->setObjectName(QString::fromUtf8("line_10"));
    line_10->setGeometry(QRect(1000, 200, 20, 45));
    line_10->setFrameShape(QFrame::VLine);
    line_10->setFrameShadow(QFrame::Sunken);
    line_11 = new QFrame(centralwidget);
    line_11->setObjectName(QString::fromUtf8("line_11"));
    line_11->setGeometry(QRect(1000, 720, 391, 20));
    line_11->setFrameShape(QFrame::HLine);
    line_11->setFrameShadow(QFrame::Sunken);
    line_12 = new QFrame(centralwidget);
    line_12->setObjectName(QString::fromUtf8("line_12"));
    line_12->setGeometry(QRect(1380, 660, 20, 68));
    line_12->setFrameShape(QFrame::VLine);
    line_12->setFrameShadow(QFrame::Sunken);
    line_13 = new QFrame(centralwidget);
    line_13->setObjectName(QString::fromUtf8("line_13"));
    line_13->setGeometry(QRect(990, 660, 20, 68));
    line_13->setFrameShape(QFrame::VLine);
    line_13->setFrameShadow(QFrame::Sunken);
    line_14 = new QFrame(centralwidget);
    line_14->setObjectName(QString::fromUtf8("line_14"));
    line_14->setGeometry(QRect(1000, 650, 391, 20));
    line_14->setFrameShape(QFrame::HLine);
    line_14->setFrameShadow(QFrame::Sunken);
    VertexColor = new QPushButton(centralwidget);
    VertexColor->setObjectName(QString::fromUtf8("VertexColor"));
    VertexColor->setGeometry(QRect(1300, 696, 80, 25));
    VertexColor->setLayoutDirection(Qt::RightToLeft);
    VertexDepth = new QSlider(centralwidget);
    VertexDepth->setObjectName(QString::fromUtf8("VertexDepth"));
    VertexDepth->setGeometry(QRect(1010, 700, 231, 16));
    VertexDepth->setMinimum(1);
    VertexDepth->setMaximum(7);
    VertexDepth->setOrientation(Qt::Horizontal);
    MainWindow->setCentralWidget(centralwidget);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  }  // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(
        QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    label->setText(
        QCoreApplication::translate("MainWindow", "File name:", nullptr));
    label_2->setText(QCoreApplication::translate(
        "MainWindow", "Number of vertices:", nullptr));
    label_3->setText(
        QCoreApplication::translate("MainWindow", "Number of edges:", nullptr));
    FileName->setText(QString());
    Amount_vertices->setText(
        QCoreApplication::translate("MainWindow", "0", nullptr));
    Amount_edges->setText(
        QCoreApplication::translate("MainWindow", "0", nullptr));
    button_findFile->setText(
        QCoreApplication::translate("MainWindow", "Load file", nullptr));
    button_GIF->setText(
        QCoreApplication::translate("MainWindow", "GIF", nullptr));
    button_Screen->setText(
        QCoreApplication::translate("MainWindow", "Screenshot", nullptr));
    label_6->setText(
        QCoreApplication::translate("MainWindow", "Scale", nullptr));
    label_7->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
    label_8->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
    label_9->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
    label_10->setText(QCoreApplication::translate("MainWindow", "XR", nullptr));
    label_11->setText(QCoreApplication::translate("MainWindow", "YR", nullptr));
    label_12->setText(QCoreApplication::translate("MainWindow", "YZ", nullptr));
    projection->setItemText(
        0, QCoreApplication::translate("MainWindow", "central", nullptr));
    projection->setItemText(
        1, QCoreApplication::translate("MainWindow", "parralel", nullptr));

    label_4->setText(
        QCoreApplication::translate("MainWindow", "Projection", nullptr));
    label_5->setText(
        QCoreApplication::translate("MainWindow", "Edges:", nullptr));
    TypeEdges->setItemText(
        0, QCoreApplication::translate("MainWindow", "none", nullptr));
    TypeEdges->setItemText(
        1, QCoreApplication::translate("MainWindow", "dashed", nullptr));
    TypeEdges->setItemText(
        2, QCoreApplication::translate("MainWindow", "solid", nullptr));

    label_14->setText(
        QCoreApplication::translate("MainWindow", "Vertices:", nullptr));
    DisplayMetod->setItemText(
        0, QCoreApplication::translate("MainWindow", "none", nullptr));
    DisplayMetod->setItemText(
        1, QCoreApplication::translate("MainWindow", "sphere", nullptr));
    DisplayMetod->setItemText(
        2, QCoreApplication::translate("MainWindow", "cube", nullptr));

    label_15->setText(
        QCoreApplication::translate("MainWindow", "Background color", nullptr));
    BackColor->setText(
        QCoreApplication::translate("MainWindow", "Set color", nullptr));
    label_16->setText(
        QCoreApplication::translate("MainWindow", "Vertices color", nullptr));
    EdgesColor->setText(
        QCoreApplication::translate("MainWindow", "Set color", nullptr));
    VertexColor->setText(
        QCoreApplication::translate("MainWindow", "Set color", nullptr));
  }  // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_MAINWINDOW_H
