
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
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

PHP_METHOD(Phalcon_Internal_Test, __construct){

	zval *a0 = NULL, *a1 = NULL;

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_internal_test_class_entry, this_ptr, "_p8", strlen("_p8"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	zend_update_property(phalcon_internal_test_class_entry, this_ptr, "_p9", strlen("_p9"), a1 TSRMLS_CC);
	
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

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_LONG(v0, 5);
	PHALCON_RETURN_NCTOR(v0);
}

PHP_METHOD(Phalcon_Internal_Test, e5){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_LONG(v0, 5);
	PHALCON_CPY_WRT(v1, v0);
	PHALCON_CPY_WRT(v2, v1);
	PHALCON_RETURN_NCTOR(v2);
}

PHP_METHOD(Phalcon_Internal_Test, e6){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_RETURN_CHECK_CTOR(v0);
}

PHP_METHOD(Phalcon_Internal_Test, e7){

	zval *v0 = NULL, *v1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_CPY_WRT(v1, v0);
	PHALCON_RETURN_CHECK_CTOR(v1);
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

	zval *v0 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v0, i0);
	phalcon_update_property_long(v0, "uno", strlen("uno"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init(i1);
	phalcon_update_property_zval(v0, "subA", strlen("subA"), i1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_long(t0, "dos", strlen("dos"), 2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, v0, "uno", sizeof("uno")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, t2, "dos", sizeof("dos")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, t1, t3 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, e14){

	zval *v0 = NULL, *v1 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v1, i0);
	phalcon_update_property_zval(v1, "val", strlen("val"), v0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, v1, "val", sizeof("val")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, e15){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v0, i0);
	phalcon_update_property_string(v0, "val", strlen("val"), "hullo" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, v0, "val", sizeof("val")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, e13){

	zval *v0 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v0, i0);
	phalcon_update_property_long(v0, "uno", strlen("uno"), 1 TSRMLS_CC);
	phalcon_update_property_long(v0, "dos", strlen("dos"), 2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init(i1);
	phalcon_update_property_zval(v0, "subA", strlen("subA"), i1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_long(t0, "uno", strlen("uno"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_long(t1, "dos", strlen("dos"), 2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i2);
	object_init(i2);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_zval(t2, "subSubA", strlen("subSubA"), i2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, t3, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_long(t4, "uno", strlen("uno"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_read_property(&t5, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t6);
	phalcon_read_property(&t6, t5, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_update_property_long(t6, "dos", strlen("dos"), 2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t7);
	phalcon_read_property(&t7, v0, "uno", sizeof("uno")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t8);
	phalcon_read_property(&t8, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t9);
	phalcon_read_property(&t9, t8, "uno", sizeof("uno")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, t7, t9 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t10);
	phalcon_read_property(&t10, v0, "subA", sizeof("subA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t11);
	phalcon_read_property(&t11, t10, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t12);
	phalcon_read_property(&t12, t11, "uno", sizeof("uno")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	mul_function(r1, r0, t12 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r1);
}

PHP_METHOD(Phalcon_Internal_Test, o1){

	zval *v0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_LONG(v0, 0);
	} else {
		PHALCON_SEPARATE_PARAM(v0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	ZVAL_ZVAL(t0, v0, 1, 0);
	increment_function(v0);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, o2){

	zval *v0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v0);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	ZVAL_ZVAL(t0, v0, 1, 0);
	decrement_function(v0);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, o3){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_LONG(v0, 1);
	}
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, v0, t0 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o4){

	zval *v0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, v0, v0 TSRMLS_CC);
	PHALCON_CPY_WRT(v0, r0);
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o5){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, v0, v1 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o6){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	sub_function(r0, v0, v1 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o7){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, v0, v1 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o8){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	div_function(r0, v0, v1 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o9){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	mod_function(r0, v0, v1 TSRMLS_CC);
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
	ZVAL_STRING(t0, "10", 0);
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
	ZVAL_STRING(t1, "5", 0);
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
	ZVAL_STRING(t1, "7", 0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o18){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "100", 0);
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
	ZVAL_STRING(t1, "5", 0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	mod_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, o20){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(v1);
	ZVAL_LONG(v1, 150);
	PHALCON_INIT_VAR(v2);
	ZVAL_LONG(v2, 250);
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, v1, v2 TSRMLS_CC);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 100);
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_add_function(r1, r0, t0 TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 100);
	PHALCON_ALLOC_ZVAL_MM(r2);
	div_function(r2, r1, t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	sub_function(r3, r2, v2 TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r3);
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 5);
	PHALCON_ALLOC_ZVAL_MM(r4);
	mul_function(r4, v2, t2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r5);
	div_function(r5, r4, v0 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r5);
	PHALCON_ALLOC_ZVAL_MM(r6);
	div_function(r6, v1, v2 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r6);
}

PHP_METHOD(Phalcon_Internal_Test, o21){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_STRING(v0, "memory", 1);
	PHALCON_INIT_VAR(v1);
	ZVAL_STRING(v1, "yes", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "no, ", v0);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CONCAT_LEFT(r1, "leaks, ", v1);
	PHALCON_CPY_WRT(v3, r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, v2, v3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	concat_function(r3, r2, v1 TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r3);
	PHALCON_RETURN_CTOR(v1);
}

PHP_METHOD(Phalcon_Internal_Test, o22){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_LONG(v0, 0);
	PHALCON_INIT_VAR(v1);
	ZVAL_LONG(v1, 0);
	fs_fdd7_0:
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 25);
	PHALCON_INIT_VAR(r0);
	is_smaller_function(r0, v1, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe_fdd7_0;
	}
	PHALCON_INIT_VAR(r1);
	concat_function(r1, v0, v1 TSRMLS_CC);
	PHALCON_CPY_WRT(v0, r1);
	PHALCON_SEPARATE(v1);
	increment_function(v1);
	goto fs_fdd7_0;
	fe_fdd7_0:
	PHALCON_RETURN_CHECK_CTOR(v0);
}

PHP_METHOD(Phalcon_Internal_Test, o23){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_LONG(v0, 0);
	PHALCON_INIT_VAR(v1);
	ZVAL_LONG(v1, 0);
	fs_fdd7_1:
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 25);
	PHALCON_INIT_VAR(r0);
	is_smaller_function(r0, v1, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe_fdd7_1;
	}
	PHALCON_INIT_VAR(r1);
	PHALCON_CONCAT_RIGHT(r1, v1, "-");
	PHALCON_CPY_WRT(v2, r1);
	PHALCON_INIT_VAR(r2);
	concat_function(r2, v0, v2 TSRMLS_CC);
	PHALCON_CPY_WRT(v0, r2);
	PHALCON_INIT_VAR(v2);
	ZVAL_STRING(v2, "nope", 1);
	PHALCON_SEPARATE(v1);
	increment_function(v1);
	goto fs_fdd7_1;
	fe_fdd7_1:
	PHALCON_RETURN_CHECK_CTOR(v0);
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

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "well", 0);
	Z_ADDREF_P(t0);
	if (Z_REFCOUNT_P(v0) > 1) {
		zval *new_zv;
		Z_DELREF_P(v0);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v0);
		v0 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update_long(v0, 0, t0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, a3){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "LOL", 0);
	Z_ADDREF_P(t0);
	if (Z_REFCOUNT_P(v0) > 1) {
		zval *new_zv;
		Z_DELREF_P(v0);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v0);
		v0 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update_long(v0, 0, t0 TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	Z_ADDREF_P(t1);
	if (Z_REFCOUNT_P(v0) > 1) {
		zval *new_zv;
		Z_DELREF_P(v0);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v0);
		v0 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update_string(v0, "LOL", strlen("LOL"), t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, v0, "LOL", strlen("LOL"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, a4){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	if (Z_TYPE_P(v0) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_array_fetch_long(&t1, v0, 1, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t1) > 1) {
		zval *new_zv;
		Z_DELREF_P(t1);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t1);
		t1 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update_long(v0, 1, t1 TSRMLS_CC);
	}
	Z_ADDREF_P(t1);
	if (Z_TYPE_P(t1) != IS_ARRAY) {
		convert_to_array(t1);
		phalcon_array_update_long(v0, 1, t1 TSRMLS_CC);
	}
	if (Z_TYPE_P(t1) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_array_fetch_string(&t2, t1, "LOL", strlen("LOL"), PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t2) > 1) {
		zval *new_zv;
		Z_DELREF_P(t2);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t2);
		t2 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update_string(t1, "LOL", strlen("LOL"), t2 TSRMLS_CC);
	}
	Z_ADDREF_P(t2);
	if (Z_TYPE_P(t2) != IS_ARRAY) {
		convert_to_array(t2);
		phalcon_array_update_string(t1, "LOL", strlen("LOL"), t2 TSRMLS_CC);
	}
	if (Z_TYPE_P(t2) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_array_fetch_long(&t3, t2, 5, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t3) > 1) {
		zval *new_zv;
		Z_DELREF_P(t3);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t3);
		t3 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update_long(t2, 5, t3 TSRMLS_CC);
	}
	Z_ADDREF_P(t3);
	if (Z_TYPE_P(t3) != IS_ARRAY) {
		convert_to_array(t3);
		phalcon_array_update_long(t2, 5, t3 TSRMLS_CC);
	}
	Z_ADDREF_P(t0);
	phalcon_array_update_string(t3, "YEAH", strlen("YEAH"), t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, r0, "LOL", strlen("LOL"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, r1, 5, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch_string(&r3, r2, "YEAH", strlen("YEAH"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r3);
}

PHP_METHOD(Phalcon_Internal_Test, a5){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "LOL", 0);
	Z_ADDREF_P(t0);
	if (Z_REFCOUNT_P(v0) > 1) {
		zval *new_zv;
		Z_DELREF_P(v0);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v0);
		v0 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update_long(v0, 0, t0 TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	Z_ADDREF_P(t1);
	if (Z_REFCOUNT_P(v0) > 1) {
		zval *new_zv;
		Z_DELREF_P(v0);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v0);
		v0 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update_string(v0, "LOL", strlen("LOL"), t1 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_CPY_WRT(v1, a1);
	PHALCON_INIT_VAR(t2);
	ZVAL_STRING(t2, "LOL", 0);
	Z_ADDREF_P(t2);
	if (Z_REFCOUNT_P(v1) > 1) {
		zval *new_zv;
		Z_DELREF_P(v1);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v1);
		v1 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update_string(v1, "LOL", strlen("LOL"), t2 TSRMLS_CC);
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 0);
	Z_ADDREF_P(t3);
	if (Z_REFCOUNT_P(v1) > 1) {
		zval *new_zv;
		Z_DELREF_P(v1);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v1);
		v1 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update_long(v1, 0, t3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, v0, "LOL", strlen("LOL"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_add_function(r2, r0, r1 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r2);
}

PHP_METHOD(Phalcon_Internal_Test, a6){

	zval *v0 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	Z_ADDREF_P(a1);
	if (Z_REFCOUNT_P(v0) > 1) {
		zval *new_zv;
		Z_DELREF_P(v0);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v0);
		v0 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update_long(v0, 1, a1 TSRMLS_CC);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	if (Z_TYPE_P(v0) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_array_fetch_long(&t1, v0, 1, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t1) > 1) {
		zval *new_zv;
		Z_DELREF_P(t1);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t1);
		t1 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update_long(v0, 1, t1 TSRMLS_CC);
	}
	Z_ADDREF_P(t1);
	if (Z_TYPE_P(t1) != IS_ARRAY) {
		convert_to_array(t1);
		phalcon_array_update_long(v0, 1, t1 TSRMLS_CC);
	}
	Z_ADDREF_P(t0);
	phalcon_array_update_string(t1, "LOL", strlen("LOL"), t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, r0, "LOL", strlen("LOL"), PHALCON_NOISY_FETCH TSRMLS_CC);
	zend_print_zval(r1, 0);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, a7){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "LOL", 0);
	Z_ADDREF_P(t0);
	if (Z_REFCOUNT_P(v0) > 1) {
		zval *new_zv;
		Z_DELREF_P(v0);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v0);
		v0 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update_long(v0, 0, t0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	Z_ADDREF_P(a1);
	if (Z_REFCOUNT_P(v0) > 1) {
		zval *new_zv;
		Z_DELREF_P(v0);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v0);
		v0 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update_long(v0, 1, a1 TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	if (Z_TYPE_P(v0) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_array_fetch_long(&t2, v0, 1, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t2) > 1) {
		zval *new_zv;
		Z_DELREF_P(t2);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t2);
		t2 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update_long(v0, 1, t2 TSRMLS_CC);
	}
	Z_ADDREF_P(t2);
	if (Z_TYPE_P(t2) != IS_ARRAY) {
		convert_to_array(t2);
		phalcon_array_update_long(v0, 1, t2 TSRMLS_CC);
	}
	Z_ADDREF_P(t1);
	phalcon_array_update_string(t2, "LOL", strlen("LOL"), t1 TSRMLS_CC);
	PHALCON_INIT_VAR(t3);
	ZVAL_LONG(t3, 0);
	Z_ADDREF_P(t3);
	if (Z_REFCOUNT_P(v0) > 1) {
		zval *new_zv;
		Z_DELREF_P(v0);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v0);
		v0 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update_string(v0, "LOL", strlen("LOL"), t3 TSRMLS_CC);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	PHALCON_CPY_WRT(v1, a2);
	PHALCON_INIT_VAR(t4);
	ZVAL_STRING(t4, "LOL", 0);
	Z_ADDREF_P(t4);
	if (Z_REFCOUNT_P(v1) > 1) {
		zval *new_zv;
		Z_DELREF_P(v1);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v1);
		v1 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update_string(v1, "LOL", strlen("LOL"), t4 TSRMLS_CC);
	PHALCON_INIT_VAR(t5);
	ZVAL_LONG(t5, 0);
	Z_ADDREF_P(t5);
	if (Z_REFCOUNT_P(v1) > 1) {
		zval *new_zv;
		Z_DELREF_P(v1);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v1);
		v1 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update_long(v1, 0, t5 TSRMLS_CC);
	PHALCON_INIT_VAR(t6);
	ZVAL_LONG(t6, 1);
	if (Z_TYPE_P(v1) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t7);
		phalcon_array_fetch_long(&t7, v1, 1, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t7) > 1) {
		zval *new_zv;
		Z_DELREF_P(t7);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t7);
		t7 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update_long(v1, 1, t7 TSRMLS_CC);
	}
	Z_ADDREF_P(t7);
	if (Z_TYPE_P(t7) != IS_ARRAY) {
		convert_to_array(t7);
		phalcon_array_update_long(v1, 1, t7 TSRMLS_CC);
	}
	Z_ADDREF_P(t6);
	phalcon_array_update_string(t7, "LOL", strlen("LOL"), t6 TSRMLS_CC);
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	PHALCON_CPY_WRT(v2, a3);
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	Z_ADDREF_P(a4);
	if (Z_REFCOUNT_P(v2) > 1) {
		zval *new_zv;
		Z_DELREF_P(v2);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v2);
		v2 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update_long(v2, 0, a4 TSRMLS_CC);
	PHALCON_INIT_VAR(a5);
	array_init(a5);
	if (Z_TYPE_P(v2) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t8);
		phalcon_array_fetch_long(&t8, v2, 0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t8) > 1) {
		zval *new_zv;
		Z_DELREF_P(t8);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t8);
		t8 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update_long(v2, 0, t8 TSRMLS_CC);
	}
	Z_ADDREF_P(t8);
	if (Z_TYPE_P(t8) != IS_ARRAY) {
		convert_to_array(t8);
		phalcon_array_update_long(v2, 0, t8 TSRMLS_CC);
	}
	Z_ADDREF_P(a5);
	phalcon_array_update_long(t8, 0, a5 TSRMLS_CC);
	PHALCON_INIT_VAR(a6);
	array_init(a6);
	if (Z_TYPE_P(v2) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t9);
		phalcon_array_fetch_long(&t9, v2, 0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t9) > 1) {
		zval *new_zv;
		Z_DELREF_P(t9);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t9);
		t9 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update_long(v2, 0, t9 TSRMLS_CC);
	}
	Z_ADDREF_P(t9);
	if (Z_TYPE_P(t9) != IS_ARRAY) {
		convert_to_array(t9);
		phalcon_array_update_long(v2, 0, t9 TSRMLS_CC);
	}
	if (Z_TYPE_P(t9) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t10);
		phalcon_array_fetch_long(&t10, t9, 0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t10) > 1) {
		zval *new_zv;
		Z_DELREF_P(t10);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t10);
		t10 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update_long(t9, 0, t10 TSRMLS_CC);
	}
	Z_ADDREF_P(t10);
	if (Z_TYPE_P(t10) != IS_ARRAY) {
		convert_to_array(t10);
		phalcon_array_update_long(t9, 0, t10 TSRMLS_CC);
	}
	Z_ADDREF_P(a6);
	phalcon_array_update_long(t10, 0, a6 TSRMLS_CC);
	PHALCON_INIT_VAR(t11);
	ZVAL_LONG(t11, 1);
	if (Z_TYPE_P(v2) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t12);
		phalcon_array_fetch_long(&t12, v2, 0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t12) > 1) {
		zval *new_zv;
		Z_DELREF_P(t12);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t12);
		t12 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update_long(v2, 0, t12 TSRMLS_CC);
	}
	Z_ADDREF_P(t12);
	if (Z_TYPE_P(t12) != IS_ARRAY) {
		convert_to_array(t12);
		phalcon_array_update_long(v2, 0, t12 TSRMLS_CC);
	}
	if (Z_TYPE_P(t12) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t13);
		phalcon_array_fetch_long(&t13, t12, 0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t13) > 1) {
		zval *new_zv;
		Z_DELREF_P(t13);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t13);
		t13 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update_long(t12, 0, t13 TSRMLS_CC);
	}
	Z_ADDREF_P(t13);
	if (Z_TYPE_P(t13) != IS_ARRAY) {
		convert_to_array(t13);
		phalcon_array_update_long(t12, 0, t13 TSRMLS_CC);
	}
	if (Z_TYPE_P(t13) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t14);
		phalcon_array_fetch_long(&t14, t13, 0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t14) > 1) {
		zval *new_zv;
		Z_DELREF_P(t14);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t14);
		t14 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update_long(t13, 0, t14 TSRMLS_CC);
	}
	Z_ADDREF_P(t14);
	if (Z_TYPE_P(t14) != IS_ARRAY) {
		convert_to_array(t14);
		phalcon_array_update_long(t13, 0, t14 TSRMLS_CC);
	}
	Z_ADDREF_P(t11);
	phalcon_array_update_string(t14, "LOL", strlen("LOL"), t11 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, v1, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, r0, "LOL", strlen("LOL"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch_string(&r3, r2, "LOL", strlen("LOL"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r4);
	mul_function(r4, r1, r3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r5);
	phalcon_array_fetch_long(&r5, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r6);
	phalcon_array_fetch_long(&r6, r5, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r7);
	phalcon_array_fetch_long(&r7, r6, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r8);
	phalcon_array_fetch_string(&r8, r7, "LOL", strlen("LOL"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r9);
	mul_function(r9, r4, r8 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r9);
}

PHP_METHOD(Phalcon_Internal_Test, a10){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_assoc_long_ex(a0, "hello1", strlen("hello1")+1, 1);
	add_assoc_long_ex(a0, "hello2", strlen("hello2")+1, 2);
	add_assoc_long_ex(a0, "hello3", strlen("hello3")+1, 3);
	PHALCON_CPY_WRT(v0, a0);
	if (Z_TYPE_P(v0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ALLOC_HASHTABLE(ah0);
		zend_hash_init(ah0, 0, NULL, NULL, 0);
		zend_hash_copy(ah0, Z_ARRVAL_P(v0), NULL, NULL, sizeof(zval*));
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_2;
		} else {
			PHALCON_INIT_VAR(v2);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v2, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v2, num);
				}
			}
		}
		PHALCON_INIT_VAR(v1);
		ZVAL_ZVAL(v1, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch(&r0, v0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 100);
		PHALCON_INIT_VAR(r1);
		phalcon_add_function(r1, r0, t0 TSRMLS_CC);
		Z_ADDREF_P(r1);
		if (Z_REFCOUNT_P(v0) > 1) {
			zval *new_zv;
			Z_DELREF_P(v0);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v0);
			v0 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update(v0, v2, r1 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_2;
		fee_fdd7_2:
		zend_hash_destroy(ah0);
		efree(ah0);
	}
	PHALCON_RETURN_CTOR(v0);
}

PHP_METHOD(Phalcon_Internal_Test, a11){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	add_next_index_long(a0, 4);
	add_next_index_long(a0, 5);
	PHALCON_CPY_WRT(v0, a0);
	if (Z_TYPE_P(v0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ALLOC_HASHTABLE(ah0);
		zend_hash_init(ah0, 0, NULL, NULL, 0);
		zend_hash_copy(ah0, Z_ARRVAL_P(v0), NULL, NULL, sizeof(zval*));
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_3:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_3;
		} else {
			PHALCON_INIT_VAR(v2);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v2, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v2, num);
				}
			}
		}
		PHALCON_INIT_VAR(v1);
		ZVAL_ZVAL(v1, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch(&r0, v0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		PHALCON_INIT_VAR(r1);
		phalcon_add_function(r1, v2, t0 TSRMLS_CC);
		Z_ADDREF_P(r0);
		if (Z_REFCOUNT_P(v0) > 1) {
			zval *new_zv;
			Z_DELREF_P(v0);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v0);
			v0 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update(v0, r1, r0 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_3;
		fee_fdd7_3:
		zend_hash_destroy(ah0);
		efree(ah0);
	}
	PHALCON_RETURN_CTOR(v0);
}

PHP_METHOD(Phalcon_Internal_Test, a12){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_LONG(v0, 0);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	add_next_index_long(a0, 4);
	add_next_index_long(a0, 5);
	PHALCON_CPY_WRT(v1, a0);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ALLOC_HASHTABLE(ah0);
		zend_hash_init(ah0, 0, NULL, NULL, 0);
		zend_hash_copy(ah0, Z_ARRVAL_P(v1), NULL, NULL, sizeof(zval*));
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_4:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_4;
		}
		PHALCON_INIT_VAR(v2);
		ZVAL_ZVAL(v2, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch(&r0, v1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 10);
		PHALCON_INIT_VAR(r1);
		phalcon_add_function(r1, v0, t0 TSRMLS_CC);
		Z_ADDREF_P(r0);
		if (Z_REFCOUNT_P(v1) > 1) {
			zval *new_zv;
			Z_DELREF_P(v1);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v1);
			v1 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update(v1, r1, r0 TSRMLS_CC);
		increment_function(v0);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_4;
		fee_fdd7_4:
		zend_hash_destroy(ah0);
		efree(ah0);
	}
	PHALCON_RETURN_CTOR(v1);
}

PHP_METHOD(Phalcon_Internal_Test, a13){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	add_next_index_long(a1, 4);
	add_next_index_long(a1, 5);
	PHALCON_CPY_WRT(v1, a1);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_5:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_5;
		}
		PHALCON_INIT_VAR(v2);
		ZVAL_ZVAL(v2, *hd, 1, 0);
		Z_ADDREF_P(v2);
		PHALCON_SEPARATE_ARRAY(v0);
		phalcon_array_append(v0, v2 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_5;
		fee_fdd7_5:
		if(0){ };
	}
	PHALCON_RETURN_CTOR(v0);
}

PHP_METHOD(Phalcon_Internal_Test, a14){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	add_next_index_long(a1, 4);
	add_next_index_long(a1, 5);
	PHALCON_CPY_WRT(v1, a1);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_6:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_6;
		} else {
			PHALCON_INIT_VAR(v3);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v3, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v3, num);
				}
			}
		}
		PHALCON_INIT_VAR(v2);
		ZVAL_ZVAL(v2, *hd, 1, 0);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 2);
		PHALCON_INIT_VAR(r0);
		mul_function(r0, v3, t0 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r0);
		PHALCON_INIT_VAR(r1);
		phalcon_add_function(r1, v2, v3 TSRMLS_CC);
		Z_ADDREF_P(r1);
		if (Z_REFCOUNT_P(v0) > 1) {
			zval *new_zv;
			Z_DELREF_P(v0);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v0);
			v0 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update(v0, v3, r1 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_6;
		fee_fdd7_6:
		if(0){ };
	}
	PHALCON_RETURN_CTOR(v0);
}

PHP_METHOD(Phalcon_Internal_Test, a15){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	add_next_index_long(a1, 4);
	add_next_index_long(a1, 5);
	PHALCON_CPY_WRT(v1, a1);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ALLOC_HASHTABLE(ah0);
		zend_hash_init(ah0, 0, NULL, NULL, 0);
		zend_hash_copy(ah0, Z_ARRVAL_P(v1), NULL, NULL, sizeof(zval*));
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_7:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_7;
		} else {
			PHALCON_INIT_VAR(v3);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v3, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v3, num);
				}
			}
		}
		PHALCON_INIT_VAR(v2);
		ZVAL_ZVAL(v2, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch(&r0, v1, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r0);
		if (Z_REFCOUNT_P(v0) > 1) {
			zval *new_zv;
			Z_DELREF_P(v0);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v0);
			v0 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update(v0, v3, r0 TSRMLS_CC);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 100);
		PHALCON_INIT_VAR(r1);
		mul_function(r1, v3, t0 TSRMLS_CC);
		Z_ADDREF_P(r1);
		if (Z_REFCOUNT_P(v1) > 1) {
			zval *new_zv;
			Z_DELREF_P(v1);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v1);
			v1 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update(v1, v3, r1 TSRMLS_CC);
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch(&r2, v0, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 50);
		PHALCON_INIT_VAR(r3);
		mul_function(r3, r2, t1 TSRMLS_CC);
		Z_ADDREF_P(r3);
		if (Z_REFCOUNT_P(v0) > 1) {
			zval *new_zv;
			Z_DELREF_P(v0);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v0);
			v0 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update(v0, v3, r3 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_7;
		fee_fdd7_7:
		zend_hash_destroy(ah0);
		efree(ah0);
	}
	PHALCON_RETURN_CTOR(v0);
}

PHP_METHOD(Phalcon_Internal_Test, a16){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL;
	zval *t0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	add_assoc_stringl_ex(a2, "in", strlen("in")+1, "out", strlen("out"), 1);
	Z_ADDREF_P(a2);
	PHALCON_SEPARATE_ARRAY(a1);
	add_assoc_zval(a1, "hello", a2);
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	add_assoc_stringl_ex(a3, "file", strlen("file")+1, "type", strlen("type"), 1);
	add_assoc_stringl_ex(a3, "php", strlen("php")+1, "unix", strlen("unix"), 1);
	add_assoc_stringl_ex(a3, "tab", strlen("tab")+1, "ins", strlen("ins"), 1);
	Z_ADDREF_P(a3);
	PHALCON_SEPARATE_ARRAY(a1);
	add_assoc_zval(a1, "bye", a3);
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	Z_ADDREF_P(a4);
	PHALCON_SEPARATE_ARRAY(a1);
	add_assoc_zval(a1, "encoding", a4);
	add_assoc_stringl_ex(a1, "sucks", strlen("sucks")+1, "yes", strlen("yes"), 1);
	PHALCON_CPY_WRT(v1, a1);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_8:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_8;
		} else {
			PHALCON_INIT_VAR(v3);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v3, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v3, num);
				}
			}
		}
		PHALCON_INIT_VAR(v2);
		ZVAL_ZVAL(v2, *hd, 1, 0);
		if (Z_TYPE_P(v2) == IS_ARRAY) { 
			if (Z_TYPE_P(v2) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah1 = Z_ARRVAL_P(v2);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_fdd7_9:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee_fdd7_9;
				} else {
					PHALCON_INIT_VAR(v5);
					htype = zend_hash_get_current_key_ex(ah1, &index, &index_len, &num, 0, &hp1);
					if (htype == HASH_KEY_IS_STRING) {
						ZVAL_STRINGL(v5, index, index_len-1, 1);
					} else {
						if (htype == HASH_KEY_IS_LONG) {
							ZVAL_LONG(v5, num);
						}
					}
				}
				PHALCON_INIT_VAR(v4);
				ZVAL_ZVAL(v4, *hd, 1, 0);
				if (Z_TYPE_P(v0) == IS_ARRAY) {
					PHALCON_INIT_VAR(t0);
					phalcon_array_fetch(&t0, v0, v3, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t0) > 1) {
					zval *new_zv;
					Z_DELREF_P(t0);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, t0);
					t0 = new_zv;
					zval_copy_ctor(new_zv);
					phalcon_array_update(v0, v3, t0 TSRMLS_CC);
				}
				Z_ADDREF_P(t0);
				if (Z_TYPE_P(t0) != IS_ARRAY) {
					convert_to_array(t0);
					phalcon_array_update(v0, v3, t0 TSRMLS_CC);
				}
				Z_ADDREF_P(v4);
				phalcon_array_update(t0, v5, v4 TSRMLS_CC);
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_fdd7_9;
				fee_fdd7_9:
				if(0){ };
			}
		} else {
			Z_ADDREF_P(v2);
			if (Z_REFCOUNT_P(v0) > 1) {
				zval *new_zv;
				Z_DELREF_P(v0);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v0);
				v0 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update(v0, v3, v2 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_8;
		fee_fdd7_8:
		if(0){ };
	}
	PHALCON_RETURN_CTOR(v0);
}

PHP_METHOD(Phalcon_Internal_Test, a17){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_index_long(a1, 7, 0);
	add_index_long(a1, 8, 1);
	add_index_long(a1, 9, 2);
	PHALCON_CPY_WRT(v1, a1);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	add_next_index_stringl(a3, "hello1", strlen("hello1"), 1);
	Z_ADDREF_P(a3);
	PHALCON_SEPARATE_ARRAY(a2);
	add_next_index_zval(a2, a3);
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	add_next_index_stringl(a4, "hello2", strlen("hello2"), 1);
	Z_ADDREF_P(a4);
	PHALCON_SEPARATE_ARRAY(a2);
	add_assoc_zval(a2, "1", a4);
	PHALCON_INIT_VAR(a5);
	array_init(a5);
	add_next_index_stringl(a5, "hello3", strlen("hello3"), 1);
	Z_ADDREF_P(a5);
	PHALCON_SEPARATE_ARRAY(a2);
	add_assoc_zval(a2, "2", a5);
	PHALCON_CPY_WRT(v2, a2);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_10:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_10;
		} else {
			PHALCON_INIT_VAR(v4);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v4, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v4, num);
				}
			}
		}
		PHALCON_INIT_VAR(v3);
		ZVAL_ZVAL(v3, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch(&r0, v2, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r0);
		if (Z_REFCOUNT_P(v0) > 1) {
			zval *new_zv;
			Z_DELREF_P(v0);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v0);
			v0 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update(v0, v4, r0 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_10;
		fee_fdd7_10:
		if(0){ };
	}
	PHALCON_RETURN_CTOR(v0);
}

PHP_METHOD(Phalcon_Internal_Test, a18){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, "hello1", strlen("hello1"), 1);
	add_next_index_stringl(a0, "hello2", strlen("hello2"), 1);
	add_next_index_stringl(a0, "hello3", strlen("hello3"), 1);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	Z_ADDREF_P(v0);
	PHALCON_SEPARATE_ARRAY(a1);
	add_next_index_zval(a1, v0);
	PHALCON_CPY_WRT(v1, a1);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "see", 0);
	if (Z_TYPE_P(v1) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_array_fetch_long(&t1, v1, 0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t1) > 1) {
		zval *new_zv;
		Z_DELREF_P(t1);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t1);
		t1 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update_long(v1, 0, t1 TSRMLS_CC);
	}
	Z_ADDREF_P(t1);
	if (Z_TYPE_P(t1) != IS_ARRAY) {
		convert_to_array(t1);
		phalcon_array_update_long(v1, 0, t1 TSRMLS_CC);
	}
	Z_ADDREF_P(t0);
	phalcon_array_update_long(t1, 0, t0 TSRMLS_CC);
	PHALCON_RETURN_CTOR(v0);
}

PHP_METHOD(Phalcon_Internal_Test, a19){

	zval *v0 = NULL, *v1 = NULL;
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
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_next_index_stringl(a1, "lol1", strlen("lol1"), 1);
	add_next_index_stringl(a1, "lol2", strlen("lol2"), 1);
	add_next_index_stringl(a1, "lol3", strlen("lol3"), 1);
	add_next_index_stringl(a1, "lol4", strlen("lol4"), 1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	PHALCON_CPY_WRT(v1, a1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, v0, v1 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, a20){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_DOUBLE(v0, 3.45);
	PHALCON_INIT_VAR(v1);
	ZVAL_STRING(v1, "6.28", 1);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v2, a0);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "whtzup!", 0);
	Z_ADDREF_P(t0);
	if (Z_REFCOUNT_P(v2) > 1) {
		zval *new_zv;
		Z_DELREF_P(v2);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v2);
		v2 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update(v2, v0, t0 TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_STRING(t1, "morelol", 0);
	Z_ADDREF_P(t1);
	if (Z_REFCOUNT_P(v2) > 1) {
		zval *new_zv;
		Z_DELREF_P(v2);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v2);
		v2 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update(v2, v1, t1 TSRMLS_CC);
	PHALCON_RETURN_CTOR(v2);
}

PHP_METHOD(Phalcon_Internal_Test, a21){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_NULL(v0);
	PHALCON_INIT_VAR(v1);
	ZVAL_BOOL(v1, 0);
	PHALCON_INIT_VAR(v2);
	ZVAL_BOOL(v2, 1);
	PHALCON_INIT_VAR(v3);
	ZVAL_LONG(v3, 100);
	PHALCON_INIT_VAR(v4);
	ZVAL_DOUBLE(v4, 3.45);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 100);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, -1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_CPY_WRT(v5, r0);
	PHALCON_INIT_VAR(v6);
	ZVAL_STRING(v6, "6.28", 1);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v7, a0);
	PHALCON_INIT_VAR(t2);
	ZVAL_STRING(t2, "whtzup!", 0);
	if (Z_TYPE_P(v7) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_array_fetch(&t3, v7, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t3) > 1) {
		zval *new_zv;
		Z_DELREF_P(t3);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t3);
		t3 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update(v7, v0, t3 TSRMLS_CC);
	}
	Z_ADDREF_P(t3);
	if (Z_TYPE_P(t3) != IS_ARRAY) {
		convert_to_array(t3);
		phalcon_array_update(v7, v0, t3 TSRMLS_CC);
	}
	if (Z_TYPE_P(t3) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_array_fetch(&t4, t3, v1, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t4) > 1) {
		zval *new_zv;
		Z_DELREF_P(t4);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t4);
		t4 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update(t3, v1, t4 TSRMLS_CC);
	}
	Z_ADDREF_P(t4);
	if (Z_TYPE_P(t4) != IS_ARRAY) {
		convert_to_array(t4);
		phalcon_array_update(t3, v1, t4 TSRMLS_CC);
	}
	if (Z_TYPE_P(t4) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_array_fetch(&t5, t4, v2, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t5) > 1) {
		zval *new_zv;
		Z_DELREF_P(t5);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t5);
		t5 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update(t4, v2, t5 TSRMLS_CC);
	}
	Z_ADDREF_P(t5);
	if (Z_TYPE_P(t5) != IS_ARRAY) {
		convert_to_array(t5);
		phalcon_array_update(t4, v2, t5 TSRMLS_CC);
	}
	if (Z_TYPE_P(t5) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t6);
		phalcon_array_fetch(&t6, t5, v3, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t6) > 1) {
		zval *new_zv;
		Z_DELREF_P(t6);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t6);
		t6 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update(t5, v3, t6 TSRMLS_CC);
	}
	Z_ADDREF_P(t6);
	if (Z_TYPE_P(t6) != IS_ARRAY) {
		convert_to_array(t6);
		phalcon_array_update(t5, v3, t6 TSRMLS_CC);
	}
	if (Z_TYPE_P(t6) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t7);
		phalcon_array_fetch(&t7, t6, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t7) > 1) {
		zval *new_zv;
		Z_DELREF_P(t7);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t7);
		t7 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update(t6, v4, t7 TSRMLS_CC);
	}
	Z_ADDREF_P(t7);
	if (Z_TYPE_P(t7) != IS_ARRAY) {
		convert_to_array(t7);
		phalcon_array_update(t6, v4, t7 TSRMLS_CC);
	}
	if (Z_TYPE_P(t7) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t8);
		phalcon_array_fetch(&t8, t7, v5, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t8) > 1) {
		zval *new_zv;
		Z_DELREF_P(t8);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t8);
		t8 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update(t7, v5, t8 TSRMLS_CC);
	}
	Z_ADDREF_P(t8);
	if (Z_TYPE_P(t8) != IS_ARRAY) {
		convert_to_array(t8);
		phalcon_array_update(t7, v5, t8 TSRMLS_CC);
	}
	Z_ADDREF_P(t2);
	phalcon_array_update(t8, v6, t2 TSRMLS_CC);
	PHALCON_RETURN_CTOR(v7);
}

PHP_METHOD(Phalcon_Internal_Test, a22){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, "222", strlen("222"), 1);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_next_index_stringl(a1, "222", strlen("222"), 1);
	add_next_index_stringl(a1, "kdkdk", strlen("kdkdk"), 1);
	PHALCON_CPY_WRT(v1, a1);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, v0, v1 TSRMLS_CC);
	Z_ADDREF_P(r0);
	PHALCON_SEPARATE_ARRAY(a2);
	add_next_index_zval(a2, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_add_function(r1, v1, v0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_add_function(r2, r1, v0 TSRMLS_CC);
	Z_ADDREF_P(r2);
	PHALCON_SEPARATE_ARRAY(a2);
	add_next_index_zval(a2, r2);
	PHALCON_CPY_WRT(v2, a2);
	PHALCON_RETURN_CTOR(v2);
}

PHP_METHOD(Phalcon_Internal_Test, a23){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	add_assoc_stringl_ex(a2, "baseuri", strlen("baseuri")+1, "/phalcon/", strlen("/phalcon/"), 1);
	Z_ADDREF_P(a2);
	PHALCON_SEPARATE_ARRAY(a1);
	add_assoc_zval(a1, "phalcon", a2);
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	add_assoc_stringl_ex(a3, "metadata", strlen("metadata")+1, "memory", strlen("memory"), 1);
	Z_ADDREF_P(a3);
	PHALCON_SEPARATE_ARRAY(a1);
	add_assoc_zval(a1, "models", a3);
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	add_assoc_stringl_ex(a4, "adapter", strlen("adapter")+1, "mysql", strlen("mysql"), 1);
	add_assoc_stringl_ex(a4, "host", strlen("host")+1, "localhost", strlen("localhost"), 1);
	add_assoc_stringl_ex(a4, "username", strlen("username")+1, "user", strlen("user"), 1);
	add_assoc_stringl_ex(a4, "password", strlen("password")+1, "passwd", strlen("passwd"), 1);
	add_assoc_stringl_ex(a4, "name", strlen("name")+1, "demo", strlen("demo"), 1);
	Z_ADDREF_P(a4);
	PHALCON_SEPARATE_ARRAY(a1);
	add_assoc_zval(a1, "database", a4);
	PHALCON_INIT_VAR(a5);
	array_init(a5);
	add_assoc_long_ex(a5, "parent.property", strlen("parent.property")+1, 1);
	add_assoc_stringl_ex(a5, "parent.property2", strlen("parent.property2")+1, "yeah", strlen("yeah"), 1);
	Z_ADDREF_P(a5);
	PHALCON_SEPARATE_ARRAY(a1);
	add_assoc_zval(a1, "test", a5);
	PHALCON_CPY_WRT(v1, a1);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_11:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_11;
		} else {
			PHALCON_INIT_VAR(v3);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v3, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v3, num);
				}
			}
		}
		PHALCON_INIT_VAR(v2);
		ZVAL_ZVAL(v2, *hd, 1, 0);
		if (Z_TYPE_P(v2) == IS_ARRAY) { 
			if (Z_TYPE_P(v2) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah1 = Z_ARRVAL_P(v2);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_fdd7_12:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee_fdd7_12;
				} else {
					PHALCON_INIT_VAR(v5);
					htype = zend_hash_get_current_key_ex(ah1, &index, &index_len, &num, 0, &hp1);
					if (htype == HASH_KEY_IS_STRING) {
						ZVAL_STRINGL(v5, index, index_len-1, 1);
					} else {
						if (htype == HASH_KEY_IS_LONG) {
							ZVAL_LONG(v5, num);
						}
					}
				}
				PHALCON_INIT_VAR(v4);
				ZVAL_ZVAL(v4, *hd, 1, 0);
				if (Z_TYPE_P(v0) == IS_ARRAY) {
					PHALCON_INIT_VAR(t0);
					phalcon_array_fetch(&t0, v0, v3, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t0) > 1) {
					zval *new_zv;
					Z_DELREF_P(t0);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, t0);
					t0 = new_zv;
					zval_copy_ctor(new_zv);
					phalcon_array_update(v0, v3, t0 TSRMLS_CC);
				}
				Z_ADDREF_P(t0);
				if (Z_TYPE_P(t0) != IS_ARRAY) {
					convert_to_array(t0);
					phalcon_array_update(v0, v3, t0 TSRMLS_CC);
				}
				Z_ADDREF_P(v4);
				phalcon_array_update(t0, v5, v4 TSRMLS_CC);
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_fdd7_12;
				fee_fdd7_12:
				if(0){ };
			}
		} else {
			PHALCON_INIT_VAR(r0);
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, ".", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r0, "strpos", c0, v2, 0x00A);
			if (Z_TYPE_P(r0) != IS_BOOL || (Z_TYPE_P(r0) == IS_BOOL && Z_BVAL_P(r0))) {
				PHALCON_INIT_VAR(r1);
				PHALCON_INIT_VAR(c1);
				ZVAL_STRING(c1, ".", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r1, "explode", c1, v2, 0x005);
				PHALCON_CPY_WRT(v6, r1);
				PHALCON_INIT_VAR(r2);
				phalcon_array_fetch_long(&r2, v6, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
				if (Z_TYPE_P(v0) == IS_ARRAY) {
					PHALCON_INIT_VAR(t1);
					phalcon_array_fetch(&t1, v0, v3, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t1) > 1) {
					zval *new_zv;
					Z_DELREF_P(t1);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, t1);
					t1 = new_zv;
					zval_copy_ctor(new_zv);
					phalcon_array_update(v0, v3, t1 TSRMLS_CC);
				}
				Z_ADDREF_P(t1);
				if (Z_TYPE_P(t1) != IS_ARRAY) {
					convert_to_array(t1);
					phalcon_array_update(v0, v3, t1 TSRMLS_CC);
				}
				PHALCON_INIT_VAR(r3);
				phalcon_array_fetch_long(&r3, v6, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r2);
				phalcon_array_update(t1, r3, r2 TSRMLS_CC);
			} else {
				Z_ADDREF_P(v2);
				if (Z_REFCOUNT_P(v0) > 1) {
					zval *new_zv;
					Z_DELREF_P(v0);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, v0);
					v0 = new_zv;
					zval_copy_ctor(new_zv);
				}
				phalcon_array_update(v0, v3, v2 TSRMLS_CC);
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_11;
		fee_fdd7_11:
		if(0){ };
	}
	PHALCON_RETURN_CTOR(v0);
}

PHP_METHOD(Phalcon_Internal_Test, a24){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	Z_ADDREF_P(v0);
	PHALCON_SEPARATE_ARRAY(a0);
	add_next_index_zval(a0, v0);
	PHALCON_CPY_WRT(v1, a0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "hello, ", v0);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_RETURN_CTOR(v2);
}

PHP_METHOD(Phalcon_Internal_Test, a25){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_STRING(v0, "h", 1);
	PHALCON_INIT_VAR(v1);
	ZVAL_STRING(v1, "k", 1);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_assoc_stringl_ex(a0, "k", strlen("k")+1, "v", strlen("v"), 1);
	add_assoc_stringl_ex(a0, "i", strlen("i")+1, "d", strlen("d"), 1);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t0) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_array_fetch(&t1, t0, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t1) > 1) {
		zval *new_zv;
		Z_DELREF_P(t1);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t1);
		t1 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update(t0, v0, t1 TSRMLS_CC);
	}
	Z_ADDREF_P(t1);
	if (Z_TYPE_P(t1) != IS_ARRAY) {
		convert_to_array(t1);
		phalcon_array_update(t0, v0, t1 TSRMLS_CC);
	}
	Z_ADDREF_P(a0);
	phalcon_array_update(t1, v1, a0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t2);
}

PHP_METHOD(Phalcon_Internal_Test, a26){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 0);
	add_next_index_long(a0, 1);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(v1);
	ZVAL_LONG(v1, 0);
	fs_fdd7_13:
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_INIT_VAR(r0);
	is_smaller_function(r0, v1, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe_fdd7_13;
	}
	PHALCON_INIT_VAR(r1);
	phalcon_array_fetch_long(&r1, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE_NMO(r1);
	decrement_function(r1);
	Z_ADDREF_P(r1);
	if (Z_REFCOUNT_P(v0) > 1) {
		zval *new_zv;
		Z_DELREF_P(v0);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v0);
		v0 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update_long(v0, 0, r1 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r1);
	PHALCON_INIT_VAR(r2);
	phalcon_array_fetch_long(&r2, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE_NMO(r2);
	PHALCON_INIT_VAR(t1);
	ZVAL_ZVAL(t1, r2, 1, 0);
	increment_function(r2);
	Z_ADDREF_P(r2);
	if (Z_REFCOUNT_P(v0) > 1) {
		zval *new_zv;
		Z_DELREF_P(v0);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v0);
		v0 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update_long(v0, 1, r2 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, t1);
	PHALCON_SEPARATE(v1);
	increment_function(v1);
	goto fs_fdd7_13;
	fe_fdd7_13:
	PHALCON_RETURN_CTOR(v0);
}

PHP_METHOD(Phalcon_Internal_Test, sa0){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, sa1){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, sa3){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sa4){

	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		convert_to_array(t0);
	}
	Z_ADDREF_P(a1);
	phalcon_array_append(t0, a1 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, t0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(t1);
	ZVAL_STRING(t1, "more-loose", 1);
	t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t2) != IS_ARRAY) {
		convert_to_array(t2);
	}
	if (Z_TYPE_P(t2) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_array_fetch_long(&t3, t2, 0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t3) > 1) {
		zval *new_zv;
		Z_DELREF_P(t3);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t3);
		t3 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update_long(t2, 0, t3 TSRMLS_CC);
	}
	Z_ADDREF_P(t3);
	if (Z_TYPE_P(t3) != IS_ARRAY) {
		convert_to_array(t3);
		phalcon_array_update_long(t2, 0, t3 TSRMLS_CC);
	}
	Z_ADDREF_P(t1);
	phalcon_array_append(t3, t1 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, t2 TSRMLS_CC);
	
	PHALCON_INIT_VAR(t4);
	ZVAL_STRING(t4, "yeah, more-loose", 1);
	t5 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t5) != IS_ARRAY) {
		convert_to_array(t5);
	}
	if (Z_TYPE_P(t5) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t6);
		phalcon_array_fetch_long(&t6, t5, 0, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t6) > 1) {
		zval *new_zv;
		Z_DELREF_P(t6);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t6);
		t6 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update_long(t5, 0, t6 TSRMLS_CC);
	}
	Z_ADDREF_P(t6);
	if (Z_TYPE_P(t6) != IS_ARRAY) {
		convert_to_array(t6);
		phalcon_array_update_long(t5, 0, t6 TSRMLS_CC);
	}
	Z_ADDREF_P(t4);
	phalcon_array_update_long(t6, 0, t4 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, t5 TSRMLS_CC);
	
	t7 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t7);
}

PHP_METHOD(Phalcon_Internal_Test, sa5){

	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "loose", 1);
	t1 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t1) != IS_ARRAY) {
		convert_to_array(t1);
	}
	if (Z_TYPE_P(t1) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_array_fetch_long(&t2, t1, 1, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t2) > 1) {
		zval *new_zv;
		Z_DELREF_P(t2);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t2);
		t2 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update_long(t1, 1, t2 TSRMLS_CC);
	}
	Z_ADDREF_P(t2);
	if (Z_TYPE_P(t2) != IS_ARRAY) {
		convert_to_array(t2);
		phalcon_array_update_long(t1, 1, t2 TSRMLS_CC);
	}
	if (Z_TYPE_P(t2) == IS_ARRAY) {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_array_fetch_long(&t3, t2, 2, PHALCON_SILENT_FETCH TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(t3) > 1) {
		zval *new_zv;
		Z_DELREF_P(t3);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, t3);
		t3 = new_zv;
		zval_copy_ctor(new_zv);
		phalcon_array_update_long(t2, 2, t3 TSRMLS_CC);
	}
	Z_ADDREF_P(t3);
	if (Z_TYPE_P(t3) != IS_ARRAY) {
		convert_to_array(t3);
		phalcon_array_update_long(t2, 2, t3 TSRMLS_CC);
	}
	Z_ADDREF_P(t0);
	phalcon_array_update_long(t3, 3, t0 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, t1 TSRMLS_CC);
	
	t4 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_INIT_VAR(t8);
	ZVAL_LONG(t8, 1);
	PHALCON_ALLOC_ZVAL_MM(t7);
	phalcon_array_fetch(&t7, t4, t8, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(t9);
	ZVAL_LONG(t9, 2);
	PHALCON_ALLOC_ZVAL_MM(t6);
	phalcon_array_fetch(&t6, t7, t9, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(t10);
	ZVAL_LONG(t10, 3);
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_array_fetch(&t5, t6, t10, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t5);
}

PHP_METHOD(Phalcon_Internal_Test, sa6){

	zval *a0 = NULL, *a1 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_next_index_long(a1, 1);
	add_next_index_long(a1, 2);
	add_next_index_long(a1, 3);
	add_next_index_long(a1, 4);
	add_next_index_long(a1, 5);
	PHALCON_CPY_WRT(v0, a1);
	if (Z_TYPE_P(v0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_14:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_14;
		} else {
			PHALCON_INIT_VAR(v2);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v2, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v2, num);
				}
			}
		}
		PHALCON_INIT_VAR(v1);
		ZVAL_ZVAL(v1, *hd, 1, 0);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 2);
		PHALCON_INIT_VAR(r0);
		mul_function(r0, v2, t0 TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r0);
		PHALCON_INIT_VAR(r1);
		phalcon_add_function(r1, v1, v2 TSRMLS_CC);
		t1 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (Z_TYPE_P(t1) != IS_ARRAY) {
			convert_to_array(t1);
		}
		Z_ADDREF_P(r1);
		phalcon_array_update(t1, v2, r1 TSRMLS_CC);
		zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, t1 TSRMLS_CC);
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_14;
		fee_fdd7_14:
		if(0){ };
	}
	t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t2);
}

PHP_METHOD(Phalcon_Internal_Test, sa7){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	add_assoc_stringl_ex(a2, "in", strlen("in")+1, "out", strlen("out"), 1);
	Z_ADDREF_P(a2);
	PHALCON_SEPARATE_ARRAY(a1);
	add_assoc_zval(a1, "hello", a2);
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	add_assoc_stringl_ex(a3, "file", strlen("file")+1, "type", strlen("type"), 1);
	add_assoc_stringl_ex(a3, "php", strlen("php")+1, "unix", strlen("unix"), 1);
	add_assoc_stringl_ex(a3, "tab", strlen("tab")+1, "ins", strlen("ins"), 1);
	Z_ADDREF_P(a3);
	PHALCON_SEPARATE_ARRAY(a1);
	add_assoc_zval(a1, "bye", a3);
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	Z_ADDREF_P(a4);
	PHALCON_SEPARATE_ARRAY(a1);
	add_assoc_zval(a1, "encoding", a4);
	add_assoc_stringl_ex(a1, "sucks", strlen("sucks")+1, "yes", strlen("yes"), 1);
	PHALCON_CPY_WRT(v0, a1);
	if (Z_TYPE_P(v0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_15:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_15;
		} else {
			PHALCON_INIT_VAR(v2);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v2, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v2, num);
				}
			}
		}
		PHALCON_INIT_VAR(v1);
		ZVAL_ZVAL(v1, *hd, 1, 0);
		if (Z_TYPE_P(v1) == IS_ARRAY) { 
			if (Z_TYPE_P(v1) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah1 = Z_ARRVAL_P(v1);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_fdd7_16:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee_fdd7_16;
				} else {
					PHALCON_INIT_VAR(v4);
					htype = zend_hash_get_current_key_ex(ah1, &index, &index_len, &num, 0, &hp1);
					if (htype == HASH_KEY_IS_STRING) {
						ZVAL_STRINGL(v4, index, index_len-1, 1);
					} else {
						if (htype == HASH_KEY_IS_LONG) {
							ZVAL_LONG(v4, num);
						}
					}
				}
				PHALCON_INIT_VAR(v3);
				ZVAL_ZVAL(v3, *hd, 1, 0);
				t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
				if (Z_TYPE_P(t0) != IS_ARRAY) {
					convert_to_array(t0);
				}
				if (Z_TYPE_P(t0) == IS_ARRAY) {
					PHALCON_INIT_VAR(t1);
					phalcon_array_fetch(&t1, t0, v2, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t1) > 1) {
					zval *new_zv;
					Z_DELREF_P(t1);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, t1);
					t1 = new_zv;
					zval_copy_ctor(new_zv);
					phalcon_array_update(t0, v2, t1 TSRMLS_CC);
				}
				Z_ADDREF_P(t1);
				if (Z_TYPE_P(t1) != IS_ARRAY) {
					convert_to_array(t1);
					phalcon_array_update(t0, v2, t1 TSRMLS_CC);
				}
				Z_ADDREF_P(v3);
				phalcon_array_update(t1, v4, v3 TSRMLS_CC);
				zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, t0 TSRMLS_CC);
				
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_fdd7_16;
				fee_fdd7_16:
				if(0){ };
			}
		} else {
			t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			if (Z_TYPE_P(t2) != IS_ARRAY) {
				convert_to_array(t2);
			}
			Z_ADDREF_P(v1);
			phalcon_array_update(t2, v2, v1 TSRMLS_CC);
			zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, t2 TSRMLS_CC);
			
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_15;
		fee_fdd7_15:
		if(0){ };
	}
	t3 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, v1, v2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, v0, r0 TSRMLS_CC);
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
	PHALCON_CALL_FUNC_PARAMS_2(r0, "rtrim", c0, c1, 0x01F);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, f3){

	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "bb", 1);
	PHALCON_INIT_VAR(p0[1]);
	ZVAL_STRING(p0[1], "xx", 1);
	PHALCON_INIT_VAR(p0[2]);
	ZVAL_STRING(p0[2], "aabbcc", 1);
	PHALCON_CALL_FUNC_PARAMS(r0, "str_replace", 3, p0, 0x003);
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
	PHALCON_CALL_FUNC_PARAMS_2(r0, "str_repeat", c0, r1, 0x020);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, f5){

	zval *v0 = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, "b", strlen("b"), 1);
	add_next_index_stringl(a0, "c", strlen("c"), 1);
	add_next_index_stringl(a0, "a", strlen("a"), 1);
	PHALCON_CPY_WRT(v0, a0);
	Z_SET_ISREF_P(v0);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("asort", v0, 0x021);
	Z_UNSET_ISREF_P(v0);
	PHALCON_RETURN_CTOR(v0);
}

PHP_METHOD(Phalcon_Internal_Test, f6){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_LONG(c0, 0);
	PHALCON_INIT_VAR(c1);
	ZVAL_LONG(c1, 100);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "mt_rand", c0, c1, 0x022);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CONCAT_RIGHT(r1, r0, ".txt");
	PHALCON_CPY_WRT(v0, r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "w", 1);
	PHALCON_CALL_FUNC_PARAMS_2(r2, "fopen", v0, c2, 0x023);
	PHALCON_CPY_WRT(v1, r2);
	Z_ADDREF_P(v1);
	PHALCON_INIT_VAR(c3);
	ZVAL_STRING(c3, "morelol\n", 1);
	PHALCON_CALL_FUNC_PARAMS_2_NORETURN("fwrite", v1, c3, 0x024);
	Z_DELREF_P(v1);
	Z_ADDREF_P(v1);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("fclose", v1, 0x025);
	Z_DELREF_P(v1);
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_FUNC_PARAMS_1(r3, "file_get_contents", v0, 0x017);
	PHALCON_CPY_WRT(v2, r3);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("unlink", v0, 0x026);
	PHALCON_RETURN_CHECK_CTOR(v2);
}

PHP_METHOD(Phalcon_Internal_Test, f7){

	zval *r0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_DOUBLE(c0, 3.14159);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "sqrt", c0, 0x027);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, f8){

	zval *r0 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, ".", strlen("."), 1);
	add_next_index_stringl(a0, ",", strlen(","), 1);
	add_next_index_stringl(a0, "-", strlen("-"), 1);
	p0[0] = a0;
	PHALCON_INIT_VAR(p0[1]);
	ZVAL_STRING(p0[1], "&", 1);
	PHALCON_INIT_VAR(p0[2]);
	ZVAL_STRING(p0[2], "-.,-.,", 1);
	PHALCON_CALL_FUNC_PARAMS(r0, "str_replace", 3, p0, 0x003);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, f9){

	zval *v0 = NULL;
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
	PHALCON_CPY_WRT(v0, r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	Z_ADDREF_P(v0);
	PHALCON_CALL_FUNC_PARAMS_1(r2, "abs", v0, 0x028);
	Z_DELREF_P(v0);
	PHALCON_RETURN_DZVAL(r2);
}

PHP_METHOD(Phalcon_Internal_Test, f10){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_long(&r1, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_numeric", r1, 0x00B);
	if (zend_is_true(r0)) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
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
	PHALCON_CALL_METHOD(r0, this_ptr, "m1", PHALCON_CALL_DEFAULT);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, m4){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "m2", PHALCON_CALL_DEFAULT);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, m5){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "m2", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, this_ptr, "m1", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, r0, r1 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r2);
}

PHP_METHOD(Phalcon_Internal_Test, m6){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, v0, v1 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, m7){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "m6", 2, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, m8){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "m6", 2, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	Z_ADDREF_P(v1);
	p1[1] = v1;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "m6", 2, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	Z_DELREF_P(p1[1]);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, r0, r1 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r2);
}

PHP_METHOD(Phalcon_Internal_Test, m9){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, v0, v1 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, m10){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "m9", 2, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, m11){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "m10", 2, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, m12){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(v2);
	ZVAL_LONG(v2, 0);
	PHALCON_INIT_VAR(v3);
	ZVAL_LONG(v3, 0);
	fs_fdd7_17:
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_INIT_VAR(r0);
	is_smaller_function(r0, v3, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe_fdd7_17;
	}
	PHALCON_INIT_VAR(r1);
	PHALCON_INIT_VAR(r2);
	phalcon_add_function(r2, v3, v0 TSRMLS_CC);
	Z_ADDREF_P(r2);
	p0[0] = r2;
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_INIT_VAR(r3);
	phalcon_add_function(r3, v3, t1 TSRMLS_CC);
	PHALCON_INIT_VAR(r4);
	phalcon_add_function(r4, v1, r3 TSRMLS_CC);
	Z_ADDREF_P(r4);
	p0[1] = r4;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "m9", 2, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_INIT_VAR(r5);
	phalcon_add_function(r5, v2, r1 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r5);
	PHALCON_SEPARATE(v3);
	increment_function(v3);
	goto fs_fdd7_17;
	fe_fdd7_17:
	PHALCON_RETURN_CTOR(v2);
}

PHP_METHOD(Phalcon_Internal_Test, m13){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v0);
	
	PHALCON_INIT_VAR(v0);
	ZVAL_LONG(v0, 100);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_ALLOC_ZVAL_MM(r0);
	mul_function(r0, v1, t0 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, m14){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "m13", 2, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_ALLOC_ZVAL_MM(r1);
	mul_function(r1, r0, v0 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r1);
	PHALCON_RETURN_CTOR(v2);
}

PHP_METHOD(Phalcon_Internal_Test, m15){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "m13", 2, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	mul_function(r1, v2, v0 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r1);
}

PHP_METHOD(Phalcon_Internal_Test, mp3){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "mp1", PHALCON_CALL_DEFAULT);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, mp4){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "mp2", 2, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, mp5){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_internal_testparent_class_entry);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	PHALCON_CPY_WRT(v0, i0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "mp1", PHALCON_CALL_DEFAULT);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, mp6){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;
	zval *p1[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_internal_testparent_class_entry);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	PHALCON_CPY_WRT(v2, i0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	Z_ADDREF_P(v1);
	p1[1] = v1;
	PHALCON_CALL_METHOD_PARAMS(r0, v2, "mp2", 2, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	Z_DELREF_P(p1[1]);
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

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, v0, v1 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, sm7){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "sm6", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, sm8){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, v0, v1 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_Test, sm9){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(v2);
	ZVAL_LONG(v2, 0);
	PHALCON_INIT_VAR(v3);
	ZVAL_LONG(v3, 0);
	fs_fdd7_18:
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_INIT_VAR(r0);
	is_smaller_function(r0, v3, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe_fdd7_18;
	}
	PHALCON_INIT_VAR(r1);
	PHALCON_INIT_VAR(r2);
	phalcon_add_function(r2, v3, v0 TSRMLS_CC);
	Z_ADDREF_P(r2);
	p0[0] = r2;
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_INIT_VAR(r3);
	phalcon_add_function(r3, v3, t1 TSRMLS_CC);
	PHALCON_INIT_VAR(r4);
	phalcon_add_function(r4, v1, r3 TSRMLS_CC);
	Z_ADDREF_P(r4);
	p0[1] = r4;
	PHALCON_CALL_SELF_PARAMS(r1, this_ptr, "sm8", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_INIT_VAR(r5);
	phalcon_add_function(r5, v2, r1 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r5);
	PHALCON_SEPARATE(v3);
	increment_function(v3);
	goto fs_fdd7_18;
	fe_fdd7_18:
	PHALCON_RETURN_CTOR(v2);
}

PHP_METHOD(Phalcon_Internal_Test, sm10){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(v2);
	ZVAL_LONG(v2, 0);
	PHALCON_INIT_VAR(v3);
	ZVAL_LONG(v3, 0);
	fs_fdd7_19:
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_INIT_VAR(r0);
	is_smaller_function(r0, v3, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe_fdd7_19;
	}
	PHALCON_INIT_VAR(r1);
	PHALCON_INIT_VAR(r2);
	phalcon_add_function(r2, v3, v0 TSRMLS_CC);
	Z_ADDREF_P(r2);
	p0[0] = r2;
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_INIT_VAR(r3);
	phalcon_add_function(r3, v3, t1 TSRMLS_CC);
	PHALCON_INIT_VAR(r4);
	phalcon_add_function(r4, v1, r3 TSRMLS_CC);
	Z_ADDREF_P(r4);
	p0[1] = r4;
	PHALCON_CALL_STATIC_PARAMS(r1, "phalcon_internal_test", "sm8", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_INIT_VAR(r5);
	phalcon_add_function(r5, v2, r1 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r5);
	PHALCON_SEPARATE(v3);
	increment_function(v3);
	goto fs_fdd7_19;
	fe_fdd7_19:
	PHALCON_RETURN_CTOR(v2);
}

PHP_METHOD(Phalcon_Internal_Test, sm11){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_STRING(v0, "sm2", 1);
	PHALCON_INIT_VAR(v1);
	ZVAL_STRING(v1, "Phalcon_Internal_Test", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_ZVAL_STATIC(r0, v1, "sm2");
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

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v1);
	p0[0] = v1;
	Z_ADDREF_P(v0);
	p0[1] = v0;
	PHALCON_CALL_PARENT_PARAMS(r0, this_ptr, "Phalcon_Internal_Test", "smp3", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_Internal_Test, smp5){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(v2);
	ZVAL_LONG(v2, 0);
	PHALCON_INIT_VAR(v3);
	ZVAL_LONG(v3, 0);
	fs_fdd7_20:
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_INIT_VAR(r0);
	is_smaller_function(r0, v3, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe_fdd7_20;
	}
	PHALCON_INIT_VAR(r1);
	PHALCON_INIT_VAR(r2);
	phalcon_add_function(r2, v3, v0 TSRMLS_CC);
	Z_ADDREF_P(r2);
	p0[0] = r2;
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_INIT_VAR(r3);
	phalcon_add_function(r3, v3, t1 TSRMLS_CC);
	PHALCON_INIT_VAR(r4);
	phalcon_add_function(r4, v1, r3 TSRMLS_CC);
	Z_ADDREF_P(r4);
	p0[1] = r4;
	PHALCON_CALL_STATIC_PARAMS(r1, "phalcon_internal_test", "smp3", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_INIT_VAR(r5);
	phalcon_add_function(r5, v2, r1 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r5);
	PHALCON_SEPARATE(v3);
	increment_function(v3);
	goto fs_fdd7_20;
	fe_fdd7_20:
	PHALCON_RETURN_CTOR(v2);
}

PHP_METHOD(Phalcon_Internal_Test, p1){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p1", sizeof("_p1")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p2){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p2", sizeof("_p2")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p3){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p3", sizeof("_p3")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p4){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p4", sizeof("_p4")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p5){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p5", sizeof("_p5")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p6){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p6", sizeof("_p6")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p7){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p7", sizeof("_p7")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p8){


	PHALCON_MM_GROW();
	phalcon_update_property_string(this_ptr, "_p0", strlen("_p0"), "more-lol" TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, p9){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p10){


	PHALCON_MM_GROW();
	phalcon_update_property_long(this_ptr, "_p0", strlen("_p0"), 14750 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, p11){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p12){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p1", sizeof("_p1")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_p2", sizeof("_p2")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_p3", sizeof("_p3")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	concat_function(r1, r0, t2 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r1);
}

PHP_METHOD(Phalcon_Internal_Test, p13){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p4", sizeof("_p4")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_p5", sizeof("_p5")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_p6", sizeof("_p6")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_add_function(r1, r0, t2 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r1);
}

PHP_METHOD(Phalcon_Internal_Test, p14){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_p0", strlen("_p0"), r0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, p15){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	phalcon_update_property_string(this_ptr, "_p0", strlen("_p0"), "" TSRMLS_CC);
	PHALCON_INIT_VAR(v0);
	ZVAL_LONG(v0, 0);
	fs_fdd7_21:
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 30);
	PHALCON_INIT_VAR(r0);
	is_smaller_function(r0, v0, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe_fdd7_21;
	}
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "p14", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	increment_function(v0);
	goto fs_fdd7_21;
	fe_fdd7_21:
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p16){

	zval *v0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_STRING(v0, "_p0", 1);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "lol", 1);
	phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v0), Z_STRLEN_P(v0), t0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, p17){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p18){

	zval *v0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_STRING(v0, "_p0", 1);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property_zval(&t0, this_ptr, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p19){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p8", sizeof("_p8")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p20){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "hello", 1);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_p8", sizeof("_p8")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t0);
	phalcon_array_append(t1, t0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_p8", strlen("_p8"), t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_p8", sizeof("_p8")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t2);
}

PHP_METHOD(Phalcon_Internal_Test, p21){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p22){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	phalcon_array_append(t0, v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p23){

	zval *v0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), v0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, p24){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t0);
	increment_function(t0);
	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p25){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t0);
	decrement_function(t0);
	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p26){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t0);
	increment_function(t0);
	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p27){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t0);
	decrement_function(t0);
	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, p28){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp2){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp2", sizeof("_sp2")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp3){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp3", sizeof("_sp3")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp4){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp4", sizeof("_sp4")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp5){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp5", sizeof("_sp5")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp6){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp6", sizeof("_sp6")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp7){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp7", sizeof("_sp7")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp8){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "i can't handle anymore", 1);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, t0 TSRMLS_CC);
	t1 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

PHP_METHOD(Phalcon_Internal_Test, sp9){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, v0, v1 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, r0 TSRMLS_CC);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, sp10){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, v0 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp2", sizeof("_sp2")-1, v1 TSRMLS_CC);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	t1 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp2", sizeof("_sp2")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_add_function(r1, r0, v2 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp3", sizeof("_sp3")-1, r1 TSRMLS_CC);
	t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp3", sizeof("_sp3")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t2);
}

PHP_METHOD(Phalcon_Internal_Test, sp11){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, v0 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp2", sizeof("_sp2")-1, v1 TSRMLS_CC);
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp1", sizeof("_sp1")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	t1 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp2", sizeof("_sp2")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, t0, t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_add_function(r1, r0, v2 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp3", sizeof("_sp3")-1, r1 TSRMLS_CC);
	t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp3", sizeof("_sp3")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t2);
}

PHP_METHOD(Phalcon_Internal_Test, cc1){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_class_entry, "C1", strlen("C1") TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, cc2){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_class_entry, "C2", strlen("C2") TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, cc3){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_class_entry, "C3", strlen("C3") TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, cc4){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_class_entry, "C4", strlen("C4") TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, cc5){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_class_entry, "C5", strlen("C5") TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, cc6){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_internal_test_class_entry, "C6", strlen("C6") TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_Test, is1){

	zval *v0 = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_bool(a0, 0);
	PHALCON_CPY_WRT(v0, a0);
	eval_int = phalcon_array_isset_long(v0, 0);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, is2){

	zval *v0 = NULL;
	zval *i0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v0, i0);
	phalcon_update_property_long(v0, "b", strlen("b"), 15 TSRMLS_CC);
	eval_int = phalcon_isset_property(v0, "b", strlen("b") TSRMLS_CC);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, is3){

	zval *v0 = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v0, a0);
	eval_int = phalcon_array_isset_long(v0, 0);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, is4){

	zval *v0 = NULL;
	zval *i0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v0, i0);
	phalcon_update_property_long(v0, "c", strlen("c"), 10 TSRMLS_CC);
	eval_int = phalcon_isset_property(v0, "b", strlen("b") TSRMLS_CC);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, is5){

	zval *v0 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v0, a0);
	eval_int = phalcon_array_isset_long(v0, 0);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	if (!zend_is_true(r0)) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, is6){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v0, i0);
	phalcon_update_property_long(v0, "c", strlen("c"), 10 TSRMLS_CC);
	eval_int = phalcon_isset_property(v0, "b", strlen("b") TSRMLS_CC);
	PHALCON_INIT_VAR(t0);
	ZVAL_BOOL(t0, eval_int);
	if (!zend_is_true(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, is7){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, "hello", strlen("hello"), 1);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(v1);
	ZVAL_LONG(v1, 0);
	eval_int = phalcon_array_isset(v0, v1);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, is8){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v0, i0);
	phalcon_update_property_string(v0, "host", strlen("host"), "192.168.0.20" TSRMLS_CC);
	phalcon_update_property_string(v0, "username", strlen("username"), "support" TSRMLS_CC);
	phalcon_update_property_string(v0, "password", strlen("password"), "H45pov682v" TSRMLS_CC);
	phalcon_update_property_string(v0, "name", strlen("name"), "demo" TSRMLS_CC);
	eval_int = phalcon_isset_property(v0, "host", strlen("host") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, v0, "host", sizeof("host")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, is9){

	zval *v0 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_index_stringl(a1, 1, "hello", strlen("hello"), 1);
	Z_ADDREF_P(a1);
	PHALCON_SEPARATE_ARRAY(a0);
	add_next_index_zval(a0, a1);
	add_next_index_bool(a0, 0);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset_long(r0, 0);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, is10){

	zval *v0 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_index_stringl(a1, 1, "hello", strlen("hello"), 1);
	Z_ADDREF_P(a1);
	PHALCON_SEPARATE_ARRAY(a0);
	add_next_index_zval(a0, a1);
	add_next_index_bool(a0, 0);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset_long(r0, 1);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
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
	Z_ADDREF_P(a1);
	PHALCON_SEPARATE_ARRAY(a0);
	add_next_index_zval(a0, a1);
	add_next_index_bool(a0, 0);
	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), a0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, t0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset_long(r0, 1);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, is12){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_STRING(v0, "hello", 1);
	PHALCON_INIT_VAR(v1);
	ZVAL_STRING(v1, "lol", 1);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, "_p9", strlen("_p9"), a0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_p9", sizeof("_p9")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch(&r0, t0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(r0, v1);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(2);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, un1){

	zval *v0 = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_bool(a0, 0);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_SEPARATE_PARAM(v0);
	phalcon_array_unset_long(v0, 0);
	PHALCON_RETURN_CTOR(v0);
}

PHP_METHOD(Phalcon_Internal_Test, un2){

	zval *v0 = NULL;
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
	Z_ADDREF_P(a1);
	PHALCON_SEPARATE_ARRAY(a0);
	add_assoc_zval(a0, "lost", a1);
	add_next_index_stringl(a0, "hello", strlen("hello"), 1);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, v0, "lost", strlen("lost"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE_NMO(r0);
	phalcon_array_unset_long(r0, 1);
	PHALCON_RETURN_CTOR(v0);
}

PHP_METHOD(Phalcon_Internal_Test, un3){

	zval *v0 = NULL, *v1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	Z_ADDREF_P(v0);
	PHALCON_SEPARATE_ARRAY(a1);
	add_next_index_zval(a1, v0);
	add_next_index_stringl(a1, "hello", strlen("hello"), 1);
	PHALCON_CPY_WRT(v1, a1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE_NMO(r0);
	phalcon_array_unset_long(r0, 1);
	PHALCON_RETURN_CTOR(v0);
}

PHP_METHOD(Phalcon_Internal_Test, iof1){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(r0);
	phalcon_instance_of(r0, this_ptr, phalcon_internal_test_class_entry TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, iof2){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v0, i0);
		ce0 = zend_fetch_class("stdclass", strlen("stdclass"), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_INIT_VAR(r0);
	phalcon_instance_of(r0, v0, ce0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, iof3){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_internal_testparent_class_entry);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	PHALCON_CPY_WRT(v0, i0);
	PHALCON_INIT_VAR(r0);
	phalcon_instance_of(r0, v0, phalcon_internal_testparent_class_entry TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, t1){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v0);
	PHALCON_SEPARATE_PARAM(v1);
	
	PHALCON_INIT_VAR(v0);
	ZVAL_LONG(v0, 17);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 100);
	Z_ADDREF_P(t0);
	if (Z_REFCOUNT_P(v1) > 1) {
		zval *new_zv;
		Z_DELREF_P(v1);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v1);
		v1 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update_long(v1, 0, t0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, t2){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_STRING(v0, "", 1);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 1);
	add_next_index_long(a0, 2);
	add_next_index_long(a0, 3);
	add_next_index_long(a0, 4);
	PHALCON_CPY_WRT(v1, a0);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_22:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_22;
		} else {
			PHALCON_INIT_VAR(v3);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v3, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v3, num);
				}
			}
		}
		PHALCON_INIT_VAR(v2);
		ZVAL_ZVAL(v2, *hd, 1, 0);
		Z_ADDREF_P(v3);
		p0[0] = v3;
		Z_ADDREF_P(v1);
		p0[1] = v1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "t1", 2, p0, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p0[0]);
		Z_DELREF_P(p0[1]);
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch_long(&r0, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_INIT_VAR(r1);
		concat_function(r1, v3, r0 TSRMLS_CC);
		PHALCON_INIT_VAR(r2);
		concat_function(r2, v0, r1 TSRMLS_CC);
		PHALCON_CPY_WRT(v0, r2);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_22;
		fee_fdd7_22:
		if(0){ };
	}
	PHALCON_RETURN_CTOR(v0);
}

PHP_METHOD(Phalcon_Internal_Test, t3){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 5);
	PHALCON_ALLOC_ZVAL_MM(r0);
	mod_function(r0, v1, t0 TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, r0, t1 TSRMLS_CC);
	if (zend_is_true(r1)) {
		t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t2);
	} else {
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 15);
		PHALCON_ALLOC_ZVAL_MM(r2);
		mul_function(r2, v1, t3 TSRMLS_CC);
		PHALCON_RETURN_CTOR(r2);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, t4){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v1);
	
	PHALCON_INIT_VAR(v1);
	ZVAL_LONG(v1, 25);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 5);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, v0, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "sqrt", v1, 0x027);
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_add_function(r2, r1, v0 TSRMLS_CC);
		PHALCON_RETURN_CTOR(r2);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, t5){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v0);
	PHALCON_SEPARATE_PARAM(v1);
	
	phalcon_update_property_long(this_ptr, "_p0", strlen("_p0"), 0 TSRMLS_CC);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v3, a0);
	ws_fdd7_23:
	if (0) {
		goto we_fdd7_23;
	}
	PHALCON_INIT_VAR(r0);
	mul_function(r0, v0, v1 TSRMLS_CC);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, r0 TSRMLS_CC);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_INIT_VAR(r1);
	phalcon_add_function(r1, v0, t0 TSRMLS_CC);
	PHALCON_CPY_WRT(v0, r1);
	PHALCON_INIT_VAR(t1);
	phalcon_read_property(&t1, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
		phalcon_add_function(r5, v2, t4 TSRMLS_CC);
		Z_ADDREF_P(r5);
		p0[0] = r5;
		t5 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(t5);
		p0[1] = t5;
		PHALCON_CALL_SELF_PARAMS(r4, this_ptr, "t4", 2, p0);
		Z_DELREF_P(p0[0]);
		Z_DELREF_P(p0[1]);
		Z_ADDREF_P(r4);
		PHALCON_SEPARATE_ARRAY(v3);
		phalcon_array_append(v3, r4 TSRMLS_CC);
		PHALCON_INIT_VAR(t6);
		ZVAL_LONG(t6, 10);
		Z_ADDREF_P(t6);
		PHALCON_SEPARATE_ARRAY(v3);
		phalcon_array_append(v3, t6 TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(r6);
		Z_ADDREF_P(v0);
		p1[0] = v0;
		Z_ADDREF_P(v1);
		p1[1] = v1;
		PHALCON_CALL_METHOD_PARAMS(r6, this_ptr, "t3", 2, p1, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p1[0]);
		Z_DELREF_P(p1[1]);
		Z_ADDREF_P(r6);
		PHALCON_SEPARATE_ARRAY(v3);
		phalcon_array_append(v3, r6 TSRMLS_CC);
	}
	PHALCON_INIT_VAR(t7);
	phalcon_read_property(&t7, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(t8);
	ZVAL_LONG(t8, 3);
	PHALCON_INIT_VAR(r7);
	mul_function(r7, t7, t8 TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r7);
	PHALCON_INIT_VAR(t9);
	phalcon_read_property(&t9, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t9);
	increment_function(t9);
	phalcon_update_property_zval(this_ptr, "_p0", strlen("_p0"), t9 TSRMLS_CC);
	PHALCON_INIT_VAR(t10);
	phalcon_read_property(&t10, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	PHALCON_RETURN_CTOR(v3);
}

PHP_METHOD(Phalcon_Internal_Test, t6){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL;
	zval *p1[] = { NULL, NULL, NULL, NULL }, *p2[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 0);
	add_next_index_long(a0, 25);
	PHALCON_CPY_WRT(v3, a0);
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_internal_testparent_class_entry);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, i0 TSRMLS_CC);
	PHALCON_INIT_VAR(v4);
	ZVAL_LONG(v4, 0);
	fs_fdd7_24:
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_INIT_VAR(r0);
	is_smaller_function(r0, v4, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe_fdd7_24;
	}
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 5);
	PHALCON_INIT_VAR(r1);
	is_smaller_function(r1, v4, t1 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch_long(&r2, v3, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_INIT_VAR(r3);
		t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(t2);
		p1[0] = t2;
		Z_ADDREF_P(v4);
		p1[1] = v4;
		Z_ADDREF_P(v0);
		p1[2] = v0;
		Z_ADDREF_P(v1);
		p1[3] = v1;
		PHALCON_CALL_STATIC_PARAMS(r3, "phalcon_internal_testparent", "smp6", 4, p1);
		Z_DELREF_P(p1[0]);
		Z_DELREF_P(p1[1]);
		Z_DELREF_P(p1[2]);
		Z_DELREF_P(p1[3]);
		PHALCON_INIT_VAR(r4);
		phalcon_add_function(r4, r2, r3 TSRMLS_CC);
		Z_ADDREF_P(r4);
		if (Z_REFCOUNT_P(v3) > 1) {
			zval *new_zv;
			Z_DELREF_P(v3);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v3);
			v3 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_long(v3, 1, r4 TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(r5);
		phalcon_array_fetch_long(&r5, v3, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_INIT_VAR(r6);
		t3 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(t3);
		p2[0] = t3;
		PHALCON_INIT_VAR(r7);
		phalcon_array_fetch_long(&r7, v3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_SEPARATE_NMO(r7);
		PHALCON_INIT_VAR(t4);
		ZVAL_ZVAL(t4, r7, 1, 0);
		increment_function(r7);
		Z_ADDREF_P(r7);
		if (Z_REFCOUNT_P(v3) > 1) {
			zval *new_zv;
			Z_DELREF_P(v3);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v3);
			v3 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_long(v3, 0, r7 TSRMLS_CC);
		Z_ADDREF_P(t4);
		p2[1] = t4;
		Z_ADDREF_P(v1);
		p2[2] = v1;
		Z_ADDREF_P(v2);
		p2[3] = v2;
		PHALCON_CALL_SELF_PARAMS(r6, this_ptr, "smp6", 4, p2);
		Z_DELREF_P(p2[0]);
		Z_DELREF_P(p2[1]);
		Z_DELREF_P(p2[2]);
		Z_DELREF_P(p2[3]);
		PHALCON_INIT_VAR(r8);
		phalcon_add_function(r8, r5, r6 TSRMLS_CC);
		Z_ADDREF_P(r8);
		if (Z_REFCOUNT_P(v3) > 1) {
			zval *new_zv;
			Z_DELREF_P(v3);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v3);
			v3 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_long(v3, 1, r8 TSRMLS_CC);
	}
	PHALCON_SEPARATE(v4);
	increment_function(v4);
	goto fs_fdd7_24;
	fe_fdd7_24:
	PHALCON_ALLOC_ZVAL_MM(r9);
	phalcon_array_fetch_long(&r9, v3, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r10);
	t5 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r10, t5, "mp7", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r11);
	phalcon_add_function(r11, r9, r10 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r11);
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_long(a0, 0);
	add_next_index_long(a0, 25);
	PHALCON_CPY_WRT(v2, a0);
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_internal_testparent_class_entry);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	zend_update_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, i0 TSRMLS_CC);
	PHALCON_INIT_VAR(v3);
	ZVAL_LONG(v3, 0);
	fs_fdd7_25:
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_INIT_VAR(r0);
	is_smaller_function(r0, v3, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe_fdd7_25;
	}
	PHALCON_CPY_WRT(v4, v0);
	fs_fdd7_26:
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_INIT_VAR(r1);
	is_smaller_function(r1, t1, v4 TSRMLS_CC);
	if (!zend_is_true(r1)) {
		goto fe_fdd7_26;
	}
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 5);
	PHALCON_INIT_VAR(r2);
	is_smaller_function(r2, v3, t2 TSRMLS_CC);
	if (zend_is_true(r2)) {
		PHALCON_INIT_VAR(r3);
		phalcon_array_fetch_long(&r3, v2, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_INIT_VAR(r4);
		t3 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(t3);
		p1[0] = t3;
		Z_ADDREF_P(v3);
		p1[1] = v3;
		Z_ADDREF_P(v0);
		p1[2] = v0;
		Z_ADDREF_P(v1);
		p1[3] = v1;
		PHALCON_CALL_STATIC_PARAMS(r4, "phalcon_internal_testparent", "smp6", 4, p1);
		Z_DELREF_P(p1[0]);
		Z_DELREF_P(p1[1]);
		Z_DELREF_P(p1[2]);
		Z_DELREF_P(p1[3]);
		PHALCON_INIT_VAR(r5);
		phalcon_add_function(r5, r3, r4 TSRMLS_CC);
		Z_ADDREF_P(r5);
		if (Z_REFCOUNT_P(v2) > 1) {
			zval *new_zv;
			Z_DELREF_P(v2);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v2);
			v2 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_long(v2, 1, r5 TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(t4);
		ZVAL_LONG(t4, 4);
		PHALCON_INIT_VAR(r6);
		is_smaller_function(r6, t4, v4 TSRMLS_CC);
		if (zend_is_true(r6)) {
			PHALCON_INIT_VAR(r7);
			phalcon_array_fetch_long(&r7, v2, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(r8);
			t5 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			Z_ADDREF_P(t5);
			p2[0] = t5;
			PHALCON_INIT_VAR(r9);
			phalcon_array_fetch_long(&r9, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE_NMO(r9);
			decrement_function(r9);
			Z_ADDREF_P(r9);
			if (Z_REFCOUNT_P(v2) > 1) {
				zval *new_zv;
				Z_DELREF_P(v2);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v2);
				v2 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v2, 0, r9 TSRMLS_CC);
			Z_ADDREF_P(r9);
			p2[1] = r9;
			Z_ADDREF_P(v1);
			p2[2] = v1;
			Z_ADDREF_P(v4);
			p2[3] = v4;
			PHALCON_CALL_SELF_PARAMS(r8, this_ptr, "smp6", 4, p2);
			Z_DELREF_P(p2[0]);
			Z_DELREF_P(p2[1]);
			Z_DELREF_P(p2[2]);
			Z_DELREF_P(p2[3]);
			PHALCON_INIT_VAR(r10);
			phalcon_add_function(r10, r7, r8 TSRMLS_CC);
			Z_ADDREF_P(r10);
			if (Z_REFCOUNT_P(v2) > 1) {
				zval *new_zv;
				Z_DELREF_P(v2);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v2);
				v2 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v2, 1, r10 TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(r11);
			phalcon_array_fetch_long(&r11, v2, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_INIT_VAR(r12);
			t6 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			Z_ADDREF_P(t6);
			p3[0] = t6;
			PHALCON_INIT_VAR(r13);
			phalcon_array_fetch_long(&r13, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE_NMO(r13);
			PHALCON_INIT_VAR(t7);
			ZVAL_ZVAL(t7, r13, 1, 0);
			increment_function(r13);
			Z_ADDREF_P(r13);
			if (Z_REFCOUNT_P(v2) > 1) {
				zval *new_zv;
				Z_DELREF_P(v2);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v2);
				v2 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v2, 0, r13 TSRMLS_CC);
			Z_ADDREF_P(t7);
			p3[1] = t7;
			Z_ADDREF_P(v0);
			p3[2] = v0;
			Z_ADDREF_P(v4);
			p3[3] = v4;
			PHALCON_CALL_SELF_PARAMS(r12, this_ptr, "smp6", 4, p3);
			Z_DELREF_P(p3[0]);
			Z_DELREF_P(p3[1]);
			Z_DELREF_P(p3[2]);
			Z_DELREF_P(p3[3]);
			PHALCON_INIT_VAR(r14);
			phalcon_add_function(r14, r11, r12 TSRMLS_CC);
			Z_ADDREF_P(r14);
			if (Z_REFCOUNT_P(v2) > 1) {
				zval *new_zv;
				Z_DELREF_P(v2);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v2);
				v2 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v2, 1, r14 TSRMLS_CC);
		}
	}
	PHALCON_SEPARATE(v4);
	decrement_function(v4);
	goto fs_fdd7_26;
	fe_fdd7_26:
	PHALCON_SEPARATE(v3);
	increment_function(v3);
	goto fs_fdd7_25;
	fe_fdd7_25:
	PHALCON_ALLOC_ZVAL_MM(r15);
	phalcon_array_fetch_long(&r15, v2, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r16);
	t8 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r16, t8, "mp7", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r17);
	phalcon_add_function(r17, r15, r16 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r17);
}

PHP_METHOD(Phalcon_Internal_Test, t9){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *p1[] = { NULL, NULL, NULL }, *p2[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, "cedula", strlen("cedula"), 1);
	add_next_index_stringl(a0, "nombre", strlen("nombre"), 1);
	add_next_index_stringl(a0, "saldo", strlen("saldo"), 1);
	add_next_index_stringl(a0, "estado", strlen("estado"), 1);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	phalcon_update_property_zval(this_ptr, "_p0", strlen("_p0"), a1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v1, i0);
	phalcon_update_property_string(v1, "cedula", strlen("cedula"), "hello" TSRMLS_CC);
	zend_update_property_null(Z_OBJCE_P(v1), v1, "nombre", strlen("nombre") TSRMLS_CC);
	zend_update_property_null(Z_OBJCE_P(v1), v1, "saldo", strlen("saldo") TSRMLS_CC);
	zend_update_property_null(Z_OBJCE_P(v1), v1, "estado", strlen("estado") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "count", v0, 0x007);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_INIT_VAR(v3);
	ZVAL_LONG(v3, 0);
	fs_fdd7_27:
	PHALCON_INIT_VAR(r1);
	is_smaller_function(r1, v3, v2 TSRMLS_CC);
	if (!zend_is_true(r1)) {
		goto fe_fdd7_27;
	}
	PHALCON_INIT_VAR(r2);
	phalcon_array_fetch(&r2, v0, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v4, r2);
	PHALCON_INIT_VAR(t0);
	phalcon_read_property_zval(&t0, v1, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v5, t0);
	PHALCON_INIT_VAR(r3);
	PHALCON_INIT_VAR(p1[0]);
	ZVAL_STRING(p1[0], "_id", 1);
	PHALCON_INIT_VAR(p1[1]);
	ZVAL_STRING(p1[1], "", 1);
	p1[2] = v4;
	PHALCON_CALL_FUNC_PARAMS(r3, "str_replace", 3, p1, 0x003);
	PHALCON_CPY_WRT(v6, r3);
	PHALCON_INIT_VAR(i1);
	object_init_ex(i1, phalcon_model_message_class_entry);
	PHALCON_INIT_VAR(r4);
	PHALCON_CONCAT_RIGHT(r4, v6, " is required");
	Z_ADDREF_P(r4);
	p2[0] = r4;
	Z_ADDREF_P(v4);
	p2[1] = v4;
	PHALCON_INIT_VAR(p2[2]);
	ZVAL_STRING(p2[2], "PresenceOf", 1);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 3, p2, PHALCON_CALL_CHECK);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	PHALCON_CPY_WRT(v7, i1);
	PHALCON_INIT_VAR(t1);
	phalcon_read_property(&t1, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v7);
	phalcon_array_append(t1, v7 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_p0", strlen("_p0"), t1 TSRMLS_CC);
	PHALCON_SEPARATE(v3);
	increment_function(v3);
	goto fs_fdd7_27;
	fe_fdd7_27:
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_p0", sizeof("_p0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t2);
}

PHP_METHOD(Phalcon_Internal_Test, t10){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
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
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_assoc_bool_ex(a1, "saldo", strlen("saldo")+1, 1);
	PHALCON_CPY_WRT(v1, a1);
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v2, i0);
	phalcon_update_property_string(v2, "cedula", strlen("cedula"), "hello" TSRMLS_CC);
	phalcon_update_property_string(v2, "nombre", strlen("nombre"), "LOL" TSRMLS_CC);
	phalcon_update_property_long(v2, "saldo", strlen("saldo"), 0 TSRMLS_CC);
	phalcon_update_property_string(v2, "estado", strlen("estado"), "X" TSRMLS_CC);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	PHALCON_CPY_WRT(v3, a2);
	if (Z_TYPE_P(v0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_28:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_28;
		}
		PHALCON_INIT_VAR(v4);
		ZVAL_ZVAL(v4, *hd, 1, 0);
		PHALCON_INIT_VAR(t0);
		phalcon_read_property_zval(&t0, v2, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v5, t0);
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, "", 1);
		PHALCON_INIT_VAR(r0);
		is_identical_function(r0, t1, v5 TSRMLS_CC);
		PHALCON_INIT_VAR(t2);
		ZVAL_NULL(t2);
		PHALCON_INIT_VAR(r1);
		is_identical_function(r1, t2, v5 TSRMLS_CC);
		PHALCON_INIT_VAR(r2);
		ZVAL_BOOL(r2, zend_is_true(r0) || zend_is_true(r1));
		if (zend_is_true(r2)) {
			PHALCON_INIT_VAR(t3);
			ZVAL_STRING(t3, "NULL", 1);
			Z_ADDREF_P(t3);
			PHALCON_SEPARATE_ARRAY(v3);
			phalcon_array_append(v3, t3 TSRMLS_CC);
		} else {
			eval_int = phalcon_array_isset(v1, v4);
			if (eval_int) {
				Z_ADDREF_P(v5);
				PHALCON_SEPARATE_ARRAY(v3);
				phalcon_array_append(v3, v5 TSRMLS_CC);
			} else {
				PHALCON_INIT_VAR(r3);
				PHALCON_CONCAT_BOTH(r3,  "'", v5, "'");
				Z_ADDREF_P(r3);
				PHALCON_SEPARATE_ARRAY(v3);
				phalcon_array_append(v3, r3 TSRMLS_CC);
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_28;
		fee_fdd7_28:
		if(0){ };
	}
	PHALCON_RETURN_CTOR(v3);
}

PHP_METHOD(Phalcon_Internal_Test, t11){

	zval *v0 = NULL, *v1 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_LONG(v0, 0);
	phalcon_update_property_string(this_ptr, "_p2", strlen("_p2"), "lol" TSRMLS_CC);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_p4", strlen("_p4"), 0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_internal_testdummy_class_entry);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
	Z_DELREF_P(p0[0]);
	PHALCON_CPY_WRT(v1, i0);
	ws_fdd7_29:
	PHALCON_INIT_VAR(t0);
	phalcon_read_property(&t0, this_ptr, "_p4", sizeof("_p4")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		goto we_fdd7_29;
	}
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_INIT_VAR(r0);
	is_equal_function(r0, v0, t1 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "x/y", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "f1", 1, p1, PHALCON_CALL_DEFAULT);
	}
	increment_function(v0);
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 2);
	PHALCON_INIT_VAR(r1);
	is_smaller_function(r1, t2, v0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_p4", strlen("_p4"), 1 TSRMLS_CC);
	}
	goto ws_fdd7_29;
	we_fdd7_29:
	if(0) { };
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_p4", strlen("_p4"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, "_p2", sizeof("_p2")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t3);
}

PHP_METHOD(Phalcon_Internal_Test, t12){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *c0 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "/", 1);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "explode", c0, v0, 0x005);
	PHALCON_CPY_WRT(v1, r0);
	eval_int = phalcon_array_isset_long(v1, 0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_long(&r1, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		p1[0] = r1;
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_filter_alphanum(r2, p1[0]);
		phalcon_update_property_zval(this_ptr, "_p1", strlen("_p1"), r2 TSRMLS_CC);
		PHALCON_SEPARATE(v1);
		phalcon_array_unset_long(v1, 0);
	}
	eval_int = phalcon_array_isset_long(v1, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_long(&r3, v1, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		p2[0] = r3;
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_filter_alphanum(r4, p2[0]);
		phalcon_update_property_zval(this_ptr, "_p2", strlen("_p2"), r4 TSRMLS_CC);
		PHALCON_SEPARATE(v1);
		phalcon_array_unset_long(v1, 1);
	}
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_p4", strlen("_p4"), 0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, t13){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *t0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	add_assoc_stringl_ex(a1, "sup", strlen("sup")+1, "hello1", strlen("hello1"), 1);
	Z_ADDREF_P(a1);
	PHALCON_SEPARATE_ARRAY(a0);
	add_assoc_zval(a0, "wish", a1);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	add_assoc_stringl_ex(a2, "xup", strlen("xup")+1, "hello2", strlen("hello2"), 1);
	Z_ADDREF_P(a2);
	PHALCON_SEPARATE_ARRAY(a0);
	add_assoc_zval(a0, "be", a2);
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	add_assoc_stringl_ex(a3, "zup", strlen("zup")+1, "hello3", strlen("hello3"), 1);
	Z_ADDREF_P(a3);
	PHALCON_SEPARATE_ARRAY(a0);
	add_assoc_zval(a0, "today", a3);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v1, i0);
	if (Z_TYPE_P(v0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_fdd7_30:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_fdd7_30;
		} else {
			PHALCON_INIT_VAR(v3);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v3, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v3, num);
				}
			}
		}
		PHALCON_INIT_VAR(v2);
		ZVAL_ZVAL(v2, *hd, 1, 0);
		if (Z_TYPE_P(v2) == IS_ARRAY) { 
			PHALCON_INIT_VAR(i1);
			object_init(i1);
			phalcon_update_property_zval(v1, Z_STRVAL_P(v3), Z_STRLEN_P(v3), i1 TSRMLS_CC);
			if (Z_TYPE_P(v2) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah1 = Z_ARRVAL_P(v2);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_fdd7_31:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee_fdd7_31;
				} else {
					PHALCON_INIT_VAR(v5);
					htype = zend_hash_get_current_key_ex(ah1, &index, &index_len, &num, 0, &hp1);
					if (htype == HASH_KEY_IS_STRING) {
						ZVAL_STRINGL(v5, index, index_len-1, 1);
					} else {
						if (htype == HASH_KEY_IS_LONG) {
							ZVAL_LONG(v5, num);
						}
					}
				}
				PHALCON_INIT_VAR(v4);
				ZVAL_ZVAL(v4, *hd, 1, 0);
				PHALCON_INIT_VAR(t0);
				phalcon_read_property_zval(&t0, v1, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
				phalcon_update_property_zval(t0, Z_STRVAL_P(v5), Z_STRLEN_P(v5), v4 TSRMLS_CC);
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_fdd7_31;
				fee_fdd7_31:
				if(0){ };
			}
		} else {
			phalcon_update_property_zval(v1, Z_STRVAL_P(v3), Z_STRLEN_P(v3), v2 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_fdd7_30;
		fee_fdd7_30:
		if(0){ };
	}
	PHALCON_RETURN_CTOR(v1);
}

PHP_METHOD(Phalcon_Internal_Test, t14){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(v0, i0);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(v0, "a", strlen("a"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(v1);
	ZVAL_LONG(v1, 0);
	fs_fdd7_32:
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_INIT_VAR(r0);
	is_smaller_function(r0, v1, t0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		goto fe_fdd7_32;
	}
	PHALCON_INIT_VAR(i1);
	object_init(i1);
	PHALCON_CPY_WRT(v2, i1);
	PHALCON_INIT_VAR(t1);
	phalcon_read_property(&t1, v0, "a", sizeof("a")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v2);
	phalcon_array_append(t1, v2 TSRMLS_CC);
	phalcon_update_property_zval(v0, "a", strlen("a"), t1 TSRMLS_CC);
	PHALCON_SEPARATE(v1);
	increment_function(v1);
	goto fs_fdd7_32;
	fe_fdd7_32:
	PHALCON_RETURN_CTOR(v0);
}

PHP_METHOD(Phalcon_Internal_Test, t15){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval **gv0;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	t0 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_array_fetch(&t1, t0, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
	if (zend_is_true(t1)) {
		t2 = zend_read_static_property(phalcon_internal_test_class_entry, "_sp0", sizeof("_sp0")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_array_fetch(&t3, t2, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t3);
	} else {
		phalcon_init_global("_POST", sizeof("_POST") TSRMLS_CC);
		if (&EG(symbol_table)) {
			if( zend_hash_find(&EG(symbol_table), "_POST", sizeof("_POST"), (void **) &gv0) == SUCCESS) {
				if(Z_TYPE_PP(gv0)==IS_ARRAY){
					g0 = *gv0;
				} else {
					PHALCON_INIT_VAR(g0);
					array_init(g0);
				}
			}
		}
		if (!g0) {
			PHALCON_INIT_VAR(g0);
			array_init(g0);
		}
		eval_int = phalcon_array_isset(g0, v0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_CALL_FUNC(r0, "get_magic_quotes_gpc", 0x029);
			if (!zend_is_true(r0)) {
				PHALCON_ALLOC_ZVAL_MM(r1);
				phalcon_array_fetch(&r1, g0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_RETURN_CHECK_CTOR(r1);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r2);
				PHALCON_ALLOC_ZVAL_MM(r3);
				phalcon_array_fetch(&r3, g0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r3);
				PHALCON_CALL_FUNC_PARAMS_1(r2, "stripslashes", r3, 0x02A);
				Z_DELREF_P(r3);
				PHALCON_RETURN_DZVAL(r2);
			}
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Internal_Test, t16){

	zval *v0 = NULL, *v1 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_internal_testdummy_class_entry);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "hello", 1);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
	PHALCON_CPY_WRT(v0, i0);
	PHALCON_ALLOC_ZVAL_MM(i1);
	phalcon_clone(i1, v0 TSRMLS_CC);
	PHALCON_CPY_WRT(v1, i1);
	PHALCON_INIT_VAR(p1[0]);
	ZVAL_STRING(p1[0], "lol", 1);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "f3", 1, p1, PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v1, "f2", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, v0, "f2", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, r0, r1 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r2);
}

PHP_METHOD(Phalcon_Internal_Test, t17){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v0, a0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "localhost", 1);
	PHALCON_INIT_VAR(p0[1]);
	ZVAL_STRING(p0[1], "root", 1);
	PHALCON_INIT_VAR(p0[2]);
	ZVAL_STRING(p0[2], "", 1);
	PHALCON_CALL_FUNC_PARAMS_NORETURN("mysql_connect", 3, p0, 0x02B);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "phalcon_test", 1);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("mysql_select_db", c0, 0x02C);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "SELECT * FROM robots", 1);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "mysql_query", c1, 0x02D);
	PHALCON_CPY_WRT(v1, r0);
	ws_fdd7_33:
	PHALCON_INIT_VAR(r1);
	Z_ADDREF_P(v1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "mysql_fetch_array", v1, 0x02E);
	Z_DELREF_P(v1);
	PHALCON_CPY_WRT(v2, r1);
	if (!zend_is_true(v2)) {
		goto we_fdd7_33;
	}
	Z_ADDREF_P(v2);
	PHALCON_SEPARATE_ARRAY(v0);
	phalcon_array_append(v0, v2 TSRMLS_CC);
	goto ws_fdd7_33;
	we_fdd7_33:
	if(0) { };
	PHALCON_RETURN_CTOR(v0);
}

