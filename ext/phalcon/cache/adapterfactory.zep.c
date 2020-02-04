
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
	zval *factory = NULL, factory_sub, *services_param = NULL, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&services);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &factory, &services_param);

	if (!factory) {
		factory = &factory_sub;
		factory = &__$null;
	}
	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&services, services_param);
	}


	zephir_update_property_zval(this_ptr, SL("serializerFactory"), factory);
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
	zval options, _1;
	zval *name_param = NULL, *options_param = NULL, definition, _0, _2;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_1);

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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkservice", NULL, 0, &name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&definition);
	zephir_array_fetch(&definition, &_0, &name, PH_NOISY, "/home/nikos/Work/niden/cphalcon/phalcon/Cache/AdapterFactory.zep", 68);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("serializerFactory"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_2);
	zephir_array_fast_append(&_1, &options);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(return_value, &definition, &_1);
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

