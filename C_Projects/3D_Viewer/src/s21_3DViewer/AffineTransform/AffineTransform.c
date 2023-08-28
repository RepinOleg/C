#include "../Headers/AffineTransform.h"

#include <stdio.h>
// void MoveToCentr(OBJData_t *data, int64_t amount) {
//   double centerX =
//       data->verticesData->xMinMax[0] +
//       (data->verticesData->xMinMax[1] - data->verticesData->xMinMax[0]) / 2;

//   double centerY =
//       data->verticesData->yMinMax[0] +
//       (data->verticesData->yMinMax[1] - data->verticesData->yMinMax[0]) / 2;

//   double centerZ =
//       data->verticesData->zMinMax[0] +
//       (data->verticesData->zMinMax[1] - data->verticesData->zMinMax[0]) / 2;

//   Vertex_t *vertex = (Vertex_t *)data->verticesData->vertices->data;
//   for (int i = 1; i < amount; i++) {
//     vertex[i].x -= centerX;
//     vertex[i].y -= centerY;
//     vertex[i].z -= centerZ;
//   }
// }

// void FindMaxMin(OBJData_t *data, int64_t amount) {
//   Vertex_t *vertex = (Vertex_t *)data->verticesData->vertices->data;

//   data->verticesData->xMinMax[0] = vertex[1].x;
//   data->verticesData->xMinMax[1] = vertex[1].x;
//   data->verticesData->yMinMax[0] = vertex[1].y;
//   data->verticesData->yMinMax[1] = vertex[1].y;
//   data->verticesData->zMinMax[0] = vertex[1].z;
//   data->verticesData->zMinMax[1] = vertex[1].z;

//   for (int i = 1; i < amount; ++i) {
//     if (vertex[i].x < data->verticesData->xMinMax[0]) {
//       data->verticesData->xMinMax[0] = vertex[i].x;
//     } else if (vertex[i].x > data->verticesData->xMinMax[1]) {
//       data->verticesData->xMinMax[1] = vertex[i].x;
//     }

//     if (vertex[i].y < data->verticesData->yMinMax[0]) {
//       data->verticesData->yMinMax[0] = vertex[i].y;
//     } else if (vertex[i].y > data->verticesData->yMinMax[1]) {
//       data->verticesData->yMinMax[1] = vertex[i].y;
//     }

//     if (vertex[i].z < data->verticesData->zMinMax[0]) {
//       data->verticesData->zMinMax[0] = vertex[i].z;
//     } else if (vertex[i].z > data->verticesData->zMinMax[1]) {
//       data->verticesData->zMinMax[1] = vertex[i].z;
//     }
//   }
// }

void ScaleReset(OBJData_t *data) {
  VerticesData_t *vert = data->verticesData;

  double xDiff = vert->xMinMax[1] - vert->xMinMax[0];
  double yDiff = vert->yMinMax[1] - vert->yMinMax[0];
  double zDiff = vert->zMinMax[1] - vert->zMinMax[0];

  double maxDiff = xDiff;

  if (yDiff > maxDiff) maxDiff = yDiff;
  if (zDiff > maxDiff) maxDiff = zDiff;

  double scale = 0.7 - (0.7 * (-1)) / maxDiff;

  if (scale) {
    Vertex_t *vertex = (Vertex_t *)data->verticesData->vertices->data;
    ChangeScale(vertex, scale, vert->amount);
  }
}

void ChangeScale(Vertex_t *vertex, double scale, int64_t amount) {
  for (int i = 1; i < amount; ++i) {
    vertex[i].x *= scale;
    vertex[i].y *= scale;
    vertex[i].z *= scale;
  }
}

void MoveXYZ(OBJData_t *data, double value, int flag) {
  Vertex_t *vertex = (Vertex_t *)data->verticesData->vertices->data;
  for (int i = 1; i < data->verticesData->amount; ++i) {
    // 1 is X, 2 is Y, 3 is Z
    if (flag == 1) {
      vertex[i].x += value;
    } else if (flag == 2) {
      vertex[i].y += value;
    } else if (flag == 3) {
      vertex[i].z += value;
    }
  }
}

void RotateX(OBJData_t *data, double value) {
  Vertex_t *vertex = (Vertex_t *)data->verticesData->vertices->data;
  double angle = value * (3.14f / 180.0f);
  for (int i = 1; i < data->verticesData->amount; ++i) {
    double tmp_y = vertex[i].y;
    double tmp_z = vertex[i].z;
    vertex[i].y = cos(angle) * tmp_y - sin(angle) * tmp_z;
    vertex[i].z = sin(angle) * tmp_y + cos(angle) * tmp_z;
  }
}

void RotateY(OBJData_t *data, double value) {
  Vertex_t *vertex = (Vertex_t *)data->verticesData->vertices->data;
  double angle = value * (3.14f / 180.0f);
  for (int i = 1; i < data->verticesData->amount; ++i) {
    double tmp_x = vertex[i].x;
    double tmp_z = vertex[i].z;
    vertex[i].x = cos(angle) * tmp_x - sin(angle) * tmp_z;
    vertex[i].z = sin(angle) * tmp_x + cos(angle) * tmp_z;
  }
}

void RotateZ(OBJData_t *data, double value) {
  Vertex_t *vertex = (Vertex_t *)data->verticesData->vertices->data;
  double angle = value * (3.14f / 180.0f);
  for (int i = 1; i < data->verticesData->amount; ++i) {
    double tmp_x = vertex[i].x;
    double tmp_y = vertex[i].y;
    vertex[i].x = cos(angle) * tmp_x - sin(angle) * tmp_y;
    vertex[i].y = sin(angle) * tmp_x + cos(angle) * tmp_y;
  }
}
