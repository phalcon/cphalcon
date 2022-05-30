/**
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code. If you did not receive
 * a copy of the license it is available through the world-wide-web at the
 * following url: https://docs.zephir-lang.com/en/latest/license
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include <php_main.h>
#include <main/php_streams.h>
#include <ext/standard/file.h>
#include <ext/standard/php_smart_string.h>
#include <ext/standard/php_filestat.h>
#include <ext/standard/php_string.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/file.h"

#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>
#include <zend_smart_str.h>

#define PHP_STREAM_TO_ZVAL(stream, arg) \
	php_stream_from_zval_no_verify(stream, arg); \
	if (stream == NULL) {   \
		if (return_value) { \
			RETURN_FALSE;   \
		} else { \
			return; \
		} \
	}

void zephir_basename(zval *return_value, zval *path)
{
	if (EXPECTED(Z_TYPE_P(path) == IS_STRING)) {
		zend_string *ret;
		ret = php_basename(Z_STRVAL_P(path), Z_STRLEN_P(path), NULL, 0);
		ZVAL_STR(return_value, ret);
	} else {
		ZVAL_FALSE(return_value);
	}
}

/**
 * Checks if a file exist
 *
 */
int zephir_file_exists(zval *filename)
{
	zval return_value;

	if (Z_TYPE_P(filename) != IS_STRING) {
		return FAILURE;
	}

#if PHP_VERSION_ID >= 80100
	zend_string *file = zend_string_init(Z_STRVAL_P(filename), Z_STRLEN_P(filename), 0);
	php_stat(file, FS_EXISTS, &return_value);
	zval_ptr_dtor(file);
#else
	php_stat(Z_STRVAL_P(filename), (php_stat_len) Z_STRLEN_P(filename), FS_EXISTS, &return_value);
#endif

	if (Z_TYPE(return_value) != IS_TRUE) {
		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Compares two file paths returning 1 if the first mtime is greater or equal than the second
 */
int zephir_compare_mtime(zval *filename1, zval *filename2)
{
	php_stream_statbuf statbuffer1, statbuffer2;

	if (Z_TYPE_P(filename1) != IS_STRING || Z_TYPE_P(filename2) != IS_STRING) {
		php_error_docref(NULL, E_WARNING, "Invalid arguments supplied for compare_mtime()");
		return 0;
	}

	if (php_stream_stat_path_ex(Z_STRVAL_P(filename1), 0, &statbuffer1, NULL)) {
		php_error_docref(NULL, E_WARNING, "mstat failed for %s", Z_STRVAL_P(filename1));
		return 0;
	}

	if (php_stream_stat_path_ex(Z_STRVAL_P(filename2), 0, &statbuffer2, NULL)) {
		php_error_docref(NULL, E_WARNING, "mstat failed for %s", Z_STRVAL_P(filename2));
		return 0;
	}

	return (int) (statbuffer1.sb.st_mtime >= statbuffer2.sb.st_mtime);
}

void zephir_fwrite(zval *return_value, zval *stream_zval, zval *data)
{
	int num_bytes;
	php_stream *stream;

	if (Z_TYPE_P(stream_zval) != IS_RESOURCE) {
		php_error_docref(NULL, E_WARNING, "Invalid arguments supplied for zephir_fwrite()");
		if (return_value) {
			RETVAL_FALSE;
		} else {
			return;
		}
	}

	if (Z_TYPE_P(data) != IS_STRING) {
		/* @todo convert data to string */
		php_error_docref(NULL, E_WARNING, "Invalid arguments supplied for zephir_fwrite()");
		if (return_value) {
			RETVAL_FALSE;
		} else {
			return;
		}
	}

	if (!Z_STRLEN_P(data)) {
		if (return_value) {
			RETURN_LONG(0);
		} else {
			return;
		}
	}

	PHP_STREAM_TO_ZVAL(stream, stream_zval);

	num_bytes = php_stream_write(stream, Z_STRVAL_P(data), Z_STRLEN_P(data));
	if (return_value) {
		RETURN_LONG(num_bytes);
	}
}

int zephir_feof(zval *stream_zval)
{
	php_stream *stream;

	if (Z_TYPE_P(stream_zval) != IS_RESOURCE) {
		php_error_docref(NULL, E_WARNING, "Invalid arguments supplied for zephir_feof()");
		return 0;
	}

	php_stream_from_zval_no_verify(stream, stream_zval);
	if (stream == NULL) {
		return 0;
	}

	return php_stream_eof(stream);
}

int zephir_fclose(zval *stream_zval)
{
	php_stream *stream;

	if (Z_TYPE_P(stream_zval) != IS_RESOURCE) {
		php_error_docref(NULL, E_WARNING, "Invalid arguments supplied for zephir_fclose()");
		return 0;
	}

	if ((stream = (php_stream*)zend_fetch_resource2(Z_RES_P(stream_zval), "stream", php_file_le_stream(), php_file_le_pstream())) == NULL) {
		return 0;
	}

	if ((stream->flags & PHP_STREAM_FLAG_NO_FCLOSE) != 0) {
		php_error_docref(NULL, E_WARNING, "%d is not a valid stream resource", stream->res->handle);
		return 0;
	}

	php_stream_free(stream, PHP_STREAM_FREE_KEEP_RSRC | (stream->is_persistent ? PHP_STREAM_FREE_CLOSE_PERSISTENT : PHP_STREAM_FREE_CLOSE));

	return 1;
}

void zephir_file_get_contents(zval *return_value, zval *filename)
{
	zend_string *contents;
	php_stream *stream;
	long maxlen = PHP_STREAM_COPY_ALL;
	zval *zcontext = NULL;
	php_stream_context *context = NULL;

	if (Z_TYPE_P(filename) != IS_STRING) {
		php_error_docref(NULL, E_WARNING, "Invalid arguments supplied for zephir_file_get_contents()");
		RETVAL_FALSE;
		return;
	}

	context = php_stream_context_from_zval(zcontext, 0);

	stream = php_stream_open_wrapper_ex(Z_STRVAL_P(filename), "rb", 0 | REPORT_ERRORS, NULL, context);
	if (!stream) {
		RETURN_FALSE;
	}

	if ((contents = php_stream_copy_to_mem(stream, maxlen, 0)) != NULL) {
		RETVAL_STR(contents);
	} else {
		RETVAL_EMPTY_STRING();
	}

	php_stream_close(stream);
}

/**
 * Writes a zval to a stream
 */
void zephir_file_put_contents(zval *return_value, zval *filename, zval *data)
{
	php_stream *stream;
	int numbytes = 0, use_copy = 0;
	zval *zcontext = NULL;
	zval copy;
	php_stream_context *context = NULL;

	if (Z_TYPE_P(filename) != IS_STRING) {
		php_error_docref(NULL, E_WARNING, "Invalid arguments supplied for zephir_file_put_contents()");
		if (return_value) {
			RETVAL_FALSE;
		}
		return;
	}

	context = php_stream_context_from_zval(zcontext, 0 & PHP_FILE_NO_DEFAULT_CONTEXT);

	stream = php_stream_open_wrapper_ex(Z_STRVAL_P(filename), "wb", ((0 & PHP_FILE_USE_INCLUDE_PATH) ? USE_PATH : 0) | REPORT_ERRORS, NULL, context);
	if (stream == NULL) {
		if (return_value) {
			RETURN_FALSE;
		}
		return;
	}

	switch (Z_TYPE_P(data)) {
		case IS_NULL:
		case IS_LONG:
		case IS_DOUBLE:
		case IS_TRUE:
		case IS_FALSE:
		case IS_CONSTANT_AST:
			use_copy = zend_make_printable_zval(data, &copy);
			if (use_copy) {
				data = &copy;
			}
			/* no break */

		case IS_STRING:
			if (Z_STRLEN_P(data)) {
				numbytes = php_stream_write(stream, Z_STRVAL_P(data), Z_STRLEN_P(data));
				if (numbytes != Z_STRLEN_P(data)) {
					php_error_docref(NULL, E_WARNING, "Only %d of %zu bytes written, possibly out of free disk space", numbytes, Z_STRLEN_P(data));
					numbytes = -1;
				}
			}
			break;
		default:
			numbytes = -1;
			break;
	}

	php_stream_close(stream);

	if (use_copy) {
		zval_dtor(data);
	}

	if (numbytes < 0) {
		if (return_value) {
			RETURN_FALSE;
		} else {
			return;
		}
	}

	if (return_value) {
		RETURN_LONG(numbytes);
	}
	return;
}

void zephir_filemtime(zval *return_value, zval *path)
{
	if (EXPECTED(Z_TYPE_P(path) == IS_STRING)) {
#if PHP_VERSION_ID >= 80100
		zend_string *file = zend_string_init(Z_STRVAL_P(path), Z_STRLEN_P(path), 0);
		php_stat(file, FS_MTIME, return_value);
		zval_ptr_dtor(file);
#else
		php_stat(Z_STRVAL_P(path), (php_stat_len)(Z_STRLEN_P(path)), FS_MTIME, return_value);
#endif
	} else {
		ZVAL_FALSE(return_value);
	}
}

/**
 * Replaces directory separators by the virtual separator
 */
void zephir_prepare_virtual_path(zval *return_value, zval *path, zval *virtual_separator)
{
	unsigned int i;
	unsigned char ch;
	smart_str virtual_str = {0};

	if (Z_TYPE_P(path) != IS_STRING || Z_TYPE_P(virtual_separator) != IS_STRING) {
		if (Z_TYPE_P(path) == IS_STRING) {
			RETURN_STR(zval_get_string(path));
		} else {
			RETURN_EMPTY_STRING();
		}
		return;
	}

	for (i = 0; i < Z_STRLEN_P(path); i++) {
		ch = Z_STRVAL_P(path)[i];
		if (ch == '\0') {
			break;
		}
		if (ch == '/' || ch == '\\' || ch == ':') {
			smart_str_appendl(&virtual_str, Z_STRVAL_P(virtual_separator), Z_STRLEN_P(virtual_separator));
		}
		else {
			smart_str_appendc(&virtual_str, tolower(ch));
		}
	}

	smart_str_0(&virtual_str);

	if (virtual_str.s) {
		RETURN_STR(virtual_str.s);
	} else {
		RETURN_EMPTY_STRING();
	}
}

/**
 * Generates a unique id for a path
 */
void zephir_unique_path_key(zval *return_value, zval *path)
{
	unsigned long h;
	char *strKey;

	if (Z_TYPE_P(path) != IS_STRING) {
		return;
	}

	h = zend_hash_func(Z_STRVAL_P(path), Z_STRLEN_P(path) + 1);

	strKey = emalloc(24);
	sprintf(strKey, "v%lu", h);

	RETVAL_STRING(strKey);
	efree(strKey);
}
