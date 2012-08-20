
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
#include "kernel/exception.h"
#include "kernel/array.h"

/**
 * Phalcon\Config\Adapter\Ini
 *
 * Reads ini files and convert it to Phalcon\Config objects.
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
 * Phalcon\Config\Adapter\Ini constructor
 *
 * @param string $filePath
 * @return Phalcon\Config\Adapter\Ini
 *
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, __construct){

	zval *file_path = NULL, *config = NULL, *ini_config = NULL, *base_path = NULL;
	zval *exception_message = NULL, *exception = NULL, *directives = NULL;
	zval *section = NULL, *value = NULL, *key = NULL, *have_dot = NULL, *directive_parts = NULL;
	zval *left_part = NULL, *right_part = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &file_path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(config);
	array_init(config);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_BOOL(c0, 1);
	
	PHALCON_INIT_VAR(ini_config);
	PHALCON_CALL_FUNC_PARAMS_2(ini_config, "parse_ini_file", file_path, c0);
	if (Z_TYPE_P(ini_config) == IS_BOOL && !Z_BVAL_P(ini_config)) {
		PHALCON_INIT_VAR(base_path);
		PHALCON_CALL_FUNC_PARAMS_1(base_path, "basename", file_path);
		
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Configuration file ", base_path, " can't be loaded");
		
		PHALCON_INIT_VAR(exception);
		object_init_ex(exception, phalcon_config_exception_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
		phalcon_throw_exception(exception TSRMLS_CC);
		return;
	}
	
	if (!phalcon_valid_foreach(ini_config TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(ini_config);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_b840_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_b840_0;
		}
		
		PHALCON_INIT_VAR(section);
		PHALCON_GET_FOREACH_KEY(section, ah0, hp0);
		PHALCON_INIT_VAR(directives);
		ZVAL_ZVAL(directives, *hd, 1, 0);
		if (!phalcon_valid_foreach(directives TSRMLS_CC)) {
			return;
		}
		
		ah1 = Z_ARRVAL_P(directives);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		fes_b840_1:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_b840_1;
			}
			
			PHALCON_INIT_VAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah1, hp1);
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			PHALCON_INIT_VAR(have_dot);
			phalcon_fast_strpos_str(have_dot, key, SL(".") TSRMLS_CC);
			if (Z_TYPE_P(have_dot) != IS_BOOL || (Z_TYPE_P(have_dot) == IS_BOOL && Z_BVAL_P(have_dot))) {
				PHALCON_INIT_VAR(c1);
				ZVAL_STRING(c1, ".", 1);
				PHALCON_INIT_VAR(directive_parts);
				phalcon_fast_explode(directive_parts, c1, key TSRMLS_CC);
				
				PHALCON_INIT_VAR(left_part);
				phalcon_array_fetch_long(&left_part, directive_parts, 0, PH_NOISY_CC);
				
				PHALCON_INIT_VAR(right_part);
				phalcon_array_fetch_long(&right_part, directive_parts, 1, PH_NOISY_CC);
				if (Z_TYPE_P(config) == IS_ARRAY) {
					PHALCON_INIT_VAR(t0);
					phalcon_array_fetch(&t0, config, section, PH_SILENT_CC);
				}
				if (Z_REFCOUNT_P(t0) > 1) {
					phalcon_array_update_zval(&config, section, &t0, PH_COPY | PH_CTOR TSRMLS_CC);
				}
				if (Z_TYPE_P(t0) != IS_ARRAY) {
					convert_to_array(t0);
					phalcon_array_update_zval(&config, section, &t0, PH_COPY TSRMLS_CC);
				}
				if (Z_TYPE_P(t0) == IS_ARRAY) {
					PHALCON_INIT_VAR(t1);
					phalcon_array_fetch(&t1, t0, left_part, PH_SILENT_CC);
				}
				if (Z_REFCOUNT_P(t1) > 1) {
					phalcon_array_update_zval(&t0, left_part, &t1, PH_COPY | PH_CTOR TSRMLS_CC);
				}
				if (Z_TYPE_P(t1) != IS_ARRAY) {
					convert_to_array(t1);
					phalcon_array_update_zval(&t0, left_part, &t1, PH_COPY TSRMLS_CC);
				}
				phalcon_array_update_zval(&t1, right_part, &value, PH_COPY TSRMLS_CC);
			} else {
				phalcon_array_update_multi_2(&config, section, key, &value, 0 TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_b840_1;
		fee_b840_1:
		if(0){}
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_b840_0;
	fee_b840_0:
	
	PHALCON_CALL_PARENT_PARAMS_1_NORETURN(this_ptr, "Phalcon\\Config\\Adapter\\Ini", "__construct", config);
	
	PHALCON_MM_RESTORE();
}

