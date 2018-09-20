
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

	zend_class_entry *_59$$14;
	zend_bool _15$$5, _16$$5, _17$$5, _34$$8;
	HashTable *_6$$4, *_40$$11, *_53$$13, *_83$$16;
	HashPosition _5$$4, _39$$11, _52$$13, _82$$16;
	zval *_130, *_1$$4, *_11$$5 = NULL, *_24$$8, *_75$$8, *_29$$9, *_44$$12 = NULL, *_66$$14 = NULL, *_88$$18 = NULL, *_94$$19 = NULL, *_102$$20, *_107$$21, *_111$$22, *_115$$23, *_121$$24, *_126$$25;
	zephir_fcall_cache_entry *_10 = NULL, *_21 = NULL, *_56 = NULL, *_57 = NULL, *_60 = NULL, *_62 = NULL, *_71 = NULL;
	zend_long tab, ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, *_0$$3;
	zval *variable, *name_param = NULL, *tab_param = NULL, *key = NULL, *value = NULL, *output = NULL, *space = NULL, *type = NULL, *attr = NULL, *_106 = NULL, *_131 = NULL, *_132, _133, *_2$$4 = NULL, *_3$$4, _4$$4 = zval_used_for_init, **_7$$4, *_23$$4 = NULL, _8$$5 = zval_used_for_init, *_9$$5 = NULL, *_12$$5 = NULL, *_13$$5 = NULL, *_14$$5 = NULL, *_18$$7 = NULL, *_19$$7 = NULL, *_20$$7 = NULL, *_22$$7 = NULL, *_25$$8 = NULL, *_26$$8 = NULL, _27$$8 = zval_used_for_init, *_28$$8 = NULL, *_33$$8, *_74$$8 = NULL, *_76$$8 = NULL, *_77$$8, *_78$$8, *_101$$8 = NULL, *_30$$9 = NULL, *_31$$9, _32$$9, _35$$10, *_36$$10 = NULL, *_37$$10, *_38$$11 = NULL, **_41$$11, _42$$12 = zval_used_for_init, *_43$$12 = NULL, *_45$$12 = NULL, *_46$$12 = NULL, *_47$$12 = NULL, *_48$$12 = NULL, *_49$$12 = NULL, *_50$$12 = NULL, *reflect$$13 = NULL, *props$$13 = NULL, *property$$13 = NULL, *_51$$13, **_54$$13, *_55$$14 = NULL, *_58$$14 = NULL, *_61$$14 = NULL, _63$$14 = zval_used_for_init, _64$$14 = zval_used_for_init, *_65$$14 = NULL, *_67$$14 = NULL, *_68$$14 = NULL, *_69$$14 = NULL, *_70$$14 = NULL, *_72$$14 = NULL, *_73$$14 = NULL, _79$$15, *_80$$15 = NULL, *_81$$15, **_84$$16, _98$$16, *_99$$16 = NULL, *_100$$16, *_85$$17 = NULL, _86$$18 = zval_used_for_init, *_87$$18 = NULL, *_89$$18 = NULL, *_90$$18 = NULL, *_91$$18 = NULL, _92$$19 = zval_used_for_init, *_93$$19 = NULL, *_95$$19 = NULL, *_96$$19 = NULL, *_97$$19 = NULL, *_103$$20 = NULL, *_104$$20, _105$$20, *_108$$21 = NULL, *_109$$21, _110$$21, *_112$$22 = NULL, *_113$$22, _114$$22, *_116$$23 = NULL, *_117$$23, _118$$23 = zval_used_for_init, _119$$23, *_120$$23 = NULL, *_122$$24 = NULL, *_123$$24, *_124$$24 = NULL, _125$$24, *_127$$25 = NULL, *_128$$25, _129$$25;

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
			ZEPHIR_CALL_FUNCTION(&_9$$5, "str_repeat", &_10, 153, space, &_8$$5);
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
				ZEPHIR_CALL_METHOD(&_18$$7, this_ptr, "output", &_21, 192, value, _19$$7, _20$$7);
				zephir_check_temp_parameter(_19$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_22$$7);
				ZEPHIR_CONCAT_VS(_22$$7, _18$$7, "\n");
				zephir_concat_self(&output, _22$$7 TSRMLS_CC);
			}
		}
		ZEPHIR_SINIT_NVAR(_4$$4);
		ZVAL_LONG(&_4$$4, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_23$$4, "str_repeat", &_10, 153, space, &_4$$4);
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
		ZEPHIR_CALL_FUNCTION(&_28$$8, "get_parent_class", NULL, 193, variable);
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
			ZEPHIR_CALL_FUNCTION(&_30$$9, "get_parent_class", NULL, 193, variable);
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
		_34$$8 = !zephir_is_true(_33$$8);
		if (!(_34$$8)) {
			_34$$8 = zephir_instance_of_ev(variable, zend_standard_class_def TSRMLS_CC);
		}
		if (zephir_instance_of_ev(variable, phalcon_di_ce TSRMLS_CC)) {
			ZEPHIR_SINIT_VAR(_35$$10);
			ZVAL_LONG(&_35$$10, tab);
			ZEPHIR_CALL_FUNCTION(&_36$$10, "str_repeat", &_10, 153, space, &_35$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_37$$10);
			ZEPHIR_CONCAT_VS(_37$$10, _36$$10, "[skipped]\n");
			zephir_concat_self(&output, _37$$10 TSRMLS_CC);
		} else if (_34$$8) {
			ZEPHIR_CALL_FUNCTION(&_38$$11, "get_object_vars", NULL, 22, variable);
			zephir_check_call_status();
			zephir_is_iterable(_38$$11, &_40$$11, &_39$$11, 0, 0, "phalcon/debug/dump.zep", 194);
			for (
			  ; zend_hash_get_current_data_ex(_40$$11, (void**) &_41$$11, &_39$$11) == SUCCESS
			  ; zend_hash_move_forward_ex(_40$$11, &_39$$11)
			) {
				ZEPHIR_GET_HMKEY(key, _40$$11, _39$$11);
				ZEPHIR_GET_HVALUE(value, _41$$11);
				ZEPHIR_SINIT_NVAR(_42$$12);
				ZVAL_LONG(&_42$$12, tab);
				ZEPHIR_CALL_FUNCTION(&_43$$12, "str_repeat", &_10, 153, space, &_42$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_44$$12);
				zephir_create_array(_44$$12, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_46$$12);
				ZVAL_STRING(_46$$12, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_45$$12, this_ptr, "getstyle", NULL, 0, _46$$12);
				zephir_check_temp_parameter(_46$$12);
				zephir_check_call_status();
				zephir_array_update_string(&_44$$12, SL(":style"), &_45$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_44$$12, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(_44$$12, SS(":type"), SL("public"), 1);
				ZEPHIR_SINIT_NVAR(_42$$12);
				ZVAL_STRING(&_42$$12, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_45$$12, "strtr", NULL, 27, &_42$$12, _44$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_47$$12);
				ZEPHIR_CONCAT_VV(_47$$12, _43$$12, _45$$12);
				zephir_concat_self(&output, _47$$12 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_46$$12);
				ZVAL_STRING(_46$$12, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_49$$12);
				ZVAL_LONG(_49$$12, (tab + 1));
				ZEPHIR_CALL_METHOD(&_48$$12, this_ptr, "output", &_21, 192, value, _46$$12, _49$$12);
				zephir_check_temp_parameter(_46$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_50$$12);
				ZEPHIR_CONCAT_VS(_50$$12, _48$$12, "\n");
				zephir_concat_self(&output, _50$$12 TSRMLS_CC);
			}
		} else {
			ZEPHIR_INIT_VAR(reflect$$13);
			object_init_ex(reflect$$13, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
			ZEPHIR_CALL_METHOD(NULL, reflect$$13, "__construct", NULL, 98, variable);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_51$$13);
			ZVAL_LONG(_51$$13, ((256 | 512) | 1024));
			ZEPHIR_CALL_METHOD(&props$$13, reflect$$13, "getproperties", NULL, 102, _51$$13);
			zephir_check_call_status();
			zephir_is_iterable(props$$13, &_53$$13, &_52$$13, 0, 0, "phalcon/debug/dump.zep", 214);
			for (
			  ; zend_hash_get_current_data_ex(_53$$13, (void**) &_54$$13, &_52$$13) == SUCCESS
			  ; zend_hash_move_forward_ex(_53$$13, &_52$$13)
			) {
				ZEPHIR_GET_HVALUE(property$$13, _54$$13);
				ZEPHIR_INIT_NVAR(_55$$14);
				ZVAL_BOOL(_55$$14, 1);
				ZEPHIR_CALL_METHOD(NULL, property$$13, "setaccessible", &_56, 0, _55$$14);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&key, property$$13, "getname", &_57, 0);
				zephir_check_call_status();
					_59$$14 = zend_fetch_class(SL("Reflection"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_61$$14, property$$13, "getmodifiers", &_62, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_CE_STATIC(&_58$$14, _59$$14, "getmodifiernames", &_60, 0, _61$$14);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_63$$14);
				ZVAL_STRING(&_63$$14, " ", 0);
				ZEPHIR_INIT_NVAR(type);
				zephir_fast_join(type, &_63$$14, _58$$14 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_64$$14);
				ZVAL_LONG(&_64$$14, tab);
				ZEPHIR_CALL_FUNCTION(&_65$$14, "str_repeat", &_10, 153, space, &_64$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_66$$14);
				zephir_create_array(_66$$14, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_55$$14);
				ZVAL_STRING(_55$$14, "obj", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_67$$14, this_ptr, "getstyle", NULL, 0, _55$$14);
				zephir_check_temp_parameter(_55$$14);
				zephir_check_call_status();
				zephir_array_update_string(&_66$$14, SL(":style"), &_67$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_66$$14, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_66$$14, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_SINIT_NVAR(_64$$14);
				ZVAL_STRING(&_64$$14, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ", 0);
				ZEPHIR_CALL_FUNCTION(&_67$$14, "strtr", NULL, 27, &_64$$14, _66$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_68$$14);
				ZEPHIR_CONCAT_VV(_68$$14, _65$$14, _67$$14);
				zephir_concat_self(&output, _68$$14 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_70$$14, property$$13, "getvalue", &_71, 0, variable);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_55$$14);
				ZVAL_STRING(_55$$14, "", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_NVAR(_72$$14);
				ZVAL_LONG(_72$$14, (tab + 1));
				ZEPHIR_CALL_METHOD(&_69$$14, this_ptr, "output", &_21, 192, _70$$14, _55$$14, _72$$14);
				zephir_check_temp_parameter(_55$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_73$$14);
				ZEPHIR_CONCAT_VS(_73$$14, _69$$14, "\n");
				zephir_concat_self(&output, _73$$14 TSRMLS_CC);
			}
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 194, variable);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_27$$8);
		ZVAL_LONG(&_27$$8, tab);
		ZEPHIR_CALL_FUNCTION(&_74$$8, "str_repeat", &_10, 153, space, &_27$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_75$$8);
		zephir_create_array(_75$$8, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_26$$8);
		ZVAL_STRING(_26$$8, "obj", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_76$$8, this_ptr, "getstyle", NULL, 0, _26$$8);
		zephir_check_temp_parameter(_26$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_75$$8, SL(":style"), &_76$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_26$$8);
		zephir_get_class(_26$$8, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_75$$8, SL(":class"), &_26$$8, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_75$$8, SS(":count"), zephir_fast_count_int(attr TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_27$$8);
		ZVAL_STRING(&_27$$8, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n", 0);
		ZEPHIR_CALL_FUNCTION(&_76$$8, "strtr", NULL, 27, &_27$$8, _75$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_77$$8);
		ZEPHIR_CONCAT_VV(_77$$8, _74$$8, _76$$8);
		zephir_concat_self(&output, _77$$8 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_26$$8);
		zephir_get_class(_26$$8, variable, 0 TSRMLS_CC);
		_78$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_methods"), PH_NOISY_CC);
		if (zephir_fast_in_array(_26$$8, _78$$8 TSRMLS_CC)) {
			ZEPHIR_SINIT_VAR(_79$$15);
			ZVAL_LONG(&_79$$15, tab);
			ZEPHIR_CALL_FUNCTION(&_80$$15, "str_repeat", &_10, 153, space, &_79$$15);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_81$$15);
			ZEPHIR_CONCAT_VS(_81$$15, _80$$15, "[already listed]\n");
			zephir_concat_self(&output, _81$$15 TSRMLS_CC);
		} else {
			zephir_is_iterable(attr, &_83$$16, &_82$$16, 0, 0, "phalcon/debug/dump.zep", 231);
			for (
			  ; zend_hash_get_current_data_ex(_83$$16, (void**) &_84$$16, &_82$$16) == SUCCESS
			  ; zend_hash_move_forward_ex(_83$$16, &_82$$16)
			) {
				ZEPHIR_GET_HVALUE(value, _84$$16);
				ZEPHIR_INIT_NVAR(_85$$17);
				zephir_get_class(_85$$17, variable, 0 TSRMLS_CC);
				zephir_update_property_array_append(this_ptr, SL("_methods"), _85$$17 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(value, "__construct")) {
					ZEPHIR_SINIT_NVAR(_86$$18);
					ZVAL_LONG(&_86$$18, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_87$$18, "str_repeat", &_10, 153, space, &_86$$18);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_88$$18);
					zephir_create_array(_88$$18, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_90$$18);
					ZVAL_STRING(_90$$18, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_89$$18, this_ptr, "getstyle", NULL, 0, _90$$18);
					zephir_check_temp_parameter(_90$$18);
					zephir_check_call_status();
					zephir_array_update_string(&_88$$18, SL(":style"), &_89$$18, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_88$$18, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_86$$18);
					ZVAL_STRING(&_86$$18, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n", 0);
					ZEPHIR_CALL_FUNCTION(&_89$$18, "strtr", NULL, 27, &_86$$18, _88$$18);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_91$$18);
					ZEPHIR_CONCAT_VV(_91$$18, _87$$18, _89$$18);
					zephir_concat_self(&output, _91$$18 TSRMLS_CC);
				} else {
					ZEPHIR_SINIT_NVAR(_92$$19);
					ZVAL_LONG(&_92$$19, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_93$$19, "str_repeat", &_10, 153, space, &_92$$19);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_94$$19);
					zephir_create_array(_94$$19, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_96$$19);
					ZVAL_STRING(_96$$19, "obj", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_95$$19, this_ptr, "getstyle", NULL, 0, _96$$19);
					zephir_check_temp_parameter(_96$$19);
					zephir_check_call_status();
					zephir_array_update_string(&_94$$19, SL(":style"), &_95$$19, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_94$$19, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_SINIT_NVAR(_92$$19);
					ZVAL_STRING(&_92$$19, "-><span style=':style'>:method</span>();\n", 0);
					ZEPHIR_CALL_FUNCTION(&_95$$19, "strtr", NULL, 27, &_92$$19, _94$$19);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_97$$19);
					ZEPHIR_CONCAT_VV(_97$$19, _93$$19, _95$$19);
					zephir_concat_self(&output, _97$$19 TSRMLS_CC);
				}
			}
			ZEPHIR_SINIT_VAR(_98$$16);
			ZVAL_LONG(&_98$$16, tab);
			ZEPHIR_CALL_FUNCTION(&_99$$16, "str_repeat", &_10, 153, space, &_98$$16);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_100$$16);
			ZEPHIR_CONCAT_VS(_100$$16, _99$$16, ")\n");
			zephir_concat_self(&output, _100$$16 TSRMLS_CC);
		}
		ZEPHIR_SINIT_NVAR(_27$$8);
		ZVAL_LONG(&_27$$8, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_101$$8, "str_repeat", &_10, 153, space, &_27$$8);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, output, _101$$8, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(_102$$20);
		zephir_create_array(_102$$20, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_104$$20);
		ZVAL_STRING(_104$$20, "int", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_103$$20, this_ptr, "getstyle", NULL, 0, _104$$20);
		zephir_check_temp_parameter(_104$$20);
		zephir_check_call_status();
		zephir_array_update_string(&_102$$20, SL(":style"), &_103$$20, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_102$$20, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_105$$20);
		ZVAL_STRING(&_105$$20, "<b style=':style'>Integer</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_103$$20, "strtr", NULL, 27, &_105$$20, _102$$20);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _103$$20);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_106, "is_float", NULL, 195, variable);
	zephir_check_call_status();
	if (zephir_is_true(_106)) {
		ZEPHIR_INIT_VAR(_107$$21);
		zephir_create_array(_107$$21, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_109$$21);
		ZVAL_STRING(_109$$21, "float", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_108$$21, this_ptr, "getstyle", NULL, 0, _109$$21);
		zephir_check_temp_parameter(_109$$21);
		zephir_check_call_status();
		zephir_array_update_string(&_107$$21, SL(":style"), &_108$$21, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_107$$21, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_110$$21);
		ZVAL_STRING(&_110$$21, "<b style=':style'>Float</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_108$$21, "strtr", NULL, 27, &_110$$21, _107$$21);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _108$$21);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(_111$$22);
		zephir_create_array(_111$$22, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_113$$22);
		ZVAL_STRING(_113$$22, "num", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_112$$22, this_ptr, "getstyle", NULL, 0, _113$$22);
		zephir_check_temp_parameter(_113$$22);
		zephir_check_call_status();
		zephir_array_update_string(&_111$$22, SL(":style"), &_112$$22, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_111$$22, SS(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_111$$22, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_114$$22);
		ZVAL_STRING(&_114$$22, "<b style=':style'>Numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_CALL_FUNCTION(&_112$$22, "strtr", NULL, 27, &_114$$22, _111$$22);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _112$$22);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(_115$$23);
		zephir_create_array(_115$$23, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_117$$23);
		ZVAL_STRING(_117$$23, "str", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_116$$23, this_ptr, "getstyle", NULL, 0, _117$$23);
		zephir_check_temp_parameter(_117$$23);
		zephir_check_call_status();
		zephir_array_update_string(&_115$$23, SL(":style"), &_116$$23, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(_115$$23, SS(":length"), zephir_fast_strlen_ev(variable));
		ZEPHIR_SINIT_VAR(_118$$23);
		ZVAL_LONG(&_118$$23, 4);
		ZEPHIR_SINIT_VAR(_119$$23);
		ZVAL_STRING(&_119$$23, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_116$$23, "htmlentities", NULL, 177, variable, &_118$$23, &_119$$23);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_120$$23, "nl2br", NULL, 196, _116$$23);
		zephir_check_call_status();
		zephir_array_update_string(&_115$$23, SL(":var"), &_120$$23, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_NVAR(_118$$23);
		ZVAL_STRING(&_118$$23, "<b style=':style'>String</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"", 0);
		ZEPHIR_CALL_FUNCTION(&_120$$23, "strtr", NULL, 27, &_118$$23, _115$$23);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _120$$23);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_BOOL) {
		ZEPHIR_INIT_VAR(_121$$24);
		zephir_create_array(_121$$24, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_123$$24);
		ZVAL_STRING(_123$$24, "bool", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_122$$24, this_ptr, "getstyle", NULL, 0, _123$$24);
		zephir_check_temp_parameter(_123$$24);
		zephir_check_call_status();
		zephir_array_update_string(&_121$$24, SL(":style"), &_122$$24, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_124$$24);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(_124$$24);
			ZVAL_STRING(_124$$24, "TRUE", 1);
		} else {
			ZEPHIR_INIT_NVAR(_124$$24);
			ZVAL_STRING(_124$$24, "FALSE", 1);
		}
		zephir_array_update_string(&_121$$24, SL(":var"), &_124$$24, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_125$$24);
		ZVAL_STRING(&_125$$24, "<b style=':style'>Boolean</b> (<span style=':style'>:var</span>)", 0);
		ZEPHIR_CALL_FUNCTION(&_122$$24, "strtr", NULL, 27, &_125$$24, _121$$24);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _122$$24);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(_126$$25);
		zephir_create_array(_126$$25, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_128$$25);
		ZVAL_STRING(_128$$25, "null", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_127$$25, this_ptr, "getstyle", NULL, 0, _128$$25);
		zephir_check_temp_parameter(_128$$25);
		zephir_check_call_status();
		zephir_array_update_string(&_126$$25, SL(":style"), &_127$$25, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_129$$25);
		ZVAL_STRING(&_129$$25, "<b style=':style'>NULL</b>", 0);
		ZEPHIR_CALL_FUNCTION(&_127$$25, "strtr", NULL, 27, &_129$$25, _126$$25);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, output, _127$$25);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_130);
	zephir_create_array(_130, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_132);
	ZVAL_STRING(_132, "other", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_131, this_ptr, "getstyle", NULL, 0, _132);
	zephir_check_temp_parameter(_132);
	zephir_check_call_status();
	zephir_array_update_string(&_130, SL(":style"), &_131, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_130, SL(":var"), &variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_VAR(_133);
	ZVAL_STRING(&_133, "(<span style=':style'>:var</span>)", 0);
	ZEPHIR_CALL_FUNCTION(&_131, "strtr", NULL, 27, &_133, _130);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, output, _131);
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
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/debug/dump.zep", 303);
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

