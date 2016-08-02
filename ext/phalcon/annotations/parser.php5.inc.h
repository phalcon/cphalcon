
#include "php_phalcon.h"
#include "phalcon.h"

#include <ext/standard/php_smart_str.h>
#include <main/spprintf.h>

#include "parser.php5.h"
#include "scanner.h"
#include "annot.h"

#include "kernel/main.h"
#include "kernel/exception.h"

static inline zval *phannot_alloc_zval()
{
    zval *ret;
    MAKE_STD_ZVAL(ret);
    return ret;
}

#define phannot_add_assoc_stringl(var, index, str, len) add_assoc_stringl(var, index, str, len, 0);
#define phannot_add_assoc_string_copy(var, index, str, copy) add_assoc_string(var, index, str, copy);
#define PHANNOT_IS_INTERNED(z) IS_INTERNED(z)

static zval *phannot_ret_literal_zval(int type, phannot_parser_token *T)
{
	zval *ret;

    ret = phannot_alloc_zval();

	array_init_size(ret, 2);
	add_assoc_long(ret, "type", type);
	if (T) {
		phannot_add_assoc_stringl(ret, "value", T->token, T->token_len);
		efree(T);
	}

	return ret;
}

static zval *phannot_ret_array(zval *items)
{
	zval *ret;

	ret = phannot_alloc_zval();
	array_init_size(ret, 2);
	add_assoc_long(ret, "type", PHANNOT_T_ARRAY);

	if (items) {
		add_assoc_zval(ret, "items", items);
	}

	return ret;
}

static zval *phannot_ret_zval_list(zval *list_left, zval *right_list)
{
	zval *ret;
	HashTable *list;

	ret = phannot_alloc_zval();
	array_init(ret);

	if (list_left) {

		list = Z_ARRVAL_P(list_left);
		if (zend_hash_index_exists(list, 0)) {
            {
                HashPosition pos;
                zend_hash_internal_pointer_reset_ex(list, &pos);
    			for (;; zend_hash_move_forward_ex(list, &pos)) {

    				zval ** item;

    				if (zend_hash_get_current_data_ex(list, (void**) &item, &pos) == FAILURE) {
    					break;
    				}

    				Z_ADDREF_PP(item);
    				add_next_index_zval(ret, *item);
    			}
    			zval_ptr_dtor(&list_left);
            }
		} else {
			add_next_index_zval(ret, list_left);
		}
	}

	add_next_index_zval(ret, right_list);

	return ret;
}

static zval *phannot_ret_named_item(phannot_parser_token *name, zval *expr)
{
	zval *ret;

	ret = phannot_alloc_zval();
	array_init_size(ret, 2);

	add_assoc_zval(ret, "expr", expr);
	if (name != NULL) {
		phannot_add_assoc_stringl(ret, "name", name->token, name->token_len);
		efree(name);
	}

	return ret;
}

static zval *phannot_ret_annotation(phannot_parser_token *name, zval *arguments, phannot_scanner_state *state)
{
	zval *ret;

	ret = phannot_alloc_zval();
	array_init_size(ret, 5);

	add_assoc_long(ret, "type", PHANNOT_T_ANNOTATION);

	if (name) {
		phannot_add_assoc_stringl(ret, "name", name->token, name->token_len);        
		efree(name);
	}

	if (arguments) {
		add_assoc_zval(ret, "arguments", arguments);
	}

	phannot_add_assoc_string_copy(ret, "file", (char*)state->active_file, !PHANNOT_IS_INTERNED(state->active_file));
	add_assoc_long(ret, "line", state->active_line);

	return ret;
}
