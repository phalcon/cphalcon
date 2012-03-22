
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

PHP_METHOD(Phalcon_Internal_TestParent, mp1){


	PHALCON_MM_GROW();
	PHALCON_MM_RESTORE();
	RETURN_STRING("mp1", 1);
}

PHP_METHOD(Phalcon_Internal_TestParent, mp2){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_long(this_ptr, "_pp0", strlen("_pp0"), 0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_add_function(r0, v0, v1 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Internal_TestParent, mp7){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_pp0", sizeof("_pp0")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Internal_TestParent, smp1){


	PHALCON_MM_GROW();
	PHALCON_MM_RESTORE();
	RETURN_STRING("parent-protected", 1);
}

PHP_METHOD(Phalcon_Internal_TestParent, smp3){

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

PHP_METHOD(Phalcon_Internal_TestParent, smp6){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 10);
	PHALCON_INIT_VAR(r0);
	is_smaller_function(r0, t0, v1 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		mul_function(r1, v2, v3 TSRMLS_CC);
		PHALCON_RETURN_CTOR(r1);
	} else {
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 30);
		PHALCON_INIT_VAR(r2);
		is_smaller_function(r2, v2, t1 TSRMLS_CC);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			mul_function(r3, v1, v3 TSRMLS_CC);
			PHALCON_RETURN_CTOR(r3);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r4);
			Z_ADDREF_P(v1);
			p0[0] = v1;
			Z_ADDREF_P(v2);
			p0[1] = v2;
			PHALCON_CALL_METHOD_PARAMS(r4, v0, "mp7", 2, p0, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p0[0]);
			Z_DELREF_P(p0[1]);
			PHALCON_RETURN_DZVAL(r4);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

