
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/main.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_debug_dump_ce, SL("detailed"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_debug_dump_ce, SL("methods"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_debug_dump_ce, SL("styles"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_debug_dump_ce->create_object = zephir_init_properties_Phalcon_Debug_Dump;
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Debug_Dump, getDetailed) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "detailed");

}

/**
 */
PHP_METHOD(Phalcon_Debug_Dump, setDetailed) {

	zval *detailed_param = NULL, __$true, __$false;
	zend_bool detailed;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &detailed_param);

	detailed = zephir_get_boolval(detailed_param);


	if (detailed) {
		zephir_update_property_zval(this_ptr, SL("detailed"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("detailed"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Phalcon\Debug\Dump constructor
 *
 * @param bool detailed debug object's private and protected properties
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
	ZEPHIR_OBS_COPY_OR_DUP(&styles, styles_param);
	}
	if (!detailed_param) {
		detailed = 0;
	} else {
		detailed = zephir_get_boolval(detailed_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstyles", NULL, 0, &styles);
	zephir_check_call_status();
	if (detailed) {
		zephir_update_property_zval(this_ptr, SL("detailed"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("detailed"), &__$false);
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
	ZEPHIR_OBS_COPY_OR_DUP(&styles, styles_param);
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
	zephir_update_property_zval(this_ptr, SL("styles"), &_0);
	RETURN_MM_MEMBER(getThis(), "styles");

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
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 66, &_2, &_0);
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
	zval output;
	zval key, value, _0, *_1, _4$$3, _5$$3;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&output);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_args(&_0);
	zephir_is_iterable(&_0, 0, "phalcon/Debug/Dump.zep", 186);
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
	RETURN_CTOR(&output);

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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	zephir_read_property(&_0, this_ptr, SL("styles"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&style, &_0, &type, 1 TSRMLS_CC))) {
		RETURN_MM_STRING("color:gray");
	}
	RETURN_CTOR(&style);

}

/**
 * Prepare an HTML string of information about a single variable.
 */
PHP_METHOD(Phalcon_Debug_Dump, output) {

	zend_class_entry *_52$$13;
	zend_bool _14$$5, _15$$5, _16$$5, _30$$7;
	zend_string *_6$$4, *_37$$10;
	zend_ulong _5$$4, _36$$10;
	zval _114, _1$$4, _10$$5, _22$$7, _67$$7, _26$$8, _40$$11, _57$$13, _77$$17, _83$$18, _92$$19, _96$$20, _99$$21, _102$$22, _107$$23, _111$$24;
	zephir_fcall_cache_entry *_9 = NULL, *_18 = NULL, *_49 = NULL, *_50 = NULL, *_53 = NULL, *_55 = NULL, *_63 = NULL;
	zend_long tab, ZEPHIR_LAST_CALL_STATUS;
	zval name, _0$$3;
	zval *variable, variable_sub, *name_param = NULL, *tab_param = NULL, key, value, output, space, type, attr, _95, _115, _116, _2$$4, _3$$4, *_4$$4, _20$$4, _21$$4, _7$$5, _8$$5, _11$$5, _12$$5, _13$$5, _17$$5, _19$$5, _23$$7, _24$$7, _25$$7, _29$$7, _65$$7, _66$$7, _68$$7, _69$$7, _90$$7, _91$$7, _27$$8, _28$$8, _31$$9, _32$$9, _33$$9, _34$$10, *_35$$10, _38$$11, _39$$11, _41$$11, _42$$11, _43$$11, _44$$11, _45$$11, reflect$$12, props$$12, property$$12, _46$$12, *_47$$12, _48$$13, _51$$13, _54$$13, _56$$13, _58$$13, _59$$13, _60$$13, _61$$13, _62$$13, _64$$13, _70$$14, _71$$14, _72$$14, *_73$$15, _87$$15, _88$$15, _89$$15, _74$$16, _75$$17, _76$$17, _78$$17, _79$$17, _80$$17, _81$$18, _82$$18, _84$$18, _85$$18, _86$$18, _93$$19, _94$$19, _97$$20, _98$$20, _100$$21, _101$$21, _103$$22, _104$$22, _105$$22, _106$$22, _108$$23, _109$$23, _110$$23, _112$$24, _113$$24;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&space);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&attr);
	ZVAL_UNDEF(&_95);
	ZVAL_UNDEF(&_115);
	ZVAL_UNDEF(&_116);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_65$$7);
	ZVAL_UNDEF(&_66$$7);
	ZVAL_UNDEF(&_68$$7);
	ZVAL_UNDEF(&_69$$7);
	ZVAL_UNDEF(&_90$$7);
	ZVAL_UNDEF(&_91$$7);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_31$$9);
	ZVAL_UNDEF(&_32$$9);
	ZVAL_UNDEF(&_33$$9);
	ZVAL_UNDEF(&_34$$10);
	ZVAL_UNDEF(&_38$$11);
	ZVAL_UNDEF(&_39$$11);
	ZVAL_UNDEF(&_41$$11);
	ZVAL_UNDEF(&_42$$11);
	ZVAL_UNDEF(&_43$$11);
	ZVAL_UNDEF(&_44$$11);
	ZVAL_UNDEF(&_45$$11);
	ZVAL_UNDEF(&reflect$$12);
	ZVAL_UNDEF(&props$$12);
	ZVAL_UNDEF(&property$$12);
	ZVAL_UNDEF(&_46$$12);
	ZVAL_UNDEF(&_48$$13);
	ZVAL_UNDEF(&_51$$13);
	ZVAL_UNDEF(&_54$$13);
	ZVAL_UNDEF(&_56$$13);
	ZVAL_UNDEF(&_58$$13);
	ZVAL_UNDEF(&_59$$13);
	ZVAL_UNDEF(&_60$$13);
	ZVAL_UNDEF(&_61$$13);
	ZVAL_UNDEF(&_62$$13);
	ZVAL_UNDEF(&_64$$13);
	ZVAL_UNDEF(&_70$$14);
	ZVAL_UNDEF(&_71$$14);
	ZVAL_UNDEF(&_72$$14);
	ZVAL_UNDEF(&_87$$15);
	ZVAL_UNDEF(&_88$$15);
	ZVAL_UNDEF(&_89$$15);
	ZVAL_UNDEF(&_74$$16);
	ZVAL_UNDEF(&_75$$17);
	ZVAL_UNDEF(&_76$$17);
	ZVAL_UNDEF(&_78$$17);
	ZVAL_UNDEF(&_79$$17);
	ZVAL_UNDEF(&_80$$17);
	ZVAL_UNDEF(&_81$$18);
	ZVAL_UNDEF(&_82$$18);
	ZVAL_UNDEF(&_84$$18);
	ZVAL_UNDEF(&_85$$18);
	ZVAL_UNDEF(&_86$$18);
	ZVAL_UNDEF(&_93$$19);
	ZVAL_UNDEF(&_94$$19);
	ZVAL_UNDEF(&_97$$20);
	ZVAL_UNDEF(&_98$$20);
	ZVAL_UNDEF(&_100$$21);
	ZVAL_UNDEF(&_101$$21);
	ZVAL_UNDEF(&_103$$22);
	ZVAL_UNDEF(&_104$$22);
	ZVAL_UNDEF(&_105$$22);
	ZVAL_UNDEF(&_106$$22);
	ZVAL_UNDEF(&_108$$23);
	ZVAL_UNDEF(&_109$$23);
	ZVAL_UNDEF(&_110$$23);
	ZVAL_UNDEF(&_112$$24);
	ZVAL_UNDEF(&_113$$24);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_114);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_67$$7);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_40$$11);
	ZVAL_UNDEF(&_57$$13);
	ZVAL_UNDEF(&_77$$17);
	ZVAL_UNDEF(&_83$$18);
	ZVAL_UNDEF(&_92$$19);
	ZVAL_UNDEF(&_96$$20);
	ZVAL_UNDEF(&_99$$21);
	ZVAL_UNDEF(&_102$$22);
	ZVAL_UNDEF(&_107$$23);
	ZVAL_UNDEF(&_111$$24);

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
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getstyle", NULL, 0, &_3$$4);
		zephir_check_call_status();
		zephir_array_update_string(&_1$$4, SL(":style"), &_2$$4, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_1$$4, SL(":count"), zephir_fast_count_int(variable TSRMLS_CC));
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "<b style =':style'>Array</b> (<span style =':style'>:count</span>) (\n");
		ZEPHIR_CALL_FUNCTION(&_2$$4, "strtr", NULL, 66, &_3$$4, &_1$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, &_2$$4 TSRMLS_CC);
		zephir_is_iterable(variable, 0, "phalcon/Debug/Dump.zep", 236);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(variable), _5$$4, _6$$4, _4$$4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_6$$4 != NULL) { 
				ZVAL_STR_COPY(&key, _6$$4);
			} else {
				ZVAL_LONG(&key, _5$$4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _4$$4);
			ZVAL_LONG(&_7$$5, tab);
			ZEPHIR_CALL_FUNCTION(&_8$$5, "str_repeat", &_9, 161, &space, &_7$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_10$$5);
			zephir_create_array(&_10$$5, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_12$$5);
			ZVAL_STRING(&_12$$5, "arr");
			ZEPHIR_CALL_METHOD(&_11$$5, this_ptr, "getstyle", NULL, 0, &_12$$5);
			zephir_check_call_status();
			zephir_array_update_string(&_10$$5, SL(":style"), &_11$$5, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_10$$5, SL(":key"), &key, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_12$$5);
			ZVAL_STRING(&_12$$5, "[<span style=':style'>:key</span>] => ");
			ZEPHIR_CALL_FUNCTION(&_11$$5, "strtr", NULL, 66, &_12$$5, &_10$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_13$$5);
			ZEPHIR_CONCAT_VV(&_13$$5, &_8$$5, &_11$$5);
			zephir_concat_self(&output, &_13$$5 TSRMLS_CC);
			_14$$5 = tab == 1;
			if (_14$$5) {
				_14$$5 = !ZEPHIR_IS_STRING(&name, "");
			}
			_15$$5 = _14$$5;
			if (_15$$5) {
				_15$$5 = !(Z_TYPE_P(&key) == IS_LONG);
			}
			_16$$5 = _15$$5;
			if (_16$$5) {
				_16$$5 = ZEPHIR_IS_EQUAL(&name, &key);
			}
			if (_16$$5) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_12$$5);
			ZVAL_STRING(&_12$$5, "");
			ZVAL_LONG(&_7$$5, (tab + 1));
			ZEPHIR_CALL_METHOD(&_17$$5, this_ptr, "output", &_18, 187, &value, &_12$$5, &_7$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_19$$5);
			ZEPHIR_CONCAT_VS(&_19$$5, &_17$$5, "\n");
			zephir_concat_self(&output, &_19$$5 TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_20$$4, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_21$$4, "str_repeat", &_9, 161, &space, &_20$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_21$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_22$$7);
		zephir_create_array(&_22$$7, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_24$$7);
		ZVAL_STRING(&_24$$7, "obj");
		ZEPHIR_CALL_METHOD(&_23$$7, this_ptr, "getstyle", NULL, 0, &_24$$7);
		zephir_check_call_status();
		zephir_array_update_string(&_22$$7, SL(":style"), &_23$$7, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_24$$7);
		zephir_get_class(&_24$$7, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_22$$7, SL(":class"), &_24$$7, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_24$$7);
		ZVAL_STRING(&_24$$7, "<b style=':style'>Object</b> :class");
		ZEPHIR_CALL_FUNCTION(&_23$$7, "strtr", NULL, 66, &_24$$7, &_22$$7);
		zephir_check_call_status();
		zephir_concat_self(&output, &_23$$7 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_25$$7, "get_parent_class", NULL, 188, variable);
		zephir_check_call_status();
		if (zephir_is_true(&_25$$7)) {
			ZEPHIR_INIT_VAR(&_26$$8);
			zephir_create_array(&_26$$8, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_28$$8);
			ZVAL_STRING(&_28$$8, "obj");
			ZEPHIR_CALL_METHOD(&_27$$8, this_ptr, "getstyle", NULL, 0, &_28$$8);
			zephir_check_call_status();
			zephir_array_update_string(&_26$$8, SL(":style"), &_27$$8, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_27$$8, "get_parent_class", NULL, 188, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_26$$8, SL(":parent"), &_27$$8, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_28$$8);
			ZVAL_STRING(&_28$$8, " <b style=':style'>extends</b> :parent");
			ZEPHIR_CALL_FUNCTION(&_27$$8, "strtr", NULL, 66, &_28$$8, &_26$$8);
			zephir_check_call_status();
			zephir_concat_self(&output, &_27$$8 TSRMLS_CC);
		}
		zephir_concat_self_str(&output, SL(" (\n") TSRMLS_CC);
		zephir_read_property(&_29$$7, this_ptr, SL("detailed"), PH_NOISY_CC | PH_READONLY);
		_30$$7 = !zephir_is_true(&_29$$7);
		if (!(_30$$7)) {
			_30$$7 = zephir_instance_of_ev(variable, zend_standard_class_def TSRMLS_CC);
		}
		if (zephir_instance_of_ev(variable, phalcon_di_ce TSRMLS_CC)) {
			ZVAL_LONG(&_31$$9, tab);
			ZEPHIR_CALL_FUNCTION(&_32$$9, "str_repeat", &_9, 161, &space, &_31$$9);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_33$$9);
			ZEPHIR_CONCAT_VS(&_33$$9, &_32$$9, "[skipped]\n");
			zephir_concat_self(&output, &_33$$9 TSRMLS_CC);
		} else if (_30$$7) {
			ZEPHIR_CALL_FUNCTION(&_34$$10, "get_object_vars", NULL, 7, variable);
			zephir_check_call_status();
			zephir_is_iterable(&_34$$10, 0, "phalcon/Debug/Dump.zep", 268);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_34$$10), _36$$10, _37$$10, _35$$10)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_37$$10 != NULL) { 
					ZVAL_STR_COPY(&key, _37$$10);
				} else {
					ZVAL_LONG(&key, _36$$10);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _35$$10);
				ZVAL_LONG(&_38$$11, tab);
				ZEPHIR_CALL_FUNCTION(&_39$$11, "str_repeat", &_9, 161, &space, &_38$$11);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_40$$11);
				zephir_create_array(&_40$$11, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_42$$11);
				ZVAL_STRING(&_42$$11, "obj");
				ZEPHIR_CALL_METHOD(&_41$$11, this_ptr, "getstyle", NULL, 0, &_42$$11);
				zephir_check_call_status();
				zephir_array_update_string(&_40$$11, SL(":style"), &_41$$11, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_40$$11, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(&_40$$11, SL(":type"), SL("public"));
				ZEPHIR_INIT_NVAR(&_42$$11);
				ZVAL_STRING(&_42$$11, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
				ZEPHIR_CALL_FUNCTION(&_41$$11, "strtr", NULL, 66, &_42$$11, &_40$$11);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_43$$11);
				ZEPHIR_CONCAT_VV(&_43$$11, &_39$$11, &_41$$11);
				zephir_concat_self(&output, &_43$$11 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_42$$11);
				ZVAL_STRING(&_42$$11, "");
				ZVAL_LONG(&_38$$11, (tab + 1));
				ZEPHIR_CALL_METHOD(&_44$$11, this_ptr, "output", &_18, 187, &value, &_42$$11, &_38$$11);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_45$$11);
				ZEPHIR_CONCAT_VS(&_45$$11, &_44$$11, "\n");
				zephir_concat_self(&output, &_45$$11 TSRMLS_CC);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&key);
		} else {
			ZEPHIR_INIT_VAR(&reflect$$12);
			object_init_ex(&reflect$$12, zephir_get_internal_ce(SL("reflectionclass")));
			ZEPHIR_CALL_METHOD(NULL, &reflect$$12, "__construct", NULL, 120, variable);
			zephir_check_call_status();
			ZVAL_LONG(&_46$$12, ((256 | 512) | 1024));
			ZEPHIR_CALL_METHOD(&props$$12, &reflect$$12, "getproperties", NULL, 124, &_46$$12);
			zephir_check_call_status();
			zephir_is_iterable(&props$$12, 0, "phalcon/Debug/Dump.zep", 294);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&props$$12), _47$$12)
			{
				ZEPHIR_INIT_NVAR(&property$$12);
				ZVAL_COPY(&property$$12, _47$$12);
				ZVAL_BOOL(&_48$$13, 1);
				ZEPHIR_CALL_METHOD(NULL, &property$$12, "setaccessible", &_49, 0, &_48$$13);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&key, &property$$12, "getname", &_50, 0);
				zephir_check_call_status();
				_52$$13 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
				ZEPHIR_CALL_METHOD(&_54$$13, &property$$12, "getmodifiers", &_55, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_CE_STATIC(&_51$$13, _52$$13, "getmodifiernames", &_53, 0, &_54$$13);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&type);
				zephir_fast_join_str(&type, SL(" "), &_51$$13 TSRMLS_CC);
				ZVAL_LONG(&_48$$13, tab);
				ZEPHIR_CALL_FUNCTION(&_56$$13, "str_repeat", &_9, 161, &space, &_48$$13);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_57$$13);
				zephir_create_array(&_57$$13, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_59$$13);
				ZVAL_STRING(&_59$$13, "obj");
				ZEPHIR_CALL_METHOD(&_58$$13, this_ptr, "getstyle", NULL, 0, &_59$$13);
				zephir_check_call_status();
				zephir_array_update_string(&_57$$13, SL(":style"), &_58$$13, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_57$$13, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_57$$13, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_59$$13);
				ZVAL_STRING(&_59$$13, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
				ZEPHIR_CALL_FUNCTION(&_58$$13, "strtr", NULL, 66, &_59$$13, &_57$$13);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_60$$13);
				ZEPHIR_CONCAT_VV(&_60$$13, &_56$$13, &_58$$13);
				zephir_concat_self(&output, &_60$$13 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_62$$13, &property$$12, "getvalue", &_63, 0, variable);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_59$$13);
				ZVAL_STRING(&_59$$13, "");
				ZVAL_LONG(&_48$$13, (tab + 1));
				ZEPHIR_CALL_METHOD(&_61$$13, this_ptr, "output", &_18, 187, &_62$$13, &_59$$13, &_48$$13);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_64$$13);
				ZEPHIR_CONCAT_VS(&_64$$13, &_61$$13, "\n");
				zephir_concat_self(&output, &_64$$13 TSRMLS_CC);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&property$$12);
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 189, variable);
		zephir_check_call_status();
		ZVAL_LONG(&_65$$7, tab);
		ZEPHIR_CALL_FUNCTION(&_66$$7, "str_repeat", &_9, 161, &space, &_65$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_67$$7);
		zephir_create_array(&_67$$7, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_24$$7);
		ZVAL_STRING(&_24$$7, "obj");
		ZEPHIR_CALL_METHOD(&_68$$7, this_ptr, "getstyle", NULL, 0, &_24$$7);
		zephir_check_call_status();
		zephir_array_update_string(&_67$$7, SL(":style"), &_68$$7, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_24$$7);
		zephir_get_class(&_24$$7, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_67$$7, SL(":class"), &_24$$7, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_67$$7, SL(":count"), zephir_fast_count_int(&attr TSRMLS_CC));
		ZEPHIR_INIT_NVAR(&_24$$7);
		ZVAL_STRING(&_24$$7, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n");
		ZEPHIR_CALL_FUNCTION(&_68$$7, "strtr", NULL, 66, &_24$$7, &_67$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_69$$7);
		ZEPHIR_CONCAT_VV(&_69$$7, &_66$$7, &_68$$7);
		zephir_concat_self(&output, &_69$$7 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_24$$7);
		zephir_get_class(&_24$$7, variable, 0 TSRMLS_CC);
		zephir_read_property(&_65$$7, this_ptr, SL("methods"), PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&_24$$7, &_65$$7 TSRMLS_CC)) {
			ZVAL_LONG(&_70$$14, tab);
			ZEPHIR_CALL_FUNCTION(&_71$$14, "str_repeat", &_9, 161, &space, &_70$$14);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_72$$14);
			ZEPHIR_CONCAT_VS(&_72$$14, &_71$$14, "[already listed]\n");
			zephir_concat_self(&output, &_72$$14 TSRMLS_CC);
		} else {
			zephir_is_iterable(&attr, 0, "phalcon/Debug/Dump.zep", 312);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attr), _73$$15)
			{
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _73$$15);
				ZEPHIR_INIT_NVAR(&_74$$16);
				zephir_get_class(&_74$$16, variable, 0 TSRMLS_CC);
				zephir_update_property_array_append(this_ptr, SL("methods"), &_74$$16 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(&value, "__construct")) {
					ZVAL_LONG(&_75$$17, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_76$$17, "str_repeat", &_9, 161, &space, &_75$$17);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_77$$17);
					zephir_create_array(&_77$$17, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_79$$17);
					ZVAL_STRING(&_79$$17, "obj");
					ZEPHIR_CALL_METHOD(&_78$$17, this_ptr, "getstyle", NULL, 0, &_79$$17);
					zephir_check_call_status();
					zephir_array_update_string(&_77$$17, SL(":style"), &_78$$17, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_77$$17, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_79$$17);
					ZVAL_STRING(&_79$$17, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n");
					ZEPHIR_CALL_FUNCTION(&_78$$17, "strtr", NULL, 66, &_79$$17, &_77$$17);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_80$$17);
					ZEPHIR_CONCAT_VV(&_80$$17, &_76$$17, &_78$$17);
					zephir_concat_self(&output, &_80$$17 TSRMLS_CC);
				} else {
					ZVAL_LONG(&_81$$18, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_82$$18, "str_repeat", &_9, 161, &space, &_81$$18);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_83$$18);
					zephir_create_array(&_83$$18, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_85$$18);
					ZVAL_STRING(&_85$$18, "obj");
					ZEPHIR_CALL_METHOD(&_84$$18, this_ptr, "getstyle", NULL, 0, &_85$$18);
					zephir_check_call_status();
					zephir_array_update_string(&_83$$18, SL(":style"), &_84$$18, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_83$$18, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_85$$18);
					ZVAL_STRING(&_85$$18, "-><span style=':style'>:method</span>();\n");
					ZEPHIR_CALL_FUNCTION(&_84$$18, "strtr", NULL, 66, &_85$$18, &_83$$18);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_86$$18);
					ZEPHIR_CONCAT_VV(&_86$$18, &_82$$18, &_84$$18);
					zephir_concat_self(&output, &_86$$18 TSRMLS_CC);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_LONG(&_87$$15, tab);
			ZEPHIR_CALL_FUNCTION(&_88$$15, "str_repeat", &_9, 161, &space, &_87$$15);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_89$$15);
			ZEPHIR_CONCAT_VS(&_89$$15, &_88$$15, ")\n");
			zephir_concat_self(&output, &_89$$15 TSRMLS_CC);
		}
		ZVAL_LONG(&_90$$7, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_91$$7, "str_repeat", &_9, 161, &space, &_90$$7);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_91$$7, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_92$$19);
		zephir_create_array(&_92$$19, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_94$$19);
		ZVAL_STRING(&_94$$19, "int");
		ZEPHIR_CALL_METHOD(&_93$$19, this_ptr, "getstyle", NULL, 0, &_94$$19);
		zephir_check_call_status();
		zephir_array_update_string(&_92$$19, SL(":style"), &_93$$19, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_92$$19, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_94$$19);
		ZVAL_STRING(&_94$$19, "<b style=':style'>Integer</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_93$$19, "strtr", NULL, 66, &_94$$19, &_92$$19);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_93$$19);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_95, "is_float", NULL, 190, variable);
	zephir_check_call_status();
	if (zephir_is_true(&_95)) {
		ZEPHIR_INIT_VAR(&_96$$20);
		zephir_create_array(&_96$$20, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_98$$20);
		ZVAL_STRING(&_98$$20, "float");
		ZEPHIR_CALL_METHOD(&_97$$20, this_ptr, "getstyle", NULL, 0, &_98$$20);
		zephir_check_call_status();
		zephir_array_update_string(&_96$$20, SL(":style"), &_97$$20, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_96$$20, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_98$$20);
		ZVAL_STRING(&_98$$20, "<b style=':style'>Float</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_97$$20, "strtr", NULL, 66, &_98$$20, &_96$$20);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_97$$20);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_99$$21);
		zephir_create_array(&_99$$21, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_101$$21);
		ZVAL_STRING(&_101$$21, "num");
		ZEPHIR_CALL_METHOD(&_100$$21, this_ptr, "getstyle", NULL, 0, &_101$$21);
		zephir_check_call_status();
		zephir_array_update_string(&_99$$21, SL(":style"), &_100$$21, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_99$$21, SL(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_99$$21, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_101$$21);
		ZVAL_STRING(&_101$$21, "<b style=':style'>Numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		ZEPHIR_CALL_FUNCTION(&_100$$21, "strtr", NULL, 66, &_101$$21, &_99$$21);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_100$$21);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_102$$22);
		zephir_create_array(&_102$$22, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_104$$22);
		ZVAL_STRING(&_104$$22, "str");
		ZEPHIR_CALL_METHOD(&_103$$22, this_ptr, "getstyle", NULL, 0, &_104$$22);
		zephir_check_call_status();
		zephir_array_update_string(&_102$$22, SL(":style"), &_103$$22, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_102$$22, SL(":length"), zephir_fast_strlen_ev(variable));
		ZVAL_LONG(&_105$$22, 4);
		ZEPHIR_INIT_NVAR(&_104$$22);
		ZVAL_STRING(&_104$$22, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_103$$22, "htmlentities", NULL, 182, variable, &_105$$22, &_104$$22);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_106$$22, "nl2br", NULL, 191, &_103$$22);
		zephir_check_call_status();
		zephir_array_update_string(&_102$$22, SL(":var"), &_106$$22, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_104$$22);
		ZVAL_STRING(&_104$$22, "<b style=':style'>String</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		ZEPHIR_CALL_FUNCTION(&_106$$22, "strtr", NULL, 66, &_104$$22, &_102$$22);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_106$$22);
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE)) {
		ZEPHIR_INIT_VAR(&_107$$23);
		zephir_create_array(&_107$$23, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_109$$23);
		ZVAL_STRING(&_109$$23, "bool");
		ZEPHIR_CALL_METHOD(&_108$$23, this_ptr, "getstyle", NULL, 0, &_109$$23);
		zephir_check_call_status();
		zephir_array_update_string(&_107$$23, SL(":style"), &_108$$23, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_110$$23);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_110$$23);
			ZVAL_STRING(&_110$$23, "TRUE");
		} else {
			ZEPHIR_INIT_NVAR(&_110$$23);
			ZVAL_STRING(&_110$$23, "FALSE");
		}
		zephir_array_update_string(&_107$$23, SL(":var"), &_110$$23, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_109$$23);
		ZVAL_STRING(&_109$$23, "<b style=':style'>Boolean</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_108$$23, "strtr", NULL, 66, &_109$$23, &_107$$23);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_108$$23);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_111$$24);
		zephir_create_array(&_111$$24, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_113$$24);
		ZVAL_STRING(&_113$$24, "null");
		ZEPHIR_CALL_METHOD(&_112$$24, this_ptr, "getstyle", NULL, 0, &_113$$24);
		zephir_check_call_status();
		zephir_array_update_string(&_111$$24, SL(":style"), &_112$$24, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_113$$24);
		ZVAL_STRING(&_113$$24, "<b style=':style'>NULL</b>");
		ZEPHIR_CALL_FUNCTION(&_112$$24, "strtr", NULL, 66, &_113$$24, &_111$$24);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_112$$24);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_114);
	zephir_create_array(&_114, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_116);
	ZVAL_STRING(&_116, "other");
	ZEPHIR_CALL_METHOD(&_115, this_ptr, "getstyle", NULL, 0, &_116);
	zephir_check_call_status();
	zephir_array_update_string(&_114, SL(":style"), &_115, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_114, SL(":var"), variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_116);
	ZVAL_STRING(&_116, "(<span style=':style'>:var</span>)");
	ZEPHIR_CALL_FUNCTION(&_115, "strtr", NULL, 66, &_116, &_114);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_115);
	RETURN_MM();

}

zend_object *zephir_init_properties_Phalcon_Debug_Dump(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("styles"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("styles"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("methods"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("methods"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

