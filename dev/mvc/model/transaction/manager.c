
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
#include "kernel/array.h"
#include "kernel/operators.h"

/**
 * Phalcon\Mvc\Model\Transaction\Manager
 *
 * A transaction acts on a single database connection. If you have multiple class-specific
 * databases, the transaction will not protect interaction among them
 *
  *
 *
 */

PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_mvc_model_transaction_manager_ce, this_ptr, SL("_transactions"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Checks whether manager has an active transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, has){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_number"), PH_NOISY_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_smaller_function(r0, t1, t0 TSRMLS_CC);
	
	RETURN_NCTOR(r0);
}

/**
 * Returns a new Phalcon\Mvc\Model\Transaction or an already created once
 *
 * @param boolean $autoBegin
 * @return Phalcon\Mvc\Model\Transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, get){

	zval *auto_begin = NULL, *number = NULL, *transaction = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &auto_begin) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!auto_begin) {
		PHALCON_ALLOC_ZVAL_MM(auto_begin);
		ZVAL_BOOL(auto_begin, 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		phalcon_array_append(&a0, this_ptr, PH_SEPARATE TSRMLS_CC);
		add_next_index_stringl(a0, SL("rollbackPendent"), 1);
		PHALCON_CALL_FUNC_PARAMS_1_NORETURN("register_shutdown_function", a0);
		phalcon_update_property_bool(this_ptr, SL("_initialized"), 1 TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(number);
	phalcon_read_property(&number, this_ptr, SL("_number"), PH_NOISY_CC);
	if (!zend_is_true(number)) {
		PHALCON_INIT_VAR(transaction);
		object_init_ex(transaction, phalcon_mvc_model_transaction_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(transaction, "__construct", auto_begin, PH_CHECK);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(transaction, "settransactionmanager", this_ptr, PH_NO_CHECK);
		
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_dependencyPointer"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(transaction, "setdependencypointer", t1, PH_NO_CHECK);
		
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, SL("_dependencyPointer"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 2048);
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_add_function(r0, t2, t3 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_dependencyPointer"), r0 TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_read_property(&t4, this_ptr, SL("_transactions"), PH_NOISY_CC);
		phalcon_array_append(&t4, transaction, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_transactions"), t4 TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_read_property(&t5, this_ptr, SL("_number"), PH_NOISY_CC);
		PHALCON_SEPARATE_NMO(t5);
		increment_function(t5);
		phalcon_update_property_zval(this_ptr, SL("_number"), t5 TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(t6);
		ZVAL_LONG(t6, 1);
		PHALCON_ALLOC_ZVAL_MM(r1);
		sub_function(r1, number, t6 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t7);
		phalcon_read_property(&t7, this_ptr, SL("_transactions"), PH_NOISY_CC);
		PHALCON_INIT_VAR(transaction);
		phalcon_array_fetch(&transaction, t7, r1, PH_NOISY_CC);
		
		PHALCON_INIT_VAR(c0);
		ZVAL_BOOL(c0, 0);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(transaction, "setisnewtransaction", c0, PH_NO_CHECK);
	}
	
	
	RETURN_CCTOR(transaction);
}

/**
 * Rollbacks active transactions within the manager
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollbackPendent){


	PHALCON_MM_GROW();
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "rollback", PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Commmits active transactions within the manager
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, commit){

	zval *transaction = NULL, *connection = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_transactions"), PH_NOISY_CC);
	if (!phalcon_valid_foreach(t0 TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(t0);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_4048_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_4048_0;
		}
		
		PHALCON_INIT_VAR(transaction);
		ZVAL_ZVAL(transaction, *hd, 1, 0);
		PHALCON_INIT_VAR(connection);
		PHALCON_CALL_METHOD(connection, transaction, "getconnection", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_METHOD(r0, connection, "isundertransaction", PH_NO_CHECK);
		if (zend_is_true(r0)) {
			PHALCON_CALL_METHOD_NORETURN(connection, "commit", PH_NO_CHECK);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_4048_0;
	fee_4048_0:
	if(0){}
	
	
	PHALCON_MM_RESTORE();
}

/**
 * Rollbacks active transactions within the manager
 * Collect will remove transaction from the manager
 *
 * @param boolean $collect
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollback){

	zval *collect = NULL, *transaction = NULL, *connection = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &collect) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!collect) {
		PHALCON_ALLOC_ZVAL_MM(collect);
		ZVAL_BOOL(collect, 0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_transactions"), PH_NOISY_CC);
	if (!phalcon_valid_foreach(t0 TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(t0);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_4048_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_4048_1;
		}
		
		PHALCON_INIT_VAR(transaction);
		ZVAL_ZVAL(transaction, *hd, 1, 0);
		PHALCON_INIT_VAR(connection);
		PHALCON_CALL_METHOD(connection, transaction, "getconnection", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_METHOD(r0, connection, "isundertransaction", PH_NO_CHECK);
		if (zend_is_true(r0)) {
			PHALCON_CALL_METHOD_NORETURN(connection, "rollback", PH_NO_CHECK);
			PHALCON_CALL_METHOD_NORETURN(connection, "close", PH_NO_CHECK);
		}
		
		if (zend_is_true(collect)) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_collecttransaction", transaction, PH_NO_CHECK);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_4048_1;
	fee_4048_1:
	if(0){}
	
	
	PHALCON_MM_RESTORE();
}

/**
 * Notifies the manager about a rollbacked transaction
 *
 * @param Phalcon\Mvc\Model\Transaction $transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyRollback){

	zval *transaction = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &transaction) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_collecttransaction", transaction, PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Notifies the manager about a commited transaction
 *
 * @param Phalcon\Mvc\Model\Transaction $transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyCommit){

	zval *transaction = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &transaction) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_collecttransaction", transaction, PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, _collectTransaction){

	zval *transaction = NULL, *transactions = NULL, *number = NULL, *managed_transaction = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &transaction) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(transactions);
	phalcon_read_property(&transactions, this_ptr, SL("_transactions"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_count(r0, transactions TSRMLS_CC);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_smaller_function(r1, t0, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(number);
		ZVAL_LONG(number, 0);
		if (!phalcon_valid_foreach(transactions TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(transactions);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_4048_2:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_4048_2;
			}
			
			PHALCON_INIT_VAR(managed_transaction);
			ZVAL_ZVAL(managed_transaction, *hd, 1, 0);
			PHALCON_INIT_VAR(r2);
			is_equal_function(r2, managed_transaction, transaction TSRMLS_CC);
			if (zend_is_true(r2)) {
				PHALCON_INIT_VAR(t1);
				phalcon_read_property(&t1, this_ptr, SL("_number"), PH_NOISY_CC);
				PHALCON_SEPARATE_NMO(t1);
				decrement_function(t1);
				phalcon_update_property_zval(this_ptr, SL("_number"), t1 TSRMLS_CC);
			}
			PHALCON_SEPARATE(number);
			increment_function(number);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_4048_2;
		fee_4048_2:
		if(0){}
		
		PHALCON_INIT_VAR(transactions);
		array_init(transactions);
		if (!phalcon_valid_foreach(transactions TSRMLS_CC)) {
			return;
		}
		
		ALLOC_HASHTABLE(ah1);
		zend_hash_init(ah1, 0, NULL, NULL, 0);
		zend_hash_copy(ah1, Z_ARRVAL_P(transactions), NULL, NULL, sizeof(zval*));
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		fes_4048_3:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_4048_3;
			}
			
			PHALCON_INIT_VAR(managed_transaction);
			ZVAL_ZVAL(managed_transaction, *hd, 1, 0);
			phalcon_array_append(&transactions, managed_transaction, PH_SEPARATE TSRMLS_CC);
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_4048_3;
		fee_4048_3:
		zend_hash_destroy(ah1);
		efree(ah1);
		
		phalcon_update_property_zval(this_ptr, SL("_transactions"), transactions TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Remove all the transactions from the manager
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, collectTransactions){

	zval *transactions = NULL, *number = NULL, *managed_transaction = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(transactions);
	phalcon_read_property(&transactions, this_ptr, SL("_transactions"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_count(r0, transactions TSRMLS_CC);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_smaller_function(r1, t0, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(number);
		ZVAL_LONG(number, 0);
		
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_transactions"), PH_NOISY_CC);
		if (!phalcon_valid_foreach(t1 TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(t1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_4048_4:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_4048_4;
			}
			
			PHALCON_INIT_VAR(managed_transaction);
			ZVAL_ZVAL(managed_transaction, *hd, 1, 0);
			PHALCON_INIT_VAR(t2);
			phalcon_read_property(&t2, this_ptr, SL("_number"), PH_NOISY_CC);
			PHALCON_SEPARATE_NMO(t2);
			decrement_function(t2);
			phalcon_update_property_zval(this_ptr, SL("_number"), t2 TSRMLS_CC);
			PHALCON_SEPARATE(number);
			increment_function(number);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_4048_4;
		fee_4048_4:
		if(0){}
		
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks whether manager will inject an automatic transaction to all newly
 * created instances of Phalcon\Mvc\Model
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, isAutomatic){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_automaticTransaction"), PH_NOISY_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_NULL(t1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_not_equal_function(r0, t0, t1 TSRMLS_CC);
	
	RETURN_NCTOR(r0);
}

/**
 * Returns automatic transaction for instances of Phalcon_Model_base
 *
 * @return Phalcon\Mvc\Model\Transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getAutomatic){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_automaticTransaction"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

