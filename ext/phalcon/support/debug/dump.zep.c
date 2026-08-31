
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
 *
 * @phpstan-import-type support_debug_styles from SupportTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Debug_Dump)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Debug, Dump, phalcon, support_debug_dump, phalcon_support_debug_dump_method_entry, 0);

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_support_debug_dump_ce, SL("detailed"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * @var array<array-key, class-string>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_support_debug_dump_ce, SL("methods"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var support_debug_styles
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_support_debug_dump_ce, SL("styles"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_support_debug_dump_ce, SL("encode"), &_zc0, ZEND_ACC_PRIVATE, 0, SL("Phalcon\\Support\\Helper\\Json\\Encode"));
	}

	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_support_debug_dump_ce, SL("templates"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	zend_class_implements(phalcon_support_debug_dump_ce, 1, phalcon_contracts_support_debug_templateaware_ce);
	return SUCCESS;
}

/**
 * Dump constructor.
 *
 * @phpstan-param support_debug_styles $styles
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("encode", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("detailed", 8, 1);
	}

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
		zephir_get_arrval(&styles, styles_param);
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

	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1355, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstyles", NULL, 0, &styles);
	zephir_check_call_status();
	if (detailed) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1356, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1356, &__$false);
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
 *
 * @throws ReflectionException
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("detailed", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(flag)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &flag_param);
	if (flag) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1356, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1356, &__$false);
	}
}

/**
 * Set styles for vars type
 *
 * @phpstan-param  support_debug_styles $styles
 * @phpstan-return support_debug_styles
 */
PHP_METHOD(Phalcon_Support_Debug_Dump, setStyles)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *styles_param = NULL, defaultStyles, _1;
	zval styles;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&styles);
	ZVAL_UNDEF(&defaultStyles);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("styles", 6, 1);
	}

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
		zephir_get_arrval(&styles, styles_param);
	}
	ZEPHIR_INIT_VAR(&defaultStyles);
	zephir_create_array(&defaultStyles, 11, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SSS(&_0, "background-color:#f3f3f3; font-size:11px; ", "padding:10px; border:1px solid #ccc; ", "text-align:left; color:#333");
	zephir_array_update_string(&defaultStyles, SL("pre"), &_0, PH_COPY | PH_SEPARATE);
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
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_array_merge(&_1, &defaultStyles, &styles);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1357, &_1);
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
 *
 * @throws InvalidArgumentException
 * @throws JsonException
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("encode", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(variable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &variable);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1355, PH_NOISY_CC | PH_READONLY);
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
 *
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Support_Debug_Dump, variable)
{
	zval context;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *name = NULL;
	zval *variable, variable_sub, name_zv, message, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&context);
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
	ZVAL_STRING(&_0, "pre");
	ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&context);
	zephir_create_array(&context, 2, 0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "pre");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstyle", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_array_update_string(&context, SL("style"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "output", NULL, 0, variable, &name_zv);
	zephir_check_call_status();
	zephir_array_update_string(&context, SL("output"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "tointerpolate", NULL, 0, &message, &context);
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
 *
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Support_Debug_Dump, variables)
{
	zend_bool _10;
	zend_string *_5;
	zend_ulong _4;
	zval output;
	zval key, value, _0, *_1, _2, *_3, _9, _6$$3, _7$$3, _11$$4, _12$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&output);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_args(&_0);
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/Support/Debug/Dump.zep", 220);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&key, _5);
			} else {
				ZVAL_LONG(&key, _4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _3);
			ZEPHIR_INIT_NVAR(&_7$$3);
			ZEPHIR_CONCAT_SV(&_7$$3, "var ", &key);
			ZEPHIR_CALL_METHOD(&_6$$3, this_ptr, "one", &_8, 0, &value, &_7$$3);
			zephir_check_call_status();
			zephir_concat_self(&output, &_6$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, _1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$4);
				ZEPHIR_CONCAT_SV(&_12$$4, "var ", &key);
				ZEPHIR_CALL_METHOD(&_11$$4, this_ptr, "one", &_8, 0, &value, &_12$$4);
				zephir_check_call_status();
				zephir_concat_self(&output, &_11$$4);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&output);
}

/**
 * Returns the embedded default template for the given name.
 *
 * @param string $name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Dump, defaultTemplate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name_zv, defaults, template;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&template);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_INIT_VAR(&defaults);
	zephir_create_array(&defaults, 12, 0);
	add_assoc_stringl_ex(&defaults, SL("pre"), SL("<pre style=\"%style%\">%output%</pre>"));
	add_assoc_stringl_ex(&defaults, SL("bold"), SL("<b style=\"%style%\">%text%</b>"));
	add_assoc_stringl_ex(&defaults, SL("varParens"), SL("(<span style=\"%style%\">%var%</span>)"));
	add_assoc_stringl_ex(&defaults, SL("lengthValue"), SL("(<span style=\"%style%\">%length%</span>) \"<span style=\"%style%\">%var%</span>\""));
	add_assoc_stringl_ex(&defaults, SL("arrayHeader"), SL("<b style=\"%style%\">Array</b> (<span style=\"%style%\">%count%</span>) (\n"));
	add_assoc_stringl_ex(&defaults, SL("arrayKey"), SL("[<span style=\"%style%\">%key%</span>] => "));
	add_assoc_stringl_ex(&defaults, SL("objectHeader"), SL("<b style=\"%style%\">Object</b> %class%"));
	add_assoc_stringl_ex(&defaults, SL("objectExtends"), SL(" <b style=\"%style%\">extends</b> %parent%"));
	add_assoc_stringl_ex(&defaults, SL("objectProperty"), SL("-><span style=\"%style%\">%key%</span> (<span style=\"%style%\">%type%</span>) = "));
	add_assoc_stringl_ex(&defaults, SL("objectMethods"), SL("%class% <b style=\"%style%\">methods</b>: (<span style=\"%style%\">%count%</span>) (\n"));
	add_assoc_stringl_ex(&defaults, SL("objectMethod"), SL("-><span style=\"%style%\">%method%</span>();\n"));
	add_assoc_stringl_ex(&defaults, SL("objectMethodConstructor"), SL("-><span style=\"%style%\">%method%</span>(); [<b style=\"%style%\">constructor</b>]\n"));
	zephir_memory_observe(&template);
	if (zephir_array_isset_fetch(&template, &defaults, &name_zv, 0)) {
		RETURN_CCTOR(&template);
	}
	RETURN_MM_STRING("");
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("styles", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	zephir_memory_observe(&style);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1357, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&style, &_0, &type_zv, 0))) {
		RETURN_MM_STRING("color:gray");
	}
	RETURN_CCTOR(&style);
}

/**
 * Prepare an HTML string of information about a single variable.
 *
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Support_Debug_Dump, output)
{
	zend_class_entry *_77$$16, *_91$$17;
	zend_bool _23$$4, _16$$5, _17$$5, _18$$5, _30$$7, _31$$7, _32$$7, _44$$9, _45$$9, _47$$9, _64$$12, _89$$15, _121$$19;
	zend_ulong _6$$4, _54$$12;
	zval space, _0$$3, _14$$5, _29$$7, _150$$26;
	zval context;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_15 = NULL, *_20 = NULL, *_78 = NULL;
	zend_long tab, ZEPHIR_LAST_CALL_STATUS;
	zend_string *name = NULL, *_7$$4, *_55$$12;
	zval *variable, variable_sub, name_zv, *tab_param = NULL, attr, key, message, output, property, props, reflect, type, value, vars, _167, _168, _169, _1$$4, _2$$4, _3$$4, *_4$$4, *_5$$4, _22$$4, _35$$4, _36$$4, _8$$5, _9$$5, _11$$5, _12$$5, _13$$5, _19$$5, _21$$5, _24$$7, _25$$7, _26$$7, _27$$7, _28$$7, _33$$7, _34$$7, _37$$9, _38$$9, _39$$9, _40$$9, _46$$9, _101$$9, _102$$9, _103$$9, _104$$9, _105$$9, _133$$9, _134$$9, _41$$10, _42$$10, _43$$10, _48$$11, _49$$11, _50$$11, *_51$$12, _52$$12, *_53$$12, _63$$12, _56$$13, _57$$13, _58$$13, _59$$13, _60$$13, _61$$13, _62$$13, _65$$14, _66$$14, _67$$14, _68$$14, _69$$14, _70$$14, _71$$14, _72$$15, *_73$$15, _74$$15, *_75$$15, _88$$15, _76$$16, _79$$16, _80$$16, _81$$16, _82$$16, _83$$16, _84$$16, _85$$16, _86$$16, _87$$16, _90$$17, _92$$17, _93$$17, _94$$17, _95$$17, _96$$17, _97$$17, _98$$17, _99$$17, _100$$17, _106$$18, _107$$18, _108$$18, *_109$$19, _110$$19, *_111$$19, _120$$19, _130$$19, _131$$19, _132$$19, _112$$20, _113$$20, _115$$20, _116$$20, _117$$20, _118$$20, _119$$20, _114$$21, _122$$22, _123$$22, _125$$22, _126$$22, _127$$22, _128$$22, _129$$22, _124$$23, _135$$24, _136$$24, _137$$24, _138$$24, _139$$24, _140$$25, _141$$25, _142$$25, _143$$25, _144$$25, _145$$26, _146$$26, _147$$26, _148$$26, _149$$26, _151$$27, _152$$27, _153$$27, _154$$27, _155$$27, _156$$27, _157$$27, _158$$28, _159$$28, _160$$28, _161$$28, _162$$28, _163$$28, _164$$29, _165$$29, _166$$29;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&attr);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&props);
	ZVAL_UNDEF(&reflect);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&vars);
	ZVAL_UNDEF(&_167);
	ZVAL_UNDEF(&_168);
	ZVAL_UNDEF(&_169);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_35$$4);
	ZVAL_UNDEF(&_36$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_33$$7);
	ZVAL_UNDEF(&_34$$7);
	ZVAL_UNDEF(&_37$$9);
	ZVAL_UNDEF(&_38$$9);
	ZVAL_UNDEF(&_39$$9);
	ZVAL_UNDEF(&_40$$9);
	ZVAL_UNDEF(&_46$$9);
	ZVAL_UNDEF(&_101$$9);
	ZVAL_UNDEF(&_102$$9);
	ZVAL_UNDEF(&_103$$9);
	ZVAL_UNDEF(&_104$$9);
	ZVAL_UNDEF(&_105$$9);
	ZVAL_UNDEF(&_133$$9);
	ZVAL_UNDEF(&_134$$9);
	ZVAL_UNDEF(&_41$$10);
	ZVAL_UNDEF(&_42$$10);
	ZVAL_UNDEF(&_43$$10);
	ZVAL_UNDEF(&_48$$11);
	ZVAL_UNDEF(&_49$$11);
	ZVAL_UNDEF(&_50$$11);
	ZVAL_UNDEF(&_52$$12);
	ZVAL_UNDEF(&_63$$12);
	ZVAL_UNDEF(&_56$$13);
	ZVAL_UNDEF(&_57$$13);
	ZVAL_UNDEF(&_58$$13);
	ZVAL_UNDEF(&_59$$13);
	ZVAL_UNDEF(&_60$$13);
	ZVAL_UNDEF(&_61$$13);
	ZVAL_UNDEF(&_62$$13);
	ZVAL_UNDEF(&_65$$14);
	ZVAL_UNDEF(&_66$$14);
	ZVAL_UNDEF(&_67$$14);
	ZVAL_UNDEF(&_68$$14);
	ZVAL_UNDEF(&_69$$14);
	ZVAL_UNDEF(&_70$$14);
	ZVAL_UNDEF(&_71$$14);
	ZVAL_UNDEF(&_72$$15);
	ZVAL_UNDEF(&_74$$15);
	ZVAL_UNDEF(&_88$$15);
	ZVAL_UNDEF(&_76$$16);
	ZVAL_UNDEF(&_79$$16);
	ZVAL_UNDEF(&_80$$16);
	ZVAL_UNDEF(&_81$$16);
	ZVAL_UNDEF(&_82$$16);
	ZVAL_UNDEF(&_83$$16);
	ZVAL_UNDEF(&_84$$16);
	ZVAL_UNDEF(&_85$$16);
	ZVAL_UNDEF(&_86$$16);
	ZVAL_UNDEF(&_87$$16);
	ZVAL_UNDEF(&_90$$17);
	ZVAL_UNDEF(&_92$$17);
	ZVAL_UNDEF(&_93$$17);
	ZVAL_UNDEF(&_94$$17);
	ZVAL_UNDEF(&_95$$17);
	ZVAL_UNDEF(&_96$$17);
	ZVAL_UNDEF(&_97$$17);
	ZVAL_UNDEF(&_98$$17);
	ZVAL_UNDEF(&_99$$17);
	ZVAL_UNDEF(&_100$$17);
	ZVAL_UNDEF(&_106$$18);
	ZVAL_UNDEF(&_107$$18);
	ZVAL_UNDEF(&_108$$18);
	ZVAL_UNDEF(&_110$$19);
	ZVAL_UNDEF(&_120$$19);
	ZVAL_UNDEF(&_130$$19);
	ZVAL_UNDEF(&_131$$19);
	ZVAL_UNDEF(&_132$$19);
	ZVAL_UNDEF(&_112$$20);
	ZVAL_UNDEF(&_113$$20);
	ZVAL_UNDEF(&_115$$20);
	ZVAL_UNDEF(&_116$$20);
	ZVAL_UNDEF(&_117$$20);
	ZVAL_UNDEF(&_118$$20);
	ZVAL_UNDEF(&_119$$20);
	ZVAL_UNDEF(&_114$$21);
	ZVAL_UNDEF(&_122$$22);
	ZVAL_UNDEF(&_123$$22);
	ZVAL_UNDEF(&_125$$22);
	ZVAL_UNDEF(&_126$$22);
	ZVAL_UNDEF(&_127$$22);
	ZVAL_UNDEF(&_128$$22);
	ZVAL_UNDEF(&_129$$22);
	ZVAL_UNDEF(&_124$$23);
	ZVAL_UNDEF(&_135$$24);
	ZVAL_UNDEF(&_136$$24);
	ZVAL_UNDEF(&_137$$24);
	ZVAL_UNDEF(&_138$$24);
	ZVAL_UNDEF(&_139$$24);
	ZVAL_UNDEF(&_140$$25);
	ZVAL_UNDEF(&_141$$25);
	ZVAL_UNDEF(&_142$$25);
	ZVAL_UNDEF(&_143$$25);
	ZVAL_UNDEF(&_144$$25);
	ZVAL_UNDEF(&_145$$26);
	ZVAL_UNDEF(&_146$$26);
	ZVAL_UNDEF(&_147$$26);
	ZVAL_UNDEF(&_148$$26);
	ZVAL_UNDEF(&_149$$26);
	ZVAL_UNDEF(&_151$$27);
	ZVAL_UNDEF(&_152$$27);
	ZVAL_UNDEF(&_153$$27);
	ZVAL_UNDEF(&_154$$27);
	ZVAL_UNDEF(&_155$$27);
	ZVAL_UNDEF(&_156$$27);
	ZVAL_UNDEF(&_157$$27);
	ZVAL_UNDEF(&_158$$28);
	ZVAL_UNDEF(&_159$$28);
	ZVAL_UNDEF(&_160$$28);
	ZVAL_UNDEF(&_161$$28);
	ZVAL_UNDEF(&_162$$28);
	ZVAL_UNDEF(&_163$$28);
	ZVAL_UNDEF(&_164$$29);
	ZVAL_UNDEF(&_165$$29);
	ZVAL_UNDEF(&_166$$29);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&space);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_150$$26);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("detailed", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("methods", 7, 1);
	}

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
	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	ZEPHIR_INIT_VAR(&context);
	array_init(&context);
	ZEPHIR_INIT_VAR(&space);
	ZVAL_STRING(&space, "  ");
	if (!(ZEPHIR_IS_EMPTY(&name_zv))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_VS(&_0$$3, &name_zv, " ");
		zephir_concat_self(&output, &_0$$3);
	}
	if (Z_TYPE_P(variable) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "arrayHeader");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_1$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_create_array(&_2$$4, 2, 0);
		ZEPHIR_INIT_NVAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "arr");
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "getstyle", NULL, 0, &_1$$4);
		zephir_check_call_status();
		zephir_array_update_string(&_2$$4, SL("style"), &_3$$4, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_2$$4, SL("count"), zephir_fast_count_int(variable));
		ZEPHIR_CPY_WRT(&context, &_2$$4);
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		zephir_concat_self(&output, &_3$$4);
		if (Z_TYPE_P(variable) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_1$$4);
			zephir_string_to_char_array(&_1$$4, variable);
			_4$$4 = &_1$$4;
		} else {
			_4$$4 = variable;
		}
		zephir_is_iterable(_4$$4, 0, "phalcon/Support/Debug/Dump.zep", 320);
		if (Z_TYPE_P(_4$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_4$$4), _6$$4, _7$$4, _5$$4)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_7$$4 != NULL) { 
					ZVAL_STR_COPY(&key, _7$$4);
				} else {
					ZVAL_LONG(&key, _6$$4);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _5$$4);
				ZVAL_LONG(&_8$$5, tab);
				ZEPHIR_CALL_FUNCTION(&_9$$5, "str_repeat", &_10, 7, &space, &_8$$5);
				zephir_check_call_status();
				zephir_concat_self(&output, &_9$$5);
				ZEPHIR_INIT_NVAR(&_11$$5);
				ZVAL_STRING(&_11$$5, "arrayKey");
				ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_11$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$5);
				zephir_create_array(&_12$$5, 2, 0);
				ZEPHIR_INIT_NVAR(&_11$$5);
				ZVAL_STRING(&_11$$5, "arr");
				ZEPHIR_CALL_METHOD(&_13$$5, this_ptr, "getstyle", NULL, 0, &_11$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_12$$5, SL("style"), &_13$$5, PH_COPY | PH_SEPARATE);
				zephir_cast_to_string(&_14$$5, &key);
				ZVAL_LONG(&_8$$5, 3);
				ZEPHIR_INIT_NVAR(&_11$$5);
				ZVAL_STRING(&_11$$5, "utf-8");
				ZEPHIR_CALL_FUNCTION(&_13$$5, "htmlspecialchars", &_15, 197, &_14$$5, &_8$$5, &_11$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_12$$5, SL("key"), &_13$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&context, &_12$$5);
				ZEPHIR_CALL_METHOD(&_13$$5, this_ptr, "tointerpolate", NULL, 0, &message, &context);
				zephir_check_call_status();
				zephir_concat_self(&output, &_13$$5);
				_16$$5 = 1 == tab;
				if (_16$$5) {
					_16$$5 = !(ZEPHIR_IS_EMPTY(&name_zv));
				}
				_17$$5 = _16$$5;
				if (_17$$5) {
					_17$$5 = Z_TYPE_P(&key) != IS_LONG;
				}
				_18$$5 = _17$$5;
				if (_18$$5) {
					_18$$5 = ZEPHIR_IS_IDENTICAL(&name_zv, &key);
				}
				if (_18$$5) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_11$$5);
				ZVAL_STRING(&_11$$5, "");
				ZVAL_LONG(&_8$$5, (tab + 1));
				ZEPHIR_CALL_METHOD(&_19$$5, this_ptr, "output", &_20, 0, &value, &_11$$5, &_8$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_21$$5);
				ZEPHIR_CONCAT_VS(&_21$$5, &_19$$5, "\n");
				zephir_concat_self(&output, &_21$$5);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _4$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			_23$$4 = 1;
			while (1) {
				if (_23$$4) {
					_23$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _4$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_22$$4, _4$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_22$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, _4$$4, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, _4$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZVAL_LONG(&_24$$7, tab);
					ZEPHIR_CALL_FUNCTION(&_25$$7, "str_repeat", &_10, 7, &space, &_24$$7);
					zephir_check_call_status();
					zephir_concat_self(&output, &_25$$7);
					ZEPHIR_INIT_NVAR(&_26$$7);
					ZVAL_STRING(&_26$$7, "arrayKey");
					ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_26$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_27$$7);
					zephir_create_array(&_27$$7, 2, 0);
					ZEPHIR_INIT_NVAR(&_26$$7);
					ZVAL_STRING(&_26$$7, "arr");
					ZEPHIR_CALL_METHOD(&_28$$7, this_ptr, "getstyle", NULL, 0, &_26$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_27$$7, SL("style"), &_28$$7, PH_COPY | PH_SEPARATE);
					zephir_cast_to_string(&_29$$7, &key);
					ZVAL_LONG(&_24$$7, 3);
					ZEPHIR_INIT_NVAR(&_26$$7);
					ZVAL_STRING(&_26$$7, "utf-8");
					ZEPHIR_CALL_FUNCTION(&_28$$7, "htmlspecialchars", &_15, 197, &_29$$7, &_24$$7, &_26$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_27$$7, SL("key"), &_28$$7, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&context, &_27$$7);
					ZEPHIR_CALL_METHOD(&_28$$7, this_ptr, "tointerpolate", NULL, 0, &message, &context);
					zephir_check_call_status();
					zephir_concat_self(&output, &_28$$7);
					_30$$7 = 1 == tab;
					if (_30$$7) {
						_30$$7 = !(ZEPHIR_IS_EMPTY(&name_zv));
					}
					_31$$7 = _30$$7;
					if (_31$$7) {
						_31$$7 = Z_TYPE_P(&key) != IS_LONG;
					}
					_32$$7 = _31$$7;
					if (_32$$7) {
						_32$$7 = ZEPHIR_IS_IDENTICAL(&name_zv, &key);
					}
					if (_32$$7) {
						continue;
					}
					ZEPHIR_INIT_NVAR(&_26$$7);
					ZVAL_STRING(&_26$$7, "");
					ZVAL_LONG(&_24$$7, (tab + 1));
					ZEPHIR_CALL_METHOD(&_33$$7, this_ptr, "output", &_20, 0, &value, &_26$$7, &_24$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_34$$7);
					ZEPHIR_CONCAT_VS(&_34$$7, &_33$$7, "\n");
					zephir_concat_self(&output, &_34$$7);
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_35$$4, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_36$$4, "str_repeat", &_10, 7, &space, &_35$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_36$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_37$$9);
		ZVAL_STRING(&_37$$9, "objectHeader");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_37$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_38$$9);
		zephir_create_array(&_38$$9, 2, 0);
		ZEPHIR_INIT_NVAR(&_37$$9);
		ZVAL_STRING(&_37$$9, "obj");
		ZEPHIR_CALL_METHOD(&_39$$9, this_ptr, "getstyle", NULL, 0, &_37$$9);
		zephir_check_call_status();
		zephir_array_update_string(&_38$$9, SL("style"), &_39$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_37$$9);
		zephir_get_class(&_37$$9, variable, 0);
		zephir_array_update_string(&_38$$9, SL("class"), &_37$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_38$$9);
		ZEPHIR_CALL_METHOD(&_39$$9, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		zephir_concat_self(&output, &_39$$9);
		ZEPHIR_CALL_FUNCTION(&_40$$9, "get_parent_class", NULL, 0, variable);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_40$$9)) {
			ZEPHIR_INIT_VAR(&_41$$10);
			ZVAL_STRING(&_41$$10, "objectExtends");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_41$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_42$$10);
			zephir_create_array(&_42$$10, 2, 0);
			ZEPHIR_INIT_NVAR(&_41$$10);
			ZVAL_STRING(&_41$$10, "obj");
			ZEPHIR_CALL_METHOD(&_43$$10, this_ptr, "getstyle", NULL, 0, &_41$$10);
			zephir_check_call_status();
			zephir_array_update_string(&_42$$10, SL("style"), &_43$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_43$$10, "get_parent_class", NULL, 0, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_42$$10, SL("parent"), &_43$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&context, &_42$$10);
			ZEPHIR_CALL_METHOD(&_43$$10, this_ptr, "tointerpolate", NULL, 0, &message, &context);
			zephir_check_call_status();
			zephir_concat_self(&output, &_43$$10);
		}
		zephir_concat_self_str(&output, SL(" (\n"));
		_44$$9 = Z_TYPE_P(variable) == IS_OBJECT;
		if (_44$$9) {
			_45$$9 = zephir_instance_of_ev(variable, phalcon_di_diinterface_ce);
			if (!(_45$$9)) {
				_45$$9 = zephir_instance_of_ev(variable, phalcon_container_container_ce);
			}
			_44$$9 = _45$$9;
		}
		if (_44$$9) {
			ZVAL_LONG(&_48$$11, tab);
			ZEPHIR_CALL_FUNCTION(&_49$$11, "str_repeat", &_10, 7, &space, &_48$$11);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_50$$11);
			ZEPHIR_CONCAT_VS(&_50$$11, &_49$$11, "[skipped]\n");
			zephir_concat_self(&output, &_50$$11);
		} else {
			zephir_read_property_cached(&_46$$9, this_ptr, _zephir_prop_0, 1356, PH_NOISY_CC | PH_READONLY);
			_47$$9 = !ZEPHIR_IS_TRUE_IDENTICAL(&_46$$9);
			if (!(_47$$9)) {
				_47$$9 = zephir_is_instance_of(variable, SL("stdClass"));
			}
			if (_47$$9) {
				ZEPHIR_CALL_FUNCTION(&vars, "get_object_vars", NULL, 357, variable);
				zephir_check_call_status();
				if (Z_TYPE_P(&vars) == IS_STRING) {
					ZEPHIR_INIT_VAR(&_52$$12);
					zephir_string_to_char_array(&_52$$12, &vars);
					_51$$12 = &_52$$12;
				} else {
					_51$$12 = &vars;
				}
				zephir_is_iterable(_51$$12, 0, "phalcon/Support/Debug/Dump.zep", 364);
				if (Z_TYPE_P(_51$$12) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_51$$12), _54$$12, _55$$12, _53$$12)
					{
						ZEPHIR_INIT_NVAR(&key);
						if (_55$$12 != NULL) { 
							ZVAL_STR_COPY(&key, _55$$12);
						} else {
							ZVAL_LONG(&key, _54$$12);
						}
						ZEPHIR_INIT_NVAR(&value);
						ZVAL_COPY(&value, _53$$12);
						ZEPHIR_INIT_NVAR(&_56$$13);
						ZVAL_STRING(&_56$$13, "objectProperty");
						ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_56$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_57$$13);
						zephir_create_array(&_57$$13, 3, 0);
						ZEPHIR_INIT_NVAR(&_56$$13);
						ZVAL_STRING(&_56$$13, "obj");
						ZEPHIR_CALL_METHOD(&_58$$13, this_ptr, "getstyle", NULL, 0, &_56$$13);
						zephir_check_call_status();
						zephir_array_update_string(&_57$$13, SL("style"), &_58$$13, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_57$$13, SL("key"), &key, PH_COPY | PH_SEPARATE);
						add_assoc_stringl_ex(&_57$$13, SL("type"), SL("public"));
						ZEPHIR_CPY_WRT(&context, &_57$$13);
						ZVAL_LONG(&_59$$13, tab);
						ZEPHIR_CALL_FUNCTION(&_58$$13, "str_repeat", &_10, 7, &space, &_59$$13);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_60$$13, this_ptr, "tointerpolate", NULL, 0, &message, &context);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_56$$13);
						ZVAL_STRING(&_56$$13, "");
						ZVAL_LONG(&_59$$13, (tab + 1));
						ZEPHIR_CALL_METHOD(&_61$$13, this_ptr, "output", &_20, 0, &value, &_56$$13, &_59$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_62$$13);
						ZEPHIR_CONCAT_VVVS(&_62$$13, &_58$$13, &_60$$13, &_61$$13, "\n");
						zephir_concat_self(&output, &_62$$13);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _51$$12, "rewind", NULL, 0);
					zephir_check_call_status();
					_64$$12 = 1;
					while (1) {
						if (_64$$12) {
							_64$$12 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _51$$12, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_63$$12, _51$$12, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_63$$12)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&key, _51$$12, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&value, _51$$12, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_65$$14);
							ZVAL_STRING(&_65$$14, "objectProperty");
							ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_65$$14);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_66$$14);
							zephir_create_array(&_66$$14, 3, 0);
							ZEPHIR_INIT_NVAR(&_65$$14);
							ZVAL_STRING(&_65$$14, "obj");
							ZEPHIR_CALL_METHOD(&_67$$14, this_ptr, "getstyle", NULL, 0, &_65$$14);
							zephir_check_call_status();
							zephir_array_update_string(&_66$$14, SL("style"), &_67$$14, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_66$$14, SL("key"), &key, PH_COPY | PH_SEPARATE);
							add_assoc_stringl_ex(&_66$$14, SL("type"), SL("public"));
							ZEPHIR_CPY_WRT(&context, &_66$$14);
							ZVAL_LONG(&_68$$14, tab);
							ZEPHIR_CALL_FUNCTION(&_67$$14, "str_repeat", &_10, 7, &space, &_68$$14);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_69$$14, this_ptr, "tointerpolate", NULL, 0, &message, &context);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_65$$14);
							ZVAL_STRING(&_65$$14, "");
							ZVAL_LONG(&_68$$14, (tab + 1));
							ZEPHIR_CALL_METHOD(&_70$$14, this_ptr, "output", &_20, 0, &value, &_65$$14, &_68$$14);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_71$$14);
							ZEPHIR_CONCAT_VVVS(&_71$$14, &_67$$14, &_69$$14, &_70$$14, "\n");
							zephir_concat_self(&output, &_71$$14);
					}
				}
				ZEPHIR_INIT_NVAR(&value);
				ZEPHIR_INIT_NVAR(&key);
			} else {
				ZEPHIR_INIT_VAR(&reflect);
				object_init_ex(&reflect, zephir_get_internal_ce(SL("reflectionclass")));
				ZEPHIR_CALL_METHOD(NULL, &reflect, "__construct", NULL, 249, variable);
				zephir_check_call_status();
				ZVAL_LONG(&_72$$15, ((1 | 2) | 4));
				ZEPHIR_CALL_METHOD(&props, &reflect, "getproperties", NULL, 370, &_72$$15);
				zephir_check_call_status();
				if (Z_TYPE_P(&props) == IS_STRING) {
					ZEPHIR_INIT_VAR(&_74$$15);
					zephir_string_to_char_array(&_74$$15, &props);
					_73$$15 = &_74$$15;
				} else {
					_73$$15 = &props;
				}
				zephir_is_iterable(_73$$15, 0, "phalcon/Support/Debug/Dump.zep", 392);
				if (Z_TYPE_P(_73$$15) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_73$$15), _75$$15)
					{
						ZEPHIR_INIT_NVAR(&property);
						ZVAL_COPY(&property, _75$$15);
						ZEPHIR_CALL_METHOD(&key, &property, "getname", NULL, 0);
						zephir_check_call_status();
						_77$$16 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
						ZEPHIR_CALL_METHOD(&_79$$16, &property, "getmodifiers", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_CE_STATIC(&_76$$16, _77$$16, "getmodifiernames", &_78, 0, &_79$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&type);
						zephir_fast_join_str(&type, SL(" "), &_76$$16);
						ZEPHIR_INIT_NVAR(&_80$$16);
						ZVAL_STRING(&_80$$16, "objectProperty");
						ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_80$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_81$$16);
						zephir_create_array(&_81$$16, 3, 0);
						ZEPHIR_INIT_NVAR(&_80$$16);
						ZVAL_STRING(&_80$$16, "obj");
						ZEPHIR_CALL_METHOD(&_82$$16, this_ptr, "getstyle", NULL, 0, &_80$$16);
						zephir_check_call_status();
						zephir_array_update_string(&_81$$16, SL("style"), &_82$$16, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_81$$16, SL("key"), &key, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_81$$16, SL("type"), &type, PH_COPY | PH_SEPARATE);
						ZEPHIR_CPY_WRT(&context, &_81$$16);
						ZVAL_LONG(&_83$$16, tab);
						ZEPHIR_CALL_FUNCTION(&_82$$16, "str_repeat", &_10, 7, &space, &_83$$16);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_84$$16, this_ptr, "tointerpolate", NULL, 0, &message, &context);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_86$$16, &property, "getvalue", NULL, 0, variable);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_80$$16);
						ZVAL_STRING(&_80$$16, "");
						ZVAL_LONG(&_83$$16, (tab + 1));
						ZEPHIR_CALL_METHOD(&_85$$16, this_ptr, "output", &_20, 0, &_86$$16, &_80$$16, &_83$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_87$$16);
						ZEPHIR_CONCAT_VVVS(&_87$$16, &_82$$16, &_84$$16, &_85$$16, "\n");
						zephir_concat_self(&output, &_87$$16);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _73$$15, "rewind", NULL, 0);
					zephir_check_call_status();
					_89$$15 = 1;
					while (1) {
						if (_89$$15) {
							_89$$15 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _73$$15, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_88$$15, _73$$15, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_88$$15)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&property, _73$$15, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&key, &property, "getname", NULL, 0);
							zephir_check_call_status();
							_91$$17 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
							ZEPHIR_CALL_METHOD(&_92$$17, &property, "getmodifiers", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_CE_STATIC(&_90$$17, _91$$17, "getmodifiernames", &_78, 0, &_92$$17);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&type);
							zephir_fast_join_str(&type, SL(" "), &_90$$17);
							ZEPHIR_INIT_NVAR(&_93$$17);
							ZVAL_STRING(&_93$$17, "objectProperty");
							ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_93$$17);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_94$$17);
							zephir_create_array(&_94$$17, 3, 0);
							ZEPHIR_INIT_NVAR(&_93$$17);
							ZVAL_STRING(&_93$$17, "obj");
							ZEPHIR_CALL_METHOD(&_95$$17, this_ptr, "getstyle", NULL, 0, &_93$$17);
							zephir_check_call_status();
							zephir_array_update_string(&_94$$17, SL("style"), &_95$$17, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_94$$17, SL("key"), &key, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_94$$17, SL("type"), &type, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&context, &_94$$17);
							ZVAL_LONG(&_96$$17, tab);
							ZEPHIR_CALL_FUNCTION(&_95$$17, "str_repeat", &_10, 7, &space, &_96$$17);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_97$$17, this_ptr, "tointerpolate", NULL, 0, &message, &context);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_99$$17, &property, "getvalue", NULL, 0, variable);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_93$$17);
							ZVAL_STRING(&_93$$17, "");
							ZVAL_LONG(&_96$$17, (tab + 1));
							ZEPHIR_CALL_METHOD(&_98$$17, this_ptr, "output", &_20, 0, &_99$$17, &_93$$17, &_96$$17);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_100$$17);
							ZEPHIR_CONCAT_VVVS(&_100$$17, &_95$$17, &_97$$17, &_98$$17, "\n");
							zephir_concat_self(&output, &_100$$17);
					}
				}
				ZEPHIR_INIT_NVAR(&property);
			}
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 0, variable);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_37$$9);
		ZVAL_STRING(&_37$$9, "objectMethods");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_37$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_101$$9);
		zephir_create_array(&_101$$9, 3, 0);
		ZEPHIR_INIT_NVAR(&_37$$9);
		ZVAL_STRING(&_37$$9, "obj");
		ZEPHIR_CALL_METHOD(&_102$$9, this_ptr, "getstyle", NULL, 0, &_37$$9);
		zephir_check_call_status();
		zephir_array_update_string(&_101$$9, SL("style"), &_102$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_37$$9);
		zephir_get_class(&_37$$9, variable, 0);
		zephir_array_update_string(&_101$$9, SL("class"), &_37$$9, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_101$$9, SL("count"), zephir_fast_count_int(&attr));
		ZEPHIR_CPY_WRT(&context, &_101$$9);
		ZVAL_LONG(&_103$$9, tab);
		ZEPHIR_CALL_FUNCTION(&_102$$9, "str_repeat", &_10, 7, &space, &_103$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_104$$9, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_105$$9);
		ZEPHIR_CONCAT_VV(&_105$$9, &_102$$9, &_104$$9);
		zephir_concat_self(&output, &_105$$9);
		ZEPHIR_INIT_NVAR(&_37$$9);
		zephir_get_class(&_37$$9, variable, 0);
		zephir_read_property_cached(&_103$$9, this_ptr, _zephir_prop_1, 1358, PH_NOISY_CC | PH_READONLY);
		if (1 == zephir_fast_in_array(&_37$$9, &_103$$9)) {
			ZVAL_LONG(&_106$$18, tab);
			ZEPHIR_CALL_FUNCTION(&_107$$18, "str_repeat", &_10, 7, &space, &_106$$18);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_108$$18);
			ZEPHIR_CONCAT_VS(&_108$$18, &_107$$18, "[already listed]\n");
			zephir_concat_self(&output, &_108$$18);
		} else {
			if (Z_TYPE_P(&attr) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_110$$19);
				zephir_string_to_char_array(&_110$$19, &attr);
				_109$$19 = &_110$$19;
			} else {
				_109$$19 = &attr;
			}
			zephir_is_iterable(_109$$19, 0, "phalcon/Support/Debug/Dump.zep", 425);
			if (Z_TYPE_P(_109$$19) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_109$$19), _111$$19)
				{
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _111$$19);
					ZEPHIR_INIT_NVAR(&_112$$20);
					zephir_get_class(&_112$$20, variable, 0);
					zephir_update_property_array_append(this_ptr, SL("methods"), &_112$$20);
					ZEPHIR_INIT_NVAR(&_112$$20);
					ZVAL_STRING(&_112$$20, "objectMethod");
					ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_112$$20);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_113$$20);
					ZVAL_STRING(&_113$$20, "__construct");
					if (ZEPHIR_IS_IDENTICAL(&_113$$20, &value)) {
						ZEPHIR_INIT_NVAR(&_114$$21);
						ZVAL_STRING(&_114$$21, "objectMethodConstructor");
						ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_114$$21);
						zephir_check_call_status();
					}
					ZEPHIR_INIT_NVAR(&_115$$20);
					zephir_create_array(&_115$$20, 2, 0);
					ZEPHIR_INIT_NVAR(&_112$$20);
					ZVAL_STRING(&_112$$20, "obj");
					ZEPHIR_CALL_METHOD(&_116$$20, this_ptr, "getstyle", NULL, 0, &_112$$20);
					zephir_check_call_status();
					zephir_array_update_string(&_115$$20, SL("style"), &_116$$20, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_115$$20, SL("method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&context, &_115$$20);
					ZVAL_LONG(&_117$$20, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_116$$20, "str_repeat", &_10, 7, &space, &_117$$20);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_118$$20, this_ptr, "tointerpolate", NULL, 0, &message, &context);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_119$$20);
					ZEPHIR_CONCAT_VV(&_119$$20, &_116$$20, &_118$$20);
					zephir_concat_self(&output, &_119$$20);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _109$$19, "rewind", NULL, 0);
				zephir_check_call_status();
				_121$$19 = 1;
				while (1) {
					if (_121$$19) {
						_121$$19 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _109$$19, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_120$$19, _109$$19, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_120$$19)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&value, _109$$19, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_122$$22);
						zephir_get_class(&_122$$22, variable, 0);
						zephir_update_property_array_append(this_ptr, SL("methods"), &_122$$22);
						ZEPHIR_INIT_NVAR(&_122$$22);
						ZVAL_STRING(&_122$$22, "objectMethod");
						ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_122$$22);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_123$$22);
						ZVAL_STRING(&_123$$22, "__construct");
						if (ZEPHIR_IS_IDENTICAL(&_123$$22, &value)) {
							ZEPHIR_INIT_NVAR(&_124$$23);
							ZVAL_STRING(&_124$$23, "objectMethodConstructor");
							ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_124$$23);
							zephir_check_call_status();
						}
						ZEPHIR_INIT_NVAR(&_125$$22);
						zephir_create_array(&_125$$22, 2, 0);
						ZEPHIR_INIT_NVAR(&_122$$22);
						ZVAL_STRING(&_122$$22, "obj");
						ZEPHIR_CALL_METHOD(&_126$$22, this_ptr, "getstyle", NULL, 0, &_122$$22);
						zephir_check_call_status();
						zephir_array_update_string(&_125$$22, SL("style"), &_126$$22, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_125$$22, SL("method"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_CPY_WRT(&context, &_125$$22);
						ZVAL_LONG(&_127$$22, (tab + 1));
						ZEPHIR_CALL_FUNCTION(&_126$$22, "str_repeat", &_10, 7, &space, &_127$$22);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_128$$22, this_ptr, "tointerpolate", NULL, 0, &message, &context);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_129$$22);
						ZEPHIR_CONCAT_VV(&_129$$22, &_126$$22, &_128$$22);
						zephir_concat_self(&output, &_129$$22);
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_LONG(&_130$$19, tab);
			ZEPHIR_CALL_FUNCTION(&_131$$19, "str_repeat", &_10, 7, &space, &_130$$19);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_132$$19);
			ZEPHIR_CONCAT_VS(&_132$$19, &_131$$19, ")\n");
			zephir_concat_self(&output, &_132$$19);
		}
		ZVAL_LONG(&_133$$9, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_134$$9, "str_repeat", &_10, 7, &space, &_133$$9);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_134$$9, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_136$$24);
		ZVAL_STRING(&_136$$24, "Integer");
		ZEPHIR_CALL_METHOD(&_135$$24, this_ptr, "getoutputbold", NULL, 0, &_136$$24);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_136$$24);
		ZVAL_STRING(&_136$$24, "varParens");
		ZEPHIR_CALL_METHOD(&_137$$24, this_ptr, "gettemplate", NULL, 0, &_136$$24);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_135$$24, " ", &_137$$24);
		ZEPHIR_INIT_VAR(&_138$$24);
		zephir_create_array(&_138$$24, 2, 0);
		ZEPHIR_INIT_NVAR(&_136$$24);
		ZVAL_STRING(&_136$$24, "int");
		ZEPHIR_CALL_METHOD(&_139$$24, this_ptr, "getstyle", NULL, 0, &_136$$24);
		zephir_check_call_status();
		zephir_array_update_string(&_138$$24, SL("style"), &_139$$24, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_138$$24, SL("var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_138$$24);
		ZEPHIR_CALL_METHOD(&_139$$24, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_139$$24);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_DOUBLE) {
		ZEPHIR_INIT_VAR(&_141$$25);
		ZVAL_STRING(&_141$$25, "Float");
		ZEPHIR_CALL_METHOD(&_140$$25, this_ptr, "getoutputbold", NULL, 0, &_141$$25);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_141$$25);
		ZVAL_STRING(&_141$$25, "varParens");
		ZEPHIR_CALL_METHOD(&_142$$25, this_ptr, "gettemplate", NULL, 0, &_141$$25);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_140$$25, " ", &_142$$25);
		ZEPHIR_INIT_VAR(&_143$$25);
		zephir_create_array(&_143$$25, 2, 0);
		ZEPHIR_INIT_NVAR(&_141$$25);
		ZVAL_STRING(&_141$$25, "float");
		ZEPHIR_CALL_METHOD(&_144$$25, this_ptr, "getstyle", NULL, 0, &_141$$25);
		zephir_check_call_status();
		zephir_array_update_string(&_143$$25, SL("style"), &_144$$25, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_143$$25, SL("var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_143$$25);
		ZEPHIR_CALL_METHOD(&_144$$25, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_144$$25);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_146$$26);
		ZVAL_STRING(&_146$$26, "Numeric String");
		ZEPHIR_CALL_METHOD(&_145$$26, this_ptr, "getoutputbold", NULL, 0, &_146$$26);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_146$$26);
		ZVAL_STRING(&_146$$26, "lengthValue");
		ZEPHIR_CALL_METHOD(&_147$$26, this_ptr, "gettemplate", NULL, 0, &_146$$26);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_145$$26, " ", &_147$$26);
		ZEPHIR_INIT_VAR(&_148$$26);
		zephir_create_array(&_148$$26, 3, 0);
		ZEPHIR_INIT_NVAR(&_146$$26);
		ZVAL_STRING(&_146$$26, "num");
		ZEPHIR_CALL_METHOD(&_149$$26, this_ptr, "getstyle", NULL, 0, &_146$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_148$$26, SL("style"), &_149$$26, PH_COPY | PH_SEPARATE);
		zephir_cast_to_string(&_150$$26, variable);
		ZEPHIR_CALL_FUNCTION(&_149$$26, "mb_strlen", NULL, 0, &_150$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_148$$26, SL("length"), &_149$$26, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_148$$26, SL("var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_148$$26);
		ZEPHIR_CALL_METHOD(&_149$$26, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_149$$26);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_152$$27);
		ZVAL_STRING(&_152$$27, "String");
		ZEPHIR_CALL_METHOD(&_151$$27, this_ptr, "getoutputbold", NULL, 0, &_152$$27);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_152$$27);
		ZVAL_STRING(&_152$$27, "lengthValue");
		ZEPHIR_CALL_METHOD(&_153$$27, this_ptr, "gettemplate", NULL, 0, &_152$$27);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_151$$27, " ", &_153$$27);
		ZEPHIR_INIT_VAR(&_154$$27);
		zephir_create_array(&_154$$27, 3, 0);
		ZEPHIR_INIT_NVAR(&_152$$27);
		ZVAL_STRING(&_152$$27, "str");
		ZEPHIR_CALL_METHOD(&_155$$27, this_ptr, "getstyle", NULL, 0, &_152$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_154$$27, SL("style"), &_155$$27, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_155$$27, "mb_strlen", NULL, 0, variable);
		zephir_check_call_status();
		zephir_array_update_string(&_154$$27, SL("length"), &_155$$27, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_156$$27, 4);
		ZEPHIR_INIT_NVAR(&_152$$27);
		ZVAL_STRING(&_152$$27, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_155$$27, "htmlentities", NULL, 0, variable, &_156$$27, &_152$$27);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_157$$27, "nl2br", NULL, 0, &_155$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_154$$27, SL("var"), &_157$$27, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_154$$27);
		ZEPHIR_CALL_METHOD(&_157$$27, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_157$$27);
		RETURN_MM();
	}
	if (((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE) == 1)) {
		ZEPHIR_INIT_VAR(&_159$$28);
		ZVAL_STRING(&_159$$28, "Boolean");
		ZEPHIR_CALL_METHOD(&_158$$28, this_ptr, "getoutputbold", NULL, 0, &_159$$28);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_159$$28);
		ZVAL_STRING(&_159$$28, "varParens");
		ZEPHIR_CALL_METHOD(&_160$$28, this_ptr, "gettemplate", NULL, 0, &_159$$28);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_158$$28, " ", &_160$$28);
		ZEPHIR_INIT_VAR(&_161$$28);
		zephir_create_array(&_161$$28, 2, 0);
		ZEPHIR_INIT_NVAR(&_159$$28);
		ZVAL_STRING(&_159$$28, "bool");
		ZEPHIR_CALL_METHOD(&_162$$28, this_ptr, "getstyle", NULL, 0, &_159$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_161$$28, SL("style"), &_162$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_163$$28);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_163$$28);
			ZVAL_STRING(&_163$$28, "TRUE");
		} else {
			ZEPHIR_INIT_NVAR(&_163$$28);
			ZVAL_STRING(&_163$$28, "FALSE");
		}
		zephir_array_update_string(&_161$$28, SL("var"), &_163$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_161$$28);
		ZEPHIR_CALL_METHOD(&_162$$28, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_162$$28);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_164$$29);
		ZVAL_STRING(&_164$$29, "NULL");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoutputbold", NULL, 0, &_164$$29);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_165$$29);
		zephir_create_array(&_165$$29, 1, 0);
		ZEPHIR_INIT_NVAR(&_164$$29);
		ZVAL_STRING(&_164$$29, "null");
		ZEPHIR_CALL_METHOD(&_166$$29, this_ptr, "getstyle", NULL, 0, &_164$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_165$$29, SL("style"), &_166$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_165$$29);
		ZEPHIR_CALL_METHOD(&_166$$29, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_166$$29);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_167);
	ZVAL_STRING(&_167, "varParens");
	ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_167);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_168);
	zephir_create_array(&_168, 2, 0);
	ZEPHIR_INIT_NVAR(&_167);
	ZVAL_STRING(&_167, "other");
	ZEPHIR_CALL_METHOD(&_169, this_ptr, "getstyle", NULL, 0, &_167);
	zephir_check_call_status();
	zephir_array_update_string(&_168, SL("style"), &_169, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_168, SL("var"), variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_CPY_WRT(&context, &_168);
	ZEPHIR_CALL_METHOD(&_169, this_ptr, "tointerpolate", NULL, 0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_169);
	RETURN_MM();
}

/**
 * @param string $text
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Dump, getOutputBold)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval text_zv, _0, _1;
	zend_string *text = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "bold");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0);
	zephir_array_update_string(&_2, SL("text"), &text_zv, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "tointerpolate", NULL, 0, &_0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string   $input
 * @param string[] $context
 * @param string   $left
 * @param string   $right
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Dump, toInterpolate)
{
	zend_bool _6;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context, replace;
	zval input_zv, *context_param = NULL, left_zv, right_zv, key, value, _0, *_1, _5, _4$$5, _7$$6;
	zend_string *input = NULL, *left = NULL, *right = NULL, *_3;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&left_zv);
	ZVAL_UNDEF(&right_zv);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&replace);
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(context, context_param)
		Z_PARAM_STR(left)
		Z_PARAM_STR(right)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		context_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}
	if (!left) {
		left = zend_string_init(ZEND_STRL("%"), 0);
		zephir_memory_observe(&left_zv);
		ZVAL_STR(&left_zv, left);
	} else {
		zephir_memory_observe(&left_zv);
	ZVAL_STR_COPY(&left_zv, left);
	}
	if (!right) {
		right = zend_string_init(ZEND_STRL("%"), 0);
		zephir_memory_observe(&right_zv);
		ZVAL_STR(&right_zv, right);
	} else {
		zephir_memory_observe(&right_zv);
	ZVAL_STR_COPY(&right_zv, right);
	}
	ZEPHIR_INIT_VAR(&replace);
	array_init(&replace);
	if (ZEPHIR_IS_EMPTY(&context)) {
		RETURN_MM_STR(zend_string_copy(input));
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strpos(&_0, &input_zv, &left_zv, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		RETURN_MM_STR(zend_string_copy(input));
	}
	zephir_is_iterable(&context, 0, "phalcon/Traits/Support/Helper/Str/InterpolateTrait.zep", 49);
	if (Z_TYPE_P(&context) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&context), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_INIT_NVAR(&_4$$5);
			ZEPHIR_CONCAT_VVV(&_4$$5, &left_zv, &key, &right_zv);
			zephir_array_update_zval(&replace, &_4$$5, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &context, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &context, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &context, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &context, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &context, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_7$$6);
				ZEPHIR_CONCAT_VVV(&_7$$6, &left_zv, &key, &right_zv);
				zephir_array_update_zval(&replace, &_7$$6, &value, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 4, &input_zv, &replace);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Dump, getTemplate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0, _1, _2;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("templates", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 1359, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value(&_1, &name_zv)) {
		zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 1359, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_0);
		zephir_array_fetch(&_0, &_2, &name_zv, PH_NOISY, "phalcon/Support/Debug/Traits/TemplateAwareTrait.zep", 31);
	} else {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "defaulttemplate", NULL, 0, &name_zv);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_0);
}

/**
 * @param string $name
 * @param string $template
 *
 * @return static
 */
PHP_METHOD(Phalcon_Support_Debug_Dump, setTemplate)
{
	zval name_zv, template_zv;
	zend_string *name = NULL, *template = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&template_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_STR(template)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	ZVAL_STR(&template_zv, template);
	zephir_update_property_array(this_ptr, SL("templates"), &name_zv, &template_zv);
	RETURN_THISW();
}

