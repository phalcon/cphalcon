
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

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *i0 = NULL;
	zval *a0 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL;
	zval *p4[] = { NULL }, *p9[] = { NULL }, *p11[] = { NULL }, *p13[] = { NULL }, *p15[] = { NULL, NULL, NULL }, *p16[] = { NULL, NULL, NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "isrequired", PHALCON_CALL_DEFAULT);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "getrecord", PHALCON_CALL_DEFAULT);
		PHALCON_ALLOC_ZVAL_MM(i0);
		phalcon_clone(i0, r1 TSRMLS_CC);
		PHALCON_CPY_WRT(v0, i0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, this_ptr, "getfieldname", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v1, r2);
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v2, a0);
		if (Z_TYPE_P(v1) == IS_ARRAY) { 
			if (Z_TYPE_P(v1) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah0 = Z_ARRVAL_P(v1);
				zend_hash_internal_pointer_reset_ex(ah0, &hp0);
				fes_d73d_0:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_d73d_0;
				}
				PHALCON_INIT_VAR(v3);
				ZVAL_ZVAL(v3, *hd, 1, 0);
				PHALCON_INIT_VAR(r3);
				PHALCON_INIT_VAR(r4);
				Z_ADDREF_P(v3);
				p4[0] = v3;
				PHALCON_CALL_METHOD_PARAMS(r4, v0, "readattribute", 1, p4, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p4[0]);
				Z_ADDREF_P(r4);
				PHALCON_CALL_FUNC_PARAMS_1(r3, "addslashes", r4, 0x00C);
				Z_DELREF_P(r4);
				PHALCON_CPY_WRT(v4, r3);
				PHALCON_INIT_VAR(r5);
				PHALCON_CONCAT_VBOTH(r5, v3, "='", v4);
				PHALCON_INIT_VAR(r6);
				PHALCON_CONCAT_RIGHT(r6, r5, "'");
				Z_ADDREF_P(r6);
				PHALCON_SEPARATE_ARRAY(v2);
				phalcon_array_append(v2, r6 TSRMLS_CC);
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_d73d_0;
				fee_d73d_0:
				if(0){ };
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r7);
			PHALCON_ALLOC_ZVAL_MM(r8);
			PHALCON_CALL_METHOD(r8, this_ptr, "getvalue", PHALCON_CALL_DEFAULT);
			Z_ADDREF_P(r8);
			PHALCON_CALL_FUNC_PARAMS_1(r7, "addslashes", r8, 0x00C);
			Z_DELREF_P(r8);
			PHALCON_CPY_WRT(v4, r7);
			PHALCON_ALLOC_ZVAL_MM(r9);
			PHALCON_CONCAT_VBOTH(r9, v1, "='", v4);
			PHALCON_ALLOC_ZVAL_MM(r10);
			PHALCON_CONCAT_RIGHT(r10, r9, "'");
			Z_ADDREF_P(r10);
			PHALCON_SEPARATE_ARRAY(v2);
			phalcon_array_append(v2, r10 TSRMLS_CC);
		}
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CALL_METHOD(r11, v0, "getmanager", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v5, r11);
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CALL_METHOD(r12, v5, "getmetadata", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v6, r12);
		PHALCON_ALLOC_ZVAL_MM(r13);
		Z_ADDREF_P(v0);
		p9[0] = v0;
		PHALCON_CALL_METHOD_PARAMS(r13, v6, "getprimarykeyattributes", 1, p9, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p9[0]);
		PHALCON_CPY_WRT(v7, r13);
		if (Z_TYPE_P(v7) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah1 = Z_ARRVAL_P(v7);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_d73d_1:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_d73d_1;
			}
			PHALCON_INIT_VAR(v8);
			ZVAL_ZVAL(v8, *hd, 1, 0);
			PHALCON_INIT_VAR(r15);
			PHALCON_INIT_VAR(r16);
			Z_ADDREF_P(v8);
			p11[0] = v8;
			PHALCON_CALL_METHOD_PARAMS(r16, v0, "readattribute", 1, p11, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p11[0]);
			Z_ADDREF_P(r16);
			PHALCON_CALL_FUNC_PARAMS_1(r15, "addslashes", r16, 0x00C);
			Z_DELREF_P(r16);
			PHALCON_INIT_VAR(r14);
			PHALCON_CONCAT_VBOTH(r14, v8, "<>'", r15);
			PHALCON_INIT_VAR(r17);
			PHALCON_CONCAT_RIGHT(r17, r14, "'");
			Z_ADDREF_P(r17);
			PHALCON_SEPARATE_ARRAY(v2);
			phalcon_array_append(v2, r17 TSRMLS_CC);
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_d73d_1;
			fee_d73d_1:
			if(0){ };
		}
		PHALCON_ALLOC_ZVAL_MM(r18);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, " AND ", 1);
		PHALCON_CALL_FUNC_PARAMS_2(r18, "join", c0, v2, 0x00D);
		PHALCON_CPY_WRT(v2, r18);
		PHALCON_ALLOC_ZVAL_MM(r19);
		Z_ADDREF_P(v2);
		p13[0] = v2;
		PHALCON_CALL_STATIC_ZVAL_PARAMS(r19, v0, "count", 1, p13);
		Z_DELREF_P(p13[0]);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 0);
		PHALCON_INIT_VAR(r20);
		is_smaller_function(r20, t0, r19 TSRMLS_CC);
		if (zend_is_true(r20)) {
			PHALCON_ALLOC_ZVAL_MM(r21);
			PHALCON_CALL_METHOD(r21, this_ptr, "getoptions", PHALCON_CALL_DEFAULT);
			PHALCON_CPY_WRT(v9, r21);
			eval_int = phalcon_array_isset_string(v9, "message", strlen("message")+1);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(r22);
				phalcon_array_fetch_string(&r22, v9, "message", strlen("message"), PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r22);
				p15[0] = r22;
				Z_ADDREF_P(v1);
				p15[1] = v1;
				PHALCON_INIT_VAR(p15[2]);
				ZVAL_STRING(p15[2], "unique", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "appendmessage", 3, p15, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p15[0]);
				Z_DELREF_P(p15[1]);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r23);
				PHALCON_CONCAT_BOTH(r23,  "Value of field '", v1, "' is already present in another record");
				Z_ADDREF_P(r23);
				p16[0] = r23;
				Z_ADDREF_P(v1);
				p16[1] = v1;
				PHALCON_INIT_VAR(p16[2]);
				ZVAL_STRING(p16[2], "unique", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "appendmessage", 3, p16, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p16[0]);
				Z_DELREF_P(p16[1]);
			}
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

