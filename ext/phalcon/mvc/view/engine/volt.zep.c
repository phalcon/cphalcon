
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
#include "kernel/require.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"


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
	zval *options = NULL;

	zephir_fetch_params(0, 1, 0, &options_param);

	options = options_param;


	zephir_update_property_this(getThis(), SL("_options"), options TSRMLS_CC);

}

/**
 * Return Volt's options
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getOptions) {

	

	RETURN_MEMBER(getThis(), "_options");

}

/**
 * Returns the Volt's compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getCompiler) {

	zval *compiler = NULL, *dependencyInjector = NULL, *options = NULL, *_0$$3, *_1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(compiler);
	zephir_read_property_this(&compiler, this_ptr, SL("_compiler"), PH_NOISY_CC);
	if (Z_TYPE_P(compiler) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(compiler);
		object_init_ex(compiler, phalcon_mvc_view_engine_volt_compiler_ce);
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_view"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, compiler, "__construct", NULL, 404, _0$$3);
		zephir_check_call_status();
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(dependencyInjector, _1$$3);
		if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(NULL, compiler, "setdi", NULL, 405, dependencyInjector);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_VAR(options);
		zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
		if (Z_TYPE_P(options) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(NULL, compiler, "setoptions", NULL, 406, options);
			zephir_check_call_status();
		}
		zephir_update_property_this(getThis(), SL("_compiler"), compiler TSRMLS_CC);
	}
	RETURN_CCTOR(compiler);

}

/**
 * Renders a view using the template engine
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, render) {

	HashTable *_1$$4;
	HashPosition _0$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool mustClean;
	zval *templatePath_param = NULL, *params, *mustClean_param = NULL, *compiler = NULL, *compiledTemplatePath = NULL, *key = NULL, *value = NULL, **_2$$4, *_3$$5 = NULL, *_4$$6, *_5$$6 = NULL;
	zval *templatePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &templatePath_param, &params, &mustClean_param);

	if (UNEXPECTED(Z_TYPE_P(templatePath_param) != IS_STRING && Z_TYPE_P(templatePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'templatePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(templatePath_param) == IS_STRING)) {
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
		ZEPHIR_CALL_FUNCTION(NULL, "ob_clean", NULL, 403);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&compiler, this_ptr, "getcompiler", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, compiler, "compile", NULL, 0, templatePath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&compiledTemplatePath, compiler, "getcompiledtemplatepath", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(params) == IS_ARRAY) {
		zephir_is_iterable(params, &_1$$4, &_0$$4, 0, 0, "phalcon/mvc/view/engine/volt.zep", 116);
		for (
		  ; zend_hash_get_current_data_ex(_1$$4, (void**) &_2$$4, &_0$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$4, &_0$$4)
		) {
			ZEPHIR_GET_HMKEY(key, _1$$4, _0$$4);
			ZEPHIR_GET_HVALUE(value, _2$$4);
			ZEPHIR_CPY_WRT(_3$$5, value);
			if (zephir_set_symbol(key, _3$$5 TSRMLS_CC) == FAILURE) {
				return;
			}
		}
	}
	if (zephir_require_zval(compiledTemplatePath TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	if (mustClean) {
		_4$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_view"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_5$$6, "ob_get_contents", NULL, 141);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _4$$6, "setcontent", NULL, 0, _5$$6);
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
	zval *item;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);



	_0 = Z_TYPE_P(item) == IS_OBJECT;
	if (!(_0)) {
		_0 = Z_TYPE_P(item) == IS_ARRAY;
	}
	if (_0) {
		RETURN_MM_LONG(zephir_fast_count_int(item TSRMLS_CC));
	}
	if ((zephir_function_exists_ex(SS("mb_strlen") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("mb_strlen", NULL, 238, item);
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
	zval *needle, *haystack, *_0$$5 = NULL, *_1$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &needle, &haystack);



	if (Z_TYPE_P(haystack) == IS_ARRAY) {
		RETURN_MM_BOOL(zephir_fast_in_array(needle, haystack TSRMLS_CC));
	}
	if (Z_TYPE_P(haystack) == IS_STRING) {
		if ((zephir_function_exists_ex(SS("mb_strpos") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_FUNCTION(&_0$$5, "mb_strpos", NULL, 407, haystack, needle);
			zephir_check_call_status();
			RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(_0$$5));
		}
		ZEPHIR_INIT_VAR(_1$$4);
		zephir_fast_strpos(_1$$4, haystack, needle, 0 );
		RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(_1$$4));
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "Invalid haystack", "phalcon/mvc/view/engine/volt.zep", 158);
	return;

}

/**
 * Performs a string conversion
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, convertEncoding) {

	zend_bool _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *from_param = NULL, *to_param = NULL;
	zval *text = NULL, *from = NULL, *to = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &text_param, &from_param, &to_param);

	zephir_get_strval(text, text_param);
	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(from, from_param);
	} else {
		ZEPHIR_INIT_VAR(from);
		ZVAL_EMPTY_STRING(from);
	}
	if (UNEXPECTED(Z_TYPE_P(to_param) != IS_STRING && Z_TYPE_P(to_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'to' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(to_param) == IS_STRING)) {
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
		ZEPHIR_RETURN_CALL_FUNCTION("utf8_encode", NULL, 408, text);
		zephir_check_call_status();
		RETURN_MM();
	}
	_1 = ZEPHIR_IS_STRING(to, "latin1");
	if (!(_1)) {
		_1 = ZEPHIR_IS_STRING(from, "utf8");
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_FUNCTION("utf8_decode", NULL, 409, text);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_function_exists_ex(SS("mb_convert_encoding") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("mb_convert_encoding", NULL, 203, text, from, to);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_function_exists_ex(SS("iconv") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("iconv", NULL, 410, from, to, text);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "Any of 'mbstring' or 'iconv' is required to perform the charset conversion", "phalcon/mvc/view/engine/volt.zep", 197);
	return;

}

/**
 * Extracts a slice from a string/array/traversable object value
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, slice) {

	zend_bool _1$$5;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zend_long start, ZEPHIR_LAST_CALL_STATUS, position = 0;
	zval *value, *start_param = NULL, *end = NULL, *length = NULL, *slice = NULL, _9, *_0$$3 = NULL, *_2$$6 = NULL, _5$$9, _6$$11, _7$$10, _8$$12;

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
			ZEPHIR_CALL_METHOD(&_0$$3, value, "valid", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(_0$$3))) {
				break;
			}
			_1$$5 = position >= start;
			if (_1$$5) {
				_1$$5 = ZEPHIR_GE_LONG(end, position);
			}
			if (_1$$5) {
				ZEPHIR_CALL_METHOD(&_2$$6, value, "current", &_3, 0);
				zephir_check_call_status();
				zephir_array_append(&slice, _2$$6, PH_SEPARATE, "phalcon/mvc/view/engine/volt.zep", 223);
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
		ZEPHIR_SINIT_VAR(_5$$9);
		ZVAL_LONG(&_5$$9, start);
		ZEPHIR_RETURN_CALL_FUNCTION("array_slice", NULL, 411, value, &_5$$9, length);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_function_exists_ex(SS("mb_substr") TSRMLS_CC) == SUCCESS)) {
		if (Z_TYPE_P(length) != IS_NULL) {
			ZEPHIR_SINIT_VAR(_6$$11);
			ZVAL_LONG(&_6$$11, start);
			ZEPHIR_RETURN_CALL_FUNCTION("mb_substr", NULL, 160, value, &_6$$11, length);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_SINIT_VAR(_7$$10);
		ZVAL_LONG(&_7$$10, start);
		ZEPHIR_RETURN_CALL_FUNCTION("mb_substr", NULL, 160, value, &_7$$10);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(length) != IS_NULL) {
		ZEPHIR_SINIT_VAR(_8$$12);
		ZVAL_LONG(&_8$$12, start);
		zephir_substr(return_value, value, zephir_get_intval(&_8$$12), zephir_get_intval(length), 0);
		RETURN_MM();
	}
	ZEPHIR_SINIT_VAR(_9);
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
	zval *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_arrval(value, value_param);


	ZEPHIR_MAKE_REF(value);
	ZEPHIR_CALL_FUNCTION(NULL, "asort", NULL, 412, value);
	ZEPHIR_UNREF(value);
	zephir_check_call_status();
	RETURN_CTOR(value);

}

/**
 * Checks if a macro is defined and calls it
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, callMacro) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL;
	zval *name_param = NULL, *arguments_param = NULL, *macro = NULL, *_0, *_1$$3;
	zval *name = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &arguments_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!arguments_param) {
		ZEPHIR_INIT_VAR(arguments);
		array_init(arguments);
	} else {
		zephir_get_arrval(arguments, arguments_param);
	}


	ZEPHIR_OBS_VAR(macro);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_macros"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&macro, _0, name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, phalcon_mvc_view_exception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SVS(_2$$3, "Macro '", name, "' does not exist");
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 9, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalcon/mvc/view/engine/volt.zep", 287 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", NULL, 311, macro, arguments);
	zephir_check_call_status();
	RETURN_MM();

}

