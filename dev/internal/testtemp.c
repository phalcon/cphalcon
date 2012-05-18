
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

PHP_METHOD(Phalcon_Internal_TestTemp, e5a){

	zval *a = NULL, *b = NULL, *c = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a);
	ZVAL_LONG(a, 5);
	PHALCON_CPY_WRT(b, a);
	PHALCON_CPY_WRT(c, b);
	PHALCON_INIT_VAR(c);
	ZVAL_LONG(c, 1);
	PHALCON_RETURN_NCTOR(a);
}

PHP_METHOD(Phalcon_Internal_TestTemp, e9a){

	zval *a = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(a, a0);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "LOL", 1);
	phalcon_array_update_long(&a, 0, t0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_RETURN_CTOR(a);
}

PHP_METHOD(Phalcon_Internal_TestTemp, e10a){

	zval *a = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(a, a0);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "LOL", 1);
	phalcon_array_update_long(&a, 0, t0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	phalcon_array_update_string(&a, "LOL", strlen("LOL"), t1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_RETURN_CTOR(a);
}

PHP_METHOD(Phalcon_Internal_TestTemp, e13a){

	zval *a = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(a, i0);
	phalcon_update_property_long(a, "uno", strlen("uno"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, a, "uno", sizeof("uno")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_TestTemp, e13b){

	zval *a = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;

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
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, a, "subA", sizeof("subA")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, t2, "dos", sizeof("dos")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t3);
}

PHP_METHOD(Phalcon_Internal_TestTemp, e13c){

	zval *a = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;

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
	phalcon_read_property(&t7, a, "subA", sizeof("subA")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t8);
	phalcon_read_property(&t8, t7, "subSubA", sizeof("subSubA")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t9);
	phalcon_read_property(&t9, t8, "dos", sizeof("dos")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t9);
}

PHP_METHOD(Phalcon_Internal_TestTemp, e13d){

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

PHP_METHOD(Phalcon_Internal_TestTemp, e14){

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

PHP_METHOD(Phalcon_Internal_TestTemp, e15){

	zval *a = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a);
	ZVAL_BOOL(a, 1);
	if (Z_TYPE_P(a) != IS_BOOL || (Z_TYPE_P(a) == IS_BOOL && Z_BVAL_P(a))) {
		php_printf("%ld", (long int) 1);
	}
	
	PHALCON_MM_RESTORE();
}

