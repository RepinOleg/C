#include "../Headers/ModelViewerWidget.h"

void ModelViewerWidget::setXOffsetPosition(const float offset) {
  m_model_x_offsetPosition += m_model_x_offsetPositionStep * offset;
}

void ModelViewerWidget::setYOffsetPosition(const float offset) {
  m_model_y_offsetPosition += m_model_y_offsetPositionStep * offset;
}

void ModelViewerWidget::setZOffsetPosition(const float offset) {
  m_model_z_offsetPosition += m_model_z_offsetPositionStep * offset;
  if (m_model_scale + m_model_scaleStep * offset > 0) {
    m_model_scale += m_model_scaleStep * offset;
  }
}

void ModelViewerWidget::setXOffsetAngle(const float offset) {
  m_model_x_offsetAngle += m_model_x_offsetAngleStep * offset;
}

void ModelViewerWidget::setYOffsetAngle(const float offset) {
  m_model_y_offsetAngle += m_model_y_offsetAngleStep * offset;
}

void ModelViewerWidget::setZOffsetAngle(const float offset) {
  m_model_z_offsetAngle += m_model_z_offsetAngleStep * offset;
}

void ModelViewerWidget::setProjectionType(const GL_ProjectionType type) {
  m_model_projectionType = type;
  if (type == GL_ProjectionType::PROJECTION_CENTRAL) {
    m_model_translateCoef = 1.0f;
  } else if (type == GL_ProjectionType::PROJECTION_PARALLEL) {
    m_model_translateCoef = 8.0f;
  }
  resize(size().width() - 1, size().height() - 1);
  resize(size().width() + 1, size().height() + 1);
}

void ModelViewerWidget::setEdgeType(const GL_EdgeType type) {
  m_model_edgeType = type;
}

void ModelViewerWidget::setEdgeColor(const QColor color) {
  m_model_edgeColor = color;
}

void ModelViewerWidget::setEdgeColorRed(const int color) {
  m_model_edgeColor.setRed(color);
}

void ModelViewerWidget::setEdgeColorGreen(const int color) {
  m_model_edgeColor.setGreen(color);
}

void ModelViewerWidget::setEdgeColorBlue(const int color) {
  m_model_edgeColor.setBlue(color);
}

void ModelViewerWidget::setEdgeThickness(const float thickness) {
  m_model_edgeThickness = thickness;
}

void ModelViewerWidget::setVertexType(const GL_VertexType type) {
  m_model_vertexType = type;
}

void ModelViewerWidget::setVertexColor(const QColor color) {
  m_model_vertexColor = color;
}

void ModelViewerWidget::setVertexColorRed(const int color) {
  m_model_vertexColor.setRed(color);
}

void ModelViewerWidget::setVertexColorGreen(const int color) {
  m_model_vertexColor.setGreen(color);
}

void ModelViewerWidget::setVertexColorBlue(const int color) {
  m_model_vertexColor.setBlue(color);
}

void ModelViewerWidget::setVertexThickness(const float thickness) {
  m_model_vertexThickness = thickness;
}

void ModelViewerWidget::setBackgroundColor(const QColor color) {
  m_model_backgroundColor = color;
}

void ModelViewerWidget::setBackgroundColorRed(const int color) {
  m_model_backgroundColor.setRed(color);
}

void ModelViewerWidget::setBackgroundColorGreen(const int color) {
  m_model_backgroundColor.setGreen(color);
}

void ModelViewerWidget::setBackgroundColorBlue(const int color) {
  m_model_backgroundColor.setBlue(color);
}
