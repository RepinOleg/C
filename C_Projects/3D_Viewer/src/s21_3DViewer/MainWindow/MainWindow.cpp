#include "Headers/MainWindow.h"

#include "Headers/ModelViewerWidget.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setWindowTitle("s21_3DViewer");
  setStyleSheet("background:rgb(143, 188, 143);");
  connect(ui->widget_modelViewer, &ModelViewerWidget::edgeThicknessLoaded, this,
          &MainWindow::rx_EdgeThikness);
  connect(ui->widget_modelViewer, &ModelViewerWidget::vertexThicknessLoaded,
          this, &MainWindow::rx_VerticesThikness);
  connect(ui->widget_modelViewer, &ModelViewerWidget::edgeTypeLoaded, this,
          &MainWindow::rx_EdgeTypeLoad);
  connect(ui->widget_modelViewer, &ModelViewerWidget::vertexTypeLoaded, this,
          &MainWindow::rx_VerticesTypeLoad);
  connect(ui->widget_modelViewer, &ModelViewerWidget::projectionTypeLoaded,
          this, &MainWindow::rx_ProjectionLoad);
  ui->widget_modelViewer->LoadSettings();
}

MainWindow::~MainWindow() {
  ui->widget_modelViewer->SaveSettings();
  delete ui;
}

void MainWindow::on_button_findFile_clicked() {
  QString fileName = QFileDialog::getOpenFileName(this, "Open file", nullptr,
                                                  "Models (*.obj)");
  const OBJData_t* modelData = ui->widget_modelViewer->LoadModel(fileName);

  if (!modelData) {
    ui->FileName->setText("ERROR");
    ui->Amount_edges->setText("0");
    ui->Amount_vertices->setText("0");
  } else {
    // name of file
    ui->FileName->setText(QFileInfo(fileName).fileName());
    // number of vertices
    ui->Amount_vertices->setText(
        QString::number(modelData->verticesData->amount));
    // number of edges
    DBuffer_t** faces = (DBuffer_t**)modelData->facesData->faces->data;
    int64_t edges = 0;
    for (int64_t i = 0; i < modelData->facesData->amount; ++i) {
      edges += faces[i]->length;
    }
    ui->Amount_edges->setText(QString::number(edges));
    ui->widget_modelViewer->ResetScale();
  }
}

void MainWindow::on_xMove_valueChanged() {
  double changeX = ui->xMove->value(), diff = 0.0;
  diff = FindDiff(changeX, moveX_sum);
  ui->widget_modelViewer->ChangeXYZ(diff, 1);
  moveX_sum += diff;
}

void MainWindow::on_yMove_valueChanged() {
  double changeY = ui->yMove->value(), diff = 0.0;
  diff = FindDiff(changeY, moveY_sum);
  ui->widget_modelViewer->ChangeXYZ(diff, 2);
  moveY_sum += diff;
}

void MainWindow::on_zMove_valueChanged() {
  double changeZ = ui->zMove->value(), diff = 0.0;
  diff = FindDiff(changeZ, moveZ_sum);
  ui->widget_modelViewer->ChangeXYZ(diff, 3);
  moveZ_sum += diff;
}

void MainWindow::on_xRotate_valueChanged() {
  double rotateX = ui->xRotate->value(), diff = 0.0;
  diff = FindDiff(rotateX, rotateX_sum);
  ui->widget_modelViewer->RotateXYZ(diff, 1);
  rotateX_sum += diff;
}

void MainWindow::on_yRotate_valueChanged() {
  double rotateY = ui->yRotate->value(), diff = 0.0;
  diff = FindDiff(rotateY, rotateY_sum);
  ui->widget_modelViewer->RotateXYZ(diff, 2);
  rotateY_sum += diff;
}

void MainWindow::on_zRotate_valueChanged() {
  double rotateZ = ui->zRotate->value(), diff = 0.0;
  diff = FindDiff(rotateZ, rotateZ_sum);
  ui->widget_modelViewer->RotateXYZ(diff, 3);
  rotateZ_sum += diff;
}

void MainWindow::on_scaling_valueChanged() {
  double scale = ui->scaling->value(), diff = 0;
  diff = FindDiff(scale, scale_sum);
  ui->widget_modelViewer->ChangeXYZ(diff, 3);
  scale_sum += diff;
}

void MainWindow::createDir() {
  QDir currentDir = QDir::current();
  QString currentPath = currentDir.absolutePath();

  QString projectPath = currentPath;
  QString newFolderName = "NewFolder1234";
  QString newFolderPath = projectPath + "/" + newFolderName;

  // Создание новой папки
  QDir dir;
  if (dir.mkdir(newFolderPath)) {
    qDebug() << "Папка успешно создана!";
  } else {
    qDebug() << "Ошибка при создании папки.";
  }
}

void MainWindow::on_button_Screen_clicked() {
  QString fileFilter =
      "PNG Files (*.png);;JPEG Files (*.jpg *.jpeg);;BMP Files (*.bmp);;All "
      "Files (*)";
  // Capture the desktop contents and store it in a QPixmap
  QPixmap screenshot = ui->widget_modelViewer->grab();
  QString fileName =
      QFileDialog::getSaveFileName(this, tr("Save Screenshot"), "", fileFilter);
  // Generate a unique filename for the screenshot using the current date and
  // time

  // Save the screenshot as an image file (PNG format in this case)
  if (!fileName.isEmpty()) {
    QFileInfo fileInfo(fileName);
    QString fileExtension = fileInfo.suffix().toLower();

    if (fileExtension.isEmpty() ||
        !(fileExtension == "png" || fileExtension == "jpg" ||
          fileExtension == "jpeg" || fileExtension == "bmp")) {
      fileName += ".png";
    }
    if (screenshot.save(fileName)) {
      qDebug() << "Screenshot saved as:" << fileName;
    } else {
      qDebug() << "Failed to save the screenshot.";
    }
  }
}

void MainWindow::captureScreenshot() {
  QPixmap screenshot(ui->widget_modelViewer->size());

  //    qDebug() << "Captured screenshot size:" << screenshot.size();

  // Render the widget into the QPixmap
  ui->widget_modelViewer->render(&screenshot);

  QString ii = QString::number(i_counter);
  qDebug() << "sizestring  = " << ii << "\n";
  QDir currentDir = QDir::current();
  QString currentPath = currentDir.absolutePath();

  QString projectPath = currentPath;
  QString newFolderName = "NewFolder1234/";
  QString newFolderPath = projectPath + "/" + newFolderName;
  screenshot.save(newFolderPath + ii + ".png");

  i_counter++;
  // Add the QPixmap to the screenshots vector
  screenshots.append(screenshot);
}

int MainWindow::deleteDir() {
  QDir currentDir = QDir::current();
  QString currentPath = currentDir.absolutePath();

  QString projectPath = currentPath;
  QString newFolderName = "NewFolder1234";
  QString newFolderPath = projectPath + "/" + newFolderName;
  std::string folderPath = newFolderPath.toStdString() + "/";

  try {
    // Удаление всех файлов в папке
    std::string command = "rm -f " + folderPath + "*";
    if (std::system(command.c_str()) != 0) {
      throw std::runtime_error("Ошибка при удалении файлов");
    }

    // Удаление пустой папки
    command = "rmdir " + folderPath;
    if (std::system(command.c_str()) != 0) {
      throw std::runtime_error("Ошибка при удалении папки");
    }

    std::cout << "Файлы и папка успешно удалены!" << std::endl;
  } catch (const std::exception& ex) {
    std::cerr << "Ошибка: " << ex.what() << std::endl;
    return 1;
  }

  return 0;
}

void MainWindow::stopRecording() {
  // Stop the timer to avoid capturing more screenshots
  timer->stop();

  QString fileName =
      QFileDialog::getSaveFileName(this, tr("Save GIF Animation"), "",
                                   tr("GIF Files (*.gif);;All Files (*)"));

  if (fileName.isEmpty()) {
    qDebug() << "No file selected. GIF animation not saved.";
    return;
  }
  create_GIF(fileName);
  screenshots.clear();
  screenshots.shrink_to_fit();
  deleteDir();
}

int MainWindow::create_GIF(const QString& dirPath) {
  // Инициализация ImageMagick
  Magick::InitializeMagick(nullptr);
  QDir currentDir = QDir::current();
  QString currentPath = currentDir.absolutePath();

  QString projectPath = currentPath;
  QString newFolderName = "NewFolder1234";
  std::string newFolderPath =
      projectPath.toStdString() + "/" + newFolderName.toStdString();

  try {
    // Создаем вектор, который будет содержать кадры анимации
    std::vector<Magick::Image> animationFrames;

    // Добавляем изображения в вектор
    int ik = 0;
    for (const QPixmap& screenshot : screenshots) {
      std::string imageName = newFolderPath + "/" + std::to_string(ik) + ".png";
      Magick::Image image(imageName);
      animationFrames.push_back(image);
      ik++;
    }
    // Устанавливаем задержку между кадрами и количество повторений анимации
    for (size_t i = 0; i < animationFrames.size(); i++) {
      animationFrames[i].animationDelay(
          100);  // Задержка между кадрами в миллисекундах (100 мс = 0.1 сек)
    }
    animationFrames.back().animationIterations(
        0);  // Количество повторений (0 = бесконечный цикл)

    // Сохраняем анимацию в GIF-файл
    Magick::writeImages(animationFrames.begin(), animationFrames.end(),
                        dirPath.toStdString());

    std::cout << "GIF-анимация успешно создана!" << std::endl;
  } catch (const Magick::Exception& ex) {
    std::cerr << "Ошибка: " << ex.what() << std::endl;
    return 1;
  }

  return 0;
}

void MainWindow::on_button_GIF_clicked() {
  i_counter = 0;
  createDir();
  timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &MainWindow::captureScreenshot);
  timer->start(100);         // 100 milliseconds for 10 FPS
  recordingDuration = 5000;  // 5 seconds
  QTimer::singleShot(recordingDuration, this, &MainWindow::stopRecording);
}

void MainWindow::on_BackColor_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Select color:");
  ui->widget_modelViewer->setBackgroundColor(color);
  ui->widget_modelViewer->update();
}

void MainWindow::on_VertexColor_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Select color:");
  ui->widget_modelViewer->setVertexColor(color);
  ui->widget_modelViewer->update();
}

void MainWindow::on_EdgesColor_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Select color:");
  ui->widget_modelViewer->setEdgeColor(color);
  ui->widget_modelViewer->update();
}

void MainWindow::on_projection_currentIndexChanged(int index) {
  switch (index) {
    case 0:
      ui->widget_modelViewer->setProjectionType(
          GL_ProjectionType::PROJECTION_CENTRAL);
      break;
    case 1:
      ui->widget_modelViewer->setProjectionType(
          GL_ProjectionType::PROJECTION_PARALLEL);
      break;
  }
}

void MainWindow::on_DepthEdges_valueChanged() {
  float thicknessEdge = ui->DepthEdges->value();
  ui->widget_modelViewer->setEdgeThickness(thicknessEdge);
}

void MainWindow::on_TypeEdges_currentIndexChanged(int index) {
  switch (index) {
    case 0:
      ui->widget_modelViewer->setEdgeType(GL_EdgeType::NONE);
      break;
    case 1:
      ui->widget_modelViewer->setEdgeType(GL_EdgeType::EDGE_NORMAL);
      break;
    case 2:
      ui->widget_modelViewer->setEdgeType(GL_EdgeType::EDGE_DASHED);
      break;
  }
}

void MainWindow::on_DisplayMetod_currentIndexChanged(int index) {
  switch (index) {
    case 0:
      ui->widget_modelViewer->setVertexType(GL_VertexType::NONE);
      break;
    case 1:
      ui->widget_modelViewer->setVertexType(GL_VertexType::VERTEX_SPHERE);
      break;
    case 2:
      ui->widget_modelViewer->setVertexType(GL_VertexType::VERTEX_CUBE);
      break;
  }
}

void MainWindow::on_VertexDepth_valueChanged() {
  float thicknessVertex = ui->VertexDepth->value();
  ui->widget_modelViewer->setVertexThickness(thicknessVertex);
}

void MainWindow::rx_EdgeThikness(float thik) { ui->DepthEdges->setValue(thik); }

void MainWindow::rx_VerticesThikness(float thik) {
  ui->VertexDepth->setValue(thik);
}

void MainWindow::rx_EdgeTypeLoad(GL_EdgeType index) {
  int i = int(index);
  ui->TypeEdges->setCurrentIndex(i);
}

void MainWindow::rx_VerticesTypeLoad(GL_VertexType index) {
  int i = int(index);
  ui->DisplayMetod->setCurrentIndex(i);
}

void MainWindow::rx_ProjectionLoad(GL_ProjectionType index) {
  int i = int(index);
  ui->projection->setCurrentIndex(i);
}

double MainWindow::FindDiff(double CurrentValue, double SumValue) {
  double diff;
  if (CurrentValue < SumValue) {
    diff = -(SumValue - CurrentValue);
  } else {
    if (CurrentValue < 0)
      diff = -(SumValue - CurrentValue);
    else
      diff = CurrentValue - SumValue;
  }
  return diff;
}
