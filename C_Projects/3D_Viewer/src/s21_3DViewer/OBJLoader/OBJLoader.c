#include "../Headers/OBJLoader.h"

#include "OBJLoader_Util.h"

OBJData_t *OBJLoader_Load(const char *fileName) {
  if (!fileName) {
    return NULL;
  }

  FILE *fp = NULL;
  if (!(fp = fopen(fileName, "r"))) {
    return NULL;
  }

  OBJLoader_Status_t status = OBJLOADER_OK;

  OBJData_t *objData = NULL;
  if (!(objData = OBJLoader_Create(fileName))) {
    status = OBJLOADER_ERROR_BAD_ALLOCATION;
  } else {
    status = OBJLoader_Load_OBJData(objData, fp);
  }

  if (status != OBJLOADER_OK) {
    OBJLoader_Dump(objData);
    objData = NULL;
  }

  fclose(fp);

  return objData;
}

OBJLoader_Status_t OBJLoader_Dump(OBJData_t *data) {
  OBJLoader_Status_t status = OBJLOADER_OK;

  status = OBJLoader_Destroy(data);

  return status;
}

int OBJLoader_IsValid(const OBJData_t *data) {
  int status = 1;

  if (!data) {
    status = 0;
  }

  if (status) {
    status = OBJLoader_IsValid_FileName(data);
  }

  if (status) {
    status = OBJLoader_IsValid_FacesData(data);
  }

  if (status) {
    status = OBJLoader_IsValid_VerticesData(data);
  }

  if (status) {
    status = OBJLoader_IsValid_InvalidData(data);
  }

  return status;
}
