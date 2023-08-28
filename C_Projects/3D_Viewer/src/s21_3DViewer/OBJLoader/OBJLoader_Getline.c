#include "OBJLoader_Util.h"

OBJLoader_Status_t OBJLoader_Getline(DBuffer_t *buf, FILE *fp) {
  if (!DBuffer_IsValid(buf) || !fp) {
    return OBJLOADER_ERROR_INVALID_ARGUMENT;
  }

  int ch = 0;
  DBuffer_Clear(buf);

  OBJLoader_Status_t status = OBJLOADER_OK;

  while (status == OBJLOADER_OK && (ch = fgetc(fp)) != EOF) {
    if (DBuffer_PushBack(buf, &ch, 1) != DBUFFER_OK) {
      status = OBJLOADER_ERROR_INTERNAL;
    }

    if (status == OBJLOADER_OK && (ch == '\n' || ch == '\r')) {
      if (DBuffer_PopBack(buf, 1) == DBUFFER_OK &&
          DBuffer_PushBack(buf, &(char){'\0'}, 1) == DBUFFER_OK) {
        break;
      } else {
        status = OBJLOADER_ERROR_INTERNAL;
      }
    }
  }

  if (status == OBJLOADER_OK &&
      DBuffer_PushBack(buf, &(char){'\0'}, 1) != DBUFFER_OK) {
    status = OBJLOADER_ERROR_INTERNAL;
  }

  if (status == OBJLOADER_OK && ch == EOF && buf->length == 1) {
    status = OBJLOADER_EOF;
  }

  return status;
}
