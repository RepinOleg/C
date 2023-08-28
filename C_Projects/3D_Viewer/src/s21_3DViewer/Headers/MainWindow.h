#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__
extern "C" {
#include "AffineTransform.h"
}
#include <QColorDialog>
#include <QComboBox>
#include <QFileDialog>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QString>
#include <QVector>

#include "ModelViewerWidget.h"

// need for screenshot
#include <QApplication>
#include <QDateTime>
#include <QPixmap>
// #include <QScreen>
// Need for screen capture
#include <Magick++.h>

#include <QBuffer>
#include <QDir>
#include <QImage>  // Include the header for QImage
#include <QImageWriter>
#include <QMovie>
#include <QTimer>
#include <QWidget>
#include <cstdio>
#include <iostream>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow* ui;
  double moveX_sum;
  double moveY_sum;
  double moveZ_sum;
  double rotateX_sum;
  double rotateY_sum;
  double rotateZ_sum;
  double scale_sum;
  float thicknessEdgeSum;

  QTimer* timer;  // Timer for capturing screenshots
  QVector<QPixmap> screenshots;
  int recordingDuration;  // Duration of the recording in
  int i_counter;

 signals:
  void vertexTypeChanged(const GL_VertexType vertexType);

  //    void captureScreenshot();

  //    void stopRecording();

 private slots:

  void on_button_findFile_clicked();

  void on_xMove_valueChanged();

  void on_yMove_valueChanged();

  void on_zMove_valueChanged();

  void on_xRotate_valueChanged();

  void on_yRotate_valueChanged();

  void on_zRotate_valueChanged();

  void on_scaling_valueChanged();

  void on_BackColor_clicked();

  void on_VertexColor_clicked();

  void on_EdgesColor_clicked();

  void on_projection_currentIndexChanged(int index);

  void on_DepthEdges_valueChanged();

  void on_TypeEdges_currentIndexChanged(int index);

  void on_DisplayMetod_currentIndexChanged(int index);

  void on_VertexDepth_valueChanged();

  double FindDiff(double CurrentValue, double SumValue);

  void on_button_Screen_clicked();

  void on_button_GIF_clicked();

  void captureScreenshot();

  void stopRecording();

  void createDir();

  int deleteDir();

  int create_GIF(const QString& dirPath);

 public slots:
  void rx_EdgeThikness(float thik);
  void rx_VerticesThikness(float thik);
  void rx_EdgeTypeLoad(GL_EdgeType edgeType);
  void rx_VerticesTypeLoad(GL_VertexType index);
  void rx_ProjectionLoad(GL_ProjectionType index);
};

#endif  // __MAINWINDOW_H__
