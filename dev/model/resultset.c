
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

/**
 * Phalcon_Model_Resultset
 *
 * This component allows to Phalcon_Model_Base returns large resulsets with the minimum memory consumption
 * Resulsets can be traversed using a standard foreach or a while statement. If a resultset is serialized
 * it will dump all the rows into a big array. Then unserialize will retrieve the rows as they were before
 * serializing.
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
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &model, &result_resource) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), model TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, model, "getconnection", PHALCON_NO_CHECK);
	phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), r0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_resultResource", strlen("_resultResource"), result_resource TSRMLS_CC);
	phalcon_update_property_long(this_ptr, "_type", strlen("_type"), 1 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether internal resource has rows to fetch
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Resultset, valid){

	zval *result_resource = NULL, *connection = NULL, *row = NULL, *rows = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_type", sizeof("_type")-1, PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(result_resource, t1);
		if (Z_TYPE_P(result_resource) != IS_BOOL || (Z_TYPE_P(result_resource) == IS_BOOL && Z_BVAL_P(result_resource))) {
			PHALCON_ALLOC_ZVAL_MM(t2);
			phalcon_read_property(&t2, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(connection, t2);
			
			PHALCON_INIT_VAR(c0);
			ZVAL_LONG(c0, 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(connection, "setfetchmode", c0, PHALCON_NO_CHECK);
			
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_CALL_METHOD_PARAMS_1(r0, connection, "fetcharray", result_resource, PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(row, r0);
			if (zend_is_true(row)) {
				PHALCON_ALLOC_ZVAL_MM(r1);
				PHALCON_ALLOC_ZVAL_MM(t3);
				phalcon_read_property(&t3, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY TSRMLS_CC);
				PHALCON_CALL_STATIC_PARAMS_2(r1, "phalcon_model_base", "dumpresult", t3, row);
				phalcon_update_property_zval(this_ptr, "_activeRow", strlen("_activeRow"), r1 TSRMLS_CC);
				PHALCON_MM_RESTORE();
				RETURN_TRUE;
			} else {
				PHALCON_INIT_VAR(c1);
				ZVAL_LONG(c1, 2);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(connection, "setfetchmode", c1, PHALCON_NO_CHECK);
			}
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_read_property(&t4, this_ptr, "_rows", sizeof("_rows")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(rows, t4);
		
		PHALCON_ALLOC_ZVAL_MM(r2);
		Z_SET_ISREF_P(rows);
		PHALCON_CALL_FUNC_PARAMS_1(r2, "current", rows, 0x054);
		Z_UNSET_ISREF_P(rows);
		PHALCON_CPY_WRT(row, r2);
		if (zend_is_true(row)) {
			Z_SET_ISREF_P(rows);
			PHALCON_CALL_FUNC_PARAMS_1_NORETURN("next", rows, 0x059);
			Z_UNSET_ISREF_P(rows);
			phalcon_update_property_zval(this_ptr, "_activeRow", strlen("_activeRow"), row TSRMLS_CC);
			PHALCON_MM_RESTORE();
			RETURN_TRUE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
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
 * Gets pointer number of active row in the resultset
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

	zval *result_resource = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_type", sizeof("_type")-1, PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(result_resource, t1);
		if (Z_TYPE_P(result_resource) != IS_BOOL || (Z_TYPE_P(result_resource) == IS_BOOL && Z_BVAL_P(result_resource))) {
			phalcon_update_property_long(this_ptr, "pointer", strlen("pointer"), 1 TSRMLS_CC);
			
			PHALCON_ALLOC_ZVAL_MM(t2);
			phalcon_read_property(&t2, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY TSRMLS_CC);
			
			PHALCON_INIT_VAR(c0);
			ZVAL_LONG(c0, 0);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(t2, "dataseek", c0, result_resource, PHALCON_NO_CHECK);
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_rows", sizeof("_rows")-1, PHALCON_NOISY TSRMLS_CC);
		Z_SET_ISREF_P(t3);
		PHALCON_CALL_FUNC_PARAMS_1_NORETURN("reset", t3, 0x055);
		Z_UNSET_ISREF_P(t3);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Changes internal pointer to a specific position in the resultset
 */
PHP_METHOD(Phalcon_Model_Resultset, seek){

	zval *position = NULL, *rows = NULL, *i = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &position) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "intval", position, 0x020);
	phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), r0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_type", sizeof("_type")-1, PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(t1, "dataseek", position, t2, PHALCON_NO_CHECK);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_rows", sizeof("_rows")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(rows, t3);
		Z_SET_ISREF_P(rows);
		PHALCON_CALL_FUNC_PARAMS_1_NORETURN("reset", rows, 0x055);
		Z_UNSET_ISREF_P(rows);
		
		PHALCON_INIT_VAR(i);
		ZVAL_LONG(i, 0);
		fs_fd08_0:
			
			PHALCON_INIT_VAR(r1);
			is_smaller_function(r1, i, position TSRMLS_CC);
			if (!zend_is_true(r1)) {
				goto fe_fd08_0;
			}
			Z_SET_ISREF_P(rows);
			PHALCON_CALL_FUNC_PARAMS_1_NORETURN("next", rows, 0x059);
			Z_UNSET_ISREF_P(rows);
			PHALCON_SEPARATE(i);
			increment_function(i);
			goto fs_fd08_0;
		fe_fd08_0:
		if(0){}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Counts how many rows are in the resultset
 *
 * @return int
 */
PHP_METHOD(Phalcon_Model_Resultset, count){

	zval *count = NULL, *result_resource = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_count", sizeof("_count")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_null", t0, 0x041);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(count);
		ZVAL_LONG(count, 0);
		
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_type", sizeof("_type")-1, PHALCON_NOISY TSRMLS_CC);
		if (zend_is_true(t1)) {
			PHALCON_ALLOC_ZVAL_MM(t2);
			phalcon_read_property(&t2, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(result_resource, t2);
			if (Z_TYPE_P(result_resource) != IS_BOOL || (Z_TYPE_P(result_resource) == IS_BOOL && Z_BVAL_P(result_resource))) {
				PHALCON_ALLOC_ZVAL_MM(r1);
				PHALCON_ALLOC_ZVAL_MM(r2);
				PHALCON_ALLOC_ZVAL_MM(t3);
				phalcon_read_property(&t3, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY TSRMLS_CC);
				PHALCON_CALL_METHOD_PARAMS_1(r2, t3, "numrows", result_resource, PHALCON_NO_CHECK);
				PHALCON_CALL_FUNC_PARAMS_1(r1, "intval", r2, 0x020);
				PHALCON_CPY_WRT(count, r1);
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(t4);
			phalcon_read_property(&t4, this_ptr, "_rows", sizeof("_rows")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_fast_count(r3, t4 TSRMLS_CC);
			PHALCON_CPY_WRT(count, r3);
		}
		
		phalcon_update_property_zval(this_ptr, "_count", strlen("_count"), count TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_read_property(&t5, this_ptr, "_count", sizeof("_count")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t5);
}

/**
 * Checks whether offset exists in the resultset
 *
 * @param int $index
 * @return boolean
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
	RETURN_FALSE;
}

/**
 * Gets row in a specific position of the resultset
 *
 * @param int $index
 * @return Phalcon_Model_Base
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
		if (Z_TYPE_P(r2) != IS_BOOL || (Z_TYPE_P(r2) == IS_BOOL && Z_BVAL_P(r2))) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CALL_METHOD(r3, this_ptr, "current", PHALCON_NO_CHECK);
			PHALCON_RETURN_DZVAL(r3);
		} else {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_model_exception_ce);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "The index does not exist in the cursor", 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
	phalcon_throw_exception(i0 TSRMLS_CC);
	return;
}

/**
 * Resulsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param int $index
 * @param Phalcon_Model_Base $value
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
	ZVAL_STRING(c0, "Cursor is an immutable ArrayAccess object", 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
	phalcon_throw_exception(i0 TSRMLS_CC);
	return;
}

/**
 * Resulsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
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
	ZVAL_STRING(c0, "Cursor is an immutable ArrayAccess object", 1);
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

	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "rewind", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "valid", PHALCON_NO_CHECK);
	if (Z_TYPE_P(r0) != IS_BOOL || (Z_TYPE_P(r0) == IS_BOOL && Z_BVAL_P(r0))) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "current", PHALCON_NO_CHECK);
		PHALCON_RETURN_DZVAL(r1);
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

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "count", PHALCON_NO_CHECK);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	sub_function(r1, r0, t0 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "seek", r1, PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, this_ptr, "valid", PHALCON_NO_CHECK);
	if (Z_TYPE_P(r2) != IS_BOOL || (Z_TYPE_P(r2) == IS_BOOL && Z_BVAL_P(r2))) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_METHOD(r3, this_ptr, "current", PHALCON_NO_CHECK);
		PHALCON_RETURN_DZVAL(r3);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Serializing a resultset will dump all related rows into a big array
 *
 * @param int $index
 */
PHP_METHOD(Phalcon_Model_Resultset, serialize){

	zval *records = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(records, a0);
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "rewind", PHALCON_NO_CHECK);
	ws_fd08_1:
		
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, "valid", PHALCON_NO_CHECK);
		if (Z_TYPE_P(r0) != IS_BOOL || (Z_TYPE_P(r0) == IS_BOOL && !Z_BVAL_P(r0))) {
			goto we_fd08_1;
		}
		PHALCON_INIT_VAR(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "current", PHALCON_NO_CHECK);
		phalcon_array_append(&records, r1, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "next", PHALCON_NO_CHECK);
		goto ws_fd08_1;
	we_fd08_1:
	if(0) { };
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_FUNC_PARAMS_1(r2, "serialize", records, 0x057);
	PHALCON_RETURN_DZVAL(r2);
}

/**
 * Unserializing a resultset will allow to only works on the rows present in the saved state
 *
 * @param int $index
 */
PHP_METHOD(Phalcon_Model_Resultset, unserialize){

	zval *data = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_long(this_ptr, "_type", strlen("_type"), 0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "unserialize", data, 0x058);
	phalcon_update_property_zval(this_ptr, "_rows", strlen("_rows"), r0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

