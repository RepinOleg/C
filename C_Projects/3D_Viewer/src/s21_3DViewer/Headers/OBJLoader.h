#ifndef __OBJLOADER_H__
#define __OBJLOADER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "DynamicBuffer.h"

/*!
 * \defgroup OBJLoader OBJLoader
 * \brief Data structure to keep *.obj file format
 */

///@{
/*!
 * \struct Vertex
 * \brief Keeps point in 3D space
 * \var Vertex_t::x
 * x coordinate
 * \var Vertex_t::y
 * y coordinate
 * \var Vertex_t::z
 * z coordinate
 * \var Vertex_t::w
 * w (weight), not required, default is 1.0
 */
typedef struct Vertex {
  double x;
  double y;
  double z;
  double w;
} Vertex_t;

/*!
 * \struct VerticesData
 * \brief Keeps an array of Vertex_t and minmax points
 * \var VerticesData_t::vertices
 * Array of Vertex_t
 * \var VerticesData_t::amount
 * Amount of Vertex_t + 1, because indexes starts from 1
 * \var VerticesData_t::xMinMax
 * keeps min and max value for x coordinate
 * \var VerticesData_t::yMinMax
 * keeps min and max value for y coordinate
 * \var VerticesData_t::zMinMax
 * keeps min and max value for z coordinate
 */
typedef struct VerticesData {
  DBuffer_t *vertices;
  int64_t amount;

  double xMinMax[2];
  double yMinMax[2];
  double zMinMax[2];
} VerticesData_t;

/*!
 * \struct FacetIndex
 * \brief Keeps index of Vertex_t for faces
 * \var FacetIndex_t::v
 * index for Vertex_t
 * \var FacetIndex_t::vt
 * not used
 * \var FacetIndex_t::vn
 * not used
 */
typedef struct FacetIndex {
  int64_t v;
  int64_t vt;
  int64_t vn;
} FacetIndex_t;

/*!
 * \struct FacesData
 * \brief Keeps surfaces
 * \var FacesData_t::faces
 * array of pointers
 * \var FacesData_t::amount
 * amount of surfaces
 */
typedef struct FacesData {
  DBuffer_t *faces;
  int64_t amount;
} FacesData_t;

/*!
 * \struct InvalidLine
 * \brief Keeps invalid lines for logging
 * \var InvalidLine_t::line
 * invalid string
 * \var InvalidLine_t::lineNumber
 * number of string in file
 */
typedef struct InvalidLine {
  char *line;
  int64_t lineNumber;
} InvalidLine_t;

/*!
 * \struct InvalidData
 * \brief Keeps an array of InvalidLine_t
 * \var InvalidData_t::lines
 * array of InvalidLine_t
 * \var InvalidData_t::amount
 * number of data in array
 */
typedef struct InvalidData {
  DBuffer_t *lines;
  int64_t amount;
} InvalidData_t;

/*!
 * \struct OBJData
 * \brief Keeps whole *.obj file data
 * \var OBJData_t::verticesData
 * \var OBJData_t::facesData
 * \var OBJData_t::fileName
 * \var OBJData_t::invalidData
 */
typedef struct OBJData {
  VerticesData_t *verticesData;
  FacesData_t *facesData;
  char *fileName;

  InvalidData_t *invalidData;
} OBJData_t;

/// Types of possible status
typedef enum OBJLoader_Status {
  OBJLOADER_OK = 0,                          ///< All OK
  OBJLOADER_EOF,                             ///< End of file reached
  OBJLOADER_WARNING_INCORRECT_DATA_IN_FILE,  ///< Warned if there are possible
                                             ///< error
  OBJLOADER_ERROR_INVALID_ARGUMENT,          ///< NULL in arg or smth
  OBJLOADER_ERROR_BAD_ALLOCATION,            ///< Errors during allocations
  OBJLOADER_ERROR_BAD_FILE,                  ///< Cant open or find file
  OBJLOADER_ERROR_INTERNAL,                  ///< Other errors during run-time
  OBJLOADER_STATUS_AMOUNT,                   ///< Amount of status
} OBJLoader_Status_t;

/*!
 * \brief Load all used file data
 * \param[in] fileName File path
 * \return Instance of OBJData_t
 */
extern OBJData_t *OBJLoader_Load(const char *fileName);

/*!
 * \brief Release allocated memory
 * \param[in, out] data Instance of OBJData_t
 * \return OBJLoader_Status_t as result
 */
extern OBJLoader_Status_t OBJLoader_Dump(OBJData_t *data);

/*!
 * \brief Checks if all data is valid
 * \param[in] data Instance of OBJData_t
 * \return 1 - valid, 0 - invalid
 */
extern int OBJLoader_IsValid(const OBJData_t *data);
///@}

#ifdef __cplusplus
}
#endif

#endif  // __OBJLOADER_H__
