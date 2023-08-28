#ifndef __MODELVIEWERWIDGET_H__
#define __MODELVIEWERWIDGET_H__

#include "DynamicBuffer.h"
#include "OBJLoader.h"
extern "C" {
#include "AffineTransform.h"
}

//#include <QGLWidget>
#include <QCloseEvent>
#include <QKeyEvent>
#include <QMatrix4x4>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QSet>
#include <QSettings>
#include <QString>

enum class GL_ProjectionType {
  PROJECTION_CENTRAL = 0,
  PROJECTION_PARALLEL,
};

enum class GL_EdgeType {
  NONE = 0,
  EDGE_NORMAL,
  EDGE_DASHED,
};

enum class GL_VertexType {
  NONE = 0,
  VERTEX_SPHERE,
  VERTEX_CUBE,
};

class ModelViewerWidget : public QOpenGLWidget {
  Q_OBJECT

 public:
  explicit ModelViewerWidget(QWidget *parent = nullptr);
  ~ModelViewerWidget(void);

  const OBJData_t *LoadModel(const QString &fileName);

  void LoadSettings(void);
  void SaveSettings(void);
  void ResetScale(void);

 private:
  QSettings *settings;

  OBJData_t *m_model_data;

  double m_model_farVal;

  float m_model_x_initPosition;
  float m_model_y_initPosition;
  float m_model_z_initPosition;

  float m_model_x_offsetPosition;
  float m_model_y_offsetPosition;
  float m_model_z_offsetPosition;

  float m_model_x_offsetPositionStep;
  float m_model_y_offsetPositionStep;
  float m_model_z_offsetPositionStep;

  float m_model_x_offsetAngle;
  float m_model_y_offsetAngle;
  float m_model_z_offsetAngle;

  float m_model_x_offsetAngleStep;
  float m_model_y_offsetAngleStep;
  float m_model_z_offsetAngleStep;

  float m_model_scale;
  float m_model_scaleStep;

  GL_ProjectionType m_model_projectionType;
  float m_model_translateCoef;

  GL_EdgeType m_model_edgeType;
  QColor m_model_edgeColor;
  float m_model_edgeThickness;

  GL_VertexType m_model_vertexType;
  QColor m_model_vertexColor;
  float m_model_vertexThickness;

  QColor m_model_backgroundColor;

  QPoint m_mouse_lastPosition;

  QSet<int> m_keys_pressed;

  void setupModelParameters(void);
  void updateModelParameters(void);

  void drawModel(void);
  void drawVertices(void);
  void drawEdges(void);

 protected:
  void initializeGL(void) override;
  void resizeGL(int width, int height) override;
  void paintGL(void) override;

  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;
  void keyReleaseEvent(QKeyEvent *event) override;

  void closeEvent(QCloseEvent *event) override;

 public slots:
  void setXOffsetPosition(const float offset);
  void setYOffsetPosition(const float offset);
  void setZOffsetPosition(const float offset);

  void setXOffsetAngle(const float offset);
  void setYOffsetAngle(const float offset);
  void setZOffsetAngle(const float offset);

  void setProjectionType(const GL_ProjectionType type);

  void setEdgeType(const GL_EdgeType type);
  void setEdgeColor(const QColor color);
  void setEdgeColorRed(const int color);
  void setEdgeColorGreen(const int color);
  void setEdgeColorBlue(const int color);
  void setEdgeThickness(const float thickness);

  void setVertexType(const GL_VertexType type);
  void setVertexColor(const QColor color);
  void setVertexColorRed(const int color);
  void setVertexColorGreen(const int color);
  void setVertexColorBlue(const int color);
  void setVertexThickness(const float thickness);

  void setBackgroundColor(const QColor color);
  void setBackgroundColorRed(const int color);
  void setBackgroundColorGreen(const int color);
  void setBackgroundColorBlue(const int color);

  void ChangeXYZ(double value, int flag);
  void RotateXYZ(double value, int flag);
 signals:
  void projectionTypeLoaded(const GL_ProjectionType type);

  void edgeTypeLoaded(const GL_EdgeType type);
  void edgeColorLoaded(const QColor color);
  void edgeThicknessLoaded(const float thickness);

  void vertexTypeLoaded(const GL_VertexType type);
  void vertexColorLoaded(const QColor color);
  void vertexThicknessLoaded(const float thickness);

  void backgroundColorLoaded(const QColor color);
};

#endif  // __MODELVIEWERWIDGET_H__
