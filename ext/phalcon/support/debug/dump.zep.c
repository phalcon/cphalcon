
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
 * For the full copyright and license information, please view the LICENSE
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

	/**
	 * @phpstan-var support_debug_templates
	 */
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

	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1373, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setStyles", NULL, 0, &styles);
	zephir_check_call_status();
	if (detailed) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1374, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1374, &__$false);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1374, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1374, &__$false);
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1375, &_1);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1373, PH_NOISY_CC | PH_READONLY);
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
	ZEPHIR_CALL_METHOD(&message, this_ptr, "getTemplate", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&context);
	zephir_create_array(&context, 2, 0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "pre");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getStyle", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_array_update_string(&context, SL("style"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "output", NULL, 0, variable, &name_zv);
	zephir_check_call_status();
	zephir_array_update_string(&context, SL("output"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "toInterpolate", NULL, 0, &message, &context);
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_6$$3, this_ptr, "one", &_8, 0, &value, &_7$$3);
			zephir_check_call_status();
			zephir_concat_self(&output, &_6$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_11$$4, this_ptr, "one", &_8, 0, &value, &_12$$4);
				zephir_check_call_status();
				zephir_concat_self(&output, &_11$$4);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
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
	zend_bool _0;
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
	_0 = zephir_array_isset_fetch(&template, &defaults, &name_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		RETURN_CCTOR(&template);
	}
	RETURN_MM_STRING("");
}

/**
 * Get style for type
 */
PHP_METHOD(Phalcon_Support_Debug_Dump, getStyle)
{
	zend_bool _1;
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1375, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_fetch(&style, &_0, &type_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
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
	zend_class_entry *_83$$16, *_99$$18;
	zend_bool _26$$4, _19$$5, _20$$5, _21$$5, _33$$7, _34$$7, _35$$7, _48$$9, _49$$9, _51$$9, _116$$9, _69$$12, _97$$15, _132$$21;
	zend_ulong _9$$4, _58$$12;
	zval space, _0$$3, _17$$5, _32$$7, _63$$13, _73$$14, _162$$28;
	zval context;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL, *_6 = NULL, *_13 = NULL, *_18 = NULL, *_23 = NULL, *_44 = NULL, *_84 = NULL, *_148 = NULL, *_163 = NULL;
	zend_long tab, ZEPHIR_LAST_CALL_STATUS;
	zend_string *name = NULL, *_10$$4, *_59$$12;
	zval *variable, variable_sub, name_zv, *tab_param = NULL, attr, key, message, output, property, props, reflect, type, value, vars, _180, _181, _182, _1$$4, _3$$4, _4$$4, *_7$$4, *_8$$4, _25$$4, _38$$4, _39$$4, _11$$5, _12$$5, _14$$5, _15$$5, _16$$5, _22$$5, _24$$5, _27$$7, _28$$7, _29$$7, _30$$7, _31$$7, _36$$7, _37$$7, _40$$9, _41$$9, _42$$9, _43$$9, _50$$9, _111$$9, _112$$9, _113$$9, _114$$9, _115$$9, _144$$9, _145$$9, _45$$10, _46$$10, _47$$10, _52$$11, _53$$11, _54$$11, *_55$$12, _56$$12, *_57$$12, _68$$12, _60$$13, _61$$13, _62$$13, _64$$13, _65$$13, _66$$13, _67$$13, _70$$14, _71$$14, _72$$14, _74$$14, _75$$14, _76$$14, _77$$14, _78$$15, *_79$$15, _80$$15, *_81$$15, _96$$15, _82$$16, _85$$16, _86$$16, _87$$16, _88$$16, _92$$16, _93$$16, _94$$16, _95$$16, _89$$17, _90$$17, _91$$17, _98$$18, _100$$18, _101$$18, _102$$18, _103$$18, _107$$18, _108$$18, _109$$18, _110$$18, _104$$19, _105$$19, _106$$19, _117$$20, _118$$20, _119$$20, *_120$$21, _121$$21, *_122$$21, _131$$21, _141$$21, _142$$21, _143$$21, _123$$22, _124$$22, _126$$22, _127$$22, _128$$22, _129$$22, _130$$22, _125$$23, _133$$24, _134$$24, _136$$24, _137$$24, _138$$24, _139$$24, _140$$24, _135$$25, _146$$26, _147$$26, _149$$26, _150$$26, _151$$26, _152$$27, _153$$27, _154$$27, _155$$27, _156$$27, _157$$28, _158$$28, _159$$28, _160$$28, _161$$28, _164$$29, _165$$29, _166$$29, _167$$29, _168$$29, _169$$29, _170$$29, _171$$30, _172$$30, _173$$30, _174$$30, _175$$30, _176$$30, _177$$31, _178$$31, _179$$31;
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
	ZVAL_UNDEF(&_180);
	ZVAL_UNDEF(&_181);
	ZVAL_UNDEF(&_182);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_25$$4);
	ZVAL_UNDEF(&_38$$4);
	ZVAL_UNDEF(&_39$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_36$$7);
	ZVAL_UNDEF(&_37$$7);
	ZVAL_UNDEF(&_40$$9);
	ZVAL_UNDEF(&_41$$9);
	ZVAL_UNDEF(&_42$$9);
	ZVAL_UNDEF(&_43$$9);
	ZVAL_UNDEF(&_50$$9);
	ZVAL_UNDEF(&_111$$9);
	ZVAL_UNDEF(&_112$$9);
	ZVAL_UNDEF(&_113$$9);
	ZVAL_UNDEF(&_114$$9);
	ZVAL_UNDEF(&_115$$9);
	ZVAL_UNDEF(&_144$$9);
	ZVAL_UNDEF(&_145$$9);
	ZVAL_UNDEF(&_45$$10);
	ZVAL_UNDEF(&_46$$10);
	ZVAL_UNDEF(&_47$$10);
	ZVAL_UNDEF(&_52$$11);
	ZVAL_UNDEF(&_53$$11);
	ZVAL_UNDEF(&_54$$11);
	ZVAL_UNDEF(&_56$$12);
	ZVAL_UNDEF(&_68$$12);
	ZVAL_UNDEF(&_60$$13);
	ZVAL_UNDEF(&_61$$13);
	ZVAL_UNDEF(&_62$$13);
	ZVAL_UNDEF(&_64$$13);
	ZVAL_UNDEF(&_65$$13);
	ZVAL_UNDEF(&_66$$13);
	ZVAL_UNDEF(&_67$$13);
	ZVAL_UNDEF(&_70$$14);
	ZVAL_UNDEF(&_71$$14);
	ZVAL_UNDEF(&_72$$14);
	ZVAL_UNDEF(&_74$$14);
	ZVAL_UNDEF(&_75$$14);
	ZVAL_UNDEF(&_76$$14);
	ZVAL_UNDEF(&_77$$14);
	ZVAL_UNDEF(&_78$$15);
	ZVAL_UNDEF(&_80$$15);
	ZVAL_UNDEF(&_96$$15);
	ZVAL_UNDEF(&_82$$16);
	ZVAL_UNDEF(&_85$$16);
	ZVAL_UNDEF(&_86$$16);
	ZVAL_UNDEF(&_87$$16);
	ZVAL_UNDEF(&_88$$16);
	ZVAL_UNDEF(&_92$$16);
	ZVAL_UNDEF(&_93$$16);
	ZVAL_UNDEF(&_94$$16);
	ZVAL_UNDEF(&_95$$16);
	ZVAL_UNDEF(&_89$$17);
	ZVAL_UNDEF(&_90$$17);
	ZVAL_UNDEF(&_91$$17);
	ZVAL_UNDEF(&_98$$18);
	ZVAL_UNDEF(&_100$$18);
	ZVAL_UNDEF(&_101$$18);
	ZVAL_UNDEF(&_102$$18);
	ZVAL_UNDEF(&_103$$18);
	ZVAL_UNDEF(&_107$$18);
	ZVAL_UNDEF(&_108$$18);
	ZVAL_UNDEF(&_109$$18);
	ZVAL_UNDEF(&_110$$18);
	ZVAL_UNDEF(&_104$$19);
	ZVAL_UNDEF(&_105$$19);
	ZVAL_UNDEF(&_106$$19);
	ZVAL_UNDEF(&_117$$20);
	ZVAL_UNDEF(&_118$$20);
	ZVAL_UNDEF(&_119$$20);
	ZVAL_UNDEF(&_121$$21);
	ZVAL_UNDEF(&_131$$21);
	ZVAL_UNDEF(&_141$$21);
	ZVAL_UNDEF(&_142$$21);
	ZVAL_UNDEF(&_143$$21);
	ZVAL_UNDEF(&_123$$22);
	ZVAL_UNDEF(&_124$$22);
	ZVAL_UNDEF(&_126$$22);
	ZVAL_UNDEF(&_127$$22);
	ZVAL_UNDEF(&_128$$22);
	ZVAL_UNDEF(&_129$$22);
	ZVAL_UNDEF(&_130$$22);
	ZVAL_UNDEF(&_125$$23);
	ZVAL_UNDEF(&_133$$24);
	ZVAL_UNDEF(&_134$$24);
	ZVAL_UNDEF(&_136$$24);
	ZVAL_UNDEF(&_137$$24);
	ZVAL_UNDEF(&_138$$24);
	ZVAL_UNDEF(&_139$$24);
	ZVAL_UNDEF(&_140$$24);
	ZVAL_UNDEF(&_135$$25);
	ZVAL_UNDEF(&_146$$26);
	ZVAL_UNDEF(&_147$$26);
	ZVAL_UNDEF(&_149$$26);
	ZVAL_UNDEF(&_150$$26);
	ZVAL_UNDEF(&_151$$26);
	ZVAL_UNDEF(&_152$$27);
	ZVAL_UNDEF(&_153$$27);
	ZVAL_UNDEF(&_154$$27);
	ZVAL_UNDEF(&_155$$27);
	ZVAL_UNDEF(&_156$$27);
	ZVAL_UNDEF(&_157$$28);
	ZVAL_UNDEF(&_158$$28);
	ZVAL_UNDEF(&_159$$28);
	ZVAL_UNDEF(&_160$$28);
	ZVAL_UNDEF(&_161$$28);
	ZVAL_UNDEF(&_164$$29);
	ZVAL_UNDEF(&_165$$29);
	ZVAL_UNDEF(&_166$$29);
	ZVAL_UNDEF(&_167$$29);
	ZVAL_UNDEF(&_168$$29);
	ZVAL_UNDEF(&_169$$29);
	ZVAL_UNDEF(&_170$$29);
	ZVAL_UNDEF(&_171$$30);
	ZVAL_UNDEF(&_172$$30);
	ZVAL_UNDEF(&_173$$30);
	ZVAL_UNDEF(&_174$$30);
	ZVAL_UNDEF(&_175$$30);
	ZVAL_UNDEF(&_176$$30);
	ZVAL_UNDEF(&_177$$31);
	ZVAL_UNDEF(&_178$$31);
	ZVAL_UNDEF(&_179$$31);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&space);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_32$$7);
	ZVAL_UNDEF(&_63$$13);
	ZVAL_UNDEF(&_73$$14);
	ZVAL_UNDEF(&_162$$28);
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
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&output, &_0$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (Z_TYPE_P(variable) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "arrayHeader");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getTemplate", &_2, 0, &_1$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_create_array(&_3$$4, 2, 0);
		ZEPHIR_INIT_NVAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "arr");
		ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "getStyle", &_5, 0, &_1$$4);
		zephir_check_call_status();
		zephir_array_update_string(&_3$$4, SL("style"), &_4$$4, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_3$$4, SL("count"), zephir_fast_count_int(variable));
		ZEPHIR_CPY_WRT(&context, &_3$$4);
		ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "toInterpolate", &_6, 0, &message, &context);
		zephir_check_call_status();
		zephir_concat_self(&output, &_4$$4);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(variable) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_1$$4);
			zephir_string_to_char_array(&_1$$4, variable);
			_7$$4 = &_1$$4;
		} else {
			_7$$4 = variable;
		}
		zephir_is_iterable(_7$$4, 0, "phalcon/Support/Debug/Dump.zep", 322);
		if (Z_TYPE_P(_7$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_7$$4), _9$$4, _10$$4, _8$$4)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_10$$4 != NULL) { 
					ZVAL_STR_COPY(&key, _10$$4);
				} else {
					ZVAL_LONG(&key, _9$$4);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _8$$4);
				ZVAL_LONG(&_11$$5, tab);
				ZEPHIR_CALL_FUNCTION(&_12$$5, "str_repeat", &_13, 5, &space, &_11$$5);
				zephir_check_call_status();
				zephir_concat_self(&output, &_12$$5);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_14$$5);
				ZVAL_STRING(&_14$$5, "arrayKey");
				ZEPHIR_CALL_METHOD(&message, this_ptr, "getTemplate", &_2, 0, &_14$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_15$$5);
				zephir_create_array(&_15$$5, 2, 0);
				ZEPHIR_INIT_NVAR(&_14$$5);
				ZVAL_STRING(&_14$$5, "arr");
				ZEPHIR_CALL_METHOD(&_16$$5, this_ptr, "getStyle", &_5, 0, &_14$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_15$$5, SL("style"), &_16$$5, PH_COPY | PH_SEPARATE);
				zephir_cast_to_string(&_17$$5, &key);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZVAL_LONG(&_11$$5, 3);
				ZEPHIR_INIT_NVAR(&_14$$5);
				ZVAL_STRING(&_14$$5, "utf-8");
				ZEPHIR_CALL_FUNCTION(&_16$$5, "htmlspecialchars", &_18, 199, &_17$$5, &_11$$5, &_14$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_15$$5, SL("key"), &_16$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&context, &_15$$5);
				ZEPHIR_CALL_METHOD(&_16$$5, this_ptr, "toInterpolate", &_6, 0, &message, &context);
				zephir_check_call_status();
				zephir_concat_self(&output, &_16$$5);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_19$$5 = 1 == tab;
				if (_19$$5) {
					_19$$5 = !(ZEPHIR_IS_EMPTY(&name_zv));
				}
				_20$$5 = _19$$5;
				if (_20$$5) {
					_20$$5 = Z_TYPE_P(&key) != IS_LONG;
				}
				_21$$5 = _20$$5;
				if (_21$$5) {
					_21$$5 = ZEPHIR_IS_IDENTICAL(&name_zv, &key);
				}
				if (_21$$5) {
					zephir_concat_self_str(&output, SL("\n"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				ZEPHIR_INIT_NVAR(&_14$$5);
				ZVAL_STRING(&_14$$5, "");
				ZVAL_LONG(&_11$$5, (tab + 1));
				ZEPHIR_CALL_METHOD(&_22$$5, this_ptr, "output", &_23, 0, &value, &_14$$5, &_11$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_24$$5);
				ZEPHIR_CONCAT_VS(&_24$$5, &_22$$5, "\n");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&output, &_24$$5);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _7$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			_26$$4 = 1;
			while (1) {
				if (_26$$4) {
					_26$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _7$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_25$$4, _7$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_25$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, _7$$4, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, _7$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZVAL_LONG(&_27$$7, tab);
					ZEPHIR_CALL_FUNCTION(&_28$$7, "str_repeat", &_13, 5, &space, &_27$$7);
					zephir_check_call_status();
					zephir_concat_self(&output, &_28$$7);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_29$$7);
					ZVAL_STRING(&_29$$7, "arrayKey");
					ZEPHIR_CALL_METHOD(&message, this_ptr, "getTemplate", &_2, 0, &_29$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_30$$7);
					zephir_create_array(&_30$$7, 2, 0);
					ZEPHIR_INIT_NVAR(&_29$$7);
					ZVAL_STRING(&_29$$7, "arr");
					ZEPHIR_CALL_METHOD(&_31$$7, this_ptr, "getStyle", &_5, 0, &_29$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_30$$7, SL("style"), &_31$$7, PH_COPY | PH_SEPARATE);
					zephir_cast_to_string(&_32$$7, &key);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZVAL_LONG(&_27$$7, 3);
					ZEPHIR_INIT_NVAR(&_29$$7);
					ZVAL_STRING(&_29$$7, "utf-8");
					ZEPHIR_CALL_FUNCTION(&_31$$7, "htmlspecialchars", &_18, 199, &_32$$7, &_27$$7, &_29$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_30$$7, SL("key"), &_31$$7, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&context, &_30$$7);
					ZEPHIR_CALL_METHOD(&_31$$7, this_ptr, "toInterpolate", &_6, 0, &message, &context);
					zephir_check_call_status();
					zephir_concat_self(&output, &_31$$7);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_33$$7 = 1 == tab;
					if (_33$$7) {
						_33$$7 = !(ZEPHIR_IS_EMPTY(&name_zv));
					}
					_34$$7 = _33$$7;
					if (_34$$7) {
						_34$$7 = Z_TYPE_P(&key) != IS_LONG;
					}
					_35$$7 = _34$$7;
					if (_35$$7) {
						_35$$7 = ZEPHIR_IS_IDENTICAL(&name_zv, &key);
					}
					if (_35$$7) {
						zephir_concat_self_str(&output, SL("\n"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					ZEPHIR_INIT_NVAR(&_29$$7);
					ZVAL_STRING(&_29$$7, "");
					ZVAL_LONG(&_27$$7, (tab + 1));
					ZEPHIR_CALL_METHOD(&_36$$7, this_ptr, "output", &_23, 0, &value, &_29$$7, &_27$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_37$$7);
					ZEPHIR_CONCAT_VS(&_37$$7, &_36$$7, "\n");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&output, &_37$$7);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_38$$4, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_39$$4, "str_repeat", &_13, 5, &space, &_38$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_39$$4, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_40$$9);
		ZVAL_STRING(&_40$$9, "objectHeader");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getTemplate", &_2, 0, &_40$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_41$$9);
		zephir_create_array(&_41$$9, 2, 0);
		ZEPHIR_INIT_NVAR(&_40$$9);
		ZVAL_STRING(&_40$$9, "obj");
		ZEPHIR_CALL_METHOD(&_42$$9, this_ptr, "getStyle", &_5, 0, &_40$$9);
		zephir_check_call_status();
		zephir_array_update_string(&_41$$9, SL("style"), &_42$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_40$$9);
		zephir_get_class(&_40$$9, variable, 0);
		zephir_array_update_string(&_41$$9, SL("class"), &_40$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_41$$9);
		ZEPHIR_CALL_METHOD(&_42$$9, this_ptr, "toInterpolate", &_6, 0, &message, &context);
		zephir_check_call_status();
		zephir_concat_self(&output, &_42$$9);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_FUNCTION(&_43$$9, "get_parent_class", &_44, 0, variable);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_43$$9)) {
			ZEPHIR_INIT_VAR(&_45$$10);
			ZVAL_STRING(&_45$$10, "objectExtends");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getTemplate", &_2, 0, &_45$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_46$$10);
			zephir_create_array(&_46$$10, 2, 0);
			ZEPHIR_INIT_NVAR(&_45$$10);
			ZVAL_STRING(&_45$$10, "obj");
			ZEPHIR_CALL_METHOD(&_47$$10, this_ptr, "getStyle", &_5, 0, &_45$$10);
			zephir_check_call_status();
			zephir_array_update_string(&_46$$10, SL("style"), &_47$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_47$$10, "get_parent_class", &_44, 0, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_46$$10, SL("parent"), &_47$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&context, &_46$$10);
			ZEPHIR_CALL_METHOD(&_47$$10, this_ptr, "toInterpolate", &_6, 0, &message, &context);
			zephir_check_call_status();
			zephir_concat_self(&output, &_47$$10);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_concat_self_str(&output, SL(" (\n"));
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_48$$9 = Z_TYPE_P(variable) == IS_OBJECT;
		if (_48$$9) {
			_49$$9 = zephir_instance_of_ev(variable, phalcon_di_diinterface_ce);
			if (!(_49$$9)) {
				_49$$9 = zephir_instance_of_ev(variable, phalcon_container_container_ce);
			}
			_48$$9 = _49$$9;
		}
		if (_48$$9) {
			ZVAL_LONG(&_52$$11, tab);
			ZEPHIR_CALL_FUNCTION(&_53$$11, "str_repeat", &_13, 5, &space, &_52$$11);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_54$$11);
			ZEPHIR_CONCAT_VS(&_54$$11, &_53$$11, "[skipped]\n");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_concat_self(&output, &_54$$11);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			zephir_read_property_cached(&_50$$9, this_ptr, _zephir_prop_0, 1374, PH_NOISY_CC | PH_READONLY);
			_51$$9 = !ZEPHIR_IS_TRUE_IDENTICAL(&_50$$9);
			if (!(_51$$9)) {
				_51$$9 = zephir_is_instance_of(variable, SL("stdClass"));
			}
			if (_51$$9) {
				ZEPHIR_CALL_FUNCTION(&vars, "get_object_vars", NULL, 358, variable);
				zephir_check_call_status();
				if (Z_TYPE_P(&vars) == IS_STRING) {
					ZEPHIR_INIT_VAR(&_56$$12);
					zephir_string_to_char_array(&_56$$12, &vars);
					_55$$12 = &_56$$12;
				} else {
					_55$$12 = &vars;
				}
				zephir_is_iterable(_55$$12, 0, "phalcon/Support/Debug/Dump.zep", 366);
				if (Z_TYPE_P(_55$$12) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_55$$12), _58$$12, _59$$12, _57$$12)
					{
						ZEPHIR_INIT_NVAR(&key);
						if (_59$$12 != NULL) { 
							ZVAL_STR_COPY(&key, _59$$12);
						} else {
							ZVAL_LONG(&key, _58$$12);
						}
						ZEPHIR_INIT_NVAR(&value);
						ZVAL_COPY(&value, _57$$12);
						ZEPHIR_INIT_NVAR(&_60$$13);
						ZVAL_STRING(&_60$$13, "objectProperty");
						ZEPHIR_CALL_METHOD(&message, this_ptr, "getTemplate", &_2, 0, &_60$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_61$$13);
						zephir_create_array(&_61$$13, 3, 0);
						ZEPHIR_INIT_NVAR(&_60$$13);
						ZVAL_STRING(&_60$$13, "obj");
						ZEPHIR_CALL_METHOD(&_62$$13, this_ptr, "getStyle", &_5, 0, &_60$$13);
						zephir_check_call_status();
						zephir_array_update_string(&_61$$13, SL("style"), &_62$$13, PH_COPY | PH_SEPARATE);
						zephir_cast_to_string(&_63$$13, &key);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZVAL_LONG(&_64$$13, 3);
						ZEPHIR_INIT_NVAR(&_60$$13);
						ZVAL_STRING(&_60$$13, "utf-8");
						ZEPHIR_CALL_FUNCTION(&_62$$13, "htmlspecialchars", &_18, 199, &_63$$13, &_64$$13, &_60$$13);
						zephir_check_call_status();
						zephir_array_update_string(&_61$$13, SL("key"), &_62$$13, PH_COPY | PH_SEPARATE);
						add_assoc_stringl_ex(&_61$$13, SL("type"), SL("public"));
						ZEPHIR_CPY_WRT(&context, &_61$$13);
						ZVAL_LONG(&_64$$13, tab);
						ZEPHIR_CALL_FUNCTION(&_62$$13, "str_repeat", &_13, 5, &space, &_64$$13);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_65$$13, this_ptr, "toInterpolate", &_6, 0, &message, &context);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_60$$13);
						ZVAL_STRING(&_60$$13, "");
						ZVAL_LONG(&_64$$13, (tab + 1));
						ZEPHIR_CALL_METHOD(&_66$$13, this_ptr, "output", &_23, 0, &value, &_60$$13, &_64$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_67$$13);
						ZEPHIR_CONCAT_VVVS(&_67$$13, &_62$$13, &_65$$13, &_66$$13, "\n");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&output, &_67$$13);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _55$$12, "rewind", NULL, 0);
					zephir_check_call_status();
					_69$$12 = 1;
					while (1) {
						if (_69$$12) {
							_69$$12 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _55$$12, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_68$$12, _55$$12, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_68$$12)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&key, _55$$12, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&value, _55$$12, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_70$$14);
							ZVAL_STRING(&_70$$14, "objectProperty");
							ZEPHIR_CALL_METHOD(&message, this_ptr, "getTemplate", &_2, 0, &_70$$14);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_71$$14);
							zephir_create_array(&_71$$14, 3, 0);
							ZEPHIR_INIT_NVAR(&_70$$14);
							ZVAL_STRING(&_70$$14, "obj");
							ZEPHIR_CALL_METHOD(&_72$$14, this_ptr, "getStyle", &_5, 0, &_70$$14);
							zephir_check_call_status();
							zephir_array_update_string(&_71$$14, SL("style"), &_72$$14, PH_COPY | PH_SEPARATE);
							zephir_cast_to_string(&_73$$14, &key);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZVAL_LONG(&_74$$14, 3);
							ZEPHIR_INIT_NVAR(&_70$$14);
							ZVAL_STRING(&_70$$14, "utf-8");
							ZEPHIR_CALL_FUNCTION(&_72$$14, "htmlspecialchars", &_18, 199, &_73$$14, &_74$$14, &_70$$14);
							zephir_check_call_status();
							zephir_array_update_string(&_71$$14, SL("key"), &_72$$14, PH_COPY | PH_SEPARATE);
							add_assoc_stringl_ex(&_71$$14, SL("type"), SL("public"));
							ZEPHIR_CPY_WRT(&context, &_71$$14);
							ZVAL_LONG(&_74$$14, tab);
							ZEPHIR_CALL_FUNCTION(&_72$$14, "str_repeat", &_13, 5, &space, &_74$$14);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_75$$14, this_ptr, "toInterpolate", &_6, 0, &message, &context);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_70$$14);
							ZVAL_STRING(&_70$$14, "");
							ZVAL_LONG(&_74$$14, (tab + 1));
							ZEPHIR_CALL_METHOD(&_76$$14, this_ptr, "output", &_23, 0, &value, &_70$$14, &_74$$14);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_77$$14);
							ZEPHIR_CONCAT_VVVS(&_77$$14, &_72$$14, &_75$$14, &_76$$14, "\n");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_concat_self(&output, &_77$$14);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&value);
				ZEPHIR_INIT_NVAR(&key);
			} else {
				ZEPHIR_INIT_VAR(&reflect);
				object_init_ex(&reflect, zephir_get_internal_ce(SL("reflectionclass")));
				ZEPHIR_CALL_METHOD(NULL, &reflect, "__construct", NULL, 253, variable);
				zephir_check_call_status();
				ZVAL_LONG(&_78$$15, ((1 | 2) | 4));
				ZEPHIR_CALL_METHOD(&props, &reflect, "getProperties", NULL, 369, &_78$$15);
				zephir_check_call_status();
				if (Z_TYPE_P(&props) == IS_STRING) {
					ZEPHIR_INIT_VAR(&_80$$15);
					zephir_string_to_char_array(&_80$$15, &props);
					_79$$15 = &_80$$15;
				} else {
					_79$$15 = &props;
				}
				zephir_is_iterable(_79$$15, 0, "phalcon/Support/Debug/Dump.zep", 402);
				if (Z_TYPE_P(_79$$15) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_79$$15), _81$$15)
					{
						ZEPHIR_INIT_NVAR(&property);
						ZVAL_COPY(&property, _81$$15);
						ZEPHIR_CALL_METHOD(&key, &property, "getName", NULL, 0);
						zephir_check_call_status();
						_83$$16 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
						ZEPHIR_CALL_METHOD(&_85$$16, &property, "getModifiers", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_CE_STATIC(&_82$$16, _83$$16, "getModifierNames", &_84, 0, &_85$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&type);
						zephir_fast_join_str(&type, SL(" "), &_82$$16);
						ZEPHIR_INIT_NVAR(&_86$$16);
						ZVAL_STRING(&_86$$16, "objectProperty");
						ZEPHIR_CALL_METHOD(&message, this_ptr, "getTemplate", &_2, 0, &_86$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_87$$16);
						zephir_create_array(&_87$$16, 3, 0);
						ZEPHIR_INIT_NVAR(&_86$$16);
						ZVAL_STRING(&_86$$16, "obj");
						ZEPHIR_CALL_METHOD(&_88$$16, this_ptr, "getStyle", &_5, 0, &_86$$16);
						zephir_check_call_status();
						zephir_array_update_string(&_87$$16, SL("style"), &_88$$16, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_87$$16, SL("key"), &key, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_87$$16, SL("type"), &type, PH_COPY | PH_SEPARATE);
						ZEPHIR_CPY_WRT(&context, &_87$$16);
						ZEPHIR_INIT_NVAR(&value);
						ZVAL_STRING(&value, "[uninitialized]");
						ZEPHIR_CALL_METHOD(&_88$$16, &property, "isInitialized", NULL, 0, variable);
						zephir_check_call_status();
						if (ZEPHIR_IS_TRUE_IDENTICAL(&_88$$16)) {
							ZEPHIR_CALL_METHOD(&_89$$17, &property, "getValue", NULL, 0, variable);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_90$$17);
							ZVAL_STRING(&_90$$17, "");
							ZVAL_LONG(&_91$$17, (tab + 1));
							ZEPHIR_CALL_METHOD(&value, this_ptr, "output", &_23, 0, &_89$$17, &_90$$17, &_91$$17);
							zephir_check_call_status();
						}
						ZVAL_LONG(&_92$$16, tab);
						ZEPHIR_CALL_FUNCTION(&_93$$16, "str_repeat", &_13, 5, &space, &_92$$16);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_94$$16, this_ptr, "toInterpolate", &_6, 0, &message, &context);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_95$$16);
						ZEPHIR_CONCAT_VVVS(&_95$$16, &_93$$16, &_94$$16, &value, "\n");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&output, &_95$$16);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _79$$15, "rewind", NULL, 0);
					zephir_check_call_status();
					_97$$15 = 1;
					while (1) {
						if (_97$$15) {
							_97$$15 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _79$$15, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_96$$15, _79$$15, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_96$$15)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&property, _79$$15, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&key, &property, "getName", NULL, 0);
							zephir_check_call_status();
							_99$$18 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
							ZEPHIR_CALL_METHOD(&_100$$18, &property, "getModifiers", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_CE_STATIC(&_98$$18, _99$$18, "getModifierNames", &_84, 0, &_100$$18);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&type);
							zephir_fast_join_str(&type, SL(" "), &_98$$18);
							ZEPHIR_INIT_NVAR(&_101$$18);
							ZVAL_STRING(&_101$$18, "objectProperty");
							ZEPHIR_CALL_METHOD(&message, this_ptr, "getTemplate", &_2, 0, &_101$$18);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_102$$18);
							zephir_create_array(&_102$$18, 3, 0);
							ZEPHIR_INIT_NVAR(&_101$$18);
							ZVAL_STRING(&_101$$18, "obj");
							ZEPHIR_CALL_METHOD(&_103$$18, this_ptr, "getStyle", &_5, 0, &_101$$18);
							zephir_check_call_status();
							zephir_array_update_string(&_102$$18, SL("style"), &_103$$18, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_102$$18, SL("key"), &key, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_102$$18, SL("type"), &type, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&context, &_102$$18);
							ZEPHIR_INIT_NVAR(&value);
							ZVAL_STRING(&value, "[uninitialized]");
							ZEPHIR_CALL_METHOD(&_103$$18, &property, "isInitialized", NULL, 0, variable);
							zephir_check_call_status();
							if (ZEPHIR_IS_TRUE_IDENTICAL(&_103$$18)) {
								ZEPHIR_CALL_METHOD(&_104$$19, &property, "getValue", NULL, 0, variable);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_105$$19);
								ZVAL_STRING(&_105$$19, "");
								ZVAL_LONG(&_106$$19, (tab + 1));
								ZEPHIR_CALL_METHOD(&value, this_ptr, "output", &_23, 0, &_104$$19, &_105$$19, &_106$$19);
								zephir_check_call_status();
							}
							ZVAL_LONG(&_107$$18, tab);
							ZEPHIR_CALL_FUNCTION(&_108$$18, "str_repeat", &_13, 5, &space, &_107$$18);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_109$$18, this_ptr, "toInterpolate", &_6, 0, &message, &context);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_110$$18);
							ZEPHIR_CONCAT_VVVS(&_110$$18, &_108$$18, &_109$$18, &value, "\n");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_concat_self(&output, &_110$$18);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&property);
			}
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 0, variable);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_40$$9);
		ZVAL_STRING(&_40$$9, "objectMethods");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getTemplate", &_2, 0, &_40$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_111$$9);
		zephir_create_array(&_111$$9, 3, 0);
		ZEPHIR_INIT_NVAR(&_40$$9);
		ZVAL_STRING(&_40$$9, "obj");
		ZEPHIR_CALL_METHOD(&_112$$9, this_ptr, "getStyle", &_5, 0, &_40$$9);
		zephir_check_call_status();
		zephir_array_update_string(&_111$$9, SL("style"), &_112$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_40$$9);
		zephir_get_class(&_40$$9, variable, 0);
		zephir_array_update_string(&_111$$9, SL("class"), &_40$$9, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_111$$9, SL("count"), zephir_fast_count_int(&attr));
		ZEPHIR_CPY_WRT(&context, &_111$$9);
		ZVAL_LONG(&_113$$9, tab);
		ZEPHIR_CALL_FUNCTION(&_112$$9, "str_repeat", &_13, 5, &space, &_113$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_114$$9, this_ptr, "toInterpolate", &_6, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_115$$9);
		ZEPHIR_CONCAT_VV(&_115$$9, &_112$$9, &_114$$9);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&output, &_115$$9);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&_40$$9);
		zephir_get_class(&_40$$9, variable, 0);
		zephir_read_property_cached(&_113$$9, this_ptr, _zephir_prop_1, 1376, PH_NOISY_CC | PH_READONLY);
		_116$$9 = zephir_fast_in_array(&_40$$9, &_113$$9);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (1 == _116$$9) {
			ZVAL_LONG(&_117$$20, tab);
			ZEPHIR_CALL_FUNCTION(&_118$$20, "str_repeat", &_13, 5, &space, &_117$$20);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_119$$20);
			ZEPHIR_CONCAT_VS(&_119$$20, &_118$$20, "[already listed]\n");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_concat_self(&output, &_119$$20);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			if (Z_TYPE_P(&attr) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_121$$21);
				zephir_string_to_char_array(&_121$$21, &attr);
				_120$$21 = &_121$$21;
			} else {
				_120$$21 = &attr;
			}
			zephir_is_iterable(_120$$21, 0, "phalcon/Support/Debug/Dump.zep", 435);
			if (Z_TYPE_P(_120$$21) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_120$$21), _122$$21)
				{
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _122$$21);
					ZEPHIR_INIT_NVAR(&_123$$22);
					zephir_get_class(&_123$$22, variable, 0);
					zephir_update_property_array_append(this_ptr, SL("methods"), &_123$$22);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_123$$22);
					ZVAL_STRING(&_123$$22, "objectMethod");
					ZEPHIR_CALL_METHOD(&message, this_ptr, "getTemplate", &_2, 0, &_123$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_124$$22);
					ZVAL_STRING(&_124$$22, "__construct");
					if (ZEPHIR_IS_IDENTICAL(&_124$$22, &value)) {
						ZEPHIR_INIT_NVAR(&_125$$23);
						ZVAL_STRING(&_125$$23, "objectMethodConstructor");
						ZEPHIR_CALL_METHOD(&message, this_ptr, "getTemplate", &_2, 0, &_125$$23);
						zephir_check_call_status();
					}
					ZEPHIR_INIT_NVAR(&_126$$22);
					zephir_create_array(&_126$$22, 2, 0);
					ZEPHIR_INIT_NVAR(&_123$$22);
					ZVAL_STRING(&_123$$22, "obj");
					ZEPHIR_CALL_METHOD(&_127$$22, this_ptr, "getStyle", &_5, 0, &_123$$22);
					zephir_check_call_status();
					zephir_array_update_string(&_126$$22, SL("style"), &_127$$22, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_126$$22, SL("method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&context, &_126$$22);
					ZVAL_LONG(&_128$$22, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_127$$22, "str_repeat", &_13, 5, &space, &_128$$22);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_129$$22, this_ptr, "toInterpolate", &_6, 0, &message, &context);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_130$$22);
					ZEPHIR_CONCAT_VV(&_130$$22, &_127$$22, &_129$$22);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&output, &_130$$22);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _120$$21, "rewind", NULL, 0);
				zephir_check_call_status();
				_132$$21 = 1;
				while (1) {
					if (_132$$21) {
						_132$$21 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _120$$21, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_131$$21, _120$$21, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_131$$21)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&value, _120$$21, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_133$$24);
						zephir_get_class(&_133$$24, variable, 0);
						zephir_update_property_array_append(this_ptr, SL("methods"), &_133$$24);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_133$$24);
						ZVAL_STRING(&_133$$24, "objectMethod");
						ZEPHIR_CALL_METHOD(&message, this_ptr, "getTemplate", &_2, 0, &_133$$24);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_134$$24);
						ZVAL_STRING(&_134$$24, "__construct");
						if (ZEPHIR_IS_IDENTICAL(&_134$$24, &value)) {
							ZEPHIR_INIT_NVAR(&_135$$25);
							ZVAL_STRING(&_135$$25, "objectMethodConstructor");
							ZEPHIR_CALL_METHOD(&message, this_ptr, "getTemplate", &_2, 0, &_135$$25);
							zephir_check_call_status();
						}
						ZEPHIR_INIT_NVAR(&_136$$24);
						zephir_create_array(&_136$$24, 2, 0);
						ZEPHIR_INIT_NVAR(&_133$$24);
						ZVAL_STRING(&_133$$24, "obj");
						ZEPHIR_CALL_METHOD(&_137$$24, this_ptr, "getStyle", &_5, 0, &_133$$24);
						zephir_check_call_status();
						zephir_array_update_string(&_136$$24, SL("style"), &_137$$24, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_136$$24, SL("method"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_CPY_WRT(&context, &_136$$24);
						ZVAL_LONG(&_138$$24, (tab + 1));
						ZEPHIR_CALL_FUNCTION(&_137$$24, "str_repeat", &_13, 5, &space, &_138$$24);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_139$$24, this_ptr, "toInterpolate", &_6, 0, &message, &context);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_140$$24);
						ZEPHIR_CONCAT_VV(&_140$$24, &_137$$24, &_139$$24);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&output, &_140$$24);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_LONG(&_141$$21, tab);
			ZEPHIR_CALL_FUNCTION(&_142$$21, "str_repeat", &_13, 5, &space, &_141$$21);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_143$$21);
			ZEPHIR_CONCAT_VS(&_143$$21, &_142$$21, ")\n");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_concat_self(&output, &_143$$21);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZVAL_LONG(&_144$$9, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_145$$9, "str_repeat", &_13, 5, &space, &_144$$9);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_145$$9, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_147$$26);
		ZVAL_STRING(&_147$$26, "Integer");
		ZEPHIR_CALL_METHOD(&_146$$26, this_ptr, "getOutputBold", &_148, 0, &_147$$26);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_147$$26);
		ZVAL_STRING(&_147$$26, "varParens");
		ZEPHIR_CALL_METHOD(&_149$$26, this_ptr, "getTemplate", &_2, 0, &_147$$26);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_146$$26, " ", &_149$$26);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_150$$26);
		zephir_create_array(&_150$$26, 2, 0);
		ZEPHIR_INIT_NVAR(&_147$$26);
		ZVAL_STRING(&_147$$26, "int");
		ZEPHIR_CALL_METHOD(&_151$$26, this_ptr, "getStyle", &_5, 0, &_147$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_150$$26, SL("style"), &_151$$26, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_150$$26, SL("var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_150$$26);
		ZEPHIR_CALL_METHOD(&_151$$26, this_ptr, "toInterpolate", &_6, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_151$$26);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_DOUBLE) {
		ZEPHIR_INIT_VAR(&_153$$27);
		ZVAL_STRING(&_153$$27, "Float");
		ZEPHIR_CALL_METHOD(&_152$$27, this_ptr, "getOutputBold", &_148, 0, &_153$$27);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_153$$27);
		ZVAL_STRING(&_153$$27, "varParens");
		ZEPHIR_CALL_METHOD(&_154$$27, this_ptr, "getTemplate", &_2, 0, &_153$$27);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_152$$27, " ", &_154$$27);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_155$$27);
		zephir_create_array(&_155$$27, 2, 0);
		ZEPHIR_INIT_NVAR(&_153$$27);
		ZVAL_STRING(&_153$$27, "float");
		ZEPHIR_CALL_METHOD(&_156$$27, this_ptr, "getStyle", &_5, 0, &_153$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_155$$27, SL("style"), &_156$$27, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_155$$27, SL("var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_155$$27);
		ZEPHIR_CALL_METHOD(&_156$$27, this_ptr, "toInterpolate", &_6, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_156$$27);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_158$$28);
		ZVAL_STRING(&_158$$28, "Numeric String");
		ZEPHIR_CALL_METHOD(&_157$$28, this_ptr, "getOutputBold", &_148, 0, &_158$$28);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_158$$28);
		ZVAL_STRING(&_158$$28, "lengthValue");
		ZEPHIR_CALL_METHOD(&_159$$28, this_ptr, "getTemplate", &_2, 0, &_158$$28);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_157$$28, " ", &_159$$28);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_160$$28);
		zephir_create_array(&_160$$28, 3, 0);
		ZEPHIR_INIT_NVAR(&_158$$28);
		ZVAL_STRING(&_158$$28, "num");
		ZEPHIR_CALL_METHOD(&_161$$28, this_ptr, "getStyle", &_5, 0, &_158$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_160$$28, SL("style"), &_161$$28, PH_COPY | PH_SEPARATE);
		zephir_cast_to_string(&_162$$28, variable);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_FUNCTION(&_161$$28, "mb_strlen", &_163, 0, &_162$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_160$$28, SL("length"), &_161$$28, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_160$$28, SL("var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_160$$28);
		ZEPHIR_CALL_METHOD(&_161$$28, this_ptr, "toInterpolate", &_6, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_161$$28);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_165$$29);
		ZVAL_STRING(&_165$$29, "String");
		ZEPHIR_CALL_METHOD(&_164$$29, this_ptr, "getOutputBold", &_148, 0, &_165$$29);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_165$$29);
		ZVAL_STRING(&_165$$29, "lengthValue");
		ZEPHIR_CALL_METHOD(&_166$$29, this_ptr, "getTemplate", &_2, 0, &_165$$29);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_164$$29, " ", &_166$$29);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_167$$29);
		zephir_create_array(&_167$$29, 3, 0);
		ZEPHIR_INIT_NVAR(&_165$$29);
		ZVAL_STRING(&_165$$29, "str");
		ZEPHIR_CALL_METHOD(&_168$$29, this_ptr, "getStyle", &_5, 0, &_165$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_167$$29, SL("style"), &_168$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_168$$29, "mb_strlen", &_163, 0, variable);
		zephir_check_call_status();
		zephir_array_update_string(&_167$$29, SL("length"), &_168$$29, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_169$$29, 4);
		ZEPHIR_INIT_NVAR(&_165$$29);
		ZVAL_STRING(&_165$$29, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_168$$29, "htmlentities", NULL, 0, variable, &_169$$29, &_165$$29);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_170$$29, "nl2br", NULL, 0, &_168$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_167$$29, SL("var"), &_170$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_167$$29);
		ZEPHIR_CALL_METHOD(&_170$$29, this_ptr, "toInterpolate", &_6, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_170$$29);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	if (((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE) == 1)) {
		ZEPHIR_INIT_VAR(&_172$$30);
		ZVAL_STRING(&_172$$30, "Boolean");
		ZEPHIR_CALL_METHOD(&_171$$30, this_ptr, "getOutputBold", &_148, 0, &_172$$30);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_172$$30);
		ZVAL_STRING(&_172$$30, "varParens");
		ZEPHIR_CALL_METHOD(&_173$$30, this_ptr, "getTemplate", &_2, 0, &_172$$30);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_171$$30, " ", &_173$$30);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_174$$30);
		zephir_create_array(&_174$$30, 2, 0);
		ZEPHIR_INIT_NVAR(&_172$$30);
		ZVAL_STRING(&_172$$30, "bool");
		ZEPHIR_CALL_METHOD(&_175$$30, this_ptr, "getStyle", &_5, 0, &_172$$30);
		zephir_check_call_status();
		zephir_array_update_string(&_174$$30, SL("style"), &_175$$30, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_176$$30);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_176$$30);
			ZVAL_STRING(&_176$$30, "TRUE");
		} else {
			ZEPHIR_INIT_NVAR(&_176$$30);
			ZVAL_STRING(&_176$$30, "FALSE");
		}
		zephir_array_update_string(&_174$$30, SL("var"), &_176$$30, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_174$$30);
		ZEPHIR_CALL_METHOD(&_175$$30, this_ptr, "toInterpolate", &_6, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_175$$30);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_177$$31);
		ZVAL_STRING(&_177$$31, "NULL");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getOutputBold", &_148, 0, &_177$$31);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_178$$31);
		zephir_create_array(&_178$$31, 1, 0);
		ZEPHIR_INIT_NVAR(&_177$$31);
		ZVAL_STRING(&_177$$31, "null");
		ZEPHIR_CALL_METHOD(&_179$$31, this_ptr, "getStyle", &_5, 0, &_177$$31);
		zephir_check_call_status();
		zephir_array_update_string(&_178$$31, SL("style"), &_179$$31, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_178$$31);
		ZEPHIR_CALL_METHOD(&_179$$31, this_ptr, "toInterpolate", &_6, 0, &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_179$$31);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_180);
	ZVAL_STRING(&_180, "varParens");
	ZEPHIR_CALL_METHOD(&message, this_ptr, "getTemplate", &_2, 0, &_180);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_181);
	zephir_create_array(&_181, 2, 0);
	ZEPHIR_INIT_NVAR(&_180);
	ZVAL_STRING(&_180, "other");
	ZEPHIR_CALL_METHOD(&_182, this_ptr, "getStyle", &_5, 0, &_180);
	zephir_check_call_status();
	zephir_array_update_string(&_181, SL("style"), &_182, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_181, SL("var"), variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_CPY_WRT(&context, &_181);
	ZEPHIR_CALL_METHOD(&_182, this_ptr, "toInterpolate", &_6, 0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_182);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getTemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0);
	zephir_array_update_string(&_2, SL("text"), &text_zv, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "toInterpolate", NULL, 0, &_0, &_2);
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&replace, &_4$$5, &value, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&replace, &_7$$6, &value, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 2, &input_zv, &replace);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Support_Debug_Dump, getTemplate)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0, _1, _3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 1377, PH_NOISY_CC | PH_READONLY);
	_2 = zephir_array_isset_value(&_1, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_2) {
		zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 1377, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_0);
		zephir_array_fetch(&_0, &_3, &name_zv, PH_NOISY, "phalcon/Support/Debug/Traits/TemplateAwareTrait.zep", 33);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "defaultTemplate", NULL, 0, &name_zv);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_0);
}

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
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_THISW();
}

