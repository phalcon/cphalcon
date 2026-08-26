
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

	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1352, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstyles", NULL, 0, &styles);
	zephir_check_call_status();
	if (detailed) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1353, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1353, &__$false);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1353, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1353, &__$false);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1354, &_1);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1352, PH_NOISY_CC | PH_READONLY);
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
	zephir_is_iterable(&_0, 0, "phalcon/Support/Debug/Dump.zep", 220);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1354, PH_NOISY_CC | PH_READONLY);
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
	zend_class_entry *_72$$16, *_86$$17;
	zend_bool _22$$4, _15$$5, _16$$5, _17$$5, _29$$7, _30$$7, _31$$7, _43$$9, _44$$9, _46$$9, _61$$12, _84$$15, _114$$19;
	zend_ulong _5$$4, _51$$12;
	zval space, _0$$3, _13$$5, _28$$7, _143$$26;
	zval context;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_14 = NULL, *_19 = NULL, *_73 = NULL;
	zend_long tab, ZEPHIR_LAST_CALL_STATUS;
	zend_string *name = NULL, *_6$$4, *_52$$12;
	zval *variable, variable_sub, name_zv, *tab_param = NULL, attr, key, message, output, property, props, reflect, type, value, vars, _160, _161, _162, _1$$4, _2$$4, _3$$4, *_4$$4, _21$$4, _34$$4, _35$$4, _7$$5, _8$$5, _10$$5, _11$$5, _12$$5, _18$$5, _20$$5, _23$$7, _24$$7, _25$$7, _26$$7, _27$$7, _32$$7, _33$$7, _36$$9, _37$$9, _38$$9, _39$$9, _45$$9, _96$$9, _97$$9, _98$$9, _99$$9, _100$$9, _126$$9, _127$$9, _40$$10, _41$$10, _42$$10, _47$$11, _48$$11, _49$$11, *_50$$12, _60$$12, _53$$13, _54$$13, _55$$13, _56$$13, _57$$13, _58$$13, _59$$13, _62$$14, _63$$14, _64$$14, _65$$14, _66$$14, _67$$14, _68$$14, _69$$15, *_70$$15, _83$$15, _71$$16, _74$$16, _75$$16, _76$$16, _77$$16, _78$$16, _79$$16, _80$$16, _81$$16, _82$$16, _85$$17, _87$$17, _88$$17, _89$$17, _90$$17, _91$$17, _92$$17, _93$$17, _94$$17, _95$$17, _101$$18, _102$$18, _103$$18, *_104$$19, _113$$19, _123$$19, _124$$19, _125$$19, _105$$20, _106$$20, _108$$20, _109$$20, _110$$20, _111$$20, _112$$20, _107$$21, _115$$22, _116$$22, _118$$22, _119$$22, _120$$22, _121$$22, _122$$22, _117$$23, _128$$24, _129$$24, _130$$24, _131$$24, _132$$24, _133$$25, _134$$25, _135$$25, _136$$25, _137$$25, _138$$26, _139$$26, _140$$26, _141$$26, _142$$26, _144$$27, _145$$27, _146$$27, _147$$27, _148$$27, _149$$27, _150$$27, _151$$28, _152$$28, _153$$28, _154$$28, _155$$28, _156$$28, _157$$29, _158$$29, _159$$29;
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
	ZVAL_UNDEF(&_160);
	ZVAL_UNDEF(&_161);
	ZVAL_UNDEF(&_162);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_34$$4);
	ZVAL_UNDEF(&_35$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_32$$7);
	ZVAL_UNDEF(&_33$$7);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_37$$9);
	ZVAL_UNDEF(&_38$$9);
	ZVAL_UNDEF(&_39$$9);
	ZVAL_UNDEF(&_45$$9);
	ZVAL_UNDEF(&_96$$9);
	ZVAL_UNDEF(&_97$$9);
	ZVAL_UNDEF(&_98$$9);
	ZVAL_UNDEF(&_99$$9);
	ZVAL_UNDEF(&_100$$9);
	ZVAL_UNDEF(&_126$$9);
	ZVAL_UNDEF(&_127$$9);
	ZVAL_UNDEF(&_40$$10);
	ZVAL_UNDEF(&_41$$10);
	ZVAL_UNDEF(&_42$$10);
	ZVAL_UNDEF(&_47$$11);
	ZVAL_UNDEF(&_48$$11);
	ZVAL_UNDEF(&_49$$11);
	ZVAL_UNDEF(&_60$$12);
	ZVAL_UNDEF(&_53$$13);
	ZVAL_UNDEF(&_54$$13);
	ZVAL_UNDEF(&_55$$13);
	ZVAL_UNDEF(&_56$$13);
	ZVAL_UNDEF(&_57$$13);
	ZVAL_UNDEF(&_58$$13);
	ZVAL_UNDEF(&_59$$13);
	ZVAL_UNDEF(&_62$$14);
	ZVAL_UNDEF(&_63$$14);
	ZVAL_UNDEF(&_64$$14);
	ZVAL_UNDEF(&_65$$14);
	ZVAL_UNDEF(&_66$$14);
	ZVAL_UNDEF(&_67$$14);
	ZVAL_UNDEF(&_68$$14);
	ZVAL_UNDEF(&_69$$15);
	ZVAL_UNDEF(&_83$$15);
	ZVAL_UNDEF(&_71$$16);
	ZVAL_UNDEF(&_74$$16);
	ZVAL_UNDEF(&_75$$16);
	ZVAL_UNDEF(&_76$$16);
	ZVAL_UNDEF(&_77$$16);
	ZVAL_UNDEF(&_78$$16);
	ZVAL_UNDEF(&_79$$16);
	ZVAL_UNDEF(&_80$$16);
	ZVAL_UNDEF(&_81$$16);
	ZVAL_UNDEF(&_82$$16);
	ZVAL_UNDEF(&_85$$17);
	ZVAL_UNDEF(&_87$$17);
	ZVAL_UNDEF(&_88$$17);
	ZVAL_UNDEF(&_89$$17);
	ZVAL_UNDEF(&_90$$17);
	ZVAL_UNDEF(&_91$$17);
	ZVAL_UNDEF(&_92$$17);
	ZVAL_UNDEF(&_93$$17);
	ZVAL_UNDEF(&_94$$17);
	ZVAL_UNDEF(&_95$$17);
	ZVAL_UNDEF(&_101$$18);
	ZVAL_UNDEF(&_102$$18);
	ZVAL_UNDEF(&_103$$18);
	ZVAL_UNDEF(&_113$$19);
	ZVAL_UNDEF(&_123$$19);
	ZVAL_UNDEF(&_124$$19);
	ZVAL_UNDEF(&_125$$19);
	ZVAL_UNDEF(&_105$$20);
	ZVAL_UNDEF(&_106$$20);
	ZVAL_UNDEF(&_108$$20);
	ZVAL_UNDEF(&_109$$20);
	ZVAL_UNDEF(&_110$$20);
	ZVAL_UNDEF(&_111$$20);
	ZVAL_UNDEF(&_112$$20);
	ZVAL_UNDEF(&_107$$21);
	ZVAL_UNDEF(&_115$$22);
	ZVAL_UNDEF(&_116$$22);
	ZVAL_UNDEF(&_118$$22);
	ZVAL_UNDEF(&_119$$22);
	ZVAL_UNDEF(&_120$$22);
	ZVAL_UNDEF(&_121$$22);
	ZVAL_UNDEF(&_122$$22);
	ZVAL_UNDEF(&_117$$23);
	ZVAL_UNDEF(&_128$$24);
	ZVAL_UNDEF(&_129$$24);
	ZVAL_UNDEF(&_130$$24);
	ZVAL_UNDEF(&_131$$24);
	ZVAL_UNDEF(&_132$$24);
	ZVAL_UNDEF(&_133$$25);
	ZVAL_UNDEF(&_134$$25);
	ZVAL_UNDEF(&_135$$25);
	ZVAL_UNDEF(&_136$$25);
	ZVAL_UNDEF(&_137$$25);
	ZVAL_UNDEF(&_138$$26);
	ZVAL_UNDEF(&_139$$26);
	ZVAL_UNDEF(&_140$$26);
	ZVAL_UNDEF(&_141$$26);
	ZVAL_UNDEF(&_142$$26);
	ZVAL_UNDEF(&_144$$27);
	ZVAL_UNDEF(&_145$$27);
	ZVAL_UNDEF(&_146$$27);
	ZVAL_UNDEF(&_147$$27);
	ZVAL_UNDEF(&_148$$27);
	ZVAL_UNDEF(&_149$$27);
	ZVAL_UNDEF(&_150$$27);
	ZVAL_UNDEF(&_151$$28);
	ZVAL_UNDEF(&_152$$28);
	ZVAL_UNDEF(&_153$$28);
	ZVAL_UNDEF(&_154$$28);
	ZVAL_UNDEF(&_155$$28);
	ZVAL_UNDEF(&_156$$28);
	ZVAL_UNDEF(&_157$$29);
	ZVAL_UNDEF(&_158$$29);
	ZVAL_UNDEF(&_159$$29);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&space);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_143$$26);
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
		zephir_is_iterable(variable, 0, "phalcon/Support/Debug/Dump.zep", 320);
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
				ZEPHIR_CALL_FUNCTION(&_8$$5, "str_repeat", &_9, 7, &space, &_7$$5);
				zephir_check_call_status();
				zephir_concat_self(&output, &_8$$5);
				ZEPHIR_INIT_NVAR(&_10$$5);
				ZVAL_STRING(&_10$$5, "arrayKey");
				ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_10$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_11$$5);
				zephir_create_array(&_11$$5, 2, 0);
				ZEPHIR_INIT_NVAR(&_10$$5);
				ZVAL_STRING(&_10$$5, "arr");
				ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "getstyle", NULL, 0, &_10$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_11$$5, SL("style"), &_12$$5, PH_COPY | PH_SEPARATE);
				zephir_cast_to_string(&_13$$5, &key);
				ZVAL_LONG(&_7$$5, 3);
				ZEPHIR_INIT_NVAR(&_10$$5);
				ZVAL_STRING(&_10$$5, "utf-8");
				ZEPHIR_CALL_FUNCTION(&_12$$5, "htmlspecialchars", &_14, 197, &_13$$5, &_7$$5, &_10$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_11$$5, SL("key"), &_12$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&context, &_11$$5);
				ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "tointerpolate", NULL, 0, &message, &context);
				zephir_check_call_status();
				zephir_concat_self(&output, &_12$$5);
				_15$$5 = 1 == tab;
				if (_15$$5) {
					_15$$5 = !(ZEPHIR_IS_EMPTY(&name_zv));
				}
				_16$$5 = _15$$5;
				if (_16$$5) {
					_16$$5 = Z_TYPE_P(&key) != IS_LONG;
				}
				_17$$5 = _16$$5;
				if (_17$$5) {
					_17$$5 = ZEPHIR_IS_IDENTICAL(&name_zv, &key);
				}
				if (_17$$5) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_10$$5);
				ZVAL_STRING(&_10$$5, "");
				ZVAL_LONG(&_7$$5, (tab + 1));
				ZEPHIR_CALL_METHOD(&_18$$5, this_ptr, "output", &_19, 0, &value, &_10$$5, &_7$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_20$$5);
				ZEPHIR_CONCAT_VS(&_20$$5, &_18$$5, "\n");
				zephir_concat_self(&output, &_20$$5);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, variable, "rewind", NULL, 0);
			zephir_check_call_status();
			_22$$4 = 1;
			while (1) {
				if (_22$$4) {
					_22$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, variable, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_21$$4, variable, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_21$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, variable, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, variable, "current", NULL, 0);
				zephir_check_call_status();
					ZVAL_LONG(&_23$$7, tab);
					ZEPHIR_CALL_FUNCTION(&_24$$7, "str_repeat", &_9, 7, &space, &_23$$7);
					zephir_check_call_status();
					zephir_concat_self(&output, &_24$$7);
					ZEPHIR_INIT_NVAR(&_25$$7);
					ZVAL_STRING(&_25$$7, "arrayKey");
					ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_25$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_26$$7);
					zephir_create_array(&_26$$7, 2, 0);
					ZEPHIR_INIT_NVAR(&_25$$7);
					ZVAL_STRING(&_25$$7, "arr");
					ZEPHIR_CALL_METHOD(&_27$$7, this_ptr, "getstyle", NULL, 0, &_25$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_26$$7, SL("style"), &_27$$7, PH_COPY | PH_SEPARATE);
					zephir_cast_to_string(&_28$$7, &key);
					ZVAL_LONG(&_23$$7, 3);
					ZEPHIR_INIT_NVAR(&_25$$7);
					ZVAL_STRING(&_25$$7, "utf-8");
					ZEPHIR_CALL_FUNCTION(&_27$$7, "htmlspecialchars", &_14, 197, &_28$$7, &_23$$7, &_25$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_26$$7, SL("key"), &_27$$7, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&context, &_26$$7);
					ZEPHIR_CALL_METHOD(&_27$$7, this_ptr, "tointerpolate", NULL, 0, &message, &context);
					zephir_check_call_status();
					zephir_concat_self(&output, &_27$$7);
					_29$$7 = 1 == tab;
					if (_29$$7) {
						_29$$7 = !(ZEPHIR_IS_EMPTY(&name_zv));
					}
					_30$$7 = _29$$7;
					if (_30$$7) {
						_30$$7 = Z_TYPE_P(&key) != IS_LONG;
					}
					_31$$7 = _30$$7;
					if (_31$$7) {
						_31$$7 = ZEPHIR_IS_IDENTICAL(&name_zv, &key);
					}
					if (_31$$7) {
						continue;
					}
					ZEPHIR_INIT_NVAR(&_25$$7);
					ZVAL_STRING(&_25$$7, "");
					ZVAL_LONG(&_23$$7, (tab + 1));
					ZEPHIR_CALL_METHOD(&_32$$7, this_ptr, "output", &_19, 0, &value, &_25$$7, &_23$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_33$$7);
					ZEPHIR_CONCAT_VS(&_33$$7, &_32$$7, "\n");
					zephir_concat_self(&output, &_33$$7);
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_34$$4, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_35$$4, "str_repeat", &_9, 7, &space, &_34$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_35$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_36$$9);
		ZVAL_STRING(&_36$$9, "objectHeader");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_36$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_37$$9);
		zephir_create_array(&_37$$9, 2, 0);
		ZEPHIR_INIT_NVAR(&_36$$9);
		ZVAL_STRING(&_36$$9, "obj");
		ZEPHIR_CALL_METHOD(&_38$$9, this_ptr, "getstyle", NULL, 0, &_36$$9);
		zephir_check_call_status();
		zephir_array_update_string(&_37$$9, SL("style"), &_38$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_36$$9);
		zephir_get_class(&_36$$9, variable, 0);
		zephir_array_update_string(&_37$$9, SL("class"), &_36$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_37$$9);
		ZEPHIR_CALL_METHOD(&_38$$9, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		zephir_concat_self(&output, &_38$$9);
		ZEPHIR_CALL_FUNCTION(&_39$$9, "get_parent_class", NULL, 0, variable);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_39$$9)) {
			ZEPHIR_INIT_VAR(&_40$$10);
			ZVAL_STRING(&_40$$10, "objectExtends");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_40$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_41$$10);
			zephir_create_array(&_41$$10, 2, 0);
			ZEPHIR_INIT_NVAR(&_40$$10);
			ZVAL_STRING(&_40$$10, "obj");
			ZEPHIR_CALL_METHOD(&_42$$10, this_ptr, "getstyle", NULL, 0, &_40$$10);
			zephir_check_call_status();
			zephir_array_update_string(&_41$$10, SL("style"), &_42$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_42$$10, "get_parent_class", NULL, 0, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_41$$10, SL("parent"), &_42$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&context, &_41$$10);
			ZEPHIR_CALL_METHOD(&_42$$10, this_ptr, "tointerpolate", NULL, 0, &message, &context);
			zephir_check_call_status();
			zephir_concat_self(&output, &_42$$10);
		}
		zephir_concat_self_str(&output, SL(" (\n"));
		_43$$9 = Z_TYPE_P(variable) == IS_OBJECT;
		if (_43$$9) {
			_44$$9 = zephir_instance_of_ev(variable, phalcon_di_diinterface_ce);
			if (!(_44$$9)) {
				_44$$9 = zephir_instance_of_ev(variable, phalcon_container_container_ce);
			}
			_43$$9 = _44$$9;
		}
		if (_43$$9) {
			ZVAL_LONG(&_47$$11, tab);
			ZEPHIR_CALL_FUNCTION(&_48$$11, "str_repeat", &_9, 7, &space, &_47$$11);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_49$$11);
			ZEPHIR_CONCAT_VS(&_49$$11, &_48$$11, "[skipped]\n");
			zephir_concat_self(&output, &_49$$11);
		} else {
			zephir_read_property_cached(&_45$$9, this_ptr, _zephir_prop_0, 1353, PH_NOISY_CC | PH_READONLY);
			_46$$9 = !ZEPHIR_IS_TRUE_IDENTICAL(&_45$$9);
			if (!(_46$$9)) {
				_46$$9 = zephir_is_instance_of(variable, SL("stdClass"));
			}
			if (_46$$9) {
				ZEPHIR_CALL_FUNCTION(&vars, "get_object_vars", NULL, 357, variable);
				zephir_check_call_status();
				zephir_is_iterable(&vars, 0, "phalcon/Support/Debug/Dump.zep", 364);
				if (Z_TYPE_P(&vars) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&vars), _51$$12, _52$$12, _50$$12)
					{
						ZEPHIR_INIT_NVAR(&key);
						if (_52$$12 != NULL) { 
							ZVAL_STR_COPY(&key, _52$$12);
						} else {
							ZVAL_LONG(&key, _51$$12);
						}
						ZEPHIR_INIT_NVAR(&value);
						ZVAL_COPY(&value, _50$$12);
						ZEPHIR_INIT_NVAR(&_53$$13);
						ZVAL_STRING(&_53$$13, "objectProperty");
						ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_53$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_54$$13);
						zephir_create_array(&_54$$13, 3, 0);
						ZEPHIR_INIT_NVAR(&_53$$13);
						ZVAL_STRING(&_53$$13, "obj");
						ZEPHIR_CALL_METHOD(&_55$$13, this_ptr, "getstyle", NULL, 0, &_53$$13);
						zephir_check_call_status();
						zephir_array_update_string(&_54$$13, SL("style"), &_55$$13, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_54$$13, SL("key"), &key, PH_COPY | PH_SEPARATE);
						add_assoc_stringl_ex(&_54$$13, SL("type"), SL("public"));
						ZEPHIR_CPY_WRT(&context, &_54$$13);
						ZVAL_LONG(&_56$$13, tab);
						ZEPHIR_CALL_FUNCTION(&_55$$13, "str_repeat", &_9, 7, &space, &_56$$13);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_57$$13, this_ptr, "tointerpolate", NULL, 0, &message, &context);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_53$$13);
						ZVAL_STRING(&_53$$13, "");
						ZVAL_LONG(&_56$$13, (tab + 1));
						ZEPHIR_CALL_METHOD(&_58$$13, this_ptr, "output", &_19, 0, &value, &_53$$13, &_56$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_59$$13);
						ZEPHIR_CONCAT_VVVS(&_59$$13, &_55$$13, &_57$$13, &_58$$13, "\n");
						zephir_concat_self(&output, &_59$$13);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &vars, "rewind", NULL, 0);
					zephir_check_call_status();
					_61$$12 = 1;
					while (1) {
						if (_61$$12) {
							_61$$12 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &vars, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_60$$12, &vars, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_60$$12)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&key, &vars, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&value, &vars, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_62$$14);
							ZVAL_STRING(&_62$$14, "objectProperty");
							ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_62$$14);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_63$$14);
							zephir_create_array(&_63$$14, 3, 0);
							ZEPHIR_INIT_NVAR(&_62$$14);
							ZVAL_STRING(&_62$$14, "obj");
							ZEPHIR_CALL_METHOD(&_64$$14, this_ptr, "getstyle", NULL, 0, &_62$$14);
							zephir_check_call_status();
							zephir_array_update_string(&_63$$14, SL("style"), &_64$$14, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_63$$14, SL("key"), &key, PH_COPY | PH_SEPARATE);
							add_assoc_stringl_ex(&_63$$14, SL("type"), SL("public"));
							ZEPHIR_CPY_WRT(&context, &_63$$14);
							ZVAL_LONG(&_65$$14, tab);
							ZEPHIR_CALL_FUNCTION(&_64$$14, "str_repeat", &_9, 7, &space, &_65$$14);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_66$$14, this_ptr, "tointerpolate", NULL, 0, &message, &context);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_62$$14);
							ZVAL_STRING(&_62$$14, "");
							ZVAL_LONG(&_65$$14, (tab + 1));
							ZEPHIR_CALL_METHOD(&_67$$14, this_ptr, "output", &_19, 0, &value, &_62$$14, &_65$$14);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_68$$14);
							ZEPHIR_CONCAT_VVVS(&_68$$14, &_64$$14, &_66$$14, &_67$$14, "\n");
							zephir_concat_self(&output, &_68$$14);
					}
				}
				ZEPHIR_INIT_NVAR(&value);
				ZEPHIR_INIT_NVAR(&key);
			} else {
				ZEPHIR_INIT_VAR(&reflect);
				object_init_ex(&reflect, zephir_get_internal_ce(SL("reflectionclass")));
				ZEPHIR_CALL_METHOD(NULL, &reflect, "__construct", NULL, 249, variable);
				zephir_check_call_status();
				ZVAL_LONG(&_69$$15, ((1 | 2) | 4));
				ZEPHIR_CALL_METHOD(&props, &reflect, "getproperties", NULL, 370, &_69$$15);
				zephir_check_call_status();
				zephir_is_iterable(&props, 0, "phalcon/Support/Debug/Dump.zep", 392);
				if (Z_TYPE_P(&props) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&props), _70$$15)
					{
						ZEPHIR_INIT_NVAR(&property);
						ZVAL_COPY(&property, _70$$15);
						ZEPHIR_CALL_METHOD(&key, &property, "getname", NULL, 0);
						zephir_check_call_status();
						_72$$16 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
						ZEPHIR_CALL_METHOD(&_74$$16, &property, "getmodifiers", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_CE_STATIC(&_71$$16, _72$$16, "getmodifiernames", &_73, 0, &_74$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&type);
						zephir_fast_join_str(&type, SL(" "), &_71$$16);
						ZEPHIR_INIT_NVAR(&_75$$16);
						ZVAL_STRING(&_75$$16, "objectProperty");
						ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_75$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_76$$16);
						zephir_create_array(&_76$$16, 3, 0);
						ZEPHIR_INIT_NVAR(&_75$$16);
						ZVAL_STRING(&_75$$16, "obj");
						ZEPHIR_CALL_METHOD(&_77$$16, this_ptr, "getstyle", NULL, 0, &_75$$16);
						zephir_check_call_status();
						zephir_array_update_string(&_76$$16, SL("style"), &_77$$16, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_76$$16, SL("key"), &key, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_76$$16, SL("type"), &type, PH_COPY | PH_SEPARATE);
						ZEPHIR_CPY_WRT(&context, &_76$$16);
						ZVAL_LONG(&_78$$16, tab);
						ZEPHIR_CALL_FUNCTION(&_77$$16, "str_repeat", &_9, 7, &space, &_78$$16);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_79$$16, this_ptr, "tointerpolate", NULL, 0, &message, &context);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_81$$16, &property, "getvalue", NULL, 0, variable);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_75$$16);
						ZVAL_STRING(&_75$$16, "");
						ZVAL_LONG(&_78$$16, (tab + 1));
						ZEPHIR_CALL_METHOD(&_80$$16, this_ptr, "output", &_19, 0, &_81$$16, &_75$$16, &_78$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_82$$16);
						ZEPHIR_CONCAT_VVVS(&_82$$16, &_77$$16, &_79$$16, &_80$$16, "\n");
						zephir_concat_self(&output, &_82$$16);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &props, "rewind", NULL, 0);
					zephir_check_call_status();
					_84$$15 = 1;
					while (1) {
						if (_84$$15) {
							_84$$15 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &props, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_83$$15, &props, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_83$$15)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&property, &props, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&key, &property, "getname", NULL, 0);
							zephir_check_call_status();
							_86$$17 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
							ZEPHIR_CALL_METHOD(&_87$$17, &property, "getmodifiers", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_CE_STATIC(&_85$$17, _86$$17, "getmodifiernames", &_73, 0, &_87$$17);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&type);
							zephir_fast_join_str(&type, SL(" "), &_85$$17);
							ZEPHIR_INIT_NVAR(&_88$$17);
							ZVAL_STRING(&_88$$17, "objectProperty");
							ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_88$$17);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_89$$17);
							zephir_create_array(&_89$$17, 3, 0);
							ZEPHIR_INIT_NVAR(&_88$$17);
							ZVAL_STRING(&_88$$17, "obj");
							ZEPHIR_CALL_METHOD(&_90$$17, this_ptr, "getstyle", NULL, 0, &_88$$17);
							zephir_check_call_status();
							zephir_array_update_string(&_89$$17, SL("style"), &_90$$17, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_89$$17, SL("key"), &key, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_89$$17, SL("type"), &type, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&context, &_89$$17);
							ZVAL_LONG(&_91$$17, tab);
							ZEPHIR_CALL_FUNCTION(&_90$$17, "str_repeat", &_9, 7, &space, &_91$$17);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_92$$17, this_ptr, "tointerpolate", NULL, 0, &message, &context);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_94$$17, &property, "getvalue", NULL, 0, variable);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_88$$17);
							ZVAL_STRING(&_88$$17, "");
							ZVAL_LONG(&_91$$17, (tab + 1));
							ZEPHIR_CALL_METHOD(&_93$$17, this_ptr, "output", &_19, 0, &_94$$17, &_88$$17, &_91$$17);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_95$$17);
							ZEPHIR_CONCAT_VVVS(&_95$$17, &_90$$17, &_92$$17, &_93$$17, "\n");
							zephir_concat_self(&output, &_95$$17);
					}
				}
				ZEPHIR_INIT_NVAR(&property);
			}
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 0, variable);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_36$$9);
		ZVAL_STRING(&_36$$9, "objectMethods");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_36$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_96$$9);
		zephir_create_array(&_96$$9, 3, 0);
		ZEPHIR_INIT_NVAR(&_36$$9);
		ZVAL_STRING(&_36$$9, "obj");
		ZEPHIR_CALL_METHOD(&_97$$9, this_ptr, "getstyle", NULL, 0, &_36$$9);
		zephir_check_call_status();
		zephir_array_update_string(&_96$$9, SL("style"), &_97$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_36$$9);
		zephir_get_class(&_36$$9, variable, 0);
		zephir_array_update_string(&_96$$9, SL("class"), &_36$$9, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_96$$9, SL("count"), zephir_fast_count_int(&attr));
		ZEPHIR_CPY_WRT(&context, &_96$$9);
		ZVAL_LONG(&_98$$9, tab);
		ZEPHIR_CALL_FUNCTION(&_97$$9, "str_repeat", &_9, 7, &space, &_98$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_99$$9, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_100$$9);
		ZEPHIR_CONCAT_VV(&_100$$9, &_97$$9, &_99$$9);
		zephir_concat_self(&output, &_100$$9);
		ZEPHIR_INIT_NVAR(&_36$$9);
		zephir_get_class(&_36$$9, variable, 0);
		zephir_read_property_cached(&_98$$9, this_ptr, _zephir_prop_1, 1355, PH_NOISY_CC | PH_READONLY);
		if (1 == zephir_fast_in_array(&_36$$9, &_98$$9)) {
			ZVAL_LONG(&_101$$18, tab);
			ZEPHIR_CALL_FUNCTION(&_102$$18, "str_repeat", &_9, 7, &space, &_101$$18);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_103$$18);
			ZEPHIR_CONCAT_VS(&_103$$18, &_102$$18, "[already listed]\n");
			zephir_concat_self(&output, &_103$$18);
		} else {
			zephir_is_iterable(&attr, 0, "phalcon/Support/Debug/Dump.zep", 425);
			if (Z_TYPE_P(&attr) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attr), _104$$19)
				{
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _104$$19);
					ZEPHIR_INIT_NVAR(&_105$$20);
					zephir_get_class(&_105$$20, variable, 0);
					zephir_update_property_array_append(this_ptr, SL("methods"), &_105$$20);
					ZEPHIR_INIT_NVAR(&_105$$20);
					ZVAL_STRING(&_105$$20, "objectMethod");
					ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_105$$20);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_106$$20);
					ZVAL_STRING(&_106$$20, "__construct");
					if (ZEPHIR_IS_IDENTICAL(&_106$$20, &value)) {
						ZEPHIR_INIT_NVAR(&_107$$21);
						ZVAL_STRING(&_107$$21, "objectMethodConstructor");
						ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_107$$21);
						zephir_check_call_status();
					}
					ZEPHIR_INIT_NVAR(&_108$$20);
					zephir_create_array(&_108$$20, 2, 0);
					ZEPHIR_INIT_NVAR(&_105$$20);
					ZVAL_STRING(&_105$$20, "obj");
					ZEPHIR_CALL_METHOD(&_109$$20, this_ptr, "getstyle", NULL, 0, &_105$$20);
					zephir_check_call_status();
					zephir_array_update_string(&_108$$20, SL("style"), &_109$$20, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_108$$20, SL("method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&context, &_108$$20);
					ZVAL_LONG(&_110$$20, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_109$$20, "str_repeat", &_9, 7, &space, &_110$$20);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_111$$20, this_ptr, "tointerpolate", NULL, 0, &message, &context);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_112$$20);
					ZEPHIR_CONCAT_VV(&_112$$20, &_109$$20, &_111$$20);
					zephir_concat_self(&output, &_112$$20);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &attr, "rewind", NULL, 0);
				zephir_check_call_status();
				_114$$19 = 1;
				while (1) {
					if (_114$$19) {
						_114$$19 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &attr, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_113$$19, &attr, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_113$$19)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&value, &attr, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_115$$22);
						zephir_get_class(&_115$$22, variable, 0);
						zephir_update_property_array_append(this_ptr, SL("methods"), &_115$$22);
						ZEPHIR_INIT_NVAR(&_115$$22);
						ZVAL_STRING(&_115$$22, "objectMethod");
						ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_115$$22);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_116$$22);
						ZVAL_STRING(&_116$$22, "__construct");
						if (ZEPHIR_IS_IDENTICAL(&_116$$22, &value)) {
							ZEPHIR_INIT_NVAR(&_117$$23);
							ZVAL_STRING(&_117$$23, "objectMethodConstructor");
							ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_117$$23);
							zephir_check_call_status();
						}
						ZEPHIR_INIT_NVAR(&_118$$22);
						zephir_create_array(&_118$$22, 2, 0);
						ZEPHIR_INIT_NVAR(&_115$$22);
						ZVAL_STRING(&_115$$22, "obj");
						ZEPHIR_CALL_METHOD(&_119$$22, this_ptr, "getstyle", NULL, 0, &_115$$22);
						zephir_check_call_status();
						zephir_array_update_string(&_118$$22, SL("style"), &_119$$22, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_118$$22, SL("method"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_CPY_WRT(&context, &_118$$22);
						ZVAL_LONG(&_120$$22, (tab + 1));
						ZEPHIR_CALL_FUNCTION(&_119$$22, "str_repeat", &_9, 7, &space, &_120$$22);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_121$$22, this_ptr, "tointerpolate", NULL, 0, &message, &context);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_122$$22);
						ZEPHIR_CONCAT_VV(&_122$$22, &_119$$22, &_121$$22);
						zephir_concat_self(&output, &_122$$22);
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_LONG(&_123$$19, tab);
			ZEPHIR_CALL_FUNCTION(&_124$$19, "str_repeat", &_9, 7, &space, &_123$$19);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_125$$19);
			ZEPHIR_CONCAT_VS(&_125$$19, &_124$$19, ")\n");
			zephir_concat_self(&output, &_125$$19);
		}
		ZVAL_LONG(&_126$$9, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_127$$9, "str_repeat", &_9, 7, &space, &_126$$9);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_127$$9, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_129$$24);
		ZVAL_STRING(&_129$$24, "Integer");
		ZEPHIR_CALL_METHOD(&_128$$24, this_ptr, "getoutputbold", NULL, 0, &_129$$24);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_129$$24);
		ZVAL_STRING(&_129$$24, "varParens");
		ZEPHIR_CALL_METHOD(&_130$$24, this_ptr, "gettemplate", NULL, 0, &_129$$24);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_128$$24, " ", &_130$$24);
		ZEPHIR_INIT_VAR(&_131$$24);
		zephir_create_array(&_131$$24, 2, 0);
		ZEPHIR_INIT_NVAR(&_129$$24);
		ZVAL_STRING(&_129$$24, "int");
		ZEPHIR_CALL_METHOD(&_132$$24, this_ptr, "getstyle", NULL, 0, &_129$$24);
		zephir_check_call_status();
		zephir_array_update_string(&_131$$24, SL("style"), &_132$$24, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_131$$24, SL("var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_131$$24);
		ZEPHIR_CALL_METHOD(&_132$$24, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_132$$24);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_DOUBLE) {
		ZEPHIR_INIT_VAR(&_134$$25);
		ZVAL_STRING(&_134$$25, "Float");
		ZEPHIR_CALL_METHOD(&_133$$25, this_ptr, "getoutputbold", NULL, 0, &_134$$25);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_134$$25);
		ZVAL_STRING(&_134$$25, "varParens");
		ZEPHIR_CALL_METHOD(&_135$$25, this_ptr, "gettemplate", NULL, 0, &_134$$25);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_133$$25, " ", &_135$$25);
		ZEPHIR_INIT_VAR(&_136$$25);
		zephir_create_array(&_136$$25, 2, 0);
		ZEPHIR_INIT_NVAR(&_134$$25);
		ZVAL_STRING(&_134$$25, "float");
		ZEPHIR_CALL_METHOD(&_137$$25, this_ptr, "getstyle", NULL, 0, &_134$$25);
		zephir_check_call_status();
		zephir_array_update_string(&_136$$25, SL("style"), &_137$$25, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_136$$25, SL("var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_136$$25);
		ZEPHIR_CALL_METHOD(&_137$$25, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_137$$25);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_139$$26);
		ZVAL_STRING(&_139$$26, "Numeric String");
		ZEPHIR_CALL_METHOD(&_138$$26, this_ptr, "getoutputbold", NULL, 0, &_139$$26);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_139$$26);
		ZVAL_STRING(&_139$$26, "lengthValue");
		ZEPHIR_CALL_METHOD(&_140$$26, this_ptr, "gettemplate", NULL, 0, &_139$$26);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_138$$26, " ", &_140$$26);
		ZEPHIR_INIT_VAR(&_141$$26);
		zephir_create_array(&_141$$26, 3, 0);
		ZEPHIR_INIT_NVAR(&_139$$26);
		ZVAL_STRING(&_139$$26, "num");
		ZEPHIR_CALL_METHOD(&_142$$26, this_ptr, "getstyle", NULL, 0, &_139$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_141$$26, SL("style"), &_142$$26, PH_COPY | PH_SEPARATE);
		zephir_cast_to_string(&_143$$26, variable);
		ZEPHIR_CALL_FUNCTION(&_142$$26, "mb_strlen", NULL, 0, &_143$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_141$$26, SL("length"), &_142$$26, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_141$$26, SL("var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_141$$26);
		ZEPHIR_CALL_METHOD(&_142$$26, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_142$$26);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_145$$27);
		ZVAL_STRING(&_145$$27, "String");
		ZEPHIR_CALL_METHOD(&_144$$27, this_ptr, "getoutputbold", NULL, 0, &_145$$27);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_145$$27);
		ZVAL_STRING(&_145$$27, "lengthValue");
		ZEPHIR_CALL_METHOD(&_146$$27, this_ptr, "gettemplate", NULL, 0, &_145$$27);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_144$$27, " ", &_146$$27);
		ZEPHIR_INIT_VAR(&_147$$27);
		zephir_create_array(&_147$$27, 3, 0);
		ZEPHIR_INIT_NVAR(&_145$$27);
		ZVAL_STRING(&_145$$27, "str");
		ZEPHIR_CALL_METHOD(&_148$$27, this_ptr, "getstyle", NULL, 0, &_145$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_147$$27, SL("style"), &_148$$27, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_148$$27, "mb_strlen", NULL, 0, variable);
		zephir_check_call_status();
		zephir_array_update_string(&_147$$27, SL("length"), &_148$$27, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_149$$27, 4);
		ZEPHIR_INIT_NVAR(&_145$$27);
		ZVAL_STRING(&_145$$27, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_148$$27, "htmlentities", NULL, 0, variable, &_149$$27, &_145$$27);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_150$$27, "nl2br", NULL, 0, &_148$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_147$$27, SL("var"), &_150$$27, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_147$$27);
		ZEPHIR_CALL_METHOD(&_150$$27, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_150$$27);
		RETURN_MM();
	}
	if (((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE) == 1)) {
		ZEPHIR_INIT_VAR(&_152$$28);
		ZVAL_STRING(&_152$$28, "Boolean");
		ZEPHIR_CALL_METHOD(&_151$$28, this_ptr, "getoutputbold", NULL, 0, &_152$$28);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_152$$28);
		ZVAL_STRING(&_152$$28, "varParens");
		ZEPHIR_CALL_METHOD(&_153$$28, this_ptr, "gettemplate", NULL, 0, &_152$$28);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_151$$28, " ", &_153$$28);
		ZEPHIR_INIT_VAR(&_154$$28);
		zephir_create_array(&_154$$28, 2, 0);
		ZEPHIR_INIT_NVAR(&_152$$28);
		ZVAL_STRING(&_152$$28, "bool");
		ZEPHIR_CALL_METHOD(&_155$$28, this_ptr, "getstyle", NULL, 0, &_152$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_154$$28, SL("style"), &_155$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_156$$28);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_156$$28);
			ZVAL_STRING(&_156$$28, "TRUE");
		} else {
			ZEPHIR_INIT_NVAR(&_156$$28);
			ZVAL_STRING(&_156$$28, "FALSE");
		}
		zephir_array_update_string(&_154$$28, SL("var"), &_156$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_154$$28);
		ZEPHIR_CALL_METHOD(&_155$$28, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_155$$28);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_157$$29);
		ZVAL_STRING(&_157$$29, "NULL");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoutputbold", NULL, 0, &_157$$29);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_158$$29);
		zephir_create_array(&_158$$29, 1, 0);
		ZEPHIR_INIT_NVAR(&_157$$29);
		ZVAL_STRING(&_157$$29, "null");
		ZEPHIR_CALL_METHOD(&_159$$29, this_ptr, "getstyle", NULL, 0, &_157$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_158$$29, SL("style"), &_159$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_158$$29);
		ZEPHIR_CALL_METHOD(&_159$$29, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_159$$29);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_160);
	ZVAL_STRING(&_160, "varParens");
	ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_160);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_161);
	zephir_create_array(&_161, 2, 0);
	ZEPHIR_INIT_NVAR(&_160);
	ZVAL_STRING(&_160, "other");
	ZEPHIR_CALL_METHOD(&_162, this_ptr, "getstyle", NULL, 0, &_160);
	zephir_check_call_status();
	zephir_array_update_string(&_161, SL("style"), &_162, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_161, SL("var"), variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_CPY_WRT(&context, &_161);
	ZEPHIR_CALL_METHOD(&_162, this_ptr, "tointerpolate", NULL, 0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_162);
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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 1356, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value(&_1, &name_zv)) {
		zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 1356, PH_NOISY_CC | PH_READONLY);
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

