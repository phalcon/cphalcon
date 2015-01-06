
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "mvc/model/metadata/session.h"
#include "mvc/model/metadata.h"
#include "mvc/model/metadatainterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"

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
zend_class_entry *phalcon_mvc_model_metadata_session_ce;

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, read);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, write);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_session___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_metadata_session_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Session, __construct, arginfo_phalcon_mvc_model_metadata_session___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Session, read, arginfo_phalcon_mvc_model_metadatainterface_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Session, write, arginfo_phalcon_mvc_model_metadatainterface_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Session, reset, arginfo_phalcon_mvc_model_metadatainterface_reset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\MetaData\Session initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Session){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Session, mvc_model_metadata_session, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_session_method_entry, 0);

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

	phalcon_fetch_params(0, 0, 1, &options);
	
	if (options && Z_TYPE_P(options) == IS_ARRAY) {
		if (phalcon_array_isset_string_fetch(&prefix, options, SS("prefix"))) {
			phalcon_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
		}
	}
	
	PHALCON_ALLOC_GHOST_ZVAL(empty_array);
	array_init(empty_array);
	phalcon_update_property_this(this_ptr, SL("_metaData"), empty_array TSRMLS_CC);
}

/**
 * Reads meta-data from $_SESSION
 *
 * @param string $key
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, read){

	zval *key, *session, *prefix, *prefix_key;
	zval *meta_data;
	zval *r0, *r1 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(0, 1, 0, &key);
	
	session = phalcon_get_global(SS("_SESSION") TSRMLS_CC);
	
	prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(prefix_key);
	PHALCON_CONCAT_SV(prefix_key, "$PMM$", prefix);
	if (phalcon_array_isset_fetch(&r0, session, prefix_key)) {

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
	
	prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(prefix_key);
	PHALCON_CONCAT_SV(prefix_key, "$PMM$", prefix);
	_SESSION = phalcon_get_global(SS("_SESSION") TSRMLS_CC);
	phalcon_array_update_multi_2(&_SESSION, prefix_key, key, data, 0);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, reset)
{
	zval prefix_key = zval_used_for_init, *pprefix = &prefix_key, *_SESSION;
	zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

	phalcon_concat_sv(&pprefix, SL("$PMM$"), prefix, 0 TSRMLS_CC);
	_SESSION = phalcon_get_global(SS("_SESSION") TSRMLS_CC);
	phalcon_array_unset(&_SESSION, &prefix_key, 0);
	zval_dtor(&prefix_key);

	PHALCON_CALL_PARENTW(NULL, phalcon_mvc_model_metadata_session_ce, getThis(), "reset");
}
