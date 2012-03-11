
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

PHP_METHOD(Phalcon_Internal_TestTemp, e5a){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_TestTemp", "e5a", 0);
	phalcon_step_over("Phalcon_Internal_TestTemp::e5a (Assignment) File=/Internal/TestTemp Line=6");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 5);
	phalcon_step_over("Phalcon_Internal_TestTemp::e5a (Assignment) File=/Internal/TestTemp Line=7");
	PHALCON_CPY_WRT(v1, v0);
	phalcon_debug_assign("$b", v0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e5a (Assignment) File=/Internal/TestTemp Line=8");
	PHALCON_CPY_WRT(v2, v1);
	phalcon_debug_assign("$c", v1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e5a (Assignment) File=/Internal/TestTemp Line=9");
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_LONG(v2, 1);
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e5a (Method) File=/Internal/TestTemp Line=13");
}

PHP_METHOD(Phalcon_Internal_TestTemp, e9a){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_TestTemp", "e9a", 0);
	phalcon_step_over("Phalcon_Internal_TestTemp::e9a (Assignment) File=/Internal/TestTemp Line=14");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e9a (Assignment) File=/Internal/TestTemp Line=15");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "LOL", 1);
	PHALCON_SEPARATE_PARAM(v0);
	phalcon_array_update_long(v0, 0, t0 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e9a (Method) File=/Internal/TestTemp Line=19");
}

PHP_METHOD(Phalcon_Internal_TestTemp, e10a){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_TestTemp", "e10a", 0);
	phalcon_step_over("Phalcon_Internal_TestTemp::e10a (Assignment) File=/Internal/TestTemp Line=20");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT_PARAM(v0, a0);
	phalcon_debug_assign("$a", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e10a (Assignment) File=/Internal/TestTemp Line=21");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "LOL", 1);
	PHALCON_SEPARATE_PARAM(v0);
	phalcon_array_update_long(v0, 0, t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e10a (Assignment) File=/Internal/TestTemp Line=22");
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_SEPARATE_PARAM(v0);
	phalcon_array_update_string(v0, "LOL", strlen("LOL"), t1 TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e10a (Method) File=/Internal/TestTemp Line=26");
}

PHP_METHOD(Phalcon_Internal_TestTemp, e13a){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_TestTemp", "e13a", 0);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13a (Assignment) File=/Internal/TestTemp Line=27");
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	PHALCON_CPY_WRT_PARAM(v0, i0);
	phalcon_debug_assign("$a", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13a (Assignment) File=/Internal/TestTemp Line=28");
	phalcon_update_property_long(v0, "uno", strlen("uno"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, v0, "uno", sizeof("uno")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_TestTemp::e13a (Method) File=/Internal/TestTemp Line=32");
}

PHP_METHOD(Phalcon_Internal_TestTemp, e13b){

	zval *v0 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_TestTemp", "e13b", 0);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13b (Assignment) File=/Internal/TestTemp Line=33");
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	PHALCON_CPY_WRT_PARAM(v0, i0);
	phalcon_debug_assign("$a", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13b (Assignment) File=/Internal/TestTemp Line=34");
	phalcon_update_property_long(v0, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13b (Assignment) File=/Internal/TestTemp Line=35");
	phalcon_update_property_long(v0, "dos", strlen("dos"), 2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13b (Assignment) File=/Internal/TestTemp Line=36");
	PHALCON_ALLOC_ZVAL(i1);
	object_init(i1);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, i1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(v0, "subA", strlen("subA"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Internal_TestTemp::e13b (Assignment) File=/Internal/TestTemp Line=37");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_long(t0, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13b (Assignment) File=/Internal/TestTemp Line=38");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_long(t1, "dos", strlen("dos"), 2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_read_property(t3, t2, "dos", sizeof("dos")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t3 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t3);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_TestTemp::e13b (Method) File=/Internal/TestTemp Line=42");
}

PHP_METHOD(Phalcon_Internal_TestTemp, e13c){

	zval *v0 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_TestTemp", "e13c", 0);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Assignment) File=/Internal/TestTemp Line=43");
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	PHALCON_CPY_WRT_PARAM(v0, i0);
	phalcon_debug_assign("$a", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Assignment) File=/Internal/TestTemp Line=44");
	phalcon_update_property_long(v0, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Assignment) File=/Internal/TestTemp Line=45");
	phalcon_update_property_long(v0, "dos", strlen("dos"), 2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Assignment) File=/Internal/TestTemp Line=46");
	PHALCON_ALLOC_ZVAL(i1);
	object_init(i1);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, i1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(v0, "subA", strlen("subA"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Assignment) File=/Internal/TestTemp Line=47");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_long(t0, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Assignment) File=/Internal/TestTemp Line=48");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_long(t1, "dos", strlen("dos"), 2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Assignment) File=/Internal/TestTemp Line=49");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Assignment) File=/Internal/TestTemp Line=50");
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_read_property(t3, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t4);
	phalcon_read_property(t4, t3, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_long(t4, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Assignment) File=/Internal/TestTemp Line=51");
	PHALCON_ALLOC_ZVAL(t5);
	phalcon_read_property(t5, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t6);
	phalcon_read_property(t6, t5, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_long(t6, "dos", strlen("dos"), 2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t7);
	phalcon_read_property(t7, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t8);
	phalcon_read_property(t8, t7, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t9);
	phalcon_read_property(t9, t8, "dos", sizeof("dos")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t9 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t9);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Method) File=/Internal/TestTemp Line=55");
}

PHP_METHOD(Phalcon_Internal_TestTemp, e13d){

	zval *v0 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_TestTemp", "e13d", 0);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Assignment) File=/Internal/TestTemp Line=56");
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	PHALCON_CPY_WRT_PARAM(v0, i0);
	phalcon_debug_assign("$a", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Assignment) File=/Internal/TestTemp Line=57");
	phalcon_update_property_long(v0, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Assignment) File=/Internal/TestTemp Line=58");
	phalcon_update_property_long(v0, "dos", strlen("dos"), 2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Assignment) File=/Internal/TestTemp Line=59");
	PHALCON_ALLOC_ZVAL(i1);
	object_init(i1);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, i1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(v0, "subA", strlen("subA"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Assignment) File=/Internal/TestTemp Line=60");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_long(t0, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Assignment) File=/Internal/TestTemp Line=61");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_long(t1, "dos", strlen("dos"), 2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Assignment) File=/Internal/TestTemp Line=62");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Assignment) File=/Internal/TestTemp Line=63");
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_read_property(t3, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t4);
	phalcon_read_property(t4, t3, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_long(t4, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Assignment) File=/Internal/TestTemp Line=64");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Method) File=/Internal/TestTemp Line=68");
}

PHP_METHOD(Phalcon_Internal_TestTemp, e14){

	zval *v0 = NULL, *v1 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_TestTemp", "e14", 0);
	phalcon_step_over("Phalcon_Internal_TestTemp::e14 (Assignment) File=/Internal/TestTemp Line=69");
	PHALCON_ALLOC_ZVAL(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v1, i0);
	phalcon_debug_assign("$a", i0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e14 (Assignment) File=/Internal/TestTemp Line=70");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e14 (Method) File=/Internal/TestTemp Line=74");
}

PHP_METHOD(Phalcon_Internal_TestTemp, e15){

	zval *v0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_TestTemp", "e15", 0);
	phalcon_step_over("Phalcon_Internal_TestTemp::e15 (Assignment) File=/Internal/TestTemp Line=75");
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_BOOL(v0, 1);
	phalcon_step_over("Phalcon_Internal_TestTemp::e15 (If) File=/Internal/TestTemp Line=76");
	if (Z_TYPE_P(v0) != IS_BOOL || (Z_TYPE_P(v0) == IS_BOOL && Z_BVAL_P(v0))) {
		phalcon_step_over("Phalcon_Internal_TestTemp::e15 (Block) File=/Internal/TestTemp Line=76");
		phalcon_step_over("Phalcon_Internal_TestTemp::e15 (Echo) File=/Internal/TestTemp Line=77");
		php_printf("%l", 1);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
}

