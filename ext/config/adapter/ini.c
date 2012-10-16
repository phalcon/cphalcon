
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
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/array.h"

/**
 * Phalcon\Config\Adapter\Ini
 *
 * Reads ini files and convert it to Phalcon\Config objects.
 *
 * Given the next configuration file:
 *
 *<code>
 *[database]
 *adapter = Mysql
 *host = localhost
 *username = scott
 *password = cheetah
 *name = test_db
 *
 *[phalcon]
 *controllersDir = "../app/controllers/"
 *modelsDir = "../app/models/"
 *viewsDir = "../app/views/"
 *</code>
 *
 * You can read it as follows:
 *
 *<code>
 *	$config = new Phalcon\Config\Adapter\Ini("path/config.ini");
 *	echo $config->phalcon->controllersDir;
 *	echo $config->database->username;
 *</code>
 *
 */


/**
 * Phalcon\Config\Adapter\Ini constructor
 *
 * @param string $filePath
 * @return Phalcon\Config\Adapter\Ini
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, __construct){

	zval *file_path, *config, *process_sections;
	zval *ini_config, *base_path, *exception_message;
	zval *dot, *directives = NULL, *section = NULL, *value = NULL, *key = NULL, *directive_parts = NULL;
	zval *left_part = NULL, *right_part = NULL;
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
	
	PHALCON_INIT_VAR(process_sections);
	ZVAL_BOOL(process_sections, 1);
	
	PHALCON_INIT_VAR(ini_config);
	PHALCON_CALL_FUNC_PARAMS_2(ini_config, "parse_ini_file", file_path, process_sections);
	if (PHALCON_IS_FALSE(ini_config)) {
		PHALCON_INIT_VAR(base_path);
		PHALCON_CALL_FUNC_PARAMS_1(base_path, "basename", file_path);
		
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Configuration file ", base_path, " can't be loaded");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_config_exception_ce, exception_message);
		return;
	}
	
	PHALCON_INIT_VAR(dot);
	ZVAL_STRING(dot, ".", 1);
	
	if (!phalcon_valid_foreach(ini_config TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(ini_config);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_KEY(section, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(directives);
		
		
		if (!phalcon_valid_foreach(directives TSRMLS_CC)) {
			return;
		}
		
		ah1 = Z_ARRVAL_P(directives);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		
		ph_cycle_start_1:
		
			if (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS) {
				goto ph_cycle_end_1;
			}
			
			PHALCON_GET_FOREACH_KEY(key, ah1, hp1);
			PHALCON_GET_FOREACH_VALUE(value);
			
			if (phalcon_memnstr_str(key, SL(".") TSRMLS_CC)) {
				PHALCON_INIT_NVAR(directive_parts);
				phalcon_fast_explode(directive_parts, dot, key TSRMLS_CC);
				
				PHALCON_INIT_NVAR(left_part);
				phalcon_array_fetch_long(&left_part, directive_parts, 0, PH_NOISY_CC);
				
				PHALCON_INIT_NVAR(right_part);
				phalcon_array_fetch_long(&right_part, directive_parts, 1, PH_NOISY_CC);
				phalcon_array_update_zval_zval_zval_multi_3(&config, section, left_part, right_part, &value, 0 TSRMLS_CC);
			} else {
				phalcon_array_update_multi_2(&config, section, key, &value, 0 TSRMLS_CC);
			}
			
			zend_hash_move_forward_ex(ah1, &hp1);
			goto ph_cycle_start_1;
			
		ph_cycle_end_1:
		
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
		
	ph_cycle_end_0:
	
	PHALCON_CALL_PARENT_PARAMS_1_NORETURN(this_ptr, "Phalcon\\Config\\Adapter\\Ini", "__construct", config);
	
	PHALCON_MM_RESTORE();
}

