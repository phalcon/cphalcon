
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
	 * Template overrides keyed by name.
	 *
	 * @todo Move getTemplate()/setTemplate()/templates into a shared trait once
	 *       Zephir supports traits (mirrors
	 *       Phalcon\Support\Debug\Traits\TemplateAwareTrait in the PHP source).
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_support_debug_dump_ce, SL("templates"), ZEND_ACC_PROTECTED);
	/**
	 * @var Encode
	 */
	zend_declare_property_null(phalcon_support_debug_dump_ce, SL("encode"), ZEND_ACC_PRIVATE);
	phalcon_support_debug_dump_ce->create_object = zephir_init_properties_Phalcon_Support_Debug_Dump;

	zend_class_implements(phalcon_support_debug_dump_ce, 1, phalcon_contracts_support_debug_templateaware_ce);
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
 * Returns the template for the given name (override if set, default
 * otherwise).
 *
 * @param string $name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Dump, getTemplate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, template, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&template);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&template);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("templates"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&template, &_0, &name_zv, 0)) {
		RETURN_CCTOR(&template);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "defaulttemplate", NULL, 0, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
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
 * Overrides the template for the given name.
 *
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
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *name = NULL;
	zval *variable, variable_sub, name_zv, _0, _1, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);
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
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "pre");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "pre");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getstyle", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_array_update_string(&_2, SL("%style%"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "output", NULL, 0, variable, &name_zv);
	zephir_check_call_status();
	zephir_array_update_string(&_2, SL("%output%"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 4, &_0, &_2);
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
	zephir_is_iterable(&_0, 0, "phalcon/Support/Debug/Dump.zep", 243);
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
	zend_class_entry *_80$$16, *_96$$17;
	zend_bool _23$$4, _16$$5, _17$$5, _18$$5, _31$$7, _32$$7, _33$$7, _48$$9, _66$$12, _93$$15, _133$$19;
	zend_ulong _6$$4, _54$$12;
	zval _0$$3;
	zval _194, _3$$4, _13$$5, _28$$7, _40$$9, _110$$9, _45$$10, _60$$13, _71$$14, _86$$16, _101$$17, _122$$21, _129$$22, _139$$24, _146$$25, _158$$26, _165$$27, _171$$28, _177$$29, _185$$30, _190$$31;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_20 = NULL, *_81 = NULL;
	zend_long tab, ZEPHIR_LAST_CALL_STATUS;
	zend_string *name = NULL, *_7$$4, *_55$$12;
	zval *variable, variable_sub, name_zv, *tab_param = NULL, key, value, output, space, type, attr, reflect, props, property, _160, _192, _193, _195, _1$$4, _2$$4, _4$$4, *_5$$4, _22$$4, _36$$4, _37$$4, _8$$5, _9$$5, _11$$5, _12$$5, _14$$5, _15$$5, _19$$5, _21$$5, _24$$7, _25$$7, _26$$7, _27$$7, _29$$7, _30$$7, _34$$7, _35$$7, _38$$9, _39$$9, _41$$9, _42$$9, _47$$9, _107$$9, _108$$9, _109$$9, _111$$9, _112$$9, _152$$9, _153$$9, _43$$10, _44$$10, _46$$10, _49$$11, _50$$11, _51$$11, _52$$12, *_53$$12, _65$$12, _56$$13, _57$$13, _58$$13, _59$$13, _61$$13, _62$$13, _63$$13, _64$$13, _67$$14, _68$$14, _69$$14, _70$$14, _72$$14, _73$$14, _74$$14, _75$$14, _76$$15, *_77$$15, _92$$15, _78$$16, _79$$16, _82$$16, _83$$16, _84$$16, _85$$16, _87$$16, _88$$16, _89$$16, _90$$16, _91$$16, _94$$17, _95$$17, _97$$17, _98$$17, _99$$17, _100$$17, _102$$17, _103$$17, _104$$17, _105$$17, _106$$17, _113$$18, _114$$18, _115$$18, *_116$$19, _132$$19, _149$$19, _150$$19, _151$$19, _117$$20, _118$$21, _119$$21, _120$$21, _121$$21, _123$$21, _124$$21, _125$$22, _126$$22, _127$$22, _128$$22, _130$$22, _131$$22, _134$$23, _135$$24, _136$$24, _137$$24, _138$$24, _140$$24, _141$$24, _142$$25, _143$$25, _144$$25, _145$$25, _147$$25, _148$$25, _154$$26, _155$$26, _156$$26, _157$$26, _159$$26, _161$$27, _162$$27, _163$$27, _164$$27, _166$$27, _167$$28, _168$$28, _169$$28, _170$$28, _172$$28, _173$$29, _174$$29, _175$$29, _176$$29, _178$$29, _179$$29, _180$$29, _181$$30, _182$$30, _183$$30, _184$$30, _186$$30, _187$$30, _188$$31, _189$$31, _191$$31;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&space);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&attr);
	ZVAL_UNDEF(&reflect);
	ZVAL_UNDEF(&props);
	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&_160);
	ZVAL_UNDEF(&_192);
	ZVAL_UNDEF(&_193);
	ZVAL_UNDEF(&_195);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_36$$4);
	ZVAL_UNDEF(&_37$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_34$$7);
	ZVAL_UNDEF(&_35$$7);
	ZVAL_UNDEF(&_38$$9);
	ZVAL_UNDEF(&_39$$9);
	ZVAL_UNDEF(&_41$$9);
	ZVAL_UNDEF(&_42$$9);
	ZVAL_UNDEF(&_47$$9);
	ZVAL_UNDEF(&_107$$9);
	ZVAL_UNDEF(&_108$$9);
	ZVAL_UNDEF(&_109$$9);
	ZVAL_UNDEF(&_111$$9);
	ZVAL_UNDEF(&_112$$9);
	ZVAL_UNDEF(&_152$$9);
	ZVAL_UNDEF(&_153$$9);
	ZVAL_UNDEF(&_43$$10);
	ZVAL_UNDEF(&_44$$10);
	ZVAL_UNDEF(&_46$$10);
	ZVAL_UNDEF(&_49$$11);
	ZVAL_UNDEF(&_50$$11);
	ZVAL_UNDEF(&_51$$11);
	ZVAL_UNDEF(&_52$$12);
	ZVAL_UNDEF(&_65$$12);
	ZVAL_UNDEF(&_56$$13);
	ZVAL_UNDEF(&_57$$13);
	ZVAL_UNDEF(&_58$$13);
	ZVAL_UNDEF(&_59$$13);
	ZVAL_UNDEF(&_61$$13);
	ZVAL_UNDEF(&_62$$13);
	ZVAL_UNDEF(&_63$$13);
	ZVAL_UNDEF(&_64$$13);
	ZVAL_UNDEF(&_67$$14);
	ZVAL_UNDEF(&_68$$14);
	ZVAL_UNDEF(&_69$$14);
	ZVAL_UNDEF(&_70$$14);
	ZVAL_UNDEF(&_72$$14);
	ZVAL_UNDEF(&_73$$14);
	ZVAL_UNDEF(&_74$$14);
	ZVAL_UNDEF(&_75$$14);
	ZVAL_UNDEF(&_76$$15);
	ZVAL_UNDEF(&_92$$15);
	ZVAL_UNDEF(&_78$$16);
	ZVAL_UNDEF(&_79$$16);
	ZVAL_UNDEF(&_82$$16);
	ZVAL_UNDEF(&_83$$16);
	ZVAL_UNDEF(&_84$$16);
	ZVAL_UNDEF(&_85$$16);
	ZVAL_UNDEF(&_87$$16);
	ZVAL_UNDEF(&_88$$16);
	ZVAL_UNDEF(&_89$$16);
	ZVAL_UNDEF(&_90$$16);
	ZVAL_UNDEF(&_91$$16);
	ZVAL_UNDEF(&_94$$17);
	ZVAL_UNDEF(&_95$$17);
	ZVAL_UNDEF(&_97$$17);
	ZVAL_UNDEF(&_98$$17);
	ZVAL_UNDEF(&_99$$17);
	ZVAL_UNDEF(&_100$$17);
	ZVAL_UNDEF(&_102$$17);
	ZVAL_UNDEF(&_103$$17);
	ZVAL_UNDEF(&_104$$17);
	ZVAL_UNDEF(&_105$$17);
	ZVAL_UNDEF(&_106$$17);
	ZVAL_UNDEF(&_113$$18);
	ZVAL_UNDEF(&_114$$18);
	ZVAL_UNDEF(&_115$$18);
	ZVAL_UNDEF(&_132$$19);
	ZVAL_UNDEF(&_149$$19);
	ZVAL_UNDEF(&_150$$19);
	ZVAL_UNDEF(&_151$$19);
	ZVAL_UNDEF(&_117$$20);
	ZVAL_UNDEF(&_118$$21);
	ZVAL_UNDEF(&_119$$21);
	ZVAL_UNDEF(&_120$$21);
	ZVAL_UNDEF(&_121$$21);
	ZVAL_UNDEF(&_123$$21);
	ZVAL_UNDEF(&_124$$21);
	ZVAL_UNDEF(&_125$$22);
	ZVAL_UNDEF(&_126$$22);
	ZVAL_UNDEF(&_127$$22);
	ZVAL_UNDEF(&_128$$22);
	ZVAL_UNDEF(&_130$$22);
	ZVAL_UNDEF(&_131$$22);
	ZVAL_UNDEF(&_134$$23);
	ZVAL_UNDEF(&_135$$24);
	ZVAL_UNDEF(&_136$$24);
	ZVAL_UNDEF(&_137$$24);
	ZVAL_UNDEF(&_138$$24);
	ZVAL_UNDEF(&_140$$24);
	ZVAL_UNDEF(&_141$$24);
	ZVAL_UNDEF(&_142$$25);
	ZVAL_UNDEF(&_143$$25);
	ZVAL_UNDEF(&_144$$25);
	ZVAL_UNDEF(&_145$$25);
	ZVAL_UNDEF(&_147$$25);
	ZVAL_UNDEF(&_148$$25);
	ZVAL_UNDEF(&_154$$26);
	ZVAL_UNDEF(&_155$$26);
	ZVAL_UNDEF(&_156$$26);
	ZVAL_UNDEF(&_157$$26);
	ZVAL_UNDEF(&_159$$26);
	ZVAL_UNDEF(&_161$$27);
	ZVAL_UNDEF(&_162$$27);
	ZVAL_UNDEF(&_163$$27);
	ZVAL_UNDEF(&_164$$27);
	ZVAL_UNDEF(&_166$$27);
	ZVAL_UNDEF(&_167$$28);
	ZVAL_UNDEF(&_168$$28);
	ZVAL_UNDEF(&_169$$28);
	ZVAL_UNDEF(&_170$$28);
	ZVAL_UNDEF(&_172$$28);
	ZVAL_UNDEF(&_173$$29);
	ZVAL_UNDEF(&_174$$29);
	ZVAL_UNDEF(&_175$$29);
	ZVAL_UNDEF(&_176$$29);
	ZVAL_UNDEF(&_178$$29);
	ZVAL_UNDEF(&_179$$29);
	ZVAL_UNDEF(&_180$$29);
	ZVAL_UNDEF(&_181$$30);
	ZVAL_UNDEF(&_182$$30);
	ZVAL_UNDEF(&_183$$30);
	ZVAL_UNDEF(&_184$$30);
	ZVAL_UNDEF(&_186$$30);
	ZVAL_UNDEF(&_187$$30);
	ZVAL_UNDEF(&_188$$31);
	ZVAL_UNDEF(&_189$$31);
	ZVAL_UNDEF(&_191$$31);
	ZVAL_UNDEF(&_194);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_40$$9);
	ZVAL_UNDEF(&_110$$9);
	ZVAL_UNDEF(&_45$$10);
	ZVAL_UNDEF(&_60$$13);
	ZVAL_UNDEF(&_71$$14);
	ZVAL_UNDEF(&_86$$16);
	ZVAL_UNDEF(&_101$$17);
	ZVAL_UNDEF(&_122$$21);
	ZVAL_UNDEF(&_129$$22);
	ZVAL_UNDEF(&_139$$24);
	ZVAL_UNDEF(&_146$$25);
	ZVAL_UNDEF(&_158$$26);
	ZVAL_UNDEF(&_165$$27);
	ZVAL_UNDEF(&_171$$28);
	ZVAL_UNDEF(&_177$$29);
	ZVAL_UNDEF(&_185$$30);
	ZVAL_UNDEF(&_190$$31);
	ZVAL_UNDEF(&_0$$3);
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
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "arrayHeader");
		ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "gettemplate", NULL, 0, &_2$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_create_array(&_3$$4, 2, 0);
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "arr");
		ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "getstyle", NULL, 0, &_2$$4);
		zephir_check_call_status();
		zephir_array_update_string(&_3$$4, SL("%style%"), &_4$$4, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_3$$4, SL("%count%"), zephir_fast_count_int(variable));
		ZEPHIR_CALL_FUNCTION(&_4$$4, "strtr", NULL, 4, &_1$$4, &_3$$4);
		zephir_check_call_status();
		zephir_concat_self(&output, &_4$$4);
		zephir_is_iterable(variable, 0, "phalcon/Support/Debug/Dump.zep", 330);
		if (Z_TYPE_P(variable) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(variable), _6$$4, _7$$4, _5$$4)
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
				ZEPHIR_CALL_FUNCTION(&_9$$5, "str_repeat", &_10, 6, &space, &_8$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZVAL_STRING(&_12$$5, "arrayKey");
				ZEPHIR_CALL_METHOD(&_11$$5, this_ptr, "gettemplate", NULL, 0, &_12$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$5);
				zephir_create_array(&_13$$5, 2, 0);
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZVAL_STRING(&_12$$5, "arr");
				ZEPHIR_CALL_METHOD(&_14$$5, this_ptr, "getstyle", NULL, 0, &_12$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_13$$5, SL("%style%"), &_14$$5, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_13$$5, SL("%key%"), &key, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_FUNCTION(&_14$$5, "strtr", NULL, 4, &_11$$5, &_13$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_15$$5);
				ZEPHIR_CONCAT_VV(&_15$$5, &_9$$5, &_14$$5);
				zephir_concat_self(&output, &_15$$5);
				_16$$5 = tab == 1;
				if (_16$$5) {
					_16$$5 = !ZEPHIR_IS_STRING(&name_zv, "");
				}
				_17$$5 = _16$$5;
				if (_17$$5) {
					_17$$5 = !(Z_TYPE_P(&key) == IS_LONG);
				}
				_18$$5 = _17$$5;
				if (_18$$5) {
					_18$$5 = ZEPHIR_IS_EQUAL(&name_zv, &key);
				}
				if (_18$$5) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZVAL_STRING(&_12$$5, "");
				ZVAL_LONG(&_8$$5, (tab + 1));
				ZEPHIR_CALL_METHOD(&_19$$5, this_ptr, "output", &_20, 0, &value, &_12$$5, &_8$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_21$$5);
				ZEPHIR_CONCAT_VS(&_21$$5, &_19$$5, "\n");
				zephir_concat_self(&output, &_21$$5);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, variable, "rewind", NULL, 0);
			zephir_check_call_status();
			_23$$4 = 1;
			while (1) {
				if (_23$$4) {
					_23$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, variable, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_22$$4, variable, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_22$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, variable, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, variable, "current", NULL, 0);
				zephir_check_call_status();
					ZVAL_LONG(&_24$$7, tab);
					ZEPHIR_CALL_FUNCTION(&_25$$7, "str_repeat", &_10, 6, &space, &_24$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_27$$7);
					ZVAL_STRING(&_27$$7, "arrayKey");
					ZEPHIR_CALL_METHOD(&_26$$7, this_ptr, "gettemplate", NULL, 0, &_27$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_28$$7);
					zephir_create_array(&_28$$7, 2, 0);
					ZEPHIR_INIT_NVAR(&_27$$7);
					ZVAL_STRING(&_27$$7, "arr");
					ZEPHIR_CALL_METHOD(&_29$$7, this_ptr, "getstyle", NULL, 0, &_27$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_28$$7, SL("%style%"), &_29$$7, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_28$$7, SL("%key%"), &key, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_FUNCTION(&_29$$7, "strtr", NULL, 4, &_26$$7, &_28$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_30$$7);
					ZEPHIR_CONCAT_VV(&_30$$7, &_25$$7, &_29$$7);
					zephir_concat_self(&output, &_30$$7);
					_31$$7 = tab == 1;
					if (_31$$7) {
						_31$$7 = !ZEPHIR_IS_STRING(&name_zv, "");
					}
					_32$$7 = _31$$7;
					if (_32$$7) {
						_32$$7 = !(Z_TYPE_P(&key) == IS_LONG);
					}
					_33$$7 = _32$$7;
					if (_33$$7) {
						_33$$7 = ZEPHIR_IS_EQUAL(&name_zv, &key);
					}
					if (_33$$7) {
						continue;
					}
					ZEPHIR_INIT_NVAR(&_27$$7);
					ZVAL_STRING(&_27$$7, "");
					ZVAL_LONG(&_24$$7, (tab + 1));
					ZEPHIR_CALL_METHOD(&_34$$7, this_ptr, "output", &_20, 0, &value, &_27$$7, &_24$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_35$$7);
					ZEPHIR_CONCAT_VS(&_35$$7, &_34$$7, "\n");
					zephir_concat_self(&output, &_35$$7);
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_36$$4, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_37$$4, "str_repeat", &_10, 6, &space, &_36$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_37$$4, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_39$$9);
		ZVAL_STRING(&_39$$9, "objectHeader");
		ZEPHIR_CALL_METHOD(&_38$$9, this_ptr, "gettemplate", NULL, 0, &_39$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_40$$9);
		zephir_create_array(&_40$$9, 2, 0);
		ZEPHIR_INIT_NVAR(&_39$$9);
		ZVAL_STRING(&_39$$9, "obj");
		ZEPHIR_CALL_METHOD(&_41$$9, this_ptr, "getstyle", NULL, 0, &_39$$9);
		zephir_check_call_status();
		zephir_array_update_string(&_40$$9, SL("%style%"), &_41$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_39$$9);
		zephir_get_class(&_39$$9, variable, 0);
		zephir_array_update_string(&_40$$9, SL("%class%"), &_39$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_41$$9, "strtr", NULL, 4, &_38$$9, &_40$$9);
		zephir_check_call_status();
		zephir_concat_self(&output, &_41$$9);
		ZEPHIR_CALL_FUNCTION(&_42$$9, "get_parent_class", NULL, 0, variable);
		zephir_check_call_status();
		if (zephir_is_true(&_42$$9)) {
			ZEPHIR_INIT_VAR(&_44$$10);
			ZVAL_STRING(&_44$$10, "objectExtends");
			ZEPHIR_CALL_METHOD(&_43$$10, this_ptr, "gettemplate", NULL, 0, &_44$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_45$$10);
			zephir_create_array(&_45$$10, 2, 0);
			ZEPHIR_INIT_NVAR(&_44$$10);
			ZVAL_STRING(&_44$$10, "obj");
			ZEPHIR_CALL_METHOD(&_46$$10, this_ptr, "getstyle", NULL, 0, &_44$$10);
			zephir_check_call_status();
			zephir_array_update_string(&_45$$10, SL("%style%"), &_46$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_46$$10, "get_parent_class", NULL, 0, variable);
			zephir_check_call_status();
			zephir_array_update_string(&_45$$10, SL("%parent%"), &_46$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_46$$10, "strtr", NULL, 4, &_43$$10, &_45$$10);
			zephir_check_call_status();
			zephir_concat_self(&output, &_46$$10);
		}
		zephir_concat_self_str(&output, SL(" (\n"));
		if (zephir_instance_of_ev(variable, phalcon_di_diinterface_ce)) {
			ZVAL_LONG(&_49$$11, tab);
			ZEPHIR_CALL_FUNCTION(&_50$$11, "str_repeat", &_10, 6, &space, &_49$$11);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_51$$11);
			ZEPHIR_CONCAT_VS(&_51$$11, &_50$$11, "[skipped]\n");
			zephir_concat_self(&output, &_51$$11);
		} else {
			zephir_read_property(&_47$$9, this_ptr, ZEND_STRL("detailed"), PH_NOISY_CC | PH_READONLY);
			_48$$9 = !zephir_is_true(&_47$$9);
			if (!(_48$$9)) {
				_48$$9 = zephir_is_instance_of(variable, SL("stdClass"));
			}
			if (_48$$9) {
				ZEPHIR_CALL_FUNCTION(&_52$$12, "get_object_vars", NULL, 0, variable);
				zephir_check_call_status();
				zephir_is_iterable(&_52$$12, 0, "phalcon/Support/Debug/Dump.zep", 367);
				if (Z_TYPE_P(&_52$$12) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_52$$12), _54$$12, _55$$12, _53$$12)
					{
						ZEPHIR_INIT_NVAR(&key);
						if (_55$$12 != NULL) { 
							ZVAL_STR_COPY(&key, _55$$12);
						} else {
							ZVAL_LONG(&key, _54$$12);
						}
						ZEPHIR_INIT_NVAR(&value);
						ZVAL_COPY(&value, _53$$12);
						ZVAL_LONG(&_56$$13, tab);
						ZEPHIR_CALL_FUNCTION(&_57$$13, "str_repeat", &_10, 6, &space, &_56$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_59$$13);
						ZVAL_STRING(&_59$$13, "objectProperty");
						ZEPHIR_CALL_METHOD(&_58$$13, this_ptr, "gettemplate", NULL, 0, &_59$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_60$$13);
						zephir_create_array(&_60$$13, 3, 0);
						ZEPHIR_INIT_NVAR(&_59$$13);
						ZVAL_STRING(&_59$$13, "obj");
						ZEPHIR_CALL_METHOD(&_61$$13, this_ptr, "getstyle", NULL, 0, &_59$$13);
						zephir_check_call_status();
						zephir_array_update_string(&_60$$13, SL("%style%"), &_61$$13, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_60$$13, SL("%key%"), &key, PH_COPY | PH_SEPARATE);
						add_assoc_stringl_ex(&_60$$13, SL("%type%"), SL("public"));
						ZEPHIR_CALL_FUNCTION(&_61$$13, "strtr", NULL, 4, &_58$$13, &_60$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_62$$13);
						ZEPHIR_CONCAT_VV(&_62$$13, &_57$$13, &_61$$13);
						zephir_concat_self(&output, &_62$$13);
						ZEPHIR_INIT_NVAR(&_59$$13);
						ZVAL_STRING(&_59$$13, "");
						ZVAL_LONG(&_56$$13, (tab + 1));
						ZEPHIR_CALL_METHOD(&_63$$13, this_ptr, "output", &_20, 0, &value, &_59$$13, &_56$$13);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_64$$13);
						ZEPHIR_CONCAT_VS(&_64$$13, &_63$$13, "\n");
						zephir_concat_self(&output, &_64$$13);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_52$$12, "rewind", NULL, 0);
					zephir_check_call_status();
					_66$$12 = 1;
					while (1) {
						if (_66$$12) {
							_66$$12 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &_52$$12, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_65$$12, &_52$$12, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_65$$12)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&key, &_52$$12, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&value, &_52$$12, "current", NULL, 0);
						zephir_check_call_status();
							ZVAL_LONG(&_67$$14, tab);
							ZEPHIR_CALL_FUNCTION(&_68$$14, "str_repeat", &_10, 6, &space, &_67$$14);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_70$$14);
							ZVAL_STRING(&_70$$14, "objectProperty");
							ZEPHIR_CALL_METHOD(&_69$$14, this_ptr, "gettemplate", NULL, 0, &_70$$14);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_71$$14);
							zephir_create_array(&_71$$14, 3, 0);
							ZEPHIR_INIT_NVAR(&_70$$14);
							ZVAL_STRING(&_70$$14, "obj");
							ZEPHIR_CALL_METHOD(&_72$$14, this_ptr, "getstyle", NULL, 0, &_70$$14);
							zephir_check_call_status();
							zephir_array_update_string(&_71$$14, SL("%style%"), &_72$$14, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_71$$14, SL("%key%"), &key, PH_COPY | PH_SEPARATE);
							add_assoc_stringl_ex(&_71$$14, SL("%type%"), SL("public"));
							ZEPHIR_CALL_FUNCTION(&_72$$14, "strtr", NULL, 4, &_69$$14, &_71$$14);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_73$$14);
							ZEPHIR_CONCAT_VV(&_73$$14, &_68$$14, &_72$$14);
							zephir_concat_self(&output, &_73$$14);
							ZEPHIR_INIT_NVAR(&_70$$14);
							ZVAL_STRING(&_70$$14, "");
							ZVAL_LONG(&_67$$14, (tab + 1));
							ZEPHIR_CALL_METHOD(&_74$$14, this_ptr, "output", &_20, 0, &value, &_70$$14, &_67$$14);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_75$$14);
							ZEPHIR_CONCAT_VS(&_75$$14, &_74$$14, "\n");
							zephir_concat_self(&output, &_75$$14);
					}
				}
				ZEPHIR_INIT_NVAR(&value);
				ZEPHIR_INIT_NVAR(&key);
			} else {
				ZEPHIR_INIT_VAR(&reflect);
				object_init_ex(&reflect, zephir_get_internal_ce(SL("reflectionclass")));
				ZEPHIR_CALL_METHOD(NULL, &reflect, "__construct", NULL, 265, variable);
				zephir_check_call_status();
				ZVAL_LONG(&_76$$15, ((1 | 2) | 4));
				ZEPHIR_CALL_METHOD(&props, &reflect, "getproperties", NULL, 282, &_76$$15);
				zephir_check_call_status();
				zephir_is_iterable(&props, 0, "phalcon/Support/Debug/Dump.zep", 395);
				if (Z_TYPE_P(&props) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&props), _77$$15)
					{
						ZEPHIR_INIT_NVAR(&property);
						ZVAL_COPY(&property, _77$$15);
						ZVAL_BOOL(&_78$$16, 1);
						ZEPHIR_CALL_METHOD(NULL, &property, "setaccessible", NULL, 0, &_78$$16);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&key, &property, "getname", NULL, 0);
						zephir_check_call_status();
						_80$$16 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
						ZEPHIR_CALL_METHOD(&_82$$16, &property, "getmodifiers", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_CE_STATIC(&_79$$16, _80$$16, "getmodifiernames", &_81, 0, &_82$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&type);
						zephir_fast_join_str(&type, SL(" "), &_79$$16);
						ZVAL_LONG(&_78$$16, tab);
						ZEPHIR_CALL_FUNCTION(&_83$$16, "str_repeat", &_10, 6, &space, &_78$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_85$$16);
						ZVAL_STRING(&_85$$16, "objectProperty");
						ZEPHIR_CALL_METHOD(&_84$$16, this_ptr, "gettemplate", NULL, 0, &_85$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_86$$16);
						zephir_create_array(&_86$$16, 3, 0);
						ZEPHIR_INIT_NVAR(&_85$$16);
						ZVAL_STRING(&_85$$16, "obj");
						ZEPHIR_CALL_METHOD(&_87$$16, this_ptr, "getstyle", NULL, 0, &_85$$16);
						zephir_check_call_status();
						zephir_array_update_string(&_86$$16, SL("%style%"), &_87$$16, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_86$$16, SL("%key%"), &key, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_86$$16, SL("%type%"), &type, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_FUNCTION(&_87$$16, "strtr", NULL, 4, &_84$$16, &_86$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_88$$16);
						ZEPHIR_CONCAT_VV(&_88$$16, &_83$$16, &_87$$16);
						zephir_concat_self(&output, &_88$$16);
						ZEPHIR_CALL_METHOD(&_90$$16, &property, "getvalue", NULL, 0, variable);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_85$$16);
						ZVAL_STRING(&_85$$16, "");
						ZVAL_LONG(&_78$$16, (tab + 1));
						ZEPHIR_CALL_METHOD(&_89$$16, this_ptr, "output", &_20, 0, &_90$$16, &_85$$16, &_78$$16);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_91$$16);
						ZEPHIR_CONCAT_VS(&_91$$16, &_89$$16, "\n");
						zephir_concat_self(&output, &_91$$16);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &props, "rewind", NULL, 0);
					zephir_check_call_status();
					_93$$15 = 1;
					while (1) {
						if (_93$$15) {
							_93$$15 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &props, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_92$$15, &props, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_92$$15)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&property, &props, "current", NULL, 0);
						zephir_check_call_status();
							ZVAL_BOOL(&_94$$17, 1);
							ZEPHIR_CALL_METHOD(NULL, &property, "setaccessible", NULL, 0, &_94$$17);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&key, &property, "getname", NULL, 0);
							zephir_check_call_status();
							_96$$17 = zephir_fetch_class_str_ex(SL("Reflection"), ZEND_FETCH_CLASS_AUTO);
							ZEPHIR_CALL_METHOD(&_97$$17, &property, "getmodifiers", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_CE_STATIC(&_95$$17, _96$$17, "getmodifiernames", &_81, 0, &_97$$17);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&type);
							zephir_fast_join_str(&type, SL(" "), &_95$$17);
							ZVAL_LONG(&_94$$17, tab);
							ZEPHIR_CALL_FUNCTION(&_98$$17, "str_repeat", &_10, 6, &space, &_94$$17);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_100$$17);
							ZVAL_STRING(&_100$$17, "objectProperty");
							ZEPHIR_CALL_METHOD(&_99$$17, this_ptr, "gettemplate", NULL, 0, &_100$$17);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_101$$17);
							zephir_create_array(&_101$$17, 3, 0);
							ZEPHIR_INIT_NVAR(&_100$$17);
							ZVAL_STRING(&_100$$17, "obj");
							ZEPHIR_CALL_METHOD(&_102$$17, this_ptr, "getstyle", NULL, 0, &_100$$17);
							zephir_check_call_status();
							zephir_array_update_string(&_101$$17, SL("%style%"), &_102$$17, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_101$$17, SL("%key%"), &key, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_101$$17, SL("%type%"), &type, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_FUNCTION(&_102$$17, "strtr", NULL, 4, &_99$$17, &_101$$17);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_103$$17);
							ZEPHIR_CONCAT_VV(&_103$$17, &_98$$17, &_102$$17);
							zephir_concat_self(&output, &_103$$17);
							ZEPHIR_CALL_METHOD(&_105$$17, &property, "getvalue", NULL, 0, variable);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_100$$17);
							ZVAL_STRING(&_100$$17, "");
							ZVAL_LONG(&_94$$17, (tab + 1));
							ZEPHIR_CALL_METHOD(&_104$$17, this_ptr, "output", &_20, 0, &_105$$17, &_100$$17, &_94$$17);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_106$$17);
							ZEPHIR_CONCAT_VS(&_106$$17, &_104$$17, "\n");
							zephir_concat_self(&output, &_106$$17);
					}
				}
				ZEPHIR_INIT_NVAR(&property);
			}
		}
		ZEPHIR_CALL_FUNCTION(&attr, "get_class_methods", NULL, 0, variable);
		zephir_check_call_status();
		ZVAL_LONG(&_107$$9, tab);
		ZEPHIR_CALL_FUNCTION(&_108$$9, "str_repeat", &_10, 6, &space, &_107$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_39$$9);
		ZVAL_STRING(&_39$$9, "objectMethods");
		ZEPHIR_CALL_METHOD(&_109$$9, this_ptr, "gettemplate", NULL, 0, &_39$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_110$$9);
		zephir_create_array(&_110$$9, 3, 0);
		ZEPHIR_INIT_NVAR(&_39$$9);
		ZVAL_STRING(&_39$$9, "obj");
		ZEPHIR_CALL_METHOD(&_111$$9, this_ptr, "getstyle", NULL, 0, &_39$$9);
		zephir_check_call_status();
		zephir_array_update_string(&_110$$9, SL("%style%"), &_111$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_39$$9);
		zephir_get_class(&_39$$9, variable, 0);
		zephir_array_update_string(&_110$$9, SL("%class%"), &_39$$9, PH_COPY | PH_SEPARATE);
		add_assoc_long_ex(&_110$$9, SL("%count%"), zephir_fast_count_int(&attr));
		ZEPHIR_CALL_FUNCTION(&_111$$9, "strtr", NULL, 4, &_109$$9, &_110$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_112$$9);
		ZEPHIR_CONCAT_VV(&_112$$9, &_108$$9, &_111$$9);
		zephir_concat_self(&output, &_112$$9);
		ZEPHIR_INIT_NVAR(&_39$$9);
		zephir_get_class(&_39$$9, variable, 0);
		zephir_read_property(&_107$$9, this_ptr, ZEND_STRL("methods"), PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&_39$$9, &_107$$9)) {
			ZVAL_LONG(&_113$$18, tab);
			ZEPHIR_CALL_FUNCTION(&_114$$18, "str_repeat", &_10, 6, &space, &_113$$18);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_115$$18);
			ZEPHIR_CONCAT_VS(&_115$$18, &_114$$18, "[already listed]\n");
			zephir_concat_self(&output, &_115$$18);
		} else {
			zephir_is_iterable(&attr, 0, "phalcon/Support/Debug/Dump.zep", 425);
			if (Z_TYPE_P(&attr) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attr), _116$$19)
				{
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _116$$19);
					ZEPHIR_INIT_NVAR(&_117$$20);
					zephir_get_class(&_117$$20, variable, 0);
					zephir_update_property_array_append(this_ptr, SL("methods"), &_117$$20);
					if (ZEPHIR_IS_STRING(&value, "__construct")) {
						ZVAL_LONG(&_118$$21, (tab + 1));
						ZEPHIR_CALL_FUNCTION(&_119$$21, "str_repeat", &_10, 6, &space, &_118$$21);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_121$$21);
						ZVAL_STRING(&_121$$21, "objectMethodConstructor");
						ZEPHIR_CALL_METHOD(&_120$$21, this_ptr, "gettemplate", NULL, 0, &_121$$21);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_122$$21);
						zephir_create_array(&_122$$21, 2, 0);
						ZEPHIR_INIT_NVAR(&_121$$21);
						ZVAL_STRING(&_121$$21, "obj");
						ZEPHIR_CALL_METHOD(&_123$$21, this_ptr, "getstyle", NULL, 0, &_121$$21);
						zephir_check_call_status();
						zephir_array_update_string(&_122$$21, SL("%style%"), &_123$$21, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_122$$21, SL("%method%"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_FUNCTION(&_123$$21, "strtr", NULL, 4, &_120$$21, &_122$$21);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_124$$21);
						ZEPHIR_CONCAT_VV(&_124$$21, &_119$$21, &_123$$21);
						zephir_concat_self(&output, &_124$$21);
					} else {
						ZVAL_LONG(&_125$$22, (tab + 1));
						ZEPHIR_CALL_FUNCTION(&_126$$22, "str_repeat", &_10, 6, &space, &_125$$22);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_128$$22);
						ZVAL_STRING(&_128$$22, "objectMethod");
						ZEPHIR_CALL_METHOD(&_127$$22, this_ptr, "gettemplate", NULL, 0, &_128$$22);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_129$$22);
						zephir_create_array(&_129$$22, 2, 0);
						ZEPHIR_INIT_NVAR(&_128$$22);
						ZVAL_STRING(&_128$$22, "obj");
						ZEPHIR_CALL_METHOD(&_130$$22, this_ptr, "getstyle", NULL, 0, &_128$$22);
						zephir_check_call_status();
						zephir_array_update_string(&_129$$22, SL("%style%"), &_130$$22, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_129$$22, SL("%method%"), &value, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_FUNCTION(&_130$$22, "strtr", NULL, 4, &_127$$22, &_129$$22);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_131$$22);
						ZEPHIR_CONCAT_VV(&_131$$22, &_126$$22, &_130$$22);
						zephir_concat_self(&output, &_131$$22);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &attr, "rewind", NULL, 0);
				zephir_check_call_status();
				_133$$19 = 1;
				while (1) {
					if (_133$$19) {
						_133$$19 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &attr, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_132$$19, &attr, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_132$$19)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&value, &attr, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_134$$23);
						zephir_get_class(&_134$$23, variable, 0);
						zephir_update_property_array_append(this_ptr, SL("methods"), &_134$$23);
						if (ZEPHIR_IS_STRING(&value, "__construct")) {
							ZVAL_LONG(&_135$$24, (tab + 1));
							ZEPHIR_CALL_FUNCTION(&_136$$24, "str_repeat", &_10, 6, &space, &_135$$24);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_138$$24);
							ZVAL_STRING(&_138$$24, "objectMethodConstructor");
							ZEPHIR_CALL_METHOD(&_137$$24, this_ptr, "gettemplate", NULL, 0, &_138$$24);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_139$$24);
							zephir_create_array(&_139$$24, 2, 0);
							ZEPHIR_INIT_NVAR(&_138$$24);
							ZVAL_STRING(&_138$$24, "obj");
							ZEPHIR_CALL_METHOD(&_140$$24, this_ptr, "getstyle", NULL, 0, &_138$$24);
							zephir_check_call_status();
							zephir_array_update_string(&_139$$24, SL("%style%"), &_140$$24, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_139$$24, SL("%method%"), &value, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_FUNCTION(&_140$$24, "strtr", NULL, 4, &_137$$24, &_139$$24);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_141$$24);
							ZEPHIR_CONCAT_VV(&_141$$24, &_136$$24, &_140$$24);
							zephir_concat_self(&output, &_141$$24);
						} else {
							ZVAL_LONG(&_142$$25, (tab + 1));
							ZEPHIR_CALL_FUNCTION(&_143$$25, "str_repeat", &_10, 6, &space, &_142$$25);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_145$$25);
							ZVAL_STRING(&_145$$25, "objectMethod");
							ZEPHIR_CALL_METHOD(&_144$$25, this_ptr, "gettemplate", NULL, 0, &_145$$25);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_146$$25);
							zephir_create_array(&_146$$25, 2, 0);
							ZEPHIR_INIT_NVAR(&_145$$25);
							ZVAL_STRING(&_145$$25, "obj");
							ZEPHIR_CALL_METHOD(&_147$$25, this_ptr, "getstyle", NULL, 0, &_145$$25);
							zephir_check_call_status();
							zephir_array_update_string(&_146$$25, SL("%style%"), &_147$$25, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_146$$25, SL("%method%"), &value, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_FUNCTION(&_147$$25, "strtr", NULL, 4, &_144$$25, &_146$$25);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_148$$25);
							ZEPHIR_CONCAT_VV(&_148$$25, &_143$$25, &_147$$25);
							zephir_concat_self(&output, &_148$$25);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_LONG(&_149$$19, tab);
			ZEPHIR_CALL_FUNCTION(&_150$$19, "str_repeat", &_10, 6, &space, &_149$$19);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_151$$19);
			ZEPHIR_CONCAT_VS(&_151$$19, &_150$$19, ")\n");
			zephir_concat_self(&output, &_151$$19);
		}
		ZVAL_LONG(&_152$$9, (tab - 1));
		ZEPHIR_CALL_FUNCTION(&_153$$9, "str_repeat", &_10, 6, &space, &_152$$9);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVS(return_value, &output, &_153$$9, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_LONG) {
		ZEPHIR_INIT_VAR(&_155$$26);
		ZVAL_STRING(&_155$$26, "Integer");
		ZEPHIR_CALL_METHOD(&_154$$26, this_ptr, "getoutputbold", NULL, 0, &_155$$26);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_155$$26);
		ZVAL_STRING(&_155$$26, "varParens");
		ZEPHIR_CALL_METHOD(&_156$$26, this_ptr, "gettemplate", NULL, 0, &_155$$26);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_157$$26);
		ZEPHIR_CONCAT_VSV(&_157$$26, &_154$$26, " ", &_156$$26);
		ZEPHIR_INIT_VAR(&_158$$26);
		zephir_create_array(&_158$$26, 2, 0);
		ZEPHIR_INIT_NVAR(&_155$$26);
		ZVAL_STRING(&_155$$26, "int");
		ZEPHIR_CALL_METHOD(&_159$$26, this_ptr, "getstyle", NULL, 0, &_155$$26);
		zephir_check_call_status();
		zephir_array_update_string(&_158$$26, SL("%style%"), &_159$$26, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_158$$26, SL("%var%"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_159$$26, "strtr", NULL, 4, &_157$$26, &_158$$26);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_159$$26);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_160, "is_float", NULL, 30, variable);
	zephir_check_call_status();
	if (zephir_is_true(&_160)) {
		ZEPHIR_INIT_VAR(&_162$$27);
		ZVAL_STRING(&_162$$27, "Float");
		ZEPHIR_CALL_METHOD(&_161$$27, this_ptr, "getoutputbold", NULL, 0, &_162$$27);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_162$$27);
		ZVAL_STRING(&_162$$27, "varParens");
		ZEPHIR_CALL_METHOD(&_163$$27, this_ptr, "gettemplate", NULL, 0, &_162$$27);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_164$$27);
		ZEPHIR_CONCAT_VSV(&_164$$27, &_161$$27, " ", &_163$$27);
		ZEPHIR_INIT_VAR(&_165$$27);
		zephir_create_array(&_165$$27, 2, 0);
		ZEPHIR_INIT_NVAR(&_162$$27);
		ZVAL_STRING(&_162$$27, "float");
		ZEPHIR_CALL_METHOD(&_166$$27, this_ptr, "getstyle", NULL, 0, &_162$$27);
		zephir_check_call_status();
		zephir_array_update_string(&_165$$27, SL("%style%"), &_166$$27, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_165$$27, SL("%var%"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_166$$27, "strtr", NULL, 4, &_164$$27, &_165$$27);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_166$$27);
		RETURN_MM();
	}
	if (zephir_is_numeric(variable)) {
		ZEPHIR_INIT_VAR(&_168$$28);
		ZVAL_STRING(&_168$$28, "Numeric String");
		ZEPHIR_CALL_METHOD(&_167$$28, this_ptr, "getoutputbold", NULL, 0, &_168$$28);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_168$$28);
		ZVAL_STRING(&_168$$28, "lengthValue");
		ZEPHIR_CALL_METHOD(&_169$$28, this_ptr, "gettemplate", NULL, 0, &_168$$28);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_170$$28);
		ZEPHIR_CONCAT_VSV(&_170$$28, &_167$$28, " ", &_169$$28);
		ZEPHIR_INIT_VAR(&_171$$28);
		zephir_create_array(&_171$$28, 3, 0);
		ZEPHIR_INIT_NVAR(&_168$$28);
		ZVAL_STRING(&_168$$28, "num");
		ZEPHIR_CALL_METHOD(&_172$$28, this_ptr, "getstyle", NULL, 0, &_168$$28);
		zephir_check_call_status();
		zephir_array_update_string(&_171$$28, SL("%style%"), &_172$$28, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_172$$28, "mb_strlen", NULL, 0, variable);
		zephir_check_call_status();
		zephir_array_update_string(&_171$$28, SL("%length%"), &_172$$28, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_171$$28, SL("%var%"), variable, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_172$$28, "strtr", NULL, 4, &_170$$28, &_171$$28);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_172$$28);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_174$$29);
		ZVAL_STRING(&_174$$29, "String");
		ZEPHIR_CALL_METHOD(&_173$$29, this_ptr, "getoutputbold", NULL, 0, &_174$$29);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_174$$29);
		ZVAL_STRING(&_174$$29, "lengthValue");
		ZEPHIR_CALL_METHOD(&_175$$29, this_ptr, "gettemplate", NULL, 0, &_174$$29);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_176$$29);
		ZEPHIR_CONCAT_VSV(&_176$$29, &_173$$29, " ", &_175$$29);
		ZEPHIR_INIT_VAR(&_177$$29);
		zephir_create_array(&_177$$29, 3, 0);
		ZEPHIR_INIT_NVAR(&_174$$29);
		ZVAL_STRING(&_174$$29, "str");
		ZEPHIR_CALL_METHOD(&_178$$29, this_ptr, "getstyle", NULL, 0, &_174$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_177$$29, SL("%style%"), &_178$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_178$$29, "mb_strlen", NULL, 0, variable);
		zephir_check_call_status();
		zephir_array_update_string(&_177$$29, SL("%length%"), &_178$$29, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_179$$29, 4);
		ZEPHIR_INIT_NVAR(&_174$$29);
		ZVAL_STRING(&_174$$29, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_178$$29, "htmlentities", NULL, 0, variable, &_179$$29, &_174$$29);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_180$$29, "nl2br", NULL, 0, &_178$$29);
		zephir_check_call_status();
		zephir_array_update_string(&_177$$29, SL("%var%"), &_180$$29, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_180$$29, "strtr", NULL, 4, &_176$$29, &_177$$29);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_180$$29);
		RETURN_MM();
	}
	if ((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE)) {
		ZEPHIR_INIT_VAR(&_182$$30);
		ZVAL_STRING(&_182$$30, "Boolean");
		ZEPHIR_CALL_METHOD(&_181$$30, this_ptr, "getoutputbold", NULL, 0, &_182$$30);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_182$$30);
		ZVAL_STRING(&_182$$30, "varParens");
		ZEPHIR_CALL_METHOD(&_183$$30, this_ptr, "gettemplate", NULL, 0, &_182$$30);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_184$$30);
		ZEPHIR_CONCAT_VSV(&_184$$30, &_181$$30, " ", &_183$$30);
		ZEPHIR_INIT_VAR(&_185$$30);
		zephir_create_array(&_185$$30, 2, 0);
		ZEPHIR_INIT_NVAR(&_182$$30);
		ZVAL_STRING(&_182$$30, "bool");
		ZEPHIR_CALL_METHOD(&_186$$30, this_ptr, "getstyle", NULL, 0, &_182$$30);
		zephir_check_call_status();
		zephir_array_update_string(&_185$$30, SL("%style%"), &_186$$30, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_187$$30);
		if (zephir_is_true(variable)) {
			ZEPHIR_INIT_NVAR(&_187$$30);
			ZVAL_STRING(&_187$$30, "TRUE");
		} else {
			ZEPHIR_INIT_NVAR(&_187$$30);
			ZVAL_STRING(&_187$$30, "FALSE");
		}
		zephir_array_update_string(&_185$$30, SL("%var%"), &_187$$30, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_186$$30, "strtr", NULL, 4, &_184$$30, &_185$$30);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_186$$30);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_189$$31);
		ZVAL_STRING(&_189$$31, "NULL");
		ZEPHIR_CALL_METHOD(&_188$$31, this_ptr, "getoutputbold", NULL, 0, &_189$$31);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_190$$31);
		zephir_create_array(&_190$$31, 1, 0);
		ZEPHIR_INIT_NVAR(&_189$$31);
		ZVAL_STRING(&_189$$31, "null");
		ZEPHIR_CALL_METHOD(&_191$$31, this_ptr, "getstyle", NULL, 0, &_189$$31);
		zephir_check_call_status();
		zephir_array_update_string(&_190$$31, SL("%style%"), &_191$$31, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_191$$31, "strtr", NULL, 4, &_188$$31, &_190$$31);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(return_value, &output, &_191$$31);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_193);
	ZVAL_STRING(&_193, "varParens");
	ZEPHIR_CALL_METHOD(&_192, this_ptr, "gettemplate", NULL, 0, &_193);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_194);
	zephir_create_array(&_194, 2, 0);
	ZEPHIR_INIT_NVAR(&_193);
	ZVAL_STRING(&_193, "other");
	ZEPHIR_CALL_METHOD(&_195, this_ptr, "getstyle", NULL, 0, &_193);
	zephir_check_call_status();
	zephir_array_update_string(&_194, SL("%style%"), &_195, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_194, SL("%var%"), variable, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_195, "strtr", NULL, 4, &_192, &_194);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &output, &_195);
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
	zephir_array_update_string(&_2, SL("%text%"), &text_zv, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 4, &_0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Support_Debug_Dump(zend_class_entry *class_type)
{
		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("templates"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("templates"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("styles"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("styles"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("methods"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("methods"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

