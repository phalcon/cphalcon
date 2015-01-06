
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

#include "kernel/string.h"

#include <ctype.h>
#include <ext/standard/php_smart_str.h>
#include <ext/standard/php_string.h>
#include <ext/standard/php_rand.h>
#include <ext/standard/php_lcg.h>
#include <ext/standard/php_http.h>
#include <ext/standard/base64.h>
#include <ext/standard/md5.h>
#include <ext/standard/url.h>
#include <ext/standard/html.h>
#include <ext/date/php_date.h>

#ifdef PHALCON_USE_PHP_PCRE
#include <ext/pcre/php_pcre.h>
#endif

#ifdef PHALCON_USE_PHP_JSON
#include <ext/json/php_json.h>
#endif

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"

#define PH_RANDOM_ALNUM 0
#define PH_RANDOM_ALPHA 1
#define PH_RANDOM_HEXDEC 2
#define PH_RANDOM_NUMERIC 3
#define PH_RANDOM_NOZERO 4

/**
 * Fast call to php strlen
 */
void phalcon_fast_strlen(zval *return_value, zval *str){

	zval copy;
	int use_copy = 0;

	if (Z_TYPE_P(str) != IS_STRING) {
		zend_make_printable_zval(str, &copy, &use_copy);
		if (use_copy) {
			str = &copy;
		}
	}

	ZVAL_LONG(return_value, Z_STRLEN_P(str));

	if (use_copy) {
		zval_dtor(str);
	}
}

/**
 * Fast call to php strlen
 */
void phalcon_fast_strtolower(zval *return_value, zval *str){

	zval copy;
	int use_copy = 0;
	char *lower_str;
	unsigned int length;

	if (Z_TYPE_P(str) != IS_STRING) {
		zend_make_printable_zval(str, &copy, &use_copy);
		if (use_copy) {
			str = &copy;
		}
	}

	length = Z_STRLEN_P(str);
	lower_str = estrndup(Z_STRVAL_P(str), length);
	php_strtolower(lower_str, length);

	if (use_copy) {
		zval_dtor(str);
	}

	ZVAL_STRINGL(return_value, lower_str, length, 0);
}

void phalcon_strtolower_inplace(zval *s) {
	if (likely(Z_TYPE_P(s) == IS_STRING)) {
		php_strtolower(Z_STRVAL_P(s), Z_STRLEN_P(s));
	}
}

/**
 * Fast call to php join  function
 */
void phalcon_fast_join(zval *result, zval *glue, zval *pieces TSRMLS_DC){

	if (Z_TYPE_P(glue) != IS_STRING || Z_TYPE_P(pieces) != IS_ARRAY) {
		ZVAL_NULL(result);
		zend_error(E_WARNING, "Invalid arguments supplied for join()");
		return;
	}

	php_implode(glue, pieces, result TSRMLS_CC);
}

/**
 * Appends to a smart_str a printable version of a zval
 */
void phalcon_append_printable_zval(smart_str *implstr, zval **tmp TSRMLS_DC) {

	zval tmp_val;
	unsigned int str_len;

	switch (Z_TYPE_PP(tmp)) {
		case IS_STRING:
			smart_str_appendl(implstr, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp));
			break;

		case IS_LONG:
			smart_str_append_long(implstr, Z_LVAL_PP(tmp));
			break;

		case IS_BOOL:
			if (Z_LVAL_PP(tmp) == 1) {
				smart_str_appendl(implstr, "1", sizeof("1") - 1);
			}
			break;

		case IS_NULL:
			break;

		case IS_DOUBLE: {
			char *stmp;
			str_len = spprintf(&stmp, 0, "%.*G", (int) EG(precision), Z_DVAL_PP(tmp));
			smart_str_appendl(implstr, stmp, str_len);
			efree(stmp);
		}
			break;

		case IS_OBJECT: {
			int copy;
			zval expr;
			zend_make_printable_zval(*tmp, &expr, &copy);
			smart_str_appendl(implstr, Z_STRVAL(expr), Z_STRLEN(expr));
			if (copy) {
				zval_dtor(&expr);
			}
		}
			break;

		default:
			tmp_val = **tmp;
			zval_copy_ctor(&tmp_val);
			convert_to_string(&tmp_val);
			smart_str_appendl(implstr, Z_STRVAL(tmp_val), Z_STRLEN(tmp_val));
			zval_dtor(&tmp_val);
			break;
	}
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
	unsigned int   numelems, i = 0;

	if (Z_TYPE_P(pieces) != IS_ARRAY) {
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
		phalcon_append_printable_zval(&implstr, tmp TSRMLS_CC);
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
 * Convert dash/underscored texts returning camelized
 */
void phalcon_camelize(zval *return_value, const zval *str){

	int i, len;
	smart_str camelize_str = {0};
	char *marker, ch;

	if (unlikely(Z_TYPE_P(str) != IS_STRING)) {
		zend_error(E_WARNING, "Invalid arguments supplied for camelize()");
		RETURN_EMPTY_STRING();
		return;
	}

	marker = Z_STRVAL_P(str);
	len    = Z_STRLEN_P(str);

	for (i = 0; i < len; i++) {
		ch = *marker;
		if (i == 0 || ch == '-' || ch == '_') {
			if (ch == '-' || ch == '_') {
				i++;
				marker++;
			}

			smart_str_appendc(&camelize_str, toupper(*marker));
		}
		else {
			smart_str_appendc(&camelize_str, tolower(*marker));
		}

		marker++;
	}

	if (likely(i == len - 1)) {
		smart_str_appendc(&camelize_str, *marker);
	}

	smart_str_0(&camelize_str);

	if (camelize_str.c) {
		RETURN_STRINGL(camelize_str.c, camelize_str.len, 0);
	} else {
		RETURN_EMPTY_STRING();
	}

}

/**
 * Convert dash/underscored texts returning camelized
 */
void phalcon_uncamelize(zval *return_value, const zval *str){

	int i;
	smart_str uncamelize_str = {0};
	char *marker, ch;

	if (Z_TYPE_P(str) != IS_STRING) {
		zend_error(E_WARNING, "Invalid arguments supplied for camelize()");
		return;
	}

	marker = Z_STRVAL_P(str);
	for (i = 0; i < Z_STRLEN_P(str); i++) {
		ch = *marker;
		if (ch == '\0') {
			break;
		}
		if (ch >= 'A' && ch <= 'Z') {
			if (i > 0) {
				smart_str_appendc(&uncamelize_str, '_');
			}
			smart_str_appendc(&uncamelize_str, (*marker) + 32);
		} else {
			smart_str_appendc(&uncamelize_str, (*marker));
		}
		marker++;
	}
	smart_str_0(&uncamelize_str);

	if (uncamelize_str.c) {
		RETURN_STRINGL(uncamelize_str.c, uncamelize_str.len, 0);
	} else {
		RETURN_EMPTY_STRING();
	}
}

/**
 * Fast call to explode php function
 */
void phalcon_fast_explode(zval *result, zval *delimiter, zval *str){

	if (unlikely(Z_TYPE_P(str) != IS_STRING || Z_TYPE_P(delimiter) != IS_STRING)) {
		ZVAL_NULL(result);
		zend_error(E_WARNING, "Invalid arguments supplied for explode()");
		return;
	}

	array_init(result);
	php_explode(delimiter, str, result, LONG_MAX);
}

/**
 * Fast call to explode php function
 */
void phalcon_fast_explode_str(zval *result, const char *delimiter, int delimiter_length, zval *str){

	zval delimiter_zval = zval_used_for_init;

	if (unlikely(Z_TYPE_P(str) != IS_STRING)) {
		ZVAL_NULL(result);
		zend_error(E_WARNING, "Invalid arguments supplied for explode()");
		return;
	}

	ZVAL_STRINGL(&delimiter_zval, delimiter, delimiter_length, 0);

	array_init(result);
	php_explode(&delimiter_zval, str, result, LONG_MAX);
}

/**
 * Check if a string is contained into another
 */
int phalcon_memnstr(const zval *haystack, const zval *needle) {

	if (Z_TYPE_P(haystack) != IS_STRING || Z_TYPE_P(needle) != IS_STRING) {
		zend_error(E_WARNING, "Invalid arguments supplied for memnstr()");
		return 0;
	}

	if (Z_STRLEN_P(haystack) >= Z_STRLEN_P(needle)) {
		return php_memnstr(Z_STRVAL_P(haystack), Z_STRVAL_P(needle), Z_STRLEN_P(needle), Z_STRVAL_P(haystack) + Z_STRLEN_P(haystack)) ? 1 : 0;
	}

	return 0;
}

/**
 * Check if a string is contained into another
 */
int phalcon_memnstr_str(const zval *haystack, char *needle, unsigned int needle_length) {

	if (Z_TYPE_P(haystack) != IS_STRING) {
		zend_error(E_WARNING, "Invalid arguments supplied for memnstr()");
		return 0;
	}

	if ((uint)(Z_STRLEN_P(haystack)) >= needle_length) {
		return php_memnstr(Z_STRVAL_P(haystack), needle, needle_length, Z_STRVAL_P(haystack) + Z_STRLEN_P(haystack)) ? 1 : 0;
	}

	return 0;
}

/**
 * Inmediate function resolution for strpos function
 */
void phalcon_fast_strpos(zval *return_value, const zval *haystack, const zval *needle) {

#if PHP_VERSION_ID >= 50600
	const
#endif
	char *found = NULL;

	if (unlikely(Z_TYPE_P(haystack) != IS_STRING || Z_TYPE_P(needle) != IS_STRING)) {
		ZVAL_NULL(return_value);
		zend_error(E_WARNING, "Invalid arguments supplied for strpos()");
		return;
	}

	if (!Z_STRLEN_P(needle)) {
		ZVAL_NULL(return_value);
		zend_error(E_WARNING, "Empty delimiter");
		return;
	}

	found = php_memnstr(Z_STRVAL_P(haystack), Z_STRVAL_P(needle), Z_STRLEN_P(needle), Z_STRVAL_P(haystack) + Z_STRLEN_P(haystack));

	if (found) {
		ZVAL_LONG(return_value, found-Z_STRVAL_P(haystack));
	} else {
		ZVAL_FALSE(return_value);
	}

}

/**
 * Inmediate function resolution for strpos function
 */
void phalcon_fast_strpos_str(zval *return_value, const zval *haystack, char *needle, unsigned int needle_length) {

#if PHP_VERSION_ID >= 50600
	const
#endif
	char *found = NULL;

	if (unlikely(Z_TYPE_P(haystack) != IS_STRING)) {
		ZVAL_NULL(return_value);
		zend_error(E_WARNING, "Invalid arguments supplied for strpos()");
		return;
	}

	found = php_memnstr(Z_STRVAL_P(haystack), needle, needle_length, Z_STRVAL_P(haystack) + Z_STRLEN_P(haystack));

	if (found) {
		ZVAL_LONG(return_value, found-Z_STRVAL_P(haystack));
	} else {
		ZVAL_FALSE(return_value);
	}

}

/**
 * Inmediate function resolution for stripos function
 */
void phalcon_fast_stripos_str(zval *return_value, zval *haystack, char *needle, unsigned int needle_length) {

#if PHP_VERSION_ID >= 50600
	const
#endif
	char *found = NULL;
	char *needle_dup, *haystack_dup;

	if (unlikely(Z_TYPE_P(haystack) != IS_STRING)) {
		ZVAL_NULL(return_value);
		zend_error(E_WARNING, "Invalid arguments supplied for stripos()");
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
		ZVAL_FALSE(return_value);
	}

}


/**
 * Immediate function resolution for str_replace function
 */
void phalcon_fast_str_replace(zval *return_value, zval *search, zval *replace, zval *subject) {

	zval replace_copy, search_copy;
	int copy_replace = 0, copy_search = 0;

	if (Z_TYPE_P(subject) != IS_STRING) {
		ZVAL_NULL(return_value);
		zend_error(E_WARNING, "Invalid arguments supplied for str_replace()");
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

/**
 * Fast call to PHP trim() function
 */
void phalcon_fast_trim(zval *return_value, zval *str, int where TSRMLS_DC) {

	zval copy;
	int use_copy = 0;

	if (Z_TYPE_P(str) != IS_STRING) {
		zend_make_printable_zval(str, &copy, &use_copy);
		if (use_copy) {
			str = &copy;
		}
	}

	php_trim(Z_STRVAL_P(str), Z_STRLEN_P(str), NULL, 0, return_value, where TSRMLS_CC);

	if (use_copy) {
		zval_dtor(&copy);
	}
}

/**
 * Fast call to PHP strip_tags() function
 */
void phalcon_fast_strip_tags(zval *return_value, zval *str) {

	zval copy;
	int use_copy = 0;
	char *stripped;
	size_t len;

	if (Z_TYPE_P(str) != IS_STRING) {
		zend_make_printable_zval(str, &copy, &use_copy);
		if (use_copy) {
			str = &copy;
		}
	}

	stripped = estrndup(Z_STRVAL_P(str), Z_STRLEN_P(str));
	len = php_strip_tags(stripped, Z_STRLEN_P(str), NULL, NULL, 0);

	if (use_copy) {
		zval_dtor(&copy);
	}

	ZVAL_STRINGL(return_value, stripped, len, 0);
}

/**
 * Fast call to PHP strtoupper() function
 */
void phalcon_fast_strtoupper(zval *return_value, zval *str) {

	zval copy;
	int use_copy = 0;
	char *lower_str;
	unsigned int length;

	if (Z_TYPE_P(str) != IS_STRING) {
		zend_make_printable_zval(str, &copy, &use_copy);
		if (use_copy) {
			str = &copy;
		}
	}

	length = Z_STRLEN_P(str);
	lower_str = estrndup(Z_STRVAL_P(str), length);
	php_strtoupper(lower_str, length);

	if (use_copy) {
		zval_dtor(str);
	}

	ZVAL_STRINGL(return_value, lower_str, length, 0);
}

/**
 * Checks if a zval string starts with a zval string
 */
int phalcon_start_with(const zval *str, const zval *compared, zval *case_sensitive){

	int sensitive = 0;
	int i;
	char *op1_cursor, *op2_cursor;

	if (Z_TYPE_P(str) != IS_STRING || Z_TYPE_P(compared) != IS_STRING) {
		return 0;
	}

	if (!Z_STRLEN_P(compared) || !Z_STRLEN_P(str) || Z_STRLEN_P(compared) > Z_STRLEN_P(str)) {
		return 0;
	}

	if (case_sensitive) {
		sensitive = zend_is_true(case_sensitive);
	}

	if (!sensitive) {
		return !memcmp(Z_STRVAL_P(str), Z_STRVAL_P(compared), Z_STRLEN_P(compared));
	}

	op1_cursor = Z_STRVAL_P(str);
	op2_cursor = Z_STRVAL_P(compared);
	for (i = 0; i < Z_STRLEN_P(compared); i++) {
		if (tolower(*op1_cursor) != tolower(*op2_cursor)) {
			return 0;
		}

		op1_cursor++;
		op2_cursor++;
	}

	return 1;
}

/**
 * Checks if a zval string starts with a string
 */
int phalcon_start_with_str(const zval *str, char *compared, unsigned int compared_length){

	if (Z_TYPE_P(str) != IS_STRING || compared_length > (uint)(Z_STRLEN_P(str))) {
		return 0;
	}

	return !memcmp(Z_STRVAL_P(str), compared, compared_length);
}

/**
 * Checks if a string starts with other string
 */
int phalcon_start_with_str_str(char *str, unsigned int str_length, char *compared, unsigned int compared_length){

	if (compared_length > str_length) {
		return 0;
	}

	return !memcmp(str, compared, compared_length);
}

/**
 * Checks if a zval string ends with a zval string
 */
int phalcon_end_with(const zval *str, const zval *compared, zval *case_sensitive){

	int sensitive = 0;
	int i;
	char *op1_cursor, *op2_cursor;

	if (Z_TYPE_P(str) != IS_STRING || Z_TYPE_P(compared) != IS_STRING) {
		return 0;
	}

	if (!Z_STRLEN_P(compared) || !Z_STRLEN_P(str) || Z_STRLEN_P(compared) > Z_STRLEN_P(str)) {
		return 0;
	}

	if (case_sensitive) {
		sensitive = zend_is_true(case_sensitive);
	}

	if (!sensitive) {
		return !memcmp(Z_STRVAL_P(str) + Z_STRLEN_P(str) - Z_STRLEN_P(compared), Z_STRVAL_P(compared), Z_STRLEN_P(compared));
	}

	op1_cursor = Z_STRVAL_P(str) + Z_STRLEN_P(str) - Z_STRLEN_P(compared);
	op2_cursor = Z_STRVAL_P(compared);

	for (i = 0; i < Z_STRLEN_P(compared); ++i) {
		if (tolower(*op1_cursor) != tolower(*op2_cursor)) {
			return 0;
		}

		++op1_cursor;
		++op2_cursor;
	}

	return 1;
}

/**
 * Checks if a zval string ends with a *char string
 */
int phalcon_end_with_str(const zval *str, char *compared, unsigned int compared_length){

	if (Z_TYPE_P(str) != IS_STRING) {
		return 0;
	}

	if (!compared_length || !Z_STRLEN_P(str) || compared_length > (uint)(Z_STRLEN_P(str))) {
		return 0;
	}

	return !memcmp(Z_STRVAL_P(str) + Z_STRLEN_P(str) - compared_length, compared, compared_length);
}

/**
 *
 */
void phalcon_random_string(zval *return_value, const zval *type, const zval *length TSRMLS_DC) {

	long i, rand_type, ch;
	smart_str random_str = {0};

	if (Z_TYPE_P(type) != IS_LONG) {
		return;
	}

	if (Z_LVAL_P(type) > PH_RANDOM_NOZERO) {
		return;
	}

	if (Z_TYPE_P(length) != IS_LONG) {
		return;
	}

	/** Generate seed */
	if (!BG(mt_rand_is_seeded)) {
		php_mt_srand(GENERATE_SEED() TSRMLS_CC);
	}

	for (i = 0; i < Z_LVAL_P(length); i++) {

		switch (Z_LVAL_P(type)) {
			case PH_RANDOM_ALNUM:
				rand_type = (long) (php_mt_rand(TSRMLS_C) >> 1);
				RAND_RANGE(rand_type, 0, 3, PHP_MT_RAND_MAX);
				break;
			case PH_RANDOM_ALPHA:
				rand_type = (long) (php_mt_rand(TSRMLS_C) >> 1);
				RAND_RANGE(rand_type, 1, 2, PHP_MT_RAND_MAX);
				break;
			case PH_RANDOM_HEXDEC:
				rand_type = (long) (php_mt_rand(TSRMLS_C) >> 1);
				RAND_RANGE(rand_type, 0, 1, PHP_MT_RAND_MAX);
				break;
			case PH_RANDOM_NUMERIC:
				rand_type = 0;
				break;
			case PH_RANDOM_NOZERO:
				rand_type = 5;
				break;
			default:
				continue;
		}

		switch (rand_type) {
			case 0:
				ch = (long) (php_mt_rand(TSRMLS_C) >> 1);
				RAND_RANGE(ch, '0', '9', PHP_MT_RAND_MAX);
				break;
			case 1:
				ch = (long) (php_mt_rand(TSRMLS_C) >> 1);
				RAND_RANGE(ch, 'a', 'f', PHP_MT_RAND_MAX);
				break;
			case 2:
				ch = (long) (php_mt_rand(TSRMLS_C) >> 1);
				RAND_RANGE(ch, 'a', 'z', PHP_MT_RAND_MAX);
				break;
			case 3:
				ch = (long) (php_mt_rand(TSRMLS_C) >> 1);
				RAND_RANGE(ch, 'A', 'Z', PHP_MT_RAND_MAX);
				break;
			case 5:
				ch = (long) (php_mt_rand(TSRMLS_C) >> 1);
				RAND_RANGE(ch, '1', '9', PHP_MT_RAND_MAX);
				break;
			default:
				continue;
		}

		smart_str_appendc(&random_str, (unsigned int) ch);
	}


	smart_str_0(&random_str);

	if (random_str.len) {
		RETURN_STRINGL(random_str.c, random_str.len, 0);
	} else {
		smart_str_free(&random_str);
		RETURN_EMPTY_STRING();
	}

}

/**
 * Removes slashes at the end of a string
 */
void phalcon_remove_extra_slashes(zval *return_value, const zval *str) {

	char *cursor, *removed_str;
	unsigned int i;

	if (Z_TYPE_P(str) != IS_STRING) {
		RETURN_EMPTY_STRING();
	}

	if (Z_STRLEN_P(str) > 1) {
		cursor = Z_STRVAL_P(str);
		cursor += (Z_STRLEN_P(str) - 1);
		for (i = Z_STRLEN_P(str); i > 0; i--) {
			if ((*cursor) == '/') {
				cursor--;
				continue;
			}
			break;
		}
	} else {
		i = Z_STRLEN_P(str);
	}

    if (i <= Z_STRLEN_P(str)) {

    	removed_str = emalloc(i + 1);
    	memcpy(removed_str, Z_STRVAL_P(str), i);
    	removed_str[i] = '\0';

    	RETURN_STRINGL(removed_str, i, 0);
    }

    RETURN_EMPTY_STRING();
}

/**
 * This function is not external in the Zend API so we redeclare it here in the extension
 */
int phalcon_spprintf(char **message, int max_len, char *format, ...)
{
    va_list arg;
    int len;

    va_start(arg, format);
    len = vspprintf(message, max_len, format, arg);
    va_end(arg);
    return len;
}

/**
 * Makes a substr like the PHP function. This function doesn't support negative lengths
 */
void phalcon_substr(zval *return_value, zval *str, unsigned long from, unsigned long length) {

	uint str_len = (uint)(Z_STRLEN_P(str));
	if (Z_TYPE_P(str) != IS_STRING) {

		if (Z_TYPE_P(str) == IS_NULL || Z_TYPE_P(str) == IS_BOOL) {
			RETURN_FALSE;
		}

		if (Z_TYPE_P(str) == IS_LONG) {
			RETURN_EMPTY_STRING();
		}

		zend_error(E_WARNING, "Invalid arguments supplied for phalcon_substr()");
		RETURN_FALSE;
	}

	if (str_len < from){
		RETURN_FALSE;
	}

	if (!length || (str_len < length + from)) {
		length = str_len - from;
	}

	if (!length){
		RETURN_EMPTY_STRING();
	}

	RETURN_STRINGL(Z_STRVAL_P(str) + from, (int)length, 1);
}

void phalcon_append_printable_array(smart_str *implstr, zval *value TSRMLS_DC) {

	zval         **tmp;
	HashTable      *arr;
	HashPosition   pos;
	unsigned int numelems, i = 0, str_len;

	arr = Z_ARRVAL_P(value);
	numelems = zend_hash_num_elements(arr);

	smart_str_appendc(implstr, '[');

	if (numelems > 0) {
		zend_hash_internal_pointer_reset_ex(arr, &pos);
		while (zend_hash_get_current_data_ex(arr, (void **) &tmp, &pos) == SUCCESS) {

			/**
			 * We don't serialize objects
			 */
			if (Z_TYPE_PP(tmp) == IS_OBJECT) {
				smart_str_appendc(implstr, 'O');
				{
					char stmp[MAX_LENGTH_OF_LONG + 1];
					str_len = slprintf(stmp, sizeof(stmp), "%ld", Z_OBJVAL_PP(tmp).handle);
					smart_str_appendl(implstr, stmp, str_len);
				}
			} else {
				if (Z_TYPE_PP(tmp) == IS_ARRAY) {
					phalcon_append_printable_array(implstr, *tmp TSRMLS_CC);
				} else {
					phalcon_append_printable_zval(implstr, tmp TSRMLS_CC);
				}
			}

			if (++i != numelems) {
				smart_str_appendc(implstr, ',');
			}

			zend_hash_move_forward_ex(arr, &pos);
		}
	}

	smart_str_appendc(implstr, ']');
}

/**
 * Creates a unique key to be used as index in a hash
 */
void phalcon_unique_key(zval *return_value, zval *prefix, zval *value TSRMLS_DC) {

	smart_str implstr = {0};

	if (Z_TYPE_P(prefix) == IS_STRING) {
		smart_str_appendl(&implstr, Z_STRVAL_P(prefix), Z_STRLEN_P(prefix));
	}

	if (Z_TYPE_P(value) == IS_ARRAY) {
		phalcon_append_printable_array(&implstr, value TSRMLS_CC);
	} else {
		phalcon_append_printable_zval(&implstr, &value TSRMLS_CC);
	}

	smart_str_0(&implstr);

	if (implstr.len) {
		RETURN_STRINGL(implstr.c, implstr.len, 0);
	} else {
		smart_str_free(&implstr);
		RETURN_NULL();
	}

}

/**
 * Base 64 encode
 */
void phalcon_base64_encode(zval *return_value, zval *data) {

	zval copy;
	char *encoded;
	int use_copy = 0, length;

	if (Z_TYPE_P(data) != IS_STRING) {
		zend_make_printable_zval(data, &copy, &use_copy);
		if (use_copy) {
			data = &copy;
		}
	}

	encoded = (char *) php_base64_encode((unsigned char *)(Z_STRVAL_P(data)), Z_STRLEN_P(data), &length);

	if (use_copy) {
		zval_dtor(data);
	}

	if (encoded) {
		RETURN_STRINGL(encoded, length, 0);
	} else {
		RETURN_NULL();
	}
}

/**
 * Base 64 decode
 */
void phalcon_base64_decode(zval *return_value, zval *data) {

	zval copy;
	char *decoded;
	int use_copy = 0, length;

	if (Z_TYPE_P(data) != IS_STRING) {
		zend_make_printable_zval(data, &copy, &use_copy);
		if (use_copy) {
			data = &copy;
		}
	}

	decoded = (char *) php_base64_decode((unsigned char *)(Z_STRVAL_P(data)), Z_STRLEN_P(data), &length);

	if (use_copy) {
		zval_dtor(data);
	}

	if (decoded) {
		RETURN_STRINGL(decoded, length, 0);
	} else {
		RETURN_NULL();
	}
}

void phalcon_md5(zval *return_value, zval *str) {

	PHP_MD5_CTX ctx;
	unsigned char digest[16];
	char hexdigest[33];
	zval copy;
	int use_copy = 0;

	if (Z_TYPE_P(str) != IS_STRING) {
		zend_make_printable_zval(str, &copy, &use_copy);
		if (use_copy) {
			str = &copy;
		}
	}

	PHP_MD5Init(&ctx);
	PHP_MD5Update(&ctx, Z_STRVAL_P(str), Z_STRLEN_P(str));
	PHP_MD5Final(digest, &ctx);

	make_digest(hexdigest, digest);

	ZVAL_STRINGL(return_value, hexdigest, 32, 1);
}

#if PHALCON_USE_PHP_PCRE

/**
 * Execute preg-match without function lookup in the PHP userland
 */
int phalcon_preg_match(zval *return_value, zval *regex, zval *subject, zval *matches TSRMLS_DC)
{
	zval copy;
	int use_copy = 0;
	pcre_cache_entry *pce;

	if (Z_TYPE_P(regex) != IS_STRING) {
		zend_error(E_WARNING, "Invalid arguments supplied for phalcon_preg_match()");
		ZVAL_FALSE(return_value);
		return SUCCESS;
	}

	if (Z_TYPE_P(subject) != IS_STRING) {
		zend_make_printable_zval(subject, &copy, &use_copy);
		if (use_copy) {
			subject = &copy;
		}
	}

	/* Compile regex or get it from cache. */
	if ((pce = pcre_get_compiled_regex_cache(Z_STRVAL_P(regex), Z_STRLEN_P(regex) TSRMLS_CC)) == NULL) {

		if (use_copy) {
			zval_dtor(subject);
		}

		ZVAL_FALSE(return_value);
		return SUCCESS;
	}

	php_pcre_match_impl(pce, Z_STRVAL_P(subject), Z_STRLEN_P(subject), return_value, matches, 0, 0, 0, 0 TSRMLS_CC);

	if (use_copy) {
		zval_dtor(&copy);
	}

	return SUCCESS;
}

#else

int phalcon_preg_match(zval *return_value, zval *regex, zval *subject, zval *matches TSRMLS_DC)
{
	zval *params[] = { regex, subject, matches };
	int result;

	if (matches) {
		Z_SET_ISREF_P(matches);
	}

	result = phalcon_return_call_function(return_value, NULL, SL("preg_match"), (matches ? 3 : 2), params TSRMLS_CC);

	if (matches) {
		Z_UNSET_ISREF_P(matches);
	}

	return result;
}

#endif /* PHALCON_USE_PHP_PCRE */

#ifdef PHALCON_USE_PHP_JSON

int phalcon_json_encode(zval *return_value, zval *v, int opts TSRMLS_DC)
{
	smart_str buf = { NULL, 0, 0 };

	php_json_encode(&buf, v, opts TSRMLS_CC);
	smart_str_0(&buf);
	ZVAL_STRINGL(return_value, buf.c, buf.len, 0);
	return SUCCESS;
}

int phalcon_json_decode(zval *return_value, zval *v, zend_bool assoc TSRMLS_DC)
{
	zval copy;
	int use_copy = 0;

	if (unlikely(Z_TYPE_P(v) != IS_STRING)) {
		zend_make_printable_zval(v, &copy, &use_copy);
		if (use_copy) {
			v = &copy;
		}
	}

	php_json_decode(return_value, Z_STRVAL_P(v), Z_STRLEN_P(v), assoc, 512 /* JSON_PARSER_DEFAULT_DEPTH */ TSRMLS_CC);

	if (unlikely(use_copy)) {
		zval_dtor(&copy);
	}

	return SUCCESS;
}

#else

int phalcon_json_encode(zval *return_value, zval *v, int opts TSRMLS_DC)
{
	zval *zopts;
	zval *params[2];
	int result;

	MAKE_STD_ZVAL(zopts);
	ZVAL_LONG(zopts, opts);

	params[0] = v;
	params[1] = zopts;
	result = phalcon_return_call_function(return_value, NULL, ZEND_STRL("json_encode"), 2, params TSRMLS_CC);

	zval_ptr_dtor(&zopts);
	return result;
}

int phalcon_json_decode(zval *return_value, zval *v, zend_bool assoc TSRMLS_DC)
{
	zval *zassoc = assoc ? PHALCON_GLOBAL(z_true) : PHALCON_GLOBAL(z_false);
	zval *params[] = { v, zassoc };

	return phalcon_return_call_function(return_value, NULL, ZEND_STRL("json_decode"), 2, params TSRMLS_CC);
}

#endif /* PHALCON_USE_PHP_JSON */

void phalcon_lcfirst(zval *return_value, zval *s)
{
	zval copy;
	char *c;
	int use_copy = 0;

	if (unlikely(Z_TYPE_P(s) != IS_STRING)) {
		zend_make_printable_zval(s, &copy, &use_copy);
		if (use_copy) {
			s = &copy;
		}
	}

	if (!Z_STRLEN_P(s)) {
		ZVAL_EMPTY_STRING(return_value);
	}
	else {
		ZVAL_STRINGL(return_value, Z_STRVAL_P(s), Z_STRLEN_P(s), 1);
		c = Z_STRVAL_P(return_value);
		*c = tolower((unsigned char)*c);
	}

	if (unlikely(use_copy)) {
		zval_dtor(&copy);
	}
}

void phalcon_ucfirst(zval *return_value, zval *s)
{
	zval copy;
	char *c;
	int use_copy = 0;

	if (unlikely(Z_TYPE_P(s) != IS_STRING)) {
		zend_make_printable_zval(s, &copy, &use_copy);
		if (use_copy) {
			s = &copy;
		}
	}

	if (!Z_STRLEN_P(s)) {
		ZVAL_EMPTY_STRING(return_value);
	}
	else {
		ZVAL_STRINGL(return_value, Z_STRVAL_P(s), Z_STRLEN_P(s), 1);
		c = Z_STRVAL_P(return_value);
		*c = toupper((unsigned char)*c);
	}

	if (unlikely(use_copy)) {
		zval_dtor(&copy);
	}
}

int phalcon_http_build_query(zval *return_value, zval *params, char *sep TSRMLS_DC)
{
	if (Z_TYPE_P(params) == IS_ARRAY || Z_TYPE_P(params) == IS_OBJECT) {
		smart_str formstr = { NULL, 0, 0 };
		int res;

#if PHP_VERSION_ID < 50400
		res = php_url_encode_hash_ex(HASH_OF(params), &formstr, NULL, 0, NULL, 0, NULL, 0, (Z_TYPE_P(params) == IS_OBJECT ? params : NULL), sep TSRMLS_CC);
#else
		res = php_url_encode_hash_ex(HASH_OF(params), &formstr, NULL, 0, NULL, 0, NULL, 0, (Z_TYPE_P(params) == IS_OBJECT ? params : NULL), sep, PHP_QUERY_RFC1738 TSRMLS_CC);
#endif

		if (res == SUCCESS) {
			if (!formstr.c) {
				ZVAL_EMPTY_STRING(return_value);
			}
			else {
				smart_str_0(&formstr);
				ZVAL_STRINGL(return_value, formstr.c, formstr.len, 0);
			}

			return SUCCESS;
		}

		smart_str_free(&formstr);
		ZVAL_FALSE(return_value);
	}
	else {
		ZVAL_NULL(return_value);
	}

	return FAILURE;
}

void phalcon_htmlspecialchars(zval *return_value, zval *string, zval *quoting, zval *charset TSRMLS_DC)
{
	zval copy;
	char *escaped, *cs;
	int qs, use_copy = 0;
#if PHP_VERSION_ID < 50400
	int escaped_len;
#else
	size_t escaped_len;
#endif

	if (unlikely(Z_TYPE_P(string) != IS_STRING)) {
		zend_make_printable_zval(string, &copy, &use_copy);
		if (use_copy) {
			string = &copy;
		}
	}

	cs = (charset && Z_TYPE_P(charset) == IS_STRING) ? Z_STRVAL_P(charset) : NULL;
	qs = (quoting && Z_TYPE_P(quoting) == IS_LONG)   ? Z_LVAL_P(quoting)   : ENT_COMPAT;

	escaped = php_escape_html_entities_ex((unsigned char *)(Z_STRVAL_P(string)), Z_STRLEN_P(string), &escaped_len, 0, qs, cs, 1 TSRMLS_CC);
	ZVAL_STRINGL(return_value, escaped, escaped_len, 0);

	if (unlikely(use_copy)) {
		zval_dtor(&copy);
	}
}

void phalcon_htmlentities(zval *return_value, zval *string, zval *quoting, zval *charset TSRMLS_DC)
{
	zval copy;
	char *escaped, *cs;
	int qs, use_copy = 0;
#if PHP_VERSION_ID < 50400
	int escaped_len;
#else
	size_t escaped_len;
#endif

	if (unlikely(Z_TYPE_P(string) != IS_STRING)) {
		zend_make_printable_zval(string, &copy, &use_copy);
		if (use_copy) {
			string = &copy;
		}
	}

	cs = (charset && Z_TYPE_P(charset) == IS_STRING) ? Z_STRVAL_P(charset) : NULL;
	qs = (quoting && Z_TYPE_P(quoting) == IS_LONG)   ? Z_LVAL_P(quoting)   : ENT_COMPAT;

	escaped = php_escape_html_entities_ex((unsigned char *)(Z_STRVAL_P(string)), Z_STRLEN_P(string), &escaped_len, 1, qs, cs, 1 TSRMLS_CC);
	ZVAL_STRINGL(return_value, escaped, escaped_len, 0);

	if (unlikely(use_copy)) {
		zval_dtor(&copy);
	}
}

void phalcon_strval(zval *return_value, zval *v)
{
	zval copy;
	int use_copy = 0;

	zend_make_printable_zval(v, &copy, &use_copy);
	if (use_copy) {
		zval *tmp = &copy;
		ZVAL_ZVAL(return_value, tmp, 0, 0);
	}
	else {
		ZVAL_ZVAL(return_value, v, 1, 0);
	}
}

void phalcon_date(zval *return_value, zval *format, zval *timestamp TSRMLS_DC)
{
	long int ts;
	zval copy;
	int use_copy = 0;
	char *formatted;

	if (unlikely(Z_TYPE_P(format) != IS_STRING)) {
		zend_make_printable_zval(format, &copy, &use_copy);
		if (use_copy) {
			format = &copy;
		}
	}

	ts = (timestamp) ? phalcon_get_intval(timestamp) : time(NULL);

	formatted = php_format_date(Z_STRVAL_P(format), Z_STRLEN_P(format), ts, 1 TSRMLS_CC);
	ZVAL_STRING(return_value, formatted, 0);

	if (unlikely(use_copy)) {
		zval_dtor(&copy);
	}
}

void phalcon_addslashes(zval *return_value, zval *str TSRMLS_DC)
{
	zval copy;
	int use_copy = 0;

	if (unlikely(Z_TYPE_P(str) != IS_STRING)) {
		zend_make_printable_zval(str, &copy, &use_copy);
		if (use_copy) {
			str = &copy;
		}
	}

	ZVAL_STRING(return_value, php_addslashes(Z_STRVAL_P(str), Z_STRLEN_P(str), &Z_STRLEN_P(return_value), 0 TSRMLS_CC), 0);

	if (unlikely(use_copy)) {
		zval_dtor(&copy);
	}
}

void phalcon_add_trailing_slash(zval** v)
{
	PHALCON_ENSURE_IS_STRING(v);
	if (Z_STRLEN_PP(v)) {
		int len = Z_STRLEN_PP(v);
		char *c = Z_STRVAL_PP(v);

#ifdef PHP_WIN32
		if (c[len - 1] != '/' && c[len - 1] != '\\')
#else
		if (c[len - 1] != PHP_DIR_SEPARATOR)
#endif
		{            
			SEPARATE_ZVAL(v);
			c = Z_STRVAL_PP(v);

			if (!IS_INTERNED(c)) {
				c = erealloc(c, len+2);
			}
			else {
				c = emalloc(len + 2);
				if (c != NULL) {
					memcpy(c, Z_STRVAL_PP(v), Z_STRLEN_PP(v));
				}
			}

			if (c != NULL) {
				c[len]   = PHP_DIR_SEPARATOR;
				c[len + 1] = 0;

				ZVAL_STRINGL(*v, c, len+1, 0);
			}
		}
	}
}
