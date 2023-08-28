#include <cmath>

#include "../Headers/AffineTransform.h"
#include "../Headers/ModelViewerWidget.h"

void ModelViewerWidget::drawVertices(void) {
  if (m_model_vertexType == GL_VertexType::NONE) {
    return;
  }

  glPointSize(m_model_vertexThickness);

  if (m_model_vertexType == GL_VertexType::VERTEX_SPHERE) {
    glEnable(GL_POINT_SMOOTH);
  } else if (m_model_vertexType == GL_VertexType::VERTEX_CUBE) {
    glDisable(GL_POINT_SMOOTH);
  }

  Vertex_t *vertices = (Vertex_t *)m_model_data->verticesData->vertices->data;

  glBegin(GL_POINTS);
  for (int64_t i = 1; i < m_model_data->verticesData->amount; ++i) {
    glColor3f(m_model_vertexColor.redF(), m_model_vertexColor.greenF(),
              m_model_vertexColor.blueF());
    glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
  }
  glEnd();
}

void ModelViewerWidget::drawEdges(void) {
  if (m_model_edgeType == GL_EdgeType::NONE) {
    return;
  }

  glLineWidth(m_model_edgeThickness);

  if (m_model_edgeType == GL_EdgeType::EDGE_DASHED) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x0C0F);
  } else if (m_model_edgeType == GL_EdgeType::EDGE_NORMAL) {
    glDisable(GL_LINE_STIPPLE);
  }

  Vertex_t *vertices = (Vertex_t *)m_model_data->verticesData->vertices->data;
  DBuffer_t **faces = (DBuffer_t **)m_model_data->facesData->faces->data;

  for (int64_t i = 0; i < m_model_data->facesData->amount; ++i) {
    FacetIndex_t *facet = (FacetIndex_t *)faces[i]->data;

    glBegin(GL_LINE_LOOP);
    for (int64_t j = 0; j < faces[i]->length; ++j) {
      if (facet[j].v < 0 ||
          facet[j].v > m_model_data->verticesData->amount - 1) {
        break;
      }
      glColor3f(m_model_edgeColor.redF(), m_model_edgeColor.greenF(),
                m_model_edgeColor.blueF());
      glVertex3f(vertices[facet[j].v].x, vertices[facet[j].v].y,
                 vertices[facet[j].v].z);
    }
    glEnd();
  }
}

void ModelViewerWidget::drawModel(void) {
  drawVertices();
  drawEdges();
}
