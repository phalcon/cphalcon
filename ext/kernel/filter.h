
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

/** Low level filters */
extern void phalcon_filter_alphanum(zval *return_value, zval *param);
extern void phalcon_filter_identifier(zval *return_value, zval *param);

/** Encoding */
extern void phalcon_is_basic_charset(zval *return_value, zval *param);

/** Escaping */
extern void phalcon_escape_css(zval *return_value, zval *param);
extern void phalcon_escape_js(zval *return_value, zval *param);
extern void phalcon_escape_htmlattr(zval *return_value, zval *param);
extern void phalcon_escape_html(zval *return_value, zval *str, zval *quote_style, zval *charset TSRMLS_DC);