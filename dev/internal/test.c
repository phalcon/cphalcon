
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
	phalcon_step_over("Phalcon_Internal_Test::e1 (Method) File=/Internal/Test Line=60");
}

PHP_METHOD(Phalcon_Internal_Test, e2){


	phalcon_step_into_entry("Phalcon_Internal_Test", "e2", 0);
	phalcon_step_out_entry();
	RETURN_STRING("5", 1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::e2 (Method) File=/Internal/Test Line=64");
}

PHP_METHOD(Phalcon_Internal_Test, e3){

	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "e3", 0);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 5);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, -1);
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
	phalcon_step_over("Phalcon_Internal_Test::e3 (Method) File=/Internal/Test Line=68");
}

PHP_METHOD(Phalcon_Internal_Test, e4){

	zval *v0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "e4", 0);
	phalcon_step_over("Phalcon_Internal_Test::e4 (Assignment) File=/Internal/Test Line=69");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 5);
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
	phalcon_step_over("Phalcon_Internal_Test::e4 (Method) File=/Internal/Test Line=73");
}

PHP_METHOD(Phalcon_Internal_Test, e5){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "e5", 0);
	phalcon_step_over("Phalcon_Internal_Test::e5 (Assignment) File=/Internal/Test Line=74");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 5);
	phalcon_step_over("Phalcon_Internal_Test::e5 (Assignment) File=/Internal/Test Line=75");
	PHALCON_CPY_WRT(v1, v0);
	phalcon_debug_assign("$b", v0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::e5 (Assignment) File=/Internal/Test Line=76");
	PHALCON_CPY_WRT(v2, v1);
	phalcon_debug_assign("$c", v1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::e5 (Method) File=/Internal/Test Line=80");
}

PHP_METHOD(Phalcon_Internal_Test, e6){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "e6", 0);
	phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(v0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::e6 (Method) File=/Internal/Test Line=84");
}

PHP_METHOD(Phalcon_Internal_Test, e7){

	zval *v0 = NULL, *v1 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "e7", 0);
	phalcon_step_over("Phalcon_Internal_Test::e7 (Assignment) File=/Internal/Test Line=85");
	PHALCON_CPY_WRT(v1, v0);
	phalcon_debug_assign("$a", v0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", v1 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(v1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::e7 (Method) File=/Internal/Test Line=96");
}

PHP_METHOD(Phalcon_Internal_Test, e9){


	phalcon_step_into_entry("Phalcon_Internal_Test", "e9", 0);
	phalcon_step_out_entry();
	RETURN_STRING("LOL", 1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::e9 (Method) File=/Internal/Test Line=100");
}

PHP_METHOD(Phalcon_Internal_Test, e10){


	phalcon_step_into_entry("Phalcon_Internal_Test", "e10", 0);
	phalcon_step_out_entry();
	RETURN_DOUBLE(1.5);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::e10 (Method) File=/Internal/Test Line=104");
}

PHP_METHOD(Phalcon_Internal_Test, e13){

	zval *v0 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "e13", 0);
	phalcon_step_over("Phalcon_Internal_Test::e13 (Assignment) File=/Internal/Test Line=105");
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	PHALCON_CPY_WRT_PARAM(v0, i0);
	phalcon_debug_assign("$a", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::e13 (Assignment) File=/Internal/Test Line=106");
	phalcon_update_property_long(v0, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::e13 (Assignment) File=/Internal/Test Line=107");
	phalcon_update_property_long(v0, "dos", strlen("dos"), 2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::e13 (Assignment) File=/Internal/Test Line=108");
	PHALCON_ALLOC_ZVAL(i1);
	object_init(i1);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, i1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(v0, "subA", strlen("subA"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Internal_Test::e13 (Assignment) File=/Internal/Test Line=109");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_long(t0, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::e13 (Assignment) File=/Internal/Test Line=110");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_long(t1, "dos", strlen("dos"), 2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::e13 (Assignment) File=/Internal/Test Line=111");
	PHALCON_ALLOC_ZVAL(i2);
	object_init(i2);
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, i2, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(t2, "subSubA", strlen("subSubA"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Internal_Test::e13 (Assignment) File=/Internal/Test Line=112");
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_read_property(t3, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t4);
	phalcon_read_property(t4, t3, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_long(t4, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::e13 (Assignment) File=/Internal/Test Line=113");
	PHALCON_ALLOC_ZVAL(t5);
	phalcon_read_property(t5, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t6);
	phalcon_read_property(t6, t5, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_long(t6, "dos", strlen("dos"), 2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t7);
	phalcon_read_property(t7, v0, "uno", sizeof("uno")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t8);
	phalcon_read_property(t8, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t9);
	phalcon_read_property(t9, t8, "uno", sizeof("uno")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	mul_function(r0, t7, t9 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t10);
	phalcon_read_property(t10, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t11);
	phalcon_read_property(t11, t10, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t12);
	phalcon_read_property(t12, t11, "uno", sizeof("uno")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::e13 (Method) File=/Internal/Test Line=117");
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
	phalcon_step_over("Phalcon_Internal_Test::e14 (Assignment) File=/Internal/Test Line=118");
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v1, i0);
	phalcon_debug_assign("$a", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::e14 (Assignment) File=/Internal/Test Line=119");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(v1, "val", strlen("val"), copy TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, v1, "val", sizeof("val")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::e14 (Method) File=/Internal/Test Line=124");
}

PHP_METHOD(Phalcon_Internal_Test, o1){

	zval *v0 = NULL;
	zval *t0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "o1", 0);
	PHALCON_SEPARATE_PARAM(v0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_ZVAL(t0, v0, 1, 0);
	increment_function(v0);
	phalcon_debug_vdump("PostIncrementing $num", v0);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::o1 (Method) File=/Internal/Test Line=128");
}

PHP_METHOD(Phalcon_Internal_Test, o2){

	zval *v0 = NULL;
	zval *t0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "o2", 0);
	PHALCON_SEPARATE_PARAM(v0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_ZVAL(t0, v0, 1, 0);
	decrement_function(v0);
	phalcon_debug_vdump("PostDecrementing $num", v0);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::o2 (Method) File=/Internal/Test Line=132");
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
	phalcon_step_over("Phalcon_Internal_Test::o3 (Method) File=/Internal/Test Line=136");
}

PHP_METHOD(Phalcon_Internal_Test, o4){

	zval *v0 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "o4", 0);
	PHALCON_ALLOC_ZVAL(r0);
	add_function(r0, v0, v0 TSRMLS_CC);
	PHALCON_CPY_WRT_PARAM(v0, r0);
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
	phalcon_step_over("Phalcon_Internal_Test::o4 (Method) File=/Internal/Test Line=140");
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
	phalcon_step_over("Phalcon_Internal_Test::o5 (Method) File=/Internal/Test Line=144");
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
	phalcon_step_over("Phalcon_Internal_Test::o6 (Method) File=/Internal/Test Line=148");
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
	phalcon_step_over("Phalcon_Internal_Test::o7 (Method) File=/Internal/Test Line=152");
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
	phalcon_step_over("Phalcon_Internal_Test::o8 (Method) File=/Internal/Test Line=156");
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
	PHALCON_ALLOC_ZVAL(r0);
	mod_function(r0, v0, v1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::o9 (Method) File=/Internal/Test Line=160");
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
	phalcon_step_over("Phalcon_Internal_Test::o10 (Method) File=/Internal/Test Line=163");
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
	phalcon_step_over("Phalcon_Internal_Test::o11 (Method) File=/Internal/Test Line=166");
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
	phalcon_step_over("Phalcon_Internal_Test::o12 (Method) File=/Internal/Test Line=170");
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
	phalcon_step_over("Phalcon_Internal_Test::o13 (Method) File=/Internal/Test Line=174");
}

PHP_METHOD(Phalcon_Internal_Test, o14){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "o14", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL(r0);
	mod_function(r0, t0, t1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::o14 (Method) File=/Internal/Test Line=178");
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
	phalcon_step_over("Phalcon_Internal_Test::o15 (Method) File=/Internal/Test Line=182");
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
	phalcon_step_over("Phalcon_Internal_Test::o16 (Method) File=/Internal/Test Line=186");
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
	phalcon_step_over("Phalcon_Internal_Test::o17 (Method) File=/Internal/Test Line=190");
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
	phalcon_step_over("Phalcon_Internal_Test::o18 (Method) File=/Internal/Test Line=194");
}

PHP_METHOD(Phalcon_Internal_Test, o19){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "o19", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 40);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_STRING(t1, "5", 1);
	PHALCON_ALLOC_ZVAL(r0);
	mod_function(r0, t0, t1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::o19 (Method) File=/Internal/Test Line=198");
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
	phalcon_step_over("Phalcon_Internal_Test::o20 (Assignment) File=/Internal/Test Line=199");
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_LONG(v1, 150);
	phalcon_step_over("Phalcon_Internal_Test::o20 (Assignment) File=/Internal/Test Line=200");
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_LONG(v2, 250);
	phalcon_step_over("Phalcon_Internal_Test::o20 (Assignment) File=/Internal/Test Line=201");
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
	PHALCON_ALLOC_ZVAL(r3);
	sub_function(r3, r2, v2 TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r3);
	phalcon_debug_assign("$a", r3 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::o20 (Assignment) File=/Internal/Test Line=202");
	PHALCON_ALLOC_ZVAL(t2);
	ZVAL_LONG(t2, 5);
	PHALCON_ALLOC_ZVAL(r4);
	mul_function(r4, v2, t2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r5);
	div_function(r5, r4, v0 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r5);
	phalcon_debug_assign("$b", r5 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::o20 (Method) File=/Internal/Test Line=206");
}

PHP_METHOD(Phalcon_Internal_Test, o21){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "o21", 0);
	phalcon_step_over("Phalcon_Internal_Test::o21 (Assignment) File=/Internal/Test Line=207");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_STRING(v0, "memory", 0);
	phalcon_step_over("Phalcon_Internal_Test::o21 (Assignment) File=/Internal/Test Line=208");
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_STRING(v1, "yes", 0);
	phalcon_step_over("Phalcon_Internal_Test::o21 (Assignment) File=/Internal/Test Line=209");
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CONCAT_LEFT(r0, "no, ", v0);
	PHALCON_CPY_WRT(v2, r0);
	phalcon_debug_assign("$c", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::o21 (Assignment) File=/Internal/Test Line=210");
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CONCAT_LEFT(r1, "leaks, ", v1);
	PHALCON_CPY_WRT(v3, r1);
	phalcon_debug_assign("$d", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::o21 (Assignment) File=/Internal/Test Line=211");
	PHALCON_ALLOC_ZVAL(r2);
	concat_function(r2, v2, v3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r3);
	concat_function(r3, r2, v1 TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r3);
	phalcon_debug_assign("$b", r3 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::o21 (Method) File=/Internal/Test Line=215");
}

PHP_METHOD(Phalcon_Internal_Test, o22){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "o22", 0);
	phalcon_step_over("Phalcon_Internal_Test::o22 (Assignment) File=/Internal/Test Line=216");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 0);
	phalcon_step_over("Phalcon_Internal_Test::o22 (For) File=/Internal/Test Line=217");
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_LONG(v1, 0);
	fs17:
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 25);
	PHALCON_ALLOC_ZVAL(r0);
	is_smaller_function(r0, v1, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe17;
	}
	phalcon_step_over("Phalcon_Internal_Test::o22 (Block) File=/Internal/Test Line=217");
	phalcon_step_over("Phalcon_Internal_Test::o22 (AssignOp) File=/Internal/Test Line=218");
	if (!r1) {
		PHALCON_ALLOC_ZVAL(r1);
	} else {
		if (Z_REFCOUNT_P(r1) > 1) {
			PHALCON_SEPARATE(r1);
		} else {
			FREE_ZVAL(r1);
			PHALCON_ALLOC_ZVAL(r1);
		}
	}
	concat_function(r1, v0, v1 TSRMLS_CC);
	PHALCON_CPY_WRT_PARAM(v0, r1);
	phalcon_debug_assign("$e", r1 TSRMLS_CC);
	PHALCON_SEPARATE(v1);
	increment_function(v1);
	phalcon_debug_vdump("PostIncrementing $i", v1);
	goto fs17;
	fe17:
	r0 = NULL;
	phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(v0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::o22 (Method) File=/Internal/Test Line=223");
}

PHP_METHOD(Phalcon_Internal_Test, o23){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "o23", 0);
	phalcon_step_over("Phalcon_Internal_Test::o23 (Assignment) File=/Internal/Test Line=224");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 0);
	phalcon_step_over("Phalcon_Internal_Test::o23 (For) File=/Internal/Test Line=225");
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_LONG(v1, 0);
	fs18:
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 25);
	PHALCON_ALLOC_ZVAL(r0);
	is_smaller_function(r0, v1, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe18;
	}
	phalcon_step_over("Phalcon_Internal_Test::o23 (Block) File=/Internal/Test Line=225");
	phalcon_step_over("Phalcon_Internal_Test::o23 (Assignment) File=/Internal/Test Line=226");
	if (!r1) {
		PHALCON_ALLOC_ZVAL(r1);
	} else {
		if (Z_REFCOUNT_P(r1) > 1) {
			PHALCON_SEPARATE(r1);
		} else {
			FREE_ZVAL(r1);
			PHALCON_ALLOC_ZVAL(r1);
		}
	}
	phalcon_concat_both(r1,  "[", v1, "]" TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r1);
	phalcon_debug_assign("$sx", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::o23 (AssignOp) File=/Internal/Test Line=227");
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
	concat_function(r2, v0, v2 TSRMLS_CC);
	PHALCON_CPY_WRT_PARAM(v0, r2);
	phalcon_debug_assign("$e", r2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::o23 (Assignment) File=/Internal/Test Line=228");
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
	PHALCON_SEPARATE(v1);
	increment_function(v1);
	phalcon_debug_vdump("PostIncrementing $i", v1);
	goto fs18;
	fe18:
	r0 = NULL;
	phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(v0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::o23 (Method) File=/Internal/Test Line=234");
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
	phalcon_step_over("Phalcon_Internal_Test::a0 (Method) File=/Internal/Test Line=238");
}

PHP_METHOD(Phalcon_Internal_Test, a1){

	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a1", 0);
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_NULL(t0);
	PHALCON_SEPARATE(a0);
	add_next_index_zval(a0, t0);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_BOOL(t1, 0);
	PHALCON_SEPARATE(a0);
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
	phalcon_step_over("Phalcon_Internal_Test::a1 (Method) File=/Internal/Test Line=242");
}

PHP_METHOD(Phalcon_Internal_Test, a2){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a2", 0);
	phalcon_step_over("Phalcon_Internal_Test::a2 (Assignment) File=/Internal/Test Line=243");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a2 (Assignment) File=/Internal/Test Line=244");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "well", 1);
	PHALCON_SEPARATE_PARAM(v0);
	phalcon_array_update_long(v0, 0, t0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::a2 (Method) File=/Internal/Test Line=247");
}

PHP_METHOD(Phalcon_Internal_Test, a3){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a3", 0);
	phalcon_step_over("Phalcon_Internal_Test::a3 (Assignment) File=/Internal/Test Line=248");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a3 (Assignment) File=/Internal/Test Line=249");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "LOL", 1);
	PHALCON_SEPARATE_PARAM(v0);
	phalcon_array_update_long(v0, 0, t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a3 (Assignment) File=/Internal/Test Line=250");
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_SEPARATE_PARAM(v0);
	phalcon_array_update_string(v0, "LOL", strlen("LOL"), t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_string(r0, v0, "LOL", strlen("LOL"), PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(r0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a3 (Method) File=/Internal/Test Line=254");
}

PHP_METHOD(Phalcon_Internal_Test, a4){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a4", 0);
	phalcon_step_over("Phalcon_Internal_Test::a4 (Assignment) File=/Internal/Test Line=255");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$b", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a4 (Assignment) File=/Internal/Test Line=256");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
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
	PHALCON_RETURN_CTOR(r3);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a4 (Method) File=/Internal/Test Line=260");
}

PHP_METHOD(Phalcon_Internal_Test, a5){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a5", 0);
	phalcon_step_over("Phalcon_Internal_Test::a5 (Assignment) File=/Internal/Test Line=262");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a5 (Assignment) File=/Internal/Test Line=263");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "LOL", 1);
	PHALCON_SEPARATE_PARAM(v0);
	phalcon_array_update_long(v0, 0, t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a5 (Assignment) File=/Internal/Test Line=264");
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_SEPARATE_PARAM(v0);
	phalcon_array_update_string(v0, "LOL", strlen("LOL"), t1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a5 (Assignment) File=/Internal/Test Line=266");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	PHALCON_CPY_WRT(v1, a1);
	phalcon_debug_assign("$b", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a5 (Assignment) File=/Internal/Test Line=267");
	PHALCON_ALLOC_ZVAL(t2);
	ZVAL_STRING(t2, "LOL", 1);
	PHALCON_SEPARATE(v1);
	phalcon_array_update_string(v1, "LOL", strlen("LOL"), t2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a5 (Assignment) File=/Internal/Test Line=268");
	PHALCON_ALLOC_ZVAL(t3);
	ZVAL_LONG(t3, 0);
	PHALCON_SEPARATE(v1);
	phalcon_array_update_long(v1, 0, t3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_long(r0, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::a5 (Method) File=/Internal/Test Line=273");
}

PHP_METHOD(Phalcon_Internal_Test, a6){

	zval *v0 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a6", 0);
	phalcon_step_over("Phalcon_Internal_Test::a6 (Assignment) File=/Internal/Test Line=275");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a6 (Assignment) File=/Internal/Test Line=276");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	PHALCON_SEPARATE_PARAM(v0);
	phalcon_array_update_long(v0, 1, a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a6 (Assignment) File=/Internal/Test Line=277");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	if (Z_TYPE_P(v0) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_array_fetch_long(t1, v0, 1, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t1) != IS_ARRAY) {
		convert_to_array(t1);
		phalcon_array_update_long(v0, 1, t1 TSRMLS_CC);
		Z_ADDREF_P(t1);
	}
	phalcon_array_update_string(t1, "LOL", strlen("LOL"), t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a6 (Echo) File=/Internal/Test Line=279");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_long(r0, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_array_fetch_string(r1, r0, "LOL", strlen("LOL"), PHALCON_NOISY_FETCH TSRMLS_CC);
	zend_print_zval(r1, 0);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::a6 (Method) File=/Internal/Test Line=282");
}

PHP_METHOD(Phalcon_Internal_Test, a7){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a7", 0);
	phalcon_step_over("Phalcon_Internal_Test::a7 (Assignment) File=/Internal/Test Line=284");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a7 (Assignment) File=/Internal/Test Line=285");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "LOL", 1);
	PHALCON_SEPARATE_PARAM(v0);
	phalcon_array_update_long(v0, 0, t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a7 (Assignment) File=/Internal/Test Line=286");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	PHALCON_SEPARATE_PARAM(v0);
	phalcon_array_update_long(v0, 1, a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a7 (Assignment) File=/Internal/Test Line=287");
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
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
	phalcon_step_over("Phalcon_Internal_Test::a7 (Assignment) File=/Internal/Test Line=288");
	PHALCON_ALLOC_ZVAL(t3);
	ZVAL_LONG(t3, 0);
	PHALCON_SEPARATE_PARAM(v0);
	phalcon_array_update_string(v0, "LOL", strlen("LOL"), t3 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a7 (Assignment) File=/Internal/Test Line=290");
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	PHALCON_CPY_WRT(v1, a2);
	phalcon_debug_assign("$b", a2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a7 (Assignment) File=/Internal/Test Line=291");
	PHALCON_ALLOC_ZVAL(t4);
	ZVAL_STRING(t4, "LOL", 1);
	PHALCON_SEPARATE(v1);
	phalcon_array_update_string(v1, "LOL", strlen("LOL"), t4 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a7 (Assignment) File=/Internal/Test Line=292");
	PHALCON_ALLOC_ZVAL(t5);
	ZVAL_LONG(t5, 0);
	PHALCON_SEPARATE(v1);
	phalcon_array_update_long(v1, 0, t5 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a7 (Assignment) File=/Internal/Test Line=293");
	PHALCON_ALLOC_ZVAL(t6);
	ZVAL_LONG(t6, 1);
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
	phalcon_step_over("Phalcon_Internal_Test::a7 (Assignment) File=/Internal/Test Line=295");
	PHALCON_ALLOC_ZVAL(a3);
	array_init(a3);
	PHALCON_CPY_WRT(v2, a3);
	phalcon_debug_assign("$c", a3 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a7 (Assignment) File=/Internal/Test Line=296");
	PHALCON_ALLOC_ZVAL(a4);
	array_init(a4);
	PHALCON_SEPARATE(v2);
	phalcon_array_update_long(v2, 0, a4 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a7 (Assignment) File=/Internal/Test Line=297");
	PHALCON_ALLOC_ZVAL(a5);
	array_init(a5);
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
	phalcon_step_over("Phalcon_Internal_Test::a7 (Assignment) File=/Internal/Test Line=298");
	PHALCON_ALLOC_ZVAL(a6);
	array_init(a6);
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
	phalcon_step_over("Phalcon_Internal_Test::a7 (Assignment) File=/Internal/Test Line=299");
	PHALCON_ALLOC_ZVAL(t11);
	ZVAL_LONG(t11, 1);
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
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_long(r0, v1, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_array_fetch_string(r1, r0, "LOL", strlen("LOL"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r2);
	phalcon_array_fetch_long(r2, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r3);
	phalcon_array_fetch_string(r3, r2, "LOL", strlen("LOL"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r4);
	mul_function(r4, r1, r3 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::a7 (Method) File=/Internal/Test Line=304");
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
	phalcon_step_over("Phalcon_Internal_Test::a10 (Assignment) File=/Internal/Test Line=305");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_assoc_long(a0, "hello1", 1);
	add_assoc_long(a0, "hello2", 2);
	add_assoc_long(a0, "hello3", 3);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$e", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a10 (Foreach) File=/Internal/Test Line=306");
	FOREACH_KV(v0, ac0, fes19, fee19, ah0, hp0, v2, v1)
		phalcon_step_over("Phalcon_Internal_Test::a10 (Block) File=/Internal/Test Line=306");
		phalcon_step_over("Phalcon_Internal_Test::a10 (Assignment) File=/Internal/Test Line=307");
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
				PHALCON_SEPARATE(r1);
			}
		}
		add_function(r1, r0, t0 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update(v0, v2, copy TSRMLS_CC);
		}
	END_FOREACH(ac0, fes19, fee19, ah0, hp0);
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
	phalcon_step_over("Phalcon_Internal_Test::a10 (Method) File=/Internal/Test Line=312");
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
	phalcon_step_over("Phalcon_Internal_Test::a11 (Assignment) File=/Internal/Test Line=313");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	add_next_index_long(a0, 4);
	add_next_index_long(a0, 5);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$e", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a11 (Foreach) File=/Internal/Test Line=314");
	FOREACH_KV(v0, ac0, fes20, fee20, ah0, hp0, v2, v1)
		phalcon_step_over("Phalcon_Internal_Test::a11 (Block) File=/Internal/Test Line=314");
		phalcon_step_over("Phalcon_Internal_Test::a11 (Assignment) File=/Internal/Test Line=315");
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
		ZVAL_LONG(t0, 10);
		if (!r1) {
			PHALCON_ALLOC_ZVAL(r1);
		} else {
			if (Z_REFCOUNT_P(r1) > 1){ 
				PHALCON_SEPARATE(r1);
			}
		}
		add_function(r1, v2, t0 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update(v0, r1, copy TSRMLS_CC);
		}
	END_FOREACH(ac0, fes20, fee20, ah0, hp0);
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
	phalcon_step_over("Phalcon_Internal_Test::a11 (Method) File=/Internal/Test Line=320");
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
	phalcon_step_over("Phalcon_Internal_Test::a12 (Assignment) File=/Internal/Test Line=321");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 0);
	phalcon_step_over("Phalcon_Internal_Test::a12 (Assignment) File=/Internal/Test Line=322");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	add_next_index_long(a0, 4);
	add_next_index_long(a0, 5);
	PHALCON_CPY_WRT(v1, a0);
	phalcon_debug_assign("$e", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a12 (Foreach) File=/Internal/Test Line=323");
	FOREACH_V(v1, ac0, fes21, fee21, ah0, hp0, v2)
		phalcon_step_over("Phalcon_Internal_Test::a12 (Block) File=/Internal/Test Line=323");
		phalcon_step_over("Phalcon_Internal_Test::a12 (Assignment) File=/Internal/Test Line=324");
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
		phalcon_array_fetch(r0, v1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
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
				PHALCON_SEPARATE(r1);
			}
		}
		add_function(r1, v0, t0 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			PHALCON_SEPARATE(v1);
			phalcon_array_update(v1, r1, copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Internal_Test::a12 (PostIncDecOp) File=/Internal/Test Line=325");
		PHALCON_SEPARATE_PARAM(v0);
		increment_function(v0);
		phalcon_debug_vdump("PostIncrementing $k", v0);
	END_FOREACH(ac0, fes21, fee21, ah0, hp0);
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
	phalcon_step_over("Phalcon_Internal_Test::a12 (Method) File=/Internal/Test Line=330");
}

PHP_METHOD(Phalcon_Internal_Test, a13){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *ac0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a13", 0);
	phalcon_step_over("Phalcon_Internal_Test::a13 (Assignment) File=/Internal/Test Line=331");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$f", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a13 (Assignment) File=/Internal/Test Line=332");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	add_next_index_long(a1, 4);
	add_next_index_long(a1, 5);
	PHALCON_CPY_WRT(v1, a1);
	phalcon_debug_assign("$e", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a13 (Foreach) File=/Internal/Test Line=333");
	FOREACH_V(v1, ac0, fes22, fee22, ah0, hp0, v2)
		phalcon_step_over("Phalcon_Internal_Test::a13 (Block) File=/Internal/Test Line=333");
		phalcon_step_over("Phalcon_Internal_Test::a13 (Assignment) File=/Internal/Test Line=334");
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_append(v0, copy TSRMLS_CC);
		}
	END_FOREACH(ac0, fes22, fee22, ah0, hp0);
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
	phalcon_step_over("Phalcon_Internal_Test::a13 (Method) File=/Internal/Test Line=339");
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
	phalcon_step_over("Phalcon_Internal_Test::a14 (Assignment) File=/Internal/Test Line=340");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$f", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a14 (Assignment) File=/Internal/Test Line=341");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	add_next_index_long(a1, 4);
	add_next_index_long(a1, 5);
	PHALCON_CPY_WRT(v1, a1);
	phalcon_debug_assign("$e", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a14 (Foreach) File=/Internal/Test Line=342");
	FOREACH_KV(v1, ac0, fes23, fee23, ah0, hp0, v3, v2)
		phalcon_step_over("Phalcon_Internal_Test::a14 (Block) File=/Internal/Test Line=342");
		phalcon_step_over("Phalcon_Internal_Test::a14 (Assignment) File=/Internal/Test Line=343");
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
				PHALCON_SEPARATE(r0);
			}
		}
		mul_function(r0, v3, t0 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r0);
		phalcon_debug_assign("$k", r0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Internal_Test::a14 (Assignment) File=/Internal/Test Line=344");
		if (!r1) {
			PHALCON_ALLOC_ZVAL(r1);
		} else {
			if (Z_REFCOUNT_P(r1) > 1){ 
				PHALCON_SEPARATE(r1);
			}
		}
		add_function(r1, v2, v3 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update(v0, v3, copy TSRMLS_CC);
		}
	END_FOREACH(ac0, fes23, fee23, ah0, hp0);
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
	phalcon_step_over("Phalcon_Internal_Test::a14 (Method) File=/Internal/Test Line=349");
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
	phalcon_step_over("Phalcon_Internal_Test::a15 (Assignment) File=/Internal/Test Line=350");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$f", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a15 (Assignment) File=/Internal/Test Line=351");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	add_next_index_long(a1, 4);
	add_next_index_long(a1, 5);
	PHALCON_CPY_WRT(v1, a1);
	phalcon_debug_assign("$e", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a15 (Foreach) File=/Internal/Test Line=352");
	FOREACH_KV(v1, ac0, fes24, fee24, ah0, hp0, v3, v2)
		phalcon_step_over("Phalcon_Internal_Test::a15 (Block) File=/Internal/Test Line=352");
		phalcon_step_over("Phalcon_Internal_Test::a15 (Assignment) File=/Internal/Test Line=353");
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
		phalcon_array_fetch(r0, v1, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update(v0, v3, copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Internal_Test::a15 (Assignment) File=/Internal/Test Line=354");
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
				PHALCON_SEPARATE(r1);
			}
		}
		mul_function(r1, v3, t0 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			PHALCON_SEPARATE(v1);
			phalcon_array_update(v1, v3, copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Internal_Test::a15 (Assignment) File=/Internal/Test Line=355");
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
				PHALCON_SEPARATE(r3);
			}
		}
		mul_function(r3, r2, t1 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r3, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update(v0, v3, copy TSRMLS_CC);
		}
	END_FOREACH(ac0, fes24, fee24, ah0, hp0);
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
	phalcon_step_over("Phalcon_Internal_Test::a15 (Method) File=/Internal/Test Line=360");
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
	phalcon_step_over("Phalcon_Internal_Test::a16 (Assignment) File=/Internal/Test Line=361");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$f", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a16 (Assignment) File=/Internal/Test Line=362");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	add_assoc_string(a2, "in", "out", 1);
	PHALCON_SEPARATE(a1);
	add_assoc_zval(a1, "hello", a2);
	PHALCON_ALLOC_ZVAL(a3);
	array_init(a3);
	add_assoc_string(a3, "file", "type", 1);
	add_assoc_string(a3, "php", "unix", 1);
	add_assoc_string(a3, "tab", "ins", 1);
	PHALCON_SEPARATE(a1);
	add_assoc_zval(a1, "bye", a3);
	PHALCON_ALLOC_ZVAL(a4);
	array_init(a4);
	PHALCON_SEPARATE(a1);
	add_assoc_zval(a1, "encoding", a4);
	add_assoc_string(a1, "sucks", "yes", 1);
	PHALCON_CPY_WRT(v1, a1);
	phalcon_debug_assign("$e", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a16 (Foreach) File=/Internal/Test Line=376");
	FOREACH_KV(v1, ac0, fes25, fee25, ah0, hp0, v3, v2)
		phalcon_step_over("Phalcon_Internal_Test::a16 (Block) File=/Internal/Test Line=376");
		phalcon_step_over("Phalcon_Internal_Test::a16 (If) File=/Internal/Test Line=377");
		if (Z_TYPE_P(v2) == IS_ARRAY) { 
			phalcon_step_over("Phalcon_Internal_Test::a16 (Block) File=/Internal/Test Line=377");
			phalcon_step_over("Phalcon_Internal_Test::a16 (Foreach) File=/Internal/Test Line=378");
			FOREACH_KV(v2, ac1, fes26, fee26, ah1, hp1, v5, v4)
				phalcon_step_over("Phalcon_Internal_Test::a16 (Block) File=/Internal/Test Line=378");
				phalcon_step_over("Phalcon_Internal_Test::a16 (Assignment) File=/Internal/Test Line=379");
				if (Z_TYPE_P(v0) == IS_ARRAY) {
					if (!t0) {
						PHALCON_ALLOC_ZVAL(t0);
					} else {
						if (Z_REFCOUNT_P(t0) > 1) {
							PHALCON_SEPARATE(t0);
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
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v4, 1, 0);
					Z_SET_REFCOUNT_P(copy, 1);
					phalcon_array_update(t0, v5, copy TSRMLS_CC);
				}
			END_FOREACH(ac1, fes26, fee26, ah1, hp1);
		} else {
			phalcon_step_over("Phalcon_Internal_Test::a16 (Block) File=/Internal/Test Line=381");
			phalcon_step_over("Phalcon_Internal_Test::a16 (Assignment) File=/Internal/Test Line=382");
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				PHALCON_SEPARATE_PARAM(v0);
				phalcon_array_update(v0, v3, copy TSRMLS_CC);
			}
		}
	END_FOREACH(ac0, fes25, fee25, ah0, hp0);
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
	phalcon_step_over("Phalcon_Internal_Test::a16 (Method) File=/Internal/Test Line=388");
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
	phalcon_step_over("Phalcon_Internal_Test::a17 (Assignment) File=/Internal/Test Line=389");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$w", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a17 (Assignment) File=/Internal/Test Line=390");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_assoc_long(a1, "7", 0);
	add_assoc_long(a1, "8", 1);
	add_assoc_long(a1, "9", 2);
	PHALCON_CPY_WRT(v1, a1);
	phalcon_debug_assign("$a", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a17 (Assignment) File=/Internal/Test Line=395");
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	PHALCON_ALLOC_ZVAL(a3);
	array_init(a3);
	add_next_index_string(a3, "hello1", 1);
	PHALCON_SEPARATE(a2);
	add_next_index_zval(a2, a3);
	PHALCON_ALLOC_ZVAL(a4);
	array_init(a4);
	add_next_index_string(a4, "hello2", 1);
	PHALCON_SEPARATE(a2);
	add_assoc_zval(a2, "1", a4);
	PHALCON_ALLOC_ZVAL(a5);
	array_init(a5);
	add_next_index_string(a5, "hello3", 1);
	PHALCON_SEPARATE(a2);
	add_assoc_zval(a2, "2", a5);
	PHALCON_CPY_WRT(v2, a2);
	phalcon_debug_assign("$b", a2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a17 (Foreach) File=/Internal/Test Line=406");
	FOREACH_KV(v1, ac0, fes27, fee27, ah0, hp0, v4, v3)
		phalcon_step_over("Phalcon_Internal_Test::a17 (Block) File=/Internal/Test Line=406");
		phalcon_step_over("Phalcon_Internal_Test::a17 (Assignment) File=/Internal/Test Line=407");
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
		phalcon_array_fetch(r0, v2, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update(v0, v4, copy TSRMLS_CC);
		}
	END_FOREACH(ac0, fes27, fee27, ah0, hp0);
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
	phalcon_step_over("Phalcon_Internal_Test::a17 (Method) File=/Internal/Test Line=412");
}

PHP_METHOD(Phalcon_Internal_Test, a18){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a18", 0);
	phalcon_step_over("Phalcon_Internal_Test::a18 (Assignment) File=/Internal/Test Line=413");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_string(a0, "hello1", 1);
	add_next_index_string(a0, "hello2", 1);
	add_next_index_string(a0, "hello3", 1);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a18 (Assignment) File=/Internal/Test Line=414");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		PHALCON_SEPARATE(a1);
		add_next_index_zval(a1, copy);
	}
	PHALCON_CPY_WRT(v1, a1);
	phalcon_debug_assign("$c", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a18 (Assignment) File=/Internal/Test Line=415");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "see", 1);
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
	phalcon_step_over("Phalcon_Internal_Test::a18 (Method) File=/Internal/Test Line=419");
}

PHP_METHOD(Phalcon_Internal_Test, a19){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a19", 0);
	phalcon_step_over("Phalcon_Internal_Test::a19 (Assignment) File=/Internal/Test Line=420");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_string(a0, "hello1", 1);
	add_next_index_string(a0, "hello2", 1);
	add_next_index_string(a0, "hello3", 1);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_BOOL(t0, 0);
	PHALCON_SEPARATE(a0);
	add_next_index_zval(a0, t0);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_NULL(t1);
	PHALCON_SEPARATE(a0);
	add_next_index_zval(a0, t1);
	add_next_index_double(a0, 1.34);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a19 (Assignment) File=/Internal/Test Line=421");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_next_index_string(a1, "lol1", 1);
	add_next_index_string(a1, "lol2", 1);
	add_next_index_string(a1, "lol3", 1);
	add_next_index_string(a1, "lol4", 1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	PHALCON_CPY_WRT(v1, a1);
	phalcon_debug_assign("$b", a1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::a19 (Method) File=/Internal/Test Line=425");
}

PHP_METHOD(Phalcon_Internal_Test, a20){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a20", 0);
	phalcon_step_over("Phalcon_Internal_Test::a20 (Assignment) File=/Internal/Test Line=426");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_DOUBLE(v0, 3.45);
	phalcon_step_over("Phalcon_Internal_Test::a20 (Assignment) File=/Internal/Test Line=427");
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_STRING(v1, "6.28", 0);
	phalcon_step_over("Phalcon_Internal_Test::a20 (Assignment) File=/Internal/Test Line=428");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v2, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a20 (Assignment) File=/Internal/Test Line=429");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "whtzup!", 1);
	PHALCON_SEPARATE(v2);
	phalcon_array_update(v2, v0, t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a20 (Assignment) File=/Internal/Test Line=430");
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_STRING(t1, "morelol", 1);
	PHALCON_SEPARATE(v2);
	phalcon_array_update(v2, v1, t1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::a20 (Method) File=/Internal/Test Line=434");
}

PHP_METHOD(Phalcon_Internal_Test, a21){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *a0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a21", 0);
	phalcon_step_over("Phalcon_Internal_Test::a21 (Assignment) File=/Internal/Test Line=435");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_NULL(v0);
	phalcon_step_over("Phalcon_Internal_Test::a21 (Assignment) File=/Internal/Test Line=436");
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_BOOL(v1, 0);
	phalcon_step_over("Phalcon_Internal_Test::a21 (Assignment) File=/Internal/Test Line=437");
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_BOOL(v2, 1);
	phalcon_step_over("Phalcon_Internal_Test::a21 (Assignment) File=/Internal/Test Line=438");
	PHALCON_ALLOC_ZVAL(v3);
	ZVAL_LONG(v3, 100);
	phalcon_step_over("Phalcon_Internal_Test::a21 (Assignment) File=/Internal/Test Line=439");
	PHALCON_ALLOC_ZVAL(v4);
	ZVAL_DOUBLE(v4, 3.45);
	phalcon_step_over("Phalcon_Internal_Test::a21 (Assignment) File=/Internal/Test Line=440");
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 100);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, -1);
	PHALCON_ALLOC_ZVAL(r0);
	mul_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_CPY_WRT(v5, r0);
	phalcon_debug_assign("$g", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a21 (Assignment) File=/Internal/Test Line=441");
	PHALCON_ALLOC_ZVAL(v6);
	ZVAL_STRING(v6, "6.28", 0);
	phalcon_step_over("Phalcon_Internal_Test::a21 (Assignment) File=/Internal/Test Line=442");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v7, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a21 (Assignment) File=/Internal/Test Line=443");
	PHALCON_ALLOC_ZVAL(t2);
	ZVAL_STRING(t2, "whtzup!", 1);
	if (Z_TYPE_P(v7) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_array_fetch(t3, v7, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t3) != IS_ARRAY) {
		convert_to_array(t3);
		phalcon_array_update(v7, v0, t3 TSRMLS_CC);
		Z_ADDREF_P(t3);
	}
	if (Z_TYPE_P(t3) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t4);
		phalcon_array_fetch(t4, t3, v1, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t4) != IS_ARRAY) {
		convert_to_array(t4);
		phalcon_array_update(t3, v1, t4 TSRMLS_CC);
		Z_ADDREF_P(t4);
	}
	if (Z_TYPE_P(t4) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t5);
		phalcon_array_fetch(t5, t4, v2, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t5) != IS_ARRAY) {
		convert_to_array(t5);
		phalcon_array_update(t4, v2, t5 TSRMLS_CC);
		Z_ADDREF_P(t5);
	}
	if (Z_TYPE_P(t5) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t6);
		phalcon_array_fetch(t6, t5, v3, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t6) != IS_ARRAY) {
		convert_to_array(t6);
		phalcon_array_update(t5, v3, t6 TSRMLS_CC);
		Z_ADDREF_P(t6);
	}
	if (Z_TYPE_P(t6) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t7);
		phalcon_array_fetch(t7, t6, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t7) != IS_ARRAY) {
		convert_to_array(t7);
		phalcon_array_update(t6, v4, t7 TSRMLS_CC);
		Z_ADDREF_P(t7);
	}
	if (Z_TYPE_P(t7) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t8);
		phalcon_array_fetch(t8, t7, v5, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t8) != IS_ARRAY) {
		convert_to_array(t8);
		phalcon_array_update(t7, v5, t8 TSRMLS_CC);
		Z_ADDREF_P(t8);
	}
	phalcon_array_update(t8, v6, t2 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::a21 (Method) File=/Internal/Test Line=447");
}

PHP_METHOD(Phalcon_Internal_Test, a22){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a22", 0);
	phalcon_step_over("Phalcon_Internal_Test::a22 (Assignment) File=/Internal/Test Line=448");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_string(a0, "222", 1);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a22 (Assignment) File=/Internal/Test Line=449");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_next_index_string(a1, "222", 1);
	add_next_index_string(a1, "kdkdk", 1);
	PHALCON_CPY_WRT(v1, a1);
	phalcon_debug_assign("$b", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a22 (Assignment) File=/Internal/Test Line=450");
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	PHALCON_ALLOC_ZVAL(r0);
	add_function(r0, v0, v1 TSRMLS_CC);
	PHALCON_SEPARATE(a2);
	add_next_index_zval(a2, r0);
	PHALCON_ALLOC_ZVAL(r1);
	add_function(r1, v1, v0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r2);
	add_function(r2, r1, v0 TSRMLS_CC);
	PHALCON_SEPARATE(a2);
	add_next_index_zval(a2, r2);
	PHALCON_CPY_WRT(v2, a2);
	phalcon_debug_assign("$e", a2 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::a22 (Method) File=/Internal/Test Line=454");
}

PHP_METHOD(Phalcon_Internal_Test, a23){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL, NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a23", 0);
	phalcon_step_over("Phalcon_Internal_Test::a23 (Assignment) File=/Internal/Test Line=455");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$f", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a23 (Assignment) File=/Internal/Test Line=456");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	add_assoc_string(a2, "baseuri", "/phalcon/", 1);
	PHALCON_SEPARATE(a1);
	add_assoc_zval(a1, "phalcon", a2);
	PHALCON_ALLOC_ZVAL(a3);
	array_init(a3);
	add_assoc_string(a3, "metadata", "memory", 1);
	PHALCON_SEPARATE(a1);
	add_assoc_zval(a1, "models", a3);
	PHALCON_ALLOC_ZVAL(a4);
	array_init(a4);
	add_assoc_string(a4, "adapter", "mysql", 1);
	add_assoc_string(a4, "host", "localhost", 1);
	add_assoc_string(a4, "username", "user", 1);
	add_assoc_string(a4, "password", "passwd", 1);
	add_assoc_string(a4, "name", "demo", 1);
	PHALCON_SEPARATE(a1);
	add_assoc_zval(a1, "database", a4);
	PHALCON_ALLOC_ZVAL(a5);
	array_init(a5);
	add_assoc_long(a5, "parent.property", 1);
	add_assoc_string(a5, "parent.property2", "yeah", 1);
	PHALCON_SEPARATE(a1);
	add_assoc_zval(a1, "test", a5);
	PHALCON_CPY_WRT(v1, a1);
	phalcon_debug_assign("$e", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a23 (Foreach) File=/Internal/Test Line=475");
	FOREACH_KV(v1, ac0, fes28, fee28, ah0, hp0, v3, v2)
		phalcon_step_over("Phalcon_Internal_Test::a23 (Block) File=/Internal/Test Line=475");
		phalcon_step_over("Phalcon_Internal_Test::a23 (If) File=/Internal/Test Line=476");
		if (Z_TYPE_P(v2) == IS_ARRAY) { 
			phalcon_step_over("Phalcon_Internal_Test::a23 (Block) File=/Internal/Test Line=476");
			phalcon_step_over("Phalcon_Internal_Test::a23 (Foreach) File=/Internal/Test Line=477");
			FOREACH_KV(v2, ac1, fes29, fee29, ah1, hp1, v5, v4)
				phalcon_step_over("Phalcon_Internal_Test::a23 (Block) File=/Internal/Test Line=477");
				phalcon_step_over("Phalcon_Internal_Test::a23 (Assignment) File=/Internal/Test Line=478");
				if (Z_TYPE_P(v0) == IS_ARRAY) {
					if (!t0) {
						PHALCON_ALLOC_ZVAL(t0);
					} else {
						if (Z_REFCOUNT_P(t0) > 1) {
							PHALCON_SEPARATE(t0);
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
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v4, 1, 0);
					Z_SET_REFCOUNT_P(copy, 1);
					phalcon_array_update(t0, v5, copy TSRMLS_CC);
				}
			END_FOREACH(ac1, fes29, fee29, ah1, hp1);
		} else {
			phalcon_step_over("Phalcon_Internal_Test::a23 (Block) File=/Internal/Test Line=480");
			phalcon_step_over("Phalcon_Internal_Test::a23 (If) File=/Internal/Test Line=481");
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
			p0[1] = v2;
			phalcon_debug_param(v2 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r0, "strpos", 2, p0);
			phalcon_debug_vdump("strpos > ", r0 TSRMLS_CC);
			if (Z_TYPE_P(r0) != IS_BOOL || (Z_TYPE_P(r0) == IS_BOOL && Z_BVAL_P(r0))) {
				phalcon_step_over("Phalcon_Internal_Test::a23 (Block) File=/Internal/Test Line=481");
				phalcon_step_over("Phalcon_Internal_Test::a23 (Assignment) File=/Internal/Test Line=482");
				if (!r1) {
					PHALCON_ALLOC_ZVAL(r1);
				} else {
					if (Z_REFCOUNT_P(r1) > 1) {
						PHALCON_SEPARATE(r1);
					} else {
						FREE_ZVAL(r1);
						PHALCON_ALLOC_ZVAL(r1);
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
				p1[1] = v2;
				phalcon_debug_param(v2 TSRMLS_CC);
				PHALCON_CALL_FUNC_PARAMS(r1, "explode", 2, p1);
				phalcon_debug_vdump("explode > ", r1 TSRMLS_CC);
				PHALCON_CPY_WRT(v6, r1);
				phalcon_debug_assign("$p", r1 TSRMLS_CC);
				phalcon_step_over("Phalcon_Internal_Test::a23 (Assignment) File=/Internal/Test Line=483");
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
				phalcon_array_fetch_long(r2, v6, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
				if (Z_TYPE_P(v0) == IS_ARRAY) {
					if (!t1) {
						PHALCON_ALLOC_ZVAL(t1);
					} else {
						if (Z_REFCOUNT_P(t1) > 1) {
							PHALCON_SEPARATE(t1);
						} else {
							FREE_ZVAL(t1);
							PHALCON_ALLOC_ZVAL(t1);
						}
					}
					phalcon_array_fetch(t1, v0, v3, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_TYPE_P(t1) != IS_ARRAY) {
					convert_to_array(t1);
					phalcon_array_update(v0, v3, t1 TSRMLS_CC);
					Z_ADDREF_P(t1);
				}
				if (!r3) {
					PHALCON_ALLOC_ZVAL(r3);
				} else {
					if (Z_REFCOUNT_P(r3) > 1) {
						PHALCON_SEPARATE(r3);
					} else {
						FREE_ZVAL(r3);
						PHALCON_ALLOC_ZVAL(r3);
					}
				}
				phalcon_array_fetch_long(r3, v6, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, r2, 1, 0);
					Z_SET_REFCOUNT_P(copy, 1);
					phalcon_array_update(t1, r3, copy TSRMLS_CC);
				}
			} else {
				phalcon_step_over("Phalcon_Internal_Test::a23 (Block) File=/Internal/Test Line=484");
				phalcon_step_over("Phalcon_Internal_Test::a23 (Assignment) File=/Internal/Test Line=485");
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v2, 1, 0);
					Z_SET_REFCOUNT_P(copy, 1);
					PHALCON_SEPARATE_PARAM(v0);
					phalcon_array_update(v0, v3, copy TSRMLS_CC);
				}
			}
		}
	END_FOREACH(ac0, fes28, fee28, ah0, hp0);
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
	phalcon_step_over("Phalcon_Internal_Test::a23 (Method) File=/Internal/Test Line=492");
}

PHP_METHOD(Phalcon_Internal_Test, a24){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "a24", 0);
	phalcon_step_over("Phalcon_Internal_Test::a24 (Assignment) File=/Internal/Test Line=493");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		PHALCON_SEPARATE(a0);
		add_next_index_zval(a0, copy);
	}
	PHALCON_CPY_WRT(v1, a0);
	phalcon_debug_assign("$e", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::a24 (Assignment) File=/Internal/Test Line=494");
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CONCAT_LEFT(r0, "hello, ", v0);
	PHALCON_CPY_WRT(v2, r0);
	phalcon_debug_assign("$p", r0 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::a24 (Method) File=/Internal/Test Line=498");
}

PHP_METHOD(Phalcon_Internal_Test, a25){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "a25", 0);
	phalcon_step_over("Phalcon_Internal_Test::a25 (Assignment) File=/Internal/Test Line=499");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_STRING(v0, "h", 0);
	phalcon_step_over("Phalcon_Internal_Test::a25 (Assignment) File=/Internal/Test Line=500");
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_STRING(v1, "k", 0);
	phalcon_step_over("Phalcon_Internal_Test::a25 (Assignment) File=/Internal/Test Line=501");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_assoc_string(a0, "k", "v", 1);
	add_assoc_string(a0, "i", "d", 1);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t0) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_array_fetch(t1, t0, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_TYPE_P(t1) != IS_ARRAY) {
		convert_to_array(t1);
		phalcon_array_update(t0, v0, t1 TSRMLS_CC);
		Z_ADDREF_P(t1);
	}
	phalcon_array_update(t1, v1, a0 TSRMLS_CC);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), copy TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t2);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::a25 (Method) File=/Internal/Test Line=509");
}

PHP_METHOD(Phalcon_Internal_Test, sa0){

	zval *a0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sa0", 0);
	phalcon_step_over("Phalcon_Internal_Test::sa0 (Assignment) File=/Internal/Test Line=510");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::sa0 (Method) File=/Internal/Test Line=513");
}

PHP_METHOD(Phalcon_Internal_Test, sa1){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sa1", 0);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sa1 (Method) File=/Internal/Test Line=517");
}

PHP_METHOD(Phalcon_Internal_Test, sa2){

	zval *a0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sa2", 0);
	phalcon_step_over("Phalcon_Internal_Test::sa2 (Assignment) File=/Internal/Test Line=518");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	add_next_index_string(a0, "lol", 1);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::sa2 (Method) File=/Internal/Test Line=521");
}

PHP_METHOD(Phalcon_Internal_Test, sa3){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sa3", 0);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sa3 (Method) File=/Internal/Test Line=525");
}

PHP_METHOD(Phalcon_Internal_Test, sa4){

	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sa4", 0);
	phalcon_step_over("Phalcon_Internal_Test::sa4 (Assignment) File=/Internal/Test Line=526");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sa4 (Assignment) File=/Internal/Test Line=527");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		convert_to_array(t0);
	}
	phalcon_array_append(t0, a1 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, t0 TSRMLS_CC);
	
	phalcon_step_over("Phalcon_Internal_Test::sa4 (Assignment) File=/Internal/Test Line=528");
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
	
	phalcon_step_over("Phalcon_Internal_Test::sa4 (Assignment) File=/Internal/Test Line=529");
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
	PHALCON_RETURN_CTOR(t7);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sa4 (Method) File=/Internal/Test Line=533");
}

PHP_METHOD(Phalcon_Internal_Test, sa5){

	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sa5", 0);
	phalcon_step_over("Phalcon_Internal_Test::sa5 (Assignment) File=/Internal/Test Line=534");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sa5 (Assignment) File=/Internal/Test Line=535");
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
	PHALCON_RETURN_CTOR(t5);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sa5 (Method) File=/Internal/Test Line=539");
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
	phalcon_step_over("Phalcon_Internal_Test::sa6 (Assignment) File=/Internal/Test Line=540");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sa6 (Assignment) File=/Internal/Test Line=541");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	add_next_index_long(a1, 4);
	add_next_index_long(a1, 5);
	PHALCON_CPY_WRT_PARAM(v0, a1);
	phalcon_debug_assign("$e", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sa6 (Foreach) File=/Internal/Test Line=542");
	FOREACH_KV(v0, ac0, fes30, fee30, ah0, hp0, v2, v1)
		phalcon_step_over("Phalcon_Internal_Test::sa6 (Block) File=/Internal/Test Line=542");
		phalcon_step_over("Phalcon_Internal_Test::sa6 (Assignment) File=/Internal/Test Line=543");
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
				PHALCON_SEPARATE(r0);
			}
		}
		mul_function(r0, v2, t0 TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r0);
		phalcon_debug_assign("$k", r0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Internal_Test::sa6 (Assignment) File=/Internal/Test Line=544");
		if (!r1) {
			PHALCON_ALLOC_ZVAL(r1);
		} else {
			if (Z_REFCOUNT_P(r1) > 1){ 
				PHALCON_SEPARATE(r1);
			}
		}
		add_function(r1, v1, v2 TSRMLS_CC);
		t1 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (Z_TYPE_P(t1) != IS_ARRAY) {
			convert_to_array(t1);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			phalcon_array_update(t1, v2, copy TSRMLS_CC);
		}
		zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, t1 TSRMLS_CC);
		
	END_FOREACH(ac0, fes30, fee30, ah0, hp0);
	t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t2);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sa6 (Method) File=/Internal/Test Line=549");
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
	phalcon_step_over("Phalcon_Internal_Test::sa7 (Assignment) File=/Internal/Test Line=550");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sa7 (Assignment) File=/Internal/Test Line=551");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	add_assoc_string(a2, "in", "out", 1);
	PHALCON_SEPARATE(a1);
	add_assoc_zval(a1, "hello", a2);
	PHALCON_ALLOC_ZVAL(a3);
	array_init(a3);
	add_assoc_string(a3, "file", "type", 1);
	add_assoc_string(a3, "php", "unix", 1);
	add_assoc_string(a3, "tab", "ins", 1);
	PHALCON_SEPARATE(a1);
	add_assoc_zval(a1, "bye", a3);
	PHALCON_ALLOC_ZVAL(a4);
	array_init(a4);
	PHALCON_SEPARATE(a1);
	add_assoc_zval(a1, "encoding", a4);
	add_assoc_string(a1, "sucks", "yes", 1);
	PHALCON_CPY_WRT_PARAM(v0, a1);
	phalcon_debug_assign("$e", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sa7 (Foreach) File=/Internal/Test Line=565");
	FOREACH_KV(v0, ac0, fes31, fee31, ah0, hp0, v2, v1)
		phalcon_step_over("Phalcon_Internal_Test::sa7 (Block) File=/Internal/Test Line=565");
		phalcon_step_over("Phalcon_Internal_Test::sa7 (If) File=/Internal/Test Line=566");
		if (Z_TYPE_P(v1) == IS_ARRAY) { 
			phalcon_step_over("Phalcon_Internal_Test::sa7 (Block) File=/Internal/Test Line=566");
			phalcon_step_over("Phalcon_Internal_Test::sa7 (Foreach) File=/Internal/Test Line=567");
			FOREACH_KV(v1, ac1, fes32, fee32, ah1, hp1, v4, v3)
				phalcon_step_over("Phalcon_Internal_Test::sa7 (Block) File=/Internal/Test Line=567");
				phalcon_step_over("Phalcon_Internal_Test::sa7 (Assignment) File=/Internal/Test Line=568");
				t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
				if (Z_TYPE_P(t0) != IS_ARRAY) {
					convert_to_array(t0);
				}
				if (Z_TYPE_P(t0) == IS_ARRAY) {
					if (!t1) {
						PHALCON_ALLOC_ZVAL(t1);
					} else {
						if (Z_REFCOUNT_P(t1) > 1) {
							PHALCON_SEPARATE(t1);
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
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v3, 1, 0);
					Z_SET_REFCOUNT_P(copy, 1);
					phalcon_array_update(t1, v4, copy TSRMLS_CC);
				}
				zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, t0 TSRMLS_CC);
				
			END_FOREACH(ac1, fes32, fee32, ah1, hp1);
		} else {
			phalcon_step_over("Phalcon_Internal_Test::sa7 (Block) File=/Internal/Test Line=570");
			phalcon_step_over("Phalcon_Internal_Test::sa7 (Assignment) File=/Internal/Test Line=571");
			t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			if (Z_TYPE_P(t2) != IS_ARRAY) {
				convert_to_array(t2);
			}
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v1, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				phalcon_array_update(t2, v2, copy TSRMLS_CC);
			}
			zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, t2 TSRMLS_CC);
			
		}
	END_FOREACH(ac0, fes31, fee31, ah0, hp0);
	t3 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t3 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t3);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sa7 (Method) File=/Internal/Test Line=578");
}

PHP_METHOD(Phalcon_Internal_Test, c1){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c1", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL(r0);
	is_equal_function(r0, t0, t1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::c1 (Method) File=/Internal/Test Line=582");
}

PHP_METHOD(Phalcon_Internal_Test, c2){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c2", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL(r0);
	is_not_equal_function(r0, t0, t1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::c2 (Method) File=/Internal/Test Line=586");
}

PHP_METHOD(Phalcon_Internal_Test, c3){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c3", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL(r0);
	is_smaller_or_equal_function(r0, t0, t1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::c3 (Method) File=/Internal/Test Line=590");
}

PHP_METHOD(Phalcon_Internal_Test, c4){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c4", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL(r0);
	is_smaller_or_equal_function(r0, t1, t0 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::c4 (Method) File=/Internal/Test Line=594");
}

PHP_METHOD(Phalcon_Internal_Test, c5){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c5", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL(r0);
	is_smaller_function(r0, t1, t0 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::c5 (Method) File=/Internal/Test Line=598");
}

PHP_METHOD(Phalcon_Internal_Test, c6){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c6", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL(r0);
	is_smaller_function(r0, t0, t1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::c6 (Method) File=/Internal/Test Line=602");
}

PHP_METHOD(Phalcon_Internal_Test, c7){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c7", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL(r0);
	is_equal_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t2);
	ZVAL_LONG(t2, 1);
	PHALCON_ALLOC_ZVAL(t3);
	ZVAL_LONG(t3, 1);
	PHALCON_ALLOC_ZVAL(r1);
	is_smaller_or_equal_function(r1, t2, t3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r2);
	phalcon_and_function(r2, r0, r1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::c7 (Method) File=/Internal/Test Line=606");
}

PHP_METHOD(Phalcon_Internal_Test, c8){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c8", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL(r0);
	is_not_equal_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t2);
	ZVAL_LONG(t2, 1);
	PHALCON_ALLOC_ZVAL(t3);
	ZVAL_LONG(t3, 1);
	PHALCON_ALLOC_ZVAL(r1);
	is_smaller_function(r1, t2, t3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r2);
	phalcon_and_function(r2, r0, r1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::c8 (Method) File=/Internal/Test Line=610");
}

PHP_METHOD(Phalcon_Internal_Test, c9){

	zval *r0 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c9", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 0);
	PHALCON_ALLOC_ZVAL(r0);
	boolean_not_function(r0, t0 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::c9 (Method) File=/Internal/Test Line=614");
}

PHP_METHOD(Phalcon_Internal_Test, c10){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "c10", 0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL(r1);
	is_not_equal_function(r1, t0, t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	boolean_not_function(r0, r1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::c10 (Method) File=/Internal/Test Line=618");
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
	PHALCON_ALLOC_ZVAL(r0);
	is_equal_function(r0, v1, v2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	is_equal_function(r1, v0, r0 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::c11 (Method) File=/Internal/Test Line=625");
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
	phalcon_step_over("Phalcon_Internal_Test::f1 (Method) File=/Internal/Test Line=629");
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
	phalcon_step_over("Phalcon_Internal_Test::f2 (Method) File=/Internal/Test Line=633");
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
	phalcon_step_over("Phalcon_Internal_Test::f3 (Method) File=/Internal/Test Line=637");
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
	phalcon_step_over("Phalcon_Internal_Test::f4 (Method) File=/Internal/Test Line=641");
}

PHP_METHOD(Phalcon_Internal_Test, f5){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Internal_Test", "f5", 0);
	phalcon_step_over("Phalcon_Internal_Test::f5 (Assignment) File=/Internal/Test Line=642");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_string(a0, "b", 1);
	add_next_index_string(a0, "c", 1);
	add_next_index_string(a0, "a", 1);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$e", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::f5 (FunctionCall) File=/Internal/Test Line=643");
	Z_SET_ISREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("asort", 1, p0);
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
	phalcon_step_over("Phalcon_Internal_Test::f5 (Method) File=/Internal/Test Line=647");
}

PHP_METHOD(Phalcon_Internal_Test, f6){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL, NULL }, *p2[] = { NULL, NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL };

	phalcon_step_into_entry("Phalcon_Internal_Test", "f6", 0);
	phalcon_step_over("Phalcon_Internal_Test::f6 (Assignment) File=/Internal/Test Line=648");
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_PARAM_LONG(p0[0], 0);
	PHALCON_PARAM_LONG(p0[1], 100);
	PHALCON_CALL_FUNC_PARAMS(r0, "mt_rand", 2, p0);
	phalcon_debug_vdump("mt_rand > ", r0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CONCAT_RIGHT(r1, r0, ".txt");
	PHALCON_CPY_WRT_PARAM(v0, r1);
	phalcon_debug_assign("$file", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::f6 (Assignment) File=/Internal/Test Line=649");
	PHALCON_ALLOC_ZVAL(r2);
	p1[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p1[1]);
	ZVAL_STRING(p1[1], "w", 1);
	PHALCON_CALL_FUNC_PARAMS(r2, "fopen", 2, p1);
	phalcon_debug_vdump("fopen > ", r2 TSRMLS_CC);
	PHALCON_CPY_WRT_PARAM(v1, r2);
	phalcon_debug_assign("$fp", r2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::f6 (FunctionCall) File=/Internal/Test Line=650");
	Z_ADDREF_P(v1);
	p2[0] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p2[1]);
	ZVAL_STRING(p2[1], "morelol\n", 1);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("fwrite", 2, p2);
	phalcon_step_over("Phalcon_Internal_Test::f6 (FunctionCall) File=/Internal/Test Line=651");
	Z_ADDREF_P(v1);
	p3[0] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("fclose", 1, p3);
	phalcon_step_over("Phalcon_Internal_Test::f6 (Assignment) File=/Internal/Test Line=652");
	PHALCON_ALLOC_ZVAL(r3);
	p4[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r3, "file_get_contents", 1, p4);
	phalcon_debug_vdump("file_get_contents > ", r3 TSRMLS_CC);
	PHALCON_CPY_WRT_PARAM(v2, r3);
	phalcon_debug_assign("$content", r3 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::f6 (FunctionCall) File=/Internal/Test Line=653");
	p5[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("unlink", 1, p5);
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(v2);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::f6 (Method) File=/Internal/Test Line=657");
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
	phalcon_step_over("Phalcon_Internal_Test::f7 (Method) File=/Internal/Test Line=661");
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
	phalcon_step_over("Phalcon_Internal_Test::f8 (Method) File=/Internal/Test Line=665");
}

PHP_METHOD(Phalcon_Internal_Test, f9){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Internal_Test", "f9", 0);
	phalcon_step_over("Phalcon_Internal_Test::f9 (Assignment) File=/Internal/Test Line=666");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "-1000", 1);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 400);
	PHALCON_ALLOC_ZVAL(r0);
	mul_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t2);
	ZVAL_BOOL(t2, 0);
	PHALCON_ALLOC_ZVAL(r1);
	mul_function(r1, r0, t2 TSRMLS_CC);
	PHALCON_CPY_WRT_PARAM(v0, r1);
	phalcon_debug_assign("$e", r1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r2);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r2, "abs", 1, p0);
	phalcon_debug_vdump("abs > ", r2 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r2 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r2, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::f9 (Method) File=/Internal/Test Line=670");
}

PHP_METHOD(Phalcon_Internal_Test, f10){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Internal_Test", "f10", 0);
	phalcon_step_over("Phalcon_Internal_Test::f10 (Assignment) File=/Internal/Test Line=671");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::f10 (If) File=/Internal/Test Line=672");
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_array_fetch_long(r1, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r1);
	p0[0] = r1;
	phalcon_debug_param(r1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "is_numeric", 1, p0);
	phalcon_debug_vdump("is_numeric > ", r0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Internal_Test::f10 (Block) File=/Internal/Test Line=672");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Internal_Test::f10 (Block) File=/Internal/Test Line=674");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::f10 (Method) File=/Internal/Test Line=682");
}

PHP_METHOD(Phalcon_Internal_Test, m1){


	phalcon_step_into_entry("Phalcon_Internal_Test", "m1", 0);
	phalcon_step_out_entry();
	RETURN_STRING("private", 1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::m1 (Method) File=/Internal/Test Line=686");
}

PHP_METHOD(Phalcon_Internal_Test, m2){


	phalcon_step_into_entry("Phalcon_Internal_Test", "m2", 0);
	phalcon_step_out_entry();
	RETURN_STRING("protected", 1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::m2 (Method) File=/Internal/Test Line=690");
}

PHP_METHOD(Phalcon_Internal_Test, m3){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "m3", 0);
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m1" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "m1", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::m3 (Method) File=/Internal/Test Line=694");
}

PHP_METHOD(Phalcon_Internal_Test, m4){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "m4", 0);
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m2" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "m2", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::m4 (Method) File=/Internal/Test Line=698");
}

PHP_METHOD(Phalcon_Internal_Test, m5){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "m5", 0);
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m2" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "m2", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
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
	phalcon_step_over("Phalcon_Internal_Test::m5 (Method) File=/Internal/Test Line=702");
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
	phalcon_step_over("Phalcon_Internal_Test::m6 (Method) File=/Internal/Test Line=706");
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
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m6" TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::m7 (Method) File=/Internal/Test Line=710");
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
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m6" TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	Z_ADDREF_P(v1);
	p0[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "m6", 2, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m6" TSRMLS_CC);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::m8 (Method) File=/Internal/Test Line=714");
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
	phalcon_step_over("Phalcon_Internal_Test::m9 (Method) File=/Internal/Test Line=718");
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
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m9" TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::m10 (Method) File=/Internal/Test Line=722");
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
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m10" TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::m11 (Method) File=/Internal/Test Line=726");
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
	phalcon_step_over("Phalcon_Internal_Test::m12 (Assignment) File=/Internal/Test Line=727");
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_LONG(v2, 0);
	phalcon_step_over("Phalcon_Internal_Test::m12 (For) File=/Internal/Test Line=728");
	PHALCON_ALLOC_ZVAL(v3);
	ZVAL_LONG(v3, 0);
	fs33:
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_ALLOC_ZVAL(r0);
	is_smaller_function(r0, v3, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe33;
	}
	phalcon_step_over("Phalcon_Internal_Test::m12 (Block) File=/Internal/Test Line=728");
	phalcon_step_over("Phalcon_Internal_Test::m12 (AssignOp) File=/Internal/Test Line=729");
	if (!r1) {
		PHALCON_ALLOC_ZVAL(r1);
	} else {
		if (Z_REFCOUNT_P(r1) > 1) {
			PHALCON_SEPARATE(r1);
		} else {
			FREE_ZVAL(r1);
			PHALCON_ALLOC_ZVAL(r1);
		}
	}
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m9" TSRMLS_CC);
	if (!r2) {
		PHALCON_ALLOC_ZVAL(r2);
	} else {
		if (Z_REFCOUNT_P(r2) > 1){ 
			PHALCON_SEPARATE(r2);
		}
	}
	add_function(r2, v3, v0 TSRMLS_CC);
	Z_ADDREF_P(r2);
	p0[0] = r2;
	phalcon_debug_param(r2 TSRMLS_CC);
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
			PHALCON_SEPARATE(r3);
		}
	}
	add_function(r3, v3, t1 TSRMLS_CC);
	if (!r4) {
		PHALCON_ALLOC_ZVAL(r4);
	} else {
		if (Z_REFCOUNT_P(r4) > 1){ 
			PHALCON_SEPARATE(r4);
		}
	}
	add_function(r4, v1, r3 TSRMLS_CC);
	Z_ADDREF_P(r4);
	p0[1] = r4;
	phalcon_debug_param(r4 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "m9", 2, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	if (!r5) {
		PHALCON_ALLOC_ZVAL(r5);
	} else {
		if (Z_REFCOUNT_P(r5) > 1){ 
			PHALCON_SEPARATE(r5);
		}
	}
	add_function(r5, v2, r1 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r5);
	phalcon_debug_assign("$d", r5 TSRMLS_CC);
	PHALCON_SEPARATE(v3);
	increment_function(v3);
	phalcon_debug_vdump("PostIncrementing $c", v3);
	goto fs33;
	fe33:
	r0 = NULL;
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
	phalcon_step_over("Phalcon_Internal_Test::m12 (Method) File=/Internal/Test Line=734");
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
	phalcon_step_over("Phalcon_Internal_Test::m13 (Assignment) File=/Internal/Test Line=735");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 100);
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
	phalcon_step_over("Phalcon_Internal_Test::m13 (Method) File=/Internal/Test Line=739");
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
	phalcon_step_over("Phalcon_Internal_Test::m14 (Assignment) File=/Internal/Test Line=740");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m13" TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	Z_ADDREF_P(v1);
	p0[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "m13", 2, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	mul_function(r1, r0, v0 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r1);
	phalcon_debug_assign("$f", r1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::m14 (Method) File=/Internal/Test Line=744");
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
	phalcon_step_over("Phalcon_Internal_Test::m15 (Assignment) File=/Internal/Test Line=745");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "m13" TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	Z_ADDREF_P(v1);
	p0[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "m13", 2, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r0);
	phalcon_debug_assign("$f", r0 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::m15 (Method) File=/Internal/Test Line=752");
}

PHP_METHOD(Phalcon_Internal_Test, mp3){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "mp3", 0);
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "mp1" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "mp1", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::mp3 (Method) File=/Internal/Test Line=756");
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
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "mp2" TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::mp4 (Method) File=/Internal/Test Line=760");
}

PHP_METHOD(Phalcon_Internal_Test, mp5){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "mp5", 0);
	phalcon_step_over("Phalcon_Internal_Test::mp5 (Assignment) File=/Internal/Test Line=761");
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_internal_testparent_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	PHALCON_CPY_WRT_PARAM(v0, i0);
	phalcon_debug_assign("$o", i0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(v0, "mp1" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, v0, "mp1", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::mp5 (Method) File=/Internal/Test Line=765");
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
	phalcon_step_over("Phalcon_Internal_Test::mp6 (Assignment) File=/Internal/Test Line=766");
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_internal_testparent_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	PHALCON_CPY_WRT(v2, i0);
	phalcon_debug_assign("$o", i0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(v2, "mp2" TSRMLS_CC);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::mp6 (Method) File=/Internal/Test Line=773");
}

PHP_METHOD(Phalcon_Internal_Test, sm1){


	phalcon_step_into_entry("Phalcon_Internal_Test", "sm1", 0);
	phalcon_step_out_entry();
	RETURN_STRING("private", 1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sm1 (Method) File=/Internal/Test Line=777");
}

PHP_METHOD(Phalcon_Internal_Test, sm2){


	phalcon_step_into_entry("Phalcon_Internal_Test", "sm2", 0);
	phalcon_step_out_entry();
	RETURN_STRING("protected", 1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sm2 (Method) File=/Internal/Test Line=781");
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
	phalcon_step_over("Phalcon_Internal_Test::sm3 (Method) File=/Internal/Test Line=785");
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
	phalcon_step_over("Phalcon_Internal_Test::sm4 (Method) File=/Internal/Test Line=789");
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
	phalcon_step_over("Phalcon_Internal_Test::sm5 (Method) File=/Internal/Test Line=793");
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
	phalcon_step_over("Phalcon_Internal_Test::sm6 (Method) File=/Internal/Test Line=797");
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
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	Z_ADDREF_P(v1);
	p0[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "sm6", 2, p0);
	phalcon_debug_vdump("SelfStaticReturn > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sm7 (Method) File=/Internal/Test Line=801");
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
	phalcon_step_over("Phalcon_Internal_Test::sm8 (Method) File=/Internal/Test Line=805");
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
	phalcon_step_over("Phalcon_Internal_Test::sm9 (Assignment) File=/Internal/Test Line=806");
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_LONG(v2, 0);
	phalcon_step_over("Phalcon_Internal_Test::sm9 (For) File=/Internal/Test Line=807");
	PHALCON_ALLOC_ZVAL(v3);
	ZVAL_LONG(v3, 0);
	fs34:
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_ALLOC_ZVAL(r0);
	is_smaller_function(r0, v3, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe34;
	}
	phalcon_step_over("Phalcon_Internal_Test::sm9 (Block) File=/Internal/Test Line=807");
	phalcon_step_over("Phalcon_Internal_Test::sm9 (AssignOp) File=/Internal/Test Line=808");
	if (!r1) {
		PHALCON_ALLOC_ZVAL(r1);
	} else {
		if (Z_REFCOUNT_P(r1) > 1) {
			PHALCON_SEPARATE(r1);
		} else {
			FREE_ZVAL(r1);
			PHALCON_ALLOC_ZVAL(r1);
		}
	}
	if (!r2) {
		PHALCON_ALLOC_ZVAL(r2);
	} else {
		if (Z_REFCOUNT_P(r2) > 1){ 
			PHALCON_SEPARATE(r2);
		}
	}
	add_function(r2, v3, v0 TSRMLS_CC);
	Z_ADDREF_P(r2);
	p0[0] = r2;
	phalcon_debug_param(r2 TSRMLS_CC);
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
			PHALCON_SEPARATE(r3);
		}
	}
	add_function(r3, v3, t1 TSRMLS_CC);
	if (!r4) {
		PHALCON_ALLOC_ZVAL(r4);
	} else {
		if (Z_REFCOUNT_P(r4) > 1){ 
			PHALCON_SEPARATE(r4);
		}
	}
	add_function(r4, v1, r3 TSRMLS_CC);
	Z_ADDREF_P(r4);
	p0[1] = r4;
	phalcon_debug_param(r4 TSRMLS_CC);
	PHALCON_CALL_SELF_PARAMS(r1, this_ptr, "sm8", 2, p0);
	phalcon_debug_vdump("SelfStaticReturn > ", r1 TSRMLS_CC);
	if (!r5) {
		PHALCON_ALLOC_ZVAL(r5);
	} else {
		if (Z_REFCOUNT_P(r5) > 1){ 
			PHALCON_SEPARATE(r5);
		}
	}
	add_function(r5, v2, r1 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r5);
	phalcon_debug_assign("$d", r5 TSRMLS_CC);
	PHALCON_SEPARATE(v3);
	increment_function(v3);
	phalcon_debug_vdump("PostIncrementing $c", v3);
	goto fs34;
	fe34:
	r0 = NULL;
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
	phalcon_step_over("Phalcon_Internal_Test::sm9 (Method) File=/Internal/Test Line=813");
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
	phalcon_step_over("Phalcon_Internal_Test::sm10 (Assignment) File=/Internal/Test Line=814");
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_LONG(v2, 0);
	phalcon_step_over("Phalcon_Internal_Test::sm10 (For) File=/Internal/Test Line=815");
	PHALCON_ALLOC_ZVAL(v3);
	ZVAL_LONG(v3, 0);
	fs35:
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_ALLOC_ZVAL(r0);
	is_smaller_function(r0, v3, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe35;
	}
	phalcon_step_over("Phalcon_Internal_Test::sm10 (Block) File=/Internal/Test Line=815");
	phalcon_step_over("Phalcon_Internal_Test::sm10 (AssignOp) File=/Internal/Test Line=816");
	if (!r1) {
		PHALCON_ALLOC_ZVAL(r1);
	} else {
		if (Z_REFCOUNT_P(r1) > 1) {
			PHALCON_SEPARATE(r1);
		} else {
			FREE_ZVAL(r1);
			PHALCON_ALLOC_ZVAL(r1);
		}
	}
	if (!r2) {
		PHALCON_ALLOC_ZVAL(r2);
	} else {
		if (Z_REFCOUNT_P(r2) > 1){ 
			PHALCON_SEPARATE(r2);
		}
	}
	add_function(r2, v3, v0 TSRMLS_CC);
	Z_ADDREF_P(r2);
	p0[0] = r2;
	phalcon_debug_param(r2 TSRMLS_CC);
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
			PHALCON_SEPARATE(r3);
		}
	}
	add_function(r3, v3, t1 TSRMLS_CC);
	if (!r4) {
		PHALCON_ALLOC_ZVAL(r4);
	} else {
		if (Z_REFCOUNT_P(r4) > 1){ 
			PHALCON_SEPARATE(r4);
		}
	}
	add_function(r4, v1, r3 TSRMLS_CC);
	Z_ADDREF_P(r4);
	p0[1] = r4;
	phalcon_debug_param(r4 TSRMLS_CC);
	PHALCON_CALL_STATIC_PARAMS(r1, "phalcon_internal_test", "sm8", 2, p0);
	phalcon_debug_vdump("StaticReturn > ", r1 TSRMLS_CC);
	if (!r5) {
		PHALCON_ALLOC_ZVAL(r5);
	} else {
		if (Z_REFCOUNT_P(r5) > 1){ 
			PHALCON_SEPARATE(r5);
		}
	}
	add_function(r5, v2, r1 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r5);
	phalcon_debug_assign("$d", r5 TSRMLS_CC);
	PHALCON_SEPARATE(v3);
	increment_function(v3);
	phalcon_debug_vdump("PostIncrementing $c", v3);
	goto fs35;
	fe35:
	r0 = NULL;
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
	phalcon_step_over("Phalcon_Internal_Test::sm10 (Method) File=/Internal/Test Line=821");
}

PHP_METHOD(Phalcon_Internal_Test, sm11){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sm11", 0);
	phalcon_step_over("Phalcon_Internal_Test::sm11 (Assignment) File=/Internal/Test Line=822");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_STRING(v0, "sm2", 0);
	phalcon_step_over("Phalcon_Internal_Test::sm11 (Assignment) File=/Internal/Test Line=823");
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_STRING(v1, "Phalcon_Internal_Test", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_ZVAL_STATIC(r0, v1, "sm2");
	phalcon_debug_vdump("StaticReturn > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sm11 (Method) File=/Internal/Test Line=830");
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
	phalcon_step_over("Phalcon_Internal_Test::smp2 (Method) File=/Internal/Test Line=834");
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
	Z_ADDREF_P(v1);
	p0[0] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[1] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_PARENT_PARAMS(r0, this_ptr, "Phalcon_Internal_Test", "smp3", 2, p0);
	phalcon_debug_vdump("ParentStaticReturn > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::smp4 (Method) File=/Internal/Test Line=838");
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
	phalcon_step_over("Phalcon_Internal_Test::smp5 (Assignment) File=/Internal/Test Line=839");
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_LONG(v2, 0);
	phalcon_step_over("Phalcon_Internal_Test::smp5 (For) File=/Internal/Test Line=840");
	PHALCON_ALLOC_ZVAL(v3);
	ZVAL_LONG(v3, 0);
	fs36:
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_ALLOC_ZVAL(r0);
	is_smaller_function(r0, v3, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe36;
	}
	phalcon_step_over("Phalcon_Internal_Test::smp5 (Block) File=/Internal/Test Line=840");
	phalcon_step_over("Phalcon_Internal_Test::smp5 (AssignOp) File=/Internal/Test Line=841");
	if (!r1) {
		PHALCON_ALLOC_ZVAL(r1);
	} else {
		if (Z_REFCOUNT_P(r1) > 1) {
			PHALCON_SEPARATE(r1);
		} else {
			FREE_ZVAL(r1);
			PHALCON_ALLOC_ZVAL(r1);
		}
	}
	if (!r2) {
		PHALCON_ALLOC_ZVAL(r2);
	} else {
		if (Z_REFCOUNT_P(r2) > 1){ 
			PHALCON_SEPARATE(r2);
		}
	}
	add_function(r2, v3, v0 TSRMLS_CC);
	Z_ADDREF_P(r2);
	p0[0] = r2;
	phalcon_debug_param(r2 TSRMLS_CC);
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
			PHALCON_SEPARATE(r3);
		}
	}
	add_function(r3, v3, t1 TSRMLS_CC);
	if (!r4) {
		PHALCON_ALLOC_ZVAL(r4);
	} else {
		if (Z_REFCOUNT_P(r4) > 1){ 
			PHALCON_SEPARATE(r4);
		}
	}
	add_function(r4, v1, r3 TSRMLS_CC);
	Z_ADDREF_P(r4);
	p0[1] = r4;
	phalcon_debug_param(r4 TSRMLS_CC);
	PHALCON_CALL_STATIC_PARAMS(r1, "phalcon_internal_test", "smp3", 2, p0);
	phalcon_debug_vdump("StaticReturn > ", r1 TSRMLS_CC);
	if (!r5) {
		PHALCON_ALLOC_ZVAL(r5);
	} else {
		if (Z_REFCOUNT_P(r5) > 1){ 
			PHALCON_SEPARATE(r5);
		}
	}
	add_function(r5, v2, r1 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r5);
	phalcon_debug_assign("$d", r5 TSRMLS_CC);
	PHALCON_SEPARATE(v3);
	increment_function(v3);
	phalcon_debug_vdump("PostIncrementing $c", v3);
	goto fs36;
	fe36:
	r0 = NULL;
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
	phalcon_step_over("Phalcon_Internal_Test::smp5 (Method) File=/Internal/Test Line=849");
}

PHP_METHOD(Phalcon_Internal_Test, p1){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p1", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p1", sizeof("_p1")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p1 (Method) File=/Internal/Test Line=853");
}

PHP_METHOD(Phalcon_Internal_Test, p2){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p2", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p2", sizeof("_p2")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p2 (Method) File=/Internal/Test Line=857");
}

PHP_METHOD(Phalcon_Internal_Test, p3){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p3", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p3", sizeof("_p3")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p3 (Method) File=/Internal/Test Line=861");
}

PHP_METHOD(Phalcon_Internal_Test, p4){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p4", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p4", sizeof("_p4")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p4 (Method) File=/Internal/Test Line=865");
}

PHP_METHOD(Phalcon_Internal_Test, p5){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p5", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p5", sizeof("_p5")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p5 (Method) File=/Internal/Test Line=869");
}

PHP_METHOD(Phalcon_Internal_Test, p6){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p6", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p6", sizeof("_p6")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p6 (Method) File=/Internal/Test Line=873");
}

PHP_METHOD(Phalcon_Internal_Test, p7){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p7", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p7", sizeof("_p7")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p7 (Method) File=/Internal/Test Line=877");
}

PHP_METHOD(Phalcon_Internal_Test, p8){


	phalcon_step_into_entry("Phalcon_Internal_Test", "p8", 0);
	phalcon_step_over("Phalcon_Internal_Test::p8 (Assignment) File=/Internal/Test Line=878");
	phalcon_update_property_string(this_ptr, "_p0", strlen("_p0"), "more-lol" TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::p8 (Method) File=/Internal/Test Line=881");
}

PHP_METHOD(Phalcon_Internal_Test, p9){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p9", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p9 (Method) File=/Internal/Test Line=885");
}

PHP_METHOD(Phalcon_Internal_Test, p10){


	phalcon_step_into_entry("Phalcon_Internal_Test", "p10", 0);
	phalcon_step_over("Phalcon_Internal_Test::p10 (Assignment) File=/Internal/Test Line=886");
	phalcon_update_property_long(this_ptr, "_p0", strlen("_p0"), 14750 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::p10 (Method) File=/Internal/Test Line=889");
}

PHP_METHOD(Phalcon_Internal_Test, p11){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p11", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p11 (Method) File=/Internal/Test Line=893");
}

PHP_METHOD(Phalcon_Internal_Test, p12){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p12", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p1", sizeof("_p1")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_p2", sizeof("_p2")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	concat_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_p3", sizeof("_p3")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p12 (Method) File=/Internal/Test Line=897");
}

PHP_METHOD(Phalcon_Internal_Test, p13){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p13", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p4", sizeof("_p4")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_p5", sizeof("_p5")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	add_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_p6", sizeof("_p6")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::p13 (Method) File=/Internal/Test Line=901");
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
	phalcon_step_over("Phalcon_Internal_Test::p14 (AssignOp) File=/Internal/Test Line=902");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	concat_function(r0, t0, v0 TSRMLS_CC);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, r0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p0", strlen("_p0"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::p14 (Method) File=/Internal/Test Line=905");
}

PHP_METHOD(Phalcon_Internal_Test, p15){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Internal_Test", "p15", 0);
	phalcon_step_over("Phalcon_Internal_Test::p15 (Assignment) File=/Internal/Test Line=906");
	phalcon_update_property_string(this_ptr, "_p0", strlen("_p0"), "" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::p15 (For) File=/Internal/Test Line=907");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 0);
	fs37:
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 30);
	PHALCON_ALLOC_ZVAL(r0);
	is_smaller_function(r0, v0, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe37;
	}
	phalcon_step_over("Phalcon_Internal_Test::p15 (Block) File=/Internal/Test Line=907");
	phalcon_step_over("Phalcon_Internal_Test::p15 (MethodCall) File=/Internal/Test Line=908");
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "p14" TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "p14", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	PHALCON_SEPARATE_PARAM(v0);
	increment_function(v0);
	phalcon_debug_vdump("PostIncrementing $i", v0);
	goto fs37;
	fe37:
	r0 = NULL;
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p15 (Method) File=/Internal/Test Line=913");
}

PHP_METHOD(Phalcon_Internal_Test, p16){

	zval *v0 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p16", 0);
	phalcon_step_over("Phalcon_Internal_Test::p16 (Assignment) File=/Internal/Test Line=914");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_STRING(v0, "_p0", 0);
	phalcon_step_over("Phalcon_Internal_Test::p16 (Assignment) File=/Internal/Test Line=915");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "lol", 1);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v0), Z_STRLEN_P(v0), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::p16 (Method) File=/Internal/Test Line=918");
}

PHP_METHOD(Phalcon_Internal_Test, p17){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p17", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p17 (Method) File=/Internal/Test Line=922");
}

PHP_METHOD(Phalcon_Internal_Test, p18){

	zval *v0 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p18", 0);
	phalcon_step_over("Phalcon_Internal_Test::p18 (Assignment) File=/Internal/Test Line=923");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_STRING(v0, "_p0", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property_zval(t0, this_ptr, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p18 (Method) File=/Internal/Test Line=927");
}

PHP_METHOD(Phalcon_Internal_Test, p19){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p19", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p8", sizeof("_p8")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p19 (Method) File=/Internal/Test Line=931");
}

PHP_METHOD(Phalcon_Internal_Test, p20){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p20", 0);
	phalcon_step_over("Phalcon_Internal_Test::p20 (Assignment) File=/Internal/Test Line=932");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "hello", 1);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_p8", sizeof("_p8")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE(t1);
	phalcon_array_append(t1, t0 TSRMLS_CC);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p8", strlen("_p8"), copy TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_p8", sizeof("_p8")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t2);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p20 (Method) File=/Internal/Test Line=936");
}

PHP_METHOD(Phalcon_Internal_Test, p21){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p21", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p21 (Method) File=/Internal/Test Line=940");
}

PHP_METHOD(Phalcon_Internal_Test, p22){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "p22", 0);
	phalcon_step_over("Phalcon_Internal_Test::p22 (Assignment) File=/Internal/Test Line=941");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE(t0);
	phalcon_array_append(t0, v0 TSRMLS_CC);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), copy TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p22 (Method) File=/Internal/Test Line=945");
}

PHP_METHOD(Phalcon_Internal_Test, p23){

	zval *v0 = NULL;
	zval *t0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_Test", "p23", 0);
	phalcon_step_over("Phalcon_Internal_Test::p23 (Assignment) File=/Internal/Test Line=946");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), copy TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p23 (Method) File=/Internal/Test Line=950");
}

PHP_METHOD(Phalcon_Internal_Test, p24){

	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p24", 0);
	phalcon_step_over("Phalcon_Internal_Test::p24 (PostIncDecOp) File=/Internal/Test Line=951");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE(t0);
	increment_function(t0);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), copy TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p24 (Method) File=/Internal/Test Line=955");
}

PHP_METHOD(Phalcon_Internal_Test, p25){

	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p25", 0);
	phalcon_step_over("Phalcon_Internal_Test::p25 (PostIncDecOp) File=/Internal/Test Line=956");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE(t0);
	decrement_function(t0);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), copy TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p25 (Method) File=/Internal/Test Line=960");
}

PHP_METHOD(Phalcon_Internal_Test, p26){

	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p26", 0);
	phalcon_step_over("Phalcon_Internal_Test::p26 (PreIncDecOp) File=/Internal/Test Line=961");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE(t0);
	increment_function(t0);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), copy TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p26 (Method) File=/Internal/Test Line=965");
}

PHP_METHOD(Phalcon_Internal_Test, p27){

	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p27", 0);
	phalcon_step_over("Phalcon_Internal_Test::p27 (PreIncDecOp) File=/Internal/Test Line=966");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE(t0);
	decrement_function(t0);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), copy TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p27 (Method) File=/Internal/Test Line=970");
}

PHP_METHOD(Phalcon_Internal_Test, p28){

	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p28", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE(t0);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_ZVAL(t1, t0, 1, 0);
	increment_function(t0);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), copy TSRMLS_CC);
	}
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p28 (Method) File=/Internal/Test Line=974");
}

PHP_METHOD(Phalcon_Internal_Test, p29){

	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p29", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE(t0);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_ZVAL(t1, t0, 1, 0);
	decrement_function(t0);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), copy TSRMLS_CC);
	}
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::p29 (Method) File=/Internal/Test Line=978");
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
	phalcon_step_over("Phalcon_Internal_Test::p30 (Assignment) File=/Internal/Test Line=979");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_assoc_string(a1, "sup", "hello1", 1);
	PHALCON_SEPARATE(a0);
	add_assoc_zval(a0, "wish", a1);
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	add_assoc_string(a2, "xup", "hello2", 1);
	PHALCON_SEPARATE(a0);
	add_assoc_zval(a0, "be", a2);
	PHALCON_ALLOC_ZVAL(a3);
	array_init(a3);
	add_assoc_string(a3, "zup", "hello3", 1);
	PHALCON_SEPARATE(a0);
	add_assoc_zval(a0, "today", a3);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$b", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::p30 (Assignment) File=/Internal/Test Line=990");
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v1, i0);
	phalcon_debug_assign("$o", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::p30 (Foreach) File=/Internal/Test Line=991");
	FOREACH_KV(v0, ac0, fes38, fee38, ah0, hp0, v3, v2)
		phalcon_step_over("Phalcon_Internal_Test::p30 (Block) File=/Internal/Test Line=991");
		phalcon_step_over("Phalcon_Internal_Test::p30 (If) File=/Internal/Test Line=992");
		if (Z_TYPE_P(v2) == IS_ARRAY) { 
			phalcon_step_over("Phalcon_Internal_Test::p30 (Block) File=/Internal/Test Line=992");
			phalcon_step_over("Phalcon_Internal_Test::p30 (Assignment) File=/Internal/Test Line=993");
			if (!i1) {
				PHALCON_ALLOC_ZVAL(i1);
			} else {
				if (Z_REFCOUNT_P(i1) > 1) {
					PHALCON_SEPARATE(i1);
				} else {
					FREE_ZVAL(i1);
					PHALCON_ALLOC_ZVAL(i1);
				}
			}
			object_init(i1);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, i1, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(v1, Z_STRVAL_P(v3), Z_STRLEN_P(v3), copy TSRMLS_CC);
			}
			phalcon_step_over("Phalcon_Internal_Test::p30 (Foreach) File=/Internal/Test Line=994");
			FOREACH_KV(v2, ac1, fes39, fee39, ah1, hp1, v5, v4)
				phalcon_step_over("Phalcon_Internal_Test::p30 (Block) File=/Internal/Test Line=994");
				phalcon_step_over("Phalcon_Internal_Test::p30 (Assignment) File=/Internal/Test Line=995");
				if (!t0) {
					PHALCON_ALLOC_ZVAL(t0);
				} else {
					if (Z_REFCOUNT_P(t0) > 1) {
						PHALCON_SEPARATE(t0);
					} else {
						FREE_ZVAL(t0);
						PHALCON_ALLOC_ZVAL(t0);
					}
				}
				phalcon_read_property_zval(t0, v1, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v4, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(t0, Z_STRVAL_P(v5), Z_STRLEN_P(v5), copy TSRMLS_CC);
				}
			END_FOREACH(ac1, fes39, fee39, ah1, hp1);
		} else {
			phalcon_step_over("Phalcon_Internal_Test::p30 (Block) File=/Internal/Test Line=997");
			phalcon_step_over("Phalcon_Internal_Test::p30 (Assignment) File=/Internal/Test Line=998");
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(v1, Z_STRVAL_P(v3), Z_STRLEN_P(v3), copy TSRMLS_CC);
			}
		}
	END_FOREACH(ac0, fes38, fee38, ah0, hp0);
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
	phalcon_step_over("Phalcon_Internal_Test::p30 (Method) File=/Internal/Test Line=1004");
}

PHP_METHOD(Phalcon_Internal_Test, p31){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "p31", 0);
	phalcon_step_over("Phalcon_Internal_Test::p31 (Assignment) File=/Internal/Test Line=1005");
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	PHALCON_CPY_WRT_PARAM(v0, i0);
	phalcon_debug_assign("$p", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::p31 (Assignment) File=/Internal/Test Line=1006");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, a0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(v0, "a", strlen("a"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Internal_Test::p31 (For) File=/Internal/Test Line=1007");
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_LONG(v1, 0);
	fs40:
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_ALLOC_ZVAL(r0);
	is_smaller_function(r0, v1, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe40;
	}
	phalcon_step_over("Phalcon_Internal_Test::p31 (Block) File=/Internal/Test Line=1007");
	phalcon_step_over("Phalcon_Internal_Test::p31 (Assignment) File=/Internal/Test Line=1008");
	if (!i1) {
		PHALCON_ALLOC_ZVAL(i1);
	} else {
		if (Z_REFCOUNT_P(i1) > 1) {
			PHALCON_SEPARATE(i1);
		} else {
			FREE_ZVAL(i1);
			PHALCON_ALLOC_ZVAL(i1);
		}
	}
	object_init(i1);
	PHALCON_CPY_WRT(v2, i1);
	phalcon_debug_assign("$f", i1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::p31 (Assignment) File=/Internal/Test Line=1009");
	if (!t1) {
		PHALCON_ALLOC_ZVAL(t1);
	} else {
		if (Z_REFCOUNT_P(t1) > 1) {
			PHALCON_SEPARATE(t1);
		} else {
			FREE_ZVAL(t1);
			PHALCON_ALLOC_ZVAL(t1);
		}
	}
	phalcon_read_property(t1, v0, "a", sizeof("a")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v2, 1, 0);
		Z_SET_REFCOUNT_P(copy, 1);
		PHALCON_SEPARATE(t1);
		phalcon_array_append(t1, copy TSRMLS_CC);
	}
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(v0, "a", strlen("a"), copy TSRMLS_CC);
	}
	PHALCON_SEPARATE(v1);
	increment_function(v1);
	phalcon_debug_vdump("PostIncrementing $i", v1);
	goto fs40;
	fe40:
	r0 = NULL;
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
	phalcon_step_over("Phalcon_Internal_Test::p31 (Method) File=/Internal/Test Line=1017");
}

PHP_METHOD(Phalcon_Internal_Test, sp1){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sp1", 0);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sp1 (Method) File=/Internal/Test Line=1021");
}

PHP_METHOD(Phalcon_Internal_Test, sp2){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sp2", 0);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp2", sizeof("_sp2")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sp2 (Method) File=/Internal/Test Line=1025");
}

PHP_METHOD(Phalcon_Internal_Test, sp3){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sp3", 0);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp3", sizeof("_sp3")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sp3 (Method) File=/Internal/Test Line=1029");
}

PHP_METHOD(Phalcon_Internal_Test, sp4){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sp4", 0);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp4", sizeof("_sp4")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sp4 (Method) File=/Internal/Test Line=1033");
}

PHP_METHOD(Phalcon_Internal_Test, sp5){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sp5", 0);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp5", sizeof("_sp5")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sp5 (Method) File=/Internal/Test Line=1037");
}

PHP_METHOD(Phalcon_Internal_Test, sp6){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sp6", 0);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp6", sizeof("_sp6")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sp6 (Method) File=/Internal/Test Line=1041");
}

PHP_METHOD(Phalcon_Internal_Test, sp7){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sp7", 0);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp7", sizeof("_sp7")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sp7 (Method) File=/Internal/Test Line=1045");
}

PHP_METHOD(Phalcon_Internal_Test, sp8){

	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "sp8", 0);
	phalcon_step_over("Phalcon_Internal_Test::sp8 (Assignment) File=/Internal/Test Line=1046");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "i can't handle anymore", 1);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, t0 TSRMLS_CC);
	t1 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sp8 (Method) File=/Internal/Test Line=1050");
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
	phalcon_step_over("Phalcon_Internal_Test::sp9 (Assignment) File=/Internal/Test Line=1051");
	PHALCON_ALLOC_ZVAL(r0);
	add_function(r0, v0, v1 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, r0 TSRMLS_CC);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sp9 (Method) File=/Internal/Test Line=1055");
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
	phalcon_step_over("Phalcon_Internal_Test::sp10 (Assignment) File=/Internal/Test Line=1056");
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, v0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sp10 (Assignment) File=/Internal/Test Line=1057");
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp2", sizeof("_sp2")-1, v1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sp10 (Assignment) File=/Internal/Test Line=1058");
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	t1 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp2", sizeof("_sp2")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	add_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	add_function(r1, r0, v2 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp3", sizeof("_sp3")-1, r1 TSRMLS_CC);
	t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp3", sizeof("_sp3")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t2);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sp10 (Method) File=/Internal/Test Line=1062");
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
	phalcon_step_over("Phalcon_Internal_Test::sp11 (Assignment) File=/Internal/Test Line=1063");
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, v0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sp11 (Assignment) File=/Internal/Test Line=1064");
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp2", sizeof("_sp2")-1, v1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::sp11 (Assignment) File=/Internal/Test Line=1065");
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	t1 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp2", sizeof("_sp2")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	add_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	add_function(r1, r0, v2 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp3", sizeof("_sp3")-1, r1 TSRMLS_CC);
	t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp3", sizeof("_sp3")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t2);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::sp11 (Method) File=/Internal/Test Line=1069");
}

PHP_METHOD(Phalcon_Internal_Test, cc1){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "cc1", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_class_entry, "C1", strlen("C1") TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::cc1 (Method) File=/Internal/Test Line=1073");
}

PHP_METHOD(Phalcon_Internal_Test, cc2){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "cc2", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_class_entry, "C2", strlen("C2") TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::cc2 (Method) File=/Internal/Test Line=1077");
}

PHP_METHOD(Phalcon_Internal_Test, cc3){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "cc3", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_class_entry, "C3", strlen("C3") TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::cc3 (Method) File=/Internal/Test Line=1081");
}

PHP_METHOD(Phalcon_Internal_Test, cc4){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "cc4", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_class_entry, "C4", strlen("C4") TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::cc4 (Method) File=/Internal/Test Line=1085");
}

PHP_METHOD(Phalcon_Internal_Test, cc5){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "cc5", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_class_entry, "C5", strlen("C5") TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::cc5 (Method) File=/Internal/Test Line=1089");
}

PHP_METHOD(Phalcon_Internal_Test, cc6){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "cc6", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_class_entry, "C6", strlen("C6") TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::cc6 (Method) File=/Internal/Test Line=1096");
}

PHP_METHOD(Phalcon_Internal_Test, is1){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is1", 0);
	phalcon_step_over("Phalcon_Internal_Test::is1 (Assignment) File=/Internal/Test Line=1097");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_BOOL(t0, 0);
	PHALCON_SEPARATE(a0);
	add_next_index_zval(a0, t0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is1 (If) File=/Internal/Test Line=1098");
	eval_int = phalcon_array_isset_long(v0, 0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is1 (Block) File=/Internal/Test Line=1098");
		phalcon_step_out_entry();
		RETURN_LONG(1);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is1 (Block) File=/Internal/Test Line=1100");
		phalcon_step_out_entry();
		RETURN_LONG(2);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is1 (Method) File=/Internal/Test Line=1105");
}

PHP_METHOD(Phalcon_Internal_Test, is2){

	zval *v0 = NULL;
	zval *i0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is2", 0);
	phalcon_step_over("Phalcon_Internal_Test::is2 (Assignment) File=/Internal/Test Line=1106");
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	PHALCON_CPY_WRT_PARAM(v0, i0);
	phalcon_debug_assign("$a", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is2 (Assignment) File=/Internal/Test Line=1107");
	phalcon_update_property_long(v0, "b", strlen("b"), 15 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is2 (If) File=/Internal/Test Line=1108");
	eval_int = phalcon_isset_property(v0, "b", strlen("b") TSRMLS_CC);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is2 (Block) File=/Internal/Test Line=1108");
		phalcon_step_out_entry();
		RETURN_LONG(1);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is2 (Block) File=/Internal/Test Line=1110");
		phalcon_step_out_entry();
		RETURN_LONG(2);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is2 (Method) File=/Internal/Test Line=1115");
}

PHP_METHOD(Phalcon_Internal_Test, is3){

	zval *v0 = NULL;
	zval *a0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is3", 0);
	phalcon_step_over("Phalcon_Internal_Test::is3 (Assignment) File=/Internal/Test Line=1116");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is3 (If) File=/Internal/Test Line=1117");
	eval_int = phalcon_array_isset_long(v0, 0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is3 (Block) File=/Internal/Test Line=1117");
		phalcon_step_out_entry();
		RETURN_LONG(1);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is3 (Block) File=/Internal/Test Line=1119");
		phalcon_step_out_entry();
		RETURN_LONG(2);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is3 (Method) File=/Internal/Test Line=1124");
}

PHP_METHOD(Phalcon_Internal_Test, is4){

	zval *v0 = NULL;
	zval *i0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is4", 0);
	phalcon_step_over("Phalcon_Internal_Test::is4 (Assignment) File=/Internal/Test Line=1125");
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	PHALCON_CPY_WRT_PARAM(v0, i0);
	phalcon_debug_assign("$a", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is4 (Assignment) File=/Internal/Test Line=1126");
	phalcon_update_property_long(v0, "c", strlen("c"), 10 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is4 (If) File=/Internal/Test Line=1127");
	eval_int = phalcon_isset_property(v0, "b", strlen("b") TSRMLS_CC);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is4 (Block) File=/Internal/Test Line=1127");
		phalcon_step_out_entry();
		RETURN_LONG(1);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is4 (Block) File=/Internal/Test Line=1129");
		phalcon_step_out_entry();
		RETURN_LONG(2);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is4 (Method) File=/Internal/Test Line=1134");
}

PHP_METHOD(Phalcon_Internal_Test, is5){

	zval *v0 = NULL;
	zval *a0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is5", 0);
	phalcon_step_over("Phalcon_Internal_Test::is5 (Assignment) File=/Internal/Test Line=1135");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is5 (If) File=/Internal/Test Line=1136");
	eval_int = phalcon_array_isset_long(v0, 0);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is5 (Block) File=/Internal/Test Line=1136");
		phalcon_step_out_entry();
		RETURN_LONG(1);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is5 (Block) File=/Internal/Test Line=1138");
		phalcon_step_out_entry();
		RETURN_LONG(2);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is5 (Method) File=/Internal/Test Line=1143");
}

PHP_METHOD(Phalcon_Internal_Test, is6){

	zval *v0 = NULL;
	zval *i0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is6", 0);
	phalcon_step_over("Phalcon_Internal_Test::is6 (Assignment) File=/Internal/Test Line=1144");
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	PHALCON_CPY_WRT_PARAM(v0, i0);
	phalcon_debug_assign("$a", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is6 (Assignment) File=/Internal/Test Line=1145");
	phalcon_update_property_long(v0, "c", strlen("c"), 10 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is6 (If) File=/Internal/Test Line=1146");
	eval_int = phalcon_isset_property(v0, "b", strlen("b") TSRMLS_CC);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is6 (Block) File=/Internal/Test Line=1146");
		phalcon_step_out_entry();
		RETURN_LONG(1);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is6 (Block) File=/Internal/Test Line=1148");
		phalcon_step_out_entry();
		RETURN_LONG(2);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is6 (Method) File=/Internal/Test Line=1153");
}

PHP_METHOD(Phalcon_Internal_Test, is7){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is7", 0);
	phalcon_step_over("Phalcon_Internal_Test::is7 (Assignment) File=/Internal/Test Line=1154");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_string(a0, "hello", 1);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is7 (Assignment) File=/Internal/Test Line=1155");
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_LONG(v1, 0);
	phalcon_step_over("Phalcon_Internal_Test::is7 (If) File=/Internal/Test Line=1156");
	eval_int = phalcon_array_isset(v0, v1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is7 (Block) File=/Internal/Test Line=1156");
		phalcon_step_out_entry();
		RETURN_LONG(1);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is7 (Block) File=/Internal/Test Line=1158");
		phalcon_step_out_entry();
		RETURN_LONG(2);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is7 (Method) File=/Internal/Test Line=1163");
}

PHP_METHOD(Phalcon_Internal_Test, is8){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is8", 0);
	phalcon_step_over("Phalcon_Internal_Test::is8 (Assignment) File=/Internal/Test Line=1164");
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	PHALCON_CPY_WRT_PARAM(v0, i0);
	phalcon_debug_assign("$config", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is8 (Assignment) File=/Internal/Test Line=1165");
	phalcon_update_property_string(v0, "host", strlen("host"), "192.168.0.20" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is8 (Assignment) File=/Internal/Test Line=1166");
	phalcon_update_property_string(v0, "username", strlen("username"), "support" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is8 (Assignment) File=/Internal/Test Line=1167");
	phalcon_update_property_string(v0, "password", strlen("password"), "H45pov682v" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is8 (Assignment) File=/Internal/Test Line=1168");
	phalcon_update_property_string(v0, "name", strlen("name"), "demo" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is8 (If) File=/Internal/Test Line=1169");
	eval_int = phalcon_isset_property(v0, "host", strlen("host") TSRMLS_CC);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is8 (Block) File=/Internal/Test Line=1169");
		PHALCON_ALLOC_ZVAL(t0);
		phalcon_read_property(t0, v0, "host", sizeof("host")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(t0);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is8 (Block) File=/Internal/Test Line=1171");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is8 (Method) File=/Internal/Test Line=1176");
}

PHP_METHOD(Phalcon_Internal_Test, is9){

	zval *v0 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is9", 0);
	phalcon_step_over("Phalcon_Internal_Test::is9 (Assignment) File=/Internal/Test Line=1177");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_assoc_string(a1, "1", "hello", 1);
	PHALCON_SEPARATE(a0);
	add_next_index_zval(a0, a1);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_BOOL(t0, 0);
	PHALCON_SEPARATE(a0);
	add_next_index_zval(a0, t0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is9 (If) File=/Internal/Test Line=1181");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_long(r0, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset_long(r0, 0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is9 (Block) File=/Internal/Test Line=1181");
		phalcon_step_out_entry();
		RETURN_LONG(1);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is9 (Block) File=/Internal/Test Line=1183");
		phalcon_step_out_entry();
		RETURN_LONG(2);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is9 (Method) File=/Internal/Test Line=1188");
}

PHP_METHOD(Phalcon_Internal_Test, is10){

	zval *v0 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is10", 0);
	phalcon_step_over("Phalcon_Internal_Test::is10 (Assignment) File=/Internal/Test Line=1189");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_assoc_string(a1, "1", "hello", 1);
	PHALCON_SEPARATE(a0);
	add_next_index_zval(a0, a1);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_BOOL(t0, 0);
	PHALCON_SEPARATE(a0);
	add_next_index_zval(a0, t0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::is10 (If) File=/Internal/Test Line=1193");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_long(r0, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset_long(r0, 1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is10 (Block) File=/Internal/Test Line=1193");
		phalcon_step_out_entry();
		RETURN_LONG(1);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is10 (Block) File=/Internal/Test Line=1195");
		phalcon_step_out_entry();
		RETURN_LONG(2);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is10 (Method) File=/Internal/Test Line=1200");
}

PHP_METHOD(Phalcon_Internal_Test, is11){

	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is11", 0);
	phalcon_step_over("Phalcon_Internal_Test::is11 (Assignment) File=/Internal/Test Line=1201");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_assoc_string(a1, "1", "hello", 1);
	PHALCON_SEPARATE(a0);
	add_next_index_zval(a0, a1);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_BOOL(t0, 0);
	PHALCON_SEPARATE(a0);
	add_next_index_zval(a0, t0);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, a0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Internal_Test::is11 (If) File=/Internal/Test Line=1205");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_long(r0, t1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset_long(r0, 1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is11 (Block) File=/Internal/Test Line=1205");
		phalcon_step_out_entry();
		RETURN_LONG(1);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is11 (Block) File=/Internal/Test Line=1207");
		phalcon_step_out_entry();
		RETURN_LONG(2);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is11 (Method) File=/Internal/Test Line=1212");
}

PHP_METHOD(Phalcon_Internal_Test, is12){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "is12", 0);
	phalcon_step_over("Phalcon_Internal_Test::is12 (Assignment) File=/Internal/Test Line=1213");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_STRING(v0, "hello", 0);
	phalcon_step_over("Phalcon_Internal_Test::is12 (Assignment) File=/Internal/Test Line=1214");
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_STRING(v1, "lol", 0);
	phalcon_step_over("Phalcon_Internal_Test::is12 (Assignment) File=/Internal/Test Line=1215");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, a0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Internal_Test::is12 (If) File=/Internal/Test Line=1216");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch(r0, t0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(r0, v1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::is12 (Block) File=/Internal/Test Line=1216");
		phalcon_step_out_entry();
		RETURN_LONG(1);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::is12 (Block) File=/Internal/Test Line=1218");
		phalcon_step_out_entry();
		RETURN_LONG(2);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::is12 (Method) File=/Internal/Test Line=1226");
}

PHP_METHOD(Phalcon_Internal_Test, un1){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "un1", 0);
	phalcon_step_over("Phalcon_Internal_Test::un1 (Assignment) File=/Internal/Test Line=1227");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_BOOL(t0, 0);
	PHALCON_SEPARATE(a0);
	add_next_index_zval(a0, t0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::un1 (Unset) File=/Internal/Test Line=1228");
	PHALCON_SEPARATE_PARAM(v0);
	phalcon_array_unset_long(v0, 0);
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
	phalcon_step_over("Phalcon_Internal_Test::un1 (Method) File=/Internal/Test Line=1232");
}

PHP_METHOD(Phalcon_Internal_Test, un2){

	zval *v0 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "un2", 0);
	phalcon_step_over("Phalcon_Internal_Test::un2 (Assignment) File=/Internal/Test Line=1233");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	add_next_index_long(a1, 0);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	PHALCON_SEPARATE(a0);
	add_assoc_zval(a0, "lost", a1);
	add_next_index_string(a0, "hello", 1);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::un2 (Unset) File=/Internal/Test Line=1237");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_string(r0, v0, "lost", strlen("lost"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE(r0);
	phalcon_array_unset_long(r0, 1);
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
	phalcon_step_over("Phalcon_Internal_Test::un2 (Method) File=/Internal/Test Line=1241");
}

PHP_METHOD(Phalcon_Internal_Test, un3){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "un3", 0);
	phalcon_step_over("Phalcon_Internal_Test::un3 (Assignment) File=/Internal/Test Line=1242");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_long(a0, 0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$b", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::un3 (Assignment) File=/Internal/Test Line=1243");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		PHALCON_SEPARATE(a1);
		add_next_index_zval(a1, copy);
	}
	add_next_index_string(a1, "hello", 1);
	PHALCON_CPY_WRT_PARAM(v1, a1);
	phalcon_debug_assign("$a", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::un3 (Unset) File=/Internal/Test Line=1247");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_long(r0, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE(r0);
	phalcon_array_unset_long(r0, 1);
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
	phalcon_step_over("Phalcon_Internal_Test::un3 (Method) File=/Internal/Test Line=1254");
}

PHP_METHOD(Phalcon_Internal_Test, iof1){

	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "iof1", 0);
	phalcon_step_over("Phalcon_Internal_Test::iof1 (If) File=/Internal/Test Line=1255");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_instance_of(r0, this_ptr, phalcon_internal_test_class_entry TSRMLS_CC);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Internal_Test::iof1 (Block) File=/Internal/Test Line=1255");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Internal_Test::iof1 (Block) File=/Internal/Test Line=1257");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::iof1 (Method) File=/Internal/Test Line=1262");
}

PHP_METHOD(Phalcon_Internal_Test, iof2){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;
	zend_class_entry *ce0;

	phalcon_step_into_entry("Phalcon_Internal_Test", "iof2", 0);
	phalcon_step_over("Phalcon_Internal_Test::iof2 (Assignment) File=/Internal/Test Line=1263");
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	PHALCON_CPY_WRT_PARAM(v0, i0);
	phalcon_debug_assign("$a", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::iof2 (If) File=/Internal/Test Line=1264");
		ce0 = zend_fetch_class("stdclass", strlen("stdclass"), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_instance_of(r0, v0, ce0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Internal_Test::iof2 (Block) File=/Internal/Test Line=1264");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Internal_Test::iof2 (Block) File=/Internal/Test Line=1266");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::iof2 (Method) File=/Internal/Test Line=1271");
}

PHP_METHOD(Phalcon_Internal_Test, iof3){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_Test", "iof3", 0);
	phalcon_step_over("Phalcon_Internal_Test::iof3 (Assignment) File=/Internal/Test Line=1272");
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_internal_testparent_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	PHALCON_CPY_WRT_PARAM(v0, i0);
	phalcon_debug_assign("$a", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::iof3 (If) File=/Internal/Test Line=1273");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_instance_of(r0, v0, phalcon_internal_testparent_class_entry TSRMLS_CC);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Internal_Test::iof3 (Block) File=/Internal/Test Line=1273");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Internal_Test::iof3 (Block) File=/Internal/Test Line=1275");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::iof3 (Method) File=/Internal/Test Line=1283");
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
	phalcon_step_over("Phalcon_Internal_Test::t1 (Assignment) File=/Internal/Test Line=1284");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 17);
	phalcon_step_over("Phalcon_Internal_Test::t1 (Assignment) File=/Internal/Test Line=1285");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 100);
	PHALCON_SEPARATE_PARAM(v1);
	phalcon_array_update_long(v1, 0, t0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::t1 (Method) File=/Internal/Test Line=1288");
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
	phalcon_step_over("Phalcon_Internal_Test::t2 (Assignment) File=/Internal/Test Line=1289");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_STRING(v0, "", 0);
	phalcon_step_over("Phalcon_Internal_Test::t2 (Assignment) File=/Internal/Test Line=1290");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	add_next_index_long(a0, 4);
	PHALCON_CPY_WRT_PARAM(v1, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t2 (Foreach) File=/Internal/Test Line=1291");
	FOREACH_KV(v1, ac0, fes41, fee41, ah0, hp0, v3, v2)
		phalcon_step_over("Phalcon_Internal_Test::t2 (Block) File=/Internal/Test Line=1291");
		phalcon_step_over("Phalcon_Internal_Test::t2 (MethodCall) File=/Internal/Test Line=1292");
		phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "t1" TSRMLS_CC);
		Z_ADDREF_P(v3);
		p0[0] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		Z_ADDREF_P(v1);
		p0[1] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "t1", 2, p0, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
		phalcon_step_over("Phalcon_Internal_Test::t2 (AssignOp) File=/Internal/Test Line=1293");
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
		phalcon_array_fetch_long(r0, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!r1) {
			PHALCON_ALLOC_ZVAL(r1);
		} else {
			if (Z_REFCOUNT_P(r1) > 1) {
				PHALCON_SEPARATE(r1);
			} else {
				FREE_ZVAL(r1);
				PHALCON_ALLOC_ZVAL(r1);
			}
		}
		concat_function(r1, v3, r0 TSRMLS_CC);
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
		concat_function(r2, v0, r1 TSRMLS_CC);
		PHALCON_CPY_WRT_PARAM(v0, r2);
		phalcon_debug_assign("$m", r2 TSRMLS_CC);
	END_FOREACH(ac0, fes41, fee41, ah0, hp0);
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
	phalcon_step_over("Phalcon_Internal_Test::t2 (Method) File=/Internal/Test Line=1298");
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
	phalcon_step_over("Phalcon_Internal_Test::t3 (If) File=/Internal/Test Line=1299");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 5);
	PHALCON_ALLOC_ZVAL(r0);
	mod_function(r0, v1, t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_ALLOC_ZVAL(r1);
	is_equal_function(r1, r0, t1 TSRMLS_CC);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Internal_Test::t3 (Block) File=/Internal/Test Line=1299");
		t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(t2);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::t3 (Block) File=/Internal/Test Line=1301");
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
	phalcon_step_over("Phalcon_Internal_Test::t3 (Method) File=/Internal/Test Line=1306");
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
	phalcon_step_over("Phalcon_Internal_Test::t4 (Assignment) File=/Internal/Test Line=1307");
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_LONG(v1, 25);
	phalcon_step_over("Phalcon_Internal_Test::t4 (If) File=/Internal/Test Line=1308");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 5);
	PHALCON_ALLOC_ZVAL(r0);
	is_equal_function(r0, v0, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Internal_Test::t4 (Block) File=/Internal/Test Line=1308");
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(t1);
	} else {
		phalcon_step_over("Phalcon_Internal_Test::t4 (Block) File=/Internal/Test Line=1310");
		PHALCON_ALLOC_ZVAL(r1);
		p0[0] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r1, "sqrt", 1, p0);
		phalcon_debug_vdump("sqrt > ", r1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_Test::t4 (Method) File=/Internal/Test Line=1315");
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
	phalcon_step_over("Phalcon_Internal_Test::t5 (Assignment) File=/Internal/Test Line=1316");
	phalcon_update_property_long(this_ptr, "_p0", strlen("_p0"), 0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t5 (Assignment) File=/Internal/Test Line=1317");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v3, a0);
	phalcon_debug_assign("$node", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t5 (While) File=/Internal/Test Line=1318");
	ws42:
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_BOOL(t0, 1);
	if (!zend_is_true(t0)) {
		goto we42;
	}
	phalcon_step_over("Phalcon_Internal_Test::t5 (Block) File=/Internal/Test Line=1318");
	phalcon_step_over("Phalcon_Internal_Test::t5 (Assignment) File=/Internal/Test Line=1319");
	if (!r0) {
		PHALCON_ALLOC_ZVAL(r0);
	} else {
		if (Z_REFCOUNT_P(r0) > 1){ 
			PHALCON_SEPARATE(r0);
		}
	}
	mul_function(r0, v0, v1 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t5 (AssignOp) File=/Internal/Test Line=1320");
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
	if (!r1) {
		PHALCON_ALLOC_ZVAL(r1);
	} else {
		if (Z_REFCOUNT_P(r1) > 1){ 
			PHALCON_SEPARATE(r1);
		}
	}
	add_function(r1, v0, t1 TSRMLS_CC);
	PHALCON_CPY_WRT_PARAM(v0, r1);
	phalcon_debug_assign("$a", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t5 (If) File=/Internal/Test Line=1321");
	if (!t2) {
		PHALCON_ALLOC_ZVAL(t2);
	} else {
		if (Z_REFCOUNT_P(t2) > 1) {
			PHALCON_SEPARATE(t2);
		} else {
			FREE_ZVAL(t2);
			PHALCON_ALLOC_ZVAL(t2);
		}
	}
	phalcon_read_property(t2, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	if (!r2) {
		PHALCON_ALLOC_ZVAL(r2);
	} else {
		if (Z_REFCOUNT_P(r2) > 1){ 
			PHALCON_SEPARATE(r2);
		}
	}
	mod_function(r2, t2, t3 TSRMLS_CC);
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
	if (!r3) {
		PHALCON_ALLOC_ZVAL(r3);
	} else {
		if (Z_REFCOUNT_P(r3) > 1){ 
			PHALCON_SEPARATE(r3);
		}
	}
	is_equal_function(r3, r2, t4 TSRMLS_CC);
	if (zend_is_true(r3)) {
		phalcon_step_over("Phalcon_Internal_Test::t5 (Block) File=/Internal/Test Line=1321");
		phalcon_step_over("Phalcon_Internal_Test::t5 (Assignment) File=/Internal/Test Line=1322");
		if (!r4) {
			PHALCON_ALLOC_ZVAL(r4);
		} else {
			if (Z_REFCOUNT_P(r4) > 1) {
				PHALCON_SEPARATE(r4);
			} else {
				FREE_ZVAL(r4);
				PHALCON_ALLOC_ZVAL(r4);
			}
		}
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
				PHALCON_SEPARATE(r5);
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
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r4, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			PHALCON_SEPARATE(v3);
			phalcon_array_append(v3, copy TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_Internal_Test::t5 (Block) File=/Internal/Test Line=1323");
		phalcon_step_over("Phalcon_Internal_Test::t5 (Assignment) File=/Internal/Test Line=1324");
		if (!r6) {
			PHALCON_ALLOC_ZVAL(r6);
		} else {
			if (Z_REFCOUNT_P(r6) > 1) {
				PHALCON_SEPARATE(r6);
			} else {
				FREE_ZVAL(r6);
				PHALCON_ALLOC_ZVAL(r6);
			}
		}
		phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "t3" TSRMLS_CC);
		Z_ADDREF_P(v0);
		p1[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		Z_ADDREF_P(v1);
		p1[1] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r6, this_ptr, "t3", 2, p1, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r6 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r6, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			PHALCON_SEPARATE(v3);
			phalcon_array_append(v3, copy TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Internal_Test::t5 (Assignment) File=/Internal/Test Line=1326");
	if (!t7) {
		PHALCON_ALLOC_ZVAL(t7);
	} else {
		if (Z_REFCOUNT_P(t7) > 1) {
			PHALCON_SEPARATE(t7);
		} else {
			FREE_ZVAL(t7);
			PHALCON_ALLOC_ZVAL(t7);
		}
	}
	phalcon_read_property(t7, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
			PHALCON_SEPARATE(r7);
		}
	}
	mul_function(r7, t7, t8 TSRMLS_CC);
	PHALCON_CPY_WRT_PARAM(v1, r7);
	phalcon_debug_assign("$b", r7 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t5 (PostIncDecOp) File=/Internal/Test Line=1327");
	if (!t9) {
		PHALCON_ALLOC_ZVAL(t9);
	} else {
		if (Z_REFCOUNT_P(t9) > 1) {
			PHALCON_SEPARATE(t9);
		} else {
			FREE_ZVAL(t9);
			PHALCON_ALLOC_ZVAL(t9);
		}
	}
	phalcon_read_property(t9, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE(t9);
	increment_function(t9);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t9, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p0", strlen("_p0"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Internal_Test::t5 (If) File=/Internal/Test Line=1328");
	if (!t10) {
		PHALCON_ALLOC_ZVAL(t10);
	} else {
		if (Z_REFCOUNT_P(t10) > 1) {
			PHALCON_SEPARATE(t10);
		} else {
			FREE_ZVAL(t10);
			PHALCON_ALLOC_ZVAL(t10);
		}
	}
	phalcon_read_property(t10, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	if (!r8) {
		PHALCON_ALLOC_ZVAL(r8);
	} else {
		if (Z_REFCOUNT_P(r8) > 1) {
			SEPARATE_ZVAL(&r8);
		} else {
			if (Z_TYPE_P(r8) != IS_BOOL) {
				FREE_ZVAL(r8);
				PHALCON_ALLOC_ZVAL(r8);
			}
		}
	}
	is_smaller_function(r8, t11, t10 TSRMLS_CC);
	if (zend_is_true(r8)) {
		phalcon_step_over("Phalcon_Internal_Test::t5 (Block) File=/Internal/Test Line=1328");
		phalcon_step_over("Phalcon_Internal_Test::t5 (Break) File=/Internal/Test Line=1329");
		goto we42;
	}
	goto ws42;
	we42:
	t0 = NULL;
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
	phalcon_step_over("Phalcon_Internal_Test::t5 (Method) File=/Internal/Test Line=1335");
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
	phalcon_step_over("Phalcon_Internal_Test::t6 (Assignment) File=/Internal/Test Line=1336");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_long(a0, 0);
	add_next_index_long(a0, 25);
	PHALCON_CPY_WRT(v3, a0);
	phalcon_debug_assign("$e", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t6 (Assignment) File=/Internal/Test Line=1337");
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_internal_testparent_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t6 (For) File=/Internal/Test Line=1338");
	PHALCON_ALLOC_ZVAL(v4);
	ZVAL_LONG(v4, 0);
	fs43:
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_ALLOC_ZVAL(r0);
	is_smaller_function(r0, v4, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe43;
	}
	phalcon_step_over("Phalcon_Internal_Test::t6 (Block) File=/Internal/Test Line=1338");
	phalcon_step_over("Phalcon_Internal_Test::t6 (If) File=/Internal/Test Line=1339");
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
	if (!r1) {
		PHALCON_ALLOC_ZVAL(r1);
	} else {
		if (Z_REFCOUNT_P(r1) > 1) {
			SEPARATE_ZVAL(&r1);
		} else {
			if (Z_TYPE_P(r1) != IS_BOOL) {
				FREE_ZVAL(r1);
				PHALCON_ALLOC_ZVAL(r1);
			}
		}
	}
	is_smaller_function(r1, v4, t1 TSRMLS_CC);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Internal_Test::t6 (Block) File=/Internal/Test Line=1339");
		phalcon_step_over("Phalcon_Internal_Test::t6 (AssignOp) File=/Internal/Test Line=1340");
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
		phalcon_array_fetch_long(r2, v3, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!r3) {
			PHALCON_ALLOC_ZVAL(r3);
		} else {
			if (Z_REFCOUNT_P(r3) > 1) {
				PHALCON_SEPARATE(r3);
			} else {
				FREE_ZVAL(r3);
				PHALCON_ALLOC_ZVAL(r3);
			}
		}
		t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(t2);
		p1[0] = t2;
		phalcon_debug_param(t2 TSRMLS_CC);
		Z_ADDREF_P(v4);
		p1[1] = v4;
		phalcon_debug_param(v4 TSRMLS_CC);
		Z_ADDREF_P(v0);
		p1[2] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		Z_ADDREF_P(v1);
		p1[3] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_STATIC_PARAMS(r3, "phalcon_internal_testparent", "smp6", 4, p1);
		phalcon_debug_vdump("StaticReturn > ", r3 TSRMLS_CC);
		if (!r4) {
			PHALCON_ALLOC_ZVAL(r4);
		} else {
			if (Z_REFCOUNT_P(r4) > 1){ 
				PHALCON_SEPARATE(r4);
			}
		}
		add_function(r4, r2, r3 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r4, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			PHALCON_SEPARATE(v3);
			phalcon_array_update_long(v3, 1, copy TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_Internal_Test::t6 (Block) File=/Internal/Test Line=1341");
		phalcon_step_over("Phalcon_Internal_Test::t6 (AssignOp) File=/Internal/Test Line=1342");
		if (!r5) {
			PHALCON_ALLOC_ZVAL(r5);
		} else {
			if (Z_REFCOUNT_P(r5) > 1) {
				PHALCON_SEPARATE(r5);
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
				PHALCON_SEPARATE(r6);
			} else {
				FREE_ZVAL(r6);
				PHALCON_ALLOC_ZVAL(r6);
			}
		}
		t3 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(t3);
		p2[0] = t3;
		phalcon_debug_param(t3 TSRMLS_CC);
		if (!r7) {
			PHALCON_ALLOC_ZVAL(r7);
		} else {
			if (Z_REFCOUNT_P(r7) > 1) {
				PHALCON_SEPARATE(r7);
			} else {
				FREE_ZVAL(r7);
				PHALCON_ALLOC_ZVAL(r7);
			}
		}
		phalcon_array_fetch_long(r7, v3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_SEPARATE(r7);
		if (!t4) {
			PHALCON_ALLOC_ZVAL(t4);
		} else {
			if (Z_REFCOUNT_P(t4) > 1) {
				PHALCON_SEPARATE(t4);
			} else {
				FREE_ZVAL(t4);
				PHALCON_ALLOC_ZVAL(t4);
			}
		}
		ZVAL_ZVAL(t4, r7, 1, 0);
		increment_function(r7);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r7, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			PHALCON_SEPARATE(v3);
			phalcon_array_update_long(v3, 0, copy TSRMLS_CC);
		}
		Z_ADDREF_P(t4);
		p2[1] = t4;
		phalcon_debug_param(t4 TSRMLS_CC);
		Z_ADDREF_P(v1);
		p2[2] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		Z_ADDREF_P(v2);
		p2[3] = v2;
		phalcon_debug_param(v2 TSRMLS_CC);
		PHALCON_CALL_SELF_PARAMS(r6, this_ptr, "smp6", 4, p2);
		phalcon_debug_vdump("SelfStaticReturn > ", r6 TSRMLS_CC);
		if (!r8) {
			PHALCON_ALLOC_ZVAL(r8);
		} else {
			if (Z_REFCOUNT_P(r8) > 1){ 
				PHALCON_SEPARATE(r8);
			}
		}
		add_function(r8, r5, r6 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r8, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			PHALCON_SEPARATE(v3);
			phalcon_array_update_long(v3, 1, copy TSRMLS_CC);
		}
	}
	PHALCON_SEPARATE(v4);
	increment_function(v4);
	phalcon_debug_vdump("PostIncrementing $i", v4);
	goto fs43;
	fe43:
	r0 = NULL;
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
	phalcon_step_over("Phalcon_Internal_Test::t6 (Method) File=/Internal/Test Line=1348");
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
	phalcon_step_over("Phalcon_Internal_Test::t7 (Assignment) File=/Internal/Test Line=1349");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_long(a0, 0);
	add_next_index_long(a0, 25);
	PHALCON_CPY_WRT(v2, a0);
	phalcon_debug_assign("$e", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t7 (Assignment) File=/Internal/Test Line=1350");
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_internal_testparent_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t7 (For) File=/Internal/Test Line=1351");
	PHALCON_ALLOC_ZVAL(v3);
	ZVAL_LONG(v3, 0);
	fs44:
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_ALLOC_ZVAL(r0);
	is_smaller_function(r0, v3, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe44;
	}
	phalcon_step_over("Phalcon_Internal_Test::t7 (Block) File=/Internal/Test Line=1351");
	phalcon_step_over("Phalcon_Internal_Test::t7 (For) File=/Internal/Test Line=1352");
	PHALCON_CPY_WRT(v4, v0);
	phalcon_debug_assign("$j", v0 TSRMLS_CC);
	fs45:
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
	if (!r1) {
		PHALCON_ALLOC_ZVAL(r1);
	} else {
		if (Z_REFCOUNT_P(r1) > 1) {
			SEPARATE_ZVAL(&r1);
		} else {
			if (Z_TYPE_P(r1) != IS_BOOL) {
				FREE_ZVAL(r1);
				PHALCON_ALLOC_ZVAL(r1);
			}
		}
	}
	is_smaller_function(r1, t1, v4 TSRMLS_CC);
	if (!zend_is_true(r1)) {
		goto fe45;
	}
	phalcon_step_over("Phalcon_Internal_Test::t7 (Block) File=/Internal/Test Line=1352");
	phalcon_step_over("Phalcon_Internal_Test::t7 (If) File=/Internal/Test Line=1353");
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
	if (!r2) {
		PHALCON_ALLOC_ZVAL(r2);
	} else {
		if (Z_REFCOUNT_P(r2) > 1) {
			SEPARATE_ZVAL(&r2);
		} else {
			if (Z_TYPE_P(r2) != IS_BOOL) {
				FREE_ZVAL(r2);
				PHALCON_ALLOC_ZVAL(r2);
			}
		}
	}
	is_smaller_function(r2, v3, t2 TSRMLS_CC);
	if (zend_is_true(r2)) {
		phalcon_step_over("Phalcon_Internal_Test::t7 (Block) File=/Internal/Test Line=1353");
		phalcon_step_over("Phalcon_Internal_Test::t7 (AssignOp) File=/Internal/Test Line=1354");
		if (!r3) {
			PHALCON_ALLOC_ZVAL(r3);
		} else {
			if (Z_REFCOUNT_P(r3) > 1) {
				PHALCON_SEPARATE(r3);
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
				PHALCON_SEPARATE(r4);
			} else {
				FREE_ZVAL(r4);
				PHALCON_ALLOC_ZVAL(r4);
			}
		}
		t3 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(t3);
		p1[0] = t3;
		phalcon_debug_param(t3 TSRMLS_CC);
		Z_ADDREF_P(v3);
		p1[1] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		Z_ADDREF_P(v0);
		p1[2] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		Z_ADDREF_P(v1);
		p1[3] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_STATIC_PARAMS(r4, "phalcon_internal_testparent", "smp6", 4, p1);
		phalcon_debug_vdump("StaticReturn > ", r4 TSRMLS_CC);
		if (!r5) {
			PHALCON_ALLOC_ZVAL(r5);
		} else {
			if (Z_REFCOUNT_P(r5) > 1){ 
				PHALCON_SEPARATE(r5);
			}
		}
		add_function(r5, r3, r4 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r5, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			PHALCON_SEPARATE(v2);
			phalcon_array_update_long(v2, 1, copy TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_Internal_Test::t7 (Block) File=/Internal/Test Line=1355");
		phalcon_step_over("Phalcon_Internal_Test::t7 (If) File=/Internal/Test Line=1356");
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
		if (!r6) {
			PHALCON_ALLOC_ZVAL(r6);
		} else {
			if (Z_REFCOUNT_P(r6) > 1) {
				SEPARATE_ZVAL(&r6);
			} else {
				if (Z_TYPE_P(r6) != IS_BOOL) {
					FREE_ZVAL(r6);
					PHALCON_ALLOC_ZVAL(r6);
				}
			}
		}
		is_smaller_function(r6, t4, v4 TSRMLS_CC);
		if (zend_is_true(r6)) {
			phalcon_step_over("Phalcon_Internal_Test::t7 (Block) File=/Internal/Test Line=1356");
			phalcon_step_over("Phalcon_Internal_Test::t7 (AssignOp) File=/Internal/Test Line=1357");
			if (!r7) {
				PHALCON_ALLOC_ZVAL(r7);
			} else {
				if (Z_REFCOUNT_P(r7) > 1) {
					PHALCON_SEPARATE(r7);
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
					PHALCON_SEPARATE(r8);
				} else {
					FREE_ZVAL(r8);
					PHALCON_ALLOC_ZVAL(r8);
				}
			}
			t5 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			Z_ADDREF_P(t5);
			p2[0] = t5;
			phalcon_debug_param(t5 TSRMLS_CC);
			if (!r9) {
				PHALCON_ALLOC_ZVAL(r9);
			} else {
				if (Z_REFCOUNT_P(r9) > 1) {
					PHALCON_SEPARATE(r9);
				} else {
					FREE_ZVAL(r9);
					PHALCON_ALLOC_ZVAL(r9);
				}
			}
			phalcon_array_fetch_long(r9, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE(r9);
			decrement_function(r9);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r9, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				PHALCON_SEPARATE(v2);
				phalcon_array_update_long(v2, 0, copy TSRMLS_CC);
			}
			Z_ADDREF_P(r9);
			p2[1] = r9;
			phalcon_debug_param(r9 TSRMLS_CC);
			Z_ADDREF_P(v1);
			p2[2] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			Z_ADDREF_P(v4);
			p2[3] = v4;
			phalcon_debug_param(v4 TSRMLS_CC);
			PHALCON_CALL_SELF_PARAMS(r8, this_ptr, "smp6", 4, p2);
			phalcon_debug_vdump("SelfStaticReturn > ", r8 TSRMLS_CC);
			if (!r10) {
				PHALCON_ALLOC_ZVAL(r10);
			} else {
				if (Z_REFCOUNT_P(r10) > 1){ 
					PHALCON_SEPARATE(r10);
				}
			}
			add_function(r10, r7, r8 TSRMLS_CC);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r10, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				PHALCON_SEPARATE(v2);
				phalcon_array_update_long(v2, 1, copy TSRMLS_CC);
			}
		} else {
			phalcon_step_over("Phalcon_Internal_Test::t7 (Block) File=/Internal/Test Line=1358");
			phalcon_step_over("Phalcon_Internal_Test::t7 (AssignOp) File=/Internal/Test Line=1359");
			if (!r11) {
				PHALCON_ALLOC_ZVAL(r11);
			} else {
				if (Z_REFCOUNT_P(r11) > 1) {
					PHALCON_SEPARATE(r11);
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
					PHALCON_SEPARATE(r12);
				} else {
					FREE_ZVAL(r12);
					PHALCON_ALLOC_ZVAL(r12);
				}
			}
			t6 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			Z_ADDREF_P(t6);
			p3[0] = t6;
			phalcon_debug_param(t6 TSRMLS_CC);
			if (!r13) {
				PHALCON_ALLOC_ZVAL(r13);
			} else {
				if (Z_REFCOUNT_P(r13) > 1) {
					PHALCON_SEPARATE(r13);
				} else {
					FREE_ZVAL(r13);
					PHALCON_ALLOC_ZVAL(r13);
				}
			}
			phalcon_array_fetch_long(r13, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE(r13);
			if (!t7) {
				PHALCON_ALLOC_ZVAL(t7);
			} else {
				if (Z_REFCOUNT_P(t7) > 1) {
					PHALCON_SEPARATE(t7);
				} else {
					FREE_ZVAL(t7);
					PHALCON_ALLOC_ZVAL(t7);
				}
			}
			ZVAL_ZVAL(t7, r13, 1, 0);
			increment_function(r13);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r13, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				PHALCON_SEPARATE(v2);
				phalcon_array_update_long(v2, 0, copy TSRMLS_CC);
			}
			Z_ADDREF_P(t7);
			p3[1] = t7;
			phalcon_debug_param(t7 TSRMLS_CC);
			Z_ADDREF_P(v0);
			p3[2] = v0;
			phalcon_debug_param(v0 TSRMLS_CC);
			Z_ADDREF_P(v4);
			p3[3] = v4;
			phalcon_debug_param(v4 TSRMLS_CC);
			PHALCON_CALL_SELF_PARAMS(r12, this_ptr, "smp6", 4, p3);
			phalcon_debug_vdump("SelfStaticReturn > ", r12 TSRMLS_CC);
			if (!r14) {
				PHALCON_ALLOC_ZVAL(r14);
			} else {
				if (Z_REFCOUNT_P(r14) > 1){ 
					PHALCON_SEPARATE(r14);
				}
			}
			add_function(r14, r11, r12 TSRMLS_CC);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r14, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				PHALCON_SEPARATE(v2);
				phalcon_array_update_long(v2, 1, copy TSRMLS_CC);
			}
		}
	}
	PHALCON_SEPARATE(v4);
	decrement_function(v4);
	phalcon_debug_vdump("PostDecrementing $j", v4);
	goto fs45;
	fe45:
	r1 = NULL;
	PHALCON_SEPARATE(v3);
	increment_function(v3);
	phalcon_debug_vdump("PostIncrementing $i", v3);
	goto fs44;
	fe44:
	r0 = NULL;
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
	phalcon_step_over("Phalcon_Internal_Test::t7 (Method) File=/Internal/Test Line=1367");
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
	phalcon_step_over("Phalcon_Internal_Test::t8 (Method) File=/Internal/Test Line=1371");
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
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=/Internal/Test Line=1373");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_string(a0, "cedula", 1);
	add_next_index_string(a0, "nombre", 1);
	add_next_index_string(a0, "saldo", 1);
	add_next_index_string(a0, "estado", 1);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$notNull", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=/Internal/Test Line=1380");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, a1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p0", strlen("_p0"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=/Internal/Test Line=1382");
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	PHALCON_CPY_WRT_PARAM(v1, i0);
	phalcon_debug_assign("$record", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=/Internal/Test Line=1383");
	phalcon_update_property_string(v1, "cedula", strlen("cedula"), "hello" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=/Internal/Test Line=1384");
	zend_update_property_null(Z_OBJCE_P(v1), v1, "nombre", strlen("nombre") TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=/Internal/Test Line=1385");
	zend_update_property_null(Z_OBJCE_P(v1), v1, "saldo", strlen("saldo") TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=/Internal/Test Line=1386");
	zend_update_property_null(Z_OBJCE_P(v1), v1, "estado", strlen("estado") TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=/Internal/Test Line=1388");
	PHALCON_ALLOC_ZVAL(r0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "count", 1, p0);
	phalcon_debug_vdump("count > ", r0 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r0);
	phalcon_debug_assign("$numFields", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (For) File=/Internal/Test Line=1389");
	PHALCON_ALLOC_ZVAL(v3);
	ZVAL_LONG(v3, 0);
	fs46:
	PHALCON_ALLOC_ZVAL(r1);
	is_smaller_function(r1, v3, v2 TSRMLS_CC);
	if (!zend_is_true(r1)) {
		goto fe46;
	}
	phalcon_step_over("Phalcon_Internal_Test::t9 (Block) File=/Internal/Test Line=1389");
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=/Internal/Test Line=1391");
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
	phalcon_array_fetch(r2, v0, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v4, r2);
	phalcon_debug_assign("$field", r2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=/Internal/Test Line=1392");
	if (!t0) {
		PHALCON_ALLOC_ZVAL(t0);
	} else {
		if (Z_REFCOUNT_P(t0) > 1) {
			PHALCON_SEPARATE(t0);
		} else {
			FREE_ZVAL(t0);
			PHALCON_ALLOC_ZVAL(t0);
		}
	}
	phalcon_read_property_zval(t0, v1, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v5, t0);
	phalcon_debug_assign("$value", t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=/Internal/Test Line=1394");
	if (!r3) {
		PHALCON_ALLOC_ZVAL(r3);
	} else {
		if (Z_REFCOUNT_P(r3) > 1) {
			PHALCON_SEPARATE(r3);
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
	p1[2] = v4;
	phalcon_debug_param(v4 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r3, "str_replace", 3, p1);
	phalcon_debug_vdump("str_replace > ", r3 TSRMLS_CC);
	PHALCON_CPY_WRT(v6, r3);
	phalcon_debug_assign("$humanField", r3 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=/Internal/Test Line=1395");
	if (!i1) {
		PHALCON_ALLOC_ZVAL(i1);
	} else {
		if (Z_REFCOUNT_P(i1) > 1) {
			PHALCON_SEPARATE(i1);
		} else {
			FREE_ZVAL(i1);
			PHALCON_ALLOC_ZVAL(i1);
		}
	}
	object_init_ex(i1, phalcon_model_message_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
	if (!r4) {
		PHALCON_ALLOC_ZVAL(r4);
	} else {
		if (Z_REFCOUNT_P(r4) > 1) {
			PHALCON_SEPARATE(r4);
		} else {
			FREE_ZVAL(r4);
			PHALCON_ALLOC_ZVAL(r4);
		}
	}
	PHALCON_CONCAT_RIGHT(r4, v6, " is required");
	Z_ADDREF_P(r4);
	p2[0] = r4;
	phalcon_debug_param(r4 TSRMLS_CC);
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
	PHALCON_CPY_WRT(v7, i1);
	phalcon_debug_assign("$message", i1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t9 (Assignment) File=/Internal/Test Line=1396");
	if (!t1) {
		PHALCON_ALLOC_ZVAL(t1);
	} else {
		if (Z_REFCOUNT_P(t1) > 1) {
			PHALCON_SEPARATE(t1);
		} else {
			FREE_ZVAL(t1);
			PHALCON_ALLOC_ZVAL(t1);
		}
	}
	phalcon_read_property(t1, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v7, 1, 0);
		Z_SET_REFCOUNT_P(copy, 1);
		PHALCON_SEPARATE(t1);
		phalcon_array_append(t1, copy TSRMLS_CC);
	}
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_p0", strlen("_p0"), copy TSRMLS_CC);
	}
	PHALCON_SEPARATE(v3);
	increment_function(v3);
	phalcon_debug_vdump("PreIncrementing $i", v3);
	goto fs46;
	fe46:
	r1 = NULL;
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t2);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::t9 (Method) File=/Internal/Test Line=1404");
}

PHP_METHOD(Phalcon_Internal_Test, t10){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *i0 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Internal_Test", "t10", 0);
	phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=/Internal/Test Line=1406");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_string(a0, "cedula", 1);
	add_next_index_string(a0, "nombre", 1);
	add_next_index_string(a0, "saldo", 1);
	add_next_index_string(a0, "estado", 1);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$attributes", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=/Internal/Test Line=1413");
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_BOOL(t0, 1);
	PHALCON_SEPARATE(a1);
	add_assoc_zval(a1, "saldo", t0);
	PHALCON_CPY_WRT_PARAM(v1, a1);
	phalcon_debug_assign("$dataTypeNumeric", a1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=/Internal/Test Line=1417");
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v2, i0);
	phalcon_debug_assign("$record", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=/Internal/Test Line=1418");
	phalcon_update_property_string(v2, "cedula", strlen("cedula"), "hello" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=/Internal/Test Line=1419");
	phalcon_update_property_string(v2, "nombre", strlen("nombre"), "LOL" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=/Internal/Test Line=1420");
	phalcon_update_property_long(v2, "saldo", strlen("saldo"), 0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=/Internal/Test Line=1421");
	phalcon_update_property_string(v2, "estado", strlen("estado"), "X" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=/Internal/Test Line=1423");
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	PHALCON_CPY_WRT(v3, a2);
	phalcon_debug_assign("$values", a2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t10 (Foreach) File=/Internal/Test Line=1424");
	FOREACH_V(v0, ac0, fes47, fee47, ah0, hp0, v4)
		phalcon_step_over("Phalcon_Internal_Test::t10 (Block) File=/Internal/Test Line=1424");
		phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=/Internal/Test Line=1425");
		if (!t1) {
			PHALCON_ALLOC_ZVAL(t1);
		} else {
			if (Z_REFCOUNT_P(t1) > 1) {
				PHALCON_SEPARATE(t1);
			} else {
				FREE_ZVAL(t1);
				PHALCON_ALLOC_ZVAL(t1);
			}
		}
		phalcon_read_property_zval(t1, v2, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v5, t1);
		phalcon_debug_assign("$value", t1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Internal_Test::t10 (If) File=/Internal/Test Line=1426");
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
		if (!r0) {
			PHALCON_ALLOC_ZVAL(r0);
		} else {
			if (Z_REFCOUNT_P(r0) > 1) {
				SEPARATE_ZVAL(&r0);
			} else {
				if (Z_TYPE_P(r0) != IS_BOOL) {
					FREE_ZVAL(r0);
					PHALCON_ALLOC_ZVAL(r0);
				}
			}
		}
		is_identical_function(r0, t2, v5 TSRMLS_CC);
		if (!t3) {
			PHALCON_ALLOC_ZVAL(t3);
		} else {
			if (Z_REFCOUNT_P(t3) > 1) {
				SEPARATE_ZVAL(&t3);
			} else {
				if (Z_TYPE_P(t3) != IS_NULL) {
					FREE_ZVAL(t3);
					PHALCON_ALLOC_ZVAL(t3);
				}
			}
		}
		ZVAL_NULL(t3);
		if (!r1) {
			PHALCON_ALLOC_ZVAL(r1);
		} else {
			if (Z_REFCOUNT_P(r1) > 1) {
				SEPARATE_ZVAL(&r1);
			} else {
				if (Z_TYPE_P(r1) != IS_BOOL) {
					FREE_ZVAL(r1);
					PHALCON_ALLOC_ZVAL(r1);
				}
			}
		}
		is_identical_function(r1, t3, v5 TSRMLS_CC);
		if (!r2) {
			PHALCON_ALLOC_ZVAL(r2);
		} else {
			if (Z_REFCOUNT_P(r2) > 1) {
				SEPARATE_ZVAL(&r2);
			} else {
				if (Z_TYPE_P(r2) != IS_BOOL) {
					FREE_ZVAL(r2);
					PHALCON_ALLOC_ZVAL(r2);
				}
			}
		}
		ZVAL_BOOL(r2, zend_is_true(r0) || zend_is_true(r1));
		if (zend_is_true(r2)) {
			phalcon_step_over("Phalcon_Internal_Test::t10 (Block) File=/Internal/Test Line=1426");
			phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=/Internal/Test Line=1427");
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
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, t4, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				PHALCON_SEPARATE(v3);
				phalcon_array_append(v3, copy TSRMLS_CC);
			}
		} else {
			phalcon_step_over("Phalcon_Internal_Test::t10 (Block) File=/Internal/Test Line=1428");
			phalcon_step_over("Phalcon_Internal_Test::t10 (If) File=/Internal/Test Line=1429");
			eval_int = phalcon_array_isset(v1, v4);
			if (eval_int) {
				phalcon_step_over("Phalcon_Internal_Test::t10 (Block) File=/Internal/Test Line=1429");
				phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=/Internal/Test Line=1430");
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v5, 1, 0);
					Z_SET_REFCOUNT_P(copy, 1);
					PHALCON_SEPARATE(v3);
					phalcon_array_append(v3, copy TSRMLS_CC);
				}
			} else {
				phalcon_step_over("Phalcon_Internal_Test::t10 (Block) File=/Internal/Test Line=1431");
				phalcon_step_over("Phalcon_Internal_Test::t10 (Assignment) File=/Internal/Test Line=1432");
				if (!r3) {
					PHALCON_ALLOC_ZVAL(r3);
				} else {
					if (Z_REFCOUNT_P(r3) > 1) {
						PHALCON_SEPARATE(r3);
					} else {
						FREE_ZVAL(r3);
						PHALCON_ALLOC_ZVAL(r3);
					}
				}
				phalcon_concat_both(r3,  "'", v5, "'" TSRMLS_CC);
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, r3, 1, 0);
					Z_SET_REFCOUNT_P(copy, 1);
					PHALCON_SEPARATE(v3);
					phalcon_array_append(v3, copy TSRMLS_CC);
				}
			}
		}
	END_FOREACH(ac0, fes47, fee47, ah0, hp0);
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
	phalcon_step_over("Phalcon_Internal_Test::t10 (Method) File=/Internal/Test Line=1440");
}

PHP_METHOD(Phalcon_Internal_Test, t11){

	zval *v0 = NULL, *v1 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	phalcon_step_into_entry("Phalcon_Internal_Test", "t11", 0);
	phalcon_step_over("Phalcon_Internal_Test::t11 (Assignment) File=/Internal/Test Line=1441");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 0);
	phalcon_step_over("Phalcon_Internal_Test::t11 (Assignment) File=/Internal/Test Line=1442");
	phalcon_update_property_string(this_ptr, "_p2", strlen("_p2"), "lol" TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t11 (Assignment) File=/Internal/Test Line=1443");
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_p4", strlen("_p4"), 0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t11 (Assignment) File=/Internal/Test Line=1444");
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_internal_testdummy_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	phalcon_debug_param(this_ptr TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_Test" TSRMLS_CC);
	PHALCON_CPY_WRT_PARAM(v1, i0);
	phalcon_debug_assign("$dummy", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t11 (While) File=/Internal/Test Line=1445");
	ws48:
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_p4", sizeof("_p4")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	boolean_not_function(r0, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto we48;
	}
	phalcon_step_over("Phalcon_Internal_Test::t11 (Block) File=/Internal/Test Line=1445");
	phalcon_step_over("Phalcon_Internal_Test::t11 (If) File=/Internal/Test Line=1446");
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
	if (!r1) {
		PHALCON_ALLOC_ZVAL(r1);
	} else {
		if (Z_REFCOUNT_P(r1) > 1){ 
			PHALCON_SEPARATE(r1);
		}
	}
	is_equal_function(r1, v0, t1 TSRMLS_CC);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Internal_Test::t11 (Block) File=/Internal/Test Line=1446");
		phalcon_step_over("Phalcon_Internal_Test::t11 (MethodCall) File=/Internal/Test Line=1447");
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
	phalcon_step_over("Phalcon_Internal_Test::t11 (PostIncDecOp) File=/Internal/Test Line=1449");
	PHALCON_SEPARATE_PARAM(v0);
	increment_function(v0);
	phalcon_debug_vdump("PostIncrementing $n", v0);
	phalcon_step_over("Phalcon_Internal_Test::t11 (If) File=/Internal/Test Line=1450");
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
	ZVAL_LONG(t2, 2);
	if (!r2) {
		PHALCON_ALLOC_ZVAL(r2);
	} else {
		if (Z_REFCOUNT_P(r2) > 1) {
			SEPARATE_ZVAL(&r2);
		} else {
			if (Z_TYPE_P(r2) != IS_BOOL) {
				FREE_ZVAL(r2);
				PHALCON_ALLOC_ZVAL(r2);
			}
		}
	}
	is_smaller_function(r2, t2, v0 TSRMLS_CC);
	if (zend_is_true(r2)) {
		phalcon_step_over("Phalcon_Internal_Test::t11 (Block) File=/Internal/Test Line=1450");
		phalcon_step_over("Phalcon_Internal_Test::t11 (Assignment) File=/Internal/Test Line=1451");
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_p4", strlen("_p4"), 1 TSRMLS_CC);
	}
	goto ws48;
	we48:
	r0 = NULL;
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_read_property(t3, this_ptr, "_p2", sizeof("_p2")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t3 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t3);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_Test::t11 (Method) File=/Internal/Test Line=1457");
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
	phalcon_step_over("Phalcon_Internal_Test::t12 (Assignment) File=/Internal/Test Line=1458");
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "/", 1);
	p0[1] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "explode", 2, p0);
	phalcon_debug_vdump("explode > ", r0 TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r0);
	phalcon_debug_assign("$parts", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_Test::t12 (If) File=/Internal/Test Line=1459");
	eval_int = phalcon_array_isset_long(v1, 0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::t12 (Block) File=/Internal/Test Line=1459");
		phalcon_step_over("Phalcon_Internal_Test::t12 (Assignment) File=/Internal/Test Line=1460");
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_long(r1, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		p1[0] = r1;
		phalcon_debug_param(r1 TSRMLS_CC);
		phalcon_filter_alphanum(&r2, p1[0]);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_p1", strlen("_p1"), copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Internal_Test::t12 (Unset) File=/Internal/Test Line=1461");
		PHALCON_SEPARATE(v1);
		phalcon_array_unset_long(v1, 0);
	}
	phalcon_step_over("Phalcon_Internal_Test::t12 (If) File=/Internal/Test Line=1463");
	eval_int = phalcon_array_isset_long(v1, 1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Internal_Test::t12 (Block) File=/Internal/Test Line=1463");
		phalcon_step_over("Phalcon_Internal_Test::t12 (Assignment) File=/Internal/Test Line=1464");
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_array_fetch_long(r3, v1, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		p2[0] = r3;
		phalcon_debug_param(r3 TSRMLS_CC);
		phalcon_filter_alphanum(&r4, p2[0]);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r4, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_p2", strlen("_p2"), copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Internal_Test::t12 (Unset) File=/Internal/Test Line=1465");
		PHALCON_SEPARATE(v1);
		phalcon_array_unset_long(v1, 1);
	}
	phalcon_step_over("Phalcon_Internal_Test::t12 (Assignment) File=/Internal/Test Line=1467");
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_p4", strlen("_p4"), 0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_Test::t12 (Method) File=/Internal/Test Line=1470");
}

PHP_METHOD(Phalcon_Internal_Test, si1){

	zval *r0 = NULL;
	zend_bool silence;

	phalcon_step_into_entry("Phalcon_Internal_Test", "si1", 0);
	phalcon_step_over("Phalcon_Internal_Test::si1 (Echo) File=/Internal/Test Line=1471");
	php_printf("lol!");
	phalcon_step_over("Phalcon_Internal_Test::si1 (Silence) File=/Internal/Test Line=1472");
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_FUNC(r0, "session_start");
	phalcon_debug_vdump("session_start > ", r0 TSRMLS_CC);
	PG(display_errors) = silence;
	phalcon_step_out_entry();
	RETURN_NULL();
}

