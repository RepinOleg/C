#include "OBJLoader_Util.h"

OBJLoader_Status_t OBJLoader_ParseVertex(
    OBJData_t *data, char *str) {  // change ',' in file to '.'
  if (!str) {                      // do not check data, because its too slow
    return OBJLOADER_ERROR_INVALID_ARGUMENT;
  }

  ++str;  // move from 'v'

  OBJLoader_Status_t status = OBJLOADER_OK;

  char *endPtr = str;
  double readNumber = 0.0;
  Vertex_t vertex = {0.0, 0.0, 0.0, 1.0};

  for (int i = 0; i < 3; ++i) {  // read x, y, z
    str = OBJLoader_SkipWhitespace(str);

    readNumber = strtod(str, &endPtr);
    if (str == endPtr) {
      status = OBJLOADER_WARNING_INCORRECT_DATA_IN_FILE;
      break;
    } else {
      if (i == 0) {
        vertex.x = readNumber;
      } else if (i == 1) {
        vertex.y = readNumber;
      } else if (i == 2) {
        vertex.z = readNumber;
      }
      str = endPtr;
    }
  }

  if (status == OBJLOADER_OK) {  // check for [w]
    str = OBJLoader_SkipWhitespace(str);

    if (*str) {
      readNumber = strtod(str, &endPtr);
      if (str == endPtr) {
        status = OBJLOADER_WARNING_INCORRECT_DATA_IN_FILE;
      } else {
        vertex.w = readNumber;
        str = endPtr;

        str = OBJLoader_SkipWhitespace(
            str);  // check remaining string for extran char
        if (*str) {
          status = OBJLOADER_WARNING_INCORRECT_DATA_IN_FILE;
        }
      }
    }
  }

  if (status == OBJLOADER_OK) {
    if (DBuffer_PushBack(data->verticesData->vertices, &vertex, 1) !=
        DBUFFER_OK) {
      status = OBJLOADER_ERROR_INTERNAL;
    } else {
      ++(data->verticesData->amount);

      if (data->verticesData->amount == 2) {  // if first vertex than initialize
        data->verticesData->xMinMax[0] = data->verticesData->xMinMax[1] =
            vertex.x;
        data->verticesData->yMinMax[0] = data->verticesData->yMinMax[1] =
            vertex.y;
        data->verticesData->zMinMax[0] = data->verticesData->zMinMax[1] =
            vertex.z;
      } else {  // else find min, max for x, y, z
        if (vertex.x < data->verticesData->xMinMax[0]) {
          data->verticesData->xMinMax[0] = vertex.x;
        } else if (vertex.x > data->verticesData->xMinMax[1]) {
          data->verticesData->xMinMax[1] = vertex.x;
        }

        if (vertex.y < data->verticesData->yMinMax[0]) {
          data->verticesData->yMinMax[0] = vertex.y;
        } else if (vertex.y > data->verticesData->yMinMax[1]) {
          data->verticesData->yMinMax[1] = vertex.y;
        }

        if (vertex.z < data->verticesData->zMinMax[0]) {
          data->verticesData->zMinMax[0] = vertex.z;
        } else if (vertex.z > data->verticesData->zMinMax[1]) {
          data->verticesData->zMinMax[1] = vertex.z;
        }
      }
    }
  }

  return status;
}

OBJLoader_Status_t OBJLoader_ParseFace(OBJData_t *data, char *str) {
  if (!str) {  // do not check data, because its too slow
    return OBJLOADER_ERROR_INVALID_ARGUMENT;
  }

  ++str;  // move from 'f'

  OBJLoader_Status_t status = OBJLOADER_OK;

  char *endPtr = str;
  int64_t readNumber = 0.0;
  FacetIndex_t facetIndex = {0, 0, 0};

  const int64_t initFacetCapacity = 4;
  DBuffer_t *facet = NULL;
  if (!(facet = DBuffer_Create(sizeof(FacetIndex_t), initFacetCapacity))) {
    status = OBJLOADER_ERROR_BAD_ALLOCATION;
  }

  int64_t i = 3;  // min amount of indexes needed to read
  while (status == OBJLOADER_OK && *str) {
    memset(&facetIndex, 0, sizeof(FacetIndex_t));

    str = OBJLoader_SkipWhitespace(str);
    if (!(*str)) {  // if end of string
      break;
    }

    readNumber = strtoll(str, &endPtr, 10);
    if (str == endPtr) {
      status = OBJLOADER_WARNING_INCORRECT_DATA_IN_FILE;
      break;
    } else {
      facetIndex.v = readNumber;
      str = endPtr;
    }

    if (*str == '/') {
      ++str;

      if (*str == '/') {
        ++str;

        readNumber = strtoll(str, &endPtr, 10);
        if (str == endPtr) {
          status = OBJLOADER_WARNING_INCORRECT_DATA_IN_FILE;
          break;
        } else {
          facetIndex.vn = readNumber;
          str = endPtr;
        }
      } else {
        readNumber = strtoll(str, &endPtr, 10);
        if (str == endPtr) {
          status = OBJLOADER_WARNING_INCORRECT_DATA_IN_FILE;
          break;
        } else {
          facetIndex.vt = readNumber;
          str = endPtr;
        }

        if (*str == '/') {
          ++str;

          readNumber = strtoll(str, &endPtr, 10);
          if (str == endPtr) {
            status = OBJLOADER_WARNING_INCORRECT_DATA_IN_FILE;
            break;
          } else {
            facetIndex.vn = readNumber;
            str = endPtr;
          }
        }
      }
    }

    --i;

    if (DBuffer_PushBack(facet, &facetIndex, 1) != DBUFFER_OK) {
      status = OBJLOADER_ERROR_INTERNAL;
    }
  }

  if (status == OBJLOADER_OK && i > 0) {
    status = OBJLOADER_WARNING_INCORRECT_DATA_IN_FILE;
  }

  if (status == OBJLOADER_OK) {
    if (DBuffer_PushBack(data->facesData->faces, &facet, 1) != DBUFFER_OK) {
      DBuffer_Destroy(facet);
      status = OBJLOADER_ERROR_INTERNAL;
    } else {
      ++(data->facesData->amount);
    }
  } else {
    DBuffer_Destroy(facet);
  }

  return status;
}
