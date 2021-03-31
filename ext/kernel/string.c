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

#include <ctype.h>

#include <php.h>
#include "php_ext.h"
#include "php_main.h"

#include <ext/standard/php_smart_string.h>
#include <ext/standard/php_string.h>
#include <ext/standard/php_rand.h>
#include <ext/standard/php_lcg.h>
#include <ext/standard/php_http.h>
#include <ext/standard/base64.h>
#include <ext/standard/md5.h>
#include <ext/standard/crc32.h>
#include <ext/standard/url.h>
#include <ext/standard/html.h>
#include <ext/date/php_date.h>

#if defined ZEPHIR_USE_PHP_PCRE && ZEPHIR_USE_PHP_PCRE
#include <ext/pcre/php_pcre.h>
#endif

#if defined ZEPHIR_USE_PHP_JSON && ZEPHIR_USE_PHP_JSON
#include <ext/json/php_json.h>
#endif

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"

#define PH_RANDOM_ALNUM 0
#define PH_RANDOM_ALPHA 1
#define PH_RANDOM_HEXDEC 2
#define PH_RANDOM_NUMERIC 3
#define PH_RANDOM_NOZERO 4

/**
 * This function is not external in the Zend API so we redeclare it here in the extension
 */
int zephir_spprintf(char **message, int max_len, char *format, ...)
{
	va_list arg;
	int len;

	va_start(arg, format);
	len = vspprintf(message, max_len, format, arg);
	va_end(arg);
	return len;
}

/**
 * Fast call to php strlen
 */
int zephir_fast_strlen_ev(zval *str)
{
	zval copy;
	int use_copy = 0, length;

	if (Z_TYPE_P(str) != IS_STRING) {
		use_copy = zend_make_printable_zval(str, &copy);
		if (use_copy) {
			str = &copy;
		}
	}

	length = Z_STRLEN_P(str);
	if (use_copy) {
		zval_dtor(str);
	}

	return length;
}

/**
 * Fast call to php strtolower
 */
void zephir_fast_strtolower(zval *return_value, zval *str)
{
	zval copy;
	int use_copy = 0;
	char *lower_str;
	unsigned int length;

	if (Z_TYPE_P(str) != IS_STRING) {
		use_copy = zend_make_printable_zval(str, &copy);
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

	ZVAL_STRINGL(return_value, lower_str, length);
	efree(lower_str);
}

/**
 * Fast call to PHP strtoupper() function
 */
void zephir_fast_strtoupper(zval *return_value, zval *str)
{
	zval copy;
	int use_copy = 0;
	char *lower_str;
	unsigned int length;

	if (Z_TYPE_P(str) != IS_STRING) {
		use_copy = zend_make_printable_zval(str, &copy);
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

	ZVAL_STRINGL(return_value, lower_str, length);
	efree(lower_str);
}

/**
 * Checks if a zval string starts with a zval string
 */
int zephir_start_with(const zval *str, const zval *compared, zval *case_sensitive)
{
	int i;
	int sensitive = 0;
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
int zephir_start_with_str(const zval *str, char *compared, unsigned int compared_length)
{
	if (Z_TYPE_P(str) != IS_STRING || compared_length > Z_STRLEN_P(str)) {
		return 0;
	}

	return !memcmp(Z_STRVAL_P(str), compared, compared_length);
}

/**
 * Checks if a string starts with other string
 */
int zephir_start_with_str_str(char *str, unsigned int str_length, char *compared, unsigned int compared_length)
{

	if (compared_length > str_length) {
		return 0;
	}

	return !memcmp(str, compared, compared_length);
}

/**
 * Checks if a zval string ends with a zval string
 */
int zephir_end_with(const zval *str, const zval *compared, zval *case_sensitive)
{
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
int zephir_end_with_str(const zval *str, char *compared, unsigned int compared_length)
{
	if (Z_TYPE_P(str) != IS_STRING) {
		return 0;
	}

	if (!compared_length || !Z_STRLEN_P(str) || compared_length > Z_STRLEN_P(str)) {
		return 0;
	}

	return !memcmp(Z_STRVAL_P(str) + Z_STRLEN_P(str) - compared_length, compared, compared_length);
}

/**
 * Makes a substr like the PHP function. This function SUPPORT negative from and length
 */
void zephir_substr(zval *return_value, zval *str, long f, long l, int flags)
{
	zval copy;
	int use_copy = 0;
	int str_len;

	if (Z_TYPE_P(str) != IS_STRING) {

		if (Z_TYPE_P(str) == IS_NULL || Z_TYPE_P(str) == IS_TRUE || Z_TYPE_P(str) == IS_FALSE) {
			RETURN_FALSE;
		}

		if (Z_TYPE_P(str) != IS_STRING) {
			use_copy = zend_make_printable_zval(str, &copy);
			if (use_copy) {
				str = &copy;
			}
		}
	}

	str_len = Z_STRLEN_P(str);
	if ((flags & ZEPHIR_SUBSTR_NO_LENGTH) == ZEPHIR_SUBSTR_NO_LENGTH) {
		l = str_len;
	}

	if ((l < 0 && -l > str_len)) {
		if (use_copy) {
			zval_dtor(str);
		}
		RETURN_FALSE;
	} else {
		if (l > str_len) {
			l = str_len;
		}
	}

	if (f > str_len) {
		if (use_copy) {
			zval_dtor(str);
		}
		RETURN_FALSE;
	} else {
		if (f < 0 && -f > str_len) {
			f = 0;
		}
	}

	if (l < 0 && (l + str_len - f) < 0) {
		if (use_copy) {
			zval_dtor(str);
		}
		RETURN_FALSE;
	}

	/* if "from" position is negative, count start position from the end
	 * of the string
	 */
	if (f < 0) {
		f = str_len + f;
		if (f < 0) {
			f = 0;
		}
	}

	/* if "length" position is negative, set it to the length
	 * needed to stop that many chars from the end of the string
	 */
	if (l < 0) {
		l = (str_len - f) + l;
		if (l < 0) {
			l = 0;
		}
	}

	if (f >= str_len) {
		if (use_copy) {
			zval_dtor(str);
		}
		RETURN_FALSE;
	}

	if ((f + l) > str_len) {
		l = str_len - f;
	}

	if (!l) {
		if (use_copy) {
			zval_dtor(str);
		}
		RETURN_EMPTY_STRING();
	}

	ZVAL_STRINGL(return_value, Z_STRVAL_P(str) + f, l);

	if (use_copy) {
		zval_dtor(str);
	}

	return;
}

/**
 * Appends to a smart_str a printable version of a zval
 */
static void zephir_append_printable_zval(smart_str *implstr, zval *tmp)
{
	switch (Z_TYPE_P(tmp)) {

		case IS_STRING:
			smart_str_appendl(implstr, Z_STRVAL_P(tmp), Z_STRLEN_P(tmp));
			break;

		default:
			smart_str_append(implstr, _zval_get_string_func(tmp));
			break;
	}
}

void zephir_append_printable_array(smart_str *implstr, const zval *value)
{
	zend_array *arr;
	unsigned int numelems;

	arr = Z_ARRVAL_P(value);
	numelems = zend_hash_num_elements(arr);

	smart_str_appendc(implstr, '[');

	if (numelems > 0) {
		zval *tmp;
		unsigned int i = 0;

		ZEND_HASH_FOREACH_VAL(arr, tmp) {

			if (Z_TYPE_P(tmp) == IS_OBJECT) {

			} else {
				if (Z_TYPE_P(tmp) == IS_ARRAY) {
					zephir_append_printable_array(implstr, tmp);
				} else {
					zephir_append_printable_zval(implstr, tmp);
				}
			}

			if (++i != numelems) {
				smart_str_appendc(implstr, ',');
			}

		} ZEND_HASH_FOREACH_END();
	}

	smart_str_appendc(implstr, ']');
}

/**
 * Creates a unique key to be used as index in a hash
 */
void zephir_unique_key(zval *return_value, const zval *prefix, zval *value)
{
	smart_str implstr = {0};

	if (Z_TYPE_P(prefix) == IS_STRING) {
		smart_str_appendl(&implstr, Z_STRVAL_P(prefix), Z_STRLEN_P(prefix));
	}

	if (Z_TYPE_P(value) == IS_ARRAY) {
		zephir_append_printable_array(&implstr, value);
	} else {
		zephir_append_printable_zval(&implstr, value);
	}

	smart_str_0(&implstr);

	if (implstr.s) {
		RETURN_STR(implstr.s);
	} else {
		smart_str_free(&implstr);
		RETURN_NULL();
	}
}

/**
 * Fast call to php join  function
 */
void zephir_fast_join(zval *result, zval *glue, zval *pieces)
{
	if (Z_TYPE_P(glue) != IS_STRING || Z_TYPE_P(pieces) != IS_ARRAY) {
		ZVAL_NULL(result);
		zend_error(E_WARNING, "Invalid arguments supplied for join()");
		return;
	}
#if PHP_VERSION_ID < 80000
	php_implode(Z_STR_P(glue), pieces, result);
#else
	php_implode(Z_STR_P(glue), Z_ARRVAL_P(pieces), result);
#endif
}

/**
 * Fast join function
 * This function is an adaption of the php_implode function
 *
 */
void zephir_fast_join_str(zval *return_value, char *glue, unsigned int glue_length, zval *pieces)
{
	zval         *tmp;
	int           numelems;
	zend_string  *str;
	char         *cptr;
	size_t        len = 0;
	zend_string **strings, **strptr;
	zend_array *arr;

	if (Z_TYPE_P(pieces) != IS_ARRAY) {
		php_error_docref(NULL, E_WARNING, "Invalid arguments supplied for fast_join()");
		RETURN_EMPTY_STRING();
	}

	arr = Z_ARRVAL_P(pieces);
	numelems = zend_hash_num_elements(arr);

	if (numelems == 0) {
		RETURN_EMPTY_STRING();
	} else if (numelems == 1) {
		/* loop to search the first not undefined element... */
		ZEND_HASH_FOREACH_VAL(arr, tmp) {
			RETURN_STR(zval_get_string(tmp));
		} ZEND_HASH_FOREACH_END();
	}

	strings = emalloc((sizeof(zend_long) + sizeof(zend_string *)) * numelems);
	strptr = strings - 1;

	ZEND_HASH_FOREACH_VAL(arr, tmp) {
		if (Z_TYPE_P(tmp) == IS_LONG) {
			double val = Z_LVAL_P(tmp);
			*++strptr = NULL;
			((zend_long *) (strings + numelems))[strptr - strings] = Z_LVAL_P(tmp);
			if (val < 0) {
				val = -10 * val;
			}
			if (val < 10) {
				len++;
			} else {
				len += (int) log10(10 * (double) val);
			}
		} else {
			*++strptr = zval_get_string(tmp);
			len += ZSTR_LEN(*strptr);
		}
	} ZEND_HASH_FOREACH_END();

	str = zend_string_alloc(len + (numelems - 1) * glue_length, 0);
	cptr = ZSTR_VAL(str) + ZSTR_LEN(str);
	*cptr = 0;

	do {
		if (*strptr) {
			cptr -= ZSTR_LEN(*strptr);
			memcpy(cptr, ZSTR_VAL(*strptr), ZSTR_LEN(*strptr));
			zend_string_release(*strptr);
		} else {
			char *oldPtr = cptr;
			char oldVal = *cptr;
			zend_long val = ((zend_long *) (strings + numelems))[strptr - strings];
			cptr = zend_print_long_to_buf(cptr, val);
			*oldPtr = oldVal;
		}

		cptr -= glue_length;
		memcpy(cptr, glue, glue_length);
	} while (--strptr > strings);

	if (*strptr) {
		memcpy(ZSTR_VAL(str), ZSTR_VAL(*strptr), ZSTR_LEN(*strptr));
		zend_string_release(*strptr);
	} else {
		char *oldPtr = cptr;
		char oldVal = *cptr;
		zend_print_long_to_buf(cptr, ((zend_long *) (strings + numelems))[strptr - strings]);
		*oldPtr = oldVal;
	}

	efree(strings);
	RETURN_NEW_STR(str);
}

/**
 * Convert dash/underscored texts returning camelized
 * (an optional delimiter can be specified as character-mask as for ltrim)
 */
void zephir_camelize(zval *return_value, const zval *str, const zval *delimiter)
{
	int i, len, delim_len, pre_del = 1;
	smart_str camelize_str = {0};
	char *marker, ch, *delim;

	if (UNEXPECTED(Z_TYPE_P(str) != IS_STRING)) {
		zend_error(E_WARNING, "Invalid arguments supplied for camelize()");
		RETURN_EMPTY_STRING();
	}

	if (delimiter == NULL || Z_TYPE_P(delimiter) == IS_NULL) {
		delim = "_-";
		delim_len = 2;
	} else if (Z_TYPE_P(delimiter) == IS_STRING && Z_STRLEN_P(delimiter) > 0) {
		delim = Z_STRVAL_P(delimiter);
		delim_len = Z_STRLEN_P(delimiter);
	} else {
		zend_error(E_WARNING, "The second argument passed to the camelize() must be a string containing at least one character");
		RETURN_EMPTY_STRING();
	}

	marker = Z_STRVAL_P(str);
	len    = Z_STRLEN_P(str);

	for (i = 0; i < len; i++) {
		ch = marker[i];

		if (memchr(delim, ch, delim_len)) {
			pre_del = 1;
			continue;
		}
		if (pre_del == 1) {
			smart_str_appendc(&camelize_str, toupper(ch));
			pre_del = 0;
		} else {
			smart_str_appendc(&camelize_str, tolower(ch));
		}
	}

	smart_str_0(&camelize_str);

	if (camelize_str.s) {
		RETURN_STR(camelize_str.s);
	} else {
		RETURN_EMPTY_STRING();
	}
}

/**
 * Convert a camelized to a dash/underscored texts (a single-character optional delimiter can be specified)
 */
void zephir_uncamelize(zval *return_value, const zval *str, const zval *delimiter)
{
	unsigned int i;
	smart_str uncamelize_str = {0};
	char *marker, ch, delim;

	if (Z_TYPE_P(str) != IS_STRING) {
		zend_error(E_WARNING, "Invalid arguments supplied for uncamelize()");
		RETURN_EMPTY_STRING();
	}

	if (delimiter == NULL || Z_TYPE_P(delimiter) == IS_NULL) {
		delim = '_';
	} else if (Z_TYPE_P(delimiter) == IS_STRING && Z_STRLEN_P(delimiter) == 1) {
		delim = *(Z_STRVAL_P(delimiter));
	} else {
		zend_error(E_WARNING, "Second argument passed to the uncamelize() must be a string of one character");
		RETURN_EMPTY_STRING();
	}

	marker = Z_STRVAL_P(str);
	for (i = 0; i < Z_STRLEN_P(str); i++) {
		ch = *marker;
		if (ch == '\0') {
			break;
		}
		if (ch >= 'A' && ch <= 'Z') {
			if (i > 0) {
				smart_str_appendc(&uncamelize_str, delim);
			}
			smart_str_appendc(&uncamelize_str, (*marker) + 32);
		} else {
			smart_str_appendc(&uncamelize_str, (*marker));
		}
		marker++;
	}
	smart_str_0(&uncamelize_str);

	if (uncamelize_str.s) {
		RETURN_STR(uncamelize_str.s);
	} else {
		RETURN_EMPTY_STRING();
	}
}

/**
 * Check if a string is contained into another
 */
int zephir_memnstr(const zval *haystack, const zval *needle ZEPHIR_DEBUG_PARAMS)
{
	if (Z_TYPE_P(haystack) != IS_STRING || Z_TYPE_P(needle) != IS_STRING) {
		#ifndef ZEPHIR_RELEASE
		zend_error(E_WARNING, "Invalid arguments supplied for memnstr in %s on line %d", file, line);
		#else
		zend_error(E_WARNING, "Invalid arguments supplied for memnstr()");
		#endif
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
int zephir_memnstr_str(const zval *haystack, char *needle, unsigned int needle_length ZEPHIR_DEBUG_PARAMS)
{
	if (Z_TYPE_P(haystack) != IS_STRING) {
		#ifndef ZEPHIR_RELEASE
		zend_error(E_WARNING, "Invalid arguments supplied for memnstr in %s on line %d", file, line);
		#else
		zend_error(E_WARNING, "Invalid arguments supplied for memnstr()");
		#endif
		return 0;
	}

	if (Z_STRLEN_P(haystack) >= needle_length) {
		return php_memnstr(Z_STRVAL_P(haystack), needle, needle_length, Z_STRVAL_P(haystack) + Z_STRLEN_P(haystack)) ? 1 : 0;
	}

	return 0;
}

/**
 * Fast call to explode php function
 */
void zephir_fast_explode(zval *return_value, zval *delimiter, zval *str, long limit)
{
	if (UNEXPECTED(Z_TYPE_P(str) != IS_STRING || Z_TYPE_P(delimiter) != IS_STRING)) {
		zend_error(E_WARNING, "Invalid arguments supplied for explode()");
		RETURN_EMPTY_STRING();
	}

	array_init(return_value);
	php_explode(Z_STR_P(delimiter), Z_STR_P(str), return_value, limit);
}

/**
 * Fast call to explode php function
 */
void zephir_fast_explode_str(zval *return_value, const char *delim, int delim_length, zval *str, long limit)
{
	zend_string *delimiter;

	if (UNEXPECTED(Z_TYPE_P(str) != IS_STRING)) {
		zend_error(E_WARNING, "Invalid arguments supplied for explode()");
		RETURN_EMPTY_STRING();
	}

	delimiter = zend_string_init(delim, delim_length, 0);
	array_init(return_value);
	php_explode(delimiter, Z_STR_P(str), return_value, limit);
	zend_string_free(delimiter);
}

/**
 * Immediate function resolution for strpos function
 */
void zephir_fast_strpos(zval *return_value, const zval *haystack, const zval *needle, unsigned int offset)
{
	const char *found = NULL;

	if (UNEXPECTED(Z_TYPE_P(haystack) != IS_STRING || Z_TYPE_P(needle) != IS_STRING)) {
		ZVAL_NULL(return_value);
		zend_error(E_WARNING, "Invalid arguments supplied for strpos()");
		return;
	}

	if (offset > Z_STRLEN_P(haystack)) {
		ZVAL_NULL(return_value);
		zend_error(E_WARNING, "Offset not contained in string");
		return;
	}

	if (!Z_STRLEN_P(needle)) {
		ZVAL_NULL(return_value);
		zend_error(E_WARNING, "Empty delimiter");
		return;
	}

	found = php_memnstr(Z_STRVAL_P(haystack)+offset, Z_STRVAL_P(needle), Z_STRLEN_P(needle), Z_STRVAL_P(haystack) + Z_STRLEN_P(haystack));

	if (found) {
		ZVAL_LONG(return_value, found - Z_STRVAL_P(haystack));
	} else {
		ZVAL_BOOL(return_value, 0);
	}
}

/**
 * Immediate function resolution for strpos function
 */
void zephir_fast_strpos_str(zval *return_value, const zval *haystack, char *needle, unsigned int needle_length)
{
	const char *found = NULL;

	if (UNEXPECTED(Z_TYPE_P(haystack) != IS_STRING)) {
		ZVAL_NULL(return_value);
		zend_error(E_WARNING, "Invalid arguments supplied for strpos()");
		return;
	}

	found = php_memnstr(Z_STRVAL_P(haystack), needle, needle_length, Z_STRVAL_P(haystack) + Z_STRLEN_P(haystack));

	if (found) {
		ZVAL_LONG(return_value, found - Z_STRVAL_P(haystack));
	} else {
		ZVAL_BOOL(return_value, 0);
	}
}

/**
 * Fast call to PHP trim() function
 */
void zephir_fast_trim(zval *return_value, zval *str, zval *charlist, int where)
{
	zval copy;
	int use_copy = 0;
	zend_string *trimmed;

	if (Z_TYPE_P(str) != IS_STRING) {
		use_copy = zend_make_printable_zval(str, &copy);
		if (use_copy) {
			str = &copy;
		}
	}

	if (charlist && Z_TYPE_P(charlist) == IS_STRING) {
		trimmed = php_trim(Z_STR_P(str), Z_STRVAL_P(charlist), Z_STRLEN_P(charlist), where);
	} else {
		trimmed = php_trim(Z_STR_P(str), NULL, 0, where);
	}
	ZVAL_STR(return_value, trimmed);

	if (use_copy) {
		zval_dtor(&copy);
	}
}

/* {{{ php_char_to_str_ex This function is subject to version 3.01 of the PHP license
 */
static zend_string* php_char_to_str_ex(zend_string *str, char from, char *to, size_t to_len, int case_sensitivity, zend_long *replace_count)
{
	zend_string *result;
	size_t char_count = 0;
	char lc_from = 0;
	char *source, *target, *source_end= ZSTR_VAL(str) + ZSTR_LEN(str);

	if (case_sensitivity) {
		char *p = ZSTR_VAL(str), *e = p + ZSTR_LEN(str);
		while ((p = memchr(p, from, (e - p)))) {
			char_count++;
			p++;
		}
	} else {
		lc_from = tolower(from);
		for (source = ZSTR_VAL(str); source < source_end; source++) {
			if (tolower(*source) == lc_from) {
				char_count++;
			}
		}
	}

	if (char_count == 0) {
		return zend_string_copy(str);
	}

	if (to_len > 0) {
		result = zend_string_safe_alloc(char_count, to_len - 1, ZSTR_LEN(str), 0);
	} else {
		result = zend_string_alloc(ZSTR_LEN(str) - char_count, 0);
	}
	target = ZSTR_VAL(result);

	if (case_sensitivity) {
		char *p = ZSTR_VAL(str), *e = p + ZSTR_LEN(str), *s = ZSTR_VAL(str);
		while ((p = memchr(p, from, (e - p)))) {
			memcpy(target, s, (p - s));
			target += p - s;
			memcpy(target, to, to_len);
			target += to_len;
			p++;
			s = p;
			if (replace_count) {
				*replace_count += 1;
			}
		}
		if (s < e) {
			memcpy(target, s, (e - s));
			target += e - s;
		}
	} else {
		for (source = ZSTR_VAL(str); source < source_end; source++) {
			if (tolower(*source) == lc_from) {
				if (replace_count) {
					*replace_count += 1;
				}
				memcpy(target, to, to_len);
				target += to_len;
			} else {
				*target = *source;
				target++;
			}
		}
	}

	*target = 0;
	return result;
}
/* }}} */

/* {{{ php_str_to_str_ex This function is subject to version 3.01 of the PHP license
 */
static zend_string *php_str_to_str_ex(zend_string *haystack,
	char *needle, size_t needle_len, char *str, size_t str_len, zend_long *replace_count)
{
	zend_string *new_str;

	if (needle_len < ZSTR_LEN(haystack)) {
		char *end;
		char *e, *s, *p, *r;

		if (needle_len == str_len) {
			new_str = NULL;
			end = ZSTR_VAL(haystack) + ZSTR_LEN(haystack);
			for (p = ZSTR_VAL(haystack); (r = (char*)php_memnstr(p, needle, needle_len, end)); p = r + needle_len) {
				if (!new_str) {
					new_str = zend_string_init(ZSTR_VAL(haystack), ZSTR_LEN(haystack), 0);
				}
				memcpy(ZSTR_VAL(new_str) + (r - ZSTR_VAL(haystack)), str, str_len);
				(*replace_count)++;
			}
			if (!new_str) {
				goto nothing_todo;
			}
			return new_str;
		} else {
			size_t count = 0;
			char *o = ZSTR_VAL(haystack);
			char *n = needle;
			char *endp = o + ZSTR_LEN(haystack);

			while ((o = (char*)php_memnstr(o, n, needle_len, endp))) {
				o += needle_len;
				count++;
			}
			if (count == 0) {
				/* Needle doesn't occur, shortcircuit the actual replacement. */
				goto nothing_todo;
			}
			new_str = zend_string_alloc(count * (str_len - needle_len) + ZSTR_LEN(haystack), 0);

			e = s = ZSTR_VAL(new_str);
			end = ZSTR_VAL(haystack) + ZSTR_LEN(haystack);
			for (p = ZSTR_VAL(haystack); (r = (char*)php_memnstr(p, needle, needle_len, end)); p = r + needle_len) {
				memcpy(e, p, r - p);
				e += r - p;
				memcpy(e, str, str_len);
				e += str_len;
				(*replace_count)++;
			}

			if (p < end) {
				memcpy(e, p, end - p);
				e += end - p;
			}

			*e = '\0';
			return new_str;
		}
	} else if (needle_len > ZSTR_LEN(haystack) || memcmp(ZSTR_VAL(haystack), needle, ZSTR_LEN(haystack))) {
nothing_todo:
		return zend_string_copy(haystack);
	} else {
		new_str = zend_string_init(str, str_len, 0);
		(*replace_count)++;
		return new_str;
	}
}
/* }}} */

/**
 * Immediate function resolution for str_replace function
 */
void zephir_fast_str_replace(zval *return_value_ptr, zval *search, zval *replace, zval *subject)
{
	zval replace_copy, search_copy;
	int copy_replace = 0, copy_search = 0;
	zend_long replace_count = 0;

	if (Z_TYPE_P(subject) != IS_STRING) {
		ZVAL_NULL(return_value_ptr);
		zend_error(E_WARNING, "Invalid arguments supplied for str_replace()");
		return;
	}

	/**
	 * Fallback to userland function if the first parameter is an array
	 */
	if (Z_TYPE_P(search) == IS_ARRAY) {
		do {
			zval *params[] = { search, replace, subject };
			ZVAL_NULL(return_value_ptr);
			zephir_call_func_aparams(return_value_ptr, "str_replace", sizeof("str_replace")-1, NULL, 0, 3, params);
			return;
		} while(0);
	}

	if (Z_TYPE_P(replace) != IS_STRING) {
		copy_replace = zend_make_printable_zval(replace, &replace_copy);
		if (copy_replace) {
			replace = &replace_copy;
		}
	}

	if (Z_TYPE_P(search) != IS_STRING) {
		copy_search = zend_make_printable_zval(search, &search_copy);
		if (copy_search) {
			search = &search_copy;
		}
	}

	if (Z_STRLEN_P(subject) == 0) {
		ZVAL_STRINGL(return_value_ptr, "", 0);
		return;
	}

	if (Z_STRLEN_P(search) == 1) {
		ZVAL_STR(return_value_ptr, php_char_to_str_ex(Z_STR_P(subject),
			Z_STRVAL_P(search)[0],
			Z_STRVAL_P(replace),
			Z_STRLEN_P(replace),
			1,
			&replace_count));
	} else {
		if (Z_STRLEN_P(search) > 1) {
			ZVAL_STR(return_value_ptr, php_str_to_str_ex(Z_STR_P(subject),
				Z_STRVAL_P(search), Z_STRLEN_P(search),
				Z_STRVAL_P(replace), Z_STRLEN_P(replace), &replace_count));
		} else {
			ZVAL_STR_COPY(return_value_ptr, Z_STR_P(subject));
		}
	}

	if (copy_replace) {
		zval_dtor(replace);
	}

	if (copy_search) {
		zval_dtor(search);
	}
}

#if defined ZEPHIR_USE_PHP_PCRE && ZEPHIR_USE_PHP_PCRE

/**
 * Execute preg-match without function lookup in the PHP userland
 */
void zephir_preg_match(zval *return_value, zval *regex, zval *subject, zval *matches, int global, long flags, long offset)
{
	int use_copy = 0;
	zval copy, tmp_matches;
	pcre_cache_entry *pce;

	if (Z_TYPE_P(regex) != IS_STRING) {
		zend_error(E_WARNING, "Invalid arguments supplied for zephir_preg_match()");
		RETURN_FALSE;
	}

	if (Z_TYPE_P(subject) != IS_STRING) {
		use_copy = zend_make_printable_zval(subject, &copy);
		if (use_copy) {
			subject = &copy;
		}
	}

	/* Compile regex or get it from cache */
	if ((pce = pcre_get_compiled_regex_cache(Z_STR_P(regex))) == NULL) {

		if (use_copy) {
			zval_dtor(subject);
		}

		RETURN_FALSE;
	}

	ZVAL_UNDEF(&tmp_matches);

	if (flags != 0 || offset != 0) {
		php_pcre_match_impl(pce, Z_STR_P(subject), return_value, &tmp_matches, global, 1, flags, offset);
	} else {
		php_pcre_match_impl(pce, Z_STR_P(subject), return_value, &tmp_matches, global, 0, 0, 0);
	}

	if (matches) {
		zval *php_matches = &tmp_matches;

		zval_dtor(matches);
		ZVAL_DEREF(php_matches);
		ZVAL_COPY(matches, php_matches);
	}

	zval_ptr_dtor(&tmp_matches);

	if (use_copy) {
		zval_dtor(&copy);
	}
}

#else

void zephir_preg_match(zval *return_value, zval *regex, zval *subject, zval *matches, int global, long flags, long offset)
{
	zval tmp_flags;
	zval tmp_offset;
	zval rv, tmp_matches;
	zval *rvp = return_value ? return_value : &rv;

	ZVAL_NULL(&tmp_flags);
	ZVAL_NULL(&tmp_offset);

	ZVAL_LONG(&tmp_flags, flags);
	ZVAL_LONG(&tmp_offset, offset);

	ZVAL_NULL(&tmp_matches);
	ZVAL_MAKE_REF(&tmp_matches);

	{
		zval *tmp_params[5] = { regex, subject, &tmp_matches, &tmp_flags, &tmp_offset };

		if (global) {
			zephir_call_func_aparams(rvp, SL("preg_match_all"), NULL, 0, 5, tmp_params);
		} else {
			zephir_call_func_aparams(rvp, SL("preg_match"), NULL, 0, 5, tmp_params);
		}
	}

	if (matches) {
		if (Z_TYPE(tmp_matches) == IS_REFERENCE) {
			ZVAL_COPY(matches, Z_REFVAL(tmp_matches));
		} else {
			ZVAL_NULL(matches);
		}
	}

	zval_dtor(&tmp_matches);

	if (!return_value) {
		zval_dtor(&rv);
	}
}

#endif /* ZEPHIR_USE_PHP_PCRE */

#if defined ZEPHIR_USE_PHP_JSON && ZEPHIR_USE_PHP_JSON

int zephir_json_encode(zval *return_value, zval *v, int opts)
{
	smart_str buf = { 0 };

	php_json_encode(&buf, v, opts);
	smart_str_0(&buf);
	ZVAL_STR(return_value, buf.s);

	return SUCCESS;
}

int zephir_json_decode(zval *return_value, zval *v, zend_bool assoc)
{
	zval copy;
	int use_copy = 0;

	if (UNEXPECTED(Z_TYPE_P(v) != IS_STRING)) {
		use_copy = zend_make_printable_zval(v, &copy);
		if (use_copy) {
			v = &copy;
		}
	}

	php_json_decode(return_value, Z_STRVAL_P(v), Z_STRLEN_P(v), assoc, 512 /* JSON_PARSER_DEFAULT_DEPTH */);

	if (UNEXPECTED(use_copy)) {
		zval_dtor(&copy);
	}

	return SUCCESS;
}

#else

int zephir_json_encode(zval *return_value, zval *v, int opts)
{
	zval zopts;
	zval *params[2];

	ZVAL_NULL(&zopts);
	ZVAL_LONG(&zopts, opts);

	params[0] = v;
	params[1] = &zopts;

	return zephir_return_call_function(return_value, SL("json_encode"), NULL, 0, 2, params);
}

int zephir_json_decode(zval *return_value, zval *v, zend_bool assoc)
{
	zval zassoc;
	zval *params[2];

	ZVAL_NULL(&zassoc);
	ZVAL_BOOL(&zassoc, assoc);

	params[0] = v;
	params[1] = &zassoc;

	return zephir_return_call_function(return_value, SL("json_decode"), NULL, 0, 2, params);
}

#endif /* ZEPHIR_USE_PHP_JSON */

void zephir_md5(zval *return_value, zval *str)
{
	PHP_MD5_CTX ctx;
	unsigned char digest[16];
	char hexdigest[33];
	zval copy;

	if (Z_TYPE_P(str) != IS_STRING) {
		int use_copy = zend_make_printable_zval(str, &copy);
		if (use_copy) {
			str = &copy;
		}
	}

	PHP_MD5Init(&ctx);
	PHP_MD5Update(&ctx, Z_STRVAL_P(str), Z_STRLEN_P(str));
	PHP_MD5Final(digest, &ctx);

	make_digest(hexdigest, digest);

	ZVAL_STRINGL(return_value, hexdigest, 32);
}

void zephir_crc32(zval *return_value, zval *str)
{
	zval copy;
	int use_copy = 0;
	size_t nr;
	char *p;
	php_uint32 crc;
	php_uint32 crcinit = 0;

	if (Z_TYPE_P(str) != IS_STRING) {
		use_copy = zend_make_printable_zval(str, &copy);
		if (use_copy) {
			str = &copy;
		}
	}

	p = Z_STRVAL_P(str);
	nr = Z_STRLEN_P(str);

	crc = crcinit^0xFFFFFFFF;
	for (; nr--; ++p) {
		crc = ((crc >> 8) & 0x00FFFFFF) ^ crc32tab[(crc ^ (*p)) & 0xFF];
	}

	if (use_copy) {
		zval_dtor(str);
	}

	RETVAL_LONG(crc ^ 0xFFFFFFFF);
}

void zephir_ucfirst(zval *return_value, zval *s)
{
	zval copy;
	int use_copy = 0;

	if (UNEXPECTED(Z_TYPE_P(s) != IS_STRING)) {
		use_copy = zend_make_printable_zval(s, &copy);
		if (use_copy) {
			s = &copy;
		}
	}

	if (!Z_STRLEN_P(s)) {
		ZVAL_EMPTY_STRING(return_value);
	} else {
		char *c;
		ZVAL_STRINGL(return_value, Z_STRVAL_P(s), Z_STRLEN_P(s));
		c = Z_STRVAL_P(return_value);
		*c = toupper((unsigned char)*c);
	}

	if (UNEXPECTED(use_copy)) {
		zval_dtor(&copy);
	}
}

void zephir_addslashes(zval *return_value, zval *str)
{
	zval copy;
	int use_copy = 0;

	if (UNEXPECTED(Z_TYPE_P(str) != IS_STRING)) {
		use_copy = zend_make_printable_zval(str, &copy);
		if (use_copy) {
			str = &copy;
		}
	}

    ZVAL_STR(return_value, php_addslashes(Z_STR_P(str)));

	if (UNEXPECTED(use_copy)) {
		zval_dtor(&copy);
	}
}

void zephir_stripslashes(zval *return_value, zval *str)
{
	zval copy;
	int use_copy = 0;

	if (UNEXPECTED(Z_TYPE_P(str) != IS_STRING)) {
		use_copy = zend_make_printable_zval(str, &copy);
		if (use_copy) {
			str = &copy;
		}
	}

	ZVAL_STRINGL(return_value, Z_STRVAL_P(str), Z_STRLEN_P(str));
	php_stripslashes(Z_STR_P(return_value));

	if (UNEXPECTED(use_copy)) {
		zval_dtor(&copy);
	}
}

void zephir_stripcslashes(zval *return_value, zval *str)
{
	zval copy;
	int use_copy = 0;

	if (UNEXPECTED(Z_TYPE_P(str) != IS_STRING)) {
		use_copy = zend_make_printable_zval(str, &copy);
		if (use_copy) {
			str = &copy;
		}
	}

	ZVAL_STRINGL(return_value, Z_STRVAL_P(str), Z_STRLEN_P(str));
	php_stripcslashes(Z_STR_P(return_value));

	if (UNEXPECTED(use_copy)) {
		zval_dtor(&copy);
	}
}

/**
 * Compares two strings using the same time whether they're equal or not.
 * A difference in length will leak
 */
int zephir_hash_equals(const zval *known_zval, const zval *user_zval)
{
	char *known_str, *user_str;
	int result = 0;
	size_t j;

	if (Z_TYPE_P(known_zval) != IS_STRING || Z_TYPE_P(user_zval) != IS_STRING) {
		return 0;
	}

	if (Z_STRLEN_P(known_zval) != Z_STRLEN_P(user_zval)) {
		return 0;
	}

	known_str = Z_STRVAL_P(known_zval);
	user_str = Z_STRVAL_P(user_zval);

	for (j = 0; j < Z_STRLEN_P(known_zval); j++) {
		result |= known_str[j] ^ user_str[j];
	}

	return (int) (result == 0);
}

void zephir_string_to_hex(zval *return_value, zval *var)
{
	int use_copy = 0;
	zval copy;
	size_t i;
	char *s;
	zend_string *res;

	if (Z_TYPE_P(var) != IS_STRING) {
		use_copy = zend_make_printable_zval(var, &copy);
		if (use_copy) {
			var = &copy;
		}
	}

	res = zend_string_alloc(2*Z_STRLEN_P(var) + 1, 0);
	s   = Z_STRVAL_P(var);
	for (i=0; i<Z_STRLEN_P(var); ++i) {
		sprintf(res->val + 2*i, "%hhX", (unsigned char) s[i]);
	}

	res->val[2*Z_STRLEN_P(var)] = 0;
	res->len = 2*Z_STRLEN_P(var);
	zend_string_forget_hash_val(res);
	ZVAL_STR(return_value, res);

	if (use_copy) {
		zval_dtor(var);
	}
}
