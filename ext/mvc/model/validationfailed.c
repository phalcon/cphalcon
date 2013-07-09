
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

#include "kernel/file.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"

/**
 * Phalcon\Mvc\Model\ValidationFailed
 *
 * This exception is generated when a model fails to save a record
 * Phalcon\Mvc\Model must be set up to have this behavior
 */


/**
 * Phalcon\Mvc\Model\ValidationFailed initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_ValidationFailed){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model, ValidationFailed, mvc_model_validationfailed, "phalcon\\mvc\\model\\exception", phalcon_mvc_model_validationfailed_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_validationfailed_ce, SL("_model"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_validationfailed_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\ValidationFailed constructor
 *
 * @param Phalcon\Mvc\Model $model
 * @param Phalcon\Mvc\Model\Message[] $validationMessages
 */
PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, __construct){

	zval *model, *validation_messages, *message;
	zval *message_str = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &validation_messages);
	
	if (phalcon_fast_count_ev(validation_messages TSRMLS_CC)) {
		/** 
		 * Get the first message in the array
		 */
		PHALCON_OBS_VAR(message);
		phalcon_array_fetch_long(&message, validation_messages, 0, PH_NOISY_CC);
	
		/** 
		 * Get the message to use it in the exception
		 */
		PHALCON_INIT_VAR(message_str);
		phalcon_call_method(message_str, message, "getmessage");
	} else {
		PHALCON_INIT_NVAR(message_str);
		ZVAL_STRING(message_str, "Validation failed", 1);
	}
	phalcon_update_property_this(this_ptr, SL("_model"), model TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_messages"), validation_messages TSRMLS_CC);
	PHALCON_CALL_PARENT_PARAMS_1_NORETURN(this_ptr, "Phalcon\\Mvc\\Model\\ValidationFailed", "__construct", message_str);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the complete group of messages produced in the validation
 *
 * @return Phalcon\Mvc\Model\Message[]
 */
PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, getMessages){


	RETURN_MEMBER(this_ptr, "_messages");
}

/**
 * Returns the model that generated the messages
 *
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, getModel){


	RETURN_MEMBER(this_ptr, "_model");
}

