
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\Transaction\Failed
 *
 * This class will be thrown to exit a try/catch block for isolated transactions
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Failed) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Transaction, Failed, phalcon, mvc_model_transaction_failed, phalcon_mvc_model_transaction_exception_ce, phalcon_mvc_model_transaction_failed_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_transaction_failed_ce, SL("record"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Transaction\Failed constructor
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *record = NULL, record_sub, __$null;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&record_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &record);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}
	if (!record) {
		record = &record_sub;
		record = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("record"), record);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_transaction_failed_ce, getThis(), "__construct", NULL, 0, &message);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns validation record messages which stop the transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, getRecord) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "record");

}

/**
 * Returns validation record messages which stop the transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, getRecordMessages) {

	zval record, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("record"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&record, &_0);
	if (Z_TYPE_P(&record) != IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(&record, "getmessages", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getmessage", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

