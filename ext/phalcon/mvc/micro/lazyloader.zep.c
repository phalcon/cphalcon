
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
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Micro\LazyLoader
 *
 * Lazy-Load of handlers for Mvc\Micro using auto-loading
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_LazyLoader) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Micro, LazyLoader, phalcon, mvc_micro_lazyloader, phalcon_mvc_micro_lazyloader_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_micro_lazyloader_ce, SL("handler"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_micro_lazyloader_ce, SL("definition"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, getHandler) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "handler");

}

PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, getDefinition) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "definition");

}

/**
 * Phalcon\Mvc\Micro\LazyLoader constructor
 */
PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *definition_param = NULL;
	zval definition;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definition);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(definition)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &definition_param);

	if (UNEXPECTED(Z_TYPE_P(definition_param) != IS_STRING && Z_TYPE_P(definition_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'definition' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(definition_param) == IS_STRING)) {
		zephir_get_strval(&definition, definition_param);
	} else {
		ZEPHIR_INIT_VAR(&definition);
		ZVAL_EMPTY_STRING(&definition);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("definition"), &definition);
	ZEPHIR_MM_RESTORE();

}

/**
 * Calling __call method
 *
 * @param  array arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, callMethod) {

	zval _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *arguments = NULL, arguments_sub, *modelBinder = NULL, modelBinder_sub, __$null, handler, definition, bindCacheKey, _0, _1$$4, _2$$4, _3$$5;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_UNDEF(&modelBinder_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&bindCacheKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(method)
		Z_PARAM_ZVAL(arguments)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(modelBinder, phalcon_mvc_model_binderinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &method_param, &arguments, &modelBinder);

	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_EMPTY_STRING(&method);
	}
	ZEPHIR_SEPARATE_PARAM(arguments);
	if (!modelBinder) {
		modelBinder = &modelBinder_sub;
		modelBinder = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&handler, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("definition"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&definition, &_0);
	if (Z_TYPE_P(&handler) != IS_OBJECT) {
		if (!(zephir_class_exists(&definition, 1))) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_mvc_micro_exception_ce);
			ZEPHIR_INIT_VAR(&_2$$4);
			ZEPHIR_CONCAT_SVS(&_2$$4, "Handler '", &definition, "' doesn't exist");
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 8, &_2$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Micro/LazyLoader.zep", 49);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&handler);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&handler, &definition);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), &handler);
	}
	if (Z_TYPE_P(modelBinder) != IS_NULL) {
		ZEPHIR_INIT_VAR(&bindCacheKey);
		ZEPHIR_CONCAT_SVSV(&bindCacheKey, "_PHMB_", &definition, "_", &method);
		ZEPHIR_CALL_METHOD(&_3$$5, modelBinder, "bindtohandler", NULL, 0, &handler, arguments, &bindCacheKey, &method);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(arguments, &_3$$5);
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0);
	zephir_array_fast_append(&_4, &handler);
	zephir_array_fast_append(&_4, &method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_4, arguments);
	zephir_check_call_status();
	RETURN_MM();

}

