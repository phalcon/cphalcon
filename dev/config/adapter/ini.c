
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
 * Phalcon_Config_Adapter_Ini
 *
 * Reads ini files and convert it to Phalcon_Config objects.
 *
 * Given the next configuration file:
 *
 * 
 *
 * You can read it as follows:
 *
 * 
 *
 */

/**
 * Phalcon_Config_Adapter_Ini constructor
 *
 * @param string $filePath
 * @return Phalcon_Config_Adapter_Ini
 *
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *p1[] = { NULL }, *p5[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	zend_bool silence;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v1, a0);
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_BOOL(c0, 1);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "parse_ini_file", v0, c0, 0x03F);
	PG(display_errors) = silence;
	PHALCON_CPY_WRT(v2, r0);
	if (Z_TYPE_P(v2) == IS_BOOL && !Z_BVAL_P(v2)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_config_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r1);
		Z_ADDREF_P(v0);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "basename", v0, 0x040);
		Z_DELREF_P(v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Configuration file ", r1, " can't be loaded");
		Z_ADDREF_P(r2);
		p1[0] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(v2) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v2);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes67:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee67;
		} else {
			PHALCON_INIT_VAR(v4);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v4, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v4, num);
				}
			}
		}
	PHALCON_INIT_VAR(v3);
		ZVAL_ZVAL(v3, *hd, 1, 0);
		if (Z_TYPE_P(v3) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah1 = Z_ARRVAL_P(v3);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes68:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee68;
			} else {
				PHALCON_INIT_VAR(v6);
				htype = zend_hash_get_current_key_ex(ah1, &index, &index_len, &num, 0, &hp1);
				if (htype == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(v6, index, index_len-1, 1);
				} else {
					if (htype == HASH_KEY_IS_LONG) {
						ZVAL_LONG(v6, num);
					}
				}
			}
		PHALCON_INIT_VAR(v5);
			ZVAL_ZVAL(v5, *hd, 1, 0);
			PHALCON_INIT_VAR(r3);
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, ".", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r3, "strpos", v6, c1, 0x005);
			if (Z_TYPE_P(r3) != IS_BOOL || (Z_TYPE_P(r3) == IS_BOOL && Z_BVAL_P(r3))) {
				PHALCON_INIT_VAR(r4);
				PHALCON_INIT_VAR(c2);
				ZVAL_STRING(c2, ".", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r4, "explode", c2, v6, 0x002);
				PHALCON_CPY_WRT(v7, r4);
				if (Z_TYPE_P(v1) == IS_ARRAY) {
					PHALCON_INIT_VAR(t0);
					phalcon_array_fetch(&t0, v1, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t0) > 1) {
					zval *new_zv;
					Z_DELREF_P(t0);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, t0);
					t0 = new_zv;
					zval_copy_ctor(new_zv);
					phalcon_array_update(v1, v4, t0 TSRMLS_CC);
				}
				Z_ADDREF_P(t0);
				if (Z_TYPE_P(t0) != IS_ARRAY) {
					convert_to_array(t0);
					phalcon_array_update(v1, v4, t0 TSRMLS_CC);
				}
				PHALCON_INIT_VAR(r5);
				phalcon_array_fetch_long(&r5, v7, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				if (Z_TYPE_P(t0) == IS_ARRAY) {
					PHALCON_INIT_VAR(t1);
					phalcon_array_fetch(&t1, t0, r5, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t1) > 1) {
					zval *new_zv;
					Z_DELREF_P(t1);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, t1);
					t1 = new_zv;
					zval_copy_ctor(new_zv);
					phalcon_array_update(t0, r5, t1 TSRMLS_CC);
				}
				Z_ADDREF_P(t1);
				if (Z_TYPE_P(t1) != IS_ARRAY) {
					convert_to_array(t1);
					phalcon_array_update(t0, r5, t1 TSRMLS_CC);
				}
				PHALCON_INIT_VAR(r6);
				phalcon_array_fetch_long(&r6, v7, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(v5);
				phalcon_array_update(t1, r6, v5 TSRMLS_CC);
			} else {
				if (Z_TYPE_P(v1) == IS_ARRAY) {
					PHALCON_INIT_VAR(t2);
					phalcon_array_fetch(&t2, v1, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t2) > 1) {
					zval *new_zv;
					Z_DELREF_P(t2);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, t2);
					t2 = new_zv;
					zval_copy_ctor(new_zv);
					phalcon_array_update(v1, v4, t2 TSRMLS_CC);
				}
				Z_ADDREF_P(t2);
				if (Z_TYPE_P(t2) != IS_ARRAY) {
					convert_to_array(t2);
					phalcon_array_update(v1, v4, t2 TSRMLS_CC);
				}
				Z_ADDREF_P(v5);
				phalcon_array_update(t2, v6, v5 TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes68;
			fee68:
			if(0){ };
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes67;
		fee67:
		if(0){ };
	}
	Z_ADDREF_P(v1);
	p5[0] = v1;
	PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Config_Adapter_Ini", "__construct", 1, p5);
	Z_DELREF_P(p5[0]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

