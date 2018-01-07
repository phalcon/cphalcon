
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/main.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * Phalcon\Debug\Dump
 *
 * Dumps information about a variable(s)
 *
 * <code>
 * $foo = 123;
 *
 * echo (new \Phalcon\Debug\Dump())->variable($foo, "foo");
 * </code>
 *
 * <code>
 * $foo = "string";
 * $bar = ["key" => "value"];
 * $baz = new stdClass();
 *
 * echo (new \Phalcon\Debug\Dump())->variables($foo, $bar, $baz);
 * </code>
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

	

	RETURN_MEMBER(getThis(), "_detailed");

}

PHP_METHOD(Phalcon_Debug_Dump, setDetailed) {

	zval *detailed;

	zephir_fetch_params(0, 1, 0, &detailed);



	zephir_update_property_this(getThis(), SL("_detailed"), detailed TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Phalcon\Debug\Dump constructor
 *
 * @param boolean detailed debug object's private and protected properties
 */
PHP_METHOD(Phalcon_Debug_Dump, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool detailed;
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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstyles", NULL, 0, styles);
	zephir_check_call_status();
	if (detailed) {
		zephir_update_property_this(getThis(), SL("_detailed"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_detailed"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
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

	zval *_1 = NULL;
	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "variables", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	zephir_get_args(_1 TSRMLS_CC);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _0, _1);
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

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
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

	zval *styles_param = NULL, *defaultStyles = NULL, *_0;
	zval *styles = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &styles_param);

	if (!styles_param) {
		ZEPHIR_INIT_VAR(styles);
		array_init(styles);
	} else {
		zephir_get_arrval(styles, styles_param);
	}


	if (1 == 0) {
		ZEPHIR_INIT_NVAR(styles);
		array_init(styles);
	}
	if (1 != 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_debug_exception_ce, "The styles must be an array", "phalcon/debug/dump.zep", 101);
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
	zephir_update_property_this(getThis(), SL("_styles"), _0 TSRMLS_CC);
	RETURN_MM_MEMBER(getThis(), "_styles");

}

/**
 * Alias of variable() method
 */
PHP_METHOD(Phalcon_Debug_Dump, one) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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

	zend_bool _15$$5, _16$$5, _17$$5;
	HashTable *_6$$4, *_39$$11, *_73$$20;
	HashPosition _5$$4, _38$$11, _72$$20;
	zval *_120, *_1$$4, *_11$$5 = NULL, *_24$$8, *_65$$8, *_29$$9, *_43$$12 = NULL, *_57$$14 = NULL, *_78$$22 = NULL, *_84$$23 = NULL, *_92$$24, *_97$$25, *_101$$26, *_105$$27, *_111$$28, *_116$$29;
	zephir_fcall_cache_entry *_10 = NULL, *_21 = NULL, *_50 = NULL, *_54 = NULL, *_59 = NULL;
	zend_long tab, ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, *_0$$3;
	zval *variable, *name_param = NULL, *tab_param = NULL, *key = NULL, *value = NULL, *output = NULL, *space = NULL, *type = NULL, *attr = NULL, *_96 = NULL, *_121 = NULL, *_122, _123, *_2$$4 = NULL, *_3$$4, _4$$4 = zval_used_for_init, **_7$$4, *_23$$4 = NULL, _8$$5 = zval_used_for_init, *_9$$5 = NULL, *_12$$5 = NULL, *_13$$5 = NULL, *_14$$5 = NULL, *_18$$7 = NULL, *_19$$7 = NULL, *_20$$7 = NULL, *_22$$7 = NULL, *_25$$8 = NULL, *_26$$8 = NULL, _27$$8 = zval_used_for_init, *_28$$8 = NULL, *_33$$8, *_64$$8 = NULL, *_66$$8 = NULL, *_67$$8, *_68$$8, *_91$$8 = NULL, *_30$$9 = NULL, *_31$$9, _32$$9, _34$$10, *_35$$10 = NULL, *_36$$10, *_37$$11 = NULL, **_40$$11, _41$$12 = zval_used_for_init, *_42$$12 = NULL, *_44$$12 = NULL, *_45$$12 = NULL, *_46$$12 = NULL, *_47$$12 = NULL, *_48$$12 = NULL, *_49$$12 = NULL, *_51$$14 = NULL, _52$$14 = zval_used_for_init, *_53$$14 = NULL, *_56$$14 = NULL, *_58$$14 = NULL, *_60$$14 = NULL, *_61$$14 = NULL, *_62$$14 = NULL, *_63$$14 = NULL, *_55$$17, _69$$19, *_70$$19 = NULL, *_71$$19, **_74$$20, _88$$20, *_89$$20 = NULL, *_90$$20, *_75$$21 = NULL, _76$$22 = zval_used_for_init, *_77$$22 = NULL, *_79$$22 = NULL, *_80$$22 = NULL, *_81$$22 = NULL, _82$$23 = zval_used_for_init, *_83$$23 = NULL, *_85$$23 = NULL, *_86$$23 = NULL, *_87$$23 = NULL, *_93$$24 = NULL, *_94$$24, _95$$24, *_98$$25 = NULL, *_99$$25, _100$$25, *_102$$26 = NULL, *_103$$26, _104$$26, *_106$$27 = NULL, *_107$$27, _108$$27 = zval_used_for_init, _109$$27, *_110$$27 = NULL, *_112$$28 = NULL, *_113$$28, *_114$$28 = NULL, _115$$28, *_117$$29 = NULL, *_118$$29, _119$$29;

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
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getstyle", NULL, 0, _3$$4);
		zephir_check_temp_parameter(_3$$4);
		zephir_check_call_status();
		zephir_array_update_string(&_1$$4, SL(":style"), &_2$$4, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_1$$4, SS(":count"), zephir_fast_count_int(variable TSRMLS_CC));
		ZEPHIR_SINIT_VAR(_4$$4);
		ZVAL_STRING(&_4$$4, "<b style =':style'>Array</b> (<span style =':style'>:count</span>) (\n", 0);
		ZEPHIR_CALL_FUNCTION(&_2$$4, "strtr", NULL, 27, &_4$$4, _1$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, _2$$4 TSRMLS_CC);
		zephir_is_iterable(variable, &_6$$4, &_5$$4, 0, 0, "phalcon/debug/dump.zep", 161);
		for (
		  ; zend_hash_get_current_data_ex(_6$$4, (void**) &_7$$4, &_5$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_6$$4, &_5$$4)
		) {
			ZEPHIR_GET_HMKEY(key, _6$$4, _5$$4);
			ZEPHIR_GET_HVALUE(value, _7$$4);
			ZEPHIR_SINIT_NVAR(_8$$5);
			ZVAL_LONG(&_8$$5, tab);
			ZEPHIR_CALL_FUNCTION(&_9$$5, "str_repeat", &_10, 147, space, &_8$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_11$$5);
			zephir_create_array(_11$$5, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_13$$5);
			ZVAL_STRING(_13$$5, "arr", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "getstyle", NULL, 0, _13$$5);
			zephir_check_temp_parameter(_13$$5);
			zephir_check_call_status();
			zephir_array_update_string(&_11$$5, SL(":style"), &_12$$5, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_11$$5, SL(":key"), &key, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_8$$5);
			ZVAL_STRING(&_8$$5, "[<span style=':style'>:key</span>] => ", 0);
			ZEPHIR_CALL_FUNCTION(&_12$$5, "strtr", NULL, 27, &_8$$5, _11$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_14$$5);
			ZEPHIR_CONCAT_VV(_14$$5, _9$$5, _12$$5);
			zephir_concat_self(&output, _14$$5 TSRMLS_CC);
			_15$$5 = tab == 1;
			if (_15$$5) {
				_15$$5 = !ZEPHIR_IS_STRING(name, "");
			}
			_16$$5 = _15$$5;
			if (_16$$5) {
				_16$$5 = !(Z_TYPE_P(key) == IS_LONG);
			}
			_17$$5 = _16$$5;
			if (_17$$5) {
				_17$$5 = ZEPHIR_IS_EQUAL(name, key);
			}
			if (_17$$5) {
				continue;
			} else {
				ZEPHIR_INIT_NVAR(_19$$7);
				ZVAL_STRING(_19$$7, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_20$$7);
				ZVAL_LONG(_20$$7, (tab + 1));
				ZEPHIR_CALL_METHOD(&_18$$7, this_ptr, "output", &_21, 181, value, _19$$7, _20$$7);
				zephir_check_temp_parameter(_19$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_22$$7);
				ZEPHIR_CONCAT_VS(_22$$7, _18$$7, "\n");
				zephir_concat_self(&output, _22$$7 TSRMLS_CC);
			}
		}
		ZEPHIR_SINIT_NVAR(_4$$4);
		ZVAL_LONG(&_4$$4, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_23$$4, "str_repeat", &_10, 147, space, &_4$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _23$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_24$$8);
		zephir_create_array(_24$$8, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_26$$8);
		ZVAL_STRING(_26$$8, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_25$$8, this_ptr, "getstyle", NULL, 0, _26$$8);
		zephir_check_temp_parameter(_26$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_24$$8, SL(":style"), &_25$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_26$$8);
		zephir_get_class(_26$$8, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_24$$8, SL(":class"), &_26$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_27$$8);
		ZVAL_STRING(&_27$$8, "<b style=':style'>Object</b> :class", 0);
		ZEPHIR_CALL_FUNCTION(&_25$$8, "strtr", NULL, 27, &_27$$8, _24$$8);
		zephir_check_call_status();
		zephir_concat_self(&output, _25$$8 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_28$$8, "get_parent_class", NULL, 182, variable);
		zephir_check_call_status();
		if (zephir_is_true(_28$$8)) {
			ZEPHIR_INIT_VAR(_29$$9);
			zephir_create_array(_29$$9, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_31$$9);
			ZVAL_STRING(_31$$9, "obj", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_30$$9, this_ptr, "getstyle", NULL, 0, _31$$9);
			zephir_check_temp_parameter(_31$$9);
			zephir_check_call_status();
			zephir_array_update_string(&_29$$9, SL(":style"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_30$$9, "get_parent_class", NULL, 182, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_29$$9, SL(":parent"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_VAR(_32$$9);
			ZVAL_STRING(&_32$$9, " <b style=':style'>extends</b> :parent", 0);
			ZEPHIR_CALL_FUNCTION(&_30$$9, "strtr", NULL, 27, &_32$$9, _29$$9);
			zephir_check_call_status();
			zephir_concat_self(&output, _30$$9 TSRMLS_CC);
		}
		zephir_concat_self_str(&output, SL(" (\n") TSRMLS_CC);
		_33$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_detailed"), PH_NOISY_CC);
		if (zephir_instance_of_ev(variable, phalcon_di_ce TSRMLS_CC)) {
			ZEPHIR_SINIT_VAR(_34$$10);
			ZVAL_LONG(&_34$$10, tab);
			ZEPHIR_CALL_FUNCTION(&_35$$10, "str_repeat", &_10, 147, space, &_34$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_36$$10);
			ZEPHIR_CONCAT_VS(_36$$10, _35$$10, "[skipped]\n");
			zephir_concat_self(&output, _36$$10 TSRMLS_CC);
		} else if (!(zephir_is_true(_33$$8))) {
			ZEPHIR_CALL_FUNCTION(&_37$$11, "get_object_vars", NULL, 22, variable);
			zephir_check_call_status();
			zephir_is_iterable(_37$$11, &_39$$11, &_38$$11, 0, 0, "phalcon/debug/dump.zep", 194);
			for (
			  ; zend_hash_get_current_data_ex(_39$$11, (void**) &_40$$11, &_38$$11) == SUCCESS
			  ; zend_hash_move_forward_ex(_39$$11, &_38$$11)
			) {
				ZEPHIR_GET_HMKEY(key, _39$$11, _38$$11);
				ZEPHIR_GET_HVALUE(value, _40$$11);
				ZEPHIR_SINIT_NVAR(_41$$12);
				ZVAL_LONG(&_41$$12, tab);
				ZEPHIR_CALL_FUNCTION(&_42$$12, "str_repeat", &_10, 147, space, &_41$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_43$$12);
				zephir_create_array(_43$$12, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_45$$12);
				ZVAL_STRING(_45$$12, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_44$$12, this_ptr, "getstyle", NULL, 0, _45$$12);
				zephir_check_temp_parameter(_45$$12);
				zephir_check_call_status();
				zephir_array_update_string(&_43$$12, SL(":style"), &_44$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_43$$12, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(_43$$12, SS(":type"), SL("public"), 1);
				ZEPHIR_SINIT_NVAR(_41$$12);
				ZVAL_STRING(&_41$$12, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_44$$12, "strtr", NULL, 27, &_41$$12, _43$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_46$$12);
				ZEPHIR_CONCAT_VV(_46$$12, _42$$12, _44$$12);
				zephir_concat_self(&output, _46$$12 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_45$$12);
				ZVAL_STRING(_45$$12, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_48$$12);
				ZVAL_LONG(_48$$12, (tab + 1));
				ZEPHIR_CALL_METHOD(&_47$$12, this_ptr, "output", &_21, 181, value, _45$$12, _48$$12);
				zephir_check_temp_parameter(_45$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_49$$12);
				ZEPHIR_CONCAT_VS(_49$$12, _47$$12, "\n");
				zephir_concat_self(&output, _49$$12 TSRMLS_CC);
			}
		} else {
			do {
				ZEPHIR_MAKE_REF(variable);
				ZEPHIR_CALL_FUNCTION(&attr, "each", &_50, 183, variable);
				ZEPHIR_UNREF(variable);
				zephir_check_call_status();
				if (!(zephir_is_true(attr))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(key);
				zephir_array_fetch_string(&key, attr, SL("key"), PH_NOISY, "phalcon/debug/dump.zep", 204 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(value);
				zephir_array_fetch_string(&value, attr, SL("value"), PH_NOISY, "phalcon/debug/dump.zep", 205 TSRMLS_CC);
				if (!(zephir_is_true(key))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(_51$$14);
				ZEPHIR_SINIT_NVAR(_52$$14);
				ZVAL_LONG(&_52$$14, 0);
				ZEPHIR_CALL_FUNCTION(&_53$$14, "chr", &_54, 146, &_52$$14);
				zephir_check_call_status();
				zephir_fast_explode(_51$$14, _53$$14, key, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(key, _51$$14);
				ZEPHIR_INIT_NVAR(type);
				ZVAL_STRING(type, "public", 1);
				if (zephir_array_isset_long(key, 1)) {
					ZEPHIR_INIT_NVAR(type);
					ZVAL_STRING(type, "private", 1);
					zephir_array_fetch_long(&_55$$17, key, 1, PH_NOISY | PH_READONLY, "phalcon/debug/dump.zep", 217 TSRMLS_CC);
					if (ZEPHIR_IS_STRING(_55$$17, "*")) {
						ZEPHIR_INIT_NVAR(type);
						ZVAL_STRING(type, "protected", 1);
					}
				}
				ZEPHIR_SINIT_NVAR(_52$$14);
				ZVAL_LONG(&_52$$14, tab);
				ZEPHIR_CALL_FUNCTION(&_56$$14, "str_repeat", &_10, 147, space, &_52$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_57$$14);
				zephir_create_array(_57$$14, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_51$$14);
				ZVAL_STRING(_51$$14, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_58$$14, this_ptr, "getstyle", NULL, 0, _51$$14);
				zephir_check_temp_parameter(_51$$14);
				zephir_check_call_status();
				zephir_array_update_string(&_57$$14, SL(":style"), &_58$$14, PH_COPY | PH_SEPARATE);
				ZEPHIR_MAKE_REF(key);
				ZEPHIR_CALL_FUNCTION(&_58$$14, "end", &_59, 184, key);
				ZEPHIR_UNREF(key);
				zephir_check_call_status();
				zephir_array_update_string(&_57$$14, SL(":key"), &_58$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_57$$14, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_SINIT_NVAR(_52$$14);
				ZVAL_STRING(&_52$$14, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_58$$14, "strtr", NULL, 27, &_52$$14, _57$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_60$$14);
				ZEPHIR_CONCAT_VV(_60$$14, _56$$14, _58$$14);
				zephir_concat_self(&output, _60$$14 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_51$$14);
				ZVAL_STRING(_51$$14, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_62$$14);
				ZVAL_LONG(_62$$14, (tab + 1));
				ZEPHIR_CALL_METHOD(&_61$$14, this_ptr, "output", &_21, 181, value, _51$$14, _62$$14);
				zephir_check_temp_parameter(_51$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_63$$14);
				ZEPHIR_CONCAT_VS(_63$$14, _61$$14, "\n");
				zephir_concat_self(&output, _63$$14 TSRMLS_CC);
			} while (zephir_is_true(attr));
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 185, variable);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_27$$8);
		ZVAL_LONG(&_27$$8, tab);
		ZEPHIR_CALL_FUNCTION(&_64$$8, "str_repeat", &_10, 147, space, &_27$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_65$$8);
		zephir_create_array(_65$$8, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_26$$8);
		ZVAL_STRING(_26$$8, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_66$$8, this_ptr, "getstyle", NULL, 0, _26$$8);
		zephir_check_temp_parameter(_26$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_65$$8, SL(":style"), &_66$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_26$$8);
		zephir_get_class(_26$$8, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_65$$8, SL(":class"), &_26$$8, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_65$$8, SS(":count"), zephir_fast_count_int(attr TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_27$$8);
		ZVAL_STRING(&_27$$8, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n", 0);
		ZEPHIR_CALL_FUNCTION(&_66$$8, "strtr", NULL, 27, &_27$$8, _65$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_67$$8);
		ZEPHIR_CONCAT_VV(_67$$8, _64$$8, _66$$8);
		zephir_concat_self(&output, _67$$8 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_26$$8);
		zephir_get_class(_26$$8, variable, 0 TSRMLS_CC);
		_68$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_methods"), PH_NOISY_CC);
		if (zephir_fast_in_array(_26$$8, _68$$8 TSRMLS_CC)) {
			ZEPHIR_SINIT_VAR(_69$$19);
			ZVAL_LONG(&_69$$19, tab);
			ZEPHIR_CALL_FUNCTION(&_70$$19, "str_repeat", &_10, 147, space, &_69$$19);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_71$$19);
			ZEPHIR_CONCAT_VS(_71$$19, _70$$19, "[already listed]\n");
			zephir_concat_self(&output, _71$$19 TSRMLS_CC);
		} else {
			zephir_is_iterable(attr, &_73$$20, &_72$$20, 0, 0, "phalcon/debug/dump.zep", 243);
			for (
			  ; zend_hash_get_current_data_ex(_73$$20, (void**) &_74$$20, &_72$$20) == SUCCESS
			  ; zend_hash_move_forward_ex(_73$$20, &_72$$20)
			) {
				ZEPHIR_GET_HVALUE(value, _74$$20);
				ZEPHIR_INIT_NVAR(_75$$21);
				zephir_get_class(_75$$21, variable, 0 TSRMLS_CC);
				zephir_update_property_array_append(this_ptr, SL("_methods"), _75$$21 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(value, "__construct")) {
					ZEPHIR_SINIT_NVAR(_76$$22);
					ZVAL_LONG(&_76$$22, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_77$$22, "str_repeat", &_10, 147, space, &_76$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_78$$22);
					zephir_create_array(_78$$22, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_80$$22);
					ZVAL_STRING(_80$$22, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_79$$22, this_ptr, "getstyle", NULL, 0, _80$$22);
					zephir_check_temp_parameter(_80$$22);
					zephir_check_call_status();
					zephir_array_update_string(&_78$$22, SL(":style"), &_79$$22, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_78$$22, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_76$$22);
					ZVAL_STRING(&_76$$22, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n", 0);
					ZEPHIR_CALL_FUNCTION(&_79$$22, "strtr", NULL, 27, &_76$$22, _78$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_81$$22);
					ZEPHIR_CONCAT_VV(_81$$22, _77$$22, _79$$22);
					zephir_concat_self(&output, _81$$22 TSRMLS_CC);
				} else {
					ZEPHIR_SINIT_NVAR(_82$$23);
					ZVAL_LONG(&_82$$23, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_83$$23, "str_repeat", &_10, 147, space, &_82$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_84$$23);
					zephir_create_array(_84$$23, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_86$$23);
					ZVAL_STRING(_86$$23, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_85$$23, this_ptr, "getstyle", NULL, 0, _86$$23);
					zephir_check_temp_parameter(_86$$23);
					zephir_check_call_status();
					zephir_array_update_string(&_84$$23, SL(":style"), &_85$$23, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_84$$23, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_82$$23);
					ZVAL_STRING(&_82$$23, "-><span style=':style'>:method</span>();\n", 0);
					ZEPHIR_CALL_FUNCTION(&_85$$23, "strtr", NULL, 27, &_82$$23, _84$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_87$$23);
					ZEPHIR_CONCAT_VV(_87$$23, _83$$23, _85$$23);
					zephir_concat_self(&output, _87$$23 TSRMLS_CC);
				}
			}
			ZEPHIR_SINIT_VAR(_88$$20);
			ZVAL_LONG(&_88$$20, tab);
			ZEPHIR_CALL_FUNCTION(&_89$$20, "str_repeat", &_10, 147, space, &_88$$20);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_90$$20);
			ZEPHIR_CONCAT_VS(_90$$20, _89$$20, ")\n");
			zephir_concat_self(&output, _90$$20 TSRMLS_CC);
		}
		ZEPHIR_SINIT_NVAR(_27$$8);
		ZVAL_LONG(&_27$$8, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_91$$8, "str_repeat", &_10, 147, space, &_27$$8);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _91$$8, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(_92$$24);
		zephir_create_array(_92$$24, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_94$$24);
		ZVAL_STRING(_94$$24, "int", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_93$$24, this_ptr, "getstyle", NULL, 0, _94$$24);
		zephir_check_temp_parameter(_94$$24);
		zephir_check_call_status();
		zephir_array_update_string(&_92$$24, SL(":style"), &_93$$24, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_92$$24, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_95$$24);
		ZVAL_STRING(&_95$$24, "<b style=':style'>Integer</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_93$$24, "strtr", NULL, 27, &_95$$24, _92$$24);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _93$$24);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_96, "is_float", NULL, 186, variable);
	zephir_check_call_status();
	if (zephir_is_true(_96)) {
		ZEPHIR_INIT_VAR(_97$$25);
		zephir_create_array(_97$$25, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_99$$25);
		ZVAL_STRING(_99$$25, "float", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_98$$25, this_ptr, "getstyle", NULL, 0, _99$$25);
		zephir_check_temp_parameter(_99$$25);
		zephir_check_call_status();
		zephir_array_update_string(&_97$$25, SL(":style"), &_98$$25, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_97$$25, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_100$$25);
		ZVAL_STRING(&_100$$25, "<b style=':style'>Float</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_98$$25, "strtr", NULL, 27, &_100$$25, _97$$25);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _98$$25);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(_101$$26);
		zephir_create_array(_101$$26, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_103$$26);
		ZVAL_STRING(_103$$26, "num", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_102$$26, this_ptr, "getstyle", NULL, 0, _103$$26);
		zephir_check_temp_parameter(_103$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_101$$26, SL(":style"), &_102$$26, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_101$$26, SS(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_101$$26, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_104$$26);
		ZVAL_STRING(&_104$$26, "<b style=':style'>Numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_CALL_FUNCTION(&_102$$26, "strtr", NULL, 27, &_104$$26, _101$$26);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _102$$26);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(_105$$27);
		zephir_create_array(_105$$27, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_107$$27);
		ZVAL_STRING(_107$$27, "str", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_106$$27, this_ptr, "getstyle", NULL, 0, _107$$27);
		zephir_check_temp_parameter(_107$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_105$$27, SL(":style"), &_106$$27, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_105$$27, SS(":length"), zephir_fast_strlen_ev(variable));
		ZEPHIR_SINIT_VAR(_108$$27);
		ZVAL_LONG(&_108$$27, 4);
		ZEPHIR_SINIT_VAR(_109$$27);
		ZVAL_STRING(&_109$$27, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_106$$27, "htmlentities", NULL, 166, variable, &_108$$27, &_109$$27);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_110$$27, "nl2br", NULL, 187, _106$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_105$$27, SL(":var"), &_110$$27, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_108$$27);
		ZVAL_STRING(&_108$$27, "<b style=':style'>String</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_CALL_FUNCTION(&_110$$27, "strtr", NULL, 27, &_108$$27, _105$$27);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _110$$27);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_BOOL) {
		ZEPHIR_INIT_VAR(_111$$28);
		zephir_create_array(_111$$28, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_113$$28);
		ZVAL_STRING(_113$$28, "bool", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_112$$28, this_ptr, "getstyle", NULL, 0, _113$$28);
		zephir_check_temp_parameter(_113$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_111$$28, SL(":style"), &_112$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_114$$28);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(_114$$28);
			ZVAL_STRING(_114$$28, "TRUE", 1);
		} else {
			ZEPHIR_INIT_NVAR(_114$$28);
			ZVAL_STRING(_114$$28, "FALSE", 1);
		}
		zephir_array_update_string(&_111$$28, SL(":var"), &_114$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_115$$28);
		ZVAL_STRING(&_115$$28, "<b style=':style'>Boolean</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_112$$28, "strtr", NULL, 27, &_115$$28, _111$$28);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _112$$28);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(_116$$29);
		zephir_create_array(_116$$29, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_118$$29);
		ZVAL_STRING(_118$$29, "null", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_117$$29, this_ptr, "getstyle", NULL, 0, _118$$29);
		zephir_check_temp_parameter(_118$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_116$$29, SL(":style"), &_117$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_119$$29);
		ZVAL_STRING(&_119$$29, "<b style=':style'>NULL</b>", 0);
		ZEPHIR_CALL_FUNCTION(&_117$$29, "strtr", NULL, 27, &_119$$29, _116$$29);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _117$$29);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_120);
	zephir_create_array(_120, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_122);
	ZVAL_STRING(_122, "other", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_121, this_ptr, "getstyle", NULL, 0, _122);
	zephir_check_temp_parameter(_122);
	zephir_check_call_status();
	zephir_array_update_string(&_120, SL(":style"), &_121, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_120, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_VAR(_123);
	ZVAL_STRING(&_123, "(<span style=':style'>:var</span>)", 0);
	ZEPHIR_CALL_FUNCTION(&_121, "strtr", NULL, 27, &_123, _120);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, output, _121);
	RETURN_MM();

}

/**
 * Returns an HTML string of information about a single variable.
 *
 * <code>
 * echo (new \Phalcon\Debug\Dump())->variable($foo, "foo");
 * </code>
 */
PHP_METHOD(Phalcon_Debug_Dump, variable) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
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
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 27, &_3, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an HTML string of debugging information about any number of
 * variables, each wrapped in a "pre" tag.
 *
 * <code>
 * $foo = "string";
 * $bar = ["key" => "value"];
 * $baz = new stdClass();
 *
 * echo (new \Phalcon\Debug\Dump())->variables($foo, $bar, $baz);
 * </code>
 *
 * @param mixed variable
 * @param ...
 */
PHP_METHOD(Phalcon_Debug_Dump, variables) {

	HashTable *_2;
	HashPosition _1;
	zval *key = NULL, *value = NULL, *output = NULL, *_0, **_3, *_4$$3 = NULL, *_5$$3 = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(output);
	ZVAL_STRING(output, "", 1);
	ZEPHIR_INIT_VAR(_0);
	zephir_get_args(_0 TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/debug/dump.zep", 315);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
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
 * $foo = [
 *     "key" => "value",
 * ];
 *
 * echo (new \Phalcon\Debug\Dump())->toJson($foo);
 *
 * $foo = new stdClass();
 * $foo->bar = "buz";
 *
 * echo (new \Phalcon\Debug\Dump())->toJson($foo);
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
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_methods"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_methods"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

