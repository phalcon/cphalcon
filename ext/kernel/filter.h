
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
  +------------------------------------------------------------------------+
*/

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