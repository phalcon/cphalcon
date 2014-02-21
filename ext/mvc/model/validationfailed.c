
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

#include "mvc/model/validationfailed.h"
#include "mvc/model/exception.h"

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
zend_class_entry *phalcon_mvc_model_validationfailed_ce;

PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, __construct);
PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, getMessages);
PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, getModel);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validationfailed___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, validationMessages)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_validationfailed_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_ValidationFailed, __construct, arginfo_phalcon_mvc_model_validationfailed___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_ValidationFailed, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_ValidationFailed, getModel, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\ValidationFailed initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_ValidationFailed){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model, ValidationFailed, mvc_model_validationfailed, phalcon_mvc_model_exception_ce, phalcon_mvc_model_validationfailed_method_entry, 0);

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
		phalcon_array_fetch_long(&message, validation_messages, 0, PH_NOISY);
	
		/** 
		 * Get the message to use it in the exception
		 */
		PHALCON_CALL_METHOD(&message_str, message, "getmessage");
	} else {
		PHALCON_INIT_VAR(message_str);
		ZVAL_STRING(message_str, "Validation failed", 1);
	}
	phalcon_update_property_this(this_ptr, SL("_model"), model TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_messages"), validation_messages TSRMLS_CC);
	PHALCON_CALL_PARENT(NULL, phalcon_mvc_model_validationfailed_ce, this_ptr, "__construct", message_str);
	
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
