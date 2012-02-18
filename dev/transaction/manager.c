
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

PHP_METHOD(Phalcon_Transaction_Manager, has){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Transaction_Manager", "has", 0);
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_SMALLER_FUNCTION(r0, t1, t0);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r0);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction_Manager::has (Method) File=Library/Phalcon/Transaction/Manager.php Line=19");
}

PHP_METHOD(Phalcon_Transaction_Manager, get){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_BOOL(v0, 1);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction_Manager", "get", 0);
	phalcon_step_over("Phalcon_Transaction_Manager::get (If) File=Library/Phalcon/Transaction/Manager.php Line=20");
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_initialized", sizeof("_initialized")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Transaction_Manager::get (Block) File=Library/Phalcon/Transaction/Manager.php Line=20");
		phalcon_step_over("Phalcon_Transaction_Manager::get (FunctionCall) File=Library/Phalcon/Transaction/Manager.php Line=21");
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		add_next_index_string(a0, "Phalcon_Transaction_Manager", 1);
		add_next_index_string(a0, "rollbackPendent", 1);
		p0[0] = a0;
		phalcon_debug_param(a0 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_NORETURN("register_shutdown_function", 1, p0);
		phalcon_step_over("Phalcon_Transaction_Manager::get (Assignment) File=Library/Phalcon/Transaction/Manager.php Line=22");
		PHALCON_INIT_TRUE(t1);
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_initialized", sizeof("_initialized")-1, t1 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Transaction_Manager::get (Assignment) File=Library/Phalcon/Transaction/Manager.php Line=24");
	//$number
	t2 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(t2);
	v1 = t2;
	phalcon_debug_assign("$number", t2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Transaction_Manager::get (If) File=Library/Phalcon/Transaction/Manager.php Line=25");
	//$number
	if (!zend_is_true(v1)) {
		phalcon_step_over("Phalcon_Transaction_Manager::get (Block) File=Library/Phalcon/Transaction/Manager.php Line=25");
		phalcon_step_over("Phalcon_Transaction_Manager::get (Assignment) File=Library/Phalcon/Transaction/Manager.php Line=26");
		//$transaction
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_transaction_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		//$autoBegin
		Z_ADDREF_P(v0);
		p1[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(i0);
		v2 = i0;
		phalcon_debug_assign("$transaction", i0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Transaction_Manager::get (MethodCall) File=Library/Phalcon/Transaction/Manager.php Line=27");
		//$transaction
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_debug_method_call(v2, "settransactionmanager" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p2[0]);
		ZVAL_STRING(p2[0], "Phalcon_Transaction_Manager", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "settransactionmanager", 1, p2, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_step_over("Phalcon_Transaction_Manager::get (MethodCall) File=Library/Phalcon/Transaction/Manager.php Line=28");
		//$transaction
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_debug_method_call(v2, "setdependencypointer" TSRMLS_CC);
		t3 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_dependencyPointer", sizeof("_dependencyPointer")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(t3);
		p3[0] = t3;
		phalcon_debug_param(t3 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setdependencypointer", 1, p3, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_step_over("Phalcon_Transaction_Manager::get (AssignOp) File=Library/Phalcon/Transaction/Manager.php Line=29");
		t4 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_dependencyPointer", sizeof("_dependencyPointer")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t5);
		ZVAL_LONG(t5, 2048);
		PHALCON_ADD_FUNCTION(r0, t4, t5);
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_dependencyPointer", sizeof("_dependencyPointer")-1, r0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Transaction_Manager::get (Assignment) File=Library/Phalcon/Transaction/Manager.php Line=30");
		//$transaction
		t6 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (Z_TYPE_P(t6) != IS_ARRAY) {
			convert_to_array(t6);
		}
		phalcon_array_append(t6, v2 TSRMLS_CC);
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, t6 TSRMLS_CC);
		
		phalcon_step_over("Phalcon_Transaction_Manager::get (PostIncDecOp) File=Library/Phalcon/Transaction/Manager.php Line=31");
		t7 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		{
			zval *orig_ptr = t7;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(t7);
				*t7 = *orig_ptr;
				zval_copy_ctor(t7);
				Z_SET_REFCOUNT_P(t7, 1);
				Z_UNSET_ISREF_P(t7);
			}
		}
		increment_function(t7);
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, t7 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Transaction_Manager::get (Block) File=Library/Phalcon/Transaction/Manager.php Line=32");
		phalcon_step_over("Phalcon_Transaction_Manager::get (Assignment) File=Library/Phalcon/Transaction/Manager.php Line=33");
		//$transaction
		t8 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		//$number
		PHALCON_ALLOC_ZVAL(t10);
		ZVAL_LONG(t10, 1);
		PHALCON_ALLOC_ZVAL(r1);
		sub_function(r1, v1, t10 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t9);
		phalcon_array_fetch(t9, t8, r1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(t9);
		v2 = t9;
		phalcon_debug_assign("$transaction", t9 TSRMLS_CC);
		phalcon_step_over("Phalcon_Transaction_Manager::get (MethodCall) File=Library/Phalcon/Transaction/Manager.php Line=34");
		//$transaction
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_debug_method_call(v2, "setisnewtransaction" TSRMLS_CC);
		PHALCON_PARAM_BOOL(p4[0], 0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setisnewtransaction", 1, p4, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
	}
	//$transaction
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(v2) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v2);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v2);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction_Manager::get (Method) File=Library/Phalcon/Transaction/Manager.php Line=39");
}

PHP_METHOD(Phalcon_Transaction_Manager, rollbackPendent){


	phalcon_step_into_entry("Phalcon_Transaction_Manager", "rollbackPendent", 0);
	phalcon_step_over("Phalcon_Transaction_Manager::rollbackPendent (StaticMethodCall) File=Library/Phalcon/Transaction/Manager.php Line=40");
	PHALCON_CALL_SELF_NORETURN(this_ptr, "rollback");
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction_Manager::rollbackPendent (Method) File=Library/Phalcon/Transaction/Manager.php Line=43");
}

PHP_METHOD(Phalcon_Transaction_Manager, commit){

	zval *t0 = NULL;
	zval *ac0 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	phalcon_step_into_entry("Phalcon_Transaction_Manager", "commit", 0);
	phalcon_step_over("Phalcon_Transaction_Manager::commit (Foreach) File=Library/Phalcon/Transaction/Manager.php Line=44");
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	//$transaction
	FOREACH_V(t0, ac0, fes55, fee55, ah0, hp0, v0)
		phalcon_step_over("Phalcon_Transaction_Manager::commit (Block) File=Library/Phalcon/Transaction/Manager.php Line=44");
		phalcon_step_over("Phalcon_Transaction_Manager::commit (Assignment) File=Library/Phalcon/Transaction/Manager.php Line=45");
		//$connection
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
		//$transaction
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_debug_method_call(v0, "getconnection" TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, v0, "getconnection", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r0);
		v1 = r0;
		phalcon_debug_assign("$connection", r0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Transaction_Manager::commit (If) File=Library/Phalcon/Transaction/Manager.php Line=46");
		if (!r1) {
			PHALCON_ALLOC_ZVAL(r1);
		} else {
			if (Z_REFCOUNT_P(r1) > 1) {
				{
					zval *orig_ptr = r1;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r1);
						*r1 = *orig_ptr;
						zval_copy_ctor(r1);
						Z_SET_REFCOUNT_P(r1, 1);
						Z_UNSET_ISREF_P(r1);
					}
				}
			} else {
				FREE_ZVAL(r1);
				PHALCON_ALLOC_ZVAL(r1);
			}
		}
		//$connection
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_debug_method_call(v1, "isundertransaction" TSRMLS_CC);
		PHALCON_CALL_METHOD(r1, v1, "isundertransaction", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		if (zend_is_true(r1)) {
			phalcon_step_over("Phalcon_Transaction_Manager::commit (Block) File=Library/Phalcon/Transaction/Manager.php Line=46");
			phalcon_step_over("Phalcon_Transaction_Manager::commit (MethodCall) File=Library/Phalcon/Transaction/Manager.php Line=47");
			//$connection
			phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
			phalcon_debug_method_call(v1, "commit" TSRMLS_CC);
			PHALCON_CALL_METHOD_NORETURN(v1, "commit", PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		}
	END_FOREACH(ac0, fes55, fee55, ah0, hp0);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction_Manager::commit (Method) File=Library/Phalcon/Transaction/Manager.php Line=52");
}

PHP_METHOD(Phalcon_Transaction_Manager, rollback){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p4[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_BOOL(v0, 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction_Manager", "rollback", 0);
	phalcon_step_over("Phalcon_Transaction_Manager::rollback (Foreach) File=Library/Phalcon/Transaction/Manager.php Line=53");
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	//$transaction
	FOREACH_V(t0, ac0, fes56, fee56, ah0, hp0, v1)
		phalcon_step_over("Phalcon_Transaction_Manager::rollback (Block) File=Library/Phalcon/Transaction/Manager.php Line=53");
		phalcon_step_over("Phalcon_Transaction_Manager::rollback (Assignment) File=Library/Phalcon/Transaction/Manager.php Line=54");
		//$connection
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
		//$transaction
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_debug_method_call(v1, "getconnection" TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, v1, "getconnection", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(r0);
		v2 = r0;
		phalcon_debug_assign("$connection", r0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Transaction_Manager::rollback (If) File=Library/Phalcon/Transaction/Manager.php Line=55");
		if (!r1) {
			PHALCON_ALLOC_ZVAL(r1);
		} else {
			if (Z_REFCOUNT_P(r1) > 1) {
				{
					zval *orig_ptr = r1;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r1);
						*r1 = *orig_ptr;
						zval_copy_ctor(r1);
						Z_SET_REFCOUNT_P(r1, 1);
						Z_UNSET_ISREF_P(r1);
					}
				}
			} else {
				FREE_ZVAL(r1);
				PHALCON_ALLOC_ZVAL(r1);
			}
		}
		//$connection
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_debug_method_call(v2, "isundertransaction" TSRMLS_CC);
		PHALCON_CALL_METHOD(r1, v2, "isundertransaction", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		if (zend_is_true(r1)) {
			phalcon_step_over("Phalcon_Transaction_Manager::rollback (Block) File=Library/Phalcon/Transaction/Manager.php Line=55");
			phalcon_step_over("Phalcon_Transaction_Manager::rollback (MethodCall) File=Library/Phalcon/Transaction/Manager.php Line=56");
			//$connection
			phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
			phalcon_debug_method_call(v2, "rollback" TSRMLS_CC);
			PHALCON_CALL_METHOD_NORETURN(v2, "rollback", PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
			phalcon_step_over("Phalcon_Transaction_Manager::rollback (MethodCall) File=Library/Phalcon/Transaction/Manager.php Line=57");
			//$connection
			phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
			phalcon_debug_method_call(v2, "close" TSRMLS_CC);
			PHALCON_CALL_METHOD_NORETURN(v2, "close", PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Transaction_Manager::rollback (If) File=Library/Phalcon/Transaction/Manager.php Line=59");
		//$collect
		if (zend_is_true(v0)) {
			phalcon_step_over("Phalcon_Transaction_Manager::rollback (Block) File=Library/Phalcon/Transaction/Manager.php Line=59");
			phalcon_step_over("Phalcon_Transaction_Manager::rollback (StaticMethodCall) File=Library/Phalcon/Transaction/Manager.php Line=60");
			//$transaction
			Z_ADDREF_P(v1);
			p4[0] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			PHALCON_CALL_SELF_PARAMS_NORETURN(this_ptr, "_collecttransaction", 1, p4);
		}
	END_FOREACH(ac0, fes56, fee56, ah0, hp0);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction_Manager::rollback (Method) File=Library/Phalcon/Transaction/Manager.php Line=65");
}

PHP_METHOD(Phalcon_Transaction_Manager, notifyRollback){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction_Manager", "notifyRollback", 0);
	phalcon_step_over("Phalcon_Transaction_Manager::notifyRollback (StaticMethodCall) File=Library/Phalcon/Transaction/Manager.php Line=69");
	//$transaction
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_SELF_PARAMS_NORETURN(this_ptr, "_collecttransaction", 1, p0);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction_Manager::notifyRollback (Method) File=Library/Phalcon/Transaction/Manager.php Line=72");
}

PHP_METHOD(Phalcon_Transaction_Manager, notifyCommit){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction_Manager", "notifyCommit", 0);
	phalcon_step_over("Phalcon_Transaction_Manager::notifyCommit (StaticMethodCall) File=Library/Phalcon/Transaction/Manager.php Line=76");
	//$transaction
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_SELF_PARAMS_NORETURN(this_ptr, "_collecttransaction", 1, p0);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction_Manager::notifyCommit (Method) File=Library/Phalcon/Transaction/Manager.php Line=79");
}

PHP_METHOD(Phalcon_Transaction_Manager, _collectTransaction){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction_Manager", "_collectTransaction", 0);
	phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (If) File=Library/Phalcon/Transaction/Manager.php Line=80");
	PHALCON_ALLOC_ZVAL(r0);
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	p0[0] = t0;
	phalcon_debug_param(t0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "count", 1, p0);
	phalcon_debug_vdump("count > ", r0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_SMALLER_FUNCTION(r1, t1, r0);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Block) File=Library/Phalcon/Transaction/Manager.php Line=80");
		phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Assignment) File=Library/Phalcon/Transaction/Manager.php Line=81");
		//$number
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_LONG(v1, 0);
		phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Foreach) File=Library/Phalcon/Transaction/Manager.php Line=82");
		t2 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		//$managedTransaction
		FOREACH_V(t2, ac0, fes57, fee57, ah0, hp0, v2)
			phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Block) File=Library/Phalcon/Transaction/Manager.php Line=82");
			phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (If) File=Library/Phalcon/Transaction/Manager.php Line=83");
			//$managedTransaction
			//$transaction
			PHALCON_EQUAL_FUNCTION(r2, v2, v0);
			if (zend_is_true(r2)) {
				phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Block) File=Library/Phalcon/Transaction/Manager.php Line=83");
				phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (PostIncDecOp) File=Library/Phalcon/Transaction/Manager.php Line=86");
				t3 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
				{
					zval *orig_ptr = t3;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(t3);
						*t3 = *orig_ptr;
						zval_copy_ctor(t3);
						Z_SET_REFCOUNT_P(t3, 1);
						Z_UNSET_ISREF_P(t3);
					}
				}
				decrement_function(t3);
				zend_update_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, t3 TSRMLS_CC);
			}
			phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (PostIncDecOp) File=Library/Phalcon/Transaction/Manager.php Line=88");
			//$number
			{
				zval *orig_ptr = v1;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(v1);
					*v1 = *orig_ptr;
					zval_copy_ctor(v1);
					Z_SET_REFCOUNT_P(v1, 1);
					Z_UNSET_ISREF_P(v1);
				}
			}
			increment_function(v1);
			phalcon_debug_vdump("PostIncrementing $number", v1);
		END_FOREACH(ac0, fes57, fee57, ah0, hp0);
		phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Assignment) File=Library/Phalcon/Transaction/Manager.php Line=90");
		//$transactions
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(a0);
		v3 = a0;
		phalcon_debug_assign("$transactions", a0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Foreach) File=Library/Phalcon/Transaction/Manager.php Line=91");
		t4 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		//$managedTransaction
		FOREACH_V(t4, ac1, fes58, fee58, ah1, hp1, v2)
			phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Block) File=Library/Phalcon/Transaction/Manager.php Line=91");
			phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Assignment) File=Library/Phalcon/Transaction/Manager.php Line=92");
			//$managedTransaction
			//$transactions
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				{
					zval *orig_ptr = v3;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(v3);
						*v3 = *orig_ptr;
						zval_copy_ctor(v3);
						Z_SET_REFCOUNT_P(v3, 1);
						Z_UNSET_ISREF_P(v3);
					}
				}
				phalcon_array_append(v3, copy TSRMLS_CC);
			}
		END_FOREACH(ac1, fes58, fee58, ah1, hp1);
		phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Assignment) File=Library/Phalcon/Transaction/Manager.php Line=94");
		//$transactions
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, v3 TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Method) File=Library/Phalcon/Transaction/Manager.php Line=98");
}

PHP_METHOD(Phalcon_Transaction_Manager, collectTransactions){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	phalcon_step_into_entry("Phalcon_Transaction_Manager", "collectTransactions", 0);
	phalcon_step_over("Phalcon_Transaction_Manager::collectTransactions (If) File=Library/Phalcon/Transaction/Manager.php Line=99");
	PHALCON_ALLOC_ZVAL(r0);
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	p0[0] = t0;
	phalcon_debug_param(t0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "count", 1, p0);
	phalcon_debug_vdump("count > ", r0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_SMALLER_FUNCTION(r1, t1, r0);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Transaction_Manager::collectTransactions (Block) File=Library/Phalcon/Transaction/Manager.php Line=99");
		phalcon_step_over("Phalcon_Transaction_Manager::collectTransactions (Assignment) File=Library/Phalcon/Transaction/Manager.php Line=100");
		//$number
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_LONG(v0, 0);
		phalcon_step_over("Phalcon_Transaction_Manager::collectTransactions (Foreach) File=Library/Phalcon/Transaction/Manager.php Line=101");
		t2 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		//$managedTransaction
		FOREACH_V(t2, ac0, fes59, fee59, ah0, hp0, v1)
			phalcon_step_over("Phalcon_Transaction_Manager::collectTransactions (Block) File=Library/Phalcon/Transaction/Manager.php Line=101");
			phalcon_step_over("Phalcon_Transaction_Manager::collectTransactions (PostIncDecOp) File=Library/Phalcon/Transaction/Manager.php Line=103");
			t3 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			{
				zval *orig_ptr = t3;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(t3);
					*t3 = *orig_ptr;
					zval_copy_ctor(t3);
					Z_SET_REFCOUNT_P(t3, 1);
					Z_UNSET_ISREF_P(t3);
				}
			}
			decrement_function(t3);
			zend_update_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, t3 TSRMLS_CC);
			phalcon_step_over("Phalcon_Transaction_Manager::collectTransactions (PostIncDecOp) File=Library/Phalcon/Transaction/Manager.php Line=104");
			//$number
			{
				zval *orig_ptr = v0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					ALLOC_ZVAL(v0);
					*v0 = *orig_ptr;
					zval_copy_ctor(v0);
					Z_SET_REFCOUNT_P(v0, 1);
					Z_UNSET_ISREF_P(v0);
				}
			}
			increment_function(v0);
			phalcon_debug_vdump("PostIncrementing $number", v0);
		END_FOREACH(ac0, fes59, fee59, ah0, hp0);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction_Manager::collectTransactions (Method) File=Library/Phalcon/Transaction/Manager.php Line=109");
}

PHP_METHOD(Phalcon_Transaction_Manager, isAutomatic){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Transaction_Manager", "isAutomatic", 0);
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_automaticTransaction", sizeof("_automaticTransaction")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_INIT_NULL(t1);
	PHALCON_NOT_EQUAL_FUNCTION(r0, t0, t1);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r0);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction_Manager::isAutomatic (Method) File=Library/Phalcon/Transaction/Manager.php Line=113");
}

PHP_METHOD(Phalcon_Transaction_Manager, getAutomatic){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Transaction_Manager", "getAutomatic", 0);
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_automaticTransaction", sizeof("_automaticTransaction")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
}

