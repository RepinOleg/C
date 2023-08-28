#ifndef __DYNAMICBUFFER_H__
#define __DYNAMICBUFFER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/*!
 * \defgroup DynamicBuffer DynamicBuffer
 * \brief Vector like data structure for every data type
 */

///@{
/*!
 * \struct DynamicBuffer
 * \brief
 * \var DBuffer_t::data
 * void pointer for data
 * \var DBuffer_t::dataSize
 * size of current data
 * \var DBuffer_t::length
 * used size of buffer
 * \var DBuffer_t::capacity
 * actual size of buffer
 */
typedef struct DynamicBuffer {
  void *data;
  int64_t dataSize;
  int64_t length;
  int64_t capacity;
} DBuffer_t;

/// Types of possible return statuses
typedef enum DynamicBuffer_Status {
  DBUFFER_OK = 0,                  ///< All OK
  DBUFFER_ERROR_INVALID_ARGUMENT,  ///< NULL pointer or negative dataSize,
                                   ///< lenght, capacity
  DBUFFER_ERROR_BAD_ALLOCATION,    ///< Error during allocation
  DBUFFER_ERROR_INTERNAL,          ///< Some unexpected errors
  DBUFFER_STATUS_AMOUNT,           ///< Amount of statuses
} DBuffer_Status_t;

/*!
 * \brief Create instance of Dynamic Buffer
 * \param[in] dataSize Size of data for buffer
 * \param[in] initCapacity Init capacity for buffer. If < 0, capacity = 0
 * \return Pointer to DBuffer_t instance
 */
extern DBuffer_t *DBuffer_Create(const int64_t dataSize,
                                 const int64_t initCapacity);

/*!
 * \brief Release DBuffer_t pointer
 * \param[in] buf Instance of DBuffer_t
 * \return DBuffer_Status_t. Might be not OK if NULL passed or smth
 */
extern DBuffer_Status_t DBuffer_Destroy(DBuffer_t *buf);

/*!
 * \brief Reserves memory for buffer. If newCapacity < buf->capacity, it wont
 * reduce memory \param[in, out] buf Instance of DBuffer_t \param[in]
 * newCapacity New value for capacity \return DBuffer_Status_t. Errors during
 * memory allocations of bad arguments
 */
extern DBuffer_Status_t DBuffer_Reserve(DBuffer_t *buf,
                                        const int64_t newCapacity);

/*!
 * \brief Insert data in buffer
 * \param[in, out] buf Instance of DBuffer_t
 * \param[in] newData Pointer to data. Might be array
 * \param[in] newDataAmount Amount of data to insert
 * \param[in] index Index in buffer
 * \return DBuffer_Status_t. Errors during memory allocations of bad arguments
 */
extern DBuffer_Status_t DBuffer_Insert(DBuffer_t *buf, const void *newData,
                                       const int64_t newDataAmount,
                                       const int64_t index);

/*!
 * \brief Erase data from buffer
 * \param[in, out] buf Instance of DBuffer_t
 * \param[in] eraseDataAmount Amount of data to erase
 * \param[in] index Index in buffer
 * \return DBuffer_Status_t. Errors during memory allocations of bad arguments
 */
extern DBuffer_Status_t DBuffer_Erase(DBuffer_t *buf,
                                      const int64_t eraseDataAmount,
                                      const int64_t index);

/*!
 * \brief Clears data structure
 * \param[in, out] buf Instance of DBuffer_t
 * \return DBuffer_Status_t. Errors during memory allocations of bad arguments
 */
extern DBuffer_Status_t DBuffer_Clear(DBuffer_t *buf);

/*!
 * \brief Gets pointer to data from buffer
 * \param[in] buf Instance of DBuffer_t
 * \param[in] index Index in buffer
 * \return DBuffer_Status_t. Errors during memory allocations of bad arguments
 */
extern void *DBuffer_GetData(const DBuffer_t *buf, const int64_t index);

/*!
 * \brief Insert data in the end of buffer
 * \param[in, out] buf Instance of DBuffer_t
 * \param[in] newData Pointer to data. Might be array
 * \param[in] newDataAmount Amount of data to insert
 * \return DBuffer_Status_t. Errors during memory allocations of bad arguments
 */
extern DBuffer_Status_t DBuffer_PushBack(DBuffer_t *buf, const void *newData,
                                         const int64_t newDataAmount);

/*!
 * \brief Erase data from the end of buffer
 * \param[in, out] buf Instance of DBuffer_t
 * \param[in] eraseDataAmount Amount of data to erase
 * \return DBuffer_Status_t. Errors during memory allocations of bad arguments
 */
extern DBuffer_Status_t DBuffer_PopBack(DBuffer_t *buf,
                                        const int64_t eraseDataAmount);

/*!
 * \brief Insert data in the front of buffer
 * \param[in, out] buf Instance of DBuffer_t
 * \param[in] newData Pointer to data. Might be array
 * \param[in] newDataAmount Amount of data to insert
 * \return DBuffer_Status_t. Errors during memory allocations of bad arguments
 */
extern DBuffer_Status_t DBuffer_PushFront(DBuffer_t *buf, const void *newData,
                                          const int64_t newDataAmount);

/*!
 * \brief Erase data from the front of buffer
 * \param[in, out] buf Instance of DBuffer_t
 * \param[in] eraseDataAmount Amount of data to erase
 * \return DBuffer_Status_t. Errors during memory allocations of bad arguments
 */
extern DBuffer_Status_t DBuffer_PopFront(DBuffer_t *buf,
                                         const int64_t eraseDataAmount);

/*!
 * \brief Checks if DBuffer_t struct is valid. Check for NULL pointers and other
 * illegal values \param[in] buf Instance of DBuffer_t \return 1 - valid, 0 -
 * invalid
 */
extern int DBuffer_IsValid(const DBuffer_t *buf);
///@}

#ifdef __cplusplus
}
#endif

#endif  // __DYNAMICBUFFER_H__
