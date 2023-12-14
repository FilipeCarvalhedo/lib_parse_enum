// Autor: FilipeCarvalhedo
// Data: 2023-12-13
// Este código é uma adaptação feita pelo OpenAI GPT-3.5.

#ifndef LIB_PARSE_ENUM_H
#define LIB_PARSE_ENUM_H

/**
 * Define max line length
 *
 */
#define MAX_LINE_LENGTH 1024

/**@brief Function to write a record to storage file system.
 *
 * @details This function can be used to write a original and backup record to storage.
 *
 * @param[in] 	file_id     	Identification of the file.	
 * @param[in]  	record_key      The record key of data.
 * @param[in]  	data 			Address of data to be stored.
 * @param[in]  	length     		The size in bytes of data.
 *
 * @retval  LK_SUCCESS                 			If the operation was queued successfully.
 * @retval  LK_ERROR_STORAGE_NOT_INIT         	If the module is not initialized.
 * @retval  LK_ERROR_STORAGE_NULL				If data pointer is NULL.
 * @retval  LK_ERROR_STORAGE_MAX_SIZE     		If data is bigger than LK_STORAGE_MAX_DATA_SIZE.
 * @retval  LK_ERROR_STORAGE_BACKUP_WRITE       If writer error ocurred on backup area.
 */


/**@brief Function to take enum in a c file and parse the positions to enum name.
 *
 * @details This function can be used to create a list of a enumarator.
 *
* @param[in] 	enum_name     	Name of required enum on file.
* @param[in] 	filePath    	File path of c enum code.
* @param[in] 	glow_divisor    In Glow mode this is the lowest bright that rgb will arrive.
*
 * @retval  LK_SUCCESS                 			If the operation was queued successfully.
*/

char **lib_parse_enum(const char *enumName, const char *filePath);

#endif //LIB_PARSE_ENUM_H