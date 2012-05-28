
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

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Phalcon_Model_Row
 *
 * This component allows to Phalcon_Model_Base returns grouped resultsets.
 */

PHP_METHOD(Phalcon_Model_Row, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_model_row_ce, this_ptr, "_columns", strlen("_columns"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Overwrites default connection
 *
 * @param Phalcon_Db $connection
 */
PHP_METHOD(Phalcon_Model_Row, setConnection){

	zval *connection = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &connection) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), connection TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns default connection
 *
 * @return Phalcon_Db
 */
PHP_METHOD(Phalcon_Model_Row, getConnection){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Assigns values to a row from an array returning a new row
 *
 *
 *
 * @param array $result
 * @return Phalcon_Model $result
 */
PHP_METHOD(Phalcon_Model_Row, dumpResult){

	zval *result = NULL, *object_row = NULL, *columns = NULL, *value = NULL, *field = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *a0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &result) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(i0);
	if (phalcon_clone(i0, this_ptr TSRMLS_CC) == FAILURE){
		return;
	}
	PHALCON_CPY_WRT(object_row, i0);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_columns", sizeof("_columns")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_count(r0, t0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, r0, t1 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(columns, a0);
		if (phalcon_valid_foreach(result TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(result);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_47c8_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_47c8_0;
			} else {
				PHALCON_INIT_VAR(field);
				PHALCON_GET_FOREACH_KEY(field, ah0, hp0);
			}
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			PHALCON_INIT_VAR(t2);
			ZVAL_BOOL(t2, 1);
			phalcon_array_update(&columns, field, &t2, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			phalcon_update_property_zval_zval(object_row, field, value TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_47c8_0;
			fee_47c8_0:
			if(0){}
		} else {
			return;
		}
		phalcon_update_property_zval(object_row, "_columns", strlen("_columns"), columns TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_columns", strlen("_columns"), columns TSRMLS_CC);
	} else {
		if (phalcon_valid_foreach(result TSRMLS_CC)) {
			ah1 = Z_ARRVAL_P(result);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_47c8_1:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_47c8_1;
			} else {
				PHALCON_INIT_VAR(field);
				PHALCON_GET_FOREACH_KEY(field, ah1, hp1);
			}
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			phalcon_update_property_zval_zval(object_row, field, value TSRMLS_CC);
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_47c8_1;
			fee_47c8_1:
			if(0){}
		} else {
			return;
		}
		
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_columns", sizeof("_columns")-1, PHALCON_NOISY TSRMLS_CC);
		phalcon_update_property_zval(object_row, "_columns", strlen("_columns"), t3 TSRMLS_CC);
	}
	
	
	PHALCON_RETURN_CHECK_CTOR(object_row);
}

/**
 * Reads an attribute value by its name
 *
 * 
 *
 * @param string $attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Model_Row, readAttribute){

	zval *property = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &property) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property_zval(&t0, this_ptr, property, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Magic method sleep
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Row, sleep){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_next_index_stringl(a0, "_columns", strlen("_columns"), 1);
	
	PHALCON_RETURN_CTOR(a0);
}

