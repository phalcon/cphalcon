
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#include "php.h"
#include "php_phalcon.h"
#include "php_main.h"
#include "ext/standard/php_smart_str.h"
#include "ext/standard/php_string.h"

#include "kernel/main.h"
#include "kernel/memory.h"

/**
 * Fast call to join php function
 */
void phalcon_fast_join(zval *result, zval *glue, zval *pieces TSRMLS_DC){

	if (Z_TYPE_P(glue) != IS_STRING || Z_TYPE_P(pieces) != IS_ARRAY){
		ZVAL_NULL(result);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for join()");
		return;
	}

	php_implode(glue, pieces, result TSRMLS_CC);
}

/**
 * Fast join function
 * This function is an adaption of the php_implode function
 *
 */
void phalcon_fast_join_str(zval *return_value, char *glue, unsigned int glue_length, zval *pieces TSRMLS_DC){

	zval         **tmp;
	HashTable      *arr;
	HashPosition   pos;
	smart_str      implstr = {0};
	int            str_len, numelems, i = 0;
	zval tmp_val;

	if (Z_TYPE_P(pieces) != IS_ARRAY){
		ZVAL_NULL(return_value);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for fast_join()");
		return;
	}

	arr = Z_ARRVAL_P(pieces);
	numelems = zend_hash_num_elements(arr);

	if (numelems == 0) {
		RETURN_EMPTY_STRING();
	}

	zend_hash_internal_pointer_reset_ex(arr, &pos);

	while (zend_hash_get_current_data_ex(arr, (void **) &tmp, &pos) == SUCCESS) {
		switch ((*tmp)->type) {
			case IS_STRING:
				smart_str_appendl(&implstr, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp));
				break;

			case IS_LONG: {
				char stmp[MAX_LENGTH_OF_LONG + 1];
				str_len = slprintf(stmp, sizeof(stmp), "%ld", Z_LVAL_PP(tmp));
				smart_str_appendl(&implstr, stmp, str_len);
			}
				break;

			case IS_BOOL:
				if (Z_LVAL_PP(tmp) == 1) {
					smart_str_appendl(&implstr, "1", sizeof("1")-1);
				}
				break;

			case IS_NULL:
				break;

			case IS_DOUBLE: {
				char *stmp;
				str_len = spprintf(&stmp, 0, "%.*G", (int) EG(precision), Z_DVAL_PP(tmp));
				smart_str_appendl(&implstr, stmp, str_len);
				efree(stmp);
			}
				break;

			case IS_OBJECT: {
				int copy;
				zval expr;
				zend_make_printable_zval(*tmp, &expr, &copy);
				smart_str_appendl(&implstr, Z_STRVAL(expr), Z_STRLEN(expr));
				if (copy) {
					zval_dtor(&expr);
				}
			}
				break;

			default:
				tmp_val = **tmp;
				zval_copy_ctor(&tmp_val);
				convert_to_string(&tmp_val);
				smart_str_appendl(&implstr, Z_STRVAL(tmp_val), Z_STRLEN(tmp_val));
				zval_dtor(&tmp_val);
				break;

		}

		if (++i != numelems) {
			smart_str_appendl(&implstr, glue, glue_length);
		}
		zend_hash_move_forward_ex(arr, &pos);
	}
	smart_str_0(&implstr);

	if (implstr.len) {
		RETURN_STRINGL(implstr.c, implstr.len, 0);
	} else {
		smart_str_free(&implstr);
		RETURN_EMPTY_STRING();
	}
}

/**
 * Convert dash texts returning camelized
 */
void phalcon_camelize(zval *return_value, zval *str){

	int i;
	smart_str camelize_str = {0};
	char *marker, ch;

	if (Z_TYPE_P(str) != IS_STRING) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for camelize()");
		return;
	}

	marker = Z_STRVAL_P(str);
	for (i = 0; i < Z_STRLEN_P(str); i++) {
		ch = *marker;
		if (i==0 || ch == '-' || ch == '_') {
			if (ch == '-' || ch == '_'){
				marker++;
				ch = *marker;
			}
			if (ch >= 97 && ch <= 122) {
				smart_str_appendc(&camelize_str, (*marker)-32);
				marker++;
				continue;
			}
		}
		smart_str_appendc(&camelize_str, (*marker));
		marker++;
	}
	smart_str_0(&camelize_str);

	ZVAL_STRINGL(return_value, camelize_str.c, camelize_str.len, 0);

}

/**
 * Fast call to explode php function
 */
void phalcon_fast_explode(zval *result, zval *delimiter, zval *str TSRMLS_DC){

	if (Z_TYPE_P(str) != IS_STRING || Z_TYPE_P(delimiter) != IS_STRING){
		ZVAL_NULL(result);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for explode()");
		return;
	}

	array_init(result);
	php_explode(delimiter, str, result, LONG_MAX);
}

/**
 * Check if a string is contained into another
 */
int phalcon_memnstr(zval *haystack, zval *needle TSRMLS_DC){

	char *found = NULL;

	if (Z_TYPE_P(haystack) != IS_STRING || Z_TYPE_P(needle) != IS_STRING) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for memnstr()");
		return 0;
	}

	if (Z_STRLEN_P(haystack) >= Z_STRLEN_P(needle)) {
		found = php_memnstr(Z_STRVAL_P(haystack), Z_STRVAL_P(needle), Z_STRLEN_P(needle), Z_STRVAL_P(haystack) + Z_STRLEN_P(haystack));
	}

	if (found) {
		return 1;
	}

	return 0;
}

/**
 * Check if a string is contained into another
 */
int phalcon_memnstr_str(zval *haystack, char *needle, int needle_length TSRMLS_DC){

	char *found = NULL;

	if (Z_TYPE_P(haystack) != IS_STRING) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for memnstr()");
		return 0;
	}

	if (Z_STRLEN_P(haystack) >= needle_length) {
		found = php_memnstr(Z_STRVAL_P(haystack), needle, needle_length, Z_STRVAL_P(haystack) + Z_STRLEN_P(haystack));
	}

	if (found) {
		return 1;
	}

	return 0;
}

/**
 * Inmediate function resolution for strpos function
 */
void phalcon_fast_strpos(zval *return_value, zval *haystack, zval *needle TSRMLS_DC){

	char *found = NULL;

	if (Z_TYPE_P(haystack) != IS_STRING || Z_TYPE_P(needle) != IS_STRING) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for strpos()");
		return;
	}

	if (!Z_STRLEN_P(needle)) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Empty delimiter");
		return;
	}

	found = php_memnstr(Z_STRVAL_P(haystack), Z_STRVAL_P(needle), Z_STRLEN_P(needle), Z_STRVAL_P(haystack) + Z_STRLEN_P(haystack));

	if (found) {
		ZVAL_LONG(return_value, found-Z_STRVAL_P(haystack));
	} else {
		ZVAL_BOOL(return_value, 0);
	}

}

/**
 * Inmediate function resolution for strpos function
 */
void phalcon_fast_strpos_str(zval *return_value, zval *haystack, char *needle, int needle_length TSRMLS_DC){

	char *found = NULL;

	if (Z_TYPE_P(haystack) != IS_STRING) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for strpos()");
		return;
	}

	found = php_memnstr(Z_STRVAL_P(haystack), needle, needle_length, Z_STRVAL_P(haystack) + Z_STRLEN_P(haystack));

	if (found) {
		ZVAL_LONG(return_value, found-Z_STRVAL_P(haystack));
	} else {
		ZVAL_BOOL(return_value, 0);
	}

}

/**
 * Inmediate function resolution for stripos function
 */
void phalcon_fast_stripos_str(zval *return_value, zval *haystack, char *needle, int needle_length TSRMLS_DC){

	char *found = NULL;
	char *needle_dup, *haystack_dup;

	if (Z_TYPE_P(haystack) != IS_STRING) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for stripos()");
		return;
	}

	haystack_dup = estrndup(Z_STRVAL_P(haystack), Z_STRLEN_P(haystack));
	php_strtolower(haystack_dup, Z_STRLEN_P(haystack));

	needle_dup = estrndup(needle, needle_length);
	php_strtolower(needle_dup, needle_length);

	found = php_memnstr(haystack_dup, needle, needle_length, haystack_dup + Z_STRLEN_P(haystack));

	efree(haystack_dup);
	efree(needle_dup);

	if (found) {
		ZVAL_LONG(return_value, found-Z_STRVAL_P(haystack));
	} else {
		ZVAL_BOOL(return_value, 0);
	}

}


/**
 * Inmediate function resolution for str_replace function
 */
void phalcon_fast_str_replace(zval *return_value, zval *search, zval *replace, zval *subject TSRMLS_DC){

	zval replace_copy, search_copy;
	int copy_replace = 0, copy_search = 0;

	if (Z_TYPE_P(subject) != IS_STRING) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for str_replace()");
		return;
	}

	if (Z_TYPE_P(replace) != IS_STRING) {
		zend_make_printable_zval(replace, &replace_copy, &copy_replace);
		if (copy_replace) {
			replace = &replace_copy;
		}
	}

	if (Z_TYPE_P(search) != IS_STRING) {
		zend_make_printable_zval(search, &search_copy, &copy_search);
		if (copy_search) {
			search = &search_copy;
		}
	}

	Z_TYPE_P(return_value) = IS_STRING;
	if (Z_STRLEN_P(subject) == 0) {
		ZVAL_STRINGL(return_value, "", 0, 1);
		return;
	}

	if (Z_STRLEN_P(search) == 1) {
		php_char_to_str_ex(Z_STRVAL_P(subject),
			Z_STRLEN_P(subject),
			Z_STRVAL_P(search)[0],
			Z_STRVAL_P(replace),
			Z_STRLEN_P(replace),
			return_value,
			1,
			NULL);
	} else {
		if (Z_STRLEN_P(search) > 1) {
			Z_STRVAL_P(return_value) = php_str_to_str_ex(Z_STRVAL_P(subject), Z_STRLEN_P(subject),
				Z_STRVAL_P(search), Z_STRLEN_P(search),
				Z_STRVAL_P(replace), Z_STRLEN_P(replace), &Z_STRLEN_P(return_value), 1, NULL);
		} else {
			MAKE_COPY_ZVAL(&subject, return_value);
		}
	}

	if (copy_replace) {
		zval_dtor(replace);
	}

	if (copy_search) {
		zval_dtor(search);
	}

}