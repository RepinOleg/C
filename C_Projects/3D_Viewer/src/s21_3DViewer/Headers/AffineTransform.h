#ifndef __AFFINETRANSFORM_H__
#define __AFFINETRANSFORM_H__

#include <math.h>

#include "DynamicBuffer.h"
#include "OBJLoader.h"

void MoveToCentr(OBJData_t *data, int64_t amount);
void FindMaxMin(OBJData_t *data, int64_t amount);
void ChangeScale(Vertex_t *vertex, double scale, int64_t amount);
void ScaleReset(OBJData_t *data);
void MoveXYZ(OBJData_t *data, double value, int flag);
void RotateX(OBJData_t *data, double value);
void RotateY(OBJData_t *data, double value);
void RotateZ(OBJData_t *data, double value);
#endif  //  __AFFINETRANSFORM_H__
