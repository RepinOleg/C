#include "../Headers/ModelViewerWidget.h"

#include <QDebug>
#include <QTimer>

#include "../Headers/AffineTransform.h"

ModelViewerWidget::ModelViewerWidget(QWidget *parent) : QOpenGLWidget(parent) {
  setAttribute(Qt::WA_QuitOnClose, false);  // close with main window
  setFocusPolicy(Qt::StrongFocus);
  setMouseTracking(true);
  setTabletTracking(true);

  setupModelParameters();

  settings =
      new QSettings("ModelSettings.ini", QSettings::Format::IniFormat, this);

  QTimer *timer = new QTimer(this);

  timer->setInterval(1000 / 30);
  connect(timer, &QTimer::timeout, this, [&](void) { update(); });

  timer->start();
}

ModelViewerWidget::~ModelViewerWidget(void) {
  OBJLoader_Dump(m_model_data);
  m_model_data = NULL;
}

const OBJData_t *ModelViewerWidget::LoadModel(const QString &fileName) {
  OBJLoader_Dump(m_model_data);  // clear previous model

  if (!(m_model_data = OBJLoader_Load(fileName.toStdString().c_str()))) {
    return NULL;
  }

  updateModelParameters();

  resize(size().width() - 1, size().height() - 1);
  resize(size().width() + 1, size().height() + 1);

  return (const OBJData_t *)
      m_model_data;  // return ptr to check for mistakes in file
}

void ModelViewerWidget::LoadSettings(void) {
  settings->beginGroup("Projection");
  m_model_projectionType =
      (GL_ProjectionType)settings
          ->value("type", (int)GL_ProjectionType::PROJECTION_CENTRAL)
          .toInt();
  emit projectionTypeLoaded(m_model_projectionType);
  settings->endGroup();

  settings->beginGroup("Vertex");
  m_model_vertexType =
      (GL_VertexType)settings->value("type", (int)GL_VertexType::VERTEX_SPHERE)
          .toInt();
  m_model_vertexColor =
      settings->value("color", QColor(255, 255, 255)).value<QColor>();
  m_model_vertexThickness = settings->value("thickness", 1.5f).toFloat();
  emit vertexTypeLoaded(m_model_vertexType);
  emit vertexColorLoaded(m_model_vertexColor);
  emit vertexThicknessLoaded(m_model_vertexThickness);
  settings->endGroup();

  settings->beginGroup("Edge");
  m_model_edgeType =
      (GL_EdgeType)settings->value("type", (int)GL_EdgeType::EDGE_NORMAL)
          .toInt();
  m_model_edgeColor =
      settings->value("color", QColor(255, 255, 255)).value<QColor>();
  m_model_edgeThickness = settings->value("thickness", 1.5f).toFloat();
  emit edgeTypeLoaded(m_model_edgeType);
  emit edgeColorLoaded(m_model_edgeColor);
  emit edgeThicknessLoaded(m_model_edgeThickness);
  settings->endGroup();

  settings->beginGroup("Background");
  m_model_backgroundColor =
      settings->value("color", QColor(0, 0, 0)).value<QColor>();
  emit backgroundColorLoaded(m_model_backgroundColor);
  settings->endGroup();
}

void ModelViewerWidget::SaveSettings(void) {
  settings->beginGroup("Projection");
  settings->setValue("type", (int)m_model_projectionType);
  settings->endGroup();

  settings->beginGroup("Vertex");
  settings->setValue("type", (int)m_model_vertexType);
  settings->setValue("color", m_model_vertexColor);
  settings->setValue("thickness", m_model_vertexThickness);
  settings->endGroup();

  settings->beginGroup("Edge");
  settings->setValue("type", (int)m_model_edgeType);
  settings->setValue("color", m_model_edgeColor);
  settings->setValue("thickness", m_model_edgeThickness);
  settings->endGroup();

  settings->beginGroup("Background");
  settings->setValue("color", m_model_backgroundColor);
  settings->endGroup();
}

void ModelViewerWidget::initializeGL(void) {
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void ModelViewerWidget::resizeGL(int width, int height) {
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (m_model_projectionType == GL_ProjectionType::PROJECTION_CENTRAL) {
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, m_model_farVal);
  } else if (m_model_projectionType == GL_ProjectionType::PROJECTION_PARALLEL) {
    glOrtho(-1.0, 1.0, -1.0, 1.0, -m_model_farVal, m_model_farVal);
  }
}

void ModelViewerWidget::paintGL(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(m_model_backgroundColor.redF(), m_model_backgroundColor.greenF(),
               m_model_backgroundColor.blueF(), 1.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  if (!m_model_data) {
    return;
  }

  glTranslatef(
      m_model_x_initPosition + m_model_x_offsetPosition / m_model_translateCoef,
      m_model_y_initPosition + m_model_y_offsetPosition / m_model_translateCoef,
      m_model_z_initPosition +
          m_model_z_offsetPosition / m_model_translateCoef);

  glTranslatef(-m_model_x_initPosition, -m_model_y_initPosition,
               -m_model_z_initPosition);
  if (m_model_projectionType == GL_ProjectionType::PROJECTION_PARALLEL) {
    glScalef(m_model_scale, m_model_scale, m_model_scale);
  }
  glRotatef(m_model_x_offsetAngle, 1.0f, 0.0f, 0.0f);
  glRotatef(m_model_y_offsetAngle, 0.0f, 1.0f, 0.0f);
  glRotatef(m_model_z_offsetAngle, 0.0f, 0.0f, 1.0f);
  glTranslatef(m_model_x_initPosition, m_model_y_initPosition,
               m_model_z_initPosition);

  drawModel();
}

void ModelViewerWidget::mousePressEvent(QMouseEvent *event) {
  m_mouse_lastPosition = event->pos();

  QOpenGLWidget::mousePressEvent(event);
}

void ModelViewerWidget::mouseMoveEvent(QMouseEvent *event) {
  int dx = event->pos().x() - m_mouse_lastPosition.x();
  int dy = event->pos().y() - m_mouse_lastPosition.y();

  if (event->buttons() & Qt::LeftButton) {
    if (m_keys_pressed.contains(Qt::Key_Shift) && m_keys_pressed.size() == 1) {
      setXOffsetPosition(dx);
      setYOffsetPosition(-dy);
    } else if (m_keys_pressed.contains(Qt::Key_Shift) &&
               m_keys_pressed.contains(Qt::Key_Z) &&
               m_keys_pressed.size() == 2) {
      setZOffsetPosition(-dy);
    } else if (m_keys_pressed.contains(Qt::Key_Control) &&
               m_keys_pressed.size() == 1) {
      setXOffsetAngle(dy);
      setYOffsetAngle(dx);
    } else if (m_keys_pressed.contains(Qt::Key_Control) &&
               m_keys_pressed.contains(Qt::Key_Z) &&
               m_keys_pressed.size() == 2) {
      setZOffsetAngle(-dx);
    }
  }

  m_mouse_lastPosition = event->pos();

  QOpenGLWidget::mouseMoveEvent(event);
}

void ModelViewerWidget::keyPressEvent(QKeyEvent *event) {
  m_keys_pressed.insert(event->key());

  //    if (m_keys_pressed.contains(Qt::Key_Escape) && m_keys_pressed.size() ==
  //    1) {
  //        close();
  //    } else if (m_keys_pressed.contains(Qt::Key_P) && m_keys_pressed.size()
  //    == 1) {
  //        if (m_model_projectionType == GL_ProjectionType::PROJECTION_CENTRAL)
  //        {
  //            setProjectionType(GL_ProjectionType::PROJECTION_PARALLEL);
  //        } else if (m_model_projectionType ==
  //        GL_ProjectionType::PROJECTION_PARALLEL) {
  //            setProjectionType(GL_ProjectionType::PROJECTION_CENTRAL);
  //        }
  //    }

  QOpenGLWidget::keyPressEvent(event);
}

void ModelViewerWidget::keyReleaseEvent(QKeyEvent *event) {
  m_keys_pressed.remove(event->key());

  QOpenGLWidget::keyReleaseEvent(event);
}

void ModelViewerWidget::closeEvent(QCloseEvent *event) {
  OBJLoader_Dump(m_model_data);
  m_model_data = NULL;
  event->accept();

  QOpenGLWidget::closeEvent(event);
}

void ModelViewerWidget::ChangeXYZ(double value, int flag) {
  if (m_model_data) {
    MoveXYZ(m_model_data, value, flag);
    update();
  }
}

void ModelViewerWidget::RotateXYZ(double value, int flag) {
  if (m_model_data) {
    switch (flag) {
      case 1:
        RotateX(m_model_data, value);
        break;
      case 2:
        RotateY(m_model_data, value);
        break;
      case 3:
        RotateZ(m_model_data, value);
        break;
    }
    update();
  }
}

void ModelViewerWidget::ResetScale() {
  if (m_model_data) {
    ScaleReset(m_model_data);
    update();
  }
}
