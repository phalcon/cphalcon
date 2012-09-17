
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
 * Phalcon\Mvc\Model\Transaction\Failed constructor
 *
 * @param string $message
 * @param Phalcon\Mvc\Model $record
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, __construct){

	zval *message = NULL, *record = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &message, &record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_record"), record TSRMLS_CC);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_LONG(c0, 0);
	PHALCON_CALL_PARENT_PARAMS_2_NORETURN(this_ptr, "Phalcon\\Mvc\\Model\\Transaction\\Failed", "__construct", message, c0);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns validation record messages which stop the transaction
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, getRecordMessages){

	zval *record = NULL, *messages = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(record);
	phalcon_read_property(&record, this_ptr, SL("_record"), PH_NOISY_CC);
	if (Z_TYPE_P(record) != IS_NULL) {
		PHALCON_INIT_VAR(record);
		PHALCON_CALL_METHOD(record, record, "getmessages", PH_NO_CHECK);
		
		RETURN_CCTOR(record);
	}
	
	PHALCON_INIT_VAR(messages);
	PHALCON_CALL_METHOD(messages, this_ptr, "getmessage", PH_NO_CHECK);
	
	RETURN_CCTOR(messages);
}

/**
 * Returns validation record messages which stop the transaction
 *
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, getRecord){

	zval *record = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(record);
	phalcon_read_property(&record, this_ptr, SL("_record"), PH_NOISY_CC);
	
	RETURN_CCTOR(record);
}

