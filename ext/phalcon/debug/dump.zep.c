
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/string.h"


/**
 * Phalcon\Debug\Dump
 *
 * Dumps information about a variable(s)
 *
 * <code>
 *    $foo = 123;
 *    echo (new \Phalcon\Debug\Dump())->variable($foo, "foo");
 *</code>
 *
 * <code>
 *    $foo = "string";
 *    $bar = ["key" => "value"];
 *    $baz = new stdClass();
 *    echo (new \Phalcon\Debug\Dump())->variables($foo, $bar, $baz);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Debug_Dump) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Debug, Dump, phalcon, debug_dump, phalcon_debug_dump_method_entry, 0);

	zend_declare_property_bool(phalcon_debug_dump_ce, SL("_detailed"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_debug_dump_ce, SL("_methods"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_debug_dump_ce, SL("_styles"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Debug_Dump, getDetailed) {


	RETURN_MEMBER(this_ptr, "_detailed");

}

PHP_METHOD(Phalcon_Debug_Dump, setDetailed) {

	zval *detailed;

	zephir_fetch_params(0, 1, 0, &detailed);



	zephir_update_property_this(this_ptr, SL("_detailed"), detailed TSRMLS_CC);

}

/**
 * Phalcon\Debug\Dump constructor
 *
 * @param boolean detailed debug object's private and protected properties
 */
PHP_METHOD(Phalcon_Debug_Dump, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool detailed, _0;
	zval *styles_param = NULL, *detailed_param = NULL, *_1;
	zval *styles = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &styles_param, &detailed_param);

	if (!styles_param) {
	ZEPHIR_INIT_VAR(styles);
	array_init(styles);
	} else {
		zephir_get_arrval(styles, styles_param);
	}
	if (!detailed_param) {
		detailed = 0;
	} else {
		detailed = zephir_get_boolval(detailed_param);
	}


	_0 = zephir_is_true(styles);
	if (_0) {
		_0 = 1 != 1;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_debug_exception_ce, "The styles must be an array", "phalcon/debug/dump.zep", 56);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstyles", NULL, 0, styles);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_methods"), _1 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_detailed"), detailed ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Alias of variables() method
 *
 * @param mixed variable
 * @param ...
 */
PHP_METHOD(Phalcon_Debug_Dump, all) {

	zval *_1, *_2 = NULL;
	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "variables", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(&_2, "func_get_args", NULL, 131);
	zephir_check_call_status();
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _0, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get style for type
 */
PHP_METHOD(Phalcon_Debug_Dump, getStyle) {

	zval *type_param = NULL, *style, *_0;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_styles"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&style, _0, type, 1 TSRMLS_CC)) {
		RETURN_CTOR(style);
	} else {
		RETURN_MM_STRING("color:gray", 1);
	}

}

/**
 * Set styles for vars type
 */
PHP_METHOD(Phalcon_Debug_Dump, setStyles) {

	zval *styles = NULL, *defaultStyles, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &styles);

	if (!styles) {
		ZEPHIR_CPY_WRT(styles, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(styles);
	}


	if (Z_TYPE_P(styles) == IS_NULL) {
		ZEPHIR_INIT_NVAR(styles);
		array_init(styles);
	}
	if (Z_TYPE_P(styles) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_debug_exception_ce, "The styles must be an array", "phalcon/debug/dump.zep", 100);
		return;
	}
	ZEPHIR_INIT_VAR(defaultStyles);
	zephir_create_array(defaultStyles, 11, 0 TSRMLS_CC);
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
	zephir_update_property_this(this_ptr, SL("_styles"), _0 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "_styles");

}

/**
 * Alias of variable() method
 */
PHP_METHOD(Phalcon_Debug_Dump, one) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL;
	zval *variable, *name_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &variable, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "variable", NULL, 0, variable, name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prepare an HTML string of information about a single variable.
 */
PHP_METHOD(Phalcon_Debug_Dump, output) {

	zend_bool _14, _15, _16;
	HashTable *_7, *_22, *_33;
	HashPosition _6, _21, _32;
	zephir_fcall_cache_entry *_4 = NULL, *_10 = NULL, *_18 = NULL, *_26 = NULL, *_27 = NULL, *_28 = NULL, *_30 = NULL;
	zval *_1 = NULL, *_11 = NULL, *_36 = NULL;
	int tab, ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, *_0;
	zval *variable, *name_param = NULL, *tab_param = NULL, *key = NULL, *value = NULL, *output = NULL, *space, *type = NULL, *attr = NULL, *_2 = NULL, *_3 = NULL, _5 = zval_used_for_init, **_8, *_9 = NULL, *_12 = NULL, *_13 = NULL, *_17 = NULL, *_19 = NULL, *_20, **_23, *_24 = NULL, *_25 = NULL, *_29, *_31, **_34, *_35 = NULL, *_37 = NULL, _38;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &variable, &name_param, &tab_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}
	if (!tab_param) {
		tab = 1;
	} else {
		tab = zephir_get_intval(tab_param);
	}


	ZEPHIR_INIT_VAR(space);
	ZVAL_STRING(space, "  ", 1);
	ZEPHIR_INIT_VAR(output);
	ZVAL_STRING(output, "", 1);
	if (name && Z_STRLEN_P(name)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VS(_0, name, " ");
		ZEPHIR_CPY_WRT(output, _0);
	}
	if (Z_TYPE_P(variable) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_1);
		zephir_create_array(_1, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "arr", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getstyle", &_4, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		zephir_array_update_string(&_1, SL(":style"), &_2, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_1, SS(":count"), zephir_fast_count_int(variable TSRMLS_CC));
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_STRING(&_5, "<b style =':style'>Array</b> (<span style =':style'>:count</span>) (\n", 0);
		ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 73, &_5, _1);
		zephir_check_call_status();
		zephir_concat_self(&output, _2 TSRMLS_CC);
		zephir_is_iterable(variable, &_7, &_6, 0, 0, "phalcon/debug/dump.zep", 154);
		for (
		  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7, &_6)
		) {
			ZEPHIR_GET_HMKEY(key, _7, _6);
			ZEPHIR_GET_HVALUE(value, _8);
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_LONG(&_5, tab);
			ZEPHIR_CALL_FUNCTION(&_9, "str_repeat", &_10, 66, space, &_5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_11);
			zephir_create_array(_11, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "arr", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_12, this_ptr, "getstyle", &_4, 0, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			zephir_array_update_string(&_11, SL(":style"), &_12, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_11, SL(":key"), &key, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_STRING(&_5, "[<span style=':style'>:key</span>] => ", 0);
			ZEPHIR_CALL_FUNCTION(&_12, "strtr", NULL, 73, &_5, _11);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_13);
			ZEPHIR_CONCAT_VV(_13, _9, _12);
			zephir_concat_self(&output, _13 TSRMLS_CC);
			_14 = tab == 1;
			if (_14) {
				_14 = !ZEPHIR_IS_STRING(name, "");
			}
			_15 = _14;
			if (_15) {
				_15 = !(Z_TYPE_P(key) == IS_LONG);
			}
			_16 = _15;
			if (_16) {
				_16 = ZEPHIR_IS_EQUAL(name, key);
			}
			if (_16) {
				continue;
			} else {
				ZEPHIR_INIT_NVAR(_3);
				ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, (tab + 1));
				ZEPHIR_CALL_METHOD(&_17, this_ptr, "output", &_18, 132, value, _3, &_5);
				zephir_check_temp_parameter(_3);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_19);
				ZEPHIR_CONCAT_VS(_19, _17, "\n");
				zephir_concat_self(&output, _19 TSRMLS_CC);
			}
		}
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_9, "str_repeat", &_10, 66, space, &_5);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _9, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_1);
		zephir_create_array(_1, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getstyle", &_4, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		zephir_array_update_string(&_1, SL(":style"), &_2, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_3);
		zephir_get_class(_3, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_1, SL(":class"), &_3, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_STRING(&_5, "<b style=':style'>Object</b> :class", 0);
		ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 73, &_5, _1);
		zephir_check_call_status();
		zephir_concat_self(&output, _2 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_12, "get_parent_class", NULL, 133, variable);
		zephir_check_call_status();
		if (zephir_is_true(_12)) {
			ZEPHIR_INIT_NVAR(_11);
			zephir_create_array(_11, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "obj", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_17, this_ptr, "getstyle", &_4, 0, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
			zephir_array_update_string(&_11, SL(":style"), &_17, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_17, "get_parent_class", NULL, 133, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_11, SL(":parent"), &_17, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_STRING(&_5, " <b style=':style'>extends</b> :parent", 0);
			ZEPHIR_CALL_FUNCTION(&_17, "strtr", NULL, 73, &_5, _11);
			zephir_check_call_status();
			zephir_concat_self(&output, _17 TSRMLS_CC);
		}
		zephir_concat_self_str(&output, SL(" (\n") TSRMLS_CC);
		_20 = zephir_fetch_nproperty_this(this_ptr, SL("_detailed"), PH_NOISY_CC);
		if (!(zephir_is_true(_20))) {
			ZEPHIR_CALL_FUNCTION(&_9, "get_object_vars", NULL, 60, variable);
			zephir_check_call_status();
			zephir_is_iterable(_9, &_22, &_21, 0, 0, "phalcon/debug/dump.zep", 171);
			for (
			  ; zephir_hash_get_current_data_ex(_22, (void**) &_23, &_21) == SUCCESS
			  ; zephir_hash_move_forward_ex(_22, &_21)
			) {
				ZEPHIR_GET_HMKEY(key, _22, _21);
				ZEPHIR_GET_HVALUE(value, _23);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, tab);
				ZEPHIR_CALL_FUNCTION(&_12, "str_repeat", &_10, 66, space, &_5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_11);
				zephir_create_array(_11, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_3);
				ZVAL_STRING(_3, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_24, this_ptr, "getstyle", &_4, 0, _3);
				zephir_check_temp_parameter(_3);
				zephir_check_call_status();
				zephir_array_update_string(&_11, SL(":style"), &_24, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_11, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(_11, SS(":type"), SL("public"), 1);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_STRING(&_5, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_24, "strtr", NULL, 73, &_5, _11);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_13);
				ZEPHIR_CONCAT_VV(_13, _12, _24);
				zephir_concat_self(&output, _13 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_3);
				ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, (tab + 1));
				ZEPHIR_CALL_METHOD(&_25, this_ptr, "output", &_18, 132, value, _3, &_5);
				zephir_check_temp_parameter(_3);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_19);
				ZEPHIR_CONCAT_VS(_19, _25, "\n");
				zephir_concat_self(&output, _19 TSRMLS_CC);
			}
		} else {
			do {
				Z_SET_ISREF_P(variable);
				ZEPHIR_CALL_FUNCTION(&attr, "each", &_26, 134, variable);
				Z_UNSET_ISREF_P(variable);
				zephir_check_call_status();
				if (!(zephir_is_true(attr))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(key);
				zephir_array_fetch_string(&key, attr, SL("key"), PH_NOISY, "phalcon/debug/dump.zep", 178 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(value);
				zephir_array_fetch_string(&value, attr, SL("value"), PH_NOISY, "phalcon/debug/dump.zep", 179 TSRMLS_CC);
				if (!(zephir_is_true(key))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(_3);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_STRING(&_5, "\\x00", 0);
				ZEPHIR_CALL_FUNCTION(&_9, "ord", &_27, 67, &_5);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_12, "chr", &_28, 65, _9);
				zephir_check_call_status();
				zephir_fast_explode(_3, _12, key, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(key, _3);
				ZEPHIR_INIT_NVAR(type);
				ZVAL_STRING(type, "public", 1);
				if (zephir_array_isset_long(key, 1)) {
					ZEPHIR_INIT_NVAR(type);
					ZVAL_STRING(type, "private", 1);
					zephir_array_fetch_long(&_29, key, 1, PH_NOISY | PH_READONLY, "phalcon/debug/dump.zep", 190 TSRMLS_CC);
					if (ZEPHIR_IS_STRING(_29, "*")) {
						ZEPHIR_INIT_NVAR(type);
						ZVAL_STRING(type, "protected", 1);
					}
				}
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, tab);
				ZEPHIR_CALL_FUNCTION(&_17, "str_repeat", &_10, 66, space, &_5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_11);
				zephir_create_array(_11, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_3);
				ZVAL_STRING(_3, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_24, this_ptr, "getstyle", &_4, 0, _3);
				zephir_check_temp_parameter(_3);
				zephir_check_call_status();
				zephir_array_update_string(&_11, SL(":style"), &_24, PH_COPY | PH_SEPARATE);
				Z_SET_ISREF_P(key);
				ZEPHIR_CALL_FUNCTION(&_24, "end", &_30, 135, key);
				Z_UNSET_ISREF_P(key);
				zephir_check_call_status();
				zephir_array_update_string(&_11, SL(":key"), &_24, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_11, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_STRING(&_5, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_24, "strtr", NULL, 73, &_5, _11);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_13);
				ZEPHIR_CONCAT_VV(_13, _17, _24);
				zephir_concat_self(&output, _13 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_3);
				ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, (tab + 1));
				ZEPHIR_CALL_METHOD(&_25, this_ptr, "output", &_18, 132, value, _3, &_5);
				zephir_check_temp_parameter(_3);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_19);
				ZEPHIR_CONCAT_VS(_19, _25, "\n");
				zephir_concat_self(&output, _19 TSRMLS_CC);
			} while (zephir_is_true(attr));
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 136, variable);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, tab);
		ZEPHIR_CALL_FUNCTION(&_9, "str_repeat", &_10, 66, space, &_5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_11);
		zephir_create_array(_11, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_12, this_ptr, "getstyle", &_4, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		zephir_array_update_string(&_11, SL(":style"), &_12, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_3);
		zephir_get_class(_3, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_11, SL(":class"), &_3, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_11, SS(":count"), zephir_fast_count_int(attr TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_STRING(&_5, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n", 0);
		ZEPHIR_CALL_FUNCTION(&_12, "strtr", NULL, 73, &_5, _11);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_13);
		ZEPHIR_CONCAT_VV(_13, _9, _12);
		zephir_concat_self(&output, _13 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_3);
		zephir_get_class(_3, variable, 0 TSRMLS_CC);
		_31 = zephir_fetch_nproperty_this(this_ptr, SL("_methods"), PH_NOISY_CC);
		if (zephir_fast_in_array(_3, _31 TSRMLS_CC)) {
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_LONG(&_5, tab);
			ZEPHIR_CALL_FUNCTION(&_17, "str_repeat", &_10, 66, space, &_5);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_19);
			ZEPHIR_CONCAT_VS(_19, _17, "[already listed]\n");
			zephir_concat_self(&output, _19 TSRMLS_CC);
		} else {
			zephir_is_iterable(attr, &_33, &_32, 0, 0, "phalcon/debug/dump.zep", 214);
			for (
			  ; zephir_hash_get_current_data_ex(_33, (void**) &_34, &_32) == SUCCESS
			  ; zephir_hash_move_forward_ex(_33, &_32)
			) {
				ZEPHIR_GET_HVALUE(value, _34);
				ZEPHIR_INIT_NVAR(_35);
				zephir_get_class(_35, variable, 0 TSRMLS_CC);
				zephir_update_property_array_append(this_ptr, SL("_methods"), _35 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(value, "__construct")) {
					ZEPHIR_SINIT_NVAR(_5);
					ZVAL_LONG(&_5, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_9, "str_repeat", &_10, 66, space, &_5);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_11);
					zephir_create_array(_11, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_35);
					ZVAL_STRING(_35, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_12, this_ptr, "getstyle", &_4, 0, _35);
					zephir_check_temp_parameter(_35);
					zephir_check_call_status();
					zephir_array_update_string(&_11, SL(":style"), &_12, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_11, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_5);
					ZVAL_STRING(&_5, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n", 0);
					ZEPHIR_CALL_FUNCTION(&_12, "strtr", NULL, 73, &_5, _11);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_13);
					ZEPHIR_CONCAT_VV(_13, _9, _12);
					zephir_concat_self(&output, _13 TSRMLS_CC);
				} else {
					ZEPHIR_SINIT_NVAR(_5);
					ZVAL_LONG(&_5, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_24, "str_repeat", &_10, 66, space, &_5);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_36);
					zephir_create_array(_36, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_35);
					ZVAL_STRING(_35, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_25, this_ptr, "getstyle", &_4, 0, _35);
					zephir_check_temp_parameter(_35);
					zephir_check_call_status();
					zephir_array_update_string(&_36, SL(":style"), &_25, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_36, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_5);
					ZVAL_STRING(&_5, "-><span style=':style'>:method</span>();\n", 0);
					ZEPHIR_CALL_FUNCTION(&_25, "strtr", NULL, 73, &_5, _36);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_37);
					ZEPHIR_CONCAT_VV(_37, _24, _25);
					zephir_concat_self(&output, _37 TSRMLS_CC);
				}
			}
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_LONG(&_5, tab);
			ZEPHIR_CALL_FUNCTION(&_17, "str_repeat", &_10, 66, space, &_5);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_19);
			ZEPHIR_CONCAT_VS(_19, _17, ")\n");
			zephir_concat_self(&output, _19 TSRMLS_CC);
		}
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_9, "str_repeat", &_10, 66, space, &_5);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _9, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_NVAR(_1);
		zephir_create_array(_1, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "int", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getstyle", &_4, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		zephir_array_update_string(&_1, SL(":style"), &_2, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_1, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_STRING(&_5, "<b style=':style'>Integer</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 73, &_5, _1);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_2, "is_float", NULL, 137, variable);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZEPHIR_INIT_NVAR(_1);
		zephir_create_array(_1, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "float", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_12, this_ptr, "getstyle", &_4, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		zephir_array_update_string(&_1, SL(":style"), &_12, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_1, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_STRING(&_5, "<b style=':style'>Float</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 73, &_5, _1);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_NVAR(_1);
		zephir_create_array(_1, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "num", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getstyle", &_4, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		zephir_array_update_string(&_1, SL(":style"), &_2, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_1, SS(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_1, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_STRING(&_5, "<b style=':style'>Numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 73, &_5, _1);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_NVAR(_1);
		zephir_create_array(_1, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "str", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getstyle", &_4, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		zephir_array_update_string(&_1, SL(":style"), &_2, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_1, SS(":length"), zephir_fast_strlen_ev(variable));
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, 4);
		ZEPHIR_SINIT_VAR(_38);
		ZVAL_STRING(&_38, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_2, "htmlentities", NULL, 117, variable, &_5, &_38);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_12, "nl2br", NULL, 138, _2);
		zephir_check_call_status();
		zephir_array_update_string(&_1, SL(":var"), &_12, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_STRING(&_5, "<b style=':style'>String</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 73, &_5, _1);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_BOOL) {
		ZEPHIR_INIT_NVAR(_1);
		zephir_create_array(_1, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "bool", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getstyle", &_4, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		zephir_array_update_string(&_1, SL(":style"), &_2, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_LNVAR(_13);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(_13);
			ZVAL_STRING(_13, "TRUE", 1);
		} else {
			ZEPHIR_INIT_NVAR(_13);
			ZVAL_STRING(_13, "FALSE", 1);
		}
		zephir_array_update_string(&_1, SL(":var"), &_13, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_STRING(&_5, "<b style=':style'>Boolean</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 73, &_5, _1);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_NVAR(_1);
		zephir_create_array(_1, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "null", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getstyle", &_4, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		zephir_array_update_string(&_1, SL(":style"), &_2, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_STRING(&_5, "<b style=':style'>NULL</b>", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 73, &_5, _1);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_1);
	zephir_create_array(_1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "other", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getstyle", &_4, 0, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL(":style"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_STRING(&_5, "(<span style=':style'>:var</span>)", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 73, &_5, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an HTML string of information about a single variable.
 *
 * <code>
 *    echo (new \Phalcon\Debug\Dump())->variable($foo, "foo");
 * </code>
 */
PHP_METHOD(Phalcon_Debug_Dump, variable) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *name = NULL;
	zval *variable, *name_param = NULL, *_1 = NULL, *_2, _3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &variable, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "pre", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "output", NULL, 0, variable, name);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":output"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "<pre style=':style'>:output</pre>", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 73, &_3, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an HTML string of debugging information about any number of
 * variables, each wrapped in a "pre" tag.
 *
 * <code>
 *    $foo = "string";
 *    $bar = ["key" => "value"];
 *    $baz = new stdClass();
 *    echo (new \Phalcon\Debug\Dump())->variables($foo, $bar, $baz);
 *</code>
 *
 * @param mixed variable
 * @param ...
 */
PHP_METHOD(Phalcon_Debug_Dump, variables) {

	zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *value = NULL, *output, *_0 = NULL, **_3, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(output);
	ZVAL_STRING(output, "", 1);
	ZEPHIR_CALL_FUNCTION(&_0, "func_get_args", NULL, 131);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/debug/dump.zep", 283);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		ZEPHIR_INIT_LNVAR(_5);
		ZEPHIR_CONCAT_SV(_5, "var ", key);
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "one", &_6, 0, value, _5);
		zephir_check_call_status();
		zephir_concat_self(&output, _4 TSRMLS_CC);
	}
	RETURN_CCTOR(output);

}

