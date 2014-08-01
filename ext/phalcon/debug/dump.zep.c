
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
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/string.h"


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

	zend_declare_property_bool(phalcon_debug_dump_ce, SL("detailed"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(phalcon_debug_dump_ce, SL("methods"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_debug_dump_ce, SL("styles"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Debug\Dump constructor
 *
 * @param array styles
 * @param boolean detailed
 */
PHP_METHOD(Phalcon_Debug_Dump, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *styles = NULL, *detailed = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &styles, &detailed);

	if (!styles) {
		styles = ZEPHIR_GLOBAL(global_null);
	}
	if (!detailed) {
		detailed = ZEPHIR_GLOBAL(global_false);
	}


	if (Z_TYPE_P(styles) != IS_ARRAY) {
		if (Z_TYPE_P(styles) != IS_NULL) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_debug_exception_ce, "The styles must be an array", "phalcon/debug/dump.zep", 46);
			return;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstyles", NULL, styles);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("methods"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Alias of vars() method
 *
 * @param mixed variable
 * @param ...
 * @return string
 */
PHP_METHOD(Phalcon_Debug_Dump, all) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *_1, *_2 = NULL;
	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "variables", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(&_2, "func_get_args", &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _0, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get style for type
 *
 * @param string type
 * @return string
 */
PHP_METHOD(Phalcon_Debug_Dump, getStyle) {

	zval *type_param = NULL, *style, *styles = NULL, *_0;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(type_param) == IS_STRING)) {
		type = type_param;
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("styles"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(styles, _0);
	if (zephir_array_isset_fetch(&style, styles, type, 1 TSRMLS_CC)) {
		RETURN_CTOR(style);
	} else {
		RETURN_MM_STRING("color:gray", 1);
	}

}

/**
 * Set styles for vars type
 *
 * @param array styles
 * @return array
 */
PHP_METHOD(Phalcon_Debug_Dump, setStyles) {

	zval *styles = NULL, *defaultStyles, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &styles);

	ZEPHIR_SEPARATE_PARAM(styles);


	if (Z_TYPE_P(styles) == IS_NULL) {
		ZEPHIR_INIT_NVAR(styles);
		array_init(styles);
	}
	if (Z_TYPE_P(styles) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_debug_exception_ce, "Styles must be an array", "phalcon/debug/dump.zep", 98);
		return;
	}
	ZEPHIR_INIT_VAR(defaultStyles);
	array_init_size(defaultStyles, 17);
	add_assoc_stringl_ex(defaultStyles, SS("pre"), SL("background-color:#f3f3f3; font-size:11px; padding:10px; border:1px solid #ccc; text-align:left; color:#333"), 1);
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
	zephir_update_property_this(this_ptr, SL("styles"), _0 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "styles");

}

/**
 * Alias of var() method
 *
 * @param mixed variable
 * @param string name
 * @return string
 */
PHP_METHOD(Phalcon_Debug_Dump, one) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *variable, *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &variable, &name);

	if (!name) {
		name = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "var", NULL, variable, name);
	zephir_check_call_status();
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

	zend_bool _13, _14, _17;
	HashTable *_6, *_25, *_36;
	HashPosition _5, _24, _35;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_9 = NULL, *_16 = NULL, *_21 = NULL, *_23 = NULL, *_27 = NULL, *_28 = NULL, *_29 = NULL, *_31 = NULL, *_33 = NULL, *_40 = NULL, *_42 = NULL, *_43 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_10 = NULL, *_38 = NULL;
	zval *variable, *name = NULL, *tab = NULL, *key = NULL, *value = NULL, *output, *space, *type = NULL, *attr = NULL, *_1 = NULL, *_2 = NULL, _3 = zval_used_for_init, **_7, *_8 = NULL, *_11 = NULL, *_12 = NULL, *_15 = NULL, *_18 = NULL, *_19 = NULL, *_20 = NULL, *_22, **_26, *_30, *_32 = NULL, *_34, **_37, *_39 = NULL, _41;

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
	if (zephir_is_true(name)) {
		ZEPHIR_INIT_BNVAR(output);
		ZEPHIR_CONCAT_VS(output, name, " ");
	}
	if (Z_TYPE_P(variable) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		array_init_size(_0, 3);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "arr", 0);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_0, SS(":count"), zephir_fast_count_int(variable TSRMLS_CC));
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "<b style =':style'>Array</b> (<span style =':style'>:count</span>) (\n", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "strtr", &_4, &_3, _0);
		zephir_check_call_status();
		zephir_concat_self(&output, _1 TSRMLS_CC);
		zephir_is_iterable(variable, &_6, &_5, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6, &_5)
		) {
			ZEPHIR_GET_HMKEY(key, _6, _5);
			ZEPHIR_GET_HVALUE(value, _7);
			ZEPHIR_CALL_FUNCTION(&_8, "str_repeat", &_9, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_10);
			array_init_size(_10, 3);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "arr", 0);
			ZEPHIR_CALL_METHOD(&_11, this_ptr, "getstyle", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			zephir_array_update_string(&_10, SL(":style"), &_11, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_10, SL(":key"), &key, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_STRING(&_3, "[<span style=':style'>:key</span>] => ", 0);
			ZEPHIR_CALL_FUNCTION(&_11, "strtr", &_4, &_3, _10);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_12);
			ZEPHIR_CONCAT_VV(_12, _8, _11);
			zephir_concat_self(&output, _12 TSRMLS_CC);
			_13 = ZEPHIR_IS_LONG(tab, 1);
			if (_13) {
				_13 = !ZEPHIR_IS_STRING(name, "");
			}
			_14 = _13;
			if (_14) {
				ZEPHIR_CALL_FUNCTION(&_15, "is_int", &_16, key);
				zephir_check_call_status();
				_14 = !zephir_is_true(_15);
			}
			_17 = _14;
			if (_17) {
				_17 = ZEPHIR_IS_EQUAL(name, key);
			}
			if (_17) {
				continue;
			} else {
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "", 0);
				ZEPHIR_INIT_NVAR(_19);
				ZVAL_LONG(_19, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_18, this_ptr, "output", NULL, value, _2, _19);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_20);
				ZEPHIR_CONCAT_VS(_20, _18, "\n");
				zephir_concat_self(&output, _20 TSRMLS_CC);
			}
		}
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_8, "str_repeat", &_9, space, &_3);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _8, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 3);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "obj", 0);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_2);
		zephir_get_class(_2, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_0, SL(":class"), &_2, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>Object</b> :class", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "strtr", &_4, &_3, _0);
		zephir_check_call_status();
		zephir_concat_self(&output, _1 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "get_parent_class", &_21, variable);
		zephir_check_call_status();
		if (zephir_is_true(_11)) {
			ZEPHIR_INIT_NVAR(_10);
			array_init_size(_10, 3);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "obj", 0);
			ZEPHIR_CALL_METHOD(&_15, this_ptr, "getstyle", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			zephir_array_update_string(&_10, SL(":style"), &_15, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_15, "get_parent_class", &_21, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_10, SL(":parent"), &_15, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_STRING(&_3, " <b style=':style'>extends</b> :parent", 0);
			ZEPHIR_CALL_FUNCTION(&_15, "strtr", &_4, &_3, _10);
			zephir_check_call_status();
			zephir_concat_self(&output, _15 TSRMLS_CC);
		}
		zephir_concat_self_str(&output, SL(" (\n") TSRMLS_CC);
		_22 = zephir_fetch_nproperty_this(this_ptr, SL("detailed"), PH_NOISY_CC);
		if (!(zephir_is_true(_22))) {
			ZEPHIR_CALL_FUNCTION(&_8, "get_object_vars", &_23, variable);
			zephir_check_call_status();
			zephir_is_iterable(_8, &_25, &_24, 0, 0);
			for (
			  ; zephir_hash_get_current_data_ex(_25, (void**) &_26, &_24) == SUCCESS
			  ; zephir_hash_move_forward_ex(_25, &_24)
			) {
				ZEPHIR_GET_HMKEY(key, _25, _24);
				ZEPHIR_GET_HVALUE(value, _26);
				ZEPHIR_CALL_FUNCTION(&_11, "str_repeat", &_9, space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_10);
				array_init_size(_10, 5);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "obj", 0);
				ZEPHIR_CALL_METHOD(&_15, this_ptr, "getstyle", NULL, _2);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				zephir_array_update_string(&_10, SL(":style"), &_15, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_10, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(_10, SS(":type"), SL("public"), 1);
				ZEPHIR_SINIT_NVAR(_3);
				ZVAL_STRING(&_3, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_15, "strtr", &_4, &_3, _10);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_12);
				ZEPHIR_CONCAT_VV(_12, _11, _15);
				zephir_concat_self(&output, _12 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "", 0);
				ZEPHIR_INIT_NVAR(_19);
				ZVAL_LONG(_19, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_18, this_ptr, "output", NULL, value, _2, _19);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_20);
				ZEPHIR_CONCAT_VS(_20, _18, "\n");
				zephir_concat_self(&output, _20 TSRMLS_CC);
			}
		} else {
			do {
				Z_SET_ISREF_P(variable);
				ZEPHIR_CALL_FUNCTION(&attr, "each", &_27, variable);
				Z_UNSET_ISREF_P(variable);
				zephir_check_call_status();
				if (!(zephir_is_true(attr))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(key);
				zephir_array_fetch_string(&key, attr, SL("key"), PH_NOISY, "phalcon/debug/dump.zep", 184 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(value);
				zephir_array_fetch_string(&value, attr, SL("value"), PH_NOISY, "phalcon/debug/dump.zep", 185 TSRMLS_CC);
				if (!(zephir_is_true(key))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(_2);
				ZEPHIR_SINIT_NVAR(_3);
				ZVAL_STRING(&_3, "\x00", 0);
				ZEPHIR_CALL_FUNCTION(&_8, "ord", &_28, &_3);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_11, "chr", &_29, _8);
				zephir_check_call_status();
				zephir_fast_explode(_2, _11, key, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(key, _2);
				ZEPHIR_INIT_NVAR(type);
				ZVAL_STRING(type, "public", 1);
				if (zephir_array_isset_long(key, 1)) {
					ZEPHIR_INIT_NVAR(type);
					ZVAL_STRING(type, "private", 1);
					zephir_array_fetch_long(&_30, key, 1, PH_NOISY | PH_READONLY, "phalcon/debug/dump.zep", 196 TSRMLS_CC);
					if (ZEPHIR_IS_STRING(_30, "*")) {
						ZEPHIR_INIT_NVAR(type);
						ZVAL_STRING(type, "protected", 1);
					}
				}
				ZEPHIR_CALL_FUNCTION(&_15, "str_repeat", &_9, space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_10);
				array_init_size(_10, 5);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "obj", 0);
				ZEPHIR_CALL_METHOD(&_18, this_ptr, "getstyle", NULL, _2);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				zephir_array_update_string(&_10, SL(":style"), &_18, PH_COPY | PH_SEPARATE);
				Z_SET_ISREF_P(key);
				ZEPHIR_CALL_FUNCTION(&_18, "end", &_31, key);
				Z_UNSET_ISREF_P(key);
				zephir_check_call_status();
				zephir_array_update_string(&_10, SL(":key"), &_18, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_10, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_SINIT_NVAR(_3);
				ZVAL_STRING(&_3, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_18, "strtr", &_4, &_3, _10);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_12);
				ZEPHIR_CONCAT_VV(_12, _15, _18);
				zephir_concat_self(&output, _12 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "", 0);
				ZEPHIR_INIT_NVAR(_19);
				ZVAL_LONG(_19, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_32, this_ptr, "output", NULL, value, _2, _19);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_20);
				ZEPHIR_CONCAT_VS(_20, _32, "\n");
				zephir_concat_self(&output, _20 TSRMLS_CC);
			} while (zephir_is_true(attr));
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", &_33, variable);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_8, "str_repeat", &_9, space, tab);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_10);
		array_init_size(_10, 5);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "obj", 0);
		ZEPHIR_CALL_METHOD(&_11, this_ptr, "getstyle", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_10, SL(":style"), &_11, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_2);
		zephir_get_class(_2, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_10, SL(":class"), &_2, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_10, SS(":count"), zephir_fast_count_int(attr TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n", 0);
		ZEPHIR_CALL_FUNCTION(&_11, "strtr", &_4, &_3, _10);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_12);
		ZEPHIR_CONCAT_VV(_12, _8, _11);
		zephir_concat_self(&output, _12 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_2);
		zephir_get_class(_2, variable, 0 TSRMLS_CC);
		_34 = zephir_fetch_nproperty_this(this_ptr, SL("methods"), PH_NOISY_CC);
		if (zephir_fast_in_array(_2, _34 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_15, "str_repeat", &_9, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_20);
			ZEPHIR_CONCAT_VS(_20, _15, "[already listed]\n");
			zephir_concat_self(&output, _20 TSRMLS_CC);
		} else {
			zephir_is_iterable(attr, &_36, &_35, 0, 0);
			for (
			  ; zephir_hash_get_current_data_ex(_36, (void**) &_37, &_35) == SUCCESS
			  ; zephir_hash_move_forward_ex(_36, &_35)
			) {
				ZEPHIR_GET_HMKEY(key, _36, _35);
				ZEPHIR_GET_HVALUE(value, _37);
				ZEPHIR_INIT_NVAR(_19);
				zephir_get_class(_19, variable, 0 TSRMLS_CC);
				zephir_update_property_array_append(this_ptr, SL("methods"), _19 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(value, "__construct")) {
					ZEPHIR_SINIT_NVAR(_3);
					ZVAL_LONG(&_3, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_8, "str_repeat", &_9, space, &_3);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_10);
					array_init_size(_10, 3);
					ZEPHIR_INIT_NVAR(_19);
					ZVAL_STRING(_19, "obj", 0);
					ZEPHIR_CALL_METHOD(&_11, this_ptr, "getstyle", NULL, _19);
					zephir_check_temp_parameter(_19);
					zephir_check_call_status();
					zephir_array_update_string(&_10, SL(":style"), &_11, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_10, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_3);
					ZVAL_STRING(&_3, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n", 0);
					ZEPHIR_CALL_FUNCTION(&_11, "strtr", &_4, &_3, _10);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_12);
					ZEPHIR_CONCAT_VV(_12, _8, _11);
					zephir_concat_self(&output, _12 TSRMLS_CC);
				} else {
					ZEPHIR_SINIT_NVAR(_3);
					ZVAL_LONG(&_3, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_15, "str_repeat", &_9, space, &_3);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_38);
					array_init_size(_38, 3);
					ZEPHIR_INIT_NVAR(_19);
					ZVAL_STRING(_19, "obj", 0);
					ZEPHIR_CALL_METHOD(&_18, this_ptr, "getstyle", NULL, _19);
					zephir_check_temp_parameter(_19);
					zephir_check_call_status();
					zephir_array_update_string(&_38, SL(":style"), &_18, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_38, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_3);
					ZVAL_STRING(&_3, "-><span style=':style'>:method</span>();\n", 0);
					ZEPHIR_CALL_FUNCTION(&_18, "strtr", &_4, &_3, _38);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_39);
					ZEPHIR_CONCAT_VV(_39, _15, _18);
					zephir_concat_self(&output, _39 TSRMLS_CC);
				}
			}
			ZEPHIR_CALL_FUNCTION(&_18, "str_repeat", &_9, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_20);
			ZEPHIR_CONCAT_VS(_20, _18, ")\n");
			zephir_concat_self(&output, _20 TSRMLS_CC);
		}
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_8, "str_repeat", &_9, space, &_3);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _8, ")");
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_1, "is_int", &_16, variable);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 3);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "int", 0);
		ZEPHIR_CALL_METHOD(&_11, this_ptr, "getstyle", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_11, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>Intiger</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_4, &_3, _0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_1, "is_float", &_40, variable);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 3);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "float", 0);
		ZEPHIR_CALL_METHOD(&_11, this_ptr, "getstyle", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_11, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>Float</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_4, &_3, _0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 5);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "num", 0);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_0, SS(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>Numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_4, &_3, _0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 5);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "str", 0);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_0, SS(":length"), zephir_fast_strlen_ev(variable));
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, 4);
		ZEPHIR_SINIT_VAR(_41);
		ZVAL_STRING(&_41, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "htmlentities", &_42, variable, &_3, &_41);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_11, "nl2br", &_43, _1);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":var"), &_11, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>String</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_4, &_3, _0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_BOOL) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 3);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "bool", 0);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_LNVAR(_12);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(_12);
			ZVAL_STRING(_12, "TRUE", 1);
		} else {
			ZEPHIR_INIT_NVAR(_12);
			ZVAL_STRING(_12, "FALSE", 1);
		}
		zephir_array_update_string(&_0, SL(":var"), &_12, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>Boolean</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_4, &_3, _0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 2);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "null", 0);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "<b style=':style'>NULL</b>", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_4, &_3, _0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_0);
	array_init_size(_0, 3);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "other", 0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_STRING(&_3, "(<span style=':style'>:var</span>)", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_4, &_3, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an HTML string of information about a single variable.
 *
 *<code>
 *echo (new \Phalcon\Debug\Dump())->var($foo, "foo");
 *</code>
 *
 * @param mixed variable
 * @param string name
 * @return string
 */
PHP_METHOD(Phalcon_Debug_Dump, var) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *variable, *name = NULL, *_1 = NULL, *_2, _3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &variable, &name);

	if (!name) {
		name = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "pre", 0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "output", NULL, variable, name);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":output"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "<pre style=':style'>:output</pre>", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_4, &_3, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an HTML string of debugging information about any number of
 * variables, each wrapped in a "pre" tag.
 *
 *<code>
 *echo (new \Phalcon\Debug\Dump())->vars($foo, $bar, $baz);
 *</code>
 *
 * @param mixed variable
 * @param ...
 * @return string
 */
PHP_METHOD(Phalcon_Debug_Dump, vars) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *key = NULL, *value = NULL, *output, *_0 = NULL, **_4, *_5 = NULL, *_6 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(output);
	ZVAL_STRING(output, "", 1);
	ZEPHIR_CALL_FUNCTION(&_0, "func_get_args", &_1);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_3, &_2, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		ZEPHIR_INIT_LNVAR(_6);
		ZEPHIR_CONCAT_SV(_6, "var ", key);
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "one", NULL, value, _6);
		zephir_check_call_status();
		zephir_concat_self(&output, _5 TSRMLS_CC);
	}
	RETURN_CCTOR(output);

}

