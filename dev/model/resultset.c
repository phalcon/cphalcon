
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
 * Phalcon_Model_Resultset
 *
 * This component allows to Phalcon_Model_Base returns large resulsets with the minimum memory comsuption
 *
 * Resulsets can be traversed using a standard foreach or a while statement.
 *
 * 
 *
 */

/**
 * Phalcon_Model_Resultset constructor
 *
 * @param Phalcon_Model_Base $model
 * @param resource $resultResource
 */
PHP_METHOD(Phalcon_Model_Resultset, __construct){

	zval *v0 = NULL, *v1 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), copy TSRMLS_CC);
	}
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_resultResource", strlen("_resultResource"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Check whether internal resource has rows to fetch
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Resultset, valid){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL, NULL }, *p4[] = { NULL };

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t0) == IS_BOOL && !Z_BVAL_P(t0)) {
		RETURN_FALSE;
	}
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(t1);
	v0 = t1;
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, v0, "getconnection", PHALCON_CALL_DEFAULT);
	if (v1) {
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	PHALCON_GET_CLASS_CONSTANT(t2, phalcon_db_class_entry, "DB_ASSOC");
	Z_ADDREF_P(t2);
	p1[0] = t2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "setfetchmode", 1, p1, PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_read_property(t3, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t3);
	p2[0] = t3;
	PHALCON_CALL_METHOD_PARAMS(r1, v1, "fetcharray", 1, p2, PHALCON_CALL_DEFAULT);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	if (zend_is_true(v2)) {
		PHALCON_ALLOC_ZVAL(r2);
		Z_ADDREF_P(v0);
		p3[0] = v0;
		Z_ADDREF_P(v2);
		p3[1] = v2;
		PHALCON_CALL_STATIC_PARAMS(r2, "phalcon_model_base", "dumpresult", 2, p3);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_activeRow", strlen("_activeRow"), copy TSRMLS_CC);
		}
		RETURN_TRUE;
	} else {
		PHALCON_GET_CLASS_CONSTANT(t4, phalcon_db_class_entry, "DB_BOTH");
		Z_ADDREF_P(t4);
		p4[0] = t4;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "setfetchmode", 1, p4, PHALCON_CALL_DEFAULT);
		RETURN_FALSE;
	}
	RETURN_NULL();
}

/**
 * Returns current row in the resultset
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Resultset, current){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_activeRow", sizeof("_activeRow")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
}

/**
 * Moves cursor to next row in the resultset
 *
 */
PHP_METHOD(Phalcon_Model_Resultset, next){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	{
		zval *orig_ptr = t0;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(t0);
			*t0 = *orig_ptr;
			zval_copy_ctor(t0);
			Z_SET_REFCOUNT_P(t0, 1);
			Z_UNSET_ISREF_P(t0);
		}
	}
	increment_function(t0);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Gets pointer number to active row in the resultset
 *
 */
PHP_METHOD(Phalcon_Model_Resultset, key){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
}

/**
 * Rewinds resultset to its beginning
 *
 */
PHP_METHOD(Phalcon_Model_Resultset, rewind){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p1[] = { NULL, NULL };

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t0) == IS_BOOL && !Z_BVAL_P(t0)) {
		RETURN_FALSE;
	}
	phalcon_update_property_long(this_ptr, "pointer", strlen("pointer"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t1, "getconnection", PHALCON_CALL_DEFAULT);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(r0);
	v0 = r0;
	PHALCON_PARAM_LONG(p1[0], 0);
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t2);
	p1[1] = t2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "dataseek", 2, p1, PHALCON_CALL_DEFAULT);
	RETURN_NULL();
}

/**
 * Changes interal pointer to a specifically position in the resultset
 */
PHP_METHOD(Phalcon_Model_Resultset, seek){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p1[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	convert_to_long(v0);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), copy TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t0, "getconnection", PHALCON_CALL_DEFAULT);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	convert_to_long(v0);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t1);
	p1[1] = t1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "dataseek", 2, p1, PHALCON_CALL_DEFAULT);
	RETURN_NULL();
}

/**
 * Counts how many rows are in the resultset
 *
 * @return int
 */
PHP_METHOD(Phalcon_Model_Resultset, count){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *v0 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL };

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t0) == IS_BOOL && !Z_BVAL_P(t0)) {
		RETURN_LONG(0);
	}
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_count", sizeof("_count")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t1);
	p0[0] = t1;
	PHALCON_CALL_FUNC_PARAMS(r0, "is_null", strlen("is_null"), 1, p0);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CALL_METHOD(r1, t2, "getconnection", PHALCON_CALL_DEFAULT);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(r1);
		v0 = r1;
		PHALCON_ALLOC_ZVAL(r2);
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t3);
		p2[0] = t3;
		PHALCON_CALL_METHOD_PARAMS(r2, v0, "numrows", 1, p2, PHALCON_CALL_DEFAULT);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_count", strlen("_count"), copy TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(t4);
	phalcon_read_property(t4, this_ptr, "_count", sizeof("_count")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t4) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t4);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t4);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

/**
 * Checks whether offset exists in the resultset
 *
 * @param int $index
 */
PHP_METHOD(Phalcon_Model_Resultset, offsetExists){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "count", PHALCON_CALL_DEFAULT);
	PHALCON_SMALLER_FUNCTION(r1, v0, r0);
	if (zend_is_true(r1)) {
		RETURN_TRUE;
	}
	RETURN_NULL();
}

/**
 * Gets row in a specifically position of the resultset
 *
 * @param int $index
 */
PHP_METHOD(Phalcon_Model_Resultset, offsetGet){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL }, *p4[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "count", PHALCON_CALL_DEFAULT);
	PHALCON_SMALLER_FUNCTION(r1, v0, r0);
	if (zend_is_true(r1)) {
		Z_ADDREF_P(v0);
		p1[0] = v0;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "seek", 1, p1, PHALCON_CALL_DEFAULT);
		PHALCON_ALLOC_ZVAL(r2);
		PHALCON_CALL_METHOD(r2, this_ptr, "valid", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL(r3);
			PHALCON_CALL_METHOD(r3, this_ptr, "current", PHALCON_CALL_DEFAULT);
			RETURN_ZVAL(r3, 1, 0);
		} else {
			RETURN_FALSE;
		}
	} else {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_ALLOC_ZVAL(p4[0]);
		ZVAL_STRING(p4[0], "The index does not exist in the cursor", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p4, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	RETURN_NULL();
}

/**
 * Resulsets cannot be changed. It has only been implemented to meet the definition of the interface
 *
 * @param int $index
 */
PHP_METHOD(Phalcon_Model_Resultset, offsetSet){

	zval *v0 = NULL, *v1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_model_exception_class_entry);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "Cursor is read only", 1);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
	zend_throw_exception_object(i0 TSRMLS_CC);
	Z_ADDREF_P(i0);
	return;
}

/**
 * Resulsets cannot be changed. It has only been implemented to meet the definition of the interface
 *
 * @param int $index
 */
PHP_METHOD(Phalcon_Model_Resultset, offsetUnset){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_model_exception_class_entry);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "Cursor is read only", 1);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
	zend_throw_exception_object(i0 TSRMLS_CC);
	Z_ADDREF_P(i0);
	return;
}

/**
 * Get first row in the resultset
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Resultset, getFirst){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_NOT_EQUAL_FUNCTION(r0, t0, t1);
	if (zend_is_true(r0)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "rewind", PHALCON_CALL_DEFAULT);
	}
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_FALSE(t3);
	PHALCON_NOT_IDENTICAL_FUNCTION(r1, t2, t3);
	if (zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL(r2);
		PHALCON_CALL_METHOD(r2, this_ptr, "valid", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL(r3);
			PHALCON_CALL_METHOD(r3, this_ptr, "current", PHALCON_CALL_DEFAULT);
			RETURN_ZVAL(r3, 1, 0);
		} else {
			RETURN_FALSE;
		}
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

/**
 * Get last row in the resultset
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Resultset, getLast){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *p0[] = { NULL };

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_FALSE(t1);
	PHALCON_NOT_IDENTICAL_FUNCTION(r0, t0, t1);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "count", PHALCON_CALL_DEFAULT);
		PHALCON_ALLOC_ZVAL(t2);
		ZVAL_LONG(t2, 1);
		PHALCON_ALLOC_ZVAL(r2);
		sub_function(r2, r1, t2 TSRMLS_CC);
		Z_ADDREF_P(r2);
		p0[0] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "seek", 1, p0, PHALCON_CALL_DEFAULT);
		PHALCON_ALLOC_ZVAL(r3);
		PHALCON_CALL_METHOD(r3, this_ptr, "valid", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r3)) {
			PHALCON_ALLOC_ZVAL(r4);
			PHALCON_CALL_METHOD(r4, this_ptr, "current", PHALCON_CALL_DEFAULT);
			RETURN_ZVAL(r4, 1, 0);
		} else {
			RETURN_FALSE;
		}
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

/**
 * Get model which originates the resultset
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Resultset, getModel){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
}

