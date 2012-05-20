
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
#include "kernel/operators.h"
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

PHP_METHOD(Phalcon_Internal_Test, __construct){

	zval *a0 = NULL, *a1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_internal_test_ce, this_ptr, "_p8", strlen("_p8"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	zend_update_property(phalcon_internal_test_ce, this_ptr, "_p9", strlen("_p9"), a1 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, e1){


	PHALCON_MM_GROW();
	PHALCON_MM_RESTORE();
	RETURN_LONG(5);
}

PHP_METHOD(Phalcon_Internal_Test, e2){


	PHALCON_MM_GROW();
	PHALCON_MM_RESTORE();
	RETURN_STRING("5", 1);
}

PHP_METHOD(Phalcon_Internal_Test, e3){

	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 5);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, -1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_RETURN_NCTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, e4){

	zval *a = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a);
	ZVAL_LONG(a, 5);
	
	PHALCON_RETURN_NCTOR(a);
}

PHP_METHOD(Phalcon_Internal_Test, e5){

	zval *a = NULL, *b = NULL, *c = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a);
	ZVAL_LONG(a, 5);
	PHALCON_CPY_WRT(b, a);
	PHALCON_CPY_WRT(c, b);
	
	PHALCON_RETURN_NCTOR(c);
}

PHP_METHOD(Phalcon_Internal_Test, e6){

	zval *num = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &num) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_RETURN_CHECK_CTOR(num);
}

PHP_METHOD(Phalcon_Internal_Test, e7){

	zval *num = NULL, *a = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &num) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(a, num);
	
	PHALCON_RETURN_CHECK_CTOR(a);
}

PHP_METHOD(Phalcon_Internal_Test, e9){


	PHALCON_MM_GROW();
	PHALCON_MM_RESTORE();
	RETURN_STRING("LOL", 1);
}

PHP_METHOD(Phalcon_Internal_Test, e10){


	PHALCON_MM_GROW();
	PHALCON_MM_RESTORE();
	RETURN_DOUBLE(1.5);
}

PHP_METHOD(Phalcon_Internal_Test, e16){

	zval *a = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(a, i0);
	phalcon_update_property_long(a, "uno", strlen("uno"), 1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init(i1);
	phalcon_update_property_zval(a, "subA", strlen("subA"), i1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, a, "subA", sizeof("subA")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_update_property_long(t0, "dos", strlen("dos"), 2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, a, "uno", sizeof("uno")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, a, "subA", sizeof("subA")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, t2, "dos", sizeof("dos")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, t1, t3 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, e14){

	zval *val = NULL, *a = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &val) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(a, i0);
	phalcon_update_property_zval(a, "val", strlen("val"), val TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, a, "val", sizeof("val")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, e15){

	zval *a = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(a, i0);
	phalcon_update_property_string(a, "val", strlen("val"), "hullo" TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, a, "val", sizeof("val")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, e13){

	zval *a = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(a, i0);
	phalcon_update_property_long(a, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_update_property_long(a, "dos", strlen("dos"), 2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init(i1);
	phalcon_update_property_zval(a, "subA", strlen("subA"), i1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, a, "subA", sizeof("subA")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_update_property_long(t0, "uno", strlen("uno"), 1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, a, "subA", sizeof("subA")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_update_property_long(t1, "dos", strlen("dos"), 2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i2);
	object_init(i2);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, a, "subA", sizeof("subA")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_update_property_zval(t2, "subSubA", strlen("subSubA"), i2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, a, "subA", sizeof("subA")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, t3, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_update_property_long(t4, "uno", strlen("uno"), 1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_read_property(&t5, a, "subA", sizeof("subA")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t6);
	phalcon_read_property(&t6, t5, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_update_property_long(t6, "dos", strlen("dos"), 2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t7);
	phalcon_read_property(&t7, a, "uno", sizeof("uno")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t8);
	phalcon_read_property(&t8, a, "subA", sizeof("subA")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t9);
	phalcon_read_property(&t9, t8, "uno", sizeof("uno")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, t7, t9 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t10);
	phalcon_read_property(&t10, a, "subA", sizeof("subA")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t11);
	phalcon_read_property(&t11, t10, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t12);
	phalcon_read_property(&t12, t11, "uno", sizeof("uno")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	mul_function(r1, r0, t12 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r1);
}

PHP_METHOD(Phalcon_Internal_Test, o1){

	zval *num = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &num) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!num) {
		PHALCON_INIT_VAR(num);
		ZVAL_LONG(num, 0);
	} else {
		PHALCON_SEPARATE_PARAM(num);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	ZVAL_ZVAL(t0, num, 1, 0);
	increment_function(num);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, o2){

	zval *num = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &num) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(num);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	ZVAL_ZVAL(t0, num, 1, 0);
	decrement_function(num);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, o3){

	zval *num = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &num) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!num) {
		PHALCON_INIT_VAR(num);
		ZVAL_LONG(num, 1);
	}
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, num, t0 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o4){

	zval *num = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &num) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(num);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, num, num TSRMLS_CC);
	PHALCON_CPY_WRT(num, r0);
	
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o5){

	zval *num1 = NULL, *num2 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &num1, &num2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, num1, num2 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o6){

	zval *num1 = NULL, *num2 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &num1, &num2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	sub_function(r0, num1, num2 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o7){

	zval *num1 = NULL, *num2 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &num1, &num2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, num1, num2 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o8){

	zval *num1 = NULL, *num2 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &num1, &num2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	div_function(r0, num1, num2 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o9){

	zval *num1 = NULL, *num2 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &num1, &num2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	mod_function(r0, num1, num2 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o10){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_RETURN_NCTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o11){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	sub_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_RETURN_NCTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o12){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_RETURN_NCTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o13){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	div_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_RETURN_NCTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o14){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	mod_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_RETURN_NCTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o15){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "10", 1);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 10);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o16){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_INIT_VAR(t1);
	ZVAL_STRING(t1, "5", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	sub_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o17){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 5);
	PHALCON_INIT_VAR(t1);
	ZVAL_STRING(t1, "7", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o18){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "100", 1);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 10);
	PHALCON_ALLOC_ZVAL_MM(r0);
	div_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o19){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 40);
	PHALCON_INIT_VAR(t1);
	ZVAL_STRING(t1, "5", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	mod_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o20){

	zval *c = NULL, *a = NULL, *b = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &c) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(a);
	ZVAL_LONG(a, 150);
	PHALCON_INIT_VAR(b);
	ZVAL_LONG(b, 250);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, a, b TSRMLS_CC);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 100);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_add_function(r1, r0, t0 TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 100);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	div_function(r2, r1, t1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	sub_function(r3, r2, b TSRMLS_CC);
	PHALCON_CPY_WRT(a, r3);
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 5);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	mul_function(r4, b, t2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	div_function(r5, r4, c TSRMLS_CC);
	PHALCON_CPY_WRT(b, r5);
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	div_function(r6, a, b TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r6);
}

PHP_METHOD(Phalcon_Internal_Test, o21){

	zval *a = NULL, *b = NULL, *c = NULL, *d = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a);
	ZVAL_STRING(a, "memory", 1);
	PHALCON_INIT_VAR(b);
	ZVAL_STRING(b, "yes", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "no, ", a);
	PHALCON_CPY_WRT(c, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CONCAT_LEFT(r1, "leaks, ", b);
	PHALCON_CPY_WRT(d, r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, c, d TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	concat_function(r3, r2, b TSRMLS_CC);
	PHALCON_CPY_WRT(b, r3);
	
	PHALCON_RETURN_CTOR(b);
}

PHP_METHOD(Phalcon_Internal_Test, o22){

	zval *e = NULL, *i = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(e);
	ZVAL_LONG(e, 0);
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	fs_fdd7_0:
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 25);
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, i, t0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_fdd7_0;
		}
		PHALCON_INIT_VAR(r1);
		concat_function(r1, e, i TSRMLS_CC);
		PHALCON_CPY_WRT(e, r1);
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto fs_fdd7_0;
	fe_fdd7_0:
	
	PHALCON_RETURN_CHECK_CTOR(e);
}

PHP_METHOD(Phalcon_Internal_Test, o23){

	zval *e = NULL, *i = NULL, *sx = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(e);
	ZVAL_LONG(e, 0);
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	fs_fdd7_1:
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 25);
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, i, t0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_fdd7_1;
		}
		PHALCON_INIT_VAR(r1);
		PHALCON_CONCAT_RIGHT(r1, i, "-");
		PHALCON_CPY_WRT(sx, r1);
		
		PHALCON_INIT_VAR(r2);
		concat_function(r2, e, sx TSRMLS_CC);
		PHALCON_CPY_WRT(e, r2);
		PHALCON_INIT_VAR(sx);
		ZVAL_STRING(sx, "nope", 1);
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto fs_fdd7_1;
	fe_fdd7_1:
	
	PHALCON_RETURN_CHECK_CTOR(e);
}

PHP_METHOD(Phalcon_Internal_Test, a0){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	
	PHALCON_RETURN_CTOR(a0);
}

PHP_METHOD(Phalcon_Internal_Test, a1){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_null(a0);
	add_next_index_bool(a0, 0);
	add_next_index_long(a0, 0);
	add_next_index_stringl(a0, "whtzup", strlen("whtzup"), 1);
	
	PHALCON_RETURN_CTOR(a0);
}

PHP_METHOD(Phalcon_Internal_Test, a2){

	zval *a = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(a, a0);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "well", 1);
	phalcon_array_update_long(&a, 0, &t0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, a3){

	zval *a = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(a, a0);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "LOL", 1);
	phalcon_array_update_long(&a, 0, &t0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	phalcon_array_update_string(&a, "LOL", strlen("LOL"), &t1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, a, "LOL", strlen("LOL"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, a4){

	zval *b = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(b, a0);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	if (Z_TYPE_P(b) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_array_fetch_long(&t1, b, 1, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t1) > 1) {
		phalcon_array_update_long(&b, 1, &t1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t1) != IS_ARRAY) {
		convert_to_array(t1);
		phalcon_array_update_long(&b, 1, &t1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t1) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_array_fetch_string(&t2, t1, "LOL", strlen("LOL"), PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t2) > 1) {
		phalcon_array_update_string(&t1, "LOL", strlen("LOL"), &t2, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t2) != IS_ARRAY) {
		convert_to_array(t2);
		phalcon_array_update_string(&t1, "LOL", strlen("LOL"), &t2, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t2) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_array_fetch_long(&t3, t2, 5, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t3) > 1) {
		phalcon_array_update_long(&t2, 5, &t3, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t3) != IS_ARRAY) {
		convert_to_array(t3);
		phalcon_array_update_long(&t2, 5, &t3, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	phalcon_array_update_string(&t3, "YEAH", strlen("YEAH"), &t0, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, b, 1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, r0, "LOL", strlen("LOL"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, r1, 5, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch_string(&r3, r2, "YEAH", strlen("YEAH"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(r3);
}

PHP_METHOD(Phalcon_Internal_Test, a5){

	zval *a = NULL, *b = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(a, a0);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "LOL", 1);
	phalcon_array_update_long(&a, 0, &t0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	phalcon_array_update_string(&a, "LOL", strlen("LOL"), &t1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_CPY_WRT(b, a1);
	PHALCON_INIT_VAR(t2);
	ZVAL_STRING(t2, "LOL", 1);
	phalcon_array_update_string(&b, "LOL", strlen("LOL"), &t2, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 0);
	phalcon_array_update_long(&b, 0, &t3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, b, 0, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, a, "LOL", strlen("LOL"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_add_function(r2, r0, r1 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r2);
}

PHP_METHOD(Phalcon_Internal_Test, a6){

	zval *a = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(a, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	phalcon_array_update_long(&a, 1, &a1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	if (Z_TYPE_P(a) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_array_fetch_long(&t1, a, 1, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t1) > 1) {
		phalcon_array_update_long(&a, 1, &t1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t1) != IS_ARRAY) {
		convert_to_array(t1);
		phalcon_array_update_long(&a, 1, &t1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	phalcon_array_update_string(&t1, "LOL", strlen("LOL"), &t0, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, a, 1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, r0, "LOL", strlen("LOL"), PHALCON_NOISY TSRMLS_CC);
	zend_print_zval(r1, 0);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, a7){

	zval *a = NULL, *b = NULL, *c = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(a, a0);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "LOL", 1);
	phalcon_array_update_long(&a, 0, &t0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	phalcon_array_update_long(&a, 1, &a1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	if (Z_TYPE_P(a) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_array_fetch_long(&t2, a, 1, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t2) > 1) {
		phalcon_array_update_long(&a, 1, &t2, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t2) != IS_ARRAY) {
		convert_to_array(t2);
		phalcon_array_update_long(&a, 1, &t2, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	phalcon_array_update_string(&t2, "LOL", strlen("LOL"), &t1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 0);
	phalcon_array_update_string(&a, "LOL", strlen("LOL"), &t3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	PHALCON_CPY_WRT(b, a2);
	PHALCON_INIT_VAR(t4);
	ZVAL_STRING(t4, "LOL", 1);
	phalcon_array_update_string(&b, "LOL", strlen("LOL"), &t4, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(t5);
	ZVAL_LONG(t5, 0);
	phalcon_array_update_long(&b, 0, &t5, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(t6);
	ZVAL_LONG(t6, 1);
	if (Z_TYPE_P(b) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t7);
		phalcon_array_fetch_long(&t7, b, 1, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t7) > 1) {
		phalcon_array_update_long(&b, 1, &t7, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t7) != IS_ARRAY) {
		convert_to_array(t7);
		phalcon_array_update_long(&b, 1, &t7, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	phalcon_array_update_string(&t7, "LOL", strlen("LOL"), &t6, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	PHALCON_CPY_WRT(c, a3);
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	phalcon_array_update_long(&c, 0, &a4, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(a5);
	array_init(a5);
	if (Z_TYPE_P(c) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t8);
		phalcon_array_fetch_long(&t8, c, 0, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t8) > 1) {
		phalcon_array_update_long(&c, 0, &t8, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t8) != IS_ARRAY) {
		convert_to_array(t8);
		phalcon_array_update_long(&c, 0, &t8, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	phalcon_array_update_long(&t8, 0, &a5, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(a6);
	array_init(a6);
	if (Z_TYPE_P(c) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t9);
		phalcon_array_fetch_long(&t9, c, 0, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t9) > 1) {
		phalcon_array_update_long(&c, 0, &t9, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t9) != IS_ARRAY) {
		convert_to_array(t9);
		phalcon_array_update_long(&c, 0, &t9, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t9) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t10);
		phalcon_array_fetch_long(&t10, t9, 0, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t10) > 1) {
		phalcon_array_update_long(&t9, 0, &t10, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t10) != IS_ARRAY) {
		convert_to_array(t10);
		phalcon_array_update_long(&t9, 0, &t10, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	phalcon_array_update_long(&t10, 0, &a6, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(t11);
	ZVAL_LONG(t11, 1);
	if (Z_TYPE_P(c) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t12);
		phalcon_array_fetch_long(&t12, c, 0, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t12) > 1) {
		phalcon_array_update_long(&c, 0, &t12, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t12) != IS_ARRAY) {
		convert_to_array(t12);
		phalcon_array_update_long(&c, 0, &t12, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t12) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t13);
		phalcon_array_fetch_long(&t13, t12, 0, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t13) > 1) {
		phalcon_array_update_long(&t12, 0, &t13, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t13) != IS_ARRAY) {
		convert_to_array(t13);
		phalcon_array_update_long(&t12, 0, &t13, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t13) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t14);
		phalcon_array_fetch_long(&t14, t13, 0, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t14) > 1) {
		phalcon_array_update_long(&t13, 0, &t14, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t14) != IS_ARRAY) {
		convert_to_array(t14);
		phalcon_array_update_long(&t13, 0, &t14, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	phalcon_array_update_string(&t14, "LOL", strlen("LOL"), &t11, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, b, 1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, r0, "LOL", strlen("LOL"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, a, 1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch_string(&r3, r2, "LOL", strlen("LOL"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	mul_function(r4, r1, r3 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	phalcon_array_fetch_long(&r5, c, 0, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	phalcon_array_fetch_long(&r6, r5, 0, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r7);
	phalcon_array_fetch_long(&r7, r6, 0, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r8);
	phalcon_array_fetch_string(&r8, r7, "LOL", strlen("LOL"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r9);
	mul_function(r9, r4, r8 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r9);
}

PHP_METHOD(Phalcon_Internal_Test, a10){

	zval *e = NULL, *v = NULL, *k = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_assoc_long_ex(a0, "hello1", strlen("hello1")+1, 1);
	add_assoc_long_ex(a0, "hello2", strlen("hello2")+1, 2);
	add_assoc_long_ex(a0, "hello3", strlen("hello3")+1, 3);
	PHALCON_CPY_WRT(e, a0);
	if (phalcon_valid_foreach(e TSRMLS_CC)) {
		ALLOC_HASHTABLE(ah0);
		zend_hash_init(ah0, 0, NULL, NULL, 0);
		zend_hash_copy(ah0, Z_ARRVAL_P(e), NULL, NULL, sizeof(zval*));
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_2;
		} else {
			PHALCON_INIT_VAR(k);
			hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
			if (hash_type == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(k, hash_index, hash_index_len-1, 1);
			} else {
				if (hash_type == HASH_KEY_IS_LONG) {
					ZVAL_LONG(k, hash_num);
				}
			}
		}
		PHALCON_INIT_VAR(v);
		ZVAL_ZVAL(v, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch(&r0, e, k, PHALCON_NOISY TSRMLS_CC);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 100);
		PHALCON_INIT_VAR(r1);
		phalcon_add_function(r1, r0, t0 TSRMLS_CC);
		phalcon_array_update(&e, k, &r1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_2;
		fee_fdd7_2:
		zend_hash_destroy(ah0);
		efree(ah0);
	}
	
	PHALCON_RETURN_CTOR(e);
}

PHP_METHOD(Phalcon_Internal_Test, a11){

	zval *e = NULL, *v = NULL, *k = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	add_next_index_long(a0, 4);
	add_next_index_long(a0, 5);
	PHALCON_CPY_WRT(e, a0);
	if (phalcon_valid_foreach(e TSRMLS_CC)) {
		ALLOC_HASHTABLE(ah0);
		zend_hash_init(ah0, 0, NULL, NULL, 0);
		zend_hash_copy(ah0, Z_ARRVAL_P(e), NULL, NULL, sizeof(zval*));
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_3:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_3;
		} else {
			PHALCON_INIT_VAR(k);
			hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
			if (hash_type == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(k, hash_index, hash_index_len-1, 1);
			} else {
				if (hash_type == HASH_KEY_IS_LONG) {
					ZVAL_LONG(k, hash_num);
				}
			}
		}
		PHALCON_INIT_VAR(v);
		ZVAL_ZVAL(v, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch(&r0, e, k, PHALCON_NOISY TSRMLS_CC);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		PHALCON_INIT_VAR(r1);
		phalcon_add_function(r1, k, t0 TSRMLS_CC);
		phalcon_array_update(&e, r1, &r0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_3;
		fee_fdd7_3:
		zend_hash_destroy(ah0);
		efree(ah0);
	}
	
	PHALCON_RETURN_CTOR(e);
}

PHP_METHOD(Phalcon_Internal_Test, a12){

	zval *k = NULL, *e = NULL, *v = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(k);
	ZVAL_LONG(k, 0);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	add_next_index_long(a0, 4);
	add_next_index_long(a0, 5);
	PHALCON_CPY_WRT(e, a0);
	if (phalcon_valid_foreach(e TSRMLS_CC)) {
		ALLOC_HASHTABLE(ah0);
		zend_hash_init(ah0, 0, NULL, NULL, 0);
		zend_hash_copy(ah0, Z_ARRVAL_P(e), NULL, NULL, sizeof(zval*));
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_4:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_4;
		}
		
		PHALCON_INIT_VAR(v);
		ZVAL_ZVAL(v, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch(&r0, e, k, PHALCON_NOISY TSRMLS_CC);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		PHALCON_INIT_VAR(r1);
		phalcon_add_function(r1, k, t0 TSRMLS_CC);
		phalcon_array_update(&e, r1, &r0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		PHALCON_SEPARATE(k);
		increment_function(k);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_4;
		fee_fdd7_4:
		zend_hash_destroy(ah0);
		efree(ah0);
	}
	
	PHALCON_RETURN_CTOR(e);
}

PHP_METHOD(Phalcon_Internal_Test, a13){

	zval *f = NULL, *e = NULL, *v = NULL;
	zval *a0 = NULL, *a1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(f, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	add_next_index_long(a1, 4);
	add_next_index_long(a1, 5);
	PHALCON_CPY_WRT(e, a1);
	if (phalcon_valid_foreach(e TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(e);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_5:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_5;
		}
		
		PHALCON_INIT_VAR(v);
		ZVAL_ZVAL(v, *hd, 1, 0);
		phalcon_array_append(&f, v, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_5;
		fee_fdd7_5:
		if(0){ };
	}
	
	PHALCON_RETURN_CTOR(f);
}

PHP_METHOD(Phalcon_Internal_Test, a14){

	zval *f = NULL, *e = NULL, *v = NULL, *k = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(f, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	add_next_index_long(a1, 4);
	add_next_index_long(a1, 5);
	PHALCON_CPY_WRT(e, a1);
	if (phalcon_valid_foreach(e TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(e);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_6:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_6;
		} else {
			PHALCON_INIT_VAR(k);
			hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
			if (hash_type == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(k, hash_index, hash_index_len-1, 1);
			} else {
				if (hash_type == HASH_KEY_IS_LONG) {
					ZVAL_LONG(k, hash_num);
				}
			}
		}
		PHALCON_INIT_VAR(v);
		ZVAL_ZVAL(v, *hd, 1, 0);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 2);
		PHALCON_INIT_VAR(r0);
		mul_function(r0, k, t0 TSRMLS_CC);
		PHALCON_CPY_WRT(k, r0);
		
		PHALCON_INIT_VAR(r1);
		phalcon_add_function(r1, v, k TSRMLS_CC);
		phalcon_array_update(&f, k, &r1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_6;
		fee_fdd7_6:
		if(0){ };
	}
	
	PHALCON_RETURN_CTOR(f);
}

PHP_METHOD(Phalcon_Internal_Test, a15){

	zval *f = NULL, *e = NULL, *v = NULL, *k = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(f, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	add_next_index_long(a1, 4);
	add_next_index_long(a1, 5);
	PHALCON_CPY_WRT(e, a1);
	if (phalcon_valid_foreach(e TSRMLS_CC)) {
		ALLOC_HASHTABLE(ah0);
		zend_hash_init(ah0, 0, NULL, NULL, 0);
		zend_hash_copy(ah0, Z_ARRVAL_P(e), NULL, NULL, sizeof(zval*));
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_7:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_7;
		} else {
			PHALCON_INIT_VAR(k);
			hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
			if (hash_type == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(k, hash_index, hash_index_len-1, 1);
			} else {
				if (hash_type == HASH_KEY_IS_LONG) {
					ZVAL_LONG(k, hash_num);
				}
			}
		}
		PHALCON_INIT_VAR(v);
		ZVAL_ZVAL(v, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch(&r0, e, k, PHALCON_NOISY TSRMLS_CC);
		phalcon_array_update(&f, k, &r0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 100);
		
		PHALCON_INIT_VAR(r1);
		mul_function(r1, k, t0 TSRMLS_CC);
		phalcon_array_update(&e, k, &r1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch(&r2, f, k, PHALCON_NOISY TSRMLS_CC);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 50);
		
		PHALCON_INIT_VAR(r3);
		mul_function(r3, r2, t1 TSRMLS_CC);
		phalcon_array_update(&f, k, &r3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_7;
		fee_fdd7_7:
		zend_hash_destroy(ah0);
		efree(ah0);
	}
	
	PHALCON_RETURN_CTOR(f);
}

PHP_METHOD(Phalcon_Internal_Test, a16){

	zval *f = NULL, *e = NULL, *v = NULL, *k = NULL, *sv = NULL, *sk = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL;
	zval *t0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(f, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	add_assoc_stringl_ex(a2, "in", strlen("in")+1, "out", strlen("out"), 1);
	phalcon_array_update_string(&a1, "hello", strlen("hello"), &a2, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	add_assoc_stringl_ex(a3, "file", strlen("file")+1, "type", strlen("type"), 1);
	add_assoc_stringl_ex(a3, "php", strlen("php")+1, "unix", strlen("unix"), 1);
	add_assoc_stringl_ex(a3, "tab", strlen("tab")+1, "ins", strlen("ins"), 1);
	phalcon_array_update_string(&a1, "bye", strlen("bye"), &a3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	phalcon_array_update_string(&a1, "encoding", strlen("encoding"), &a4, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	add_assoc_stringl_ex(a1, "sucks", strlen("sucks")+1, "yes", strlen("yes"), 1);
	PHALCON_CPY_WRT(e, a1);
	if (phalcon_valid_foreach(e TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(e);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_8:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_8;
		} else {
			PHALCON_INIT_VAR(k);
			hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
			if (hash_type == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(k, hash_index, hash_index_len-1, 1);
			} else {
				if (hash_type == HASH_KEY_IS_LONG) {
					ZVAL_LONG(k, hash_num);
				}
			}
		}
		PHALCON_INIT_VAR(v);
		ZVAL_ZVAL(v, *hd, 1, 0);
		if (Z_TYPE_P(v) == IS_ARRAY) { 
			if (phalcon_valid_foreach(v TSRMLS_CC)) {
				ah1 = Z_ARRVAL_P(v);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_fdd7_9:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee_fdd7_9;
				} else {
					PHALCON_INIT_VAR(sk);
					hash_type = zend_hash_get_current_key_ex(ah1, &hash_index, &hash_index_len, &hash_num, 0, &hp1);
					if (hash_type == HASH_KEY_IS_STRING) {
						ZVAL_STRINGL(sk, hash_index, hash_index_len-1, 1);
					} else {
						if (hash_type == HASH_KEY_IS_LONG) {
							ZVAL_LONG(sk, hash_num);
						}
					}
				}
				PHALCON_INIT_VAR(sv);
				ZVAL_ZVAL(sv, *hd, 1, 0);
				if (Z_TYPE_P(f) == IS_ARRAY) {
					PHALCON_INIT_VAR(t0);
					phalcon_array_fetch(&t0, f, k, PHALCON_SILENT TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t0) > 1) {
					phalcon_array_update(&f, k, &t0, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
				}
				if (Z_TYPE_P(t0) != IS_ARRAY) {
					convert_to_array(t0);
					phalcon_array_update(&f, k, &t0, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				}
				phalcon_array_update(&t0, sk, &sv, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_fdd7_9;
				fee_fdd7_9:
				if(0){ };
			}
		} else {
			phalcon_array_update(&f, k, &v, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_8;
		fee_fdd7_8:
		if(0){ };
	}
	
	PHALCON_RETURN_CTOR(f);
}

PHP_METHOD(Phalcon_Internal_Test, a17){

	zval *w = NULL, *a = NULL, *b = NULL, *v = NULL, *k = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(w, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_index_long(a1, 7, 0);
	add_index_long(a1, 8, 1);
	add_index_long(a1, 9, 2);
	PHALCON_CPY_WRT(a, a1);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	add_next_index_stringl(a3, "hello1", strlen("hello1"), 1);
	phalcon_array_append(&a2, a3, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	add_next_index_stringl(a4, "hello2", strlen("hello2"), 1);
	phalcon_array_update_long(&a2, 1, &a4, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(a5);
	array_init(a5);
	add_next_index_stringl(a5, "hello3", strlen("hello3"), 1);
	phalcon_array_update_long(&a2, 2, &a5, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_CPY_WRT(b, a2);
	if (phalcon_valid_foreach(a TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(a);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_10:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_10;
		} else {
			PHALCON_INIT_VAR(k);
			hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
			if (hash_type == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(k, hash_index, hash_index_len-1, 1);
			} else {
				if (hash_type == HASH_KEY_IS_LONG) {
					ZVAL_LONG(k, hash_num);
				}
			}
		}
		PHALCON_INIT_VAR(v);
		ZVAL_ZVAL(v, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch(&r0, b, v, PHALCON_NOISY TSRMLS_CC);
		phalcon_array_update(&w, k, &r0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_10;
		fee_fdd7_10:
		if(0){ };
	}
	
	PHALCON_RETURN_CTOR(w);
}

PHP_METHOD(Phalcon_Internal_Test, a18){

	zval *a = NULL, *c = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, "hello1", strlen("hello1"), 1);
	add_next_index_stringl(a0, "hello2", strlen("hello2"), 1);
	add_next_index_stringl(a0, "hello3", strlen("hello3"), 1);
	PHALCON_CPY_WRT(a, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	phalcon_array_append(&a1, a, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	PHALCON_CPY_WRT(c, a1);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "see", 1);
	if (Z_TYPE_P(c) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_array_fetch_long(&t1, c, 0, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t1) > 1) {
		phalcon_array_update_long(&c, 0, &t1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t1) != IS_ARRAY) {
		convert_to_array(t1);
		phalcon_array_update_long(&c, 0, &t1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	phalcon_array_update_long(&t1, 0, &t0, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(a);
}

PHP_METHOD(Phalcon_Internal_Test, a19){

	zval *a = NULL, *b = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, "hello1", strlen("hello1"), 1);
	add_next_index_stringl(a0, "hello2", strlen("hello2"), 1);
	add_next_index_stringl(a0, "hello3", strlen("hello3"), 1);
	add_next_index_bool(a0, 0);
	add_next_index_null(a0);
	add_next_index_double(a0, 1.34);
	PHALCON_CPY_WRT(a, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_next_index_stringl(a1, "lol1", strlen("lol1"), 1);
	add_next_index_stringl(a1, "lol2", strlen("lol2"), 1);
	add_next_index_stringl(a1, "lol3", strlen("lol3"), 1);
	add_next_index_stringl(a1, "lol4", strlen("lol4"), 1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	PHALCON_CPY_WRT(b, a1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, a, b TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, a20){

	zval *b = NULL, *c = NULL, *a = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(b);
	ZVAL_DOUBLE(b, 3.45);
	PHALCON_INIT_VAR(c);
	ZVAL_STRING(c, "6.28", 1);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(a, a0);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "whtzup!", 1);
	phalcon_array_update(&a, b, &t0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_STRING(t1, "morelol", 1);
	phalcon_array_update(&a, c, &t1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(a);
}

PHP_METHOD(Phalcon_Internal_Test, a21){

	zval *b = NULL, *c = NULL, *d = NULL, *e = NULL, *f = NULL, *g = NULL, *h = NULL, *a = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(b);
	ZVAL_NULL(b);
	PHALCON_INIT_VAR(c);
	ZVAL_BOOL(c, 0);
	PHALCON_INIT_VAR(d);
	ZVAL_BOOL(d, 1);
	PHALCON_INIT_VAR(e);
	ZVAL_LONG(e, 100);
	PHALCON_INIT_VAR(f);
	ZVAL_DOUBLE(f, 3.45);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 100);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, -1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_CPY_WRT(g, r0);
	PHALCON_INIT_VAR(h);
	ZVAL_STRING(h, "6.28", 1);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(a, a0);
	PHALCON_INIT_VAR(t2);
	ZVAL_STRING(t2, "whtzup!", 1);
	if (Z_TYPE_P(a) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_array_fetch(&t3, a, b, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t3) > 1) {
		phalcon_array_update(&a, b, &t3, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t3) != IS_ARRAY) {
		convert_to_array(t3);
		phalcon_array_update(&a, b, &t3, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t3) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_array_fetch(&t4, t3, c, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t4) > 1) {
		phalcon_array_update(&t3, c, &t4, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t4) != IS_ARRAY) {
		convert_to_array(t4);
		phalcon_array_update(&t3, c, &t4, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t4) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_array_fetch(&t5, t4, d, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t5) > 1) {
		phalcon_array_update(&t4, d, &t5, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t5) != IS_ARRAY) {
		convert_to_array(t5);
		phalcon_array_update(&t4, d, &t5, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t5) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t6);
		phalcon_array_fetch(&t6, t5, e, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t6) > 1) {
		phalcon_array_update(&t5, e, &t6, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t6) != IS_ARRAY) {
		convert_to_array(t6);
		phalcon_array_update(&t5, e, &t6, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t6) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t7);
		phalcon_array_fetch(&t7, t6, f, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t7) > 1) {
		phalcon_array_update(&t6, f, &t7, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t7) != IS_ARRAY) {
		convert_to_array(t7);
		phalcon_array_update(&t6, f, &t7, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t7) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t8);
		phalcon_array_fetch(&t8, t7, g, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t8) > 1) {
		phalcon_array_update(&t7, g, &t8, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t8) != IS_ARRAY) {
		convert_to_array(t8);
		phalcon_array_update(&t7, g, &t8, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	phalcon_array_update(&t8, h, &t2, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(a);
}

PHP_METHOD(Phalcon_Internal_Test, a22){

	zval *a = NULL, *b = NULL, *e = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, "222", strlen("222"), 1);
	PHALCON_CPY_WRT(a, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_next_index_stringl(a1, "222", strlen("222"), 1);
	add_next_index_stringl(a1, "kdkdk", strlen("kdkdk"), 1);
	PHALCON_CPY_WRT(b, a1);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, a, b TSRMLS_CC);
	phalcon_array_append(&a2, r0, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_add_function(r1, b, a TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_add_function(r2, r1, a TSRMLS_CC);
	phalcon_array_append(&a2, r2, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	PHALCON_CPY_WRT(e, a2);
	
	PHALCON_RETURN_CTOR(e);
}

PHP_METHOD(Phalcon_Internal_Test, a23){

	zval *f = NULL, *e = NULL, *v = NULL, *k = NULL, *sv = NULL, *sk = NULL, *p = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(f, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	add_assoc_stringl_ex(a2, "baseuri", strlen("baseuri")+1, "/phalcon/", strlen("/phalcon/"), 1);
	phalcon_array_update_string(&a1, "phalcon", strlen("phalcon"), &a2, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	add_assoc_stringl_ex(a3, "metadata", strlen("metadata")+1, "memory", strlen("memory"), 1);
	phalcon_array_update_string(&a1, "models", strlen("models"), &a3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	add_assoc_stringl_ex(a4, "adapter", strlen("adapter")+1, "mysql", strlen("mysql"), 1);
	add_assoc_stringl_ex(a4, "host", strlen("host")+1, "localhost", strlen("localhost"), 1);
	add_assoc_stringl_ex(a4, "username", strlen("username")+1, "user", strlen("user"), 1);
	add_assoc_stringl_ex(a4, "password", strlen("password")+1, "passwd", strlen("passwd"), 1);
	add_assoc_stringl_ex(a4, "name", strlen("name")+1, "demo", strlen("demo"), 1);
	phalcon_array_update_string(&a1, "database", strlen("database"), &a4, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(a5);
	array_init(a5);
	add_assoc_long_ex(a5, "parent.property", strlen("parent.property")+1, 1);
	add_assoc_stringl_ex(a5, "parent.property2", strlen("parent.property2")+1, "yeah", strlen("yeah"), 1);
	phalcon_array_update_string(&a1, "test", strlen("test"), &a5, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_CPY_WRT(e, a1);
	if (phalcon_valid_foreach(e TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(e);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_11:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_11;
		} else {
			PHALCON_INIT_VAR(k);
			hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
			if (hash_type == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(k, hash_index, hash_index_len-1, 1);
			} else {
				if (hash_type == HASH_KEY_IS_LONG) {
					ZVAL_LONG(k, hash_num);
				}
			}
		}
		PHALCON_INIT_VAR(v);
		ZVAL_ZVAL(v, *hd, 1, 0);
		if (Z_TYPE_P(v) == IS_ARRAY) { 
			if (phalcon_valid_foreach(v TSRMLS_CC)) {
				ah1 = Z_ARRVAL_P(v);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_fdd7_12:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee_fdd7_12;
				} else {
					PHALCON_INIT_VAR(sk);
					hash_type = zend_hash_get_current_key_ex(ah1, &hash_index, &hash_index_len, &hash_num, 0, &hp1);
					if (hash_type == HASH_KEY_IS_STRING) {
						ZVAL_STRINGL(sk, hash_index, hash_index_len-1, 1);
					} else {
						if (hash_type == HASH_KEY_IS_LONG) {
							ZVAL_LONG(sk, hash_num);
						}
					}
				}
				PHALCON_INIT_VAR(sv);
				ZVAL_ZVAL(sv, *hd, 1, 0);
				if (Z_TYPE_P(f) == IS_ARRAY) {
					PHALCON_INIT_VAR(t0);
					phalcon_array_fetch(&t0, f, k, PHALCON_SILENT TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t0) > 1) {
					phalcon_array_update(&f, k, &t0, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
				}
				if (Z_TYPE_P(t0) != IS_ARRAY) {
					convert_to_array(t0);
					phalcon_array_update(&f, k, &t0, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				}
				phalcon_array_update(&t0, sk, &sv, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_fdd7_12;
				fee_fdd7_12:
				if(0){ };
			}
		} else {
			PHALCON_INIT_VAR(r0);
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, ".", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r0, "strpos", c0, v, 0x00E);
			if (Z_TYPE_P(r0) != IS_BOOL || (Z_TYPE_P(r0) == IS_BOOL && Z_BVAL_P(r0))) {
				PHALCON_INIT_VAR(r1);
				PHALCON_INIT_VAR(c1);
				ZVAL_STRING(c1, ".", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r1, "explode", c1, v, 0x009);
				PHALCON_CPY_WRT(p, r1);
				
				PHALCON_INIT_VAR(r2);
				phalcon_array_fetch_long(&r2, p, 1, PHALCON_NOISY TSRMLS_CC);
				if (Z_TYPE_P(f) == IS_ARRAY) {
					PHALCON_INIT_VAR(t1);
					phalcon_array_fetch(&t1, f, k, PHALCON_SILENT TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t1) > 1) {
					phalcon_array_update(&f, k, &t1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
				}
				if (Z_TYPE_P(t1) != IS_ARRAY) {
					convert_to_array(t1);
					phalcon_array_update(&f, k, &t1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				}
				
				PHALCON_INIT_VAR(r3);
				phalcon_array_fetch_long(&r3, p, 0, PHALCON_NOISY TSRMLS_CC);
				phalcon_array_update(&t1, r3, &r2, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			} else {
				phalcon_array_update(&f, k, &v, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_11;
		fee_fdd7_11:
		if(0){ };
	}
	
	PHALCON_RETURN_CTOR(f);
}

PHP_METHOD(Phalcon_Internal_Test, a24){

	zval *num = NULL, *e = NULL, *p = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &num) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_array_append(&a0, num, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	PHALCON_CPY_WRT(e, a0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "hello, ", num);
	PHALCON_CPY_WRT(p, r0);
	
	PHALCON_RETURN_CTOR(p);
}

PHP_METHOD(Phalcon_Internal_Test, a25){

	zval *a = NULL, *b = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a);
	ZVAL_STRING(a, "h", 1);
	PHALCON_INIT_VAR(b);
	ZVAL_STRING(b, "k", 1);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_assoc_stringl_ex(a0, "k", strlen("k")+1, "v", strlen("v"), 1);
	add_assoc_stringl_ex(a0, "i", strlen("i")+1, "d", strlen("d"), 1);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY TSRMLS_CC);
	if (Z_TYPE_P(t0) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_array_fetch(&t1, t0, a, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t1) > 1) {
		phalcon_array_update(&t0, a, &t1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t1) != IS_ARRAY) {
		convert_to_array(t1);
		phalcon_array_update(&t0, a, &t1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	phalcon_array_update(&t1, b, &a0, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), t0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t2);
}

PHP_METHOD(Phalcon_Internal_Test, a26){

	zval *a = NULL, *i = NULL, *e = NULL, *f = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 0);
	add_next_index_long(a0, 1);
	PHALCON_CPY_WRT(a, a0);
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	fs_fdd7_13:
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, i, t0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_fdd7_13;
		}
		PHALCON_INIT_VAR(r1);
		phalcon_array_fetch_long(&r1, a, 0, PHALCON_NOISY TSRMLS_CC);
		PHALCON_SEPARATE_NMO(r1);
		decrement_function(r1);
		phalcon_array_update_long(&a, 0, &r1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		PHALCON_CPY_WRT(e, r1);
		
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch_long(&r2, a, 1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_SEPARATE_NMO(r2);
		
		PHALCON_INIT_VAR(t1);
		ZVAL_ZVAL(t1, r2, 1, 0);
		increment_function(r2);
		phalcon_array_update_long(&a, 1, &r2, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		PHALCON_CPY_WRT(f, t1);
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto fs_fdd7_13;
	fe_fdd7_13:
	
	PHALCON_RETURN_CTOR(a);
}

PHP_METHOD(Phalcon_Internal_Test, sa0){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, sa1){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sa2){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	add_next_index_stringl(a0, "lol", strlen("lol"), 1);
	zend_update_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, sa3){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sa4){

	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	t0 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		convert_to_array(t0);
	}
	phalcon_array_append(&t0, a1, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, t0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(t1);
	ZVAL_STRING(t1, "more-loose", 1);
	t2 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t2) != IS_ARRAY) {
		convert_to_array(t2);
	}
	if (Z_TYPE_P(t2) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_array_fetch_long(&t3, t2, 0, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t3) > 1) {
		phalcon_array_update_long(&t2, 0, &t3, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t3) != IS_ARRAY) {
		convert_to_array(t3);
		phalcon_array_update_long(&t2, 0, &t3, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	phalcon_array_append(&t3, t1, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, t2 TSRMLS_CC);
	
	PHALCON_INIT_VAR(t4);
	ZVAL_STRING(t4, "yeah, more-loose", 1);
	t5 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t5) != IS_ARRAY) {
		convert_to_array(t5);
	}
	if (Z_TYPE_P(t5) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t6);
		phalcon_array_fetch_long(&t6, t5, 0, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t6) > 1) {
		phalcon_array_update_long(&t5, 0, &t6, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t6) != IS_ARRAY) {
		convert_to_array(t6);
		phalcon_array_update_long(&t5, 0, &t6, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	phalcon_array_update_long(&t6, 0, &t4, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, t5 TSRMLS_CC);
	
	t7 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t7);
}

PHP_METHOD(Phalcon_Internal_Test, sa5){

	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "loose", 1);
	t1 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t1) != IS_ARRAY) {
		convert_to_array(t1);
	}
	if (Z_TYPE_P(t1) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_array_fetch_long(&t2, t1, 1, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t2) > 1) {
		phalcon_array_update_long(&t1, 1, &t2, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t2) != IS_ARRAY) {
		convert_to_array(t2);
		phalcon_array_update_long(&t1, 1, &t2, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t2) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_array_fetch_long(&t3, t2, 2, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t3) > 1) {
		phalcon_array_update_long(&t2, 2, &t3, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t3) != IS_ARRAY) {
		convert_to_array(t3);
		phalcon_array_update_long(&t2, 2, &t3, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	phalcon_array_update_long(&t3, 3, &t0, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, t1 TSRMLS_CC);
	
	t4 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_INIT_VAR(t8);
	ZVAL_LONG(t8, 1);
	
	PHALCON_ALLOC_ZVAL_MM(t7);
	phalcon_array_fetch(&t7, t4, t8, PHALCON_NOISY TSRMLS_CC);
	PHALCON_INIT_VAR(t9);
	ZVAL_LONG(t9, 2);
	
	PHALCON_ALLOC_ZVAL_MM(t6);
	phalcon_array_fetch(&t6, t7, t9, PHALCON_NOISY TSRMLS_CC);
	PHALCON_INIT_VAR(t10);
	ZVAL_LONG(t10, 3);
	
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_array_fetch(&t5, t6, t10, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t5);
}

PHP_METHOD(Phalcon_Internal_Test, sa6){

	zval *e = NULL, *v = NULL, *k = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	add_next_index_long(a1, 4);
	add_next_index_long(a1, 5);
	PHALCON_CPY_WRT(e, a1);
	if (phalcon_valid_foreach(e TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(e);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_14:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_14;
		} else {
			PHALCON_INIT_VAR(k);
			hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
			if (hash_type == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(k, hash_index, hash_index_len-1, 1);
			} else {
				if (hash_type == HASH_KEY_IS_LONG) {
					ZVAL_LONG(k, hash_num);
				}
			}
		}
		PHALCON_INIT_VAR(v);
		ZVAL_ZVAL(v, *hd, 1, 0);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 2);
		PHALCON_INIT_VAR(r0);
		mul_function(r0, k, t0 TSRMLS_CC);
		PHALCON_CPY_WRT(k, r0);
		
		PHALCON_INIT_VAR(r1);
		phalcon_add_function(r1, v, k TSRMLS_CC);
		t1 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (Z_TYPE_P(t1) != IS_ARRAY) {
			convert_to_array(t1);
		}
		phalcon_array_update(&t1, k, &r1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		zend_update_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, t1 TSRMLS_CC);
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_14;
		fee_fdd7_14:
		if(0){ };
	}
	t2 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t2);
}

PHP_METHOD(Phalcon_Internal_Test, sa7){

	zval *e = NULL, *v = NULL, *k = NULL, *sv = NULL, *sk = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	add_assoc_stringl_ex(a2, "in", strlen("in")+1, "out", strlen("out"), 1);
	phalcon_array_update_string(&a1, "hello", strlen("hello"), &a2, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	add_assoc_stringl_ex(a3, "file", strlen("file")+1, "type", strlen("type"), 1);
	add_assoc_stringl_ex(a3, "php", strlen("php")+1, "unix", strlen("unix"), 1);
	add_assoc_stringl_ex(a3, "tab", strlen("tab")+1, "ins", strlen("ins"), 1);
	phalcon_array_update_string(&a1, "bye", strlen("bye"), &a3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	phalcon_array_update_string(&a1, "encoding", strlen("encoding"), &a4, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	add_assoc_stringl_ex(a1, "sucks", strlen("sucks")+1, "yes", strlen("yes"), 1);
	PHALCON_CPY_WRT(e, a1);
	if (phalcon_valid_foreach(e TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(e);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_15:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_15;
		} else {
			PHALCON_INIT_VAR(k);
			hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
			if (hash_type == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(k, hash_index, hash_index_len-1, 1);
			} else {
				if (hash_type == HASH_KEY_IS_LONG) {
					ZVAL_LONG(k, hash_num);
				}
			}
		}
		PHALCON_INIT_VAR(v);
		ZVAL_ZVAL(v, *hd, 1, 0);
		if (Z_TYPE_P(v) == IS_ARRAY) { 
			if (phalcon_valid_foreach(v TSRMLS_CC)) {
				ah1 = Z_ARRVAL_P(v);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_fdd7_16:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee_fdd7_16;
				} else {
					PHALCON_INIT_VAR(sk);
					hash_type = zend_hash_get_current_key_ex(ah1, &hash_index, &hash_index_len, &hash_num, 0, &hp1);
					if (hash_type == HASH_KEY_IS_STRING) {
						ZVAL_STRINGL(sk, hash_index, hash_index_len-1, 1);
					} else {
						if (hash_type == HASH_KEY_IS_LONG) {
							ZVAL_LONG(sk, hash_num);
						}
					}
				}
				PHALCON_INIT_VAR(sv);
				ZVAL_ZVAL(sv, *hd, 1, 0);
				t0 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
				if (Z_TYPE_P(t0) != IS_ARRAY) {
					convert_to_array(t0);
				}
				if (Z_TYPE_P(t0) == IS_ARRAY) {
					PHALCON_INIT_VAR(t1);
					phalcon_array_fetch(&t1, t0, k, PHALCON_SILENT TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t1) > 1) {
					phalcon_array_update(&t0, k, &t1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
				}
				if (Z_TYPE_P(t1) != IS_ARRAY) {
					convert_to_array(t1);
					phalcon_array_update(&t0, k, &t1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				}
				phalcon_array_update(&t1, sk, &sv, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				zend_update_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, t0 TSRMLS_CC);
				
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_fdd7_16;
				fee_fdd7_16:
				if(0){ };
			}
		} else {
			t2 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			if (Z_TYPE_P(t2) != IS_ARRAY) {
				convert_to_array(t2);
			}
			phalcon_array_update(&t2, k, &v, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			zend_update_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, t2 TSRMLS_CC);
			
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_15;
		fee_fdd7_15:
		if(0){ };
	}
	t3 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t3);
}

PHP_METHOD(Phalcon_Internal_Test, c1){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_RETURN_NCTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, c2){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_INIT_VAR(r0);
	is_not_equal_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_RETURN_NCTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, c3){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_INIT_VAR(r0);
	is_smaller_or_equal_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_RETURN_NCTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, c4){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_INIT_VAR(r0);
	is_smaller_or_equal_function(r0, t1, t0 TSRMLS_CC);
	
	PHALCON_RETURN_NCTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, c5){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_INIT_VAR(r0);
	is_smaller_function(r0, t1, t0 TSRMLS_CC);
	
	PHALCON_RETURN_NCTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, c6){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_INIT_VAR(r0);
	is_smaller_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_RETURN_NCTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, c7){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 1);
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 1);
	PHALCON_INIT_VAR(r1);
	is_smaller_or_equal_function(r1, t2, t3 TSRMLS_CC);
	PHALCON_INIT_VAR(r2);
	phalcon_and_function(r2, r0, r1);
	
	PHALCON_RETURN_NCTOR(r2);
}

PHP_METHOD(Phalcon_Internal_Test, c8){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_INIT_VAR(r0);
	is_not_equal_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 1);
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 1);
	PHALCON_INIT_VAR(r1);
	is_smaller_function(r1, t2, t3 TSRMLS_CC);
	PHALCON_INIT_VAR(r2);
	phalcon_and_function(r2, r0, r1);
	
	PHALCON_RETURN_NCTOR(r2);
}

PHP_METHOD(Phalcon_Internal_Test, c9){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	boolean_not_function(r0, t0 TSRMLS_CC);
	
	PHALCON_RETURN_NCTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, c10){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_INIT_VAR(r1);
	is_not_equal_function(r1, t0, t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	boolean_not_function(r0, r1 TSRMLS_CC);
	
	PHALCON_RETURN_NCTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, c11){

	zval *a = NULL, *b = NULL, *c = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &a, &b, &c) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, b, c TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, a, r0 TSRMLS_CC);
	
	PHALCON_RETURN_NCTOR(r1);
}

PHP_METHOD(Phalcon_Internal_Test, f1){

	zval *r0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "LOL", 1);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "strlen", c0, 0x001);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, f2){

	zval *r0 = NULL;
	zval *c0 = NULL, *c1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "hello\t", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "\t", 1);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "rtrim", c0, c1, 0x021);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, f3){

	zval *r0 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "bb", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "xx", 1);
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "aabbcc", 1);
	PHALCON_CALL_FUNC_PARAMS_3(r0, "str_replace", c0, c1, c2, 0x003);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, f4){

	zval *r0 = NULL, *r1 = NULL;
	zval *c0 = NULL, *c1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "deux", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "deux", 1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "strlen", c1, 0x001);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "str_repeat", c0, r1, 0x022);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, f5){

	zval *e = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, "b", strlen("b"), 1);
	add_next_index_stringl(a0, "c", strlen("c"), 1);
	add_next_index_stringl(a0, "a", strlen("a"), 1);
	PHALCON_CPY_WRT(e, a0);
	Z_SET_ISREF_P(e);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("asort", e, 0x023);
	Z_UNSET_ISREF_P(e);
	
	PHALCON_RETURN_CTOR(e);
}

PHP_METHOD(Phalcon_Internal_Test, f6){

	zval *file = NULL, *fp = NULL, *content = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_LONG(c0, 0);
	PHALCON_INIT_VAR(c1);
	ZVAL_LONG(c1, 100);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "mt_rand", c0, c1, 0x024);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CONCAT_RIGHT(r1, r0, ".txt");
	PHALCON_CPY_WRT(file, r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "w", 1);
	PHALCON_CALL_FUNC_PARAMS_2(r2, "fopen", file, c2, 0x025);
	PHALCON_CPY_WRT(fp, r2);
	PHALCON_INIT_VAR(c3);
	ZVAL_STRING(c3, "morelol\n", 1);
	PHALCON_CALL_FUNC_PARAMS_2_NORETURN("fwrite", fp, c3, 0x026);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("fclose", fp, 0x027);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_FUNC_PARAMS_1(r3, "file_get_contents", file, 0x01A);
	PHALCON_CPY_WRT(content, r3);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("unlink", file, 0x028);
	
	PHALCON_RETURN_CHECK_CTOR(content);
}

PHP_METHOD(Phalcon_Internal_Test, f7){

	zval *r0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_DOUBLE(c0, 3.14159);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "sqrt", c0, 0x029);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, f8){

	zval *r0 = NULL;
	zval *a0 = NULL;
	zval *c0 = NULL, *c1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, ".", strlen("."), 1);
	add_next_index_stringl(a0, ",", strlen(","), 1);
	add_next_index_stringl(a0, "-", strlen("-"), 1);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "&", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "-.,-.,", 1);
	PHALCON_CALL_FUNC_PARAMS_3(r0, "str_replace", a0, c0, c1, 0x003);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, f9){

	zval *e = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "-1000", 1);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 400);
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_INIT_VAR(t2);
	ZVAL_BOOL(t2, 0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	mul_function(r1, r0, t2 TSRMLS_CC);
	PHALCON_CPY_WRT(e, r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_FUNC_PARAMS_1(r2, "abs", e, 0x02A);
	PHALCON_RETURN_DZVAL(r2);
}

PHP_METHOD(Phalcon_Internal_Test, f10){

	zval *a = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	PHALCON_CPY_WRT(a, a0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_long(&r1, a, 0, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_numeric", r1, 0x02B);
	if (zend_is_true(r0)) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, m1){


	PHALCON_MM_GROW();
	PHALCON_MM_RESTORE();
	RETURN_STRING("private", 1);
}

PHP_METHOD(Phalcon_Internal_Test, m2){


	PHALCON_MM_GROW();
	PHALCON_MM_RESTORE();
	RETURN_STRING("protected", 1);
}

PHP_METHOD(Phalcon_Internal_Test, m3){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "m1", PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, m4){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "m2", PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, m5){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "m2", PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, this_ptr, "m1", PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, r0, r1 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r2);
}

PHP_METHOD(Phalcon_Internal_Test, m6){

	zval *a = NULL, *b = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, a, b TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, m7){

	zval *a = NULL, *b = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, this_ptr, "m6", a, b, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, m8){

	zval *a = NULL, *b = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, this_ptr, "m6", a, b, PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_2(r1, this_ptr, "m6", a, b, PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, r0, r1 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r2);
}

PHP_METHOD(Phalcon_Internal_Test, m9){

	zval *a = NULL, *b = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, a, b TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, m10){

	zval *a = NULL, *b = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, this_ptr, "m9", a, b, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, m11){

	zval *a = NULL, *b = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, this_ptr, "m10", a, b, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, m12){

	zval *a = NULL, *b = NULL, *d = NULL, *c = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(d);
	ZVAL_LONG(d, 0);
	PHALCON_INIT_VAR(c);
	ZVAL_LONG(c, 0);
	fs_fdd7_17:
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, c, t0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_fdd7_17;
		}
		PHALCON_INIT_VAR(r1);
		PHALCON_INIT_VAR(r2);
		phalcon_add_function(r2, c, a TSRMLS_CC);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 1);
		PHALCON_INIT_VAR(r3);
		phalcon_add_function(r3, c, t1 TSRMLS_CC);
		PHALCON_INIT_VAR(r4);
		phalcon_add_function(r4, b, r3 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_2(r1, this_ptr, "m9", r2, r4, PHALCON_NO_CHECK);
		PHALCON_INIT_VAR(r5);
		phalcon_add_function(r5, d, r1 TSRMLS_CC);
		PHALCON_CPY_WRT(d, r5);
		PHALCON_SEPARATE(c);
		increment_function(c);
		goto fs_fdd7_17;
	fe_fdd7_17:
	
	PHALCON_RETURN_CTOR(d);
}

PHP_METHOD(Phalcon_Internal_Test, m13){

	zval *a = NULL, *b = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(a);
	
	PHALCON_INIT_VAR(a);
	ZVAL_LONG(a, 100);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 10);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, b, t0 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, m14){

	zval *a = NULL, *b = NULL, *f = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, this_ptr, "m13", a, b, PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r1);
	mul_function(r1, r0, a TSRMLS_CC);
	PHALCON_CPY_WRT(f, r1);
	
	PHALCON_RETURN_CTOR(f);
}

PHP_METHOD(Phalcon_Internal_Test, m15){

	zval *a = NULL, *b = NULL, *f = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, this_ptr, "m13", a, b, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(f, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	mul_function(r1, f, a TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r1);
}

PHP_METHOD(Phalcon_Internal_Test, mp3){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "mp1", PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, mp4){

	zval *a = NULL, *b = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, this_ptr, "mp2", a, b, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, mp5){

	zval *o = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_internal_testparent_ce);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
	PHALCON_CPY_WRT(o, i0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, o, "mp1", PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, mp6){

	zval *a = NULL, *b = NULL, *o = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_internal_testparent_ce);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
	PHALCON_CPY_WRT(o, i0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, o, "mp2", a, b, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, sm1){


	PHALCON_MM_GROW();
	PHALCON_MM_RESTORE();
	RETURN_STRING("private", 1);
}

PHP_METHOD(Phalcon_Internal_Test, sm2){


	PHALCON_MM_GROW();
	PHALCON_MM_RESTORE();
	RETURN_STRING("protected", 1);
}

PHP_METHOD(Phalcon_Internal_Test, sm3){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF(r0, this_ptr, "sm1");
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, sm4){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF(r0, this_ptr, "sm2");
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, sm5){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF(r0, this_ptr, "sm2");
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_SELF(r1, this_ptr, "sm1");
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, r0, r1 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r2);
}

PHP_METHOD(Phalcon_Internal_Test, sm6){

	zval *a = NULL, *b = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, a, b TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, sm7){

	zval *a = NULL, *b = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "sm6", a, b);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, sm8){

	zval *a = NULL, *b = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, a, b TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, sm9){

	zval *a = NULL, *b = NULL, *d = NULL, *c = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(d);
	ZVAL_LONG(d, 0);
	PHALCON_INIT_VAR(c);
	ZVAL_LONG(c, 0);
	fs_fdd7_18:
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, c, t0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_fdd7_18;
		}
		PHALCON_INIT_VAR(r1);
		PHALCON_INIT_VAR(r2);
		phalcon_add_function(r2, c, a TSRMLS_CC);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 1);
		PHALCON_INIT_VAR(r3);
		phalcon_add_function(r3, c, t1 TSRMLS_CC);
		PHALCON_INIT_VAR(r4);
		phalcon_add_function(r4, b, r3 TSRMLS_CC);
		PHALCON_CALL_SELF_PARAMS_2(r1, this_ptr, "sm8", r2, r4);
		PHALCON_INIT_VAR(r5);
		phalcon_add_function(r5, d, r1 TSRMLS_CC);
		PHALCON_CPY_WRT(d, r5);
		PHALCON_SEPARATE(c);
		increment_function(c);
		goto fs_fdd7_18;
	fe_fdd7_18:
	
	PHALCON_RETURN_CTOR(d);
}

PHP_METHOD(Phalcon_Internal_Test, sm10){

	zval *a = NULL, *b = NULL, *d = NULL, *c = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(d);
	ZVAL_LONG(d, 0);
	PHALCON_INIT_VAR(c);
	ZVAL_LONG(c, 0);
	fs_fdd7_19:
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, c, t0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_fdd7_19;
		}
		PHALCON_INIT_VAR(r1);
		PHALCON_INIT_VAR(r2);
		phalcon_add_function(r2, c, a TSRMLS_CC);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 1);
		PHALCON_INIT_VAR(r3);
		phalcon_add_function(r3, c, t1 TSRMLS_CC);
		PHALCON_INIT_VAR(r4);
		phalcon_add_function(r4, b, r3 TSRMLS_CC);
		PHALCON_CALL_STATIC_PARAMS_2(r1, "phalcon_internal_test", "sm8", r2, r4);
		PHALCON_INIT_VAR(r5);
		phalcon_add_function(r5, d, r1 TSRMLS_CC);
		PHALCON_CPY_WRT(d, r5);
		PHALCON_SEPARATE(c);
		increment_function(c);
		goto fs_fdd7_19;
	fe_fdd7_19:
	
	PHALCON_RETURN_CTOR(d);
}

PHP_METHOD(Phalcon_Internal_Test, sm11){

	zval *method = NULL, *class = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(method);
	ZVAL_STRING(method, "sm2", 1);
	PHALCON_INIT_VAR(class);
	ZVAL_STRING(class, "Phalcon_Internal_Test", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_ZVAL_STATIC(r0, class, "sm2");
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, smp2){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF(r0, this_ptr, "smp1");
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, smp4){

	zval *a = NULL, *b = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_PARENT_PARAMS_2(r0, this_ptr, "Phalcon_Internal_Test", "smp3", b, a);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, smp5){

	zval *a = NULL, *b = NULL, *d = NULL, *c = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(d);
	ZVAL_LONG(d, 0);
	PHALCON_INIT_VAR(c);
	ZVAL_LONG(c, 0);
	fs_fdd7_20:
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, c, t0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_fdd7_20;
		}
		PHALCON_INIT_VAR(r1);
		PHALCON_INIT_VAR(r2);
		phalcon_add_function(r2, c, a TSRMLS_CC);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 1);
		PHALCON_INIT_VAR(r3);
		phalcon_add_function(r3, c, t1 TSRMLS_CC);
		PHALCON_INIT_VAR(r4);
		phalcon_add_function(r4, b, r3 TSRMLS_CC);
		PHALCON_CALL_STATIC_PARAMS_2(r1, "phalcon_internal_test", "smp3", r2, r4);
		PHALCON_INIT_VAR(r5);
		phalcon_add_function(r5, d, r1 TSRMLS_CC);
		PHALCON_CPY_WRT(d, r5);
		PHALCON_SEPARATE(c);
		increment_function(c);
		goto fs_fdd7_20;
	fe_fdd7_20:
	
	PHALCON_RETURN_CTOR(d);
}

PHP_METHOD(Phalcon_Internal_Test, p1){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p1", sizeof("_p1")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p2){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p2", sizeof("_p2")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p3){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p3", sizeof("_p3")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p4){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p4", sizeof("_p4")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p5){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p5", sizeof("_p5")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p6){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p6", sizeof("_p6")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p7){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p7", sizeof("_p7")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p8){


	PHALCON_MM_GROW();
	phalcon_update_property_string(this_ptr, "_p0", strlen("_p0"), "more-lol" TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, p9){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p10){


	PHALCON_MM_GROW();
	phalcon_update_property_long(this_ptr, "_p0", strlen("_p0"), 14750 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, p11){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p12){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p1", sizeof("_p1")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_p2", sizeof("_p2")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_p3", sizeof("_p3")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	concat_function(r1, r0, t2 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r1);
}

PHP_METHOD(Phalcon_Internal_Test, p13){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p4", sizeof("_p4")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_p5", sizeof("_p5")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_p6", sizeof("_p6")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_add_function(r1, r0, t2 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r1);
}

PHP_METHOD(Phalcon_Internal_Test, p14){

	zval *data = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, data TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_p0", strlen("_p0"), r0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, p15){

	zval *i = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	phalcon_update_property_string(this_ptr, "_p0", strlen("_p0"), "" TSRMLS_CC);
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	fs_fdd7_21:
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 30);
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, i, t0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_fdd7_21;
		}
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "p14", i, PHALCON_NO_CHECK);
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto fs_fdd7_21;
	fe_fdd7_21:
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p16){

	zval *p = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(p);
	ZVAL_STRING(p, "_p0", 1);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "lol", 1);
	phalcon_update_property_zval(this_ptr, Z_STRVAL_P(p), Z_STRLEN_P(p), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, p17){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p18){

	zval *p = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(p);
	ZVAL_STRING(p, "_p0", 1);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property_zval(&t0, this_ptr, p, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p19){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p8", sizeof("_p8")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p20){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "hello", 1);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_p8", sizeof("_p8")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_array_append(&t1, t0, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_p8", strlen("_p8"), t1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_p8", sizeof("_p8")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t2);
}

PHP_METHOD(Phalcon_Internal_Test, p21){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p22){

	zval *a = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &a) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_array_append(&t0, a, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), t0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p23){

	zval *a = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &a) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), a TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p24){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t0);
	increment_function(t0);
	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), t0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p25){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t0);
	decrement_function(t0);
	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), t0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p26){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t0);
	increment_function(t0);
	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), t0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p27){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t0);
	decrement_function(t0);
	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), t0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p28){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	ZVAL_ZVAL(t1, t0, 1, 0);
	increment_function(t0);
	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), t0 TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p29){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	ZVAL_ZVAL(t1, t0, 1, 0);
	decrement_function(t0);
	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), t0 TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, sp1){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_internal_test_ce, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp2){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_internal_test_ce, "_sp2", sizeof("_sp2")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp3){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_internal_test_ce, "_sp3", sizeof("_sp3")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp4){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_internal_test_ce, "_sp4", sizeof("_sp4")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp5){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_internal_test_ce, "_sp5", sizeof("_sp5")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp6){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_internal_test_ce, "_sp6", sizeof("_sp6")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp7){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_internal_test_ce, "_sp7", sizeof("_sp7")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp8){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "i can't handle anymore", 1);
	zend_update_static_property(phalcon_internal_test_ce, "_sp1", sizeof("_sp1")-1, t0 TSRMLS_CC);
	t1 = zend_read_static_property(phalcon_internal_test_ce, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, sp9){

	zval *a = NULL, *b = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, a, b TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_ce, "_sp1", sizeof("_sp1")-1, r0 TSRMLS_CC);
	t0 = zend_read_static_property(phalcon_internal_test_ce, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp10){

	zval *a = NULL, *b = NULL, *c = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &a, &b, &c) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	zend_update_static_property(phalcon_internal_test_ce, "_sp1", sizeof("_sp1")-1, a TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_ce, "_sp2", sizeof("_sp2")-1, b TSRMLS_CC);
	t0 = zend_read_static_property(phalcon_internal_test_ce, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	t1 = zend_read_static_property(phalcon_internal_test_ce, "_sp2", sizeof("_sp2")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_add_function(r1, r0, c TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_ce, "_sp3", sizeof("_sp3")-1, r1 TSRMLS_CC);
	t2 = zend_read_static_property(phalcon_internal_test_ce, "_sp3", sizeof("_sp3")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t2);
}

PHP_METHOD(Phalcon_Internal_Test, sp11){

	zval *a = NULL, *b = NULL, *c = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &a, &b, &c) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	zend_update_static_property(phalcon_internal_test_ce, "_sp1", sizeof("_sp1")-1, a TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_ce, "_sp2", sizeof("_sp2")-1, b TSRMLS_CC);
	t0 = zend_read_static_property(phalcon_internal_test_ce, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	t1 = zend_read_static_property(phalcon_internal_test_ce, "_sp2", sizeof("_sp2")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_add_function(r1, r0, c TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_ce, "_sp3", sizeof("_sp3")-1, r1 TSRMLS_CC);
	t2 = zend_read_static_property(phalcon_internal_test_ce, "_sp3", sizeof("_sp3")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t2);
}

PHP_METHOD(Phalcon_Internal_Test, cc1){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_ce, "C1", strlen("C1") TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, cc2){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_ce, "C2", strlen("C2") TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, cc3){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_ce, "C3", strlen("C3") TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, cc4){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_ce, "C4", strlen("C4") TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, cc5){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_ce, "C5", strlen("C5") TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, cc6){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_ce, "C6", strlen("C6") TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, is1){

	zval *a = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_bool(a0, 0);
	PHALCON_CPY_WRT(a, a0);
	eval_int = phalcon_array_isset_long(a, 0);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, is2){

	zval *a = NULL;
	zval *i0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(a, i0);
	phalcon_update_property_long(a, "b", strlen("b"), 15 TSRMLS_CC);
	eval_int = phalcon_isset_property(a, "b", strlen("b") TSRMLS_CC);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, is3){

	zval *a = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(a, a0);
	eval_int = phalcon_array_isset_long(a, 0);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, is4){

	zval *a = NULL;
	zval *i0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(a, i0);
	phalcon_update_property_long(a, "c", strlen("c"), 10 TSRMLS_CC);
	eval_int = phalcon_isset_property(a, "b", strlen("b") TSRMLS_CC);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, is5){

	zval *a = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(a, a0);
	eval_int = phalcon_array_isset_long(a, 0);
	if (!eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, is6){

	zval *a = NULL;
	zval *i0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(a, i0);
	phalcon_update_property_long(a, "c", strlen("c"), 10 TSRMLS_CC);
	eval_int = phalcon_isset_property(a, "b", strlen("b") TSRMLS_CC);
	if (!eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, is7){

	zval *a = NULL, *t = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, "hello", strlen("hello"), 1);
	PHALCON_CPY_WRT(a, a0);
	PHALCON_INIT_VAR(t);
	ZVAL_LONG(t, 0);
	eval_int = phalcon_array_isset(a, t);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, is8){

	zval *config = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(config, i0);
	phalcon_update_property_string(config, "host", strlen("host"), "192.168.0.20" TSRMLS_CC);
	phalcon_update_property_string(config, "username", strlen("username"), "support" TSRMLS_CC);
	phalcon_update_property_string(config, "password", strlen("password"), "H45pov682v" TSRMLS_CC);
	phalcon_update_property_string(config, "name", strlen("name"), "demo" TSRMLS_CC);
	eval_int = phalcon_isset_property(config, "host", strlen("host") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, config, "host", sizeof("host")-1, PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_RETURN_CHECK_CTOR(t0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, is9){

	zval *a = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_index_stringl(a1, 1, "hello", strlen("hello"), 1);
	phalcon_array_append(&a0, a1, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	add_next_index_bool(a0, 0);
	PHALCON_CPY_WRT(a, a0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, a, 0, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset_long(r0, 0);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, is10){

	zval *a = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_index_stringl(a1, 1, "hello", strlen("hello"), 1);
	phalcon_array_append(&a0, a1, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	add_next_index_bool(a0, 0);
	PHALCON_CPY_WRT(a, a0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, a, 0, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset_long(r0, 1);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, is11){

	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_index_stringl(a1, 1, "hello", strlen("hello"), 1);
	phalcon_array_append(&a0, a1, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	add_next_index_bool(a0, 0);
	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), a0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, t0, 0, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset_long(r0, 1);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, is12){

	zval *index = NULL, *another_index = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(index);
	ZVAL_STRING(index, "hello", 1);
	PHALCON_INIT_VAR(another_index);
	ZVAL_STRING(another_index, "lol", 1);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), a0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch(&r0, t0, index, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(r0, another_index);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, un1){

	zval *a = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_bool(a0, 0);
	PHALCON_CPY_WRT(a, a0);
	PHALCON_SEPARATE_PARAM(a);
	phalcon_array_unset_long(a, 0);
	
	PHALCON_RETURN_CTOR(a);
}

PHP_METHOD(Phalcon_Internal_Test, un2){

	zval *a = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_next_index_long(a1, 0);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	phalcon_array_update_string(&a0, "lost", strlen("lost"), &a1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	add_next_index_stringl(a0, "hello", strlen("hello"), 1);
	PHALCON_CPY_WRT(a, a0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, a, "lost", strlen("lost"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_SEPARATE_NMO(r0);
	phalcon_array_unset_long(r0, 1);
	
	PHALCON_RETURN_CTOR(a);
}

PHP_METHOD(Phalcon_Internal_Test, un3){

	zval *b = NULL, *a = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	PHALCON_CPY_WRT(b, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	phalcon_array_append(&a1, b, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	add_next_index_stringl(a1, "hello", strlen("hello"), 1);
	PHALCON_CPY_WRT(a, a1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, a, 0, PHALCON_NOISY TSRMLS_CC);
	PHALCON_SEPARATE_NMO(r0);
	phalcon_array_unset_long(r0, 1);
	
	PHALCON_RETURN_CTOR(b);
}

PHP_METHOD(Phalcon_Internal_Test, iof1){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(r0);
	phalcon_instance_of(r0, this_ptr, phalcon_internal_test_ce TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, iof2){

	zval *a = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(a, i0);
		ce0 = zend_fetch_class("stdclass", strlen("stdclass"), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_INIT_VAR(r0);
	phalcon_instance_of(r0, a, ce0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, iof3){

	zval *a = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_internal_testparent_ce);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
	PHALCON_CPY_WRT(a, i0);
	PHALCON_INIT_VAR(r0);
	phalcon_instance_of(r0, a, phalcon_internal_testparent_ce TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, t1){

	zval *k = NULL, *a = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &k, &a) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(k);
	
	PHALCON_SEPARATE_PARAM(a);
	
	PHALCON_INIT_VAR(k);
	ZVAL_LONG(k, 17);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 100);
	phalcon_array_update_long(&a, 0, &t0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, t2){

	zval *m = NULL, *a = NULL, *v = NULL, *k = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(m);
	ZVAL_STRING(m, "", 1);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	add_next_index_long(a0, 4);
	PHALCON_CPY_WRT(a, a0);
	if (phalcon_valid_foreach(a TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(a);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_22:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_22;
		} else {
			PHALCON_INIT_VAR(k);
			hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
			if (hash_type == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(k, hash_index, hash_index_len-1, 1);
			} else {
				if (hash_type == HASH_KEY_IS_LONG) {
					ZVAL_LONG(k, hash_num);
				}
			}
		}
		PHALCON_INIT_VAR(v);
		ZVAL_ZVAL(v, *hd, 1, 0);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "t1", k, a, PHALCON_NO_CHECK);
		
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch_long(&r0, a, 0, PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_INIT_VAR(r1);
		concat_function(r1, k, r0 TSRMLS_CC);
		
		PHALCON_INIT_VAR(r2);
		concat_function(r2, m, r1 TSRMLS_CC);
		PHALCON_CPY_WRT(m, r2);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_22;
		fee_fdd7_22:
		if(0){ };
	}
	
	PHALCON_RETURN_CTOR(m);
}

PHP_METHOD(Phalcon_Internal_Test, t3){

	zval *a = NULL, *b = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 5);
	PHALCON_ALLOC_ZVAL_MM(r0);
	mod_function(r0, b, t0 TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, r0, t1 TSRMLS_CC);
	if (zend_is_true(r1)) {
		t2 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		
		PHALCON_RETURN_CHECK_CTOR(t2);
	} else {
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 15);
		PHALCON_ALLOC_ZVAL_MM(r2);
		mul_function(r2, b, t3 TSRMLS_CC);
		
		PHALCON_RETURN_CTOR(r2);
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, t4){

	zval *a = NULL, *b = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(b);
	
	PHALCON_INIT_VAR(b);
	ZVAL_LONG(b, 25);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 5);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, a, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_RETURN_CHECK_CTOR(t1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "sqrt", b, 0x029);
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_add_function(r2, r1, a TSRMLS_CC);
		
		PHALCON_RETURN_CTOR(r2);
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, t5){

	zval *a = NULL, *b = NULL, *c = NULL, *node = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &a, &b, &c) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(a);
	
	PHALCON_SEPARATE_PARAM(b);
	
	phalcon_update_property_long(this_ptr, "_p0", strlen("_p0"), 0 TSRMLS_CC);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(node, a0);
	ws_fdd7_23:
		if (0) {
			goto we_fdd7_23;
		}
		PHALCON_INIT_VAR(r0);
		mul_function(r0, a, b TSRMLS_CC);
		zend_update_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, r0 TSRMLS_CC);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		
		PHALCON_INIT_VAR(r1);
		phalcon_add_function(r1, a, t0 TSRMLS_CC);
		PHALCON_CPY_WRT(a, r1);
		
		PHALCON_INIT_VAR(t1);
		phalcon_read_property(&t1, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_INIT_VAR(t2);
		ZVAL_LONG(t2, 2);
		
		PHALCON_INIT_VAR(r2);
		mod_function(r2, t1, t2 TSRMLS_CC);
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 0);
		
		PHALCON_INIT_VAR(r3);
		is_equal_function(r3, r2, t3 TSRMLS_CC);
		if (zend_is_true(r3)) {
			PHALCON_INIT_VAR(r4);
			PHALCON_INIT_VAR(t4);
			ZVAL_LONG(t4, 1);
			PHALCON_INIT_VAR(r5);
			phalcon_add_function(r5, c, t4 TSRMLS_CC);
			t5 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			PHALCON_CALL_SELF_PARAMS_2(r4, this_ptr, "t4", r5, t5);
			phalcon_array_append(&node, r4, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			PHALCON_INIT_VAR(t6);
			ZVAL_LONG(t6, 10);
			phalcon_array_append(&node, t6, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(r6);
			PHALCON_CALL_METHOD_PARAMS_2(r6, this_ptr, "t3", a, b, PHALCON_NO_CHECK);
			phalcon_array_append(&node, r6, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		}
		
		
		PHALCON_INIT_VAR(t7);
		phalcon_read_property(&t7, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_INIT_VAR(t8);
		ZVAL_LONG(t8, 3);
		
		PHALCON_INIT_VAR(r7);
		mul_function(r7, t7, t8 TSRMLS_CC);
		PHALCON_CPY_WRT(b, r7);
		
		PHALCON_INIT_VAR(t9);
		phalcon_read_property(&t9, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_SEPARATE_NMO(t9);
		increment_function(t9);
		phalcon_update_property_zval(this_ptr, "_p0", strlen("_p0"), t9 TSRMLS_CC);
		
		PHALCON_INIT_VAR(t10);
		phalcon_read_property(&t10, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_INIT_VAR(t11);
		ZVAL_LONG(t11, 10);
		PHALCON_INIT_VAR(r8);
		is_smaller_function(r8, t11, t10 TSRMLS_CC);
		if (zend_is_true(r8)) {
			goto we_fdd7_23;
		}
		goto ws_fdd7_23;
	we_fdd7_23:
	if(0) { };
	
	PHALCON_RETURN_CTOR(node);
}

PHP_METHOD(Phalcon_Internal_Test, t6){

	zval *a = NULL, *b = NULL, *c = NULL, *e = NULL, *i = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL;
	zval *p1[] = { NULL, NULL, NULL, NULL }, *p2[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &a, &b, &c) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 0);
	add_next_index_long(a0, 25);
	PHALCON_CPY_WRT(e, a0);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_internal_testparent_ce);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
	zend_update_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, i0 TSRMLS_CC);
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	fs_fdd7_24:
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, i, t0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_fdd7_24;
		}
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 5);
		PHALCON_INIT_VAR(r1);
		is_smaller_function(r1, i, t1 TSRMLS_CC);
		if (zend_is_true(r1)) {
			PHALCON_INIT_VAR(r2);
			phalcon_array_fetch_long(&r2, e, 1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_INIT_VAR(r3);
			t2 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			p1[0] = t2;
			p1[1] = i;
			p1[2] = a;
			p1[3] = b;
			PHALCON_CALL_STATIC_PARAMS(r3, "phalcon_internal_testparent", "smp6", 4, p1);
			PHALCON_INIT_VAR(r4);
			phalcon_add_function(r4, r2, r3 TSRMLS_CC);
			phalcon_array_update_long(&e, 1, &r4, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(r5);
			phalcon_array_fetch_long(&r5, e, 1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_INIT_VAR(r6);
			t3 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			p2[0] = t3;
			PHALCON_INIT_VAR(r7);
			phalcon_array_fetch_long(&r7, e, 0, PHALCON_NOISY TSRMLS_CC);
			PHALCON_SEPARATE_NMO(r7);
			PHALCON_INIT_VAR(t4);
			ZVAL_ZVAL(t4, r7, 1, 0);
			increment_function(r7);
			phalcon_array_update_long(&e, 0, &r7, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			p2[1] = t4;
			p2[2] = b;
			p2[3] = c;
			PHALCON_CALL_SELF_PARAMS(r6, this_ptr, "smp6", 4, p2);
			PHALCON_INIT_VAR(r8);
			phalcon_add_function(r8, r5, r6 TSRMLS_CC);
			phalcon_array_update_long(&e, 1, &r8, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto fs_fdd7_24;
	fe_fdd7_24:
	
	PHALCON_ALLOC_ZVAL_MM(r9);
	phalcon_array_fetch_long(&r9, e, 1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r10);
	t5 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r10, t5, "mp7", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r11);
	phalcon_add_function(r11, r9, r10 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r11);
}

PHP_METHOD(Phalcon_Internal_Test, t7){

	zval *a = NULL, *b = NULL, *e = NULL, *i = NULL, *j = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL;
	zval *p1[] = { NULL, NULL, NULL, NULL }, *p2[] = { NULL, NULL, NULL, NULL }, *p3[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &a, &b) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 0);
	add_next_index_long(a0, 25);
	PHALCON_CPY_WRT(e, a0);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_internal_testparent_ce);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
	zend_update_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, i0 TSRMLS_CC);
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	fs_fdd7_25:
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, i, t0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_fdd7_25;
		}
		PHALCON_CPY_WRT(j, a);
		fs_fdd7_26:
			PHALCON_INIT_VAR(t1);
			ZVAL_LONG(t1, 0);
			PHALCON_INIT_VAR(r1);
			is_smaller_function(r1, t1, j TSRMLS_CC);
			if (!zend_is_true(r1)) {
				goto fe_fdd7_26;
			}
			PHALCON_INIT_VAR(t2);
			ZVAL_LONG(t2, 5);
			PHALCON_INIT_VAR(r2);
			is_smaller_function(r2, i, t2 TSRMLS_CC);
			if (zend_is_true(r2)) {
				PHALCON_INIT_VAR(r3);
				phalcon_array_fetch_long(&r3, e, 1, PHALCON_NOISY TSRMLS_CC);
				PHALCON_INIT_VAR(r4);
				t3 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
				p1[0] = t3;
				p1[1] = i;
				p1[2] = a;
				p1[3] = b;
				PHALCON_CALL_STATIC_PARAMS(r4, "phalcon_internal_testparent", "smp6", 4, p1);
				PHALCON_INIT_VAR(r5);
				phalcon_add_function(r5, r3, r4 TSRMLS_CC);
				phalcon_array_update_long(&e, 1, &r5, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			} else {
				PHALCON_INIT_VAR(t4);
				ZVAL_LONG(t4, 4);
				PHALCON_INIT_VAR(r6);
				is_smaller_function(r6, t4, j TSRMLS_CC);
				if (zend_is_true(r6)) {
					PHALCON_INIT_VAR(r7);
					phalcon_array_fetch_long(&r7, e, 1, PHALCON_NOISY TSRMLS_CC);
					PHALCON_INIT_VAR(r8);
					t5 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
					p2[0] = t5;
					PHALCON_INIT_VAR(r9);
					phalcon_array_fetch_long(&r9, e, 0, PHALCON_NOISY TSRMLS_CC);
					PHALCON_SEPARATE_NMO(r9);
					decrement_function(r9);
					phalcon_array_update_long(&e, 0, &r9, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
					p2[1] = r9;
					p2[2] = b;
					p2[3] = j;
					PHALCON_CALL_SELF_PARAMS(r8, this_ptr, "smp6", 4, p2);
					PHALCON_INIT_VAR(r10);
					phalcon_add_function(r10, r7, r8 TSRMLS_CC);
					phalcon_array_update_long(&e, 1, &r10, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(r11);
					phalcon_array_fetch_long(&r11, e, 1, PHALCON_NOISY TSRMLS_CC);
					PHALCON_INIT_VAR(r12);
					t6 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
					p3[0] = t6;
					PHALCON_INIT_VAR(r13);
					phalcon_array_fetch_long(&r13, e, 0, PHALCON_NOISY TSRMLS_CC);
					PHALCON_SEPARATE_NMO(r13);
					PHALCON_INIT_VAR(t7);
					ZVAL_ZVAL(t7, r13, 1, 0);
					increment_function(r13);
					phalcon_array_update_long(&e, 0, &r13, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
					p3[1] = t7;
					p3[2] = a;
					p3[3] = j;
					PHALCON_CALL_SELF_PARAMS(r12, this_ptr, "smp6", 4, p3);
					PHALCON_INIT_VAR(r14);
					phalcon_add_function(r14, r11, r12 TSRMLS_CC);
					phalcon_array_update_long(&e, 1, &r14, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				}
			}
			PHALCON_SEPARATE(j);
			decrement_function(j);
			goto fs_fdd7_26;
		fe_fdd7_26:
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto fs_fdd7_25;
	fe_fdd7_25:
	
	PHALCON_ALLOC_ZVAL_MM(r15);
	phalcon_array_fetch_long(&r15, e, 1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r16);
	t8 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r16, t8, "mp7", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r17);
	phalcon_add_function(r17, r15, r16 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r17);
}

PHP_METHOD(Phalcon_Internal_Test, t9){

	zval *not_null = NULL, *record = NULL, *num_fields = NULL, *i = NULL, *field = NULL, *value = NULL;
	zval *human_field = NULL, *message = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, "cedula", strlen("cedula"), 1);
	add_next_index_stringl(a0, "nombre", strlen("nombre"), 1);
	add_next_index_stringl(a0, "saldo", strlen("saldo"), 1);
	add_next_index_stringl(a0, "estado", strlen("estado"), 1);
	PHALCON_CPY_WRT(not_null, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	phalcon_update_property_zval(this_ptr, "_p0", strlen("_p0"), a1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(record, i0);
	phalcon_update_property_string(record, "cedula", strlen("cedula"), "hello" TSRMLS_CC);
	zend_update_property_null(Z_OBJCE_P(record), record, "nombre", strlen("nombre") TSRMLS_CC);
	zend_update_property_null(Z_OBJCE_P(record), record, "saldo", strlen("saldo") TSRMLS_CC);
	zend_update_property_null(Z_OBJCE_P(record), record, "estado", strlen("estado") TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_count(r0, not_null TSRMLS_CC);
	PHALCON_CPY_WRT(num_fields, r0);
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	fs_fdd7_27:
		PHALCON_INIT_VAR(r1);
		is_smaller_function(r1, i, num_fields TSRMLS_CC);
		if (!zend_is_true(r1)) {
			goto fe_fdd7_27;
		}
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch(&r2, not_null, i, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(field, r2);
		
		PHALCON_INIT_VAR(t0);
		phalcon_read_property_zval(&t0, record, field, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(value, t0);
		
		PHALCON_INIT_VAR(r3);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "_id", 1);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "", 1);
		PHALCON_CALL_FUNC_PARAMS_3(r3, "str_replace", c0, c1, field, 0x003);
		PHALCON_CPY_WRT(human_field, r3);
		
		PHALCON_INIT_VAR(i1);
		object_init_ex(i1, phalcon_model_message_ce);
		
		PHALCON_INIT_VAR(r4);
		PHALCON_CONCAT_RIGHT(r4, human_field, " is required");
		PHALCON_INIT_VAR(c2);
		ZVAL_STRING(c2, "PresenceOf", 1);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(i1, "__construct", r4, field, c2, PHALCON_CHECK);
		PHALCON_CPY_WRT(message, i1);
		
		PHALCON_INIT_VAR(t1);
		phalcon_read_property(&t1, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY TSRMLS_CC);
		phalcon_array_append(&t1, message, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_p0", strlen("_p0"), t1 TSRMLS_CC);
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto fs_fdd7_27;
	fe_fdd7_27:
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t2);
}

PHP_METHOD(Phalcon_Internal_Test, t10){

	zval *attributes = NULL, *data_type_numeric = NULL, *record = NULL;
	zval *values = NULL, *field = NULL, *value = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, "cedula", strlen("cedula"), 1);
	add_next_index_stringl(a0, "nombre", strlen("nombre"), 1);
	add_next_index_stringl(a0, "saldo", strlen("saldo"), 1);
	add_next_index_stringl(a0, "estado", strlen("estado"), 1);
	PHALCON_CPY_WRT(attributes, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_assoc_bool_ex(a1, "saldo", strlen("saldo")+1, 1);
	PHALCON_CPY_WRT(data_type_numeric, a1);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(record, i0);
	phalcon_update_property_string(record, "cedula", strlen("cedula"), "hello" TSRMLS_CC);
	phalcon_update_property_string(record, "nombre", strlen("nombre"), "LOL" TSRMLS_CC);
	phalcon_update_property_long(record, "saldo", strlen("saldo"), 0 TSRMLS_CC);
	phalcon_update_property_string(record, "estado", strlen("estado"), "X" TSRMLS_CC);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	PHALCON_CPY_WRT(values, a2);
	if (phalcon_valid_foreach(attributes TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(attributes);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_28:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_28;
		}
		
		PHALCON_INIT_VAR(field);
		ZVAL_ZVAL(field, *hd, 1, 0);
		PHALCON_INIT_VAR(t0);
		phalcon_read_property_zval(&t0, record, field, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(value, t0);
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, "", 1);
		PHALCON_INIT_VAR(r0);
		is_identical_function(r0, t1, value TSRMLS_CC);
		PHALCON_INIT_VAR(t2);
		ZVAL_NULL(t2);
		PHALCON_INIT_VAR(r1);
		is_identical_function(r1, t2, value TSRMLS_CC);
		PHALCON_INIT_VAR(r2);
		ZVAL_BOOL(r2, zend_is_true(r0) || zend_is_true(r1));
		if (zend_is_true(r2)) {
			PHALCON_INIT_VAR(t3);
			ZVAL_STRING(t3, "NULL", 1);
			phalcon_array_append(&values, t3, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		} else {
			eval_int = phalcon_array_isset(data_type_numeric, field);
			if (eval_int) {
				phalcon_array_append(&values, value, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			} else {
				PHALCON_INIT_VAR(r3);
				PHALCON_CONCAT_BOTH(r3,  "'", value, "'");
				phalcon_array_append(&values, r3, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_28;
		fee_fdd7_28:
		if(0){ };
	}
	
	PHALCON_RETURN_CTOR(values);
}

PHP_METHOD(Phalcon_Internal_Test, t11){

	zval *n = NULL, *dummy = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(n);
	ZVAL_LONG(n, 0);
	phalcon_update_property_string(this_ptr, "_p2", strlen("_p2"), "lol" TSRMLS_CC);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_p4", strlen("_p4"), 0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_internal_testdummy_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", this_ptr, PHALCON_CHECK);
	PHALCON_CPY_WRT(dummy, i0);
	ws_fdd7_29:
		
		PHALCON_INIT_VAR(t0);
		phalcon_read_property(&t0, this_ptr, "_p4", sizeof("_p4")-1, PHALCON_NOISY TSRMLS_CC);
		if (zend_is_true(t0)) {
			goto we_fdd7_29;
		}
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 1);
		PHALCON_INIT_VAR(r0);
		is_equal_function(r0, n, t1 TSRMLS_CC);
		if (zend_is_true(r0)) {
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "x/y", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(dummy, "f1", c0, PHALCON_NO_CHECK);
		}
		PHALCON_SEPARATE(n);
		increment_function(n);
		PHALCON_INIT_VAR(t2);
		ZVAL_LONG(t2, 2);
		PHALCON_INIT_VAR(r1);
		is_smaller_function(r1, t2, n TSRMLS_CC);
		if (zend_is_true(r1)) {
			zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_p4", strlen("_p4"), 1 TSRMLS_CC);
		}
		goto ws_fdd7_29;
	we_fdd7_29:
	if(0) { };
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_p4", strlen("_p4"), 1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, "_p2", sizeof("_p2")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t3);
}

PHP_METHOD(Phalcon_Internal_Test, t12){

	zval *uri = NULL, *parts = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &uri) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "/", 1);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "explode", c0, uri, 0x009);
	PHALCON_CPY_WRT(parts, r0);
	eval_int = phalcon_array_isset_long(parts, 0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_long(&r1, parts, 0, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_filter_alphanum(r2, r1);
		phalcon_update_property_zval(this_ptr, "_p1", strlen("_p1"), r2 TSRMLS_CC);
		PHALCON_SEPARATE(parts);
		phalcon_array_unset_long(parts, 0);
	}
	
	eval_int = phalcon_array_isset_long(parts, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_long(&r3, parts, 1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_filter_alphanum(r4, r3);
		phalcon_update_property_zval(this_ptr, "_p2", strlen("_p2"), r4 TSRMLS_CC);
		PHALCON_SEPARATE(parts);
		phalcon_array_unset_long(parts, 1);
	}
	
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_p4", strlen("_p4"), 0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, t13){

	zval *b = NULL, *o = NULL, *v = NULL, *k = NULL, *vv = NULL, *kv = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *t0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_assoc_stringl_ex(a1, "sup", strlen("sup")+1, "hello1", strlen("hello1"), 1);
	phalcon_array_update_string(&a0, "wish", strlen("wish"), &a1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	add_assoc_stringl_ex(a2, "xup", strlen("xup")+1, "hello2", strlen("hello2"), 1);
	phalcon_array_update_string(&a0, "be", strlen("be"), &a2, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	add_assoc_stringl_ex(a3, "zup", strlen("zup")+1, "hello3", strlen("hello3"), 1);
	phalcon_array_update_string(&a0, "today", strlen("today"), &a3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_CPY_WRT(b, a0);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(o, i0);
	if (phalcon_valid_foreach(b TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(b);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_30:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_30;
		} else {
			PHALCON_INIT_VAR(k);
			hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
			if (hash_type == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(k, hash_index, hash_index_len-1, 1);
			} else {
				if (hash_type == HASH_KEY_IS_LONG) {
					ZVAL_LONG(k, hash_num);
				}
			}
		}
		PHALCON_INIT_VAR(v);
		ZVAL_ZVAL(v, *hd, 1, 0);
		if (Z_TYPE_P(v) == IS_ARRAY) { 
			PHALCON_INIT_VAR(i1);
			object_init(i1);
			phalcon_update_property_zval(o, Z_STRVAL_P(k), Z_STRLEN_P(k), i1 TSRMLS_CC);
			if (phalcon_valid_foreach(v TSRMLS_CC)) {
				ah1 = Z_ARRVAL_P(v);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_fdd7_31:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee_fdd7_31;
				} else {
					PHALCON_INIT_VAR(kv);
					hash_type = zend_hash_get_current_key_ex(ah1, &hash_index, &hash_index_len, &hash_num, 0, &hp1);
					if (hash_type == HASH_KEY_IS_STRING) {
						ZVAL_STRINGL(kv, hash_index, hash_index_len-1, 1);
					} else {
						if (hash_type == HASH_KEY_IS_LONG) {
							ZVAL_LONG(kv, hash_num);
						}
					}
				}
				PHALCON_INIT_VAR(vv);
				ZVAL_ZVAL(vv, *hd, 1, 0);
				PHALCON_INIT_VAR(t0);
				phalcon_read_property_zval(&t0, o, k, PHALCON_NOISY TSRMLS_CC);
				phalcon_update_property_zval(t0, Z_STRVAL_P(kv), Z_STRLEN_P(kv), vv TSRMLS_CC);
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_fdd7_31;
				fee_fdd7_31:
				if(0){ };
			}
		} else {
			phalcon_update_property_zval(o, Z_STRVAL_P(k), Z_STRLEN_P(k), v TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_30;
		fee_fdd7_30:
		if(0){ };
	}
	
	PHALCON_RETURN_CTOR(o);
}

PHP_METHOD(Phalcon_Internal_Test, t14){

	zval *p = NULL, *i = NULL, *f = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(p, i0);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(p, "a", strlen("a"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	fs_fdd7_32:
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, i, t0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_fdd7_32;
		}
		PHALCON_INIT_VAR(i1);
		object_init(i1);
		PHALCON_CPY_WRT(f, i1);
		
		PHALCON_INIT_VAR(t1);
		phalcon_read_property(&t1, p, "a", sizeof("a")-1, PHALCON_NOISY TSRMLS_CC);
		phalcon_array_append(&t1, f, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
		phalcon_update_property_zval(p, "a", strlen("a"), t1 TSRMLS_CC);
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto fs_fdd7_32;
	fe_fdd7_32:
	
	PHALCON_RETURN_CTOR(p);
}

PHP_METHOD(Phalcon_Internal_Test, t15){

	zval *name = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_array_fetch(&t1, t0, name, PHALCON_SILENT TSRMLS_CC);
	if (zend_is_true(t1)) {
		t2 = zend_read_static_property(phalcon_internal_test_ce, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_array_fetch(&t3, t2, name, PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_RETURN_CHECK_CTOR(t3);
	} else {
		phalcon_get_global(&g0, "_POST", sizeof("_POST") TSRMLS_CC);
		eval_int = phalcon_array_isset(g0, name);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_CALL_FUNC(r0, "get_magic_quotes_gpc", 0x02C);
			if (!zend_is_true(r0)) {
				PHALCON_ALLOC_ZVAL_MM(r1);
				phalcon_array_fetch(&r1, g0, name, PHALCON_NOISY TSRMLS_CC);
				
				PHALCON_RETURN_CHECK_CTOR(r1);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r2);
				PHALCON_ALLOC_ZVAL_MM(r3);
				phalcon_array_fetch(&r3, g0, name, PHALCON_NOISY TSRMLS_CC);
				PHALCON_CALL_FUNC_PARAMS_1(r2, "stripslashes", r3, 0x02D);
				PHALCON_RETURN_DZVAL(r2);
			}
		}
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, t16){

	zval *a = NULL, *b = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_internal_testdummy_ce);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "hello", 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
	PHALCON_CPY_WRT(a, i0);
	
	PHALCON_ALLOC_ZVAL_MM(i1);
	if (phalcon_clone(i1, a TSRMLS_CC) == FAILURE){
		return;
	}
	PHALCON_CPY_WRT(b, i1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "lol", 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(b, "f3", c1, PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, b, "f2", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, a, "f2", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, r0, r1 TSRMLS_CC);
	
	PHALCON_RETURN_CTOR(r2);
}

PHP_METHOD(Phalcon_Internal_Test, t17){

	zval *robots = NULL, *result_query = NULL, *robot = NULL;
	zval *a0 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL, *c4 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(robots, a0);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "localhost", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "root", 1);
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "", 1);
	PHALCON_CALL_FUNC_PARAMS_3_NORETURN("mysql_connect", c0, c1, c2, 0x02E);
	PHALCON_INIT_VAR(c3);
	ZVAL_STRING(c3, "phalcon_test", 1);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("mysql_select_db", c3, 0x02F);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c4);
	ZVAL_STRING(c4, "SELECT * FROM robots", 1);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "mysql_query", c4, 0x030);
	PHALCON_CPY_WRT(result_query, r0);
	ws_fdd7_33:
		
		PHALCON_INIT_VAR(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "mysql_fetch_array", result_query, 0x031);
		PHALCON_CPY_WRT(robot, r1);
		if (!zend_is_true(robot)) {
			goto we_fdd7_33;
		}
		phalcon_array_append(&robots, robot, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		goto ws_fdd7_33;
	we_fdd7_33:
	if(0) { };
	
	PHALCON_RETURN_CTOR(robots);
}

