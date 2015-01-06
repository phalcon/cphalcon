
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#include "kernel/file.h"
#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/operators.h"

#include <ctype.h>

#include <main/php_streams.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>
#include <ext/standard/file.h>
#include <ext/standard/php_smart_str.h>
#include <ext/standard/php_filestat.h>
#include <ext/standard/php_string.h>

/**
 * Checks if a file exist
 *
 */
int phalcon_file_exists(zval *filename TSRMLS_DC){

	zval return_value;

	if (Z_TYPE_P(filename) != IS_STRING) {
		return FAILURE;
	}

	php_stat(Z_STRVAL_P(filename), (php_stat_len) Z_STRLEN_P(filename), FS_EXISTS, &return_value TSRMLS_CC);

	if (PHALCON_IS_FALSE((&return_value))) {
		return FAILURE;
	}

	if (PHALCON_IS_EMPTY((&return_value))) {
		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Compares two file paths returning 1 if the first mtime is greater or equal than the second
 */
int phalcon_compare_mtime(zval *filename1, zval *filename2 TSRMLS_DC){

	php_stream_statbuf statbuffer1, statbuffer2;

	if (Z_TYPE_P(filename1) != IS_STRING || Z_TYPE_P(filename2) != IS_STRING) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for compare_mtime()");
		return 0;
	}

	if (php_stream_stat_path_ex(Z_STRVAL_P(filename1), 0, &statbuffer1, NULL)) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "mstat failed for %s", Z_STRVAL_P(filename1));
		return 0;
	}

	if (php_stream_stat_path_ex(Z_STRVAL_P(filename2), 0, &statbuffer2, NULL)) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "mstat failed for %s", Z_STRVAL_P(filename2));
		return 0;
	}

	return (int) (statbuffer1.sb.st_mtime >= statbuffer2.sb.st_mtime);
}

/**
 * Executes the filemtime function without function lookup
 */
void phalcon_fast_filemtime(zval *return_value, zval *filename TSRMLS_DC){

	if (Z_TYPE_P(filename) != IS_STRING) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for fast_filemtime()");
		return;
	}

	php_stat(Z_STRVAL_P(filename), (php_stat_len) Z_STRLEN_P(filename), FS_MTIME, return_value TSRMLS_CC);
}

/**
 * Adds a trailing directory separator if the path doesn't have it
 */
void phalcon_fix_path(zval **return_value, zval *path, zval *directory_separator TSRMLS_DC) {

	if (Z_TYPE_P(path) != IS_STRING || Z_TYPE_P(directory_separator) != IS_STRING) {
		return;
	}

	if (Z_STRLEN_P(path) > 0 && Z_STRLEN_P(directory_separator) > 0) {
		if (Z_STRVAL_P(path)[Z_STRLEN_P(path) - 1] != '\\' && Z_STRVAL_P(path)[Z_STRLEN_P(path) - 1] != '/') {
			PHALCON_CONCAT_VV(*return_value, path, directory_separator);
			return;
		}
	}

	zval_ptr_dtor(return_value);
	*return_value = path;
	Z_ADDREF_P(path);
}

/**
 * Replaces directory separators by the virtual separator
 */
void phalcon_prepare_virtual_path(zval *return_value, zval *path, zval *virtual_separator TSRMLS_DC) {

	int i;
	unsigned char ch;
	smart_str virtual_str = {0};

	if (Z_TYPE_P(path) != IS_STRING || Z_TYPE_P(virtual_separator) != IS_STRING) {
		if (Z_TYPE_P(path) == IS_STRING) {
			RETURN_STRINGL(Z_STRVAL_P(path), Z_STRLEN_P(path), 1);
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
		if (ch == '/' || ch == '\\' || ch == ':' || !isprint(ch)) {
			smart_str_appendl(&virtual_str, Z_STRVAL_P(virtual_separator), Z_STRLEN_P(virtual_separator));
		}
		else {
			smart_str_appendc(&virtual_str, tolower(ch));
		}
	}

	smart_str_0(&virtual_str);

	if (virtual_str.c) {
		RETURN_STRINGL(virtual_str.c, virtual_str.len, 0);
	} else {
		RETURN_EMPTY_STRING();
	}
}

/**
 * Faster version of phalcon_prepare_virtual_path()
 */
void phalcon_prepare_virtual_path_ex(zval *return_value, const char *path, size_t path_len, char virtual_separator TSRMLS_DC)
{
	char *copy = ecalloc(path_len+1, 1);
	size_t i;

	for (i=0; i<path_len; ++i) {
		char c = path[i];

		if (c == '/' || c == '\\' || c == ':' || !isprint(c)) {
			copy[i] = virtual_separator;
		}
		else {
			copy[i] = tolower(c);
		}
	}

	ZVAL_STRINGL(return_value, copy, path_len, 0);
}

/**
 * Generates a unique id for a path
 */
void phalcon_unique_path_key(zval *return_value, zval *path TSRMLS_DC) {

	unsigned long h;
	char *strKey;

	if (Z_TYPE_P(path) != IS_STRING) {
		return;
	}

	h = zend_hash_func(Z_STRVAL_P(path), Z_STRLEN_P(path) + 1);

	strKey = emalloc(24);
	snprintf(strKey, 23, "v%lu", h);    

	RETURN_STRING(strKey, 0);
}

/**
 * Returns the realpath of a zval filename
 *
 */
void phalcon_realpath(zval *return_value, zval *filename TSRMLS_DC) {

	char resolved_path_buff[MAXPATHLEN];

	if (Z_TYPE_P(filename) != IS_STRING) {
		RETURN_FALSE;
	}

	if (strlen(Z_STRVAL_P(filename)) != (size_t)(Z_STRLEN_P(filename))) {
		RETURN_FALSE;
	}

	if (VCWD_REALPATH(Z_STRVAL_P(filename), resolved_path_buff)) {
		RETURN_STRING(resolved_path_buff, 1);
	}

	RETURN_FALSE;
}

/**
 * Removes the prefix from a class name, removes malicious characters, replace namespace separator by directory separator
 */
void phalcon_possible_autoload_filepath(zval *return_value, zval *prefix, zval *class_name, zval *virtual_separator, zval *separator TSRMLS_DC) {

	int i, length;
	unsigned char ch;
	smart_str virtual_str = {0};

	if (Z_TYPE_P(prefix) != IS_STRING || Z_TYPE_P(class_name) != IS_STRING || Z_TYPE_P(virtual_separator) != IS_STRING) {
		RETURN_FALSE;
	}

	length = Z_STRLEN_P(prefix);
	if (!length) {
		RETURN_FALSE;
	}

	if (length > Z_STRLEN_P(class_name)) {
		RETURN_FALSE;
	}

	if (separator) {
		if (Z_STRVAL_P(prefix)[Z_STRLEN_P(prefix) - 1] == Z_STRVAL_P(separator)[0]) {
			length--;
		}
	}

	for (i = length + 1; i < Z_STRLEN_P(class_name); i++) {

		ch = Z_STRVAL_P(class_name)[i];

		/**
		 * Anticipated end of string
		 */
		if (ch == '\0') {
			break;
		}

		/**
		 * Replace namespace separator by directory separator
		 */
		if (ch == '\\') {
			smart_str_appendl(&virtual_str, Z_STRVAL_P(virtual_separator), Z_STRLEN_P(virtual_separator));
			continue;
		}

		/**
		 * Replace separator
		 */
		if (separator) {
			if (ch == Z_STRVAL_P(separator)[0]) {
				smart_str_appendl(&virtual_str, Z_STRVAL_P(virtual_separator), Z_STRLEN_P(virtual_separator));
				continue;
			}
		}

		/**
		 * Basic alphanumeric characters
		 */
		if ((ch == '_') || (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
			smart_str_appendc(&virtual_str, ch);
			continue;
		}

		/**
		 * Multibyte characters?
		 */
		if (ch > 127) {
			smart_str_appendc(&virtual_str, ch);
			continue;
		}

	}

	smart_str_0(&virtual_str);

	if (virtual_str.len) {
		RETURN_STRINGL(virtual_str.c, virtual_str.len, 0);
	} else {
		smart_str_free(&virtual_str);
		RETURN_FALSE;
	}

}

void phalcon_file_get_contents(zval *return_value, zval *filename TSRMLS_DC)
{

	char *contents;
	php_stream *stream;
	int len;
	long maxlen = PHP_STREAM_COPY_ALL;
	zval *zcontext = NULL;
	php_stream_context *context = NULL;

	if (Z_TYPE_P(filename) != IS_STRING) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for phalcon_file_get_contents()");
		RETVAL_FALSE;
		return;
	}

	context = php_stream_context_from_zval(zcontext, 0);

	stream = php_stream_open_wrapper_ex(Z_STRVAL_P(filename), "rb", 0 | REPORT_ERRORS, NULL, context);
	if (!stream) {
		RETURN_FALSE;
	}

	if ((len = php_stream_copy_to_mem(stream, &contents, maxlen, 0)) > 0) {
		RETVAL_STRINGL(contents, len, 0);
	} else {
		if (len == 0) {
			RETVAL_EMPTY_STRING();
		} else {
			RETVAL_FALSE;
		}
	}

	php_stream_close(stream);
}

/**
 * Writes a zval to a stream
 */
void phalcon_file_put_contents(zval *return_value, zval *filename, zval *data TSRMLS_DC)
{
	php_stream *stream;
	int numbytes = 0, use_copy = 0;
	zval *zcontext = NULL;
	zval copy;
	php_stream_context *context = NULL;

	if (Z_TYPE_P(filename) != IS_STRING) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for phalcon_file_put_contents()");
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
		case IS_BOOL:
		case IS_CONSTANT:
			zend_make_printable_zval(data, &copy, &use_copy);
			if (use_copy) {
				data = &copy;
			}
			/* no break */

		case IS_STRING:
			if (Z_STRLEN_P(data)) {
				numbytes = php_stream_write(stream, Z_STRVAL_P(data), Z_STRLEN_P(data));
				if (numbytes != Z_STRLEN_P(data)) {
					php_error_docref(NULL TSRMLS_CC, E_WARNING, "Only %d of %d bytes written, possibly out of free disk space", numbytes, Z_STRLEN_P(data));
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

void phalcon_is_dir(zval *return_value, zval *path TSRMLS_DC)
{
	if (likely(Z_TYPE_P(path) == IS_STRING)) {
		php_stat(Z_STRVAL_P(path), (php_stat_len)(Z_STRLEN_P(path)), FS_IS_DIR, return_value TSRMLS_CC);
	}
	else {
		ZVAL_FALSE(return_value);
	}
}

void phalcon_unlink(zval *return_value, zval *path TSRMLS_DC)
{
	if (likely(Z_TYPE_P(path) == IS_STRING)) {
		php_stream_context *context;
		php_stream_wrapper *wrapper;
		zval *zctx = NULL;

		if (unlikely(strlen(Z_STRVAL_P(path)) != (size_t)(Z_STRLEN_P(path)))) {
			ZVAL_FALSE(return_value);
			return;
		}

		context = php_stream_context_from_zval(zctx, 0);
		wrapper = php_stream_locate_url_wrapper(Z_STRVAL_P(path), NULL, 0 TSRMLS_CC);

		if (!wrapper || !wrapper->wops || !wrapper->wops->unlink) {
			ZVAL_FALSE(return_value);
			return;
		}

		ZVAL_BOOL(return_value, wrapper->wops->unlink(wrapper, Z_STRVAL_P(path), REPORT_ERRORS, context TSRMLS_CC));
		return;
	}

	ZVAL_FALSE(return_value);
	return;
}

void phalcon_filemtime(zval *return_value, zval *path TSRMLS_DC)
{
	if (likely(Z_TYPE_P(path) == IS_STRING)) {
		php_stat(Z_STRVAL_P(path), (php_stat_len)(Z_STRLEN_P(path)), FS_MTIME, return_value TSRMLS_CC);
	}
	else {
		ZVAL_FALSE(return_value);
	}
}

void phalcon_basename(zval *return_value, zval *path TSRMLS_DC)
{
	if (likely(Z_TYPE_P(path) == IS_STRING)) {
		char *ret;
		size_t ret_len;

		php_basename(Z_STRVAL_P(path), Z_STRLEN_P(path), NULL, 0, &ret, &ret_len TSRMLS_CC);
		ZVAL_STRINGL(return_value, ret, (int)ret_len, 0);
	}
	else {
		ZVAL_FALSE(return_value);
	}
}
