
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
 * This class will be thrown to exit a try/catch block for isolated transactions
 */


/**
 * Phalcon\Mvc\Model\Transaction\Failed initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Failed){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Transaction, Failed, mvc_model_transaction_failed, "phalcon\\mvc\\model\\transaction\\exception", phalcon_mvc_model_transaction_failed_method_entry, 0);

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

	phalcon_fetch_params(1, 2, 0, &message, &record);
	
	phalcon_update_property_this(this_ptr, SL("_record"), record TSRMLS_CC);
	phalcon_call_parent_p1_noret(this_ptr, phalcon_mvc_model_transaction_failed_ce, "__construct", message);
	
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
	phalcon_read_property_this(&record, this_ptr, SL("_record"), PH_NOISY_CC);
	if (Z_TYPE_P(record) != IS_NULL) {
		PHALCON_INIT_NVAR(record);
		phalcon_call_method(record, record, "getmessages");
		RETURN_CCTOR(record);
	}
	
	PHALCON_INIT_VAR(messages);
	phalcon_call_method(messages, this_ptr, "getmessage");
	
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

