/*
 * Copyright (c) 2011 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dlog.h>
#include <xdgmime.h>

#include <mime_type.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif

#define LOG_TAG "TIZEN_N_MIME_TYPE"

#define FILE_EXTENSION_DELIMITER '.'

static const char* mime_type_error_to_string(mime_type_error_e error)
{
	switch (error)
	{
	case MIME_TYPE_ERROR_NONE:
		return "NONE";

	case MIME_TYPE_ERROR_INVALID_PARAMETER:
		return "INVALID_PARAMETER";

	case MIME_TYPE_ERROR_OUT_OF_MEMORY:
		return "OUT_OF_MEMORY";

	case MIME_TYPE_ERROR_IO_ERROR:
		return "IO_ERROR";

	default :
		return "UNKNOWN";
	}
}

static int mime_type_error(mime_type_error_e error, const char* function, const char *description)
{
	if (description)
	{
		LOGE("[%s] %s(0x%08x) : %s", function, mime_type_error_to_string(error), error, description);
	}
	else
	{
		LOGE("[%s] %s(0x%08x)", function, mime_type_error_to_string(error), error);
	}

	return error;
}


int mime_type_get_mime_type(const char *file_extension, char **mime_type)
{
	char file_extension_with_dot[32] = {0, };
	const char *xdg_mime_type = NULL;

	if (file_extension == NULL || mime_type == NULL)
	{
		return mime_type_error(MIME_TYPE_ERROR_INVALID_PARAMETER, __FUNCTION__, NULL);
	}

	if (file_extension[0] == '\0')
	{
		return mime_type_error(MIME_TYPE_ERROR_INVALID_PARAMETER, __FUNCTION__, "the given file extension is an empy string");
	}

	if (file_extension[0] == FILE_EXTENSION_DELIMITER)
	{
		return mime_type_error(MIME_TYPE_ERROR_INVALID_PARAMETER, __FUNCTION__, "the given file extension includes the leading dot ('.')");
	}

	snprintf(file_extension_with_dot, sizeof(file_extension_with_dot), ".%s", file_extension);

	xdg_mime_type = xdg_mime_get_mime_type_from_file_name(file_extension_with_dot);

	if (xdg_mime_type == NULL || *xdg_mime_type == '\0')
	{
		*mime_type = NULL;
		return mime_type_error(MIME_TYPE_ERROR_IO_ERROR, __FUNCTION__, "failed to get the mime type from the shared MIME database");
	}

	char * mime_type_dup = NULL;

	mime_type_dup = strdup(xdg_mime_type);

	if (mime_type_dup == NULL)
	{
		return mime_type_error(MIME_TYPE_ERROR_OUT_OF_MEMORY, __FUNCTION__, NULL);
	}

	*mime_type = mime_type_dup;


	return MIME_TYPE_ERROR_NONE;
}

int mime_type_get_file_extension(const char *mime_type, char *** file_extension, int *length)
{
	const char **xdg_file_extension = NULL;
	int xdg_file_extension_length = 0;
	char **file_extension_array = NULL;
	int file_extension_array_index = 0;

	if (mime_type == NULL || file_extension == NULL || length == NULL)
	{
		return mime_type_error(MIME_TYPE_ERROR_INVALID_PARAMETER, __FUNCTION__, NULL);
	}

	if (mime_type[0] == '\0')
	{
		return mime_type_error(MIME_TYPE_ERROR_INVALID_PARAMETER, __FUNCTION__, "the given MIME type is an empy string");
	}

	xdg_file_extension = xdg_mime_get_file_names_from_mime_type(mime_type);

	if (xdg_file_extension == NULL)
	{
		return mime_type_error(MIME_TYPE_ERROR_IO_ERROR, __FUNCTION__, "failed to get the file extensions from the shared MIME database");
	}

	while (xdg_file_extension[xdg_file_extension_length] != NULL)
	{
		xdg_file_extension_length++;
	}

	file_extension_array = calloc(xdg_file_extension_length, sizeof(char*));

	if (file_extension_array == NULL)
	{
		return mime_type_error(MIME_TYPE_ERROR_OUT_OF_MEMORY, __FUNCTION__, NULL);
	}

	for (xdg_file_extension_length = 0; xdg_file_extension[xdg_file_extension_length] != NULL; xdg_file_extension_length++)
	{
		char *entry = NULL;

		entry = strrchr(xdg_file_extension[xdg_file_extension_length], FILE_EXTENSION_DELIMITER);

		if (entry != NULL)
		{
			entry++;
			file_extension_array[file_extension_array_index] = strdup(entry);
			file_extension_array_index++;
		}
	}

	*file_extension = file_extension_array;
	*length = file_extension_array_index;

	return MIME_TYPE_ERROR_NONE;
}

