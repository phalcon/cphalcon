
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "mvc/micro/lazyloader.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"

/**
 * Phalcon\Mvc\Micro\LazyLoader
 *
 * Lazy-Load of handlers for Mvc\Micro using auto-loading
 */
zend_class_entry *phalcon_mvc_micro_lazyloader_ce;

PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, __construct);
PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, __call);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_lazyloader___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_lazyloader___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_micro_lazyloader_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Micro_LazyLoader, __construct, arginfo_phalcon_mvc_micro_lazyloader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Micro_LazyLoader, __call, arginfo_phalcon_mvc_micro_lazyloader___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Micro\LazyLoader initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Micro_LazyLoader){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Micro, LazyLoader, mvc_micro_lazyloader, phalcon_mvc_micro_lazyloader_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_micro_lazyloader_ce, SL("_handler"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_lazyloader_ce, SL("_definition"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Micro\LazyLoader constructor
 *
 * @param string $definition
 */
PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, __construct){

	zval **definition;

	phalcon_fetch_params_ex(1, 0, &definition);
	PHALCON_ENSURE_IS_STRING(definition);
	
	phalcon_update_property_this(this_ptr, SL("_definition"), *definition TSRMLS_CC);
}

/**
 * Initializes the internal handler, calling functions on it
 *
 * @param string $method
 * @param array $arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, __call){

	zval *method, *arguments, *handler = NULL, *definition;
	zval *call_handler;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &method, &arguments);
	
	PHALCON_OBS_VAR(handler);
	phalcon_read_property_this(&handler, this_ptr, SL("_handler"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(handler) != IS_OBJECT) {
		PHALCON_OBS_VAR(definition);
		phalcon_read_property_this(&definition, this_ptr, SL("_definition"), PH_NOISY TSRMLS_CC);
		ce0 = phalcon_fetch_class(definition TSRMLS_CC);
	
		PHALCON_INIT_NVAR(handler);
		object_init_ex(handler, ce0);
		if (phalcon_has_constructor(handler TSRMLS_CC)) {
			PHALCON_CALL_METHOD(NULL, handler, "__construct");
		}
		phalcon_update_property_this(this_ptr, SL("_handler"), handler TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(call_handler);
	array_init_size(call_handler, 2);
	phalcon_array_append(&call_handler, handler, 0);
	phalcon_array_append(&call_handler, method, 0);
	
	/** 
	 * Call the handler
	 */
	PHALCON_CALL_USER_FUNC_ARRAY(return_value, call_handler, arguments);
	RETURN_MM();
}
