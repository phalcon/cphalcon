
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 * Reads ini files and converts them to Phalcon\Config objects.
 *
 * Given the next configuration file:
 *
 *<code>
 *[database]
 *adapter = Mysql
 *host = localhost
 *username = scott
 *password = cheetah
 *dbname = test_db
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
 * Phalcon\Config\Adapter\Ini initializer
 */
PHALCON_INIT_CLASS(Phalcon_Config_Adapter_Ini){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Ini, config_adapter_ini, "phalcon\\config", phalcon_config_adapter_ini_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\Config\Adapter\Ini constructor
 *
 * @param string $filePath
 */
PHP_METHOD(Phalcon_Config_Adapter_Ini, __construct){

	zval *file_path, *config, *process_sections;
	zval *ini_config, *base_path, *exception_message;
	zval *dot, *directives = NULL, *section = NULL, *value = NULL, *key = NULL, *directive_parts = NULL;
	zval *left_part = NULL, *right_part = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &file_path);
	
	PHALCON_INIT_VAR(config);
	array_init(config);
	
	PHALCON_INIT_VAR(process_sections);
	ZVAL_BOOL(process_sections, 1);
	
	/** 
	 * Use the standard parse_ini_file
	 */
	PHALCON_INIT_VAR(ini_config);
	phalcon_call_func_p2(ini_config, "parse_ini_file", file_path, process_sections);
	
	/** 
	 * Check if the file had errors
	 */
	if (PHALCON_IS_FALSE(ini_config)) {
		PHALCON_INIT_VAR(base_path);
		phalcon_call_func_p1(base_path, "basename", file_path);
	
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Configuration file ", base_path, " can't be loaded");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_config_exception_ce, exception_message);
		return;
	}
	
	PHALCON_INIT_VAR(dot);
	ZVAL_STRING(dot, ".", 1);
	
	if (!phalcon_is_iterable(ini_config, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(section, ah0, hp0);
		PHALCON_GET_HVALUE(directives);
	
	
		if (!phalcon_is_iterable(directives, &ah1, &hp1, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_HKEY(key, ah1, hp1);
			PHALCON_GET_HVALUE(value);
	
			if (phalcon_memnstr_str(key, SL(".") TSRMLS_CC)) {
				PHALCON_INIT_NVAR(directive_parts);
				phalcon_fast_explode(directive_parts, dot, key TSRMLS_CC);
	
				PHALCON_OBS_NVAR(left_part);
				phalcon_array_fetch_long(&left_part, directive_parts, 0, PH_NOISY_CC);
	
				PHALCON_OBS_NVAR(right_part);
				phalcon_array_fetch_long(&right_part, directive_parts, 1, PH_NOISY_CC);
				phalcon_array_update_zval_zval_zval_multi_3(&config, section, left_part, right_part, &value, 0 TSRMLS_CC);
			} else {
				phalcon_array_update_multi_2(&config, section, key, &value, 0 TSRMLS_CC);
			}
	
			zend_hash_move_forward_ex(ah1, &hp1);
		}
	
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Calls the Phalcon\Config constructor
	 */
	PHALCON_CALL_PARENT_PARAMS_1_NORETURN(this_ptr, "Phalcon\\Config\\Adapter\\Ini", "__construct", config);
	
	PHALCON_MM_RESTORE();
}

