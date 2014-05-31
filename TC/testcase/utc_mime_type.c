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

#include <tet_api.h>
#include <mime_type.h>

static void startup(void);
static void cleanup(void);

void (*tet_startup)(void) = startup;
void (*tet_cleanup)(void) = cleanup;

static void utc_mime_type_get_mime_type_positive1(void);
static void utc_mime_type_get_mime_type_positive2(void);
static void utc_mime_type_get_mime_type_positive3(void);
static void utc_mime_type_get_mime_type_positive4(void);
static void utc_mime_type_get_mime_type_positive5(void);
static void utc_mime_type_get_mime_type_positive5(void);

static void utc_mime_type_get_mime_type_negative1(void);
static void utc_mime_type_get_mime_type_negative2(void);
static void utc_mime_type_get_mime_type_negative3(void);

static void utc_mime_type_get_file_extension_positive1(void);
static void utc_mime_type_get_file_extension_positive2(void);

static void utc_mime_type_get_file_extension_negative1(void);
static void utc_mime_type_get_file_extension_negative2(void);
static void utc_mime_type_get_file_extension_negative3(void);
static void utc_mime_type_get_file_extension_negative4(void);

struct tet_testlist tet_testlist[] = {
	{utc_mime_type_get_mime_type_positive1, 1},
	{utc_mime_type_get_mime_type_positive2, 1},
	{utc_mime_type_get_mime_type_positive3, 1},
	{utc_mime_type_get_mime_type_positive4, 1},
	{utc_mime_type_get_mime_type_positive5, 1},

	{utc_mime_type_get_mime_type_negative1, 1},
	{utc_mime_type_get_mime_type_negative2, 1},
	{utc_mime_type_get_mime_type_negative3, 1},

	{utc_mime_type_get_file_extension_positive1, 1},
	{utc_mime_type_get_file_extension_positive2, 1},

	{utc_mime_type_get_file_extension_negative1, 1},
	{utc_mime_type_get_file_extension_negative2, 1},
	{utc_mime_type_get_file_extension_negative3, 1},
	{utc_mime_type_get_file_extension_negative4, 1},

	{NULL, 0},
};

static void startup(void)
{

}

static void cleanup(void)
{
	/* end of TC */
}

void utc_mime_type_get_mime_type_positive1(void)
{
	const char *TC_NAME = __FUNCTION__;

	int retcode;
	char *mime_type;

	retcode = mime_type_get_mime_type("png", &mime_type);

	if (retcode == MIME_TYPE_ERROR_NONE && !strcmp(mime_type, "image/png"))
	{
		dts_pass(TC_NAME, "passed");
	}
	else
	{
		dts_fail(TC_NAME, "failed");
	}
}

void utc_mime_type_get_mime_type_positive2(void)
{
	const char *TC_NAME = __FUNCTION__;

	int retcode;
	char *mime_type;

	retcode = mime_type_get_mime_type("jpg", &mime_type);

	if (retcode == MIME_TYPE_ERROR_NONE && !strcmp(mime_type, "image/jpeg"))
	{
		dts_pass(TC_NAME, "passed");
	}
	else
	{
		dts_fail(TC_NAME, "failed");
	}
}

void utc_mime_type_get_mime_type_positive3(void)
{
	const char *TC_NAME = __FUNCTION__;

	int retcode;
	char *mime_type;

	retcode = mime_type_get_mime_type("mpg", &mime_type);

	if (retcode == MIME_TYPE_ERROR_NONE && !strcmp(mime_type, "video/mpeg"))
	{
		dts_pass(TC_NAME, "passed");
	}
	else
	{
		dts_fail(TC_NAME, "failed");
	}
}

void utc_mime_type_get_mime_type_positive4(void)
{
	const char *TC_NAME = __FUNCTION__;

	int retcode;
	char *mime_type;

	retcode = mime_type_get_mime_type("mp3", &mime_type);

	if (retcode == MIME_TYPE_ERROR_NONE && !strcmp(mime_type, "audio/mpeg"))
	{
		dts_pass(TC_NAME, "passed");
	}
	else
	{
		dts_fail(TC_NAME, "failed");
	}
}


void utc_mime_type_get_mime_type_positive5(void)
{
	const char *TC_NAME = __FUNCTION__;

	int retcode;
	char *mime_type;

	retcode = mime_type_get_mime_type("bin", &mime_type);

	if (retcode == MIME_TYPE_ERROR_NONE && !strcmp(mime_type, "application/octet-stream"))
	{
		dts_pass(TC_NAME, "passed");
	}
	else
	{
		dts_fail(TC_NAME, "failed");
	}
}

void utc_mime_type_get_mime_type_positive6(void)
{
	const char *TC_NAME = __FUNCTION__;

	int retcode;
	char *mime_type;

	retcode = mime_type_get_mime_type("abcdef", &mime_type);

	if (retcode == MIME_TYPE_ERROR_NONE && !strcmp(mime_type, "application/octet-stream"))
	{
		dts_pass(TC_NAME, "passed");
	}
	else
	{
		dts_fail(TC_NAME, "failed");
	}
}


void utc_mime_type_get_mime_type_negative1(void)
{
	const char *TC_NAME = __FUNCTION__;

	int retcode;
	char *mime_type;

	retcode = mime_type_get_mime_type(NULL, &mime_type);

	if (retcode == MIME_TYPE_ERROR_INVALID_PARAMETER)
	{
		dts_pass(TC_NAME, "passed");
	}
	else
	{
		dts_fail(TC_NAME, "failed");
	}
}

void utc_mime_type_get_mime_type_negative2(void)
{
	const char *TC_NAME = __FUNCTION__;

	int retcode;
	char *mime_type;

	retcode = mime_type_get_mime_type("", &mime_type);

	if (retcode == MIME_TYPE_ERROR_INVALID_PARAMETER)
	{
		dts_pass(TC_NAME, "passed");
	}
	else
	{
		dts_fail(TC_NAME, "failed");
	}
}

void utc_mime_type_get_mime_type_negative3(void)
{
	const char *TC_NAME = __FUNCTION__;

	int retcode;

	retcode = mime_type_get_mime_type("mp3", NULL);

	if (retcode == MIME_TYPE_ERROR_INVALID_PARAMETER)
	{
		dts_pass(TC_NAME, "passed");
	}
	else
	{
		dts_fail(TC_NAME, "failed");
	}
}


void utc_mime_type_get_file_extension_positive1(void)
{
	const char *TC_NAME = __FUNCTION__;

	int retcode;
	char **file_extension;
	int length;

	retcode = mime_type_get_file_extension("video/mpeg", &file_extension, &length);

	if (retcode == MIME_TYPE_ERROR_NONE && length > 0)
	{
		dts_pass(TC_NAME, "passed");
	}
	else
	{
		dts_fail(TC_NAME, "failed");
	}
}

void utc_mime_type_get_file_extension_positive2(void)
{
	const char *TC_NAME = __FUNCTION__;

	int retcode;
	char **file_extension;
	int length;

	retcode = mime_type_get_file_extension("image/jpeg", &file_extension, &length);

	if (retcode == MIME_TYPE_ERROR_NONE && length > 0)
	{
		dts_pass(TC_NAME, "passed");
	}
	else
	{
		dts_fail(TC_NAME, "failed");
	}
}

void utc_mime_type_get_file_extension_negative1(void)
{
	const char *TC_NAME = __FUNCTION__;

	int retcode;
	char **file_extension;
	int length;

	retcode = mime_type_get_file_extension(NULL, &file_extension, &length);

	if (retcode == MIME_TYPE_ERROR_INVALID_PARAMETER)
	{
		dts_pass(TC_NAME, "passed");
	}
	else
	{
		dts_fail(TC_NAME, "failed");
	}
}

void utc_mime_type_get_file_extension_negative2(void)
{
	const char *TC_NAME = __FUNCTION__;

	int retcode;
	char **file_extension;
	int length;

	retcode = mime_type_get_file_extension("", &file_extension, &length);

	if (retcode == MIME_TYPE_ERROR_INVALID_PARAMETER)
	{
		dts_pass(TC_NAME, "passed");
	}
	else
	{
		dts_fail(TC_NAME, "failed");
	}
}

void utc_mime_type_get_file_extension_negative3(void)
{
	const char *TC_NAME = __FUNCTION__;

	int retcode;
	int length;

	retcode = mime_type_get_file_extension("image/jpeg", NULL, &length);

	if (retcode == MIME_TYPE_ERROR_INVALID_PARAMETER)
	{
		dts_pass(TC_NAME, "passed");
	}
	else
	{
		dts_fail(TC_NAME, "failed");
	}
}

void utc_mime_type_get_file_extension_negative4(void)
{
	const char *TC_NAME = __FUNCTION__;

	int retcode;
	char **file_extension;

	retcode = mime_type_get_file_extension("image/jpeg", &file_extension, NULL);

	if (retcode == MIME_TYPE_ERROR_INVALID_PARAMETER)
	{
		dts_pass(TC_NAME, "passed");
	}
	else
	{
		dts_fail(TC_NAME, "failed");
	}
}
