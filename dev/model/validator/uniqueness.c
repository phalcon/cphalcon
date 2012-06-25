
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
 * Phalcon_Model_Validator_Uniqueness
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
	zval *primary_fields = NULL, *numeric_fields = NULL, *primary_field = NULL;
	zval *options = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL;
	zval *i0 = NULL;
	zval *a0 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *t0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "isrequired", PHALCON_NO_CHECK);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "getrecord", PHALCON_NO_CHECK);
		PHALCON_ALLOC_ZVAL_MM(i0);
		if (phalcon_clone(i0, r1 TSRMLS_CC) == FAILURE){
			return;
		}
		PHALCON_CPY_WRT(record, i0);
		
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, record, "getconnection", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(connection, r2);
		
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_METHOD(r3, this_ptr, "getfieldname", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(field, r3);
		
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(conditions, a0);
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
				PHALCON_INIT_VAR(r4);
				PHALCON_INIT_VAR(r5);
				PHALCON_CALL_METHOD_PARAMS_1(r5, record, "readattribute", compose_field, PHALCON_NO_CHECK);
				PHALCON_CALL_METHOD_PARAMS_1(r4, connection, "escapestring", r5, PHALCON_NO_CHECK);
				PHALCON_CPY_WRT(value, r4);
				
				PHALCON_INIT_VAR(r6);
				PHALCON_CONCAT_VSVS(r6, compose_field, "='", value, "'");
				phalcon_array_append(&conditions, r6, PHALCON_SEPARATE_PLZ TSRMLS_CC);
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_d73d_0;
				fee_d73d_0:
				if(0){}
			} else {
				return;
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r7);
			PHALCON_ALLOC_ZVAL_MM(r8);
			PHALCON_CALL_METHOD(r8, this_ptr, "getvalue", PHALCON_NO_CHECK);
			PHALCON_CALL_METHOD_PARAMS_1(r7, connection, "escapestring", r8, PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(value, r7);
			
			PHALCON_ALLOC_ZVAL_MM(r9);
			PHALCON_CONCAT_VSVS(r9, field, "='", value, "'");
			phalcon_array_append(&conditions, r9, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		}
		
		PHALCON_ALLOC_ZVAL_MM(r10);
		PHALCON_CALL_METHOD(r10, record, "getmanager", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(manager, r10);
		
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CALL_METHOD(r11, manager, "getmetadata", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(meta_data, r11);
		
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CALL_METHOD_PARAMS_1(r12, meta_data, "getprimarykeyattributes", record, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(primary_fields, r12);
		
		PHALCON_ALLOC_ZVAL_MM(r13);
		PHALCON_CALL_METHOD_PARAMS_1(r13, meta_data, "getdatatypesnumeric", record, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(numeric_fields, r13);
		if (phalcon_valid_foreach(primary_fields TSRMLS_CC)) {
			ah1 = Z_ARRVAL_P(primary_fields);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_d73d_1:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_d73d_1;
			}
			
			PHALCON_INIT_VAR(primary_field);
			ZVAL_ZVAL(primary_field, *hd, 1, 0);
			eval_int = phalcon_array_isset(numeric_fields, primary_field);
			if (!eval_int) {
				PHALCON_INIT_VAR(r14);
				PHALCON_INIT_VAR(r15);
				PHALCON_INIT_VAR(r16);
				PHALCON_CALL_METHOD_PARAMS_1(r16, record, "readattribute", primary_field, PHALCON_NO_CHECK);
				PHALCON_CALL_METHOD_PARAMS_1(r15, connection, "escapestring", r16, PHALCON_NO_CHECK);
				PHALCON_CONCAT_VSVS(r14, primary_field, "<>'", r15, "'");
				phalcon_array_append(&conditions, r14, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			} else {
				PHALCON_INIT_VAR(r17);
				PHALCON_INIT_VAR(r18);
				PHALCON_INIT_VAR(r19);
				PHALCON_CALL_METHOD_PARAMS_1(r19, record, "readattribute", primary_field, PHALCON_NO_CHECK);
				PHALCON_CALL_METHOD_PARAMS_1(r18, connection, "escapestring", r19, PHALCON_NO_CHECK);
				PHALCON_INIT_VAR(r20);
				PHALCON_CALL_FUNC_PARAMS_1(r20, "intval", r18);
				PHALCON_CONCAT_VSV(r17, primary_field, "<>", r20);
				phalcon_array_append(&conditions, r17, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_d73d_1;
			fee_d73d_1:
			if(0){}
		} else {
			return;
		}
		
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, " AND ", 1);
		
		PHALCON_ALLOC_ZVAL_MM(r21);
		phalcon_fast_join(r21, c0, conditions TSRMLS_CC);
		PHALCON_CPY_WRT(conditions, r21);
		
		PHALCON_ALLOC_ZVAL_MM(r22);
		PHALCON_CALL_STATIC_ZVAL_PARAMS_1(r22, record, "count", conditions);
		
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 0);
		
		PHALCON_INIT_VAR(r23);
		is_smaller_function(r23, t0, r22 TSRMLS_CC);
		if (zend_is_true(r23)) {
			PHALCON_ALLOC_ZVAL_MM(r24);
			PHALCON_CALL_METHOD(r24, this_ptr, "getoptions", PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(options, r24);
			eval_int = phalcon_array_isset_string(options, SL("message")+1);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(r25);
				phalcon_array_fetch_string(&r25, options, SL("message"), PHALCON_NOISY TSRMLS_CC);
				PHALCON_INIT_VAR(c1);
				ZVAL_STRING(c1, "unique", 1);
				PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", r25, field, c1, PHALCON_NO_CHECK);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r26);
				PHALCON_CONCAT_SVS(r26, "Value of field '", field, "' is already present in another record");
				PHALCON_INIT_VAR(c2);
				ZVAL_STRING(c2, "unique", 1);
				PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", r26, field, c2, PHALCON_NO_CHECK);
			}
			
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

