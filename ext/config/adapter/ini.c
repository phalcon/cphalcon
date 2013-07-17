
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
#include "kernel/hash.h"
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

static inline void phalcon_config_adapter_ini_update_zval_directive(zval **arr, zval *section, zval *directive, zval **value, int flags TSRMLS_DC) {
	zval *temp1 = NULL, *temp2 = NULL, *index = NULL;
	int i, n;

	n = zend_hash_num_elements(Z_ARRVAL_P(directive));

	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		phalcon_array_fetch(&temp1, *arr, section, PH_SILENT_CC);
		if (Z_REFCOUNT_P(temp1) > 1) {
			phalcon_array_update_zval(arr, section, &temp1, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(temp1) != IS_ARRAY) {
			convert_to_array(temp1);
			phalcon_array_update_zval(arr, section, &temp1, PH_COPY TSRMLS_CC);
		}

		for (i = 0; i < n - 1; i++) {
			phalcon_array_fetch_long(&index, directive, i, PH_NOISY_CC);

			phalcon_array_fetch(&temp2, temp1, index, PH_SILENT_CC);
			if (Z_REFCOUNT_P(temp2) > 1) {
				phalcon_array_update_zval(&temp1, index, &temp2, PH_COPY | PH_CTOR TSRMLS_CC);
			}
			if (Z_TYPE_P(temp2) != IS_ARRAY) {
				convert_to_array(temp2);
				phalcon_array_update_zval(&temp1, index, &temp2, PH_COPY TSRMLS_CC);
			}
			zval_ptr_dtor(&index);

			if (temp1 != NULL) {
				zval_ptr_dtor(&temp1);
			}
			temp1 = temp2;
			temp2 = NULL;
		}

		phalcon_array_fetch_long(&index, directive, n - 1, PH_NOISY_CC);
		phalcon_array_update_zval(&temp1, index, value, PH_COPY TSRMLS_CC);

		zval_ptr_dtor(&index);

		if (temp1 != NULL) {
			zval_ptr_dtor(&temp1);
		}
	}
}

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

	zval *file_path, *process_sections, *ini_config;
	zval *exception_message, *config, *directives = NULL;
	zval *section = NULL, *value = NULL, *key = NULL, *directive_parts = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &file_path);
	
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
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Configuration file ", file_path, " can't be loaded");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_config_exception_ce, exception_message);
		return;
	}
	
	PHALCON_INIT_VAR(config);
	array_init(config);
	
	phalcon_is_iterable(ini_config, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(section, ah0, hp0);
		PHALCON_GET_HVALUE(directives);
	
		if (unlikely(Z_TYPE_P(directives) != IS_ARRAY)) {
			Z_ADDREF_P(directives);
			if (phalcon_array_update_zval(&config, section, &directives, 0) != SUCCESS) {
				Z_DELREF_P(directives);
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			continue;
		}
	
		phalcon_is_iterable(directives, &ah1, &hp1, 0, 0);
	
		if (zend_hash_num_elements(ah1) == 0) {
			Z_ADDREF_P(directives);
			phalcon_array_update_zval(&config, section, &directives, 0);
			zend_hash_move_forward_ex(ah0, &hp0);
			continue;
		}
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_HKEY(key, ah1, hp1);
			PHALCON_GET_HVALUE(value);
	
			if (phalcon_memnstr_str(key, SL("."))) {
				PHALCON_INIT_NVAR(directive_parts);
				phalcon_fast_explode_str(directive_parts, SL("."), key TSRMLS_CC);
				phalcon_config_adapter_ini_update_zval_directive(&config, section, directive_parts, &value, 0 TSRMLS_CC);
			} else {
				phalcon_array_update_multi_2(&config, section, key, &value, 0);
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

