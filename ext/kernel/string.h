
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

#ifndef PHALCON_KERNEL_STRING_H
#define PHALCON_KERNEL_STRING_H

#include "Zend/zend.h"

#define PHALCON_TRIM_LEFT  1
#define PHALCON_TRIM_RIGHT 2
#define PHALCON_TRIM_BOTH  3

/** Fast char position */
int phalcon_memnstr(const zval *haystack, const zval *needle);
int phalcon_memnstr_str(const zval *haystack, char *needle, unsigned int needle_length);

/** Function replacement */
void phalcon_fast_strlen(zval *return_value, zval *str);
void phalcon_fast_strtolower(zval *return_value, zval *str);
void phalcon_strtolower_inplace(zval *s);
void phalcon_fast_join(zval *result, zval *glue, zval *pieces TSRMLS_DC);
void phalcon_fast_join_str(zval *result, char *glue, unsigned int glue_length, zval *pieces TSRMLS_DC);
void phalcon_fast_explode(zval *result, zval *delimiter, zval *str);
void phalcon_fast_explode_str(zval *result, const char *delimiter, int delimiter_length, zval *str);
void phalcon_fast_strpos(zval *return_value, const zval *haystack, const zval *needle);
void phalcon_fast_strpos_str(zval *return_value, const zval *haystack, char *needle, unsigned int needle_length);
void phalcon_fast_stripos_str(zval *return_value, zval *haystack, char *needle, unsigned int needle_length);
void phalcon_fast_str_replace(zval *return_value, zval *search, zval *replace, zval *subject);
void phalcon_fast_trim(zval *return_value, zval *str, int where TSRMLS_DC);
void phalcon_fast_strip_tags(zval *return_value, zval *str);
void phalcon_fast_strtoupper(zval *return_value, zval *str);

/** Camelize/Uncamelize */
void phalcon_camelize(zval *return_value, const zval *str);
void phalcon_uncamelize(zval *return_value, const zval *str);

/** Starts/Ends with */
int phalcon_start_with(const zval *str, const zval *compared, zval *case_sensitive);
int phalcon_start_with_str(const zval *str, char *compared, unsigned int compared_length);
int phalcon_start_with_str_str(char *str, unsigned int str_length, char *compared, unsigned int compared_length);
int phalcon_end_with(const zval *str, const zval *compared, zval *case_sensitive);
int phalcon_end_with_str(const zval *str, char *compared, unsigned int compared_length);

/** Random string */
void phalcon_random_string(zval *return_value, const zval *type, const zval *length TSRMLS_DC);

/* Strips extra slashes */
void phalcon_remove_extra_slashes(zval *return_value, const zval *str);

/** Generates a unique key for an array/object */
void phalcon_unique_key(zval *return_value, zval *prefix, zval *value TSRMLS_DC);

/** spprintf */
int phalcon_spprintf(char **message, int max_len, char *format, ...);

/* Substr */
void phalcon_substr(zval *return_value, zval *str, unsigned long from, unsigned long length);

/** EOL */
zval *phalcon_eol(int eol TSRMLS_DC);

/** Preg-Match */
void phalcon_preg_match(zval *return_value, zval **return_value_ptr, zval *regex, zval *subject, zval *matches TSRMLS_DC);

/** Base64 */
void phalcon_base64_encode(zval *return_value, zval *data);
void phalcon_base64_decode(zval *return_value, zval *data);

/** Hash */
void phalcon_md5(zval *return_value, zval *str);

/** JSON */
void phalcon_json_encode(zval *return_value, zval **return_value_ptr, zval *v, int opts TSRMLS_DC);
void phalcon_json_decode(zval *return_value, zval **return_value_ptr, zval *v, zend_bool assoc TSRMLS_DC);

/***/
void phalcon_lcfirst(zval *return_value, zval *s);
void phalcon_ucfirst(zval *return_value, zval *s);
int phalcon_http_build_query(zval *return_value, zval *params, char *sep TSRMLS_DC);
void phalcon_htmlspecialchars(zval *return_value, zval *string, zval *quoting, zval *charset TSRMLS_DC);
void phalcon_htmlentities(zval *return_value, zval *string, zval *quoting, zval *charset TSRMLS_DC);
void phalcon_strval(zval *return_value, zval *v);
void phalcon_date(zval *return_value, zval *format, zval *timestamp TSRMLS_DC);
void phalcon_addslashes(zval *return_value, zval *str TSRMLS_DC);
void phalcon_add_trailing_slash(zval** v);

#if PHP_VERSION_ID < 50400

const char* zend_new_interned_string(const char *arKey, int nKeyLength, int free_src TSRMLS_DC);
#define PHALCON_ZVAL_MAYBE_INTERNED_STRING(pz, string)  ZVAL_STRING(pz, string, 1);

#else

#define PHALCON_ZVAL_MAYBE_INTERNED_STRING(pz, string) \
	do { \
		if (IS_INTERNED(string)) { \
			ZVAL_STRINGL(pz, string, INTERNED_LEN(string)-1, 0); \
		} \
		else { \
			ZVAL_STRING(pz, string, 1); \
		} \
	} while (0)

#endif /* PHP_VERSION_ID < 50400 */

#endif /* PHALCON_KERNEL_STRING_H */
