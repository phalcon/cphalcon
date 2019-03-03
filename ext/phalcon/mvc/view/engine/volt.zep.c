
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
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/require.h"
#include "kernel/string.h"
#include "kernel/array.h"
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
 * Phalcon\Mvc\View\Engine\Volt
 *
 * Designer friendly and fast template engine for PHP written in Zephir/C
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\View\\Engine, Volt, phalcon, mvc_view_engine_volt, phalcon_mvc_view_engine_ce, phalcon_mvc_view_engine_volt_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_ce, SL("_compiler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_ce, SL("_macros"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Set Volt's options
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, setOptions) {

	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);


	zephir_update_property_zval(this_ptr, SL("_options"), &options);
	ZEPHIR_MM_RESTORE();

}

/**
 * Return Volt's options
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_options");

}

/**
 * Returns the Volt's compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getCompiler) {

	zval compiler, dependencyInjector, options, _0$$3, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&compiler);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&compiler);
	zephir_read_property(&compiler, this_ptr, SL("_compiler"), PH_NOISY_CC);
	if (Z_TYPE_P(&compiler) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&compiler);
		object_init_ex(&compiler, phalcon_mvc_view_engine_volt_compiler_ce);
		zephir_read_property(&_0$$3, this_ptr, SL("_view"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &compiler, "__construct", NULL, 380, &_0$$3);
		zephir_check_call_status();
		zephir_read_property(&_1$$3, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&dependencyInjector, &_1$$3);
		if (Z_TYPE_P(&dependencyInjector) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(NULL, &compiler, "setdi", NULL, 381, &dependencyInjector);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_VAR(&options);
		zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
		if (Z_TYPE_P(&options) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(NULL, &compiler, "setoptions", NULL, 382, &options);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, SL("_compiler"), &compiler);
	}
	RETURN_CCTOR(&compiler);

}

/**
 * Renders a view using the template engine
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, render) {

	zend_string *_7$$8;
	zend_ulong _6$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool mustClean;
	zval *templatePath_param = NULL, *params, params_sub, *mustClean_param = NULL, compiler, compiledTemplatePath, eventsManager, key, value, _0$$4, _1$$4, _2$$6, _3$$6, *_4$$8, _5$$8, _8$$9, _9$$10, _10$$11, _11$$11;
	zval templatePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&templatePath);
	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&compiler);
	ZVAL_UNDEF(&compiledTemplatePath);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &templatePath_param, &params, &mustClean_param);

	if (UNEXPECTED(Z_TYPE_P(templatePath_param) != IS_STRING && Z_TYPE_P(templatePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'templatePath' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(templatePath_param) == IS_STRING)) {
		zephir_get_strval(&templatePath, templatePath_param);
	} else {
		ZEPHIR_INIT_VAR(&templatePath);
		ZVAL_EMPTY_STRING(&templatePath);
	}
	if (!mustClean_param) {
		mustClean = 0;
	} else {
		mustClean = zephir_get_boolval(mustClean_param);
	}


	if (mustClean) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_clean", NULL, 379);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&compiler, this_ptr, "getcompiler", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&eventsManager);
	zephir_read_property(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "view:beforeCompile");
		ZEPHIR_CALL_METHOD(&_0$$4, &eventsManager, "fire", NULL, 0, &_1$$4, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_0$$4)) {
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &compiler, "compile", NULL, 0, &templatePath);
	zephir_check_call_status();
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_3$$6);
		ZVAL_STRING(&_3$$6, "view:afterCompile");
		ZEPHIR_CALL_METHOD(&_2$$6, &eventsManager, "fire", NULL, 0, &_3$$6, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_2$$6)) {
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_CALL_METHOD(&compiledTemplatePath, &compiler, "getcompiledtemplatepath", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(params) == IS_ARRAY) {
		zephir_is_iterable(params, 0, "phalcon/mvc/view/engine/volt.zep", 120);
		if (Z_TYPE_P(params) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(params), _6$$8, _7$$8, _4$$8)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_7$$8 != NULL) { 
					ZVAL_STR_COPY(&key, _7$$8);
				} else {
					ZVAL_LONG(&key, _6$$8);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _4$$8);
				ZEPHIR_CPY_WRT(&_8$$9, &value);
				if (zephir_set_symbol(&key, &_8$$9 TSRMLS_CC) == FAILURE) {
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, params, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$8, params, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$8)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, params, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, params, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CPY_WRT(&_9$$10, &value);
					if (zephir_set_symbol(&key, &_9$$10 TSRMLS_CC) == FAILURE) {
						return;
					}
				ZEPHIR_CALL_METHOD(NULL, params, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	}
	if (zephir_require_zval(&compiledTemplatePath TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	if (mustClean) {
		zephir_read_property(&_10$$11, this_ptr, SL("_view"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_11$$11, "ob_get_contents", NULL, 115);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_10$$11, "setcontent", NULL, 0, &_11$$11);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Length filter. If an array/object is passed a count is performed otherwise a strlen/mb_strlen
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, length) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);



	_0 = Z_TYPE_P(item) == IS_OBJECT;
	if (!(_0)) {
		_0 = Z_TYPE_P(item) == IS_ARRAY;
	}
	if (_0) {
		RETURN_MM_LONG(zephir_fast_count_int(item TSRMLS_CC));
	}
	if ((zephir_function_exists_ex(SL("mb_strlen") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("mb_strlen", NULL, 213, item);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_LONG(zephir_fast_strlen_ev(item));

}

/**
 * Checks if the needle is included in the haystack
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, isIncluded) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *needle, needle_sub, *haystack, haystack_sub, _0$$5, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&needle_sub);
	ZVAL_UNDEF(&haystack_sub);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &needle, &haystack);



	if (Z_TYPE_P(haystack) == IS_ARRAY) {
		RETURN_MM_BOOL(zephir_fast_in_array(needle, haystack TSRMLS_CC));
	}
	if (Z_TYPE_P(haystack) == IS_STRING) {
		if ((zephir_function_exists_ex(SL("mb_strpos") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_FUNCTION(&_0$$5, "mb_strpos", NULL, 383, haystack, needle);
			zephir_check_call_status();
			RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_0$$5));
		}
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_fast_strpos(&_1$$4, haystack, needle, 0 );
		RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_1$$4));
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "Invalid haystack", "phalcon/mvc/view/engine/volt.zep", 162);
	return;

}

/**
 * Performs a string conversion
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, convertEncoding) {

	zend_bool _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *from_param = NULL, *to_param = NULL;
	zval text, from, to;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&to);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &text_param, &from_param, &to_param);

	zephir_get_strval(&text, text_param);
	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(&from, from_param);
	} else {
		ZEPHIR_INIT_VAR(&from);
		ZVAL_EMPTY_STRING(&from);
	}
	if (UNEXPECTED(Z_TYPE_P(to_param) != IS_STRING && Z_TYPE_P(to_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'to' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(to_param) == IS_STRING)) {
		zephir_get_strval(&to, to_param);
	} else {
		ZEPHIR_INIT_VAR(&to);
		ZVAL_EMPTY_STRING(&to);
	}


	_0 = ZEPHIR_IS_STRING(&from, "latin1");
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING(&to, "utf8");
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_FUNCTION("utf8_encode", NULL, 384, &text);
		zephir_check_call_status();
		RETURN_MM();
	}
	_1 = ZEPHIR_IS_STRING(&to, "latin1");
	if (!(_1)) {
		_1 = ZEPHIR_IS_STRING(&from, "utf8");
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_FUNCTION("utf8_decode", NULL, 191, &text);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_function_exists_ex(SL("mb_convert_encoding") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("mb_convert_encoding", NULL, 176, &text, &from, &to);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_function_exists_ex(SL("iconv") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("iconv", NULL, 204, &from, &to, &text);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "Any of 'mbstring' or 'iconv' is required to perform the charset conversion", "phalcon/mvc/view/engine/volt.zep", 201);
	return;

}

/**
 * Extracts a slice from a string/array/traversable object value
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, slice) {

	zend_bool _1$$5;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zend_long start, ZEPHIR_LAST_CALL_STATUS, position = 0;
	zval *value, value_sub, *start_param = NULL, *end = NULL, end_sub, __$null, length, slice, _9, _0$$3, _2$$6, _5$$9, _6$$11, _7$$10, _8$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&end_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&slice);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &value, &start_param, &end);

	if (!start_param) {
		start = 0;
	} else {
		start = zephir_get_intval(start_param);
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
			ZVAL_LONG(end, (zephir_fast_count_int(value TSRMLS_CC) - 1));
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
				zephir_array_append(&slice, &_2$$6, PH_SEPARATE, "phalcon/mvc/view/engine/volt.zep", 227);
			}
			ZEPHIR_CALL_METHOD(NULL, value, "next", &_4, 0);
			zephir_check_call_status();
			position++;
		}
		RETURN_CCTOR(&slice);
	}
	ZEPHIR_INIT_VAR(&length);
	if (Z_TYPE_P(end) != IS_NULL) {
		ZVAL_LONG(&length, (((zephir_get_numberval(end) - start)) + 1));
	} else {
		ZVAL_NULL(&length);
	}
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZVAL_LONG(&_5$$9, start);
		ZEPHIR_RETURN_CALL_FUNCTION("array_slice", NULL, 385, value, &_5$$9, &length);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_function_exists_ex(SL("mb_substr") TSRMLS_CC) == SUCCESS)) {
		if (Z_TYPE_P(&length) != IS_NULL) {
			ZVAL_LONG(&_6$$11, start);
			ZEPHIR_RETURN_CALL_FUNCTION("mb_substr", NULL, 134, value, &_6$$11, &length);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZVAL_LONG(&_7$$10, start);
		ZEPHIR_RETURN_CALL_FUNCTION("mb_substr", NULL, 134, value, &_7$$10);
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
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, sort) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_arrval(&value, value_param);


	ZEPHIR_MAKE_REF(&value);
	ZEPHIR_CALL_FUNCTION(NULL, "asort", NULL, 386, &value);
	ZEPHIR_UNREF(&value);
	zephir_check_call_status();
	RETURN_CTOR(&value);

}

/**
 * Checks if a macro is defined and calls it
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, callMacro) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &arguments_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
		zephir_get_arrval(&arguments, arguments_param);
	}


	ZEPHIR_OBS_VAR(&macro);
	zephir_read_property(&_0, this_ptr, SL("_macros"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&macro, &_0, &name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_view_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Macro '", &name, "' does not exist");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 4, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/mvc/view/engine/volt.zep", 291 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", NULL, 287, &macro, &arguments);
	zephir_check_call_status();
	RETURN_MM();

}

