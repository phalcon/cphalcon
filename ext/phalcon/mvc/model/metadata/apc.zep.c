
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


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
 *	$metaData = new \Phalcon\Mvc\Model\Metadata\Apc(array(
 *		'prefix' => 'my-app-id',
 *		'lifetime' => 86400
 *	));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Apc) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Apc, phalcon, mvc_model_metadata_apc, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_apc_method_entry, 0);

	zend_declare_property_string(phalcon_mvc_model_metadata_apc_ce, SL("_prefix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_model_metadata_apc_ce, SL("_ttl"), 172800, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_metadata_apc_ce TSRMLS_CC, 1, phalcon_mvc_model_metadatainterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\MetaData\Apc constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, __construct) {

	zval *options = NULL, *prefix, *ttl, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(options) == IS_ARRAY) {
		if (zephir_array_isset_string_fetch(&prefix, options, SS("prefix"), 1 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
		}
		if (zephir_array_isset_string_fetch(&ttl, options, SS("lifetime"), 1 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_ttl"), ttl TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_metaData"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads meta-data from APC
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, read) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *data = NULL, *_0, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVV(_1, "$PMM$", _0, key);
	ZEPHIR_CALL_FUNCTION(&data, "apc_fetch", NULL, 7, _1);
	zephir_check_call_status();
	if (Z_TYPE_P(data) == IS_ARRAY) {
		RETURN_CCTOR(data);
	}
	RETURN_MM_NULL();

}

/**
 * Writes the meta-data to APC
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, write) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *data, *_0, *_1, *_2;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &data);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVV(_1, "$PMM$", _0, key);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_ttl"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "apc_store", NULL, 8, _1, data, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

