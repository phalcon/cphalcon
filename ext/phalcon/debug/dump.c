
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
/**
 * Phalcon\Debug\Dump
 *
 * Dumps information about a variable
 */
ZEPHIR_INIT_CLASS(Phalcon_Debug_Dump) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Debug, Dump, phalcon, debug_dump, phalcon_debug_dump_method_entry, 0);

	zend_declare_property_null(phalcon_debug_dump_ce, SL("_styles"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_debug_dump_ce, SL("methods"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Debug\Dump constructor
 *
 * @param array styles
 */
PHP_METHOD(Phalcon_Debug_Dump, __construct) {

	zval *styles = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &styles);

	if (!styles) {
		styles = ZEPHIR_GLOBAL(global_null);
	}


	if ((Z_TYPE_P(styles) != IS_ARRAY)) {
		if ((Z_TYPE_P(styles) != IS_NULL)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_debug_exception_ce, "The styles must be a array");
			return;
		}
	}
	zephir_call_method_p1_noret(this_ptr, "setstyles", styles);
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("methods"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns an HTML string of debugging information about any number of
 * variables, each wrapped in a "pre" tag.
 *
 *<code>
 *echo (new Phalcon\Debug\Dump())->vars($foo, $bar, $baz);
 *</code>
 *
 * @param mixed variable
 * @param ...
 * @return string
 */
PHP_METHOD(Phalcon_Debug_Dump, vars) {

	zend_function *_5 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *key = NULL, *value = NULL, *vars, *output, **_2, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(vars);
	zephir_call_func(vars, "func_get_args");
	ZEPHIR_INIT_VAR(output);
	ZVAL_STRING(output, "", 1);
	zephir_is_iterable(vars, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_INIT_NVAR(_3);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SV(_4, "var ", key);
		zephir_call_method_p2_cache(_3, this_ptr, "dump", &_5, value, _4);
		zephir_concat_self(&output, _3 TSRMLS_CC);
	}
	RETURN_CCTOR(output);

}

/**
 * Returns an HTML string of information about a single variable.
 *
 *<code>
 *echo (new Phalcon\Debug\Dump())->dump($foo, "foo");
 *</code>
 *
 * @param mixed variable
 * @param string name
 * @return string
 */
PHP_METHOD(Phalcon_Debug_Dump, dump) {

	zval *variable, *name = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &variable, &name);

	if (!name) {
		name = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "pre", 1);
	zephir_call_method_p1(_0, this_ptr, "getstyle", _1);
	ZEPHIR_INIT_BNVAR(_1);
	zephir_call_method_p2(_1, this_ptr, "output", variable, name);
	ZEPHIR_CONCAT_SVSVSVS(return_value, "<pre style='", _0, "'>", name, " ", _1, "</pre>");
	RETURN_MM();

}

/**
 * Prepare an HTML string of information about a single variable.
 *
 * @param mixed variable
 * @param string name
 * @param intiger tab
 * @return  string
 */
PHP_METHOD(Phalcon_Debug_Dump, output) {

	zend_function *_11 = NULL, *_16 = NULL, *_19 = NULL, *_22 = NULL, *_27 = NULL, *_30 = NULL;
	HashTable *_6, *_25;
	HashPosition _5, _24;
	zval *variable, *name = NULL, *tab = NULL, *key = NULL, *value = NULL, *output, *space, *type = NULL, *attr = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL, _4 = zval_used_for_init, **_7, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_17 = NULL, *_18, *_20 = NULL, *_21 = NULL, *_23 = NULL, **_26, *_28 = NULL, *_29 = NULL, _31;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &variable, &name, &tab);

	if (!name) {
		name = ZEPHIR_GLOBAL(global_null);
	}
	if (!tab) {
		ZEPHIR_INIT_VAR(tab);
		ZVAL_LONG(tab, 1);
	}


	ZEPHIR_INIT_VAR(space);
	ZVAL_STRING(space, "  ", 1);
	ZEPHIR_INIT_VAR(output);
	ZVAL_STRING(output, "", 1);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "is_array", variable);
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_1);
		array_init_size(_1, 3);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "arr", 1);
		zephir_call_method_p1(_2, this_ptr, "getstyle", _3);
		zephir_array_update_string(&_1, SL(":style"), &_2, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_1, SS(":count"), zephir_fast_count_int(variable TSRMLS_CC));
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "<b style =':style'>Array</b> (<span style =':style'>:count</span>) (\n", 0);
		ZEPHIR_INIT_NVAR(_2);
		zephir_call_func_p2(_2, "strtr", &_4, _1);
		zephir_concat_self(&output, _2 TSRMLS_CC);
		zephir_is_iterable(variable, &_6, &_5, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
			; zend_hash_move_forward_ex(_6, &_5)
		) {
			ZEPHIR_GET_HMKEY(key, _6, _5);
			ZEPHIR_GET_HVALUE(value, _7);
			ZEPHIR_INIT_NVAR(_3);
			zephir_call_func_p2(_3, "str_repeat", space, tab);
			ZEPHIR_INIT_NVAR(_8);
			array_init_size(_8, 3);
			ZEPHIR_INIT_NVAR(_9);
			ZEPHIR_INIT_NVAR(_10);
			ZVAL_STRING(_10, "arr", 1);
			zephir_call_method_p1_cache(_9, this_ptr, "getstyle", &_11, _10);
			zephir_array_update_string(&_8, SL(":style"), &_9, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_8, SL(":key"), &key, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_STRING(&_4, "[<span style=':style'>:key</span>] => ", 0);
			ZEPHIR_INIT_NVAR(_9);
			zephir_call_func_p2(_9, "strtr", &_4, _8);
			ZEPHIR_INIT_LNVAR(_12);
			ZEPHIR_CONCAT_VV(_12, _3, _9);
			zephir_concat_self(&output, _12 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_10);
			zephir_call_func_p1(_10, "is_int", key);
			if ((((ZEPHIR_IS_LONG(tab, 0) && !ZEPHIR_IS_STRING(name, "")) && !zephir_is_true(_10)) && ZEPHIR_IS_EQUAL(name, key))) {
				continue;
			} else {
				ZEPHIR_INIT_NVAR(_13);
				ZEPHIR_INIT_NVAR(_14);
				ZVAL_STRING(_14, "", 1);
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_LONG(_15, (zephir_get_numberval(tab) + 1));
				zephir_call_method_p3_cache(_13, this_ptr, "output", &_16, value, _14, _15);
				ZEPHIR_INIT_LNVAR(_17);
				ZEPHIR_CONCAT_VS(_17, _13, "\n");
				zephir_concat_self(&output, _17 TSRMLS_CC);
			}
		}
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, (zephir_get_numberval(tab) - 1));
		ZEPHIR_INIT_NVAR(_8);
		zephir_call_func_p2(_8, "str_repeat", space, &_4);
		ZEPHIR_CONCAT_VVS(return_value, output, _8, ")");
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_1);
	zephir_call_func_p1(_1, "is_object", variable);
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(_2);
		array_init_size(_2, 3);
		ZEPHIR_INIT_NVAR(_3);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "obj", 1);
		zephir_call_method_p1(_3, this_ptr, "getstyle", _9);
		zephir_array_update_string(&_2, SL(":style"), &_3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_3);
		zephir_get_class(_3, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_2, SL(":class"), &_3, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>Object</b> :class", 0);
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_func_p2(_3, "strtr", &_4, _2);
		zephir_concat_self(&output, _3 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_9);
		zephir_call_func_p1(_9, "get_parent_class", variable);
		if (zephir_is_true(_9)) {
			ZEPHIR_INIT_NVAR(_10);
			array_init_size(_10, 3);
			ZEPHIR_INIT_NVAR(_13);
			ZEPHIR_INIT_NVAR(_14);
			ZVAL_STRING(_14, "obj", 1);
			zephir_call_method_p1(_13, this_ptr, "getstyle", _14);
			zephir_array_update_string(&_10, SL(":style"), &_13, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_13);
			zephir_call_func_p1(_13, "get_parent_class", variable);
			zephir_array_update_string(&_10, SL(":parent"), &_13, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_STRING(&_4, " <b style=':style'>extends</b> :parent", 0);
			ZEPHIR_INIT_NVAR(_13);
			zephir_call_func_p2(_13, "strtr", &_4, _10);
			zephir_concat_self(&output, _13 TSRMLS_CC);
		}
		zephir_concat_self_str(&output, SL(" (\n") TSRMLS_CC);
		do {
			Z_SET_ISREF_P(variable);
			ZEPHIR_INIT_NVAR(attr);
			zephir_call_func_p1(attr, "each", variable);
			Z_UNSET_ISREF_P(variable);
			if (!(zephir_is_true(attr))) {
				continue;
			}
			ZEPHIR_OBS_NVAR(key);
			zephir_array_fetch_string(&key, attr, SL("key"), PH_NOISY TSRMLS_CC);
			ZEPHIR_OBS_NVAR(value);
			zephir_array_fetch_string(&value, attr, SL("value"), PH_NOISY TSRMLS_CC);
			if (!(zephir_is_true(key))) {
				continue;
			}
			ZEPHIR_INIT_NVAR(_8);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_STRING(&_4, "\x00", 0);
			ZEPHIR_INIT_NVAR(_9);
			zephir_call_func_p1(_9, "ord", &_4);
			ZEPHIR_INIT_NVAR(_10);
			zephir_call_func_p1(_10, "chr", _9);
			zephir_fast_explode(_8, _10, key, LONG_MAX TSRMLS_CC);
			ZEPHIR_CPY_WRT(key, _8);
			ZEPHIR_INIT_NVAR(type);
			ZVAL_STRING(type, "public", 1);
			if (zephir_array_isset_long(key, 1)) {
				ZEPHIR_INIT_NVAR(type);
				ZVAL_STRING(type, "private", 1);
				zephir_array_fetch_long(&_18, key, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
				if (ZEPHIR_IS_STRING(_18, "*")) {
					ZEPHIR_INIT_NVAR(type);
					ZVAL_STRING(type, "protected", 1);
				}
			}
			ZEPHIR_INIT_NVAR(_8);
			zephir_call_func_p2(_8, "str_repeat", space, tab);
			ZEPHIR_INIT_NVAR(_13);
			array_init_size(_13, 4);
			ZEPHIR_INIT_NVAR(_14);
			ZEPHIR_INIT_NVAR(_15);
			ZVAL_STRING(_15, "obj", 1);
			zephir_call_method_p1_cache(_14, this_ptr, "getstyle", &_19, _15);
			zephir_array_update_string(&_13, SL(":style"), &_14, PH_COPY | PH_SEPARATE);
			Z_SET_ISREF_P(key);
			ZEPHIR_INIT_NVAR(_14);
			zephir_call_func_p1(_14, "end", key);
			Z_UNSET_ISREF_P(key);
			zephir_array_update_string(&_13, SL(":key"), &_14, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_13, SL(":type"), &type, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_STRING(&_4, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
			ZEPHIR_INIT_NVAR(_14);
			zephir_call_func_p2(_14, "strtr", &_4, _13);
			ZEPHIR_INIT_LNVAR(_12);
			ZEPHIR_CONCAT_VV(_12, _8, _14);
			zephir_concat_self(&output, _12 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_15);
			ZEPHIR_INIT_NVAR(_20);
			ZVAL_STRING(_20, "", 1);
			ZEPHIR_INIT_NVAR(_21);
			ZVAL_LONG(_21, (zephir_get_numberval(tab) + 1));
			zephir_call_method_p3_cache(_15, this_ptr, "output", &_22, value, _20, _21);
			ZEPHIR_INIT_LNVAR(_17);
			ZEPHIR_CONCAT_VS(_17, _15, "\n");
			zephir_concat_self(&output, _17 TSRMLS_CC);
		} while (zephir_is_true(attr));
		ZEPHIR_INIT_NVAR(attr);
		zephir_call_func_p1(attr, "get_class_methods", variable);
		ZEPHIR_INIT_NVAR(_8);
		zephir_call_func_p2(_8, "str_repeat", space, tab);
		ZEPHIR_INIT_NVAR(_9);
		array_init_size(_9, 4);
		ZEPHIR_INIT_NVAR(_10);
		ZEPHIR_INIT_NVAR(_20);
		ZVAL_STRING(_20, "obj", 1);
		zephir_call_method_p1(_10, this_ptr, "getstyle", _20);
		zephir_array_update_string(&_9, SL(":style"), &_10, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_10);
		zephir_get_class(_10, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_9, SL(":class"), &_10, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_9, SS(":count"), zephir_fast_count_int(attr TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, ":class <b style=':style'>:methods</b>: (<span style=':style'>:count</span>) (\n", 0);
		ZEPHIR_INIT_NVAR(_10);
		zephir_call_func_p2(_10, "strtr", &_4, _9);
		ZEPHIR_INIT_LNVAR(_12);
		ZEPHIR_CONCAT_VV(_12, _8, _10);
		zephir_concat_self(&output, _12 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_20);
		zephir_get_class(_20, variable, 0 TSRMLS_CC);
		_18 = zephir_fetch_nproperty_this(this_ptr, SL("methods"), PH_NOISY_CC);
		if (zephir_fast_in_array(_20, _18 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_21);
			zephir_call_func_p2(_21, "str_repeat", space, tab);
			ZEPHIR_INIT_VAR(_23);
			ZEPHIR_CONCAT_VS(_23, _21, "[already listed]\n");
			zephir_concat_self(&output, _23 TSRMLS_CC);
		} else {
			zephir_is_iterable(attr, &_25, &_24, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_25, (void**) &_26, &_24) == SUCCESS
				; zend_hash_move_forward_ex(_25, &_24)
			) {
				ZEPHIR_GET_HMKEY(key, _25, _24);
				ZEPHIR_GET_HVALUE(value, _26);
				ZEPHIR_INIT_NVAR(_8);
				zephir_get_class(_8, variable, 0 TSRMLS_CC);
				zephir_update_property_array_append(this_ptr, SL("methods"), _8 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(value, "__construct")) {
					ZEPHIR_SINIT_NVAR(_4);
					ZVAL_LONG(&_4, (zephir_get_numberval(tab) + 1));
					ZEPHIR_INIT_NVAR(_8);
					zephir_call_func_p2(_8, "str_repeat", space, &_4);
					ZEPHIR_INIT_NVAR(_9);
					array_init_size(_9, 3);
					ZEPHIR_INIT_NVAR(_10);
					ZEPHIR_INIT_NVAR(_20);
					ZVAL_STRING(_20, "obj", 1);
					zephir_call_method_p1_cache(_10, this_ptr, "getstyle", &_27, _20);
					zephir_array_update_string(&_9, SL(":style"), &_10, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_9, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_4);
					ZVAL_STRING(&_4, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n", 0);
					ZEPHIR_INIT_NVAR(_10);
					zephir_call_func_p2(_10, "strtr", &_4, _9);
					ZEPHIR_INIT_LNVAR(_12);
					ZEPHIR_CONCAT_VV(_12, _8, _10);
					zephir_concat_self(&output, _12 TSRMLS_CC);
				} else {
					ZEPHIR_SINIT_NVAR(_4);
					ZVAL_LONG(&_4, (zephir_get_numberval(tab) + 1));
					ZEPHIR_INIT_NVAR(_20);
					zephir_call_func_p2(_20, "str_repeat", space, &_4);
					ZEPHIR_INIT_NVAR(_21);
					array_init_size(_21, 3);
					ZEPHIR_INIT_NVAR(_28);
					ZEPHIR_INIT_NVAR(_29);
					ZVAL_STRING(_29, "obj", 1);
					zephir_call_method_p1_cache(_28, this_ptr, "getstyle", &_30, _29);
					zephir_array_update_string(&_21, SL(":style"), &_28, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_21, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_4);
					ZVAL_STRING(&_4, "-><span style=':style'>:method</span>();\n", 0);
					ZEPHIR_INIT_NVAR(_28);
					zephir_call_func_p2(_28, "strtr", &_4, _21);
					ZEPHIR_INIT_LNVAR(_23);
					ZEPHIR_CONCAT_VV(_23, _20, _28);
					zephir_concat_self(&output, _23 TSRMLS_CC);
				}
			}
			ZEPHIR_INIT_NVAR(_13);
			zephir_call_func_p2(_13, "str_repeat", space, tab);
			ZEPHIR_INIT_LNVAR(_17);
			ZEPHIR_CONCAT_VS(_17, _13, ")\n");
			zephir_concat_self(&output, _17 TSRMLS_CC);
		}
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, (zephir_get_numberval(tab) - 1));
		ZEPHIR_INIT_NVAR(_8);
		zephir_call_func_p2(_8, "str_repeat", space, &_4);
		ZEPHIR_CONCAT_VVS(return_value, output, _8, ")");
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_1);
	zephir_call_func_p1(_1, "is_resource", variable);
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(_2);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "res", 1);
		zephir_call_method_p1(_2, this_ptr, "getstyle", _3);
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_func_p1(_3, "get_resource_type", variable);
		ZEPHIR_INIT_NVAR(_9);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "res", 1);
		zephir_call_method_p1(_9, this_ptr, "getstyle", _10);
		ZEPHIR_CONCAT_SVSVSVSVS(return_value, "<b style='", _2, "'>Resource</b> [", _3, "] ( <span style='", _9, "'>", variable, "</span> )");
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_1);
	zephir_call_func_p1(_1, "is_int", variable);
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(_2);
		array_init_size(_2, 3);
		ZEPHIR_INIT_NVAR(_3);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "int", 1);
		zephir_call_method_p1(_3, this_ptr, "getstyle", _10);
		zephir_array_update_string(&_2, SL(":style"), &_3, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_2, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>Intiger</b> (<span style=':style'>:var</span>)", 0);
		zephir_call_func_p2(return_value, "strtr", &_4, _2);
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_1);
	zephir_call_func_p1(_1, "is_float", variable);
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(_2);
		array_init_size(_2, 3);
		ZEPHIR_INIT_NVAR(_3);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "float", 1);
		zephir_call_method_p1(_3, this_ptr, "getstyle", _10);
		zephir_array_update_string(&_2, SL(":style"), &_3, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_2, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>Float</b> (<span style=':style'>:var</span>)", 0);
		zephir_call_func_p2(return_value, "strtr", &_4, _2);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_NVAR(_1);
		array_init_size(_1, 4);
		ZEPHIR_INIT_NVAR(_2);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "num", 1);
		zephir_call_method_p1(_2, this_ptr, "getstyle", _3);
		zephir_array_update_string(&_1, SL(":style"), &_2, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_1, SS(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_1, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>Numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		zephir_call_func_p2(return_value, "strtr", &_4, _1);
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_1);
	zephir_call_func_p1(_1, "is_string", variable);
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(_2);
		array_init_size(_2, 4);
		ZEPHIR_INIT_NVAR(_3);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "str", 1);
		zephir_call_method_p1(_3, this_ptr, "getstyle", _10);
		zephir_array_update_string(&_2, SL(":style"), &_3, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_2, SS(":length"), zephir_fast_strlen_ev(variable));
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 4);
		ZEPHIR_SINIT_VAR(_31);
		ZVAL_STRING(&_31, "utf-8", 0);
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_func_p3(_3, "htmlentities", variable, &_4, &_31);
		ZEPHIR_INIT_NVAR(_10);
		zephir_call_func_p1(_10, "nl2br", _3);
		zephir_array_update_string(&_2, SL(":var"), &_10, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>String</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		zephir_call_func_p2(return_value, "strtr", &_4, _2);
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_1);
	zephir_call_func_p1(_1, "is_bool", variable);
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(type);
		ZVAL_STRING(type, "FALSE", 1);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(type);
			ZVAL_STRING(type, "TRUE", 1);
		}
		ZEPHIR_INIT_NVAR(_2);
		array_init_size(_2, 3);
		ZEPHIR_INIT_NVAR(_3);
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_STRING(_8, "bool", 1);
		zephir_call_method_p1(_3, this_ptr, "getstyle", _8);
		zephir_array_update_string(&_2, SL(":style"), &_3, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_2, SL(":var"), &type, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>Boolean</b> (<span style=':style'>:var</span>)", 0);
		zephir_call_func_p2(return_value, "strtr", &_4, _2);
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_1);
	zephir_call_func_p1(_1, "is_null", variable);
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(_2);
		array_init_size(_2, 2);
		ZEPHIR_INIT_NVAR(_3);
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_STRING(_8, "null", 1);
		zephir_call_method_p1(_3, this_ptr, "getstyle", _8);
		zephir_array_update_string(&_2, SL(":style"), &_3, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>NULL</b>", 0);
		zephir_call_func_p2(return_value, "strtr", &_4, _2);
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_1);
	array_init_size(_1, 3);
	ZEPHIR_INIT_NVAR(_2);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "other", 1);
	zephir_call_method_p1(_2, this_ptr, "getstyle", _3);
	zephir_array_update_string(&_1, SL(":style"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_STRING(&_4, "(<span style=':style'>:var</span>)", 0);
	zephir_call_func_p2(return_value, "strtr", &_4, _1);
	RETURN_MM();

}

PHP_METHOD(Phalcon_Debug_Dump, setStyles) {

	zval *styles = NULL, *defaultStyles, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &styles);

	ZEPHIR_SEPARATE_PARAM(styles);


	if ((Z_TYPE_P(styles) == IS_NULL)) {
		ZEPHIR_INIT_NVAR(styles);
		array_init(styles);
	}
	if ((Z_TYPE_P(styles) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_debug_exception_ce, "Styles must be an array");
		return;
	}
	ZEPHIR_INIT_VAR(defaultStyles);
	array_init_size(defaultStyles, 12);
	add_assoc_stringl_ex(defaultStyles, SS("pre"), SL("background-color:#f3f3f3;font-size:11px;padding:10px; border:1px solid #ccc; text-align:left; color:#333"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("arr"), SL("color:red"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("bool"), SL("color:green"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("float"), SL("color:fuchsia"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("int"), SL("color:blue"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("null"), SL("color:black"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("num"), SL("color:navy"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("obj"), SL("color:purple"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("other"), SL("color:maroon"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("res"), SL("color:lime"), 1);
	add_assoc_stringl_ex(defaultStyles, SS("str"), SL("color:teal"), 1);
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_array_merge(_0, &(defaultStyles), &(styles) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_styles"), _0 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "_styles");

}

/**
 * Get style for type
 *
 * @param string type
 * @return string
 */
PHP_METHOD(Phalcon_Debug_Dump, getStyle) {

	zval *type_param = NULL, *_0, *_1;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(type_param) == IS_STRING) {
		type = type_param;
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_styles"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, type, PH_NOISY | PH_READONLY TSRMLS_CC);
	RETURN_CTOR(_1);

}

