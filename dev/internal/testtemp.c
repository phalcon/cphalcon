
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

#include "kernel/array.h"
#include "kernel/object.h"
PHP_METHOD(Phalcon_Internal_TestTemp, e5a){

	zval *a = NULL, *b = NULL, *c = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a);
	ZVAL_LONG(a, 5);
	PHALCON_CPY_WRT(b, a);
	PHALCON_CPY_WRT(c, b);
	
	PHALCON_INIT_VAR(c);
	ZVAL_LONG(c, 1);
	
	RETURN_NCTOR(a);
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
	phalcon_array_update_long(&a, 0, &t0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	RETURN_CTOR(a);
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
	phalcon_array_update_long(&a, 0, &t0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	phalcon_array_update_string(&a, SL("LOL"), &t1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	RETURN_CTOR(a);
}

PHP_METHOD(Phalcon_Internal_TestTemp, e13a){

	zval *a = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init(i0);
	PHALCON_CPY_WRT(a, i0);
	phalcon_update_property_long(a, SL("uno"), 1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, a, SL("uno"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_TestTemp, e13b){

	zval *a = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;

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
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, a, SL("subA"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, t2, SL("dos"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t3);
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
	phalcon_read_property(&t7, a, SL("subA"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t8);
	phalcon_read_property(&t8, t7, SL("subSubA"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t9);
	phalcon_read_property(&t9, t8, SL("dos"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t9);
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
	phalcon_update_property_zval(a, SL("val"), val TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, a, SL("val"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
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

