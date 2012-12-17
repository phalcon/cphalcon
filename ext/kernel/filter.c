
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "php_main.h"
#include "ext/standard/php_smart_str.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Filter alphanum string
 */
void phalcon_filter_alphanum(zval *return_value, zval *param){

	int i, ch;
	smart_str filtered_str = {0};
	zval copy;
	int use_copy = 0;

	if (Z_TYPE_P(param) != IS_STRING) {
		zend_make_printable_zval(param, &copy, &use_copy);
		if (use_copy) {
			param = &copy;
		}
	}

	for (i=0; i < Z_STRLEN_P(param); i++) {
		ch = Z_STRVAL_P(param)[i];
		if ((ch > 96 && ch < 123)||(ch > 64 && ch < 91)||(ch > 47 && ch < 58)) {
			smart_str_appendc(&filtered_str, ch);
		}
	}

	if (use_copy) {
		zval_dtor(param);
	}

	smart_str_0(&filtered_str);

	if (filtered_str.len) {
		RETURN_STRINGL(filtered_str.c, filtered_str.len, 0);
	} else {
		smart_str_free(&filtered_str);
		RETURN_EMPTY_STRING();
	}
}

/**
 * Filter identifiers string like variables or database columns/tables
 */
void phalcon_filter_identifier(zval *return_value, zval *param){

	int i, ch;
	zval copy;
	smart_str filtered_str = {0};
	int use_copy = 0;

	if (Z_TYPE_P(param) != IS_STRING) {
		zend_make_printable_zval(param, &copy, &use_copy);
		if (use_copy) {
			param = &copy;
		}
	}

	for (i=0; i < Z_STRLEN_P(param); i++) {
		ch = Z_STRVAL_P(param)[i];
		if ((ch > 96 && ch < 123) || (ch > 64 && ch < 91) || (ch > 47 && ch < 58) || ch == 95) {
			smart_str_appendc(&filtered_str, ch);
		}
	}

	if (use_copy) {
		zval_dtor(param);
	}

	smart_str_0(&filtered_str);

	if (filtered_str.len) {
		RETURN_STRINGL(filtered_str.c, filtered_str.len, 0);
	} else {
		smart_str_free(&filtered_str);
		RETURN_EMPTY_STRING();
	}

}