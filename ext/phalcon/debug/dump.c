
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

	zend_bool _14, _15, _17;
	zend_function *_7 = NULL, *_11 = NULL, *_12 = NULL, *_16 = NULL, *_21 = NULL, *_23 = NULL, *_24 = NULL, *_26 = NULL, *_28 = NULL, *_34 = NULL, *_38 = NULL;
	HashTable *_5, *_32;
	HashPosition _4, _31;
	zval *_0 = NULL, *_8 = NULL, *_35 = NULL;
	zval *variable, *name = NULL, *tab = NULL, *key = NULL, *value = NULL, *output, *space, *type = NULL, *attr = NULL, *_1 = NULL, *_2 = NULL, _3 = zval_used_for_init, **_6, *_9 = NULL, *_10 = NULL, *_13 = NULL, *_18 = NULL, *_19 = NULL, *_20 = NULL, *_22 = NULL, *_25, *_27 = NULL, *_29, *_30 = NULL, **_33, *_36 = NULL, *_37 = NULL, _39;

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
	if ((Z_TYPE_P(variable) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		array_init_size(_0, 3);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "arr", 1);
		zephir_call_method_p1(_1, this_ptr, "getstyle", _2);
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_0, SS(":count"), zephir_fast_count_int(variable TSRMLS_CC));
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "<b style =':style'>Array</b> (<span style =':style'>:count</span>) (\n", 0);
		ZEPHIR_INIT_NVAR(_1);
		zephir_call_func_p2(_1, "strtr", &_3, _0);
		zephir_concat_self(&output, _1 TSRMLS_CC);
		zephir_is_iterable(variable, &_5, &_4, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
			; zend_hash_move_forward_ex(_5, &_4)
		) {
			ZEPHIR_GET_HMKEY(key, _5, _4);
			ZEPHIR_GET_HVALUE(value, _6);
			ZEPHIR_INIT_NVAR(_2);
			ZEPHIR_CALL_INTERNAL_FUNCTION(_2, &_2, "str_repeat", &_7, 2, space, tab);
			ZEPHIR_INIT_NVAR(_8);
			array_init_size(_8, 3);
			ZEPHIR_INIT_NVAR(_9);
			ZEPHIR_INIT_NVAR(_10);
			ZVAL_STRING(_10, "arr", 1);
			zephir_call_method_p1_cache(_9, this_ptr, "getstyle", &_11, _10);
			zephir_array_update_string(&_8, SL(":style"), &_9, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_8, SL(":key"), &key, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_STRING(&_3, "[<span style=':style'>:key</span>] => ", 0);
			ZEPHIR_INIT_NVAR(_9);
			ZEPHIR_CALL_INTERNAL_FUNCTION(_9, &_9, "strtr", &_12, 2, &_3, _8);
			ZEPHIR_INIT_LNVAR(_13);
			ZEPHIR_CONCAT_VV(_13, _2, _9);
			zephir_concat_self(&output, _13 TSRMLS_CC);
			_14 = ZEPHIR_IS_LONG(tab, 0);
			if (_14) {
				_14 = !ZEPHIR_IS_STRING(name, "");
			}
			_15 = _14;
			if (_15) {
				ZEPHIR_INIT_NVAR(_10);
				ZEPHIR_CALL_INTERNAL_FUNCTION(_10, &_10, "is_int", &_16, 1, key);
				_17 = zephir_is_true(_10);
				if (_17) {
					_17 = ZEPHIR_IS_EQUAL(name, key);
				}
				_15 = !_17;
			}
			if (_15) {
				continue;
			} else {
				ZEPHIR_INIT_NVAR(_18);
				ZEPHIR_INIT_NVAR(_19);
				ZVAL_STRING(_19, "", 1);
				ZEPHIR_INIT_NVAR(_20);
				ZVAL_LONG(_20, (zephir_get_numberval(tab) + 1));
				zephir_call_method_p3_cache(_18, this_ptr, "output", &_21, value, _19, _20);
				ZEPHIR_INIT_LNVAR(_22);
				ZEPHIR_CONCAT_VS(_22, _18, "\n");
				zephir_concat_self(&output, _22 TSRMLS_CC);
			}
		}
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, (zephir_get_numberval(tab) - 1));
		ZEPHIR_INIT_NVAR(_9);
		zephir_call_func_p2(_9, "str_repeat", space, &_3);
		ZEPHIR_CONCAT_VVS(return_value, output, _9, ")");
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_1);
	zephir_call_func_p1(_1, "is_object", variable);
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 3);
		ZEPHIR_INIT_NVAR(_2);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "obj", 1);
		zephir_call_method_p1(_2, this_ptr, "getstyle", _10);
		zephir_array_update_string(&_0, SL(":style"), &_2, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_2);
		zephir_get_class(_2, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_0, SL(":class"), &_2, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>Object</b> :class", 0);
		ZEPHIR_INIT_NVAR(_2);
		zephir_call_func_p2(_2, "strtr", &_3, _0);
		zephir_concat_self(&output, _2 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_10);
		zephir_call_func_p1(_10, "get_parent_class", variable);
		if (zephir_is_true(_10)) {
			ZEPHIR_INIT_NVAR(_8);
			array_init_size(_8, 3);
			ZEPHIR_INIT_NVAR(_18);
			ZEPHIR_INIT_NVAR(_19);
			ZVAL_STRING(_19, "obj", 1);
			zephir_call_method_p1(_18, this_ptr, "getstyle", _19);
			zephir_array_update_string(&_8, SL(":style"), &_18, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_18);
			zephir_call_func_p1(_18, "get_parent_class", variable);
			zephir_array_update_string(&_8, SL(":parent"), &_18, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_STRING(&_3, " <b style=':style'>extends</b> :parent", 0);
			ZEPHIR_INIT_NVAR(_18);
			zephir_call_func_p2(_18, "strtr", &_3, _8);
			zephir_concat_self(&output, _18 TSRMLS_CC);
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
			ZEPHIR_INIT_NVAR(_9);
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_STRING(&_3, "\x00", 0);
			ZEPHIR_INIT_NVAR(_10);
			ZEPHIR_CALL_INTERNAL_FUNCTION(_10, &_10, "ord", &_23, 1, &_3);
			ZEPHIR_INIT_NVAR(_18);
			ZEPHIR_CALL_INTERNAL_FUNCTION(_18, &_18, "chr", &_24, 1, _10);
			zephir_fast_explode(_9, _18, key, LONG_MAX TSRMLS_CC);
			ZEPHIR_CPY_WRT(key, _9);
			ZEPHIR_INIT_NVAR(type);
			ZVAL_STRING(type, "public", 1);
			if (zephir_array_isset_long(key, 1)) {
				ZEPHIR_INIT_NVAR(type);
				ZVAL_STRING(type, "private", 1);
				zephir_array_fetch_long(&_25, key, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
				if (ZEPHIR_IS_STRING(_25, "*")) {
					ZEPHIR_INIT_NVAR(type);
					ZVAL_STRING(type, "protected", 1);
				}
			}
			ZEPHIR_INIT_NVAR(_9);
			ZEPHIR_CALL_INTERNAL_FUNCTION(_9, &_9, "str_repeat", &_7, 2, space, tab);
			ZEPHIR_INIT_NVAR(_8);
			array_init_size(_8, 5);
			ZEPHIR_INIT_NVAR(_18);
			ZEPHIR_INIT_NVAR(_19);
			ZVAL_STRING(_19, "obj", 1);
			zephir_call_method_p1_cache(_18, this_ptr, "getstyle", &_26, _19);
			zephir_array_update_string(&_8, SL(":style"), &_18, PH_COPY | PH_SEPARATE);
			Z_SET_ISREF_P(key);
			ZEPHIR_INIT_NVAR(_18);
			zephir_call_func_p1(_18, "end", key);
			Z_UNSET_ISREF_P(key);
			zephir_array_update_string(&_8, SL(":key"), &_18, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_8, SL(":type"), &type, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_STRING(&_3, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
			ZEPHIR_INIT_NVAR(_18);
			ZEPHIR_CALL_INTERNAL_FUNCTION(_18, &_18, "strtr", &_12, 2, &_3, _8);
			ZEPHIR_INIT_LNVAR(_13);
			ZEPHIR_CONCAT_VV(_13, _9, _18);
			zephir_concat_self(&output, _13 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_19);
			ZEPHIR_INIT_NVAR(_20);
			ZVAL_STRING(_20, "", 1);
			ZEPHIR_INIT_NVAR(_27);
			ZVAL_LONG(_27, (zephir_get_numberval(tab) + 1));
			zephir_call_method_p3_cache(_19, this_ptr, "output", &_28, value, _20, _27);
			ZEPHIR_INIT_LNVAR(_22);
			ZEPHIR_CONCAT_VS(_22, _19, "\n");
			zephir_concat_self(&output, _22 TSRMLS_CC);
		} while (zephir_is_true(attr));
		ZEPHIR_INIT_NVAR(attr);
		zephir_call_func_p1(attr, "get_class_methods", variable);
		ZEPHIR_INIT_NVAR(_9);
		zephir_call_func_p2(_9, "str_repeat", space, tab);
		ZEPHIR_INIT_NVAR(_8);
		array_init_size(_8, 5);
		ZEPHIR_INIT_NVAR(_10);
		ZEPHIR_INIT_NVAR(_20);
		ZVAL_STRING(_20, "obj", 1);
		zephir_call_method_p1(_10, this_ptr, "getstyle", _20);
		zephir_array_update_string(&_8, SL(":style"), &_10, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_10);
		zephir_get_class(_10, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_8, SL(":class"), &_10, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_8, SS(":count"), zephir_fast_count_int(attr TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, ":class <b style=':style'>:methods</b>: (<span style=':style'>:count</span>) (\n", 0);
		ZEPHIR_INIT_NVAR(_10);
		zephir_call_func_p2(_10, "strtr", &_3, _8);
		ZEPHIR_INIT_LNVAR(_13);
		ZEPHIR_CONCAT_VV(_13, _9, _10);
		zephir_concat_self(&output, _13 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_20);
		zephir_get_class(_20, variable, 0 TSRMLS_CC);
		_29 = zephir_fetch_nproperty_this(this_ptr, SL("methods"), PH_NOISY_CC);
		if (zephir_fast_in_array(_20, _29 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_27);
			zephir_call_func_p2(_27, "str_repeat", space, tab);
			ZEPHIR_INIT_VAR(_30);
			ZEPHIR_CONCAT_VS(_30, _27, "[already listed]\n");
			zephir_concat_self(&output, _30 TSRMLS_CC);
		} else {
			zephir_is_iterable(attr, &_32, &_31, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_32, (void**) &_33, &_31) == SUCCESS
				; zend_hash_move_forward_ex(_32, &_31)
			) {
				ZEPHIR_GET_HMKEY(key, _32, _31);
				ZEPHIR_GET_HVALUE(value, _33);
				ZEPHIR_INIT_NVAR(_9);
				zephir_get_class(_9, variable, 0 TSRMLS_CC);
				zephir_update_property_array_append(this_ptr, SL("methods"), _9 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(value, "__construct")) {
					ZEPHIR_SINIT_NVAR(_3);
					ZVAL_LONG(&_3, (zephir_get_numberval(tab) + 1));
					ZEPHIR_INIT_NVAR(_9);
					ZEPHIR_CALL_INTERNAL_FUNCTION(_9, &_9, "str_repeat", &_7, 2, space, &_3);
					ZEPHIR_INIT_NVAR(_8);
					array_init_size(_8, 3);
					ZEPHIR_INIT_NVAR(_10);
					ZEPHIR_INIT_NVAR(_27);
					ZVAL_STRING(_27, "obj", 1);
					zephir_call_method_p1_cache(_10, this_ptr, "getstyle", &_34, _27);
					zephir_array_update_string(&_8, SL(":style"), &_10, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_8, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_3);
					ZVAL_STRING(&_3, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n", 0);
					ZEPHIR_INIT_NVAR(_10);
					ZEPHIR_CALL_INTERNAL_FUNCTION(_10, &_10, "strtr", &_12, 2, &_3, _8);
					ZEPHIR_INIT_LNVAR(_13);
					ZEPHIR_CONCAT_VV(_13, _9, _10);
					zephir_concat_self(&output, _13 TSRMLS_CC);
				} else {
					ZEPHIR_SINIT_NVAR(_3);
					ZVAL_LONG(&_3, (zephir_get_numberval(tab) + 1));
					ZEPHIR_INIT_NVAR(_27);
					ZEPHIR_CALL_INTERNAL_FUNCTION(_27, &_27, "str_repeat", &_7, 2, space, &_3);
					ZEPHIR_INIT_NVAR(_35);
					array_init_size(_35, 3);
					ZEPHIR_INIT_NVAR(_36);
					ZEPHIR_INIT_NVAR(_37);
					ZVAL_STRING(_37, "obj", 1);
					zephir_call_method_p1_cache(_36, this_ptr, "getstyle", &_38, _37);
					zephir_array_update_string(&_35, SL(":style"), &_36, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_35, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_3);
					ZVAL_STRING(&_3, "-><span style=':style'>:method</span>();\n", 0);
					ZEPHIR_INIT_NVAR(_36);
					ZEPHIR_CALL_INTERNAL_FUNCTION(_36, &_36, "strtr", &_12, 2, &_3, _35);
					ZEPHIR_INIT_LNVAR(_30);
					ZEPHIR_CONCAT_VV(_30, _27, _36);
					zephir_concat_self(&output, _30 TSRMLS_CC);
				}
			}
			ZEPHIR_INIT_NVAR(_18);
			zephir_call_func_p2(_18, "str_repeat", space, tab);
			ZEPHIR_INIT_LNVAR(_22);
			ZEPHIR_CONCAT_VS(_22, _18, ")\n");
			zephir_concat_self(&output, _22 TSRMLS_CC);
		}
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, (zephir_get_numberval(tab) - 1));
		ZEPHIR_INIT_NVAR(_9);
		zephir_call_func_p2(_9, "str_repeat", space, &_3);
		ZEPHIR_CONCAT_VVS(return_value, output, _9, ")");
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_1);
	zephir_call_func_p1(_1, "is_resource", variable);
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(_2);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "res", 1);
		zephir_call_method_p1(_2, this_ptr, "getstyle", _10);
		ZEPHIR_INIT_NVAR(_10);
		zephir_call_func_p1(_10, "get_resource_type", variable);
		ZEPHIR_INIT_NVAR(_19);
		ZEPHIR_INIT_NVAR(_20);
		ZVAL_STRING(_20, "res", 1);
		zephir_call_method_p1(_19, this_ptr, "getstyle", _20);
		ZEPHIR_CONCAT_SVSVSVSVS(return_value, "<b style='", _2, "'>Resource</b> [", _10, "] ( <span style='", _19, "'>", variable, "</span> )");
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_1);
	zephir_call_func_p1(_1, "is_int", variable);
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 3);
		ZEPHIR_INIT_NVAR(_2);
		ZEPHIR_INIT_NVAR(_20);
		ZVAL_STRING(_20, "int", 1);
		zephir_call_method_p1(_2, this_ptr, "getstyle", _20);
		zephir_array_update_string(&_0, SL(":style"), &_2, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>Intiger</b> (<span style=':style'>:var</span>)", 0);
		zephir_call_func_p2(return_value, "strtr", &_3, _0);
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_1);
	zephir_call_func_p1(_1, "is_float", variable);
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 3);
		ZEPHIR_INIT_NVAR(_2);
		ZEPHIR_INIT_NVAR(_20);
		ZVAL_STRING(_20, "float", 1);
		zephir_call_method_p1(_2, this_ptr, "getstyle", _20);
		zephir_array_update_string(&_0, SL(":style"), &_2, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>Float</b> (<span style=':style'>:var</span>)", 0);
		zephir_call_func_p2(return_value, "strtr", &_3, _0);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 5);
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "num", 1);
		zephir_call_method_p1(_1, this_ptr, "getstyle", _2);
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_0, SS(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>Numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		zephir_call_func_p2(return_value, "strtr", &_3, _0);
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_STRING)) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 5);
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "str", 1);
		zephir_call_method_p1(_1, this_ptr, "getstyle", _2);
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_0, SS(":length"), zephir_fast_strlen_ev(variable));
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, 4);
		ZEPHIR_SINIT_VAR(_39);
		ZVAL_STRING(&_39, "utf-8", 0);
		ZEPHIR_INIT_NVAR(_1);
		zephir_call_func_p3(_1, "htmlentities", variable, &_3, &_39);
		ZEPHIR_INIT_NVAR(_2);
		zephir_call_func_p1(_2, "nl2br", _1);
		zephir_array_update_string(&_0, SL(":var"), &_2, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>String</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		zephir_call_func_p2(return_value, "strtr", &_3, _0);
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_BOOL)) {
		ZEPHIR_INIT_NVAR(type);
		ZVAL_STRING(type, "FALSE", 1);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(type);
			ZVAL_STRING(type, "TRUE", 1);
		}
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 3);
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "bool", 1);
		zephir_call_method_p1(_1, this_ptr, "getstyle", _2);
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0, SL(":var"), &type, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>Boolean</b> (<span style=':style'>:var</span>)", 0);
		zephir_call_func_p2(return_value, "strtr", &_3, _0);
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_NULL)) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 2);
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "null", 1);
		zephir_call_method_p1(_1, this_ptr, "getstyle", _2);
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>NULL</b>", 0);
		zephir_call_func_p2(return_value, "strtr", &_3, _0);
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_0);
	array_init_size(_0, 3);
	ZEPHIR_INIT_NVAR(_1);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "other", 1);
	zephir_call_method_p1(_1, this_ptr, "getstyle", _2);
	zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_STRING(&_3, "(<span style=':style'>:var</span>)", 0);
	zephir_call_func_p2(return_value, "strtr", &_3, _0);
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
	array_init_size(defaultStyles, 17);
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

