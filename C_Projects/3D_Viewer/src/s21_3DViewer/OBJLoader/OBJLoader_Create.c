#include "OBJLoader_Util.h"

OBJData_t *OBJLoader_Create(const char *fileName) {
  if (!fileName) {
    return NULL;
  }

  OBJData_t *data = NULL;

  OBJLoader_Status_t status = OBJLOADER_OK;

  if (!(data = (OBJData_t *)calloc(1, sizeof(OBJData_t)))) {
    status = OBJLOADER_ERROR_BAD_ALLOCATION;
  }

  if (status == OBJLOADER_OK) {
    status = OBJLoader_Create_FileName(data, fileName);
  }

  if (status == OBJLOADER_OK) {
    status = OBJLoader_Create_FacesData(data);
  }

  if (status == OBJLOADER_OK) {
    status = OBJLoader_Create_VerticesData(data);
  }

  if (status == OBJLOADER_OK) {
    status = OBJLoader_Create_InvalidData(data);
  }

  if (status != OBJLOADER_OK) {
    OBJLoader_Destroy(data);
    data = NULL;
  }

  return data;
}

OBJLoader_Status_t OBJLoader_Create_FileName(OBJData_t *data,
                                             const char *fileName) {
  OBJLoader_Status_t status = OBJLOADER_OK;

  if (!(data->fileName =
            (char *)malloc(sizeof(char) * (strlen(fileName) + 1)))) {
    status = OBJLOADER_ERROR_BAD_ALLOCATION;
  } else {
    strcpy(data->fileName, fileName);
  }

  return status;
}

OBJLoader_Status_t OBJLoader_Create_FacesData(OBJData_t *data) {
  OBJLoader_Status_t status = OBJLOADER_OK;

  if (!(data->facesData = (FacesData_t *)calloc(1, sizeof(FacesData_t)))) {
    status = OBJLOADER_ERROR_BAD_ALLOCATION;
  } else {
    if (!(data->facesData->faces = DBuffer_Create(
              sizeof(DBuffer_t *), 0))) {  // create buffer inside buffer
      status = OBJLOADER_ERROR_BAD_ALLOCATION;
    } else {
      data->facesData->amount = 0;
    }
  }

  return status;
}

OBJLoader_Status_t OBJLoader_Create_VerticesData(OBJData_t *data) {
  OBJLoader_Status_t status = OBJLOADER_OK;

  if (!(data->verticesData =
            (VerticesData_t *)calloc(1, sizeof(VerticesData_t)))) {
    status = OBJLOADER_ERROR_BAD_ALLOCATION;
  } else {
    if (!(data->verticesData->vertices = DBuffer_Create(sizeof(Vertex_t), 0))) {
      status = OBJLOADER_ERROR_BAD_ALLOCATION;
    } else {
      Vertex_t zeroVertex = {0.0, 0.0, 0.0,
                             0.0};  // push empty vertex, because all indexes in
                                    // file start from 1, not 0
      if (DBuffer_PushBack(data->verticesData->vertices, &zeroVertex, 1) !=
          DBUFFER_OK) {
        status = OBJLOADER_ERROR_INTERNAL;
      } else {
        data->verticesData->amount =
            1;  // means we need to iterate from 1, when operate vertices

        memset(data->verticesData->xMinMax, 0, sizeof(double) * 2);
        memset(data->verticesData->yMinMax, 0, sizeof(double) * 2);
        memset(data->verticesData->zMinMax, 0, sizeof(double) * 2);
      }
    }
  }

  return status;
}

OBJLoader_Status_t OBJLoader_Create_InvalidData(OBJData_t *data) {
  OBJLoader_Status_t status = OBJLOADER_OK;

  if (!(data->invalidData =
            (InvalidData_t *)calloc(1, sizeof(InvalidData_t)))) {
    status = OBJLOADER_ERROR_BAD_ALLOCATION;
  } else {
    if (!(data->invalidData->lines =
              DBuffer_Create(sizeof(InvalidLine_t), 0))) {
      status = OBJLOADER_ERROR_BAD_ALLOCATION;
    } else {
      data->invalidData->amount = 0;
    }
  }

  return status;
}
