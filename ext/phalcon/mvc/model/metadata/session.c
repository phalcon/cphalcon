
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Session) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Session, phalcon, mvc_model_metadata_session, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_session_method_entry, 0);

	zend_declare_property_string(phalcon_mvc_model_metadata_session_ce, SL("_prefix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_metadata_session_ce TSRMLS_CC, 1, phalcon_mvc_model_metadatainterface_ce);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\MetaData\Session constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, __construct) {

	zval *options = NULL, *prefix, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if ((Z_TYPE_P(options) == IS_ARRAY)) {
		if (zephir_array_isset_string_fetch(&prefix, options, SS("prefix"), 1 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_metaData"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads meta-data from $_SESSION
 *
 * @param string key
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, read) {

	zval *key_param = NULL, *session = NULL, *prefixKey, *metaData, *_SESSION, *_0, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

		if (Z_TYPE_P(key_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		key = key_param;



	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	ZEPHIR_CPY_WRT(session, _SESSION);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixKey);
	ZEPHIR_CONCAT_SV(prefixKey, "$PMM$", _0);
	if (zephir_array_isset(session, prefixKey)) {
		zephir_array_fetch(&_1, session, prefixKey, PH_NOISY | PH_READONLY TSRMLS_CC);
		if (zephir_array_isset_fetch(&metaData, _1, key, 1 TSRMLS_CC)) {
			RETURN_CTOR(metaData);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Writes the meta-data to $_SESSION
 *
 * @param string key
 * @param array data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, write) {

	zval *key_param = NULL, *data, *_SESSION, *_0, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &data);

		if (Z_TYPE_P(key_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		key = key_param;



	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "$PMM$", _0);
	zephir_array_update_multi(&_SESSION, &data TSRMLS_CC, SL("zz"), 2, _1, key);
	ZEPHIR_MM_RESTORE();

}

