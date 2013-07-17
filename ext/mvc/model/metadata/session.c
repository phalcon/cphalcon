
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

/**
 * Phalcon\Mvc\Model\MetaData\Session
 *
 * Stores model meta-data in session. Data will erased when the session finishes.
 * Meta-data are permanent while the session is active.
 *
 * You can query the meta-data by printing $_SESSION['$PMM$']
 *
 *<code>
 * $metaData = new Phalcon\Mvc\Model\Metadata\Session(array(
 *    'prefix' => 'my-app-id'
 * ));
 *</code>
 */


/**
 * Phalcon\Mvc\Model\MetaData\Session initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Session){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Session, mvc_model_metadata_session, "phalcon\\mvc\\model\\metadata", phalcon_mvc_model_metadata_session_method_entry, 0);

	zend_declare_property_string(phalcon_mvc_model_metadata_session_ce, SL("_prefix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_metadata_session_ce TSRMLS_CC, 1, phalcon_mvc_model_metadatainterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\MetaData\Session constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, __construct){

	zval *options = NULL, *prefix, *empty_array;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &options);
	
	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		if (phalcon_array_isset_string(options, SS("prefix"))) {
			PHALCON_OBS_VAR(prefix);
			phalcon_array_fetch_string(&prefix, options, SL("prefix"), PH_NOISY);
			phalcon_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	phalcon_update_property_this(this_ptr, SL("_metaData"), empty_array TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Reads meta-data from $_SESSION
 *
 * @param string $key
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, read){

	zval *key, *session = NULL, *_SESSION, *prefix, *prefix_key;
	zval *meta_data;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key);
	
	phalcon_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	PHALCON_CPY_WRT(session, _SESSION);
	
	PHALCON_OBS_VAR(prefix);
	phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefix_key);
	PHALCON_CONCAT_SV(prefix_key, "$PMM$", prefix);
	if (phalcon_array_isset(session, prefix_key)) {
	
		PHALCON_OBS_VAR(r0);
		phalcon_array_fetch(&r0, session, prefix_key, PH_NOISY);
		if (phalcon_array_isset(r0, key)) {
			PHALCON_OBS_VAR(r1);
			phalcon_array_fetch(&r1, session, prefix_key, PH_NOISY);
			PHALCON_OBS_VAR(meta_data);
			phalcon_array_fetch(&meta_data, r1, key, PH_NOISY);
			RETURN_CCTOR(meta_data);
		}
	}
	
	RETURN_MM_NULL();
}

/**
 * Writes the meta-data to $_SESSION
 *
 * @param string $key
 * @param array $data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, write){

	zval *key, *data, *prefix, *prefix_key, *_SESSION;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &key, &data);
	
	PHALCON_OBS_VAR(prefix);
	phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefix_key);
	PHALCON_CONCAT_SV(prefix_key, "$PMM$", prefix);
	phalcon_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	phalcon_array_update_multi_2(&_SESSION, prefix_key, key, &data, 0);
	
	PHALCON_MM_RESTORE();
}

