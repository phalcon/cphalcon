
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
	if (detailed) {
		zephir_update_property_this(this_ptr, SL("_detailed"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_detailed"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
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
	ZEPHIR_CALL_FUNCTION(&_2, "func_get_args", NULL, 163);
	zephir_check_call_status();
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _0, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get style for type
 */
PHP_METHOD(Phalcon_Debug_Dump, getStyle) {

	zval *type_param = NULL, *style = NULL, *_0;
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

	zval *styles = NULL, *defaultStyles = NULL, *_0;

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

	zend_bool _17$$5, _18$$5, _19$$5;
	HashTable *_8$$4, *_39$$10, *_75$$19;
	HashPosition _7$$4, _38$$10, _74$$19;
	zval *_122, *_1$$4, *_13$$5 = NULL, *_26$$8, *_67$$8, *_32$$9, *_43$$11 = NULL, *_59$$13 = NULL, *_80$$21 = NULL, *_86$$22 = NULL, *_94$$23, *_99$$24, *_103$$25, *_107$$26, *_113$$27, *_118$$28;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_12 = NULL, *_23 = NULL, *_31 = NULL, *_50 = NULL, *_54 = NULL, *_56 = NULL, *_61 = NULL;
	int tab, ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, *_0$$3;
	zval *variable, *name_param = NULL, *tab_param = NULL, *key = NULL, *value = NULL, *output = NULL, *space = NULL, *type = NULL, *attr = NULL, *_98 = NULL, *_123 = NULL, *_124, _125, *_2$$4 = NULL, *_3$$4, _5$$4 = zval_used_for_init, **_9$$4, *_25$$4 = NULL, _10$$5 = zval_used_for_init, *_11$$5 = NULL, *_14$$5 = NULL, *_15$$5 = NULL, *_16$$5 = NULL, *_20$$7 = NULL, *_21$$7 = NULL, *_22$$7 = NULL, *_24$$7 = NULL, *_27$$8 = NULL, *_28$$8 = NULL, _29$$8 = zval_used_for_init, *_30$$8 = NULL, *_36$$8, *_66$$8 = NULL, *_68$$8 = NULL, *_69$$8, *_70$$8, *_93$$8 = NULL, *_33$$9 = NULL, *_34$$9, _35$$9, *_37$$10 = NULL, **_40$$10, _41$$11 = zval_used_for_init, *_42$$11 = NULL, *_44$$11 = NULL, *_45$$11 = NULL, *_46$$11 = NULL, *_47$$11 = NULL, *_48$$11 = NULL, *_49$$11 = NULL, *_51$$13 = NULL, _52$$13 = zval_used_for_init, *_53$$13 = NULL, *_55$$13 = NULL, *_58$$13 = NULL, *_60$$13 = NULL, *_62$$13 = NULL, *_63$$13 = NULL, *_64$$13 = NULL, *_65$$13 = NULL, *_57$$16, _71$$18, *_72$$18 = NULL, *_73$$18, **_76$$19, _90$$19, *_91$$19 = NULL, *_92$$19, *_77$$20 = NULL, _78$$21 = zval_used_for_init, *_79$$21 = NULL, *_81$$21 = NULL, *_82$$21 = NULL, *_83$$21 = NULL, _84$$22 = zval_used_for_init, *_85$$22 = NULL, *_87$$22 = NULL, *_88$$22 = NULL, *_89$$22 = NULL, *_95$$23 = NULL, *_96$$23, _97$$23, *_100$$24 = NULL, *_101$$24, _102$$24, *_104$$25 = NULL, *_105$$25, _106$$25, *_108$$26 = NULL, *_109$$26, _110$$26 = zval_used_for_init, _111$$26, *_112$$26 = NULL, *_114$$27 = NULL, *_115$$27, *_116$$27 = NULL, _117$$27, *_119$$28 = NULL, *_120$$28, _121$$28;

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
	if (!(!name) && Z_STRLEN_P(name)) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZEPHIR_CONCAT_VS(_0$$3, name, " ");
		ZEPHIR_CPY_WRT(output, _0$$3);
	}
	if (Z_TYPE_P(variable) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_1$$4);
		zephir_create_array(_1$$4, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3$$4);
		ZVAL_STRING(_3$$4, "arr", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getstyle", &_4, 0, _3$$4);
		zephir_check_temp_parameter(_3$$4);
		zephir_check_call_status();
		zephir_array_update_string(&_1$$4, SL(":style"), &_2$$4, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_1$$4, SS(":count"), zephir_fast_count_int(variable TSRMLS_CC));
		ZEPHIR_SINIT_VAR(_5$$4);
		ZVAL_STRING(&_5$$4, "<b style =':style'>Array</b> (<span style =':style'>:count</span>) (\n", 0);
		ZEPHIR_CALL_FUNCTION(&_2$$4, "strtr", &_6, 55, &_5$$4, _1$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, _2$$4 TSRMLS_CC);
		zephir_is_iterable(variable, &_8$$4, &_7$$4, 0, 0, "phalcon/debug/dump.zep", 154);
		for (
		  ; zephir_hash_get_current_data_ex(_8$$4, (void**) &_9$$4, &_7$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_8$$4, &_7$$4)
		) {
			ZEPHIR_GET_HMKEY(key, _8$$4, _7$$4);
			ZEPHIR_GET_HVALUE(value, _9$$4);
			ZEPHIR_SINIT_NVAR(_10$$5);
			ZVAL_LONG(&_10$$5, tab);
			ZEPHIR_CALL_FUNCTION(&_11$$5, "str_repeat", &_12, 133, space, &_10$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_13$$5);
			zephir_create_array(_13$$5, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_15$$5);
			ZVAL_STRING(_15$$5, "arr", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_14$$5, this_ptr, "getstyle", &_4, 0, _15$$5);
			zephir_check_temp_parameter(_15$$5);
			zephir_check_call_status();
			zephir_array_update_string(&_13$$5, SL(":style"), &_14$$5, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_13$$5, SL(":key"), &key, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_10$$5);
			ZVAL_STRING(&_10$$5, "[<span style=':style'>:key</span>] => ", 0);
			ZEPHIR_CALL_FUNCTION(&_14$$5, "strtr", &_6, 55, &_10$$5, _13$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_16$$5);
			ZEPHIR_CONCAT_VV(_16$$5, _11$$5, _14$$5);
			zephir_concat_self(&output, _16$$5 TSRMLS_CC);
			_17$$5 = tab == 1;
			if (_17$$5) {
				_17$$5 = !ZEPHIR_IS_STRING(name, "");
			}
			_18$$5 = _17$$5;
			if (_18$$5) {
				_18$$5 = !(Z_TYPE_P(key) == IS_LONG);
			}
			_19$$5 = _18$$5;
			if (_19$$5) {
				_19$$5 = ZEPHIR_IS_EQUAL(name, key);
			}
			if (_19$$5) {
				continue;
			} else {
				ZEPHIR_INIT_NVAR(_21$$7);
				ZVAL_STRING(_21$$7, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_22$$7);
				ZVAL_LONG(_22$$7, (tab + 1));
				ZEPHIR_CALL_METHOD(&_20$$7, this_ptr, "output", &_23, 164, value, _21$$7, _22$$7);
				zephir_check_temp_parameter(_21$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_24$$7);
				ZEPHIR_CONCAT_VS(_24$$7, _20$$7, "\n");
				zephir_concat_self(&output, _24$$7 TSRMLS_CC);
			}
		}
		ZEPHIR_SINIT_NVAR(_5$$4);
		ZVAL_LONG(&_5$$4, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_25$$4, "str_repeat", &_12, 133, space, &_5$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _25$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_26$$8);
		zephir_create_array(_26$$8, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_28$$8);
		ZVAL_STRING(_28$$8, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_27$$8, this_ptr, "getstyle", &_4, 0, _28$$8);
		zephir_check_temp_parameter(_28$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_26$$8, SL(":style"), &_27$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_28$$8);
		zephir_get_class(_28$$8, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_26$$8, SL(":class"), &_28$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_29$$8);
		ZVAL_STRING(&_29$$8, "<b style=':style'>Object</b> :class", 0);
		ZEPHIR_CALL_FUNCTION(&_27$$8, "strtr", &_6, 55, &_29$$8, _26$$8);
		zephir_check_call_status();
		zephir_concat_self(&output, _27$$8 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_30$$8, "get_parent_class", &_31, 165, variable);
		zephir_check_call_status();
		if (zephir_is_true(_30$$8)) {
			ZEPHIR_INIT_VAR(_32$$9);
			zephir_create_array(_32$$9, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_34$$9);
			ZVAL_STRING(_34$$9, "obj", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_33$$9, this_ptr, "getstyle", &_4, 0, _34$$9);
			zephir_check_temp_parameter(_34$$9);
			zephir_check_call_status();
			zephir_array_update_string(&_32$$9, SL(":style"), &_33$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_33$$9, "get_parent_class", &_31, 165, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_32$$9, SL(":parent"), &_33$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_VAR(_35$$9);
			ZVAL_STRING(&_35$$9, " <b style=':style'>extends</b> :parent", 0);
			ZEPHIR_CALL_FUNCTION(&_33$$9, "strtr", &_6, 55, &_35$$9, _32$$9);
			zephir_check_call_status();
			zephir_concat_self(&output, _33$$9 TSRMLS_CC);
		}
		zephir_concat_self_str(&output, SL(" (\n") TSRMLS_CC);
		_36$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_detailed"), PH_NOISY_CC);
		if (!(zephir_is_true(_36$$8))) {
			ZEPHIR_CALL_FUNCTION(&_37$$10, "get_object_vars", NULL, 24, variable);
			zephir_check_call_status();
			zephir_is_iterable(_37$$10, &_39$$10, &_38$$10, 0, 0, "phalcon/debug/dump.zep", 171);
			for (
			  ; zephir_hash_get_current_data_ex(_39$$10, (void**) &_40$$10, &_38$$10) == SUCCESS
			  ; zephir_hash_move_forward_ex(_39$$10, &_38$$10)
			) {
				ZEPHIR_GET_HMKEY(key, _39$$10, _38$$10);
				ZEPHIR_GET_HVALUE(value, _40$$10);
				ZEPHIR_SINIT_NVAR(_41$$11);
				ZVAL_LONG(&_41$$11, tab);
				ZEPHIR_CALL_FUNCTION(&_42$$11, "str_repeat", &_12, 133, space, &_41$$11);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_43$$11);
				zephir_create_array(_43$$11, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_45$$11);
				ZVAL_STRING(_45$$11, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_44$$11, this_ptr, "getstyle", &_4, 0, _45$$11);
				zephir_check_temp_parameter(_45$$11);
				zephir_check_call_status();
				zephir_array_update_string(&_43$$11, SL(":style"), &_44$$11, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_43$$11, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(_43$$11, SS(":type"), SL("public"), 1);
				ZEPHIR_SINIT_NVAR(_41$$11);
				ZVAL_STRING(&_41$$11, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_44$$11, "strtr", &_6, 55, &_41$$11, _43$$11);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_46$$11);
				ZEPHIR_CONCAT_VV(_46$$11, _42$$11, _44$$11);
				zephir_concat_self(&output, _46$$11 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_45$$11);
				ZVAL_STRING(_45$$11, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_48$$11);
				ZVAL_LONG(_48$$11, (tab + 1));
				ZEPHIR_CALL_METHOD(&_47$$11, this_ptr, "output", &_23, 164, value, _45$$11, _48$$11);
				zephir_check_temp_parameter(_45$$11);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_49$$11);
				ZEPHIR_CONCAT_VS(_49$$11, _47$$11, "\n");
				zephir_concat_self(&output, _49$$11 TSRMLS_CC);
			}
		} else {
			do {
				ZEPHIR_MAKE_REF(variable);
				ZEPHIR_CALL_FUNCTION(&attr, "each", &_50, 166, variable);
				ZEPHIR_UNREF(variable);
				zephir_check_call_status();
				if (!(zephir_is_true(attr))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(key);
				zephir_array_fetch_string(&key, attr, SL("key"), PH_NOISY, "phalcon/debug/dump.zep", 180 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(value);
				zephir_array_fetch_string(&value, attr, SL("value"), PH_NOISY, "phalcon/debug/dump.zep", 181 TSRMLS_CC);
				if (!(zephir_is_true(key))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(_51$$13);
				ZEPHIR_SINIT_NVAR(_52$$13);
				ZVAL_STRING(&_52$$13, "\\x00", 0);
				ZEPHIR_CALL_FUNCTION(&_53$$13, "ord", &_54, 134, &_52$$13);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_55$$13, "chr", &_56, 132, _53$$13);
				zephir_check_call_status();
				zephir_fast_explode(_51$$13, _55$$13, key, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(key, _51$$13);
				ZEPHIR_INIT_NVAR(type);
				ZVAL_STRING(type, "public", 1);
				if (zephir_array_isset_long(key, 1)) {
					ZEPHIR_INIT_NVAR(type);
					ZVAL_STRING(type, "private", 1);
					zephir_array_fetch_long(&_57$$16, key, 1, PH_NOISY | PH_READONLY, "phalcon/debug/dump.zep", 193 TSRMLS_CC);
					if (ZEPHIR_IS_STRING(_57$$16, "*")) {
						ZEPHIR_INIT_NVAR(type);
						ZVAL_STRING(type, "protected", 1);
					}
				}
				ZEPHIR_SINIT_NVAR(_52$$13);
				ZVAL_LONG(&_52$$13, tab);
				ZEPHIR_CALL_FUNCTION(&_58$$13, "str_repeat", &_12, 133, space, &_52$$13);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_59$$13);
				zephir_create_array(_59$$13, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_51$$13);
				ZVAL_STRING(_51$$13, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_60$$13, this_ptr, "getstyle", &_4, 0, _51$$13);
				zephir_check_temp_parameter(_51$$13);
				zephir_check_call_status();
				zephir_array_update_string(&_59$$13, SL(":style"), &_60$$13, PH_COPY | PH_SEPARATE);
				ZEPHIR_MAKE_REF(key);
				ZEPHIR_CALL_FUNCTION(&_60$$13, "end", &_61, 167, key);
				ZEPHIR_UNREF(key);
				zephir_check_call_status();
				zephir_array_update_string(&_59$$13, SL(":key"), &_60$$13, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_59$$13, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_SINIT_NVAR(_52$$13);
				ZVAL_STRING(&_52$$13, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_60$$13, "strtr", &_6, 55, &_52$$13, _59$$13);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_62$$13);
				ZEPHIR_CONCAT_VV(_62$$13, _58$$13, _60$$13);
				zephir_concat_self(&output, _62$$13 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_51$$13);
				ZVAL_STRING(_51$$13, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_64$$13);
				ZVAL_LONG(_64$$13, (tab + 1));
				ZEPHIR_CALL_METHOD(&_63$$13, this_ptr, "output", &_23, 164, value, _51$$13, _64$$13);
				zephir_check_temp_parameter(_51$$13);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_65$$13);
				ZEPHIR_CONCAT_VS(_65$$13, _63$$13, "\n");
				zephir_concat_self(&output, _65$$13 TSRMLS_CC);
			} while (zephir_is_true(attr));
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 168, variable);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_29$$8);
		ZVAL_LONG(&_29$$8, tab);
		ZEPHIR_CALL_FUNCTION(&_66$$8, "str_repeat", &_12, 133, space, &_29$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_67$$8);
		zephir_create_array(_67$$8, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_28$$8);
		ZVAL_STRING(_28$$8, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_68$$8, this_ptr, "getstyle", &_4, 0, _28$$8);
		zephir_check_temp_parameter(_28$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_67$$8, SL(":style"), &_68$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_28$$8);
		zephir_get_class(_28$$8, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_67$$8, SL(":class"), &_28$$8, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_67$$8, SS(":count"), zephir_fast_count_int(attr TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_29$$8);
		ZVAL_STRING(&_29$$8, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n", 0);
		ZEPHIR_CALL_FUNCTION(&_68$$8, "strtr", &_6, 55, &_29$$8, _67$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_69$$8);
		ZEPHIR_CONCAT_VV(_69$$8, _66$$8, _68$$8);
		zephir_concat_self(&output, _69$$8 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_28$$8);
		zephir_get_class(_28$$8, variable, 0 TSRMLS_CC);
		_70$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_methods"), PH_NOISY_CC);
		if (zephir_fast_in_array(_28$$8, _70$$8 TSRMLS_CC)) {
			ZEPHIR_SINIT_VAR(_71$$18);
			ZVAL_LONG(&_71$$18, tab);
			ZEPHIR_CALL_FUNCTION(&_72$$18, "str_repeat", &_12, 133, space, &_71$$18);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_73$$18);
			ZEPHIR_CONCAT_VS(_73$$18, _72$$18, "[already listed]\n");
			zephir_concat_self(&output, _73$$18 TSRMLS_CC);
		} else {
			zephir_is_iterable(attr, &_75$$19, &_74$$19, 0, 0, "phalcon/debug/dump.zep", 219);
			for (
			  ; zephir_hash_get_current_data_ex(_75$$19, (void**) &_76$$19, &_74$$19) == SUCCESS
			  ; zephir_hash_move_forward_ex(_75$$19, &_74$$19)
			) {
				ZEPHIR_GET_HVALUE(value, _76$$19);
				ZEPHIR_INIT_NVAR(_77$$20);
				zephir_get_class(_77$$20, variable, 0 TSRMLS_CC);
				zephir_update_property_array_append(this_ptr, SL("_methods"), _77$$20 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(value, "__construct")) {
					ZEPHIR_SINIT_NVAR(_78$$21);
					ZVAL_LONG(&_78$$21, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_79$$21, "str_repeat", &_12, 133, space, &_78$$21);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_80$$21);
					zephir_create_array(_80$$21, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_82$$21);
					ZVAL_STRING(_82$$21, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_81$$21, this_ptr, "getstyle", &_4, 0, _82$$21);
					zephir_check_temp_parameter(_82$$21);
					zephir_check_call_status();
					zephir_array_update_string(&_80$$21, SL(":style"), &_81$$21, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_80$$21, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_78$$21);
					ZVAL_STRING(&_78$$21, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n", 0);
					ZEPHIR_CALL_FUNCTION(&_81$$21, "strtr", &_6, 55, &_78$$21, _80$$21);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_83$$21);
					ZEPHIR_CONCAT_VV(_83$$21, _79$$21, _81$$21);
					zephir_concat_self(&output, _83$$21 TSRMLS_CC);
				} else {
					ZEPHIR_SINIT_NVAR(_84$$22);
					ZVAL_LONG(&_84$$22, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_85$$22, "str_repeat", &_12, 133, space, &_84$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_86$$22);
					zephir_create_array(_86$$22, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_88$$22);
					ZVAL_STRING(_88$$22, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_87$$22, this_ptr, "getstyle", &_4, 0, _88$$22);
					zephir_check_temp_parameter(_88$$22);
					zephir_check_call_status();
					zephir_array_update_string(&_86$$22, SL(":style"), &_87$$22, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_86$$22, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_84$$22);
					ZVAL_STRING(&_84$$22, "-><span style=':style'>:method</span>();\n", 0);
					ZEPHIR_CALL_FUNCTION(&_87$$22, "strtr", &_6, 55, &_84$$22, _86$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_89$$22);
					ZEPHIR_CONCAT_VV(_89$$22, _85$$22, _87$$22);
					zephir_concat_self(&output, _89$$22 TSRMLS_CC);
				}
			}
			ZEPHIR_SINIT_VAR(_90$$19);
			ZVAL_LONG(&_90$$19, tab);
			ZEPHIR_CALL_FUNCTION(&_91$$19, "str_repeat", &_12, 133, space, &_90$$19);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_92$$19);
			ZEPHIR_CONCAT_VS(_92$$19, _91$$19, ")\n");
			zephir_concat_self(&output, _92$$19 TSRMLS_CC);
		}
		ZEPHIR_SINIT_NVAR(_29$$8);
		ZVAL_LONG(&_29$$8, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_93$$8, "str_repeat", &_12, 133, space, &_29$$8);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _93$$8, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(_94$$23);
		zephir_create_array(_94$$23, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_96$$23);
		ZVAL_STRING(_96$$23, "int", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_95$$23, this_ptr, "getstyle", &_4, 0, _96$$23);
		zephir_check_temp_parameter(_96$$23);
		zephir_check_call_status();
		zephir_array_update_string(&_94$$23, SL(":style"), &_95$$23, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_94$$23, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_97$$23);
		ZVAL_STRING(&_97$$23, "<b style=':style'>Integer</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_95$$23, "strtr", &_6, 55, &_97$$23, _94$$23);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _95$$23);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_98, "is_float", NULL, 169, variable);
	zephir_check_call_status();
	if (zephir_is_true(_98)) {
		ZEPHIR_INIT_VAR(_99$$24);
		zephir_create_array(_99$$24, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_101$$24);
		ZVAL_STRING(_101$$24, "float", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_100$$24, this_ptr, "getstyle", &_4, 0, _101$$24);
		zephir_check_temp_parameter(_101$$24);
		zephir_check_call_status();
		zephir_array_update_string(&_99$$24, SL(":style"), &_100$$24, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_99$$24, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_102$$24);
		ZVAL_STRING(&_102$$24, "<b style=':style'>Float</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_100$$24, "strtr", &_6, 55, &_102$$24, _99$$24);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _100$$24);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(_103$$25);
		zephir_create_array(_103$$25, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_105$$25);
		ZVAL_STRING(_105$$25, "num", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_104$$25, this_ptr, "getstyle", &_4, 0, _105$$25);
		zephir_check_temp_parameter(_105$$25);
		zephir_check_call_status();
		zephir_array_update_string(&_103$$25, SL(":style"), &_104$$25, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_103$$25, SS(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_103$$25, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_106$$25);
		ZVAL_STRING(&_106$$25, "<b style=':style'>Numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_CALL_FUNCTION(&_104$$25, "strtr", &_6, 55, &_106$$25, _103$$25);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _104$$25);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(_107$$26);
		zephir_create_array(_107$$26, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_109$$26);
		ZVAL_STRING(_109$$26, "str", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_108$$26, this_ptr, "getstyle", &_4, 0, _109$$26);
		zephir_check_temp_parameter(_109$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_107$$26, SL(":style"), &_108$$26, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_107$$26, SS(":length"), zephir_fast_strlen_ev(variable));
		ZEPHIR_SINIT_VAR(_110$$26);
		ZVAL_LONG(&_110$$26, 4);
		ZEPHIR_SINIT_VAR(_111$$26);
		ZVAL_STRING(&_111$$26, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_108$$26, "htmlentities", NULL, 149, variable, &_110$$26, &_111$$26);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_112$$26, "nl2br", NULL, 170, _108$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_107$$26, SL(":var"), &_112$$26, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_110$$26);
		ZVAL_STRING(&_110$$26, "<b style=':style'>String</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_CALL_FUNCTION(&_112$$26, "strtr", &_6, 55, &_110$$26, _107$$26);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _112$$26);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_BOOL) {
		ZEPHIR_INIT_VAR(_113$$27);
		zephir_create_array(_113$$27, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_115$$27);
		ZVAL_STRING(_115$$27, "bool", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_114$$27, this_ptr, "getstyle", &_4, 0, _115$$27);
		zephir_check_temp_parameter(_115$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_113$$27, SL(":style"), &_114$$27, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_116$$27);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(_116$$27);
			ZVAL_STRING(_116$$27, "TRUE", 1);
		} else {
			ZEPHIR_INIT_NVAR(_116$$27);
			ZVAL_STRING(_116$$27, "FALSE", 1);
		}
		zephir_array_update_string(&_113$$27, SL(":var"), &_116$$27, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_117$$27);
		ZVAL_STRING(&_117$$27, "<b style=':style'>Boolean</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_114$$27, "strtr", &_6, 55, &_117$$27, _113$$27);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _114$$27);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(_118$$28);
		zephir_create_array(_118$$28, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_120$$28);
		ZVAL_STRING(_120$$28, "null", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_119$$28, this_ptr, "getstyle", &_4, 0, _120$$28);
		zephir_check_temp_parameter(_120$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_118$$28, SL(":style"), &_119$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_121$$28);
		ZVAL_STRING(&_121$$28, "<b style=':style'>NULL</b>", 0);
		ZEPHIR_CALL_FUNCTION(&_119$$28, "strtr", &_6, 55, &_121$$28, _118$$28);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _119$$28);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_122);
	zephir_create_array(_122, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_124);
	ZVAL_STRING(_124, "other", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_123, this_ptr, "getstyle", &_4, 0, _124);
	zephir_check_temp_parameter(_124);
	zephir_check_call_status();
	zephir_array_update_string(&_122, SL(":style"), &_123, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_122, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_VAR(_125);
	ZVAL_STRING(&_125, "(<span style=':style'>:var</span>)", 0);
	ZEPHIR_CALL_FUNCTION(&_123, "strtr", &_6, 55, &_125, _122);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, output, _123);
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

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;
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
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 55, &_3, _0);
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

	HashTable *_2;
	HashPosition _1;
	zval *key = NULL, *value = NULL, *output = NULL, *_0 = NULL, **_3, *_4$$3 = NULL, *_5$$3 = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(output);
	ZVAL_STRING(output, "", 1);
	ZEPHIR_CALL_FUNCTION(&_0, "func_get_args", NULL, 163);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/debug/dump.zep", 290);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		ZEPHIR_INIT_LNVAR(_5$$3);
		ZEPHIR_CONCAT_SV(_5$$3, "var ", key);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "one", &_6, 0, value, _5$$3);
		zephir_check_call_status();
		zephir_concat_self(&output, _4$$3 TSRMLS_CC);
	}
	RETURN_CCTOR(output);

}

/**
 * Returns an JSON string of information about a single variable.
 *
 * <code>
 *    $foo = ["key" => "value"];
 *    echo (new \Phalcon\Debug\Dump())->toJson($foo);
 *    $foo = new stdClass();
 *    $foo->bar = 'buz';
 *    echo (new \Phalcon\Debug\Dump())->toJson($foo);
 * </code>
 *
 * @param mixed variable
 */
PHP_METHOD(Phalcon_Debug_Dump, toJson) {

	zval *variable, _0;

	zephir_fetch_params(0, 1, 0, &variable);



	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, ((128 | 64) | 256));
	zephir_json_encode(return_value, &(return_value), variable, zephir_get_intval(&_0)  TSRMLS_CC);
	return;

}

