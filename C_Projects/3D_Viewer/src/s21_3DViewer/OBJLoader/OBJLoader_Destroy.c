#include "OBJLoader_Util.h"

OBJLoader_Status_t OBJLoader_Destroy(OBJData_t *data) {
  OBJLoader_Status_t status = OBJLOADER_OK;

  if (!data) {
    status = OBJLOADER_ERROR_INVALID_ARGUMENT;
  } else {
    OBJLoader_Destroy_FileName(data, &status);

    OBJLoader_Destroy_FacesData(data, &status);

    OBJLoader_Destroy_VerticesData(data, &status);

    OBJLoader_Destroy_InvalidData(data, &status);

    free(data);
  }

  return status;
}

void OBJLoader_Destroy_FileName(OBJData_t *data, OBJLoader_Status_t *status) {
  if (!data->fileName) {
    *status = OBJLOADER_ERROR_INVALID_ARGUMENT;
  } else {
    free(data->fileName);
    data->fileName = NULL;
  }
}

void OBJLoader_Destroy_FacesData(OBJData_t *data, OBJLoader_Status_t *status) {
  if (!data->facesData) {
    *status = OBJLOADER_ERROR_INVALID_ARGUMENT;
  } else {
    if (!DBuffer_IsValid(data->facesData->faces)) {
      *status = OBJLOADER_ERROR_INVALID_ARGUMENT;
    } else {
      for (int64_t i = 0; i < data->facesData->amount; ++i) {
        if (DBuffer_Destroy(((DBuffer_t **)data->facesData->faces->data)[i]) !=
            DBUFFER_OK) {
          *status = OBJLOADER_ERROR_INVALID_ARGUMENT;
        }
      }
    }

    if (DBuffer_Destroy(data->facesData->faces) != DBUFFER_OK) {
      *status = OBJLOADER_ERROR_INVALID_ARGUMENT;
    }

    free(data->facesData);
    data->facesData = NULL;
  }
}

void OBJLoader_Destroy_VerticesData(OBJData_t *data,
                                    OBJLoader_Status_t *status) {
  if (!data->verticesData) {
    *status = OBJLOADER_ERROR_INVALID_ARGUMENT;
  } else {
    if (DBuffer_Destroy(data->verticesData->vertices) != DBUFFER_OK) {
      *status = OBJLOADER_ERROR_INVALID_ARGUMENT;
    }

    free(data->verticesData);
    data->verticesData = NULL;
  }
}

void OBJLoader_Destroy_InvalidData(OBJData_t *data,
                                   OBJLoader_Status_t *status) {
  if (!data->invalidData) {
    *status = OBJLOADER_ERROR_INVALID_ARGUMENT;
  } else {
    if (!DBuffer_IsValid(data->invalidData->lines)) {
      *status = OBJLOADER_ERROR_INVALID_ARGUMENT;
    } else {
      InvalidLine_t *invalidLine =
          (InvalidLine_t *)data->invalidData->lines->data;
      for (int64_t i = 0; i < data->invalidData->amount; ++i) {
        if (!invalidLine[i].line) {
          *status = OBJLOADER_ERROR_INVALID_ARGUMENT;
        } else {
          free(invalidLine[i].line);
        }
      }
    }

    if (DBuffer_Destroy(data->invalidData->lines) != DBUFFER_OK) {
      *status = OBJLOADER_ERROR_INVALID_ARGUMENT;
    }

    free(data->invalidData);
    data->invalidData = NULL;
  }
}
