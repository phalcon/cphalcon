
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
<<<<<<< HEAD
  | Copyright (c) 2011-2015 Zephir Team (http://www.zephir-lang.com)       |
=======
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
>>>>>>> master
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
  +------------------------------------------------------------------------+
*/

<<<<<<< HEAD
#ifndef ZEPHIR_KERNEL_FILTER_H
#define ZEPHIR_KERNEL_FILTER_H

#include <php.h>

/** Low level filters */
void zephir_filter_alphanum(zval *return_value, zval *param);
void zephir_filter_identifier(zval *return_value, zval *param);

/** Encoding */
void zephir_is_basic_charset(zval *return_value, const zval *param);

/** Escaping */
void zephir_escape_css(zval *return_value, zval *param);
void zephir_escape_js(zval *return_value, zval *param);
void zephir_escape_htmlattr(zval *return_value, zval *param);
void zephir_escape_html(zval *return_value, zval *str, zval *quote_style, zval *charset TSRMLS_DC);

#endif
=======
#ifndef PHALCON_KERNEL_FILTER_H
#define PHALCON_KERNEL_FILTER_H

#include "php_phalcon.h"

/**
 * Perform escaping of non-alphanumeric characters to different formats
 */
void phalcon_escape_multi(zval *return_value, zval *param, const char *escape_char, unsigned int escape_length, char escape_extra, int use_whitelist);


/** Low level filters */
void phalcon_filter_alphanum(zval *return_value, zval *param) PHALCON_ATTR_NONNULL;
void phalcon_filter_identifier(zval *return_value, zval *param) PHALCON_ATTR_NONNULL;

/** Encoding */
void phalcon_is_basic_charset(zval *return_value, const zval *param) PHALCON_ATTR_NONNULL;

/** Escaping */

/**
 * Escapes non-alphanumeric characters to \HH+space
 */
PHALCON_ATTR_NONNULL static inline void phalcon_escape_css(zval *return_value, zval *param)
{
	phalcon_escape_multi(return_value, param, ZEND_STRL("\\"), ' ', 0);
}

/**
 * Escapes non-alphanumeric characters to \xHH+
 */
PHALCON_ATTR_NONNULL static inline void phalcon_escape_js(zval *return_value, zval *param)
{
	phalcon_escape_multi(return_value, param, ZEND_STRL("\\x"), '\0', 1);
}

/**
 * Escapes non-alphanumeric characters to &xHH;
 */
PHALCON_ATTR_NONNULL static inline void phalcon_escape_htmlattr(zval *return_value, zval *param)
{
	phalcon_escape_multi(return_value, param, ZEND_STRL("&#x"), ';', 1);
}

void phalcon_escape_html(zval *return_value, zval *str, const zval *quote_style, const zval *charset TSRMLS_DC) PHALCON_ATTR_NONNULL;

#endif /* PHALCON_KERNEL_FILTER_H */
>>>>>>> master
