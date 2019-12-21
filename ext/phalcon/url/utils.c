
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"

#include <ext/standard/php_smart_string.h>
#include <zend_smart_str.h>

#include <ext/standard/php_string.h>

void phalcon_get_uri(zval *return_value, zval *path)
{
	int i, found = 0, mark = 0;
	char *cursor, *str, ch;

	if (Z_TYPE_P(path) != IS_STRING) {
		RETURN_EMPTY_STRING();
	}

	if (Z_STRLEN_P(path) > 0) {
		cursor = Z_STRVAL_P(path) + Z_STRLEN_P(path) - 1;
		for (i = Z_STRLEN_P(path); i > 0; i--) {
			ch = *cursor;
			if (ch == '/' || ch == '\\') {
				found++;
				if (found == 1) {
					mark = i - 1;
				} else {
					str = emalloc(mark - i + 1);
					memcpy(str, Z_STRVAL_P(path) + i, mark - i);
					str[mark - i] = '\0';
					ZVAL_STRINGL(return_value, str, mark - i);
					return;
				}
			}
			cursor--;
		}
	}

	RETURN_EMPTY_STRING();
}

zval *phalcon_replace_marker(int named, zval *paths, zval *replacements, unsigned long *position, char *cursor, char *marker)
{
	unsigned int length = 0, variable_length, ch, j;
	char *item = NULL, *cursor_var, *variable = NULL;
	int not_valid = 0;
	zval *zv, *tmp;

	if (named) {
		length = cursor - marker - 1;
		item = estrndup(marker + 1, length);
		cursor_var = item;
		marker = item;
		for (j = 0; j < length; j++) {
			ch = *cursor_var;
			if (ch == '\0') {
				not_valid = 1;
				break;
			}
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
				if (zend_hash_str_exists(Z_ARRVAL_P(replacements), item, length)) {
					if ((zv = zend_hash_str_find(Z_ARRVAL_P(replacements), item, length)) != NULL) {
						efree(item);
						(*position)++;
						return zv;
					}
				}
			} else {
				if ((zv = zend_hash_index_find(Z_ARRVAL_P(paths), *position)) != NULL) {
					if (Z_TYPE_P(zv) == IS_STRING) {
						if (zend_hash_str_exists(Z_ARRVAL_P(replacements), Z_STRVAL_P(zv), Z_STRLEN_P(zv))) {
							if ((tmp = zend_hash_str_find(Z_ARRVAL_P(replacements), Z_STRVAL_P(zv), Z_STRLEN_P(zv))) != NULL) {
								(*position)++;
								return tmp;
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
void phalcon_replace_paths(zval *return_value, zval *pattern, zval *paths, zval *replacements TSRMLS_DC)
{

	char *cursor, *marker = NULL;
	unsigned int bracket_count = 0, parentheses_count = 0, intermediate = 0;
	unsigned char ch;
	smart_str route_str = {0};
	zend_ulong position = 1;
	int i;
	zval *replace, replace_copy;
	int use_copy, looking_placeholder = 0;

	if (Z_TYPE_P(pattern) != IS_STRING || Z_TYPE_P(replacements) != IS_ARRAY || Z_TYPE_P(paths) != IS_ARRAY) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for phalcon_replace_paths()");
		return;
	}

	if (Z_STRLEN_P(pattern) <= 0) {
		ZVAL_FALSE(return_value);
		return;
	}

	cursor = Z_STRVAL_P(pattern);
	if (*cursor == '/') {
		++cursor;
		i = 1;
	}
	else {
		i = 0;
	}

	if (!zend_hash_num_elements(Z_ARRVAL_P(paths))) {
		ZVAL_STRINGL(return_value, Z_STRVAL_P(pattern) + i, Z_STRLEN_P(pattern) - i);
		return;
	}

	for (; i < Z_STRLEN_P(pattern); ++i) {

		ch = *cursor;
		if (ch == '\0') {
			break;
		}

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
									use_copy = zend_make_printable_zval(replace, &replace_copy);
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
									use_copy = zend_make_printable_zval(replace, &replace_copy);
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
								use_copy = zend_make_printable_zval(replace, &replace_copy);
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

	if (route_str.s) {
		RETURN_STR(route_str.s);
	} else {
		smart_str_free(&route_str);
		RETURN_EMPTY_STRING();
	}
}
