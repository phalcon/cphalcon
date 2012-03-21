
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

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

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
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_INIT_VAR(r0);
	is_smaller_function(r0, t1, t0 TSRMLS_CC);
	PHALCON_RETURN_NCTOR(r0);
}

/**
 * Returns a new Phalcon_Transaction or an already created once
 *
 * @param boolean $autoBegin
 * @return Phalcon_Transaction
 */
PHP_METHOD(Phalcon_Transaction_Manager, get){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_BOOL(v0, 1);
	}
	
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_initialized", sizeof("_initialized")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		add_next_index_stringl(a0, "Phalcon_Transaction_Manager", strlen("Phalcon_Transaction_Manager"), 1);
		add_next_index_stringl(a0, "rollbackPendent", strlen("rollbackPendent"), 1);
		PHALCON_CALL_FUNC_PARAMS_1_NORETURN("register_shutdown_function", a0, 0x03C);
		PHALCON_INIT_VAR(t1);
		ZVAL_BOOL(t1, 1);
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_initialized", sizeof("_initialized")-1, t1 TSRMLS_CC);
	}
	t2 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CPY_WRT(v1, t2);
	if (!zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_transaction_class_entry);
		Z_ADDREF_P(v0);
		p1[0] = v0;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		PHALCON_CPY_WRT(v2, i0);
		PHALCON_INIT_VAR(p2[0]);
		ZVAL_STRING(p2[0], "Phalcon_Transaction_Manager", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "settransactionmanager", 1, p2, PHALCON_CALL_DEFAULT);
		t3 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_dependencyPointer", sizeof("_dependencyPointer")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(t3);
		p3[0] = t3;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setdependencypointer", 1, p3, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p3[0]);
		t4 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_dependencyPointer", sizeof("_dependencyPointer")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_INIT_VAR(t5);
		ZVAL_LONG(t5, 2048);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_add_function(r0, t4, t5 TSRMLS_CC);
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_dependencyPointer", sizeof("_dependencyPointer")-1, r0 TSRMLS_CC);
		t6 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (Z_TYPE_P(t6) != IS_ARRAY) {
			convert_to_array(t6);
		}
		Z_ADDREF_P(v2);
		phalcon_array_append(t6, v2 TSRMLS_CC);
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, t6 TSRMLS_CC);
		
		t7 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_SEPARATE_NMO(t7);
		increment_function(t7);
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, t7 TSRMLS_CC);
	} else {
		t8 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_INIT_VAR(t10);
		ZVAL_LONG(t10, 1);
		PHALCON_ALLOC_ZVAL_MM(r1);
		sub_function(r1, v1, t10 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t9);
		phalcon_array_fetch(&t9, t8, r1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, t9);
		PHALCON_INIT_VAR(p4[0]);
		ZVAL_BOOL(p4[0], 0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setisnewtransaction", 1, p4, PHALCON_CALL_DEFAULT);
	}
	PHALCON_RETURN_CHECK_CTOR(v2);
}

/**
 * Rollbacks active transactions whithin the manager
 *
 */
PHP_METHOD(Phalcon_Transaction_Manager, rollbackPendent){


	PHALCON_MM_GROW();
	PHALCON_CALL_SELF_NORETURN(this_ptr, "rollback");
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Commmits active transactions whithin the manager
 *
 */
PHP_METHOD(Phalcon_Transaction_Manager, commit){

	zval *t0 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(t0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes62:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee62;
		}
		v0 = *hd;
		Z_REFCOUNT_P(v0);
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_METHOD(r0, v0, "getconnection", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v1, r0);
		PHALCON_INIT_VAR(r1);
		PHALCON_CALL_METHOD(r1, v1, "isundertransaction", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r1)) {
			PHALCON_CALL_METHOD_NORETURN(v1, "commit", PHALCON_CALL_DEFAULT);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes62;
		fee62:
		if(0){ };
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Rollbacks active transactions whithin the manager
 * Collect will remove transaction from the manager
 *
 * @param boolean $collect
 */
PHP_METHOD(Phalcon_Transaction_Manager, rollback){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p4[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_BOOL(v0, 0);
	}
	
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(t0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes63:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee63;
		}
		v1 = *hd;
		Z_REFCOUNT_P(v1);
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_METHOD(r0, v1, "getconnection", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v2, r0);
		PHALCON_INIT_VAR(r1);
		PHALCON_CALL_METHOD(r1, v2, "isundertransaction", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r1)) {
			PHALCON_CALL_METHOD_NORETURN(v2, "rollback", PHALCON_CALL_DEFAULT);
			PHALCON_CALL_METHOD_NORETURN(v2, "close", PHALCON_CALL_DEFAULT);
		}
		if (zend_is_true(v0)) {
			Z_ADDREF_P(v1);
			p4[0] = v1;
			PHALCON_CALL_SELF_PARAMS_NORETURN(this_ptr, "_collecttransaction", 1, p4);
			Z_DELREF_P(p4[0]);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes63;
		fee63:
		if(0){ };
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Notifies the manager about a rollbacked transaction
 *
 * @param Phalcon_Transaction $transaction
 */
PHP_METHOD(Phalcon_Transaction_Manager, notifyRollback){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_SELF_PARAMS_NORETURN(this_ptr, "_collecttransaction", 1, p0);
	Z_DELREF_P(p0[0]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Notifies the manager about a commited transaction
 *
 * @param Phalcon_Transaction $transaction
 */
PHP_METHOD(Phalcon_Transaction_Manager, notifyCommit){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_SELF_PARAMS_NORETURN(this_ptr, "_collecttransaction", 1, p0);
	Z_DELREF_P(p0[0]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Transaction_Manager, _collectTransaction){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *a0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "count", t0, 0x008);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_INIT_VAR(r1);
	is_smaller_function(r1, t1, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(v1);
		ZVAL_LONG(v1, 0);
		t2 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (Z_TYPE_P(t2) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(t2);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes64:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee64;
			}
			v2 = *hd;
			Z_REFCOUNT_P(v2);
			PHALCON_INIT_VAR(r2);
			is_equal_function(r2, v2, v0 TSRMLS_CC);
			if (zend_is_true(r2)) {
				t3 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
				PHALCON_SEPARATE_NMO(t3);
				decrement_function(t3);
				zend_update_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, t3 TSRMLS_CC);
			}
			PHALCON_SEPARATE(v1);
			increment_function(v1);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes64;
			fee64:
			if(0){ };
		}
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v3, a0);
		t4 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (Z_TYPE_P(t4) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah1 = Z_ARRVAL_P(t4);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes65:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee65;
			}
			v2 = *hd;
			Z_REFCOUNT_P(v2);
			Z_ADDREF_P(v2);
			PHALCON_SEPARATE_ARRAY(v3);
			phalcon_array_append(v3, v2 TSRMLS_CC);
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes65;
			fee65:
			if(0){ };
		}
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, v3 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Remove all the transactions from the manager
 *
 */
PHP_METHOD(Phalcon_Transaction_Manager, collectTransactions){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "count", t0, 0x008);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_INIT_VAR(r1);
	is_smaller_function(r1, t1, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_LONG(v0, 0);
		t2 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (Z_TYPE_P(t2) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(t2);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes66:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee66;
			}
			v1 = *hd;
			Z_REFCOUNT_P(v1);
			t3 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			PHALCON_SEPARATE_NMO(t3);
			decrement_function(t3);
			zend_update_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, t3 TSRMLS_CC);
			increment_function(v0);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes66;
			fee66:
			if(0){ };
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
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
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_automaticTransaction", sizeof("_automaticTransaction")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_NULL(t1);
	PHALCON_INIT_VAR(r0);
	is_not_equal_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_RETURN_NCTOR(r0);
}

/**
 * Returns automatic transaction for instances of Phalcon_Model_base
 *
 * @return Phalcon_Transaction
 */
PHP_METHOD(Phalcon_Transaction_Manager, getAutomatic){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_automaticTransaction", sizeof("_automaticTransaction")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

