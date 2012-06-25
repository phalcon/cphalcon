
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
#include "kernel/operators.h"
#include "kernel/array.h"
/**
 * Phalcon_Transaction_Manager
 *
 * A transaction acts on a single database connection. If you have multiple class-specific
 * databases, the transaction will not protect interaction among them
 *
  *
 *
 */

/**
 * Checks whether manager has an active transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Transaction_Manager, has){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Transaction_Manager"), SL("_number") TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_INIT_VAR(r0);
	is_smaller_function(r0, t1, t0 TSRMLS_CC);
	
	RETURN_NCTOR(r0);
}

/**
 * Returns a new Phalcon_Transaction or an already created once
 *
 * @param boolean $autoBegin
 * @return Phalcon_Transaction
 */
PHP_METHOD(Phalcon_Transaction_Manager, get){

	zval *auto_begin = NULL, *number = NULL, *transaction = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &auto_begin) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!auto_begin) {
		PHALCON_INIT_VAR(auto_begin);
		ZVAL_BOOL(auto_begin, 1);
	}
	
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Transaction_Manager"), SL("_initialized") TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		add_next_index_stringl(a0, SL("Phalcon_Transaction_Manager"), 1);
		add_next_index_stringl(a0, SL("rollbackPendent"), 1);
		PHALCON_CALL_FUNC_PARAMS_1_NORETURN("register_shutdown_function", a0);
		
		PHALCON_INIT_VAR(t1);
		ZVAL_BOOL(t1, 1);
		phalcon_update_static_property(SL("Phalcon_Transaction_Manager"), SL("_initialized"), t1 TSRMLS_CC);
	}
	PHALCON_OBSERVE_VAR(t2);
	phalcon_read_static_property(&t2, SL("Phalcon_Transaction_Manager"), SL("_number") TSRMLS_CC);
	PHALCON_CPY_WRT(number, t2);
	if (!zend_is_true(number)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_transaction_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", auto_begin, PHALCON_CHECK);
		PHALCON_CPY_WRT(transaction, i0);
		
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "Phalcon_Transaction_Manager", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(transaction, "settransactionmanager", c0, PHALCON_NO_CHECK);
		PHALCON_OBSERVE_VAR(t3);
		phalcon_read_static_property(&t3, SL("Phalcon_Transaction_Manager"), SL("_dependencyPointer") TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(transaction, "setdependencypointer", t3, PHALCON_NO_CHECK);
		PHALCON_OBSERVE_VAR(t4);
		phalcon_read_static_property(&t4, SL("Phalcon_Transaction_Manager"), SL("_dependencyPointer") TSRMLS_CC);
		
		PHALCON_INIT_VAR(t5);
		ZVAL_LONG(t5, 2048);
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_add_function(r0, t4, t5 TSRMLS_CC);
		phalcon_update_static_property(SL("Phalcon_Transaction_Manager"), SL("_dependencyPointer"), r0 TSRMLS_CC);
		t6 = zend_read_static_property(phalcon_transaction_manager_ce, SL("_transactions"), PHALCON_FETCH_CLASS_SILENT);
		if (Z_TYPE_P(t6) != IS_ARRAY) {
			convert_to_array(t6);
		}
		phalcon_array_append(&t6, transaction, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
		phalcon_update_static_property(SL("phalcon_transaction_manager_ce"), SL("_transactions"), t6 TSRMLS_CC);
		
		PHALCON_OBSERVE_VAR(t7);
		phalcon_read_static_property(&t7, SL("Phalcon_Transaction_Manager"), SL("_number") TSRMLS_CC);
		PHALCON_SEPARATE_NMO(t7);
		increment_function(t7);
		phalcon_update_static_property(SL("Phalcon_Transaction_Manager"), SL("_number"), t7 TSRMLS_CC);
	} else {
		PHALCON_OBSERVE_VAR(t8);
		phalcon_read_static_property(&t8, SL("Phalcon_Transaction_Manager"), SL("_transactions") TSRMLS_CC);
		PHALCON_INIT_VAR(t10);
		ZVAL_LONG(t10, 1);
		PHALCON_ALLOC_ZVAL_MM(r1);
		sub_function(r1, number, t10 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t9);
		phalcon_array_fetch(&t9, t8, r1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(transaction, t9);
		
		PHALCON_INIT_VAR(c1);
		ZVAL_BOOL(c1, 0);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(transaction, "setisnewtransaction", c1, PHALCON_NO_CHECK);
	}
	
	
	RETURN_CHECK_CTOR(transaction);
}

/**
 * Rollbacks active transactions whithin the manager
 *
 */
PHP_METHOD(Phalcon_Transaction_Manager, rollbackPendent){


	PHALCON_MM_GROW();
	PHALCON_CALL_SELF_NORETURN(this_ptr, "rollback");
	
	PHALCON_MM_RESTORE();
}

/**
 * Commmits active transactions whithin the manager
 *
 */
PHP_METHOD(Phalcon_Transaction_Manager, commit){

	zval *transaction = NULL, *connection = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Transaction_Manager"), SL("_transactions") TSRMLS_CC);
	if (phalcon_valid_foreach(t0 TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(t0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_ad2c_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_ad2c_0;
		}
		PHALCON_INIT_VAR(transaction);
		ZVAL_ZVAL(transaction, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_METHOD(r0, transaction, "getconnection", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(connection, r0);
		
		PHALCON_INIT_VAR(r1);
		PHALCON_CALL_METHOD(r1, connection, "isundertransaction", PHALCON_NO_CHECK);
		if (zend_is_true(r1)) {
			PHALCON_CALL_METHOD_NORETURN(connection, "commit", PHALCON_NO_CHECK);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_ad2c_0;
		fee_ad2c_0:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Rollbacks active transactions whithin the manager
 * Collect will remove transaction from the manager
 *
 * @param boolean $collect
 */
PHP_METHOD(Phalcon_Transaction_Manager, rollback){

	zval *collect = NULL, *transaction = NULL, *connection = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &collect) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!collect) {
		PHALCON_INIT_VAR(collect);
		ZVAL_BOOL(collect, 0);
	}
	
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Transaction_Manager"), SL("_transactions") TSRMLS_CC);
	if (phalcon_valid_foreach(t0 TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(t0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_ad2c_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_ad2c_1;
		}
		PHALCON_INIT_VAR(transaction);
		ZVAL_ZVAL(transaction, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_METHOD(r0, transaction, "getconnection", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(connection, r0);
		
		PHALCON_INIT_VAR(r1);
		PHALCON_CALL_METHOD(r1, connection, "isundertransaction", PHALCON_NO_CHECK);
		if (zend_is_true(r1)) {
			PHALCON_CALL_METHOD_NORETURN(connection, "rollback", PHALCON_NO_CHECK);
			PHALCON_CALL_METHOD_NORETURN(connection, "close", PHALCON_NO_CHECK);
		}
		
		if (zend_is_true(collect)) {
			PHALCON_CALL_SELF_PARAMS_1_NORETURN(this_ptr, "_collecttransaction", transaction);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_ad2c_1;
		fee_ad2c_1:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Notifies the manager about a rollbacked transaction
 *
 * @param Phalcon_Transaction $transaction
 */
PHP_METHOD(Phalcon_Transaction_Manager, notifyRollback){

	zval *transaction = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &transaction) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_CALL_SELF_PARAMS_1_NORETURN(this_ptr, "_collecttransaction", transaction);
	
	PHALCON_MM_RESTORE();
}

/**
 * Notifies the manager about a commited transaction
 *
 * @param Phalcon_Transaction $transaction
 */
PHP_METHOD(Phalcon_Transaction_Manager, notifyCommit){

	zval *transaction = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &transaction) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_CALL_SELF_PARAMS_1_NORETURN(this_ptr, "_collecttransaction", transaction);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Transaction_Manager, _collectTransaction){

	zval *transaction = NULL, *number = NULL, *managed_transaction = NULL;
	zval *transactions = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *a0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &transaction) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Transaction_Manager"), SL("_transactions") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_count(r0, t0 TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_INIT_VAR(r1);
	is_smaller_function(r1, t1, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(number);
		ZVAL_LONG(number, 0);
		PHALCON_OBSERVE_VAR(t2);
		phalcon_read_static_property(&t2, SL("Phalcon_Transaction_Manager"), SL("_transactions") TSRMLS_CC);
		if (phalcon_valid_foreach(t2 TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(t2);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_ad2c_2:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_ad2c_2;
			}
			
			PHALCON_INIT_VAR(managed_transaction);
			ZVAL_ZVAL(managed_transaction, *hd, 1, 0);
			PHALCON_INIT_VAR(r2);
			is_equal_function(r2, managed_transaction, transaction TSRMLS_CC);
			if (zend_is_true(r2)) {
				PHALCON_OBSERVE_VAR(t3);
				phalcon_read_static_property(&t3, SL("Phalcon_Transaction_Manager"), SL("_number") TSRMLS_CC);
				PHALCON_SEPARATE_NMO(t3);
				decrement_function(t3);
				phalcon_update_static_property(SL("Phalcon_Transaction_Manager"), SL("_number"), t3 TSRMLS_CC);
			}
			PHALCON_SEPARATE(number);
			increment_function(number);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_ad2c_2;
			fee_ad2c_2:
			if(0){}
		} else {
			return;
		}
		
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(transactions, a0);
		PHALCON_OBSERVE_VAR(t4);
		phalcon_read_static_property(&t4, SL("Phalcon_Transaction_Manager"), SL("_transactions") TSRMLS_CC);
		if (phalcon_valid_foreach(t4 TSRMLS_CC)) {
			ah1 = Z_ARRVAL_P(t4);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_ad2c_3:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_ad2c_3;
			}
			
			PHALCON_INIT_VAR(managed_transaction);
			ZVAL_ZVAL(managed_transaction, *hd, 1, 0);
			phalcon_array_append(&transactions, managed_transaction, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_ad2c_3;
			fee_ad2c_3:
			if(0){}
		} else {
			return;
		}
		phalcon_update_static_property(SL("Phalcon_Transaction_Manager"), SL("_transactions"), transactions TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Remove all the transactions from the manager
 *
 */
PHP_METHOD(Phalcon_Transaction_Manager, collectTransactions){

	zval *number = NULL, *managed_transaction = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Transaction_Manager"), SL("_transactions") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_count(r0, t0 TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_INIT_VAR(r1);
	is_smaller_function(r1, t1, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(number);
		ZVAL_LONG(number, 0);
		PHALCON_OBSERVE_VAR(t2);
		phalcon_read_static_property(&t2, SL("Phalcon_Transaction_Manager"), SL("_transactions") TSRMLS_CC);
		if (phalcon_valid_foreach(t2 TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(t2);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_ad2c_4:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_ad2c_4;
			}
			
			PHALCON_INIT_VAR(managed_transaction);
			ZVAL_ZVAL(managed_transaction, *hd, 1, 0);
			PHALCON_OBSERVE_VAR(t3);
			phalcon_read_static_property(&t3, SL("Phalcon_Transaction_Manager"), SL("_number") TSRMLS_CC);
			PHALCON_SEPARATE_NMO(t3);
			decrement_function(t3);
			phalcon_update_static_property(SL("Phalcon_Transaction_Manager"), SL("_number"), t3 TSRMLS_CC);
			PHALCON_SEPARATE(number);
			increment_function(number);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_ad2c_4;
			fee_ad2c_4:
			if(0){}
		} else {
			return;
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks whether manager will inject an automatic transaction to all newly
 * created instances of Phalcon_Model_base
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Transaction_Manager, isAutomatic){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Transaction_Manager"), SL("_automaticTransaction") TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_NULL(t1);
	PHALCON_INIT_VAR(r0);
	is_not_equal_function(r0, t0, t1 TSRMLS_CC);
	
	RETURN_NCTOR(r0);
}

/**
 * Returns automatic transaction for instances of Phalcon_Model_base
 *
 * @return Phalcon_Transaction
 */
PHP_METHOD(Phalcon_Transaction_Manager, getAutomatic){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Transaction_Manager"), SL("_automaticTransaction") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

