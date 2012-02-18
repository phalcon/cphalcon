
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

PHP_METHOD(Phalcon_Internal_Test, __construct){

	zval *a0 = NULL, *a1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "::__construct", 0);
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_property(phalcon_internal_test_class_entry, this_ptr, "_p8", strlen("_p8"), a0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	zend_update_property(phalcon_internal_test_class_entry, this_ptr, "_p9", strlen("_p9"), a1 TSRMLS_CC);
}

PHP_METHOD(Phalcon_Internal_Test, e1){


	phalcon_step_into_entry("Phalcon_Internal_Test", "e1", 0);
	phalcon_step_out_entry();
	RETURN_LONG(5);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::e1 (Method) File=Library/Phalcon/Internal/Test.php Line=60");
}

PHP_METHOD(Phalcon_Internal_Test, e2){


	phalcon_step_into_entry("Phalcon_Internal_Test", "e2", 0);
	phalcon_step_out_entry();
	RETURN_STRING("5", 1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::e2 (Method) File=Library/Phalcon/Internal/Test.php Line=64");
}

PHP_METHOD(Phalcon_Internal_Test, e3){

	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "e3", 0);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 5);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, -1);
	PHALCON_MUL_FUNCTION(r0, t0, t1);
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
	phalcon_step_over("Phalcon_Internal_Test::e3 (Method) File=Library/Phalcon/Internal/Test.php Line=68");
}

PHP_METHOD(Phalcon_Internal_Test, e4){

	zval *v0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "e4", 0);
	phalcon_step_over("Phalcon_Internal_Test::e4 (Assignment) File=Library/Phalcon/Internal/Test.php Line=69");
	//$a
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 5);
	//$a
	phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v0);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::e4 (Method) File=Library/Phalcon/Internal/Test.php Line=73");
}

PHP_METHOD(Phalcon_Internal_Test, e5){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "e5", 0);
	phalcon_step_over("Phalcon_Internal_Test::e5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=74");
	//$a
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 5);
	phalcon_step_over("Phalcon_Internal_Test::e5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=75");
	//$b
	//$a
	if (v1) {
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(v0);
	v1 = v0;
	phalcon_debug_assign("$b", v0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::e5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=76");
	//$c
	//$b
	if (v2) {
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(v1);
	v2 = v1;
	phalcon_debug_assign("$c", v1 TSRMLS_CC);
	//$c
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::e5 (Method) File=Library/Phalcon/Internal/Test.php Line=80");
}

PHP_METHOD(Phalcon_Internal_Test, e6){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "e6", 0);
	//$num
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::e6 (Method) File=Library/Phalcon/Internal/Test.php Line=84");
}

PHP_METHOD(Phalcon_Internal_Test, e7){

	zval *v0 = NULL, *v1 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "e7", 0);
	phalcon_step_over("Phalcon_Internal_Test::e7 (Assignment) File=Library/Phalcon/Internal/Test.php Line=85");
	//$a
	//$num
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(v0);
	v1 = v0;
	phalcon_debug_assign("$a", v0 TSRMLS_CC);
	//$a
	phalcon_debug_vdump("Returning > ", v1 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(v1) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v1);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v1);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::e7 (Method) File=Library/Phalcon/Internal/Test.php Line=96");
}

PHP_METHOD(Phalcon_Internal_Test, e9){


	phalcon_step_into_entry("Phalcon_Internal_Test", "e9", 0);
	phalcon_step_out_entry();
	RETURN_STRING("LOL", 1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::e9 (Method) File=Library/Phalcon/Internal/Test.php Line=100");
}

PHP_METHOD(Phalcon_Internal_Test, e10){


	phalcon_step_into_entry("Phalcon_Internal_Test", "e10", 0);
	phalcon_step_out_entry();
	RETURN_DOUBLE(1.5);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::e10 (Method) File=Library/Phalcon/Internal/Test.php Line=104");
}

PHP_METHOD(Phalcon_Internal_Test, e13){

	zval *v0 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "e13", 0);
	phalcon_step_over("Phalcon_Internal_Test::e13 (Assignment) File=Library/Phalcon/Internal/Test.php Line=105");
	//$a
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(i0);
	v0 = i0;
	phalcon_debug_assign("$a", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::e13 (Assignment) File=Library/Phalcon/Internal/Test.php Line=106");
	//$a
	phalcon_update_property_long(v0, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::e13 (Assignment) File=Library/Phalcon/Internal/Test.php Line=107");
	//$a
	phalcon_update_property_long(v0, "dos", strlen("dos"), 2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::e13 (Assignment) File=Library/Phalcon/Internal/Test.php Line=108");
	PHALCON_ALLOC_ZVAL(i1);
	object_init(i1);
	//$a
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, i1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(v0, "subA", strlen("subA"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Internal_Test::e13 (Assignment) File=Library/Phalcon/Internal/Test.php Line=109");
	//$a
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_update_property_long(t0, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::e13 (Assignment) File=Library/Phalcon/Internal/Test.php Line=110");
	//$a
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	phalcon_update_property_long(t1, "dos", strlen("dos"), 2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::e13 (Assignment) File=Library/Phalcon/Internal/Test.php Line=111");
	PHALCON_ALLOC_ZVAL(i2);
	object_init(i2);
	//$a
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t2);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, i2, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(t2, "subSubA", strlen("subSubA"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Internal_Test::e13 (Assignment) File=Library/Phalcon/Internal/Test.php Line=112");
	//$a
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_read_property(t3, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t3);
	PHALCON_ALLOC_ZVAL(t4);
	phalcon_read_property(t4, t3, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t4);
	phalcon_update_property_long(t4, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::e13 (Assignment) File=Library/Phalcon/Internal/Test.php Line=113");
	//$a
	PHALCON_ALLOC_ZVAL(t5);
	phalcon_read_property(t5, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t5);
	PHALCON_ALLOC_ZVAL(t6);
	phalcon_read_property(t6, t5, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t6);
	phalcon_update_property_long(t6, "dos", strlen("dos"), 2 TSRMLS_CC);
	//$a
	PHALCON_ALLOC_ZVAL(t7);
	phalcon_read_property(t7, v0, "uno", sizeof("uno")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t7);
	//$a
	PHALCON_ALLOC_ZVAL(t8);
	phalcon_read_property(t8, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t8);
	PHALCON_ALLOC_ZVAL(t9);
	phalcon_read_property(t9, t8, "uno", sizeof("uno")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t9);
	PHALCON_ALLOC_ZVAL(r0);
	mul_function(r0, t7, t9 TSRMLS_CC);
	//$a
	PHALCON_ALLOC_ZVAL(t10);
	phalcon_read_property(t10, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t10);
	PHALCON_ALLOC_ZVAL(t11);
	phalcon_read_property(t11, t10, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t11);
	PHALCON_ALLOC_ZVAL(t12);
	phalcon_read_property(t12, t11, "uno", sizeof("uno")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t12);
	PHALCON_ALLOC_ZVAL(r1);
	mul_function(r1, r0, t12 TSRMLS_CC);
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::e13 (Method) File=Library/Phalcon/Internal/Test.php Line=117");
}

PHP_METHOD(Phalcon_Internal_Test, e14){

	zval *v0 = NULL, *v1 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "e14", 0);
	phalcon_step_over("Phalcon_Internal_Test::e14 (Assignment) File=Library/Phalcon/Internal/Test.php Line=118");
	//$a
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(i0);
	v1 = i0;
	phalcon_debug_assign("$a", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::e14 (Assignment) File=Library/Phalcon/Internal/Test.php Line=119");
	//$val
	//$a
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(v1, "val", strlen("val"), copy TSRMLS_CC);
	}
	//$a
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, v1, "val", sizeof("val")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::e14 (Method) File=Library/Phalcon/Internal/Test.php Line=124");
}

PHP_METHOD(Phalcon_Internal_Test, o1){

	zval *v0 = NULL;
	zval *t0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "o1", 0);
	//$num
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
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_ZVAL(t0, v0, 1, 0);
	increment_function(v0);
	phalcon_debug_vdump("PostIncrementing $num", v0);
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
	phalcon_step_over("Phalcon_Internal_Test::o1 (Method) File=Library/Phalcon/Internal/Test.php Line=128");
}

PHP_METHOD(Phalcon_Internal_Test, o2){

	zval *v0 = NULL;
	zval *t0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "o2", 0);
	//$num
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
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_ZVAL(t0, v0, 1, 0);
	decrement_function(v0);
	phalcon_debug_vdump("PostDecrementing $num", v0);
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
	phalcon_step_over("Phalcon_Internal_Test::o2 (Method) File=Library/Phalcon/Internal/Test.php Line=132");
}

PHP_METHOD(Phalcon_Internal_Test, o3){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "o3", 0);
	//$num
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(r0);
	mul_function(r0, v0, t0 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::o3 (Method) File=Library/Phalcon/Internal/Test.php Line=136");
}

PHP_METHOD(Phalcon_Internal_Test, o4){

	zval *v0 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "o4", 0);
	//$num
	//$num
	PHALCON_ADD_FUNCTION(r0, v0, v0);
	//$num
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(r0);
	v0 = r0;
	phalcon_debug_assign("$num", r0 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::o4 (Method) File=Library/Phalcon/Internal/Test.php Line=140");
}

PHP_METHOD(Phalcon_Internal_Test, o5){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "o5", 0);
	//$num1
	//$num2
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
	phalcon_step_over("Phalcon_Internal_Test::o5 (Method) File=Library/Phalcon/Internal/Test.php Line=144");
}

PHP_METHOD(Phalcon_Internal_Test, o6){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "o6", 0);
	//$num1
	//$num2
	PHALCON_ALLOC_ZVAL(r0);
	sub_function(r0, v0, v1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::o6 (Method) File=Library/Phalcon/Internal/Test.php Line=148");
}

PHP_METHOD(Phalcon_Internal_Test, o7){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "o7", 0);
	//$num1
	//$num2
	PHALCON_ALLOC_ZVAL(r0);
	mul_function(r0, v0, v1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::o7 (Method) File=Library/Phalcon/Internal/Test.php Line=152");
}

PHP_METHOD(Phalcon_Internal_Test, o8){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "o8", 0);
	//$num1
	//$num2
	PHALCON_ALLOC_ZVAL(r0);
	div_function(r0, v0, v1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::o8 (Method) File=Library/Phalcon/Internal/Test.php Line=156");
}

PHP_METHOD(Phalcon_Internal_Test, o9){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "o9", 0);
	//$num1
	//$num2
	PHALCON_MOD_FUNCTION(r0, v0, v1);
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
	phalcon_step_over("Phalcon_Internal_Test::o9 (Method) File=Library/Phalcon/Internal/Test.php Line=160");
}

PHP_METHOD(Phalcon_Internal_Test, o10){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "o10", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL(r0);
	add_function(r0, t0, t1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::o10 (Method) File=Library/Phalcon/Internal/Test.php Line=163");
}

PHP_METHOD(Phalcon_Internal_Test, o11){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "o11", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL(r0);
	sub_function(r0, t0, t1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::o11 (Method) File=Library/Phalcon/Internal/Test.php Line=166");
}

PHP_METHOD(Phalcon_Internal_Test, o12){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "o12", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL(r0);
	mul_function(r0, t0, t1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::o12 (Method) File=Library/Phalcon/Internal/Test.php Line=170");
}

PHP_METHOD(Phalcon_Internal_Test, o13){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "o13", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL(r0);
	div_function(r0, t0, t1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::o13 (Method) File=Library/Phalcon/Internal/Test.php Line=174");
}

PHP_METHOD(Phalcon_Internal_Test, o14){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "o14", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_MOD_FUNCTION(r0, t0, t1);
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
	phalcon_step_over("Phalcon_Internal_Test::o14 (Method) File=Library/Phalcon/Internal/Test.php Line=178");
}

PHP_METHOD(Phalcon_Internal_Test, o15){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "o15", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "10", 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 10);
	PHALCON_ALLOC_ZVAL(r0);
	add_function(r0, t0, t1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::o15 (Method) File=Library/Phalcon/Internal/Test.php Line=182");
}

PHP_METHOD(Phalcon_Internal_Test, o16){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "o16", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_STRING(t1, "5", 1);
	PHALCON_ALLOC_ZVAL(r0);
	sub_function(r0, t0, t1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::o16 (Method) File=Library/Phalcon/Internal/Test.php Line=186");
}

PHP_METHOD(Phalcon_Internal_Test, o17){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "o17", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 5);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_STRING(t1, "7", 1);
	PHALCON_ALLOC_ZVAL(r0);
	mul_function(r0, t0, t1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::o17 (Method) File=Library/Phalcon/Internal/Test.php Line=190");
}

PHP_METHOD(Phalcon_Internal_Test, o18){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "o18", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "100", 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 10);
	PHALCON_ALLOC_ZVAL(r0);
	div_function(r0, t0, t1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::o18 (Method) File=Library/Phalcon/Internal/Test.php Line=194");
}

PHP_METHOD(Phalcon_Internal_Test, o19){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "o19", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 40);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_STRING(t1, "5", 1);
	PHALCON_MOD_FUNCTION(r0, t0, t1);
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
	phalcon_step_over("Phalcon_Internal_Test::o19 (Method) File=Library/Phalcon/Internal/Test.php Line=198");
}

PHP_METHOD(Phalcon_Internal_Test, o20){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "o20", 0);
	phalcon_step_over("Phalcon_Internal_Test::o20 (Assignment) File=Library/Phalcon/Internal/Test.php Line=199");
	//$a
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_LONG(v1, 150);
	phalcon_step_over("Phalcon_Internal_Test::o20 (Assignment) File=Library/Phalcon/Internal/Test.php Line=200");
	//$b
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_LONG(v2, 250);
	phalcon_step_over("Phalcon_Internal_Test::o20 (Assignment) File=Library/Phalcon/Internal/Test.php Line=201");
	//$a
	//$a
	//$b
	PHALCON_ALLOC_ZVAL(r0);
	mul_function(r0, v1, v2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 100);
	PHALCON_ALLOC_ZVAL(r1);
	add_function(r1, r0, t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 100);
	PHALCON_ALLOC_ZVAL(r2);
	div_function(r2, r1, t1 TSRMLS_CC);
	//$b
	PHALCON_ALLOC_ZVAL(r3);
	sub_function(r3, r2, v2 TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r3);
	v1 = r3;
	phalcon_debug_assign("$a", r3 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::o20 (Assignment) File=Library/Phalcon/Internal/Test.php Line=202");
	//$b
	//$b
	PHALCON_ALLOC_ZVAL(t2);
	ZVAL_LONG(t2, 5);
	PHALCON_ALLOC_ZVAL(r4);
	mul_function(r4, v2, t2 TSRMLS_CC);
	//$c
	PHALCON_ALLOC_ZVAL(r5);
	div_function(r5, r4, v0 TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r5);
	v2 = r5;
	phalcon_debug_assign("$b", r5 TSRMLS_CC);
	//$a
	//$b
	PHALCON_ALLOC_ZVAL(r6);
	div_function(r6, v1, v2 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r6 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r6);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::o20 (Method) File=Library/Phalcon/Internal/Test.php Line=206");
}

PHP_METHOD(Phalcon_Internal_Test, o21){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "o21", 0);
	phalcon_step_over("Phalcon_Internal_Test::o21 (Assignment) File=Library/Phalcon/Internal/Test.php Line=207");
	//$a
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_STRING(v0, "memory", 0);
	phalcon_step_over("Phalcon_Internal_Test::o21 (Assignment) File=Library/Phalcon/Internal/Test.php Line=208");
	//$b
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_STRING(v1, "yes", 0);
	phalcon_step_over("Phalcon_Internal_Test::o21 (Assignment) File=Library/Phalcon/Internal/Test.php Line=209");
	//$c
	//$a
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_concat_left(r0, "no, ", v0 TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r0);
	v2 = r0;
	phalcon_debug_assign("$c", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::o21 (Assignment) File=Library/Phalcon/Internal/Test.php Line=210");
	//$d
	//$b
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_concat_left(r1, "leaks, ", v1 TSRMLS_CC);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(r1);
	v3 = r1;
	phalcon_debug_assign("$d", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::o21 (Assignment) File=Library/Phalcon/Internal/Test.php Line=211");
	//$b
	//$c
	//$d
	PHALCON_ALLOC_ZVAL(r2);
	concat_function(r2, v2, v3 TSRMLS_CC);
	//$b
	PHALCON_ALLOC_ZVAL(r3);
	concat_function(r3, r2, v1 TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r3);
	v1 = r3;
	phalcon_debug_assign("$b", r3 TSRMLS_CC);
	//$b
	phalcon_debug_vdump("Returning > ", v1 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v1);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::o21 (Method) File=Library/Phalcon/Internal/Test.php Line=215");
}

PHP_METHOD(Phalcon_Internal_Test, o22){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "o22", 0);
	phalcon_step_over("Phalcon_Internal_Test::o22 (Assignment) File=Library/Phalcon/Internal/Test.php Line=216");
	//$e
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 0);
	phalcon_step_over("Phalcon_Internal_Test::o22 (For) File=Library/Phalcon/Internal/Test.php Line=217");
	//$i
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_LONG(v1, 0);
	fs16:
	//$i
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 25);
	PHALCON_SMALLER_FUNCTION(r0, v1, t0);
	if (!zend_is_true(r0)) {
		goto fe16;
	}
	phalcon_step_over("Phalcon_Internal_Test::o22 (Block) File=Library/Phalcon/Internal/Test.php Line=217");
	phalcon_step_over("Phalcon_Internal_Test::o22 (AssignOp) File=Library/Phalcon/Internal/Test.php Line=218");
	//$e
	//$i
	PHALCON_CONCAT_FUNCTION(r1, v0, v1);
	//$e
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(r1);
	v0 = r1;
	phalcon_debug_assign("$e", r1 TSRMLS_CC);
	//$i
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
	phalcon_debug_vdump("PostIncrementing $i", v1);
	goto fs16;
	fe16:
	r0 = NULL;
	//$e
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::o22 (Method) File=Library/Phalcon/Internal/Test.php Line=223");
}

PHP_METHOD(Phalcon_Internal_Test, o23){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "o23", 0);
	phalcon_step_over("Phalcon_Internal_Test::o23 (Assignment) File=Library/Phalcon/Internal/Test.php Line=224");
	//$e
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 0);
	phalcon_step_over("Phalcon_Internal_Test::o23 (For) File=Library/Phalcon/Internal/Test.php Line=225");
	//$i
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_LONG(v1, 0);
	fs17:
	//$i
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 25);
	PHALCON_SMALLER_FUNCTION(r0, v1, t0);
	if (!zend_is_true(r0)) {
		goto fe17;
	}
	phalcon_step_over("Phalcon_Internal_Test::o23 (Block) File=Library/Phalcon/Internal/Test.php Line=225");
	phalcon_step_over("Phalcon_Internal_Test::o23 (Assignment) File=Library/Phalcon/Internal/Test.php Line=226");
	//$sx
	//$i
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
	phalcon_concat_both(r1,  "[", v1, "]" TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	phalcon_debug_assign("$sx", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::o23 (AssignOp) File=Library/Phalcon/Internal/Test.php Line=227");
	//$e
	//$sx
	PHALCON_CONCAT_FUNCTION(r2, v0, v2);
	//$e
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(r2);
	v0 = r2;
	phalcon_debug_assign("$e", r2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::o23 (Assignment) File=Library/Phalcon/Internal/Test.php Line=228");
	//$sx
	if (!v2) {
		PHALCON_ALLOC_ZVAL(v2);
	} else {
		if (Z_REFCOUNT_P(v2) > 1) {
			SEPARATE_ZVAL(&v2);
		} else {
			if (Z_TYPE_P(v2) != IS_STRING) {
				FREE_ZVAL(v2);
				PHALCON_ALLOC_ZVAL(v2);
			}
		}
	}
	ZVAL_STRING(v2, "k", 0);
	//$i
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
	phalcon_debug_vdump("PostIncrementing $i", v1);
	goto fs17;
	fe17:
	r0 = NULL;
	//$e
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::o23 (Method) File=Library/Phalcon/Internal/Test.php Line=234");
}

PHP_METHOD(Phalcon_Internal_Test, a0){

	zval *a0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a0", 0);
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	phalcon_debug_vdump("Returning > ", a0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(a0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a0 (Method) File=Library/Phalcon/Internal/Test.php Line=238");
}

PHP_METHOD(Phalcon_Internal_Test, a1){

	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a1", 0);
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_INIT_NULL(t0);
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
	add_next_index_zval(a0, t0);
	PHALCON_INIT_FALSE(t1);
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
	add_next_index_long(a0, 0);
	add_next_index_string(a0, "whtzup", 1);
	phalcon_debug_vdump("Returning > ", a0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(a0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a1 (Method) File=Library/Phalcon/Internal/Test.php Line=242");
}

PHP_METHOD(Phalcon_Internal_Test, a2){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a2", 0);
	phalcon_step_over("Phalcon_Internal_Test::a2 (Assignment) File=Library/Phalcon/Internal/Test.php Line=243");
	//$a
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a2 (Assignment) File=Library/Phalcon/Internal/Test.php Line=244");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "well", 1);
	//$a
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
	phalcon_array_update_long(v0, 0, t0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::a2 (Method) File=Library/Phalcon/Internal/Test.php Line=247");
}

PHP_METHOD(Phalcon_Internal_Test, a3){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a3", 0);
	phalcon_step_over("Phalcon_Internal_Test::a3 (Assignment) File=Library/Phalcon/Internal/Test.php Line=248");
	//$a
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a3 (Assignment) File=Library/Phalcon/Internal/Test.php Line=249");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "LOL", 1);
	//$a
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
	phalcon_array_update_long(v0, 0, t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a3 (Assignment) File=Library/Phalcon/Internal/Test.php Line=250");
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 0);
	//$a
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
	phalcon_array_update_string(v0, "LOL", strlen("LOL"), t1 TSRMLS_CC);
	//$a
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_string(r0, v0, "LOL", strlen("LOL"), PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::a3 (Method) File=Library/Phalcon/Internal/Test.php Line=254");
}

PHP_METHOD(Phalcon_Internal_Test, a4){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a4", 0);
	phalcon_step_over("Phalcon_Internal_Test::a4 (Assignment) File=Library/Phalcon/Internal/Test.php Line=255");
	//$b
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$b", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a4 (Assignment) File=Library/Phalcon/Internal/Test.php Line=256");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	//$b
	if (Z_TYPE_P(v0) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_array_fetch_long(t1, v0, 1, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t1) != IS_ARRAY) {
		convert_to_array(t1);
		phalcon_array_update_long(v0, 1, t1 TSRMLS_CC);
		Z_ADDREF_P(t1);
	}
	if (Z_TYPE_P(t1) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_array_fetch_string(t2, t1, "LOL", strlen("LOL"), PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t2) != IS_ARRAY) {
		convert_to_array(t2);
		phalcon_array_update_string(t1, "LOL", strlen("LOL"), t2 TSRMLS_CC);
		Z_ADDREF_P(t2);
	}
	if (Z_TYPE_P(t2) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_array_fetch_long(t3, t2, 5, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t3) != IS_ARRAY) {
		convert_to_array(t3);
		phalcon_array_update_long(t2, 5, t3 TSRMLS_CC);
		Z_ADDREF_P(t3);
	}
	phalcon_array_update_string(t3, "YEAH", strlen("YEAH"), t0 TSRMLS_CC);
	//$b
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_long(r0, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_array_fetch_string(r1, r0, "LOL", strlen("LOL"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r2);
	phalcon_array_fetch_long(r2, r1, 5, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r3);
	phalcon_array_fetch_string(r3, r2, "YEAH", strlen("YEAH"), PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(r3) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(r3);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(r3);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a4 (Method) File=Library/Phalcon/Internal/Test.php Line=260");
}

PHP_METHOD(Phalcon_Internal_Test, a5){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a5", 0);
	phalcon_step_over("Phalcon_Internal_Test::a5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=262");
	//$a
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=263");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "LOL", 1);
	//$a
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
	phalcon_array_update_long(v0, 0, t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=264");
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 0);
	//$a
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
	phalcon_array_update_string(v0, "LOL", strlen("LOL"), t1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=266");
	//$b
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(a1);
	v1 = a1;
	phalcon_debug_assign("$b", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=267");
	PHALCON_ALLOC_ZVAL(t2);
	ZVAL_STRING(t2, "LOL", 1);
	//$b
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
	phalcon_array_update_string(v1, "LOL", strlen("LOL"), t2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=268");
	PHALCON_ALLOC_ZVAL(t3);
	ZVAL_LONG(t3, 0);
	//$b
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
	phalcon_array_update_long(v1, 0, t3 TSRMLS_CC);
	//$b
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_long(r0, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	//$a
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_array_fetch_string(r1, v0, "LOL", strlen("LOL"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r2);
	add_function(r2, r0, r1 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a5 (Method) File=Library/Phalcon/Internal/Test.php Line=273");
}

PHP_METHOD(Phalcon_Internal_Test, a6){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a6", 0);
	phalcon_step_over("Phalcon_Internal_Test::a6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=275");
	//$a
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=276");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "LOL", 1);
	//$a
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
	phalcon_array_update_long(v0, 0, t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=277");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	//$a
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
	phalcon_array_update_long(v0, 1, a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=278");
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	//$a
	if (Z_TYPE_P(v0) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_array_fetch_long(t2, v0, 1, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t2) != IS_ARRAY) {
		convert_to_array(t2);
		phalcon_array_update_long(v0, 1, t2 TSRMLS_CC);
		Z_ADDREF_P(t2);
	}
	phalcon_array_update_string(t2, "LOL", strlen("LOL"), t1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=279");
	PHALCON_ALLOC_ZVAL(t3);
	ZVAL_LONG(t3, 0);
	//$a
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
	phalcon_array_update_string(v0, "LOL", strlen("LOL"), t3 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=281");
	//$b
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(a2);
	v1 = a2;
	phalcon_debug_assign("$b", a2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=282");
	PHALCON_ALLOC_ZVAL(t4);
	ZVAL_STRING(t4, "LOL", 1);
	//$b
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
	phalcon_array_update_string(v1, "LOL", strlen("LOL"), t4 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=283");
	PHALCON_ALLOC_ZVAL(t5);
	ZVAL_LONG(t5, 0);
	//$b
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
	phalcon_array_update_long(v1, 0, t5 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=284");
	PHALCON_ALLOC_ZVAL(t6);
	ZVAL_LONG(t6, 1);
	//$b
	if (Z_TYPE_P(v1) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t7);
		phalcon_array_fetch_long(t7, v1, 1, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t7) != IS_ARRAY) {
		convert_to_array(t7);
		phalcon_array_update_long(v1, 1, t7 TSRMLS_CC);
		Z_ADDREF_P(t7);
	}
	phalcon_array_update_string(t7, "LOL", strlen("LOL"), t6 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=286");
	//$c
	PHALCON_ALLOC_ZVAL(a3);
	array_init(a3);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(a3);
	v2 = a3;
	phalcon_debug_assign("$c", a3 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=287");
	PHALCON_ALLOC_ZVAL(a4);
	array_init(a4);
	//$c
	{
		zval *orig_ptr = v2;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(v2);
			*v2 = *orig_ptr;
			zval_copy_ctor(v2);
			Z_SET_REFCOUNT_P(v2, 1);
			Z_UNSET_ISREF_P(v2);
		}
	}
	phalcon_array_update_long(v2, 0, a4 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=288");
	PHALCON_ALLOC_ZVAL(a5);
	array_init(a5);
	//$c
	if (Z_TYPE_P(v2) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t8);
		phalcon_array_fetch_long(t8, v2, 0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t8) != IS_ARRAY) {
		convert_to_array(t8);
		phalcon_array_update_long(v2, 0, t8 TSRMLS_CC);
		Z_ADDREF_P(t8);
	}
	phalcon_array_update_long(t8, 0, a5 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=289");
	PHALCON_ALLOC_ZVAL(a6);
	array_init(a6);
	//$c
	if (Z_TYPE_P(v2) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t9);
		phalcon_array_fetch_long(t9, v2, 0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t9) != IS_ARRAY) {
		convert_to_array(t9);
		phalcon_array_update_long(v2, 0, t9 TSRMLS_CC);
		Z_ADDREF_P(t9);
	}
	if (Z_TYPE_P(t9) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t10);
		phalcon_array_fetch_long(t10, t9, 0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t10) != IS_ARRAY) {
		convert_to_array(t10);
		phalcon_array_update_long(t9, 0, t10 TSRMLS_CC);
		Z_ADDREF_P(t10);
	}
	phalcon_array_update_long(t10, 0, a6 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=290");
	PHALCON_ALLOC_ZVAL(t11);
	ZVAL_LONG(t11, 1);
	//$c
	if (Z_TYPE_P(v2) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t12);
		phalcon_array_fetch_long(t12, v2, 0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t12) != IS_ARRAY) {
		convert_to_array(t12);
		phalcon_array_update_long(v2, 0, t12 TSRMLS_CC);
		Z_ADDREF_P(t12);
	}
	if (Z_TYPE_P(t12) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t13);
		phalcon_array_fetch_long(t13, t12, 0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t13) != IS_ARRAY) {
		convert_to_array(t13);
		phalcon_array_update_long(t12, 0, t13 TSRMLS_CC);
		Z_ADDREF_P(t13);
	}
	if (Z_TYPE_P(t13) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t14);
		phalcon_array_fetch_long(t14, t13, 0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t14) != IS_ARRAY) {
		convert_to_array(t14);
		phalcon_array_update_long(t13, 0, t14 TSRMLS_CC);
		Z_ADDREF_P(t14);
	}
	phalcon_array_update_string(t14, "LOL", strlen("LOL"), t11 TSRMLS_CC);
	//$b
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_long(r0, v1, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_array_fetch_string(r1, r0, "LOL", strlen("LOL"), PHALCON_NOISY_FETCH TSRMLS_CC);
	//$a
	PHALCON_ALLOC_ZVAL(r2);
	phalcon_array_fetch_long(r2, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r3);
	phalcon_array_fetch_string(r3, r2, "LOL", strlen("LOL"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r4);
	mul_function(r4, r1, r3 TSRMLS_CC);
	//$c
	PHALCON_ALLOC_ZVAL(r5);
	phalcon_array_fetch_long(r5, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r6);
	phalcon_array_fetch_long(r6, r5, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r7);
	phalcon_array_fetch_long(r7, r6, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r8);
	phalcon_array_fetch_string(r8, r7, "LOL", strlen("LOL"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r9);
	mul_function(r9, r4, r8 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r9 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r9);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a6 (Method) File=Library/Phalcon/Internal/Test.php Line=295");
}

PHP_METHOD(Phalcon_Internal_Test, a10){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a10", 0);
	phalcon_step_over("Phalcon_Internal_Test::a10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=296");
	//$e
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_assoc_long(a0, "hello1", 1);
	add_assoc_long(a0, "hello2", 2);
	add_assoc_long(a0, "hello3", 3);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$e", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a10 (Foreach) File=Library/Phalcon/Internal/Test.php Line=297");
	//$e
	//$v
	//$k
	FOREACH_KV(v0, ac0, fes18, fee18, ah0, hp0, v2, v1)
		phalcon_step_over("Phalcon_Internal_Test::a10 (Block) File=Library/Phalcon/Internal/Test.php Line=297");
		phalcon_step_over("Phalcon_Internal_Test::a10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=298");
		//$k
		//$e
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
		phalcon_array_fetch(r0, v0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!t0) {
			PHALCON_ALLOC_ZVAL(t0);
		} else {
			if (Z_REFCOUNT_P(t0) > 1) {
				SEPARATE_ZVAL(&t0);
			} else {
				if (Z_TYPE_P(t0) != IS_LONG) {
					FREE_ZVAL(t0);
					PHALCON_ALLOC_ZVAL(t0);
				}
			}
		}
		ZVAL_LONG(t0, 100);
		if (!r1) {
			PHALCON_ALLOC_ZVAL(r1);
		} else {
			if (Z_REFCOUNT_P(r1) > 1){ 
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
			}
		}
		add_function(r1, r0, t0 TSRMLS_CC);
		//$e
		//$k
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
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
			phalcon_array_update(v0, v2, copy TSRMLS_CC);
		}
	END_FOREACH(ac0, fes18, fee18, ah0, hp0);
	//$e
	phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a10 (Method) File=Library/Phalcon/Internal/Test.php Line=303");
}

PHP_METHOD(Phalcon_Internal_Test, a11){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a11", 0);
	phalcon_step_over("Phalcon_Internal_Test::a11 (Assignment) File=Library/Phalcon/Internal/Test.php Line=304");
	//$e
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	add_next_index_long(a0, 4);
	add_next_index_long(a0, 5);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$e", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a11 (Foreach) File=Library/Phalcon/Internal/Test.php Line=305");
	//$e
	//$v
	//$k
	FOREACH_KV(v0, ac0, fes19, fee19, ah0, hp0, v2, v1)
		phalcon_step_over("Phalcon_Internal_Test::a11 (Block) File=Library/Phalcon/Internal/Test.php Line=305");
		phalcon_step_over("Phalcon_Internal_Test::a11 (Assignment) File=Library/Phalcon/Internal/Test.php Line=306");
		//$k
		//$e
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
		phalcon_array_fetch(r0, v0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
		//$e
		//$k
		if (!t0) {
			PHALCON_ALLOC_ZVAL(t0);
		} else {
			if (Z_REFCOUNT_P(t0) > 1) {
				SEPARATE_ZVAL(&t0);
			} else {
				if (Z_TYPE_P(t0) != IS_LONG) {
					FREE_ZVAL(t0);
					PHALCON_ALLOC_ZVAL(t0);
				}
			}
		}
		ZVAL_LONG(t0, 10);
		if (!r1) {
			PHALCON_ALLOC_ZVAL(r1);
		} else {
			if (Z_REFCOUNT_P(r1) > 1){ 
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
			}
		}
		add_function(r1, v2, t0 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
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
			phalcon_array_update(v0, r1, copy TSRMLS_CC);
		}
	END_FOREACH(ac0, fes19, fee19, ah0, hp0);
	//$e
	phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a11 (Method) File=Library/Phalcon/Internal/Test.php Line=311");
}

PHP_METHOD(Phalcon_Internal_Test, a12){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a12", 0);
	phalcon_step_over("Phalcon_Internal_Test::a12 (Assignment) File=Library/Phalcon/Internal/Test.php Line=312");
	//$k
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 0);
	phalcon_step_over("Phalcon_Internal_Test::a12 (Assignment) File=Library/Phalcon/Internal/Test.php Line=313");
	//$e
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	add_next_index_long(a0, 4);
	add_next_index_long(a0, 5);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(a0);
	v1 = a0;
	phalcon_debug_assign("$e", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a12 (Foreach) File=Library/Phalcon/Internal/Test.php Line=314");
	//$e
	//$v
	FOREACH_V(v1, ac0, fes20, fee20, ah0, hp0, v2)
		phalcon_step_over("Phalcon_Internal_Test::a12 (Block) File=Library/Phalcon/Internal/Test.php Line=314");
		phalcon_step_over("Phalcon_Internal_Test::a12 (Assignment) File=Library/Phalcon/Internal/Test.php Line=315");
		//$k
		//$e
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
		phalcon_array_fetch(r0, v1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		//$e
		//$k
		if (!t0) {
			PHALCON_ALLOC_ZVAL(t0);
		} else {
			if (Z_REFCOUNT_P(t0) > 1) {
				SEPARATE_ZVAL(&t0);
			} else {
				if (Z_TYPE_P(t0) != IS_LONG) {
					FREE_ZVAL(t0);
					PHALCON_ALLOC_ZVAL(t0);
				}
			}
		}
		ZVAL_LONG(t0, 10);
		if (!r1) {
			PHALCON_ALLOC_ZVAL(r1);
		} else {
			if (Z_REFCOUNT_P(r1) > 1){ 
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
			}
		}
		add_function(r1, v0, t0 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
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
			phalcon_array_update(v1, r1, copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Internal_Test::a12 (PostIncDecOp) File=Library/Phalcon/Internal/Test.php Line=316");
		//$k
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
		phalcon_debug_vdump("PostIncrementing $k", v0);
	END_FOREACH(ac0, fes20, fee20, ah0, hp0);
	//$e
	phalcon_debug_vdump("Returning > ", v1 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v1);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a12 (Method) File=Library/Phalcon/Internal/Test.php Line=321");
}

PHP_METHOD(Phalcon_Internal_Test, a13){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *ac0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a13", 0);
	phalcon_step_over("Phalcon_Internal_Test::a13 (Assignment) File=Library/Phalcon/Internal/Test.php Line=322");
	//$f
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$f", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a13 (Assignment) File=Library/Phalcon/Internal/Test.php Line=323");
	//$e
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	add_next_index_long(a1, 4);
	add_next_index_long(a1, 5);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(a1);
	v1 = a1;
	phalcon_debug_assign("$e", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a13 (Foreach) File=Library/Phalcon/Internal/Test.php Line=324");
	//$e
	//$v
	FOREACH_V(v1, ac0, fes21, fee21, ah0, hp0, v2)
		phalcon_step_over("Phalcon_Internal_Test::a13 (Block) File=Library/Phalcon/Internal/Test.php Line=324");
		phalcon_step_over("Phalcon_Internal_Test::a13 (Assignment) File=Library/Phalcon/Internal/Test.php Line=325");
		//$v
		//$f
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
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
			phalcon_array_append(v0, copy TSRMLS_CC);
		}
	END_FOREACH(ac0, fes21, fee21, ah0, hp0);
	//$f
	phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a13 (Method) File=Library/Phalcon/Internal/Test.php Line=330");
}

PHP_METHOD(Phalcon_Internal_Test, a14){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *ac0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a14", 0);
	phalcon_step_over("Phalcon_Internal_Test::a14 (Assignment) File=Library/Phalcon/Internal/Test.php Line=331");
	//$f
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$f", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a14 (Assignment) File=Library/Phalcon/Internal/Test.php Line=332");
	//$e
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	add_next_index_long(a1, 4);
	add_next_index_long(a1, 5);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(a1);
	v1 = a1;
	phalcon_debug_assign("$e", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a14 (Foreach) File=Library/Phalcon/Internal/Test.php Line=333");
	//$e
	//$v
	//$k
	FOREACH_KV(v1, ac0, fes22, fee22, ah0, hp0, v3, v2)
		phalcon_step_over("Phalcon_Internal_Test::a14 (Block) File=Library/Phalcon/Internal/Test.php Line=333");
		phalcon_step_over("Phalcon_Internal_Test::a14 (Assignment) File=Library/Phalcon/Internal/Test.php Line=334");
		//$k
		//$k
		if (!t0) {
			PHALCON_ALLOC_ZVAL(t0);
		} else {
			if (Z_REFCOUNT_P(t0) > 1) {
				SEPARATE_ZVAL(&t0);
			} else {
				if (Z_TYPE_P(t0) != IS_LONG) {
					FREE_ZVAL(t0);
					PHALCON_ALLOC_ZVAL(t0);
				}
			}
		}
		ZVAL_LONG(t0, 2);
		if (!r0) {
			PHALCON_ALLOC_ZVAL(r0);
		} else {
			if (Z_REFCOUNT_P(r0) > 1){ 
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
			}
		}
		mul_function(r0, v3, t0 TSRMLS_CC);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r0);
		v3 = r0;
		phalcon_debug_assign("$k", r0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Internal_Test::a14 (Assignment) File=Library/Phalcon/Internal/Test.php Line=335");
		//$v
		//$k
		if (!r1) {
			PHALCON_ALLOC_ZVAL(r1);
		} else {
			if (Z_REFCOUNT_P(r1) > 1){ 
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
			}
		}
		add_function(r1, v2, v3 TSRMLS_CC);
		//$f
		//$k
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
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
			phalcon_array_update(v0, v3, copy TSRMLS_CC);
		}
	END_FOREACH(ac0, fes22, fee22, ah0, hp0);
	//$f
	phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a14 (Method) File=Library/Phalcon/Internal/Test.php Line=340");
}

PHP_METHOD(Phalcon_Internal_Test, a15){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a15", 0);
	phalcon_step_over("Phalcon_Internal_Test::a15 (Assignment) File=Library/Phalcon/Internal/Test.php Line=341");
	//$f
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$f", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a15 (Assignment) File=Library/Phalcon/Internal/Test.php Line=342");
	//$e
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	add_next_index_long(a1, 4);
	add_next_index_long(a1, 5);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(a1);
	v1 = a1;
	phalcon_debug_assign("$e", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a15 (Foreach) File=Library/Phalcon/Internal/Test.php Line=343");
	//$e
	//$v
	//$k
	FOREACH_KV(v1, ac0, fes23, fee23, ah0, hp0, v3, v2)
		phalcon_step_over("Phalcon_Internal_Test::a15 (Block) File=Library/Phalcon/Internal/Test.php Line=343");
		phalcon_step_over("Phalcon_Internal_Test::a15 (Assignment) File=Library/Phalcon/Internal/Test.php Line=344");
		//$k
		//$e
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
		phalcon_array_fetch(r0, v1, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
		//$f
		//$k
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
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
			phalcon_array_update(v0, v3, copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Internal_Test::a15 (Assignment) File=Library/Phalcon/Internal/Test.php Line=345");
		//$k
		if (!t0) {
			PHALCON_ALLOC_ZVAL(t0);
		} else {
			if (Z_REFCOUNT_P(t0) > 1) {
				SEPARATE_ZVAL(&t0);
			} else {
				if (Z_TYPE_P(t0) != IS_LONG) {
					FREE_ZVAL(t0);
					PHALCON_ALLOC_ZVAL(t0);
				}
			}
		}
		ZVAL_LONG(t0, 100);
		if (!r1) {
			PHALCON_ALLOC_ZVAL(r1);
		} else {
			if (Z_REFCOUNT_P(r1) > 1){ 
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
			}
		}
		mul_function(r1, v3, t0 TSRMLS_CC);
		//$e
		//$k
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
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
			phalcon_array_update(v1, v3, copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Internal_Test::a15 (Assignment) File=Library/Phalcon/Internal/Test.php Line=346");
		//$k
		//$f
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
		phalcon_array_fetch(r2, v0, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!t1) {
			PHALCON_ALLOC_ZVAL(t1);
		} else {
			if (Z_REFCOUNT_P(t1) > 1) {
				SEPARATE_ZVAL(&t1);
			} else {
				if (Z_TYPE_P(t1) != IS_LONG) {
					FREE_ZVAL(t1);
					PHALCON_ALLOC_ZVAL(t1);
				}
			}
		}
		ZVAL_LONG(t1, 50);
		if (!r3) {
			PHALCON_ALLOC_ZVAL(r3);
		} else {
			if (Z_REFCOUNT_P(r3) > 1){ 
				{
					zval *orig_ptr = r3;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r3);
						*r3 = *orig_ptr;
						zval_copy_ctor(r3);
						Z_SET_REFCOUNT_P(r3, 1);
						Z_UNSET_ISREF_P(r3);
					}
				}
			}
		}
		mul_function(r3, r2, t1 TSRMLS_CC);
		//$f
		//$k
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r3, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
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
			phalcon_array_update(v0, v3, copy TSRMLS_CC);
		}
	END_FOREACH(ac0, fes23, fee23, ah0, hp0);
	//$f
	phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a15 (Method) File=Library/Phalcon/Internal/Test.php Line=351");
}

PHP_METHOD(Phalcon_Internal_Test, a16){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *t0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a16", 0);
	phalcon_step_over("Phalcon_Internal_Test::a16 (Assignment) File=Library/Phalcon/Internal/Test.php Line=352");
	//$f
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$f", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a16 (Assignment) File=Library/Phalcon/Internal/Test.php Line=353");
	//$e
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	add_assoc_string(a2, "in", "out", 1);
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
	add_assoc_zval(a1, "hello", a2);
	PHALCON_ALLOC_ZVAL(a3);
	array_init(a3);
	add_assoc_string(a3, "file", "type", 1);
	add_assoc_string(a3, "php", "unix", 1);
	add_assoc_string(a3, "tab", "ins", 1);
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
	add_assoc_zval(a1, "bye", a3);
	PHALCON_ALLOC_ZVAL(a4);
	array_init(a4);
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
	add_assoc_zval(a1, "encoding", a4);
	add_assoc_string(a1, "sucks", "yes", 1);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(a1);
	v1 = a1;
	phalcon_debug_assign("$e", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a16 (Foreach) File=Library/Phalcon/Internal/Test.php Line=367");
	//$e
	//$v
	//$k
	FOREACH_KV(v1, ac0, fes24, fee24, ah0, hp0, v3, v2)
		phalcon_step_over("Phalcon_Internal_Test::a16 (Block) File=Library/Phalcon/Internal/Test.php Line=367");
		phalcon_step_over("Phalcon_Internal_Test::a16 (If) File=Library/Phalcon/Internal/Test.php Line=368");
		//$v
		if (Z_TYPE_P(v2) == IS_ARRAY) { 
			phalcon_step_over("Phalcon_Internal_Test::a16 (Block) File=Library/Phalcon/Internal/Test.php Line=368");
			phalcon_step_over("Phalcon_Internal_Test::a16 (Foreach) File=Library/Phalcon/Internal/Test.php Line=369");
			//$v
			//$sv
			//$sk
			FOREACH_KV(v2, ac1, fes25, fee25, ah1, hp1, v5, v4)
				phalcon_step_over("Phalcon_Internal_Test::a16 (Block) File=Library/Phalcon/Internal/Test.php Line=369");
				phalcon_step_over("Phalcon_Internal_Test::a16 (Assignment) File=Library/Phalcon/Internal/Test.php Line=370");
				//$sv
				//$f
				//$k
				if (Z_TYPE_P(v0) == IS_ARRAY) {
					if (!t0) {
						PHALCON_ALLOC_ZVAL(t0);
					} else {
						if (Z_REFCOUNT_P(t0) > 1) {
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
						} else {
							FREE_ZVAL(t0);
							PHALCON_ALLOC_ZVAL(t0);
						}
					}
					phalcon_array_fetch(t0, v0, v3, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_TYPE_P(t0) != IS_ARRAY) {
					convert_to_array(t0);
					phalcon_array_update(v0, v3, t0 TSRMLS_CC);
					Z_ADDREF_P(t0);
				}
				//$sk
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v4, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_array_update(t0, v5, copy TSRMLS_CC);
				}
			END_FOREACH(ac1, fes25, fee25, ah1, hp1);
		} else {
			phalcon_step_over("Phalcon_Internal_Test::a16 (Block) File=Library/Phalcon/Internal/Test.php Line=372");
			phalcon_step_over("Phalcon_Internal_Test::a16 (Assignment) File=Library/Phalcon/Internal/Test.php Line=373");
			//$v
			//$f
			//$k
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
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
				phalcon_array_update(v0, v3, copy TSRMLS_CC);
			}
		}
	END_FOREACH(ac0, fes24, fee24, ah0, hp0);
	//$f
	phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a16 (Method) File=Library/Phalcon/Internal/Test.php Line=379");
}

PHP_METHOD(Phalcon_Internal_Test, a17){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a17", 0);
	phalcon_step_over("Phalcon_Internal_Test::a17 (Assignment) File=Library/Phalcon/Internal/Test.php Line=380");
	//$w
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$w", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a17 (Assignment) File=Library/Phalcon/Internal/Test.php Line=381");
	//$a
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_assoc_long(a1, "7", 0);
	add_assoc_long(a1, "8", 1);
	add_assoc_long(a1, "9", 2);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(a1);
	v1 = a1;
	phalcon_debug_assign("$a", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a17 (Assignment) File=Library/Phalcon/Internal/Test.php Line=386");
	//$b
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	PHALCON_ALLOC_ZVAL(a3);
	array_init(a3);
	add_next_index_string(a3, "hello1", 1);
	{
		zval *orig_ptr = a2;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(a2);
			*a2 = *orig_ptr;
			zval_copy_ctor(a2);
			Z_SET_REFCOUNT_P(a2, 1);
			Z_UNSET_ISREF_P(a2);
		}
	}
	add_next_index_zval(a2, a3);
	PHALCON_ALLOC_ZVAL(a4);
	array_init(a4);
	add_next_index_string(a4, "hello2", 1);
	{
		zval *orig_ptr = a2;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(a2);
			*a2 = *orig_ptr;
			zval_copy_ctor(a2);
			Z_SET_REFCOUNT_P(a2, 1);
			Z_UNSET_ISREF_P(a2);
		}
	}
	add_assoc_zval(a2, "1", a4);
	PHALCON_ALLOC_ZVAL(a5);
	array_init(a5);
	add_next_index_string(a5, "hello3", 1);
	{
		zval *orig_ptr = a2;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(a2);
			*a2 = *orig_ptr;
			zval_copy_ctor(a2);
			Z_SET_REFCOUNT_P(a2, 1);
			Z_UNSET_ISREF_P(a2);
		}
	}
	add_assoc_zval(a2, "2", a5);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(a2);
	v2 = a2;
	phalcon_debug_assign("$b", a2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a17 (Foreach) File=Library/Phalcon/Internal/Test.php Line=397");
	//$a
	//$v
	//$k
	FOREACH_KV(v1, ac0, fes26, fee26, ah0, hp0, v4, v3)
		phalcon_step_over("Phalcon_Internal_Test::a17 (Block) File=Library/Phalcon/Internal/Test.php Line=397");
		phalcon_step_over("Phalcon_Internal_Test::a17 (Assignment) File=Library/Phalcon/Internal/Test.php Line=398");
		//$v
		//$b
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
		phalcon_array_fetch(r0, v2, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
		//$w
		//$k
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
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
			phalcon_array_update(v0, v4, copy TSRMLS_CC);
		}
	END_FOREACH(ac0, fes26, fee26, ah0, hp0);
	//$w
	phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a17 (Method) File=Library/Phalcon/Internal/Test.php Line=403");
}

PHP_METHOD(Phalcon_Internal_Test, a18){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a18", 0);
	phalcon_step_over("Phalcon_Internal_Test::a18 (Assignment) File=Library/Phalcon/Internal/Test.php Line=404");
	//$a
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_string(a0, "hello1", 1);
	add_next_index_string(a0, "hello2", 1);
	add_next_index_string(a0, "hello3", 1);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a18 (Assignment) File=Library/Phalcon/Internal/Test.php Line=405");
	//$c
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	//$a
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
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
		add_next_index_zval(a1, copy);
	}
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(a1);
	v1 = a1;
	phalcon_debug_assign("$c", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a18 (Assignment) File=Library/Phalcon/Internal/Test.php Line=406");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "see", 1);
	//$c
	if (Z_TYPE_P(v1) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_array_fetch_long(t1, v1, 0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t1) != IS_ARRAY) {
		convert_to_array(t1);
		phalcon_array_update_long(v1, 0, t1 TSRMLS_CC);
		Z_ADDREF_P(t1);
	}
	phalcon_array_update_long(t1, 0, t0 TSRMLS_CC);
	//$a
	phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a18 (Method) File=Library/Phalcon/Internal/Test.php Line=410");
}

PHP_METHOD(Phalcon_Internal_Test, a19){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a19", 0);
	phalcon_step_over("Phalcon_Internal_Test::a19 (Assignment) File=Library/Phalcon/Internal/Test.php Line=411");
	//$a
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_string(a0, "hello1", 1);
	add_next_index_string(a0, "hello2", 1);
	add_next_index_string(a0, "hello3", 1);
	PHALCON_INIT_FALSE(t0);
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
	add_next_index_zval(a0, t0);
	PHALCON_INIT_NULL(t1);
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
	add_next_index_double(a0, 1.34);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a19 (Assignment) File=Library/Phalcon/Internal/Test.php Line=412");
	//$b
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_next_index_string(a1, "lol1", 1);
	add_next_index_string(a1, "lol2", 1);
	add_next_index_string(a1, "lol3", 1);
	add_next_index_string(a1, "lol4", 1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(a1);
	v1 = a1;
	phalcon_debug_assign("$b", a1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::a19 (Method) File=Library/Phalcon/Internal/Test.php Line=416");
}

PHP_METHOD(Phalcon_Internal_Test, a20){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a20", 0);
	phalcon_step_over("Phalcon_Internal_Test::a20 (Assignment) File=Library/Phalcon/Internal/Test.php Line=417");
	//$b
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_DOUBLE(v0, 3.45);
	phalcon_step_over("Phalcon_Internal_Test::a20 (Assignment) File=Library/Phalcon/Internal/Test.php Line=418");
	//$c
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_STRING(v1, "6.28", 0);
	phalcon_step_over("Phalcon_Internal_Test::a20 (Assignment) File=Library/Phalcon/Internal/Test.php Line=419");
	//$a
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(a0);
	v2 = a0;
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a20 (Assignment) File=Library/Phalcon/Internal/Test.php Line=420");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "whtzup!", 1);
	//$a
	//$b
	{
		zval *orig_ptr = v2;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(v2);
			*v2 = *orig_ptr;
			zval_copy_ctor(v2);
			Z_SET_REFCOUNT_P(v2, 1);
			Z_UNSET_ISREF_P(v2);
		}
	}
	phalcon_array_update(v2, v0, t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a20 (Assignment) File=Library/Phalcon/Internal/Test.php Line=421");
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_STRING(t1, "morelol", 1);
	//$a
	//$c
	{
		zval *orig_ptr = v2;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(v2);
			*v2 = *orig_ptr;
			zval_copy_ctor(v2);
			Z_SET_REFCOUNT_P(v2, 1);
			Z_UNSET_ISREF_P(v2);
		}
	}
	phalcon_array_update(v2, v1, t1 TSRMLS_CC);
	//$a
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a20 (Method) File=Library/Phalcon/Internal/Test.php Line=425");
}

PHP_METHOD(Phalcon_Internal_Test, a21){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *a0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a21", 0);
	phalcon_step_over("Phalcon_Internal_Test::a21 (Assignment) File=Library/Phalcon/Internal/Test.php Line=426");
	//$b
	PHALCON_INIT_NULL(v0);
	phalcon_step_over("Phalcon_Internal_Test::a21 (Assignment) File=Library/Phalcon/Internal/Test.php Line=427");
	//$c
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_BOOL(v1, 0);
	phalcon_step_over("Phalcon_Internal_Test::a21 (Assignment) File=Library/Phalcon/Internal/Test.php Line=428");
	//$d
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_BOOL(v2, 1);
	phalcon_step_over("Phalcon_Internal_Test::a21 (Assignment) File=Library/Phalcon/Internal/Test.php Line=429");
	//$e
	PHALCON_ALLOC_ZVAL(v3);
	ZVAL_LONG(v3, 100);
	phalcon_step_over("Phalcon_Internal_Test::a21 (Assignment) File=Library/Phalcon/Internal/Test.php Line=430");
	//$f
	PHALCON_ALLOC_ZVAL(v4);
	ZVAL_DOUBLE(v4, 3.45);
	phalcon_step_over("Phalcon_Internal_Test::a21 (Assignment) File=Library/Phalcon/Internal/Test.php Line=431");
	//$g
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 100);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, -1);
	PHALCON_MUL_FUNCTION(r0, t0, t1);
	if (v5) {
		Z_DELREF_P(v5);
		if (!Z_REFCOUNT_P(v5)) {
			FREE_ZVAL(v5);
		}
	}
	Z_ADDREF_P(r0);
	v5 = r0;
	phalcon_debug_assign("$g", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a21 (Assignment) File=Library/Phalcon/Internal/Test.php Line=432");
	//$h
	PHALCON_ALLOC_ZVAL(v6);
	ZVAL_STRING(v6, "6.28", 0);
	phalcon_step_over("Phalcon_Internal_Test::a21 (Assignment) File=Library/Phalcon/Internal/Test.php Line=433");
	//$a
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v7) {
		Z_DELREF_P(v7);
		if (!Z_REFCOUNT_P(v7)) {
			FREE_ZVAL(v7);
		}
	}
	Z_ADDREF_P(a0);
	v7 = a0;
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a21 (Assignment) File=Library/Phalcon/Internal/Test.php Line=434");
	PHALCON_ALLOC_ZVAL(t2);
	ZVAL_STRING(t2, "whtzup!", 1);
	//$a
	//$b
	if (Z_TYPE_P(v7) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_array_fetch(t3, v7, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t3) != IS_ARRAY) {
		convert_to_array(t3);
		phalcon_array_update(v7, v0, t3 TSRMLS_CC);
		Z_ADDREF_P(t3);
	}
	//$c
	if (Z_TYPE_P(t3) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t4);
		phalcon_array_fetch(t4, t3, v1, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t4) != IS_ARRAY) {
		convert_to_array(t4);
		phalcon_array_update(t3, v1, t4 TSRMLS_CC);
		Z_ADDREF_P(t4);
	}
	//$d
	if (Z_TYPE_P(t4) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t5);
		phalcon_array_fetch(t5, t4, v2, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t5) != IS_ARRAY) {
		convert_to_array(t5);
		phalcon_array_update(t4, v2, t5 TSRMLS_CC);
		Z_ADDREF_P(t5);
	}
	//$e
	if (Z_TYPE_P(t5) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t6);
		phalcon_array_fetch(t6, t5, v3, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t6) != IS_ARRAY) {
		convert_to_array(t6);
		phalcon_array_update(t5, v3, t6 TSRMLS_CC);
		Z_ADDREF_P(t6);
	}
	//$f
	if (Z_TYPE_P(t6) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t7);
		phalcon_array_fetch(t7, t6, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t7) != IS_ARRAY) {
		convert_to_array(t7);
		phalcon_array_update(t6, v4, t7 TSRMLS_CC);
		Z_ADDREF_P(t7);
	}
	//$g
	if (Z_TYPE_P(t7) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t8);
		phalcon_array_fetch(t8, t7, v5, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t8) != IS_ARRAY) {
		convert_to_array(t8);
		phalcon_array_update(t7, v5, t8 TSRMLS_CC);
		Z_ADDREF_P(t8);
	}
	//$h
	phalcon_array_update(t8, v6, t2 TSRMLS_CC);
	//$a
	phalcon_debug_vdump("Returning > ", v7 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v7);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a21 (Method) File=Library/Phalcon/Internal/Test.php Line=438");
}

PHP_METHOD(Phalcon_Internal_Test, a22){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a22", 0);
	phalcon_step_over("Phalcon_Internal_Test::a22 (Assignment) File=Library/Phalcon/Internal/Test.php Line=439");
	//$a
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_string(a0, "222", 1);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a22 (Assignment) File=Library/Phalcon/Internal/Test.php Line=440");
	//$b
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_next_index_string(a1, "222", 1);
	add_next_index_string(a1, "kdkdk", 1);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(a1);
	v1 = a1;
	phalcon_debug_assign("$b", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a22 (Assignment) File=Library/Phalcon/Internal/Test.php Line=441");
	//$e
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	//$a
	//$b
	PHALCON_ALLOC_ZVAL(r0);
	add_function(r0, v0, v1 TSRMLS_CC);
	{
		zval *orig_ptr = a2;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(a2);
			*a2 = *orig_ptr;
			zval_copy_ctor(a2);
			Z_SET_REFCOUNT_P(a2, 1);
			Z_UNSET_ISREF_P(a2);
		}
	}
	add_next_index_zval(a2, r0);
	//$b
	//$a
	PHALCON_ALLOC_ZVAL(r1);
	add_function(r1, v1, v0 TSRMLS_CC);
	//$a
	PHALCON_ALLOC_ZVAL(r2);
	add_function(r2, r1, v0 TSRMLS_CC);
	{
		zval *orig_ptr = a2;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(a2);
			*a2 = *orig_ptr;
			zval_copy_ctor(a2);
			Z_SET_REFCOUNT_P(a2, 1);
			Z_UNSET_ISREF_P(a2);
		}
	}
	add_next_index_zval(a2, r2);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(a2);
	v2 = a2;
	phalcon_debug_assign("$e", a2 TSRMLS_CC);
	//$e
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a22 (Method) File=Library/Phalcon/Internal/Test.php Line=445");
}

PHP_METHOD(Phalcon_Internal_Test, a23){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL, NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a23", 0);
	phalcon_step_over("Phalcon_Internal_Test::a23 (Assignment) File=Library/Phalcon/Internal/Test.php Line=446");
	//$f
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$f", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a23 (Assignment) File=Library/Phalcon/Internal/Test.php Line=447");
	//$e
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	add_assoc_string(a2, "baseuri", "/phalcon/", 1);
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
	add_assoc_zval(a1, "phalcon", a2);
	PHALCON_ALLOC_ZVAL(a3);
	array_init(a3);
	add_assoc_string(a3, "metadata", "memory", 1);
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
	add_assoc_zval(a1, "models", a3);
	PHALCON_ALLOC_ZVAL(a4);
	array_init(a4);
	add_assoc_string(a4, "adapter", "mysql", 1);
	add_assoc_string(a4, "host", "localhost", 1);
	add_assoc_string(a4, "username", "user", 1);
	add_assoc_string(a4, "password", "passwd", 1);
	add_assoc_string(a4, "name", "demo", 1);
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
	add_assoc_zval(a1, "database", a4);
	PHALCON_ALLOC_ZVAL(a5);
	array_init(a5);
	add_assoc_long(a5, "parent.property", 1);
	add_assoc_string(a5, "parent.property2", "yeah", 1);
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
	add_assoc_zval(a1, "test", a5);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(a1);
	v1 = a1;
	phalcon_debug_assign("$e", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a23 (Foreach) File=Library/Phalcon/Internal/Test.php Line=466");
	//$e
	//$v
	//$k
	FOREACH_KV(v1, ac0, fes27, fee27, ah0, hp0, v3, v2)
		phalcon_step_over("Phalcon_Internal_Test::a23 (Block) File=Library/Phalcon/Internal/Test.php Line=466");
		phalcon_step_over("Phalcon_Internal_Test::a23 (If) File=Library/Phalcon/Internal/Test.php Line=467");
		//$v
		if (Z_TYPE_P(v2) == IS_ARRAY) { 
			phalcon_step_over("Phalcon_Internal_Test::a23 (Block) File=Library/Phalcon/Internal/Test.php Line=467");
			phalcon_step_over("Phalcon_Internal_Test::a23 (Foreach) File=Library/Phalcon/Internal/Test.php Line=468");
			//$v
			//$sv
			//$sk
			FOREACH_KV(v2, ac1, fes28, fee28, ah1, hp1, v5, v4)
				phalcon_step_over("Phalcon_Internal_Test::a23 (Block) File=Library/Phalcon/Internal/Test.php Line=468");
				phalcon_step_over("Phalcon_Internal_Test::a23 (Assignment) File=Library/Phalcon/Internal/Test.php Line=469");
				//$sv
				//$f
				//$k
				if (Z_TYPE_P(v0) == IS_ARRAY) {
					if (!t0) {
						PHALCON_ALLOC_ZVAL(t0);
					} else {
						if (Z_REFCOUNT_P(t0) > 1) {
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
						} else {
							FREE_ZVAL(t0);
							PHALCON_ALLOC_ZVAL(t0);
						}
					}
					phalcon_array_fetch(t0, v0, v3, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_TYPE_P(t0) != IS_ARRAY) {
					convert_to_array(t0);
					phalcon_array_update(v0, v3, t0 TSRMLS_CC);
					Z_ADDREF_P(t0);
				}
				//$sk
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v4, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_array_update(t0, v5, copy TSRMLS_CC);
				}
			END_FOREACH(ac1, fes28, fee28, ah1, hp1);
		} else {
			phalcon_step_over("Phalcon_Internal_Test::a23 (Block) File=Library/Phalcon/Internal/Test.php Line=471");
			phalcon_step_over("Phalcon_Internal_Test::a23 (If) File=Library/Phalcon/Internal/Test.php Line=472");
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
			if (!p0[0]) {
				PHALCON_ALLOC_ZVAL(p0[0]);
			} else {
				if (Z_REFCOUNT_P(p0[0]) > 1) {
					SEPARATE_ZVAL(&p0[0]);
				} else {
					if (Z_TYPE_P(p0[0]) != IS_STRING) {
						FREE_ZVAL(p0[0]);
						PHALCON_ALLOC_ZVAL(p0[0]);
					}
				}
			}
			ZVAL_STRING(p0[0], ".", 1);
			//$v
			p0[1] = v2;
			phalcon_debug_param(v2 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r0, "strpos", 2, p0);
			phalcon_debug_vdump("strpos > ", r0 TSRMLS_CC);
			PHALCON_INIT_FALSE(t1);
			PHALCON_NOT_IDENTICAL_FUNCTION(r1, r0, t1);
			if (zend_is_true(r1)) {
				phalcon_step_over("Phalcon_Internal_Test::a23 (Block) File=Library/Phalcon/Internal/Test.php Line=472");
				phalcon_step_over("Phalcon_Internal_Test::a23 (Assignment) File=Library/Phalcon/Internal/Test.php Line=473");
				//$p
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
				if (!p1[0]) {
					PHALCON_ALLOC_ZVAL(p1[0]);
				} else {
					if (Z_REFCOUNT_P(p1[0]) > 1) {
						SEPARATE_ZVAL(&p1[0]);
					} else {
						if (Z_TYPE_P(p1[0]) != IS_STRING) {
							FREE_ZVAL(p1[0]);
							PHALCON_ALLOC_ZVAL(p1[0]);
						}
					}
				}
				ZVAL_STRING(p1[0], ".", 1);
				//$v
				p1[1] = v2;
				phalcon_debug_param(v2 TSRMLS_CC);
				PHALCON_CALL_FUNC_PARAMS(r2, "explode", 2, p1);
				phalcon_debug_vdump("explode > ", r2 TSRMLS_CC);
				if (v6) {
					Z_DELREF_P(v6);
					if (!Z_REFCOUNT_P(v6)) {
						FREE_ZVAL(v6);
					}
				}
				Z_ADDREF_P(r2);
				v6 = r2;
				phalcon_debug_assign("$p", r2 TSRMLS_CC);
				phalcon_step_over("Phalcon_Internal_Test::a23 (Assignment) File=Library/Phalcon/Internal/Test.php Line=474");
				//$p
				if (!r3) {
					PHALCON_ALLOC_ZVAL(r3);
				} else {
					if (Z_REFCOUNT_P(r3) > 1) {
						{
							zval *orig_ptr = r3;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r3);
								*r3 = *orig_ptr;
								zval_copy_ctor(r3);
								Z_SET_REFCOUNT_P(r3, 1);
								Z_UNSET_ISREF_P(r3);
							}
						}
					} else {
						FREE_ZVAL(r3);
						PHALCON_ALLOC_ZVAL(r3);
					}
				}
				phalcon_array_fetch_long(r3, v6, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
				//$f
				//$k
				if (Z_TYPE_P(v0) == IS_ARRAY) {
					if (!t2) {
						PHALCON_ALLOC_ZVAL(t2);
					} else {
						if (Z_REFCOUNT_P(t2) > 1) {
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
						} else {
							FREE_ZVAL(t2);
							PHALCON_ALLOC_ZVAL(t2);
						}
					}
					phalcon_array_fetch(t2, v0, v3, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_TYPE_P(t2) != IS_ARRAY) {
					convert_to_array(t2);
					phalcon_array_update(v0, v3, t2 TSRMLS_CC);
					Z_ADDREF_P(t2);
				}
				//$p
				if (!r4) {
					PHALCON_ALLOC_ZVAL(r4);
				} else {
					if (Z_REFCOUNT_P(r4) > 1) {
						{
							zval *orig_ptr = r4;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r4);
								*r4 = *orig_ptr;
								zval_copy_ctor(r4);
								Z_SET_REFCOUNT_P(r4, 1);
								Z_UNSET_ISREF_P(r4);
							}
						}
					} else {
						FREE_ZVAL(r4);
						PHALCON_ALLOC_ZVAL(r4);
					}
				}
				phalcon_array_fetch_long(r4, v6, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, r3, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_array_update(t2, r4, copy TSRMLS_CC);
				}
			} else {
				phalcon_step_over("Phalcon_Internal_Test::a23 (Block) File=Library/Phalcon/Internal/Test.php Line=475");
				phalcon_step_over("Phalcon_Internal_Test::a23 (Assignment) File=Library/Phalcon/Internal/Test.php Line=476");
				//$v
				//$f
				//$k
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v2, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
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
					phalcon_array_update(v0, v3, copy TSRMLS_CC);
				}
			}
		}
	END_FOREACH(ac0, fes27, fee27, ah0, hp0);
	//$f
	phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a23 (Method) File=Library/Phalcon/Internal/Test.php Line=483");
}

PHP_METHOD(Phalcon_Internal_Test, a24){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "a24", 0);
	phalcon_step_over("Phalcon_Internal_Test::a24 (Assignment) File=Library/Phalcon/Internal/Test.php Line=484");
	//$num
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	//$num
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
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
		add_next_index_zval(a0, copy);
	}
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$num", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a24 (Assignment) File=Library/Phalcon/Internal/Test.php Line=485");
	//$p
	//$num
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_concat_left(r0, "hello, ", v0 TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	phalcon_debug_assign("$p", r0 TSRMLS_CC);
	//$num
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a24 (Method) File=Library/Phalcon/Internal/Test.php Line=490");
}

PHP_METHOD(Phalcon_Internal_Test, sa0){

	zval *a0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sa0", 0);
	phalcon_step_over("Phalcon_Internal_Test::sa0 (Assignment) File=Library/Phalcon/Internal/Test.php Line=491");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::sa0 (Method) File=Library/Phalcon/Internal/Test.php Line=494");
}

PHP_METHOD(Phalcon_Internal_Test, sa1){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sa1", 0);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::sa1 (Method) File=Library/Phalcon/Internal/Test.php Line=498");
}

PHP_METHOD(Phalcon_Internal_Test, sa2){

	zval *a0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sa2", 0);
	phalcon_step_over("Phalcon_Internal_Test::sa2 (Assignment) File=Library/Phalcon/Internal/Test.php Line=499");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	add_next_index_string(a0, "lol", 1);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::sa2 (Method) File=Library/Phalcon/Internal/Test.php Line=502");
}

PHP_METHOD(Phalcon_Internal_Test, sa3){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sa3", 0);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::sa3 (Method) File=Library/Phalcon/Internal/Test.php Line=506");
}

PHP_METHOD(Phalcon_Internal_Test, sa4){

	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sa4", 0);
	phalcon_step_over("Phalcon_Internal_Test::sa4 (Assignment) File=Library/Phalcon/Internal/Test.php Line=507");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sa4 (Assignment) File=Library/Phalcon/Internal/Test.php Line=508");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		convert_to_array(t0);
	}
	phalcon_array_append(t0, a1 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, t0 TSRMLS_CC);
	
	phalcon_step_over("Phalcon_Internal_Test::sa4 (Assignment) File=Library/Phalcon/Internal/Test.php Line=509");
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_STRING(t1, "more-loose", 1);
	t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t2) != IS_ARRAY) {
		convert_to_array(t2);
	}
	if (Z_TYPE_P(t2) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_array_fetch_long(t3, t2, 0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t3) != IS_ARRAY) {
		convert_to_array(t3);
		phalcon_array_update_long(t2, 0, t3 TSRMLS_CC);
		Z_ADDREF_P(t3);
	}
	phalcon_array_append(t3, t1 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, t2 TSRMLS_CC);
	
	phalcon_step_over("Phalcon_Internal_Test::sa4 (Assignment) File=Library/Phalcon/Internal/Test.php Line=510");
	PHALCON_ALLOC_ZVAL(t4);
	ZVAL_STRING(t4, "yeah, more-loose", 1);
	t5 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t5) != IS_ARRAY) {
		convert_to_array(t5);
	}
	if (Z_TYPE_P(t5) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t6);
		phalcon_array_fetch_long(t6, t5, 0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t6) != IS_ARRAY) {
		convert_to_array(t6);
		phalcon_array_update_long(t5, 0, t6 TSRMLS_CC);
		Z_ADDREF_P(t6);
	}
	phalcon_array_update_long(t6, 0, t4 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, t5 TSRMLS_CC);
	
	t7 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t7 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t7) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t7);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t7);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sa4 (Method) File=Library/Phalcon/Internal/Test.php Line=514");
}

PHP_METHOD(Phalcon_Internal_Test, sa5){

	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sa5", 0);
	phalcon_step_over("Phalcon_Internal_Test::sa5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=515");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sa5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=516");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "loose", 1);
	t1 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t1) != IS_ARRAY) {
		convert_to_array(t1);
	}
	if (Z_TYPE_P(t1) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_array_fetch_long(t2, t1, 1, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t2) != IS_ARRAY) {
		convert_to_array(t2);
		phalcon_array_update_long(t1, 1, t2 TSRMLS_CC);
		Z_ADDREF_P(t2);
	}
	if (Z_TYPE_P(t2) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_array_fetch_long(t3, t2, 2, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t3) != IS_ARRAY) {
		convert_to_array(t3);
		phalcon_array_update_long(t2, 2, t3 TSRMLS_CC);
		Z_ADDREF_P(t3);
	}
	phalcon_array_update_long(t3, 3, t0 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, t1 TSRMLS_CC);
	
	t4 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t8);
	ZVAL_LONG(t8, 1);
	PHALCON_ALLOC_ZVAL(t7);
	phalcon_array_fetch(t7, t4, t8, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t9);
	ZVAL_LONG(t9, 2);
	PHALCON_ALLOC_ZVAL(t6);
	phalcon_array_fetch(t6, t7, t9, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t10);
	ZVAL_LONG(t10, 3);
	PHALCON_ALLOC_ZVAL(t5);
	phalcon_array_fetch(t5, t6, t10, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t5 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t5) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t5);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t5);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sa5 (Method) File=Library/Phalcon/Internal/Test.php Line=520");
}

PHP_METHOD(Phalcon_Internal_Test, sa6){

	zval *a0 = NULL, *a1 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *ac0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sa6", 0);
	phalcon_step_over("Phalcon_Internal_Test::sa6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=521");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sa6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=522");
	//$e
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	add_next_index_long(a1, 4);
	add_next_index_long(a1, 5);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a1);
	v0 = a1;
	phalcon_debug_assign("$e", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sa6 (Foreach) File=Library/Phalcon/Internal/Test.php Line=523");
	//$e
	//$v
	//$k
	FOREACH_KV(v0, ac0, fes29, fee29, ah0, hp0, v2, v1)
		phalcon_step_over("Phalcon_Internal_Test::sa6 (Block) File=Library/Phalcon/Internal/Test.php Line=523");
		phalcon_step_over("Phalcon_Internal_Test::sa6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=524");
		//$k
		//$k
		if (!t0) {
			PHALCON_ALLOC_ZVAL(t0);
		} else {
			if (Z_REFCOUNT_P(t0) > 1) {
				SEPARATE_ZVAL(&t0);
			} else {
				if (Z_TYPE_P(t0) != IS_LONG) {
					FREE_ZVAL(t0);
					PHALCON_ALLOC_ZVAL(t0);
				}
			}
		}
		ZVAL_LONG(t0, 2);
		if (!r0) {
			PHALCON_ALLOC_ZVAL(r0);
		} else {
			if (Z_REFCOUNT_P(r0) > 1){ 
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
			}
		}
		mul_function(r0, v2, t0 TSRMLS_CC);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(r0);
		v2 = r0;
		phalcon_debug_assign("$k", r0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Internal_Test::sa6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=525");
		//$v
		//$k
		if (!r1) {
			PHALCON_ALLOC_ZVAL(r1);
		} else {
			if (Z_REFCOUNT_P(r1) > 1){ 
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
			}
		}
		add_function(r1, v1, v2 TSRMLS_CC);
		t1 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (Z_TYPE_P(t1) != IS_ARRAY) {
			convert_to_array(t1);
		}
		//$k
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_array_update(t1, v2, copy TSRMLS_CC);
		}
		zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, t1 TSRMLS_CC);
		
	END_FOREACH(ac0, fes29, fee29, ah0, hp0);
	t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t2) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t2);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t2);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sa6 (Method) File=Library/Phalcon/Internal/Test.php Line=530");
}

PHP_METHOD(Phalcon_Internal_Test, sa7){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sa7", 0);
	phalcon_step_over("Phalcon_Internal_Test::sa7 (Assignment) File=Library/Phalcon/Internal/Test.php Line=531");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sa7 (Assignment) File=Library/Phalcon/Internal/Test.php Line=532");
	//$e
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	add_assoc_string(a2, "in", "out", 1);
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
	add_assoc_zval(a1, "hello", a2);
	PHALCON_ALLOC_ZVAL(a3);
	array_init(a3);
	add_assoc_string(a3, "file", "type", 1);
	add_assoc_string(a3, "php", "unix", 1);
	add_assoc_string(a3, "tab", "ins", 1);
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
	add_assoc_zval(a1, "bye", a3);
	PHALCON_ALLOC_ZVAL(a4);
	array_init(a4);
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
	add_assoc_zval(a1, "encoding", a4);
	add_assoc_string(a1, "sucks", "yes", 1);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a1);
	v0 = a1;
	phalcon_debug_assign("$e", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sa7 (Foreach) File=Library/Phalcon/Internal/Test.php Line=546");
	//$e
	//$v
	//$k
	FOREACH_KV(v0, ac0, fes30, fee30, ah0, hp0, v2, v1)
		phalcon_step_over("Phalcon_Internal_Test::sa7 (Block) File=Library/Phalcon/Internal/Test.php Line=546");
		phalcon_step_over("Phalcon_Internal_Test::sa7 (If) File=Library/Phalcon/Internal/Test.php Line=547");
		//$v
		if (Z_TYPE_P(v1) == IS_ARRAY) { 
			phalcon_step_over("Phalcon_Internal_Test::sa7 (Block) File=Library/Phalcon/Internal/Test.php Line=547");
			phalcon_step_over("Phalcon_Internal_Test::sa7 (Foreach) File=Library/Phalcon/Internal/Test.php Line=548");
			//$v
			//$sv
			//$sk
			FOREACH_KV(v1, ac1, fes31, fee31, ah1, hp1, v4, v3)
				phalcon_step_over("Phalcon_Internal_Test::sa7 (Block) File=Library/Phalcon/Internal/Test.php Line=548");
				phalcon_step_over("Phalcon_Internal_Test::sa7 (Assignment) File=Library/Phalcon/Internal/Test.php Line=549");
				//$sv
				t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
				if (Z_TYPE_P(t0) != IS_ARRAY) {
					convert_to_array(t0);
				}
				//$k
				if (Z_TYPE_P(t0) == IS_ARRAY) {
					if (!t1) {
						PHALCON_ALLOC_ZVAL(t1);
					} else {
						if (Z_REFCOUNT_P(t1) > 1) {
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
						} else {
							FREE_ZVAL(t1);
							PHALCON_ALLOC_ZVAL(t1);
						}
					}
					phalcon_array_fetch(t1, t0, v2, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_TYPE_P(t1) != IS_ARRAY) {
					convert_to_array(t1);
					phalcon_array_update(t0, v2, t1 TSRMLS_CC);
					Z_ADDREF_P(t1);
				}
				//$sk
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v3, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_array_update(t1, v4, copy TSRMLS_CC);
				}
				zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, t0 TSRMLS_CC);
				
			END_FOREACH(ac1, fes31, fee31, ah1, hp1);
		} else {
			phalcon_step_over("Phalcon_Internal_Test::sa7 (Block) File=Library/Phalcon/Internal/Test.php Line=551");
			phalcon_step_over("Phalcon_Internal_Test::sa7 (Assignment) File=Library/Phalcon/Internal/Test.php Line=552");
			//$v
			t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			if (Z_TYPE_P(t2) != IS_ARRAY) {
				convert_to_array(t2);
			}
			//$k
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v1, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_array_update(t2, v2, copy TSRMLS_CC);
			}
			zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, t2 TSRMLS_CC);
			
		}
	END_FOREACH(ac0, fes30, fee30, ah0, hp0);
	t3 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t3 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t3) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t3);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t3);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sa7 (Method) File=Library/Phalcon/Internal/Test.php Line=559");
}

PHP_METHOD(Phalcon_Internal_Test, c1){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c1", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_EQUAL_FUNCTION(r0, t0, t1);
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
	phalcon_step_over("Phalcon_Internal_Test::c1 (Method) File=Library/Phalcon/Internal/Test.php Line=563");
}

PHP_METHOD(Phalcon_Internal_Test, c2){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c2", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
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
	phalcon_step_over("Phalcon_Internal_Test::c2 (Method) File=Library/Phalcon/Internal/Test.php Line=567");
}

PHP_METHOD(Phalcon_Internal_Test, c3){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c3", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_SMALLER_EQUAL_FUNCTION(r0, t0, t1);
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
	phalcon_step_over("Phalcon_Internal_Test::c3 (Method) File=Library/Phalcon/Internal/Test.php Line=571");
}

PHP_METHOD(Phalcon_Internal_Test, c4){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c4", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_SMALLER_EQUAL_FUNCTION(r0, t1, t0);
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
	phalcon_step_over("Phalcon_Internal_Test::c4 (Method) File=Library/Phalcon/Internal/Test.php Line=575");
}

PHP_METHOD(Phalcon_Internal_Test, c5){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c5", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
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
	phalcon_step_over("Phalcon_Internal_Test::c5 (Method) File=Library/Phalcon/Internal/Test.php Line=579");
}

PHP_METHOD(Phalcon_Internal_Test, c6){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c6", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_SMALLER_FUNCTION(r0, t0, t1);
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
	phalcon_step_over("Phalcon_Internal_Test::c6 (Method) File=Library/Phalcon/Internal/Test.php Line=583");
}

PHP_METHOD(Phalcon_Internal_Test, c7){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c7", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_EQUAL_FUNCTION(r0, t0, t1);
	PHALCON_ALLOC_ZVAL(t2);
	ZVAL_LONG(t2, 1);
	PHALCON_ALLOC_ZVAL(t3);
	ZVAL_LONG(t3, 1);
	PHALCON_SMALLER_EQUAL_FUNCTION(r1, t2, t3);
	PHALCON_AND_FUNCTION(r2, r0, r1);
	phalcon_debug_vdump("Returning > ", r2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r2);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::c7 (Method) File=Library/Phalcon/Internal/Test.php Line=587");
}

PHP_METHOD(Phalcon_Internal_Test, c8){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c8", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_NOT_EQUAL_FUNCTION(r0, t0, t1);
	PHALCON_ALLOC_ZVAL(t2);
	ZVAL_LONG(t2, 1);
	PHALCON_ALLOC_ZVAL(t3);
	ZVAL_LONG(t3, 1);
	PHALCON_SMALLER_FUNCTION(r1, t2, t3);
	PHALCON_AND_FUNCTION(r2, r0, r1);
	phalcon_debug_vdump("Returning > ", r2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r2);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::c8 (Method) File=Library/Phalcon/Internal/Test.php Line=591");
}

PHP_METHOD(Phalcon_Internal_Test, c9){

	zval *r0 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c9", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 0);
	PHALCON_BOOLEAN_NOT_FUNCTION(r0, t0);
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
	phalcon_step_over("Phalcon_Internal_Test::c9 (Method) File=Library/Phalcon/Internal/Test.php Line=595");
}

PHP_METHOD(Phalcon_Internal_Test, c10){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c10", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_NOT_EQUAL_FUNCTION(r1, t0, t1);
	PHALCON_BOOLEAN_NOT_FUNCTION(r0, r1);
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
	phalcon_step_over("Phalcon_Internal_Test::c10 (Method) File=Library/Phalcon/Internal/Test.php Line=599");
}

PHP_METHOD(Phalcon_Internal_Test, c11){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "c11", 0);
	//$a
	//$b
	//$c
	PHALCON_EQUAL_FUNCTION(r0, v1, v2);
	PHALCON_EQUAL_FUNCTION(r1, v0, r0);
	phalcon_debug_vdump("Returning > ", r1 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r1);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::c11 (Method) File=Library/Phalcon/Internal/Test.php Line=606");
}

PHP_METHOD(Phalcon_Internal_Test, f1){

	zval *r0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Internal_Test", "f1", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "LOL", 1);
	PHALCON_CALL_FUNC_PARAMS(r0, "strlen", 1, p0);
	phalcon_debug_vdump("strlen > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::f1 (Method) File=Library/Phalcon/Internal/Test.php Line=610");
}

PHP_METHOD(Phalcon_Internal_Test, f2){

	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	phalcon_step_into_entry("Phalcon_Internal_Test", "f2", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "hello\t", 1);
	PHALCON_ALLOC_ZVAL(p0[1]);
	ZVAL_STRING(p0[1], "\t", 1);
	PHALCON_CALL_FUNC_PARAMS(r0, "rtrim", 2, p0);
	phalcon_debug_vdump("rtrim > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::f2 (Method) File=Library/Phalcon/Internal/Test.php Line=614");
}

PHP_METHOD(Phalcon_Internal_Test, f3){

	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL, NULL };

	phalcon_step_into_entry("Phalcon_Internal_Test", "f3", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "bb", 1);
	PHALCON_ALLOC_ZVAL(p0[1]);
	ZVAL_STRING(p0[1], "xx", 1);
	PHALCON_ALLOC_ZVAL(p0[2]);
	ZVAL_STRING(p0[2], "aabbcc", 1);
	PHALCON_CALL_FUNC_PARAMS(r0, "str_replace", 3, p0);
	phalcon_debug_vdump("str_replace > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::f3 (Method) File=Library/Phalcon/Internal/Test.php Line=618");
}

PHP_METHOD(Phalcon_Internal_Test, f4){

	zval *r0 = NULL, *r1 = NULL;
	zval *p1[] = { NULL }, *p0[] = { NULL, NULL };

	phalcon_step_into_entry("Phalcon_Internal_Test", "f4", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "deux", 1);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(p1[0]);
	ZVAL_STRING(p1[0], "deux", 1);
	PHALCON_CALL_FUNC_PARAMS(r1, "strlen", 1, p1);
	phalcon_debug_vdump("strlen > ", r1 TSRMLS_CC);
	p0[1] = r1;
	phalcon_debug_param(r1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "str_repeat", 2, p0);
	phalcon_debug_vdump("str_repeat > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::f4 (Method) File=Library/Phalcon/Internal/Test.php Line=622");
}

PHP_METHOD(Phalcon_Internal_Test, f5){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Internal_Test", "f5", 0);
	phalcon_step_over("Phalcon_Internal_Test::f5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=623");
	//$e
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_string(a0, "b", 1);
	add_next_index_string(a0, "c", 1);
	add_next_index_string(a0, "a", 1);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$e", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::f5 (FunctionCall) File=Library/Phalcon/Internal/Test.php Line=624");
	//$e
	Z_SET_ISREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("asort", 1, p0);
	//$e
	phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::f5 (Method) File=Library/Phalcon/Internal/Test.php Line=628");
}

PHP_METHOD(Phalcon_Internal_Test, f6){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL, NULL }, *p2[] = { NULL, NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL };

	phalcon_step_into_entry("Phalcon_Internal_Test", "f6", 0);
	phalcon_step_over("Phalcon_Internal_Test::f6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=629");
	//$file
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_PARAM_LONG(p0[0], 0);
	PHALCON_PARAM_LONG(p0[1], 100);
	PHALCON_CALL_FUNC_PARAMS(r0, "mt_rand", 2, p0);
	phalcon_debug_vdump("mt_rand > ", r0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_concat_right(r1, r0, ".txt" TSRMLS_CC);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(r1);
	v0 = r1;
	phalcon_debug_assign("$file", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::f6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=630");
	//$fp
	PHALCON_ALLOC_ZVAL(r2);
	//$file
	p1[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p1[1]);
	ZVAL_STRING(p1[1], "w", 1);
	PHALCON_CALL_FUNC_PARAMS(r2, "fopen", 2, p1);
	phalcon_debug_vdump("fopen > ", r2 TSRMLS_CC);
	if (v1) {
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r2);
	v1 = r2;
	phalcon_debug_assign("$fp", r2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::f6 (FunctionCall) File=Library/Phalcon/Internal/Test.php Line=631");
	//$fp
	Z_ADDREF_P(v1);
	p2[0] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p2[1]);
	ZVAL_STRING(p2[1], "morelol\n", 1);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("fwrite", 2, p2);
	phalcon_step_over("Phalcon_Internal_Test::f6 (FunctionCall) File=Library/Phalcon/Internal/Test.php Line=632");
	//$fp
	Z_ADDREF_P(v1);
	p3[0] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("fclose", 1, p3);
	phalcon_step_over("Phalcon_Internal_Test::f6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=633");
	//$content
	PHALCON_ALLOC_ZVAL(r3);
	//$file
	p4[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r3, "file_get_contents", 1, p4);
	phalcon_debug_vdump("file_get_contents > ", r3 TSRMLS_CC);
	if (v2) {
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r3);
	v2 = r3;
	phalcon_debug_assign("$content", r3 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::f6 (FunctionCall) File=Library/Phalcon/Internal/Test.php Line=634");
	//$file
	p5[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("unlink", 1, p5);
	//$content
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
	phalcon_step_over("Phalcon_Internal_Test::f6 (Method) File=Library/Phalcon/Internal/Test.php Line=638");
}

PHP_METHOD(Phalcon_Internal_Test, f7){

	zval *r0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Internal_Test", "f7", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_PARAM_DOUBLE(p0[0], 3.14159);
	PHALCON_CALL_FUNC_PARAMS(r0, "sqrt", 1, p0);
	phalcon_debug_vdump("sqrt > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::f7 (Method) File=Library/Phalcon/Internal/Test.php Line=642");
}

PHP_METHOD(Phalcon_Internal_Test, f8){

	zval *r0 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL, NULL, NULL };

	phalcon_step_into_entry("Phalcon_Internal_Test", "f8", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_string(a0, ".", 1);
	add_next_index_string(a0, ",", 1);
	add_next_index_string(a0, "-", 1);
	p0[0] = a0;
	phalcon_debug_param(a0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p0[1]);
	ZVAL_STRING(p0[1], "&", 1);
	PHALCON_ALLOC_ZVAL(p0[2]);
	ZVAL_STRING(p0[2], "-.,-.,", 1);
	PHALCON_CALL_FUNC_PARAMS(r0, "str_replace", 3, p0);
	phalcon_debug_vdump("str_replace > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::f8 (Method) File=Library/Phalcon/Internal/Test.php Line=646");
}

PHP_METHOD(Phalcon_Internal_Test, f9){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Internal_Test", "f9", 0);
	phalcon_step_over("Phalcon_Internal_Test::f9 (Assignment) File=Library/Phalcon/Internal/Test.php Line=647");
	//$e
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "-1000", 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 400);
	PHALCON_ALLOC_ZVAL(r0);
	mul_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_INIT_FALSE(t2);
	PHALCON_ALLOC_ZVAL(r1);
	mul_function(r1, r0, t2 TSRMLS_CC);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(r1);
	v0 = r1;
	phalcon_debug_assign("$e", r1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r2);
	//$e
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r2, "abs", 1, p0);
	phalcon_debug_vdump("abs > ", r2 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r2 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r2, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::f9 (Method) File=Library/Phalcon/Internal/Test.php Line=651");
}

PHP_METHOD(Phalcon_Internal_Test, f10){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Internal_Test", "f10", 0);
	phalcon_step_over("Phalcon_Internal_Test::f10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=652");
	//$a
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::f10 (If) File=Library/Phalcon/Internal/Test.php Line=653");
	PHALCON_ALLOC_ZVAL(r0);
	//$a
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_array_fetch_long(r1, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r1);
	p0[0] = r1;
	phalcon_debug_param(r1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "is_numeric", 1, p0);
	phalcon_debug_vdump("is_numeric > ", r0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Internal_Test::f10 (Block) File=Library/Phalcon/Internal/Test.php Line=653");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Internal_Test::f10 (Block) File=Library/Phalcon/Internal/Test.php Line=655");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::f10 (Method) File=Library/Phalcon/Internal/Test.php Line=663");
}

PHP_METHOD(Phalcon_Internal_Test, m1){


	phalcon_step_into_entry("Phalcon_Internal_Test", "m1", 0);
	phalcon_step_out_entry();
	RETURN_STRING("private", 1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::m1 (Method) File=Library/Phalcon/Internal/Test.php Line=667");
}

PHP_METHOD(Phalcon_Internal_Test, m2){


	phalcon_step_into_entry("Phalcon_Internal_Test", "m2", 0);
	phalcon_step_out_entry();
	RETURN_STRING("protected", 1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::m2 (Method) File=Library/Phalcon/Internal/Test.php Line=671");
}

PHP_METHOD(Phalcon_Internal_Test, m3){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "m3", 0);
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m1" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "m1", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::m3 (Method) File=Library/Phalcon/Internal/Test.php Line=675");
}

PHP_METHOD(Phalcon_Internal_Test, m4){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "m4", 0);
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m2" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "m2", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::m4 (Method) File=Library/Phalcon/Internal/Test.php Line=679");
}

PHP_METHOD(Phalcon_Internal_Test, m5){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "m5", 0);
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m2" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "m2", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m1" TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, this_ptr, "m1", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r2);
	concat_function(r2, r0, r1 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::m5 (Method) File=Library/Phalcon/Internal/Test.php Line=683");
}

PHP_METHOD(Phalcon_Internal_Test, m6){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "m6", 0);
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
	phalcon_step_over("Phalcon_Internal_Test::m6 (Method) File=Library/Phalcon/Internal/Test.php Line=687");
}

PHP_METHOD(Phalcon_Internal_Test, m7){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "m7", 0);
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m6" TSRMLS_CC);
	//$a
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$b
	Z_ADDREF_P(v1);
	p0[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "m6", 2, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::m7 (Method) File=Library/Phalcon/Internal/Test.php Line=691");
}

PHP_METHOD(Phalcon_Internal_Test, m8){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "m8", 0);
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m6" TSRMLS_CC);
	//$a
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$b
	Z_ADDREF_P(v1);
	p0[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "m6", 2, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m6" TSRMLS_CC);
	//$a
	Z_ADDREF_P(v0);
	p1[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$b
	Z_ADDREF_P(v1);
	p1[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "m6", 2, p1, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r2);
	concat_function(r2, r0, r1 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::m8 (Method) File=Library/Phalcon/Internal/Test.php Line=695");
}

PHP_METHOD(Phalcon_Internal_Test, m9){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "m9", 0);
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
	phalcon_step_over("Phalcon_Internal_Test::m9 (Method) File=Library/Phalcon/Internal/Test.php Line=699");
}

PHP_METHOD(Phalcon_Internal_Test, m10){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "m10", 0);
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m9" TSRMLS_CC);
	//$a
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$b
	Z_ADDREF_P(v1);
	p0[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "m9", 2, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::m10 (Method) File=Library/Phalcon/Internal/Test.php Line=703");
}

PHP_METHOD(Phalcon_Internal_Test, m11){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "m11", 0);
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m10" TSRMLS_CC);
	//$a
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$b
	Z_ADDREF_P(v1);
	p0[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "m10", 2, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::m11 (Method) File=Library/Phalcon/Internal/Test.php Line=707");
}

PHP_METHOD(Phalcon_Internal_Test, m12){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "m12", 0);
	phalcon_step_over("Phalcon_Internal_Test::m12 (Assignment) File=Library/Phalcon/Internal/Test.php Line=708");
	//$d
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_LONG(v2, 0);
	phalcon_step_over("Phalcon_Internal_Test::m12 (For) File=Library/Phalcon/Internal/Test.php Line=709");
	//$c
	PHALCON_ALLOC_ZVAL(v3);
	ZVAL_LONG(v3, 0);
	fs32:
	//$c
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_SMALLER_FUNCTION(r0, v3, t0);
	if (!zend_is_true(r0)) {
		goto fe32;
	}
	phalcon_step_over("Phalcon_Internal_Test::m12 (Block) File=Library/Phalcon/Internal/Test.php Line=709");
	phalcon_step_over("Phalcon_Internal_Test::m12 (AssignOp) File=Library/Phalcon/Internal/Test.php Line=710");
	//$d
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
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m9" TSRMLS_CC);
	//$c
	//$a
	if (!r2) {
		PHALCON_ALLOC_ZVAL(r2);
	} else {
		if (Z_REFCOUNT_P(r2) > 1){ 
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
		}
	}
	add_function(r2, v3, v0 TSRMLS_CC);
	Z_ADDREF_P(r2);
	p0[0] = r2;
	phalcon_debug_param(r2 TSRMLS_CC);
	//$b
	//$c
	if (!t1) {
		PHALCON_ALLOC_ZVAL(t1);
	} else {
		if (Z_REFCOUNT_P(t1) > 1) {
			SEPARATE_ZVAL(&t1);
		} else {
			if (Z_TYPE_P(t1) != IS_LONG) {
				FREE_ZVAL(t1);
				PHALCON_ALLOC_ZVAL(t1);
			}
		}
	}
	ZVAL_LONG(t1, 1);
	if (!r3) {
		PHALCON_ALLOC_ZVAL(r3);
	} else {
		if (Z_REFCOUNT_P(r3) > 1){ 
			{
				zval *orig_ptr = r3;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(r3);
					*r3 = *orig_ptr;
					zval_copy_ctor(r3);
					Z_SET_REFCOUNT_P(r3, 1);
					Z_UNSET_ISREF_P(r3);
				}
			}
		}
	}
	add_function(r3, v3, t1 TSRMLS_CC);
	if (!r4) {
		PHALCON_ALLOC_ZVAL(r4);
	} else {
		if (Z_REFCOUNT_P(r4) > 1){ 
			{
				zval *orig_ptr = r4;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(r4);
					*r4 = *orig_ptr;
					zval_copy_ctor(r4);
					Z_SET_REFCOUNT_P(r4, 1);
					Z_UNSET_ISREF_P(r4);
				}
			}
		}
	}
	add_function(r4, v1, r3 TSRMLS_CC);
	Z_ADDREF_P(r4);
	p0[1] = r4;
	phalcon_debug_param(r4 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "m9", 2, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	PHALCON_ADD_FUNCTION(r5, v2, r1);
	//$d
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r5);
	v2 = r5;
	phalcon_debug_assign("$d", r5 TSRMLS_CC);
	//$c
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
	increment_function(v3);
	phalcon_debug_vdump("PostIncrementing $c", v3);
	goto fs32;
	fe32:
	r0 = NULL;
	//$d
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::m12 (Method) File=Library/Phalcon/Internal/Test.php Line=715");
}

PHP_METHOD(Phalcon_Internal_Test, m13){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "m13", 0);
	phalcon_step_over("Phalcon_Internal_Test::m13 (Assignment) File=Library/Phalcon/Internal/Test.php Line=716");
	//$a
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 100);
	//$b
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_ALLOC_ZVAL(r0);
	mul_function(r0, v1, t0 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::m13 (Method) File=Library/Phalcon/Internal/Test.php Line=720");
}

PHP_METHOD(Phalcon_Internal_Test, m14){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "m14", 0);
	phalcon_step_over("Phalcon_Internal_Test::m14 (Assignment) File=Library/Phalcon/Internal/Test.php Line=721");
	//$f
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m13" TSRMLS_CC);
	//$a
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$b
	Z_ADDREF_P(v1);
	p0[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "m13", 2, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	//$a
	PHALCON_ALLOC_ZVAL(r1);
	mul_function(r1, r0, v0 TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	phalcon_debug_assign("$f", r1 TSRMLS_CC);
	//$f
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::m14 (Method) File=Library/Phalcon/Internal/Test.php Line=725");
}

PHP_METHOD(Phalcon_Internal_Test, m15){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "m15", 0);
	phalcon_step_over("Phalcon_Internal_Test::m15 (Assignment) File=Library/Phalcon/Internal/Test.php Line=726");
	//$f
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m13" TSRMLS_CC);
	//$a
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$b
	Z_ADDREF_P(v1);
	p0[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "m13", 2, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r0);
	v2 = r0;
	phalcon_debug_assign("$f", r0 TSRMLS_CC);
	//$f
	//$a
	PHALCON_ALLOC_ZVAL(r1);
	mul_function(r1, v2, v0 TSRMLS_CC);
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::m15 (Method) File=Library/Phalcon/Internal/Test.php Line=733");
}

PHP_METHOD(Phalcon_Internal_Test, mp3){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "mp3", 0);
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "mp1" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "mp1", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::mp3 (Method) File=Library/Phalcon/Internal/Test.php Line=737");
}

PHP_METHOD(Phalcon_Internal_Test, mp4){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "mp4", 0);
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "mp2" TSRMLS_CC);
	//$a
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$b
	Z_ADDREF_P(v1);
	p0[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "mp2", 2, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::mp4 (Method) File=Library/Phalcon/Internal/Test.php Line=741");
}

PHP_METHOD(Phalcon_Internal_Test, mp5){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "mp5", 0);
	phalcon_step_over("Phalcon_Internal_Test::mp5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=742");
	//$o
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_internal_testparent_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(i0);
	v0 = i0;
	phalcon_debug_assign("$o", i0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	//$o
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(v0, "mp1" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, v0, "mp1", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::mp5 (Method) File=Library/Phalcon/Internal/Test.php Line=746");
}

PHP_METHOD(Phalcon_Internal_Test, mp6){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;
	zval *p1[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "mp6", 0);
	phalcon_step_over("Phalcon_Internal_Test::mp6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=747");
	//$o
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_internal_testparent_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(i0);
	v2 = i0;
	phalcon_debug_assign("$o", i0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	//$o
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(v2, "mp2" TSRMLS_CC);
	//$a
	Z_ADDREF_P(v0);
	p1[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$b
	Z_ADDREF_P(v1);
	p1[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, v2, "mp2", 2, p1, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::mp6 (Method) File=Library/Phalcon/Internal/Test.php Line=754");
}

PHP_METHOD(Phalcon_Internal_Test, sm1){


	phalcon_step_into_entry("Phalcon_Internal_Test", "sm1", 0);
	phalcon_step_out_entry();
	RETURN_STRING("private", 1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sm1 (Method) File=Library/Phalcon/Internal/Test.php Line=758");
}

PHP_METHOD(Phalcon_Internal_Test, sm2){


	phalcon_step_into_entry("Phalcon_Internal_Test", "sm2", 0);
	phalcon_step_out_entry();
	RETURN_STRING("protected", 1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sm2 (Method) File=Library/Phalcon/Internal/Test.php Line=762");
}

PHP_METHOD(Phalcon_Internal_Test, sm3){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sm3", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_SELF(r0, this_ptr, "sm1");
	phalcon_debug_vdump("SelfStaticReturn > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sm3 (Method) File=Library/Phalcon/Internal/Test.php Line=766");
}

PHP_METHOD(Phalcon_Internal_Test, sm4){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sm4", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_SELF(r0, this_ptr, "sm2");
	phalcon_debug_vdump("SelfStaticReturn > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sm4 (Method) File=Library/Phalcon/Internal/Test.php Line=770");
}

PHP_METHOD(Phalcon_Internal_Test, sm5){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sm5", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_SELF(r0, this_ptr, "sm2");
	phalcon_debug_vdump("SelfStaticReturn > ", r0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_SELF(r1, this_ptr, "sm1");
	phalcon_debug_vdump("SelfStaticReturn > ", r1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r2);
	concat_function(r2, r0, r1 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sm5 (Method) File=Library/Phalcon/Internal/Test.php Line=774");
}

PHP_METHOD(Phalcon_Internal_Test, sm6){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "sm6", 0);
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
	phalcon_step_over("Phalcon_Internal_Test::sm6 (Method) File=Library/Phalcon/Internal/Test.php Line=778");
}

PHP_METHOD(Phalcon_Internal_Test, sm7){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "sm7", 0);
	PHALCON_ALLOC_ZVAL(r0);
	//$a
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$b
	Z_ADDREF_P(v1);
	p0[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "sm6", 2, p0);
	phalcon_debug_vdump("SelfStaticReturn > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sm7 (Method) File=Library/Phalcon/Internal/Test.php Line=782");
}

PHP_METHOD(Phalcon_Internal_Test, sm8){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "sm8", 0);
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
	phalcon_step_over("Phalcon_Internal_Test::sm8 (Method) File=Library/Phalcon/Internal/Test.php Line=786");
}

PHP_METHOD(Phalcon_Internal_Test, sm9){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "sm9", 0);
	phalcon_step_over("Phalcon_Internal_Test::sm9 (Assignment) File=Library/Phalcon/Internal/Test.php Line=787");
	//$d
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_LONG(v2, 0);
	phalcon_step_over("Phalcon_Internal_Test::sm9 (For) File=Library/Phalcon/Internal/Test.php Line=788");
	//$c
	PHALCON_ALLOC_ZVAL(v3);
	ZVAL_LONG(v3, 0);
	fs33:
	//$c
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_SMALLER_FUNCTION(r0, v3, t0);
	if (!zend_is_true(r0)) {
		goto fe33;
	}
	phalcon_step_over("Phalcon_Internal_Test::sm9 (Block) File=Library/Phalcon/Internal/Test.php Line=788");
	phalcon_step_over("Phalcon_Internal_Test::sm9 (AssignOp) File=Library/Phalcon/Internal/Test.php Line=789");
	//$d
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
	//$c
	//$a
	if (!r2) {
		PHALCON_ALLOC_ZVAL(r2);
	} else {
		if (Z_REFCOUNT_P(r2) > 1){ 
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
		}
	}
	add_function(r2, v3, v0 TSRMLS_CC);
	Z_ADDREF_P(r2);
	p0[0] = r2;
	phalcon_debug_param(r2 TSRMLS_CC);
	//$b
	//$c
	if (!t1) {
		PHALCON_ALLOC_ZVAL(t1);
	} else {
		if (Z_REFCOUNT_P(t1) > 1) {
			SEPARATE_ZVAL(&t1);
		} else {
			if (Z_TYPE_P(t1) != IS_LONG) {
				FREE_ZVAL(t1);
				PHALCON_ALLOC_ZVAL(t1);
			}
		}
	}
	ZVAL_LONG(t1, 1);
	if (!r3) {
		PHALCON_ALLOC_ZVAL(r3);
	} else {
		if (Z_REFCOUNT_P(r3) > 1){ 
			{
				zval *orig_ptr = r3;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(r3);
					*r3 = *orig_ptr;
					zval_copy_ctor(r3);
					Z_SET_REFCOUNT_P(r3, 1);
					Z_UNSET_ISREF_P(r3);
				}
			}
		}
	}
	add_function(r3, v3, t1 TSRMLS_CC);
	if (!r4) {
		PHALCON_ALLOC_ZVAL(r4);
	} else {
		if (Z_REFCOUNT_P(r4) > 1){ 
			{
				zval *orig_ptr = r4;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(r4);
					*r4 = *orig_ptr;
					zval_copy_ctor(r4);
					Z_SET_REFCOUNT_P(r4, 1);
					Z_UNSET_ISREF_P(r4);
				}
			}
		}
	}
	add_function(r4, v1, r3 TSRMLS_CC);
	Z_ADDREF_P(r4);
	p0[1] = r4;
	phalcon_debug_param(r4 TSRMLS_CC);
	PHALCON_CALL_SELF_PARAMS(r1, this_ptr, "sm8", 2, p0);
	phalcon_debug_vdump("SelfStaticReturn > ", r1 TSRMLS_CC);
	PHALCON_ADD_FUNCTION(r5, v2, r1);
	//$d
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r5);
	v2 = r5;
	phalcon_debug_assign("$d", r5 TSRMLS_CC);
	//$c
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
	increment_function(v3);
	phalcon_debug_vdump("PostIncrementing $c", v3);
	goto fs33;
	fe33:
	r0 = NULL;
	//$d
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sm9 (Method) File=Library/Phalcon/Internal/Test.php Line=794");
}

PHP_METHOD(Phalcon_Internal_Test, sm10){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "sm10", 0);
	phalcon_step_over("Phalcon_Internal_Test::sm10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=795");
	//$d
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_LONG(v2, 0);
	phalcon_step_over("Phalcon_Internal_Test::sm10 (For) File=Library/Phalcon/Internal/Test.php Line=796");
	//$c
	PHALCON_ALLOC_ZVAL(v3);
	ZVAL_LONG(v3, 0);
	fs34:
	//$c
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_SMALLER_FUNCTION(r0, v3, t0);
	if (!zend_is_true(r0)) {
		goto fe34;
	}
	phalcon_step_over("Phalcon_Internal_Test::sm10 (Block) File=Library/Phalcon/Internal/Test.php Line=796");
	phalcon_step_over("Phalcon_Internal_Test::sm10 (AssignOp) File=Library/Phalcon/Internal/Test.php Line=797");
	//$d
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
	//$c
	//$a
	if (!r2) {
		PHALCON_ALLOC_ZVAL(r2);
	} else {
		if (Z_REFCOUNT_P(r2) > 1){ 
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
		}
	}
	add_function(r2, v3, v0 TSRMLS_CC);
	Z_ADDREF_P(r2);
	p0[0] = r2;
	phalcon_debug_param(r2 TSRMLS_CC);
	//$b
	//$c
	if (!t1) {
		PHALCON_ALLOC_ZVAL(t1);
	} else {
		if (Z_REFCOUNT_P(t1) > 1) {
			SEPARATE_ZVAL(&t1);
		} else {
			if (Z_TYPE_P(t1) != IS_LONG) {
				FREE_ZVAL(t1);
				PHALCON_ALLOC_ZVAL(t1);
			}
		}
	}
	ZVAL_LONG(t1, 1);
	if (!r3) {
		PHALCON_ALLOC_ZVAL(r3);
	} else {
		if (Z_REFCOUNT_P(r3) > 1){ 
			{
				zval *orig_ptr = r3;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(r3);
					*r3 = *orig_ptr;
					zval_copy_ctor(r3);
					Z_SET_REFCOUNT_P(r3, 1);
					Z_UNSET_ISREF_P(r3);
				}
			}
		}
	}
	add_function(r3, v3, t1 TSRMLS_CC);
	if (!r4) {
		PHALCON_ALLOC_ZVAL(r4);
	} else {
		if (Z_REFCOUNT_P(r4) > 1){ 
			{
				zval *orig_ptr = r4;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(r4);
					*r4 = *orig_ptr;
					zval_copy_ctor(r4);
					Z_SET_REFCOUNT_P(r4, 1);
					Z_UNSET_ISREF_P(r4);
				}
			}
		}
	}
	add_function(r4, v1, r3 TSRMLS_CC);
	Z_ADDREF_P(r4);
	p0[1] = r4;
	phalcon_debug_param(r4 TSRMLS_CC);
	PHALCON_CALL_STATIC_PARAMS(r1, "phalcon_internal_test", "sm8", 2, p0);
	phalcon_debug_vdump("StaticReturn > ", r1 TSRMLS_CC);
	PHALCON_ADD_FUNCTION(r5, v2, r1);
	//$d
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r5);
	v2 = r5;
	phalcon_debug_assign("$d", r5 TSRMLS_CC);
	//$c
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
	increment_function(v3);
	phalcon_debug_vdump("PostIncrementing $c", v3);
	goto fs34;
	fe34:
	r0 = NULL;
	//$d
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sm10 (Method) File=Library/Phalcon/Internal/Test.php Line=805");
}

PHP_METHOD(Phalcon_Internal_Test, smp2){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "smp2", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_SELF(r0, this_ptr, "smp1");
	phalcon_debug_vdump("SelfStaticReturn > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::smp2 (Method) File=Library/Phalcon/Internal/Test.php Line=809");
}

PHP_METHOD(Phalcon_Internal_Test, smp4){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "smp4", 0);
	PHALCON_ALLOC_ZVAL(r0);
	//$b
	Z_ADDREF_P(v1);
	p0[0] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	//$a
	Z_ADDREF_P(v0);
	p0[1] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_PARENT_PARAMS(r0, this_ptr, "Phalcon_Internal_Test", "smp3", 2, p0);
	phalcon_debug_vdump("ParentStaticReturn > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::smp4 (Method) File=Library/Phalcon/Internal/Test.php Line=813");
}

PHP_METHOD(Phalcon_Internal_Test, smp5){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "smp5", 0);
	phalcon_step_over("Phalcon_Internal_Test::smp5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=814");
	//$d
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_LONG(v2, 0);
	phalcon_step_over("Phalcon_Internal_Test::smp5 (For) File=Library/Phalcon/Internal/Test.php Line=815");
	//$c
	PHALCON_ALLOC_ZVAL(v3);
	ZVAL_LONG(v3, 0);
	fs35:
	//$c
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_SMALLER_FUNCTION(r0, v3, t0);
	if (!zend_is_true(r0)) {
		goto fe35;
	}
	phalcon_step_over("Phalcon_Internal_Test::smp5 (Block) File=Library/Phalcon/Internal/Test.php Line=815");
	phalcon_step_over("Phalcon_Internal_Test::smp5 (AssignOp) File=Library/Phalcon/Internal/Test.php Line=816");
	//$d
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
	//$c
	//$a
	if (!r2) {
		PHALCON_ALLOC_ZVAL(r2);
	} else {
		if (Z_REFCOUNT_P(r2) > 1){ 
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
		}
	}
	add_function(r2, v3, v0 TSRMLS_CC);
	Z_ADDREF_P(r2);
	p0[0] = r2;
	phalcon_debug_param(r2 TSRMLS_CC);
	//$b
	//$c
	if (!t1) {
		PHALCON_ALLOC_ZVAL(t1);
	} else {
		if (Z_REFCOUNT_P(t1) > 1) {
			SEPARATE_ZVAL(&t1);
		} else {
			if (Z_TYPE_P(t1) != IS_LONG) {
				FREE_ZVAL(t1);
				PHALCON_ALLOC_ZVAL(t1);
			}
		}
	}
	ZVAL_LONG(t1, 1);
	if (!r3) {
		PHALCON_ALLOC_ZVAL(r3);
	} else {
		if (Z_REFCOUNT_P(r3) > 1){ 
			{
				zval *orig_ptr = r3;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(r3);
					*r3 = *orig_ptr;
					zval_copy_ctor(r3);
					Z_SET_REFCOUNT_P(r3, 1);
					Z_UNSET_ISREF_P(r3);
				}
			}
		}
	}
	add_function(r3, v3, t1 TSRMLS_CC);
	if (!r4) {
		PHALCON_ALLOC_ZVAL(r4);
	} else {
		if (Z_REFCOUNT_P(r4) > 1){ 
			{
				zval *orig_ptr = r4;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(r4);
					*r4 = *orig_ptr;
					zval_copy_ctor(r4);
					Z_SET_REFCOUNT_P(r4, 1);
					Z_UNSET_ISREF_P(r4);
				}
			}
		}
	}
	add_function(r4, v1, r3 TSRMLS_CC);
	Z_ADDREF_P(r4);
	p0[1] = r4;
	phalcon_debug_param(r4 TSRMLS_CC);
	PHALCON_CALL_STATIC_PARAMS(r1, "phalcon_internal_test", "smp3", 2, p0);
	phalcon_debug_vdump("StaticReturn > ", r1 TSRMLS_CC);
	PHALCON_ADD_FUNCTION(r5, v2, r1);
	//$d
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r5);
	v2 = r5;
	phalcon_debug_assign("$d", r5 TSRMLS_CC);
	//$c
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
	increment_function(v3);
	phalcon_debug_vdump("PostIncrementing $c", v3);
	goto fs35;
	fe35:
	r0 = NULL;
	//$d
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::smp5 (Method) File=Library/Phalcon/Internal/Test.php Line=824");
}

PHP_METHOD(Phalcon_Internal_Test, p1){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p1", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p1", sizeof("_p1")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p1 (Method) File=Library/Phalcon/Internal/Test.php Line=828");
}

PHP_METHOD(Phalcon_Internal_Test, p2){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p2", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p2", sizeof("_p2")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p2 (Method) File=Library/Phalcon/Internal/Test.php Line=832");
}

PHP_METHOD(Phalcon_Internal_Test, p3){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p3", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p3", sizeof("_p3")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p3 (Method) File=Library/Phalcon/Internal/Test.php Line=836");
}

PHP_METHOD(Phalcon_Internal_Test, p4){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p4", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p4", sizeof("_p4")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p4 (Method) File=Library/Phalcon/Internal/Test.php Line=840");
}

PHP_METHOD(Phalcon_Internal_Test, p5){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p5", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p5", sizeof("_p5")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p5 (Method) File=Library/Phalcon/Internal/Test.php Line=844");
}

PHP_METHOD(Phalcon_Internal_Test, p6){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p6", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p6", sizeof("_p6")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p6 (Method) File=Library/Phalcon/Internal/Test.php Line=848");
}

PHP_METHOD(Phalcon_Internal_Test, p7){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p7", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p7", sizeof("_p7")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p7 (Method) File=Library/Phalcon/Internal/Test.php Line=852");
}

PHP_METHOD(Phalcon_Internal_Test, p8){


	phalcon_step_into_entry("Phalcon_Internal_Test", "p8", 0);
	phalcon_step_over("Phalcon_Internal_Test::p8 (Assignment) File=Library/Phalcon/Internal/Test.php Line=853");
	//$this
	phalcon_update_property_string(this_ptr, "_p0", strlen("_p0"), "more-lol" TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::p8 (Method) File=Library/Phalcon/Internal/Test.php Line=856");
}

PHP_METHOD(Phalcon_Internal_Test, p9){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p9", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p9 (Method) File=Library/Phalcon/Internal/Test.php Line=860");
}

PHP_METHOD(Phalcon_Internal_Test, p10){


	phalcon_step_into_entry("Phalcon_Internal_Test", "p10", 0);
	phalcon_step_over("Phalcon_Internal_Test::p10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=861");
	//$this
	phalcon_update_property_long(this_ptr, "_p0", strlen("_p0"), 14750 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::p10 (Method) File=Library/Phalcon/Internal/Test.php Line=864");
}

PHP_METHOD(Phalcon_Internal_Test, p11){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p11", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p11 (Method) File=Library/Phalcon/Internal/Test.php Line=868");
}

PHP_METHOD(Phalcon_Internal_Test, p12){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p12", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p1", sizeof("_p1")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_p2", sizeof("_p2")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	PHALCON_ALLOC_ZVAL(r0);
	concat_function(r0, t0, t1 TSRMLS_CC);
	//$this
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_p3", sizeof("_p3")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t2);
	PHALCON_ALLOC_ZVAL(r1);
	concat_function(r1, r0, t2 TSRMLS_CC);
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p12 (Method) File=Library/Phalcon/Internal/Test.php Line=872");
}

PHP_METHOD(Phalcon_Internal_Test, p13){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p13", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p4", sizeof("_p4")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_p5", sizeof("_p5")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	PHALCON_ALLOC_ZVAL(r0);
	add_function(r0, t0, t1 TSRMLS_CC);
	//$this
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_p6", sizeof("_p6")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t2);
	PHALCON_ALLOC_ZVAL(r1);
	add_function(r1, r0, t2 TSRMLS_CC);
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p13 (Method) File=Library/Phalcon/Internal/Test.php Line=876");
}

PHP_METHOD(Phalcon_Internal_Test, p14){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "p14", 0);
	phalcon_step_over("Phalcon_Internal_Test::p14 (AssignOp) File=Library/Phalcon/Internal/Test.php Line=877");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	//$data
	PHALCON_CONCAT_FUNCTION(r0, t0, v0);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, r0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p0", strlen("_p0"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::p14 (Method) File=Library/Phalcon/Internal/Test.php Line=880");
}

PHP_METHOD(Phalcon_Internal_Test, p15){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Internal_Test", "p15", 0);
	phalcon_step_over("Phalcon_Internal_Test::p15 (Assignment) File=Library/Phalcon/Internal/Test.php Line=881");
	//$this
	phalcon_update_property_string(this_ptr, "_p0", strlen("_p0"), "" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::p15 (For) File=Library/Phalcon/Internal/Test.php Line=882");
	//$i
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 0);
	fs36:
	//$i
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 30);
	PHALCON_SMALLER_FUNCTION(r0, v0, t0);
	if (!zend_is_true(r0)) {
		goto fe36;
	}
	phalcon_step_over("Phalcon_Internal_Test::p15 (Block) File=Library/Phalcon/Internal/Test.php Line=882");
	phalcon_step_over("Phalcon_Internal_Test::p15 (MethodCall) File=Library/Phalcon/Internal/Test.php Line=883");
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "p14" TSRMLS_CC);
	//$i
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "p14", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	//$i
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
	phalcon_debug_vdump("PostIncrementing $i", v0);
	goto fs36;
	fe36:
	r0 = NULL;
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p15 (Method) File=Library/Phalcon/Internal/Test.php Line=888");
}

PHP_METHOD(Phalcon_Internal_Test, p16){

	zval *v0 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p16", 0);
	phalcon_step_over("Phalcon_Internal_Test::p16 (Assignment) File=Library/Phalcon/Internal/Test.php Line=889");
	//$p
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_STRING(v0, "_p0", 0);
	phalcon_step_over("Phalcon_Internal_Test::p16 (Assignment) File=Library/Phalcon/Internal/Test.php Line=890");
	//$p
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "lol", 1);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v0), Z_STRLEN_P(v0), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::p16 (Method) File=Library/Phalcon/Internal/Test.php Line=893");
}

PHP_METHOD(Phalcon_Internal_Test, p17){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p17", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p17 (Method) File=Library/Phalcon/Internal/Test.php Line=897");
}

PHP_METHOD(Phalcon_Internal_Test, p18){

	zval *v0 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p18", 0);
	phalcon_step_over("Phalcon_Internal_Test::p18 (Assignment) File=Library/Phalcon/Internal/Test.php Line=898");
	//$p
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_STRING(v0, "_p0", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	//$p
	phalcon_read_property_zval(t0, this_ptr, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p18 (Method) File=Library/Phalcon/Internal/Test.php Line=902");
}

PHP_METHOD(Phalcon_Internal_Test, p19){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p19", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p8", sizeof("_p8")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p19 (Method) File=Library/Phalcon/Internal/Test.php Line=906");
}

PHP_METHOD(Phalcon_Internal_Test, p20){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p20", 0);
	phalcon_step_over("Phalcon_Internal_Test::p20 (Assignment) File=Library/Phalcon/Internal/Test.php Line=907");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "hello", 1);
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_p8", sizeof("_p8")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_array_append(t1, t0 TSRMLS_CC);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p8", strlen("_p8"), copy TSRMLS_CC);
	}
	//$this
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_p8", sizeof("_p8")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t2);
	phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t2) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t2);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t2);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p20 (Method) File=Library/Phalcon/Internal/Test.php Line=911");
}

PHP_METHOD(Phalcon_Internal_Test, p21){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p21", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p21 (Method) File=Library/Phalcon/Internal/Test.php Line=915");
}

PHP_METHOD(Phalcon_Internal_Test, p22){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "p22", 0);
	phalcon_step_over("Phalcon_Internal_Test::p22 (Assignment) File=Library/Phalcon/Internal/Test.php Line=916");
	//$a
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_array_append(t0, v0 TSRMLS_CC);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), copy TSRMLS_CC);
	}
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p22 (Method) File=Library/Phalcon/Internal/Test.php Line=920");
}

PHP_METHOD(Phalcon_Internal_Test, p23){

	zval *v0 = NULL;
	zval *t0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "p23", 0);
	phalcon_step_over("Phalcon_Internal_Test::p23 (Assignment) File=Library/Phalcon/Internal/Test.php Line=921");
	//$a
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), copy TSRMLS_CC);
	}
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p23 (Method) File=Library/Phalcon/Internal/Test.php Line=925");
}

PHP_METHOD(Phalcon_Internal_Test, p24){

	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p24", 0);
	phalcon_step_over("Phalcon_Internal_Test::p24 (PostIncDecOp) File=Library/Phalcon/Internal/Test.php Line=926");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
		phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), copy TSRMLS_CC);
	}
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p24 (Method) File=Library/Phalcon/Internal/Test.php Line=930");
}

PHP_METHOD(Phalcon_Internal_Test, p25){

	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p25", 0);
	phalcon_step_over("Phalcon_Internal_Test::p25 (PostIncDecOp) File=Library/Phalcon/Internal/Test.php Line=931");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	decrement_function(t0);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), copy TSRMLS_CC);
	}
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p25 (Method) File=Library/Phalcon/Internal/Test.php Line=935");
}

PHP_METHOD(Phalcon_Internal_Test, p26){

	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p26", 0);
	phalcon_step_over("Phalcon_Internal_Test::p26 (PreIncDecOp) File=Library/Phalcon/Internal/Test.php Line=936");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
		phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), copy TSRMLS_CC);
	}
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p26 (Method) File=Library/Phalcon/Internal/Test.php Line=940");
}

PHP_METHOD(Phalcon_Internal_Test, p27){

	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p27", 0);
	phalcon_step_over("Phalcon_Internal_Test::p27 (PreIncDecOp) File=Library/Phalcon/Internal/Test.php Line=941");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	decrement_function(t0);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), copy TSRMLS_CC);
	}
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p27 (Method) File=Library/Phalcon/Internal/Test.php Line=945");
}

PHP_METHOD(Phalcon_Internal_Test, p28){

	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p28", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_ZVAL(t1, t0, 1, 0);
	increment_function(t0);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), copy TSRMLS_CC);
	}
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
	phalcon_step_over("Phalcon_Internal_Test::p28 (Method) File=Library/Phalcon/Internal/Test.php Line=949");
}

PHP_METHOD(Phalcon_Internal_Test, p29){

	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p29", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_ZVAL(t1, t0, 1, 0);
	decrement_function(t0);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), copy TSRMLS_CC);
	}
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
	phalcon_step_over("Phalcon_Internal_Test::p29 (Method) File=Library/Phalcon/Internal/Test.php Line=953");
}

PHP_METHOD(Phalcon_Internal_Test, p30){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *t0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p30", 0);
	phalcon_step_over("Phalcon_Internal_Test::p30 (Assignment) File=Library/Phalcon/Internal/Test.php Line=954");
	//$b
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_assoc_string(a1, "sup", "hello1", 1);
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
	add_assoc_zval(a0, "wish", a1);
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	add_assoc_string(a2, "xup", "hello2", 1);
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
	add_assoc_zval(a0, "be", a2);
	PHALCON_ALLOC_ZVAL(a3);
	array_init(a3);
	add_assoc_string(a3, "zup", "hello3", 1);
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
	add_assoc_zval(a0, "today", a3);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$b", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::p30 (Assignment) File=Library/Phalcon/Internal/Test.php Line=965");
	//$o
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(i0);
	v1 = i0;
	phalcon_debug_assign("$o", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::p30 (Foreach) File=Library/Phalcon/Internal/Test.php Line=966");
	//$b
	//$v
	//$k
	FOREACH_KV(v0, ac0, fes37, fee37, ah0, hp0, v3, v2)
		phalcon_step_over("Phalcon_Internal_Test::p30 (Block) File=Library/Phalcon/Internal/Test.php Line=966");
		phalcon_step_over("Phalcon_Internal_Test::p30 (If) File=Library/Phalcon/Internal/Test.php Line=967");
		//$v
		if (Z_TYPE_P(v2) == IS_ARRAY) { 
			phalcon_step_over("Phalcon_Internal_Test::p30 (Block) File=Library/Phalcon/Internal/Test.php Line=967");
			phalcon_step_over("Phalcon_Internal_Test::p30 (Assignment) File=Library/Phalcon/Internal/Test.php Line=968");
			//$k
			if (!i1) {
				PHALCON_ALLOC_ZVAL(i1);
			} else {
				if (Z_REFCOUNT_P(i1) > 1) {
					{
						zval *orig_ptr = i1;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(i1);
							*i1 = *orig_ptr;
							zval_copy_ctor(i1);
							Z_SET_REFCOUNT_P(i1, 1);
							Z_UNSET_ISREF_P(i1);
						}
					}
				} else {
					FREE_ZVAL(i1);
					PHALCON_ALLOC_ZVAL(i1);
				}
			}
			object_init(i1);
			//$o
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, i1, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(v1, Z_STRVAL_P(v3), Z_STRLEN_P(v3), copy TSRMLS_CC);
			}
			phalcon_step_over("Phalcon_Internal_Test::p30 (Foreach) File=Library/Phalcon/Internal/Test.php Line=969");
			//$v
			//$vv
			//$kv
			FOREACH_KV(v2, ac1, fes38, fee38, ah1, hp1, v5, v4)
				phalcon_step_over("Phalcon_Internal_Test::p30 (Block) File=Library/Phalcon/Internal/Test.php Line=969");
				phalcon_step_over("Phalcon_Internal_Test::p30 (Assignment) File=Library/Phalcon/Internal/Test.php Line=970");
				//$kv
				//$vv
				//$o
				if (!t0) {
					PHALCON_ALLOC_ZVAL(t0);
				} else {
					if (Z_REFCOUNT_P(t0) > 1) {
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
					} else {
						FREE_ZVAL(t0);
						PHALCON_ALLOC_ZVAL(t0);
					}
				}
				//$k
				phalcon_read_property_zval(t0, v1, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t0);
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v4, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(t0, Z_STRVAL_P(v5), Z_STRLEN_P(v5), copy TSRMLS_CC);
				}
			END_FOREACH(ac1, fes38, fee38, ah1, hp1);
		} else {
			phalcon_step_over("Phalcon_Internal_Test::p30 (Block) File=Library/Phalcon/Internal/Test.php Line=972");
			phalcon_step_over("Phalcon_Internal_Test::p30 (Assignment) File=Library/Phalcon/Internal/Test.php Line=973");
			//$k
			//$v
			//$o
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(v1, Z_STRVAL_P(v3), Z_STRLEN_P(v3), copy TSRMLS_CC);
			}
		}
	END_FOREACH(ac0, fes37, fee37, ah0, hp0);
	//$o
	phalcon_debug_vdump("Returning > ", v1 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v1);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p30 (Method) File=Library/Phalcon/Internal/Test.php Line=979");
}

PHP_METHOD(Phalcon_Internal_Test, p31){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p31", 0);
	phalcon_step_over("Phalcon_Internal_Test::p31 (Assignment) File=Library/Phalcon/Internal/Test.php Line=980");
	//$p
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(i0);
	v0 = i0;
	phalcon_debug_assign("$p", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::p31 (Assignment) File=Library/Phalcon/Internal/Test.php Line=981");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	//$p
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, a0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(v0, "a", strlen("a"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Internal_Test::p31 (For) File=Library/Phalcon/Internal/Test.php Line=982");
	//$i
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_LONG(v1, 0);
	fs39:
	//$i
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_SMALLER_FUNCTION(r0, v1, t0);
	if (!zend_is_true(r0)) {
		goto fe39;
	}
	phalcon_step_over("Phalcon_Internal_Test::p31 (Block) File=Library/Phalcon/Internal/Test.php Line=982");
	phalcon_step_over("Phalcon_Internal_Test::p31 (Assignment) File=Library/Phalcon/Internal/Test.php Line=983");
	//$f
	if (!i1) {
		PHALCON_ALLOC_ZVAL(i1);
	} else {
		if (Z_REFCOUNT_P(i1) > 1) {
			{
				zval *orig_ptr = i1;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(i1);
					*i1 = *orig_ptr;
					zval_copy_ctor(i1);
					Z_SET_REFCOUNT_P(i1, 1);
					Z_UNSET_ISREF_P(i1);
				}
			}
		} else {
			FREE_ZVAL(i1);
			PHALCON_ALLOC_ZVAL(i1);
		}
	}
	object_init(i1);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(i1);
	v2 = i1;
	phalcon_debug_assign("$f", i1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::p31 (Assignment) File=Library/Phalcon/Internal/Test.php Line=984");
	//$f
	//$p
	if (!t1) {
		PHALCON_ALLOC_ZVAL(t1);
	} else {
		if (Z_REFCOUNT_P(t1) > 1) {
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
		} else {
			FREE_ZVAL(t1);
			PHALCON_ALLOC_ZVAL(t1);
		}
	}
	phalcon_read_property(t1, v0, "a", sizeof("a")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v2, 1, 0);
		Z_SET_REFCOUNT_P(copy, 1);
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
		phalcon_array_append(t1, copy TSRMLS_CC);
	}
	//$p
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(v0, "a", strlen("a"), copy TSRMLS_CC);
	}
	//$i
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
	phalcon_debug_vdump("PostIncrementing $i", v1);
	goto fs39;
	fe39:
	r0 = NULL;
	//$p
	phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p31 (Method) File=Library/Phalcon/Internal/Test.php Line=992");
}

PHP_METHOD(Phalcon_Internal_Test, sp1){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sp1", 0);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::sp1 (Method) File=Library/Phalcon/Internal/Test.php Line=996");
}

PHP_METHOD(Phalcon_Internal_Test, sp2){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sp2", 0);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp2", sizeof("_sp2")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::sp2 (Method) File=Library/Phalcon/Internal/Test.php Line=1000");
}

PHP_METHOD(Phalcon_Internal_Test, sp3){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sp3", 0);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp3", sizeof("_sp3")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::sp3 (Method) File=Library/Phalcon/Internal/Test.php Line=1004");
}

PHP_METHOD(Phalcon_Internal_Test, sp4){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sp4", 0);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp4", sizeof("_sp4")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::sp4 (Method) File=Library/Phalcon/Internal/Test.php Line=1008");
}

PHP_METHOD(Phalcon_Internal_Test, sp5){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sp5", 0);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp5", sizeof("_sp5")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::sp5 (Method) File=Library/Phalcon/Internal/Test.php Line=1012");
}

PHP_METHOD(Phalcon_Internal_Test, sp6){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sp6", 0);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp6", sizeof("_sp6")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::sp6 (Method) File=Library/Phalcon/Internal/Test.php Line=1016");
}

PHP_METHOD(Phalcon_Internal_Test, sp7){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sp7", 0);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp7", sizeof("_sp7")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::sp7 (Method) File=Library/Phalcon/Internal/Test.php Line=1020");
}

PHP_METHOD(Phalcon_Internal_Test, sp8){

	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sp8", 0);
	phalcon_step_over("Phalcon_Internal_Test::sp8 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1021");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "i can't handle anymore", 1);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, t0 TSRMLS_CC);
	t1 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::sp8 (Method) File=Library/Phalcon/Internal/Test.php Line=1025");
}

PHP_METHOD(Phalcon_Internal_Test, sp9){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "sp9", 0);
	phalcon_step_over("Phalcon_Internal_Test::sp9 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1026");
	//$a
	//$b
	PHALCON_ALLOC_ZVAL(r0);
	add_function(r0, v0, v1 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, r0 TSRMLS_CC);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::sp9 (Method) File=Library/Phalcon/Internal/Test.php Line=1030");
}

PHP_METHOD(Phalcon_Internal_Test, sp10){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "sp10", 0);
	phalcon_step_over("Phalcon_Internal_Test::sp10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1031");
	//$a
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, v0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sp10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1032");
	//$b
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp2", sizeof("_sp2")-1, v1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sp10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1033");
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	t1 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp2", sizeof("_sp2")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	add_function(r0, t0, t1 TSRMLS_CC);
	//$c
	PHALCON_ALLOC_ZVAL(r1);
	add_function(r1, r0, v2 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp3", sizeof("_sp3")-1, r1 TSRMLS_CC);
	t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp3", sizeof("_sp3")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t2) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t2);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t2);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sp10 (Method) File=Library/Phalcon/Internal/Test.php Line=1037");
}

PHP_METHOD(Phalcon_Internal_Test, sp11){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "sp11", 0);
	phalcon_step_over("Phalcon_Internal_Test::sp11 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1038");
	//$a
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, v0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sp11 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1039");
	//$b
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp2", sizeof("_sp2")-1, v1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sp11 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1040");
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	t1 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp2", sizeof("_sp2")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	add_function(r0, t0, t1 TSRMLS_CC);
	//$c
	PHALCON_ALLOC_ZVAL(r1);
	add_function(r1, r0, v2 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp3", sizeof("_sp3")-1, r1 TSRMLS_CC);
	t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp3", sizeof("_sp3")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t2) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t2);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t2);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sp11 (Method) File=Library/Phalcon/Internal/Test.php Line=1044");
}

PHP_METHOD(Phalcon_Internal_Test, cc1){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "cc1", 0);
	PHALCON_GET_CLASS_CONSTANT(t0, phalcon_internal_test_class_entry, "C1");
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
	phalcon_step_over("Phalcon_Internal_Test::cc1 (Method) File=Library/Phalcon/Internal/Test.php Line=1048");
}

PHP_METHOD(Phalcon_Internal_Test, cc2){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "cc2", 0);
	PHALCON_GET_CLASS_CONSTANT(t0, phalcon_internal_test_class_entry, "C2");
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
	phalcon_step_over("Phalcon_Internal_Test::cc2 (Method) File=Library/Phalcon/Internal/Test.php Line=1052");
}

PHP_METHOD(Phalcon_Internal_Test, cc3){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "cc3", 0);
	PHALCON_GET_CLASS_CONSTANT(t0, phalcon_internal_test_class_entry, "C3");
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
	phalcon_step_over("Phalcon_Internal_Test::cc3 (Method) File=Library/Phalcon/Internal/Test.php Line=1056");
}

PHP_METHOD(Phalcon_Internal_Test, cc4){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "cc4", 0);
	PHALCON_GET_CLASS_CONSTANT(t0, phalcon_internal_test_class_entry, "C4");
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
	phalcon_step_over("Phalcon_Internal_Test::cc4 (Method) File=Library/Phalcon/Internal/Test.php Line=1060");
}

PHP_METHOD(Phalcon_Internal_Test, cc5){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "cc5", 0);
	PHALCON_GET_CLASS_CONSTANT(t0, phalcon_internal_test_class_entry, "C5");
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
	phalcon_step_over("Phalcon_Internal_Test::cc5 (Method) File=Library/Phalcon/Internal/Test.php Line=1064");
}

PHP_METHOD(Phalcon_Internal_Test, cc6){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "cc6", 0);
	PHALCON_GET_CLASS_CONSTANT(t0, phalcon_internal_test_class_entry, "C6");
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
	phalcon_step_over("Phalcon_Internal_Test::cc6 (Method) File=Library/Phalcon/Internal/Test.php Line=1071");
}

PHP_METHOD(Phalcon_Internal_Test, is1){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is1", 0);
	phalcon_step_over("Phalcon_Internal_Test::is1 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1072");
	//$a
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_INIT_FALSE(t0);
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
	add_next_index_zval(a0, t0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is1 (If) File=Library/Phalcon/Internal/Test.php Line=1073");
	//$a
	eval_int = phalcon_array_isset_long(v0, 0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is1 (Block) File=Library/Phalcon/Internal/Test.php Line=1073");
		phalcon_step_out_entry();
		RETURN_LONG(1);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is1 (Block) File=Library/Phalcon/Internal/Test.php Line=1075");
		phalcon_step_out_entry();
		RETURN_LONG(2);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is1 (Method) File=Library/Phalcon/Internal/Test.php Line=1080");
}

PHP_METHOD(Phalcon_Internal_Test, is2){

	zval *v0 = NULL;
	zval *i0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is2", 0);
	phalcon_step_over("Phalcon_Internal_Test::is2 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1081");
	//$a
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(i0);
	v0 = i0;
	phalcon_debug_assign("$a", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is2 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1082");
	//$a
	phalcon_update_property_long(v0, "b", strlen("b"), 15 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is2 (If) File=Library/Phalcon/Internal/Test.php Line=1083");
	//$a
	eval_int = phalcon_isset_property(v0, "b", strlen("b") TSRMLS_CC);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is2 (Block) File=Library/Phalcon/Internal/Test.php Line=1083");
		phalcon_step_out_entry();
		RETURN_LONG(1);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is2 (Block) File=Library/Phalcon/Internal/Test.php Line=1085");
		phalcon_step_out_entry();
		RETURN_LONG(2);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is2 (Method) File=Library/Phalcon/Internal/Test.php Line=1090");
}

PHP_METHOD(Phalcon_Internal_Test, is3){

	zval *v0 = NULL;
	zval *a0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is3", 0);
	phalcon_step_over("Phalcon_Internal_Test::is3 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1091");
	//$a
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is3 (If) File=Library/Phalcon/Internal/Test.php Line=1092");
	//$a
	eval_int = phalcon_array_isset_long(v0, 0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is3 (Block) File=Library/Phalcon/Internal/Test.php Line=1092");
		phalcon_step_out_entry();
		RETURN_LONG(1);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is3 (Block) File=Library/Phalcon/Internal/Test.php Line=1094");
		phalcon_step_out_entry();
		RETURN_LONG(2);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is3 (Method) File=Library/Phalcon/Internal/Test.php Line=1099");
}

PHP_METHOD(Phalcon_Internal_Test, is4){

	zval *v0 = NULL;
	zval *i0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is4", 0);
	phalcon_step_over("Phalcon_Internal_Test::is4 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1100");
	//$a
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(i0);
	v0 = i0;
	phalcon_debug_assign("$a", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is4 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1101");
	//$a
	phalcon_update_property_long(v0, "c", strlen("c"), 10 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is4 (If) File=Library/Phalcon/Internal/Test.php Line=1102");
	//$a
	eval_int = phalcon_isset_property(v0, "b", strlen("b") TSRMLS_CC);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is4 (Block) File=Library/Phalcon/Internal/Test.php Line=1102");
		phalcon_step_out_entry();
		RETURN_LONG(1);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is4 (Block) File=Library/Phalcon/Internal/Test.php Line=1104");
		phalcon_step_out_entry();
		RETURN_LONG(2);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is4 (Method) File=Library/Phalcon/Internal/Test.php Line=1109");
}

PHP_METHOD(Phalcon_Internal_Test, is5){

	zval *v0 = NULL;
	zval *a0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is5", 0);
	phalcon_step_over("Phalcon_Internal_Test::is5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1110");
	//$a
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is5 (If) File=Library/Phalcon/Internal/Test.php Line=1111");
	//$a
	eval_int = phalcon_array_isset_long(v0, 0);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is5 (Block) File=Library/Phalcon/Internal/Test.php Line=1111");
		phalcon_step_out_entry();
		RETURN_LONG(1);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is5 (Block) File=Library/Phalcon/Internal/Test.php Line=1113");
		phalcon_step_out_entry();
		RETURN_LONG(2);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is5 (Method) File=Library/Phalcon/Internal/Test.php Line=1118");
}

PHP_METHOD(Phalcon_Internal_Test, is6){

	zval *v0 = NULL;
	zval *i0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is6", 0);
	phalcon_step_over("Phalcon_Internal_Test::is6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1119");
	//$a
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(i0);
	v0 = i0;
	phalcon_debug_assign("$a", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1120");
	//$a
	phalcon_update_property_long(v0, "c", strlen("c"), 10 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is6 (If) File=Library/Phalcon/Internal/Test.php Line=1121");
	//$a
	eval_int = phalcon_isset_property(v0, "b", strlen("b") TSRMLS_CC);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is6 (Block) File=Library/Phalcon/Internal/Test.php Line=1121");
		phalcon_step_out_entry();
		RETURN_LONG(1);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is6 (Block) File=Library/Phalcon/Internal/Test.php Line=1123");
		phalcon_step_out_entry();
		RETURN_LONG(2);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is6 (Method) File=Library/Phalcon/Internal/Test.php Line=1128");
}

PHP_METHOD(Phalcon_Internal_Test, is7){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is7", 0);
	phalcon_step_over("Phalcon_Internal_Test::is7 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1129");
	//$a
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_string(a0, "hello", 1);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is7 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1130");
	//$t
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_LONG(v1, 0);
	phalcon_step_over("Phalcon_Internal_Test::is7 (If) File=Library/Phalcon/Internal/Test.php Line=1131");
	//$t
	//$a
	eval_int = phalcon_array_isset(v0, v1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is7 (Block) File=Library/Phalcon/Internal/Test.php Line=1131");
		phalcon_step_out_entry();
		RETURN_LONG(1);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is7 (Block) File=Library/Phalcon/Internal/Test.php Line=1133");
		phalcon_step_out_entry();
		RETURN_LONG(2);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is7 (Method) File=Library/Phalcon/Internal/Test.php Line=1138");
}

PHP_METHOD(Phalcon_Internal_Test, is8){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is8", 0);
	phalcon_step_over("Phalcon_Internal_Test::is8 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1139");
	//$config
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(i0);
	v0 = i0;
	phalcon_debug_assign("$config", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is8 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1140");
	//$config
	phalcon_update_property_string(v0, "host", strlen("host"), "192.168.0.20" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is8 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1141");
	//$config
	phalcon_update_property_string(v0, "username", strlen("username"), "support" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is8 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1142");
	//$config
	phalcon_update_property_string(v0, "password", strlen("password"), "H45pov682v" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is8 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1143");
	//$config
	phalcon_update_property_string(v0, "name", strlen("name"), "demo" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is8 (If) File=Library/Phalcon/Internal/Test.php Line=1144");
	//$config
	eval_int = phalcon_isset_property(v0, "host", strlen("host") TSRMLS_CC);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is8 (Block) File=Library/Phalcon/Internal/Test.php Line=1144");
		//$config
		PHALCON_ALLOC_ZVAL(t0);
		phalcon_read_property(t0, v0, "host", sizeof("host")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is8 (Block) File=Library/Phalcon/Internal/Test.php Line=1146");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is8 (Method) File=Library/Phalcon/Internal/Test.php Line=1154");
}

PHP_METHOD(Phalcon_Internal_Test, un1){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "un1", 0);
	phalcon_step_over("Phalcon_Internal_Test::un1 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1155");
	//$a
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_INIT_FALSE(t0);
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
	add_next_index_zval(a0, t0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::un1 (Unset) File=Library/Phalcon/Internal/Test.php Line=1156");
	//$a
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
	phalcon_array_unset_long(v0, 0);
	//$a
	phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::un1 (Method) File=Library/Phalcon/Internal/Test.php Line=1160");
}

PHP_METHOD(Phalcon_Internal_Test, un2){

	zval *v0 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "un2", 0);
	phalcon_step_over("Phalcon_Internal_Test::un2 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1161");
	//$a
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_next_index_long(a1, 0);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
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
	add_assoc_zval(a0, "lost", a1);
	add_next_index_string(a0, "hello", 1);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::un2 (Unset) File=Library/Phalcon/Internal/Test.php Line=1165");
	//$a
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_string(r0, v0, "lost", strlen("lost"), PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_array_unset_long(r0, 1);
	//$a
	phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::un2 (Method) File=Library/Phalcon/Internal/Test.php Line=1169");
}

PHP_METHOD(Phalcon_Internal_Test, un3){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "un3", 0);
	phalcon_step_over("Phalcon_Internal_Test::un3 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1170");
	//$b
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_long(a0, 0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$b", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::un3 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1171");
	//$a
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	//$b
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
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
		add_next_index_zval(a1, copy);
	}
	add_next_index_string(a1, "hello", 1);
	if (v1) {
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(a1);
	v1 = a1;
	phalcon_debug_assign("$a", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::un3 (Unset) File=Library/Phalcon/Internal/Test.php Line=1175");
	//$a
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_long(r0, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_array_unset_long(r0, 1);
	//$b
	phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::un3 (Method) File=Library/Phalcon/Internal/Test.php Line=1182");
}

PHP_METHOD(Phalcon_Internal_Test, iof1){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "iof1", 0);
	phalcon_step_over("Phalcon_Internal_Test::iof1 (If) File=Library/Phalcon/Internal/Test.php Line=1183");
	//$this
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_instance_of(r0, this_ptr, phalcon_internal_test_class_entry TSRMLS_CC);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Internal_Test::iof1 (Block) File=Library/Phalcon/Internal/Test.php Line=1183");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Internal_Test::iof1 (Block) File=Library/Phalcon/Internal/Test.php Line=1185");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::iof1 (Method) File=Library/Phalcon/Internal/Test.php Line=1190");
}

PHP_METHOD(Phalcon_Internal_Test, iof2){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;
	zend_class_entry *ce0;

	phalcon_step_into_entry("Phalcon_Internal_Test", "iof2", 0);
	phalcon_step_over("Phalcon_Internal_Test::iof2 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1191");
	//$a
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(i0);
	v0 = i0;
	phalcon_debug_assign("$a", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::iof2 (If) File=Library/Phalcon/Internal/Test.php Line=1192");
	//$a
		ce0 = zend_fetch_class("stdclass", strlen("stdclass"), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_instance_of(r0, v0, ce0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Internal_Test::iof2 (Block) File=Library/Phalcon/Internal/Test.php Line=1192");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Internal_Test::iof2 (Block) File=Library/Phalcon/Internal/Test.php Line=1194");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::iof2 (Method) File=Library/Phalcon/Internal/Test.php Line=1199");
}

PHP_METHOD(Phalcon_Internal_Test, iof3){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "iof3", 0);
	phalcon_step_over("Phalcon_Internal_Test::iof3 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1200");
	//$a
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_internal_testparent_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(i0);
	v0 = i0;
	phalcon_debug_assign("$a", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::iof3 (If) File=Library/Phalcon/Internal/Test.php Line=1201");
	//$a
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_instance_of(r0, v0, phalcon_internal_testparent_class_entry TSRMLS_CC);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Internal_Test::iof3 (Block) File=Library/Phalcon/Internal/Test.php Line=1201");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Internal_Test::iof3 (Block) File=Library/Phalcon/Internal/Test.php Line=1203");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::iof3 (Method) File=Library/Phalcon/Internal/Test.php Line=1211");
}

PHP_METHOD(Phalcon_Internal_Test, t1){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "t1", 0);
	phalcon_step_over("Phalcon_Internal_Test::t1 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1212");
	//$k
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 17);
	phalcon_step_over("Phalcon_Internal_Test::t1 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1213");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 100);
	//$a
	{
		zval *orig_ptr = v1;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			ALLOC_ZVAL(v1);
			*v1 = *orig_ptr;
			zval_copy_ctor(v1);
			Z_SET_REFCOUNT_P(v1, 1);
			Z_UNSET_ISREF_P(v1);
		}
	}
	phalcon_array_update_long(v1, 0, t0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::t1 (Method) File=Library/Phalcon/Internal/Test.php Line=1216");
}

PHP_METHOD(Phalcon_Internal_Test, t2){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	phalcon_step_into_entry("Phalcon_Internal_Test", "t2", 0);
	phalcon_step_over("Phalcon_Internal_Test::t2 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1217");
	//$m
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_STRING(v0, "", 0);
	phalcon_step_over("Phalcon_Internal_Test::t2 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1218");
	//$a
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	add_next_index_long(a0, 4);
	if (v1) {
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(a0);
	v1 = a0;
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t2 (Foreach) File=Library/Phalcon/Internal/Test.php Line=1219");
	//$a
	//$v
	//$k
	FOREACH_KV(v1, ac0, fes40, fee40, ah0, hp0, v3, v2)
		phalcon_step_over("Phalcon_Internal_Test::t2 (Block) File=Library/Phalcon/Internal/Test.php Line=1219");
		phalcon_step_over("Phalcon_Internal_Test::t2 (MethodCall) File=Library/Phalcon/Internal/Test.php Line=1220");
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "t1" TSRMLS_CC);
		//$k
		Z_ADDREF_P(v3);
		p0[0] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		//$a
		Z_ADDREF_P(v1);
		p0[1] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "t1", 2, p0, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
		phalcon_step_over("Phalcon_Internal_Test::t2 (AssignOp) File=Library/Phalcon/Internal/Test.php Line=1221");
		//$m
		//$k
		//$a
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
		phalcon_array_fetch_long(r0, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
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
		concat_function(r1, v3, r0 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r2, v0, r1);
		//$m
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(r2);
		v0 = r2;
		phalcon_debug_assign("$m", r2 TSRMLS_CC);
	END_FOREACH(ac0, fes40, fee40, ah0, hp0);
	//$m
	phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::t2 (Method) File=Library/Phalcon/Internal/Test.php Line=1226");
}

PHP_METHOD(Phalcon_Internal_Test, t3){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "t3", 0);
	phalcon_step_over("Phalcon_Internal_Test::t3 (If) File=Library/Phalcon/Internal/Test.php Line=1227");
	//$b
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 5);
	PHALCON_MOD_FUNCTION(r0, v1, t0);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_EQUAL_FUNCTION(r1, r0, t1);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Internal_Test::t3 (Block) File=Library/Phalcon/Internal/Test.php Line=1227");
		t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(t2) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(t2);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(t2);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Internal_Test::t3 (Block) File=Library/Phalcon/Internal/Test.php Line=1229");
		//$b
		PHALCON_ALLOC_ZVAL(t3);
		ZVAL_LONG(t3, 15);
		PHALCON_ALLOC_ZVAL(r2);
		mul_function(r2, v1, t3 TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r2 TSRMLS_CC);
		phalcon_step_out_entry();
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(r2);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
			Z_SET_REFCOUNT_P(return_value, refcount);
		}
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::t3 (Method) File=Library/Phalcon/Internal/Test.php Line=1234");
}

PHP_METHOD(Phalcon_Internal_Test, t4){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "t4", 0);
	phalcon_step_over("Phalcon_Internal_Test::t4 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1235");
	//$b
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_LONG(v1, 25);
	phalcon_step_over("Phalcon_Internal_Test::t4 (If) File=Library/Phalcon/Internal/Test.php Line=1236");
	//$a
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 5);
	PHALCON_EQUAL_FUNCTION(r0, v0, t0);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Internal_Test::t4 (Block) File=Library/Phalcon/Internal/Test.php Line=1236");
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	} else {
		phalcon_step_over("Phalcon_Internal_Test::t4 (Block) File=Library/Phalcon/Internal/Test.php Line=1238");
		PHALCON_ALLOC_ZVAL(r1);
		//$b
		p0[0] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r1, "sqrt", 1, p0);
		phalcon_debug_vdump("sqrt > ", r1 TSRMLS_CC);
		//$a
		PHALCON_ALLOC_ZVAL(r2);
		add_function(r2, r1, v0 TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r2 TSRMLS_CC);
		phalcon_step_out_entry();
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(r2);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
			Z_SET_REFCOUNT_P(return_value, refcount);
		}
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::t4 (Method) File=Library/Phalcon/Internal/Test.php Line=1243");
}

PHP_METHOD(Phalcon_Internal_Test, t5){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "t5", 0);
	phalcon_step_over("Phalcon_Internal_Test::t5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1244");
	//$this
	phalcon_update_property_long(this_ptr, "_p0", strlen("_p0"), 0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1245");
	//$node
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
	phalcon_debug_assign("$node", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t5 (While) File=Library/Phalcon/Internal/Test.php Line=1246");
	ws41:
	PHALCON_INIT_TRUE(t0);
	if (!zend_is_true(t0)) {
		goto we41;
	}
	phalcon_step_over("Phalcon_Internal_Test::t5 (Block) File=Library/Phalcon/Internal/Test.php Line=1246");
	phalcon_step_over("Phalcon_Internal_Test::t5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1247");
	//$a
	//$b
	if (!r0) {
		PHALCON_ALLOC_ZVAL(r0);
	} else {
		if (Z_REFCOUNT_P(r0) > 1){ 
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
		}
	}
	mul_function(r0, v0, v1 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t5 (AssignOp) File=Library/Phalcon/Internal/Test.php Line=1248");
	//$a
	if (!t1) {
		PHALCON_ALLOC_ZVAL(t1);
	} else {
		if (Z_REFCOUNT_P(t1) > 1) {
			SEPARATE_ZVAL(&t1);
		} else {
			if (Z_TYPE_P(t1) != IS_LONG) {
				FREE_ZVAL(t1);
				PHALCON_ALLOC_ZVAL(t1);
			}
		}
	}
	ZVAL_LONG(t1, 10);
	PHALCON_ADD_FUNCTION(r1, v0, t1);
	//$a
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(r1);
	v0 = r1;
	phalcon_debug_assign("$a", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t5 (If) File=Library/Phalcon/Internal/Test.php Line=1249");
	//$this
	if (!t2) {
		PHALCON_ALLOC_ZVAL(t2);
	} else {
		if (Z_REFCOUNT_P(t2) > 1) {
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
		} else {
			FREE_ZVAL(t2);
			PHALCON_ALLOC_ZVAL(t2);
		}
	}
	phalcon_read_property(t2, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t2);
	if (!t3) {
		PHALCON_ALLOC_ZVAL(t3);
	} else {
		if (Z_REFCOUNT_P(t3) > 1) {
			SEPARATE_ZVAL(&t3);
		} else {
			if (Z_TYPE_P(t3) != IS_LONG) {
				FREE_ZVAL(t3);
				PHALCON_ALLOC_ZVAL(t3);
			}
		}
	}
	ZVAL_LONG(t3, 2);
	PHALCON_MOD_FUNCTION(r2, t2, t3);
	if (!t4) {
		PHALCON_ALLOC_ZVAL(t4);
	} else {
		if (Z_REFCOUNT_P(t4) > 1) {
			SEPARATE_ZVAL(&t4);
		} else {
			if (Z_TYPE_P(t4) != IS_LONG) {
				FREE_ZVAL(t4);
				PHALCON_ALLOC_ZVAL(t4);
			}
		}
	}
	ZVAL_LONG(t4, 0);
	PHALCON_EQUAL_FUNCTION(r3, r2, t4);
	if (zend_is_true(r3)) {
		phalcon_step_over("Phalcon_Internal_Test::t5 (Block) File=Library/Phalcon/Internal/Test.php Line=1249");
		phalcon_step_over("Phalcon_Internal_Test::t5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1250");
		if (!r4) {
			PHALCON_ALLOC_ZVAL(r4);
		} else {
			if (Z_REFCOUNT_P(r4) > 1) {
				{
					zval *orig_ptr = r4;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r4);
						*r4 = *orig_ptr;
						zval_copy_ctor(r4);
						Z_SET_REFCOUNT_P(r4, 1);
						Z_UNSET_ISREF_P(r4);
					}
				}
			} else {
				FREE_ZVAL(r4);
				PHALCON_ALLOC_ZVAL(r4);
			}
		}
		//$c
		if (!t5) {
			PHALCON_ALLOC_ZVAL(t5);
		} else {
			if (Z_REFCOUNT_P(t5) > 1) {
				SEPARATE_ZVAL(&t5);
			} else {
				if (Z_TYPE_P(t5) != IS_LONG) {
					FREE_ZVAL(t5);
					PHALCON_ALLOC_ZVAL(t5);
				}
			}
		}
		ZVAL_LONG(t5, 1);
		if (!r5) {
			PHALCON_ALLOC_ZVAL(r5);
		} else {
			if (Z_REFCOUNT_P(r5) > 1){ 
				{
					zval *orig_ptr = r5;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r5);
						*r5 = *orig_ptr;
						zval_copy_ctor(r5);
						Z_SET_REFCOUNT_P(r5, 1);
						Z_UNSET_ISREF_P(r5);
					}
				}
			}
		}
		add_function(r5, v2, t5 TSRMLS_CC);
		Z_ADDREF_P(r5);
		p0[0] = r5;
		phalcon_debug_param(r5 TSRMLS_CC);
		t6 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(t6);
		p0[1] = t6;
		phalcon_debug_param(t6 TSRMLS_CC);
		PHALCON_CALL_SELF_PARAMS(r4, this_ptr, "t4", 2, p0);
		phalcon_debug_vdump("SelfStaticReturn > ", r4 TSRMLS_CC);
		//$node
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r4, 1, 0);
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
	} else {
		phalcon_step_over("Phalcon_Internal_Test::t5 (Block) File=Library/Phalcon/Internal/Test.php Line=1251");
		phalcon_step_over("Phalcon_Internal_Test::t5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1252");
		if (!r6) {
			PHALCON_ALLOC_ZVAL(r6);
		} else {
			if (Z_REFCOUNT_P(r6) > 1) {
				{
					zval *orig_ptr = r6;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r6);
						*r6 = *orig_ptr;
						zval_copy_ctor(r6);
						Z_SET_REFCOUNT_P(r6, 1);
						Z_UNSET_ISREF_P(r6);
					}
				}
			} else {
				FREE_ZVAL(r6);
				PHALCON_ALLOC_ZVAL(r6);
			}
		}
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "t3" TSRMLS_CC);
		//$a
		Z_ADDREF_P(v0);
		p1[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		//$b
		Z_ADDREF_P(v1);
		p1[1] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r6, this_ptr, "t3", 2, p1, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r6 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
		//$node
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r6, 1, 0);
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
	}
	phalcon_step_over("Phalcon_Internal_Test::t5 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1254");
	//$b
	//$this
	if (!t7) {
		PHALCON_ALLOC_ZVAL(t7);
	} else {
		if (Z_REFCOUNT_P(t7) > 1) {
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
		} else {
			FREE_ZVAL(t7);
			PHALCON_ALLOC_ZVAL(t7);
		}
	}
	phalcon_read_property(t7, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t7);
	if (!t8) {
		PHALCON_ALLOC_ZVAL(t8);
	} else {
		if (Z_REFCOUNT_P(t8) > 1) {
			SEPARATE_ZVAL(&t8);
		} else {
			if (Z_TYPE_P(t8) != IS_LONG) {
				FREE_ZVAL(t8);
				PHALCON_ALLOC_ZVAL(t8);
			}
		}
	}
	ZVAL_LONG(t8, 3);
	if (!r7) {
		PHALCON_ALLOC_ZVAL(r7);
	} else {
		if (Z_REFCOUNT_P(r7) > 1){ 
			{
				zval *orig_ptr = r7;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(r7);
					*r7 = *orig_ptr;
					zval_copy_ctor(r7);
					Z_SET_REFCOUNT_P(r7, 1);
					Z_UNSET_ISREF_P(r7);
				}
			}
		}
	}
	mul_function(r7, t7, t8 TSRMLS_CC);
	if (v1) {
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r7);
	v1 = r7;
	phalcon_debug_assign("$b", r7 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t5 (PostIncDecOp) File=Library/Phalcon/Internal/Test.php Line=1255");
	//$this
	if (!t9) {
		PHALCON_ALLOC_ZVAL(t9);
	} else {
		if (Z_REFCOUNT_P(t9) > 1) {
			{
				zval *orig_ptr = t9;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(t9);
					*t9 = *orig_ptr;
					zval_copy_ctor(t9);
					Z_SET_REFCOUNT_P(t9, 1);
					Z_UNSET_ISREF_P(t9);
				}
			}
		} else {
			FREE_ZVAL(t9);
			PHALCON_ALLOC_ZVAL(t9);
		}
	}
	phalcon_read_property(t9, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t9);
	{
		zval *orig_ptr = t9;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(t9);
			*t9 = *orig_ptr;
			zval_copy_ctor(t9);
			Z_SET_REFCOUNT_P(t9, 1);
			Z_UNSET_ISREF_P(t9);
		}
	}
	increment_function(t9);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t9, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p0", strlen("_p0"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Internal_Test::t5 (If) File=Library/Phalcon/Internal/Test.php Line=1256");
	//$this
	if (!t10) {
		PHALCON_ALLOC_ZVAL(t10);
	} else {
		if (Z_REFCOUNT_P(t10) > 1) {
			{
				zval *orig_ptr = t10;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(t10);
					*t10 = *orig_ptr;
					zval_copy_ctor(t10);
					Z_SET_REFCOUNT_P(t10, 1);
					Z_UNSET_ISREF_P(t10);
				}
			}
		} else {
			FREE_ZVAL(t10);
			PHALCON_ALLOC_ZVAL(t10);
		}
	}
	phalcon_read_property(t10, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t10);
	if (!t11) {
		PHALCON_ALLOC_ZVAL(t11);
	} else {
		if (Z_REFCOUNT_P(t11) > 1) {
			SEPARATE_ZVAL(&t11);
		} else {
			if (Z_TYPE_P(t11) != IS_LONG) {
				FREE_ZVAL(t11);
				PHALCON_ALLOC_ZVAL(t11);
			}
		}
	}
	ZVAL_LONG(t11, 10);
	PHALCON_SMALLER_FUNCTION(r8, t11, t10);
	if (zend_is_true(r8)) {
		phalcon_step_over("Phalcon_Internal_Test::t5 (Block) File=Library/Phalcon/Internal/Test.php Line=1256");
		phalcon_step_over("Phalcon_Internal_Test::t5 (Break) File=Library/Phalcon/Internal/Test.php Line=1257");
		goto we41;
	}
	goto ws41;
	we41:
	t0 = NULL;
	//$node
	phalcon_debug_vdump("Returning > ", v3 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v3);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::t5 (Method) File=Library/Phalcon/Internal/Test.php Line=1263");
}

PHP_METHOD(Phalcon_Internal_Test, t6){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL;
	zval *p1[] = { NULL, NULL, NULL, NULL }, *p2[] = { NULL, NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "t6", 0);
	phalcon_step_over("Phalcon_Internal_Test::t6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1264");
	//$e
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_long(a0, 0);
	add_next_index_long(a0, 25);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(a0);
	v3 = a0;
	phalcon_debug_assign("$e", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t6 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1265");
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_internal_testparent_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t6 (For) File=Library/Phalcon/Internal/Test.php Line=1266");
	//$i
	PHALCON_ALLOC_ZVAL(v4);
	ZVAL_LONG(v4, 0);
	fs42:
	//$i
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_SMALLER_FUNCTION(r0, v4, t0);
	if (!zend_is_true(r0)) {
		goto fe42;
	}
	phalcon_step_over("Phalcon_Internal_Test::t6 (Block) File=Library/Phalcon/Internal/Test.php Line=1266");
	phalcon_step_over("Phalcon_Internal_Test::t6 (If) File=Library/Phalcon/Internal/Test.php Line=1267");
	//$i
	if (!t1) {
		PHALCON_ALLOC_ZVAL(t1);
	} else {
		if (Z_REFCOUNT_P(t1) > 1) {
			SEPARATE_ZVAL(&t1);
		} else {
			if (Z_TYPE_P(t1) != IS_LONG) {
				FREE_ZVAL(t1);
				PHALCON_ALLOC_ZVAL(t1);
			}
		}
	}
	ZVAL_LONG(t1, 5);
	PHALCON_SMALLER_FUNCTION(r1, v4, t1);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Internal_Test::t6 (Block) File=Library/Phalcon/Internal/Test.php Line=1267");
		phalcon_step_over("Phalcon_Internal_Test::t6 (AssignOp) File=Library/Phalcon/Internal/Test.php Line=1268");
		//$e
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
		phalcon_array_fetch_long(r2, v3, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!r3) {
			PHALCON_ALLOC_ZVAL(r3);
		} else {
			if (Z_REFCOUNT_P(r3) > 1) {
				{
					zval *orig_ptr = r3;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r3);
						*r3 = *orig_ptr;
						zval_copy_ctor(r3);
						Z_SET_REFCOUNT_P(r3, 1);
						Z_UNSET_ISREF_P(r3);
					}
				}
			} else {
				FREE_ZVAL(r3);
				PHALCON_ALLOC_ZVAL(r3);
			}
		}
		t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(t2);
		p1[0] = t2;
		phalcon_debug_param(t2 TSRMLS_CC);
		//$i
		Z_ADDREF_P(v4);
		p1[1] = v4;
		phalcon_debug_param(v4 TSRMLS_CC);
		//$a
		Z_ADDREF_P(v0);
		p1[2] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		//$b
		Z_ADDREF_P(v1);
		p1[3] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_STATIC_PARAMS(r3, "phalcon_internal_testparent", "smp6", 4, p1);
		phalcon_debug_vdump("StaticReturn > ", r3 TSRMLS_CC);
		PHALCON_ADD_FUNCTION(r4, r2, r3);
		//$e
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r4, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
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
			phalcon_array_update_long(v3, 1, copy TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_Internal_Test::t6 (Block) File=Library/Phalcon/Internal/Test.php Line=1269");
		phalcon_step_over("Phalcon_Internal_Test::t6 (AssignOp) File=Library/Phalcon/Internal/Test.php Line=1270");
		//$e
		if (!r5) {
			PHALCON_ALLOC_ZVAL(r5);
		} else {
			if (Z_REFCOUNT_P(r5) > 1) {
				{
					zval *orig_ptr = r5;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r5);
						*r5 = *orig_ptr;
						zval_copy_ctor(r5);
						Z_SET_REFCOUNT_P(r5, 1);
						Z_UNSET_ISREF_P(r5);
					}
				}
			} else {
				FREE_ZVAL(r5);
				PHALCON_ALLOC_ZVAL(r5);
			}
		}
		phalcon_array_fetch_long(r5, v3, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!r6) {
			PHALCON_ALLOC_ZVAL(r6);
		} else {
			if (Z_REFCOUNT_P(r6) > 1) {
				{
					zval *orig_ptr = r6;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r6);
						*r6 = *orig_ptr;
						zval_copy_ctor(r6);
						Z_SET_REFCOUNT_P(r6, 1);
						Z_UNSET_ISREF_P(r6);
					}
				}
			} else {
				FREE_ZVAL(r6);
				PHALCON_ALLOC_ZVAL(r6);
			}
		}
		t3 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(t3);
		p2[0] = t3;
		phalcon_debug_param(t3 TSRMLS_CC);
		//$e
		if (!r7) {
			PHALCON_ALLOC_ZVAL(r7);
		} else {
			if (Z_REFCOUNT_P(r7) > 1) {
				{
					zval *orig_ptr = r7;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r7);
						*r7 = *orig_ptr;
						zval_copy_ctor(r7);
						Z_SET_REFCOUNT_P(r7, 1);
						Z_UNSET_ISREF_P(r7);
					}
				}
			} else {
				FREE_ZVAL(r7);
				PHALCON_ALLOC_ZVAL(r7);
			}
		}
		phalcon_array_fetch_long(r7, v3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *orig_ptr = r7;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(r7);
				*r7 = *orig_ptr;
				zval_copy_ctor(r7);
				Z_SET_REFCOUNT_P(r7, 1);
				Z_UNSET_ISREF_P(r7);
			}
		}
		if (!t4) {
			PHALCON_ALLOC_ZVAL(t4);
		} else {
			if (Z_REFCOUNT_P(t4) > 1) {
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
			} else {
				FREE_ZVAL(t4);
				PHALCON_ALLOC_ZVAL(t4);
			}
		}
		ZVAL_ZVAL(t4, r7, 1, 0);
		increment_function(r7);
		//$e
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r7, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
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
			phalcon_array_update_long(v3, 0, copy TSRMLS_CC);
		}
		Z_ADDREF_P(t4);
		p2[1] = t4;
		phalcon_debug_param(t4 TSRMLS_CC);
		//$b
		Z_ADDREF_P(v1);
		p2[2] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		//$c
		Z_ADDREF_P(v2);
		p2[3] = v2;
		phalcon_debug_param(v2 TSRMLS_CC);
		PHALCON_CALL_SELF_PARAMS(r6, this_ptr, "smp6", 4, p2);
		phalcon_debug_vdump("SelfStaticReturn > ", r6 TSRMLS_CC);
		PHALCON_ADD_FUNCTION(r8, r5, r6);
		//$e
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r8, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
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
			phalcon_array_update_long(v3, 1, copy TSRMLS_CC);
		}
	}
	//$i
	{
		zval *orig_ptr = v4;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(v4);
			*v4 = *orig_ptr;
			zval_copy_ctor(v4);
			Z_SET_REFCOUNT_P(v4, 1);
			Z_UNSET_ISREF_P(v4);
		}
	}
	increment_function(v4);
	phalcon_debug_vdump("PostIncrementing $i", v4);
	goto fs42;
	fe42:
	r0 = NULL;
	//$e
	PHALCON_ALLOC_ZVAL(r9);
	phalcon_array_fetch_long(r9, v3, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r10);
	t5 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(t5, "mp7" TSRMLS_CC);
	PHALCON_CALL_METHOD(r10, t5, "mp7", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r10 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r11);
	add_function(r11, r9, r10 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r11 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r11);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::t6 (Method) File=Library/Phalcon/Internal/Test.php Line=1276");
}

PHP_METHOD(Phalcon_Internal_Test, t7){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL;
	zval *p1[] = { NULL, NULL, NULL, NULL }, *p2[] = { NULL, NULL, NULL, NULL }, *p3[] = { NULL, NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "t7", 0);
	phalcon_step_over("Phalcon_Internal_Test::t7 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1277");
	//$e
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_long(a0, 0);
	add_next_index_long(a0, 25);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(a0);
	v2 = a0;
	phalcon_debug_assign("$e", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t7 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1278");
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_internal_testparent_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t7 (For) File=Library/Phalcon/Internal/Test.php Line=1279");
	//$i
	PHALCON_ALLOC_ZVAL(v3);
	ZVAL_LONG(v3, 0);
	fs43:
	//$i
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_SMALLER_FUNCTION(r0, v3, t0);
	if (!zend_is_true(r0)) {
		goto fe43;
	}
	phalcon_step_over("Phalcon_Internal_Test::t7 (Block) File=Library/Phalcon/Internal/Test.php Line=1279");
	phalcon_step_over("Phalcon_Internal_Test::t7 (For) File=Library/Phalcon/Internal/Test.php Line=1280");
	//$j
	//$a
	if (v4) {
		Z_DELREF_P(v4);
		if (!Z_REFCOUNT_P(v4)) {
			FREE_ZVAL(v4);
		}
	}
	Z_ADDREF_P(v0);
	v4 = v0;
	phalcon_debug_assign("$j", v0 TSRMLS_CC);
	fs44:
	//$j
	if (!t1) {
		PHALCON_ALLOC_ZVAL(t1);
	} else {
		if (Z_REFCOUNT_P(t1) > 1) {
			SEPARATE_ZVAL(&t1);
		} else {
			if (Z_TYPE_P(t1) != IS_LONG) {
				FREE_ZVAL(t1);
				PHALCON_ALLOC_ZVAL(t1);
			}
		}
	}
	ZVAL_LONG(t1, 0);
	PHALCON_SMALLER_FUNCTION(r1, t1, v4);
	if (!zend_is_true(r1)) {
		goto fe44;
	}
	phalcon_step_over("Phalcon_Internal_Test::t7 (Block) File=Library/Phalcon/Internal/Test.php Line=1280");
	phalcon_step_over("Phalcon_Internal_Test::t7 (If) File=Library/Phalcon/Internal/Test.php Line=1281");
	//$i
	if (!t2) {
		PHALCON_ALLOC_ZVAL(t2);
	} else {
		if (Z_REFCOUNT_P(t2) > 1) {
			SEPARATE_ZVAL(&t2);
		} else {
			if (Z_TYPE_P(t2) != IS_LONG) {
				FREE_ZVAL(t2);
				PHALCON_ALLOC_ZVAL(t2);
			}
		}
	}
	ZVAL_LONG(t2, 5);
	PHALCON_SMALLER_FUNCTION(r2, v3, t2);
	if (zend_is_true(r2)) {
		phalcon_step_over("Phalcon_Internal_Test::t7 (Block) File=Library/Phalcon/Internal/Test.php Line=1281");
		phalcon_step_over("Phalcon_Internal_Test::t7 (AssignOp) File=Library/Phalcon/Internal/Test.php Line=1282");
		//$e
		if (!r3) {
			PHALCON_ALLOC_ZVAL(r3);
		} else {
			if (Z_REFCOUNT_P(r3) > 1) {
				{
					zval *orig_ptr = r3;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r3);
						*r3 = *orig_ptr;
						zval_copy_ctor(r3);
						Z_SET_REFCOUNT_P(r3, 1);
						Z_UNSET_ISREF_P(r3);
					}
				}
			} else {
				FREE_ZVAL(r3);
				PHALCON_ALLOC_ZVAL(r3);
			}
		}
		phalcon_array_fetch_long(r3, v2, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!r4) {
			PHALCON_ALLOC_ZVAL(r4);
		} else {
			if (Z_REFCOUNT_P(r4) > 1) {
				{
					zval *orig_ptr = r4;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r4);
						*r4 = *orig_ptr;
						zval_copy_ctor(r4);
						Z_SET_REFCOUNT_P(r4, 1);
						Z_UNSET_ISREF_P(r4);
					}
				}
			} else {
				FREE_ZVAL(r4);
				PHALCON_ALLOC_ZVAL(r4);
			}
		}
		t3 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(t3);
		p1[0] = t3;
		phalcon_debug_param(t3 TSRMLS_CC);
		//$i
		Z_ADDREF_P(v3);
		p1[1] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		//$a
		Z_ADDREF_P(v0);
		p1[2] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		//$b
		Z_ADDREF_P(v1);
		p1[3] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_STATIC_PARAMS(r4, "phalcon_internal_testparent", "smp6", 4, p1);
		phalcon_debug_vdump("StaticReturn > ", r4 TSRMLS_CC);
		PHALCON_ADD_FUNCTION(r5, r3, r4);
		//$e
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r5, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = v2;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(v2);
					*v2 = *orig_ptr;
					zval_copy_ctor(v2);
					Z_SET_REFCOUNT_P(v2, 1);
					Z_UNSET_ISREF_P(v2);
				}
			}
			phalcon_array_update_long(v2, 1, copy TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_Internal_Test::t7 (Block) File=Library/Phalcon/Internal/Test.php Line=1283");
		phalcon_step_over("Phalcon_Internal_Test::t7 (If) File=Library/Phalcon/Internal/Test.php Line=1284");
		//$j
		if (!t4) {
			PHALCON_ALLOC_ZVAL(t4);
		} else {
			if (Z_REFCOUNT_P(t4) > 1) {
				SEPARATE_ZVAL(&t4);
			} else {
				if (Z_TYPE_P(t4) != IS_LONG) {
					FREE_ZVAL(t4);
					PHALCON_ALLOC_ZVAL(t4);
				}
			}
		}
		ZVAL_LONG(t4, 4);
		PHALCON_SMALLER_FUNCTION(r6, t4, v4);
		if (zend_is_true(r6)) {
			phalcon_step_over("Phalcon_Internal_Test::t7 (Block) File=Library/Phalcon/Internal/Test.php Line=1284");
			phalcon_step_over("Phalcon_Internal_Test::t7 (AssignOp) File=Library/Phalcon/Internal/Test.php Line=1285");
			//$e
			if (!r7) {
				PHALCON_ALLOC_ZVAL(r7);
			} else {
				if (Z_REFCOUNT_P(r7) > 1) {
					{
						zval *orig_ptr = r7;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r7);
							*r7 = *orig_ptr;
							zval_copy_ctor(r7);
							Z_SET_REFCOUNT_P(r7, 1);
							Z_UNSET_ISREF_P(r7);
						}
					}
				} else {
					FREE_ZVAL(r7);
					PHALCON_ALLOC_ZVAL(r7);
				}
			}
			phalcon_array_fetch_long(r7, v2, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (!r8) {
				PHALCON_ALLOC_ZVAL(r8);
			} else {
				if (Z_REFCOUNT_P(r8) > 1) {
					{
						zval *orig_ptr = r8;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r8);
							*r8 = *orig_ptr;
							zval_copy_ctor(r8);
							Z_SET_REFCOUNT_P(r8, 1);
							Z_UNSET_ISREF_P(r8);
						}
					}
				} else {
					FREE_ZVAL(r8);
					PHALCON_ALLOC_ZVAL(r8);
				}
			}
			t5 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			Z_ADDREF_P(t5);
			p2[0] = t5;
			phalcon_debug_param(t5 TSRMLS_CC);
			//$e
			if (!r9) {
				PHALCON_ALLOC_ZVAL(r9);
			} else {
				if (Z_REFCOUNT_P(r9) > 1) {
					{
						zval *orig_ptr = r9;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r9);
							*r9 = *orig_ptr;
							zval_copy_ctor(r9);
							Z_SET_REFCOUNT_P(r9, 1);
							Z_UNSET_ISREF_P(r9);
						}
					}
				} else {
					FREE_ZVAL(r9);
					PHALCON_ALLOC_ZVAL(r9);
				}
			}
			phalcon_array_fetch_long(r9, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			{
				zval *orig_ptr = r9;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(r9);
					*r9 = *orig_ptr;
					zval_copy_ctor(r9);
					Z_SET_REFCOUNT_P(r9, 1);
					Z_UNSET_ISREF_P(r9);
				}
			}
			decrement_function(r9);
			//$e
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r9, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				{
					zval *orig_ptr = v2;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(v2);
						*v2 = *orig_ptr;
						zval_copy_ctor(v2);
						Z_SET_REFCOUNT_P(v2, 1);
						Z_UNSET_ISREF_P(v2);
					}
				}
				phalcon_array_update_long(v2, 0, copy TSRMLS_CC);
			}
			Z_ADDREF_P(r9);
			p2[1] = r9;
			phalcon_debug_param(r9 TSRMLS_CC);
			//$b
			Z_ADDREF_P(v1);
			p2[2] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			//$j
			Z_ADDREF_P(v4);
			p2[3] = v4;
			phalcon_debug_param(v4 TSRMLS_CC);
			PHALCON_CALL_SELF_PARAMS(r8, this_ptr, "smp6", 4, p2);
			phalcon_debug_vdump("SelfStaticReturn > ", r8 TSRMLS_CC);
			PHALCON_ADD_FUNCTION(r10, r7, r8);
			//$e
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r10, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				{
					zval *orig_ptr = v2;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(v2);
						*v2 = *orig_ptr;
						zval_copy_ctor(v2);
						Z_SET_REFCOUNT_P(v2, 1);
						Z_UNSET_ISREF_P(v2);
					}
				}
				phalcon_array_update_long(v2, 1, copy TSRMLS_CC);
			}
		} else {
			phalcon_step_over("Phalcon_Internal_Test::t7 (Block) File=Library/Phalcon/Internal/Test.php Line=1286");
			phalcon_step_over("Phalcon_Internal_Test::t7 (AssignOp) File=Library/Phalcon/Internal/Test.php Line=1287");
			//$e
			if (!r11) {
				PHALCON_ALLOC_ZVAL(r11);
			} else {
				if (Z_REFCOUNT_P(r11) > 1) {
					{
						zval *orig_ptr = r11;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r11);
							*r11 = *orig_ptr;
							zval_copy_ctor(r11);
							Z_SET_REFCOUNT_P(r11, 1);
							Z_UNSET_ISREF_P(r11);
						}
					}
				} else {
					FREE_ZVAL(r11);
					PHALCON_ALLOC_ZVAL(r11);
				}
			}
			phalcon_array_fetch_long(r11, v2, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (!r12) {
				PHALCON_ALLOC_ZVAL(r12);
			} else {
				if (Z_REFCOUNT_P(r12) > 1) {
					{
						zval *orig_ptr = r12;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r12);
							*r12 = *orig_ptr;
							zval_copy_ctor(r12);
							Z_SET_REFCOUNT_P(r12, 1);
							Z_UNSET_ISREF_P(r12);
						}
					}
				} else {
					FREE_ZVAL(r12);
					PHALCON_ALLOC_ZVAL(r12);
				}
			}
			t6 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			Z_ADDREF_P(t6);
			p3[0] = t6;
			phalcon_debug_param(t6 TSRMLS_CC);
			//$e
			if (!r13) {
				PHALCON_ALLOC_ZVAL(r13);
			} else {
				if (Z_REFCOUNT_P(r13) > 1) {
					{
						zval *orig_ptr = r13;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r13);
							*r13 = *orig_ptr;
							zval_copy_ctor(r13);
							Z_SET_REFCOUNT_P(r13, 1);
							Z_UNSET_ISREF_P(r13);
						}
					}
				} else {
					FREE_ZVAL(r13);
					PHALCON_ALLOC_ZVAL(r13);
				}
			}
			phalcon_array_fetch_long(r13, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			{
				zval *orig_ptr = r13;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(r13);
					*r13 = *orig_ptr;
					zval_copy_ctor(r13);
					Z_SET_REFCOUNT_P(r13, 1);
					Z_UNSET_ISREF_P(r13);
				}
			}
			if (!t7) {
				PHALCON_ALLOC_ZVAL(t7);
			} else {
				if (Z_REFCOUNT_P(t7) > 1) {
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
				} else {
					FREE_ZVAL(t7);
					PHALCON_ALLOC_ZVAL(t7);
				}
			}
			ZVAL_ZVAL(t7, r13, 1, 0);
			increment_function(r13);
			//$e
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r13, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				{
					zval *orig_ptr = v2;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(v2);
						*v2 = *orig_ptr;
						zval_copy_ctor(v2);
						Z_SET_REFCOUNT_P(v2, 1);
						Z_UNSET_ISREF_P(v2);
					}
				}
				phalcon_array_update_long(v2, 0, copy TSRMLS_CC);
			}
			Z_ADDREF_P(t7);
			p3[1] = t7;
			phalcon_debug_param(t7 TSRMLS_CC);
			//$a
			Z_ADDREF_P(v0);
			p3[2] = v0;
			phalcon_debug_param(v0 TSRMLS_CC);
			//$j
			Z_ADDREF_P(v4);
			p3[3] = v4;
			phalcon_debug_param(v4 TSRMLS_CC);
			PHALCON_CALL_SELF_PARAMS(r12, this_ptr, "smp6", 4, p3);
			phalcon_debug_vdump("SelfStaticReturn > ", r12 TSRMLS_CC);
			PHALCON_ADD_FUNCTION(r14, r11, r12);
			//$e
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r14, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				{
					zval *orig_ptr = v2;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(v2);
						*v2 = *orig_ptr;
						zval_copy_ctor(v2);
						Z_SET_REFCOUNT_P(v2, 1);
						Z_UNSET_ISREF_P(v2);
					}
				}
				phalcon_array_update_long(v2, 1, copy TSRMLS_CC);
			}
		}
	}
	//$j
	{
		zval *orig_ptr = v4;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(v4);
			*v4 = *orig_ptr;
			zval_copy_ctor(v4);
			Z_SET_REFCOUNT_P(v4, 1);
			Z_UNSET_ISREF_P(v4);
		}
	}
	decrement_function(v4);
	phalcon_debug_vdump("PostDecrementing $j", v4);
	goto fs44;
	fe44:
	r1 = NULL;
	//$i
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
	increment_function(v3);
	phalcon_debug_vdump("PostIncrementing $i", v3);
	goto fs43;
	fe43:
	r0 = NULL;
	//$e
	PHALCON_ALLOC_ZVAL(r15);
	phalcon_array_fetch_long(r15, v2, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r16);
	t8 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(t8, "mp7" TSRMLS_CC);
	PHALCON_CALL_METHOD(r16, t8, "mp7", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r16 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r17);
	add_function(r17, r15, r16 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r17 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r17);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::t7 (Method) File=Library/Phalcon/Internal/Test.php Line=1295");
}

PHP_METHOD(Phalcon_Internal_Test, t8){

	zval *v0 = NULL, *v1 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "t8", 0);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::t8 (Method) File=Library/Phalcon/Internal/Test.php Line=1299");
}

PHP_METHOD(Phalcon_Internal_Test, t9){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL, NULL }, *p2[] = { NULL, NULL, NULL };

	phalcon_step_into_entry("Phalcon_Internal_Test", "t9", 0);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1301");
	//$notNull
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_string(a0, "cedula", 1);
	add_next_index_string(a0, "nombre", 1);
	add_next_index_string(a0, "saldo", 1);
	add_next_index_string(a0, "estado", 1);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$notNull", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1308");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, a1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p0", strlen("_p0"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1310");
	//$record
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	if (v1) {
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(i0);
	v1 = i0;
	phalcon_debug_assign("$record", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1311");
	//$record
	phalcon_update_property_string(v1, "cedula", strlen("cedula"), "hello" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1312");
	//$record
	zend_update_property_null(Z_OBJCE_P(v1), v1, "nombre", strlen("nombre") TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1313");
	//$record
	zend_update_property_null(Z_OBJCE_P(v1), v1, "saldo", strlen("saldo") TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1314");
	//$record
	zend_update_property_null(Z_OBJCE_P(v1), v1, "estado", strlen("estado") TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1316");
	//$numFields
	PHALCON_ALLOC_ZVAL(r0);
	//$notNull
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "count", 1, p0);
	phalcon_debug_vdump("count > ", r0 TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r0);
	v2 = r0;
	phalcon_debug_assign("$numFields", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (For) File=Library/Phalcon/Internal/Test.php Line=1317");
	//$i
	PHALCON_ALLOC_ZVAL(v3);
	ZVAL_LONG(v3, 0);
	fs45:
	//$i
	//$numFields
	PHALCON_SMALLER_FUNCTION(r1, v3, v2);
	if (!zend_is_true(r1)) {
		goto fe45;
	}
	phalcon_step_over("Phalcon_Internal_Test::t9 (Block) File=Library/Phalcon/Internal/Test.php Line=1317");
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1319");
	//$field
	//$i
	//$notNull
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
	phalcon_array_fetch(r2, v0, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (v4) {
		Z_DELREF_P(v4);
		if (!Z_REFCOUNT_P(v4)) {
			FREE_ZVAL(v4);
		}
	}
	Z_ADDREF_P(r2);
	v4 = r2;
	phalcon_debug_assign("$field", r2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1320");
	//$value
	//$record
	if (!t0) {
		PHALCON_ALLOC_ZVAL(t0);
	} else {
		if (Z_REFCOUNT_P(t0) > 1) {
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
		} else {
			FREE_ZVAL(t0);
			PHALCON_ALLOC_ZVAL(t0);
		}
	}
	//$field
	phalcon_read_property_zval(t0, v1, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (v5) {
		Z_DELREF_P(v5);
		if (!Z_REFCOUNT_P(v5)) {
			FREE_ZVAL(v5);
		}
	}
	Z_ADDREF_P(t0);
	v5 = t0;
	phalcon_debug_assign("$value", t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1322");
	//$humanField
	if (!r3) {
		PHALCON_ALLOC_ZVAL(r3);
	} else {
		if (Z_REFCOUNT_P(r3) > 1) {
			{
				zval *orig_ptr = r3;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(r3);
					*r3 = *orig_ptr;
					zval_copy_ctor(r3);
					Z_SET_REFCOUNT_P(r3, 1);
					Z_UNSET_ISREF_P(r3);
				}
			}
		} else {
			FREE_ZVAL(r3);
			PHALCON_ALLOC_ZVAL(r3);
		}
	}
	if (!p1[0]) {
		PHALCON_ALLOC_ZVAL(p1[0]);
	} else {
		if (Z_REFCOUNT_P(p1[0]) > 1) {
			SEPARATE_ZVAL(&p1[0]);
		} else {
			if (Z_TYPE_P(p1[0]) != IS_STRING) {
				FREE_ZVAL(p1[0]);
				PHALCON_ALLOC_ZVAL(p1[0]);
			}
		}
	}
	ZVAL_STRING(p1[0], "_id", 1);
	if (!p1[1]) {
		PHALCON_ALLOC_ZVAL(p1[1]);
	} else {
		if (Z_REFCOUNT_P(p1[1]) > 1) {
			SEPARATE_ZVAL(&p1[1]);
		} else {
			if (Z_TYPE_P(p1[1]) != IS_STRING) {
				FREE_ZVAL(p1[1]);
				PHALCON_ALLOC_ZVAL(p1[1]);
			}
		}
	}
	ZVAL_STRING(p1[1], "", 1);
	//$field
	p1[2] = v4;
	phalcon_debug_param(v4 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r3, "str_replace", 3, p1);
	phalcon_debug_vdump("str_replace > ", r3 TSRMLS_CC);
	if (v6) {
		Z_DELREF_P(v6);
		if (!Z_REFCOUNT_P(v6)) {
			FREE_ZVAL(v6);
		}
	}
	Z_ADDREF_P(r3);
	v6 = r3;
	phalcon_debug_assign("$humanField", r3 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1323");
	//$message
	if (!i1) {
		PHALCON_ALLOC_ZVAL(i1);
	} else {
		if (Z_REFCOUNT_P(i1) > 1) {
			{
				zval *orig_ptr = i1;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(i1);
					*i1 = *orig_ptr;
					zval_copy_ctor(i1);
					Z_SET_REFCOUNT_P(i1, 1);
					Z_UNSET_ISREF_P(i1);
				}
			}
		} else {
			FREE_ZVAL(i1);
			PHALCON_ALLOC_ZVAL(i1);
		}
	}
	object_init_ex(i1, phalcon_model_message_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
	//$humanField
	if (!r4) {
		PHALCON_ALLOC_ZVAL(r4);
	} else {
		if (Z_REFCOUNT_P(r4) > 1) {
			{
				zval *orig_ptr = r4;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(r4);
					*r4 = *orig_ptr;
					zval_copy_ctor(r4);
					Z_SET_REFCOUNT_P(r4, 1);
					Z_UNSET_ISREF_P(r4);
				}
			}
		} else {
			FREE_ZVAL(r4);
			PHALCON_ALLOC_ZVAL(r4);
		}
	}
	phalcon_concat_right(r4, v6, " is required" TSRMLS_CC);
	Z_ADDREF_P(r4);
	p2[0] = r4;
	phalcon_debug_param(r4 TSRMLS_CC);
	//$field
	Z_ADDREF_P(v4);
	p2[1] = v4;
	phalcon_debug_param(v4 TSRMLS_CC);
	if (!p2[2]) {
		PHALCON_ALLOC_ZVAL(p2[2]);
	} else {
		if (Z_REFCOUNT_P(p2[2]) > 1) {
			SEPARATE_ZVAL(&p2[2]);
		} else {
			if (Z_TYPE_P(p2[2]) != IS_STRING) {
				FREE_ZVAL(p2[2]);
				PHALCON_ALLOC_ZVAL(p2[2]);
			}
		}
	}
	ZVAL_STRING(p2[2], "PresenceOf", 1);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 3, p2, PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	if (v7) {
		Z_DELREF_P(v7);
		if (!Z_REFCOUNT_P(v7)) {
			FREE_ZVAL(v7);
		}
	}
	Z_ADDREF_P(i1);
	v7 = i1;
	phalcon_debug_assign("$message", i1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1324");
	//$message
	//$this
	if (!t1) {
		PHALCON_ALLOC_ZVAL(t1);
	} else {
		if (Z_REFCOUNT_P(t1) > 1) {
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
		} else {
			FREE_ZVAL(t1);
			PHALCON_ALLOC_ZVAL(t1);
		}
	}
	phalcon_read_property(t1, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v7, 1, 0);
		Z_SET_REFCOUNT_P(copy, 1);
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
		phalcon_array_append(t1, copy TSRMLS_CC);
	}
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p0", strlen("_p0"), copy TSRMLS_CC);
	}
	//$i
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
	increment_function(v3);
	phalcon_debug_vdump("PreIncrementing $i", v3);
	goto fs45;
	fe45:
	r1 = NULL;
	//$this
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t2);
	phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t2) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t2);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t2);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::t9 (Method) File=Library/Phalcon/Internal/Test.php Line=1332");
}

PHP_METHOD(Phalcon_Internal_Test, t10){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *i0 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "t10", 0);
	phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1334");
	//$attributes
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_string(a0, "cedula", 1);
	add_next_index_string(a0, "nombre", 1);
	add_next_index_string(a0, "saldo", 1);
	add_next_index_string(a0, "estado", 1);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(a0);
	v0 = a0;
	phalcon_debug_assign("$attributes", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1341");
	//$dataTypeNumeric
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	PHALCON_INIT_TRUE(t0);
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
	add_assoc_zval(a1, "saldo", t0);
	if (v1) {
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(a1);
	v1 = a1;
	phalcon_debug_assign("$dataTypeNumeric", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1345");
	//$record
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(i0);
	v2 = i0;
	phalcon_debug_assign("$record", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1346");
	//$record
	phalcon_update_property_string(v2, "cedula", strlen("cedula"), "hello" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1347");
	//$record
	phalcon_update_property_string(v2, "nombre", strlen("nombre"), "LOL" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1348");
	//$record
	phalcon_update_property_long(v2, "saldo", strlen("saldo"), 0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1349");
	//$record
	phalcon_update_property_string(v2, "estado", strlen("estado"), "X" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1351");
	//$values
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(a2);
	v3 = a2;
	phalcon_debug_assign("$values", a2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t10 (Foreach) File=Library/Phalcon/Internal/Test.php Line=1352");
	//$attributes
	//$field
	FOREACH_V(v0, ac0, fes46, fee46, ah0, hp0, v4)
		phalcon_step_over("Phalcon_Internal_Test::t10 (Block) File=Library/Phalcon/Internal/Test.php Line=1352");
		phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1353");
		//$value
		//$record
		if (!t1) {
			PHALCON_ALLOC_ZVAL(t1);
		} else {
			if (Z_REFCOUNT_P(t1) > 1) {
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
			} else {
				FREE_ZVAL(t1);
				PHALCON_ALLOC_ZVAL(t1);
			}
		}
		//$field
		phalcon_read_property_zval(t1, v2, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		if (v5) {
			Z_DELREF_P(v5);
			if (!Z_REFCOUNT_P(v5)) {
				FREE_ZVAL(v5);
			}
		}
		Z_ADDREF_P(t1);
		v5 = t1;
		phalcon_debug_assign("$value", t1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Internal_Test::t10 (If) File=Library/Phalcon/Internal/Test.php Line=1354");
		//$value
		if (!t2) {
			PHALCON_ALLOC_ZVAL(t2);
		} else {
			if (Z_REFCOUNT_P(t2) > 1) {
				SEPARATE_ZVAL(&t2);
			} else {
				if (Z_TYPE_P(t2) != IS_STRING) {
					FREE_ZVAL(t2);
					PHALCON_ALLOC_ZVAL(t2);
				}
			}
		}
		ZVAL_STRING(t2, "", 1);
		PHALCON_IDENTICAL_FUNCTION(r0, v5, t2);
		//$value
		PHALCON_INIT_NULL(t3);
		PHALCON_IDENTICAL_FUNCTION(r1, v5, t3);
		PHALCON_OR_FUNCTION(r2, r0, r1);
		if (zend_is_true(r2)) {
			phalcon_step_over("Phalcon_Internal_Test::t10 (Block) File=Library/Phalcon/Internal/Test.php Line=1354");
			phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1355");
			if (!t4) {
				PHALCON_ALLOC_ZVAL(t4);
			} else {
				if (Z_REFCOUNT_P(t4) > 1) {
					SEPARATE_ZVAL(&t4);
				} else {
					if (Z_TYPE_P(t4) != IS_STRING) {
						FREE_ZVAL(t4);
						PHALCON_ALLOC_ZVAL(t4);
					}
				}
			}
			ZVAL_STRING(t4, "NULL", 1);
			//$values
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, t4, 1, 0);
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
		} else {
			phalcon_step_over("Phalcon_Internal_Test::t10 (Block) File=Library/Phalcon/Internal/Test.php Line=1356");
			phalcon_step_over("Phalcon_Internal_Test::t10 (If) File=Library/Phalcon/Internal/Test.php Line=1357");
			//$field
			//$dataTypeNumeric
			eval_int = phalcon_array_isset(v1, v4);
			if (eval_int) {
				phalcon_step_over("Phalcon_Internal_Test::t10 (Block) File=Library/Phalcon/Internal/Test.php Line=1357");
				phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1358");
				//$value
				//$values
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v5, 1, 0);
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
			} else {
				phalcon_step_over("Phalcon_Internal_Test::t10 (Block) File=Library/Phalcon/Internal/Test.php Line=1359");
				phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1360");
				//$value
				if (!r3) {
					PHALCON_ALLOC_ZVAL(r3);
				} else {
					if (Z_REFCOUNT_P(r3) > 1) {
						{
							zval *orig_ptr = r3;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r3);
								*r3 = *orig_ptr;
								zval_copy_ctor(r3);
								Z_SET_REFCOUNT_P(r3, 1);
								Z_UNSET_ISREF_P(r3);
							}
						}
					} else {
						FREE_ZVAL(r3);
						PHALCON_ALLOC_ZVAL(r3);
					}
				}
				phalcon_concat_both(r3,  "'", v5, "'" TSRMLS_CC);
				//$values
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, r3, 1, 0);
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
			}
		}
	END_FOREACH(ac0, fes46, fee46, ah0, hp0);
	phalcon_step_over("Phalcon_Internal_Test::t10 (FunctionCall) File=Library/Phalcon/Internal/Test.php Line=1365");
	//$values
	p0[0] = v3;
	phalcon_debug_param(v3 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("print_r", 1, p0);
	//$values
	phalcon_debug_vdump("Returning > ", v3 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v3);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::t10 (Method) File=Library/Phalcon/Internal/Test.php Line=1370");
}

PHP_METHOD(Phalcon_Internal_Test, t11){

	zval *v0 = NULL, *v1 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	phalcon_step_into_entry("Phalcon_Internal_Test", "t11", 0);
	phalcon_step_over("Phalcon_Internal_Test::t11 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1371");
	//$n
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 0);
	phalcon_step_over("Phalcon_Internal_Test::t11 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1372");
	//$this
	phalcon_update_property_string(this_ptr, "_p2", strlen("_p2"), "lol" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t11 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1373");
	//$this
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_p4", strlen("_p4"), 0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t11 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1374");
	//$dummy
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_internal_testdummy_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
	//$this
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	phalcon_debug_param(this_ptr TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	if (v1) {
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(i0);
	v1 = i0;
	phalcon_debug_assign("$dummy", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t11 (While) File=Library/Phalcon/Internal/Test.php Line=1375");
	ws47:
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p4", sizeof("_p4")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	PHALCON_BOOLEAN_NOT_FUNCTION(r0, t0);
	if (!zend_is_true(r0)) {
		goto we47;
	}
	phalcon_step_over("Phalcon_Internal_Test::t11 (Block) File=Library/Phalcon/Internal/Test.php Line=1375");
	phalcon_step_over("Phalcon_Internal_Test::t11 (Echo) File=Library/Phalcon/Internal/Test.php Line=1376");
	//$this
	if (!t1) {
		PHALCON_ALLOC_ZVAL(t1);
	} else {
		if (Z_REFCOUNT_P(t1) > 1) {
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
		} else {
			FREE_ZVAL(t1);
			PHALCON_ALLOC_ZVAL(t1);
		}
	}
	phalcon_read_property(t1, this_ptr, "_p2", sizeof("_p2")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	zend_print_zval(t1, 0);
	php_printf(" ");
	//$n
	zend_print_zval(v0, 0);
	PHALCON_GET_CONSTANT(t2, "PHP_EOL");
	zend_print_zval(t2, 0);
	phalcon_step_over("Phalcon_Internal_Test::t11 (If) File=Library/Phalcon/Internal/Test.php Line=1377");
	//$n
	if (!t3) {
		PHALCON_ALLOC_ZVAL(t3);
	} else {
		if (Z_REFCOUNT_P(t3) > 1) {
			SEPARATE_ZVAL(&t3);
		} else {
			if (Z_TYPE_P(t3) != IS_LONG) {
				FREE_ZVAL(t3);
				PHALCON_ALLOC_ZVAL(t3);
			}
		}
	}
	ZVAL_LONG(t3, 1);
	PHALCON_EQUAL_FUNCTION(r1, v0, t3);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Internal_Test::t11 (Block) File=Library/Phalcon/Internal/Test.php Line=1377");
		phalcon_step_over("Phalcon_Internal_Test::t11 (MethodCall) File=Library/Phalcon/Internal/Test.php Line=1378");
		//$dummy
		phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
		phalcon_debug_method_call(v1, "f1" TSRMLS_CC);
		if (!p1[0]) {
			PHALCON_ALLOC_ZVAL(p1[0]);
		} else {
			if (Z_REFCOUNT_P(p1[0]) > 1) {
				SEPARATE_ZVAL(&p1[0]);
			} else {
				if (Z_TYPE_P(p1[0]) != IS_STRING) {
					FREE_ZVAL(p1[0]);
					PHALCON_ALLOC_ZVAL(p1[0]);
				}
			}
		}
		ZVAL_STRING(p1[0], "x/y", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "f1", 1, p1, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Internal_Test::t11 (PostIncDecOp) File=Library/Phalcon/Internal/Test.php Line=1380");
	//$n
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
	phalcon_debug_vdump("PostIncrementing $n", v0);
	phalcon_step_over("Phalcon_Internal_Test::t11 (If) File=Library/Phalcon/Internal/Test.php Line=1381");
	//$n
	if (!t4) {
		PHALCON_ALLOC_ZVAL(t4);
	} else {
		if (Z_REFCOUNT_P(t4) > 1) {
			SEPARATE_ZVAL(&t4);
		} else {
			if (Z_TYPE_P(t4) != IS_LONG) {
				FREE_ZVAL(t4);
				PHALCON_ALLOC_ZVAL(t4);
			}
		}
	}
	ZVAL_LONG(t4, 2);
	PHALCON_SMALLER_FUNCTION(r2, t4, v0);
	if (zend_is_true(r2)) {
		phalcon_step_over("Phalcon_Internal_Test::t11 (Block) File=Library/Phalcon/Internal/Test.php Line=1381");
		phalcon_step_over("Phalcon_Internal_Test::t11 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1382");
		//$this
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_p4", strlen("_p4"), 1 TSRMLS_CC);
	}
	goto ws47;
	we47:
	r0 = NULL;
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::t11 (Method) File=Library/Phalcon/Internal/Test.php Line=1387");
}

PHP_METHOD(Phalcon_Internal_Test, t12){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL }, *p2[] = { NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "t12", 0);
	phalcon_step_over("Phalcon_Internal_Test::t12 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1388");
	//$parts
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "/", 1);
	//$uri
	p0[1] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "explode", 2, p0);
	phalcon_debug_vdump("explode > ", r0 TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	phalcon_debug_assign("$parts", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t12 (If) File=Library/Phalcon/Internal/Test.php Line=1389");
	//$parts
	eval_int = phalcon_array_isset_long(v1, 0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::t12 (Block) File=Library/Phalcon/Internal/Test.php Line=1389");
		phalcon_step_over("Phalcon_Internal_Test::t12 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1390");
		//$parts
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_long(r1, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		p1[0] = r1;
		phalcon_debug_param(r1 TSRMLS_CC);
		phalcon_filter_alphanum(&r2, p1[0]);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_p1", strlen("_p1"), copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Internal_Test::t12 (Unset) File=Library/Phalcon/Internal/Test.php Line=1391");
		//$parts
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
		phalcon_array_unset_long(v1, 0);
	}
	phalcon_step_over("Phalcon_Internal_Test::t12 (If) File=Library/Phalcon/Internal/Test.php Line=1393");
	//$parts
	eval_int = phalcon_array_isset_long(v1, 1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::t12 (Block) File=Library/Phalcon/Internal/Test.php Line=1393");
		phalcon_step_over("Phalcon_Internal_Test::t12 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1394");
		//$parts
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_array_fetch_long(r3, v1, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		p2[0] = r3;
		phalcon_debug_param(r3 TSRMLS_CC);
		phalcon_filter_alphanum(&r4, p2[0]);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r4, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_p2", strlen("_p2"), copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Internal_Test::t12 (Unset) File=Library/Phalcon/Internal/Test.php Line=1395");
		//$parts
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
		phalcon_array_unset_long(v1, 1);
	}
	phalcon_step_over("Phalcon_Internal_Test::t12 (Assignment) File=Library/Phalcon/Internal/Test.php Line=1397");
	//$this
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_p4", strlen("_p4"), 0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
}

