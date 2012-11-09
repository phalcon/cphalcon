
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

#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"

/**
 * Phalcon\Config
 *
 * Phalcon\Config is designed to simplify the access to, and the use of, configuration data within applications.
 * It provides a nested object property based user interface for accessing this configuration data within
 * application code.
 *
 * <code>$config = new Phalcon\Config(array(
 *  "database" => array(
 *    "adapter" => "Mysql",
 *    "host" => "localhost",
 *    "username" => "scott",
 *    "password" => "cheetah",
 *    "name" => "test_db"
 *  ),
 *  "phalcon" => array(
 *    "controllersDir" => "../app/controllers/",
 *    "modelsDir" => "../app/models/",
 *    "viewsDir" => "../app/views/"
 *  )
 * ));</code>
 *
 */


/**
 * Phalcon\Config constructor
 *
 * @param array $arrayConfig
 */
PHP_METHOD(Phalcon_Config, __construct){

	zval *array_config = NULL, *value = NULL, *key = NULL, *config_value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &array_config) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!array_config) {
		PHALCON_INIT_NVAR(array_config);
		array_init(array_config);
	}
	
	if (Z_TYPE_P(array_config) == IS_ARRAY) { 
		
		if (!phalcon_valid_foreach(array_config TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(array_config);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_0:
		
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
			
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(value);
			
			if (Z_TYPE_P(value) == IS_ARRAY) { 
				eval_int = phalcon_array_isset_long(value, 0);
				if (!eval_int) {
					PHALCON_INIT_NVAR(config_value);
					object_init_ex(config_value, phalcon_config_ce);
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(config_value, "__construct", value, PH_CHECK);
					phalcon_update_property_zval_zval(this_ptr, key, config_value TSRMLS_CC);
				} else {
					phalcon_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
				}
			} else {
				phalcon_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
			}
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
			
		ph_cycle_end_0:
		if(0){}
		
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_config_exception_ce, "The configuration must be an Array");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Restores the state of a Phalcon\Config object
 *
 * @return Phalcon\Config
 */
PHP_METHOD(Phalcon_Config, __set_state){

	zval *data, *config;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(config);
	object_init_ex(config, phalcon_config_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(config, "__construct", data, PH_CHECK);
	
	RETURN_CTOR(config);
}

