
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

	phalcon_step_over("Phalcon_Transaction::__construct (ClassVariables) File=/Transaction Line=41");
	phalcon_step_over("Phalcon_Transaction::__construct (ClassVariables) File=/Transaction Line=43");
	phalcon_step_over("Phalcon_Transaction::__construct (ClassVariables) File=/Transaction Line=45");
	phalcon_step_over("Phalcon_Transaction::__construct (ClassVariables) File=/Transaction Line=47");
	phalcon_step_over("Phalcon_Transaction::__construct (ClassVariables) File=/Transaction Line=49");
	phalcon_step_over("Phalcon_Transaction::__construct (ClassVariables) File=/Transaction Line=51");
	phalcon_step_over("Phalcon_Transaction::__construct (ClassVariables) File=/Transaction Line=53");
	phalcon_step_into_entry("Phalcon_Transaction", "::__construct", 0);
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
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_BOOL(v0, 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction", "__construct", 0);
	phalcon_step_over("Phalcon_Transaction::__construct (Assignment) File=/Transaction Line=65");
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_PARAM_BOOL(p0[0], 1);
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_pool", "getconnection", 1, p0);
	phalcon_debug_vdump("StaticReturn > ", r0 TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r0);
	phalcon_debug_assign("$connection", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Transaction::__construct (Assignment) File=/Transaction Line=66");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Transaction::__construct (If) File=/Transaction Line=67");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_BOOL(t0, 1);
	PHALCON_ALLOC_ZVAL(r1);
	is_equal_function(r1, v0, t0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Transaction::__construct (Block) File=/Transaction Line=67");
		phalcon_step_over("Phalcon_Transaction::__construct (MethodCall) File=/Transaction Line=68");
		phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
		phalcon_debug_method_call(v1, "begin" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(v1, "begin", PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction::__construct (Method) File=/Transaction Line=77");
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

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction", "setTransactionManager", 0);
	phalcon_step_over("Phalcon_Transaction::setTransactionManager (Assignment) File=/Transaction Line=78");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_manager", strlen("_manager"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction::setTransactionManager (Method) File=/Transaction Line=84");
}

/**
 * Starts the transaction
 */
PHP_METHOD(Phalcon_Transaction, begin){

	zval *r0 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Transaction", "begin", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
	phalcon_debug_method_call(t0, "begin" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t0, "begin", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction::begin (Method) File=/Transaction Line=93");
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

	phalcon_step_into_entry("Phalcon_Transaction", "commit", 0);
	phalcon_step_over("Phalcon_Transaction::commit (If) File=/Transaction Line=94");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!PHALCON_COMPARE_STRING(t0, "")) {
		phalcon_step_over("Phalcon_Transaction::commit (Block) File=/Transaction Line=94");
		phalcon_step_over("Phalcon_Transaction::commit (FunctionCall) File=/Transaction Line=95");
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_SEPARATE(a0);
		add_next_index_zval(a0, t1);
		add_next_index_string(a0, "notifyCommit", 1);
		Z_ADDREF_P(a0);
		p0[0] = a0;
		phalcon_debug_param(a0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(a1);
		array_init(a1);
		PHALCON_SEPARATE(a1);
		add_next_index_zval(a1, this_ptr);
		Z_ADDREF_P(a1);
		p0[1] = a1;
		phalcon_debug_param(a1 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_NORETURN("call_user_func_array", 2, p0);
	}
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
	phalcon_debug_method_call(t2, "commit" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t2, "commit", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction::commit (Method) File=/Transaction Line=107");
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
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_NULL(v1);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction", "rollback", 0);
	phalcon_step_over("Phalcon_Transaction::rollback (If) File=/Transaction Line=108");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!PHALCON_COMPARE_STRING(t0, "")) {
		phalcon_step_over("Phalcon_Transaction::rollback (Block) File=/Transaction Line=108");
		phalcon_step_over("Phalcon_Transaction::rollback (FunctionCall) File=/Transaction Line=109");
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_SEPARATE(a0);
		add_next_index_zval(a0, t1);
		add_next_index_string(a0, "notifyRollback", 1);
		Z_ADDREF_P(a0);
		p0[0] = a0;
		phalcon_debug_param(a0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(a1);
		array_init(a1);
		PHALCON_SEPARATE(a1);
		add_next_index_zval(a1, this_ptr);
		Z_ADDREF_P(a1);
		p0[1] = a1;
		phalcon_debug_param(a1 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_NORETURN("call_user_func_array", 2, p0);
	}
	phalcon_step_over("Phalcon_Transaction::rollback (Assignment) File=/Transaction Line=111");
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
	phalcon_debug_method_call(t2, "rollback" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t2, "rollback", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r0);
	phalcon_debug_assign("$success", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Transaction::rollback (If) File=/Transaction Line=112");
	PHALCON_ALLOC_ZVAL(t3);
	ZVAL_BOOL(t3, 1);
	PHALCON_ALLOC_ZVAL(r1);
	is_equal_function(r1, v2, t3 TSRMLS_CC);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Transaction::rollback (Block) File=/Transaction Line=112");
		phalcon_step_over("Phalcon_Transaction::rollback (If) File=/Transaction Line=113");
		if (PHALCON_COMPARE_STRING(v0, "")) {
			phalcon_step_over("Phalcon_Transaction::rollback (Block) File=/Transaction Line=113");
			phalcon_step_over("Phalcon_Transaction::rollback (Assignment) File=/Transaction Line=114");
			PHALCON_ALLOC_ZVAL(v0);
			ZVAL_STRING(v0, "Transaction aborted", 0);
		}
		phalcon_step_over("Phalcon_Transaction::rollback (If) File=/Transaction Line=116");
		if (zend_is_true(v1)) {
			phalcon_step_over("Phalcon_Transaction::rollback (Block) File=/Transaction Line=116");
			phalcon_step_over("Phalcon_Transaction::rollback (Assignment) File=/Transaction Line=117");
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v1, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_rollbackRecord", strlen("_rollbackRecord"), copy TSRMLS_CC);
			}
		}
		phalcon_step_over("Phalcon_Transaction::rollback (Throw) File=/Transaction Line=119");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_transaction_failed_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		Z_ADDREF_P(v0);
		p2[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t4);
		phalcon_read_property(t4, this_ptr, "_rollbackRecord", sizeof("_rollbackRecord")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t4);
		p2[1] = t4;
		phalcon_debug_param(t4 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p2, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction::rollback (Method) File=/Transaction Line=128");
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

	phalcon_step_into_entry("Phalcon_Transaction", "getConnection", 0);
	phalcon_step_over("Phalcon_Transaction::getConnection (If) File=/Transaction Line=129");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_rollbackOnAbort", sizeof("_rollbackOnAbort")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Transaction::getConnection (Block) File=/Transaction Line=129");
		phalcon_step_over("Phalcon_Transaction::getConnection (If) File=/Transaction Line=130");
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_CALL_FUNC(r0, "connection_aborted");
		phalcon_debug_vdump("connection_aborted > ", r0 TSRMLS_CC);
		if (zend_is_true(r0)) {
			phalcon_step_over("Phalcon_Transaction::getConnection (Block) File=/Transaction Line=130");
			phalcon_step_over("Phalcon_Transaction::getConnection (MethodCall) File=/Transaction Line=131");
			phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "rollback" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p1[0]);
			ZVAL_STRING(p1[0], "The request was aborted", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "rollback", 1, p1, PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction::getConnection (Method) File=/Transaction Line=142");
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

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction", "setIsNewTransaction", 0);
	phalcon_step_over("Phalcon_Transaction::setIsNewTransaction (Assignment) File=/Transaction Line=143");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_isNewTransaction", strlen("_isNewTransaction"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction::setIsNewTransaction (Method) File=/Transaction Line=151");
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

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction", "setRollbackOnAbort", 0);
	phalcon_step_over("Phalcon_Transaction::setRollbackOnAbort (Assignment) File=/Transaction Line=152");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_rollbackOnAbort", strlen("_rollbackOnAbort"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction::setRollbackOnAbort (Method) File=/Transaction Line=160");
}

/**
 * Checks whether transaction is managed by a transaction manager
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Transaction, isManaged){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;

	phalcon_step_into_entry("Phalcon_Transaction", "isManaged", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_NULL(t1);
	PHALCON_ALLOC_ZVAL(r1);
	is_equal_function(r1, t0, t1 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL(t2);
		ZVAL_BOOL(t2, 0);
		r0 = t2;
	} else {
		PHALCON_ALLOC_ZVAL(t3);
		ZVAL_BOOL(t3, 1);
		r0 = t3;
	}
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(r0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction::isManaged (Method) File=/Transaction Line=169");
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

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction", "setDependencyPointer", 0);
	phalcon_step_over("Phalcon_Transaction::setDependencyPointer (Assignment) File=/Transaction Line=170");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction::setDependencyPointer (Method) File=/Transaction Line=179");
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

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction", "attachDependency", 0);
	phalcon_step_over("Phalcon_Transaction::attachDependency (If) File=/Transaction Line=180");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_NULL(t0);
	PHALCON_ALLOC_ZVAL(r0);
	is_equal_function(r0, v0, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Transaction::attachDependency (Block) File=/Transaction Line=180");
		phalcon_step_over("Phalcon_Transaction::attachDependency (Assignment) File=/Transaction Line=181");
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_SEPARATE(t1);
		increment_function(t1);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), copy TSRMLS_CC);
		}
		PHALCON_CPY_WRT_PARAM(v0, t1);
		phalcon_debug_assign("$pointer", t1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Transaction::attachDependency (Assignment) File=/Transaction Line=182");
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_SEPARATE(t2);
		phalcon_array_update(t2, v0, v1 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_dependencies", strlen("_dependencies"), copy TSRMLS_CC);
		}
		phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(v0);
	} else {
		phalcon_step_over("Phalcon_Transaction::attachDependency (Block) File=/Transaction Line=184");
		phalcon_step_over("Phalcon_Transaction::attachDependency (If) File=/Transaction Line=185");
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_array_isset(t3, v0);
		if (!eval_int) {
			phalcon_step_over("Phalcon_Transaction::attachDependency (Block) File=/Transaction Line=185");
			phalcon_step_over("Phalcon_Transaction::attachDependency (Assignment) File=/Transaction Line=186");
			PHALCON_ALLOC_ZVAL(t4);
			phalcon_read_property(t4, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE(t4);
			phalcon_array_update(t4, v0, v1 TSRMLS_CC);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, t4, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_dependencies", strlen("_dependencies"), copy TSRMLS_CC);
			}
			phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
			phalcon_step_out_entry();
			PHALCON_RETURN_CTOR(v0);
		} else {
			phalcon_step_over("Phalcon_Transaction::attachDependency (Block) File=/Transaction Line=188");
			phalcon_step_over("Phalcon_Transaction::attachDependency (Assignment) File=/Transaction Line=189");
			PHALCON_ALLOC_ZVAL(t5);
			phalcon_read_property(t5, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE(t5);
			increment_function(t5);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, t5, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), copy TSRMLS_CC);
			}
			PHALCON_CPY_WRT_PARAM(v0, t5);
			phalcon_debug_assign("$pointer", t5 TSRMLS_CC);
			phalcon_step_over("Phalcon_Transaction::attachDependency (Assignment) File=/Transaction Line=190");
			PHALCON_ALLOC_ZVAL(t6);
			phalcon_read_property(t6, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE(t6);
			phalcon_array_update(t6, v0, v1 TSRMLS_CC);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, t6, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_dependencies", strlen("_dependencies"), copy TSRMLS_CC);
			}
			phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
			phalcon_step_out_entry();
			PHALCON_RETURN_CTOR(v0);
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction::attachDependency (Method) File=/Transaction Line=201");
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

	phalcon_step_into_entry("Phalcon_Transaction", "save", 0);
	phalcon_step_over("Phalcon_Transaction::save (Assignment) File=/Transaction Line=202");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, a0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_messages", strlen("_messages"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Transaction::save (Foreach) File=/Transaction Line=203");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	FOREACH_V(t0, ac0, fes56, fee56, ah0, hp0, v0)
		phalcon_step_over("Phalcon_Transaction::save (Block) File=/Transaction Line=203");
		phalcon_step_over("Phalcon_Transaction::save (If) File=/Transaction Line=204");
		if (!r0) {
			PHALCON_ALLOC_ZVAL(r0);
		} else {
			if (Z_REFCOUNT_P(r0) > 1) {
				PHALCON_SEPARATE(r0);
			} else {
				FREE_ZVAL(r0);
				PHALCON_ALLOC_ZVAL(r0);
			}
		}
		phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
		phalcon_debug_method_call(v0, "save" TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, v0, "save", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
		if (!t1) {
			PHALCON_ALLOC_ZVAL(t1);
		} else {
			if (Z_REFCOUNT_P(t1) > 1) {
				SEPARATE_ZVAL(&t1);
			} else {
				if (Z_TYPE_P(t1) != IS_BOOL) {
					FREE_ZVAL(t1);
					PHALCON_ALLOC_ZVAL(t1);
				}
			}
		}
		ZVAL_BOOL(t1, 0);
		if (!r1) {
			PHALCON_ALLOC_ZVAL(r1);
		} else {
			if (Z_REFCOUNT_P(r1) > 1){ 
				PHALCON_SEPARATE(r1);
			}
		}
		is_equal_function(r1, r0, t1 TSRMLS_CC);
		if (zend_is_true(r1)) {
			phalcon_step_over("Phalcon_Transaction::save (Block) File=/Transaction Line=204");
			phalcon_step_over("Phalcon_Transaction::save (Assignment) File=/Transaction Line=205");
			if (!r2) {
				PHALCON_ALLOC_ZVAL(r2);
			} else {
				if (Z_REFCOUNT_P(r2) > 1) {
					PHALCON_SEPARATE(r2);
				} else {
					FREE_ZVAL(r2);
					PHALCON_ALLOC_ZVAL(r2);
				}
			}
			phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
			phalcon_debug_method_call(v0, "getmessages" TSRMLS_CC);
			PHALCON_CALL_METHOD(r2, v0, "getmessages", PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_messages", strlen("_messages"), copy TSRMLS_CC);
			}
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	END_FOREACH(ac0, fes56, fee56, ah0, hp0);
	phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_TRUE;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction::save (Method) File=/Transaction Line=217");
}

/**
 * Returns validations messages from last save try
 *
 * @return array
 */
PHP_METHOD(Phalcon_Transaction, getMessages){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Transaction", "getMessages", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_messages", sizeof("_messages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction::getMessages (Method) File=/Transaction Line=226");
}

/**
     * Checks whether internal connection is under an active transaction
     *
     * @return boolean
     */
PHP_METHOD(Phalcon_Transaction, isValid){

	zval *r0 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Transaction", "isValid", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
	phalcon_debug_method_call(t0, "isundertransaction" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t0, "isundertransaction", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction::isValid (Method) File=/Transaction Line=235");
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

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction", "setRollbackedRecord", 0);
	phalcon_step_over("Phalcon_Transaction::setRollbackedRecord (Assignment) File=/Transaction Line=236");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_rollbackRecord", strlen("_rollbackRecord"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
}

