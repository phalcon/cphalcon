
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
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Dumps information about a variable(s)
 *
 * ```php
 * $foo = 123;
 *
 * echo (new \Phalcon\Debug\Dump())->variable($foo, "foo");
 * ```
 *
 * ```php
 * $foo = "string";
 * $bar = ["key" => "value"];
 * $baz = new stdClass();
 *
 * echo (new \Phalcon\Debug\Dump())->variables($foo, $bar, $baz);
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Debug_Dump) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Debug, Dump, phalcon, debug_dump, phalcon_debug_dump_method_entry, 0);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_debug_dump_ce, SL("detailed"), 0, ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_debug_dump_ce, SL("methods"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_debug_dump_ce, SL("styles"), ZEND_ACC_PROTECTED);

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

	zephir_fetch_params_without_memory_grow(1, 0, &detailed_param);

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
 */
PHP_METHOD(Phalcon_Debug_Dump, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
 */
PHP_METHOD(Phalcon_Debug_Dump, all) {

	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	zephir_create_array(&defaultStyles, 11, 0);
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
	zephir_fast_array_merge(&_0, &defaultStyles, &styles);
	zephir_update_property_zval(this_ptr, SL("styles"), &_0);
	RETURN_MM_MEMBER(getThis(), "styles");

}

/**
 * Returns an JSON string of information about a single variable.
 *
 * ```php
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
 * ```
 */
PHP_METHOD(Phalcon_Debug_Dump, toJson) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *variable, variable_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &variable);



	ZVAL_LONG(&_1, ((128 | 64) | 256));
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_json_ce, "encode", &_0, 13, variable, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an HTML string of information about a single variable.
 *
 * ```php
 * echo (new \Phalcon\Debug\Dump())->variable($foo, "foo");
 * ```
 */
PHP_METHOD(Phalcon_Debug_Dump, variable) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	zephir_create_array(&_0, 2, 0);
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
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 3, &_2, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an HTML string of debugging information about any number of
 * variables, each wrapped in a "pre" tag.
 *
 * ```php
 * $foo = "string";
 * $bar = ["key" => "value"];
 * $baz = new stdClass();
 *
 * echo (new \Phalcon\Debug\Dump())->variables($foo, $bar, $baz);
 * ```
 */
PHP_METHOD(Phalcon_Debug_Dump, variables) {

	zend_string *_4;
	zend_ulong _3;
	zval output;
	zval key, value, _0, *_1, _2, _5$$3, _6$$3, _8$$4, _9$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&output);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_args(&_0);
	zephir_is_iterable(&_0, 0, "phalcon/Debug/Dump.zep", 181);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZEPHIR_CONCAT_SV(&_6$$3, "var ", &key);
			ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "one", &_7, 0, &value, &_6$$3);
			zephir_check_call_status();
			zephir_concat_self(&output, &_5$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZEPHIR_CONCAT_SV(&_9$$4, "var ", &key);
				ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "one", &_7, 0, &value, &_9$$4);
				zephir_check_call_status();
				zephir_concat_self(&output, &_8$$4);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&output);

}

/**
 * Get style for type
 */
PHP_METHOD(Phalcon_Debug_Dump, getStyle) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL, style, _0;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&style);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	zephir_read_property(&_0, this_ptr, SL("styles"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&style, &_0, &type, 1))) {
		RETURN_MM_STRING("color:gray");
	}
	RETURN_CTOR(&style);

}

/**
 * Prepare an HTML string of information about a single variable.
 */
PHP_METHOD(Phalcon_Debug_Dump, output) {

	zend_class_entry *_74$$16, *_91$$17;
	zend_bool _15$$5, _16$$5, _17$$5, _27$$7, _28$$7, _29$$7, _42$$9;
	zend_string *_7$$4, *_50$$12;
	zend_ulong _6$$4, _49$$12;
	zval _166, _1$$4, _11$$5, _23$$7, _34$$9, _105$$9, _38$$10, _53$$13, _61$$14, _79$$16, _95$$17, _116$$21, _122$$22, _129$$24, _135$$25, _144$$26, _148$$27, _151$$28, _154$$29, _159$$30, _163$$31;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_19 = NULL, *_71 = NULL, *_72 = NULL, *_75 = NULL, *_77 = NULL, *_85 = NULL, *_88 = NULL, *_89 = NULL, *_93 = NULL, *_101 = NULL;
	zend_long tab, ZEPHIR_LAST_CALL_STATUS;
	zval name, _0$$3;
	zval *variable, variable_sub, *name_param = NULL, *tab_param = NULL, key, value, output, space, type, attr, _147, _167, _168, _2$$4, _3$$4, *_4$$4, _5$$4, _32$$4, _33$$4, _8$$5, _9$$5, _12$$5, _13$$5, _14$$5, _18$$5, _20$$5, _21$$7, _22$$7, _24$$7, _25$$7, _26$$7, _30$$7, _31$$7, _35$$9, _36$$9, _37$$9, _41$$9, _103$$9, _104$$9, _106$$9, _107$$9, _142$$9, _143$$9, _39$$10, _40$$10, _43$$11, _44$$11, _45$$11, _46$$12, *_47$$12, _48$$12, _51$$13, _52$$13, _54$$13, _55$$13, _56$$13, _57$$13, _58$$13, _59$$14, _60$$14, _62$$14, _63$$14, _64$$14, _65$$14, _66$$14, reflect$$15, props$$15, property$$15, _67$$15, *_68$$15, _69$$15, _70$$16, _73$$16, _76$$16, _78$$16, _80$$16, _81$$16, _82$$16, _83$$16, _84$$16, _86$$16, _87$$17, _90$$17, _92$$17, _94$$17, _96$$17, _97$$17, _98$$17, _99$$17, _100$$17, _102$$17, _108$$18, _109$$18, _110$$18, *_111$$19, _112$$19, _139$$19, _140$$19, _141$$19, _113$$20, _114$$21, _115$$21, _117$$21, _118$$21, _119$$21, _120$$22, _121$$22, _123$$22, _124$$22, _125$$22, _126$$23, _127$$24, _128$$24, _130$$24, _131$$24, _132$$24, _133$$25, _134$$25, _136$$25, _137$$25, _138$$25, _145$$26, _146$$26, _149$$27, _150$$27, _152$$28, _153$$28, _155$$29, _156$$29, _157$$29, _158$$29, _160$$30, _161$$30, _162$$30, _164$$31, _165$$31;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&space);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&attr);
	ZVAL_UNDEF(&_147);
	ZVAL_UNDEF(&_167);
	ZVAL_UNDEF(&_168);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_32$$4);
	ZVAL_UNDEF(&_33$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_35$$9);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_37$$9);
	ZVAL_UNDEF(&_41$$9);
	ZVAL_UNDEF(&_103$$9);
	ZVAL_UNDEF(&_104$$9);
	ZVAL_UNDEF(&_106$$9);
	ZVAL_UNDEF(&_107$$9);
	ZVAL_UNDEF(&_142$$9);
	ZVAL_UNDEF(&_143$$9);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_40$$10);
	ZVAL_UNDEF(&_43$$11);
	ZVAL_UNDEF(&_44$$11);
	ZVAL_UNDEF(&_45$$11);
	ZVAL_UNDEF(&_46$$12);
	ZVAL_UNDEF(&_48$$12);
	ZVAL_UNDEF(&_51$$13);
	ZVAL_UNDEF(&_52$$13);
	ZVAL_UNDEF(&_54$$13);
	ZVAL_UNDEF(&_55$$13);
	ZVAL_UNDEF(&_56$$13);
	ZVAL_UNDEF(&_57$$13);
	ZVAL_UNDEF(&_58$$13);
	ZVAL_UNDEF(&_59$$14);
	ZVAL_UNDEF(&_60$$14);
	ZVAL_UNDEF(&_62$$14);
	ZVAL_UNDEF(&_63$$14);
	ZVAL_UNDEF(&_64$$14);
	ZVAL_UNDEF(&_65$$14);
	ZVAL_UNDEF(&_66$$14);
	ZVAL_UNDEF(&reflect$$15);
	ZVAL_UNDEF(&props$$15);
	ZVAL_UNDEF(&property$$15);
	ZVAL_UNDEF(&_67$$15);
	ZVAL_UNDEF(&_69$$15);
	ZVAL_UNDEF(&_70$$16);
	ZVAL_UNDEF(&_73$$16);
	ZVAL_UNDEF(&_76$$16);
	ZVAL_UNDEF(&_78$$16);
	ZVAL_UNDEF(&_80$$16);
	ZVAL_UNDEF(&_81$$16);
	ZVAL_UNDEF(&_82$$16);
	ZVAL_UNDEF(&_83$$16);
	ZVAL_UNDEF(&_84$$16);
	ZVAL_UNDEF(&_86$$16);
	ZVAL_UNDEF(&_87$$17);
	ZVAL_UNDEF(&_90$$17);
	ZVAL_UNDEF(&_92$$17);
	ZVAL_UNDEF(&_94$$17);
	ZVAL_UNDEF(&_96$$17);
	ZVAL_UNDEF(&_97$$17);
	ZVAL_UNDEF(&_98$$17);
	ZVAL_UNDEF(&_99$$17);
	ZVAL_UNDEF(&_100$$17);
	ZVAL_UNDEF(&_102$$17);
	ZVAL_UNDEF(&_108$$18);
	ZVAL_UNDEF(&_109$$18);
	ZVAL_UNDEF(&_110$$18);
	ZVAL_UNDEF(&_112$$19);
	ZVAL_UNDEF(&_139$$19);
	ZVAL_UNDEF(&_140$$19);
	ZVAL_UNDEF(&_141$$19);
	ZVAL_UNDEF(&_113$$20);
	ZVAL_UNDEF(&_114$$21);
	ZVAL_UNDEF(&_115$$21);
	ZVAL_UNDEF(&_117$$21);
	ZVAL_UNDEF(&_118$$21);
	ZVAL_UNDEF(&_119$$21);
	ZVAL_UNDEF(&_120$$22);
	ZVAL_UNDEF(&_121$$22);
	ZVAL_UNDEF(&_123$$22);
	ZVAL_UNDEF(&_124$$22);
	ZVAL_UNDEF(&_125$$22);
	ZVAL_UNDEF(&_126$$23);
	ZVAL_UNDEF(&_127$$24);
	ZVAL_UNDEF(&_128$$24);
	ZVAL_UNDEF(&_130$$24);
	ZVAL_UNDEF(&_131$$24);
	ZVAL_UNDEF(&_132$$24);
	ZVAL_UNDEF(&_133$$25);
	ZVAL_UNDEF(&_134$$25);
	ZVAL_UNDEF(&_136$$25);
	ZVAL_UNDEF(&_137$$25);
	ZVAL_UNDEF(&_138$$25);
	ZVAL_UNDEF(&_145$$26);
	ZVAL_UNDEF(&_146$$26);
	ZVAL_UNDEF(&_149$$27);
	ZVAL_UNDEF(&_150$$27);
	ZVAL_UNDEF(&_152$$28);
	ZVAL_UNDEF(&_153$$28);
	ZVAL_UNDEF(&_155$$29);
	ZVAL_UNDEF(&_156$$29);
	ZVAL_UNDEF(&_157$$29);
	ZVAL_UNDEF(&_158$$29);
	ZVAL_UNDEF(&_160$$30);
	ZVAL_UNDEF(&_161$$30);
	ZVAL_UNDEF(&_162$$30);
	ZVAL_UNDEF(&_164$$31);
	ZVAL_UNDEF(&_165$$31);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_166);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_34$$9);
	ZVAL_UNDEF(&_105$$9);
	ZVAL_UNDEF(&_38$$10);
	ZVAL_UNDEF(&_53$$13);
	ZVAL_UNDEF(&_61$$14);
	ZVAL_UNDEF(&_79$$16);
	ZVAL_UNDEF(&_95$$17);
	ZVAL_UNDEF(&_116$$21);
	ZVAL_UNDEF(&_122$$22);
	ZVAL_UNDEF(&_129$$24);
	ZVAL_UNDEF(&_135$$25);
	ZVAL_UNDEF(&_144$$26);
	ZVAL_UNDEF(&_148$$27);
	ZVAL_UNDEF(&_151$$28);
	ZVAL_UNDEF(&_154$$29);
	ZVAL_UNDEF(&_159$$30);
	ZVAL_UNDEF(&_163$$31);

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
		zephir_create_array(&_1$$4, 2, 0);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "arr");
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getstyle", NULL, 0, &_3$$4);
		zephir_check_call_status();
		zephir_array_update_string(&_1$$4, SL(":style"), &_2$$4, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_1$$4, SL(":count"), zephir_fast_count_int(variable));
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "<b style =':style'>Array</b> (<span style =':style'>:count</span>) (\n");
		ZEPHIR_CALL_FUNCTION(&_2$$4, "strtr", NULL, 3, &_3$$4, &_1$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, &_2$$4);
		zephir_is_iterable(variable, 0, "phalcon/Debug/Dump.zep", 231);
		if (Z_TYPE_P(variable) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(variable), _6$$4, _7$$4, _4$$4)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_7$$4 != NULL) { 
					ZVAL_STR_COPY(&key, _7$$4);
				} else {
					ZVAL_LONG(&key, _6$$4);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _4$$4);
				ZVAL_LONG(&_8$$5, tab);
				ZEPHIR_CALL_FUNCTION(&_9$$5, "str_repeat", &_10, 183, &space, &_8$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_11$$5);
				zephir_create_array(&_11$$5, 2, 0);
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZVAL_STRING(&_13$$5, "arr");
				ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "getstyle", NULL, 0, &_13$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_11$$5, SL(":style"), &_12$$5, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_11$$5, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZVAL_STRING(&_13$$5, "[<span style=':style'>:key</span>] => ");
				ZEPHIR_CALL_FUNCTION(&_12$$5, "strtr", NULL, 3, &_13$$5, &_11$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_14$$5);
				ZEPHIR_CONCAT_VV(&_14$$5, &_9$$5, &_12$$5);
				zephir_concat_self(&output, &_14$$5);
				_15$$5 = tab == 1;
				if (_15$$5) {
					_15$$5 = !ZEPHIR_IS_STRING(&name, "");
				}
				_16$$5 = _15$$5;
				if (_16$$5) {
					_16$$5 = !(Z_TYPE_P(&key) == IS_LONG);
				}
				_17$$5 = _16$$5;
				if (_17$$5) {
					_17$$5 = ZEPHIR_IS_EQUAL(&name, &key);
				}
				if (_17$$5) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZVAL_STRING(&_13$$5, "");
				ZVAL_LONG(&_8$$5, (tab + 1));
				ZEPHIR_CALL_METHOD(&_18$$5, this_ptr, "output", &_19, 209, &value, &_13$$5, &_8$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_20$$5);
				ZEPHIR_CONCAT_VS(&_20$$5, &_18$$5, "\n");
				zephir_concat_self(&output, &_20$$5);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, variable, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$4, variable, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, variable, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, variable, "current", NULL, 0);
				zephir_check_call_status();
					ZVAL_LONG(&_21$$7, tab);
					ZEPHIR_CALL_FUNCTION(&_22$$7, "str_repeat", &_10, 183, &space, &_21$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_23$$7);
					zephir_create_array(&_23$$7, 2, 0);
					ZEPHIR_INIT_NVAR(&_25$$7);
					ZVAL_STRING(&_25$$7, "arr");
					ZEPHIR_CALL_METHOD(&_24$$7, this_ptr, "getstyle", NULL, 0, &_25$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_23$$7, SL(":style"), &_24$$7, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_23$$7, SL(":key"), &key, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_25$$7);
					ZVAL_STRING(&_25$$7, "[<span style=':style'>:key</span>] => ");
					ZEPHIR_CALL_FUNCTION(&_24$$7, "strtr", NULL, 3, &_25$$7, &_23$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_26$$7);
					ZEPHIR_CONCAT_VV(&_26$$7, &_22$$7, &_24$$7);
					zephir_concat_self(&output, &_26$$7);
					_27$$7 = tab == 1;
					if (_27$$7) {
						_27$$7 = !ZEPHIR_IS_STRING(&name, "");
					}
					_28$$7 = _27$$7;
					if (_28$$7) {
						_28$$7 = !(Z_TYPE_P(&key) == IS_LONG);
					}
					_29$$7 = _28$$7;
					if (_29$$7) {
						_29$$7 = ZEPHIR_IS_EQUAL(&name, &key);
					}
					if (_29$$7) {
						continue;
					}
					ZEPHIR_INIT_NVAR(&_25$$7);
					ZVAL_STRING(&_25$$7, "");
					ZVAL_LONG(&_21$$7, (tab + 1));
					ZEPHIR_CALL_METHOD(&_30$$7, this_ptr, "output", &_19, 209, &value, &_25$$7, &_21$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_31$$7);
					ZEPHIR_CONCAT_VS(&_31$$7, &_30$$7, "\n");
					zephir_concat_self(&output, &_31$$7);
				ZEPHIR_CALL_METHOD(NULL, variable, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_32$$4, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_33$$4, "str_repeat", &_10, 183, &space, &_32$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_33$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_34$$9);
		zephir_create_array(&_34$$9, 2, 0);
		ZEPHIR_INIT_VAR(&_36$$9);
		ZVAL_STRING(&_36$$9, "obj");
		ZEPHIR_CALL_METHOD(&_35$$9, this_ptr, "getstyle", NULL, 0, &_36$$9);
		zephir_check_call_status();
		zephir_array_update_string(&_34$$9, SL(":style"), &_35$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_36$$9);
		zephir_get_class(&_36$$9, variable, 0);
		zephir_array_update_string(&_34$$9, SL(":class"), &_36$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_36$$9);
		ZVAL_STRING(&_36$$9, "<b style=':style'>Object</b> :class");
		ZEPHIR_CALL_FUNCTION(&_35$$9, "strtr", NULL, 3, &_36$$9, &_34$$9);
		zephir_check_call_status();
		zephir_concat_self(&output, &_35$$9);
		ZEPHIR_CALL_FUNCTION(&_37$$9, "get_parent_class", NULL, 210, variable);
		zephir_check_call_status();
		if (zephir_is_true(&_37$$9)) {
			ZEPHIR_INIT_VAR(&_38$$10);
			zephir_create_array(&_38$$10, 2, 0);
			ZEPHIR_INIT_VAR(&_40$$10);
			ZVAL_STRING(&_40$$10, "obj");
			ZEPHIR_CALL_METHOD(&_39$$10, this_ptr, "getstyle", NULL, 0, &_40$$10);
			zephir_check_call_status();
			zephir_array_update_string(&_38$$10, SL(":style"), &_39$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_39$$10, "get_parent_class", NULL, 210, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_38$$10, SL(":parent"), &_39$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_40$$10);
			ZVAL_STRING(&_40$$10, " <b style=':style'>extends</b> :parent");
			ZEPHIR_CALL_FUNCTION(&_39$$10, "strtr", NULL, 3, &_40$$10, &_38$$10);
			zephir_check_call_status();
			zephir_concat_self(&output, &_39$$10);
		}
		zephir_concat_self_str(&output, SL(" (\n"));
		zephir_read_property(&_41$$9, this_ptr, SL("detailed"), PH_NOISY_CC | PH_READONLY);
		_42$$9 = !zephir_is_true(&_41$$9);
		if (!(_42$$9)) {
			_42$$9 = zephir_instance_of_ev(variable, zend_standard_class_def);
		}
		if (zephir_instance_of_ev(variable, phalcon_di_ce)) {
			ZVAL_LONG(&_43$$11, tab);
			ZEPHIR_CALL_FUNCTION(&_44$$11, "str_repeat", &_10, 183, &space, &_43$$11);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_45$$11);
			ZEPHIR_CONCAT_VS(&_45$$11, &_44$$11, "[skipped]\n");
			zephir_concat_self(&output, &_45$$11);
		} else if (_42$$9) {
			ZEPHIR_CALL_FUNCTION(&_46$$12, "get_object_vars", NULL, 211, variable);
			zephir_check_call_status();
			zephir_is_iterable(&_46$$12, 0, "phalcon/Debug/Dump.zep", 263);
			if (Z_TYPE_P(&_46$$12) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_46$$12), _49$$12, _50$$12, _47$$12)
				{
					ZEPHIR_INIT_NVAR(&key);
					if (_50$$12 != NULL) { 
						ZVAL_STR_COPY(&key, _50$$12);
					} else {
						ZVAL_LONG(&key, _49$$12);
					}
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _47$$12);
					ZVAL_LONG(&_51$$13, tab);
					ZEPHIR_CALL_FUNCTION(&_52$$13, "str_repeat", &_10, 183, &space, &_51$$13);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_53$$13);
					zephir_create_array(&_53$$13, 3, 0);
					ZEPHIR_INIT_NVAR(&_55$$13);
					ZVAL_STRING(&_55$$13, "obj");
					ZEPHIR_CALL_METHOD(&_54$$13, this_ptr, "getstyle", NULL, 0, &_55$$13);
					zephir_check_call_status();
					zephir_array_update_string(&_53$$13, SL(":style"), &_54$$13, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_53$$13, SL(":key"), &key, PH_COPY | PH_SEPARATE);
					add_assoc_stringl_ex(&_53$$13, SL(":type"), SL("public"));
					ZEPHIR_INIT_NVAR(&_55$$13);
					ZVAL_STRING(&_55$$13, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
					ZEPHIR_CALL_FUNCTION(&_54$$13, "strtr", NULL, 3, &_55$$13, &_53$$13);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_56$$13);
					ZEPHIR_CONCAT_VV(&_56$$13, &_52$$13, &_54$$13);
					zephir_concat_self(&output, &_56$$13);
					ZEPHIR_INIT_NVAR(&_55$$13);
					ZVAL_STRING(&_55$$13, "");
					ZVAL_LONG(&_51$$13, (tab + 1));
					ZEPHIR_CALL_METHOD(&_57$$13, this_ptr, "output", &_19, 209, &value, &_55$$13, &_51$$13);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_58$$13);
					ZEPHIR_CONCAT_VS(&_58$$13, &_57$$13, "\n");
					zephir_concat_self(&output, &_58$$13);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_46$$12, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_48$$12, &_46$$12, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_48$$12)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&key, &_46$$12, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&value, &_46$$12, "current", NULL, 0);
					zephir_check_call_status();
						ZVAL_LONG(&_59$$14, tab);
						ZEPHIR_CALL_FUNCTION(&_60$$14, "str_repeat", &_10, 183, &space, &_59$$14);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_61$$14);
						zephir_create_array(&_61$$14, 3, 0);
						ZEPHIR_INIT_NVAR(&_63$$14);
						ZVAL_STRING(&_63$$14, "obj");
						ZEPHIR_CALL_METHOD(&_62$$14, this_ptr, "getstyle", NULL, 0, &_63$$14);
						zephir_check_call_status();
						zephir_array_update_string(&_61$$14, SL(":style"), &_62$$14, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_61$$14, SL(":key"), &key, PH_COPY | PH_SEPARATE);
						add_assoc_stringl_ex(&_61$$14, SL(":type"), SL("public"));
						ZEPHIR_INIT_NVAR(&_63$$14);
						ZVAL_STRING(&_63$$14, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
						ZEPHIR_CALL_FUNCTION(&_62$$14, "strtr", NULL, 3, &_63$$14, &_61$$14);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_64$$14);
						ZEPHIR_CONCAT_VV(&_64$$14, &_60$$14, &_62$$14);
						zephir_concat_self(&output, &_64$$14);
						ZEPHIR_INIT_NVAR(&_63$$14);
						ZVAL_STRING(&_63$$14, "");
						ZVAL_LONG(&_59$$14, (tab + 1));
						ZEPHIR_CALL_METHOD(&_65$$14, this_ptr, "output", &_19, 209, &value, &_63$$14, &_59$$14);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_66$$14);
						ZEPHIR_CONCAT_VS(&_66$$14, &_65$$14, "\n");
						zephir_concat_self(&output, &_66$$14);
					ZEPHIR_CALL_METHOD(NULL, &_46$$12, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&key);
		} else {
			ZEPHIR_INIT_VAR(&reflect$$15);
			object_init_ex(&reflect$$15, zephir_get_internal_ce(SL("reflectionclass")));
			ZEPHIR_CALL_METHOD(NULL, &reflect$$15, "__construct", NULL, 141, variable);
			zephir_check_call_status();
			ZVAL_LONG(&_67$$15, ((1 | 2) | 4));
			ZEPHIR_CALL_METHOD(&props$$15, &reflect$$15, "getproperties", NULL, 145, &_67$$15);
			zephir_check_call_status();
			zephir_is_iterable(&props$$15, 0, "phalcon/Debug/Dump.zep", 289);
			if (Z_TYPE_P(&props$$15) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&props$$15), _68$$15)
				{
					ZEPHIR_INIT_NVAR(&property$$15);
					ZVAL_COPY(&property$$15, _68$$15);
					ZVAL_BOOL(&_70$$16, 1);
					ZEPHIR_CALL_METHOD(NULL, &property$$15, "setaccessible", &_71, 0, &_70$$16);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&key, &property$$15, "getname", &_72, 0);
					zephir_check_call_status();
					_74$$16 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
					ZEPHIR_CALL_METHOD(&_76$$16, &property$$15, "getmodifiers", &_77, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_CE_STATIC(&_73$$16, _74$$16, "getmodifiernames", &_75, 0, &_76$$16);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&type);
					zephir_fast_join_str(&type, SL(" "), &_73$$16);
					ZVAL_LONG(&_70$$16, tab);
					ZEPHIR_CALL_FUNCTION(&_78$$16, "str_repeat", &_10, 183, &space, &_70$$16);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_79$$16);
					zephir_create_array(&_79$$16, 3, 0);
					ZEPHIR_INIT_NVAR(&_81$$16);
					ZVAL_STRING(&_81$$16, "obj");
					ZEPHIR_CALL_METHOD(&_80$$16, this_ptr, "getstyle", NULL, 0, &_81$$16);
					zephir_check_call_status();
					zephir_array_update_string(&_79$$16, SL(":style"), &_80$$16, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_79$$16, SL(":key"), &key, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_79$$16, SL(":type"), &type, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_81$$16);
					ZVAL_STRING(&_81$$16, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
					ZEPHIR_CALL_FUNCTION(&_80$$16, "strtr", NULL, 3, &_81$$16, &_79$$16);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_82$$16);
					ZEPHIR_CONCAT_VV(&_82$$16, &_78$$16, &_80$$16);
					zephir_concat_self(&output, &_82$$16);
					ZEPHIR_CALL_METHOD(&_84$$16, &property$$15, "getvalue", &_85, 0, variable);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_81$$16);
					ZVAL_STRING(&_81$$16, "");
					ZVAL_LONG(&_70$$16, (tab + 1));
					ZEPHIR_CALL_METHOD(&_83$$16, this_ptr, "output", &_19, 209, &_84$$16, &_81$$16, &_70$$16);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_86$$16);
					ZEPHIR_CONCAT_VS(&_86$$16, &_83$$16, "\n");
					zephir_concat_self(&output, &_86$$16);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &props$$15, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_69$$15, &props$$15, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_69$$15)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&property$$15, &props$$15, "current", NULL, 0);
					zephir_check_call_status();
						ZVAL_BOOL(&_87$$17, 1);
						ZEPHIR_CALL_METHOD(NULL, &property$$15, "setaccessible", &_88, 0, &_87$$17);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&key, &property$$15, "getname", &_89, 0);
						zephir_check_call_status();
						_91$$17 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
						ZEPHIR_CALL_METHOD(&_92$$17, &property$$15, "getmodifiers", &_93, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_CE_STATIC(&_90$$17, _91$$17, "getmodifiernames", &_75, 0, &_92$$17);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&type);
						zephir_fast_join_str(&type, SL(" "), &_90$$17);
						ZVAL_LONG(&_87$$17, tab);
						ZEPHIR_CALL_FUNCTION(&_94$$17, "str_repeat", &_10, 183, &space, &_87$$17);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_95$$17);
						zephir_create_array(&_95$$17, 3, 0);
						ZEPHIR_INIT_NVAR(&_97$$17);
						ZVAL_STRING(&_97$$17, "obj");
						ZEPHIR_CALL_METHOD(&_96$$17, this_ptr, "getstyle", NULL, 0, &_97$$17);
						zephir_check_call_status();
						zephir_array_update_string(&_95$$17, SL(":style"), &_96$$17, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_95$$17, SL(":key"), &key, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_95$$17, SL(":type"), &type, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_97$$17);
						ZVAL_STRING(&_97$$17, "-><span style=':style'>:key</span> (<span style=':style'>:type</span>) = ");
						ZEPHIR_CALL_FUNCTION(&_96$$17, "strtr", NULL, 3, &_97$$17, &_95$$17);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_98$$17);
						ZEPHIR_CONCAT_VV(&_98$$17, &_94$$17, &_96$$17);
						zephir_concat_self(&output, &_98$$17);
						ZEPHIR_CALL_METHOD(&_100$$17, &property$$15, "getvalue", &_101, 0, variable);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_97$$17);
						ZVAL_STRING(&_97$$17, "");
						ZVAL_LONG(&_87$$17, (tab + 1));
						ZEPHIR_CALL_METHOD(&_99$$17, this_ptr, "output", &_19, 209, &_100$$17, &_97$$17, &_87$$17);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_102$$17);
						ZEPHIR_CONCAT_VS(&_102$$17, &_99$$17, "\n");
						zephir_concat_self(&output, &_102$$17);
					ZEPHIR_CALL_METHOD(NULL, &props$$15, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&property$$15);
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 212, variable);
		zephir_check_call_status();
		ZVAL_LONG(&_103$$9, tab);
		ZEPHIR_CALL_FUNCTION(&_104$$9, "str_repeat", &_10, 183, &space, &_103$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_105$$9);
		zephir_create_array(&_105$$9, 3, 0);
		ZEPHIR_INIT_NVAR(&_36$$9);
		ZVAL_STRING(&_36$$9, "obj");
		ZEPHIR_CALL_METHOD(&_106$$9, this_ptr, "getstyle", NULL, 0, &_36$$9);
		zephir_check_call_status();
		zephir_array_update_string(&_105$$9, SL(":style"), &_106$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_36$$9);
		zephir_get_class(&_36$$9, variable, 0);
		zephir_array_update_string(&_105$$9, SL(":class"), &_36$$9, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_105$$9, SL(":count"), zephir_fast_count_int(&attr));
		ZEPHIR_INIT_NVAR(&_36$$9);
		ZVAL_STRING(&_36$$9, ":class <b style=':style'>methods</b>: (<span style=':style'>:count</span>) (\n");
		ZEPHIR_CALL_FUNCTION(&_106$$9, "strtr", NULL, 3, &_36$$9, &_105$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_107$$9);
		ZEPHIR_CONCAT_VV(&_107$$9, &_104$$9, &_106$$9);
		zephir_concat_self(&output, &_107$$9);
		ZEPHIR_INIT_NVAR(&_36$$9);
		zephir_get_class(&_36$$9, variable, 0);
		zephir_read_property(&_103$$9, this_ptr, SL("methods"), PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&_36$$9, &_103$$9)) {
			ZVAL_LONG(&_108$$18, tab);
			ZEPHIR_CALL_FUNCTION(&_109$$18, "str_repeat", &_10, 183, &space, &_108$$18);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_110$$18);
			ZEPHIR_CONCAT_VS(&_110$$18, &_109$$18, "[already listed]\n");
			zephir_concat_self(&output, &_110$$18);
		} else {
			zephir_is_iterable(&attr, 0, "phalcon/Debug/Dump.zep", 307);
			if (Z_TYPE_P(&attr) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attr), _111$$19)
				{
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _111$$19);
					ZEPHIR_INIT_NVAR(&_113$$20);
					zephir_get_class(&_113$$20, variable, 0);
					zephir_update_property_array_append(this_ptr, SL("methods"), &_113$$20);
					if (ZEPHIR_IS_STRING(&value, "__construct")) {
						ZVAL_LONG(&_114$$21, (tab + 1));
						ZEPHIR_CALL_FUNCTION(&_115$$21, "str_repeat", &_10, 183, &space, &_114$$21);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_116$$21);
						zephir_create_array(&_116$$21, 2, 0);
						ZEPHIR_INIT_NVAR(&_118$$21);
						ZVAL_STRING(&_118$$21, "obj");
						ZEPHIR_CALL_METHOD(&_117$$21, this_ptr, "getstyle", NULL, 0, &_118$$21);
						zephir_check_call_status();
						zephir_array_update_string(&_116$$21, SL(":style"), &_117$$21, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_116$$21, SL(":method"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_118$$21);
						ZVAL_STRING(&_118$$21, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n");
						ZEPHIR_CALL_FUNCTION(&_117$$21, "strtr", NULL, 3, &_118$$21, &_116$$21);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_119$$21);
						ZEPHIR_CONCAT_VV(&_119$$21, &_115$$21, &_117$$21);
						zephir_concat_self(&output, &_119$$21);
					} else {
						ZVAL_LONG(&_120$$22, (tab + 1));
						ZEPHIR_CALL_FUNCTION(&_121$$22, "str_repeat", &_10, 183, &space, &_120$$22);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_122$$22);
						zephir_create_array(&_122$$22, 2, 0);
						ZEPHIR_INIT_NVAR(&_124$$22);
						ZVAL_STRING(&_124$$22, "obj");
						ZEPHIR_CALL_METHOD(&_123$$22, this_ptr, "getstyle", NULL, 0, &_124$$22);
						zephir_check_call_status();
						zephir_array_update_string(&_122$$22, SL(":style"), &_123$$22, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_122$$22, SL(":method"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_124$$22);
						ZVAL_STRING(&_124$$22, "-><span style=':style'>:method</span>();\n");
						ZEPHIR_CALL_FUNCTION(&_123$$22, "strtr", NULL, 3, &_124$$22, &_122$$22);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_125$$22);
						ZEPHIR_CONCAT_VV(&_125$$22, &_121$$22, &_123$$22);
						zephir_concat_self(&output, &_125$$22);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &attr, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_112$$19, &attr, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_112$$19)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&value, &attr, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_126$$23);
						zephir_get_class(&_126$$23, variable, 0);
						zephir_update_property_array_append(this_ptr, SL("methods"), &_126$$23);
						if (ZEPHIR_IS_STRING(&value, "__construct")) {
							ZVAL_LONG(&_127$$24, (tab + 1));
							ZEPHIR_CALL_FUNCTION(&_128$$24, "str_repeat", &_10, 183, &space, &_127$$24);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_129$$24);
							zephir_create_array(&_129$$24, 2, 0);
							ZEPHIR_INIT_NVAR(&_131$$24);
							ZVAL_STRING(&_131$$24, "obj");
							ZEPHIR_CALL_METHOD(&_130$$24, this_ptr, "getstyle", NULL, 0, &_131$$24);
							zephir_check_call_status();
							zephir_array_update_string(&_129$$24, SL(":style"), &_130$$24, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_129$$24, SL(":method"), &value, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_131$$24);
							ZVAL_STRING(&_131$$24, "-><span style=':style'>:method</span>(); [<b style=':style'>constructor</b>]\n");
							ZEPHIR_CALL_FUNCTION(&_130$$24, "strtr", NULL, 3, &_131$$24, &_129$$24);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_132$$24);
							ZEPHIR_CONCAT_VV(&_132$$24, &_128$$24, &_130$$24);
							zephir_concat_self(&output, &_132$$24);
						} else {
							ZVAL_LONG(&_133$$25, (tab + 1));
							ZEPHIR_CALL_FUNCTION(&_134$$25, "str_repeat", &_10, 183, &space, &_133$$25);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_135$$25);
							zephir_create_array(&_135$$25, 2, 0);
							ZEPHIR_INIT_NVAR(&_137$$25);
							ZVAL_STRING(&_137$$25, "obj");
							ZEPHIR_CALL_METHOD(&_136$$25, this_ptr, "getstyle", NULL, 0, &_137$$25);
							zephir_check_call_status();
							zephir_array_update_string(&_135$$25, SL(":style"), &_136$$25, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_135$$25, SL(":method"), &value, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_137$$25);
							ZVAL_STRING(&_137$$25, "-><span style=':style'>:method</span>();\n");
							ZEPHIR_CALL_FUNCTION(&_136$$25, "strtr", NULL, 3, &_137$$25, &_135$$25);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_138$$25);
							ZEPHIR_CONCAT_VV(&_138$$25, &_134$$25, &_136$$25);
							zephir_concat_self(&output, &_138$$25);
						}
					ZEPHIR_CALL_METHOD(NULL, &attr, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_LONG(&_139$$19, tab);
			ZEPHIR_CALL_FUNCTION(&_140$$19, "str_repeat", &_10, 183, &space, &_139$$19);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_141$$19);
			ZEPHIR_CONCAT_VS(&_141$$19, &_140$$19, ")\n");
			zephir_concat_self(&output, &_141$$19);
		}
		ZVAL_LONG(&_142$$9, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_143$$9, "str_repeat", &_10, 183, &space, &_142$$9);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_143$$9, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_144$$26);
		zephir_create_array(&_144$$26, 2, 0);
		ZEPHIR_INIT_VAR(&_146$$26);
		ZVAL_STRING(&_146$$26, "int");
		ZEPHIR_CALL_METHOD(&_145$$26, this_ptr, "getstyle", NULL, 0, &_146$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_144$$26, SL(":style"), &_145$$26, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_144$$26, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_146$$26);
		ZVAL_STRING(&_146$$26, "<b style=':style'>Integer</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_145$$26, "strtr", NULL, 3, &_146$$26, &_144$$26);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_145$$26);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_147, "is_float", NULL, 213, variable);
	zephir_check_call_status();
	if (zephir_is_true(&_147)) {
		ZEPHIR_INIT_VAR(&_148$$27);
		zephir_create_array(&_148$$27, 2, 0);
		ZEPHIR_INIT_VAR(&_150$$27);
		ZVAL_STRING(&_150$$27, "float");
		ZEPHIR_CALL_METHOD(&_149$$27, this_ptr, "getstyle", NULL, 0, &_150$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_148$$27, SL(":style"), &_149$$27, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_148$$27, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_150$$27);
		ZVAL_STRING(&_150$$27, "<b style=':style'>Float</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_149$$27, "strtr", NULL, 3, &_150$$27, &_148$$27);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_149$$27);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_151$$28);
		zephir_create_array(&_151$$28, 3, 0);
		ZEPHIR_INIT_VAR(&_153$$28);
		ZVAL_STRING(&_153$$28, "num");
		ZEPHIR_CALL_METHOD(&_152$$28, this_ptr, "getstyle", NULL, 0, &_153$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_151$$28, SL(":style"), &_152$$28, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_151$$28, SL(":length"), zephir_fast_strlen_ev(variable));
		zephir_array_update_string(&_151$$28, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_153$$28);
		ZVAL_STRING(&_153$$28, "<b style=':style'>Numeric string</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		ZEPHIR_CALL_FUNCTION(&_152$$28, "strtr", NULL, 3, &_153$$28, &_151$$28);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_152$$28);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_154$$29);
		zephir_create_array(&_154$$29, 3, 0);
		ZEPHIR_INIT_VAR(&_156$$29);
		ZVAL_STRING(&_156$$29, "str");
		ZEPHIR_CALL_METHOD(&_155$$29, this_ptr, "getstyle", NULL, 0, &_156$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_154$$29, SL(":style"), &_155$$29, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_154$$29, SL(":length"), zephir_fast_strlen_ev(variable));
		ZVAL_LONG(&_157$$29, 4);
		ZEPHIR_INIT_NVAR(&_156$$29);
		ZVAL_STRING(&_156$$29, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_155$$29, "htmlentities", NULL, 204, variable, &_157$$29, &_156$$29);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_158$$29, "nl2br", NULL, 214, &_155$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_154$$29, SL(":var"), &_158$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_156$$29);
		ZVAL_STRING(&_156$$29, "<b style=':style'>String</b> (<span style=':style'>:length</span>) \"<span style=':style'>:var</span>\"");
		ZEPHIR_CALL_FUNCTION(&_158$$29, "strtr", NULL, 3, &_156$$29, &_154$$29);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_158$$29);
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE)) {
		ZEPHIR_INIT_VAR(&_159$$30);
		zephir_create_array(&_159$$30, 2, 0);
		ZEPHIR_INIT_VAR(&_161$$30);
		ZVAL_STRING(&_161$$30, "bool");
		ZEPHIR_CALL_METHOD(&_160$$30, this_ptr, "getstyle", NULL, 0, &_161$$30);
		zephir_check_call_status();
		zephir_array_update_string(&_159$$30, SL(":style"), &_160$$30, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_162$$30);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_162$$30);
			ZVAL_STRING(&_162$$30, "TRUE");
		} else {
			ZEPHIR_INIT_NVAR(&_162$$30);
			ZVAL_STRING(&_162$$30, "FALSE");
		}
		zephir_array_update_string(&_159$$30, SL(":var"), &_162$$30, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_161$$30);
		ZVAL_STRING(&_161$$30, "<b style=':style'>Boolean</b> (<span style=':style'>:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_160$$30, "strtr", NULL, 3, &_161$$30, &_159$$30);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_160$$30);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_163$$31);
		zephir_create_array(&_163$$31, 1, 0);
		ZEPHIR_INIT_VAR(&_165$$31);
		ZVAL_STRING(&_165$$31, "null");
		ZEPHIR_CALL_METHOD(&_164$$31, this_ptr, "getstyle", NULL, 0, &_165$$31);
		zephir_check_call_status();
		zephir_array_update_string(&_163$$31, SL(":style"), &_164$$31, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_165$$31);
		ZVAL_STRING(&_165$$31, "<b style=':style'>NULL</b>");
		ZEPHIR_CALL_FUNCTION(&_164$$31, "strtr", NULL, 3, &_165$$31, &_163$$31);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_164$$31);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_166);
	zephir_create_array(&_166, 2, 0);
	ZEPHIR_INIT_VAR(&_168);
	ZVAL_STRING(&_168, "other");
	ZEPHIR_CALL_METHOD(&_167, this_ptr, "getstyle", NULL, 0, &_168);
	zephir_check_call_status();
	zephir_array_update_string(&_166, SL(":style"), &_167, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_166, SL(":var"), variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_168);
	ZVAL_STRING(&_168, "(<span style=':style'>:var</span>)");
	ZEPHIR_CALL_FUNCTION(&_167, "strtr", NULL, 3, &_168, &_166);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_167);
	RETURN_MM();

}

zend_object *zephir_init_properties_Phalcon_Debug_Dump(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

