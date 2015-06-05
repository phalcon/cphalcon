
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * Phalcon\Mvc\Model\Transaction\Failed
 *
 * This class will be thrown to exit a try/catch block for isolated transactions
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Failed) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Transaction, Failed, phalcon, mvc_model_transaction_failed, phalcon_mvc_model_transaction_exception_ce, phalcon_mvc_model_transaction_failed_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_transaction_failed_ce, SL("_record"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Transaction\Failed constructor
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *record = NULL;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &record);

	if (unlikely(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!record) {
		record = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("_record"), record TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_transaction_failed_ce, this_ptr, "__construct", NULL, 0, message);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns validation record messages which stop the transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, getRecordMessages) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *record;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(record);
	zephir_read_property_this(&record, this_ptr, SL("_record"), PH_NOISY_CC);
	if (Z_TYPE_P(record) != IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(record, "getmessages", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getmessage", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns validation record messages which stop the transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, getRecord) {


	RETURN_MEMBER(this_ptr, "_record");

}

