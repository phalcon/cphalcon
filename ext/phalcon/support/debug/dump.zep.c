
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

	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1349, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstyles", NULL, 0, &styles);
	zephir_check_call_status();
	if (detailed) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1350, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1350, &__$false);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1350, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1350, &__$false);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1351, &_1);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1349, PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1351, PH_NOISY_CC | PH_READONLY);
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
	zend_class_entry *_69$$16, *_83$$17;
	zend_bool _20$$4, _13$$5, _14$$5, _15$$5, _26$$7, _27$$7, _28$$7, _40$$9, _41$$9, _43$$9, _58$$12, _81$$15, _111$$19;
	zend_ulong _5$$4, _48$$12;
	zval space, _0$$3, _140$$26;
	zval context;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_17 = NULL, *_70 = NULL;
	zend_long tab, ZEPHIR_LAST_CALL_STATUS;
	zend_string *name = NULL, *_6$$4, *_49$$12;
	zval *variable, variable_sub, name_zv, *tab_param = NULL, attr, key, message, output, property, props, reflect, type, value, vars, _157, _158, _159, _1$$4, _2$$4, _3$$4, *_4$$4, _19$$4, _31$$4, _32$$4, _7$$5, _8$$5, _10$$5, _11$$5, _12$$5, _16$$5, _18$$5, _21$$7, _22$$7, _23$$7, _24$$7, _25$$7, _29$$7, _30$$7, _33$$9, _34$$9, _35$$9, _36$$9, _42$$9, _93$$9, _94$$9, _95$$9, _96$$9, _97$$9, _123$$9, _124$$9, _37$$10, _38$$10, _39$$10, _44$$11, _45$$11, _46$$11, *_47$$12, _57$$12, _50$$13, _51$$13, _52$$13, _53$$13, _54$$13, _55$$13, _56$$13, _59$$14, _60$$14, _61$$14, _62$$14, _63$$14, _64$$14, _65$$14, _66$$15, *_67$$15, _80$$15, _68$$16, _71$$16, _72$$16, _73$$16, _74$$16, _75$$16, _76$$16, _77$$16, _78$$16, _79$$16, _82$$17, _84$$17, _85$$17, _86$$17, _87$$17, _88$$17, _89$$17, _90$$17, _91$$17, _92$$17, _98$$18, _99$$18, _100$$18, *_101$$19, _110$$19, _120$$19, _121$$19, _122$$19, _102$$20, _103$$20, _105$$20, _106$$20, _107$$20, _108$$20, _109$$20, _104$$21, _112$$22, _113$$22, _115$$22, _116$$22, _117$$22, _118$$22, _119$$22, _114$$23, _125$$24, _126$$24, _127$$24, _128$$24, _129$$24, _130$$25, _131$$25, _132$$25, _133$$25, _134$$25, _135$$26, _136$$26, _137$$26, _138$$26, _139$$26, _141$$27, _142$$27, _143$$27, _144$$27, _145$$27, _146$$27, _147$$27, _148$$28, _149$$28, _150$$28, _151$$28, _152$$28, _153$$28, _154$$29, _155$$29, _156$$29;
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
	ZVAL_UNDEF(&_157);
	ZVAL_UNDEF(&_158);
	ZVAL_UNDEF(&_159);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_31$$4);
	ZVAL_UNDEF(&_32$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_33$$9);
	ZVAL_UNDEF(&_34$$9);
	ZVAL_UNDEF(&_35$$9);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_42$$9);
	ZVAL_UNDEF(&_93$$9);
	ZVAL_UNDEF(&_94$$9);
	ZVAL_UNDEF(&_95$$9);
	ZVAL_UNDEF(&_96$$9);
	ZVAL_UNDEF(&_97$$9);
	ZVAL_UNDEF(&_123$$9);
	ZVAL_UNDEF(&_124$$9);
	ZVAL_UNDEF(&_37$$10);
	ZVAL_UNDEF(&_38$$10);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_44$$11);
	ZVAL_UNDEF(&_45$$11);
	ZVAL_UNDEF(&_46$$11);
	ZVAL_UNDEF(&_57$$12);
	ZVAL_UNDEF(&_50$$13);
	ZVAL_UNDEF(&_51$$13);
	ZVAL_UNDEF(&_52$$13);
	ZVAL_UNDEF(&_53$$13);
	ZVAL_UNDEF(&_54$$13);
	ZVAL_UNDEF(&_55$$13);
	ZVAL_UNDEF(&_56$$13);
	ZVAL_UNDEF(&_59$$14);
	ZVAL_UNDEF(&_60$$14);
	ZVAL_UNDEF(&_61$$14);
	ZVAL_UNDEF(&_62$$14);
	ZVAL_UNDEF(&_63$$14);
	ZVAL_UNDEF(&_64$$14);
	ZVAL_UNDEF(&_65$$14);
	ZVAL_UNDEF(&_66$$15);
	ZVAL_UNDEF(&_80$$15);
	ZVAL_UNDEF(&_68$$16);
	ZVAL_UNDEF(&_71$$16);
	ZVAL_UNDEF(&_72$$16);
	ZVAL_UNDEF(&_73$$16);
	ZVAL_UNDEF(&_74$$16);
	ZVAL_UNDEF(&_75$$16);
	ZVAL_UNDEF(&_76$$16);
	ZVAL_UNDEF(&_77$$16);
	ZVAL_UNDEF(&_78$$16);
	ZVAL_UNDEF(&_79$$16);
	ZVAL_UNDEF(&_82$$17);
	ZVAL_UNDEF(&_84$$17);
	ZVAL_UNDEF(&_85$$17);
	ZVAL_UNDEF(&_86$$17);
	ZVAL_UNDEF(&_87$$17);
	ZVAL_UNDEF(&_88$$17);
	ZVAL_UNDEF(&_89$$17);
	ZVAL_UNDEF(&_90$$17);
	ZVAL_UNDEF(&_91$$17);
	ZVAL_UNDEF(&_92$$17);
	ZVAL_UNDEF(&_98$$18);
	ZVAL_UNDEF(&_99$$18);
	ZVAL_UNDEF(&_100$$18);
	ZVAL_UNDEF(&_110$$19);
	ZVAL_UNDEF(&_120$$19);
	ZVAL_UNDEF(&_121$$19);
	ZVAL_UNDEF(&_122$$19);
	ZVAL_UNDEF(&_102$$20);
	ZVAL_UNDEF(&_103$$20);
	ZVAL_UNDEF(&_105$$20);
	ZVAL_UNDEF(&_106$$20);
	ZVAL_UNDEF(&_107$$20);
	ZVAL_UNDEF(&_108$$20);
	ZVAL_UNDEF(&_109$$20);
	ZVAL_UNDEF(&_104$$21);
	ZVAL_UNDEF(&_112$$22);
	ZVAL_UNDEF(&_113$$22);
	ZVAL_UNDEF(&_115$$22);
	ZVAL_UNDEF(&_116$$22);
	ZVAL_UNDEF(&_117$$22);
	ZVAL_UNDEF(&_118$$22);
	ZVAL_UNDEF(&_119$$22);
	ZVAL_UNDEF(&_114$$23);
	ZVAL_UNDEF(&_125$$24);
	ZVAL_UNDEF(&_126$$24);
	ZVAL_UNDEF(&_127$$24);
	ZVAL_UNDEF(&_128$$24);
	ZVAL_UNDEF(&_129$$24);
	ZVAL_UNDEF(&_130$$25);
	ZVAL_UNDEF(&_131$$25);
	ZVAL_UNDEF(&_132$$25);
	ZVAL_UNDEF(&_133$$25);
	ZVAL_UNDEF(&_134$$25);
	ZVAL_UNDEF(&_135$$26);
	ZVAL_UNDEF(&_136$$26);
	ZVAL_UNDEF(&_137$$26);
	ZVAL_UNDEF(&_138$$26);
	ZVAL_UNDEF(&_139$$26);
	ZVAL_UNDEF(&_141$$27);
	ZVAL_UNDEF(&_142$$27);
	ZVAL_UNDEF(&_143$$27);
	ZVAL_UNDEF(&_144$$27);
	ZVAL_UNDEF(&_145$$27);
	ZVAL_UNDEF(&_146$$27);
	ZVAL_UNDEF(&_147$$27);
	ZVAL_UNDEF(&_148$$28);
	ZVAL_UNDEF(&_149$$28);
	ZVAL_UNDEF(&_150$$28);
	ZVAL_UNDEF(&_151$$28);
	ZVAL_UNDEF(&_152$$28);
	ZVAL_UNDEF(&_153$$28);
	ZVAL_UNDEF(&_154$$29);
	ZVAL_UNDEF(&_155$$29);
	ZVAL_UNDEF(&_156$$29);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&space);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_140$$26);
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
				ZEPHIR_CALL_FUNCTION(&_8$$5, "str_repeat", &_9, 6, &space, &_7$$5);
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
				zephir_array_update_string(&_11$$5, SL("key"), &key, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&context, &_11$$5);
				ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "tointerpolate", NULL, 0, &message, &context);
				zephir_check_call_status();
				zephir_concat_self(&output, &_12$$5);
				_13$$5 = 1 == tab;
				if (_13$$5) {
					_13$$5 = !(ZEPHIR_IS_EMPTY(&name_zv));
				}
				_14$$5 = _13$$5;
				if (_14$$5) {
					_14$$5 = Z_TYPE_P(&key) != IS_LONG;
				}
				_15$$5 = _14$$5;
				if (_15$$5) {
					_15$$5 = ZEPHIR_IS_IDENTICAL(&name_zv, &key);
				}
				if (_15$$5) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_10$$5);
				ZVAL_STRING(&_10$$5, "");
				ZVAL_LONG(&_7$$5, (tab + 1));
				ZEPHIR_CALL_METHOD(&_16$$5, this_ptr, "output", &_17, 0, &value, &_10$$5, &_7$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_18$$5);
				ZEPHIR_CONCAT_VS(&_18$$5, &_16$$5, "\n");
				zephir_concat_self(&output, &_18$$5);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, variable, "rewind", NULL, 0);
			zephir_check_call_status();
			_20$$4 = 1;
			while (1) {
				if (_20$$4) {
					_20$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, variable, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_19$$4, variable, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_19$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, variable, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, variable, "current", NULL, 0);
				zephir_check_call_status();
					ZVAL_LONG(&_21$$7, tab);
					ZEPHIR_CALL_FUNCTION(&_22$$7, "str_repeat", &_9, 6, &space, &_21$$7);
					zephir_check_call_status();
					zephir_concat_self(&output, &_22$$7);
					ZEPHIR_INIT_NVAR(&_23$$7);
					ZVAL_STRING(&_23$$7, "arrayKey");
					ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_23$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_24$$7);
					zephir_create_array(&_24$$7, 2, 0);
					ZEPHIR_INIT_NVAR(&_23$$7);
					ZVAL_STRING(&_23$$7, "arr");
					ZEPHIR_CALL_METHOD(&_25$$7, this_ptr, "getstyle", NULL, 0, &_23$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_24$$7, SL("style"), &_25$$7, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_24$$7, SL("key"), &key, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&context, &_24$$7);
					ZEPHIR_CALL_METHOD(&_25$$7, this_ptr, "tointerpolate", NULL, 0, &message, &context);
					zephir_check_call_status();
					zephir_concat_self(&output, &_25$$7);
					_26$$7 = 1 == tab;
					if (_26$$7) {
						_26$$7 = !(ZEPHIR_IS_EMPTY(&name_zv));
					}
					_27$$7 = _26$$7;
					if (_27$$7) {
						_27$$7 = Z_TYPE_P(&key) != IS_LONG;
					}
					_28$$7 = _27$$7;
					if (_28$$7) {
						_28$$7 = ZEPHIR_IS_IDENTICAL(&name_zv, &key);
					}
					if (_28$$7) {
						continue;
					}
					ZEPHIR_INIT_NVAR(&_23$$7);
					ZVAL_STRING(&_23$$7, "");
					ZVAL_LONG(&_21$$7, (tab + 1));
					ZEPHIR_CALL_METHOD(&_29$$7, this_ptr, "output", &_17, 0, &value, &_23$$7, &_21$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_30$$7);
					ZEPHIR_CONCAT_VS(&_30$$7, &_29$$7, "\n");
					zephir_concat_self(&output, &_30$$7);
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_31$$4, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_32$$4, "str_repeat", &_9, 6, &space, &_31$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_32$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_33$$9);
		ZVAL_STRING(&_33$$9, "objectHeader");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_33$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_34$$9);
		zephir_create_array(&_34$$9, 2, 0);
		ZEPHIR_INIT_NVAR(&_33$$9);
		ZVAL_STRING(&_33$$9, "obj");
		ZEPHIR_CALL_METHOD(&_35$$9, this_ptr, "getstyle", NULL, 0, &_33$$9);
		zephir_check_call_status();
		zephir_array_update_string(&_34$$9, SL("style"), &_35$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_33$$9);
		zephir_get_class(&_33$$9, variable, 0);
		zephir_array_update_string(&_34$$9, SL("class"), &_33$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_34$$9);
		ZEPHIR_CALL_METHOD(&_35$$9, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		zephir_concat_self(&output, &_35$$9);
		ZEPHIR_CALL_FUNCTION(&_36$$9, "get_parent_class", NULL, 0, variable);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_36$$9)) {
			ZEPHIR_INIT_VAR(&_37$$10);
			ZVAL_STRING(&_37$$10, "objectExtends");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_37$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_38$$10);
			zephir_create_array(&_38$$10, 2, 0);
			ZEPHIR_INIT_NVAR(&_37$$10);
			ZVAL_STRING(&_37$$10, "obj");
			ZEPHIR_CALL_METHOD(&_39$$10, this_ptr, "getstyle", NULL, 0, &_37$$10);
			zephir_check_call_status();
			zephir_array_update_string(&_38$$10, SL("style"), &_39$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_39$$10, "get_parent_class", NULL, 0, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_38$$10, SL("parent"), &_39$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&context, &_38$$10);
			ZEPHIR_CALL_METHOD(&_39$$10, this_ptr, "tointerpolate", NULL, 0, &message, &context);
			zephir_check_call_status();
			zephir_concat_self(&output, &_39$$10);
		}
		zephir_concat_self_str(&output, SL(" (\n"));
		_40$$9 = Z_TYPE_P(variable) == IS_OBJECT;
		if (_40$$9) {
			_41$$9 = zephir_instance_of_ev(variable, phalcon_di_diinterface_ce);
			if (!(_41$$9)) {
				_41$$9 = zephir_instance_of_ev(variable, phalcon_container_container_ce);
			}
			_40$$9 = _41$$9;
		}
		if (_40$$9) {
			ZVAL_LONG(&_44$$11, tab);
			ZEPHIR_CALL_FUNCTION(&_45$$11, "str_repeat", &_9, 6, &space, &_44$$11);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_46$$11);
			ZEPHIR_CONCAT_VS(&_46$$11, &_45$$11, "[skipped]\n");
			zephir_concat_self(&output, &_46$$11);
		} else {
			zephir_read_property_cached(&_42$$9, this_ptr, _zephir_prop_0, 1350, PH_NOISY_CC | PH_READONLY);
			_43$$9 = !ZEPHIR_IS_TRUE_IDENTICAL(&_42$$9);
			if (!(_43$$9)) {
				_43$$9 = zephir_is_instance_of(variable, SL("stdClass"));
			}
			if (_43$$9) {
				ZEPHIR_CALL_FUNCTION(&vars, "get_object_vars", NULL, 353, variable);
				zephir_check_call_status();
				zephir_is_iterable(&vars, 0, "phalcon/Support/Debug/Dump.zep", 364);
				if (Z_TYPE_P(&vars) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&vars), _48$$12, _49$$12, _47$$12)
					{
						ZEPHIR_INIT_NVAR(&key);
						if (_49$$12 != NULL) { 
							ZVAL_STR_COPY(&key, _49$$12);
						} else {
							ZVAL_LONG(&key, _48$$12);
						}
						ZEPHIR_INIT_NVAR(&value);
						ZVAL_COPY(&value, _47$$12);
						ZEPHIR_INIT_NVAR(&_50$$13);
						ZVAL_STRING(&_50$$13, "objectProperty");
						ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_50$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_51$$13);
						zephir_create_array(&_51$$13, 3, 0);
						ZEPHIR_INIT_NVAR(&_50$$13);
						ZVAL_STRING(&_50$$13, "obj");
						ZEPHIR_CALL_METHOD(&_52$$13, this_ptr, "getstyle", NULL, 0, &_50$$13);
						zephir_check_call_status();
						zephir_array_update_string(&_51$$13, SL("style"), &_52$$13, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_51$$13, SL("key"), &key, PH_COPY | PH_SEPARATE);
						add_assoc_stringl_ex(&_51$$13, SL("type"), SL("public"));
						ZEPHIR_CPY_WRT(&context, &_51$$13);
						ZVAL_LONG(&_53$$13, tab);
						ZEPHIR_CALL_FUNCTION(&_52$$13, "str_repeat", &_9, 6, &space, &_53$$13);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_54$$13, this_ptr, "tointerpolate", NULL, 0, &message, &context);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_50$$13);
						ZVAL_STRING(&_50$$13, "");
						ZVAL_LONG(&_53$$13, (tab + 1));
						ZEPHIR_CALL_METHOD(&_55$$13, this_ptr, "output", &_17, 0, &value, &_50$$13, &_53$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_56$$13);
						ZEPHIR_CONCAT_VVVS(&_56$$13, &_52$$13, &_54$$13, &_55$$13, "\n");
						zephir_concat_self(&output, &_56$$13);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &vars, "rewind", NULL, 0);
					zephir_check_call_status();
					_58$$12 = 1;
					while (1) {
						if (_58$$12) {
							_58$$12 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &vars, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_57$$12, &vars, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_57$$12)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&key, &vars, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&value, &vars, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_59$$14);
							ZVAL_STRING(&_59$$14, "objectProperty");
							ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_59$$14);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_60$$14);
							zephir_create_array(&_60$$14, 3, 0);
							ZEPHIR_INIT_NVAR(&_59$$14);
							ZVAL_STRING(&_59$$14, "obj");
							ZEPHIR_CALL_METHOD(&_61$$14, this_ptr, "getstyle", NULL, 0, &_59$$14);
							zephir_check_call_status();
							zephir_array_update_string(&_60$$14, SL("style"), &_61$$14, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_60$$14, SL("key"), &key, PH_COPY | PH_SEPARATE);
							add_assoc_stringl_ex(&_60$$14, SL("type"), SL("public"));
							ZEPHIR_CPY_WRT(&context, &_60$$14);
							ZVAL_LONG(&_62$$14, tab);
							ZEPHIR_CALL_FUNCTION(&_61$$14, "str_repeat", &_9, 6, &space, &_62$$14);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_63$$14, this_ptr, "tointerpolate", NULL, 0, &message, &context);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_59$$14);
							ZVAL_STRING(&_59$$14, "");
							ZVAL_LONG(&_62$$14, (tab + 1));
							ZEPHIR_CALL_METHOD(&_64$$14, this_ptr, "output", &_17, 0, &value, &_59$$14, &_62$$14);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_65$$14);
							ZEPHIR_CONCAT_VVVS(&_65$$14, &_61$$14, &_63$$14, &_64$$14, "\n");
							zephir_concat_self(&output, &_65$$14);
					}
				}
				ZEPHIR_INIT_NVAR(&value);
				ZEPHIR_INIT_NVAR(&key);
			} else {
				ZEPHIR_INIT_VAR(&reflect);
				object_init_ex(&reflect, zephir_get_internal_ce(SL("reflectionclass")));
				ZEPHIR_CALL_METHOD(NULL, &reflect, "__construct", NULL, 246, variable);
				zephir_check_call_status();
				ZVAL_LONG(&_66$$15, ((1 | 2) | 4));
				ZEPHIR_CALL_METHOD(&props, &reflect, "getproperties", NULL, 365, &_66$$15);
				zephir_check_call_status();
				zephir_is_iterable(&props, 0, "phalcon/Support/Debug/Dump.zep", 392);
				if (Z_TYPE_P(&props) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&props), _67$$15)
					{
						ZEPHIR_INIT_NVAR(&property);
						ZVAL_COPY(&property, _67$$15);
						ZEPHIR_CALL_METHOD(&key, &property, "getname", NULL, 0);
						zephir_check_call_status();
						_69$$16 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
						ZEPHIR_CALL_METHOD(&_71$$16, &property, "getmodifiers", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_CE_STATIC(&_68$$16, _69$$16, "getmodifiernames", &_70, 0, &_71$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&type);
						zephir_fast_join_str(&type, SL(" "), &_68$$16);
						ZEPHIR_INIT_NVAR(&_72$$16);
						ZVAL_STRING(&_72$$16, "objectProperty");
						ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_72$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_73$$16);
						zephir_create_array(&_73$$16, 3, 0);
						ZEPHIR_INIT_NVAR(&_72$$16);
						ZVAL_STRING(&_72$$16, "obj");
						ZEPHIR_CALL_METHOD(&_74$$16, this_ptr, "getstyle", NULL, 0, &_72$$16);
						zephir_check_call_status();
						zephir_array_update_string(&_73$$16, SL("style"), &_74$$16, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_73$$16, SL("key"), &key, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_73$$16, SL("type"), &type, PH_COPY | PH_SEPARATE);
						ZEPHIR_CPY_WRT(&context, &_73$$16);
						ZVAL_LONG(&_75$$16, tab);
						ZEPHIR_CALL_FUNCTION(&_74$$16, "str_repeat", &_9, 6, &space, &_75$$16);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_76$$16, this_ptr, "tointerpolate", NULL, 0, &message, &context);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_78$$16, &property, "getvalue", NULL, 0, variable);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_72$$16);
						ZVAL_STRING(&_72$$16, "");
						ZVAL_LONG(&_75$$16, (tab + 1));
						ZEPHIR_CALL_METHOD(&_77$$16, this_ptr, "output", &_17, 0, &_78$$16, &_72$$16, &_75$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_79$$16);
						ZEPHIR_CONCAT_VVVS(&_79$$16, &_74$$16, &_76$$16, &_77$$16, "\n");
						zephir_concat_self(&output, &_79$$16);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &props, "rewind", NULL, 0);
					zephir_check_call_status();
					_81$$15 = 1;
					while (1) {
						if (_81$$15) {
							_81$$15 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &props, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_80$$15, &props, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_80$$15)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&property, &props, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&key, &property, "getname", NULL, 0);
							zephir_check_call_status();
							_83$$17 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
							ZEPHIR_CALL_METHOD(&_84$$17, &property, "getmodifiers", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_CE_STATIC(&_82$$17, _83$$17, "getmodifiernames", &_70, 0, &_84$$17);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&type);
							zephir_fast_join_str(&type, SL(" "), &_82$$17);
							ZEPHIR_INIT_NVAR(&_85$$17);
							ZVAL_STRING(&_85$$17, "objectProperty");
							ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_85$$17);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_86$$17);
							zephir_create_array(&_86$$17, 3, 0);
							ZEPHIR_INIT_NVAR(&_85$$17);
							ZVAL_STRING(&_85$$17, "obj");
							ZEPHIR_CALL_METHOD(&_87$$17, this_ptr, "getstyle", NULL, 0, &_85$$17);
							zephir_check_call_status();
							zephir_array_update_string(&_86$$17, SL("style"), &_87$$17, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_86$$17, SL("key"), &key, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_86$$17, SL("type"), &type, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&context, &_86$$17);
							ZVAL_LONG(&_88$$17, tab);
							ZEPHIR_CALL_FUNCTION(&_87$$17, "str_repeat", &_9, 6, &space, &_88$$17);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_89$$17, this_ptr, "tointerpolate", NULL, 0, &message, &context);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_91$$17, &property, "getvalue", NULL, 0, variable);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_85$$17);
							ZVAL_STRING(&_85$$17, "");
							ZVAL_LONG(&_88$$17, (tab + 1));
							ZEPHIR_CALL_METHOD(&_90$$17, this_ptr, "output", &_17, 0, &_91$$17, &_85$$17, &_88$$17);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_92$$17);
							ZEPHIR_CONCAT_VVVS(&_92$$17, &_87$$17, &_89$$17, &_90$$17, "\n");
							zephir_concat_self(&output, &_92$$17);
					}
				}
				ZEPHIR_INIT_NVAR(&property);
			}
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 0, variable);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_33$$9);
		ZVAL_STRING(&_33$$9, "objectMethods");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_33$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_93$$9);
		zephir_create_array(&_93$$9, 3, 0);
		ZEPHIR_INIT_NVAR(&_33$$9);
		ZVAL_STRING(&_33$$9, "obj");
		ZEPHIR_CALL_METHOD(&_94$$9, this_ptr, "getstyle", NULL, 0, &_33$$9);
		zephir_check_call_status();
		zephir_array_update_string(&_93$$9, SL("style"), &_94$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_33$$9);
		zephir_get_class(&_33$$9, variable, 0);
		zephir_array_update_string(&_93$$9, SL("class"), &_33$$9, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_93$$9, SL("count"), zephir_fast_count_int(&attr));
		ZEPHIR_CPY_WRT(&context, &_93$$9);
		ZVAL_LONG(&_95$$9, tab);
		ZEPHIR_CALL_FUNCTION(&_94$$9, "str_repeat", &_9, 6, &space, &_95$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_96$$9, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_97$$9);
		ZEPHIR_CONCAT_VV(&_97$$9, &_94$$9, &_96$$9);
		zephir_concat_self(&output, &_97$$9);
		ZEPHIR_INIT_NVAR(&_33$$9);
		zephir_get_class(&_33$$9, variable, 0);
		zephir_read_property_cached(&_95$$9, this_ptr, _zephir_prop_1, 1352, PH_NOISY_CC | PH_READONLY);
		if (1 == zephir_fast_in_array(&_33$$9, &_95$$9)) {
			ZVAL_LONG(&_98$$18, tab);
			ZEPHIR_CALL_FUNCTION(&_99$$18, "str_repeat", &_9, 6, &space, &_98$$18);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_100$$18);
			ZEPHIR_CONCAT_VS(&_100$$18, &_99$$18, "[already listed]\n");
			zephir_concat_self(&output, &_100$$18);
		} else {
			zephir_is_iterable(&attr, 0, "phalcon/Support/Debug/Dump.zep", 425);
			if (Z_TYPE_P(&attr) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attr), _101$$19)
				{
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _101$$19);
					ZEPHIR_INIT_NVAR(&_102$$20);
					zephir_get_class(&_102$$20, variable, 0);
					zephir_update_property_array_append(this_ptr, SL("methods"), &_102$$20);
					ZEPHIR_INIT_NVAR(&_102$$20);
					ZVAL_STRING(&_102$$20, "objectMethod");
					ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_102$$20);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_103$$20);
					ZVAL_STRING(&_103$$20, "__construct");
					if (ZEPHIR_IS_IDENTICAL(&_103$$20, &value)) {
						ZEPHIR_INIT_NVAR(&_104$$21);
						ZVAL_STRING(&_104$$21, "objectMethodConstructor");
						ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_104$$21);
						zephir_check_call_status();
					}
					ZEPHIR_INIT_NVAR(&_105$$20);
					zephir_create_array(&_105$$20, 2, 0);
					ZEPHIR_INIT_NVAR(&_102$$20);
					ZVAL_STRING(&_102$$20, "obj");
					ZEPHIR_CALL_METHOD(&_106$$20, this_ptr, "getstyle", NULL, 0, &_102$$20);
					zephir_check_call_status();
					zephir_array_update_string(&_105$$20, SL("style"), &_106$$20, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_105$$20, SL("method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&context, &_105$$20);
					ZVAL_LONG(&_107$$20, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_106$$20, "str_repeat", &_9, 6, &space, &_107$$20);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_108$$20, this_ptr, "tointerpolate", NULL, 0, &message, &context);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_109$$20);
					ZEPHIR_CONCAT_VV(&_109$$20, &_106$$20, &_108$$20);
					zephir_concat_self(&output, &_109$$20);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &attr, "rewind", NULL, 0);
				zephir_check_call_status();
				_111$$19 = 1;
				while (1) {
					if (_111$$19) {
						_111$$19 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &attr, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_110$$19, &attr, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_110$$19)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&value, &attr, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_112$$22);
						zephir_get_class(&_112$$22, variable, 0);
						zephir_update_property_array_append(this_ptr, SL("methods"), &_112$$22);
						ZEPHIR_INIT_NVAR(&_112$$22);
						ZVAL_STRING(&_112$$22, "objectMethod");
						ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_112$$22);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_113$$22);
						ZVAL_STRING(&_113$$22, "__construct");
						if (ZEPHIR_IS_IDENTICAL(&_113$$22, &value)) {
							ZEPHIR_INIT_NVAR(&_114$$23);
							ZVAL_STRING(&_114$$23, "objectMethodConstructor");
							ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_114$$23);
							zephir_check_call_status();
						}
						ZEPHIR_INIT_NVAR(&_115$$22);
						zephir_create_array(&_115$$22, 2, 0);
						ZEPHIR_INIT_NVAR(&_112$$22);
						ZVAL_STRING(&_112$$22, "obj");
						ZEPHIR_CALL_METHOD(&_116$$22, this_ptr, "getstyle", NULL, 0, &_112$$22);
						zephir_check_call_status();
						zephir_array_update_string(&_115$$22, SL("style"), &_116$$22, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_115$$22, SL("method"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_CPY_WRT(&context, &_115$$22);
						ZVAL_LONG(&_117$$22, (tab + 1));
						ZEPHIR_CALL_FUNCTION(&_116$$22, "str_repeat", &_9, 6, &space, &_117$$22);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_118$$22, this_ptr, "tointerpolate", NULL, 0, &message, &context);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_119$$22);
						ZEPHIR_CONCAT_VV(&_119$$22, &_116$$22, &_118$$22);
						zephir_concat_self(&output, &_119$$22);
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_LONG(&_120$$19, tab);
			ZEPHIR_CALL_FUNCTION(&_121$$19, "str_repeat", &_9, 6, &space, &_120$$19);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_122$$19);
			ZEPHIR_CONCAT_VS(&_122$$19, &_121$$19, ")\n");
			zephir_concat_self(&output, &_122$$19);
		}
		ZVAL_LONG(&_123$$9, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_124$$9, "str_repeat", &_9, 6, &space, &_123$$9);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_124$$9, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_126$$24);
		ZVAL_STRING(&_126$$24, "Integer");
		ZEPHIR_CALL_METHOD(&_125$$24, this_ptr, "getoutputbold", NULL, 0, &_126$$24);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_126$$24);
		ZVAL_STRING(&_126$$24, "varParens");
		ZEPHIR_CALL_METHOD(&_127$$24, this_ptr, "gettemplate", NULL, 0, &_126$$24);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_125$$24, " ", &_127$$24);
		ZEPHIR_INIT_VAR(&_128$$24);
		zephir_create_array(&_128$$24, 2, 0);
		ZEPHIR_INIT_NVAR(&_126$$24);
		ZVAL_STRING(&_126$$24, "int");
		ZEPHIR_CALL_METHOD(&_129$$24, this_ptr, "getstyle", NULL, 0, &_126$$24);
		zephir_check_call_status();
		zephir_array_update_string(&_128$$24, SL("style"), &_129$$24, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_128$$24, SL("var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_128$$24);
		ZEPHIR_CALL_METHOD(&_129$$24, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_129$$24);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_DOUBLE) {
		ZEPHIR_INIT_VAR(&_131$$25);
		ZVAL_STRING(&_131$$25, "Float");
		ZEPHIR_CALL_METHOD(&_130$$25, this_ptr, "getoutputbold", NULL, 0, &_131$$25);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_131$$25);
		ZVAL_STRING(&_131$$25, "varParens");
		ZEPHIR_CALL_METHOD(&_132$$25, this_ptr, "gettemplate", NULL, 0, &_131$$25);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_130$$25, " ", &_132$$25);
		ZEPHIR_INIT_VAR(&_133$$25);
		zephir_create_array(&_133$$25, 2, 0);
		ZEPHIR_INIT_NVAR(&_131$$25);
		ZVAL_STRING(&_131$$25, "float");
		ZEPHIR_CALL_METHOD(&_134$$25, this_ptr, "getstyle", NULL, 0, &_131$$25);
		zephir_check_call_status();
		zephir_array_update_string(&_133$$25, SL("style"), &_134$$25, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_133$$25, SL("var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_133$$25);
		ZEPHIR_CALL_METHOD(&_134$$25, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_134$$25);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_136$$26);
		ZVAL_STRING(&_136$$26, "Numeric String");
		ZEPHIR_CALL_METHOD(&_135$$26, this_ptr, "getoutputbold", NULL, 0, &_136$$26);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_136$$26);
		ZVAL_STRING(&_136$$26, "lengthValue");
		ZEPHIR_CALL_METHOD(&_137$$26, this_ptr, "gettemplate", NULL, 0, &_136$$26);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_135$$26, " ", &_137$$26);
		ZEPHIR_INIT_VAR(&_138$$26);
		zephir_create_array(&_138$$26, 3, 0);
		ZEPHIR_INIT_NVAR(&_136$$26);
		ZVAL_STRING(&_136$$26, "num");
		ZEPHIR_CALL_METHOD(&_139$$26, this_ptr, "getstyle", NULL, 0, &_136$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_138$$26, SL("style"), &_139$$26, PH_COPY | PH_SEPARATE);
		zephir_cast_to_string(&_140$$26, variable);
		ZEPHIR_CALL_FUNCTION(&_139$$26, "mb_strlen", NULL, 0, &_140$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_138$$26, SL("length"), &_139$$26, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_138$$26, SL("var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_138$$26);
		ZEPHIR_CALL_METHOD(&_139$$26, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_139$$26);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_142$$27);
		ZVAL_STRING(&_142$$27, "String");
		ZEPHIR_CALL_METHOD(&_141$$27, this_ptr, "getoutputbold", NULL, 0, &_142$$27);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_142$$27);
		ZVAL_STRING(&_142$$27, "lengthValue");
		ZEPHIR_CALL_METHOD(&_143$$27, this_ptr, "gettemplate", NULL, 0, &_142$$27);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_141$$27, " ", &_143$$27);
		ZEPHIR_INIT_VAR(&_144$$27);
		zephir_create_array(&_144$$27, 3, 0);
		ZEPHIR_INIT_NVAR(&_142$$27);
		ZVAL_STRING(&_142$$27, "str");
		ZEPHIR_CALL_METHOD(&_145$$27, this_ptr, "getstyle", NULL, 0, &_142$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_144$$27, SL("style"), &_145$$27, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_145$$27, "mb_strlen", NULL, 0, variable);
		zephir_check_call_status();
		zephir_array_update_string(&_144$$27, SL("length"), &_145$$27, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_146$$27, 4);
		ZEPHIR_INIT_NVAR(&_142$$27);
		ZVAL_STRING(&_142$$27, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_145$$27, "htmlentities", NULL, 0, variable, &_146$$27, &_142$$27);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_147$$27, "nl2br", NULL, 0, &_145$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_144$$27, SL("var"), &_147$$27, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_144$$27);
		ZEPHIR_CALL_METHOD(&_147$$27, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_147$$27);
		RETURN_MM();
	}
	if (((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE) == 1)) {
		ZEPHIR_INIT_VAR(&_149$$28);
		ZVAL_STRING(&_149$$28, "Boolean");
		ZEPHIR_CALL_METHOD(&_148$$28, this_ptr, "getoutputbold", NULL, 0, &_149$$28);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_149$$28);
		ZVAL_STRING(&_149$$28, "varParens");
		ZEPHIR_CALL_METHOD(&_150$$28, this_ptr, "gettemplate", NULL, 0, &_149$$28);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_148$$28, " ", &_150$$28);
		ZEPHIR_INIT_VAR(&_151$$28);
		zephir_create_array(&_151$$28, 2, 0);
		ZEPHIR_INIT_NVAR(&_149$$28);
		ZVAL_STRING(&_149$$28, "bool");
		ZEPHIR_CALL_METHOD(&_152$$28, this_ptr, "getstyle", NULL, 0, &_149$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_151$$28, SL("style"), &_152$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_153$$28);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_153$$28);
			ZVAL_STRING(&_153$$28, "TRUE");
		} else {
			ZEPHIR_INIT_NVAR(&_153$$28);
			ZVAL_STRING(&_153$$28, "FALSE");
		}
		zephir_array_update_string(&_151$$28, SL("var"), &_153$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_151$$28);
		ZEPHIR_CALL_METHOD(&_152$$28, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_152$$28);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_154$$29);
		ZVAL_STRING(&_154$$29, "NULL");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoutputbold", NULL, 0, &_154$$29);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_155$$29);
		zephir_create_array(&_155$$29, 1, 0);
		ZEPHIR_INIT_NVAR(&_154$$29);
		ZVAL_STRING(&_154$$29, "null");
		ZEPHIR_CALL_METHOD(&_156$$29, this_ptr, "getstyle", NULL, 0, &_154$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_155$$29, SL("style"), &_156$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_155$$29);
		ZEPHIR_CALL_METHOD(&_156$$29, this_ptr, "tointerpolate", NULL, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_156$$29);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_157);
	ZVAL_STRING(&_157, "varParens");
	ZEPHIR_CALL_METHOD(&message, this_ptr, "gettemplate", NULL, 0, &_157);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_158);
	zephir_create_array(&_158, 2, 0);
	ZEPHIR_INIT_NVAR(&_157);
	ZVAL_STRING(&_157, "other");
	ZEPHIR_CALL_METHOD(&_159, this_ptr, "getstyle", NULL, 0, &_157);
	zephir_check_call_status();
	zephir_array_update_string(&_158, SL("style"), &_159, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_158, SL("var"), variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_CPY_WRT(&context, &_158);
	ZEPHIR_CALL_METHOD(&_159, this_ptr, "tointerpolate", NULL, 0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_159);
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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 1353, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value(&_1, &name_zv)) {
		zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 1353, PH_NOISY_CC | PH_READONLY);
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

