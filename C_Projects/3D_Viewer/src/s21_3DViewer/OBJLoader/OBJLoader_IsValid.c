#include "OBJLoader_Util.h"

int OBJLoader_IsValid_FileName(const OBJData_t *data) {
  int status = 1;

  if (!data->fileName) {
    status = 0;
  }

  return status;
}

int OBJLoader_IsValid_FacesData(const OBJData_t *data) {
  int status = 1;

  if (!(data->facesData && DBuffer_IsValid(data->facesData->faces) &&
        data->facesData->amount >= 0)) {
    status = 0;
  } else {
    for (int64_t i = 0; i < data->facesData->amount; ++i) {
      if (!DBuffer_IsValid(((DBuffer_t **)data->facesData->faces->data)[i])) {
        status = 0;
        break;
      }
    }
  }

  return status;
}

int OBJLoader_IsValid_VerticesData(const OBJData_t *data) {
  int status = 1;

  if (!(data->verticesData && DBuffer_IsValid(data->verticesData->vertices) &&
        data->verticesData->amount >= 0 &&
        data->verticesData->xMinMax[0] <= data->verticesData->xMinMax[1] &&
        data->verticesData->yMinMax[0] <= data->verticesData->yMinMax[1] &&
        data->verticesData->zMinMax[0] <= data->verticesData->zMinMax[1])) {
    status = 0;
  }

  return status;
}

int OBJLoader_IsValid_InvalidData(const OBJData_t *data) {
  int status = 1;

  if (!(data->invalidData && DBuffer_IsValid(data->invalidData->lines) &&
        data->invalidData->amount >= 0)) {
    status = 0;
  } else {
    for (int64_t i = 0; i < data->invalidData->amount; ++i) {
      if (!((InvalidLine_t *)data->invalidData->lines->data)[i].line) {
        status = 0;
        break;
      }
    }
  }

  return status;
}
