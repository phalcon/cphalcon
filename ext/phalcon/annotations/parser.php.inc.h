
#include "php_phalcon.h"
#include "phalcon.h"

#if PHP_VERSION_ID < 80500
#include <ext/standard/php_smart_string.h>
#endif
#include <zend_smart_str.h>

#include <main/spprintf.h>

#include "parser.php.h"
#include "scanner.h"
#include "annot.h"

#include "kernel/main.h"
#include "kernel/exception.h"

#define phannot_add_assoc_stringl(var, index, str, len) add_assoc_stringl(var, index, str, len);
#define phannot_add_assoc_string(var, index, str) add_assoc_string(var, index, str);

static void phannot_ret_literal_zval(zval *ret, int type, phannot_parser_token *T)
{
    array_init(ret);

	add_assoc_long(ret, "type", type);
	if (T) {
		phannot_add_assoc_stringl(ret, "value", T->token, T->token_len);
        efree(T->token);
		efree(T);
	}
}

static void phannot_ret_array(zval *ret, zval *items)
{
	array_init(ret);

	add_assoc_long(ret, "type", PHANNOT_T_ARRAY);

	if (items) {
		add_assoc_zval(ret, "items", items);
	}
}

static void phannot_ret_zval_list(zval *ret, zval *list_left, zval *right_list)
{
	if (list_left) {
		if (zend_hash_index_exists(Z_ARRVAL_P(list_left), 0)) {
			/*
			 * list_left is the list built so far. Take it over instead of
			 * copying every item on each reduction (that made a list of n
			 * items cost O(n^2)). The parser drops the source slot after
			 * the reduction, so the ownership moves with the zval.
			 */
			ZVAL_COPY_VALUE(ret, list_left);
			ZVAL_UNDEF(list_left);
			SEPARATE_ARRAY(ret);
		} else {
			array_init(ret);
			add_next_index_zval(ret, list_left);
		}
	} else {
		array_init(ret);
	}

	if (right_list) {
		add_next_index_zval(ret, right_list);
	}
}

static void phannot_ret_named_item(zval *ret, phannot_parser_token *name, zval *expr)
{
	array_init(ret);

	add_assoc_zval(ret, "expr", expr);
	if (name != NULL) {
		phannot_add_assoc_stringl(ret, "name", name->token, name->token_len);
        efree(name->token);
		efree(name);
	}
}

static void phannot_ret_annotation(zval *ret, phannot_parser_token *name, zval *arguments, phannot_scanner_state *state)
{
	array_init(ret);

	add_assoc_long(ret, "type", PHANNOT_T_ANNOTATION);

	if (name) {
		phannot_add_assoc_stringl(ret, "name", name->token, name->token_len);
        efree(name->token);
		efree(name);
	}

	if (arguments) {
		add_assoc_zval(ret, "arguments", arguments);
	}

	phannot_add_assoc_string(ret, "file", (char*) state->active_file);
	add_assoc_long(ret, "line", state->active_line);
}
