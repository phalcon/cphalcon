
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

#ifndef PHALCON_KERNEL_STRING_H
#define PHALCON_KERNEL_STRING_H

#include "php_phalcon.h"

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

/** Preg-Match */
int phalcon_preg_match(zval *return_value, zval *regex, zval *subject, zval *matches TSRMLS_DC) PHALCON_ATTR_WARN_UNUSED_RESULT;

/** Base64 */
void phalcon_base64_encode(zval *return_value, zval *data);
void phalcon_base64_decode(zval *return_value, zval *data);

/** Hash */
void phalcon_md5(zval *return_value, zval *str);

/** JSON */
int phalcon_json_encode(zval *return_value, zval *v, int opts TSRMLS_DC) PHALCON_ATTR_WARN_UNUSED_RESULT;
int phalcon_json_decode(zval *return_value, zval *v, zend_bool assoc TSRMLS_DC) PHALCON_ATTR_WARN_UNUSED_RESULT;

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

#endif /* PHALCON_KERNEL_STRING_H */
