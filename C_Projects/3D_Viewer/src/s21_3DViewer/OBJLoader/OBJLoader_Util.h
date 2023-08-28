#ifndef __OBJLOADER_UTIL_H__
#define __OBJLOADER_UTIL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <ctype.h>
#include <stdio.h>

#include "../Headers/OBJLoader.h"

/*!
 * \defgroup OBJLoader_Util OBJLoader_Util functions
 * \ingroup OBJLoader
 */

///@{
/*!
 * \brief Initialize all field in OBJData_t struct
 * \param[in] fileName Path to file
 * \return Instance of OBJData_t
 */
extern OBJData_t *OBJLoader_Create(const char *fileName);

extern OBJLoader_Status_t OBJLoader_Create_FileName(OBJData_t *data,
                                                    const char *fileName);
extern OBJLoader_Status_t OBJLoader_Create_FacesData(OBJData_t *data);
extern OBJLoader_Status_t OBJLoader_Create_VerticesData(OBJData_t *data);
extern OBJLoader_Status_t OBJLoader_Create_InvalidData(OBJData_t *data);

/*!
 * \brief Load data from file to struct
 * \param[in, out] data Instance of OBJData_t
 * \param[in, out] fp Opened file thread
 * \return OBJLoader_Status_t
 */
extern OBJLoader_Status_t OBJLoader_Load_OBJData(OBJData_t *data, FILE *fp);

/*!
 * \brief Releases fields allocated memory in struct
 * \param[in, out] Instance of OBJData_t
 * \return OBJLoader_Status_t
 */
extern OBJLoader_Status_t OBJLoader_Destroy(OBJData_t *data);
extern void OBJLoader_Destroy_FileName(OBJData_t *data,
                                       OBJLoader_Status_t *status);
extern void OBJLoader_Destroy_FacesData(OBJData_t *data,
                                        OBJLoader_Status_t *status);
extern void OBJLoader_Destroy_VerticesData(OBJData_t *data,
                                           OBJLoader_Status_t *status);
extern void OBJLoader_Destroy_InvalidData(OBJData_t *data,
                                          OBJLoader_Status_t *status);

extern int OBJLoader_IsValid_FileName(const OBJData_t *data);
extern int OBJLoader_IsValid_FacesData(const OBJData_t *data);
extern int OBJLoader_IsValid_VerticesData(const OBJData_t *data);
extern int OBJLoader_IsValid_InvalidData(const OBJData_t *data);

/*!
 * \brief Parses string for vertices from file
 * \param[in, out] data Instance of OBJData_t
 * \param[in, out] str File line
 * \return OBJLoader_Status_t
 */
extern OBJLoader_Status_t OBJLoader_ParseVertex(OBJData_t *data, char *str);

/*!
 * \brief Parses string for faces from file
 * \param[in, out] data Instance of OBJData_t
 * \param[in, out] str File line
 * \return OBJLoader_Status_t
 */
extern OBJLoader_Status_t OBJLoader_ParseFace(OBJData_t *data, char *str);

/*!
 * \brief Reads line from file
 * \param[in, out] buf Dynamic Buffer for string
 * \param[in, out] fp Opened file thread
 * \return OBJLoader_Status_t
 */
extern OBJLoader_Status_t OBJLoader_Getline(DBuffer_t *buf, FILE *fp);

/*!
 * \brief Deletes whitespaces from string
 * \param[in] str Input string
 * \return Same string
 */
extern char *OBJLoader_SkipWhitespace(const char *str);

/*!
 * \brief Add data about invalid line to OBJData_t instance
 * \param[in, out] Instance of OBJData_t
 * \param[in] fileLine Error line
 * \param[in] fileLineNumber Error line number
 * \return OBJLoader_Status_t
 */
extern OBJLoader_Status_t OBJLoader_InvalidData(OBJData_t *data,
                                                const char *fileLine,
                                                const int64_t fileLineNumber);
///@}

#ifdef __cplusplus
}
#endif

#endif  // __OBJLOADERUTIL_H__
