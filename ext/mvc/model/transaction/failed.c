
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

#include "kernel/object.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Mvc\Model\Transaction\Failed
 *
 * Phalcon\Mvc\Model\Transaction\Failed will be thrown to exit a try/catch block for transactions
 *
 */


/**
 * Phalcon\Mvc\Model\Transaction\Failed initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Failed){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Transaction, Failed, mvc_model_transaction_failed, "exception", phalcon_mvc_model_transaction_failed_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_transaction_failed_ce, SL("_record"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Transaction\Failed constructor
 *
 * @param string $message
 * @param Phalcon\Mvc\ModelInterface $record
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, __construct){

	zval *message, *record;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &message, &record) == FAILURE) {
		RETURN_MM_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_record"), record TSRMLS_CC);
	PHALCON_CALL_PARENT_PARAMS_1_NORETURN(this_ptr, "Phalcon\\Mvc\\Model\\Transaction\\Failed", "__construct", message);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns validation record messages which stop the transaction
 *
 * @return Phalcon\Mvc\Model\MessageInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, getRecordMessages){

	zval *record = NULL, *messages;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(record);
	phalcon_read_property(&record, this_ptr, SL("_record"), PH_NOISY_CC);
	if (Z_TYPE_P(record) != IS_NULL) {
		PHALCON_INIT_NVAR(record);
		PHALCON_CALL_METHOD(record, record, "getmessages");
		RETURN_CCTOR(record);
	}
	
	PHALCON_INIT_VAR(messages);
	PHALCON_CALL_METHOD(messages, this_ptr, "getmessage");
	
	RETURN_CCTOR(messages);
}

/**
 * Returns validation record messages which stop the transaction
 *
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, getRecord){


	RETURN_MEMBER(this_ptr, "_record");
}

