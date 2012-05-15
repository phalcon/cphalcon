
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

	zval *file_path = NULL, *config = NULL, *ini_config = NULL, *directives = NULL;
	zval *section = NULL, *value = NULL, *key = NULL, *directive_parts = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	zend_bool silence;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &file_path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(config, a0);
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_BOOL(c0, 1);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "parse_ini_file", file_path, c0, 0x008);
	PG(display_errors) = silence;
	PHALCON_CPY_WRT(ini_config, r0);
	if (Z_TYPE_P(ini_config) == IS_BOOL && !Z_BVAL_P(ini_config)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_config_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r1);
		Z_ADDREF_P(file_path);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "basename", file_path, 0x009);
		Z_DELREF_P(file_path);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Configuration file ", r1, " can't be loaded");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r2, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	if (phalcon_valid_foreach(ini_config TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(ini_config);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_b840_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_b840_0;
		} else {
			PHALCON_INIT_VAR(section);
			hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
			if (hash_type == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(section, hash_index, hash_index_len-1, 1);
			} else {
				if (hash_type == HASH_KEY_IS_LONG) {
					ZVAL_LONG(section, hash_num);
				}
			}
		}
		PHALCON_INIT_VAR(directives);
		ZVAL_ZVAL(directives, *hd, 1, 0);
		if (phalcon_valid_foreach(directives TSRMLS_CC)) {
			ah1 = Z_ARRVAL_P(directives);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_b840_1:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_b840_1;
			} else {
				PHALCON_INIT_VAR(key);
				hash_type = zend_hash_get_current_key_ex(ah1, &hash_index, &hash_index_len, &hash_num, 0, &hp1);
				if (hash_type == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(key, hash_index, hash_index_len-1, 1);
				} else {
					if (hash_type == HASH_KEY_IS_LONG) {
						ZVAL_LONG(key, hash_num);
					}
				}
			}
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			PHALCON_INIT_VAR(r3);
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, ".", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r3, "strpos", key, c1, 0x00A);
			if (Z_TYPE_P(r3) != IS_BOOL || (Z_TYPE_P(r3) == IS_BOOL && Z_BVAL_P(r3))) {
				PHALCON_INIT_VAR(r4);
				PHALCON_INIT_VAR(c2);
				ZVAL_STRING(c2, ".", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r4, "explode", c2, key, 0x005);
				PHALCON_CPY_WRT(directive_parts, r4);
				if (Z_TYPE_P(config) == IS_ARRAY) {
					PHALCON_INIT_VAR(t0);
					phalcon_array_fetch(&t0, config, section, PHALCON_SILENT TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t0) > 1) {
					phalcon_array_update(&config, section, t0, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_CTOR TSRMLS_CC);
				}
				Z_ADDREF_P(t0);
				if (Z_TYPE_P(t0) != IS_ARRAY) {
					convert_to_array(t0);
					phalcon_array_update(&config, section, t0, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				}
				PHALCON_INIT_VAR(r5);
				phalcon_array_fetch_long(&r5, directive_parts, 0, PHALCON_NOISY TSRMLS_CC);
				if (Z_TYPE_P(t0) == IS_ARRAY) {
					PHALCON_INIT_VAR(t1);
					phalcon_array_fetch(&t1, t0, r5, PHALCON_SILENT TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t1) > 1) {
					phalcon_array_update(&t0, r5, t1, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_CTOR TSRMLS_CC);
				}
				Z_ADDREF_P(t1);
				if (Z_TYPE_P(t1) != IS_ARRAY) {
					convert_to_array(t1);
					phalcon_array_update(&t0, r5, t1, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				}
				PHALCON_INIT_VAR(r6);
				phalcon_array_fetch_long(&r6, directive_parts, 1, PHALCON_NOISY TSRMLS_CC);
				phalcon_array_update(&t1, r6, value, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			} else {
				if (Z_TYPE_P(config) == IS_ARRAY) {
					PHALCON_INIT_VAR(t2);
					phalcon_array_fetch(&t2, config, section, PHALCON_SILENT TSRMLS_CC);
				}
				if (Z_REFCOUNT_P(t2) > 1) {
					phalcon_array_update(&config, section, t2, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_CTOR TSRMLS_CC);
				}
				Z_ADDREF_P(t2);
				if (Z_TYPE_P(t2) != IS_ARRAY) {
					convert_to_array(t2);
					phalcon_array_update(&config, section, t2, PHALCON_NO_SEPARATE_THX, PHALCON_NO_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				}
				phalcon_array_update(&t2, key, value, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_b840_1;
			fee_b840_1:
			if(0){ };
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_b840_0;
		fee_b840_0:
		if(0){ };
	}
	PHALCON_CALL_PARENT_PARAMS_1_NORETURN(this_ptr, "Phalcon_Config_Adapter_Ini", "__construct", config);
	
	PHALCON_MM_RESTORE();
}

