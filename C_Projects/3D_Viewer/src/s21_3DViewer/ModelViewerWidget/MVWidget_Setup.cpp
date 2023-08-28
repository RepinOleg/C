#include "../Headers/ModelViewerWidget.h"

void ModelViewerWidget::setupModelParameters(void) {
  m_model_data = NULL;

  m_model_farVal = 0.0;

  m_model_x_initPosition = 0.0f;
  m_model_y_initPosition = 0.0f;
  m_model_z_initPosition = 0.0f;

  m_model_x_offsetPosition = 0.0f;
  m_model_y_offsetPosition = 0.0f;
  m_model_z_offsetPosition = 0.0f;

  m_model_x_offsetPositionStep = 0.0f;
  m_model_y_offsetPositionStep = 0.0f;
  m_model_z_offsetPositionStep = 0.0f;

  m_model_x_offsetAngle = 0.0f;
  m_model_y_offsetAngle = 0.0f;
  m_model_z_offsetAngle = 0.0f;

  m_model_x_offsetAngleStep = 0.5f;
  m_model_y_offsetAngleStep = 0.5f;
  m_model_z_offsetAngleStep = 0.5f;

  m_model_scale = 0.0f;
  m_model_scaleStep = 0.0f;

  m_model_projectionType = GL_ProjectionType::PROJECTION_CENTRAL;

  m_model_translateCoef = 1.0f;

  m_model_edgeType = GL_EdgeType::EDGE_NORMAL;
  m_model_edgeColor = Qt::white;
  m_model_edgeThickness = 1.5f;

  m_model_vertexType = GL_VertexType::VERTEX_CUBE;
  m_model_vertexColor = Qt::white;
  m_model_vertexThickness = 1.5f;

  m_model_backgroundColor = Qt::black;

  m_mouse_lastPosition = QPoint();
}

void ModelViewerWidget::updateModelParameters(void) {
  m_model_x_initPosition = -(m_model_data->verticesData->xMinMax[0] +
                             m_model_data->verticesData->xMinMax[1]) /
                           2.0f;
  m_model_y_initPosition = -(m_model_data->verticesData->yMinMax[0] +
                             m_model_data->verticesData->yMinMax[1]) /
                           2.0f;
  m_model_z_initPosition = -(m_model_data->verticesData->zMinMax[0] +
                             m_model_data->verticesData->zMinMax[1]) /
                           2.0f;

  m_model_x_offsetPosition = 0.0f;
  m_model_y_offsetPosition = 0.0f;
  m_model_z_offsetPosition = 0.0f;
  m_model_z_offsetPosition -=
      std::max({m_model_data->verticesData->xMinMax[1] -
                    m_model_data->verticesData->xMinMax[0],
                m_model_data->verticesData->yMinMax[1] -
                    m_model_data->verticesData->yMinMax[0],
                m_model_data->verticesData->zMinMax[1] -
                    m_model_data->verticesData->zMinMax[0]});

  m_model_x_offsetPositionStep = (m_model_data->verticesData->xMinMax[1] -
                                  m_model_data->verticesData->xMinMax[0]) /
                                 600.0f;
  m_model_y_offsetPositionStep = (m_model_data->verticesData->yMinMax[1] -
                                  m_model_data->verticesData->yMinMax[0]) /
                                 600.0f;
  m_model_z_offsetPositionStep = (m_model_data->verticesData->zMinMax[1] -
                                  m_model_data->verticesData->zMinMax[0]) /
                                 200.0f;

  m_model_x_offsetAngle = 0.0f;
  m_model_y_offsetAngle = 0.0f;
  m_model_z_offsetAngle = 0.0f;

  m_model_scale = -2.0f / m_model_z_offsetPosition;
  m_model_scaleStep = m_model_scale / 1000.0f;

  m_model_farVal = -10.0 * m_model_z_offsetPosition;

  m_model_z_offsetPosition *= 0.75f;

  m_keys_pressed.clear();
}
