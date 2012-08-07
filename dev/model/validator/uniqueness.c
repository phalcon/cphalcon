
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
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/array.h"

/**
 * Phalcon\Model\Validator\Uniqueness
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
PHP_METHOD(Phalcon_Model_Validator_Uniqueness, validate){

	zval *record = NULL, *connection = NULL, *field = NULL, *conditions = NULL;
	zval *compose_field = NULL, *value = NULL, *manager = NULL, *meta_data = NULL;
	zval *primary_fields = NULL, *primary_field = NULL, *options = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *t0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "isrequired", PH_NO_CHECK);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "getrecord", PH_NO_CHECK);
		PHALCON_ALLOC_ZVAL_MM(i0);
		if (phalcon_clone(i0, r1 TSRMLS_CC) == FAILURE){
			return;
		}
		PHALCON_CPY_WRT(record, i0);
		
		PHALCON_INIT_VAR(connection);
		PHALCON_CALL_METHOD(connection, record, "getconnection", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(field);
		PHALCON_CALL_METHOD(field, this_ptr, "getfieldname", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(conditions);
		array_init(conditions);
		if (Z_TYPE_P(field) == IS_ARRAY) { 
			if (phalcon_valid_foreach(field TSRMLS_CC)) {
				ah0 = Z_ARRVAL_P(field);
				zend_hash_internal_pointer_reset_ex(ah0, &hp0);
				fes_d73d_0:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_d73d_0;
				}
				PHALCON_INIT_VAR(compose_field);
				ZVAL_ZVAL(compose_field, *hd, 1, 0);
				PHALCON_INIT_VAR(r2);
				PHALCON_CALL_METHOD_PARAMS_1(r2, record, "readattribute", compose_field, PH_NO_CHECK);
				PHALCON_INIT_VAR(value);
				PHALCON_CALL_METHOD_PARAMS_1(value, connection, "escapestring", r2, PH_NO_CHECK);
				
				PHALCON_INIT_VAR(r3);
				PHALCON_CONCAT_VSV(r3, compose_field, "=", value);
				phalcon_array_append(&conditions, r3, PH_SEPARATE TSRMLS_CC);
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_d73d_0;
				fee_d73d_0:
				if(0){}
			} else {
				return;
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_METHOD(r4, this_ptr, "getvalue", PH_NO_CHECK);
			PHALCON_INIT_VAR(value);
			PHALCON_CALL_METHOD_PARAMS_1(value, connection, "escapestring", r4, PH_NO_CHECK);
			
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CONCAT_VSV(r5, field, "=", value);
			phalcon_array_append(&conditions, r5, PH_SEPARATE TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(manager);
		PHALCON_CALL_METHOD(manager, record, "getmanager", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(meta_data);
		PHALCON_CALL_METHOD(meta_data, manager, "getmetadata", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(primary_fields);
		PHALCON_CALL_METHOD_PARAMS_1(primary_fields, meta_data, "getprimarykeyattributes", record, PH_NO_CHECK);
		if (phalcon_valid_foreach(primary_fields TSRMLS_CC)) {
			ah1 = Z_ARRVAL_P(primary_fields);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_d73d_1:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_d73d_1;
			}
			
			PHALCON_INIT_VAR(primary_field);
			ZVAL_ZVAL(primary_field, *hd, 1, 0);
			PHALCON_INIT_VAR(r6);
			PHALCON_CALL_METHOD_PARAMS_1(r6, record, "readattribute", primary_field, PH_NO_CHECK);
			PHALCON_INIT_VAR(r7);
			PHALCON_CALL_METHOD_PARAMS_1(r7, connection, "escapestring", r6, PH_NO_CHECK);
			PHALCON_INIT_VAR(r8);
			PHALCON_CONCAT_VSV(r8, primary_field, " <> ", r7);
			phalcon_array_append(&conditions, r8, PH_SEPARATE TSRMLS_CC);
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_d73d_1;
			fee_d73d_1:
			if(0){}
		} else {
			return;
		}
		
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, " AND ", 1);
		
		PHALCON_ALLOC_ZVAL_MM(r9);
		phalcon_fast_join(r9, c0, conditions TSRMLS_CC);
		PHALCON_CPY_WRT(conditions, r9);
		
		PHALCON_ALLOC_ZVAL_MM(r10);
		PHALCON_CALL_STATIC_ZVAL_PARAMS_1(r10, record, "count", conditions);
		
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 0);
		
		PHALCON_ALLOC_ZVAL_MM(r11);
		is_smaller_function(r11, t0, r10 TSRMLS_CC);
		if (zend_is_true(r11)) {
			PHALCON_INIT_VAR(options);
			PHALCON_CALL_METHOD(options, this_ptr, "getoptions", PH_NO_CHECK);
			eval_int = phalcon_array_isset_string(options, SL("message")+1);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(r12);
				phalcon_array_fetch_string(&r12, options, SL("message"), PH_NOISY_CC);
				PHALCON_INIT_VAR(c1);
				ZVAL_STRING(c1, "unique", 1);
				PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", r12, field, c1, PH_NO_CHECK);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r13);
				PHALCON_CONCAT_SVS(r13, "Value of field '", field, "' is already present in another record");
				PHALCON_INIT_VAR(c2);
				ZVAL_STRING(c2, "unique", 1);
				PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", r13, field, c2, PH_NO_CHECK);
			}
			
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

