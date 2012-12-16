
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

#include "php.h"
#include "php_phalcon.h"
#include "php_main.h"
#include "ext/standard/php_smart_str.h"
#include "ext/standard/php_string.h"
#include "ext/standard/php_rand.h"
#include "ext/standard/php_lcg.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#define PH_RANDOM_ALNUM 0
#define PH_RANDOM_ALPHA 1
#define PH_RANDOM_HEXDEC 2
#define PH_RANDOM_NUMERIC 3
#define PH_RANDOM_NOZERO 4

/**
 * Fast call to php strlen
 */
void phalcon_fast_strlen(zval *return_value, zval *str){

	zval copy;
	int use_copy = 0;

	if (Z_TYPE_P(str) != IS_STRING) {
		zend_make_printable_zval(str, &copy, &use_copy);
		if (use_copy) {
			str = &copy;
		}
	}

	ZVAL_LONG(return_value, Z_STRLEN_P(str));

	if (use_copy) {
		zval_dtor(str);
	}
}

/**
 * Fast call to php strlen
 */
void phalcon_fast_strtolower(zval *return_value, zval *str){

	zval copy;
	int use_copy = 0;
	char *lower_str;
	unsigned int length;

	if (Z_TYPE_P(str) != IS_STRING) {
		zend_make_printable_zval(str, &copy, &use_copy);
		if (use_copy) {
			str = &copy;
		}
	}

	length = Z_STRLEN_P(str);
	lower_str = estrndup(Z_STRVAL_P(str), length);
	php_strtolower(lower_str, length);

	if (use_copy) {
		zval_dtor(str);
	}

	ZVAL_STRINGL(return_value, lower_str, length, 0);
}

/**
 * Fast call to php join  function
 */
void phalcon_fast_join(zval *result, zval *glue, zval *pieces TSRMLS_DC){

	if (Z_TYPE_P(glue) != IS_STRING || Z_TYPE_P(pieces) != IS_ARRAY) {
		ZVAL_NULL(result);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for join()");
		return;
	}

	php_implode(glue, pieces, result TSRMLS_CC);
}

/**
 * Fast join function
 * This function is an adaption of the php_implode function
 *
 */
void phalcon_fast_join_str(zval *return_value, char *glue, unsigned int glue_length, zval *pieces TSRMLS_DC){

	zval         **tmp;
	HashTable      *arr;
	HashPosition   pos;
	smart_str      implstr = {0};
	int            str_len, numelems, i = 0;
	zval tmp_val;

	if (Z_TYPE_P(pieces) != IS_ARRAY) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for fast_join()");
		return;
	}

	arr = Z_ARRVAL_P(pieces);
	numelems = zend_hash_num_elements(arr);

	if (numelems == 0) {
		RETURN_EMPTY_STRING();
	}

	zend_hash_internal_pointer_reset_ex(arr, &pos);

	while (zend_hash_get_current_data_ex(arr, (void **) &tmp, &pos) == SUCCESS) {
		switch ((*tmp)->type) {
			case IS_STRING:
				smart_str_appendl(&implstr, Z_STRVAL_PP(tmp), Z_STRLEN_PP(tmp));
				break;

			case IS_LONG: {
				char stmp[MAX_LENGTH_OF_LONG + 1];
				str_len = slprintf(stmp, sizeof(stmp), "%ld", Z_LVAL_PP(tmp));
				smart_str_appendl(&implstr, stmp, str_len);
			}
				break;

			case IS_BOOL:
				if (Z_LVAL_PP(tmp) == 1) {
					smart_str_appendl(&implstr, "1", sizeof("1")-1);
				}
				break;

			case IS_NULL:
				break;

			case IS_DOUBLE: {
				char *stmp;
				str_len = spprintf(&stmp, 0, "%.*G", (int) EG(precision), Z_DVAL_PP(tmp));
				smart_str_appendl(&implstr, stmp, str_len);
				efree(stmp);
			}
				break;

			case IS_OBJECT: {
				int copy;
				zval expr;
				zend_make_printable_zval(*tmp, &expr, &copy);
				smart_str_appendl(&implstr, Z_STRVAL(expr), Z_STRLEN(expr));
				if (copy) {
					zval_dtor(&expr);
				}
			}
				break;

			default:
				tmp_val = **tmp;
				zval_copy_ctor(&tmp_val);
				convert_to_string(&tmp_val);
				smart_str_appendl(&implstr, Z_STRVAL(tmp_val), Z_STRLEN(tmp_val));
				zval_dtor(&tmp_val);
				break;

		}

		if (++i != numelems) {
			smart_str_appendl(&implstr, glue, glue_length);
		}
		zend_hash_move_forward_ex(arr, &pos);
	}
	smart_str_0(&implstr);

	if (implstr.len) {
		RETURN_STRINGL(implstr.c, implstr.len, 0);
	} else {
		smart_str_free(&implstr);
		RETURN_EMPTY_STRING();
	}
}

/**
 * Convert dash/underscored texts returning camelized
 */
void phalcon_camelize(zval *return_value, zval *str TSRMLS_DC){

	int i;
	smart_str camelize_str = {0};
	char *marker, ch;

	if (Z_TYPE_P(str) != IS_STRING) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for camelize()");
		return;
	}

	marker = Z_STRVAL_P(str);
	for (i = 0; i < Z_STRLEN_P(str); i++) {
		ch = *marker;
		if (i == 0 || ch == '-' || ch == '_') {
			if (ch == '-' || ch == '_') {
				i++;
				marker++;
				ch = *marker;
			}
			if (ch >= 'a' && ch <= 'z') {
				smart_str_appendc(&camelize_str, (*marker)-32);
			} else {
				smart_str_appendc(&camelize_str, (*marker));
			}
			marker++;
			continue;
		}
		if (ch >= 'A' && ch <= 'Z') {
			smart_str_appendc(&camelize_str, (*marker)+32);
		} else {
			smart_str_appendc(&camelize_str, (*marker));
		}
		marker++;
	}
	smart_str_0(&camelize_str);

	if (camelize_str.len) {
		ZVAL_STRINGL(return_value, camelize_str.c, camelize_str.len, 0);
	} else {
		ZVAL_STRING(return_value, "", 1);
	}

}

/**
 * Convert dash/underscored texts returning camelized
 */
void phalcon_uncamelize(zval *return_value, zval *str TSRMLS_DC){

	int i;
	smart_str uncamelize_str = {0};
	char *marker, ch;

	if (Z_TYPE_P(str) != IS_STRING) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for camelize()");
		return;
	}

	marker = Z_STRVAL_P(str);
	for (i = 0; i < Z_STRLEN_P(str); i++) {
		ch = *marker;
		if (ch >= 'A' && ch <= 'Z') {
			if (i > 0) {
				smart_str_appendc(&uncamelize_str, '_');
			}
			smart_str_appendc(&uncamelize_str, (*marker)+32);
		} else {
			smart_str_appendc(&uncamelize_str, (*marker));
		}
		marker++;
	}
	smart_str_0(&uncamelize_str);

	if (uncamelize_str.len) {
		ZVAL_STRINGL(return_value, uncamelize_str.c, uncamelize_str.len, 0);
	} else {
		ZVAL_STRING(return_value, "", 1);
	}
}

/**
 * Fast call to explode php function
 */
void phalcon_fast_explode(zval *result, zval *delimiter, zval *str TSRMLS_DC){

	if (Z_TYPE_P(str) != IS_STRING || Z_TYPE_P(delimiter) != IS_STRING) {
		ZVAL_NULL(result);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for explode()");
		return;
	}

	array_init(result);
	php_explode(delimiter, str, result, LONG_MAX);
}

/**
 * Check if a string is contained into another
 */
int phalcon_memnstr(zval *haystack, zval *needle TSRMLS_DC){

	char *found = NULL;

	if (Z_TYPE_P(haystack) != IS_STRING || Z_TYPE_P(needle) != IS_STRING) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for memnstr()");
		return 0;
	}

	if (Z_STRLEN_P(haystack) >= Z_STRLEN_P(needle)) {
		found = php_memnstr(Z_STRVAL_P(haystack), Z_STRVAL_P(needle), Z_STRLEN_P(needle), Z_STRVAL_P(haystack) + Z_STRLEN_P(haystack));
	}

	if (found) {
		return 1;
	}

	return 0;
}

/**
 * Check if a string is contained into another
 */
int phalcon_memnstr_str(zval *haystack, char *needle, int needle_length TSRMLS_DC){

	char *found = NULL;

	if (Z_TYPE_P(haystack) != IS_STRING) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for memnstr()");
		return 0;
	}

	if (Z_STRLEN_P(haystack) >= needle_length) {
		found = php_memnstr(Z_STRVAL_P(haystack), needle, needle_length, Z_STRVAL_P(haystack) + Z_STRLEN_P(haystack));
	}

	if (found) {
		return 1;
	}

	return 0;
}

/**
 * Inmediate function resolution for strpos function
 */
void phalcon_fast_strpos(zval *return_value, zval *haystack, zval *needle TSRMLS_DC){

	char *found = NULL;

	if (Z_TYPE_P(haystack) != IS_STRING || Z_TYPE_P(needle) != IS_STRING) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for strpos()");
		return;
	}

	if (!Z_STRLEN_P(needle)) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Empty delimiter");
		return;
	}

	found = php_memnstr(Z_STRVAL_P(haystack), Z_STRVAL_P(needle), Z_STRLEN_P(needle), Z_STRVAL_P(haystack) + Z_STRLEN_P(haystack));

	if (found) {
		ZVAL_LONG(return_value, found-Z_STRVAL_P(haystack));
	} else {
		ZVAL_BOOL(return_value, 0);
	}

}

/**
 * Inmediate function resolution for strpos function
 */
void phalcon_fast_strpos_str(zval *return_value, zval *haystack, char *needle, int needle_length TSRMLS_DC){

	char *found = NULL;

	if (Z_TYPE_P(haystack) != IS_STRING) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for strpos()");
		return;
	}

	found = php_memnstr(Z_STRVAL_P(haystack), needle, needle_length, Z_STRVAL_P(haystack) + Z_STRLEN_P(haystack));

	if (found) {
		ZVAL_LONG(return_value, found-Z_STRVAL_P(haystack));
	} else {
		ZVAL_BOOL(return_value, 0);
	}

}

/**
 * Inmediate function resolution for stripos function
 */
void phalcon_fast_stripos_str(zval *return_value, zval *haystack, char *needle, int needle_length TSRMLS_DC){

	char *found = NULL;
	char *needle_dup, *haystack_dup;

	if (Z_TYPE_P(haystack) != IS_STRING) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for stripos()");
		return;
	}

	haystack_dup = estrndup(Z_STRVAL_P(haystack), Z_STRLEN_P(haystack));
	php_strtolower(haystack_dup, Z_STRLEN_P(haystack));

	needle_dup = estrndup(needle, needle_length);
	php_strtolower(needle_dup, needle_length);

	found = php_memnstr(haystack_dup, needle, needle_length, haystack_dup + Z_STRLEN_P(haystack));

	efree(haystack_dup);
	efree(needle_dup);

	if (found) {
		ZVAL_LONG(return_value, found-Z_STRVAL_P(haystack));
	} else {
		ZVAL_BOOL(return_value, 0);
	}

}


/**
 * Inmediate function resolution for str_replace function
 */
void phalcon_fast_str_replace(zval *return_value, zval *search, zval *replace, zval *subject TSRMLS_DC){

	zval replace_copy, search_copy;
	int copy_replace = 0, copy_search = 0;

	if (Z_TYPE_P(subject) != IS_STRING) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for str_replace()");
		return;
	}

	if (Z_TYPE_P(replace) != IS_STRING) {
		zend_make_printable_zval(replace, &replace_copy, &copy_replace);
		if (copy_replace) {
			replace = &replace_copy;
		}
	}

	if (Z_TYPE_P(search) != IS_STRING) {
		zend_make_printable_zval(search, &search_copy, &copy_search);
		if (copy_search) {
			search = &search_copy;
		}
	}

	Z_TYPE_P(return_value) = IS_STRING;
	if (Z_STRLEN_P(subject) == 0) {
		ZVAL_STRINGL(return_value, "", 0, 1);
		return;
	}

	if (Z_STRLEN_P(search) == 1) {
		php_char_to_str_ex(Z_STRVAL_P(subject),
			Z_STRLEN_P(subject),
			Z_STRVAL_P(search)[0],
			Z_STRVAL_P(replace),
			Z_STRLEN_P(replace),
			return_value,
			1,
			NULL);
	} else {
		if (Z_STRLEN_P(search) > 1) {
			Z_STRVAL_P(return_value) = php_str_to_str_ex(Z_STRVAL_P(subject), Z_STRLEN_P(subject),
				Z_STRVAL_P(search), Z_STRLEN_P(search),
				Z_STRVAL_P(replace), Z_STRLEN_P(replace), &Z_STRLEN_P(return_value), 1, NULL);
		} else {
			MAKE_COPY_ZVAL(&subject, return_value);
		}
	}

	if (copy_replace) {
		zval_dtor(replace);
	}

	if (copy_search) {
		zval_dtor(search);
	}

}

/**
 * Extracts parameters from a string
 * An initialized zval array must be passed as second parameter
 */
void phalcon_extract_named_params(zval *return_value, zval *str, zval *matches){

	unsigned int i, j, bracket_count = 0, parentheses_count = 0, ch;
	unsigned int intermediate, length, number_matches = 0;
	int variable_length, regexp_length, not_valid;
	char *cursor, *cursor_var, *marker;
	char *item, *variable = NULL, *regexp;
	smart_str route_str = {0};

	if (Z_TYPE_P(str) != IS_STRING) {
		ZVAL_BOOL(return_value, 0);
		return;
	}

	if (Z_STRLEN_P(str) <= 0) {
		ZVAL_BOOL(return_value, 0);
		return;
	}

	cursor = Z_STRVAL_P(str);
	for (i = 0; i<Z_STRLEN_P(str); i++) {
		ch = *cursor;

		if (parentheses_count == 0) {
			if (ch == '{') {
				if (bracket_count == 0) {
					marker = cursor;
					intermediate = 0;
					not_valid = 0;
				}
				bracket_count++;
			} else {
				if (ch == '}') {
					bracket_count--;
					if (intermediate > 0) {
						if (bracket_count == 0) {

							number_matches++;

							variable = NULL;
							length = cursor - marker - 1;
							item = estrndup(marker + 1, length);
							cursor_var = item;
							marker = item;
							for (j=0; j<length; j++) {
								ch = *cursor_var;
								if (j == 0 && !((ch >= 'a' && ch <='z') || (ch >= 'A' && ch <='Z'))){
									not_valid = 1;
									break;
								}
								if ((ch >= 'a' && ch <='z') || (ch >= 'A' && ch <='Z') || (ch >= '0' && ch <='9') || ch == '-' || ch == '_' || ch ==  ':') {
									if (ch == ':') {
										regexp_length = length - j - 1;
										variable_length = cursor_var - marker;
										variable = estrndup(marker, variable_length);
										regexp = estrndup(cursor_var+1, regexp_length);
										break;
									}
								} else {
									not_valid = 1;
									break;
								}
								cursor_var++;
							}

							if (!not_valid) {
								{
									zval *tmp;
									ALLOC_INIT_ZVAL(tmp);
									ZVAL_LONG(tmp, number_matches);

									if (variable) {
										smart_str_appendc(&route_str, '(');
										smart_str_appendl(&route_str, regexp, regexp_length);
										smart_str_appendc(&route_str, ')');
										zend_hash_update(Z_ARRVAL_P(matches), variable, variable_length+1, &tmp, sizeof(zval *), NULL);
										efree(regexp);
										efree(variable);
									} else {
										smart_str_appendl(&route_str, "([^/]*)", strlen("([^/]*)"));
										zend_hash_update(Z_ARRVAL_P(matches), item, length+1, &tmp, sizeof(zval *), NULL);
									}
								}
							} else {
								smart_str_appendc(&route_str, '{');
								smart_str_appendl(&route_str, item, length);
								smart_str_appendc(&route_str, '}');
							}

							efree(item);

							cursor++;
							continue;
						}
					}
				}
			}

		}

		if (bracket_count == 0) {
			if (ch == '(') {
				parentheses_count++;
			} else {
				if (ch == ')') {
					parentheses_count--;
					if (parentheses_count == 0) {
						number_matches++;
					}
				}
			}
		}

		if (bracket_count > 0) {
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

zval *phalcon_replace_marker(int named, zval *paths, zval *replacements, ulong *position, char *cursor, char *marker){

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
		for (j=0; j<length; j++) {
			ch = *cursor_var;
			if (j == 0 && !((ch >= 'a' && ch <='z') || (ch >= 'A' && ch <='Z'))){
				not_valid = 1;
				break;
			}
			if ((ch >= 'a' && ch <='z') || (ch >= 'A' && ch <='Z') || (ch >= '0' && ch <='9') || ch == '-' || ch == '_' || ch ==  ':') {
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
				if (zend_hash_exists(Z_ARRVAL_P(replacements), item, length+1)) {
					if ((result = zend_hash_find(Z_ARRVAL_P(replacements), item, length+1, (void**) &zv)) == SUCCESS) {
						efree(item);
						(*position)++;
						return *zv;
					}
				}
			} else {
				if ((result = zend_hash_index_find(Z_ARRVAL_P(paths), *position, (void**) &zv)) == SUCCESS) {
					if (Z_TYPE_PP(zv) == IS_STRING) {
						if (zend_hash_exists(Z_ARRVAL_P(replacements), Z_STRVAL_PP(zv), Z_STRLEN_PP(zv)+1)) {
							if ((result = zend_hash_find(Z_ARRVAL_P(replacements), Z_STRVAL_PP(zv), Z_STRLEN_PP(zv)+1, (void**) &tmp)) == SUCCESS) {
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
	unsigned int ch, bracket_count = 0, parentheses_count = 0, intermediate;
	smart_str route_str = {0};
	ulong position = 1;
	zval *replace, replace_copy;
	int i, use_copy, looking_placeholder = 0;

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
	for (i = 0; i < Z_STRLEN_P(pattern); i++) {

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
					if (ch < 'a' || ch > 'z' || i == (Z_STRLEN_P(pattern)-1)) {
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

/**
 * Checks if a zval string starts with a zval string
 */
int phalcon_start_with(zval *str, zval *compared, zval *ignore_case){

	int ignore = 1;
	unsigned int i, number;
	char *op1_cursor, *op2_cursor;

	if (Z_TYPE_P(str) != IS_STRING || Z_TYPE_P(compared) != IS_STRING) {
		return 0;
	}

	if (!Z_STRLEN_P(compared) || !Z_STRLEN_P(str)) {
		return 0;
	}

	if (Z_STRLEN_P(compared) > Z_STRLEN_P(str)) {
		return 0;
	}

	if (ignore_case) {
		ignore = zend_is_true(ignore_case);
	}

	if (Z_STRLEN_P(compared) < Z_STRLEN_P(str)) {
		number = Z_STRLEN_P(compared);
	} else {
		number = Z_STRLEN_P(str);
	}

	op1_cursor = Z_STRVAL_P(str);
	op2_cursor = Z_STRVAL_P(compared);
	for (i = 0; i < number; i++) {
		if (ignore) {
			if ((*op1_cursor) != (*op2_cursor)) {
				return 0;
			}
		} else {
			if ((*op1_cursor) != (*op2_cursor)) {
				if (((*op1_cursor)+32) != (*op2_cursor)) {
					if ((*op1_cursor-32) != (*op2_cursor)) {
						return 0;
					}
				}
			}
		}
		op1_cursor++;
		op2_cursor++;
	}

	return 1;
}

/**
 * Checks if a zval string starts with a string
 */
int phalcon_start_with_str(zval *str, char *compared, unsigned int compared_length){

	char *op1_cursor, *op2_cursor;
	unsigned int i, number;

	if (Z_TYPE_P(str) != IS_STRING) {
		return 0;
	}

	if (compared_length > Z_STRLEN_P(str)) {
		return 0;
	}

	if (compared_length < Z_STRLEN_P(str)) {
		number = compared_length;
	} else {
		number = Z_STRLEN_P(str);
	}

	op1_cursor = Z_STRVAL_P(str);
	op2_cursor = compared;
	for (i = 0; i<number; i++){
		if ((*op1_cursor) != (*op2_cursor)) {
			return 0;
		}
		op1_cursor++;
		op2_cursor++;
	}

	return 1;
}

/**
 * Checks if a string starts with other  string
 */
int phalcon_start_with_str_str(char *str, unsigned int str_length, char *compared, unsigned int compared_length){

	char *op1_cursor, *op2_cursor;
	unsigned int i, number;

	if (compared_length > str_length) {
		return 0;
	}

	if (compared_length < str_length) {
		number = compared_length;
	} else {
		number = str_length;
	}

	op1_cursor = str;
	op2_cursor = compared;
	for (i = 0; i<number; i++){
		if ((*op1_cursor) != (*op2_cursor)) {
			return 0;
		}
		op1_cursor++;
		op2_cursor++;
	}

	return 1;
}

/**
 * Checks if a zval string ends with a zval string
 */
int phalcon_end_with(zval *str, zval *compared, zval *ignore_case){

	int ignore = 1, number = 0;
	unsigned int i;
	char *op1_cursor, *op2_cursor;

	if (Z_TYPE_P(str) != IS_STRING || Z_TYPE_P(compared) != IS_STRING) {
		return 0;
	}

	if (!Z_STRLEN_P(compared) || !Z_STRLEN_P(str)) {
		return 0;
	}

	if (Z_STRLEN_P(compared) > Z_STRLEN_P(str)) {
		return 0;
	}

	if (ignore_case) {
		ignore = zend_is_true(ignore_case);
	}

	op1_cursor = Z_STRVAL_P(str);
	op2_cursor = Z_STRVAL_P(compared);

	op1_cursor += (Z_STRLEN_P(str)-1);
	op2_cursor += (Z_STRLEN_P(compared)-1);

	if (Z_STRLEN_P(compared) < Z_STRLEN_P(str)) {
		number = Z_STRLEN_P(compared);
	} else {
		number = Z_STRLEN_P(str);
	}

	for (i = number; i > 0; i--) {
		if (ignore) {
			if ((*op1_cursor) != (*op2_cursor)) {
				return 0;
			}
		} else {
			if ((*op1_cursor) != (*op2_cursor)) {
				if (((*op1_cursor)+32) != (*op2_cursor)) {
					if ((*op1_cursor-32) != (*op2_cursor)) {
						return 0;
					}
				}
			}
		}
		op1_cursor--;
		op2_cursor--;
	}

	return 1;
}


void phalcon_random_string(zval *return_value, zval *type, zval *length TSRMLS_DC){

	long i, ch, rand_type;
	smart_str random_str = {0};

	if (Z_TYPE_P(type) != IS_LONG) {
		return;
	}

	if (Z_LVAL_P(type) > PH_RANDOM_NOZERO) {
		return;
	}

	if (Z_TYPE_P(length) != IS_LONG) {
		return;
	}

	/** Generate seed */
	if (!BG(mt_rand_is_seeded)) {
		php_mt_srand(GENERATE_SEED() TSRMLS_CC);
	}

	for (i = 0; i < Z_LVAL_P(length); i++) {

		switch (Z_LVAL_P(type)) {
			case PH_RANDOM_ALNUM:
				rand_type = (long) (php_mt_rand(TSRMLS_C) >> 1);
				RAND_RANGE(rand_type, 0, 3, PHP_MT_RAND_MAX);
				break;
			case PH_RANDOM_ALPHA:
				rand_type = (long) (php_mt_rand(TSRMLS_C) >> 1);
				RAND_RANGE(rand_type, 1, 2, PHP_MT_RAND_MAX);
				break;
			case PH_RANDOM_HEXDEC:
				rand_type = (long) (php_mt_rand(TSRMLS_C) >> 1);
				RAND_RANGE(rand_type, 0, 1, PHP_MT_RAND_MAX);
				break;
			case PH_RANDOM_NUMERIC:
				rand_type = 0;
				break;
			case PH_RANDOM_NOZERO:
				rand_type = 5;
				break;
			default:
				continue;
		}

		switch (rand_type) {
			case 0:
				ch = (long) (php_mt_rand(TSRMLS_C) >> 1);
				RAND_RANGE(ch, '0', '9', PHP_MT_RAND_MAX);
				break;
			case 1:
				ch = (long) (php_mt_rand(TSRMLS_C) >> 1);
				RAND_RANGE(ch, 'a', 'f', PHP_MT_RAND_MAX);
				break;
			case 2:
				ch = (long) (php_mt_rand(TSRMLS_C) >> 1);
				RAND_RANGE(ch, 'a', 'z', PHP_MT_RAND_MAX);
				break;
			case 3:
				ch = (long) (php_mt_rand(TSRMLS_C) >> 1);
				RAND_RANGE(ch, 'A', 'Z', PHP_MT_RAND_MAX);
				break;
			case 5:
				ch = (long) (php_mt_rand(TSRMLS_C) >> 1);
				RAND_RANGE(ch, '1', '9', PHP_MT_RAND_MAX);
				break;
			default:
				continue;
		}

		smart_str_appendc(&random_str, (unsigned int) ch);
	}


	smart_str_0(&random_str);

	if (random_str.len) {
		RETURN_STRINGL(random_str.c, random_str.len, 0);
	} else {
		smart_str_free(&random_str);
		RETURN_EMPTY_STRING();
	}

}

/**
 * Removes slashes at the end of a string
 */
void phalcon_remove_extra_slashes(zval *return_value, zval *str){

	char *cursor, *removed_str;
	unsigned int i;

	if (Z_TYPE_P(str) != IS_STRING) {
		RETURN_EMPTY_STRING();
		return;
	}

	if (Z_STRLEN_P(str) > 1) {
		cursor = Z_STRVAL_P(str);
		cursor += (Z_STRLEN_P(str)-1);
		for (i = Z_STRLEN_P(str); i > 0; i--) {
			if ((*cursor) == '/') {
				cursor--;
				continue;
			}
			break;
		}
	} else {
		i = Z_STRLEN_P(str);
	}

	removed_str = emalloc(i + 1);
	memcpy(removed_str, Z_STRVAL_P(str), i);
	removed_str[i] = '\0';

	RETURN_STRINGL(removed_str, i, 0);

}