
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
 * $metaData = new \Phalcon\Mvc\Model\Metadata\Apc(
 *     [
 *         "prefix"   => "my-app-id",
 *         "lifetime" => 86400,
 *     ]
 * );
 *</code>
 *
 * @deprecated Deprecated since 3.3.0, will be removed in 4.0.0
 * @see Phalcon\Mvc\Model\Metadata\Apcu
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Apc) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Apc, phalcon, mvc_model_metadata_apc, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_apc_method_entry, 0);

	zend_declare_property_string(phalcon_mvc_model_metadata_apc_ce, SL("_prefix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_model_metadata_apc_ce, SL("_ttl"), 172800, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_metadata_apc_ce, SL("_metaData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_mvc_model_metadata_apc_ce->create_object = zephir_init_properties_Phalcon_Mvc_Model_MetaData_Apc;
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\MetaData\Apc constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, __construct) {

	zval *options = NULL, *prefix = NULL, *ttl = NULL;

	zephir_fetch_params(0, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(options) == IS_ARRAY) {
		if (zephir_array_isset_string_fetch(&prefix, options, SS("prefix"), 1 TSRMLS_CC)) {
			zephir_update_property_this(getThis(), SL("_prefix"), prefix TSRMLS_CC);
		}
		if (zephir_array_isset_string_fetch(&ttl, options, SS("lifetime"), 1 TSRMLS_CC)) {
			zephir_update_property_this(getThis(), SL("_ttl"), ttl TSRMLS_CC);
		}
	}

}

/**
 * Reads meta-data from APC
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, read) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *data = NULL, *_0, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVV(_1, "$PMM$", _0, key);
	ZEPHIR_CALL_FUNCTION(&data, "apc_fetch", NULL, 90, _1);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *data, *_0, *_1, *_2;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &data);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVV(_1, "$PMM$", _0, key);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_ttl"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "apc_store", NULL, 91, _1, data, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object_value zephir_init_properties_Phalcon_Mvc_Model_MetaData_Apc(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_metaData"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_metaData"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

