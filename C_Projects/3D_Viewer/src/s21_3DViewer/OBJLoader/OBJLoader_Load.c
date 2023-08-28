#include "OBJLoader_Util.h"

#define INIT_SIZE (1024)

OBJLoader_Status_t OBJLoader_Load_OBJData(OBJData_t *data, FILE *fp) {
  if (!OBJLoader_IsValid(data) || !fp) {
    return OBJLOADER_ERROR_INVALID_ARGUMENT;
  }

  fseek(fp, 0, SEEK_SET);  // rewind to start of file

  OBJLoader_Status_t status = OBJLOADER_OK;

  DBuffer_t *fileLine = NULL;
  if (!(fileLine = DBuffer_Create(sizeof(char), INIT_SIZE))) {
    status = OBJLOADER_ERROR_BAD_ALLOCATION;
  }

  int64_t lineNumber = 0;
  while (status == OBJLOADER_OK &&
         OBJLoader_Getline(fileLine, fp) != OBJLOADER_EOF) {
    ++lineNumber;

    char *str = OBJLoader_SkipWhitespace(fileLine->data);

    if (!str) {  // check it here, not to check it in parse functions
      status = OBJLOADER_ERROR_INTERNAL;
    }

    if (status == OBJLOADER_OK && !strlen(str)) {  // if empty string
      continue;
    }

    if (status == OBJLOADER_OK && (*str == 'v' && *(str + 1) == ' ')) {
      status = OBJLoader_ParseVertex(data, str);
    } else if (status == OBJLOADER_OK && (*str == 'f' && *(str + 1) == ' ')) {
      status = OBJLoader_ParseFace(data, str);
    }

    if (status ==
        OBJLOADER_WARNING_INCORRECT_DATA_IN_FILE) {  // add error line to buffer
      if (OBJLoader_InvalidData(data, fileLine->data, lineNumber) !=
          OBJLOADER_OK) {
        status = OBJLOADER_ERROR_INTERNAL;
      } else {
        status = OBJLOADER_OK;
      }
    }
  }

  DBuffer_Destroy(fileLine);

  return status;
}
