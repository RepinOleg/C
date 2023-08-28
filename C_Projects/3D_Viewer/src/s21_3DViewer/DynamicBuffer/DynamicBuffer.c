#include "../Headers/DynamicBuffer.h"

#define INIT_CAPACITY 10
#define GROWTH_FACTOR 1.5

DBuffer_t *DBuffer_Create(const int64_t dataSize, const int64_t initCapacity) {
  if (dataSize < 1) {
    return NULL;
  }

  DBuffer_t *buf = NULL;

  DBuffer_Status_t status = DBUFFER_OK;

  if (!(buf = (DBuffer_t *)calloc(1, sizeof(DBuffer_t)))) {
    status = DBUFFER_ERROR_BAD_ALLOCATION;
  } else {
    int64_t capacity = initCapacity > 0 ? initCapacity : INIT_CAPACITY;
    if (!(buf->data = malloc(dataSize * capacity))) {
      status = DBUFFER_ERROR_BAD_ALLOCATION;
    } else {
      buf->dataSize = dataSize;
      buf->length = 0;
      buf->capacity = capacity;
    }
  }

  if (status != DBUFFER_OK) {
    DBuffer_Destroy(buf);
    buf = NULL;
  }

  return buf;
}

DBuffer_Status_t DBuffer_Destroy(DBuffer_t *buf) {
  DBuffer_Status_t status = DBUFFER_OK;

  if (!buf) {
    status = DBUFFER_ERROR_INVALID_ARGUMENT;
  } else {
    if (!buf->data) {
      status = DBUFFER_ERROR_INVALID_ARGUMENT;
    } else {
      free(buf->data);
      buf->data = NULL;
    }

    buf->dataSize = buf->length = buf->capacity = 0;

    free(buf);
  }

  return status;
}

DBuffer_Status_t DBuffer_Reserve(DBuffer_t *buf, const int64_t newCapacity) {
  if (!DBuffer_IsValid(buf) || newCapacity < 0) {
    return DBUFFER_ERROR_INVALID_ARGUMENT;
  }

  DBuffer_Status_t status = DBUFFER_OK;

  if (newCapacity > buf->capacity) {
    if (!(buf->data = realloc(buf->data, buf->dataSize * newCapacity))) {
      status = DBUFFER_ERROR_BAD_ALLOCATION;
    } else {
      buf->capacity = newCapacity;
    }
  }

  return status;
}

DBuffer_Status_t DBuffer_Insert(DBuffer_t *buf, const void *newData,
                                const int64_t newDataAmount,
                                const int64_t index) {
  if (!DBuffer_IsValid(buf) || !newData || newDataAmount < 1 || index < 0 ||
      index > buf->length) {
    return DBUFFER_ERROR_INVALID_ARGUMENT;
  }

  DBuffer_Status_t status = DBUFFER_OK;

  if (buf->length + newDataAmount - 1 >= buf->capacity) {
    if (!(buf->data = realloc(buf->data,
                              buf->dataSize * buf->capacity * GROWTH_FACTOR))) {
      status = DBUFFER_ERROR_BAD_ALLOCATION;
    } else {
      buf->capacity *= GROWTH_FACTOR;
    }
  }

  if (status == DBUFFER_OK) {
    memmove((char *)buf->data + buf->dataSize * (index + newDataAmount),
            (char *)buf->data + buf->dataSize * index,
            buf->dataSize * (buf->length - index));  // move data to right

    memmove((char *)buf->data + buf->dataSize * index, newData,
            buf->dataSize * newDataAmount);  // insert data in free space

    buf->length += newDataAmount;
  }

  return status;
}

DBuffer_Status_t DBuffer_Erase(DBuffer_t *buf, const int64_t eraseDataAmount,
                               const int64_t index) {
  if (!DBuffer_IsValid(buf) || eraseDataAmount < 1 || index < 0 ||
      index >= buf->length) {  // todo test index
    return DBUFFER_ERROR_INVALID_ARGUMENT;
  }

  DBuffer_Status_t status = DBUFFER_OK;

  if (buf->length - index - eraseDataAmount < 0) {
    status = DBUFFER_ERROR_INVALID_ARGUMENT;
  } else {
    memmove((char *)buf->data + buf->dataSize * index,
            (char *)buf->data + buf->dataSize * (index + eraseDataAmount),
            buf->dataSize *
                (buf->length - index - eraseDataAmount));  // move data to left

    buf->length -= eraseDataAmount;
  }

  return status;
}

DBuffer_Status_t DBuffer_Clear(DBuffer_t *buf) {
  if (!DBuffer_IsValid(buf)) {
    return DBUFFER_ERROR_INVALID_ARGUMENT;
  }

  buf->length = 0;

  return DBUFFER_OK;
}

void *DBuffer_GetData(const DBuffer_t *buf, const int64_t index) {
  if (!DBuffer_IsValid(buf) || index < 0 || index >= buf->length) {
    return NULL;
  }

  return (char *)buf->data + buf->dataSize * index;
}

DBuffer_Status_t DBuffer_PushBack(DBuffer_t *buf, const void *newData,
                                  const int64_t newDataAmount) {
  if (!DBuffer_IsValid(buf) || !newData || newDataAmount < 1) {
    return DBUFFER_ERROR_INVALID_ARGUMENT;
  }

  return DBuffer_Insert(buf, newData, newDataAmount, buf->length);
}

DBuffer_Status_t DBuffer_PopBack(DBuffer_t *buf,
                                 const int64_t eraseDataAmount) {
  if (!DBuffer_IsValid(buf) || eraseDataAmount < 1) {
    return DBUFFER_ERROR_INVALID_ARGUMENT;
  }

  return DBuffer_Erase(buf, eraseDataAmount, buf->length - 1);
}

DBuffer_Status_t DBuffer_PushFront(DBuffer_t *buf, const void *newData,
                                   const int64_t newDataAmount) {
  if (!DBuffer_IsValid(buf) || !newData || newDataAmount < 1) {
    return DBUFFER_ERROR_INVALID_ARGUMENT;
  }

  return DBuffer_Insert(buf, newData, newDataAmount, 0);
}

DBuffer_Status_t DBuffer_PopFront(DBuffer_t *buf,
                                  const int64_t eraseDataAmount) {
  if (!DBuffer_IsValid(buf) || eraseDataAmount < 1) {
    return DBUFFER_ERROR_INVALID_ARGUMENT;
  }

  return DBuffer_Erase(buf, eraseDataAmount, 0);
}

int DBuffer_IsValid(const DBuffer_t *buf) {
  return (buf && buf->data && buf->dataSize > 0 && buf->length >= 0 &&
          buf->capacity > 0);
}
