
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
#include "kernel/array.h"


/**
 * Phalcon\Mvc\Micro\LazyLoader
 *
 * Lazy-Load of handlers for Mvc\Micro using auto-loading
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_LazyLoader) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Micro, LazyLoader, phalcon, mvc_micro_lazyloader, phalcon_mvc_micro_lazyloader_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_micro_lazyloader_ce, SL("_handler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_lazyloader_ce, SL("_definition"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Micro\LazyLoader constructor
 */
PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, __construct) {

	zval *definition_param = NULL;
	zval *definition = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &definition_param);

	if (unlikely(Z_TYPE_P(definition_param) != IS_STRING && Z_TYPE_P(definition_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'definition' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(definition_param) == IS_STRING)) {
		zephir_get_strval(definition, definition_param);
	} else {
		ZEPHIR_INIT_VAR(definition);
		ZVAL_EMPTY_STRING(definition);
	}


	zephir_update_property_this(this_ptr, SL("_definition"), definition TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Initializes the internal handler, calling functions on it
 *
 * @param  string method
 * @param  array arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, __call) {

	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *method_param = NULL, *arguments, *handler = NULL, *definition, *_0 = NULL;
	zval *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &arguments);

	if (unlikely(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}


	ZEPHIR_OBS_VAR(handler);
	zephir_read_property_this(&handler, this_ptr, SL("_handler"), PH_NOISY_CC);
	if (Z_TYPE_P(handler) != IS_OBJECT) {
		ZEPHIR_OBS_VAR(definition);
		zephir_read_property_this(&definition, this_ptr, SL("_definition"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(handler);
		zephir_fetch_safe_class(_0, definition);
		_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(handler, _1);
		if (zephir_has_constructor(handler TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, handler, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("_handler"), handler TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_2, handler);
	zephir_array_fast_append(_2, method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _2, arguments);
	zephir_check_call_status();
	RETURN_MM();

}

