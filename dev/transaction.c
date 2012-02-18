
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

PHP_METHOD(Phalcon_Transaction, __construct){

	zval *a0 = NULL, *a1 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_over("Phalcon_Transaction::__construct (ClassVariables) File=Library/Phalcon/Transaction.php Line=5");
	phalcon_step_over("Phalcon_Transaction::__construct (ClassVariables) File=Library/Phalcon/Transaction.php Line=7");
	phalcon_step_over("Phalcon_Transaction::__construct (ClassVariables) File=Library/Phalcon/Transaction.php Line=9");
	phalcon_step_over("Phalcon_Transaction::__construct (ClassVariables) File=Library/Phalcon/Transaction.php Line=11");
	phalcon_step_over("Phalcon_Transaction::__construct (ClassVariables) File=Library/Phalcon/Transaction.php Line=13");
	phalcon_step_over("Phalcon_Transaction::__construct (ClassVariables) File=Library/Phalcon/Transaction.php Line=15");
	phalcon_step_over("Phalcon_Transaction::__construct (ClassVariables) File=Library/Phalcon/Transaction.php Line=17");
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
		PHALCON_INIT_BOOL(v0, 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction", "__construct", 0);
	phalcon_step_over("Phalcon_Transaction::__construct (Assignment) File=Library/Phalcon/Transaction.php Line=24");
	//$connection
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_PARAM_BOOL(p0[0], 1);
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_pool", "getconnection", 1, p0);
	phalcon_debug_vdump("StaticReturn > ", r0 TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	phalcon_debug_assign("$connection", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Transaction::__construct (Assignment) File=Library/Phalcon/Transaction.php Line=25");
	//$connection
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Transaction::__construct (If) File=Library/Phalcon/Transaction.php Line=26");
	//$autoBegin
	PHALCON_INIT_TRUE(t0);
	PHALCON_EQUAL_FUNCTION(r1, v0, t0);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Transaction::__construct (Block) File=Library/Phalcon/Transaction.php Line=26");
		phalcon_step_over("Phalcon_Transaction::__construct (MethodCall) File=Library/Phalcon/Transaction.php Line=27");
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
		phalcon_debug_method_call(t1, "begin" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(t1, "begin", PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction::__construct (Method) File=Library/Phalcon/Transaction.php Line=31");
}

PHP_METHOD(Phalcon_Transaction, setTransactionManager){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction", "setTransactionManager", 0);
	phalcon_step_over("Phalcon_Transaction::setTransactionManager (Assignment) File=Library/Phalcon/Transaction.php Line=32");
	//$manager
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_manager", strlen("_manager"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction::setTransactionManager (Method) File=Library/Phalcon/Transaction.php Line=35");
}

PHP_METHOD(Phalcon_Transaction, begin){

	zval *r0 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Transaction", "begin", 0);
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
	phalcon_debug_method_call(t0, "begin" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t0, "begin", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction::begin (Method) File=Library/Phalcon/Transaction.php Line=39");
}

PHP_METHOD(Phalcon_Transaction, commit){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	phalcon_step_into_entry("Phalcon_Transaction", "commit", 0);
	phalcon_step_over("Phalcon_Transaction::commit (If) File=Library/Phalcon/Transaction.php Line=40");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!phalcon_compare_strict_string(t0, "")) {
		phalcon_step_over("Phalcon_Transaction::commit (Block) File=Library/Phalcon/Transaction.php Line=40");
		phalcon_step_over("Phalcon_Transaction::commit (FunctionCall) File=Library/Phalcon/Transaction.php Line=41");
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
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
		phalcon_debug_param(a0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(a1);
		array_init(a1);
		//$this
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
		phalcon_debug_param(a1 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_NORETURN("call_user_func_array", 2, p0);
	}
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t2);
	phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
	phalcon_debug_method_call(t2, "commit" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t2, "commit", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction::commit (Method) File=Library/Phalcon/Transaction.php Line=46");
}

PHP_METHOD(Phalcon_Transaction, rollback){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL }, *p3[] = { NULL, NULL };

	
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
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction", "rollback", 0);
	phalcon_step_over("Phalcon_Transaction::rollback (FunctionCall) File=Library/Phalcon/Transaction.php Line=47");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	Z_ADDREF_P(t0);
	p0[0] = t0;
	phalcon_debug_param(t0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("var_dump", 1, p0);
	phalcon_step_over("Phalcon_Transaction::rollback (If) File=Library/Phalcon/Transaction.php Line=48");
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	if (!phalcon_compare_strict_string(t1, "")) {
		phalcon_step_over("Phalcon_Transaction::rollback (Block) File=Library/Phalcon/Transaction.php Line=48");
		phalcon_step_over("Phalcon_Transaction::rollback (FunctionCall) File=Library/Phalcon/Transaction.php Line=49");
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		//$this
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
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
		add_next_index_zval(a0, t2);
		add_next_index_string(a0, "notifyRollback", 1);
		Z_ADDREF_P(a0);
		p1[0] = a0;
		phalcon_debug_param(a0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(a1);
		array_init(a1);
		//$this
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
		p1[1] = a1;
		phalcon_debug_param(a1 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_NORETURN("call_user_func_array", 2, p1);
	}
	phalcon_step_over("Phalcon_Transaction::rollback (Assignment) File=Library/Phalcon/Transaction.php Line=51");
	//$success
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_read_property(t3, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t3);
	phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
	phalcon_debug_method_call(t3, "rollback" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t3, "rollback", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r0);
	v2 = r0;
	phalcon_debug_assign("$success", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Transaction::rollback (If) File=Library/Phalcon/Transaction.php Line=52");
	//$success
	PHALCON_INIT_TRUE(t4);
	PHALCON_EQUAL_FUNCTION(r1, v2, t4);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Transaction::rollback (Block) File=Library/Phalcon/Transaction.php Line=52");
		phalcon_step_over("Phalcon_Transaction::rollback (If) File=Library/Phalcon/Transaction.php Line=53");
		//$rollbackMessage
		if (phalcon_compare_strict_string(v0, "")) {
			phalcon_step_over("Phalcon_Transaction::rollback (Block) File=Library/Phalcon/Transaction.php Line=53");
			phalcon_step_over("Phalcon_Transaction::rollback (Assignment) File=Library/Phalcon/Transaction.php Line=54");
			//$rollbackMessage
			PHALCON_ALLOC_ZVAL(v0);
			ZVAL_STRING(v0, "Transaction aborted", 0);
		}
		phalcon_step_over("Phalcon_Transaction::rollback (If) File=Library/Phalcon/Transaction.php Line=56");
		//$rollbackRecord
		if (Z_TYPE_P(v1) != IS_NULL) {
			phalcon_step_over("Phalcon_Transaction::rollback (Block) File=Library/Phalcon/Transaction.php Line=56");
			phalcon_step_over("Phalcon_Transaction::rollback (Assignment) File=Library/Phalcon/Transaction.php Line=57");
			//$rollbackRecord
			//$this
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v1, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_rollbackRecord", strlen("_rollbackRecord"), copy TSRMLS_CC);
			}
		}
		phalcon_step_over("Phalcon_Transaction::rollback (Throw) File=Library/Phalcon/Transaction.php Line=59");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_transaction_failed_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		//$rollbackMessage
		Z_ADDREF_P(v0);
		p3[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		//$this
		PHALCON_ALLOC_ZVAL(t5);
		phalcon_read_property(t5, this_ptr, "_rollbackRecord", sizeof("_rollbackRecord")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t5);
		Z_ADDREF_P(t5);
		p3[1] = t5;
		phalcon_debug_param(t5 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p3, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction::rollback (Method) File=Library/Phalcon/Transaction.php Line=63");
}

PHP_METHOD(Phalcon_Transaction, getConnection){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *p1[] = { NULL };

	phalcon_step_into_entry("Phalcon_Transaction", "getConnection", 0);
	phalcon_step_over("Phalcon_Transaction::getConnection (If) File=Library/Phalcon/Transaction.php Line=64");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_rollbackOnAbort", sizeof("_rollbackOnAbort")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Transaction::getConnection (Block) File=Library/Phalcon/Transaction.php Line=64");
		phalcon_step_over("Phalcon_Transaction::getConnection (If) File=Library/Phalcon/Transaction.php Line=65");
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_CALL_FUNC(r0, "connection_aborted");
		phalcon_debug_vdump("connection_aborted > ", r0 TSRMLS_CC);
		if (zend_is_true(r0)) {
			phalcon_step_over("Phalcon_Transaction::getConnection (Block) File=Library/Phalcon/Transaction.php Line=65");
			phalcon_step_over("Phalcon_Transaction::getConnection (MethodCall) File=Library/Phalcon/Transaction.php Line=66");
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "rollback" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p1[0]);
			ZVAL_STRING(p1[0], "The request was aborted", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "rollback", 1, p1, PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
		}
	}
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction::getConnection (Method) File=Library/Phalcon/Transaction.php Line=72");
}

PHP_METHOD(Phalcon_Transaction, setIsNewTransaction){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction", "setIsNewTransaction", 0);
	phalcon_step_over("Phalcon_Transaction::setIsNewTransaction (Assignment) File=Library/Phalcon/Transaction.php Line=73");
	//$isNew
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_isNewTransaction", strlen("_isNewTransaction"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction::setIsNewTransaction (Method) File=Library/Phalcon/Transaction.php Line=76");
}

PHP_METHOD(Phalcon_Transaction, setRollbackOnAbort){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction", "setRollbackOnAbort", 0);
	phalcon_step_over("Phalcon_Transaction::setRollbackOnAbort (Assignment) File=Library/Phalcon/Transaction.php Line=77");
	//$rollbackOnAbort
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_rollbackOnAbort", strlen("_rollbackOnAbort"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction::setRollbackOnAbort (Method) File=Library/Phalcon/Transaction.php Line=80");
}

PHP_METHOD(Phalcon_Transaction, isManaged){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;

	phalcon_step_into_entry("Phalcon_Transaction", "isManaged", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	PHALCON_INIT_NULL(t1);
	PHALCON_EQUAL_FUNCTION(r1, t0, t1);
	if (zend_is_true(r1)) {
		PHALCON_INIT_FALSE(t2);
		r0 = t2;
	} else {
		PHALCON_INIT_TRUE(t3);
		r0 = t3;
	}
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction::isManaged (Method) File=Library/Phalcon/Transaction.php Line=84");
}

PHP_METHOD(Phalcon_Transaction, setDependencyPointer){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction", "setDependencyPointer", 0);
	phalcon_step_over("Phalcon_Transaction::setDependencyPointer (Assignment) File=Library/Phalcon/Transaction.php Line=85");
	//$pointer
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction::setDependencyPointer (Method) File=Library/Phalcon/Transaction.php Line=88");
}

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
	phalcon_step_over("Phalcon_Transaction::attachDependency (If) File=Library/Phalcon/Transaction.php Line=89");
	//$pointer
	PHALCON_INIT_NULL(t0);
	PHALCON_EQUAL_FUNCTION(r0, v0, t0);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Transaction::attachDependency (Block) File=Library/Phalcon/Transaction.php Line=89");
		phalcon_step_over("Phalcon_Transaction::attachDependency (Assignment) File=Library/Phalcon/Transaction.php Line=90");
		//$pointer
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
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
		//$this
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
		phalcon_debug_assign("$pointer", t1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Transaction::attachDependency (Assignment) File=Library/Phalcon/Transaction.php Line=91");
		//$object
		//$this
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
		//$pointer
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
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_dependencies", strlen("_dependencies"), copy TSRMLS_CC);
		}
		//$pointer
		phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
		phalcon_step_out_entry();
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
		phalcon_step_over("Phalcon_Transaction::attachDependency (Block) File=Library/Phalcon/Transaction.php Line=93");
		phalcon_step_over("Phalcon_Transaction::attachDependency (If) File=Library/Phalcon/Transaction.php Line=94");
		//$pointer
		//$this
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t3);
		eval_int = phalcon_array_isset(t3, v0);
		if (!eval_int) {
			phalcon_step_over("Phalcon_Transaction::attachDependency (Block) File=Library/Phalcon/Transaction.php Line=94");
			phalcon_step_over("Phalcon_Transaction::attachDependency (Assignment) File=Library/Phalcon/Transaction.php Line=95");
			//$object
			//$this
			PHALCON_ALLOC_ZVAL(t4);
			phalcon_read_property(t4, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t4);
			//$pointer
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
			//$this
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, t4, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_dependencies", strlen("_dependencies"), copy TSRMLS_CC);
			}
			//$pointer
			phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
			phalcon_step_out_entry();
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
			phalcon_step_over("Phalcon_Transaction::attachDependency (Block) File=Library/Phalcon/Transaction.php Line=97");
			phalcon_step_over("Phalcon_Transaction::attachDependency (Assignment) File=Library/Phalcon/Transaction.php Line=98");
			//$pointer
			//$this
			PHALCON_ALLOC_ZVAL(t5);
			phalcon_read_property(t5, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t5);
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
			//$this
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
			phalcon_debug_assign("$pointer", t5 TSRMLS_CC);
			phalcon_step_over("Phalcon_Transaction::attachDependency (Assignment) File=Library/Phalcon/Transaction.php Line=99");
			//$object
			//$this
			PHALCON_ALLOC_ZVAL(t6);
			phalcon_read_property(t6, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t6);
			//$pointer
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
			//$this
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, t6, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_dependencies", strlen("_dependencies"), copy TSRMLS_CC);
			}
			//$pointer
			phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
			phalcon_step_out_entry();
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
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction::attachDependency (Method) File=Library/Phalcon/Transaction.php Line=105");
}

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
	phalcon_step_over("Phalcon_Transaction::save (Assignment) File=Library/Phalcon/Transaction.php Line=106");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, a0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_messages", strlen("_messages"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Transaction::save (Foreach) File=Library/Phalcon/Transaction.php Line=107");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_dependencies", sizeof("_dependencies")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	//$dependency
	FOREACH_V(t0, ac0, fes54, fee54, ah0, hp0, v0)
		phalcon_step_over("Phalcon_Transaction::save (Block) File=Library/Phalcon/Transaction.php Line=107");
		phalcon_step_over("Phalcon_Transaction::save (If) File=Library/Phalcon/Transaction.php Line=108");
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
		//$dependency
		phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
		phalcon_debug_method_call(v0, "save" TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, v0, "save", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
		PHALCON_INIT_FALSE(t1);
		PHALCON_EQUAL_FUNCTION(r1, r0, t1);
		if (zend_is_true(r1)) {
			phalcon_step_over("Phalcon_Transaction::save (Block) File=Library/Phalcon/Transaction.php Line=108");
			phalcon_step_over("Phalcon_Transaction::save (Assignment) File=Library/Phalcon/Transaction.php Line=109");
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
			//$dependency
			phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
			phalcon_debug_method_call(v0, "getmessages" TSRMLS_CC);
			PHALCON_CALL_METHOD(r2, v0, "getmessages", PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
			//$this
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
	END_FOREACH(ac0, fes54, fee54, ah0, hp0);
	phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_TRUE;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction::save (Method) File=Library/Phalcon/Transaction.php Line=116");
}

PHP_METHOD(Phalcon_Transaction, getMessages){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Transaction", "getMessages", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_messages", sizeof("_messages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction::getMessages (Method) File=Library/Phalcon/Transaction.php Line=120");
}

PHP_METHOD(Phalcon_Transaction, isValid){

	zval *r0 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Transaction", "isValid", 0);
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
	phalcon_debug_method_call(t0, "isundertransaction" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t0, "isundertransaction", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Transaction" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction::isValid (Method) File=Library/Phalcon/Transaction.php Line=124");
}

PHP_METHOD(Phalcon_Transaction, setRollbackedRecord){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction", "setRollbackedRecord", 0);
	phalcon_step_over("Phalcon_Transaction::setRollbackedRecord (Assignment) File=Library/Phalcon/Transaction.php Line=125");
	//$record
	//$this
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

