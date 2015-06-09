
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
#include "kernel/hash.h"
#include "kernel/require.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"


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
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, setOptions) {

	zval *options_param = NULL;
	zval *options = NULL;

	zephir_fetch_params(0, 1, 0, &options_param);

	options = options_param;



	zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);

}

/**
 * Return Volt's options	 
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getOptions) {


	RETURN_MEMBER(this_ptr, "_options");

}

/**
 * Returns the Volt's compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getCompiler) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *compiler = NULL, *dependencyInjector = NULL, *options, *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(compiler);
	zephir_read_property_this(&compiler, this_ptr, SL("_compiler"), PH_NOISY_CC);
	if (Z_TYPE_P(compiler) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(compiler);
		object_init_ex(compiler, phalcon_mvc_view_engine_volt_compiler_ce);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_view"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, compiler, "__construct", NULL, 361, _0);
		zephir_check_call_status();
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(dependencyInjector, _1);
		if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(NULL, compiler, "setdi", NULL, 362, dependencyInjector);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_VAR(options);
		zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
		if (Z_TYPE_P(options) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(NULL, compiler, "setoptions", NULL, 363, options);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("_compiler"), compiler TSRMLS_CC);
	}
	RETURN_CCTOR(compiler);

}

/**
 * Renders a view using the template engine
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, render) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool mustClean;
	zval *templatePath_param = NULL, *params, *mustClean_param = NULL, *compiler = NULL, *compiledTemplatePath = NULL, *key = NULL, *value = NULL, **_2, *_3 = NULL, *_4, *_5 = NULL;
	zval *templatePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &templatePath_param, &params, &mustClean_param);

	if (unlikely(Z_TYPE_P(templatePath_param) != IS_STRING && Z_TYPE_P(templatePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'templatePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(templatePath_param) == IS_STRING)) {
		zephir_get_strval(templatePath, templatePath_param);
	} else {
		ZEPHIR_INIT_VAR(templatePath);
		ZVAL_EMPTY_STRING(templatePath);
	}
	if (!mustClean_param) {
		mustClean = 0;
	} else {
		mustClean = zephir_get_boolval(mustClean_param);
	}


	if (mustClean) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_clean", NULL, 360);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&compiler, this_ptr, "getcompiler", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, compiler, "compile", NULL, 0, templatePath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&compiledTemplatePath, compiler, "getcompiledtemplatepath", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(params) == IS_ARRAY) {
		zephir_is_iterable(params, &_1, &_0, 0, 0, "phalcon/mvc/view/engine/volt.zep", 116);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(key, _1, _0);
			ZEPHIR_GET_HVALUE(value, _2);
			ZEPHIR_CPY_WRT(_3, value);
			if (zephir_set_symbol(key, _3 TSRMLS_CC) == FAILURE){
				return;
			}
		}
	}
	if (zephir_require_zval(compiledTemplatePath TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	if (mustClean) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_view"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_5, "ob_get_contents", NULL, 50);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _4, "setcontent", NULL, 0, _5);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Length filter. If an array/object is passed a count is performed otherwise a strlen/mb_strlen
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, length) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *item, *length = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);



	ZEPHIR_INIT_VAR(length);
	ZVAL_LONG(length, 0);
	if (Z_TYPE_P(item) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(length);
		ZVAL_LONG(length, zephir_fast_count_int(item TSRMLS_CC));
	} else {
		if (Z_TYPE_P(item) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(length);
			ZVAL_LONG(length, zephir_fast_count_int(item TSRMLS_CC));
		} else {
			if ((zephir_function_exists_ex(SS("mb_strlen") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_FUNCTION(&length, "mb_strlen", NULL, 353, item);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(length);
				ZVAL_LONG(length, zephir_fast_strlen_ev(item));
			}
		}
	}
	RETURN_CCTOR(length);

}

/**
 * Checks if the needle is included in the haystack
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, isIncluded) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *needle, *haystack, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &needle, &haystack);



	if (Z_TYPE_P(haystack) == IS_ARRAY) {
		RETURN_MM_BOOL(zephir_fast_in_array(needle, haystack TSRMLS_CC));
	}
	if (Z_TYPE_P(haystack) == IS_STRING) {
		if ((zephir_function_exists_ex(SS("mb_strpos") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_FUNCTION(&_0, "mb_strpos", NULL, 364, haystack, needle);
			zephir_check_call_status();
			RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(_0));
		}
		ZEPHIR_INIT_VAR(_1);
		zephir_fast_strpos(_1, haystack, needle, 0 );
		RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(_1));
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "Invalid haystack", "phalcon/mvc/view/engine/volt.zep", 168);
	return;

}

/**
 * Performs a string conversion
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, convertEncoding) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0, _1;
	zval *text_param = NULL, *from_param = NULL, *to_param = NULL;
	zval *text = NULL, *from = NULL, *to = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &text_param, &from_param, &to_param);

	zephir_get_strval(text, text_param);
	if (unlikely(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(from, from_param);
	} else {
		ZEPHIR_INIT_VAR(from);
		ZVAL_EMPTY_STRING(from);
	}
	if (unlikely(Z_TYPE_P(to_param) != IS_STRING && Z_TYPE_P(to_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'to' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(to_param) == IS_STRING)) {
		zephir_get_strval(to, to_param);
	} else {
		ZEPHIR_INIT_VAR(to);
		ZVAL_EMPTY_STRING(to);
	}


	_0 = ZEPHIR_IS_STRING(from, "latin1");
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING(to, "utf8");
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_FUNCTION("utf8_encode", NULL, 365, text);
		zephir_check_call_status();
		RETURN_MM();
	}
	_1 = ZEPHIR_IS_STRING(to, "latin1");
	if (!(_1)) {
		_1 = ZEPHIR_IS_STRING(from, "utf8");
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_FUNCTION("utf8_decode", NULL, 366, text);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_function_exists_ex(SS("mb_convert_encoding") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("mb_convert_encoding", NULL, 154, text, from, to);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_function_exists_ex(SS("iconv") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("iconv", NULL, 367, from, to, text);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "Any of 'mbstring' or 'iconv' is required to perform the charset conversion", "phalcon/mvc/view/engine/volt.zep", 207);
	return;

}

/**
 * Extracts a slice from a string/array/traversable object value
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, slice) {

	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL, *_6 = NULL;
	zend_bool _1;
	int start, position, ZEPHIR_LAST_CALL_STATUS;
	zval *value, *start_param = NULL, *end = NULL, *length, *slice, *_0 = NULL, *_2 = NULL, _5 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &value, &start_param, &end);

	if (!start_param) {
		start = 0;
	} else {
		start = zephir_get_intval(start_param);
	}
	if (!end) {
		ZEPHIR_CPY_WRT(end, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(end);
	}


	if (Z_TYPE_P(value) == IS_OBJECT) {
		if (Z_TYPE_P(end) == IS_NULL) {
			ZEPHIR_INIT_NVAR(end);
			ZVAL_LONG(end, (zephir_fast_count_int(value TSRMLS_CC) - 1));
		}
		position = 0;
		ZEPHIR_INIT_VAR(slice);
		array_init(slice);
		ZEPHIR_CALL_METHOD(NULL, value, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_0, value, "valid", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(_0))) {
				break;
			}
			_1 = position >= start;
			if (_1) {
				_1 = ZEPHIR_GE_LONG(end, position);
			}
			if (_1) {
				ZEPHIR_CALL_METHOD(&_2, value, "current", &_3, 0);
				zephir_check_call_status();
				zephir_array_append(&slice, _2, PH_SEPARATE, "phalcon/mvc/view/engine/volt.zep", 233);
			}
			ZEPHIR_CALL_METHOD(NULL, value, "next", &_4, 0);
			zephir_check_call_status();
			position++;
		}
		RETURN_CCTOR(slice);
	}
	ZEPHIR_INIT_VAR(length);
	if (Z_TYPE_P(end) != IS_NULL) {
		ZVAL_LONG(length, (((zephir_get_numberval(end) - start)) + 1));
	} else {
		ZVAL_NULL(length);
	}
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_LONG(&_5, start);
		ZEPHIR_RETURN_CALL_FUNCTION("array_slice", NULL, 368, value, &_5, length);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_function_exists_ex(SS("mb_substr") TSRMLS_CC) == SUCCESS)) {
		if (Z_TYPE_P(length) != IS_NULL) {
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_LONG(&_5, start);
			ZEPHIR_RETURN_CALL_FUNCTION("mb_substr", &_6, 369, value, &_5, length);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, start);
		ZEPHIR_RETURN_CALL_FUNCTION("mb_substr", &_6, 369, value, &_5);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(length) != IS_NULL) {
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, start);
		zephir_substr(return_value, value, zephir_get_intval(&_5), zephir_get_intval(length), 0);
		RETURN_MM();
	}
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, start);
	zephir_substr(return_value, value, zephir_get_intval(&_5), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	RETURN_MM();

}

/**
 * Sorts an array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, sort) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL;
	zval *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_arrval(value, value_param);


	Z_SET_ISREF_P(value);
	ZEPHIR_CALL_FUNCTION(NULL, "asort", NULL, 370, value);
	Z_UNSET_ISREF_P(value);
	zephir_check_call_status();
	RETURN_CTOR(value);

}

