
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

	phalcon_debug_dump_ce->create_object = zephir_init_properties_Phalcon_Debug_Dump;
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
	zval *styles_param = NULL, *detailed_param = NULL;
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_debug_exception_ce, "The styles must be an array", "phalcon/debug/dump.zep", 58);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstyles", NULL, 0, styles);
	zephir_check_call_status();
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
	ZEPHIR_CALL_FUNCTION(&_2, "func_get_args", NULL, 172);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_debug_exception_ce, "The styles must be an array", "phalcon/debug/dump.zep", 102);
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
	HashTable *_8$$4, *_42$$11, *_76$$20;
	HashPosition _7$$4, _41$$11, _75$$20;
	zval *_123, *_1$$4, *_13$$5 = NULL, *_26$$8, *_68$$8, *_32$$9, *_46$$12 = NULL, *_60$$14 = NULL, *_81$$22 = NULL, *_87$$23 = NULL, *_95$$24, *_100$$25, *_104$$26, *_108$$27, *_114$$28, *_119$$29;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_12 = NULL, *_23 = NULL, *_31 = NULL, *_53 = NULL, *_57 = NULL, *_62 = NULL;
	int tab, ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, *_0$$3;
	zval *variable, *name_param = NULL, *tab_param = NULL, *key = NULL, *value = NULL, *output = NULL, *space = NULL, *type = NULL, *attr = NULL, *_99 = NULL, *_124 = NULL, *_125, _126, *_2$$4 = NULL, *_3$$4, _5$$4 = zval_used_for_init, **_9$$4, *_25$$4 = NULL, _10$$5 = zval_used_for_init, *_11$$5 = NULL, *_14$$5 = NULL, *_15$$5 = NULL, *_16$$5 = NULL, *_20$$7 = NULL, *_21$$7 = NULL, *_22$$7 = NULL, *_24$$7 = NULL, *_27$$8 = NULL, *_28$$8 = NULL, _29$$8 = zval_used_for_init, *_30$$8 = NULL, *_36$$8, *_67$$8 = NULL, *_69$$8 = NULL, *_70$$8, *_71$$8, *_94$$8 = NULL, *_33$$9 = NULL, *_34$$9, _35$$9, _37$$10, *_38$$10 = NULL, *_39$$10, *_40$$11 = NULL, **_43$$11, _44$$12 = zval_used_for_init, *_45$$12 = NULL, *_47$$12 = NULL, *_48$$12 = NULL, *_49$$12 = NULL, *_50$$12 = NULL, *_51$$12 = NULL, *_52$$12 = NULL, *_54$$14 = NULL, _55$$14 = zval_used_for_init, *_56$$14 = NULL, *_59$$14 = NULL, *_61$$14 = NULL, *_63$$14 = NULL, *_64$$14 = NULL, *_65$$14 = NULL, *_66$$14 = NULL, *_58$$17, _72$$19, *_73$$19 = NULL, *_74$$19, **_77$$20, _91$$20, *_92$$20 = NULL, *_93$$20, *_78$$21 = NULL, _79$$22 = zval_used_for_init, *_80$$22 = NULL, *_82$$22 = NULL, *_83$$22 = NULL, *_84$$22 = NULL, _85$$23 = zval_used_for_init, *_86$$23 = NULL, *_88$$23 = NULL, *_89$$23 = NULL, *_90$$23 = NULL, *_96$$24 = NULL, *_97$$24, _98$$24, *_101$$25 = NULL, *_102$$25, _103$$25, *_105$$26 = NULL, *_106$$26, _107$$26, *_109$$27 = NULL, *_110$$27, _111$$27 = zval_used_for_init, _112$$27, *_113$$27 = NULL, *_115$$28 = NULL, *_116$$28, *_117$$28 = NULL, _118$$28, *_120$$29 = NULL, *_121$$29, _122$$29;

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
		ZEPHIR_CALL_FUNCTION(&_2$$4, "strtr", &_6, 26, &_5$$4, _1$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, _2$$4 TSRMLS_CC);
		zephir_is_iterable(variable, &_8$$4, &_7$$4, 0, 0, "phalcon/debug/dump.zep", 156);
		for (
		  ; zephir_hash_get_current_data_ex(_8$$4, (void**) &_9$$4, &_7$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_8$$4, &_7$$4)
		) {
			ZEPHIR_GET_HMKEY(key, _8$$4, _7$$4);
			ZEPHIR_GET_HVALUE(value, _9$$4);
			ZEPHIR_SINIT_NVAR(_10$$5);
			ZVAL_LONG(&_10$$5, tab);
			ZEPHIR_CALL_FUNCTION(&_11$$5, "str_repeat", &_12, 140, space, &_10$$5);
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
			ZEPHIR_CALL_FUNCTION(&_14$$5, "strtr", &_6, 26, &_10$$5, _13$$5);
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
				ZEPHIR_CALL_METHOD(&_20$$7, this_ptr, "output", &_23, 173, value, _21$$7, _22$$7);
				zephir_check_temp_parameter(_21$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_24$$7);
				ZEPHIR_CONCAT_VS(_24$$7, _20$$7, "\n");
				zephir_concat_self(&output, _24$$7 TSRMLS_CC);
			}
		}
		ZEPHIR_SINIT_NVAR(_5$$4);
		ZVAL_LONG(&_5$$4, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_25$$4, "str_repeat", &_12, 140, space, &_5$$4);
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
		ZEPHIR_CALL_FUNCTION(&_27$$8, "strtr", &_6, 26, &_29$$8, _26$$8);
		zephir_check_call_status();
		zephir_concat_self(&output, _27$$8 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_30$$8, "get_parent_class", &_31, 174, variable);
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
			ZEPHIR_CALL_FUNCTION(&_33$$9, "get_parent_class", &_31, 174, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_32$$9, SL(":parent"), &_33$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_VAR(_35$$9);
			ZVAL_STRING(&_35$$9, " <b style=':style'>extends</b> :parent", 0);
			ZEPHIR_CALL_FUNCTION(&_33$$9, "strtr", &_6, 26, &_35$$9, _32$$9);
			zephir_check_call_status();
			zephir_concat_self(&output, _33$$9 TSRMLS_CC);
		}
		zephir_concat_self_str(&output, SL(" (\n") TSRMLS_CC);
		_36$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_detailed"), PH_NOISY_CC);
		if (zephir_instance_of_ev(variable, phalcon_di_ce TSRMLS_CC)) {
			ZEPHIR_SINIT_VAR(_37$$10);
			ZVAL_LONG(&_37$$10, tab);
			ZEPHIR_CALL_FUNCTION(&_38$$10, "str_repeat", &_12, 140, space, &_37$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_39$$10);
			ZEPHIR_CONCAT_VS(_39$$10, _38$$10, "[skipped]\n");
			zephir_concat_self(&output, _39$$10 TSRMLS_CC);
		} else if (!(zephir_is_true(_36$$8))) {
			ZEPHIR_CALL_FUNCTION(&_40$$11, "get_object_vars", NULL, 21, variable);
			zephir_check_call_status();
			zephir_is_iterable(_40$$11, &_42$$11, &_41$$11, 0, 0, "phalcon/debug/dump.zep", 177);
			for (
			  ; zephir_hash_get_current_data_ex(_42$$11, (void**) &_43$$11, &_41$$11) == SUCCESS
			  ; zephir_hash_move_forward_ex(_42$$11, &_41$$11)
			) {
				ZEPHIR_GET_HMKEY(key, _42$$11, _41$$11);
				ZEPHIR_GET_HVALUE(value, _43$$11);
				ZEPHIR_SINIT_NVAR(_44$$12);
				ZVAL_LONG(&_44$$12, tab);
				ZEPHIR_CALL_FUNCTION(&_45$$12, "str_repeat", &_12, 140, space, &_44$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_46$$12);
				zephir_create_array(_46$$12, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_48$$12);
				ZVAL_STRING(_48$$12, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_47$$12, this_ptr, "getstyle", &_4, 0, _48$$12);
				zephir_check_temp_parameter(_48$$12);
				zephir_check_call_status();
				zephir_array_update_string(&_46$$12, SL(":style"), &_47$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_46$$12, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(_46$$12, SS(":type"), SL("public"), 1);
				ZEPHIR_SINIT_NVAR(_44$$12);
				ZVAL_STRING(&_44$$12, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_47$$12, "strtr", &_6, 26, &_44$$12, _46$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_49$$12);
				ZEPHIR_CONCAT_VV(_49$$12, _45$$12, _47$$12);
				zephir_concat_self(&output, _49$$12 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_48$$12);
				ZVAL_STRING(_48$$12, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_51$$12);
				ZVAL_LONG(_51$$12, (tab + 1));
				ZEPHIR_CALL_METHOD(&_50$$12, this_ptr, "output", &_23, 173, value, _48$$12, _51$$12);
				zephir_check_temp_parameter(_48$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_52$$12);
				ZEPHIR_CONCAT_VS(_52$$12, _50$$12, "\n");
				zephir_concat_self(&output, _52$$12 TSRMLS_CC);
			}
		} else {
			do {
				ZEPHIR_MAKE_REF(variable);
				ZEPHIR_CALL_FUNCTION(&attr, "each", &_53, 175, variable);
				ZEPHIR_UNREF(variable);
				zephir_check_call_status();
				if (!(zephir_is_true(attr))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(key);
				zephir_array_fetch_string(&key, attr, SL("key"), PH_NOISY, "phalcon/debug/dump.zep", 187 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(value);
				zephir_array_fetch_string(&value, attr, SL("value"), PH_NOISY, "phalcon/debug/dump.zep", 188 TSRMLS_CC);
				if (!(zephir_is_true(key))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(_54$$14);
				ZEPHIR_SINIT_NVAR(_55$$14);
				ZVAL_LONG(&_55$$14, 0);
				ZEPHIR_CALL_FUNCTION(&_56$$14, "chr", &_57, 139, &_55$$14);
				zephir_check_call_status();
				zephir_fast_explode(_54$$14, _56$$14, key, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(key, _54$$14);
				ZEPHIR_INIT_NVAR(type);
				ZVAL_STRING(type, "public", 1);
				if (zephir_array_isset_long(key, 1)) {
					ZEPHIR_INIT_NVAR(type);
					ZVAL_STRING(type, "private", 1);
					zephir_array_fetch_long(&_58$$17, key, 1, PH_NOISY | PH_READONLY, "phalcon/debug/dump.zep", 200 TSRMLS_CC);
					if (ZEPHIR_IS_STRING(_58$$17, "*")) {
						ZEPHIR_INIT_NVAR(type);
						ZVAL_STRING(type, "protected", 1);
					}
				}
				ZEPHIR_SINIT_NVAR(_55$$14);
				ZVAL_LONG(&_55$$14, tab);
				ZEPHIR_CALL_FUNCTION(&_59$$14, "str_repeat", &_12, 140, space, &_55$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_60$$14);
				zephir_create_array(_60$$14, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_54$$14);
				ZVAL_STRING(_54$$14, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_61$$14, this_ptr, "getstyle", &_4, 0, _54$$14);
				zephir_check_temp_parameter(_54$$14);
				zephir_check_call_status();
				zephir_array_update_string(&_60$$14, SL(":style"), &_61$$14, PH_COPY | PH_SEPARATE);
				ZEPHIR_MAKE_REF(key);
				ZEPHIR_CALL_FUNCTION(&_61$$14, "end", &_62, 176, key);
				ZEPHIR_UNREF(key);
				zephir_check_call_status();
				zephir_array_update_string(&_60$$14, SL(":key"), &_61$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_60$$14, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_SINIT_NVAR(_55$$14);
				ZVAL_STRING(&_55$$14, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_61$$14, "strtr", &_6, 26, &_55$$14, _60$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_63$$14);
				ZEPHIR_CONCAT_VV(_63$$14, _59$$14, _61$$14);
				zephir_concat_self(&output, _63$$14 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_54$$14);
				ZVAL_STRING(_54$$14, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_65$$14);
				ZVAL_LONG(_65$$14, (tab + 1));
				ZEPHIR_CALL_METHOD(&_64$$14, this_ptr, "output", &_23, 173, value, _54$$14, _65$$14);
				zephir_check_temp_parameter(_54$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_66$$14);
				ZEPHIR_CONCAT_VS(_66$$14, _64$$14, "\n");
				zephir_concat_self(&output, _66$$14 TSRMLS_CC);
			} while (zephir_is_true(attr));
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 177, variable);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_29$$8);
		ZVAL_LONG(&_29$$8, tab);
		ZEPHIR_CALL_FUNCTION(&_67$$8, "str_repeat", &_12, 140, space, &_29$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_68$$8);
		zephir_create_array(_68$$8, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_28$$8);
		ZVAL_STRING(_28$$8, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_69$$8, this_ptr, "getstyle", &_4, 0, _28$$8);
		zephir_check_temp_parameter(_28$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_68$$8, SL(":style"), &_69$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_28$$8);
		zephir_get_class(_28$$8, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_68$$8, SL(":class"), &_28$$8, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_68$$8, SS(":count"), zephir_fast_count_int(attr TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_29$$8);
		ZVAL_STRING(&_29$$8, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n", 0);
		ZEPHIR_CALL_FUNCTION(&_69$$8, "strtr", &_6, 26, &_29$$8, _68$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_70$$8);
		ZEPHIR_CONCAT_VV(_70$$8, _67$$8, _69$$8);
		zephir_concat_self(&output, _70$$8 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_28$$8);
		zephir_get_class(_28$$8, variable, 0 TSRMLS_CC);
		_71$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_methods"), PH_NOISY_CC);
		if (zephir_fast_in_array(_28$$8, _71$$8 TSRMLS_CC)) {
			ZEPHIR_SINIT_VAR(_72$$19);
			ZVAL_LONG(&_72$$19, tab);
			ZEPHIR_CALL_FUNCTION(&_73$$19, "str_repeat", &_12, 140, space, &_72$$19);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_74$$19);
			ZEPHIR_CONCAT_VS(_74$$19, _73$$19, "[already listed]\n");
			zephir_concat_self(&output, _74$$19 TSRMLS_CC);
		} else {
			zephir_is_iterable(attr, &_76$$20, &_75$$20, 0, 0, "phalcon/debug/dump.zep", 226);
			for (
			  ; zephir_hash_get_current_data_ex(_76$$20, (void**) &_77$$20, &_75$$20) == SUCCESS
			  ; zephir_hash_move_forward_ex(_76$$20, &_75$$20)
			) {
				ZEPHIR_GET_HVALUE(value, _77$$20);
				ZEPHIR_INIT_NVAR(_78$$21);
				zephir_get_class(_78$$21, variable, 0 TSRMLS_CC);
				zephir_update_property_array_append(this_ptr, SL("_methods"), _78$$21 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(value, "__construct")) {
					ZEPHIR_SINIT_NVAR(_79$$22);
					ZVAL_LONG(&_79$$22, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_80$$22, "str_repeat", &_12, 140, space, &_79$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_81$$22);
					zephir_create_array(_81$$22, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_83$$22);
					ZVAL_STRING(_83$$22, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_82$$22, this_ptr, "getstyle", &_4, 0, _83$$22);
					zephir_check_temp_parameter(_83$$22);
					zephir_check_call_status();
					zephir_array_update_string(&_81$$22, SL(":style"), &_82$$22, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_81$$22, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_79$$22);
					ZVAL_STRING(&_79$$22, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n", 0);
					ZEPHIR_CALL_FUNCTION(&_82$$22, "strtr", &_6, 26, &_79$$22, _81$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_84$$22);
					ZEPHIR_CONCAT_VV(_84$$22, _80$$22, _82$$22);
					zephir_concat_self(&output, _84$$22 TSRMLS_CC);
				} else {
					ZEPHIR_SINIT_NVAR(_85$$23);
					ZVAL_LONG(&_85$$23, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_86$$23, "str_repeat", &_12, 140, space, &_85$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_87$$23);
					zephir_create_array(_87$$23, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_89$$23);
					ZVAL_STRING(_89$$23, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_88$$23, this_ptr, "getstyle", &_4, 0, _89$$23);
					zephir_check_temp_parameter(_89$$23);
					zephir_check_call_status();
					zephir_array_update_string(&_87$$23, SL(":style"), &_88$$23, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_87$$23, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_85$$23);
					ZVAL_STRING(&_85$$23, "-><span style=':style'>:method</span>();\n", 0);
					ZEPHIR_CALL_FUNCTION(&_88$$23, "strtr", &_6, 26, &_85$$23, _87$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_90$$23);
					ZEPHIR_CONCAT_VV(_90$$23, _86$$23, _88$$23);
					zephir_concat_self(&output, _90$$23 TSRMLS_CC);
				}
			}
			ZEPHIR_SINIT_VAR(_91$$20);
			ZVAL_LONG(&_91$$20, tab);
			ZEPHIR_CALL_FUNCTION(&_92$$20, "str_repeat", &_12, 140, space, &_91$$20);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_93$$20);
			ZEPHIR_CONCAT_VS(_93$$20, _92$$20, ")\n");
			zephir_concat_self(&output, _93$$20 TSRMLS_CC);
		}
		ZEPHIR_SINIT_NVAR(_29$$8);
		ZVAL_LONG(&_29$$8, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_94$$8, "str_repeat", &_12, 140, space, &_29$$8);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _94$$8, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(_95$$24);
		zephir_create_array(_95$$24, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_97$$24);
		ZVAL_STRING(_97$$24, "int", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_96$$24, this_ptr, "getstyle", &_4, 0, _97$$24);
		zephir_check_temp_parameter(_97$$24);
		zephir_check_call_status();
		zephir_array_update_string(&_95$$24, SL(":style"), &_96$$24, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_95$$24, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_98$$24);
		ZVAL_STRING(&_98$$24, "<b style=':style'>Integer</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_96$$24, "strtr", &_6, 26, &_98$$24, _95$$24);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _96$$24);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_99, "is_float", NULL, 178, variable);
	zephir_check_call_status();
	if (zephir_is_true(_99)) {
		ZEPHIR_INIT_VAR(_100$$25);
		zephir_create_array(_100$$25, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_102$$25);
		ZVAL_STRING(_102$$25, "float", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_101$$25, this_ptr, "getstyle", &_4, 0, _102$$25);
		zephir_check_temp_parameter(_102$$25);
		zephir_check_call_status();
		zephir_array_update_string(&_100$$25, SL(":style"), &_101$$25, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_100$$25, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_103$$25);
		ZVAL_STRING(&_103$$25, "<b style=':style'>Float</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_101$$25, "strtr", &_6, 26, &_103$$25, _100$$25);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _101$$25);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(_104$$26);
		zephir_create_array(_104$$26, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_106$$26);
		ZVAL_STRING(_106$$26, "num", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_105$$26, this_ptr, "getstyle", &_4, 0, _106$$26);
		zephir_check_temp_parameter(_106$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_104$$26, SL(":style"), &_105$$26, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_104$$26, SS(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_104$$26, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_107$$26);
		ZVAL_STRING(&_107$$26, "<b style=':style'>Numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_CALL_FUNCTION(&_105$$26, "strtr", &_6, 26, &_107$$26, _104$$26);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _105$$26);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(_108$$27);
		zephir_create_array(_108$$27, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_110$$27);
		ZVAL_STRING(_110$$27, "str", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_109$$27, this_ptr, "getstyle", &_4, 0, _110$$27);
		zephir_check_temp_parameter(_110$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_108$$27, SL(":style"), &_109$$27, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_108$$27, SS(":length"), zephir_fast_strlen_ev(variable));
		ZEPHIR_SINIT_VAR(_111$$27);
		ZVAL_LONG(&_111$$27, 4);
		ZEPHIR_SINIT_VAR(_112$$27);
		ZVAL_STRING(&_112$$27, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_109$$27, "htmlentities", NULL, 159, variable, &_111$$27, &_112$$27);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_113$$27, "nl2br", NULL, 179, _109$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_108$$27, SL(":var"), &_113$$27, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_111$$27);
		ZVAL_STRING(&_111$$27, "<b style=':style'>String</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_CALL_FUNCTION(&_113$$27, "strtr", &_6, 26, &_111$$27, _108$$27);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _113$$27);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_BOOL) {
		ZEPHIR_INIT_VAR(_114$$28);
		zephir_create_array(_114$$28, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_116$$28);
		ZVAL_STRING(_116$$28, "bool", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_115$$28, this_ptr, "getstyle", &_4, 0, _116$$28);
		zephir_check_temp_parameter(_116$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_114$$28, SL(":style"), &_115$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_117$$28);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(_117$$28);
			ZVAL_STRING(_117$$28, "TRUE", 1);
		} else {
			ZEPHIR_INIT_NVAR(_117$$28);
			ZVAL_STRING(_117$$28, "FALSE", 1);
		}
		zephir_array_update_string(&_114$$28, SL(":var"), &_117$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_118$$28);
		ZVAL_STRING(&_118$$28, "<b style=':style'>Boolean</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_115$$28, "strtr", &_6, 26, &_118$$28, _114$$28);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _115$$28);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(_119$$29);
		zephir_create_array(_119$$29, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_121$$29);
		ZVAL_STRING(_121$$29, "null", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_120$$29, this_ptr, "getstyle", &_4, 0, _121$$29);
		zephir_check_temp_parameter(_121$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_119$$29, SL(":style"), &_120$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_122$$29);
		ZVAL_STRING(&_122$$29, "<b style=':style'>NULL</b>", 0);
		ZEPHIR_CALL_FUNCTION(&_120$$29, "strtr", &_6, 26, &_122$$29, _119$$29);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _120$$29);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_123);
	zephir_create_array(_123, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_125);
	ZVAL_STRING(_125, "other", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_124, this_ptr, "getstyle", &_4, 0, _125);
	zephir_check_temp_parameter(_125);
	zephir_check_call_status();
	zephir_array_update_string(&_123, SL(":style"), &_124, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_123, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_VAR(_126);
	ZVAL_STRING(&_126, "(<span style=':style'>:var</span>)", 0);
	ZEPHIR_CALL_FUNCTION(&_124, "strtr", &_6, 26, &_126, _123);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, output, _124);
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
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 26, &_3, _0);
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
	ZEPHIR_CALL_FUNCTION(&_0, "func_get_args", NULL, 172);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/debug/dump.zep", 297);
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

zend_object_value zephir_init_properties_Phalcon_Debug_Dump(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_methods"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("_methods"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

