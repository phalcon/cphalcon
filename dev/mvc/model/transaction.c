
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

#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/array.h"

/**
 * Phalcon\Mvc\Model\Transaction
 *
 * Transactions are protective blocks where SQL statements are only permanent if they can
 * all succeed as one atomic action. Phalcon\Transaction is intended to be used with Phalcon_Model_Base.
 * Phalcon Transactions should be created using Phalcon\Transaction\Manager.
 *
 *
 */

/**
 * Phalcon\Mvc\Model\Transaction constructor
 *
 * @param Phalcon\DI $dependencyInjector
 * @param boolean $autoBegin
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, __construct){

	zval *dependency_injector = NULL, *auto_begin = NULL, *connection = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_mvc_model_transaction_ce, this_ptr, SL("_dependencies"), a0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a1);
	array_init(a1);
	zend_update_property(phalcon_mvc_model_transaction_ce, this_ptr, SL("_messages"), a1 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &dependency_injector, &auto_begin) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!auto_begin) {
		PHALCON_ALLOC_ZVAL_MM(auto_begin);
		ZVAL_BOOL(auto_begin, 0);
	}
	
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "db", 1);
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD_PARAMS_1(connection, dependency_injector, "get", c0, PH_NO_CHECK);
	phalcon_update_property_zval(this_ptr, SL("_connection"), connection TSRMLS_CC);
	if (zend_is_true(auto_begin)) {
		PHALCON_CALL_METHOD_NORETURN(connection, "begin", PH_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets transaction manager related to the transaction
 *
 * @param Phalcon\Mvc\Model\Transaction\Manager $manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setTransactionManager){

	zval *manager = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &manager) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(manager) != IS_OBJECT) {
		ce0 = zend_fetch_class(SL("Phalcon_Transaction_Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, ce0);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VS(r0, manager, " must be an Object");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r0, PH_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_manager"), manager TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Starts the transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, begin){

	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_connection"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, t0, "begin", PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Commits the transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, commit){

	zval *manager = NULL, *connection = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	if (zend_is_true(manager)) {
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		phalcon_array_append(&a0, manager, PH_SEPARATE TSRMLS_CC);
		add_next_index_stringl(a0, SL("notifyCommit"), 1);
		PHALCON_ALLOC_ZVAL_MM(a1);
		array_init(a1);
		phalcon_array_append(&a1, this_ptr, PH_SEPARATE TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("call_user_func_array", a0, a1);
	}
	
	PHALCON_INIT_VAR(connection);
	phalcon_read_property(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, connection, "commit", PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Rollbacks the transaction
 *
 * @param  string $rollbackMessage
 * @param  Phalcon\Mvc\Model $rollbackRecord
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, rollback){

	zval *rollback_message = NULL, *rollback_record = NULL;
	zval *manager = NULL, *connection = NULL, *success = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &rollback_message, &rollback_record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!rollback_message) {
		PHALCON_ALLOC_ZVAL_MM(rollback_message);
		ZVAL_NULL(rollback_message);
	} else {
		PHALCON_SEPARATE_PARAM(rollback_message);
	}
	
	if (!rollback_record) {
		PHALCON_ALLOC_ZVAL_MM(rollback_record);
		ZVAL_NULL(rollback_record);
	}
	
	PHALCON_INIT_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	if (zend_is_true(manager)) {
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		phalcon_array_append(&a0, manager, PH_SEPARATE TSRMLS_CC);
		add_next_index_stringl(a0, SL("notifyRollback"), 1);
		PHALCON_ALLOC_ZVAL_MM(a1);
		array_init(a1);
		phalcon_array_append(&a1, this_ptr, PH_SEPARATE TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("call_user_func_array", a0, a1);
	}
	
	PHALCON_INIT_VAR(connection);
	phalcon_read_property(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD(success, connection, "rollback", PH_NO_CHECK);
	if (zend_is_true(success)) {
		if (!zend_is_true(rollback_message)) {
			PHALCON_INIT_VAR(rollback_message);
			ZVAL_STRING(rollback_message, "Transaction aborted", 1);
		}
		if (zend_is_true(rollback_record)) {
			phalcon_update_property_zval(this_ptr, SL("_rollbackRecord"), rollback_record TSRMLS_CC);
		}
		
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_mvc_model_transaction_failed_ce);
		
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, SL("_rollbackRecord"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i0, "__construct", rollback_message, t0, PH_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns connection related to transaction
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, getConnection){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_rollbackOnAbort"), PH_NOISY_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC(r0, "connection_aborted");
		if (zend_is_true(r0)) {
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "The request was aborted", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "rollback", c0, PH_NO_CHECK);
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_connection"), PH_NOISY_CC);
	
	RETURN_CCTOR(t1);
}

/**
 * Sets if is a reused transaction or new once
 *
 * @param boolean $isNew
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setIsNewTransaction){

	zval *is_new = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &is_new) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_isNewTransaction"), is_new TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets flag to rollback on abort the HTTP connection
 *
 * @param boolean $rollbackOnAbort
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setRollbackOnAbort){

	zval *rollback_on_abort = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &rollback_on_abort) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_rollbackOnAbort"), rollback_on_abort TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks whether transaction is managed by a transaction manager
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, isManaged){

	zval *manager = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	boolean_not_function(r0, manager TSRMLS_CC);
	
	RETURN_NCTOR(r0);
}

/**
 * Returns validations messages from last save try
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, getMessages){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_messages"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Checks whether internal connection is under an active transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, isValid){

	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_connection"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, t0, "isundertransaction", PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Sets object which generates rollback action
 *
 * @param Phalcon\Mvc\Model $record
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setRollbackedRecord){

	zval *record = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_rollbackRecord"), record TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

