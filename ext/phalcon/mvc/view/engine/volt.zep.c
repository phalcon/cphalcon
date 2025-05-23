
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/require.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Designer friendly and fast template engine for PHP written in Zephir/C
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\View\\Engine, Volt, phalcon, mvc_view_engine_volt, phalcon_mvc_view_engine_abstractengine_ce, phalcon_mvc_view_engine_volt_method_entry, 0);

	/**
	 * @var Compiler
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_ce, SL("compiler"), ZEND_ACC_PROTECTED);
	/**
	 * @var ManagerInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_ce, SL("eventsManager"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_ce, SL("macros"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_ce, SL("options"), ZEND_ACC_PROTECTED);
	phalcon_mvc_view_engine_volt_ce->create_object = zephir_init_properties_Phalcon_Mvc_View_Engine_Volt;

	zend_class_implements(phalcon_mvc_view_engine_volt_ce, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;
}

/**
 * Checks if a macro is defined and calls it
 *
 * @params string name
 * @params array arguments
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, callMacro)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments;
	zval *name_param = NULL, *arguments_param = NULL, macro, _0, _1$$3;
	zval name, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&macro);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&arguments);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(arguments)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &name_param, &arguments_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
		zephir_get_arrval(&arguments, arguments_param);
	}
	zephir_memory_observe(&macro);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("macros"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&macro, &_0, &name, 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_view_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Macro '", &name, "' does not exist");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 33, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/View/Engine/Volt.zep", 59);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", NULL, 188, &macro, &arguments);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Performs a string conversion
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, convertEncoding)
{
	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *from_param = NULL, *to_param = NULL;
	zval text, from, to;

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&to);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(text)
		Z_PARAM_STR(from)
		Z_PARAM_STR(to)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &text_param, &from_param, &to_param);
	zephir_get_strval(&text, text_param);
	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(&from, from_param);
	} else {
		ZEPHIR_INIT_VAR(&from);
	}
	if (UNEXPECTED(Z_TYPE_P(to_param) != IS_STRING && Z_TYPE_P(to_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'to' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(to_param) == IS_STRING)) {
		zephir_get_strval(&to, to_param);
	} else {
		ZEPHIR_INIT_VAR(&to);
	}
	_0 = ZEPHIR_IS_STRING_IDENTICAL(&from, "latin1");
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING_IDENTICAL(&to, "utf8");
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_FUNCTION("utf8_encode", NULL, 498, &text);
		zephir_check_call_status();
		RETURN_MM();
	}
	_1 = ZEPHIR_IS_STRING_IDENTICAL(&to, "latin1");
	if (!(_1)) {
		_1 = ZEPHIR_IS_STRING_IDENTICAL(&from, "utf8");
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_FUNCTION("utf8_decode", NULL, 285, &text);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_function_exists_ex(ZEND_STRL("mb_convert_encoding")) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("mb_convert_encoding", NULL, 327, &text, &from, &to);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "'mbstring' is required to perform the charset conversion", "phalcon/Mvc/View/Engine/Volt.zep", 98);
	return;
}

/**
 * Returns the Volt's compiler
 *
 * @return Compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getCompiler)
{
	zval compiler, container, options, _0, _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&compiler);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("compiler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&compiler, &_0);
	if (Z_TYPE_P(&compiler) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&compiler);
		object_init_ex(&compiler, phalcon_mvc_view_engine_volt_compiler_ce);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("view"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &compiler, "__construct", NULL, 499, &_1$$3);
		zephir_check_call_status();
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&container, &_2$$3);
		if (Z_TYPE_P(&container) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(NULL, &compiler, "setdi", NULL, 500, &container);
			zephir_check_call_status();
		}
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&options, &_2$$3);
		if (Z_TYPE_P(&options) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(NULL, &compiler, "setoptions", NULL, 501, &options);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("compiler"), &compiler);
	}
	RETURN_CCTOR(&compiler);
}

/**
 * Returns the internal event manager
 *
 * @return ManagerInterface|null
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getEventsManager)
{

	RETURN_MEMBER(getThis(), "eventsManager");
}

/**
 * Return Volt's options
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getOptions)
{

	RETURN_MEMBER(getThis(), "options");
}

/**
 * Checks if the needle is included in the haystack
 *
 * @param mixed needle
 * @param array|string haystack
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, isIncluded)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *needle = NULL, needle_sub, *haystack, haystack_sub, _0$$6, _1$$5;

	ZVAL_UNDEF(&needle_sub);
	ZVAL_UNDEF(&haystack_sub);
	ZVAL_UNDEF(&_0$$6);
	ZVAL_UNDEF(&_1$$5);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(needle)
		Z_PARAM_ZVAL(haystack)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &needle, &haystack);
	ZEPHIR_SEPARATE_PARAM(needle);
	if (UNEXPECTED(Z_TYPE_P(needle) == IS_NULL)) {
		ZEPHIR_INIT_NVAR(needle);
		ZVAL_STRING(needle, "");
	}
	if (Z_TYPE_P(haystack) == IS_ARRAY) {
		RETURN_MM_BOOL(zephir_fast_in_array(needle, haystack));
	}
	if (Z_TYPE_P(haystack) == IS_STRING) {
		if ((zephir_function_exists_ex(ZEND_STRL("mb_strpos")) == SUCCESS)) {
			ZEPHIR_CALL_FUNCTION(&_0$$6, "mb_strpos", NULL, 86, haystack, needle);
			zephir_check_call_status();
			RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_0$$6));
		}
		ZEPHIR_INIT_VAR(&_1$$5);
		zephir_fast_strpos(&_1$$5, haystack, needle, 0 );
		RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_1$$5));
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "Invalid haystack", "phalcon/Mvc/View/Engine/Volt.zep", 185);
	return;
}

/**
 * Length filter. If an array/object is passed a count is performed otherwise a strlen/mb_strlen
 *
 * @param mixed item
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, length)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item = NULL, item_sub;

	ZVAL_UNDEF(&item_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(item)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &item);
	ZEPHIR_SEPARATE_PARAM(item);
	if (UNEXPECTED(Z_TYPE_P(item) == IS_NULL)) {
		ZEPHIR_INIT_NVAR(item);
		ZVAL_STRING(item, "");
	}
	_0 = Z_TYPE_P(item) == IS_OBJECT;
	if (!(_0)) {
		_0 = Z_TYPE_P(item) == IS_ARRAY;
	}
	if (_0) {
		RETURN_MM_LONG(zephir_fast_count_int(item));
	}
	if ((zephir_function_exists_ex(ZEND_STRL("mb_strlen")) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("mb_strlen", NULL, 246, item);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_LONG(zephir_fast_strlen_ev(item));
}

/**
 * Parses the preload element passed and sets the necessary link headers
 * @todo find a better way to handle this
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, preload)
{
	zval _10$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters, parameters_sub, attributes, container, header, href, link, params, response, _1, _2, _3, _0$$3, _4$$7, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&href);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(parameters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &parameters);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0);
		zephir_array_fast_append(&_0$$3, parameters);
		ZEPHIR_CPY_WRT(&params, &_0$$3);
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	zephir_memory_observe(&href);
	zephir_array_isset_long_fetch(&href, &params, 0, 0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_1);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "response");
	ZEPHIR_CALL_METHOD(&_2, &container, "has", NULL, 0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		if (zephir_array_isset_long(&params, 1)) {
			zephir_memory_observe(&attributes);
			zephir_array_fetch_long(&attributes, &params, 1, PH_NOISY, "phalcon/Mvc/View/Engine/Volt.zep", 240);
		} else {
			ZEPHIR_INIT_VAR(&_4$$7);
			zephir_create_array(&_4$$7, 1, 0);
			add_assoc_stringl_ex(&_4$$7, SL("as"), SL("style"));
			ZEPHIR_CPY_WRT(&attributes, &_4$$7);
		}
		ZEPHIR_INIT_VAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "response");
		ZEPHIR_CALL_METHOD(&response, &container, "get", NULL, 0, &_5$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&link);
		object_init_ex(&link, phalcon_html_link_link_ce);
		ZEPHIR_INIT_NVAR(&_5$$5);
		ZEPHIR_INIT_VAR(&_6$$5);
		ZVAL_STRING(&_6$$5, "'");
		ZEPHIR_INIT_VAR(&_7$$5);
		ZVAL_STRING(&_7$$5, "");
		zephir_fast_str_replace(&_5$$5, &_6$$5, &_7$$5, &href);
		ZEPHIR_INIT_VAR(&_8$$5);
		ZVAL_STRING(&_8$$5, "preload");
		ZEPHIR_CALL_METHOD(NULL, &link, "__construct", NULL, 502, &_8$$5, &_5$$5, &attributes);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_8$$5);
		object_init_ex(&_8$$5, phalcon_html_link_serializer_header_ce);
		if (zephir_has_constructor(&_8$$5)) {
			ZEPHIR_CALL_METHOD(NULL, &_8$$5, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZEPHIR_INIT_VAR(&_10$$5);
		zephir_create_array(&_10$$5, 1, 0);
		zephir_array_fast_append(&_10$$5, &link);
		ZEPHIR_CALL_METHOD(&_9$$5, &_8$$5, "serialize", NULL, 503, &_10$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&header);
		ZEPHIR_CONCAT_SV(&header, "Link: ", &_9$$5);
		ZEPHIR_CALL_METHOD(NULL, &response, "setrawheader", NULL, 0, &header);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&href);
}

/**
 * Renders a view using the template engine
 *
 * @param string path
 * @param mixed params
 * @params bool mustClean
 *
 * @return void
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, render)
{
	zend_string *_8$$8;
	zend_ulong _7$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool mustClean;
	zval *path_param = NULL, *params, params_sub, *mustClean_param = NULL, compiler, compiledTemplatePath, eventsManager, key, value, _0, _1$$4, _2$$4, _3$$6, _4$$6, *_5$$8, _6$$8, _9$$9, _10$$10, _11$$11, _12$$11;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&compiler);
	ZVAL_UNDEF(&compiledTemplatePath);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(path)
		Z_PARAM_ZVAL(params)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(mustClean)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &path_param, &params, &mustClean_param);
	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
	}
	if (!mustClean_param) {
		mustClean = 0;
	} else {
		}
	if (mustClean) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_clean", NULL, 497);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&compiler, this_ptr, "getcompiler", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "view:beforeCompile");
		ZEPHIR_CALL_METHOD(&_1$$4, &eventsManager, "fire", NULL, 0, &_2$$4, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_1$$4)) {
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &compiler, "compile", NULL, 0, &path);
	zephir_check_call_status();
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_4$$6);
		ZVAL_STRING(&_4$$6, "view:afterCompile");
		ZEPHIR_CALL_METHOD(&_3$$6, &eventsManager, "fire", NULL, 0, &_4$$6, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_3$$6)) {
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_CALL_METHOD(&compiledTemplatePath, &compiler, "getcompiledtemplatepath", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(params) == IS_ARRAY) {
		zephir_is_iterable(params, 0, "phalcon/Mvc/View/Engine/Volt.zep", 308);
		if (Z_TYPE_P(params) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(params), _7$$8, _8$$8, _5$$8)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_8$$8 != NULL) { 
					ZVAL_STR_COPY(&key, _8$$8);
				} else {
					ZVAL_LONG(&key, _7$$8);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _5$$8);
				ZEPHIR_CPY_WRT(&_9$$9, &value);
				if (zephir_set_symbol(&key, &_9$$9) == FAILURE) {
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, params, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_6$$8, params, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$8)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, params, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, params, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CPY_WRT(&_10$$10, &value);
					if (zephir_set_symbol(&key, &_10$$10) == FAILURE) {
						return;
					}
				ZEPHIR_CALL_METHOD(NULL, params, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	}
	if (zephir_require_zval(&compiledTemplatePath) == FAILURE) {
		RETURN_MM_NULL();
	}
	if (mustClean) {
		zephir_read_property(&_11$$11, this_ptr, ZEND_STRL("view"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_12$$11, "ob_get_contents", NULL, 496);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_11$$11, "setcontent", NULL, 0, &_12$$11);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the events manager
 *
 * @param ManagerInterface eventsManager
 *
 * @return void
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, setEventsManager)
{
	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);
	zephir_update_property_zval(this_ptr, ZEND_STRL("eventsManager"), eventsManager);
}

/**
 * Set Volt's options
 *
 * @param array options
 *
 * @return void
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, setOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &options_param);
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	ZEPHIR_MM_RESTORE();
}

/**
 * Extracts a slice from a string/array/traversable object value
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, slice)
{
	zend_bool _1$$5;
	zval slice;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zend_long start, ZEPHIR_LAST_CALL_STATUS, position = 0;
	zval *value, value_sub, *start_param = NULL, *end = NULL, end_sub, __$null, length, _9, _0$$3, _2$$6, _5$$9, _6$$11, _7$$10, _8$$12;

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&end_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&slice);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(start)
		Z_PARAM_ZVAL_OR_NULL(end)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &value, &start_param, &end);
	if (!start_param) {
		start = 0;
	} else {
		}
	if (!end) {
		end = &end_sub;
		ZEPHIR_CPY_WRT(end, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(end);
	}
	if (Z_TYPE_P(value) == IS_OBJECT) {
		if (Z_TYPE_P(end) == IS_NULL) {
			ZEPHIR_INIT_NVAR(end);
			ZVAL_LONG(end, (zephir_fast_count_int(value) - 1));
		}
		position = 0;
		ZEPHIR_INIT_VAR(&slice);
		array_init(&slice);
		ZEPHIR_CALL_METHOD(NULL, value, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_0$$3, value, "valid", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_0$$3))) {
				break;
			}
			_1$$5 = position >= start;
			if (_1$$5) {
				_1$$5 = ZEPHIR_GE_LONG(end, position);
			}
			if (_1$$5) {
				ZEPHIR_CALL_METHOD(&_2$$6, value, "current", &_3, 0);
				zephir_check_call_status();
				zephir_array_append(&slice, &_2$$6, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt.zep", 365);
			}
			ZEPHIR_CALL_METHOD(NULL, value, "next", &_4, 0);
			zephir_check_call_status();
			position++;
		}
		RETURN_CTOR(&slice);
	}
	ZEPHIR_INIT_VAR(&length);
	if (Z_TYPE_P(end) != IS_NULL) {
		ZVAL_LONG(&length, (((zephir_get_numberval(end) - start)) + 1));
	} else {
		ZVAL_NULL(&length);
	}
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZVAL_LONG(&_5$$9, start);
		ZEPHIR_RETURN_CALL_FUNCTION("array_slice", NULL, 504, value, &_5$$9, &length);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_function_exists_ex(ZEND_STRL("mb_substr")) == SUCCESS)) {
		if (Z_TYPE_P(&length) != IS_NULL) {
			ZVAL_LONG(&_6$$11, start);
			ZEPHIR_RETURN_CALL_FUNCTION("mb_substr", NULL, 228, value, &_6$$11, &length);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZVAL_LONG(&_7$$10, start);
		ZEPHIR_RETURN_CALL_FUNCTION("mb_substr", NULL, 228, value, &_7$$10);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(&length) != IS_NULL) {
		ZVAL_LONG(&_8$$12, start);
		zephir_substr(return_value, value, zephir_get_intval(&_8$$12), zephir_get_intval(&length), 0);
		RETURN_MM();
	}
	ZVAL_LONG(&_9, start);
	zephir_substr(return_value, value, zephir_get_intval(&_9), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	RETURN_MM();
}

/**
 * Sorts an array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, sort)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL;
	zval value;

	ZVAL_UNDEF(&value);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &value_param);
	zephir_get_arrval(&value, value_param);
	ZEPHIR_MAKE_REF(&value);
	ZEPHIR_CALL_FUNCTION(NULL, "asort", NULL, 505, &value);
	ZEPHIR_UNREF(&value);
	zephir_check_call_status();
	RETURN_CTOR(&value);
}

zend_object *zephir_init_properties_Phalcon_Mvc_View_Engine_Volt(zend_class_entry *class_type)
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("macros"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("macros"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

