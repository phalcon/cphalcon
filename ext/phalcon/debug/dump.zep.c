
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

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_detailed");

}

PHP_METHOD(Phalcon_Debug_Dump, setDetailed) {

	zval *detailed, detailed_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&detailed_sub);

	zephir_fetch_params(0, 1, 0, &detailed);



	zephir_update_property_zval(this_ptr, SL("_detailed"), detailed);

}

/**
 * Phalcon\Debug\Dump constructor
 *
 * @param boolean detailed debug object's private and protected properties
 */
PHP_METHOD(Phalcon_Debug_Dump, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool detailed, _0;
	zval *styles_param = NULL, *detailed_param = NULL, __$true, __$false;
	zval styles;
	ZEPHIR_INIT_THIS();

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


	_0 = zephir_is_true(&styles);
	if (_0) {
		_0 = 1 != 1;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_debug_exception_ce, "The styles must be an array", "phalcon/debug/dump.zep", 56);
		return;
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

	zval _1, _2;
	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "variables");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(&_2, "func_get_args", NULL, 175);
	zephir_check_call_status();
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get style for type
 */
PHP_METHOD(Phalcon_Debug_Dump, getStyle) {

	zval *type_param = NULL, style, _0;
	zval type;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&style);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	zephir_read_property(&_0, this_ptr, SL("_styles"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&style, &_0, &type, 1 TSRMLS_CC)) {
		RETURN_CTOR(style);
	} else {
		RETURN_MM_STRING("color:gray");
	}

}

/**
 * Set styles for vars type
 */
PHP_METHOD(Phalcon_Debug_Dump, setStyles) {

	zval *styles = NULL, styles_sub, __$null, defaultStyles, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&styles_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&defaultStyles);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &styles);

	if (!styles) {
		styles = &styles_sub;
		ZEPHIR_CPY_WRT(styles, &__$null);
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
	zephir_fast_array_merge(&_0, &defaultStyles, styles TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_styles"), &_0);
	RETURN_MM_MEMBER(this_ptr, "_styles");

}

/**
 * Alias of variable() method
 */
PHP_METHOD(Phalcon_Debug_Dump, one) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *variable, variable_sub, *name_param = NULL;
	ZEPHIR_INIT_THIS();

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
	zend_string *_8$$4, *_38$$10;
	zend_ulong _7$$4, _37$$10;
	zval _112, _1$$4, _12$$5, _26$$8, _65$$8, _31$$9, _41$$11, _57$$13, _75$$21, _81$$22, _90$$23, _94$$24, _97$$25, _100$$26, _105$$27, _109$$28;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL, *_11 = NULL, *_22 = NULL, *_30 = NULL, *_47 = NULL, *_51 = NULL, *_53 = NULL, *_59 = NULL;
	int tab, ZEPHIR_LAST_CALL_STATUS;
	zval name, _0$$3;
	zval *variable, variable_sub, *name_param = NULL, *tab_param = NULL, key, value, output, space, type, attr, _93, _113, _114, _2$$4, _3$$4, *_6$$4, _24$$4, _25$$4, _9$$5, _10$$5, _13$$5, _14$$5, _15$$5, _19$$7, _20$$7, _21$$7, _23$$7, _27$$8, _28$$8, _29$$8, _34$$8, _63$$8, _64$$8, _66$$8, _67$$8, _88$$8, _89$$8, _32$$9, _33$$9, _35$$10, *_36$$10, _39$$11, _40$$11, _42$$11, _43$$11, _44$$11, _45$$11, _46$$11, _48$$13, _49$$13, _50$$13, _52$$13, _55$$13, _56$$13, _58$$13, _60$$13, _61$$13, _62$$13, _54$$16, _68$$18, _69$$18, _70$$18, *_71$$19, _85$$19, _86$$19, _87$$19, _72$$20, _73$$21, _74$$21, _76$$21, _77$$21, _78$$21, _79$$22, _80$$22, _82$$22, _83$$22, _84$$22, _91$$23, _92$$23, _95$$24, _96$$24, _98$$25, _99$$25, _101$$26, _102$$26, _103$$26, _104$$26, _106$$27, _107$$27, _108$$27, _110$$28, _111$$28;
	ZEPHIR_INIT_THIS();

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
	ZVAL_UNDEF(&_39$$11);
	ZVAL_UNDEF(&_40$$11);
	ZVAL_UNDEF(&_42$$11);
	ZVAL_UNDEF(&_43$$11);
	ZVAL_UNDEF(&_44$$11);
	ZVAL_UNDEF(&_45$$11);
	ZVAL_UNDEF(&_46$$11);
	ZVAL_UNDEF(&_48$$13);
	ZVAL_UNDEF(&_49$$13);
	ZVAL_UNDEF(&_50$$13);
	ZVAL_UNDEF(&_52$$13);
	ZVAL_UNDEF(&_55$$13);
	ZVAL_UNDEF(&_56$$13);
	ZVAL_UNDEF(&_58$$13);
	ZVAL_UNDEF(&_60$$13);
	ZVAL_UNDEF(&_61$$13);
	ZVAL_UNDEF(&_62$$13);
	ZVAL_UNDEF(&_54$$16);
	ZVAL_UNDEF(&_68$$18);
	ZVAL_UNDEF(&_69$$18);
	ZVAL_UNDEF(&_70$$18);
	ZVAL_UNDEF(&_85$$19);
	ZVAL_UNDEF(&_86$$19);
	ZVAL_UNDEF(&_87$$19);
	ZVAL_UNDEF(&_72$$20);
	ZVAL_UNDEF(&_73$$21);
	ZVAL_UNDEF(&_74$$21);
	ZVAL_UNDEF(&_76$$21);
	ZVAL_UNDEF(&_77$$21);
	ZVAL_UNDEF(&_78$$21);
	ZVAL_UNDEF(&_79$$22);
	ZVAL_UNDEF(&_80$$22);
	ZVAL_UNDEF(&_82$$22);
	ZVAL_UNDEF(&_83$$22);
	ZVAL_UNDEF(&_84$$22);
	ZVAL_UNDEF(&_91$$23);
	ZVAL_UNDEF(&_92$$23);
	ZVAL_UNDEF(&_95$$24);
	ZVAL_UNDEF(&_96$$24);
	ZVAL_UNDEF(&_98$$25);
	ZVAL_UNDEF(&_99$$25);
	ZVAL_UNDEF(&_101$$26);
	ZVAL_UNDEF(&_102$$26);
	ZVAL_UNDEF(&_103$$26);
	ZVAL_UNDEF(&_104$$26);
	ZVAL_UNDEF(&_106$$27);
	ZVAL_UNDEF(&_107$$27);
	ZVAL_UNDEF(&_108$$27);
	ZVAL_UNDEF(&_110$$28);
	ZVAL_UNDEF(&_111$$28);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_112);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_65$$8);
	ZVAL_UNDEF(&_31$$9);
	ZVAL_UNDEF(&_41$$11);
	ZVAL_UNDEF(&_57$$13);
	ZVAL_UNDEF(&_75$$21);
	ZVAL_UNDEF(&_81$$22);
	ZVAL_UNDEF(&_90$$23);
	ZVAL_UNDEF(&_94$$24);
	ZVAL_UNDEF(&_97$$25);
	ZVAL_UNDEF(&_100$$26);
	ZVAL_UNDEF(&_105$$27);
	ZVAL_UNDEF(&_109$$28);

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
		ZEPHIR_CALL_FUNCTION(&_2$$4, "strtr", &_5, 55, &_3$$4, &_1$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, &_2$$4 TSRMLS_CC);
		zephir_is_iterable(variable, 0, "phalcon/debug/dump.zep", 154);
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
			ZEPHIR_CALL_FUNCTION(&_10$$5, "str_repeat", &_11, 142, &space, &_9$$5);
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
			ZEPHIR_CALL_FUNCTION(&_13$$5, "strtr", &_5, 55, &_14$$5, &_12$$5);
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
				ZEPHIR_CALL_METHOD(&_19$$7, this_ptr, "output", &_22, 176, &value, &_20$$7, &_21$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_23$$7);
				ZEPHIR_CONCAT_VS(&_23$$7, &_19$$7, "\n");
				zephir_concat_self(&output, &_23$$7 TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_24$$4, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_25$$4, "str_repeat", &_11, 142, &space, &_24$$4);
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
		ZEPHIR_CALL_FUNCTION(&_27$$8, "strtr", &_5, 55, &_28$$8, &_26$$8);
		zephir_check_call_status();
		zephir_concat_self(&output, &_27$$8 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_29$$8, "get_parent_class", &_30, 177, variable);
		zephir_check_call_status();
		if (zephir_is_true(&_29$$8)) {
			ZEPHIR_INIT_VAR(&_31$$9);
			zephir_create_array(&_31$$9, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_33$$9);
			ZVAL_STRING(&_33$$9, "obj");
			ZEPHIR_CALL_METHOD(&_32$$9, this_ptr, "getstyle", &_4, 0, &_33$$9);
			zephir_check_call_status();
			zephir_array_update_string(&_31$$9, SL(":style"), &_32$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_32$$9, "get_parent_class", &_30, 177, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_31$$9, SL(":parent"), &_32$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_33$$9);
			ZVAL_STRING(&_33$$9, " <b style=':style'>extends</b> :parent");
			ZEPHIR_CALL_FUNCTION(&_32$$9, "strtr", &_5, 55, &_33$$9, &_31$$9);
			zephir_check_call_status();
			zephir_concat_self(&output, &_32$$9 TSRMLS_CC);
		}
		zephir_concat_self_str(&output, SL(" (\n") TSRMLS_CC);
		zephir_read_property(&_34$$8, this_ptr, SL("_detailed"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_is_true(&_34$$8))) {
			ZEPHIR_CALL_FUNCTION(&_35$$10, "get_object_vars", NULL, 18, variable);
			zephir_check_call_status();
			zephir_is_iterable(&_35$$10, 0, "phalcon/debug/dump.zep", 171);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_35$$10), _37$$10, _38$$10, _36$$10)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_38$$10 != NULL) { 
					ZVAL_STR_COPY(&key, _38$$10);
				} else {
					ZVAL_LONG(&key, _37$$10);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _36$$10);
				ZVAL_LONG(&_39$$11, tab);
				ZEPHIR_CALL_FUNCTION(&_40$$11, "str_repeat", &_11, 142, &space, &_39$$11);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_41$$11);
				zephir_create_array(&_41$$11, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_43$$11);
				ZVAL_STRING(&_43$$11, "obj");
				ZEPHIR_CALL_METHOD(&_42$$11, this_ptr, "getstyle", &_4, 0, &_43$$11);
				zephir_check_call_status();
				zephir_array_update_string(&_41$$11, SL(":style"), &_42$$11, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_41$$11, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(&_41$$11, SL(":type"), SL("public"));
				ZEPHIR_INIT_NVAR(&_43$$11);
				ZVAL_STRING(&_43$$11, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
				ZEPHIR_CALL_FUNCTION(&_42$$11, "strtr", &_5, 55, &_43$$11, &_41$$11);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_44$$11);
				ZEPHIR_CONCAT_VV(&_44$$11, &_40$$11, &_42$$11);
				zephir_concat_self(&output, &_44$$11 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_43$$11);
				ZVAL_STRING(&_43$$11, "");
				ZVAL_LONG(&_39$$11, (tab + 1));
				ZEPHIR_CALL_METHOD(&_45$$11, this_ptr, "output", &_22, 176, &value, &_43$$11, &_39$$11);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_46$$11);
				ZEPHIR_CONCAT_VS(&_46$$11, &_45$$11, "\n");
				zephir_concat_self(&output, &_46$$11 TSRMLS_CC);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&key);
		} else {
			do {
				ZEPHIR_MAKE_REF(variable);
				ZEPHIR_CALL_FUNCTION(&attr, "each", &_47, 178, variable);
				ZEPHIR_UNREF(variable);
				zephir_check_call_status();
				if (!(zephir_is_true(&attr))) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&key);
				zephir_array_fetch_string(&key, &attr, SL("key"), PH_NOISY, "phalcon/debug/dump.zep", 180 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch_string(&value, &attr, SL("value"), PH_NOISY, "phalcon/debug/dump.zep", 181 TSRMLS_CC);
				if (!(zephir_is_true(&key))) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_48$$13);
				ZEPHIR_INIT_NVAR(&_49$$13);
				ZVAL_STRING(&_49$$13, "\\x00");
				ZEPHIR_CALL_FUNCTION(&_50$$13, "ord", &_51, 143, &_49$$13);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_52$$13, "chr", &_53, 141, &_50$$13);
				zephir_check_call_status();
				zephir_fast_explode(&_48$$13, &_52$$13, &key, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(&key, &_48$$13);
				ZEPHIR_INIT_NVAR(&type);
				ZVAL_STRING(&type, "public");
				if (zephir_array_isset_long(&key, 1)) {
					ZEPHIR_INIT_NVAR(&type);
					ZVAL_STRING(&type, "private");
					zephir_array_fetch_long(&_54$$16, &key, 1, PH_NOISY | PH_READONLY, "phalcon/debug/dump.zep", 193 TSRMLS_CC);
					if (ZEPHIR_IS_STRING(&_54$$16, "*")) {
						ZEPHIR_INIT_NVAR(&type);
						ZVAL_STRING(&type, "protected");
					}
				}
				ZVAL_LONG(&_55$$13, tab);
				ZEPHIR_CALL_FUNCTION(&_56$$13, "str_repeat", &_11, 142, &space, &_55$$13);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_57$$13);
				zephir_create_array(&_57$$13, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_48$$13);
				ZVAL_STRING(&_48$$13, "obj");
				ZEPHIR_CALL_METHOD(&_58$$13, this_ptr, "getstyle", &_4, 0, &_48$$13);
				zephir_check_call_status();
				zephir_array_update_string(&_57$$13, SL(":style"), &_58$$13, PH_COPY | PH_SEPARATE);
				ZEPHIR_MAKE_REF(&key);
				ZEPHIR_CALL_FUNCTION(&_58$$13, "end", &_59, 179, &key);
				ZEPHIR_UNREF(&key);
				zephir_check_call_status();
				zephir_array_update_string(&_57$$13, SL(":key"), &_58$$13, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_57$$13, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_48$$13);
				ZVAL_STRING(&_48$$13, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
				ZEPHIR_CALL_FUNCTION(&_58$$13, "strtr", &_5, 55, &_48$$13, &_57$$13);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_60$$13);
				ZEPHIR_CONCAT_VV(&_60$$13, &_56$$13, &_58$$13);
				zephir_concat_self(&output, &_60$$13 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_48$$13);
				ZVAL_STRING(&_48$$13, "");
				ZVAL_LONG(&_55$$13, (tab + 1));
				ZEPHIR_CALL_METHOD(&_61$$13, this_ptr, "output", &_22, 176, &value, &_48$$13, &_55$$13);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_62$$13);
				ZEPHIR_CONCAT_VS(&_62$$13, &_61$$13, "\n");
				zephir_concat_self(&output, &_62$$13 TSRMLS_CC);
			} while (zephir_is_true(&attr));
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 180, variable);
		zephir_check_call_status();
		ZVAL_LONG(&_63$$8, tab);
		ZEPHIR_CALL_FUNCTION(&_64$$8, "str_repeat", &_11, 142, &space, &_63$$8);
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
		ZEPHIR_CALL_FUNCTION(&_66$$8, "strtr", &_5, 55, &_28$$8, &_65$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_67$$8);
		ZEPHIR_CONCAT_VV(&_67$$8, &_64$$8, &_66$$8);
		zephir_concat_self(&output, &_67$$8 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_28$$8);
		zephir_get_class(&_28$$8, variable, 0 TSRMLS_CC);
		zephir_read_property(&_63$$8, this_ptr, SL("_methods"), PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&_28$$8, &_63$$8 TSRMLS_CC)) {
			ZVAL_LONG(&_68$$18, tab);
			ZEPHIR_CALL_FUNCTION(&_69$$18, "str_repeat", &_11, 142, &space, &_68$$18);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_70$$18);
			ZEPHIR_CONCAT_VS(&_70$$18, &_69$$18, "[already listed]\n");
			zephir_concat_self(&output, &_70$$18 TSRMLS_CC);
		} else {
			zephir_is_iterable(&attr, 0, "phalcon/debug/dump.zep", 219);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attr), _71$$19)
			{
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _71$$19);
				ZEPHIR_INIT_NVAR(&_72$$20);
				zephir_get_class(&_72$$20, variable, 0 TSRMLS_CC);
				zephir_update_property_array_append(this_ptr, SL("_methods"), &_72$$20 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(&value, "__construct")) {
					ZVAL_LONG(&_73$$21, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_74$$21, "str_repeat", &_11, 142, &space, &_73$$21);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_75$$21);
					zephir_create_array(&_75$$21, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_77$$21);
					ZVAL_STRING(&_77$$21, "obj");
					ZEPHIR_CALL_METHOD(&_76$$21, this_ptr, "getstyle", &_4, 0, &_77$$21);
					zephir_check_call_status();
					zephir_array_update_string(&_75$$21, SL(":style"), &_76$$21, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_75$$21, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_77$$21);
					ZVAL_STRING(&_77$$21, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n");
					ZEPHIR_CALL_FUNCTION(&_76$$21, "strtr", &_5, 55, &_77$$21, &_75$$21);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_78$$21);
					ZEPHIR_CONCAT_VV(&_78$$21, &_74$$21, &_76$$21);
					zephir_concat_self(&output, &_78$$21 TSRMLS_CC);
				} else {
					ZVAL_LONG(&_79$$22, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_80$$22, "str_repeat", &_11, 142, &space, &_79$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_81$$22);
					zephir_create_array(&_81$$22, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_83$$22);
					ZVAL_STRING(&_83$$22, "obj");
					ZEPHIR_CALL_METHOD(&_82$$22, this_ptr, "getstyle", &_4, 0, &_83$$22);
					zephir_check_call_status();
					zephir_array_update_string(&_81$$22, SL(":style"), &_82$$22, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_81$$22, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_83$$22);
					ZVAL_STRING(&_83$$22, "-><span style=':style'>:method</span>();\n");
					ZEPHIR_CALL_FUNCTION(&_82$$22, "strtr", &_5, 55, &_83$$22, &_81$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_84$$22);
					ZEPHIR_CONCAT_VV(&_84$$22, &_80$$22, &_82$$22);
					zephir_concat_self(&output, &_84$$22 TSRMLS_CC);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_LONG(&_85$$19, tab);
			ZEPHIR_CALL_FUNCTION(&_86$$19, "str_repeat", &_11, 142, &space, &_85$$19);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_87$$19);
			ZEPHIR_CONCAT_VS(&_87$$19, &_86$$19, ")\n");
			zephir_concat_self(&output, &_87$$19 TSRMLS_CC);
		}
		ZVAL_LONG(&_88$$8, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_89$$8, "str_repeat", &_11, 142, &space, &_88$$8);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_89$$8, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_90$$23);
		zephir_create_array(&_90$$23, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_92$$23);
		ZVAL_STRING(&_92$$23, "int");
		ZEPHIR_CALL_METHOD(&_91$$23, this_ptr, "getstyle", &_4, 0, &_92$$23);
		zephir_check_call_status();
		zephir_array_update_string(&_90$$23, SL(":style"), &_91$$23, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_90$$23, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_92$$23);
		ZVAL_STRING(&_92$$23, "<b style=':style'>Integer</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_91$$23, "strtr", &_5, 55, &_92$$23, &_90$$23);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_91$$23);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_93, "is_float", NULL, 181, variable);
	zephir_check_call_status();
	if (zephir_is_true(&_93)) {
		ZEPHIR_INIT_VAR(&_94$$24);
		zephir_create_array(&_94$$24, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_96$$24);
		ZVAL_STRING(&_96$$24, "float");
		ZEPHIR_CALL_METHOD(&_95$$24, this_ptr, "getstyle", &_4, 0, &_96$$24);
		zephir_check_call_status();
		zephir_array_update_string(&_94$$24, SL(":style"), &_95$$24, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_94$$24, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_96$$24);
		ZVAL_STRING(&_96$$24, "<b style=':style'>Float</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_95$$24, "strtr", &_5, 55, &_96$$24, &_94$$24);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_95$$24);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_97$$25);
		zephir_create_array(&_97$$25, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_99$$25);
		ZVAL_STRING(&_99$$25, "num");
		ZEPHIR_CALL_METHOD(&_98$$25, this_ptr, "getstyle", &_4, 0, &_99$$25);
		zephir_check_call_status();
		zephir_array_update_string(&_97$$25, SL(":style"), &_98$$25, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_97$$25, SL(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_97$$25, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_99$$25);
		ZVAL_STRING(&_99$$25, "<b style=':style'>Numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		ZEPHIR_CALL_FUNCTION(&_98$$25, "strtr", &_5, 55, &_99$$25, &_97$$25);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_98$$25);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_100$$26);
		zephir_create_array(&_100$$26, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_102$$26);
		ZVAL_STRING(&_102$$26, "str");
		ZEPHIR_CALL_METHOD(&_101$$26, this_ptr, "getstyle", &_4, 0, &_102$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_100$$26, SL(":style"), &_101$$26, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_100$$26, SL(":length"), zephir_fast_strlen_ev(variable));
		ZVAL_LONG(&_103$$26, 4);
		ZEPHIR_INIT_NVAR(&_102$$26);
		ZVAL_STRING(&_102$$26, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_101$$26, "htmlentities", NULL, 162, variable, &_103$$26, &_102$$26);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_104$$26, "nl2br", NULL, 182, &_101$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_100$$26, SL(":var"), &_104$$26, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_102$$26);
		ZVAL_STRING(&_102$$26, "<b style=':style'>String</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		ZEPHIR_CALL_FUNCTION(&_104$$26, "strtr", &_5, 55, &_102$$26, &_100$$26);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_104$$26);
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE)) {
		ZEPHIR_INIT_VAR(&_105$$27);
		zephir_create_array(&_105$$27, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_107$$27);
		ZVAL_STRING(&_107$$27, "bool");
		ZEPHIR_CALL_METHOD(&_106$$27, this_ptr, "getstyle", &_4, 0, &_107$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_105$$27, SL(":style"), &_106$$27, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_108$$27);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_108$$27);
			ZVAL_STRING(&_108$$27, "TRUE");
		} else {
			ZEPHIR_INIT_NVAR(&_108$$27);
			ZVAL_STRING(&_108$$27, "FALSE");
		}
		zephir_array_update_string(&_105$$27, SL(":var"), &_108$$27, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_107$$27);
		ZVAL_STRING(&_107$$27, "<b style=':style'>Boolean</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_106$$27, "strtr", &_5, 55, &_107$$27, &_105$$27);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_106$$27);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_109$$28);
		zephir_create_array(&_109$$28, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_111$$28);
		ZVAL_STRING(&_111$$28, "null");
		ZEPHIR_CALL_METHOD(&_110$$28, this_ptr, "getstyle", &_4, 0, &_111$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_109$$28, SL(":style"), &_110$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_111$$28);
		ZVAL_STRING(&_111$$28, "<b style=':style'>NULL</b>");
		ZEPHIR_CALL_FUNCTION(&_110$$28, "strtr", &_5, 55, &_111$$28, &_109$$28);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_110$$28);
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
	ZEPHIR_CALL_FUNCTION(&_113, "strtr", &_5, 55, &_114, &_112);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_113);
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

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *variable, variable_sub, *name_param = NULL, _1, _2;
	ZEPHIR_INIT_THIS();

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
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 55, &_2, &_0);
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

	zend_string *_3;
	zend_ulong _2;
	zval key, value, output, _0, *_1, _4$$3, _5$$3;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	ZEPHIR_CALL_FUNCTION(&_0, "func_get_args", NULL, 175);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/debug/dump.zep", 290);
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

	zval *variable, variable_sub, _0;
	ZEPHIR_INIT_THIS();

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

