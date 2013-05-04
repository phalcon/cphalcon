
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
 *  Phalcon\Mvc\Micro\LazyLoader constructor
 *
 * @param string $definition
 */
PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, __construct){

	zval *definition;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &definition) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(definition) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_micro_exception_ce, "Only strings can be lazy loaded");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_definition"), definition TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, __call){

	zval *method, *arguments;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &method, &arguments) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("print_r", method);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("print_r", arguments);
	
	PHALCON_MM_RESTORE();
}

