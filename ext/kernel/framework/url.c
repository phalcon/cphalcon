
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

#include "php.h"
#include "php_phalcon.h"
#include "php_main.h"

void phalcon_get_uri(zval *return_value, zval *path TSRMLS_DC) {

	int i, found = 0, mark;
	char *cursor, *str, ch;

	if (Z_TYPE_P(path) != IS_STRING) {
		RETURN_EMPTY_STRING();
	}

	if (Z_STRLEN_P(path) > 0) {
		cursor = Z_STRVAL_P(path) + Z_STRLEN_P(path) - 1;
		for (i = Z_STRLEN_P(path); i >= 0; i--) {
			ch = *cursor;
			if (ch == '/' || ch == '\\') {
				found++;
				if (found == 1) {
					mark = i - 1;
				} else {
					str = emalloc(mark - i + 1);
					memcpy(str, Z_STRVAL_P(path) + i, mark - i);
					str[mark - i] = '\0';
					ZVAL_STRINGL(return_value, str, mark - i, 0);
					return;
				}
			}
			cursor--;
		}
	}

	RETURN_EMPTY_STRING();
}