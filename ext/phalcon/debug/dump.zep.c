
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

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_detailed");

}

PHP_METHOD(Phalcon_Debug_Dump, setDetailed) {

	zval *detailed, detailed_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&detailed_sub);

	zephir_fetch_params(0, 1, 0, &detailed);



	zephir_update_property_zval(this_ptr, SL("_detailed"), detailed);
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
	zval *styles_param = NULL, *detailed_param = NULL, __$true, __$false;
	zval styles;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&styles);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &styles_param, &detailed_param);

	if (!styles_param) {
		ZEPHIR_INIT_VAR(&styles);
		array_init(&styles);
	} else {
		zephir_get_arrval(&styles, styles_param);
	}
	if (!detailed_param) {
		detailed = 0;
	} else {
		detailed = zephir_get_boolval(detailed_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstyles", NULL, 0, &styles);
	zephir_check_call_status();
	if (detailed) {
		zephir_update_property_zval(this_ptr, SL("_detailed"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_detailed"), &__$false);
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

	zval _1;
	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "variables");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_get_args(&_1);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get style for type
 */
PHP_METHOD(Phalcon_Debug_Dump, getStyle) {

	zval *type_param = NULL, style, _0;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&style);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	zephir_read_property(&_0, this_ptr, SL("_styles"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&style, &_0, &type, 1 TSRMLS_CC)) {
		RETURN_CTOR(&style);
	} else {
		RETURN_MM_STRING("color:gray");
	}

}

/**
 * Set styles for vars type
 */
PHP_METHOD(Phalcon_Debug_Dump, setStyles) {

	zval *styles_param = NULL, defaultStyles, _0;
	zval styles;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&styles);
	ZVAL_UNDEF(&defaultStyles);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &styles_param);

	if (!styles_param) {
		ZEPHIR_INIT_VAR(&styles);
		array_init(&styles);
	} else {
		zephir_get_arrval(&styles, styles_param);
	}


	if (1 == 0) {
		ZEPHIR_INIT_NVAR(&styles);
		array_init(&styles);
	}
	if (1 != 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_debug_exception_ce, "The styles must be an array", "phalcon/debug/dump.zep", 101);
		return;
	}
	ZEPHIR_INIT_VAR(&defaultStyles);
	zephir_create_array(&defaultStyles, 11, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&defaultStyles, SL("pre"), SL("background-color:#f3f3f3; font-size:11px; padding:10px; border:1px solid #ccc; text-align:left; color:#333"));
	add_assoc_stringl_ex(&defaultStyles, SL("arr"), SL("color:red"));
	add_assoc_stringl_ex(&defaultStyles, SL("bool"), SL("color:green"));
	add_assoc_stringl_ex(&defaultStyles, SL("float"), SL("color:fuchsia"));
	add_assoc_stringl_ex(&defaultStyles, SL("int"), SL("color:blue"));
	add_assoc_stringl_ex(&defaultStyles, SL("null"), SL("color:black"));
	add_assoc_stringl_ex(&defaultStyles, SL("num"), SL("color:navy"));
	add_assoc_stringl_ex(&defaultStyles, SL("obj"), SL("color:purple"));
	add_assoc_stringl_ex(&defaultStyles, SL("other"), SL("color:maroon"));
	add_assoc_stringl_ex(&defaultStyles, SL("res"), SL("color:lime"));
	add_assoc_stringl_ex(&defaultStyles, SL("str"), SL("color:teal"));
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_array_merge(&_0, &defaultStyles, &styles TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_styles"), &_0);
	RETURN_MM_MEMBER(getThis(), "_styles");

}

/**
 * Alias of variable() method
 */
PHP_METHOD(Phalcon_Debug_Dump, one) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *variable, variable_sub, *name_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &variable, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "variable", NULL, 0, variable, &name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prepare an HTML string of information about a single variable.
 */
PHP_METHOD(Phalcon_Debug_Dump, output) {

	zend_bool _16$$5, _17$$5, _18$$5;
	zend_string *_8$$4, *_41$$11;
	zend_ulong _7$$4, _40$$11;
	zval _112, _1$$4, _12$$5, _26$$8, _65$$8, _31$$9, _44$$12, _57$$14, _75$$22, _81$$23, _90$$24, _94$$25, _97$$26, _100$$27, _105$$28, _109$$29;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL, *_11 = NULL, *_22 = NULL, *_30 = NULL, *_50 = NULL, *_54 = NULL, *_59 = NULL;
	zend_long tab, ZEPHIR_LAST_CALL_STATUS;
	zval name, _0$$3;
	zval *variable, variable_sub, *name_param = NULL, *tab_param = NULL, key, value, output, space, type, attr, _93, _113, _114, _2$$4, _3$$4, *_6$$4, _24$$4, _25$$4, _9$$5, _10$$5, _13$$5, _14$$5, _15$$5, _19$$7, _20$$7, _21$$7, _23$$7, _27$$8, _28$$8, _29$$8, _34$$8, _63$$8, _64$$8, _66$$8, _67$$8, _88$$8, _89$$8, _32$$9, _33$$9, _35$$10, _36$$10, _37$$10, _38$$11, *_39$$11, _42$$12, _43$$12, _45$$12, _46$$12, _47$$12, _48$$12, _49$$12, _51$$14, _52$$14, _53$$14, _56$$14, _58$$14, _60$$14, _61$$14, _62$$14, _55$$17, _68$$19, _69$$19, _70$$19, *_71$$20, _85$$20, _86$$20, _87$$20, _72$$21, _73$$22, _74$$22, _76$$22, _77$$22, _78$$22, _79$$23, _80$$23, _82$$23, _83$$23, _84$$23, _91$$24, _92$$24, _95$$25, _96$$25, _98$$26, _99$$26, _101$$27, _102$$27, _103$$27, _104$$27, _106$$28, _107$$28, _108$$28, _110$$29, _111$$29;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&space);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&attr);
	ZVAL_UNDEF(&_93);
	ZVAL_UNDEF(&_113);
	ZVAL_UNDEF(&_114);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_24$$4);
	ZVAL_UNDEF(&_25$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_63$$8);
	ZVAL_UNDEF(&_64$$8);
	ZVAL_UNDEF(&_66$$8);
	ZVAL_UNDEF(&_67$$8);
	ZVAL_UNDEF(&_88$$8);
	ZVAL_UNDEF(&_89$$8);
	ZVAL_UNDEF(&_32$$9);
	ZVAL_UNDEF(&_33$$9);
	ZVAL_UNDEF(&_35$$10);
	ZVAL_UNDEF(&_36$$10);
	ZVAL_UNDEF(&_37$$10);
	ZVAL_UNDEF(&_38$$11);
	ZVAL_UNDEF(&_42$$12);
	ZVAL_UNDEF(&_43$$12);
	ZVAL_UNDEF(&_45$$12);
	ZVAL_UNDEF(&_46$$12);
	ZVAL_UNDEF(&_47$$12);
	ZVAL_UNDEF(&_48$$12);
	ZVAL_UNDEF(&_49$$12);
	ZVAL_UNDEF(&_51$$14);
	ZVAL_UNDEF(&_52$$14);
	ZVAL_UNDEF(&_53$$14);
	ZVAL_UNDEF(&_56$$14);
	ZVAL_UNDEF(&_58$$14);
	ZVAL_UNDEF(&_60$$14);
	ZVAL_UNDEF(&_61$$14);
	ZVAL_UNDEF(&_62$$14);
	ZVAL_UNDEF(&_55$$17);
	ZVAL_UNDEF(&_68$$19);
	ZVAL_UNDEF(&_69$$19);
	ZVAL_UNDEF(&_70$$19);
	ZVAL_UNDEF(&_85$$20);
	ZVAL_UNDEF(&_86$$20);
	ZVAL_UNDEF(&_87$$20);
	ZVAL_UNDEF(&_72$$21);
	ZVAL_UNDEF(&_73$$22);
	ZVAL_UNDEF(&_74$$22);
	ZVAL_UNDEF(&_76$$22);
	ZVAL_UNDEF(&_77$$22);
	ZVAL_UNDEF(&_78$$22);
	ZVAL_UNDEF(&_79$$23);
	ZVAL_UNDEF(&_80$$23);
	ZVAL_UNDEF(&_82$$23);
	ZVAL_UNDEF(&_83$$23);
	ZVAL_UNDEF(&_84$$23);
	ZVAL_UNDEF(&_91$$24);
	ZVAL_UNDEF(&_92$$24);
	ZVAL_UNDEF(&_95$$25);
	ZVAL_UNDEF(&_96$$25);
	ZVAL_UNDEF(&_98$$26);
	ZVAL_UNDEF(&_99$$26);
	ZVAL_UNDEF(&_101$$27);
	ZVAL_UNDEF(&_102$$27);
	ZVAL_UNDEF(&_103$$27);
	ZVAL_UNDEF(&_104$$27);
	ZVAL_UNDEF(&_106$$28);
	ZVAL_UNDEF(&_107$$28);
	ZVAL_UNDEF(&_108$$28);
	ZVAL_UNDEF(&_110$$29);
	ZVAL_UNDEF(&_111$$29);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_112);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_65$$8);
	ZVAL_UNDEF(&_31$$9);
	ZVAL_UNDEF(&_44$$12);
	ZVAL_UNDEF(&_57$$14);
	ZVAL_UNDEF(&_75$$22);
	ZVAL_UNDEF(&_81$$23);
	ZVAL_UNDEF(&_90$$24);
	ZVAL_UNDEF(&_94$$25);
	ZVAL_UNDEF(&_97$$26);
	ZVAL_UNDEF(&_100$$27);
	ZVAL_UNDEF(&_105$$28);
	ZVAL_UNDEF(&_109$$29);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &variable, &name_param, &tab_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}
	if (!tab_param) {
		tab = 1;
	} else {
		tab = zephir_get_intval(tab_param);
	}


	ZEPHIR_INIT_VAR(&space);
	ZVAL_STRING(&space, "  ");
	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	if (!(Z_TYPE_P(&name) == IS_UNDEF) && Z_STRLEN_P(&name)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_VS(&_0$$3, &name, " ");
		ZEPHIR_CPY_WRT(&output, &_0$$3);
	}
	if (Z_TYPE_P(variable) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_create_array(&_1$$4, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "arr");
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getstyle", &_4, 0, &_3$$4);
		zephir_check_call_status();
		zephir_array_update_string(&_1$$4, SL(":style"), &_2$$4, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_1$$4, SL(":count"), zephir_fast_count_int(variable TSRMLS_CC));
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "<b style =':style'>Array</b> (<span style =':style'>:count</span>) (\n");
		ZEPHIR_CALL_FUNCTION(&_2$$4, "strtr", &_5, 22, &_3$$4, &_1$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, &_2$$4 TSRMLS_CC);
		zephir_is_iterable(variable, 0, "phalcon/debug/dump.zep", 161);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(variable), _7$$4, _8$$4, _6$$4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_8$$4 != NULL) { 
				ZVAL_STR_COPY(&key, _8$$4);
			} else {
				ZVAL_LONG(&key, _7$$4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _6$$4);
			ZVAL_LONG(&_9$$5, tab);
			ZEPHIR_CALL_FUNCTION(&_10$$5, "str_repeat", &_11, 136, &space, &_9$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_12$$5);
			zephir_create_array(&_12$$5, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_14$$5);
			ZVAL_STRING(&_14$$5, "arr");
			ZEPHIR_CALL_METHOD(&_13$$5, this_ptr, "getstyle", &_4, 0, &_14$$5);
			zephir_check_call_status();
			zephir_array_update_string(&_12$$5, SL(":style"), &_13$$5, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_12$$5, SL(":key"), &key, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_14$$5);
			ZVAL_STRING(&_14$$5, "[<span style=':style'>:key</span>] => ");
			ZEPHIR_CALL_FUNCTION(&_13$$5, "strtr", &_5, 22, &_14$$5, &_12$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_15$$5);
			ZEPHIR_CONCAT_VV(&_15$$5, &_10$$5, &_13$$5);
			zephir_concat_self(&output, &_15$$5 TSRMLS_CC);
			_16$$5 = tab == 1;
			if (_16$$5) {
				_16$$5 = !ZEPHIR_IS_STRING(&name, "");
			}
			_17$$5 = _16$$5;
			if (_17$$5) {
				_17$$5 = !(Z_TYPE_P(&key) == IS_LONG);
			}
			_18$$5 = _17$$5;
			if (_18$$5) {
				_18$$5 = ZEPHIR_IS_EQUAL(&name, &key);
			}
			if (_18$$5) {
				continue;
			} else {
				ZEPHIR_INIT_NVAR(&_20$$7);
				ZVAL_STRING(&_20$$7, "");
				ZVAL_LONG(&_21$$7, (tab + 1));
				ZEPHIR_CALL_METHOD(&_19$$7, this_ptr, "output", &_22, 166, &value, &_20$$7, &_21$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_23$$7);
				ZEPHIR_CONCAT_VS(&_23$$7, &_19$$7, "\n");
				zephir_concat_self(&output, &_23$$7 TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_24$$4, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_25$$4, "str_repeat", &_11, 136, &space, &_24$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_25$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_26$$8);
		zephir_create_array(&_26$$8, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_28$$8);
		ZVAL_STRING(&_28$$8, "obj");
		ZEPHIR_CALL_METHOD(&_27$$8, this_ptr, "getstyle", &_4, 0, &_28$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_26$$8, SL(":style"), &_27$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_28$$8);
		zephir_get_class(&_28$$8, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_26$$8, SL(":class"), &_28$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_28$$8);
		ZVAL_STRING(&_28$$8, "<b style=':style'>Object</b> :class");
		ZEPHIR_CALL_FUNCTION(&_27$$8, "strtr", &_5, 22, &_28$$8, &_26$$8);
		zephir_check_call_status();
		zephir_concat_self(&output, &_27$$8 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_29$$8, "get_parent_class", &_30, 167, variable);
		zephir_check_call_status();
		if (zephir_is_true(&_29$$8)) {
			ZEPHIR_INIT_VAR(&_31$$9);
			zephir_create_array(&_31$$9, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_33$$9);
			ZVAL_STRING(&_33$$9, "obj");
			ZEPHIR_CALL_METHOD(&_32$$9, this_ptr, "getstyle", &_4, 0, &_33$$9);
			zephir_check_call_status();
			zephir_array_update_string(&_31$$9, SL(":style"), &_32$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_32$$9, "get_parent_class", &_30, 167, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_31$$9, SL(":parent"), &_32$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_33$$9);
			ZVAL_STRING(&_33$$9, " <b style=':style'>extends</b> :parent");
			ZEPHIR_CALL_FUNCTION(&_32$$9, "strtr", &_5, 22, &_33$$9, &_31$$9);
			zephir_check_call_status();
			zephir_concat_self(&output, &_32$$9 TSRMLS_CC);
		}
		zephir_concat_self_str(&output, SL(" (\n") TSRMLS_CC);
		zephir_read_property(&_34$$8, this_ptr, SL("_detailed"), PH_NOISY_CC | PH_READONLY);
		if (zephir_instance_of_ev(variable, phalcon_di_ce TSRMLS_CC)) {
			ZVAL_LONG(&_35$$10, tab);
			ZEPHIR_CALL_FUNCTION(&_36$$10, "str_repeat", &_11, 136, &space, &_35$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_37$$10);
			ZEPHIR_CONCAT_VS(&_37$$10, &_36$$10, "[skipped]\n");
			zephir_concat_self(&output, &_37$$10 TSRMLS_CC);
		} else if (!(zephir_is_true(&_34$$8))) {
			ZEPHIR_CALL_FUNCTION(&_38$$11, "get_object_vars", NULL, 17, variable);
			zephir_check_call_status();
			zephir_is_iterable(&_38$$11, 0, "phalcon/debug/dump.zep", 194);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_38$$11), _40$$11, _41$$11, _39$$11)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_41$$11 != NULL) { 
					ZVAL_STR_COPY(&key, _41$$11);
				} else {
					ZVAL_LONG(&key, _40$$11);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _39$$11);
				ZVAL_LONG(&_42$$12, tab);
				ZEPHIR_CALL_FUNCTION(&_43$$12, "str_repeat", &_11, 136, &space, &_42$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_44$$12);
				zephir_create_array(&_44$$12, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_46$$12);
				ZVAL_STRING(&_46$$12, "obj");
				ZEPHIR_CALL_METHOD(&_45$$12, this_ptr, "getstyle", &_4, 0, &_46$$12);
				zephir_check_call_status();
				zephir_array_update_string(&_44$$12, SL(":style"), &_45$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_44$$12, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(&_44$$12, SL(":type"), SL("public"));
				ZEPHIR_INIT_NVAR(&_46$$12);
				ZVAL_STRING(&_46$$12, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
				ZEPHIR_CALL_FUNCTION(&_45$$12, "strtr", &_5, 22, &_46$$12, &_44$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_47$$12);
				ZEPHIR_CONCAT_VV(&_47$$12, &_43$$12, &_45$$12);
				zephir_concat_self(&output, &_47$$12 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_46$$12);
				ZVAL_STRING(&_46$$12, "");
				ZVAL_LONG(&_42$$12, (tab + 1));
				ZEPHIR_CALL_METHOD(&_48$$12, this_ptr, "output", &_22, 166, &value, &_46$$12, &_42$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_49$$12);
				ZEPHIR_CONCAT_VS(&_49$$12, &_48$$12, "\n");
				zephir_concat_self(&output, &_49$$12 TSRMLS_CC);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&key);
		} else {
			do {
				ZEPHIR_MAKE_REF(variable);
				ZEPHIR_CALL_FUNCTION(&attr, "each", &_50, 168, variable);
				ZEPHIR_UNREF(variable);
				zephir_check_call_status();
				if (!(zephir_is_true(&attr))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&key);
				zephir_array_fetch_string(&key, &attr, SL("key"), PH_NOISY, "phalcon/debug/dump.zep", 204 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch_string(&value, &attr, SL("value"), PH_NOISY, "phalcon/debug/dump.zep", 205 TSRMLS_CC);
				if (!(zephir_is_true(&key))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_51$$14);
				ZVAL_LONG(&_52$$14, 0);
				ZEPHIR_CALL_FUNCTION(&_53$$14, "chr", &_54, 135, &_52$$14);
				zephir_check_call_status();
				zephir_fast_explode(&_51$$14, &_53$$14, &key, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(&key, &_51$$14);
				ZEPHIR_INIT_NVAR(&type);
				ZVAL_STRING(&type, "public");
				if (zephir_array_isset_long(&key, 1)) {
					ZEPHIR_INIT_NVAR(&type);
					ZVAL_STRING(&type, "private");
					zephir_array_fetch_long(&_55$$17, &key, 1, PH_NOISY | PH_READONLY, "phalcon/debug/dump.zep", 217 TSRMLS_CC);
					if (ZEPHIR_IS_STRING(&_55$$17, "*")) {
						ZEPHIR_INIT_NVAR(&type);
						ZVAL_STRING(&type, "protected");
					}
				}
				ZVAL_LONG(&_52$$14, tab);
				ZEPHIR_CALL_FUNCTION(&_56$$14, "str_repeat", &_11, 136, &space, &_52$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_57$$14);
				zephir_create_array(&_57$$14, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_51$$14);
				ZVAL_STRING(&_51$$14, "obj");
				ZEPHIR_CALL_METHOD(&_58$$14, this_ptr, "getstyle", &_4, 0, &_51$$14);
				zephir_check_call_status();
				zephir_array_update_string(&_57$$14, SL(":style"), &_58$$14, PH_COPY | PH_SEPARATE);
				ZEPHIR_MAKE_REF(&key);
				ZEPHIR_CALL_FUNCTION(&_58$$14, "end", &_59, 169, &key);
				ZEPHIR_UNREF(&key);
				zephir_check_call_status();
				zephir_array_update_string(&_57$$14, SL(":key"), &_58$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_57$$14, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_51$$14);
				ZVAL_STRING(&_51$$14, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
				ZEPHIR_CALL_FUNCTION(&_58$$14, "strtr", &_5, 22, &_51$$14, &_57$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_60$$14);
				ZEPHIR_CONCAT_VV(&_60$$14, &_56$$14, &_58$$14);
				zephir_concat_self(&output, &_60$$14 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_51$$14);
				ZVAL_STRING(&_51$$14, "");
				ZVAL_LONG(&_52$$14, (tab + 1));
				ZEPHIR_CALL_METHOD(&_61$$14, this_ptr, "output", &_22, 166, &value, &_51$$14, &_52$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_62$$14);
				ZEPHIR_CONCAT_VS(&_62$$14, &_61$$14, "\n");
				zephir_concat_self(&output, &_62$$14 TSRMLS_CC);
			} while (zephir_is_true(&attr));
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 170, variable);
		zephir_check_call_status();
		ZVAL_LONG(&_63$$8, tab);
		ZEPHIR_CALL_FUNCTION(&_64$$8, "str_repeat", &_11, 136, &space, &_63$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_65$$8);
		zephir_create_array(&_65$$8, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_28$$8);
		ZVAL_STRING(&_28$$8, "obj");
		ZEPHIR_CALL_METHOD(&_66$$8, this_ptr, "getstyle", &_4, 0, &_28$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_65$$8, SL(":style"), &_66$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_28$$8);
		zephir_get_class(&_28$$8, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_65$$8, SL(":class"), &_28$$8, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_65$$8, SL(":count"), zephir_fast_count_int(&attr TSRMLS_CC));
		ZEPHIR_INIT_NVAR(&_28$$8);
		ZVAL_STRING(&_28$$8, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n");
		ZEPHIR_CALL_FUNCTION(&_66$$8, "strtr", &_5, 22, &_28$$8, &_65$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_67$$8);
		ZEPHIR_CONCAT_VV(&_67$$8, &_64$$8, &_66$$8);
		zephir_concat_self(&output, &_67$$8 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_28$$8);
		zephir_get_class(&_28$$8, variable, 0 TSRMLS_CC);
		zephir_read_property(&_63$$8, this_ptr, SL("_methods"), PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&_28$$8, &_63$$8 TSRMLS_CC)) {
			ZVAL_LONG(&_68$$19, tab);
			ZEPHIR_CALL_FUNCTION(&_69$$19, "str_repeat", &_11, 136, &space, &_68$$19);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_70$$19);
			ZEPHIR_CONCAT_VS(&_70$$19, &_69$$19, "[already listed]\n");
			zephir_concat_self(&output, &_70$$19 TSRMLS_CC);
		} else {
			zephir_is_iterable(&attr, 0, "phalcon/debug/dump.zep", 243);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attr), _71$$20)
			{
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _71$$20);
				ZEPHIR_INIT_NVAR(&_72$$21);
				zephir_get_class(&_72$$21, variable, 0 TSRMLS_CC);
				zephir_update_property_array_append(this_ptr, SL("_methods"), &_72$$21 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(&value, "__construct")) {
					ZVAL_LONG(&_73$$22, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_74$$22, "str_repeat", &_11, 136, &space, &_73$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_75$$22);
					zephir_create_array(&_75$$22, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_77$$22);
					ZVAL_STRING(&_77$$22, "obj");
					ZEPHIR_CALL_METHOD(&_76$$22, this_ptr, "getstyle", &_4, 0, &_77$$22);
					zephir_check_call_status();
					zephir_array_update_string(&_75$$22, SL(":style"), &_76$$22, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_75$$22, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_77$$22);
					ZVAL_STRING(&_77$$22, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n");
					ZEPHIR_CALL_FUNCTION(&_76$$22, "strtr", &_5, 22, &_77$$22, &_75$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_78$$22);
					ZEPHIR_CONCAT_VV(&_78$$22, &_74$$22, &_76$$22);
					zephir_concat_self(&output, &_78$$22 TSRMLS_CC);
				} else {
					ZVAL_LONG(&_79$$23, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_80$$23, "str_repeat", &_11, 136, &space, &_79$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_81$$23);
					zephir_create_array(&_81$$23, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_83$$23);
					ZVAL_STRING(&_83$$23, "obj");
					ZEPHIR_CALL_METHOD(&_82$$23, this_ptr, "getstyle", &_4, 0, &_83$$23);
					zephir_check_call_status();
					zephir_array_update_string(&_81$$23, SL(":style"), &_82$$23, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_81$$23, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_83$$23);
					ZVAL_STRING(&_83$$23, "-><span style=':style'>:method</span>();\n");
					ZEPHIR_CALL_FUNCTION(&_82$$23, "strtr", &_5, 22, &_83$$23, &_81$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_84$$23);
					ZEPHIR_CONCAT_VV(&_84$$23, &_80$$23, &_82$$23);
					zephir_concat_self(&output, &_84$$23 TSRMLS_CC);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_LONG(&_85$$20, tab);
			ZEPHIR_CALL_FUNCTION(&_86$$20, "str_repeat", &_11, 136, &space, &_85$$20);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_87$$20);
			ZEPHIR_CONCAT_VS(&_87$$20, &_86$$20, ")\n");
			zephir_concat_self(&output, &_87$$20 TSRMLS_CC);
		}
		ZVAL_LONG(&_88$$8, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_89$$8, "str_repeat", &_11, 136, &space, &_88$$8);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_89$$8, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_90$$24);
		zephir_create_array(&_90$$24, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_92$$24);
		ZVAL_STRING(&_92$$24, "int");
		ZEPHIR_CALL_METHOD(&_91$$24, this_ptr, "getstyle", &_4, 0, &_92$$24);
		zephir_check_call_status();
		zephir_array_update_string(&_90$$24, SL(":style"), &_91$$24, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_90$$24, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_92$$24);
		ZVAL_STRING(&_92$$24, "<b style=':style'>Integer</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_91$$24, "strtr", &_5, 22, &_92$$24, &_90$$24);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_91$$24);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_93, "is_float", NULL, 171, variable);
	zephir_check_call_status();
	if (zephir_is_true(&_93)) {
		ZEPHIR_INIT_VAR(&_94$$25);
		zephir_create_array(&_94$$25, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_96$$25);
		ZVAL_STRING(&_96$$25, "float");
		ZEPHIR_CALL_METHOD(&_95$$25, this_ptr, "getstyle", &_4, 0, &_96$$25);
		zephir_check_call_status();
		zephir_array_update_string(&_94$$25, SL(":style"), &_95$$25, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_94$$25, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_96$$25);
		ZVAL_STRING(&_96$$25, "<b style=':style'>Float</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_95$$25, "strtr", &_5, 22, &_96$$25, &_94$$25);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_95$$25);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_97$$26);
		zephir_create_array(&_97$$26, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_99$$26);
		ZVAL_STRING(&_99$$26, "num");
		ZEPHIR_CALL_METHOD(&_98$$26, this_ptr, "getstyle", &_4, 0, &_99$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_97$$26, SL(":style"), &_98$$26, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_97$$26, SL(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_97$$26, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_99$$26);
		ZVAL_STRING(&_99$$26, "<b style=':style'>Numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		ZEPHIR_CALL_FUNCTION(&_98$$26, "strtr", &_5, 22, &_99$$26, &_97$$26);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_98$$26);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_100$$27);
		zephir_create_array(&_100$$27, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_102$$27);
		ZVAL_STRING(&_102$$27, "str");
		ZEPHIR_CALL_METHOD(&_101$$27, this_ptr, "getstyle", &_4, 0, &_102$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_100$$27, SL(":style"), &_101$$27, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_100$$27, SL(":length"), zephir_fast_strlen_ev(variable));
		ZVAL_LONG(&_103$$27, 4);
		ZEPHIR_INIT_NVAR(&_102$$27);
		ZVAL_STRING(&_102$$27, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_101$$27, "htmlentities", NULL, 154, variable, &_103$$27, &_102$$27);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_104$$27, "nl2br", NULL, 172, &_101$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_100$$27, SL(":var"), &_104$$27, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_102$$27);
		ZVAL_STRING(&_102$$27, "<b style=':style'>String</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		ZEPHIR_CALL_FUNCTION(&_104$$27, "strtr", &_5, 22, &_102$$27, &_100$$27);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_104$$27);
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE)) {
		ZEPHIR_INIT_VAR(&_105$$28);
		zephir_create_array(&_105$$28, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_107$$28);
		ZVAL_STRING(&_107$$28, "bool");
		ZEPHIR_CALL_METHOD(&_106$$28, this_ptr, "getstyle", &_4, 0, &_107$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_105$$28, SL(":style"), &_106$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_108$$28);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_108$$28);
			ZVAL_STRING(&_108$$28, "TRUE");
		} else {
			ZEPHIR_INIT_NVAR(&_108$$28);
			ZVAL_STRING(&_108$$28, "FALSE");
		}
		zephir_array_update_string(&_105$$28, SL(":var"), &_108$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_107$$28);
		ZVAL_STRING(&_107$$28, "<b style=':style'>Boolean</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_106$$28, "strtr", &_5, 22, &_107$$28, &_105$$28);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_106$$28);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_109$$29);
		zephir_create_array(&_109$$29, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_111$$29);
		ZVAL_STRING(&_111$$29, "null");
		ZEPHIR_CALL_METHOD(&_110$$29, this_ptr, "getstyle", &_4, 0, &_111$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_109$$29, SL(":style"), &_110$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_111$$29);
		ZVAL_STRING(&_111$$29, "<b style=':style'>NULL</b>");
		ZEPHIR_CALL_FUNCTION(&_110$$29, "strtr", &_5, 22, &_111$$29, &_109$$29);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_110$$29);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_112);
	zephir_create_array(&_112, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_114);
	ZVAL_STRING(&_114, "other");
	ZEPHIR_CALL_METHOD(&_113, this_ptr, "getstyle", &_4, 0, &_114);
	zephir_check_call_status();
	zephir_array_update_string(&_112, SL(":style"), &_113, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_112, SL(":var"), variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_114);
	ZVAL_STRING(&_114, "(<span style=':style'>:var</span>)");
	ZEPHIR_CALL_FUNCTION(&_113, "strtr", &_5, 22, &_114, &_112);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_113);
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

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *variable, variable_sub, *name_param = NULL, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &variable, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "pre");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "output", NULL, 0, variable, &name);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":output"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "<pre style=':style'>:output</pre>");
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 22, &_2, &_0);
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

	zend_string *_3;
	zend_ulong _2;
	zval key, value, output, _0, *_1, _4$$3, _5$$3;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_args(&_0);
	zephir_is_iterable(&_0, 0, "phalcon/debug/dump.zep", 315);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		ZEPHIR_INIT_LNVAR(_5$$3);
		ZEPHIR_CONCAT_SV(&_5$$3, "var ", &key);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "one", &_6, 0, &value, &_5$$3);
		zephir_check_call_status();
		zephir_concat_self(&output, &_4$$3 TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&output);

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
 */
PHP_METHOD(Phalcon_Debug_Dump, toJson) {

	zval *variable, variable_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &variable);



	ZVAL_LONG(&_0, ((128 | 64) | 256));
	zephir_json_encode(return_value, variable, zephir_get_intval(&_0) );
	return;

}

zend_object *zephir_init_properties_Phalcon_Debug_Dump(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_methods"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_methods"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

