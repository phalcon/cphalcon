
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
 *<code>
 *	$foo = 123;
 *	echo (new \Phalcon\Debug\Dump())->var($foo, "foo");
 *</code>
 *
 *<code>
 *	$foo = "string";
 *	$bar = ["key" => "value"];
 *	$baz = new stdClass();
 *	echo (new \Phalcon\Debug\Dump())->vars($foo, $bar, $baz);
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
 * @param array styles
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_debug_exception_ce, "The styles must be an array", "phalcon/debug/dump.zep", 57);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstyles", NULL, styles);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_methods"), _1 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_detailed"), detailed ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
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
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "vars", 1);
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
 *
 * @param array styles
 * @return array
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_debug_exception_ce, "The styles must be an array", "phalcon/debug/dump.zep", 108);
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
 * Alias of var() method
 *
 * @param mixed variable
 * @param string name
 * @return string
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

	zend_bool _14, _15, _16;
	HashTable *_7, *_25, *_37;
	HashPosition _6, _24, _36;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_10 = NULL, *_19 = NULL, *_21 = NULL, *_23 = NULL, *_29 = NULL, *_30 = NULL, *_31 = NULL, *_33 = NULL, *_34 = NULL, *_41 = NULL, *_43 = NULL, *_44 = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_11 = NULL, *_39 = NULL;
	zval *variable, *name = NULL, *tab = NULL, *key = NULL, *value = NULL, *output = NULL, *space, *type = NULL, *attr = NULL, *_1 = NULL, *_2 = NULL, _4 = zval_used_for_init, **_8, *_9 = NULL, *_12 = NULL, *_13 = NULL, *_17 = NULL, *_18 = NULL, *_20 = NULL, *_22, **_26, *_27 = NULL, *_28 = NULL, *_32, *_35, **_38, *_40 = NULL, _42;

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
		ZEPHIR_INIT_NVAR(output);
		ZEPHIR_CONCAT_VS(output, name, " ");
	}
	if (Z_TYPE_P(variable) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		zephir_create_array(_0, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "arr", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_3, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_0, SS(":count"), zephir_fast_count_int(variable TSRMLS_CC));
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "<b style =':style'>Array</b> (<span style =':style'>:count</span>) (\n", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "strtr", &_5, &_4, _0);
		zephir_check_call_status();
		zephir_concat_self(&output, _1 TSRMLS_CC);
		zephir_is_iterable(variable, &_7, &_6, 0, 0, "phalcon/debug/dump.zep", 171);
		for (
		  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7, &_6)
		) {
			ZEPHIR_GET_HMKEY(key, _7, _6);
			ZEPHIR_GET_HVALUE(value, _8);
			ZEPHIR_CALL_FUNCTION(&_9, "str_repeat", &_10, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_11);
			zephir_create_array(_11, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "arr", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_12, this_ptr, "getstyle", &_3, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			zephir_array_update_string(&_11, SL(":style"), &_12, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_11, SL(":key"), &key, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_STRING(&_4, "[<span style=':style'>:key</span>] => ", 0);
			ZEPHIR_CALL_FUNCTION(&_12, "strtr", &_5, &_4, _11);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_13);
			ZEPHIR_CONCAT_VV(_13, _9, _12);
			zephir_concat_self(&output, _13 TSRMLS_CC);
			_14 = ZEPHIR_IS_LONG(tab, 1);
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
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_18);
				ZVAL_LONG(_18, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_17, this_ptr, "output", &_19, value, _2, _18);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_20);
				ZEPHIR_CONCAT_VS(_20, _17, "\n");
				zephir_concat_self(&output, _20 TSRMLS_CC);
			}
		}
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_9, "str_repeat", &_10, space, &_4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _9, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_create_array(_0, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_3, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_2);
		zephir_get_class(_2, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_0, SL(":class"), &_2, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>Object</b> :class", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "strtr", &_5, &_4, _0);
		zephir_check_call_status();
		zephir_concat_self(&output, _1 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_12, "get_parent_class", &_21, variable);
		zephir_check_call_status();
		if (zephir_is_true(_12)) {
			ZEPHIR_INIT_NVAR(_11);
			zephir_create_array(_11, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "obj", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_17, this_ptr, "getstyle", &_3, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			zephir_array_update_string(&_11, SL(":style"), &_17, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_17, "get_parent_class", &_21, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_11, SL(":parent"), &_17, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_STRING(&_4, " <b style=':style'>extends</b> :parent", 0);
			ZEPHIR_CALL_FUNCTION(&_17, "strtr", &_5, &_4, _11);
			zephir_check_call_status();
			zephir_concat_self(&output, _17 TSRMLS_CC);
		}
		zephir_concat_self_str(&output, SL(" (\n") TSRMLS_CC);
		_22 = zephir_fetch_nproperty_this(this_ptr, SL("_detailed"), PH_NOISY_CC);
		if (!(zephir_is_true(_22))) {
			ZEPHIR_CALL_FUNCTION(&_9, "get_object_vars", &_23, variable);
			zephir_check_call_status();
			zephir_is_iterable(_9, &_25, &_24, 0, 0, "phalcon/debug/dump.zep", 188);
			for (
			  ; zephir_hash_get_current_data_ex(_25, (void**) &_26, &_24) == SUCCESS
			  ; zephir_hash_move_forward_ex(_25, &_24)
			) {
				ZEPHIR_GET_HMKEY(key, _25, _24);
				ZEPHIR_GET_HVALUE(value, _26);
				ZEPHIR_CALL_FUNCTION(&_12, "str_repeat", &_10, space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_11);
				zephir_create_array(_11, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_27, this_ptr, "getstyle", &_3, _2);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				zephir_array_update_string(&_11, SL(":style"), &_27, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_11, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(_11, SS(":type"), SL("public"), 1);
				ZEPHIR_SINIT_NVAR(_4);
				ZVAL_STRING(&_4, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_27, "strtr", &_5, &_4, _11);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_13);
				ZEPHIR_CONCAT_VV(_13, _12, _27);
				zephir_concat_self(&output, _13 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_18);
				ZVAL_LONG(_18, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_28, this_ptr, "output", &_19, value, _2, _18);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_20);
				ZEPHIR_CONCAT_VS(_20, _28, "\n");
				zephir_concat_self(&output, _20 TSRMLS_CC);
			}
		} else {
			do {
				Z_SET_ISREF_P(variable);
				ZEPHIR_CALL_FUNCTION(&attr, "each", &_29, variable);
				Z_UNSET_ISREF_P(variable);
				zephir_check_call_status();
				if (!(zephir_is_true(attr))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(key);
				zephir_array_fetch_string(&key, attr, SL("key"), PH_NOISY, "phalcon/debug/dump.zep", 195 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(value);
				zephir_array_fetch_string(&value, attr, SL("value"), PH_NOISY, "phalcon/debug/dump.zep", 196 TSRMLS_CC);
				if (!(zephir_is_true(key))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(_2);
				ZEPHIR_SINIT_NVAR(_4);
				ZVAL_STRING(&_4, "\\x00", 0);
				ZEPHIR_CALL_FUNCTION(&_9, "ord", &_30, &_4);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_12, "chr", &_31, _9);
				zephir_check_call_status();
				zephir_fast_explode(_2, _12, key, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(key, _2);
				ZEPHIR_INIT_NVAR(type);
				ZVAL_STRING(type, "public", 1);
				if (zephir_array_isset_long(key, 1)) {
					ZEPHIR_INIT_NVAR(type);
					ZVAL_STRING(type, "private", 1);
					zephir_array_fetch_long(&_32, key, 1, PH_NOISY | PH_READONLY, "phalcon/debug/dump.zep", 207 TSRMLS_CC);
					if (ZEPHIR_IS_STRING(_32, "*")) {
						ZEPHIR_INIT_NVAR(type);
						ZVAL_STRING(type, "protected", 1);
					}
				}
				ZEPHIR_CALL_FUNCTION(&_17, "str_repeat", &_10, space, tab);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_11);
				zephir_create_array(_11, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_27, this_ptr, "getstyle", &_3, _2);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				zephir_array_update_string(&_11, SL(":style"), &_27, PH_COPY | PH_SEPARATE);
				Z_SET_ISREF_P(key);
				ZEPHIR_CALL_FUNCTION(&_27, "end", &_33, key);
				Z_UNSET_ISREF_P(key);
				zephir_check_call_status();
				zephir_array_update_string(&_11, SL(":key"), &_27, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_11, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_SINIT_NVAR(_4);
				ZVAL_STRING(&_4, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_27, "strtr", &_5, &_4, _11);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_13);
				ZEPHIR_CONCAT_VV(_13, _17, _27);
				zephir_concat_self(&output, _13 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_2);
				ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_18);
				ZVAL_LONG(_18, (zephir_get_numberval(tab) + 1));
				ZEPHIR_CALL_METHOD(&_28, this_ptr, "output", &_19, value, _2, _18);
				zephir_check_temp_parameter(_2);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_20);
				ZEPHIR_CONCAT_VS(_20, _28, "\n");
				zephir_concat_self(&output, _20 TSRMLS_CC);
			} while (zephir_is_true(attr));
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", &_34, variable);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_9, "str_repeat", &_10, space, tab);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_11);
		zephir_create_array(_11, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_12, this_ptr, "getstyle", &_3, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_11, SL(":style"), &_12, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_2);
		zephir_get_class(_2, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_11, SL(":class"), &_2, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_11, SS(":count"), zephir_fast_count_int(attr TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n", 0);
		ZEPHIR_CALL_FUNCTION(&_12, "strtr", &_5, &_4, _11);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_13);
		ZEPHIR_CONCAT_VV(_13, _9, _12);
		zephir_concat_self(&output, _13 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_2);
		zephir_get_class(_2, variable, 0 TSRMLS_CC);
		_35 = zephir_fetch_nproperty_this(this_ptr, SL("_methods"), PH_NOISY_CC);
		if (zephir_fast_in_array(_2, _35 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_17, "str_repeat", &_10, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_20);
			ZEPHIR_CONCAT_VS(_20, _17, "[already listed]\n");
			zephir_concat_self(&output, _20 TSRMLS_CC);
		} else {
			zephir_is_iterable(attr, &_37, &_36, 0, 0, "phalcon/debug/dump.zep", 231);
			for (
			  ; zephir_hash_get_current_data_ex(_37, (void**) &_38, &_36) == SUCCESS
			  ; zephir_hash_move_forward_ex(_37, &_36)
			) {
				ZEPHIR_GET_HVALUE(value, _38);
				ZEPHIR_INIT_NVAR(_18);
				zephir_get_class(_18, variable, 0 TSRMLS_CC);
				zephir_update_property_array_append(this_ptr, SL("_methods"), _18 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(value, "__construct")) {
					ZEPHIR_SINIT_NVAR(_4);
					ZVAL_LONG(&_4, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_9, "str_repeat", &_10, space, &_4);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_11);
					zephir_create_array(_11, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_18);
					ZVAL_STRING(_18, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_12, this_ptr, "getstyle", &_3, _18);
					zephir_check_temp_parameter(_18);
					zephir_check_call_status();
					zephir_array_update_string(&_11, SL(":style"), &_12, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_11, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_4);
					ZVAL_STRING(&_4, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n", 0);
					ZEPHIR_CALL_FUNCTION(&_12, "strtr", &_5, &_4, _11);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_13);
					ZEPHIR_CONCAT_VV(_13, _9, _12);
					zephir_concat_self(&output, _13 TSRMLS_CC);
				} else {
					ZEPHIR_SINIT_NVAR(_4);
					ZVAL_LONG(&_4, (zephir_get_numberval(tab) + 1));
					ZEPHIR_CALL_FUNCTION(&_27, "str_repeat", &_10, space, &_4);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_39);
					zephir_create_array(_39, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_18);
					ZVAL_STRING(_18, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_28, this_ptr, "getstyle", &_3, _18);
					zephir_check_temp_parameter(_18);
					zephir_check_call_status();
					zephir_array_update_string(&_39, SL(":style"), &_28, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_39, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_4);
					ZVAL_STRING(&_4, "-><span style=':style'>:method</span>();\n", 0);
					ZEPHIR_CALL_FUNCTION(&_28, "strtr", &_5, &_4, _39);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_40);
					ZEPHIR_CONCAT_VV(_40, _27, _28);
					zephir_concat_self(&output, _40 TSRMLS_CC);
				}
			}
			ZEPHIR_CALL_FUNCTION(&_17, "str_repeat", &_10, space, tab);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_20);
			ZEPHIR_CONCAT_VS(_20, _17, ")\n");
			zephir_concat_self(&output, _20 TSRMLS_CC);
		}
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, (zephir_get_numberval(tab) - 1));
		ZEPHIR_CALL_FUNCTION(&_9, "str_repeat", &_10, space, &_4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _9, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_create_array(_0, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "int", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_3, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>Intiger</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_5, &_4, _0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_1, "is_float", &_41, variable);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_create_array(_0, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "float", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_12, this_ptr, "getstyle", &_3, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_12, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>Float</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_5, &_4, _0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_create_array(_0, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "num", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_3, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_0, SS(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>Numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_5, &_4, _0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_create_array(_0, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "str", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_3, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_0, SS(":length"), zephir_fast_strlen_ev(variable));
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 4);
		ZEPHIR_SINIT_VAR(_42);
		ZVAL_STRING(&_42, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "htmlentities", &_43, variable, &_4, &_42);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_12, "nl2br", &_44, _1);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":var"), &_12, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>String</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_5, &_4, _0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_BOOL) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_create_array(_0, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "bool", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_3, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_LNVAR(_13);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(_13);
			ZVAL_STRING(_13, "TRUE", 1);
		} else {
			ZEPHIR_INIT_NVAR(_13);
			ZVAL_STRING(_13, "FALSE", 1);
		}
		zephir_array_update_string(&_0, SL(":var"), &_13, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>Boolean</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_5, &_4, _0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_create_array(_0, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "null", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_3, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "<b style=':style'>NULL</b>", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_5, &_4, _0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "other", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", &_3, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_STRING(&_4, "(<span style=':style'>:var</span>)", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_5, &_4, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an HTML string of information about a single variable.
 *
 *<code>
 *	echo (new \Phalcon\Debug\Dump())->var($foo, "foo");
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
 *	$foo = "string";
 *	$bar = ["key" => "value"];
 *	$baz = new stdClass();
 *	echo (new \Phalcon\Debug\Dump())->vars($foo, $bar, $baz);
 *</code>
 *
 * @param mixed variable
 * @param ...
 * @return string
 */
PHP_METHOD(Phalcon_Debug_Dump, vars) {

	zephir_fcall_cache_entry *_7 = NULL;
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
	zephir_is_iterable(_0, &_3, &_2, 0, 0, "phalcon/debug/dump.zep", 305);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		ZEPHIR_INIT_LNVAR(_6);
		ZEPHIR_CONCAT_SV(_6, "var ", key);
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "one", &_7, value, _6);
		zephir_check_call_status();
		zephir_concat_self(&output, _5 TSRMLS_CC);
	}
	RETURN_CCTOR(output);

}

