
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Factory to create Cache adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_AdapterFactory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache, AdapterFactory, phalcon, cache_adapterfactory, phalcon_factory_abstractfactory_ce, phalcon_cache_adapterfactory_method_entry, 0);

	/**
	 * @var SerializerFactory
	 */
	zend_declare_property_null(phalcon_cache_adapterfactory_ce, SL("serializerFactory"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

/**
 * AdapterFactory constructor.
 */
PHP_METHOD(Phalcon_Cache_AdapterFactory, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval services;
	zval *factory, factory_sub, *services_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_UNDEF(&services);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(factory, phalcon_storage_serializerfactory_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(services)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &factory, &services_param);

	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&services, services_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("serializerFactory"), factory);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Create a new instance of the adapter
 *
 * @param array options = [
 *     'servers' => [
 *         [
 *             'host' => 'localhost',
 *             'port' => 11211,
 *             'weight' => 1,
 *         ]
 *     ],
 *     'host' => '127.0.0.1',
 *     'port' => 6379,
 *     'index' => 0,
 *     'persistent' => false,
 *     'auth' => '',
 *     'socket' => '',
 *     'defaultSerializer' => 'Php',
 *     'lifetime' => 3600,
 *     'serializer' => null,
 *     'prefix' => 'phalcon',
 *     'storageDir' => ''
 * ]
 */
PHP_METHOD(Phalcon_Cache_AdapterFactory, newInstance) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, _0;
	zval *name_param = NULL, *options_param = NULL, definition, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &options_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_CALL_METHOD(&definition, this_ptr, "getservice", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("serializerFactory"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, &options);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(return_value, &definition, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the available adapters
 */
PHP_METHOD(Phalcon_Cache_AdapterFactory, getAdapters) {

	zval *this_ptr = getThis();



	zephir_create_array(return_value, 5, 0);
	add_assoc_stringl_ex(return_value, SL("apcu"), SL("Phalcon\\Cache\\Adapter\\Apcu"));
	add_assoc_stringl_ex(return_value, SL("libmemcached"), SL("Phalcon\\Cache\\Adapter\\Libmemcached"));
	add_assoc_stringl_ex(return_value, SL("memory"), SL("Phalcon\\Cache\\Adapter\\Memory"));
	add_assoc_stringl_ex(return_value, SL("redis"), SL("Phalcon\\Cache\\Adapter\\Redis"));
	add_assoc_stringl_ex(return_value, SL("stream"), SL("Phalcon\\Cache\\Adapter\\Stream"));
	return;

}

