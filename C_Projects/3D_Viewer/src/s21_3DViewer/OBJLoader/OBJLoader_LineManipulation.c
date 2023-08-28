#include "OBJLoader_Util.h"

char *OBJLoader_SkipWhitespace(const char *str) {
  char *returnValue = NULL;

  if (str) {
    while (*str == ' ' || *str == '\t') {
      ++str;
    }

    returnValue = (char *)str;
  }

  return returnValue;
}
