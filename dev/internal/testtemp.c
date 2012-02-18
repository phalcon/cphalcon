
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e5a (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=6");
	//$a
	PHALCON_ALLOC_ZVAL(v0);
	ZVAL_LONG(v0, 5);
	phalcon_step_over("Phalcon_Internal_TestTemp::e5a (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=7");
	//$b
	//$a
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(v0);
	v1 = v0;
	phalcon_debug_assign("$b", v0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e5a (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=8");
	//$c
	//$b
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(v1);
	v2 = v1;
	phalcon_debug_assign("$c", v1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e5a (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=9");
	//$c
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_LONG(v2, 1);
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e5a (Method) File=Library/Phalcon/Internal/TestTemp.php Line=13");
}

PHP_METHOD(Phalcon_Internal_TestTemp, e9a){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_TestTemp", "e9a", 0);
	phalcon_step_over("Phalcon_Internal_TestTemp::e9a (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=14");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e9a (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=15");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e9a (Method) File=Library/Phalcon/Internal/TestTemp.php Line=19");
}

PHP_METHOD(Phalcon_Internal_TestTemp, e10a){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_TestTemp", "e10a", 0);
	phalcon_step_over("Phalcon_Internal_TestTemp::e10a (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=20");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e10a (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=21");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e10a (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=22");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e10a (Method) File=Library/Phalcon/Internal/TestTemp.php Line=26");
}

PHP_METHOD(Phalcon_Internal_TestTemp, e13a){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_TestTemp", "e13a", 0);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13a (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=27");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e13a (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=28");
	//$a
	phalcon_update_property_long(v0, "uno", strlen("uno"), 1 TSRMLS_CC);
	//$a
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, v0, "uno", sizeof("uno")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e13a (Method) File=Library/Phalcon/Internal/TestTemp.php Line=32");
}

PHP_METHOD(Phalcon_Internal_TestTemp, e13b){

	zval *v0 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_TestTemp", "e13b", 0);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13b (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=33");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e13b (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=34");
	//$a
	phalcon_update_property_long(v0, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13b (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=35");
	//$a
	phalcon_update_property_long(v0, "dos", strlen("dos"), 2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13b (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=36");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e13b (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=37");
	//$a
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_update_property_long(t0, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13b (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=38");
	//$a
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	phalcon_update_property_long(t1, "dos", strlen("dos"), 2 TSRMLS_CC);
	//$a
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t2);
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_read_property(t3, t2, "dos", sizeof("dos")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t3);
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e13b (Method) File=Library/Phalcon/Internal/TestTemp.php Line=42");
}

PHP_METHOD(Phalcon_Internal_TestTemp, e13c){

	zval *v0 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_TestTemp", "e13c", 0);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=43");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=44");
	//$a
	phalcon_update_property_long(v0, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=45");
	//$a
	phalcon_update_property_long(v0, "dos", strlen("dos"), 2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=46");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=47");
	//$a
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_update_property_long(t0, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=48");
	//$a
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	phalcon_update_property_long(t1, "dos", strlen("dos"), 2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=49");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=50");
	//$a
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_read_property(t3, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t3);
	PHALCON_ALLOC_ZVAL(t4);
	phalcon_read_property(t4, t3, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t4);
	phalcon_update_property_long(t4, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=51");
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
	phalcon_read_property(t7, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t7);
	PHALCON_ALLOC_ZVAL(t8);
	phalcon_read_property(t8, t7, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t8);
	PHALCON_ALLOC_ZVAL(t9);
	phalcon_read_property(t9, t8, "dos", sizeof("dos")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t9);
	phalcon_debug_vdump("Returning > ", t9 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t9) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t9);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t9);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Internal_TestTemp::e13c (Method) File=Library/Phalcon/Internal/TestTemp.php Line=55");
}

PHP_METHOD(Phalcon_Internal_TestTemp, e13d){

	zval *v0 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	phalcon_step_into_entry("Phalcon_Internal_TestTemp", "e13d", 0);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=56");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=57");
	//$a
	phalcon_update_property_long(v0, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=58");
	//$a
	phalcon_update_property_long(v0, "dos", strlen("dos"), 2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=59");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=60");
	//$a
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_update_property_long(t0, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=61");
	//$a
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	phalcon_update_property_long(t1, "dos", strlen("dos"), 2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=62");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=63");
	//$a
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_read_property(t3, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t3);
	PHALCON_ALLOC_ZVAL(t4);
	phalcon_read_property(t4, t3, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t4);
	phalcon_update_property_long(t4, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=64");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e13d (Method) File=Library/Phalcon/Internal/TestTemp.php Line=68");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e14 (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=69");
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
	phalcon_step_over("Phalcon_Internal_TestTemp::e14 (Assignment) File=Library/Phalcon/Internal/TestTemp.php Line=70");
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
}

