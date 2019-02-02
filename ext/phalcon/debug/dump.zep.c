
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
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 50, &_2, &_0);
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
	zephir_is_iterable(&_0, 0, "phalcon/debug/dump.zep", 169);
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
	if (zephir_array_isset_fetch(&style, &_0, &type, 1 TSRMLS_CC)) {
		RETURN_CTOR(&style);
	} else {
		RETURN_MM_STRING("color:gray");
	}

}

/**
 * Prepare an HTML string of information about a single variable.
 */
PHP_METHOD(Phalcon_Debug_Dump, output) {

	zend_class_entry *_54$$14;
	zend_bool _14$$5, _15$$5, _16$$5, _32$$8;
	zend_string *_6$$4, *_39$$11;
	zend_ulong _5$$4, _38$$11;
	zval _117, _1$$4, _10$$5, _24$$8, _70$$8, _28$$9, _42$$12, _60$$14, _80$$18, _86$$19, _95$$20, _99$$21, _102$$22, _105$$23, _110$$24, _114$$25;
	zephir_fcall_cache_entry *_9 = NULL, *_20 = NULL, *_51 = NULL, *_52 = NULL, *_55 = NULL, *_57 = NULL, *_66 = NULL;
	zend_long tab, ZEPHIR_LAST_CALL_STATUS;
	zval name, _0$$3;
	zval *variable, variable_sub, *name_param = NULL, *tab_param = NULL, key, value, output, space, type, attr, _98, _118, _119, _2$$4, _3$$4, *_4$$4, _22$$4, _23$$4, _7$$5, _8$$5, _11$$5, _12$$5, _13$$5, _17$$7, _18$$7, _19$$7, _21$$7, _25$$8, _26$$8, _27$$8, _31$$8, _68$$8, _69$$8, _71$$8, _72$$8, _93$$8, _94$$8, _29$$9, _30$$9, _33$$10, _34$$10, _35$$10, _36$$11, *_37$$11, _40$$12, _41$$12, _43$$12, _44$$12, _45$$12, _46$$12, _47$$12, reflect$$13, props$$13, property$$13, _48$$13, *_49$$13, _50$$14, _53$$14, _56$$14, _58$$14, _59$$14, _61$$14, _62$$14, _63$$14, _64$$14, _65$$14, _67$$14, _73$$15, _74$$15, _75$$15, *_76$$16, _90$$16, _91$$16, _92$$16, _77$$17, _78$$18, _79$$18, _81$$18, _82$$18, _83$$18, _84$$19, _85$$19, _87$$19, _88$$19, _89$$19, _96$$20, _97$$20, _100$$21, _101$$21, _103$$22, _104$$22, _106$$23, _107$$23, _108$$23, _109$$23, _111$$24, _112$$24, _113$$24, _115$$25, _116$$25;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&space);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&attr);
	ZVAL_UNDEF(&_98);
	ZVAL_UNDEF(&_118);
	ZVAL_UNDEF(&_119);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_23$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_68$$8);
	ZVAL_UNDEF(&_69$$8);
	ZVAL_UNDEF(&_71$$8);
	ZVAL_UNDEF(&_72$$8);
	ZVAL_UNDEF(&_93$$8);
	ZVAL_UNDEF(&_94$$8);
	ZVAL_UNDEF(&_29$$9);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_33$$10);
	ZVAL_UNDEF(&_34$$10);
	ZVAL_UNDEF(&_35$$10);
	ZVAL_UNDEF(&_36$$11);
	ZVAL_UNDEF(&_40$$12);
	ZVAL_UNDEF(&_41$$12);
	ZVAL_UNDEF(&_43$$12);
	ZVAL_UNDEF(&_44$$12);
	ZVAL_UNDEF(&_45$$12);
	ZVAL_UNDEF(&_46$$12);
	ZVAL_UNDEF(&_47$$12);
	ZVAL_UNDEF(&reflect$$13);
	ZVAL_UNDEF(&props$$13);
	ZVAL_UNDEF(&property$$13);
	ZVAL_UNDEF(&_48$$13);
	ZVAL_UNDEF(&_50$$14);
	ZVAL_UNDEF(&_53$$14);
	ZVAL_UNDEF(&_56$$14);
	ZVAL_UNDEF(&_58$$14);
	ZVAL_UNDEF(&_59$$14);
	ZVAL_UNDEF(&_61$$14);
	ZVAL_UNDEF(&_62$$14);
	ZVAL_UNDEF(&_63$$14);
	ZVAL_UNDEF(&_64$$14);
	ZVAL_UNDEF(&_65$$14);
	ZVAL_UNDEF(&_67$$14);
	ZVAL_UNDEF(&_73$$15);
	ZVAL_UNDEF(&_74$$15);
	ZVAL_UNDEF(&_75$$15);
	ZVAL_UNDEF(&_90$$16);
	ZVAL_UNDEF(&_91$$16);
	ZVAL_UNDEF(&_92$$16);
	ZVAL_UNDEF(&_77$$17);
	ZVAL_UNDEF(&_78$$18);
	ZVAL_UNDEF(&_79$$18);
	ZVAL_UNDEF(&_81$$18);
	ZVAL_UNDEF(&_82$$18);
	ZVAL_UNDEF(&_83$$18);
	ZVAL_UNDEF(&_84$$19);
	ZVAL_UNDEF(&_85$$19);
	ZVAL_UNDEF(&_87$$19);
	ZVAL_UNDEF(&_88$$19);
	ZVAL_UNDEF(&_89$$19);
	ZVAL_UNDEF(&_96$$20);
	ZVAL_UNDEF(&_97$$20);
	ZVAL_UNDEF(&_100$$21);
	ZVAL_UNDEF(&_101$$21);
	ZVAL_UNDEF(&_103$$22);
	ZVAL_UNDEF(&_104$$22);
	ZVAL_UNDEF(&_106$$23);
	ZVAL_UNDEF(&_107$$23);
	ZVAL_UNDEF(&_108$$23);
	ZVAL_UNDEF(&_109$$23);
	ZVAL_UNDEF(&_111$$24);
	ZVAL_UNDEF(&_112$$24);
	ZVAL_UNDEF(&_113$$24);
	ZVAL_UNDEF(&_115$$25);
	ZVAL_UNDEF(&_116$$25);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_117);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_70$$8);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_42$$12);
	ZVAL_UNDEF(&_60$$14);
	ZVAL_UNDEF(&_80$$18);
	ZVAL_UNDEF(&_86$$19);
	ZVAL_UNDEF(&_95$$20);
	ZVAL_UNDEF(&_99$$21);
	ZVAL_UNDEF(&_102$$22);
	ZVAL_UNDEF(&_105$$23);
	ZVAL_UNDEF(&_110$$24);
	ZVAL_UNDEF(&_114$$25);

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
		ZEPHIR_CALL_FUNCTION(&_2$$4, "strtr", NULL, 50, &_3$$4, &_1$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, &_2$$4 TSRMLS_CC);
		zephir_is_iterable(variable, 0, "phalcon/debug/dump.zep", 217);
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
			ZEPHIR_CALL_FUNCTION(&_8$$5, "str_repeat", &_9, 127, &space, &_7$$5);
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
			ZEPHIR_CALL_FUNCTION(&_11$$5, "strtr", NULL, 50, &_12$$5, &_10$$5);
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
			} else {
				ZEPHIR_INIT_NVAR(&_18$$7);
				ZVAL_STRING(&_18$$7, "");
				ZVAL_LONG(&_19$$7, (tab + 1));
				ZEPHIR_CALL_METHOD(&_17$$7, this_ptr, "output", &_20, 165, &value, &_18$$7, &_19$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_21$$7);
				ZEPHIR_CONCAT_VS(&_21$$7, &_17$$7, "\n");
				zephir_concat_self(&output, &_21$$7 TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_22$$4, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_23$$4, "str_repeat", &_9, 127, &space, &_22$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_23$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_24$$8);
		zephir_create_array(&_24$$8, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_26$$8);
		ZVAL_STRING(&_26$$8, "obj");
		ZEPHIR_CALL_METHOD(&_25$$8, this_ptr, "getstyle", NULL, 0, &_26$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_24$$8, SL(":style"), &_25$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_26$$8);
		zephir_get_class(&_26$$8, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_24$$8, SL(":class"), &_26$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_26$$8);
		ZVAL_STRING(&_26$$8, "<b style=':style'>Object</b> :class");
		ZEPHIR_CALL_FUNCTION(&_25$$8, "strtr", NULL, 50, &_26$$8, &_24$$8);
		zephir_check_call_status();
		zephir_concat_self(&output, &_25$$8 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_27$$8, "get_parent_class", NULL, 166, variable);
		zephir_check_call_status();
		if (zephir_is_true(&_27$$8)) {
			ZEPHIR_INIT_VAR(&_28$$9);
			zephir_create_array(&_28$$9, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_30$$9);
			ZVAL_STRING(&_30$$9, "obj");
			ZEPHIR_CALL_METHOD(&_29$$9, this_ptr, "getstyle", NULL, 0, &_30$$9);
			zephir_check_call_status();
			zephir_array_update_string(&_28$$9, SL(":style"), &_29$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_29$$9, "get_parent_class", NULL, 166, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_28$$9, SL(":parent"), &_29$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_30$$9);
			ZVAL_STRING(&_30$$9, " <b style=':style'>extends</b> :parent");
			ZEPHIR_CALL_FUNCTION(&_29$$9, "strtr", NULL, 50, &_30$$9, &_28$$9);
			zephir_check_call_status();
			zephir_concat_self(&output, &_29$$9 TSRMLS_CC);
		}
		zephir_concat_self_str(&output, SL(" (\n") TSRMLS_CC);
		zephir_read_property(&_31$$8, this_ptr, SL("detailed"), PH_NOISY_CC | PH_READONLY);
		_32$$8 = !zephir_is_true(&_31$$8);
		if (!(_32$$8)) {
			_32$$8 = zephir_instance_of_ev(variable, zend_standard_class_def TSRMLS_CC);
		}
		if (zephir_instance_of_ev(variable, phalcon_di_ce TSRMLS_CC)) {
			ZVAL_LONG(&_33$$10, tab);
			ZEPHIR_CALL_FUNCTION(&_34$$10, "str_repeat", &_9, 127, &space, &_33$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_35$$10);
			ZEPHIR_CONCAT_VS(&_35$$10, &_34$$10, "[skipped]\n");
			zephir_concat_self(&output, &_35$$10 TSRMLS_CC);
		} else if (_32$$8) {
			ZEPHIR_CALL_FUNCTION(&_36$$11, "get_object_vars", NULL, 14, variable);
			zephir_check_call_status();
			zephir_is_iterable(&_36$$11, 0, "phalcon/debug/dump.zep", 249);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_36$$11), _38$$11, _39$$11, _37$$11)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_39$$11 != NULL) { 
					ZVAL_STR_COPY(&key, _39$$11);
				} else {
					ZVAL_LONG(&key, _38$$11);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _37$$11);
				ZVAL_LONG(&_40$$12, tab);
				ZEPHIR_CALL_FUNCTION(&_41$$12, "str_repeat", &_9, 127, &space, &_40$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_42$$12);
				zephir_create_array(&_42$$12, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_44$$12);
				ZVAL_STRING(&_44$$12, "obj");
				ZEPHIR_CALL_METHOD(&_43$$12, this_ptr, "getstyle", NULL, 0, &_44$$12);
				zephir_check_call_status();
				zephir_array_update_string(&_42$$12, SL(":style"), &_43$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_42$$12, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				add_assoc_stringl_ex(&_42$$12, SL(":type"), SL("public"));
				ZEPHIR_INIT_NVAR(&_44$$12);
				ZVAL_STRING(&_44$$12, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
				ZEPHIR_CALL_FUNCTION(&_43$$12, "strtr", NULL, 50, &_44$$12, &_42$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_45$$12);
				ZEPHIR_CONCAT_VV(&_45$$12, &_41$$12, &_43$$12);
				zephir_concat_self(&output, &_45$$12 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_44$$12);
				ZVAL_STRING(&_44$$12, "");
				ZVAL_LONG(&_40$$12, (tab + 1));
				ZEPHIR_CALL_METHOD(&_46$$12, this_ptr, "output", &_20, 165, &value, &_44$$12, &_40$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_47$$12);
				ZEPHIR_CONCAT_VS(&_47$$12, &_46$$12, "\n");
				zephir_concat_self(&output, &_47$$12 TSRMLS_CC);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&key);
		} else {
			ZEPHIR_INIT_VAR(&reflect$$13);
			object_init_ex(&reflect$$13, zephir_get_internal_ce(SL("reflectionclass")));
			ZEPHIR_CALL_METHOD(NULL, &reflect$$13, "__construct", NULL, 81, variable);
			zephir_check_call_status();
			ZVAL_LONG(&_48$$13, ((256 | 512) | 1024));
			ZEPHIR_CALL_METHOD(&props$$13, &reflect$$13, "getproperties", NULL, 85, &_48$$13);
			zephir_check_call_status();
			zephir_is_iterable(&props$$13, 0, "phalcon/debug/dump.zep", 269);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&props$$13), _49$$13)
			{
				ZEPHIR_INIT_NVAR(&property$$13);
				ZVAL_COPY(&property$$13, _49$$13);
				ZVAL_BOOL(&_50$$14, 1);
				ZEPHIR_CALL_METHOD(NULL, &property$$13, "setaccessible", &_51, 0, &_50$$14);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&key, &property$$13, "getname", &_52, 0);
				zephir_check_call_status();
				_54$$14 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
				ZEPHIR_CALL_METHOD(&_56$$14, &property$$13, "getmodifiers", &_57, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_CE_STATIC(&_53$$14, _54$$14, "getmodifiernames", &_55, 0, &_56$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_58$$14);
				ZVAL_STRING(&_58$$14, " ");
				ZEPHIR_INIT_NVAR(&type);
				zephir_fast_join(&type, &_58$$14, &_53$$14 TSRMLS_CC);
				ZVAL_LONG(&_50$$14, tab);
				ZEPHIR_CALL_FUNCTION(&_59$$14, "str_repeat", &_9, 127, &space, &_50$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_60$$14);
				zephir_create_array(&_60$$14, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_62$$14);
				ZVAL_STRING(&_62$$14, "obj");
				ZEPHIR_CALL_METHOD(&_61$$14, this_ptr, "getstyle", NULL, 0, &_62$$14);
				zephir_check_call_status();
				zephir_array_update_string(&_60$$14, SL(":style"), &_61$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_60$$14, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_60$$14, SL(":type"), &type, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_62$$14);
				ZVAL_STRING(&_62$$14, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
				ZEPHIR_CALL_FUNCTION(&_61$$14, "strtr", NULL, 50, &_62$$14, &_60$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_63$$14);
				ZEPHIR_CONCAT_VV(&_63$$14, &_59$$14, &_61$$14);
				zephir_concat_self(&output, &_63$$14 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_65$$14, &property$$13, "getvalue", &_66, 0, variable);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_62$$14);
				ZVAL_STRING(&_62$$14, "");
				ZVAL_LONG(&_50$$14, (tab + 1));
				ZEPHIR_CALL_METHOD(&_64$$14, this_ptr, "output", &_20, 165, &_65$$14, &_62$$14, &_50$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_67$$14);
				ZEPHIR_CONCAT_VS(&_67$$14, &_64$$14, "\n");
				zephir_concat_self(&output, &_67$$14 TSRMLS_CC);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&property$$13);
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 167, variable);
		zephir_check_call_status();
		ZVAL_LONG(&_68$$8, tab);
		ZEPHIR_CALL_FUNCTION(&_69$$8, "str_repeat", &_9, 127, &space, &_68$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_70$$8);
		zephir_create_array(&_70$$8, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_26$$8);
		ZVAL_STRING(&_26$$8, "obj");
		ZEPHIR_CALL_METHOD(&_71$$8, this_ptr, "getstyle", NULL, 0, &_26$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_70$$8, SL(":style"), &_71$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_26$$8);
		zephir_get_class(&_26$$8, variable, 0 TSRMLS_CC);
		zephir_array_update_string(&_70$$8, SL(":class"), &_26$$8, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_70$$8, SL(":count"), zephir_fast_count_int(&attr TSRMLS_CC));
		ZEPHIR_INIT_NVAR(&_26$$8);
		ZVAL_STRING(&_26$$8, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n");
		ZEPHIR_CALL_FUNCTION(&_71$$8, "strtr", NULL, 50, &_26$$8, &_70$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_72$$8);
		ZEPHIR_CONCAT_VV(&_72$$8, &_69$$8, &_71$$8);
		zephir_concat_self(&output, &_72$$8 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_26$$8);
		zephir_get_class(&_26$$8, variable, 0 TSRMLS_CC);
		zephir_read_property(&_68$$8, this_ptr, SL("methods"), PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&_26$$8, &_68$$8 TSRMLS_CC)) {
			ZVAL_LONG(&_73$$15, tab);
			ZEPHIR_CALL_FUNCTION(&_74$$15, "str_repeat", &_9, 127, &space, &_73$$15);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_75$$15);
			ZEPHIR_CONCAT_VS(&_75$$15, &_74$$15, "[already listed]\n");
			zephir_concat_self(&output, &_75$$15 TSRMLS_CC);
		} else {
			zephir_is_iterable(&attr, 0, "phalcon/debug/dump.zep", 286);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attr), _76$$16)
			{
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _76$$16);
				ZEPHIR_INIT_NVAR(&_77$$17);
				zephir_get_class(&_77$$17, variable, 0 TSRMLS_CC);
				zephir_update_property_array_append(this_ptr, SL("methods"), &_77$$17 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(&value, "__construct")) {
					ZVAL_LONG(&_78$$18, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_79$$18, "str_repeat", &_9, 127, &space, &_78$$18);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_80$$18);
					zephir_create_array(&_80$$18, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_82$$18);
					ZVAL_STRING(&_82$$18, "obj");
					ZEPHIR_CALL_METHOD(&_81$$18, this_ptr, "getstyle", NULL, 0, &_82$$18);
					zephir_check_call_status();
					zephir_array_update_string(&_80$$18, SL(":style"), &_81$$18, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_80$$18, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_82$$18);
					ZVAL_STRING(&_82$$18, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n");
					ZEPHIR_CALL_FUNCTION(&_81$$18, "strtr", NULL, 50, &_82$$18, &_80$$18);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_83$$18);
					ZEPHIR_CONCAT_VV(&_83$$18, &_79$$18, &_81$$18);
					zephir_concat_self(&output, &_83$$18 TSRMLS_CC);
				} else {
					ZVAL_LONG(&_84$$19, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_85$$19, "str_repeat", &_9, 127, &space, &_84$$19);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_86$$19);
					zephir_create_array(&_86$$19, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_88$$19);
					ZVAL_STRING(&_88$$19, "obj");
					ZEPHIR_CALL_METHOD(&_87$$19, this_ptr, "getstyle", NULL, 0, &_88$$19);
					zephir_check_call_status();
					zephir_array_update_string(&_86$$19, SL(":style"), &_87$$19, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_86$$19, SL(":method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_88$$19);
					ZVAL_STRING(&_88$$19, "-><span style=':style'>:method</span>();\n");
					ZEPHIR_CALL_FUNCTION(&_87$$19, "strtr", NULL, 50, &_88$$19, &_86$$19);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_89$$19);
					ZEPHIR_CONCAT_VV(&_89$$19, &_85$$19, &_87$$19);
					zephir_concat_self(&output, &_89$$19 TSRMLS_CC);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_LONG(&_90$$16, tab);
			ZEPHIR_CALL_FUNCTION(&_91$$16, "str_repeat", &_9, 127, &space, &_90$$16);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_92$$16);
			ZEPHIR_CONCAT_VS(&_92$$16, &_91$$16, ")\n");
			zephir_concat_self(&output, &_92$$16 TSRMLS_CC);
		}
		ZVAL_LONG(&_93$$8, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_94$$8, "str_repeat", &_9, 127, &space, &_93$$8);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_94$$8, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_95$$20);
		zephir_create_array(&_95$$20, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_97$$20);
		ZVAL_STRING(&_97$$20, "int");
		ZEPHIR_CALL_METHOD(&_96$$20, this_ptr, "getstyle", NULL, 0, &_97$$20);
		zephir_check_call_status();
		zephir_array_update_string(&_95$$20, SL(":style"), &_96$$20, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_95$$20, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_97$$20);
		ZVAL_STRING(&_97$$20, "<b style=':style'>Integer</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_96$$20, "strtr", NULL, 50, &_97$$20, &_95$$20);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_96$$20);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_98, "is_float", NULL, 168, variable);
	zephir_check_call_status();
	if (zephir_is_true(&_98)) {
		ZEPHIR_INIT_VAR(&_99$$21);
		zephir_create_array(&_99$$21, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_101$$21);
		ZVAL_STRING(&_101$$21, "float");
		ZEPHIR_CALL_METHOD(&_100$$21, this_ptr, "getstyle", NULL, 0, &_101$$21);
		zephir_check_call_status();
		zephir_array_update_string(&_99$$21, SL(":style"), &_100$$21, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_99$$21, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_101$$21);
		ZVAL_STRING(&_101$$21, "<b style=':style'>Float</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_100$$21, "strtr", NULL, 50, &_101$$21, &_99$$21);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_100$$21);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_102$$22);
		zephir_create_array(&_102$$22, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_104$$22);
		ZVAL_STRING(&_104$$22, "num");
		ZEPHIR_CALL_METHOD(&_103$$22, this_ptr, "getstyle", NULL, 0, &_104$$22);
		zephir_check_call_status();
		zephir_array_update_string(&_102$$22, SL(":style"), &_103$$22, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_102$$22, SL(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_102$$22, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_104$$22);
		ZVAL_STRING(&_104$$22, "<b style=':style'>Numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		ZEPHIR_CALL_FUNCTION(&_103$$22, "strtr", NULL, 50, &_104$$22, &_102$$22);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_103$$22);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_105$$23);
		zephir_create_array(&_105$$23, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_107$$23);
		ZVAL_STRING(&_107$$23, "str");
		ZEPHIR_CALL_METHOD(&_106$$23, this_ptr, "getstyle", NULL, 0, &_107$$23);
		zephir_check_call_status();
		zephir_array_update_string(&_105$$23, SL(":style"), &_106$$23, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_105$$23, SL(":length"), zephir_fast_strlen_ev(variable));
		ZVAL_LONG(&_108$$23, 4);
		ZEPHIR_INIT_NVAR(&_107$$23);
		ZVAL_STRING(&_107$$23, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_106$$23, "htmlentities", NULL, 160, variable, &_108$$23, &_107$$23);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_109$$23, "nl2br", NULL, 169, &_106$$23);
		zephir_check_call_status();
		zephir_array_update_string(&_105$$23, SL(":var"), &_109$$23, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_107$$23);
		ZVAL_STRING(&_107$$23, "<b style=':style'>String</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		ZEPHIR_CALL_FUNCTION(&_109$$23, "strtr", NULL, 50, &_107$$23, &_105$$23);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_109$$23);
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE)) {
		ZEPHIR_INIT_VAR(&_110$$24);
		zephir_create_array(&_110$$24, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_112$$24);
		ZVAL_STRING(&_112$$24, "bool");
		ZEPHIR_CALL_METHOD(&_111$$24, this_ptr, "getstyle", NULL, 0, &_112$$24);
		zephir_check_call_status();
		zephir_array_update_string(&_110$$24, SL(":style"), &_111$$24, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_113$$24);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_113$$24);
			ZVAL_STRING(&_113$$24, "TRUE");
		} else {
			ZEPHIR_INIT_NVAR(&_113$$24);
			ZVAL_STRING(&_113$$24, "FALSE");
		}
		zephir_array_update_string(&_110$$24, SL(":var"), &_113$$24, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_112$$24);
		ZVAL_STRING(&_112$$24, "<b style=':style'>Boolean</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_111$$24, "strtr", NULL, 50, &_112$$24, &_110$$24);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_111$$24);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_114$$25);
		zephir_create_array(&_114$$25, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_116$$25);
		ZVAL_STRING(&_116$$25, "null");
		ZEPHIR_CALL_METHOD(&_115$$25, this_ptr, "getstyle", NULL, 0, &_116$$25);
		zephir_check_call_status();
		zephir_array_update_string(&_114$$25, SL(":style"), &_115$$25, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_116$$25);
		ZVAL_STRING(&_116$$25, "<b style=':style'>NULL</b>");
		ZEPHIR_CALL_FUNCTION(&_115$$25, "strtr", NULL, 50, &_116$$25, &_114$$25);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_115$$25);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_117);
	zephir_create_array(&_117, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_119);
	ZVAL_STRING(&_119, "other");
	ZEPHIR_CALL_METHOD(&_118, this_ptr, "getstyle", NULL, 0, &_119);
	zephir_check_call_status();
	zephir_array_update_string(&_117, SL(":style"), &_118, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_117, SL(":var"), variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_119);
	ZVAL_STRING(&_119, "(<span style=':style'>:var</span>)");
	ZEPHIR_CALL_FUNCTION(&_118, "strtr", NULL, 50, &_119, &_117);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_118);
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

