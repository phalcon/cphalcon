
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

PHP_METHOD(Phalcon_Model_Resultset, __construct){

	zval *v0 = NULL, *v1 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Resultset", "__construct", 0);
	phalcon_step_over("Phalcon_Model_Resultset::__construct (Assignment) File=Library/Phalcon/Model/Resultset.php Line=16");
	//$model
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Resultset::__construct (Assignment) File=Library/Phalcon/Model/Resultset.php Line=17");
	//$resultResource
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_resultResource", strlen("_resultResource"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Resultset::__construct (Method) File=Library/Phalcon/Model/Resultset.php Line=20");
}

PHP_METHOD(Phalcon_Model_Resultset, valid){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL };

	phalcon_step_into_entry("Phalcon_Model_Resultset", "valid", 0);
	phalcon_step_over("Phalcon_Model_Resultset::valid (If) File=Library/Phalcon/Model/Resultset.php Line=21");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (Z_TYPE_P(t0) == IS_BOOL && !Z_BVAL_P(t0)) {
		phalcon_step_over("Phalcon_Model_Resultset::valid (Block) File=Library/Phalcon/Model/Resultset.php Line=21");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_over("Phalcon_Model_Resultset::valid (Assignment) File=Library/Phalcon/Model/Resultset.php Line=24");
	//$dbResource
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(t1, "getconnection" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t1, "getconnection", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(r0);
	v0 = r0;
	phalcon_debug_assign("$dbResource", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Resultset::valid (MethodCall) File=Library/Phalcon/Model/Resultset.php Line=25");
	//$dbResource
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(v0, "setfetchmode" TSRMLS_CC);
	PHALCON_GET_CLASS_CONSTANT(t2, phalcon_db_class_entry, "DB_ASSOC");
	Z_ADDREF_P(t2);
	p1[0] = t2;
	phalcon_debug_param(t2 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setfetchmode", 1, p1, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Resultset::valid (Assignment) File=Library/Phalcon/Model/Resultset.php Line=26");
	//$row
	PHALCON_ALLOC_ZVAL(r1);
	//$dbResource
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(v0, "fetcharray" TSRMLS_CC);
	//$this
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_read_property(t3, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t3);
	Z_ADDREF_P(t3);
	p2[0] = t3;
	phalcon_debug_param(t3 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r1, v0, "fetcharray", 1, p2, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	if (v1) {
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r1);
	v1 = r1;
	phalcon_debug_assign("$row", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Resultset::valid (If) File=Library/Phalcon/Model/Resultset.php Line=27");
	//$row
	if (zend_is_true(v1)) {
		phalcon_step_over("Phalcon_Model_Resultset::valid (Block) File=Library/Phalcon/Model/Resultset.php Line=27");
		phalcon_step_over("Phalcon_Model_Resultset::valid (If) File=Library/Phalcon/Model/Resultset.php Line=28");
		PHALCON_ALLOC_ZVAL(r2);
		//$this
		PHALCON_ALLOC_ZVAL(t4);
		phalcon_read_property(t4, this_ptr, "_activeRow", sizeof("_activeRow")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t4);
		Z_ADDREF_P(t4);
		p3[0] = t4;
		phalcon_debug_param(t4 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r2, "is_object", 1, p3);
		phalcon_debug_vdump("is_object > ", r2 TSRMLS_CC);
		if (zend_is_true(r2)) {
			phalcon_step_over("Phalcon_Model_Resultset::valid (Block) File=Library/Phalcon/Model/Resultset.php Line=28");
			phalcon_step_over("Phalcon_Model_Resultset::valid (Unset) File=Library/Phalcon/Model/Resultset.php Line=29");
			//Unset ObjectProperty
		}
		phalcon_step_over("Phalcon_Model_Resultset::valid (Assignment) File=Library/Phalcon/Model/Resultset.php Line=31");
		PHALCON_ALLOC_ZVAL(r3);
		//$this
		PHALCON_ALLOC_ZVAL(t5);
		phalcon_read_property(t5, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t5);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(t5, "dumpresult" TSRMLS_CC);
		//$row
		Z_ADDREF_P(v1);
		p4[0] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r3, t5, "dumpresult", 1, p4, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r3 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r3, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_activeRow", strlen("_activeRow"), copy TSRMLS_CC);
		}
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Model_Resultset::valid (Block) File=Library/Phalcon/Model/Resultset.php Line=33");
		phalcon_step_over("Phalcon_Model_Resultset::valid (MethodCall) File=Library/Phalcon/Model/Resultset.php Line=34");
		//$dbResource
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(v0, "setfetchmode" TSRMLS_CC);
		PHALCON_GET_CLASS_CONSTANT(t6, phalcon_db_class_entry, "DB_BOTH");
		Z_ADDREF_P(t6);
		p5[0] = t6;
		phalcon_debug_param(t6 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setfetchmode", 1, p5, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Resultset::valid (Method) File=Library/Phalcon/Model/Resultset.php Line=39");
}

PHP_METHOD(Phalcon_Model_Resultset, current){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Resultset", "current", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_activeRow", sizeof("_activeRow")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Model_Resultset::current (Method) File=Library/Phalcon/Model/Resultset.php Line=43");
}

PHP_METHOD(Phalcon_Model_Resultset, next){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Resultset", "next", 0);
	phalcon_step_over("Phalcon_Model_Resultset::next (PreIncDecOp) File=Library/Phalcon/Model/Resultset.php Line=44");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	{
		zval *orig_ptr = t0;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(t0);
			*t0 = *orig_ptr;
			zval_copy_ctor(t0);
			Z_SET_REFCOUNT_P(t0, 1);
			Z_UNSET_ISREF_P(t0);
		}
	}
	increment_function(t0);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Resultset::next (Method) File=Library/Phalcon/Model/Resultset.php Line=47");
}

PHP_METHOD(Phalcon_Model_Resultset, key){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Resultset", "key", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Model_Resultset::key (Method) File=Library/Phalcon/Model/Resultset.php Line=51");
}

PHP_METHOD(Phalcon_Model_Resultset, rewind){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p1[] = { NULL, NULL };

	phalcon_step_into_entry("Phalcon_Model_Resultset", "rewind", 0);
	phalcon_step_over("Phalcon_Model_Resultset::rewind (If) File=Library/Phalcon/Model/Resultset.php Line=52");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (Z_TYPE_P(t0) == IS_BOOL && !Z_BVAL_P(t0)) {
		phalcon_step_over("Phalcon_Model_Resultset::rewind (Block) File=Library/Phalcon/Model/Resultset.php Line=52");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_over("Phalcon_Model_Resultset::rewind (Assignment) File=Library/Phalcon/Model/Resultset.php Line=55");
	//$this
	phalcon_update_property_long(this_ptr, "pointer", strlen("pointer"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Resultset::rewind (Assignment) File=Library/Phalcon/Model/Resultset.php Line=56");
	//$dbResource
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(t1, "getconnection" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t1, "getconnection", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(r0);
	v0 = r0;
	phalcon_debug_assign("$dbResource", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Resultset::rewind (MethodCall) File=Library/Phalcon/Model/Resultset.php Line=57");
	//$dbResource
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(v0, "dataseek" TSRMLS_CC);
	PHALCON_PARAM_LONG(p1[0], 0);
	//$this
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t2);
	Z_ADDREF_P(t2);
	p1[1] = t2;
	phalcon_debug_param(t2 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "dataseek", 2, p1, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Resultset::rewind (Method) File=Library/Phalcon/Model/Resultset.php Line=60");
}

PHP_METHOD(Phalcon_Model_Resultset, seek){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p1[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Resultset", "seek", 0);
	phalcon_step_over("Phalcon_Model_Resultset::seek (Assignment) File=Library/Phalcon/Model/Resultset.php Line=61");
	//$position
	convert_to_long(v0);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Resultset::seek (Assignment) File=Library/Phalcon/Model/Resultset.php Line=62");
	//$dbResource
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(t0, "getconnection" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t0, "getconnection", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	phalcon_debug_assign("$dbResource", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Resultset::seek (MethodCall) File=Library/Phalcon/Model/Resultset.php Line=63");
	//$dbResource
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(v1, "dataseek" TSRMLS_CC);
	//$position
	convert_to_long(v0);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	Z_ADDREF_P(t1);
	p1[1] = t1;
	phalcon_debug_param(t1 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "dataseek", 2, p1, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Resultset::seek (Method) File=Library/Phalcon/Model/Resultset.php Line=66");
}

PHP_METHOD(Phalcon_Model_Resultset, count){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *v0 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL };

	phalcon_step_into_entry("Phalcon_Model_Resultset", "count", 0);
	phalcon_step_over("Phalcon_Model_Resultset::count (If) File=Library/Phalcon/Model/Resultset.php Line=67");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (Z_TYPE_P(t0) == IS_BOOL && !Z_BVAL_P(t0)) {
		phalcon_step_over("Phalcon_Model_Resultset::count (Block) File=Library/Phalcon/Model/Resultset.php Line=67");
		phalcon_step_out_entry();
		RETURN_LONG(0);
	}
	phalcon_step_over("Phalcon_Model_Resultset::count (If) File=Library/Phalcon/Model/Resultset.php Line=70");
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_count", sizeof("_count")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	Z_ADDREF_P(t1);
	p0[0] = t1;
	phalcon_debug_param(t1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "is_null", 1, p0);
	phalcon_debug_vdump("is_null > ", r0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Model_Resultset::count (Block) File=Library/Phalcon/Model/Resultset.php Line=70");
		phalcon_step_over("Phalcon_Model_Resultset::count (Assignment) File=Library/Phalcon/Model/Resultset.php Line=71");
		//$dbResource
		PHALCON_ALLOC_ZVAL(r1);
		//$this
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(t2, "getconnection" TSRMLS_CC);
		PHALCON_CALL_METHOD(r1, t2, "getconnection", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(r1);
		v0 = r1;
		phalcon_debug_assign("$dbResource", r1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Resultset::count (Assignment) File=Library/Phalcon/Model/Resultset.php Line=72");
		PHALCON_ALLOC_ZVAL(r2);
		//$dbResource
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(v0, "numrows" TSRMLS_CC);
		//$this
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t3);
		Z_ADDREF_P(t3);
		p2[0] = t3;
		phalcon_debug_param(t3 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r2, v0, "numrows", 1, p2, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_count", strlen("_count"), copy TSRMLS_CC);
		}
	}
	//$this
	PHALCON_ALLOC_ZVAL(t4);
	phalcon_read_property(t4, this_ptr, "_count", sizeof("_count")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t4);
	phalcon_debug_vdump("Returning > ", t4 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t4) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t4);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t4);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Resultset::count (Method) File=Library/Phalcon/Model/Resultset.php Line=77");
}

PHP_METHOD(Phalcon_Model_Resultset, offsetExists){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Resultset", "offsetExists", 0);
	phalcon_step_over("Phalcon_Model_Resultset::offsetExists (If) File=Library/Phalcon/Model/Resultset.php Line=78");
	//$index
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "count" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "count", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	PHALCON_SMALLER_FUNCTION(r1, v0, r0);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Model_Resultset::offsetExists (Block) File=Library/Phalcon/Model/Resultset.php Line=78");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Resultset::offsetExists (Method) File=Library/Phalcon/Model/Resultset.php Line=83");
}

PHP_METHOD(Phalcon_Model_Resultset, offsetGet){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL }, *p4[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Resultset", "offsetGet", 0);
	phalcon_step_over("Phalcon_Model_Resultset::offsetGet (If) File=Library/Phalcon/Model/Resultset.php Line=84");
	//$index
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "count" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "count", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	PHALCON_SMALLER_FUNCTION(r1, v0, r0);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Model_Resultset::offsetGet (Block) File=Library/Phalcon/Model/Resultset.php Line=84");
		phalcon_step_over("Phalcon_Model_Resultset::offsetGet (MethodCall) File=Library/Phalcon/Model/Resultset.php Line=85");
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "seek" TSRMLS_CC);
		//$index
		Z_ADDREF_P(v0);
		p1[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "seek", 1, p1, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Resultset::offsetGet (If) File=Library/Phalcon/Model/Resultset.php Line=86");
		PHALCON_ALLOC_ZVAL(r2);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "valid" TSRMLS_CC);
		PHALCON_CALL_METHOD(r2, this_ptr, "valid", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		if (zend_is_true(r2)) {
			phalcon_step_over("Phalcon_Model_Resultset::offsetGet (Block) File=Library/Phalcon/Model/Resultset.php Line=86");
			PHALCON_ALLOC_ZVAL(r3);
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "current" TSRMLS_CC);
			PHALCON_CALL_METHOD(r3, this_ptr, "current", PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r3 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_ZVAL(r3, 1, 0);
		} else {
			phalcon_step_over("Phalcon_Model_Resultset::offsetGet (Block) File=Library/Phalcon/Model/Resultset.php Line=88");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	} else {
		phalcon_step_over("Phalcon_Model_Resultset::offsetGet (Block) File=Library/Phalcon/Model/Resultset.php Line=91");
		phalcon_step_over("Phalcon_Model_Resultset::offsetGet (Throw) File=Library/Phalcon/Model/Resultset.php Line=92");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p4[0]);
		ZVAL_STRING(p4[0], "The index does not exist in the cursor", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p4, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Resultset::offsetGet (Method) File=Library/Phalcon/Model/Resultset.php Line=96");
}

PHP_METHOD(Phalcon_Model_Resultset, offsetSet){

	zval *v0 = NULL, *v1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Resultset", "offsetSet", 0);
	phalcon_step_over("Phalcon_Model_Resultset::offsetSet (Throw) File=Library/Phalcon/Model/Resultset.php Line=97");
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_model_exception_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "Cursor is read only", 1);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	zend_throw_exception_object(i0 TSRMLS_CC);
	Z_ADDREF_P(i0);
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Resultset::offsetSet (Method) File=Library/Phalcon/Model/Resultset.php Line=100");
}

PHP_METHOD(Phalcon_Model_Resultset, offsetUnset){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Resultset", "offsetUnset", 0);
	phalcon_step_over("Phalcon_Model_Resultset::offsetUnset (Throw) File=Library/Phalcon/Model/Resultset.php Line=101");
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_model_exception_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "Cursor is read only", 1);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	zend_throw_exception_object(i0 TSRMLS_CC);
	Z_ADDREF_P(i0);
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Resultset::offsetUnset (Method) File=Library/Phalcon/Model/Resultset.php Line=104");
}

PHP_METHOD(Phalcon_Model_Resultset, getFirst){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Resultset", "getFirst", 0);
	phalcon_step_over("Phalcon_Model_Resultset::getFirst (If) File=Library/Phalcon/Model/Resultset.php Line=105");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_NOT_EQUAL_FUNCTION(r0, t0, t1);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Model_Resultset::getFirst (Block) File=Library/Phalcon/Model/Resultset.php Line=105");
		phalcon_step_over("Phalcon_Model_Resultset::getFirst (MethodCall) File=Library/Phalcon/Model/Resultset.php Line=106");
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "rewind" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "rewind", PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Resultset::getFirst (If) File=Library/Phalcon/Model/Resultset.php Line=108");
	//$this
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t2);
	PHALCON_INIT_FALSE(t3);
	PHALCON_NOT_IDENTICAL_FUNCTION(r1, t2, t3);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Model_Resultset::getFirst (Block) File=Library/Phalcon/Model/Resultset.php Line=108");
		phalcon_step_over("Phalcon_Model_Resultset::getFirst (If) File=Library/Phalcon/Model/Resultset.php Line=109");
		PHALCON_ALLOC_ZVAL(r2);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "valid" TSRMLS_CC);
		PHALCON_CALL_METHOD(r2, this_ptr, "valid", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		if (zend_is_true(r2)) {
			phalcon_step_over("Phalcon_Model_Resultset::getFirst (Block) File=Library/Phalcon/Model/Resultset.php Line=109");
			PHALCON_ALLOC_ZVAL(r3);
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "current" TSRMLS_CC);
			PHALCON_CALL_METHOD(r3, this_ptr, "current", PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r3 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_ZVAL(r3, 1, 0);
		} else {
			phalcon_step_over("Phalcon_Model_Resultset::getFirst (Block) File=Library/Phalcon/Model/Resultset.php Line=111");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	} else {
		phalcon_step_over("Phalcon_Model_Resultset::getFirst (Block) File=Library/Phalcon/Model/Resultset.php Line=114");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Resultset::getFirst (Method) File=Library/Phalcon/Model/Resultset.php Line=119");
}

PHP_METHOD(Phalcon_Model_Resultset, getLast){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Model_Resultset", "getLast", 0);
	phalcon_step_over("Phalcon_Model_Resultset::getLast (If) File=Library/Phalcon/Model/Resultset.php Line=120");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	PHALCON_INIT_FALSE(t1);
	PHALCON_NOT_IDENTICAL_FUNCTION(r0, t0, t1);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Model_Resultset::getLast (Block) File=Library/Phalcon/Model/Resultset.php Line=120");
		phalcon_step_over("Phalcon_Model_Resultset::getLast (MethodCall) File=Library/Phalcon/Model/Resultset.php Line=121");
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "seek" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r1);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "count" TSRMLS_CC);
		PHALCON_CALL_METHOD(r1, this_ptr, "count", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t2);
		ZVAL_LONG(t2, 1);
		PHALCON_ALLOC_ZVAL(r2);
		sub_function(r2, r1, t2 TSRMLS_CC);
		Z_ADDREF_P(r2);
		p0[0] = r2;
		phalcon_debug_param(r2 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "seek", 1, p0, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Resultset::getLast (If) File=Library/Phalcon/Model/Resultset.php Line=122");
		PHALCON_ALLOC_ZVAL(r3);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "valid" TSRMLS_CC);
		PHALCON_CALL_METHOD(r3, this_ptr, "valid", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r3 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		if (zend_is_true(r3)) {
			phalcon_step_over("Phalcon_Model_Resultset::getLast (Block) File=Library/Phalcon/Model/Resultset.php Line=122");
			PHALCON_ALLOC_ZVAL(r4);
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "current" TSRMLS_CC);
			PHALCON_CALL_METHOD(r4, this_ptr, "current", PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r4 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r4 TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_ZVAL(r4, 1, 0);
		} else {
			phalcon_step_over("Phalcon_Model_Resultset::getLast (Block) File=Library/Phalcon/Model/Resultset.php Line=124");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	} else {
		phalcon_step_over("Phalcon_Model_Resultset::getLast (Block) File=Library/Phalcon/Model/Resultset.php Line=127");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Resultset::getLast (Method) File=Library/Phalcon/Model/Resultset.php Line=132");
}

PHP_METHOD(Phalcon_Model_Resultset, getModel){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Resultset", "getModel", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
}

