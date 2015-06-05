
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
 * Phalcon\Mvc\Model\ValidationFailed
 *
 * This exception is generated when a model fails to save a record
 * Phalcon\Mvc\Model must be set up to have this behavior
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_ValidationFailed) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model, ValidationFailed, phalcon, mvc_model_validationfailed, phalcon_mvc_model_exception_ce, phalcon_mvc_model_validationfailed_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_validationfailed_ce, SL("_model"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_validationfailed_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\ValidationFailed constructor
 *
 * @param Model model
 * @param Message[] validationMessages
 */
PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *validationMessages = NULL;
	zval *model, *validationMessages_param = NULL, *messageStr = NULL, *message;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &validationMessages_param);

	validationMessages = validationMessages_param;



	if (zephir_fast_count_int(validationMessages TSRMLS_CC) > 0) {
		ZEPHIR_OBS_VAR(message);
		zephir_array_fetch_long(&message, validationMessages, 0, PH_NOISY, "phalcon/mvc/model/validationfailed.zep", 51 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&messageStr, message, "getmessage", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(messageStr);
		ZVAL_STRING(messageStr, "Validation failed", 1);
	}
	zephir_update_property_this(this_ptr, SL("_model"), model TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_messages"), validationMessages TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_validationfailed_ce, this_ptr, "__construct", NULL, 0, messageStr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the model that generated the messages
 */
PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, getModel) {


	RETURN_MEMBER(this_ptr, "_model");

}

/**
 * Returns the complete group of messages produced in the validation
 */
PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, getMessages) {


	RETURN_MEMBER(this_ptr, "_messages");

}

