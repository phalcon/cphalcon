
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "php_main.h"
#include "main/php_streams.h"
#include "ext/standard/php_smart_str.h"
#include "ext/standard/php_filestat.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/concat.h"

#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"


/**
 * Checks if a file exist
 *
 */
int phalcon_file_exists(zval *filename TSRMLS_DC){

	if (Z_TYPE_P(filename) != IS_STRING) {
		return FAILURE;
	}

	if (VCWD_ACCESS(Z_STRVAL_P(filename), F_OK) == 0) {
		return SUCCESS;
	}

	return FAILURE;
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
		if (Z_STRVAL_P(path)[Z_STRLEN_P(path)-1] != Z_STRVAL_P(directory_separator)[0]) {
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

	unsigned int i;
	unsigned char ch;
	smart_str virtual_str = {0};

	if (Z_TYPE_P(path) != IS_STRING || Z_TYPE_P(virtual_separator) != IS_STRING) {
		return;
	}

	for (i = 0; i < Z_STRLEN_P(path); i++) {
		ch = Z_STRVAL_P(path)[i];
		if (ch == '/' || ch == '\\' || ch == ':') {
			smart_str_appendl(&virtual_str, Z_STRVAL_P(virtual_separator), Z_STRLEN_P(virtual_separator));
			continue;
		}
		smart_str_appendc(&virtual_str, ch);
	}

	smart_str_0(&virtual_str);

	if (virtual_str.len) {
		RETURN_STRINGL(virtual_str.c, virtual_str.len, 0);
	} else {
		smart_str_free(&virtual_str);
		RETURN_EMPTY_STRING();
	}
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
	sprintf(strKey, "v%lu", h);

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

	if (strlen(Z_STRVAL_P(filename)) != Z_STRLEN_P(filename)) {
		RETURN_FALSE;
	}

	if (VCWD_REALPATH(Z_STRVAL_P(filename), resolved_path_buff)) {
		RETURN_STRING(resolved_path_buff, 1);
	}

	RETURN_FALSE;
}
