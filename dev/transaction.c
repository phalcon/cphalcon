
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

#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/array.h"

/**
 * Phalcon\Transaction
 *
 * Transactions are protective blocks where SQL statements are only permanent if they can
 * all succeed as one atomic action. Phalcon\Transaction is intended to be used with Phalcon_Model_Base.
 * Phalcon Transactions should be created using Phalcon\Transaction\Manager.
 *
 *
 */

/**
 * Phalcon\Transaction constructor
 *
 * @param boolean $autoBegin
 */
PHP_METHOD(Phalcon_Transaction, __construct){

	zval *auto_begin = NULL, *connection = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_transaction_ce, this_ptr, SL("_dependencies"), a0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a1);
	array_init(a1);
	zend_update_property(phalcon_transaction_ce, this_ptr, SL("_messages"), a1 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &auto_begin) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!auto_begin) {
		PHALCON_ALLOC_ZVAL_MM(auto_begin);
		ZVAL_BOOL(auto_begin, 0);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_BOOL(c0, 1);
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_STATIC_PARAMS_1(connection, "phalcon\\db\\pool", "getconnection", c0);
	phalcon_update_property_zval(this_ptr, SL("_connection"), connection TSRMLS_CC);
	if (zend_is_true(auto_begin)) {
		PHALCON_CALL_METHOD_NORETURN(connection, "begin", PH_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets transaction manager related to the transaction
 *
 * @param Phalcon\Transaction\Manager $manager
 */
PHP_METHOD(Phalcon_Transaction, setTransactionManager){

	zval *manager = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &manager) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(manager) != IS_OBJECT) {
		if (Z_TYPE_P(manager) != IS_STRING) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_transaction_exception_ce);
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_CONCAT_VS(r0, manager, " must be object or string");
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r0, PH_CHECK);
			phalcon_throw_exception(i0 TSRMLS_CC);
			return;
		}
	}
	phalcon_update_property_zval(this_ptr, SL("_manager"), manager TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Starts the transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Transaction, begin){

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
PHP_METHOD(Phalcon_Transaction, commit){

	zval *manager = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL;
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
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_connection"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, t0, "commit", PH_NO_CHECK);
	RETURN_CTOR(r0);
}

/**
 * Rollbacks the transaction
 *
 * @param  string $rollbackMessage
 * @param  Phalcon\Model\Base $rollbackRecord
 * @return boolean
 */
PHP_METHOD(Phalcon_Transaction, rollback){

	zval *rollback_message = NULL, *rollback_record = NULL;
	zval *manager = NULL, *success = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

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
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_connection"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD(success, t0, "rollback", PH_NO_CHECK);
	if (zend_is_true(success)) {
		if (!zend_is_true(rollback_message)) {
			PHALCON_INIT_VAR(rollback_message);
			ZVAL_STRING(rollback_message, "Transaction aborted", 1);
		}
		if (zend_is_true(rollback_record)) {
			phalcon_update_property_zval(this_ptr, SL("_rollbackRecord"), rollback_record TSRMLS_CC);
		}
		
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_transaction_failed_ce);
		
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_rollbackRecord"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i0, "__construct", rollback_message, t1, PH_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns connection related to transaction
 *
 * @return Phalcon_Db
 */
PHP_METHOD(Phalcon_Transaction, getConnection){

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
PHP_METHOD(Phalcon_Transaction, setIsNewTransaction){

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
PHP_METHOD(Phalcon_Transaction, setRollbackOnAbort){

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
PHP_METHOD(Phalcon_Transaction, isManaged){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_manager"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	boolean_not_function(r0, t0 TSRMLS_CC);
	
	RETURN_NCTOR(r0);
}

/**
 * Changes dependency internal pointer
 *
 * @param int $pointer
 */
PHP_METHOD(Phalcon_Transaction, setDependencyPointer){

	zval *pointer = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &pointer) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_pointer"), pointer TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Attaches Phalcon_Model_Base object to the active transaction
 *
 * @param int $pointer
 * @param Phalcon\Model\Base $object
 */
PHP_METHOD(Phalcon_Transaction, attachDependency){

	zval *pointer = NULL, *object = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &pointer, &object) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(pointer);
	
	if (!zend_is_true(pointer)) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, SL("_pointer"), PH_NOISY_CC);
		PHALCON_SEPARATE_NMO(t0);
		increment_function(t0);
		phalcon_update_property_zval(this_ptr, SL("_pointer"), t0 TSRMLS_CC);
		PHALCON_CPY_WRT(pointer, t0);
		
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_dependencies"), PH_NOISY_CC);
		phalcon_array_update(&t1, pointer, &object, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_dependencies"), t1 TSRMLS_CC);
		
		RETURN_CCTOR(pointer);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, SL("_dependencies"), PH_NOISY_CC);
		eval_int = phalcon_array_isset(t2, pointer);
		if (!eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t3);
			phalcon_read_property(&t3, this_ptr, SL("_dependencies"), PH_NOISY_CC);
			phalcon_array_update(&t3, pointer, &object, PH_COPY TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, SL("_dependencies"), t3 TSRMLS_CC);
			
			RETURN_CCTOR(pointer);
		} else {
			PHALCON_ALLOC_ZVAL_MM(t4);
			phalcon_read_property(&t4, this_ptr, SL("_pointer"), PH_NOISY_CC);
			PHALCON_SEPARATE_NMO(t4);
			increment_function(t4);
			phalcon_update_property_zval(this_ptr, SL("_pointer"), t4 TSRMLS_CC);
			PHALCON_CPY_WRT(pointer, t4);
			
			PHALCON_ALLOC_ZVAL_MM(t5);
			phalcon_read_property(&t5, this_ptr, SL("_dependencies"), PH_NOISY_CC);
			phalcon_array_update(&t5, pointer, &object, PH_COPY TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, SL("_dependencies"), t5 TSRMLS_CC);
			
			RETURN_CCTOR(pointer);
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Make a bulk save on all attached objects
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Transaction, save){

	zval *dependency = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, SL("_messages"), a0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dependencies"), PH_NOISY_CC);
	if (phalcon_valid_foreach(t0 TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(t0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_815a_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_815a_0;
		}
		
		PHALCON_INIT_VAR(dependency);
		ZVAL_ZVAL(dependency, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_METHOD(r0, dependency, "save", PH_NO_CHECK);
		if (!zend_is_true(r0)) {
			PHALCON_INIT_VAR(r1);
			PHALCON_CALL_METHOD(r1, dependency, "getmessages", PH_NO_CHECK);
			phalcon_update_property_zval(this_ptr, SL("_messages"), r1 TSRMLS_CC);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_815a_0;
		fee_815a_0:
		if(0){}
	} else {
		return;
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Returns validations messages from last save try
 *
 * @return array
 */
PHP_METHOD(Phalcon_Transaction, getMessages){

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
PHP_METHOD(Phalcon_Transaction, isValid){

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
 * @param Phalcon\Model\Base $record
 */
PHP_METHOD(Phalcon_Transaction, setRollbackedRecord){

	zval *record = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_rollbackRecord"), record TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

