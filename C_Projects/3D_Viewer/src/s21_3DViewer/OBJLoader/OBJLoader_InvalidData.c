#include "OBJLoader_Util.h"

OBJLoader_Status_t OBJLoader_InvalidData(OBJData_t *data, const char *fileLine,
                                         const int64_t fileLineNumber) {
  if (!OBJLoader_IsValid(data) || !fileLineNumber || fileLineNumber <= 0) {
    return OBJLOADER_ERROR_INVALID_ARGUMENT;
  }

  OBJLoader_Status_t status = OBJLOADER_OK;

  InvalidLine_t invalidLine = {0, 0};

  if (!(invalidLine.line =
            (char *)malloc(sizeof(char) * (strlen(fileLine) + 1)))) {
    status = OBJLOADER_ERROR_BAD_ALLOCATION;
  } else {
    strcpy(invalidLine.line, fileLine);
    invalidLine.lineNumber = fileLineNumber;

    if (DBuffer_PushBack(data->invalidData->lines, &invalidLine, 1) !=
        DBUFFER_OK) {
      free(invalidLine.line);
      status = OBJLOADER_ERROR_INTERNAL;
    } else {
      ++(data->invalidData->amount);
    }
  }

  return status;
}
