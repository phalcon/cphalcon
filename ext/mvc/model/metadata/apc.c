
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

#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Mvc\Model\MetaData\Apc
 *
 * Stores model meta-data in the APC cache. Data will erased if the web server is restarted
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 * You can query the meta-data by printing apc_fetch('$PMM$') or apc_fetch('$PMM$my-app-id')
 *
 *<code>
 *	$metaData = new Phalcon\Mvc\Model\Metadata\Apc(array(
 *		'prefix' => 'my-app-id',
 *		'lifetime' => 86400
 *	));
 *</code>
 */


/**
 * Phalcon\Mvc\Model\MetaData\Apc initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Apc){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Apc, mvc_model_metadata_apc, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_apc_method_entry, 0);

	zend_declare_property_string(phalcon_mvc_model_metadata_apc_ce, SL("_prefix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_metadata_apc_ce, SL("_ttl"), 172800, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_metadata_apc_ce TSRMLS_CC, 1, phalcon_mvc_model_metadatainterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\MetaData\Apc constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, __construct){

	zval *options = NULL, *prefix, *ttl, *empty_array;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &options);
	
	if (!options) {
		options = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		if (phalcon_array_isset_string(options, SS("prefix"))) {
			PHALCON_OBS_VAR(prefix);
			phalcon_array_fetch_string(&prefix, options, SL("prefix"), PH_NOISY);
			phalcon_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
		}
		if (phalcon_array_isset_string(options, SS("lifetime"))) {
			PHALCON_OBS_VAR(ttl);
			phalcon_array_fetch_string(&ttl, options, SL("lifetime"), PH_NOISY);
			phalcon_update_property_this(this_ptr, SL("_ttl"), ttl TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	phalcon_update_property_this(this_ptr, SL("_metaData"), empty_array TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Reads meta-data from APC
 *
 * @param  string $key
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, read){

	zval *key, *prefix, *apc_key, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key);
	
	PHALCON_OBS_VAR(prefix);
	phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(apc_key);
	PHALCON_CONCAT_SVV(apc_key, "$PMM$", prefix, key);
	
	PHALCON_INIT_VAR(data);
	phalcon_call_func_p1(data, "apc_fetch", apc_key);
	if (Z_TYPE_P(data) == IS_ARRAY) { 
		RETURN_CCTOR(data);
	}
	
	RETURN_MM_NULL();
}

/**
 * Writes the meta-data to APC
 *
 * @param string $key
 * @param array $data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, write){

	zval *key, *data, *prefix, *apc_key, *ttl;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &key, &data);
	
	PHALCON_OBS_VAR(prefix);
	phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(apc_key);
	PHALCON_CONCAT_SVV(apc_key, "$PMM$", prefix, key);
	
	PHALCON_OBS_VAR(ttl);
	phalcon_read_property_this(&ttl, this_ptr, SL("_ttl"), PH_NOISY_CC);
	phalcon_call_func_p3_noret("apc_store", apc_key, data, ttl);
	
	PHALCON_MM_RESTORE();
}

