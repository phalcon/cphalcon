
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
 * Phalcon_Transaction
 *
 * Transactions are protective blocks where SQL statements are only permanent if they can
 * all succeed as one atomic action. Phalcon_Transaction is intended to be used with Phalcon_Model_Base.
 * Phalcon Transactions should be created using Phalcon_Transaction_Manager.
 *
 *
 */

/**
 * Phalcon_Transaction constructor
 *
 * @param boolean $autoBegin
 */
PHP_METHOD(Phalcon_Transaction, __construct){

	zval *a0 = NULL, *a1 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_transaction_class_entry, this_ptr, "_dependencies", strlen("_dependencies"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_transaction_class_entry, this_ptr, "_messages", strlen("_messages"), a1 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_BOOL(v0, 0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_BOOL(p0[0], 1);
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_pool", "getconnection", 1, p0);
	PHALCON_CPY_WRT(v1, r0);
	phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), v1 TSRMLS_CC);
	PHALCON_INIT_VAR(t0);
	ZVAL_BOOL(t0, 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, v0, t0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_CALL_METHOD_NORETURN(v1, "begin", PHALCON_CALL_DEFAULT);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sets transaction manager related to the transaction
 *
 * @param Phalcon_Transaction_Manager $manager
 */
PHP_METHOD(Phalcon_Transaction, setTransactionManager){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_manager", strlen("_manager"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Starts the transaction
 */
PHP_METHOD(Phalcon_Transaction, begin){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t0, "begin", PHALCON_CALL_DEFAULT);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Commits the transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Transaction, commit){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!PHALCON_COMPARE_STRING(t0, "")) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t1);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, t1);
		add_next_index_stringl(a0, "notifyCommit", strlen("notifyCommit"), 1);
		Z_ADDREF_P(a0);
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		Z_ADDREF_P(this_ptr);
		PHALCON_SEPARATE_ARRAY(a1);
		add_next_index_zval(a1, this_ptr);
		Z_ADDREF_P(a1);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("call_user_func_array", a0, a1, 0x001);
		Z_DELREF_P(a0);
		Z_DELREF_P(a1);
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t2, "commit", PHALCON_CALL_DEFAULT);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Rollbacks the transaction
 *
 * @param  string $rollbackMessage
 * @param  Phalcon_Model_Base $rollbackRecord
 * @return boolean
 */
PHP_METHOD(Phalcon_Transaction, rollback){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *i0 = NULL;
	zval *p2[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(v0);
	}
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_NULL(v1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!PHALCON_COMPARE_STRING(t0, "")) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t1);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, t1);
		add_next_index_stringl(a0, "notifyRollback", strlen("notifyRollback"), 1);
		Z_ADDREF_P(a0);
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		Z_ADDREF_P(this_ptr);
		PHALCON_SEPARATE_ARRAY(a1);
		add_next_index_zval(a1, this_ptr);
		Z_ADDREF_P(a1);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("call_user_func_array", a0, a1, 0x001);
		Z_DELREF_P(a0);
		Z_DELREF_P(a1);
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t2, "rollback", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_INIT_VAR(t3);
	ZVAL_BOOL(t3, 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, v2, t3 TSRMLS_CC);
	if (zend_is_true(r1)) {
		if (PHALCON_COMPARE_STRING(v0, "")) {
			PHALCON_INIT_VAR(v0);
			ZVAL_STRING(v0, "Transaction aborted", 1);
		}
		if (zend_is_true(v1)) {
			phalcon_update_property_zval(this_ptr, "_rollbackRecord", strlen("_rollbackRecord"), v1 TSRMLS_CC);
		}
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_transaction_failed_class_entry);
		Z_ADDREF_P(v0);
		p2[0] = v0;
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_read_property(&t4, this_ptr, "_rollbackRecord", sizeof("_rollbackRecord")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t4);
		p2[1] = t4;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p2, PHALCON_CALL_CHECK);
		Z_DELREF_P(p2[0]);
		Z_DELREF_P(p2[1]);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns connection related to transaction
 *
 * @return Phalcon_Db
 */
PHP_METHOD(Phalcon_Transaction, getConnection){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *p1[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_rollbackOnAbort", sizeof("_rollbackOnAbort")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC(r0, "connection_aborted", 0x03B);
		if (zend_is_true(r0)) {
			PHALCON_INIT_VAR(p1[0]);
			ZVAL_STRING(p1[0], "The request was aborted", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "rollback", 1, p1, PHALCON_CALL_DEFAULT);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Sets if is a reused transaction or new once
 *
 * @param boolean $isNew
 */
PHP_METHOD(Phalcon_Transaction, setIsNewTransaction){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_isNewTransaction", strlen("_isNewTransaction"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sets flag to rollback on abort the HTTP connection
 *
 * @param boolean $rollbackOnAbort
 */
PHP_METHOD(Phalcon_Transaction, setRollbackOnAbort){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_rollbackOnAbort", strlen("_rollbackOnAbort"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Checks whether transaction is managed by a transaction manager
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Transaction, isManaged){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_NULL(t1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, t0, t1 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(t2);
		ZVAL_BOOL(t2, 0);
		r0 = t2;
	} else {
		PHALCON_INIT_VAR(t3);
		ZVAL_BOOL(t3, 1);
		r0 = t3;
	}
	PHALCON_RETURN_CHECK_CTOR(r0);
}

/**
 * Changes dependency internal pointer
 *
 * @param int $pointer
 */
PHP_METHOD(Phalcon_Transaction, setDependencyPointer){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Attaches Phalcon_Model_Base object to the active transaction
 *
 * @param int $pointer
 * @param Phalcon_Model_Base $object
 */
PHP_METHOD(Phalcon_Transaction, attachDependency){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v0);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_NULL(t0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, v0, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_SEPARATE_NMO(t1);
		increment_function(t1);
		phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), t1 TSRMLS_CC);
		PHALCON_CPY_WRT(v0, t1);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(v1);
		phalcon_array_update(t2, v0, v1 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_dependencies", strlen("_dependencies"), t2 TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(v0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(t3, v0);
		if (!eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t4);
			phalcon_read_property(&t4, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(v1);
			phalcon_array_update(t4, v0, v1 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_dependencies", strlen("_dependencies"), t4 TSRMLS_CC);
			PHALCON_RETURN_CHECK_CTOR(v0);
		} else {
			PHALCON_ALLOC_ZVAL_MM(t5);
			phalcon_read_property(&t5, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE_NMO(t5);
			increment_function(t5);
			phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), t5 TSRMLS_CC);
			PHALCON_CPY_WRT(v0, t5);
			PHALCON_ALLOC_ZVAL_MM(t6);
			phalcon_read_property(&t6, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(v1);
			phalcon_array_update(t6, v0, v1 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_dependencies", strlen("_dependencies"), t6 TSRMLS_CC);
			PHALCON_RETURN_CHECK_CTOR(v0);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Make a bulk save on all attached objects
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Transaction, save){

	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, "_messages", strlen("_messages"), a0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(t0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes61:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee61;
		}
		v0 = *hd;
		Z_REFCOUNT_P(v0);
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_METHOD(r0, v0, "save", PHALCON_CALL_DEFAULT);
		PHALCON_INIT_VAR(t1);
		ZVAL_BOOL(t1, 0);
		PHALCON_INIT_VAR(r1);
		is_equal_function(r1, r0, t1 TSRMLS_CC);
		if (zend_is_true(r1)) {
			PHALCON_INIT_VAR(r2);
			PHALCON_CALL_METHOD(r2, v0, "getmessages", PHALCON_CALL_DEFAULT);
			phalcon_update_property_zval(this_ptr, "_messages", strlen("_messages"), r2 TSRMLS_CC);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes61;
		fee61:
		if(0){ };
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
	phalcon_read_property(&t0, this_ptr, "_messages", sizeof("_messages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
     * Checks whether internal connection is under an active transaction
     *
     * @return boolean
     */
PHP_METHOD(Phalcon_Transaction, isValid){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t0, "isundertransaction", PHALCON_CALL_DEFAULT);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Sets object which generates rollback action
 *
 * @param Phalcon_Model_Base $record
 */
PHP_METHOD(Phalcon_Transaction, setRollbackedRecord){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_rollbackRecord", strlen("_rollbackRecord"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

