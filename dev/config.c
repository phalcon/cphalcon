
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
 * Phalcon_Config
 *
 * Phalcon_Config is designed to simplify the access to, and the use of, configuration data within applications.
 * It provides a nested object property based user interface for accessing this configuration data within
 * application code.
 *
 * 
 *
 */

/**
 * Phalcon_Config constructor
 *
 * @param array $arrayConfig
 * @return Phalcon_Config
 */
PHP_METHOD(Phalcon_Config, __construct){

	zval *array_config = NULL, *value = NULL, *key = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &array_config) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!array_config) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(array_config, a0);
	}
	
	if (phalcon_valid_foreach(array_config TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(array_config);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9656_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9656_0;
		} else {
			PHALCON_INIT_VAR(key);
			hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
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
		if (Z_TYPE_P(value) == IS_ARRAY) { 
			PHALCON_INIT_VAR(i0);
			object_init_ex(i0, phalcon_config_ce);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", value, PHALCON_CHECK);
			phalcon_update_property_zval(this_ptr, Z_STRVAL_P(key), Z_STRLEN_P(key), i0 TSRMLS_CC);
		} else {
			phalcon_update_property_zval(this_ptr, Z_STRVAL_P(key), Z_STRLEN_P(key), value TSRMLS_CC);
		}
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9656_0;
		fee_9656_0:
		if(0){ };
	}
	
	PHALCON_MM_RESTORE();
}

