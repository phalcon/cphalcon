
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

#include "ext/standard/php_smart_str.h"
#include "ext/standard/php_string.h"

zval *phalcon_replace_marker(int named, zval *paths, zval *replacements, unsigned long *position, char *cursor, char *marker){

	zval **zv, **tmp;
	int result = FAILURE;
	unsigned int length, variable_length, ch;
	char *item = NULL, *cursor_var, *variable = NULL;
	int not_valid = 0, j;

	if (named) {
		length = cursor - marker - 1;
		item = estrndup(marker + 1, length);
		cursor_var = item;
		marker = item;
		for (j = 0; j < length; j++) {
			ch = *cursor_var;
			if (j == 0 && !((ch >= 'a' && ch <='z') || (ch >= 'A' && ch <= 'Z'))){
				not_valid = 1;
				break;
			}
			if ((ch >= 'a' && ch <='z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '-' || ch == '_' || ch ==  ':') {
				if (ch == ':') {
					variable_length = cursor_var - marker;
					variable = estrndup(marker, variable_length);
					break;
				}
			} else {
				not_valid = 1;
				break;
			}
			cursor_var++;
		}
	}

	if (!not_valid) {

		if (zend_hash_index_exists(Z_ARRVAL_P(paths), *position)) {
			if (named) {
				if (variable) {
					efree(item);
					item = variable;
					length = variable_length;
				}
				if (zend_hash_exists(Z_ARRVAL_P(replacements), item, length + 1)) {
					if ((result = zend_hash_find(Z_ARRVAL_P(replacements), item, length + 1, (void**) &zv)) == SUCCESS) {
						efree(item);
						(*position)++;
						return *zv;
					}
				}
			} else {
				if ((result = zend_hash_index_find(Z_ARRVAL_P(paths), *position, (void**) &zv)) == SUCCESS) {
					if (Z_TYPE_PP(zv) == IS_STRING) {
						if (zend_hash_exists(Z_ARRVAL_P(replacements), Z_STRVAL_PP(zv), Z_STRLEN_PP(zv) + 1)) {
							if ((result = zend_hash_find(Z_ARRVAL_P(replacements), Z_STRVAL_PP(zv), Z_STRLEN_PP(zv) + 1, (void**) &tmp)) == SUCCESS) {
								(*position)++;
								return *tmp;
							}
						}
					}
				}
			}
		}

		(*position)++;
	}

	if (item) {
		efree(item);
	}

	return NULL;
}

/**
 * Replaces placeholders and named variables with their corresponding values in an array
 */
void phalcon_replace_paths(zval *return_value, zval *pattern, zval *paths, zval *replacements TSRMLS_DC){

	char *cursor, *marker;
	unsigned int i, bracket_count = 0, parentheses_count = 0, intermediate;
	unsigned char ch;
	smart_str route_str = {0};
	unsigned long position = 1;
	zval *replace, replace_copy;
	int use_copy, looking_placeholder = 0;

	if (Z_TYPE_P(pattern) != IS_STRING || Z_TYPE_P(replacements) != IS_ARRAY || Z_TYPE_P(paths) != IS_ARRAY) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for phalcon_replace_paths()");
		return;
	}

	if (Z_STRLEN_P(pattern) <= 0) {
		ZVAL_BOOL(return_value, 0);
		return;
	}

	if (!zend_hash_num_elements(Z_ARRVAL_P(paths))) {
		ZVAL_STRINGL(return_value, Z_STRVAL_P(pattern), Z_STRLEN_P(pattern), 1);
		return;
	}

	cursor = Z_STRVAL_P(pattern);

	/**
	 * Ignoring the first character, it must be a /
	 */
	 cursor++;

	for (i = 1; i < Z_STRLEN_P(pattern); i++) {

		ch = *cursor;

		if (parentheses_count == 0 && !looking_placeholder) {
			if (ch == '{') {
				if (bracket_count == 0) {
					marker = cursor;
					intermediate = 0;
				}
				bracket_count++;
			} else {
				if (ch == '}') {
					bracket_count--;
					if (intermediate > 0) {
						if (bracket_count == 0) {
							replace = phalcon_replace_marker(1, paths, replacements, &position, cursor, marker);
							if (replace) {
								use_copy = 0;
								if (Z_TYPE_P(replace) != IS_STRING) {
									zend_make_printable_zval(replace, &replace_copy, &use_copy);
									if (use_copy) {
										replace = &replace_copy;
									}
								}
								smart_str_appendl(&route_str, Z_STRVAL_P(replace), Z_STRLEN_P(replace));
								if (use_copy) {
									zval_dtor(&replace_copy);
								}
							}
							cursor++;
							continue;
						}
					}
				}
			}
		}

		if (bracket_count == 0 && !looking_placeholder) {
			if (ch == '(') {
				if (parentheses_count == 0) {
					marker = cursor;
					intermediate = 0;
				}
				parentheses_count++;
			} else {
				if (ch == ')') {
					parentheses_count--;
					if (intermediate > 0) {
						if (parentheses_count == 0) {
							replace = phalcon_replace_marker(0, paths, replacements, &position, cursor, marker);
							if (replace) {
								use_copy = 0;
								if (Z_TYPE_P(replace) != IS_STRING) {
									zend_make_printable_zval(replace, &replace_copy, &use_copy);
									if (use_copy) {
										replace = &replace_copy;
									}
								}
								smart_str_appendl(&route_str, Z_STRVAL_P(replace), Z_STRLEN_P(replace));
								if (use_copy) {
									zval_dtor(&replace_copy);
								}
							}
							cursor++;
							continue;
						}
					}
				}
			}
		}

		if (bracket_count == 0 && parentheses_count == 0) {
			if (looking_placeholder) {
				if (intermediate > 0) {
					if (ch < 'a' || ch > 'z' || i == (Z_STRLEN_P(pattern) - 1)) {
						replace = phalcon_replace_marker(0, paths, replacements, &position, cursor, marker);
						if (replace) {
							use_copy = 0;
							if (Z_TYPE_P(replace) != IS_STRING) {
								zend_make_printable_zval(replace, &replace_copy, &use_copy);
								if (use_copy) {
									replace = &replace_copy;
								}
							}
							smart_str_appendl(&route_str, Z_STRVAL_P(replace), Z_STRLEN_P(replace));
							if (use_copy) {
								zval_dtor(&replace_copy);
							}
						}
						looking_placeholder = 0;
						continue;
					}
				}
			} else {
				if (ch == ':') {
					looking_placeholder = 1;
					marker = cursor;
					intermediate = 0;
				}
			}
		}

		if (bracket_count > 0 || parentheses_count > 0 || looking_placeholder) {
			intermediate++;
		} else {
			smart_str_appendc(&route_str, ch);
		}

		cursor++;
	}
	smart_str_0(&route_str);

	if (route_str.len) {
		RETURN_STRINGL(route_str.c, route_str.len, 0);
	} else {
		smart_str_free(&route_str);
		RETURN_EMPTY_STRING();
	}

}