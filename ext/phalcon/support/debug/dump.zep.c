
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
	}

	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1373, &_0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "setStyles", &_zephir_call_cache[1], &styles);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "variable", &_zephir_call_cache[0], variable, &name_zv);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_LONG(&_1, (((128 | 64) | 256) | 4194304));
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_0, "__invoke", &_zephir_call_cache[0], variable, &_1);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
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
	ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getTemplate", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&context);
	zephir_create_array(&context, 2, 0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "pre");
	ZEPHIR_CALL_METHOD_CACHED(&_1, this_ptr, "getStyle", &_zephir_call_cache[1], &_0);
	zephir_check_call_status();
	zephir_array_update_string(&context, SL("style"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD_CACHED(&_1, this_ptr, "output", &_zephir_call_cache[2], variable, &name_zv);
	zephir_check_call_status();
	zephir_array_update_string(&context, SL("output"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "toInterpolate", &_zephir_call_cache[3], &message, &context);
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
	zend_bool _9;
	zend_string *_5;
	zend_ulong _4;
	zval output;
	zval key, value, _0, *_1, _2, *_3, _8, _6$$3, _7$$3, _10$$4, _11$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&output);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
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
			ZEPHIR_CALL_METHOD_CACHED(&_6$$3, this_ptr, "one", &_zephir_call_cache[0], &value, &_7$$3);
			zephir_check_call_status();
			zephir_concat_self(&output, &_6$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_9 = 1;
		while (1) {
			if (_9) {
				_9 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_8, _1, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&key, _1, "key", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, _1, "current", &_zephir_call_cache[5]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_11$$4);
				ZEPHIR_CONCAT_SV(&_11$$4, "var ", &key);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_10$$4, this_ptr, "one", &_zephir_call_cache[6], &value, &_11$$4);
				zephir_check_call_status();
				zephir_concat_self(&output, &_10$$4);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1375, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	zend_class_entry *_79$$16, *_94$$18;
	zend_bool _22$$4, _16$$5, _17$$5, _18$$5, _29$$7, _30$$7, _31$$7, _44$$9, _45$$9, _47$$9, _111$$9, _65$$12, _92$$15, _127$$21;
	zend_ulong _6$$4, _54$$12;
	zval space, _0$$3, _14$$5, _28$$7, _59$$13, _69$$14, _156$$28;
	zval context;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_15 = NULL, *_40 = NULL, *_157 = NULL;
	zend_long tab, ZEPHIR_LAST_CALL_STATUS;
	zend_string *name = NULL, *_7$$4, *_55$$12;
	zval *variable, variable_sub, name_zv, *tab_param = NULL, attr, key, message, output, property, props, reflect, type, value, vars, _174, _175, _176, _1$$4, _2$$4, _3$$4, *_4$$4, *_5$$4, _21$$4, _34$$4, _35$$4, _8$$5, _9$$5, _11$$5, _12$$5, _13$$5, _19$$5, _20$$5, _23$$7, _24$$7, _25$$7, _26$$7, _27$$7, _32$$7, _33$$7, _36$$9, _37$$9, _38$$9, _39$$9, _46$$9, _106$$9, _107$$9, _108$$9, _109$$9, _110$$9, _139$$9, _140$$9, _41$$10, _42$$10, _43$$10, _48$$11, _49$$11, _50$$11, *_51$$12, _52$$12, *_53$$12, _64$$12, _56$$13, _57$$13, _58$$13, _60$$13, _61$$13, _62$$13, _63$$13, _66$$14, _67$$14, _68$$14, _70$$14, _71$$14, _72$$14, _73$$14, _74$$15, *_75$$15, _76$$15, *_77$$15, _91$$15, _78$$16, _80$$16, _81$$16, _82$$16, _83$$16, _87$$16, _88$$16, _89$$16, _90$$16, _84$$17, _85$$17, _86$$17, _93$$18, _95$$18, _96$$18, _97$$18, _98$$18, _102$$18, _103$$18, _104$$18, _105$$18, _99$$19, _100$$19, _101$$19, _112$$20, _113$$20, _114$$20, *_115$$21, _116$$21, *_117$$21, _126$$21, _136$$21, _137$$21, _138$$21, _118$$22, _119$$22, _121$$22, _122$$22, _123$$22, _124$$22, _125$$22, _120$$23, _128$$24, _129$$24, _131$$24, _132$$24, _133$$24, _134$$24, _135$$24, _130$$25, _141$$26, _142$$26, _143$$26, _144$$26, _145$$26, _146$$27, _147$$27, _148$$27, _149$$27, _150$$27, _151$$28, _152$$28, _153$$28, _154$$28, _155$$28, _158$$29, _159$$29, _160$$29, _161$$29, _162$$29, _163$$29, _164$$29, _165$$30, _166$$30, _167$$30, _168$$30, _169$$30, _170$$30, _171$$31, _172$$31, _173$$31;
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
	ZVAL_UNDEF(&_174);
	ZVAL_UNDEF(&_175);
	ZVAL_UNDEF(&_176);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_34$$4);
	ZVAL_UNDEF(&_35$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_19$$5);
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
	ZVAL_UNDEF(&_46$$9);
	ZVAL_UNDEF(&_106$$9);
	ZVAL_UNDEF(&_107$$9);
	ZVAL_UNDEF(&_108$$9);
	ZVAL_UNDEF(&_109$$9);
	ZVAL_UNDEF(&_110$$9);
	ZVAL_UNDEF(&_139$$9);
	ZVAL_UNDEF(&_140$$9);
	ZVAL_UNDEF(&_41$$10);
	ZVAL_UNDEF(&_42$$10);
	ZVAL_UNDEF(&_43$$10);
	ZVAL_UNDEF(&_48$$11);
	ZVAL_UNDEF(&_49$$11);
	ZVAL_UNDEF(&_50$$11);
	ZVAL_UNDEF(&_52$$12);
	ZVAL_UNDEF(&_64$$12);
	ZVAL_UNDEF(&_56$$13);
	ZVAL_UNDEF(&_57$$13);
	ZVAL_UNDEF(&_58$$13);
	ZVAL_UNDEF(&_60$$13);
	ZVAL_UNDEF(&_61$$13);
	ZVAL_UNDEF(&_62$$13);
	ZVAL_UNDEF(&_63$$13);
	ZVAL_UNDEF(&_66$$14);
	ZVAL_UNDEF(&_67$$14);
	ZVAL_UNDEF(&_68$$14);
	ZVAL_UNDEF(&_70$$14);
	ZVAL_UNDEF(&_71$$14);
	ZVAL_UNDEF(&_72$$14);
	ZVAL_UNDEF(&_73$$14);
	ZVAL_UNDEF(&_74$$15);
	ZVAL_UNDEF(&_76$$15);
	ZVAL_UNDEF(&_91$$15);
	ZVAL_UNDEF(&_78$$16);
	ZVAL_UNDEF(&_80$$16);
	ZVAL_UNDEF(&_81$$16);
	ZVAL_UNDEF(&_82$$16);
	ZVAL_UNDEF(&_83$$16);
	ZVAL_UNDEF(&_87$$16);
	ZVAL_UNDEF(&_88$$16);
	ZVAL_UNDEF(&_89$$16);
	ZVAL_UNDEF(&_90$$16);
	ZVAL_UNDEF(&_84$$17);
	ZVAL_UNDEF(&_85$$17);
	ZVAL_UNDEF(&_86$$17);
	ZVAL_UNDEF(&_93$$18);
	ZVAL_UNDEF(&_95$$18);
	ZVAL_UNDEF(&_96$$18);
	ZVAL_UNDEF(&_97$$18);
	ZVAL_UNDEF(&_98$$18);
	ZVAL_UNDEF(&_102$$18);
	ZVAL_UNDEF(&_103$$18);
	ZVAL_UNDEF(&_104$$18);
	ZVAL_UNDEF(&_105$$18);
	ZVAL_UNDEF(&_99$$19);
	ZVAL_UNDEF(&_100$$19);
	ZVAL_UNDEF(&_101$$19);
	ZVAL_UNDEF(&_112$$20);
	ZVAL_UNDEF(&_113$$20);
	ZVAL_UNDEF(&_114$$20);
	ZVAL_UNDEF(&_116$$21);
	ZVAL_UNDEF(&_126$$21);
	ZVAL_UNDEF(&_136$$21);
	ZVAL_UNDEF(&_137$$21);
	ZVAL_UNDEF(&_138$$21);
	ZVAL_UNDEF(&_118$$22);
	ZVAL_UNDEF(&_119$$22);
	ZVAL_UNDEF(&_121$$22);
	ZVAL_UNDEF(&_122$$22);
	ZVAL_UNDEF(&_123$$22);
	ZVAL_UNDEF(&_124$$22);
	ZVAL_UNDEF(&_125$$22);
	ZVAL_UNDEF(&_120$$23);
	ZVAL_UNDEF(&_128$$24);
	ZVAL_UNDEF(&_129$$24);
	ZVAL_UNDEF(&_131$$24);
	ZVAL_UNDEF(&_132$$24);
	ZVAL_UNDEF(&_133$$24);
	ZVAL_UNDEF(&_134$$24);
	ZVAL_UNDEF(&_135$$24);
	ZVAL_UNDEF(&_130$$25);
	ZVAL_UNDEF(&_141$$26);
	ZVAL_UNDEF(&_142$$26);
	ZVAL_UNDEF(&_143$$26);
	ZVAL_UNDEF(&_144$$26);
	ZVAL_UNDEF(&_145$$26);
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
	ZVAL_UNDEF(&_158$$29);
	ZVAL_UNDEF(&_159$$29);
	ZVAL_UNDEF(&_160$$29);
	ZVAL_UNDEF(&_161$$29);
	ZVAL_UNDEF(&_162$$29);
	ZVAL_UNDEF(&_163$$29);
	ZVAL_UNDEF(&_164$$29);
	ZVAL_UNDEF(&_165$$30);
	ZVAL_UNDEF(&_166$$30);
	ZVAL_UNDEF(&_167$$30);
	ZVAL_UNDEF(&_168$$30);
	ZVAL_UNDEF(&_169$$30);
	ZVAL_UNDEF(&_170$$30);
	ZVAL_UNDEF(&_171$$31);
	ZVAL_UNDEF(&_172$$31);
	ZVAL_UNDEF(&_173$$31);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&space);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_59$$13);
	ZVAL_UNDEF(&_69$$14);
	ZVAL_UNDEF(&_156$$28);
	ZEND_TLS zephir_method_cache _zephir_call_cache[100];
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
		ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getTemplate", &_zephir_call_cache[0], &_1$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_create_array(&_2$$4, 2, 0);
		ZEPHIR_INIT_NVAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "arr");
		ZEPHIR_CALL_METHOD_CACHED(&_3$$4, this_ptr, "getStyle", &_zephir_call_cache[1], &_1$$4);
		zephir_check_call_status();
		zephir_array_update_string(&_2$$4, SL("style"), &_3$$4, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_2$$4, SL("count"), zephir_fast_count_int(variable));
		ZEPHIR_CPY_WRT(&context, &_2$$4);
		ZEPHIR_CALL_METHOD_CACHED(&_3$$4, this_ptr, "toInterpolate", &_zephir_call_cache[2], &message, &context);
		zephir_check_call_status();
		zephir_concat_self(&output, &_3$$4);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(variable) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_1$$4);
			zephir_string_to_char_array(&_1$$4, variable);
			_4$$4 = &_1$$4;
		} else {
			_4$$4 = variable;
		}
		zephir_is_iterable(_4$$4, 0, "phalcon/Support/Debug/Dump.zep", 322);
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
				ZEPHIR_CALL_FUNCTION(&_9$$5, "str_repeat", &_10, 3, &space, &_8$$5);
				zephir_check_call_status();
				zephir_concat_self(&output, &_9$$5);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_11$$5);
				ZVAL_STRING(&_11$$5, "arrayKey");
				ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getTemplate", &_zephir_call_cache[3], &_11$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$5);
				zephir_create_array(&_12$$5, 2, 0);
				ZEPHIR_INIT_NVAR(&_11$$5);
				ZVAL_STRING(&_11$$5, "arr");
				ZEPHIR_CALL_METHOD_CACHED(&_13$$5, this_ptr, "getStyle", &_zephir_call_cache[4], &_11$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_12$$5, SL("style"), &_13$$5, PH_COPY | PH_SEPARATE);
				zephir_cast_to_string(&_14$$5, &key);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZVAL_LONG(&_8$$5, 3);
				ZEPHIR_INIT_NVAR(&_11$$5);
				ZVAL_STRING(&_11$$5, "utf-8");
				ZEPHIR_CALL_FUNCTION(&_13$$5, "htmlspecialchars", &_15, 60, &_14$$5, &_8$$5, &_11$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_12$$5, SL("key"), &_13$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&context, &_12$$5);
				ZEPHIR_CALL_METHOD_CACHED(&_13$$5, this_ptr, "toInterpolate", &_zephir_call_cache[5], &message, &context);
				zephir_check_call_status();
				zephir_concat_self(&output, &_13$$5);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
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
					zephir_concat_self_str(&output, SL("\n"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				ZEPHIR_INIT_NVAR(&_11$$5);
				ZVAL_STRING(&_11$$5, "");
				ZVAL_LONG(&_8$$5, (tab + 1));
				ZEPHIR_CALL_METHOD_CACHED(&_19$$5, this_ptr, "output", &_zephir_call_cache[6], &value, &_11$$5, &_8$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_20$$5);
				ZEPHIR_CONCAT_VS(&_20$$5, &_19$$5, "\n");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&output, &_20$$5);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _4$$4, "rewind", &_zephir_call_cache[7]);
			zephir_check_call_status();
			_22$$4 = 1;
			while (1) {
				if (_22$$4) {
					_22$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _4$$4, "next", &_zephir_call_cache[8]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_21$$4, _4$$4, "valid", &_zephir_call_cache[9]);
				zephir_check_call_status();
				if (!zend_is_true(&_21$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&key, _4$$4, "key", &_zephir_call_cache[10]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&value, _4$$4, "current", &_zephir_call_cache[11]);
				zephir_check_call_status();
					ZVAL_LONG(&_23$$7, tab);
					ZEPHIR_CALL_FUNCTION(&_24$$7, "str_repeat", &_10, 3, &space, &_23$$7);
					zephir_check_call_status();
					zephir_concat_self(&output, &_24$$7);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_25$$7);
					ZVAL_STRING(&_25$$7, "arrayKey");
					ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getTemplate", &_zephir_call_cache[12], &_25$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_26$$7);
					zephir_create_array(&_26$$7, 2, 0);
					ZEPHIR_INIT_NVAR(&_25$$7);
					ZVAL_STRING(&_25$$7, "arr");
					ZEPHIR_CALL_METHOD_CACHED(&_27$$7, this_ptr, "getStyle", &_zephir_call_cache[13], &_25$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_26$$7, SL("style"), &_27$$7, PH_COPY | PH_SEPARATE);
					zephir_cast_to_string(&_28$$7, &key);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZVAL_LONG(&_23$$7, 3);
					ZEPHIR_INIT_NVAR(&_25$$7);
					ZVAL_STRING(&_25$$7, "utf-8");
					ZEPHIR_CALL_FUNCTION(&_27$$7, "htmlspecialchars", &_15, 60, &_28$$7, &_23$$7, &_25$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_26$$7, SL("key"), &_27$$7, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&context, &_26$$7);
					ZEPHIR_CALL_METHOD_CACHED(&_27$$7, this_ptr, "toInterpolate", &_zephir_call_cache[14], &message, &context);
					zephir_check_call_status();
					zephir_concat_self(&output, &_27$$7);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
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
						zephir_concat_self_str(&output, SL("\n"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					ZEPHIR_INIT_NVAR(&_25$$7);
					ZVAL_STRING(&_25$$7, "");
					ZVAL_LONG(&_23$$7, (tab + 1));
					ZEPHIR_CALL_METHOD_CACHED(&_32$$7, this_ptr, "output", &_zephir_call_cache[15], &value, &_25$$7, &_23$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_33$$7);
					ZEPHIR_CONCAT_VS(&_33$$7, &_32$$7, "\n");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&output, &_33$$7);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_34$$4, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_35$$4, "str_repeat", &_10, 3, &space, &_34$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_35$$4, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_36$$9);
		ZVAL_STRING(&_36$$9, "objectHeader");
		ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getTemplate", &_zephir_call_cache[16], &_36$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_37$$9);
		zephir_create_array(&_37$$9, 2, 0);
		ZEPHIR_INIT_NVAR(&_36$$9);
		ZVAL_STRING(&_36$$9, "obj");
		ZEPHIR_CALL_METHOD_CACHED(&_38$$9, this_ptr, "getStyle", &_zephir_call_cache[17], &_36$$9);
		zephir_check_call_status();
		zephir_array_update_string(&_37$$9, SL("style"), &_38$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_36$$9);
		zephir_get_class(&_36$$9, variable, 0);
		zephir_array_update_string(&_37$$9, SL("class"), &_36$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_37$$9);
		ZEPHIR_CALL_METHOD_CACHED(&_38$$9, this_ptr, "toInterpolate", &_zephir_call_cache[18], &message, &context);
		zephir_check_call_status();
		zephir_concat_self(&output, &_38$$9);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_FUNCTION(&_39$$9, "get_parent_class", &_40, 267, variable);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_39$$9)) {
			ZEPHIR_INIT_VAR(&_41$$10);
			ZVAL_STRING(&_41$$10, "objectExtends");
			ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getTemplate", &_zephir_call_cache[19], &_41$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_42$$10);
			zephir_create_array(&_42$$10, 2, 0);
			ZEPHIR_INIT_NVAR(&_41$$10);
			ZVAL_STRING(&_41$$10, "obj");
			ZEPHIR_CALL_METHOD_CACHED(&_43$$10, this_ptr, "getStyle", &_zephir_call_cache[20], &_41$$10);
			zephir_check_call_status();
			zephir_array_update_string(&_42$$10, SL("style"), &_43$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_43$$10, "get_parent_class", &_40, 267, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_42$$10, SL("parent"), &_43$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&context, &_42$$10);
			ZEPHIR_CALL_METHOD_CACHED(&_43$$10, this_ptr, "toInterpolate", &_zephir_call_cache[21], &message, &context);
			zephir_check_call_status();
			zephir_concat_self(&output, &_43$$10);
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
			ZEPHIR_CALL_FUNCTION(&_49$$11, "str_repeat", &_10, 3, &space, &_48$$11);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_50$$11);
			ZEPHIR_CONCAT_VS(&_50$$11, &_49$$11, "[skipped]\n");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_concat_self(&output, &_50$$11);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			zephir_read_property_cached(&_46$$9, this_ptr, _zephir_prop_0, 1374, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_47$$9 = !ZEPHIR_IS_TRUE_IDENTICAL(&_46$$9);
			if (!(_47$$9)) {
				_47$$9 = zephir_is_instance_of(variable, SL("stdClass"));
			}
			if (_47$$9) {
				ZEPHIR_CALL_FUNCTION(&vars, "get_object_vars", NULL, 107, variable);
				zephir_check_call_status();
				if (Z_TYPE_P(&vars) == IS_STRING) {
					ZEPHIR_INIT_VAR(&_52$$12);
					zephir_string_to_char_array(&_52$$12, &vars);
					_51$$12 = &_52$$12;
				} else {
					_51$$12 = &vars;
				}
				zephir_is_iterable(_51$$12, 0, "phalcon/Support/Debug/Dump.zep", 366);
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
						ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getTemplate", &_zephir_call_cache[22], &_56$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_57$$13);
						zephir_create_array(&_57$$13, 3, 0);
						ZEPHIR_INIT_NVAR(&_56$$13);
						ZVAL_STRING(&_56$$13, "obj");
						ZEPHIR_CALL_METHOD_CACHED(&_58$$13, this_ptr, "getStyle", &_zephir_call_cache[23], &_56$$13);
						zephir_check_call_status();
						zephir_array_update_string(&_57$$13, SL("style"), &_58$$13, PH_COPY | PH_SEPARATE);
						zephir_cast_to_string(&_59$$13, &key);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZVAL_LONG(&_60$$13, 3);
						ZEPHIR_INIT_NVAR(&_56$$13);
						ZVAL_STRING(&_56$$13, "utf-8");
						ZEPHIR_CALL_FUNCTION(&_58$$13, "htmlspecialchars", &_15, 60, &_59$$13, &_60$$13, &_56$$13);
						zephir_check_call_status();
						zephir_array_update_string(&_57$$13, SL("key"), &_58$$13, PH_COPY | PH_SEPARATE);
						add_assoc_stringl_ex(&_57$$13, SL("type"), SL("public"));
						ZEPHIR_CPY_WRT(&context, &_57$$13);
						ZVAL_LONG(&_60$$13, tab);
						ZEPHIR_CALL_FUNCTION(&_58$$13, "str_repeat", &_10, 3, &space, &_60$$13);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&_61$$13, this_ptr, "toInterpolate", &_zephir_call_cache[24], &message, &context);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_56$$13);
						ZVAL_STRING(&_56$$13, "");
						ZVAL_LONG(&_60$$13, (tab + 1));
						ZEPHIR_CALL_METHOD_CACHED(&_62$$13, this_ptr, "output", &_zephir_call_cache[25], &value, &_56$$13, &_60$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_63$$13);
						ZEPHIR_CONCAT_VVVS(&_63$$13, &_58$$13, &_61$$13, &_62$$13, "\n");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&output, &_63$$13);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _51$$12, "rewind", &_zephir_call_cache[26]);
					zephir_check_call_status();
					_65$$12 = 1;
					while (1) {
						if (_65$$12) {
							_65$$12 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _51$$12, "next", &_zephir_call_cache[27]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_64$$12, _51$$12, "valid", &_zephir_call_cache[28]);
						zephir_check_call_status();
						if (!zend_is_true(&_64$$12)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&key, _51$$12, "key", &_zephir_call_cache[29]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&value, _51$$12, "current", &_zephir_call_cache[30]);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_66$$14);
							ZVAL_STRING(&_66$$14, "objectProperty");
							ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getTemplate", &_zephir_call_cache[31], &_66$$14);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_67$$14);
							zephir_create_array(&_67$$14, 3, 0);
							ZEPHIR_INIT_NVAR(&_66$$14);
							ZVAL_STRING(&_66$$14, "obj");
							ZEPHIR_CALL_METHOD_CACHED(&_68$$14, this_ptr, "getStyle", &_zephir_call_cache[32], &_66$$14);
							zephir_check_call_status();
							zephir_array_update_string(&_67$$14, SL("style"), &_68$$14, PH_COPY | PH_SEPARATE);
							zephir_cast_to_string(&_69$$14, &key);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZVAL_LONG(&_70$$14, 3);
							ZEPHIR_INIT_NVAR(&_66$$14);
							ZVAL_STRING(&_66$$14, "utf-8");
							ZEPHIR_CALL_FUNCTION(&_68$$14, "htmlspecialchars", &_15, 60, &_69$$14, &_70$$14, &_66$$14);
							zephir_check_call_status();
							zephir_array_update_string(&_67$$14, SL("key"), &_68$$14, PH_COPY | PH_SEPARATE);
							add_assoc_stringl_ex(&_67$$14, SL("type"), SL("public"));
							ZEPHIR_CPY_WRT(&context, &_67$$14);
							ZVAL_LONG(&_70$$14, tab);
							ZEPHIR_CALL_FUNCTION(&_68$$14, "str_repeat", &_10, 3, &space, &_70$$14);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&_71$$14, this_ptr, "toInterpolate", &_zephir_call_cache[33], &message, &context);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_66$$14);
							ZVAL_STRING(&_66$$14, "");
							ZVAL_LONG(&_70$$14, (tab + 1));
							ZEPHIR_CALL_METHOD_CACHED(&_72$$14, this_ptr, "output", &_zephir_call_cache[34], &value, &_66$$14, &_70$$14);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_73$$14);
							ZEPHIR_CONCAT_VVVS(&_73$$14, &_68$$14, &_71$$14, &_72$$14, "\n");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_concat_self(&output, &_73$$14);
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
				ZEPHIR_CALL_METHOD_CACHED(NULL, &reflect, "__construct", &_zephir_call_cache[35], variable);
				zephir_check_call_status();
				ZVAL_LONG(&_74$$15, ((1 | 2) | 4));
				ZEPHIR_CALL_METHOD_CACHED(&props, &reflect, "getProperties", &_zephir_call_cache[36], &_74$$15);
				zephir_check_call_status();
				if (Z_TYPE_P(&props) == IS_STRING) {
					ZEPHIR_INIT_VAR(&_76$$15);
					zephir_string_to_char_array(&_76$$15, &props);
					_75$$15 = &_76$$15;
				} else {
					_75$$15 = &props;
				}
				zephir_is_iterable(_75$$15, 0, "phalcon/Support/Debug/Dump.zep", 402);
				if (Z_TYPE_P(_75$$15) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_75$$15), _77$$15)
					{
						ZEPHIR_INIT_NVAR(&property);
						ZVAL_COPY(&property, _77$$15);
						ZEPHIR_CALL_METHOD_CACHED(&key, &property, "getName", &_zephir_call_cache[37]);
						zephir_check_call_status();
						_79$$16 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
						ZEPHIR_CALL_METHOD_CACHED(&_80$$16, &property, "getModifiers", &_zephir_call_cache[38]);
						zephir_check_call_status();
						ZEPHIR_CALL_CE_STATIC_CACHED(&_78$$16, _79$$16, "getModifierNames", &_zephir_call_cache[39], &_80$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&type);
						zephir_fast_join_str(&type, SL(" "), &_78$$16);
						ZEPHIR_INIT_NVAR(&_81$$16);
						ZVAL_STRING(&_81$$16, "objectProperty");
						ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getTemplate", &_zephir_call_cache[40], &_81$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_82$$16);
						zephir_create_array(&_82$$16, 3, 0);
						ZEPHIR_INIT_NVAR(&_81$$16);
						ZVAL_STRING(&_81$$16, "obj");
						ZEPHIR_CALL_METHOD_CACHED(&_83$$16, this_ptr, "getStyle", &_zephir_call_cache[41], &_81$$16);
						zephir_check_call_status();
						zephir_array_update_string(&_82$$16, SL("style"), &_83$$16, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_82$$16, SL("key"), &key, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_82$$16, SL("type"), &type, PH_COPY | PH_SEPARATE);
						ZEPHIR_CPY_WRT(&context, &_82$$16);
						ZEPHIR_INIT_NVAR(&value);
						ZVAL_STRING(&value, "[uninitialized]");
						ZEPHIR_CALL_METHOD_CACHED(&_83$$16, &property, "isInitialized", &_zephir_call_cache[42], variable);
						zephir_check_call_status();
						if (ZEPHIR_IS_TRUE_IDENTICAL(&_83$$16)) {
							ZEPHIR_CALL_METHOD_CACHED(&_84$$17, &property, "getValue", &_zephir_call_cache[43], variable);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_85$$17);
							ZVAL_STRING(&_85$$17, "");
							ZVAL_LONG(&_86$$17, (tab + 1));
							ZEPHIR_CALL_METHOD_CACHED(&value, this_ptr, "output", &_zephir_call_cache[44], &_84$$17, &_85$$17, &_86$$17);
							zephir_check_call_status();
						}
						ZVAL_LONG(&_87$$16, tab);
						ZEPHIR_CALL_FUNCTION(&_88$$16, "str_repeat", &_10, 3, &space, &_87$$16);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&_89$$16, this_ptr, "toInterpolate", &_zephir_call_cache[45], &message, &context);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_90$$16);
						ZEPHIR_CONCAT_VVVS(&_90$$16, &_88$$16, &_89$$16, &value, "\n");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&output, &_90$$16);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _75$$15, "rewind", &_zephir_call_cache[46]);
					zephir_check_call_status();
					_92$$15 = 1;
					while (1) {
						if (_92$$15) {
							_92$$15 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _75$$15, "next", &_zephir_call_cache[47]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_91$$15, _75$$15, "valid", &_zephir_call_cache[48]);
						zephir_check_call_status();
						if (!zend_is_true(&_91$$15)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&property, _75$$15, "current", &_zephir_call_cache[49]);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&key, &property, "getName", &_zephir_call_cache[50]);
							zephir_check_call_status();
							_94$$18 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
							ZEPHIR_CALL_METHOD_CACHED(&_95$$18, &property, "getModifiers", &_zephir_call_cache[51]);
							zephir_check_call_status();
							ZEPHIR_CALL_CE_STATIC_CACHED(&_93$$18, _94$$18, "getModifierNames", &_zephir_call_cache[52], &_95$$18);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&type);
							zephir_fast_join_str(&type, SL(" "), &_93$$18);
							ZEPHIR_INIT_NVAR(&_96$$18);
							ZVAL_STRING(&_96$$18, "objectProperty");
							ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getTemplate", &_zephir_call_cache[53], &_96$$18);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_97$$18);
							zephir_create_array(&_97$$18, 3, 0);
							ZEPHIR_INIT_NVAR(&_96$$18);
							ZVAL_STRING(&_96$$18, "obj");
							ZEPHIR_CALL_METHOD_CACHED(&_98$$18, this_ptr, "getStyle", &_zephir_call_cache[54], &_96$$18);
							zephir_check_call_status();
							zephir_array_update_string(&_97$$18, SL("style"), &_98$$18, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_97$$18, SL("key"), &key, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_97$$18, SL("type"), &type, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&context, &_97$$18);
							ZEPHIR_INIT_NVAR(&value);
							ZVAL_STRING(&value, "[uninitialized]");
							ZEPHIR_CALL_METHOD_CACHED(&_98$$18, &property, "isInitialized", &_zephir_call_cache[55], variable);
							zephir_check_call_status();
							if (ZEPHIR_IS_TRUE_IDENTICAL(&_98$$18)) {
								ZEPHIR_CALL_METHOD_CACHED(&_99$$19, &property, "getValue", &_zephir_call_cache[56], variable);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_100$$19);
								ZVAL_STRING(&_100$$19, "");
								ZVAL_LONG(&_101$$19, (tab + 1));
								ZEPHIR_CALL_METHOD_CACHED(&value, this_ptr, "output", &_zephir_call_cache[57], &_99$$19, &_100$$19, &_101$$19);
								zephir_check_call_status();
							}
							ZVAL_LONG(&_102$$18, tab);
							ZEPHIR_CALL_FUNCTION(&_103$$18, "str_repeat", &_10, 3, &space, &_102$$18);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&_104$$18, this_ptr, "toInterpolate", &_zephir_call_cache[58], &message, &context);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_105$$18);
							ZEPHIR_CONCAT_VVVS(&_105$$18, &_103$$18, &_104$$18, &value, "\n");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_concat_self(&output, &_105$$18);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&property);
			}
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 268, variable);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_36$$9);
		ZVAL_STRING(&_36$$9, "objectMethods");
		ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getTemplate", &_zephir_call_cache[59], &_36$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_106$$9);
		zephir_create_array(&_106$$9, 3, 0);
		ZEPHIR_INIT_NVAR(&_36$$9);
		ZVAL_STRING(&_36$$9, "obj");
		ZEPHIR_CALL_METHOD_CACHED(&_107$$9, this_ptr, "getStyle", &_zephir_call_cache[60], &_36$$9);
		zephir_check_call_status();
		zephir_array_update_string(&_106$$9, SL("style"), &_107$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_36$$9);
		zephir_get_class(&_36$$9, variable, 0);
		zephir_array_update_string(&_106$$9, SL("class"), &_36$$9, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_106$$9, SL("count"), zephir_fast_count_int(&attr));
		ZEPHIR_CPY_WRT(&context, &_106$$9);
		ZVAL_LONG(&_108$$9, tab);
		ZEPHIR_CALL_FUNCTION(&_107$$9, "str_repeat", &_10, 3, &space, &_108$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_109$$9, this_ptr, "toInterpolate", &_zephir_call_cache[61], &message, &context);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_110$$9);
		ZEPHIR_CONCAT_VV(&_110$$9, &_107$$9, &_109$$9);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&output, &_110$$9);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&_36$$9);
		zephir_get_class(&_36$$9, variable, 0);
		zephir_read_property_cached(&_108$$9, this_ptr, _zephir_prop_1, 1376, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_111$$9 = zephir_fast_in_array(&_36$$9, &_108$$9);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (1 == _111$$9) {
			ZVAL_LONG(&_112$$20, tab);
			ZEPHIR_CALL_FUNCTION(&_113$$20, "str_repeat", &_10, 3, &space, &_112$$20);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_114$$20);
			ZEPHIR_CONCAT_VS(&_114$$20, &_113$$20, "[already listed]\n");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_concat_self(&output, &_114$$20);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			if (Z_TYPE_P(&attr) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_116$$21);
				zephir_string_to_char_array(&_116$$21, &attr);
				_115$$21 = &_116$$21;
			} else {
				_115$$21 = &attr;
			}
			zephir_is_iterable(_115$$21, 0, "phalcon/Support/Debug/Dump.zep", 435);
			if (Z_TYPE_P(_115$$21) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_115$$21), _117$$21)
				{
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _117$$21);
					ZEPHIR_INIT_NVAR(&_118$$22);
					zephir_get_class(&_118$$22, variable, 0);
					zephir_update_property_array_append(this_ptr, SL("methods"), &_118$$22);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_118$$22);
					ZVAL_STRING(&_118$$22, "objectMethod");
					ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getTemplate", &_zephir_call_cache[62], &_118$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_119$$22);
					ZVAL_STRING(&_119$$22, "__construct");
					if (ZEPHIR_IS_IDENTICAL(&_119$$22, &value)) {
						ZEPHIR_INIT_NVAR(&_120$$23);
						ZVAL_STRING(&_120$$23, "objectMethodConstructor");
						ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getTemplate", &_zephir_call_cache[63], &_120$$23);
						zephir_check_call_status();
					}
					ZEPHIR_INIT_NVAR(&_121$$22);
					zephir_create_array(&_121$$22, 2, 0);
					ZEPHIR_INIT_NVAR(&_118$$22);
					ZVAL_STRING(&_118$$22, "obj");
					ZEPHIR_CALL_METHOD_CACHED(&_122$$22, this_ptr, "getStyle", &_zephir_call_cache[64], &_118$$22);
					zephir_check_call_status();
					zephir_array_update_string(&_121$$22, SL("style"), &_122$$22, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_121$$22, SL("method"), &value, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&context, &_121$$22);
					ZVAL_LONG(&_123$$22, (tab + 1));
					ZEPHIR_CALL_FUNCTION(&_122$$22, "str_repeat", &_10, 3, &space, &_123$$22);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_124$$22, this_ptr, "toInterpolate", &_zephir_call_cache[65], &message, &context);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_125$$22);
					ZEPHIR_CONCAT_VV(&_125$$22, &_122$$22, &_124$$22);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&output, &_125$$22);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _115$$21, "rewind", &_zephir_call_cache[66]);
				zephir_check_call_status();
				_127$$21 = 1;
				while (1) {
					if (_127$$21) {
						_127$$21 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _115$$21, "next", &_zephir_call_cache[67]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_126$$21, _115$$21, "valid", &_zephir_call_cache[68]);
					zephir_check_call_status();
					if (!zend_is_true(&_126$$21)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&value, _115$$21, "current", &_zephir_call_cache[69]);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_128$$24);
						zephir_get_class(&_128$$24, variable, 0);
						zephir_update_property_array_append(this_ptr, SL("methods"), &_128$$24);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_128$$24);
						ZVAL_STRING(&_128$$24, "objectMethod");
						ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getTemplate", &_zephir_call_cache[70], &_128$$24);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_129$$24);
						ZVAL_STRING(&_129$$24, "__construct");
						if (ZEPHIR_IS_IDENTICAL(&_129$$24, &value)) {
							ZEPHIR_INIT_NVAR(&_130$$25);
							ZVAL_STRING(&_130$$25, "objectMethodConstructor");
							ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getTemplate", &_zephir_call_cache[71], &_130$$25);
							zephir_check_call_status();
						}
						ZEPHIR_INIT_NVAR(&_131$$24);
						zephir_create_array(&_131$$24, 2, 0);
						ZEPHIR_INIT_NVAR(&_128$$24);
						ZVAL_STRING(&_128$$24, "obj");
						ZEPHIR_CALL_METHOD_CACHED(&_132$$24, this_ptr, "getStyle", &_zephir_call_cache[72], &_128$$24);
						zephir_check_call_status();
						zephir_array_update_string(&_131$$24, SL("style"), &_132$$24, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_131$$24, SL("method"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_CPY_WRT(&context, &_131$$24);
						ZVAL_LONG(&_133$$24, (tab + 1));
						ZEPHIR_CALL_FUNCTION(&_132$$24, "str_repeat", &_10, 3, &space, &_133$$24);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&_134$$24, this_ptr, "toInterpolate", &_zephir_call_cache[73], &message, &context);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_135$$24);
						ZEPHIR_CONCAT_VV(&_135$$24, &_132$$24, &_134$$24);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&output, &_135$$24);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_LONG(&_136$$21, tab);
			ZEPHIR_CALL_FUNCTION(&_137$$21, "str_repeat", &_10, 3, &space, &_136$$21);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_138$$21);
			ZEPHIR_CONCAT_VS(&_138$$21, &_137$$21, ")\n");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_concat_self(&output, &_138$$21);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZVAL_LONG(&_139$$9, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_140$$9, "str_repeat", &_10, 3, &space, &_139$$9);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_140$$9, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_142$$26);
		ZVAL_STRING(&_142$$26, "Integer");
		ZEPHIR_CALL_METHOD_CACHED(&_141$$26, this_ptr, "getOutputBold", &_zephir_call_cache[74], &_142$$26);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_142$$26);
		ZVAL_STRING(&_142$$26, "varParens");
		ZEPHIR_CALL_METHOD_CACHED(&_143$$26, this_ptr, "getTemplate", &_zephir_call_cache[75], &_142$$26);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_141$$26, " ", &_143$$26);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_144$$26);
		zephir_create_array(&_144$$26, 2, 0);
		ZEPHIR_INIT_NVAR(&_142$$26);
		ZVAL_STRING(&_142$$26, "int");
		ZEPHIR_CALL_METHOD_CACHED(&_145$$26, this_ptr, "getStyle", &_zephir_call_cache[76], &_142$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_144$$26, SL("style"), &_145$$26, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_144$$26, SL("var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_144$$26);
		ZEPHIR_CALL_METHOD_CACHED(&_145$$26, this_ptr, "toInterpolate", &_zephir_call_cache[77], &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_145$$26);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_DOUBLE) {
		ZEPHIR_INIT_VAR(&_147$$27);
		ZVAL_STRING(&_147$$27, "Float");
		ZEPHIR_CALL_METHOD_CACHED(&_146$$27, this_ptr, "getOutputBold", &_zephir_call_cache[78], &_147$$27);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_147$$27);
		ZVAL_STRING(&_147$$27, "varParens");
		ZEPHIR_CALL_METHOD_CACHED(&_148$$27, this_ptr, "getTemplate", &_zephir_call_cache[79], &_147$$27);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_146$$27, " ", &_148$$27);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_149$$27);
		zephir_create_array(&_149$$27, 2, 0);
		ZEPHIR_INIT_NVAR(&_147$$27);
		ZVAL_STRING(&_147$$27, "float");
		ZEPHIR_CALL_METHOD_CACHED(&_150$$27, this_ptr, "getStyle", &_zephir_call_cache[80], &_147$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_149$$27, SL("style"), &_150$$27, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_149$$27, SL("var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_149$$27);
		ZEPHIR_CALL_METHOD_CACHED(&_150$$27, this_ptr, "toInterpolate", &_zephir_call_cache[81], &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_150$$27);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_152$$28);
		ZVAL_STRING(&_152$$28, "Numeric String");
		ZEPHIR_CALL_METHOD_CACHED(&_151$$28, this_ptr, "getOutputBold", &_zephir_call_cache[82], &_152$$28);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_152$$28);
		ZVAL_STRING(&_152$$28, "lengthValue");
		ZEPHIR_CALL_METHOD_CACHED(&_153$$28, this_ptr, "getTemplate", &_zephir_call_cache[83], &_152$$28);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_151$$28, " ", &_153$$28);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_154$$28);
		zephir_create_array(&_154$$28, 3, 0);
		ZEPHIR_INIT_NVAR(&_152$$28);
		ZVAL_STRING(&_152$$28, "num");
		ZEPHIR_CALL_METHOD_CACHED(&_155$$28, this_ptr, "getStyle", &_zephir_call_cache[84], &_152$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_154$$28, SL("style"), &_155$$28, PH_COPY | PH_SEPARATE);
		zephir_cast_to_string(&_156$$28, variable);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_FUNCTION(&_155$$28, "mb_strlen", &_157, 160, &_156$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_154$$28, SL("length"), &_155$$28, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_154$$28, SL("var"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_154$$28);
		ZEPHIR_CALL_METHOD_CACHED(&_155$$28, this_ptr, "toInterpolate", &_zephir_call_cache[85], &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_155$$28);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_159$$29);
		ZVAL_STRING(&_159$$29, "String");
		ZEPHIR_CALL_METHOD_CACHED(&_158$$29, this_ptr, "getOutputBold", &_zephir_call_cache[86], &_159$$29);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_159$$29);
		ZVAL_STRING(&_159$$29, "lengthValue");
		ZEPHIR_CALL_METHOD_CACHED(&_160$$29, this_ptr, "getTemplate", &_zephir_call_cache[87], &_159$$29);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_158$$29, " ", &_160$$29);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_161$$29);
		zephir_create_array(&_161$$29, 3, 0);
		ZEPHIR_INIT_NVAR(&_159$$29);
		ZVAL_STRING(&_159$$29, "str");
		ZEPHIR_CALL_METHOD_CACHED(&_162$$29, this_ptr, "getStyle", &_zephir_call_cache[88], &_159$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_161$$29, SL("style"), &_162$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_162$$29, "mb_strlen", &_157, 160, variable);
		zephir_check_call_status();
		zephir_array_update_string(&_161$$29, SL("length"), &_162$$29, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_163$$29, 4);
		ZEPHIR_INIT_NVAR(&_159$$29);
		ZVAL_STRING(&_159$$29, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_162$$29, "htmlentities", NULL, 269, variable, &_163$$29, &_159$$29);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_164$$29, "nl2br", NULL, 270, &_162$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_161$$29, SL("var"), &_164$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_161$$29);
		ZEPHIR_CALL_METHOD_CACHED(&_164$$29, this_ptr, "toInterpolate", &_zephir_call_cache[89], &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_164$$29);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	if (((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE) == 1)) {
		ZEPHIR_INIT_VAR(&_166$$30);
		ZVAL_STRING(&_166$$30, "Boolean");
		ZEPHIR_CALL_METHOD_CACHED(&_165$$30, this_ptr, "getOutputBold", &_zephir_call_cache[90], &_166$$30);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_166$$30);
		ZVAL_STRING(&_166$$30, "varParens");
		ZEPHIR_CALL_METHOD_CACHED(&_167$$30, this_ptr, "getTemplate", &_zephir_call_cache[91], &_166$$30);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_VSV(&message, &_165$$30, " ", &_167$$30);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_168$$30);
		zephir_create_array(&_168$$30, 2, 0);
		ZEPHIR_INIT_NVAR(&_166$$30);
		ZVAL_STRING(&_166$$30, "bool");
		ZEPHIR_CALL_METHOD_CACHED(&_169$$30, this_ptr, "getStyle", &_zephir_call_cache[92], &_166$$30);
		zephir_check_call_status();
		zephir_array_update_string(&_168$$30, SL("style"), &_169$$30, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_170$$30);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_170$$30);
			ZVAL_STRING(&_170$$30, "TRUE");
		} else {
			ZEPHIR_INIT_NVAR(&_170$$30);
			ZVAL_STRING(&_170$$30, "FALSE");
		}
		zephir_array_update_string(&_168$$30, SL("var"), &_170$$30, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_168$$30);
		ZEPHIR_CALL_METHOD_CACHED(&_169$$30, this_ptr, "toInterpolate", &_zephir_call_cache[93], &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_169$$30);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_171$$31);
		ZVAL_STRING(&_171$$31, "NULL");
		ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getOutputBold", &_zephir_call_cache[94], &_171$$31);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_172$$31);
		zephir_create_array(&_172$$31, 1, 0);
		ZEPHIR_INIT_NVAR(&_171$$31);
		ZVAL_STRING(&_171$$31, "null");
		ZEPHIR_CALL_METHOD_CACHED(&_173$$31, this_ptr, "getStyle", &_zephir_call_cache[95], &_171$$31);
		zephir_check_call_status();
		zephir_array_update_string(&_172$$31, SL("style"), &_173$$31, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&context, &_172$$31);
		ZEPHIR_CALL_METHOD_CACHED(&_173$$31, this_ptr, "toInterpolate", &_zephir_call_cache[96], &message, &context);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_173$$31);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_174);
	ZVAL_STRING(&_174, "varParens");
	ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getTemplate", &_zephir_call_cache[97], &_174);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_175);
	zephir_create_array(&_175, 2, 0);
	ZEPHIR_INIT_NVAR(&_174);
	ZVAL_STRING(&_174, "other");
	ZEPHIR_CALL_METHOD_CACHED(&_176, this_ptr, "getStyle", &_zephir_call_cache[98], &_174);
	zephir_check_call_status();
	zephir_array_update_string(&_175, SL("style"), &_176, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_175, SL("var"), variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_CPY_WRT(&context, &_175);
	ZEPHIR_CALL_METHOD_CACHED(&_176, this_ptr, "toInterpolate", &_zephir_call_cache[99], &message, &context);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_176);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "bold");
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getTemplate", &_zephir_call_cache[0], &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0);
	zephir_array_update_string(&_2, SL("text"), &text_zv, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "toInterpolate", &_zephir_call_cache[1], &_0, &_2);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &context, "rewind", &_zephir_call_cache[0]);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &context, "next", &_zephir_call_cache[1]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_5, &context, "valid", &_zephir_call_cache[2]);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&key, &context, "key", &_zephir_call_cache[3]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, &context, "current", &_zephir_call_cache[4]);
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
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 1, &input_zv, &replace);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 1377, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = zephir_array_isset_value(&_1, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_2) {
		zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 1377, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(&_0);
		zephir_array_fetch(&_0, &_3, &name_zv, PH_NOISY, "phalcon/Support/Debug/Traits/TemplateAwareTrait.zep", 33);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "defaultTemplate", &_zephir_call_cache[0], &name_zv);
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

