
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

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

	zval *definition;

	phalcon_fetch_params(0, 1, 0, &definition);
	
	if (Z_TYPE_P(definition) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "Only strings can be lazy loaded");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_definition"), definition TSRMLS_CC);
	
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
	zval *call_handler, *result;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &method, &arguments);
	
	PHALCON_OBS_VAR(handler);
	phalcon_read_property_this(&handler, this_ptr, SL("_handler"), PH_NOISY_CC);
	if (Z_TYPE_P(handler) != IS_OBJECT) {
		PHALCON_OBS_VAR(definition);
		phalcon_read_property_this(&definition, this_ptr, SL("_definition"), PH_NOISY_CC);
		ce0 = phalcon_fetch_class(definition TSRMLS_CC);
	
		PHALCON_INIT_NVAR(handler);
		object_init_ex(handler, ce0);
		if (phalcon_has_constructor(handler TSRMLS_CC)) {
			phalcon_call_method_noret(handler, "__construct");
		}
		phalcon_update_property_this(this_ptr, SL("_handler"), handler TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(call_handler);
	array_init_size(call_handler, 2);
	phalcon_array_append(&call_handler, handler, PH_SEPARATE TSRMLS_CC);
	phalcon_array_append(&call_handler, method, PH_SEPARATE TSRMLS_CC);
	
	/** 
	 * Call the handler
	 */
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_USER_FUNC_ARRAY(result, call_handler, arguments);
	
	RETURN_CCTOR(result);
}

