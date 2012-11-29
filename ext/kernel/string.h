
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

/** Fast char position */
extern int phalcon_memnstr(zval *haystack, zval *needle TSRMLS_DC);
extern int phalcon_memnstr_str(zval *haystack, char *needle, int needle_length TSRMLS_DC);

/** Function replacement */
extern void phalcon_fast_strlen(zval *return_value, zval *str);
extern void phalcon_fast_join(zval *result, zval *glue, zval *pieces TSRMLS_DC);
extern void phalcon_fast_join_str(zval *result, char *glue, unsigned int glue_length, zval *pieces TSRMLS_DC);
extern void phalcon_fast_explode(zval *result, zval *delimiter, zval *str TSRMLS_DC);
extern void phalcon_fast_strpos(zval *return_value, zval *haystack, zval *needle TSRMLS_DC);
extern void phalcon_fast_strpos_str(zval *return_value, zval *haystack, char *needle, int needle_length TSRMLS_DC);
extern void phalcon_fast_stripos_str(zval *return_value, zval *haystack, char *needle, int needle_length TSRMLS_DC);
extern void phalcon_fast_str_replace(zval *return_value, zval *search, zval *replace, zval *subject TSRMLS_DC);

/** Camelize/Uncamelize */
extern void phalcon_camelize(zval *return_value, zval *str TSRMLS_DC);
extern void phalcon_uncamelize(zval *return_value, zval *str TSRMLS_DC);

/** Extract named parameters */
extern void phalcon_extract_named_params(zval *return_value, zval *str, zval *matches);
extern void phalcon_replace_paths(zval *return_value, zval *pattern, zval *paths, zval *uri TSRMLS_DC);

/** Start with */
extern int phalcon_start_with(zval *str, zval *compared);
extern int phalcon_start_with_str(zval *str, char *compared, unsigned int compared_length);