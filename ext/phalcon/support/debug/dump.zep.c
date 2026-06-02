
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Support_Debug_Dump)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Debug, Dump, phalcon, support_debug_dump, phalcon_support_debug_dump_method_entry, 0);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_support_debug_dump_ce, SL("detailed"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_support_debug_dump_ce, SL("methods"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_support_debug_dump_ce, SL("styles"), ZEND_ACC_PROTECTED);
	/**
	 * @var Encode
	 */
	zend_declare_property_null(phalcon_support_debug_dump_ce, SL("encode"), ZEND_ACC_PRIVATE);
	phalcon_support_debug_dump_ce->create_object = zephir_init_properties_Phalcon_Support_Debug_Dump;

	return SUCCESS;
}

/**
 * Phalcon\Debug\Dump constructor
 */
PHP_METHOD(Phalcon_Support_Debug_Dump, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool detailed;
	zval *styles_param = NULL, *detailed_param = NULL, __$true, __$false, _0;
	zval styles;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&styles);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(styles, styles_param)
		Z_PARAM_BOOL(detailed)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
		}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_support_helper_json_encode_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_update_property_zval(this_ptr, ZEND_STRL("encode"), &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstyles", NULL, 0, &styles);
	zephir_check_call_status();
	if (detailed) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("detailed"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("detailed"), &__$false);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Alias of variables() method
 */
PHP_METHOD(Phalcon_Support_Debug_Dump, all)
{
	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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

PHP_METHOD(Phalcon_Support_Debug_Dump, getDetailed)
{

	RETURN_MEMBER(getThis(), "detailed");
}

/**
 * Alias of variable() method
 */
PHP_METHOD(Phalcon_Support_Debug_Dump, one)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *name = NULL;
	zval *variable, variable_sub, name_zv;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&name_zv);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(variable)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	variable = ZEND_CALL_ARG(execute_data, 1);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "variable", NULL, 0, variable, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Support_Debug_Dump, setDetailed)
{
	zval *flag_param = NULL, __$true, __$false;
	zend_bool flag;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(flag)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &flag_param);
	if (flag) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("detailed"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("detailed"), &__$false);
	}
}

/**
 * Set styles for vars type
 */
PHP_METHOD(Phalcon_Support_Debug_Dump, setStyles)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *styles_param = NULL, defaultStyles, _0;
	zval styles;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&styles);
	ZVAL_UNDEF(&defaultStyles);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(styles, styles_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("styles"), &_0);
	RETURN_MM_MEMBER_TYPED(getThis(), "styles", IS_ARRAY);
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
PHP_METHOD(Phalcon_Support_Debug_Dump, toJson)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *variable, variable_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(variable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &variable);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("encode"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, (((128 | 64) | 256) | 4194304));
	ZEPHIR_RETURN_CALL_METHOD(&_0, "__invoke", NULL, 0, variable, &_1);
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
PHP_METHOD(Phalcon_Support_Debug_Dump, variable)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *name = NULL;
	zval *variable, variable_sub, name_zv, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(variable)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	variable = ZEND_CALL_ARG(execute_data, 1);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "pre");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":style"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "output", NULL, 0, variable, &name_zv);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL(":output"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "<pre style=\":style\">:output</pre>");
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 6, &_2, &_0);
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
PHP_METHOD(Phalcon_Support_Debug_Dump, variables)
{
	zend_bool _8;
	zend_string *_3;
	zend_ulong _2;
	zval output;
	zval key, value, _0, *_1, _7, _4$$3, _5$$3, _9$$4, _10$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&output);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_args(&_0);
	zephir_is_iterable(&_0, 0, "phalcon/Support/Debug/Dump.zep", 198);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
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
			ZEPHIR_INIT_NVAR(&_5$$3);
			ZEPHIR_CONCAT_SV(&_5$$3, "var ", &key);
			ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "one", &_6, 0, &value, &_5$$3);
			zephir_check_call_status();
			zephir_concat_self(&output, &_4$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_7, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_10$$4);
				ZEPHIR_CONCAT_SV(&_10$$4, "var ", &key);
				ZEPHIR_CALL_METHOD(&_9$$4, this_ptr, "one", &_6, 0, &value, &_10$$4);
				zephir_check_call_status();
				zephir_concat_self(&output, &_9$$4);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&output);
}

/**
 * Get style for type
 */
PHP_METHOD(Phalcon_Support_Debug_Dump, getStyle)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval type_zv, style, _0;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&style);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	zephir_memory_observe(&style);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("styles"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&style, &_0, &type_zv, 0))) {
		RETURN_MM_STRING("color:gray");
	}
	RETURN_CCTOR(&style);
}

/**
 * Prepare an HTML string of information about a single variable.
 */
PHP_METHOD(Phalcon_Support_Debug_Dump, output)
{
	zend_class_entry *_75$$16, *_94$$17;
	zend_bool _21$$4, _14$$5, _15$$5, _16$$5, _28$$7, _29$$7, _30$$7, _43$$9, _60$$12, _89$$15, _129$$19;
	zend_ulong _5$$4, _49$$12;
	zval _0$$3, _155$$28, _159$$29;
	zval _172, _1$$4, _10$$5, _24$$7, _35$$9, _108$$9, _39$$10, _53$$13, _63$$14, _80$$16, _98$$17, _118$$21, _124$$22, _133$$24, _139$$25, _148$$26, _152$$27, _156$$28, _160$$29, _165$$30, _169$$31;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_18 = NULL, *_72 = NULL, *_73 = NULL, *_76 = NULL, *_78 = NULL, *_86 = NULL, *_91 = NULL, *_92 = NULL, *_96 = NULL, *_104 = NULL;
	zend_long tab, ZEPHIR_LAST_CALL_STATUS;
	zend_string *name = NULL, *_6$$4, *_50$$12;
	zval *variable, variable_sub, name_zv, *tab_param = NULL, key, value, output, space, type, attr, _151, _173, _174, _2$$4, _3$$4, *_4$$4, _20$$4, _33$$4, _34$$4, _7$$5, _8$$5, _11$$5, _12$$5, _13$$5, _17$$5, _19$$5, _22$$7, _23$$7, _25$$7, _26$$7, _27$$7, _31$$7, _32$$7, _36$$9, _37$$9, _38$$9, _42$$9, _106$$9, _107$$9, _109$$9, _110$$9, _146$$9, _147$$9, _40$$10, _41$$10, _44$$11, _45$$11, _46$$11, _47$$12, *_48$$12, _59$$12, _51$$13, _52$$13, _54$$13, _55$$13, _56$$13, _57$$13, _58$$13, _61$$14, _62$$14, _64$$14, _65$$14, _66$$14, _67$$14, _68$$14, reflect$$15, props$$15, property$$15, _69$$15, *_70$$15, _88$$15, _71$$16, _74$$16, _77$$16, _79$$16, _81$$16, _82$$16, _83$$16, _84$$16, _85$$16, _87$$16, _90$$17, _93$$17, _95$$17, _97$$17, _99$$17, _100$$17, _101$$17, _102$$17, _103$$17, _105$$17, _111$$18, _112$$18, _113$$18, *_114$$19, _128$$19, _143$$19, _144$$19, _145$$19, _115$$20, _116$$21, _117$$21, _119$$21, _120$$21, _121$$21, _122$$22, _123$$22, _125$$22, _126$$22, _127$$22, _130$$23, _131$$24, _132$$24, _134$$24, _135$$24, _136$$24, _137$$25, _138$$25, _140$$25, _141$$25, _142$$25, _149$$26, _150$$26, _153$$27, _154$$27, _157$$28, _158$$28, _161$$29, _162$$29, _163$$29, _164$$29, _166$$30, _167$$30, _168$$30, _170$$31, _171$$31;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&space);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&attr);
	ZVAL_UNDEF(&_151);
	ZVAL_UNDEF(&_173);
	ZVAL_UNDEF(&_174);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_33$$4);
	ZVAL_UNDEF(&_34$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_32$$7);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_37$$9);
	ZVAL_UNDEF(&_38$$9);
	ZVAL_UNDEF(&_42$$9);
	ZVAL_UNDEF(&_106$$9);
	ZVAL_UNDEF(&_107$$9);
	ZVAL_UNDEF(&_109$$9);
	ZVAL_UNDEF(&_110$$9);
	ZVAL_UNDEF(&_146$$9);
	ZVAL_UNDEF(&_147$$9);
	ZVAL_UNDEF(&_40$$10);
	ZVAL_UNDEF(&_41$$10);
	ZVAL_UNDEF(&_44$$11);
	ZVAL_UNDEF(&_45$$11);
	ZVAL_UNDEF(&_46$$11);
	ZVAL_UNDEF(&_47$$12);
	ZVAL_UNDEF(&_59$$12);
	ZVAL_UNDEF(&_51$$13);
	ZVAL_UNDEF(&_52$$13);
	ZVAL_UNDEF(&_54$$13);
	ZVAL_UNDEF(&_55$$13);
	ZVAL_UNDEF(&_56$$13);
	ZVAL_UNDEF(&_57$$13);
	ZVAL_UNDEF(&_58$$13);
	ZVAL_UNDEF(&_61$$14);
	ZVAL_UNDEF(&_62$$14);
	ZVAL_UNDEF(&_64$$14);
	ZVAL_UNDEF(&_65$$14);
	ZVAL_UNDEF(&_66$$14);
	ZVAL_UNDEF(&_67$$14);
	ZVAL_UNDEF(&_68$$14);
	ZVAL_UNDEF(&reflect$$15);
	ZVAL_UNDEF(&props$$15);
	ZVAL_UNDEF(&property$$15);
	ZVAL_UNDEF(&_69$$15);
	ZVAL_UNDEF(&_88$$15);
	ZVAL_UNDEF(&_71$$16);
	ZVAL_UNDEF(&_74$$16);
	ZVAL_UNDEF(&_77$$16);
	ZVAL_UNDEF(&_79$$16);
	ZVAL_UNDEF(&_81$$16);
	ZVAL_UNDEF(&_82$$16);
	ZVAL_UNDEF(&_83$$16);
	ZVAL_UNDEF(&_84$$16);
	ZVAL_UNDEF(&_85$$16);
	ZVAL_UNDEF(&_87$$16);
	ZVAL_UNDEF(&_90$$17);
	ZVAL_UNDEF(&_93$$17);
	ZVAL_UNDEF(&_95$$17);
	ZVAL_UNDEF(&_97$$17);
	ZVAL_UNDEF(&_99$$17);
	ZVAL_UNDEF(&_100$$17);
	ZVAL_UNDEF(&_101$$17);
	ZVAL_UNDEF(&_102$$17);
	ZVAL_UNDEF(&_103$$17);
	ZVAL_UNDEF(&_105$$17);
	ZVAL_UNDEF(&_111$$18);
	ZVAL_UNDEF(&_112$$18);
	ZVAL_UNDEF(&_113$$18);
	ZVAL_UNDEF(&_128$$19);
	ZVAL_UNDEF(&_143$$19);
	ZVAL_UNDEF(&_144$$19);
	ZVAL_UNDEF(&_145$$19);
	ZVAL_UNDEF(&_115$$20);
	ZVAL_UNDEF(&_116$$21);
	ZVAL_UNDEF(&_117$$21);
	ZVAL_UNDEF(&_119$$21);
	ZVAL_UNDEF(&_120$$21);
	ZVAL_UNDEF(&_121$$21);
	ZVAL_UNDEF(&_122$$22);
	ZVAL_UNDEF(&_123$$22);
	ZVAL_UNDEF(&_125$$22);
	ZVAL_UNDEF(&_126$$22);
	ZVAL_UNDEF(&_127$$22);
	ZVAL_UNDEF(&_130$$23);
	ZVAL_UNDEF(&_131$$24);
	ZVAL_UNDEF(&_132$$24);
	ZVAL_UNDEF(&_134$$24);
	ZVAL_UNDEF(&_135$$24);
	ZVAL_UNDEF(&_136$$24);
	ZVAL_UNDEF(&_137$$25);
	ZVAL_UNDEF(&_138$$25);
	ZVAL_UNDEF(&_140$$25);
	ZVAL_UNDEF(&_141$$25);
	ZVAL_UNDEF(&_142$$25);
	ZVAL_UNDEF(&_149$$26);
	ZVAL_UNDEF(&_150$$26);
	ZVAL_UNDEF(&_153$$27);
	ZVAL_UNDEF(&_154$$27);
	ZVAL_UNDEF(&_157$$28);
	ZVAL_UNDEF(&_158$$28);
	ZVAL_UNDEF(&_161$$29);
	ZVAL_UNDEF(&_162$$29);
	ZVAL_UNDEF(&_163$$29);
	ZVAL_UNDEF(&_164$$29);
	ZVAL_UNDEF(&_166$$30);
	ZVAL_UNDEF(&_167$$30);
	ZVAL_UNDEF(&_168$$30);
	ZVAL_UNDEF(&_170$$31);
	ZVAL_UNDEF(&_171$$31);
	ZVAL_UNDEF(&_172);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_35$$9);
	ZVAL_UNDEF(&_108$$9);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_53$$13);
	ZVAL_UNDEF(&_63$$14);
	ZVAL_UNDEF(&_80$$16);
	ZVAL_UNDEF(&_98$$17);
	ZVAL_UNDEF(&_118$$21);
	ZVAL_UNDEF(&_124$$22);
	ZVAL_UNDEF(&_133$$24);
	ZVAL_UNDEF(&_139$$25);
	ZVAL_UNDEF(&_148$$26);
	ZVAL_UNDEF(&_152$$27);
	ZVAL_UNDEF(&_156$$28);
	ZVAL_UNDEF(&_160$$29);
	ZVAL_UNDEF(&_165$$30);
	ZVAL_UNDEF(&_169$$31);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_155$$28);
	ZVAL_UNDEF(&_159$$29);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(variable)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
		Z_PARAM_LONG(tab)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	variable = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		tab_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	if (!tab_param) {
		tab = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&space);
	ZVAL_STRING(&space, "  ");
	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	if (!(ZEPHIR_IS_EMPTY(&name_zv))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_VS(&_0$$3, &name_zv, " ");
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
		ZVAL_STRING(&_3$$4, "<b style=\":style\">Array</b> (<span style=\":style\">:count</span>) (\n");
		ZEPHIR_CALL_FUNCTION(&_2$$4, "strtr", NULL, 6, &_3$$4, &_1$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, &_2$$4);
		zephir_is_iterable(variable, 0, "phalcon/Support/Debug/Dump.zep", 249);
		if (Z_TYPE_P(variable) == IS_ARRAY) {
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
				ZEPHIR_CALL_FUNCTION(&_8$$5, "str_repeat", &_9, 1, &space, &_7$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_10$$5);
				zephir_create_array(&_10$$5, 2, 0);
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZVAL_STRING(&_12$$5, "arr");
				ZEPHIR_CALL_METHOD(&_11$$5, this_ptr, "getstyle", NULL, 0, &_12$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_10$$5, SL(":style"), &_11$$5, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_10$$5, SL(":key"), &key, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZVAL_STRING(&_12$$5, "[<span style=\":style\">:key</span>] => ");
				ZEPHIR_CALL_FUNCTION(&_11$$5, "strtr", NULL, 6, &_12$$5, &_10$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZEPHIR_CONCAT_VV(&_13$$5, &_8$$5, &_11$$5);
				zephir_concat_self(&output, &_13$$5);
				_14$$5 = tab == 1;
				if (_14$$5) {
					_14$$5 = !ZEPHIR_IS_STRING(&name_zv, "");
				}
				_15$$5 = _14$$5;
				if (_15$$5) {
					_15$$5 = !(Z_TYPE_P(&key) == IS_LONG);
				}
				_16$$5 = _15$$5;
				if (_16$$5) {
					_16$$5 = ZEPHIR_IS_EQUAL(&name_zv, &key);
				}
				if (_16$$5) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZVAL_STRING(&_12$$5, "");
				ZVAL_LONG(&_7$$5, (tab + 1));
				ZEPHIR_CALL_METHOD(&_17$$5, this_ptr, "output", &_18, 0, &value, &_12$$5, &_7$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_19$$5);
				ZEPHIR_CONCAT_VS(&_19$$5, &_17$$5, "\n");
				zephir_concat_self(&output, &_19$$5);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, variable, "rewind", NULL, 0);
			zephir_check_call_status();
			_21$$4 = 1;
			while (1) {
				if (_21$$4) {
					_21$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, variable, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_20$$4, variable, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_20$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, variable, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, variable, "current", NULL, 0);
				zephir_check_call_status();
					ZVAL_LONG(&_22$$7, tab);
					ZEPHIR_CALL_FUNCTION(&_23$$7, "str_repeat", &_9, 1, &space, &_22$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_24$$7);
					zephir_create_array(&_24$$7, 2, 0);
					ZEPHIR_INIT_NVAR(&_26$$7);
					ZVAL_STRING(&_26$$7, "arr");
					ZEPHIR_CALL_METHOD(&_25$$7, this_ptr, "getstyle", NULL, 0, &_26$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_24$$7, SL(":style"), &_25$$7, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_24$$7, SL(":key"), &key, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_26$$7);
					ZVAL_STRING(&_26$$7, "[<span style=\":style\">:key</span>] => ");
					ZEPHIR_CALL_FUNCTION(&_25$$7, "strtr", NULL, 6, &_26$$7, &_24$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_27$$7);
					ZEPHIR_CONCAT_VV(&_27$$7, &_23$$7, &_25$$7);
					zephir_concat_self(&output, &_27$$7);
					_28$$7 = tab == 1;
					if (_28$$7) {
						_28$$7 = !ZEPHIR_IS_STRING(&name_zv, "");
					}
					_29$$7 = _28$$7;
					if (_29$$7) {
						_29$$7 = !(Z_TYPE_P(&key) == IS_LONG);
					}
					_30$$7 = _29$$7;
					if (_30$$7) {
						_30$$7 = ZEPHIR_IS_EQUAL(&name_zv, &key);
					}
					if (_30$$7) {
						continue;
					}
					ZEPHIR_INIT_NVAR(&_26$$7);
					ZVAL_STRING(&_26$$7, "");
					ZVAL_LONG(&_22$$7, (tab + 1));
					ZEPHIR_CALL_METHOD(&_31$$7, this_ptr, "output", &_18, 0, &value, &_26$$7, &_22$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_32$$7);
					ZEPHIR_CONCAT_VS(&_32$$7, &_31$$7, "\n");
					zephir_concat_self(&output, &_32$$7);
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_33$$4, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_34$$4, "str_repeat", &_9, 1, &space, &_33$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_34$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_35$$9);
		zephir_create_array(&_35$$9, 2, 0);
		ZEPHIR_INIT_VAR(&_37$$9);
		ZVAL_STRING(&_37$$9, "obj");
		ZEPHIR_CALL_METHOD(&_36$$9, this_ptr, "getstyle", NULL, 0, &_37$$9);
		zephir_check_call_status();
		zephir_array_update_string(&_35$$9, SL(":style"), &_36$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_37$$9);
		zephir_get_class(&_37$$9, variable, 0);
		zephir_array_update_string(&_35$$9, SL(":class"), &_37$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_37$$9);
		ZVAL_STRING(&_37$$9, "<b style=\":style\">Object</b> :class");
		ZEPHIR_CALL_FUNCTION(&_36$$9, "strtr", NULL, 6, &_37$$9, &_35$$9);
		zephir_check_call_status();
		zephir_concat_self(&output, &_36$$9);
		ZEPHIR_CALL_FUNCTION(&_38$$9, "get_parent_class", NULL, 0, variable);
		zephir_check_call_status();
		if (zephir_is_true(&_38$$9)) {
			ZEPHIR_INIT_VAR(&_39$$10);
			zephir_create_array(&_39$$10, 2, 0);
			ZEPHIR_INIT_VAR(&_41$$10);
			ZVAL_STRING(&_41$$10, "obj");
			ZEPHIR_CALL_METHOD(&_40$$10, this_ptr, "getstyle", NULL, 0, &_41$$10);
			zephir_check_call_status();
			zephir_array_update_string(&_39$$10, SL(":style"), &_40$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_40$$10, "get_parent_class", NULL, 0, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_39$$10, SL(":parent"), &_40$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_41$$10);
			ZVAL_STRING(&_41$$10, " <b style=\":style\">extends</b> :parent");
			ZEPHIR_CALL_FUNCTION(&_40$$10, "strtr", NULL, 6, &_41$$10, &_39$$10);
			zephir_check_call_status();
			zephir_concat_self(&output, &_40$$10);
		}
		zephir_concat_self_str(&output, SL(" (\n"));
		if (zephir_instance_of_ev(variable, phalcon_di_diinterface_ce)) {
			ZVAL_LONG(&_44$$11, tab);
			ZEPHIR_CALL_FUNCTION(&_45$$11, "str_repeat", &_9, 1, &space, &_44$$11);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_46$$11);
			ZEPHIR_CONCAT_VS(&_46$$11, &_45$$11, "[skipped]\n");
			zephir_concat_self(&output, &_46$$11);
		} else {
			zephir_read_property(&_42$$9, this_ptr, ZEND_STRL("detailed"), PH_NOISY_CC | PH_READONLY);
			_43$$9 = !zephir_is_true(&_42$$9);
			if (!(_43$$9)) {
				_43$$9 = zephir_is_instance_of(variable, SL("stdClass"));
			}
			if (_43$$9) {
				ZEPHIR_CALL_FUNCTION(&_47$$12, "get_object_vars", NULL, 0, variable);
				zephir_check_call_status();
				zephir_is_iterable(&_47$$12, 0, "phalcon/Support/Debug/Dump.zep", 285);
				if (Z_TYPE_P(&_47$$12) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_47$$12), _49$$12, _50$$12, _48$$12)
					{
						ZEPHIR_INIT_NVAR(&key);
						if (_50$$12 != NULL) { 
							ZVAL_STR_COPY(&key, _50$$12);
						} else {
							ZVAL_LONG(&key, _49$$12);
						}
						ZEPHIR_INIT_NVAR(&value);
						ZVAL_COPY(&value, _48$$12);
						ZVAL_LONG(&_51$$13, tab);
						ZEPHIR_CALL_FUNCTION(&_52$$13, "str_repeat", &_9, 1, &space, &_51$$13);
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
						ZVAL_STRING(&_55$$13, "-><span style=\":style\">:key</span> (<span style=\":style\">:type</span>) = ");
						ZEPHIR_CALL_FUNCTION(&_54$$13, "strtr", NULL, 6, &_55$$13, &_53$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_56$$13);
						ZEPHIR_CONCAT_VV(&_56$$13, &_52$$13, &_54$$13);
						zephir_concat_self(&output, &_56$$13);
						ZEPHIR_INIT_NVAR(&_55$$13);
						ZVAL_STRING(&_55$$13, "");
						ZVAL_LONG(&_51$$13, (tab + 1));
						ZEPHIR_CALL_METHOD(&_57$$13, this_ptr, "output", &_18, 0, &value, &_55$$13, &_51$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_58$$13);
						ZEPHIR_CONCAT_VS(&_58$$13, &_57$$13, "\n");
						zephir_concat_self(&output, &_58$$13);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_47$$12, "rewind", NULL, 0);
					zephir_check_call_status();
					_60$$12 = 1;
					while (1) {
						if (_60$$12) {
							_60$$12 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &_47$$12, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_59$$12, &_47$$12, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_59$$12)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&key, &_47$$12, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&value, &_47$$12, "current", NULL, 0);
						zephir_check_call_status();
							ZVAL_LONG(&_61$$14, tab);
							ZEPHIR_CALL_FUNCTION(&_62$$14, "str_repeat", &_9, 1, &space, &_61$$14);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_63$$14);
							zephir_create_array(&_63$$14, 3, 0);
							ZEPHIR_INIT_NVAR(&_65$$14);
							ZVAL_STRING(&_65$$14, "obj");
							ZEPHIR_CALL_METHOD(&_64$$14, this_ptr, "getstyle", NULL, 0, &_65$$14);
							zephir_check_call_status();
							zephir_array_update_string(&_63$$14, SL(":style"), &_64$$14, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_63$$14, SL(":key"), &key, PH_COPY | PH_SEPARATE);
							add_assoc_stringl_ex(&_63$$14, SL(":type"), SL("public"));
							ZEPHIR_INIT_NVAR(&_65$$14);
							ZVAL_STRING(&_65$$14, "-><span style=\":style\">:key</span> (<span style=\":style\">:type</span>) = ");
							ZEPHIR_CALL_FUNCTION(&_64$$14, "strtr", NULL, 6, &_65$$14, &_63$$14);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_66$$14);
							ZEPHIR_CONCAT_VV(&_66$$14, &_62$$14, &_64$$14);
							zephir_concat_self(&output, &_66$$14);
							ZEPHIR_INIT_NVAR(&_65$$14);
							ZVAL_STRING(&_65$$14, "");
							ZVAL_LONG(&_61$$14, (tab + 1));
							ZEPHIR_CALL_METHOD(&_67$$14, this_ptr, "output", &_18, 0, &value, &_65$$14, &_61$$14);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_68$$14);
							ZEPHIR_CONCAT_VS(&_68$$14, &_67$$14, "\n");
							zephir_concat_self(&output, &_68$$14);
					}
				}
				ZEPHIR_INIT_NVAR(&value);
				ZEPHIR_INIT_NVAR(&key);
			} else {
				ZEPHIR_INIT_VAR(&reflect$$15);
				object_init_ex(&reflect$$15, zephir_get_internal_ce(SL("reflectionclass")));
				ZEPHIR_CALL_METHOD(NULL, &reflect$$15, "__construct", NULL, 252, variable);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&reflect$$15, &reflect$$15);
				ZVAL_LONG(&_69$$15, ((1 | 2) | 4));
				ZEPHIR_CALL_METHOD(&props$$15, &reflect$$15, "getproperties", NULL, 268, &_69$$15);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&props$$15, &props$$15);
				zephir_is_iterable(&props$$15, 0, "phalcon/Support/Debug/Dump.zep", 315);
				if (Z_TYPE_P(&props$$15) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&props$$15), _70$$15)
					{
						ZEPHIR_INIT_NVAR(&property$$15);
						ZVAL_COPY(&property$$15, _70$$15);
						ZVAL_BOOL(&_71$$16, 1);
						ZEPHIR_CALL_METHOD(NULL, &property$$15, "setaccessible", &_72, 0, &_71$$16);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&key, &property$$15, "getname", &_73, 0);
						zephir_check_call_status();
						_75$$16 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
						ZEPHIR_CALL_METHOD(&_77$$16, &property$$15, "getmodifiers", &_78, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_CE_STATIC(&_74$$16, _75$$16, "getmodifiernames", &_76, 0, &_77$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&type);
						zephir_fast_join_str(&type, SL(" "), &_74$$16);
						ZVAL_LONG(&_71$$16, tab);
						ZEPHIR_CALL_FUNCTION(&_79$$16, "str_repeat", &_9, 1, &space, &_71$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_80$$16);
						zephir_create_array(&_80$$16, 3, 0);
						ZEPHIR_INIT_NVAR(&_82$$16);
						ZVAL_STRING(&_82$$16, "obj");
						ZEPHIR_CALL_METHOD(&_81$$16, this_ptr, "getstyle", NULL, 0, &_82$$16);
						zephir_check_call_status();
						zephir_array_update_string(&_80$$16, SL(":style"), &_81$$16, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_80$$16, SL(":key"), &key, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_80$$16, SL(":type"), &type, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_82$$16);
						ZVAL_STRING(&_82$$16, "-><span style=\":style\">:key</span> (<span style=\":style\">:type</span>) = ");
						ZEPHIR_CALL_FUNCTION(&_81$$16, "strtr", NULL, 6, &_82$$16, &_80$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_83$$16);
						ZEPHIR_CONCAT_VV(&_83$$16, &_79$$16, &_81$$16);
						zephir_concat_self(&output, &_83$$16);
						ZEPHIR_CALL_METHOD(&_85$$16, &property$$15, "getvalue", &_86, 0, variable);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_82$$16);
						ZVAL_STRING(&_82$$16, "");
						ZVAL_LONG(&_71$$16, (tab + 1));
						ZEPHIR_CALL_METHOD(&_84$$16, this_ptr, "output", &_18, 0, &_85$$16, &_82$$16, &_71$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_87$$16);
						ZEPHIR_CONCAT_VS(&_87$$16, &_84$$16, "\n");
						zephir_concat_self(&output, &_87$$16);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &props$$15, "rewind", NULL, 0);
					zephir_check_call_status();
					_89$$15 = 1;
					while (1) {
						if (_89$$15) {
							_89$$15 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &props$$15, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_88$$15, &props$$15, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_88$$15)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&property$$15, &props$$15, "current", NULL, 0);
						zephir_check_call_status();
							ZVAL_BOOL(&_90$$17, 1);
							ZEPHIR_CALL_METHOD(NULL, &property$$15, "setaccessible", &_91, 0, &_90$$17);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&key, &property$$15, "getname", &_92, 0);
							zephir_check_call_status();
							_94$$17 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
							ZEPHIR_CALL_METHOD(&_95$$17, &property$$15, "getmodifiers", &_96, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_CE_STATIC(&_93$$17, _94$$17, "getmodifiernames", &_76, 0, &_95$$17);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&type);
							zephir_fast_join_str(&type, SL(" "), &_93$$17);
							ZVAL_LONG(&_90$$17, tab);
							ZEPHIR_CALL_FUNCTION(&_97$$17, "str_repeat", &_9, 1, &space, &_90$$17);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_98$$17);
							zephir_create_array(&_98$$17, 3, 0);
							ZEPHIR_INIT_NVAR(&_100$$17);
							ZVAL_STRING(&_100$$17, "obj");
							ZEPHIR_CALL_METHOD(&_99$$17, this_ptr, "getstyle", NULL, 0, &_100$$17);
							zephir_check_call_status();
							zephir_array_update_string(&_98$$17, SL(":style"), &_99$$17, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_98$$17, SL(":key"), &key, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_98$$17, SL(":type"), &type, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_100$$17);
							ZVAL_STRING(&_100$$17, "-><span style=\":style\">:key</span> (<span style=\":style\">:type</span>) = ");
							ZEPHIR_CALL_FUNCTION(&_99$$17, "strtr", NULL, 6, &_100$$17, &_98$$17);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_101$$17);
							ZEPHIR_CONCAT_VV(&_101$$17, &_97$$17, &_99$$17);
							zephir_concat_self(&output, &_101$$17);
							ZEPHIR_CALL_METHOD(&_103$$17, &property$$15, "getvalue", &_104, 0, variable);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_100$$17);
							ZVAL_STRING(&_100$$17, "");
							ZVAL_LONG(&_90$$17, (tab + 1));
							ZEPHIR_CALL_METHOD(&_102$$17, this_ptr, "output", &_18, 0, &_103$$17, &_100$$17, &_90$$17);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_105$$17);
							ZEPHIR_CONCAT_VS(&_105$$17, &_102$$17, "\n");
							zephir_concat_self(&output, &_105$$17);
					}
				}
				ZEPHIR_INIT_NVAR(&property$$15);
			}
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 0, variable);
		zephir_check_call_status();
		ZVAL_LONG(&_106$$9, tab);
		ZEPHIR_CALL_FUNCTION(&_107$$9, "str_repeat", &_9, 1, &space, &_106$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_108$$9);
		zephir_create_array(&_108$$9, 3, 0);
		ZEPHIR_INIT_NVAR(&_37$$9);
		ZVAL_STRING(&_37$$9, "obj");
		ZEPHIR_CALL_METHOD(&_109$$9, this_ptr, "getstyle", NULL, 0, &_37$$9);
		zephir_check_call_status();
		zephir_array_update_string(&_108$$9, SL(":style"), &_109$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_37$$9);
		zephir_get_class(&_37$$9, variable, 0);
		zephir_array_update_string(&_108$$9, SL(":class"), &_37$$9, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_108$$9, SL(":count"), zephir_fast_count_int(&attr));
		ZEPHIR_INIT_NVAR(&_37$$9);
		ZVAL_STRING(&_37$$9, ":class <b style=\":style\">methods</b>: (<span style=\":style\">:count</span>) (\n");
		ZEPHIR_CALL_FUNCTION(&_109$$9, "strtr", NULL, 6, &_37$$9, &_108$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_110$$9);
		ZEPHIR_CONCAT_VV(&_110$$9, &_107$$9, &_109$$9);
		zephir_concat_self(&output, &_110$$9);
		ZEPHIR_INIT_NVAR(&_37$$9);
		zephir_get_class(&_37$$9, variable, 0);
		zephir_read_property(&_106$$9, this_ptr, ZEND_STRL("methods"), PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&_37$$9, &_106$$9)) {
			ZVAL_LONG(&_111$$18, tab);
			ZEPHIR_CALL_FUNCTION(&_112$$18, "str_repeat", &_9, 1, &space, &_111$$18);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_113$$18);
			ZEPHIR_CONCAT_VS(&_113$$18, &_112$$18, "[already listed]\n");
			zephir_concat_self(&output, &_113$$18);
		} else {
			zephir_is_iterable(&attr, 0, "phalcon/Support/Debug/Dump.zep", 345);
			if (Z_TYPE_P(&attr) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attr), _114$$19)
				{
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _114$$19);
					ZEPHIR_INIT_NVAR(&_115$$20);
					zephir_get_class(&_115$$20, variable, 0);
					zephir_update_property_array_append(this_ptr, SL("methods"), &_115$$20);
					if (ZEPHIR_IS_STRING(&value, "__construct")) {
						ZVAL_LONG(&_116$$21, (tab + 1));
						ZEPHIR_CALL_FUNCTION(&_117$$21, "str_repeat", &_9, 1, &space, &_116$$21);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_118$$21);
						zephir_create_array(&_118$$21, 2, 0);
						ZEPHIR_INIT_NVAR(&_120$$21);
						ZVAL_STRING(&_120$$21, "obj");
						ZEPHIR_CALL_METHOD(&_119$$21, this_ptr, "getstyle", NULL, 0, &_120$$21);
						zephir_check_call_status();
						zephir_array_update_string(&_118$$21, SL(":style"), &_119$$21, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_118$$21, SL(":method"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_120$$21);
						ZVAL_STRING(&_120$$21, "-><span style=\":style\">:method</span>(); [<b style=\":style\">constructor</b>]\n");
						ZEPHIR_CALL_FUNCTION(&_119$$21, "strtr", NULL, 6, &_120$$21, &_118$$21);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_121$$21);
						ZEPHIR_CONCAT_VV(&_121$$21, &_117$$21, &_119$$21);
						zephir_concat_self(&output, &_121$$21);
					} else {
						ZVAL_LONG(&_122$$22, (tab + 1));
						ZEPHIR_CALL_FUNCTION(&_123$$22, "str_repeat", &_9, 1, &space, &_122$$22);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_124$$22);
						zephir_create_array(&_124$$22, 2, 0);
						ZEPHIR_INIT_NVAR(&_126$$22);
						ZVAL_STRING(&_126$$22, "obj");
						ZEPHIR_CALL_METHOD(&_125$$22, this_ptr, "getstyle", NULL, 0, &_126$$22);
						zephir_check_call_status();
						zephir_array_update_string(&_124$$22, SL(":style"), &_125$$22, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_124$$22, SL(":method"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_126$$22);
						ZVAL_STRING(&_126$$22, "-><span style=\":style\">:method</span>();\n");
						ZEPHIR_CALL_FUNCTION(&_125$$22, "strtr", NULL, 6, &_126$$22, &_124$$22);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_127$$22);
						ZEPHIR_CONCAT_VV(&_127$$22, &_123$$22, &_125$$22);
						zephir_concat_self(&output, &_127$$22);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &attr, "rewind", NULL, 0);
				zephir_check_call_status();
				_129$$19 = 1;
				while (1) {
					if (_129$$19) {
						_129$$19 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &attr, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_128$$19, &attr, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_128$$19)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&value, &attr, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_130$$23);
						zephir_get_class(&_130$$23, variable, 0);
						zephir_update_property_array_append(this_ptr, SL("methods"), &_130$$23);
						if (ZEPHIR_IS_STRING(&value, "__construct")) {
							ZVAL_LONG(&_131$$24, (tab + 1));
							ZEPHIR_CALL_FUNCTION(&_132$$24, "str_repeat", &_9, 1, &space, &_131$$24);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_133$$24);
							zephir_create_array(&_133$$24, 2, 0);
							ZEPHIR_INIT_NVAR(&_135$$24);
							ZVAL_STRING(&_135$$24, "obj");
							ZEPHIR_CALL_METHOD(&_134$$24, this_ptr, "getstyle", NULL, 0, &_135$$24);
							zephir_check_call_status();
							zephir_array_update_string(&_133$$24, SL(":style"), &_134$$24, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_133$$24, SL(":method"), &value, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_135$$24);
							ZVAL_STRING(&_135$$24, "-><span style=\":style\">:method</span>(); [<b style=\":style\">constructor</b>]\n");
							ZEPHIR_CALL_FUNCTION(&_134$$24, "strtr", NULL, 6, &_135$$24, &_133$$24);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_136$$24);
							ZEPHIR_CONCAT_VV(&_136$$24, &_132$$24, &_134$$24);
							zephir_concat_self(&output, &_136$$24);
						} else {
							ZVAL_LONG(&_137$$25, (tab + 1));
							ZEPHIR_CALL_FUNCTION(&_138$$25, "str_repeat", &_9, 1, &space, &_137$$25);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_139$$25);
							zephir_create_array(&_139$$25, 2, 0);
							ZEPHIR_INIT_NVAR(&_141$$25);
							ZVAL_STRING(&_141$$25, "obj");
							ZEPHIR_CALL_METHOD(&_140$$25, this_ptr, "getstyle", NULL, 0, &_141$$25);
							zephir_check_call_status();
							zephir_array_update_string(&_139$$25, SL(":style"), &_140$$25, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_139$$25, SL(":method"), &value, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_141$$25);
							ZVAL_STRING(&_141$$25, "-><span style=\":style\">:method</span>();\n");
							ZEPHIR_CALL_FUNCTION(&_140$$25, "strtr", NULL, 6, &_141$$25, &_139$$25);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_142$$25);
							ZEPHIR_CONCAT_VV(&_142$$25, &_138$$25, &_140$$25);
							zephir_concat_self(&output, &_142$$25);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_LONG(&_143$$19, tab);
			ZEPHIR_CALL_FUNCTION(&_144$$19, "str_repeat", &_9, 1, &space, &_143$$19);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_145$$19);
			ZEPHIR_CONCAT_VS(&_145$$19, &_144$$19, ")\n");
			zephir_concat_self(&output, &_145$$19);
		}
		ZVAL_LONG(&_146$$9, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_147$$9, "str_repeat", &_9, 1, &space, &_146$$9);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_147$$9, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_148$$26);
		zephir_create_array(&_148$$26, 2, 0);
		ZEPHIR_INIT_VAR(&_150$$26);
		ZVAL_STRING(&_150$$26, "int");
		ZEPHIR_CALL_METHOD(&_149$$26, this_ptr, "getstyle", NULL, 0, &_150$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_148$$26, SL(":style"), &_149$$26, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_148$$26, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_150$$26);
		ZVAL_STRING(&_150$$26, "<b style=\":style\">Integer</b> (<span style=\":style\">:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_149$$26, "strtr", NULL, 6, &_150$$26, &_148$$26);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_149$$26);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_151, "is_float", NULL, 29, variable);
	zephir_check_call_status();
	if (zephir_is_true(&_151)) {
		ZEPHIR_INIT_VAR(&_152$$27);
		zephir_create_array(&_152$$27, 2, 0);
		ZEPHIR_INIT_VAR(&_154$$27);
		ZVAL_STRING(&_154$$27, "float");
		ZEPHIR_CALL_METHOD(&_153$$27, this_ptr, "getstyle", NULL, 0, &_154$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_152$$27, SL(":style"), &_153$$27, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_152$$27, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_154$$27);
		ZVAL_STRING(&_154$$27, "<b style=\":style\">Float</b> (<span style=\":style\">:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_153$$27, "strtr", NULL, 6, &_154$$27, &_152$$27);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_153$$27);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_155$$28);
		ZEPHIR_CONCAT_SS(&_155$$28, "<b style=\":style\">Numeric String</b> ", "(<span style=\":style\">:length</span>) \"<span style=\":style\">:var</span>\"");
		ZEPHIR_INIT_VAR(&_156$$28);
		zephir_create_array(&_156$$28, 3, 0);
		ZEPHIR_INIT_VAR(&_158$$28);
		ZVAL_STRING(&_158$$28, "num");
		ZEPHIR_CALL_METHOD(&_157$$28, this_ptr, "getstyle", NULL, 0, &_158$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_156$$28, SL(":style"), &_157$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_157$$28, "mb_strlen", NULL, 464, variable);
		zephir_check_call_status();
		zephir_array_update_string(&_156$$28, SL(":length"), &_157$$28, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_156$$28, SL(":var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_157$$28, "strtr", NULL, 6, &_155$$28, &_156$$28);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_157$$28);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_159$$29);
		ZEPHIR_CONCAT_SS(&_159$$29, "<b style=\":style\">String</b> ", "(<span style=\":style\">:length</span>) \"<span style=\":style\">:var</span>\"");
		ZEPHIR_INIT_VAR(&_160$$29);
		zephir_create_array(&_160$$29, 3, 0);
		ZEPHIR_INIT_VAR(&_162$$29);
		ZVAL_STRING(&_162$$29, "str");
		ZEPHIR_CALL_METHOD(&_161$$29, this_ptr, "getstyle", NULL, 0, &_162$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_160$$29, SL(":style"), &_161$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_161$$29, "mb_strlen", NULL, 464, variable);
		zephir_check_call_status();
		zephir_array_update_string(&_160$$29, SL(":length"), &_161$$29, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_163$$29, 4);
		ZEPHIR_INIT_NVAR(&_162$$29);
		ZVAL_STRING(&_162$$29, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_161$$29, "htmlentities", NULL, 0, variable, &_163$$29, &_162$$29);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_164$$29, "nl2br", NULL, 0, &_161$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_160$$29, SL(":var"), &_164$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_164$$29, "strtr", NULL, 6, &_159$$29, &_160$$29);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_164$$29);
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE)) {
		ZEPHIR_INIT_VAR(&_165$$30);
		zephir_create_array(&_165$$30, 2, 0);
		ZEPHIR_INIT_VAR(&_167$$30);
		ZVAL_STRING(&_167$$30, "bool");
		ZEPHIR_CALL_METHOD(&_166$$30, this_ptr, "getstyle", NULL, 0, &_167$$30);
		zephir_check_call_status();
		zephir_array_update_string(&_165$$30, SL(":style"), &_166$$30, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_168$$30);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_168$$30);
			ZVAL_STRING(&_168$$30, "TRUE");
		} else {
			ZEPHIR_INIT_NVAR(&_168$$30);
			ZVAL_STRING(&_168$$30, "FALSE");
		}
		zephir_array_update_string(&_165$$30, SL(":var"), &_168$$30, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_167$$30);
		ZVAL_STRING(&_167$$30, "<b style=\":style\">Boolean</b> (<span style=\":style\">:var</span>)");
		ZEPHIR_CALL_FUNCTION(&_166$$30, "strtr", NULL, 6, &_167$$30, &_165$$30);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_166$$30);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_169$$31);
		zephir_create_array(&_169$$31, 1, 0);
		ZEPHIR_INIT_VAR(&_171$$31);
		ZVAL_STRING(&_171$$31, "null");
		ZEPHIR_CALL_METHOD(&_170$$31, this_ptr, "getstyle", NULL, 0, &_171$$31);
		zephir_check_call_status();
		zephir_array_update_string(&_169$$31, SL(":style"), &_170$$31, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_171$$31);
		ZVAL_STRING(&_171$$31, "<b style=\":style\">NULL</b>");
		ZEPHIR_CALL_FUNCTION(&_170$$31, "strtr", NULL, 6, &_171$$31, &_169$$31);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_170$$31);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_172);
	zephir_create_array(&_172, 2, 0);
	ZEPHIR_INIT_VAR(&_174);
	ZVAL_STRING(&_174, "other");
	ZEPHIR_CALL_METHOD(&_173, this_ptr, "getstyle", NULL, 0, &_174);
	zephir_check_call_status();
	zephir_array_update_string(&_172, SL(":style"), &_173, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_172, SL(":var"), variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_174);
	ZVAL_STRING(&_174, "(<span style=\":style\">:var</span>)");
	ZEPHIR_CALL_FUNCTION(&_173, "strtr", NULL, 6, &_174, &_172);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_173);
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Support_Debug_Dump(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("styles"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("styles"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("methods"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("methods"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

