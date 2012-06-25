
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

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
PHP_METHOD(Phalcon_Internal_Test, __construct){

	zval *a0 = NULL, *a1 = NULL;

	PHALCON_MM_GROW();
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_internal_test_ce, this_ptr, SL("_p8"), a0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	zend_update_property(phalcon_internal_test_ce, this_ptr, SL("_p9"), a1 TSRMLS_CC);
	
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
	
	RETURN_NCTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, e4){

	zval *a = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a);
	ZVAL_LONG(a, 5);
	
	RETURN_NCTOR(a);
}

PHP_METHOD(Phalcon_Internal_Test, e5){

	zval *a = NULL, *b = NULL, *c = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a);
	ZVAL_LONG(a, 5);
	PHALCON_CPY_WRT(b, a);
	PHALCON_CPY_WRT(c, b);
	
	RETURN_NCTOR(c);
}

PHP_METHOD(Phalcon_Internal_Test, e6){

	zval *num = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &num) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	RETURN_CHECK_CTOR(num);
}

PHP_METHOD(Phalcon_Internal_Test, e7){

	zval *num = NULL, *a = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &num) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(a, num);
	
	RETURN_CHECK_CTOR(a);
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
	phalcon_update_property_long(a, SL("uno"), 1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init(i1);
	phalcon_update_property_zval(a, SL("subA"), i1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, a, SL("subA"), PHALCON_NOISY TSRMLS_CC);
	phalcon_update_property_long(t0, SL("dos"), 2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, a, SL("uno"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, a, SL("subA"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, t2, SL("dos"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, t1, t3 TSRMLS_CC);
	
	RETURN_CTOR(r0);
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
	phalcon_update_property_zval(a, SL("val"), val TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, a, SL("val"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, e15){

	zval *a = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(a, i0);
	phalcon_update_property_string(a, SL("val"), "hullo" TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, a, SL("val"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
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
	phalcon_update_property_long(a, SL("uno"), 1 TSRMLS_CC);
	phalcon_update_property_long(a, SL("dos"), 2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init(i1);
	phalcon_update_property_zval(a, SL("subA"), i1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, a, SL("subA"), PHALCON_NOISY TSRMLS_CC);
	phalcon_update_property_long(t0, SL("uno"), 1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, a, SL("subA"), PHALCON_NOISY TSRMLS_CC);
	phalcon_update_property_long(t1, SL("dos"), 2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i2);
	object_init(i2);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, a, SL("subA"), PHALCON_NOISY TSRMLS_CC);
	phalcon_update_property_zval(t2, SL("subSubA"), i2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, a, SL("subA"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, t3, SL("subSubA"), PHALCON_NOISY TSRMLS_CC);
	phalcon_update_property_long(t4, SL("uno"), 1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_read_property(&t5, a, SL("subA"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t6);
	phalcon_read_property(&t6, t5, SL("subSubA"), PHALCON_NOISY TSRMLS_CC);
	phalcon_update_property_long(t6, SL("dos"), 2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t7);
	phalcon_read_property(&t7, a, SL("uno"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t8);
	phalcon_read_property(&t8, a, SL("subA"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t9);
	phalcon_read_property(&t9, t8, SL("uno"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, t7, t9 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t10);
	phalcon_read_property(&t10, a, SL("subA"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t11);
	phalcon_read_property(&t11, t10, SL("subSubA"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t12);
	phalcon_read_property(&t12, t11, SL("uno"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	mul_function(r1, r0, t12 TSRMLS_CC);
	
	RETURN_CTOR(r1);
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
	
	RETURN_CHECK_CTOR(t0);
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
	
	RETURN_CHECK_CTOR(t0);
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
	
	RETURN_CTOR(r0);
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
	
	RETURN_CTOR(r0);
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
	
	RETURN_CTOR(r0);
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
	
	RETURN_CTOR(r0);
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
	
	RETURN_CTOR(r0);
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
	
	RETURN_CTOR(r0);
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
	
	RETURN_CTOR(r0);
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
	
	RETURN_NCTOR(r0);
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
	
	RETURN_NCTOR(r0);
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
	
	RETURN_NCTOR(r0);
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
	
	RETURN_NCTOR(r0);
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
	
	RETURN_NCTOR(r0);
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
	
	RETURN_CTOR(r0);
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
	
	RETURN_CTOR(r0);
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
	
	RETURN_CTOR(r0);
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
	
	RETURN_CTOR(r0);
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
	
	RETURN_CTOR(r0);
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
	
	RETURN_CTOR(r6);
}

PHP_METHOD(Phalcon_Internal_Test, o21){

	zval *a = NULL, *b = NULL, *c = NULL, *d = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a);
	ZVAL_STRING(a, "memory", 1);
	
	PHALCON_INIT_VAR(b);
	ZVAL_STRING(b, "yes", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_SV(r0, "no, ", a);
	PHALCON_CPY_WRT(c, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CONCAT_SV(r1, "leaks, ", b);
	PHALCON_CPY_WRT(d, r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_VVV(r2, c, d, b);
	PHALCON_CPY_WRT(b, r2);
	
	RETURN_CTOR(b);
}

PHP_METHOD(Phalcon_Internal_Test, o22){

	zval *e = NULL, *i = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

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
		phalcon_concat_self(&e, i TSRMLS_CC);
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto fs_fdd7_0;
	fe_fdd7_0:
	
	RETURN_CHECK_CTOR(e);
}

PHP_METHOD(Phalcon_Internal_Test, o23){

	zval *e = NULL, *i = NULL, *sx = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

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
		PHALCON_CONCAT_VS(r1, i, "-");
		PHALCON_CPY_WRT(sx, r1);
		phalcon_concat_self(&e, sx TSRMLS_CC);
		
		PHALCON_INIT_VAR(sx);
		ZVAL_STRING(sx, "nope", 1);
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto fs_fdd7_1;
	fe_fdd7_1:
	
	RETURN_CHECK_CTOR(e);
}

PHP_METHOD(Phalcon_Internal_Test, o24){

	zval *a = NULL, *b = NULL, *c = NULL, *d = NULL, *e = NULL, *f = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a);
	ZVAL_STRING(a, "hello", 1);
	
	PHALCON_INIT_VAR(b);
	ZVAL_STRING(b, "la", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_SV(r0, "thievery ", a);
	PHALCON_CPY_WRT(c, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CONCAT_SVS(r1, "thievery ", a, " corp ");
	PHALCON_CPY_WRT(d, r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_SVSV(r2, "thievery ", a, " corp ", c);
	PHALCON_CPY_WRT(e, r2);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CONCAT_SVSVS(r3, "WHERE ", a, " = '", b, "'");
	PHALCON_CPY_WRT(f, r3);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_VVV(r4, d, e, f);
	
	RETURN_CTOR(r4);
}

PHP_METHOD(Phalcon_Internal_Test, a0){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	
	RETURN_CTOR(a0);
}

PHP_METHOD(Phalcon_Internal_Test, a1){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_null(a0);
	add_next_index_bool(a0, 0);
	add_next_index_long(a0, 0);
	add_next_index_stringl(a0, SL("whtzup"), 1);
	
	RETURN_CTOR(a0);
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
	phalcon_array_update_string(&a, SL("LOL"), &t1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, a, SL("LOL"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(r0);
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
		phalcon_array_fetch_string(&t2, t1, SL("LOL"), PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t2) > 1) {
		phalcon_array_update_string(&t1, SL("LOL"), &t2, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t2) != IS_ARRAY) {
		convert_to_array(t2);
		phalcon_array_update_string(&t1, SL("LOL"), &t2, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
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
	phalcon_array_update_string(&t3, SL("YEAH"), &t0, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, b, 1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, r0, SL("LOL"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, r1, 5, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch_string(&r3, r2, SL("YEAH"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(r3);
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
	phalcon_array_update_string(&a, SL("LOL"), &t1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_CPY_WRT(b, a1);
	
	PHALCON_INIT_VAR(t2);
	ZVAL_STRING(t2, "LOL", 1);
	phalcon_array_update_string(&b, SL("LOL"), &t2, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 0);
	phalcon_array_update_long(&b, 0, &t3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, b, 0, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, a, SL("LOL"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_add_function(r2, r0, r1 TSRMLS_CC);
	
	RETURN_CTOR(r2);
}

PHP_METHOD(Phalcon_Internal_Test, a6){

	zval *a = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL;
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
	phalcon_array_update_multi_long_str_2(&a, 1, "LOL", strlen("LOL"), &t0, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, a, 1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, r0, SL("LOL"), PHALCON_NOISY TSRMLS_CC);
	zend_print_zval(r1, 1);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, a7){

	zval *a = NULL, *b = NULL, *c = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL;
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
	phalcon_array_update_multi_long_str_2(&a, 1, "LOL", strlen("LOL"), &t1, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 0);
	phalcon_array_update_string(&a, SL("LOL"), &t2, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	PHALCON_CPY_WRT(b, a2);
	
	PHALCON_INIT_VAR(t3);
	ZVAL_STRING(t3, "LOL", 1);
	phalcon_array_update_string(&b, SL("LOL"), &t3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 0);
	phalcon_array_update_long(&b, 0, &t4, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_INIT_VAR(t5);
	ZVAL_LONG(t5, 1);
	phalcon_array_update_multi_long_str_2(&b, 1, "LOL", strlen("LOL"), &t5, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	PHALCON_CPY_WRT(c, a3);
	
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	phalcon_array_update_long(&c, 0, &a4, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_INIT_VAR(a5);
	array_init(a5);
	phalcon_array_update_multi_long_long_2(&c, 0, 0, &a5, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	
	PHALCON_INIT_VAR(a6);
	array_init(a6);
	if (Z_TYPE_P(c) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t6);
		phalcon_array_fetch_long(&t6, c, 0, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t6) > 1) {
		phalcon_array_update_long(&c, 0, &t6, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t6) != IS_ARRAY) {
		convert_to_array(t6);
		phalcon_array_update_long(&c, 0, &t6, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t6) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t7);
		phalcon_array_fetch_long(&t7, t6, 0, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t7) > 1) {
		phalcon_array_update_long(&t6, 0, &t7, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t7) != IS_ARRAY) {
		convert_to_array(t7);
		phalcon_array_update_long(&t6, 0, &t7, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	phalcon_array_update_long(&t7, 0, &a6, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_INIT_VAR(t8);
	ZVAL_LONG(t8, 1);
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
	if (Z_TYPE_P(t10) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t11);
		phalcon_array_fetch_long(&t11, t10, 0, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t11) > 1) {
		phalcon_array_update_long(&t10, 0, &t11, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(t11) != IS_ARRAY) {
		convert_to_array(t11);
		phalcon_array_update_long(&t10, 0, &t11, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	phalcon_array_update_string(&t11, SL("LOL"), &t8, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, b, 1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, r0, SL("LOL"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, a, 1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch_string(&r3, r2, SL("LOL"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	mul_function(r4, r1, r3 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	phalcon_array_fetch_long(&r5, c, 0, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	phalcon_array_fetch_long(&r6, r5, 0, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r7);
	phalcon_array_fetch_long(&r7, r6, 0, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r8);
	phalcon_array_fetch_string(&r8, r7, SL("LOL"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r9);
	mul_function(r9, r4, r8 TSRMLS_CC);
	
	RETURN_CTOR(r9);
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
	add_assoc_long_ex(a0, SL("hello1")+1, 1);
	add_assoc_long_ex(a0, SL("hello2")+1, 2);
	add_assoc_long_ex(a0, SL("hello3")+1, 3);
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
			PHALCON_GET_FOREACH_KEY(k, ah0, hp0);
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
	} else {
		return;
	}
	
	RETURN_CTOR(e);
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
			PHALCON_GET_FOREACH_KEY(k, ah0, hp0);
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
	} else {
		return;
	}
	
	RETURN_CTOR(e);
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
	} else {
		return;
	}
	
	RETURN_CTOR(e);
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
		if(0){}
	} else {
		return;
	}
	
	RETURN_CTOR(f);
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
			PHALCON_GET_FOREACH_KEY(k, ah0, hp0);
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
		if(0){}
	} else {
		return;
	}
	
	RETURN_CTOR(f);
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
			PHALCON_GET_FOREACH_KEY(k, ah0, hp0);
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
	} else {
		return;
	}
	
	RETURN_CTOR(f);
}

PHP_METHOD(Phalcon_Internal_Test, a16){

	zval *f = NULL, *e = NULL, *v = NULL, *k = NULL, *sv = NULL, *sk = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL;
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
	add_assoc_stringl_ex(a2, SL("in")+1, SL("out"), 1);
	phalcon_array_update_string(&a1, SL("hello"), &a2, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	add_assoc_stringl_ex(a3, SL("file")+1, SL("type"), 1);
	add_assoc_stringl_ex(a3, SL("php")+1, SL("unix"), 1);
	add_assoc_stringl_ex(a3, SL("tab")+1, SL("ins"), 1);
	phalcon_array_update_string(&a1, SL("bye"), &a3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	phalcon_array_update_string(&a1, SL("encoding"), &a4, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	add_assoc_stringl_ex(a1, SL("sucks")+1, SL("yes"), 1);
	PHALCON_CPY_WRT(e, a1);
	if (phalcon_valid_foreach(e TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(e);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_8:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_8;
		} else {
			PHALCON_INIT_VAR(k);
			PHALCON_GET_FOREACH_KEY(k, ah0, hp0);
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
					PHALCON_GET_FOREACH_KEY(sk, ah1, hp1);
				}
				PHALCON_INIT_VAR(sv);
				ZVAL_ZVAL(sv, *hd, 1, 0);
				phalcon_array_update_multi_2(&f, k, sk, &sv, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_fdd7_9;
				fee_fdd7_9:
				if(0){}
			} else {
				return;
			}
		} else {
			phalcon_array_update(&f, k, &v, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_8;
		fee_fdd7_8:
		if(0){}
	} else {
		return;
	}
	
	RETURN_CTOR(f);
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
	add_next_index_stringl(a3, SL("hello1"), 1);
	phalcon_array_append(&a2, a3, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	add_next_index_stringl(a4, SL("hello2"), 1);
	phalcon_array_update_long(&a2, 1, &a4, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_INIT_VAR(a5);
	array_init(a5);
	add_next_index_stringl(a5, SL("hello3"), 1);
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
			PHALCON_GET_FOREACH_KEY(k, ah0, hp0);
		}
		PHALCON_INIT_VAR(v);
		ZVAL_ZVAL(v, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch(&r0, b, v, PHALCON_NOISY TSRMLS_CC);
		phalcon_array_update(&w, k, &r0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_10;
		fee_fdd7_10:
		if(0){}
	} else {
		return;
	}
	
	RETURN_CTOR(w);
}

PHP_METHOD(Phalcon_Internal_Test, a18){

	zval *a = NULL, *c = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, SL("hello1"), 1);
	add_next_index_stringl(a0, SL("hello2"), 1);
	add_next_index_stringl(a0, SL("hello3"), 1);
	PHALCON_CPY_WRT(a, a0);
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	phalcon_array_append(&a1, a, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	PHALCON_CPY_WRT(c, a1);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "see", 1);
	phalcon_array_update_multi_long_long_2(&c, 0, 0, &t0, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	
	RETURN_CTOR(a);
}

PHP_METHOD(Phalcon_Internal_Test, a19){

	zval *a = NULL, *b = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, SL("hello1"), 1);
	add_next_index_stringl(a0, SL("hello2"), 1);
	add_next_index_stringl(a0, SL("hello3"), 1);
	add_next_index_bool(a0, 0);
	add_next_index_null(a0);
	add_next_index_double(a0, 1.34);
	PHALCON_CPY_WRT(a, a0);
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_next_index_stringl(a1, SL("lol1"), 1);
	add_next_index_stringl(a1, SL("lol2"), 1);
	add_next_index_stringl(a1, SL("lol3"), 1);
	add_next_index_stringl(a1, SL("lol4"), 1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	PHALCON_CPY_WRT(b, a1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, a, b TSRMLS_CC);
	
	RETURN_CTOR(r0);
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
	
	RETURN_CTOR(a);
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
	
	RETURN_CTOR(a);
}

PHP_METHOD(Phalcon_Internal_Test, a22){

	zval *a = NULL, *b = NULL, *e = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, SL("222"), 1);
	PHALCON_CPY_WRT(a, a0);
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_next_index_stringl(a1, SL("222"), 1);
	add_next_index_stringl(a1, SL("kdkdk"), 1);
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
	
	RETURN_CTOR(e);
}

PHP_METHOD(Phalcon_Internal_Test, a23){

	zval *f = NULL, *e = NULL, *v = NULL, *k = NULL, *sv = NULL, *sk = NULL, *p = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
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
	add_assoc_stringl_ex(a2, SL("baseuri")+1, SL("/phalcon/"), 1);
	phalcon_array_update_string(&a1, SL("phalcon"), &a2, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	add_assoc_stringl_ex(a3, SL("metadata")+1, SL("memory"), 1);
	phalcon_array_update_string(&a1, SL("models"), &a3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	add_assoc_stringl_ex(a4, SL("adapter")+1, SL("mysql"), 1);
	add_assoc_stringl_ex(a4, SL("host")+1, SL("localhost"), 1);
	add_assoc_stringl_ex(a4, SL("username")+1, SL("user"), 1);
	add_assoc_stringl_ex(a4, SL("password")+1, SL("passwd"), 1);
	add_assoc_stringl_ex(a4, SL("name")+1, SL("demo"), 1);
	phalcon_array_update_string(&a1, SL("database"), &a4, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_INIT_VAR(a5);
	array_init(a5);
	add_assoc_long_ex(a5, SL("parent.property")+1, 1);
	add_assoc_stringl_ex(a5, SL("parent.property2")+1, SL("yeah"), 1);
	phalcon_array_update_string(&a1, SL("test"), &a5, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_CPY_WRT(e, a1);
	if (phalcon_valid_foreach(e TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(e);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_11:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_11;
		} else {
			PHALCON_INIT_VAR(k);
			PHALCON_GET_FOREACH_KEY(k, ah0, hp0);
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
					PHALCON_GET_FOREACH_KEY(sk, ah1, hp1);
				}
				PHALCON_INIT_VAR(sv);
				ZVAL_ZVAL(sv, *hd, 1, 0);
				phalcon_array_update_multi_2(&f, k, sk, &sv, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_fdd7_12;
				fee_fdd7_12:
				if(0){}
			} else {
				return;
			}
		} else {
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, ".", 1);
			PHALCON_INIT_VAR(r0);
			phalcon_fast_strpos(r0, c0, v TSRMLS_CC);
			if (Z_TYPE_P(r0) != IS_BOOL || (Z_TYPE_P(r0) == IS_BOOL && Z_BVAL_P(r0))) {
				PHALCON_INIT_VAR(c1);
				ZVAL_STRING(c1, ".", 1);
				PHALCON_INIT_VAR(r1);
				phalcon_fast_explode(r1, c1, v TSRMLS_CC);
				PHALCON_CPY_WRT(p, r1);
				
				PHALCON_INIT_VAR(r2);
				phalcon_array_fetch_long(&r2, p, 1, PHALCON_NOISY TSRMLS_CC);
				
				PHALCON_INIT_VAR(r3);
				phalcon_array_fetch_long(&r3, p, 0, PHALCON_NOISY TSRMLS_CC);
				phalcon_array_update_multi_2(&f, k, r3, &r2, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
			} else {
				phalcon_array_update(&f, k, &v, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_11;
		fee_fdd7_11:
		if(0){}
	} else {
		return;
	}
	
	RETURN_CTOR(f);
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
	PHALCON_CONCAT_SV(r0, "hello, ", num);
	PHALCON_CPY_WRT(p, r0);
	
	RETURN_CTOR(p);
}

PHP_METHOD(Phalcon_Internal_Test, a25){

	zval *a = NULL, *b = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a);
	ZVAL_STRING(a, "h", 1);
	
	PHALCON_INIT_VAR(b);
	ZVAL_STRING(b, "k", 1);
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_assoc_stringl_ex(a0, SL("k")+1, SL("v"), 1);
	add_assoc_stringl_ex(a0, SL("i")+1, SL("d"), 1);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p9"), PHALCON_NOISY TSRMLS_CC);
	phalcon_array_update_multi_2(&t0, a, b, &a0, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_p9"), t0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_p9"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t1);
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
	
	RETURN_CTOR(a);
}

PHP_METHOD(Phalcon_Internal_Test, sa0){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_static_property(SL("Phalcon_Internal_Test"), SL("_sp0"), a0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, sa1){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Internal_Test"), SL("_sp0") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sa2){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	add_next_index_stringl(a0, SL("lol"), 1);
	phalcon_update_static_property(SL("Phalcon_Internal_Test"), SL("_sp0"), a0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, sa3){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Internal_Test"), SL("_sp0") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sa4){

	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_static_property(SL("Phalcon_Internal_Test"), SL("_sp0"), a0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	t0 = zend_read_static_property(phalcon_internal_test_ce, SL("_sp0"), PHALCON_FETCH_CLASS_SILENT);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		convert_to_array(t0);
	}
	phalcon_array_append(&t0, a1, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	phalcon_update_static_property(SL("phalcon_internal_test_ce"), SL("_sp0"), t0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(t1);
	ZVAL_STRING(t1, "more-loose", 1);
	t2 = zend_read_static_property(phalcon_internal_test_ce, SL("_sp0"), PHALCON_FETCH_CLASS_SILENT);
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
	phalcon_update_static_property(SL("phalcon_internal_test_ce"), SL("_sp0"), t2 TSRMLS_CC);
	
	PHALCON_INIT_VAR(t4);
	ZVAL_STRING(t4, "yeah, more-loose", 1);
	t5 = zend_read_static_property(phalcon_internal_test_ce, SL("_sp0"), PHALCON_FETCH_CLASS_SILENT);
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
	phalcon_update_static_property(SL("phalcon_internal_test_ce"), SL("_sp0"), t5 TSRMLS_CC);
	
	PHALCON_OBSERVE_VAR(t7);
	phalcon_read_static_property(&t7, SL("Phalcon_Internal_Test"), SL("_sp0") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t7);
}

PHP_METHOD(Phalcon_Internal_Test, sa5){

	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_static_property(SL("Phalcon_Internal_Test"), SL("_sp0"), a0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "loose", 1);
	t1 = zend_read_static_property(phalcon_internal_test_ce, SL("_sp0"), PHALCON_FETCH_CLASS_SILENT);
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
	phalcon_update_static_property(SL("phalcon_internal_test_ce"), SL("_sp0"), t1 TSRMLS_CC);
	
	PHALCON_OBSERVE_VAR(t4);
	phalcon_read_static_property(&t4, SL("Phalcon_Internal_Test"), SL("_sp0") TSRMLS_CC);
	
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
	
	RETURN_CHECK_CTOR(t5);
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
	phalcon_update_static_property(SL("Phalcon_Internal_Test"), SL("_sp0"), a0 TSRMLS_CC);
	
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
			PHALCON_GET_FOREACH_KEY(k, ah0, hp0);
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
		t1 = zend_read_static_property(phalcon_internal_test_ce, SL("_sp0"), PHALCON_FETCH_CLASS_SILENT);
		if (Z_TYPE_P(t1) != IS_ARRAY) {
			convert_to_array(t1);
		}
		phalcon_array_update(&t1, k, &r1, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		phalcon_update_static_property(SL("phalcon_internal_test_ce"), SL("_sp0"), t1 TSRMLS_CC);
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_14;
		fee_fdd7_14:
		if(0){}
	} else {
		return;
	}
	PHALCON_OBSERVE_VAR(t2);
	phalcon_read_static_property(&t2, SL("Phalcon_Internal_Test"), SL("_sp0") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t2);
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
	phalcon_update_static_property(SL("Phalcon_Internal_Test"), SL("_sp0"), a0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	add_assoc_stringl_ex(a2, SL("in")+1, SL("out"), 1);
	phalcon_array_update_string(&a1, SL("hello"), &a2, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	add_assoc_stringl_ex(a3, SL("file")+1, SL("type"), 1);
	add_assoc_stringl_ex(a3, SL("php")+1, SL("unix"), 1);
	add_assoc_stringl_ex(a3, SL("tab")+1, SL("ins"), 1);
	phalcon_array_update_string(&a1, SL("bye"), &a3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	phalcon_array_update_string(&a1, SL("encoding"), &a4, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	add_assoc_stringl_ex(a1, SL("sucks")+1, SL("yes"), 1);
	PHALCON_CPY_WRT(e, a1);
	if (phalcon_valid_foreach(e TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(e);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_15:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_15;
		} else {
			PHALCON_INIT_VAR(k);
			PHALCON_GET_FOREACH_KEY(k, ah0, hp0);
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
					PHALCON_GET_FOREACH_KEY(sk, ah1, hp1);
				}
				PHALCON_INIT_VAR(sv);
				ZVAL_ZVAL(sv, *hd, 1, 0);
				t0 = zend_read_static_property(phalcon_internal_test_ce, SL("_sp0"), PHALCON_FETCH_CLASS_SILENT);
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
				phalcon_update_static_property(SL("phalcon_internal_test_ce"), SL("_sp0"), t0 TSRMLS_CC);
				
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_fdd7_16;
				fee_fdd7_16:
				if(0){}
			} else {
				return;
			}
		} else {
			t2 = zend_read_static_property(phalcon_internal_test_ce, SL("_sp0"), PHALCON_FETCH_CLASS_SILENT);
			if (Z_TYPE_P(t2) != IS_ARRAY) {
				convert_to_array(t2);
			}
			phalcon_array_update(&t2, k, &v, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			phalcon_update_static_property(SL("phalcon_internal_test_ce"), SL("_sp0"), t2 TSRMLS_CC);
			
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_15;
		fee_fdd7_15:
		if(0){}
	} else {
		return;
	}
	PHALCON_OBSERVE_VAR(t3);
	phalcon_read_static_property(&t3, SL("Phalcon_Internal_Test"), SL("_sp0") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t3);
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
	
	RETURN_NCTOR(r0);
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
	
	RETURN_NCTOR(r0);
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
	
	RETURN_NCTOR(r0);
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
	
	RETURN_NCTOR(r0);
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
	
	RETURN_NCTOR(r0);
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
	
	RETURN_NCTOR(r0);
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
	
	RETURN_NCTOR(r2);
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
	
	RETURN_NCTOR(r2);
}

PHP_METHOD(Phalcon_Internal_Test, c9){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	boolean_not_function(r0, t0 TSRMLS_CC);
	
	RETURN_NCTOR(r0);
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
	
	RETURN_NCTOR(r0);
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
	
	RETURN_NCTOR(r1);
}

PHP_METHOD(Phalcon_Internal_Test, f1){

	zval *c0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "LOL", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "strlen", c0);
	RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, f2){

	zval *c0 = NULL, *c1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "hello\t", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "\t", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "rtrim", c0, c1);
	RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, f3){

	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "bb", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "xx", 1);
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "aabbcc", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_str_replace(r0, c0, c1, c2 TSRMLS_CC);
	RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, f4){

	zval *c0 = NULL, *c1 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "deux", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "deux", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "strlen", c1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_2(r1, "str_repeat", c0, r0);
	RETURN_DZVAL(r1);
}

PHP_METHOD(Phalcon_Internal_Test, f5){

	zval *e = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, SL("b"), 1);
	add_next_index_stringl(a0, SL("c"), 1);
	add_next_index_stringl(a0, SL("a"), 1);
	PHALCON_CPY_WRT(e, a0);
	Z_SET_ISREF_P(e);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("asort", e);
	Z_UNSET_ISREF_P(e);
	
	RETURN_CTOR(e);
}

PHP_METHOD(Phalcon_Internal_Test, f6){

	zval *file = NULL, *fp = NULL, *content = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_LONG(c0, 0);
	PHALCON_INIT_VAR(c1);
	ZVAL_LONG(c1, 100);
	PHALCON_INIT_VAR(file);
	PHALCON_CALL_FUNC_PARAMS_2(file, "mt_rand", c0, c1);
	PHALCON_CONCAT_VS(r0, file, ".txt");
	PHALCON_CPY_WRT(file, r0);
	
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "w", 1);
	
	PHALCON_INIT_VAR(fp);
	PHALCON_CALL_FUNC_PARAMS_2(fp, "fopen", file, c2);
	
	PHALCON_INIT_VAR(c3);
	ZVAL_STRING(c3, "morelol\n", 1);
	PHALCON_CALL_FUNC_PARAMS_2_NORETURN("fwrite", fp, c3);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("fclose", fp);
	
	PHALCON_INIT_VAR(content);
	PHALCON_CALL_FUNC_PARAMS_1(content, "file_get_contents", file);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("unlink", file);
	
	RETURN_CHECK_CTOR(content);
}

PHP_METHOD(Phalcon_Internal_Test, f7){

	zval *c0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(c0);
	ZVAL_DOUBLE(c0, 3.14159);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "sqrt", c0);
	RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, f8){

	zval *a0 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, SL("."), 1);
	add_next_index_stringl(a0, SL(","), 1);
	add_next_index_stringl(a0, SL("-"), 1);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "&", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "-.,-.,", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_str_replace(r0, a0, c0, c1 TSRMLS_CC);
	RETURN_DZVAL(r0);
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
	PHALCON_CALL_FUNC_PARAMS_1(r2, "abs", e);
	RETURN_DZVAL(r2);
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
	phalcon_array_fetch_long(&r0, a, 0, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "is_numeric", r0);
	if (zend_is_true(r1)) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, f11){

	zval *n = NULL, *i = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(n);
	ZVAL_STRING(n, "", 1);
	
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	fs_fdd7_17:
		
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, i, t0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_fdd7_17;
		}
		PHALCON_INIT_VAR(n);
		PHALCON_CALL_FUNC_PARAMS_1(n, "strlen", i);
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto fs_fdd7_17;
	fe_fdd7_17:
	
	RETURN_CHECK_CTOR(n);
}

PHP_METHOD(Phalcon_Internal_Test, f12){

	zval *n = NULL, *i = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(n);
	ZVAL_STRING(n, "", 1);
	
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	fs_fdd7_18:
		
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, i, t0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_fdd7_18;
		}
		PHALCON_INIT_VAR(r1);
		PHALCON_CALL_FUNC_PARAMS_2(r1, "str_repeat", n, i);
		phalcon_concat_self(&n, r1 TSRMLS_CC);
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto fs_fdd7_18;
	fe_fdd7_18:
	
	RETURN_CTOR(n);
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
	RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, m4){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "m2", PHALCON_NO_CHECK);
	RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, m5){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, this_ptr, "m2", PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, this_ptr, "m1", PHALCON_NO_CHECK);
	PHALCON_CONCAT_VV(r0, r1, r2);
	
	RETURN_CTOR(r0);
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
	
	RETURN_CTOR(r0);
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
	RETURN_DZVAL(r0);
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
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_2(r1, this_ptr, "m6", a, b, PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD_PARAMS_2(r2, this_ptr, "m6", a, b, PHALCON_NO_CHECK);
	PHALCON_CONCAT_VV(r0, r1, r2);
	
	RETURN_CTOR(r0);
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
	
	RETURN_CTOR(r0);
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
	RETURN_DZVAL(r0);
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
	RETURN_DZVAL(r0);
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
		PHALCON_CALL_METHOD_PARAMS_2(r1, this_ptr, "m9", r2, r4, PHALCON_NO_CHECK);
		PHALCON_INIT_VAR(r5);
		phalcon_add_function(r5, d, r1 TSRMLS_CC);
		PHALCON_CPY_WRT(d, r5);
		PHALCON_SEPARATE(c);
		increment_function(c);
		goto fs_fdd7_19;
	fe_fdd7_19:
	
	RETURN_CTOR(d);
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
	
	RETURN_CTOR(r0);
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
	
	RETURN_CTOR(f);
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
	
	RETURN_CTOR(r1);
}

PHP_METHOD(Phalcon_Internal_Test, mp3){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "mp1", PHALCON_NO_CHECK);
	RETURN_DZVAL(r0);
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
	RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, mp5){

	zval *o = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_internal_testparent_ce);
	PHALCON_CPY_WRT(o, i0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, o, "mp1", PHALCON_NO_CHECK);
	RETURN_DZVAL(r0);
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
	PHALCON_CPY_WRT(o, i0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, o, "mp2", a, b, PHALCON_NO_CHECK);
	RETURN_DZVAL(r0);
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
	RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, sm4){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF(r0, this_ptr, "sm2");
	RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, sm5){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_SELF(r1, this_ptr, "sm2");
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_SELF(r2, this_ptr, "sm1");
	PHALCON_CONCAT_VV(r0, r1, r2);
	
	RETURN_CTOR(r0);
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
	
	RETURN_CTOR(r0);
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
	RETURN_DZVAL(r0);
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
	
	RETURN_CTOR(r0);
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
		PHALCON_CALL_SELF_PARAMS_2(r1, this_ptr, "sm8", r2, r4);
		PHALCON_INIT_VAR(r5);
		phalcon_add_function(r5, d, r1 TSRMLS_CC);
		PHALCON_CPY_WRT(d, r5);
		PHALCON_SEPARATE(c);
		increment_function(c);
		goto fs_fdd7_20;
	fe_fdd7_20:
	
	RETURN_CTOR(d);
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
	fs_fdd7_21:
		
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, c, t0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_fdd7_21;
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
		goto fs_fdd7_21;
	fe_fdd7_21:
	
	RETURN_CTOR(d);
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
	RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, smp2){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF(r0, this_ptr, "smp1");
	RETURN_DZVAL(r0);
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
	RETURN_DZVAL(r0);
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
	fs_fdd7_22:
		
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, c, t0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_fdd7_22;
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
		goto fs_fdd7_22;
	fe_fdd7_22:
	
	RETURN_CTOR(d);
}

PHP_METHOD(Phalcon_Internal_Test, p1){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p1"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p2){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p2"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p3){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p3"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p4){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p4"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p5){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p5"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p6){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p6"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p7){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p7"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p8){


	PHALCON_MM_GROW();
	phalcon_update_property_string(this_ptr, SL("_p0"), "more-lol" TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, p9){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p0"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p10){


	PHALCON_MM_GROW();
	phalcon_update_property_long(this_ptr, SL("_p0"), 14750 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, p11){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p0"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p12){

	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p1"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_p2"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_p3"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CONCAT_VVV(r0, t0, t1, t2);
	
	RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, p13){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p4"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_p5"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_p6"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_add_function(r1, r0, t2 TSRMLS_CC);
	
	RETURN_CTOR(r1);
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
	phalcon_read_property(&t0, this_ptr, SL("_p0"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, data TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_p0"), r0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, p15){

	zval *i = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	phalcon_update_property_string(this_ptr, SL("_p0"), "" TSRMLS_CC);
	
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	fs_fdd7_23:
		
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 30);
		
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, i, t0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_fdd7_23;
		}
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "p14", i, PHALCON_NO_CHECK);
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto fs_fdd7_23;
	fe_fdd7_23:
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_p0"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p16){

	zval *p = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(p);
	ZVAL_STRING(p, "_p0", 1);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "lol", 1);
	phalcon_update_property_zval_zval(this_ptr, p, t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Internal_Test, p17){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p0"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p18){

	zval *p = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(p);
	ZVAL_STRING(p, "_p0", 1);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property_zval(&t0, this_ptr, p, PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p19){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p8"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p20){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "hello", 1);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_p8"), PHALCON_NOISY TSRMLS_CC);
	phalcon_array_append(&t1, t0, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_p8"), t1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_p8"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t2);
}

PHP_METHOD(Phalcon_Internal_Test, p21){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p9"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, SL("_p9"), PHALCON_NOISY TSRMLS_CC);
	phalcon_array_append(&t0, a, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_p9"), t0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_p9"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p23){

	zval *a = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &a) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_p9"), a TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p9"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p24){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p9"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t0);
	increment_function(t0);
	phalcon_update_property_zval(this_ptr, SL("_p9"), t0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_p9"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p25){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p9"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t0);
	decrement_function(t0);
	phalcon_update_property_zval(this_ptr, SL("_p9"), t0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_p9"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p26){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p9"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t0);
	increment_function(t0);
	phalcon_update_property_zval(this_ptr, SL("_p9"), t0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_p9"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p27){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p9"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t0);
	decrement_function(t0);
	phalcon_update_property_zval(this_ptr, SL("_p9"), t0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_p9"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p28){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p9"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	ZVAL_ZVAL(t1, t0, 1, 0);
	increment_function(t0);
	phalcon_update_property_zval(this_ptr, SL("_p9"), t0 TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p29){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p9"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	ZVAL_ZVAL(t1, t0, 1, 0);
	decrement_function(t0);
	phalcon_update_property_zval(this_ptr, SL("_p9"), t0 TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, sp1){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Internal_Test"), SL("_sp1") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp2){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Internal_Test"), SL("_sp2") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp3){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Internal_Test"), SL("_sp3") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp4){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Internal_Test"), SL("_sp4") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp5){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Internal_Test"), SL("_sp5") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp6){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Internal_Test"), SL("_sp6") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp7){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Internal_Test"), SL("_sp7") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp8){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "i can't handle anymore", 1);
	phalcon_update_static_property(SL("Phalcon_Internal_Test"), SL("_sp1"), t0 TSRMLS_CC);
	PHALCON_OBSERVE_VAR(t1);
	phalcon_read_static_property(&t1, SL("Phalcon_Internal_Test"), SL("_sp1") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t1);
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
	phalcon_update_static_property(SL("Phalcon_Internal_Test"), SL("_sp1"), r0 TSRMLS_CC);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Internal_Test"), SL("_sp1") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
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

	phalcon_update_static_property(SL("Phalcon_Internal_Test"), SL("_sp1"), a TSRMLS_CC);
	phalcon_update_static_property(SL("Phalcon_Internal_Test"), SL("_sp2"), b TSRMLS_CC);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Internal_Test"), SL("_sp1") TSRMLS_CC);
	PHALCON_OBSERVE_VAR(t1);
	phalcon_read_static_property(&t1, SL("Phalcon_Internal_Test"), SL("_sp2") TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_add_function(r1, r0, c TSRMLS_CC);
	phalcon_update_static_property(SL("Phalcon_Internal_Test"), SL("_sp3"), r1 TSRMLS_CC);
	PHALCON_OBSERVE_VAR(t2);
	phalcon_read_static_property(&t2, SL("Phalcon_Internal_Test"), SL("_sp3") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t2);
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

	phalcon_update_static_property(SL("Phalcon_Internal_Test"), SL("_sp1"), a TSRMLS_CC);
	phalcon_update_static_property(SL("Phalcon_Internal_Test"), SL("_sp2"), b TSRMLS_CC);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Internal_Test"), SL("_sp1") TSRMLS_CC);
	PHALCON_OBSERVE_VAR(t1);
	phalcon_read_static_property(&t1, SL("Phalcon_Internal_Test"), SL("_sp2") TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_add_function(r1, r0, c TSRMLS_CC);
	phalcon_update_static_property(SL("Phalcon_Internal_Test"), SL("_sp3"), r1 TSRMLS_CC);
	PHALCON_OBSERVE_VAR(t2);
	phalcon_read_static_property(&t2, SL("Phalcon_Internal_Test"), SL("_sp3") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t2);
}

PHP_METHOD(Phalcon_Internal_Test, cc1){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_ce, SL("C1") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, cc2){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_ce, SL("C2") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, cc3){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_ce, SL("C3") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, cc4){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_ce, SL("C4") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, cc5){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_ce, SL("C5") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, cc6){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_ce, SL("C6") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
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
	phalcon_update_property_long(a, SL("b"), 15 TSRMLS_CC);
	eval_int = phalcon_isset_property(a, SL("b") TSRMLS_CC);
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
	phalcon_update_property_long(a, SL("c"), 10 TSRMLS_CC);
	eval_int = phalcon_isset_property(a, SL("b") TSRMLS_CC);
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
	phalcon_update_property_long(a, SL("c"), 10 TSRMLS_CC);
	eval_int = phalcon_isset_property(a, SL("b") TSRMLS_CC);
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
	add_next_index_stringl(a0, SL("hello"), 1);
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
	phalcon_update_property_string(config, SL("host"), "192.168.0.20" TSRMLS_CC);
	phalcon_update_property_string(config, SL("username"), "support" TSRMLS_CC);
	phalcon_update_property_string(config, SL("password"), "H45pov682v" TSRMLS_CC);
	phalcon_update_property_string(config, SL("name"), "demo" TSRMLS_CC);
	eval_int = phalcon_isset_property(config, SL("host") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, config, SL("host"), PHALCON_NOISY TSRMLS_CC);
		
		RETURN_CHECK_CTOR(t0);
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
	add_index_stringl(a1, 1, SL("hello"), 1);
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
	add_index_stringl(a1, 1, SL("hello"), 1);
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
	add_index_stringl(a1, 1, SL("hello"), 1);
	phalcon_array_append(&a0, a1, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	add_next_index_bool(a0, 0);
	phalcon_update_property_zval(this_ptr, SL("_p9"), a0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p9"), PHALCON_NOISY TSRMLS_CC);
	
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
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(index);
	ZVAL_STRING(index, "hello", 1);
	
	PHALCON_INIT_VAR(another_index);
	ZVAL_STRING(another_index, "lol", 1);
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, SL("_p9"), a0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_p9"), PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, index);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_p9"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, index, PHALCON_NOISY TSRMLS_CC);
		eval_int = phalcon_array_isset(r0, another_index);
		if (eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_LONG(1);
		} else {
			PHALCON_MM_RESTORE();
			RETURN_LONG(2);
		}
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
	
	RETURN_CTOR(a);
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
	phalcon_array_update_string(&a0, SL("lost"), &a1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	add_next_index_stringl(a0, SL("hello"), 1);
	PHALCON_CPY_WRT(a, a0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, a, SL("lost"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_SEPARATE_NMO(r0);
	phalcon_array_unset_long(r0, 1);
	
	RETURN_CTOR(a);
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
	add_next_index_stringl(a1, SL("hello"), 1);
	PHALCON_CPY_WRT(a, a1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, a, 0, PHALCON_NOISY TSRMLS_CC);
	PHALCON_SEPARATE_NMO(r0);
	phalcon_array_unset_long(r0, 1);
	
	RETURN_CTOR(b);
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
		ce0 = zend_fetch_class("stdclass", strlen("stdclass"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
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
	zval *r0 = NULL, *r1 = NULL;
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
		fes_fdd7_24:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_24;
		} else {
			PHALCON_INIT_VAR(k);
			PHALCON_GET_FOREACH_KEY(k, ah0, hp0);
		}
		PHALCON_INIT_VAR(v);
		ZVAL_ZVAL(v, *hd, 1, 0);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "t1", k, a, PHALCON_NO_CHECK);
		
		PHALCON_INIT_VAR(r0);
		
		PHALCON_INIT_VAR(r1);
		phalcon_array_fetch_long(&r1, a, 0, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CONCAT_VV(r0, k, r1);
		phalcon_concat_self(&m, r0 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_24;
		fee_fdd7_24:
		if(0){}
	} else {
		return;
	}
	
	RETURN_CTOR(m);
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
		PHALCON_OBSERVE_VAR(t2);
		phalcon_read_static_property(&t2, SL("Phalcon_Internal_Test"), SL("_sp0") TSRMLS_CC);
		
		RETURN_CHECK_CTOR(t2);
	} else {
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 15);
		PHALCON_ALLOC_ZVAL_MM(r2);
		mul_function(r2, b, t3 TSRMLS_CC);
		
		RETURN_CTOR(r2);
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
		phalcon_read_property(&t1, this_ptr, SL("_p0"), PHALCON_NOISY TSRMLS_CC);
		
		RETURN_CHECK_CTOR(t1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "sqrt", b);
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_add_function(r2, r1, a TSRMLS_CC);
		
		RETURN_CTOR(r2);
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
	
	phalcon_update_property_long(this_ptr, SL("_p0"), 0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(node, a0);
	ws_fdd7_25:
		if (0) {
			goto we_fdd7_25;
		}
		PHALCON_INIT_VAR(r0);
		mul_function(r0, a, b TSRMLS_CC);
		phalcon_update_static_property(SL("Phalcon_Internal_Test"), SL("_sp0"), r0 TSRMLS_CC);
		
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		
		PHALCON_INIT_VAR(r1);
		phalcon_add_function(r1, a, t0 TSRMLS_CC);
		PHALCON_CPY_WRT(a, r1);
		
		PHALCON_INIT_VAR(t1);
		phalcon_read_property(&t1, this_ptr, SL("_p0"), PHALCON_NOISY TSRMLS_CC);
		
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
			PHALCON_OBSERVE_VAR(t5);
			phalcon_read_static_property(&t5, SL("Phalcon_Internal_Test"), SL("_sp0") TSRMLS_CC);
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
		phalcon_read_property(&t7, this_ptr, SL("_p0"), PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_INIT_VAR(t8);
		ZVAL_LONG(t8, 3);
		
		PHALCON_INIT_VAR(r7);
		mul_function(r7, t7, t8 TSRMLS_CC);
		PHALCON_CPY_WRT(b, r7);
		
		PHALCON_INIT_VAR(t9);
		phalcon_read_property(&t9, this_ptr, SL("_p0"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_SEPARATE_NMO(t9);
		increment_function(t9);
		phalcon_update_property_zval(this_ptr, SL("_p0"), t9 TSRMLS_CC);
		
		PHALCON_INIT_VAR(t10);
		phalcon_read_property(&t10, this_ptr, SL("_p0"), PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_INIT_VAR(t11);
		ZVAL_LONG(t11, 10);
		
		PHALCON_INIT_VAR(r8);
		is_smaller_function(r8, t11, t10 TSRMLS_CC);
		if (zend_is_true(r8)) {
			goto we_fdd7_25;
		}
		goto ws_fdd7_25;
	we_fdd7_25:
	
	RETURN_CTOR(node);
}

PHP_METHOD(Phalcon_Internal_Test, t6){

	zval *a = NULL, *b = NULL, *c = NULL, *e = NULL, *i = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL, NULL };

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
	phalcon_update_static_property(SL("Phalcon_Internal_Test"), SL("_sp0"), i0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	fs_fdd7_26:
		
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, i, t0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_fdd7_26;
		}
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 5);
		PHALCON_INIT_VAR(r1);
		is_smaller_function(r1, i, t1 TSRMLS_CC);
		if (zend_is_true(r1)) {
			PHALCON_INIT_VAR(r2);
			phalcon_array_fetch_long(&r2, e, 1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_INIT_VAR(r3);
			PHALCON_OBSERVE_VAR(t2);
			phalcon_read_static_property(&t2, SL("Phalcon_Internal_Test"), SL("_sp0") TSRMLS_CC);
			p0[0] = t2;
			p0[1] = i;
			p0[2] = a;
			p0[3] = b;
			PHALCON_CALL_STATIC_PARAMS(r3, "phalcon_internal_testparent", "smp6", 4, p0);
			PHALCON_INIT_VAR(r4);
			phalcon_add_function(r4, r2, r3 TSRMLS_CC);
			phalcon_array_update_long(&e, 1, &r4, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(r5);
			phalcon_array_fetch_long(&r5, e, 1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_INIT_VAR(r6);
			PHALCON_OBSERVE_VAR(t3);
			phalcon_read_static_property(&t3, SL("Phalcon_Internal_Test"), SL("_sp0") TSRMLS_CC);
			p1[0] = t3;
			PHALCON_INIT_VAR(r7);
			phalcon_array_fetch_long(&r7, e, 0, PHALCON_NOISY TSRMLS_CC);
			PHALCON_SEPARATE_NMO(r7);
			PHALCON_INIT_VAR(t4);
			ZVAL_ZVAL(t4, r7, 1, 0);
			increment_function(r7);
			phalcon_array_update_long(&e, 0, &r7, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			p1[1] = t4;
			p1[2] = b;
			p1[3] = c;
			PHALCON_CALL_SELF_PARAMS(r6, this_ptr, "smp6", 4, p1);
			PHALCON_INIT_VAR(r8);
			phalcon_add_function(r8, r5, r6 TSRMLS_CC);
			phalcon_array_update_long(&e, 1, &r8, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto fs_fdd7_26;
	fe_fdd7_26:
	
	PHALCON_ALLOC_ZVAL_MM(r9);
	phalcon_array_fetch_long(&r9, e, 1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r10);
	PHALCON_OBSERVE_VAR(t5);
	phalcon_read_static_property(&t5, SL("Phalcon_Internal_Test"), SL("_sp0") TSRMLS_CC);
	PHALCON_CALL_METHOD(r10, t5, "mp7", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r11);
	phalcon_add_function(r11, r9, r10 TSRMLS_CC);
	
	RETURN_CTOR(r11);
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
	zval *p0[] = { NULL, NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL, NULL }, *p2[] = { NULL, NULL, NULL, NULL };

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
	phalcon_update_static_property(SL("Phalcon_Internal_Test"), SL("_sp0"), i0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	fs_fdd7_27:
		
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, i, t0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_fdd7_27;
		}
		PHALCON_CPY_WRT(j, a);
		fs_fdd7_28:
			PHALCON_INIT_VAR(t1);
			ZVAL_LONG(t1, 0);
			PHALCON_INIT_VAR(r1);
			is_smaller_function(r1, t1, j TSRMLS_CC);
			if (!zend_is_true(r1)) {
				goto fe_fdd7_28;
			}
			PHALCON_INIT_VAR(t2);
			ZVAL_LONG(t2, 5);
			PHALCON_INIT_VAR(r2);
			is_smaller_function(r2, i, t2 TSRMLS_CC);
			if (zend_is_true(r2)) {
				PHALCON_INIT_VAR(r3);
				phalcon_array_fetch_long(&r3, e, 1, PHALCON_NOISY TSRMLS_CC);
				PHALCON_INIT_VAR(r4);
				PHALCON_OBSERVE_VAR(t3);
				phalcon_read_static_property(&t3, SL("Phalcon_Internal_Test"), SL("_sp0") TSRMLS_CC);
				p0[0] = t3;
				p0[1] = i;
				p0[2] = a;
				p0[3] = b;
				PHALCON_CALL_STATIC_PARAMS(r4, "phalcon_internal_testparent", "smp6", 4, p0);
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
					PHALCON_OBSERVE_VAR(t5);
					phalcon_read_static_property(&t5, SL("Phalcon_Internal_Test"), SL("_sp0") TSRMLS_CC);
					p1[0] = t5;
					PHALCON_INIT_VAR(r9);
					phalcon_array_fetch_long(&r9, e, 0, PHALCON_NOISY TSRMLS_CC);
					PHALCON_SEPARATE_NMO(r9);
					decrement_function(r9);
					phalcon_array_update_long(&e, 0, &r9, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
					p1[1] = r9;
					p1[2] = b;
					p1[3] = j;
					PHALCON_CALL_SELF_PARAMS(r8, this_ptr, "smp6", 4, p1);
					PHALCON_INIT_VAR(r10);
					phalcon_add_function(r10, r7, r8 TSRMLS_CC);
					phalcon_array_update_long(&e, 1, &r10, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(r11);
					phalcon_array_fetch_long(&r11, e, 1, PHALCON_NOISY TSRMLS_CC);
					PHALCON_INIT_VAR(r12);
					PHALCON_OBSERVE_VAR(t6);
					phalcon_read_static_property(&t6, SL("Phalcon_Internal_Test"), SL("_sp0") TSRMLS_CC);
					p2[0] = t6;
					PHALCON_INIT_VAR(r13);
					phalcon_array_fetch_long(&r13, e, 0, PHALCON_NOISY TSRMLS_CC);
					PHALCON_SEPARATE_NMO(r13);
					PHALCON_INIT_VAR(t7);
					ZVAL_ZVAL(t7, r13, 1, 0);
					increment_function(r13);
					phalcon_array_update_long(&e, 0, &r13, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
					p2[1] = t7;
					p2[2] = a;
					p2[3] = j;
					PHALCON_CALL_SELF_PARAMS(r12, this_ptr, "smp6", 4, p2);
					PHALCON_INIT_VAR(r14);
					phalcon_add_function(r14, r11, r12 TSRMLS_CC);
					phalcon_array_update_long(&e, 1, &r14, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				}
			}
			PHALCON_SEPARATE(j);
			decrement_function(j);
			goto fs_fdd7_28;
		fe_fdd7_28:
		if(0){}
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto fs_fdd7_27;
	fe_fdd7_27:
	
	PHALCON_ALLOC_ZVAL_MM(r15);
	phalcon_array_fetch_long(&r15, e, 1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r16);
	PHALCON_OBSERVE_VAR(t8);
	phalcon_read_static_property(&t8, SL("Phalcon_Internal_Test"), SL("_sp0") TSRMLS_CC);
	PHALCON_CALL_METHOD(r16, t8, "mp7", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r17);
	phalcon_add_function(r17, r15, r16 TSRMLS_CC);
	
	RETURN_CTOR(r17);
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
	add_next_index_stringl(a0, SL("cedula"), 1);
	add_next_index_stringl(a0, SL("nombre"), 1);
	add_next_index_stringl(a0, SL("saldo"), 1);
	add_next_index_stringl(a0, SL("estado"), 1);
	PHALCON_CPY_WRT(not_null, a0);
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	phalcon_update_property_zval(this_ptr, SL("_p0"), a1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(record, i0);
	phalcon_update_property_string(record, SL("cedula"), "hello" TSRMLS_CC);
	phalcon_update_property_null(record, SL("nombre") TSRMLS_CC);
	phalcon_update_property_null(record, SL("saldo") TSRMLS_CC);
	phalcon_update_property_null(record, SL("estado") TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_count(r0, not_null TSRMLS_CC);
	PHALCON_CPY_WRT(num_fields, r0);
	
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	fs_fdd7_29:
		
		PHALCON_INIT_VAR(r1);
		is_smaller_function(r1, i, num_fields TSRMLS_CC);
		if (!zend_is_true(r1)) {
			goto fe_fdd7_29;
		}
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch(&r2, not_null, i, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(field, r2);
		
		PHALCON_INIT_VAR(t0);
		phalcon_read_property_zval(&t0, record, field, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(value, t0);
		
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "_id", 1);
		
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "", 1);
		
		PHALCON_INIT_VAR(r3);
		phalcon_fast_str_replace(r3, c0, c1, field TSRMLS_CC);
		PHALCON_CPY_WRT(human_field, r3);
		
		PHALCON_INIT_VAR(i1);
		object_init_ex(i1, phalcon_model_message_ce);
		
		PHALCON_INIT_VAR(r4);
		PHALCON_CONCAT_VS(r4, human_field, " is required");
		
		PHALCON_INIT_VAR(c2);
		ZVAL_STRING(c2, "PresenceOf", 1);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(i1, "__construct", r4, field, c2, PHALCON_CHECK);
		PHALCON_CPY_WRT(message, i1);
		
		PHALCON_INIT_VAR(t1);
		phalcon_read_property(&t1, this_ptr, SL("_p0"), PHALCON_NOISY TSRMLS_CC);
		phalcon_array_append(&t1, message, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_p0"), t1 TSRMLS_CC);
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto fs_fdd7_29;
	fe_fdd7_29:
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_p0"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t2);
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
	add_next_index_stringl(a0, SL("cedula"), 1);
	add_next_index_stringl(a0, SL("nombre"), 1);
	add_next_index_stringl(a0, SL("saldo"), 1);
	add_next_index_stringl(a0, SL("estado"), 1);
	PHALCON_CPY_WRT(attributes, a0);
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_assoc_bool_ex(a1, SL("saldo")+1, 1);
	PHALCON_CPY_WRT(data_type_numeric, a1);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(record, i0);
	phalcon_update_property_string(record, SL("cedula"), "hello" TSRMLS_CC);
	phalcon_update_property_string(record, SL("nombre"), "LOL" TSRMLS_CC);
	phalcon_update_property_long(record, SL("saldo"), 0 TSRMLS_CC);
	phalcon_update_property_string(record, SL("estado"), "X" TSRMLS_CC);
	
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	PHALCON_CPY_WRT(values, a2);
	if (phalcon_valid_foreach(attributes TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(attributes);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_30:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_30;
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
				PHALCON_CONCAT_SVS(r3, "'", value, "'");
				phalcon_array_append(&values, r3, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_30;
		fee_fdd7_30:
		if(0){}
	} else {
		return;
	}
	
	RETURN_CTOR(values);
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
	phalcon_update_property_string(this_ptr, SL("_p2"), "lol" TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, SL("_p4"), 0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_internal_testdummy_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", this_ptr, PHALCON_CHECK);
	PHALCON_CPY_WRT(dummy, i0);
	ws_fdd7_31:
		
		PHALCON_INIT_VAR(t0);
		phalcon_read_property(&t0, this_ptr, SL("_p4"), PHALCON_NOISY TSRMLS_CC);
		if (zend_is_true(t0)) {
			goto we_fdd7_31;
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
			phalcon_update_property_bool(this_ptr, SL("_p4"), 1 TSRMLS_CC);
		}
		goto ws_fdd7_31;
	we_fdd7_31:
	phalcon_update_property_bool(this_ptr, SL("_p4"), 1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, SL("_p2"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t3);
}

PHP_METHOD(Phalcon_Internal_Test, t12){

	zval *uri = NULL, *parts = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(uri);
	ZVAL_STRING(uri, "controller/action", 1);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "/", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_explode(r0, c0, uri TSRMLS_CC);
	PHALCON_CPY_WRT(parts, r0);
	eval_int = phalcon_array_isset_long(parts, 0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_long(&r1, parts, 0, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_filter_alphanum(r2, r1);
		phalcon_update_property_zval(this_ptr, SL("_p1"), r2 TSRMLS_CC);
		PHALCON_SEPARATE(parts);
		phalcon_array_unset_long(parts, 0);
	}
	
	eval_int = phalcon_array_isset_long(parts, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_long(&r3, parts, 1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_filter_alphanum(r4, r3);
		phalcon_update_property_zval(this_ptr, SL("_p2"), r4 TSRMLS_CC);
		PHALCON_SEPARATE(parts);
		phalcon_array_unset_long(parts, 1);
	}
	
	phalcon_update_property_bool(this_ptr, SL("_p4"), 0 TSRMLS_CC);
	
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
	add_assoc_stringl_ex(a1, SL("sup")+1, SL("hello1"), 1);
	phalcon_array_update_string(&a0, SL("wish"), &a1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	add_assoc_stringl_ex(a2, SL("xup")+1, SL("hello2"), 1);
	phalcon_array_update_string(&a0, SL("be"), &a2, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	add_assoc_stringl_ex(a3, SL("zup")+1, SL("hello3"), 1);
	phalcon_array_update_string(&a0, SL("today"), &a3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_CPY_WRT(b, a0);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(o, i0);
	if (phalcon_valid_foreach(b TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(b);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_32:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_32;
		} else {
			PHALCON_INIT_VAR(k);
			PHALCON_GET_FOREACH_KEY(k, ah0, hp0);
		}
		PHALCON_INIT_VAR(v);
		ZVAL_ZVAL(v, *hd, 1, 0);
		if (Z_TYPE_P(v) == IS_ARRAY) { 
			PHALCON_INIT_VAR(i1);
			object_init(i1);
			phalcon_update_property_zval_zval(o, k, i1 TSRMLS_CC);
			if (phalcon_valid_foreach(v TSRMLS_CC)) {
				ah1 = Z_ARRVAL_P(v);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_fdd7_33:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee_fdd7_33;
				} else {
					PHALCON_INIT_VAR(kv);
					PHALCON_GET_FOREACH_KEY(kv, ah1, hp1);
				}
				PHALCON_INIT_VAR(vv);
				ZVAL_ZVAL(vv, *hd, 1, 0);
				PHALCON_INIT_VAR(t0);
				phalcon_read_property_zval(&t0, o, k, PHALCON_NOISY TSRMLS_CC);
				phalcon_update_property_zval_zval(t0, kv, vv TSRMLS_CC);
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_fdd7_33;
				fee_fdd7_33:
				if(0){}
			} else {
				return;
			}
		} else {
			phalcon_update_property_zval_zval(o, k, v TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_32;
		fee_fdd7_32:
		if(0){}
	} else {
		return;
	}
	
	RETURN_CTOR(o);
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
	phalcon_update_property_zval(p, SL("a"), a0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	fs_fdd7_34:
		
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		
		PHALCON_INIT_VAR(r0);
		is_smaller_function(r0, i, t0 TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto fe_fdd7_34;
		}
		PHALCON_INIT_VAR(i1);
		object_init(i1);
		PHALCON_CPY_WRT(f, i1);
		
		PHALCON_INIT_VAR(t1);
		phalcon_read_property(&t1, p, SL("a"), PHALCON_NOISY TSRMLS_CC);
		phalcon_array_append(&t1, f, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
		phalcon_update_property_zval(p, SL("a"), t1 TSRMLS_CC);
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto fs_fdd7_34;
	fe_fdd7_34:
	
	RETURN_CTOR(p);
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

	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Internal_Test"), SL("_sp0") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_array_fetch(&t1, t0, name, PHALCON_SILENT TSRMLS_CC);
	if (zend_is_true(t1)) {
		PHALCON_OBSERVE_VAR(t2);
		phalcon_read_static_property(&t2, SL("Phalcon_Internal_Test"), SL("_sp0") TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_array_fetch(&t3, t2, name, PHALCON_NOISY TSRMLS_CC);
		
		RETURN_CHECK_CTOR(t3);
	} else {
		phalcon_get_global(&g0, SL("_POST")+1 TSRMLS_CC);
		eval_int = phalcon_array_isset(g0, name);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_CALL_FUNC(r0, "get_magic_quotes_gpc");
			if (!zend_is_true(r0)) {
				PHALCON_ALLOC_ZVAL_MM(r1);
				phalcon_array_fetch(&r1, g0, name, PHALCON_NOISY TSRMLS_CC);
				
				RETURN_CHECK_CTOR(r1);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r2);
				phalcon_array_fetch(&r2, g0, name, PHALCON_NOISY TSRMLS_CC);
				PHALCON_ALLOC_ZVAL_MM(r3);
				PHALCON_CALL_FUNC_PARAMS_1(r3, "stripslashes", r2);
				RETURN_DZVAL(r3);
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
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, b, "f2", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, a, "f2", PHALCON_NO_CHECK);
	PHALCON_CONCAT_VV(r0, r1, r2);
	
	RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, t17){

	zval *robots = NULL, *result_query = NULL, *robot = NULL;
	zval *a0 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL, *c4 = NULL;

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
	PHALCON_CALL_FUNC_PARAMS_3_NORETURN("mysql_connect", c0, c1, c2);
	
	PHALCON_INIT_VAR(c3);
	ZVAL_STRING(c3, "phalcon_test", 1);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("mysql_select_db", c3);
	
	PHALCON_INIT_VAR(c4);
	ZVAL_STRING(c4, "SELECT * FROM robots", 1);
	
	PHALCON_INIT_VAR(result_query);
	PHALCON_CALL_FUNC_PARAMS_1(result_query, "mysql_query", c4);
	ws_fdd7_35:
		
		PHALCON_INIT_VAR(robot);
		PHALCON_CALL_FUNC_PARAMS_1(robot, "mysql_fetch_array", result_query);
		if (!zend_is_true(robot)) {
			goto we_fdd7_35;
		}
		phalcon_array_append(&robots, robot, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		goto ws_fdd7_35;
	we_fdd7_35:
	
	RETURN_CTOR(robots);
}

