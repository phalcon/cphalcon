
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

#define PHALCON_TRIM_LEFT  1
#define PHALCON_TRIM_RIGHT 2
#define PHALCON_TRIM_BOTH  3

/** Fast char position */
extern int phalcon_memnstr(const zval *haystack, const zval *needle);
extern int phalcon_memnstr_str(const zval *haystack, char *needle, unsigned int needle_length);

/** Function replacement */
extern void phalcon_fast_strlen(zval *return_value, zval *str);
extern void phalcon_fast_strtolower(zval *return_value, zval *str);
extern void phalcon_fast_join(zval *result, zval *glue, zval *pieces TSRMLS_DC);
extern void phalcon_fast_join_str(zval *result, char *glue, unsigned int glue_length, zval *pieces TSRMLS_DC);
extern void phalcon_fast_explode(zval *result, zval *delimiter, zval *str);
extern void phalcon_fast_explode_str(zval *result, const char *delimiter, int delimiter_length, zval *str);
extern void phalcon_fast_strpos(zval *return_value, const zval *haystack, const zval *needle);
extern void phalcon_fast_strpos_str(zval *return_value, const zval *haystack, char *needle, unsigned int needle_length);
extern void phalcon_fast_stripos_str(zval *return_value, zval *haystack, char *needle, unsigned int needle_length);
extern void phalcon_fast_str_replace(zval *return_value, zval *search, zval *replace, zval *subject);
extern void phalcon_fast_trim(zval *return_value, zval *str, int where TSRMLS_DC);
extern void phalcon_fast_strip_tags(zval *return_value, zval *str);
extern void phalcon_fast_strtoupper(zval *return_value, zval *str);

/** Camelize/Uncamelize */
extern void phalcon_camelize(zval *return_value, const zval *str);
extern void phalcon_uncamelize(zval *return_value, const zval *str);

/** Starts/Ends with */
extern int phalcon_start_with(const zval *str, const zval *compared, zval *ignore_case);
extern int phalcon_start_with_str(const zval *str, char *compared, unsigned int compared_length);
extern int phalcon_start_with_str_str(char *str, unsigned int str_length, char *compared, unsigned int compared_length);
extern int phalcon_end_with(const zval *str, const zval *compared, zval *ignore_case);
extern int phalcon_end_with_str(const zval *str, char *compared, unsigned int compared_length);

/** Random string */
extern void phalcon_random_string(zval *return_value, const zval *type, const zval *length TSRMLS_DC);

/* Strips extra slashes */
extern void phalcon_remove_extra_slashes(zval *return_value, const zval *str);

/** Generates a unique key for an array/object */
extern void phalcon_unique_key(zval *return_value, zval *prefix, zval *value TSRMLS_DC);

/** spprintf */
extern int phalcon_spprintf(char **message, int max_len, char *format, ...);

/* Substr */
void phalcon_substr(zval *return_value, zval *str, unsigned long from, unsigned long length);

/** EOL */
zval *phalcon_eol(int eol TSRMLS_DC);

/** Preg-Match */
void phalcon_preg_match(zval *return_value, zval *regex, zval *subject, zval *matches TSRMLS_DC);

/** Base64 */
extern void phalcon_base64_encode(zval *return_value, zval *data);
extern void phalcon_base64_decode(zval *return_value, zval *data);

/** Hash */
void phalcon_md5(zval *return_value, zval *str);

/** JSON */
void phalcon_json_encode(zval *return_value, zval *v, int opts TSRMLS_DC);
void phalcon_json_decode(zval *return_value, zval *v, zend_bool assoc TSRMLS_DC);

/***/
void phalcon_lcfirst(zval *return_value, zval *s);
void phalcon_ucfirst(zval *return_value, zval *s);

