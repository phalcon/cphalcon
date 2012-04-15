
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
 * @param  mixed $value
 * @param  mixed $filters
 * @param  boolean $silent
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, sanitize){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_BOOL(v2, 0);
	}
	
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		PHALCON_CPY_WRT(v3, v0);
		if (Z_TYPE_P(v0) != IS_NULL) {
			if (Z_TYPE_P(v1) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah0 = Z_ARRVAL_P(v1);
				zend_hash_internal_pointer_reset_ex(ah0, &hp0);
				fes_e618_0:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_e618_0;
				}
				PHALCON_INIT_VAR(v4);
				ZVAL_ZVAL(v4, *hd, 1, 0);
				PHALCON_INIT_VAR(r0);
				Z_ADDREF_P(v3);
				p0[0] = v3;
				Z_ADDREF_P(v4);
				p0[1] = v4;
				Z_ADDREF_P(v2);
				p0[2] = v2;
				PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_sanitize", 3, p0, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p0[0]);
				Z_DELREF_P(p0[1]);
				Z_DELREF_P(p0[2]);
				PHALCON_CPY_WRT(v3, r0);
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_e618_0;
				fee_e618_0:
				if(0){ };
			}
		}
		PHALCON_RETURN_CHECK_CTOR(v3);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		Z_ADDREF_P(v0);
		p1[0] = v0;
		Z_ADDREF_P(v1);
		p1[1] = v1;
		Z_ADDREF_P(v2);
		p1[2] = v2;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "_sanitize", 3, p1, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p1[0]);
		Z_DELREF_P(p1[1]);
		Z_DELREF_P(p1[2]);
		PHALCON_RETURN_DZVAL(r1);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Filters a value with a specified single or set of filters
 *
 * @param  mixed $value
 * @param  array $filters
 * @param  boolean $silent
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, filter){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_BOOL(v2, 0);
	}
	
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		PHALCON_CPY_WRT(v3, v0);
		if (Z_TYPE_P(v0) != IS_NULL) {
			if (Z_TYPE_P(v1) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah0 = Z_ARRVAL_P(v1);
				zend_hash_internal_pointer_reset_ex(ah0, &hp0);
				fes_e618_1:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_e618_1;
				}
				PHALCON_INIT_VAR(v4);
				ZVAL_ZVAL(v4, *hd, 1, 0);
				PHALCON_INIT_VAR(r0);
				Z_ADDREF_P(v3);
				p0[0] = v3;
				Z_ADDREF_P(v4);
				p0[1] = v4;
				Z_ADDREF_P(v2);
				p0[2] = v2;
				PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_filter", 3, p0, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p0[0]);
				Z_DELREF_P(p0[1]);
				Z_DELREF_P(p0[2]);
				PHALCON_CPY_WRT(v3, r0);
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_e618_1;
				fee_e618_1:
				if(0){ };
			}
		}
		PHALCON_RETURN_CHECK_CTOR(v3);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		Z_ADDREF_P(v0);
		p1[0] = v0;
		Z_ADDREF_P(v1);
		p1[1] = v1;
		Z_ADDREF_P(v2);
		p1[2] = v2;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "_filter", 3, p1, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p1[0]);
		Z_DELREF_P(p1[1]);
		Z_DELREF_P(p1[2]);
		PHALCON_RETURN_DZVAL(r1);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sanitize and Filter a value with a specified single or set of filters
 *
 * @param  mixed $value
 * @param  array $filters
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, sanitizeAndFilter){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL };

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
	PHALCON_INIT_VAR(p0[2]);
	ZVAL_BOOL(p0[2], 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "sanitize", 3, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	p1[0] = v2;
	Z_ADDREF_P(v1);
	p1[1] = v1;
	PHALCON_INIT_VAR(p1[2]);
	ZVAL_BOOL(p1[2], 1);
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "filter", 3, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	Z_DELREF_P(p1[1]);
	PHALCON_CPY_WRT(v2, r1);
	PHALCON_RETURN_CHECK_CTOR(v2);
}

/**
 * Internal sanizite wrapper to filter_var
 *
 * @param  mixed $value
 * @param  mixed $filters
 * @param  boolean $silent
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, _sanitize){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	zval *p3[] = { NULL, NULL, NULL }, *p4[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_BOOL(v2, 0);
	}
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "email", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, v1, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 517);
		PHALCON_CALL_FUNC_PARAMS_2(r1, "filter_var", v0, t1, 0x03D);
		PHALCON_RETURN_DZVAL(r1);
	}
	PHALCON_INIT_VAR(t2);
	ZVAL_STRING(t2, "int", 1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	is_equal_function(r2, v1, t2 TSRMLS_CC);
	if (zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 519);
		PHALCON_CALL_FUNC_PARAMS_2(r3, "filter_var", v0, t3, 0x03D);
		PHALCON_RETURN_DZVAL(r3);
	}
	PHALCON_INIT_VAR(t4);
	ZVAL_STRING(t4, "string", 1);
	PHALCON_ALLOC_ZVAL_MM(r4);
	is_equal_function(r4, v1, t4 TSRMLS_CC);
	if (zend_is_true(r4)) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_INIT_VAR(t5);
		ZVAL_LONG(t5, 513);
		PHALCON_CALL_FUNC_PARAMS_2(r5, "filter_var", v0, t5, 0x03D);
		PHALCON_RETURN_DZVAL(r5);
	}
	PHALCON_INIT_VAR(t6);
	ZVAL_STRING(t6, "float", 1);
	PHALCON_ALLOC_ZVAL_MM(r6);
	is_equal_function(r6, v1, t6 TSRMLS_CC);
	if (zend_is_true(r6)) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		p3[0] = v0;
		PHALCON_INIT_VAR(t7);
		ZVAL_LONG(t7, 520);
		p3[1] = t7;
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_INIT_VAR(t8);
		ZVAL_LONG(t8, 4096);
		Z_ADDREF_P(t8);
		PHALCON_SEPARATE_ARRAY(a0);
		add_assoc_zval(a0, "flags", t8);
		p3[2] = a0;
		PHALCON_CALL_FUNC_PARAMS(r7, "filter_var", 3, p3, 0x03D);
		PHALCON_RETURN_DZVAL(r7);
	}
	if (!zend_is_true(v2)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CONCAT_BOTH(r8,  "Sanitize filter ", v1, " is not supported");
		Z_ADDREF_P(r8);
		p4[0] = r8;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p4, PHALCON_CALL_CHECK);
		Z_DELREF_P(p4[0]);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	} else {
		PHALCON_RETURN_CHECK_CTOR(v0);
	}
	se_e618_2:
	if(0) { };
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Internal filter function
 *
 * @parammixed $value
 * @paramarray $filters
 * @param  boolean $silent
 * @returnmixed
 */
PHP_METHOD(Phalcon_Filter, _filter){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *p2[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_BOOL(v2, 0);
	}
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "extraspaces", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, v1, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		Z_ADDREF_P(v0);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "trim", v0, 0x020);
		Z_DELREF_P(v0);
		PHALCON_RETURN_DZVAL(r1);
	}
	PHALCON_INIT_VAR(t1);
	ZVAL_STRING(t1, "striptags", 1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	is_equal_function(r2, v1, t1 TSRMLS_CC);
	if (zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		Z_ADDREF_P(v0);
		PHALCON_CALL_FUNC_PARAMS_1(r3, "strip_tags", v0, 0x03E);
		Z_DELREF_P(v0);
		PHALCON_RETURN_DZVAL(r3);
	}
	if (!zend_is_true(v2)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_BOTH(r4,  "Filter ", v1, " is not supported");
		Z_ADDREF_P(r4);
		p2[0] = r4;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p2, PHALCON_CALL_CHECK);
		Z_DELREF_P(p2[0]);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	} else {
		PHALCON_RETURN_CHECK_CTOR(v0);
	}
	se_e618_3:
	if(0) { };
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

