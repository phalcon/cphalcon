
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

	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_property(phalcon_transaction_class_entry, this_ptr, "_dependencies", strlen("_dependencies"), a0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	zend_update_property(phalcon_transaction_class_entry, this_ptr, "_messages", strlen("_messages"), a1 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_BOOL(v0, 0);
	}
	
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_PARAM_BOOL(p0[0], 1);
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_pool", "getconnection", 1, p0);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), copy TSRMLS_CC);
	}
	PHALCON_INIT_TRUE(t0);
	PHALCON_EQUAL_FUNCTION(r1, v0, t0);
	if (zend_is_true(r1)) {
		PHALCON_CALL_METHOD_NORETURN(v1, "begin", PHALCON_CALL_DEFAULT);
	}
	RETURN_NULL();
}

/**
 * Sets transaction manager related to the transaction
 *
 * @param Phalcon_Transaction_Manager $manager
 */
PHP_METHOD(Phalcon_Transaction, setTransactionManager){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_manager", strlen("_manager"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Starts the transaction
 */
PHP_METHOD(Phalcon_Transaction, begin){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t0, "begin", PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 1, 0);
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
	zval *p0[] = { NULL, NULL };

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!phalcon_compare_strict_string(t0, "")) {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *orig_ptr = a0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(a0);
				*a0 = *orig_ptr;
				zval_copy_ctor(a0);
				Z_SET_REFCOUNT_P(a0, 1);
				Z_UNSET_ISREF_P(a0);
			}
		}
		add_next_index_zval(a0, t1);
		add_next_index_string(a0, "notifyCommit", 1);
		Z_ADDREF_P(a0);
		p0[0] = a0;
		PHALCON_ALLOC_ZVAL(a1);
		array_init(a1);
		{
			zval *orig_ptr = a1;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(a1);
				*a1 = *orig_ptr;
				zval_copy_ctor(a1);
				Z_SET_REFCOUNT_P(a1, 1);
				Z_UNSET_ISREF_P(a1);
			}
		}
		add_next_index_zval(a1, this_ptr);
		Z_ADDREF_P(a1);
		p0[1] = a1;
		PHALCON_CALL_FUNC_PARAMS_NORETURN("call_user_func_array", strlen("call_user_func_array"), 2, p0);
	}
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t2, "commit", PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 1, 0);
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
	zval *p0[] = { NULL, NULL }, *p2[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	if (!v1) {
		PHALCON_INIT_NULL(v1);
	}
	
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!phalcon_compare_strict_string(t0, "")) {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *orig_ptr = a0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(a0);
				*a0 = *orig_ptr;
				zval_copy_ctor(a0);
				Z_SET_REFCOUNT_P(a0, 1);
				Z_UNSET_ISREF_P(a0);
			}
		}
		add_next_index_zval(a0, t1);
		add_next_index_string(a0, "notifyRollback", 1);
		Z_ADDREF_P(a0);
		p0[0] = a0;
		PHALCON_ALLOC_ZVAL(a1);
		array_init(a1);
		{
			zval *orig_ptr = a1;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(a1);
				*a1 = *orig_ptr;
				zval_copy_ctor(a1);
				Z_SET_REFCOUNT_P(a1, 1);
				Z_UNSET_ISREF_P(a1);
			}
		}
		add_next_index_zval(a1, this_ptr);
		Z_ADDREF_P(a1);
		p0[1] = a1;
		PHALCON_CALL_FUNC_PARAMS_NORETURN("call_user_func_array", strlen("call_user_func_array"), 2, p0);
	}
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t2, "rollback", PHALCON_CALL_DEFAULT);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r0);
	v2 = r0;
	PHALCON_INIT_TRUE(t3);
	PHALCON_EQUAL_FUNCTION(r1, v2, t3);
	if (zend_is_true(r1)) {
		if (phalcon_compare_strict_string(v0, "")) {
			PHALCON_ALLOC_ZVAL(v0);
			ZVAL_STRING(v0, "Transaction aborted", 0);
		}
		if (zend_is_true(v1)) {
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v1, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_rollbackRecord", strlen("_rollbackRecord"), copy TSRMLS_CC);
			}
		}
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_transaction_failed_class_entry);
		Z_ADDREF_P(v0);
		p2[0] = v0;
		PHALCON_ALLOC_ZVAL(t4);
		phalcon_read_property(t4, this_ptr, "_rollbackRecord", sizeof("_rollbackRecord")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t4);
		p2[1] = t4;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p2, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
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

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_rollbackOnAbort", sizeof("_rollbackOnAbort")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_CALL_FUNC(r0, "connection_aborted", strlen("connection_aborted"));
		if (zend_is_true(r0)) {
			PHALCON_ALLOC_ZVAL(p1[0]);
			ZVAL_STRING(p1[0], "The request was aborted", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "rollback", 1, p1, PHALCON_CALL_DEFAULT);
		}
	}
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t1) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

/**
 * Sets if is a reused transaction or new once
 *
 * @param boolean $isNew
 */
PHP_METHOD(Phalcon_Transaction, setIsNewTransaction){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_isNewTransaction", strlen("_isNewTransaction"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Sets flag to rollback on abort the HTTP connection
 *
 * @param boolean $rollbackOnAbort
 */
PHP_METHOD(Phalcon_Transaction, setRollbackOnAbort){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_rollbackOnAbort", strlen("_rollbackOnAbort"), copy TSRMLS_CC);
	}
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

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_NULL(t1);
	PHALCON_EQUAL_FUNCTION(r1, t0, t1);
	if (zend_is_true(r1)) {
		PHALCON_INIT_FALSE(t2);
		r0 = t2;
	} else {
		PHALCON_INIT_TRUE(t3);
		r0 = t3;
	}
	if (Z_TYPE_P(r0) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(r0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(r0);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

/**
 * Changes dependency internal pointer
 *
 * @param int $pointer
 */
PHP_METHOD(Phalcon_Transaction, setDependencyPointer){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), copy TSRMLS_CC);
	}
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

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_INIT_NULL(t0);
	PHALCON_EQUAL_FUNCTION(r0, v0, t0);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *orig_ptr = t1;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(t1);
				*t1 = *orig_ptr;
				zval_copy_ctor(t1);
				Z_SET_REFCOUNT_P(t1, 1);
				Z_UNSET_ISREF_P(t1);
			}
		}
		increment_function(t1);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), copy TSRMLS_CC);
		}
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(t1);
		v0 = t1;
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *orig_ptr = t2;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(t2);
				*t2 = *orig_ptr;
				zval_copy_ctor(t2);
				Z_SET_REFCOUNT_P(t2, 1);
				Z_UNSET_ISREF_P(t2);
			}
		}
		phalcon_array_update(t2, v0, v1 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_dependencies", strlen("_dependencies"), copy TSRMLS_CC);
		}
		if (Z_TYPE_P(v0) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v0);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v0);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(t3, v0);
		if (!eval_int) {
			PHALCON_ALLOC_ZVAL(t4);
			phalcon_read_property(t4, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			{
				zval *orig_ptr = t4;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(t4);
					*t4 = *orig_ptr;
					zval_copy_ctor(t4);
					Z_SET_REFCOUNT_P(t4, 1);
					Z_UNSET_ISREF_P(t4);
				}
			}
			phalcon_array_update(t4, v0, v1 TSRMLS_CC);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, t4, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_dependencies", strlen("_dependencies"), copy TSRMLS_CC);
			}
			if (Z_TYPE_P(v0) > IS_BOOL) {
				{
					zend_uchar is_ref = Z_ISREF_P(return_value);
					zend_uint refcount = Z_REFCOUNT_P(return_value);
					*(return_value) = *(v0);
					zval_copy_ctor(return_value);
					Z_SET_ISREF_TO_P(return_value, is_ref);
			 		Z_SET_REFCOUNT_P(return_value, refcount);
				}
			} else {
				{
					zend_uchar is_ref = Z_ISREF_P(return_value);
					zend_uint refcount = Z_REFCOUNT_P(return_value);
					*(return_value) = *(v0);
					Z_SET_ISREF_TO_P(return_value, is_ref);
			 		Z_SET_REFCOUNT_P(return_value, refcount);
				}
			}
			return;
		} else {
			PHALCON_ALLOC_ZVAL(t5);
			phalcon_read_property(t5, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			{
				zval *orig_ptr = t5;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(t5);
					*t5 = *orig_ptr;
					zval_copy_ctor(t5);
					Z_SET_REFCOUNT_P(t5, 1);
					Z_UNSET_ISREF_P(t5);
				}
			}
			increment_function(t5);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, t5, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), copy TSRMLS_CC);
			}
			if (v0) {
				if (!Z_REFCOUNT_P(v0)) {
					FREE_ZVAL(v0);
				}
			}
			Z_ADDREF_P(t5);
			v0 = t5;
			PHALCON_ALLOC_ZVAL(t6);
			phalcon_read_property(t6, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			{
				zval *orig_ptr = t6;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(t6);
					*t6 = *orig_ptr;
					zval_copy_ctor(t6);
					Z_SET_REFCOUNT_P(t6, 1);
					Z_UNSET_ISREF_P(t6);
				}
			}
			phalcon_array_update(t6, v0, v1 TSRMLS_CC);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, t6, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_dependencies", strlen("_dependencies"), copy TSRMLS_CC);
			}
			if (Z_TYPE_P(v0) > IS_BOOL) {
				{
					zend_uchar is_ref = Z_ISREF_P(return_value);
					zend_uint refcount = Z_REFCOUNT_P(return_value);
					*(return_value) = *(v0);
					zval_copy_ctor(return_value);
					Z_SET_ISREF_TO_P(return_value, is_ref);
			 		Z_SET_REFCOUNT_P(return_value, refcount);
				}
			} else {
				{
					zend_uchar is_ref = Z_ISREF_P(return_value);
					zend_uint refcount = Z_REFCOUNT_P(return_value);
					*(return_value) = *(v0);
					Z_SET_ISREF_TO_P(return_value, is_ref);
			 		Z_SET_REFCOUNT_P(return_value, refcount);
				}
			}
			return;
		}
	}
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
	zval *ac0 = NULL;
	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, a0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_messages", strlen("_messages"), copy TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	FOREACH_V(t0, ac0, fes56, fee56, ah0, hp0, v0)
		if (!r0) {
			PHALCON_ALLOC_ZVAL(r0);
		} else {
			if (Z_REFCOUNT_P(r0) > 1) {
				{
					zval *orig_ptr = r0;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r0);
						*r0 = *orig_ptr;
						zval_copy_ctor(r0);
						Z_SET_REFCOUNT_P(r0, 1);
						Z_UNSET_ISREF_P(r0);
					}
				}
			} else {
				FREE_ZVAL(r0);
				PHALCON_ALLOC_ZVAL(r0);
			}
		}
		PHALCON_CALL_METHOD(r0, v0, "save", PHALCON_CALL_DEFAULT);
		PHALCON_INIT_FALSE(t1);
		PHALCON_EQUAL_FUNCTION(r1, r0, t1);
		if (zend_is_true(r1)) {
			if (!r2) {
				PHALCON_ALLOC_ZVAL(r2);
			} else {
				if (Z_REFCOUNT_P(r2) > 1) {
					{
						zval *orig_ptr = r2;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r2);
							*r2 = *orig_ptr;
							zval_copy_ctor(r2);
							Z_SET_REFCOUNT_P(r2, 1);
							Z_UNSET_ISREF_P(r2);
						}
					}
				} else {
					FREE_ZVAL(r2);
					PHALCON_ALLOC_ZVAL(r2);
				}
			}
			PHALCON_CALL_METHOD(r2, v0, "getmessages", PHALCON_CALL_DEFAULT);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_messages", strlen("_messages"), copy TSRMLS_CC);
			}
			RETURN_FALSE;
		}
	END_FOREACH(ac0, fes56, fee56, ah0, hp0);
	RETURN_TRUE;
}

/**
 * Returns validations messages from last save try
 *
 * @return array
 */
PHP_METHOD(Phalcon_Transaction, getMessages){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_messages", sizeof("_messages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t0) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

/**
     * Checks whether internal connection is under an active transaction
     *
     * @return boolean
     */
PHP_METHOD(Phalcon_Transaction, isValid){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t0, "isundertransaction", PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 1, 0);
}

/**
 * Sets object which generates rollback action
 *
 * @param Phalcon_Model_Base $record
 */
PHP_METHOD(Phalcon_Transaction, setRollbackedRecord){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_rollbackRecord", strlen("_rollbackRecord"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

