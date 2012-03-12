
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

/**
 * Phalcon_Filter
 *
 * The Phalcon_Filter component provides a set of commonly needed data filters. It provides
 * object oriented wrappers to the php filter extension
 *
 *
 *
 */

/**
 * Sanizites a value with a specified single or set of filters
 *
 * @param mixed $value
 * @param mixed $filters
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, sanitize){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		if (zend_is_true(v0)) {
			FOREACH_V(v1, ac0, fes54, fee54, ah0, hp0, v2)
				PHALCON_INIT_RESULT(r0);
				Z_ADDREF_P(v0);
				p0[0] = v0;
				Z_ADDREF_P(v2);
				p0[1] = v2;
				PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_sanitize", 2, p0, PHALCON_CALL_DEFAULT);
				PHALCON_CPY_WRT_PARAM(v0, r0);
			END_FOREACH(ac0, fes54, fee54, ah0, hp0);
		}
		PHALCON_RETURN_CHECK_CTOR(v0);
	} else {
		PHALCON_ALLOC_ZVAL(r1);
		Z_ADDREF_P(v0);
		p1[0] = v0;
		Z_ADDREF_P(v1);
		p1[1] = v1;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "_sanitize", 2, p1, PHALCON_CALL_DEFAULT);
		RETURN_ZVAL(r1, 1, 0);
	}
	RETURN_NULL();
}

/**
 * Internal sanizite wrapper to filter_var
 *
 * @param mixed $value
 * @param mixed $filters
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, _sanitize){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	zval *p3[] = { NULL, NULL, NULL }, *p4[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "email", 1);
	PHALCON_ALLOC_ZVAL(r0);
	is_equal_function(r0, v1, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_ALLOC_ZVAL(t1);
		ZVAL_LONG(t1, 517);
		PHALCON_CALL_FUNC_PARAMS_2(r1, "filter_var", v0, t1, 0x037);
		RETURN_ZVAL(r1, 1, 0);
	}
	PHALCON_ALLOC_ZVAL(t2);
	ZVAL_STRING(t2, "int", 1);
	PHALCON_ALLOC_ZVAL(r2);
	is_equal_function(r2, v1, t2 TSRMLS_CC);
	if (zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL(r3);
		PHALCON_ALLOC_ZVAL(t3);
		ZVAL_LONG(t3, 519);
		PHALCON_CALL_FUNC_PARAMS_2(r3, "filter_var", v0, t3, 0x037);
		RETURN_ZVAL(r3, 1, 0);
	}
	PHALCON_ALLOC_ZVAL(t4);
	ZVAL_STRING(t4, "string", 1);
	PHALCON_ALLOC_ZVAL(r4);
	is_equal_function(r4, v1, t4 TSRMLS_CC);
	if (zend_is_true(r4)) {
		PHALCON_ALLOC_ZVAL(r5);
		PHALCON_ALLOC_ZVAL(t5);
		ZVAL_LONG(t5, 513);
		PHALCON_CALL_FUNC_PARAMS_2(r5, "filter_var", v0, t5, 0x037);
		RETURN_ZVAL(r5, 1, 0);
	}
	PHALCON_ALLOC_ZVAL(t6);
	ZVAL_STRING(t6, "float", 1);
	PHALCON_ALLOC_ZVAL(r6);
	is_equal_function(r6, v1, t6 TSRMLS_CC);
	if (zend_is_true(r6)) {
		PHALCON_ALLOC_ZVAL(r7);
		p3[0] = v0;
		PHALCON_ALLOC_ZVAL(t7);
		ZVAL_LONG(t7, 520);
		p3[1] = t7;
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL(t8);
		ZVAL_LONG(t8, 4096);
		PHALCON_SEPARATE(a0);
		add_assoc_zval(a0, "flags", t8);
		p3[2] = a0;
		PHALCON_CALL_FUNC_PARAMS(r7, "filter_var", 3, p3, 0x037);
		RETURN_ZVAL(r7, 1, 0);
	}
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_exception_class_entry);
	PHALCON_ALLOC_ZVAL(r8);
	PHALCON_CONCAT_BOTH(r8,  "Filter ", v1, " is not supported");
	Z_ADDREF_P(r8);
	p4[0] = r8;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p4, PHALCON_CALL_CHECK);
	zend_throw_exception_object(i0 TSRMLS_CC);
	Z_ADDREF_P(i0);
	return;
	se55:
	php_printf("");
	RETURN_NULL();
}

