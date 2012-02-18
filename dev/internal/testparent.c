
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

PHP_METHOD(Phalcon_Internal_TestParent, mp1){


	phalcon_step_into_entry("Phalcon_Internal_TestParent", "mp1", 0);
	phalcon_step_out_entry();
	RETURN_STRING("mp1", 1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_TestParent::mp1 (Method) File=Library/Phalcon/Internal/TestParent.php Line=11");
}

PHP_METHOD(Phalcon_Internal_TestParent, mp2){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_TestParent", "mp2", 0);
	phalcon_step_over("Phalcon_Internal_TestParent::mp2 (Assignment) File=Library/Phalcon/Internal/TestParent.php Line=12");
	//$this
	phalcon_update_property_long(this_ptr, "_pp0", strlen("_pp0"), 0 TSRMLS_CC);
	//$a
	//$b
	PHALCON_ALLOC_ZVAL(r0);
	add_function(r0, v0, v1 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_TestParent::mp2 (Method) File=Library/Phalcon/Internal/TestParent.php Line=16");
}

PHP_METHOD(Phalcon_Internal_TestParent, mp7){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_TestParent", "mp7", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_pp0", sizeof("_pp0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_TestParent::mp7 (Method) File=Library/Phalcon/Internal/TestParent.php Line=20");
}

PHP_METHOD(Phalcon_Internal_TestParent, smp1){


	phalcon_step_into_entry("Phalcon_Internal_TestParent", "smp1", 0);
	phalcon_step_out_entry();
	RETURN_STRING("parent-protected", 1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_TestParent::smp1 (Method) File=Library/Phalcon/Internal/TestParent.php Line=24");
}

PHP_METHOD(Phalcon_Internal_TestParent, smp3){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_TestParent", "smp3", 0);
	//$a
	//$b
	PHALCON_ALLOC_ZVAL(r0);
	add_function(r0, v0, v1 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_TestParent::smp3 (Method) File=Library/Phalcon/Internal/TestParent.php Line=28");
}

PHP_METHOD(Phalcon_Internal_TestParent, smp6){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v3 > ", v3 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_TestParent", "smp6", 0);
	phalcon_step_over("Phalcon_Internal_TestParent::smp6 (If) File=Library/Phalcon/Internal/TestParent.php Line=29");
	//$a
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_SMALLER_FUNCTION(r0, t0, v1);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Internal_TestParent::smp6 (Block) File=Library/Phalcon/Internal/TestParent.php Line=29");
		//$b
		//$c
		PHALCON_ALLOC_ZVAL(r1);
		mul_function(r1, v2, v3 TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r1 TSRMLS_CC);
		phalcon_step_out_entry();
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(r1);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
			Z_SET_REFCOUNT_P(return_value, refcount);
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Internal_TestParent::smp6 (Block) File=Library/Phalcon/Internal/TestParent.php Line=31");
		phalcon_step_over("Phalcon_Internal_TestParent::smp6 (If) File=Library/Phalcon/Internal/TestParent.php Line=32");
		//$b
		PHALCON_ALLOC_ZVAL(t1);
		ZVAL_LONG(t1, 30);
		PHALCON_SMALLER_FUNCTION(r2, v2, t1);
		if (zend_is_true(r2)) {
			phalcon_step_over("Phalcon_Internal_TestParent::smp6 (Block) File=Library/Phalcon/Internal/TestParent.php Line=32");
			//$a
			//$c
			PHALCON_ALLOC_ZVAL(r3);
			mul_function(r3, v1, v3 TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
			phalcon_step_out_entry();
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r3);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
				Z_SET_REFCOUNT_P(return_value, refcount);
			}
			return;
		} else {
			phalcon_step_over("Phalcon_Internal_TestParent::smp6 (Block) File=Library/Phalcon/Internal/TestParent.php Line=34");
			PHALCON_ALLOC_ZVAL(r4);
			//$o
			phalcon_assert_class(this_ptr, "Phalcon_Internal_TestParent" TSRMLS_CC);
			phalcon_debug_method_call(v0, "mp7" TSRMLS_CC);
			//$a
			Z_ADDREF_P(v1);
			p0[0] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			//$b
			Z_ADDREF_P(v2);
			p0[1] = v2;
			phalcon_debug_param(v2 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS(r4, v0, "mp7", 2, p0, PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r4 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Internal_TestParent" TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r4 TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_ZVAL(r4, 1, 0);
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
}

