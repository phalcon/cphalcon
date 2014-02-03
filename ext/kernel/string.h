
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Zephir Team (http://www.zephir-lang.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#ifndef ZEPHIR_KERNEL_STRING_H
#define ZEPHIR_KERNEL_STRING_H

#include <Zend/zend.h>

#define ZEPHIR_TRIM_LEFT  1
#define ZEPHIR_TRIM_RIGHT 2
#define ZEPHIR_TRIM_BOTH  3

/** Fast char position */
int zephir_memnstr(const zval *haystack, const zval *needle ZEPHIR_DEBUG_PARAMS);
int zephir_memnstr_str(const zval *haystack, char *needle, unsigned int needle_length ZEPHIR_DEBUG_PARAMS);

/** Function replacement */
void zephir_fast_strlen(zval *return_value, zval *str);
int zephir_fast_strlen_ev(zval *str);
void zephir_fast_strtolower(zval *return_value, zval *str);
void zephir_strtolower_inplace(zval *s);
void zephir_fast_join(zval *result, zval *glue, zval *pieces TSRMLS_DC);
void zephir_fast_join_str(zval *result, char *glue, unsigned int glue_length, zval *pieces TSRMLS_DC);
void zephir_fast_explode(zval *result, zval *delimiter, zval *str, long limit TSRMLS_DC);
void zephir_fast_explode_str(zval *result, const char *delimiter, int delimiter_length, zval *str, long limit TSRMLS_DC);
void zephir_fast_strpos(zval *return_value, const zval *haystack, const zval *needle, unsigned int offset);
void zephir_fast_strpos_str(zval *return_value, const zval *haystack, char *needle, unsigned int needle_length);
void zephir_fast_stripos_str(zval *return_value, zval *haystack, char *needle, unsigned int needle_length);
void zephir_fast_str_replace(zval *return_value, zval *search, zval *replace, zval *subject);
void zephir_fast_trim(zval *return_value, zval *str, zval *charlist, int where TSRMLS_DC);
void zephir_fast_strip_tags(zval *return_value, zval *str);
void zephir_fast_strtoupper(zval *return_value, zval *str);

/** Camelize/Uncamelize */
void zephir_camelize(zval *return_value, const zval *str);
void zephir_uncamelize(zval *return_value, const zval *str);

/** Starts/Ends with */
int zephir_start_with(const zval *str, const zval *compared, zval *case_sensitive);
int zephir_start_with_str(const zval *str, char *compared, unsigned int compared_length);
int zephir_start_with_str_str(char *str, unsigned int str_length, char *compared, unsigned int compared_length);
int zephir_end_with(const zval *str, const zval *compared, zval *case_sensitive);
int zephir_end_with_str(const zval *str, char *compared, unsigned int compared_length);

/** Random string */
void zephir_random_string(zval *return_value, const zval *type, const zval *length TSRMLS_DC);

/* Strips extra slashes */
void zephir_remove_extra_slashes(zval *return_value, const zval *str);

/** Generates a unique key for an array/object */
void zephir_unique_key(zval *return_value, zval *prefix, zval *value TSRMLS_DC);

/** spprintf */
int zephir_spprintf(char **message, int max_len, char *format, ...);

/* Substr */
void zephir_substr(zval *return_value, zval *str, long from, long length);

/** EOL */
zval *zephir_eol(int eol TSRMLS_DC);

/** Preg-Match */
void zephir_preg_match(zval *return_value, zval **return_value_ptr, zval *regex, zval *subject, zval *matches, int global, long flags, long offset TSRMLS_DC);

/** Base64 */
void zephir_base64_encode(zval *return_value, zval *data);
void zephir_base64_decode(zval *return_value, zval *data);

/** Hash */
void zephir_md5(zval *return_value, zval *str);

/** JSON */
void zephir_json_encode(zval *return_value, zval **return_value_ptr, zval *v, int opts TSRMLS_DC);
void zephir_json_decode(zval *return_value, zval **return_value_ptr, zval *v, zend_bool assoc TSRMLS_DC);

/***/
void zephir_lcfirst(zval *return_value, zval *s);
void zephir_ucfirst(zval *return_value, zval *s);
int zephir_http_build_query(zval *return_value, zval *params, char *sep TSRMLS_DC);
void zephir_htmlspecialchars(zval *return_value, zval *string, zval *quoting, zval *charset TSRMLS_DC);
void zephir_htmlentities(zval *return_value, zval *string, zval *quoting, zval *charset TSRMLS_DC);
void zephir_strval(zval *return_value, zval *v);
void zephir_date(zval *return_value, zval *format, zval *timestamp TSRMLS_DC);
void zephir_addslashes(zval *return_value, zval *str TSRMLS_DC);
void zephir_stripslashes(zval *return_value, zval *str TSRMLS_DC);

#if PHP_VERSION_ID < 50400

const char* zend_new_interned_string(const char *arKey, int nKeyLength, int free_src TSRMLS_DC);
#define ZEPHIR_ZVAL_MAYBE_INTERNED_STRING(pz, string)  ZVAL_STRING(pz, string, 1);

#else

#define ZEPHIR_ZVAL_MAYBE_INTERNED_STRING(pz, string) \
	do { \
		if (IS_INTERNED(string)) { \
			ZVAL_STRINGL(pz, string, INTERNED_LEN(string)-1, 0); \
		} \
		else { \
			ZVAL_STRING(pz, string, 1); \
		} \
	} while (0)

#endif /* PHP_VERSION_ID < 50400 */

#endif /* ZEPHIR_KERNEL_STRING_H */
