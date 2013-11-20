
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
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Mvc\View\Engine\Volt
 *
 * Designer friendly and fast template engine for PHP written in C
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\View\\Engine, Volt, phalcon, mvc_view_engine_volt, phalcon_mvc_view_engine_ce, phalcon_mvc_view_engine_volt_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_ce, SL("_compiler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_view_engine_volt_ce TSRMLS_CC, 1, phalcon_mvc_view_engineinterface_ce);

	return SUCCESS;

}

/**
 * Set Volt's options
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, setOptions) {

	zval *options;

	zephir_fetch_params(0, 1, 0, &options);



	if ((Z_TYPE_P(options) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, "Options parameter must be an array");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);

}

/**
 * Return Volt's options
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getOptions) {


	RETURN_MEMBER(this_ptr, "_options");

}

/**
 * Returns the Volt's compiler
 *
 * @return Phalcon\Mvc\View\Engine\Volt\Compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getCompiler) {

	zval *compiler, *dependencyInjector, *options, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(compiler);
	zephir_read_property_this(&compiler, this_ptr, SL("_compiler"), PH_NOISY_CC);
	if ((Z_TYPE_P(compiler) != IS_OBJECT)) {
		ZEPHIR_INIT_BNVAR(compiler);
		object_init_ex(compiler, phalcon_mvc_view_engine_volt_compiler_ce);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_view"), PH_NOISY_CC);
		zephir_call_method_p1_noret(compiler, "__construct", _0);
		dependencyInjector = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
			zephir_call_method_p1_noret(compiler, "setdi", dependencyInjector);
		}
		options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
		if ((Z_TYPE_P(options) == IS_ARRAY)) {
			zephir_call_method_p1_noret(compiler, "setoptions", options);
		}
		zephir_update_property_this(this_ptr, SL("_compiler"), compiler TSRMLS_CC);
	}
	RETURN_CCTOR(compiler);

}

/**
 * Renders a view using the template engine
 *
 * @param string  templatePath
 * @param array   params
 * @param boolean mustClean
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, render) {

	HashTable *_1;
	HashPosition _0;
	zend_bool mustClean;
	zval *templatePath_param = NULL, *params, *mustClean_param = NULL, *compiler, *compiledTemplatePath, *key = NULL, *value = NULL, **_2, *_3, *_4;
	zval *templatePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &templatePath_param, &params, &mustClean_param);

		if (Z_TYPE_P(templatePath_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'templatePath' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		templatePath = templatePath_param;

	if (!mustClean_param || Z_TYPE_P(mustClean_param) == IS_NULL) {
		mustClean = 0;
	} else {
		mustClean = zephir_get_boolval(mustClean_param);
	}


	if ((mustClean == 1)) {
		zephir_call_func_noret("ob_clean");
	}
	ZEPHIR_INIT_VAR(compiler);
	zephir_call_method(compiler, this_ptr, "getcompiler");
	zephir_call_method_p1_noret(compiler, "compile", templatePath);
	ZEPHIR_INIT_VAR(compiledTemplatePath);
	zephir_call_method(compiledTemplatePath, compiler, "getcompiledtemplatepath");
	if ((Z_TYPE_P(params) == IS_ARRAY)) {
		zephir_is_iterable(params, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(key, _1, _0);
			ZEPHIR_GET_HVALUE(value, _2);
		}
	}
	if ((mustClean == 1)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_view"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4);
		zephir_call_func(_4, "ob_get_contents");
		zephir_call_method_p1_noret(_3, "setcontent", _4);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Length filter. If an array/object is passed a count is performed otherwise a strlen/mb_strlen
 *
 * @param mixed $item
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, length) {

	zval *item, *length, _0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);



	ZEPHIR_INIT_VAR(length);
	ZVAL_LONG(length, 0);
	if ((Z_TYPE_P(item) == IS_OBJECT)) {
		ZEPHIR_INIT_BNVAR(length);
		ZVAL_LONG(length, zephir_fast_count_int(item TSRMLS_CC));
	} else {
		if ((Z_TYPE_P(item) == IS_ARRAY)) {
			ZEPHIR_INIT_BNVAR(length);
			ZVAL_LONG(length, zephir_fast_count_int(item TSRMLS_CC));
		} else {
			ZEPHIR_INIT_BNVAR(length);
			ZEPHIR_SINIT_VAR(_0);
			ZVAL_STRING(&_0, "mb_strlen", 0);
			ZEPHIR_INIT_VAR(_1);
			zephir_call_func_p1(_1, "function_exists", &_0);
			if (zephir_is_true(_1)) {
				zephir_call_func_p1(length, "mb_strlen", item);
			} else {
				ZVAL_LONG(length, zephir_fast_strlen_ev(item));
			}
		}
	}
	RETURN_CCTOR(length);

}

/**
 * Checks if the needle is included in the haystack
 *
 * @param  mixed needle
 * @param  mixed haystack
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, isIncluded) {

	zval *needle, *haystack, _0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &needle, &haystack);



	if ((Z_TYPE_P(haystack) == IS_ARRAY)) {
		zephir_call_func_p2(return_value, "in_array", needle, haystack);
		RETURN_MM();
	}
	if ((Z_TYPE_P(haystack) == IS_STRING)) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_STRING(&_0, "mb_strpos", 0);
		ZEPHIR_INIT_VAR(_1);
		zephir_call_func_p1(_1, "function_exists", &_0);
		if (zephir_is_true(_1)) {
			zephir_call_func_p2(return_value, "mb_strpos", haystack, needle);
			RETURN_MM();
		}
		zephir_call_func_p2(return_value, "strpos", haystack, needle);
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Invalid haystack");
	return;

}

/**
 * Performs a string conversion
 *
 * @param  string text
 * @param  string from
 * @param  string to
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, convertEncoding) {

	zval *text_param = NULL, *from_param = NULL, *to_param = NULL, _0 = zval_used_for_init, *_1, *_2;
	zval *text = NULL, *from = NULL, *to = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &text_param, &from_param, &to_param);

		zephir_get_strval(text, text_param);
		if (Z_TYPE_P(from_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		from = from_param;

		if (Z_TYPE_P(to_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'to' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		to = to_param;



	if (ZEPHIR_IS_STRING(from, "latin1")) {
		if (ZEPHIR_IS_STRING(to, "utf8")) {
			zephir_call_func_p1(return_value, "utf8_encode", text);
			RETURN_MM();
		}
	}
	if (ZEPHIR_IS_STRING(to, "latin1")) {
		if (ZEPHIR_IS_STRING(from, "utf8")) {
			zephir_call_func_p1(return_value, "utf8_decode", text);
			RETURN_MM();
		}
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "mb_convert_encoding", 0);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "function_exists", &_0);
	if (zephir_is_true(_1)) {
		zephir_call_func_p3(return_value, "mb_convert_encoding", text, from, to);
		RETURN_MM();
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "iconv", 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "function_exists", &_0);
	if (zephir_is_true(_2)) {
		zephir_call_func_p3(return_value, "iconv", from, to, text);
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Any of 'mbstring' or 'iconv' is required to perform the charset conversion");
	return;

}

/**
 * Extracts a slice from a string/array/traversable object value
 *
 * @param mixed value
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, slice) {

	zend_function *_1 = NULL, *_3 = NULL, *_4 = NULL;
	int position;
	zval *value, *start, *end = NULL, *length = NULL, *slice, *_0 = NULL, *_2 = NULL, *_5, _6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &value, &start, &end);

	if (!end || Z_TYPE_P(end) == IS_NULL) {
		end = ZEPHIR_GLOBAL(global_null);
	}


	if ((Z_TYPE_P(value) == IS_OBJECT)) {
		if ((Z_TYPE_P(end) == IS_NULL)) {
			ZEPHIR_INIT_VAR(length);
			ZVAL_LONG(length, zephir_fast_count_int(value TSRMLS_CC));
		} else {
			ZEPHIR_CPY_WRT(length, end);
		}
		position = 0;
		ZEPHIR_INIT_VAR(slice);
		array_init(slice);
		while (1) {
			ZEPHIR_INIT_NVAR(_0);
			zephir_call_method_cache(_0, value, "valid", &_1);
			if (!(zephir_is_true(_0))) {
				break;
			}
			if (ZEPHIR_GE_LONG(start, position)) {
				ZEPHIR_INIT_NVAR(_2);
				zephir_call_method_cache(_2, value, "current", &_3);
				zephir_array_append(&slice, _2, PH_SEPARATE);
			}
			zephir_call_method_cache_noret(value, "next", &_4);
			position++;
		}
		RETURN_CCTOR(slice);
	}
	ZEPHIR_INIT_NVAR(length);
	if ((Z_TYPE_P(end) != IS_NULL)) {
		ZEPHIR_INIT_VAR(_5);
		sub_function(_5, end, start TSRMLS_CC);
		ZVAL_LONG(length, (zephir_get_numberval(_5) + 1));
	} else {
		ZVAL_NULL(length);
	}
	if ((Z_TYPE_P(value) == IS_ARRAY)) {
		zephir_call_func_p3(return_value, "array_slice", value, start, length);
		RETURN_MM();
	}
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "mb_substr", 0);
	ZEPHIR_INIT_NVAR(_0);
	zephir_call_func_p1(_0, "function_exists", &_6);
	if (zephir_is_true(_0)) {
		if ((Z_TYPE_P(length) != IS_NULL)) {
			zephir_call_func_p3(return_value, "mb_substr", value, start, length);
			RETURN_MM();
		}
		zephir_call_func_p2(return_value, "mb_substr", value, start);
		RETURN_MM();
	}
	if ((Z_TYPE_P(length) != IS_NULL)) {
		zephir_call_func_p3(return_value, "substr", value, start, length);
		RETURN_MM();
	}
	zephir_call_func_p2(return_value, "substr", value, start);
	RETURN_MM();

}

/**
 * Sorts an array
 *
 * @param array value
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, sort) {

	zval *value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	Z_SET_ISREF_P(value);
	zephir_call_func_p1_noret("asort", value);
	RETURN_CCTOR(value);

}

