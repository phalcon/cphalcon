
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

#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/object.h"

/**
 * Phalcon\Mvc\Model\Validator\Uniqueness
 *
 * Validates that a field or a combination of a set of fields are not
 * present more than once in the existing records of the related table
 *
 *
 *
 */

/**
 * Executes the validator
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Uniqueness, validate){

	zval *record = NULL, *field = NULL, *conditions = NULL, *placeholders = NULL;
	zval *number = NULL, *compose_field = NULL, *value = NULL, *dependency_injector = NULL;
	zval *meta_data = NULL, *primary_fields = NULL, *primary_field = NULL;
	zval *params = NULL, *class_name = NULL, *message = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL, *c4 = NULL, *c5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "field", 1);
	PHALCON_INIT_VAR(field);
	PHALCON_CALL_METHOD_PARAMS_1(field, this_ptr, "getoption", c0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(conditions);
	array_init(conditions);
	
	PHALCON_INIT_VAR(placeholders);
	array_init(placeholders);
	
	PHALCON_INIT_VAR(number);
	ZVAL_LONG(number, 0);
	if (Z_TYPE_P(field) == IS_ARRAY) { 
		if (!phalcon_valid_foreach(field TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(field);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_8aab_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_8aab_0;
			}
			
			PHALCON_INIT_VAR(compose_field);
			ZVAL_ZVAL(compose_field, *hd, 1, 0);
			PHALCON_INIT_VAR(value);
			PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", compose_field, PH_NO_CHECK);
			
			PHALCON_INIT_VAR(r0);
			PHALCON_CONCAT_VSV(r0, compose_field, " = ?", number);
			phalcon_array_append(&conditions, r0, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&placeholders, value, PH_SEPARATE TSRMLS_CC);
			PHALCON_SEPARATE(number);
			increment_function(number);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_8aab_0;
		fee_8aab_0:
		if(0){}
		
	} else {
		PHALCON_INIT_VAR(value);
		PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", field, PH_NO_CHECK);
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_VS(r1, field, " = ?0");
		phalcon_array_append(&conditions, r1, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&placeholders, value, PH_SEPARATE TSRMLS_CC);
		PHALCON_SEPARATE(number);
		increment_function(number);
	}
	
	PHALCON_INIT_VAR(dependency_injector);
	PHALCON_CALL_METHOD(dependency_injector, record, "getdi", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "modelsMetadata", 1);
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", c1, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(primary_fields);
	PHALCON_CALL_METHOD_PARAMS_1(primary_fields, meta_data, "getprimarykeyattributes", record, PH_NO_CHECK);
	if (!phalcon_valid_foreach(primary_fields TSRMLS_CC)) {
		return;
	}
	
	ah1 = Z_ARRVAL_P(primary_fields);
	zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	fes_8aab_1:
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto fee_8aab_1;
		}
		
		PHALCON_INIT_VAR(primary_field);
		ZVAL_ZVAL(primary_field, *hd, 1, 0);
		PHALCON_INIT_VAR(value);
		PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", primary_field, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(r2);
		PHALCON_CONCAT_VSV(r2, primary_field, " <> ?", number);
		phalcon_array_append(&conditions, r2, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&placeholders, value, PH_SEPARATE TSRMLS_CC);
		PHALCON_SEPARATE(number);
		increment_function(number);
		zend_hash_move_forward_ex(ah1, &hp1);
		goto fes_8aab_1;
	fee_8aab_1:
	if(0){}
	
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, " AND ", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_fast_join(r3, c2, conditions TSRMLS_CC);
	PHALCON_CPY_WRT(conditions, r3);
	
	PHALCON_INIT_VAR(params);
	array_init(params);
	phalcon_array_update_string(&params, SL("conditions"), &conditions, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&params, SL("bind"), &placeholders, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, record TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_STATIC_ZVAL_PARAMS_1(r4, class_name, "count", params);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 0);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	is_smaller_function(r5, t0, r4 TSRMLS_CC);
	if (zend_is_true(r5)) {
		PHALCON_INIT_VAR(c3);
		ZVAL_STRING(c3, "message", 1);
		PHALCON_INIT_VAR(message);
		PHALCON_CALL_METHOD_PARAMS_1(message, this_ptr, "getoption", c3, PH_NO_CHECK);
		if (zend_is_true(message)) {
			PHALCON_INIT_VAR(c4);
			ZVAL_STRING(c4, "unique", 1);
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", message, field, c4, PH_NO_CHECK);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r6);
			PHALCON_CONCAT_SVS(r6, "Value of field '", field, "' is already present in another record");
			PHALCON_INIT_VAR(c5);
			ZVAL_STRING(c5, "unique", 1);
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", r6, field, c5, PH_NO_CHECK);
		}
		
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

