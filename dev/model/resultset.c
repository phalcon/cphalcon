
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

	zval *model = NULL, *result_resource = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &model, &result_resource) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	
	phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), model TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_resultResource", strlen("_resultResource"), result_resource TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether internal resource has rows to fetch
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Resultset, valid){

	zval *model = NULL, *db_resource = NULL, *row = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *c0 = NULL, *c1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY TSRMLS_CC);
	if (Z_TYPE_P(t0) == IS_BOOL && !Z_BVAL_P(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(model, t1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, model, "getconnection", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(db_resource, r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_LONG(c0, 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(db_resource, "setfetchmode", c0, PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_1(r1, db_resource, "fetcharray", t2, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(row, r1);
	if (zend_is_true(row)) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_STATIC_PARAMS_2(r2, "phalcon_model_base", "dumpresult", model, row);
		phalcon_update_property_zval(this_ptr, "_activeRow", strlen("_activeRow"), r2 TSRMLS_CC);
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_INIT_VAR(c1);
		ZVAL_LONG(c1, 2);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(db_resource, "setfetchmode", c1, PHALCON_NO_CHECK);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns current row in the resultset
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Resultset, current){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_activeRow", sizeof("_activeRow")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Moves cursor to next row in the resultset
 *
 */
PHP_METHOD(Phalcon_Model_Resultset, next){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_SEPARATE_NMO(t0);
	increment_function(t0);
	phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets pointer number to active row in the resultset
 *
 */
PHP_METHOD(Phalcon_Model_Resultset, key){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Rewinds resultset to its beginning
 *
 */
PHP_METHOD(Phalcon_Model_Resultset, rewind){

	zval *db_resource = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY TSRMLS_CC);
	if (Z_TYPE_P(t0) == IS_BOOL && !Z_BVAL_P(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	phalcon_update_property_long(this_ptr, "pointer", strlen("pointer"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t1, "getconnection", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(db_resource, r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_LONG(c0, 0);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(db_resource, "dataseek", c0, t2, PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Changes interal pointer to a specifically position in the resultset
 */
PHP_METHOD(Phalcon_Model_Resultset, seek){

	zval *position = NULL, *db_resource = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &position) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(position);
	
	convert_to_long(position);
	phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), position TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t0, "getconnection", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(db_resource, r0);
	convert_to_long(position);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(db_resource, "dataseek", position, t1, PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Counts how many rows are in the resultset
 *
 * @return int
 */
PHP_METHOD(Phalcon_Model_Resultset, count){

	zval *db_resource = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY TSRMLS_CC);
	if (Z_TYPE_P(t0) == IS_BOOL && !Z_BVAL_P(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(0);
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_count", sizeof("_count")-1, PHALCON_NOISY TSRMLS_CC);
	Z_ADDREF_P(t1);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_null", t1, 0x040);
	Z_DELREF_P(t1);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD(r1, t2, "getconnection", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(db_resource, r1);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1(r2, db_resource, "numrows", t3, PHALCON_NO_CHECK);
		phalcon_update_property_zval(this_ptr, "_count", strlen("_count"), r2 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, "_count", sizeof("_count")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t4);
}

/**
 * Checks whether offset exists in the resultset
 *
 * @param int $index
 */
PHP_METHOD(Phalcon_Model_Resultset, offsetExists){

	zval *index = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "count", PHALCON_NO_CHECK);
	PHALCON_INIT_VAR(r1);
	is_smaller_function(r1, index, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets row in a specifically position of the resultset
 *
 * @param int $index
 */
PHP_METHOD(Phalcon_Model_Resultset, offsetGet){

	zval *index = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "count", PHALCON_NO_CHECK);
	PHALCON_INIT_VAR(r1);
	is_smaller_function(r1, index, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "seek", index, PHALCON_NO_CHECK);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, this_ptr, "valid", PHALCON_NO_CHECK);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CALL_METHOD(r3, this_ptr, "current", PHALCON_NO_CHECK);
			PHALCON_RETURN_DZVAL(r3);
		} else {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "The index does not exist in the cursor", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Resulsets cannot be changed. It has only been implemented to meet the definition of the interface
 *
 * @param int $index
 */
PHP_METHOD(Phalcon_Model_Resultset, offsetSet){

	zval *index = NULL, *value = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &index, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_model_exception_ce);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "Cursor is read only", 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
	phalcon_throw_exception(i0 TSRMLS_CC);
	return;
}

/**
 * Resulsets cannot be changed. It has only been implemented to meet the definition of the interface
 *
 * @param int $index
 */
PHP_METHOD(Phalcon_Model_Resultset, offsetUnset){

	zval *offset = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &offset) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_model_exception_ce);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "Cursor is read only", 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
	phalcon_throw_exception(i0 TSRMLS_CC);
	return;
}

/**
 * Get first row in the resultset
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Resultset, getFirst){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_INIT_VAR(r0);
	is_not_equal_function(r0, t0, t1 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "rewind", PHALCON_NO_CHECK);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY TSRMLS_CC);
	if (Z_TYPE_P(t2) != IS_BOOL || (Z_TYPE_P(t2) == IS_BOOL && Z_BVAL_P(t2))) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "valid", PHALCON_NO_CHECK);
		if (zend_is_true(r1)) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CALL_METHOD(r2, this_ptr, "current", PHALCON_NO_CHECK);
			PHALCON_RETURN_DZVAL(r2);
		}
		
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Get last row in the resultset
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Resultset, getLast){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_BOOL || (Z_TYPE_P(t0) == IS_BOOL && Z_BVAL_P(t0))) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, "count", PHALCON_NO_CHECK);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 1);
		PHALCON_ALLOC_ZVAL_MM(r1);
		sub_function(r1, r0, t1 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "seek", r1, PHALCON_NO_CHECK);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, this_ptr, "valid", PHALCON_NO_CHECK);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CALL_METHOD(r3, this_ptr, "current", PHALCON_NO_CHECK);
			PHALCON_RETURN_DZVAL(r3);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Get model which originates the resultset
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Resultset, getModel){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

