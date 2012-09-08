
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
#include "php_main.h"
#include "ext/standard/php_string.h"
  
#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"

#include "Zend/zend_exceptions.h"

/**
 * Throws an zval object as exception
 */
void phalcon_throw_exception(zval *object TSRMLS_DC){
	Z_ADDREF_P(object);
	zend_throw_exception_object(object TSRMLS_CC);
	phalcon_memory_restore_stack(TSRMLS_C);
}

/**
 * Throws a exception with a single string parameter
 */
void phalcon_throw_exception_string(zend_class_entry *ce, char *message, zend_uint message_len TSRMLS_DC){
	zval *object, *msg;

	ALLOC_INIT_ZVAL(object);
	object_init_ex(object, ce);

	PHALCON_ALLOC_ZVAL_MM(msg);
	ZVAL_STRINGL(msg, message, message_len, 1);

	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(object, "__construct", msg, PH_CHECK);

	zend_throw_exception_object(object TSRMLS_CC);	

	phalcon_memory_restore_stack(TSRMLS_C);
}

/**
 * Latest version of zend_throw_exception_internal
 */
void phalcon_throw_exception_internal(zval *exception TSRMLS_DC) {

	if (exception != NULL) {
		zval *previous = EG(exception);
		zend_exception_set_previous(exception, EG(exception) TSRMLS_CC);
		EG(exception) = exception;
		if (previous) {
			return;
		}
	}
	if (!EG(current_execute_data)) {
		if(EG(exception)) {
			zend_exception_error(EG(exception), E_ERROR TSRMLS_CC);
		}
		zend_error(E_ERROR, "Exception thrown without a stack frame");
	}

	if (zend_throw_exception_hook) {
    	zend_throw_exception_hook(exception TSRMLS_CC);
	}

	if (EG(current_execute_data)->opline == NULL ||
    	(EG(current_execute_data)->opline+1)->opcode == ZEND_HANDLE_EXCEPTION) {
		/* no need to rethrow the exception */
		return;
	}
	EG(opline_before_exception) = EG(current_execute_data)->opline;
	EG(current_execute_data)->opline = EG(exception_op);
	
}

