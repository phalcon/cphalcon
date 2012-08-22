
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

#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"

/**
 * Phalcon\Mvc\Model\Row
 *
 * This component allows to Phalcon\Mvc\Model returns grouped resultsets.
 */

PHP_METHOD(Phalcon_Mvc_Model_Row, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_mvc_model_row_ce, this_ptr, SL("_columns"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_Row, setForceExists){


	
}

/**
 * Assigns values to a row from an array returning a new row
 *
 * @param array $result
 * @return Phalcon\Mvc\Model $result
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, dumpResult){

	zval *result = NULL, *object_row = NULL, *columns = NULL, *number_columns = NULL;
	zval *value = NULL, *field = NULL;
	zval *i0 = NULL;
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
	
	PHALCON_INIT_VAR(columns);
	phalcon_read_property(&columns, this_ptr, SL("_columns"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(number_columns);
	phalcon_fast_count(number_columns, columns TSRMLS_CC);
	if (zend_is_true(number_columns)) {
		PHALCON_INIT_VAR(columns);
		array_init(columns);
		if (!phalcon_valid_foreach(result TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(result);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_4c15_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_4c15_0;
			}
			
			PHALCON_INIT_VAR(field);
			PHALCON_GET_FOREACH_KEY(field, ah0, hp0);
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			phalcon_array_update_zval_bool(&columns, field, 1, PH_SEPARATE TSRMLS_CC);
			phalcon_update_property_zval_zval(object_row, field, value TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_4c15_0;
		fee_4c15_0:
		
		phalcon_update_property_zval(object_row, SL("_columns"), columns TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_columns"), columns TSRMLS_CC);
	} else {
		if (!phalcon_valid_foreach(result TSRMLS_CC)) {
			return;
		}
		
		ah1 = Z_ARRVAL_P(result);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		fes_4c15_1:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_4c15_1;
			}
			
			PHALCON_INIT_VAR(field);
			PHALCON_GET_FOREACH_KEY(field, ah1, hp1);
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			phalcon_update_property_zval_zval(object_row, field, value TSRMLS_CC);
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_4c15_1;
		fee_4c15_1:
		
		phalcon_update_property_zval(object_row, SL("_columns"), columns TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(object_row);
}

/**
 * Reads an attribute value by its name
 *
 * @param string $property
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, readAttribute){

	zval *property = NULL, *value = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &property) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(value);
	phalcon_read_property_zval(&value, this_ptr, property, PH_NOISY_CC);
	
	RETURN_CCTOR(value);
}

/**
 * Magic method sleep
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Row, sleep){

	zval *attributes = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(attributes);
	array_init(attributes);
	add_next_index_stringl(attributes, SL("_columns"), 1);
	
	RETURN_CTOR(attributes);
}

