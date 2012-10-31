
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
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Mvc\Model\MetaData\Apc
 *
 * Stores model meta-data in the APC cache. Data will erased if the web server is restarted
 *
 * By default meta-data is stored 48 hours (172800 seconds)
 *
 * You can query the meta-data by printing apc_fetch('$PMM$') or apc_fetch('$PMM$my-local-app')
 *
 *<code>
 * $metaData = new Phalcon\Mvc\Model\Metadata\Apc(array(
 *    'suffix' => 'my-app-id',
 *    'lifetime' => 86400
 * ));
 *</code>
 */


/**
 * Phalcon\Mvc\Model\MetaData\Apc constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, __construct){

	zval *options = NULL, *suffix, *ttl, *empty_array;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_NVAR(options);
	}
	
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		eval_int = phalcon_array_isset_string(options, SS("suffix"));
		if (eval_int) {
			PHALCON_INIT_VAR(suffix);
			phalcon_array_fetch_string(&suffix, options, SL("suffix"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_suffix"), suffix TSRMLS_CC);
		}
		eval_int = phalcon_array_isset_string(options, SS("lifetime"));
		if (eval_int) {
			PHALCON_INIT_VAR(ttl);
			phalcon_array_fetch_string(&ttl, options, SL("lifetime"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_ttl"), ttl TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	phalcon_update_property_zval(this_ptr, SL("_metaData"), empty_array TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Reads meta-data from APC
 *
 * @param  string $key
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, read){

	zval *key, *suffix, *apc_key, *data;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(suffix);
	phalcon_read_property(&suffix, this_ptr, SL("_suffix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(apc_key);
	PHALCON_CONCAT_SVV(apc_key, "$PMM$", suffix, key);
	
	PHALCON_INIT_VAR(data);
	PHALCON_CALL_FUNC_PARAMS_1(data, "apc_fetch", apc_key);
	if (Z_TYPE_P(data) == IS_ARRAY) { 
		
		RETURN_CCTOR(data);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Writes the meta-data to APC
 *
 * @param string $key
 * @param array $data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, write){

	zval *key, *data, *suffix, *apc_key, *ttl;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &key, &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(suffix);
	phalcon_read_property(&suffix, this_ptr, SL("_suffix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(apc_key);
	PHALCON_CONCAT_SVV(apc_key, "$PMM$", suffix, key);
	
	PHALCON_INIT_VAR(ttl);
	phalcon_read_property(&ttl, this_ptr, SL("_ttl"), PH_NOISY_CC);
	PHALCON_CALL_FUNC_PARAMS_3_NORETURN("apc_store", apc_key, data, ttl);
	
	PHALCON_MM_RESTORE();
}

