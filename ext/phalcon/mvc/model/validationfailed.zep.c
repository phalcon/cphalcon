
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\ValidationFailed
 *
 * This exception is generated when a model fails to save a record
 * Phalcon\Mvc\Model must be set up to have this behavior
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_ValidationFailed) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model, ValidationFailed, phalcon, mvc_model_validationfailed, phalcon_mvc_model_exception_ce, phalcon_mvc_model_validationfailed_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_validationfailed_ce, SL("messages"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_model_validationfailed_ce, SL("model"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\ValidationFailed constructor
 *
 * @param Message[] validationMessages
 */
PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval validationMessages;
	zval *model, model_sub, *validationMessages_param = NULL, messageStr, message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&messageStr);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&validationMessages);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &validationMessages_param);

	ZEPHIR_OBS_COPY_OR_DUP(&validationMessages, validationMessages_param);


	if (zephir_fast_count_int(&validationMessages) > 0) {
		ZEPHIR_OBS_VAR(&message);
		zephir_array_fetch_long(&message, &validationMessages, 0, PH_NOISY, "phalcon/Mvc/Model/ValidationFailed.zep", 40);
		ZEPHIR_CALL_METHOD(&messageStr, &message, "getmessage", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&messageStr);
		ZVAL_STRING(&messageStr, "Validation failed");
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("model"), model);
	zephir_update_property_zval(this_ptr, ZEND_STRL("messages"), &validationMessages);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_validationfailed_ce, getThis(), "__construct", NULL, 0, &messageStr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the complete group of messages produced in the validation
 */
PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, getMessages) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "messages");

}

/**
 * Returns the model that generated the messages
 */
PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, getModel) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "model");

}

