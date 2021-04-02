
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
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
 * Creates a new Cache class
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_CacheFactory) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Cache, CacheFactory, phalcon, cache_cachefactory, phalcon_cache_cachefactory_method_entry, 0);

	/**
	 * @var AdapterFactory
	 */
	zend_declare_property_null(phalcon_cache_cachefactory_ce, SL("adapterFactory"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Constructor
 */
PHP_METHOD(Phalcon_Cache_CacheFactory, __construct) {

	zval *factory, factory_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(factory, phalcon_cache_adapterfactory_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &factory);



	zephir_update_property_zval(this_ptr, ZEND_STRL("adapterFactory"), factory);

}

/**
 * Factory to create an instance from a Config object
 *
 * @param array|\Phalcon\Config config = [
 *     'adapter' => 'apcu',
 *     'options' => [
 *         'servers' => [
 *             [
 *                 'host' => 'localhost',
 *                 'port' => 11211,
 *                 'weight' => 1,
 *
 *             ]
 *         ],
 *         'host' => '127.0.0.1',
 *         'port' => 6379,
 *         'index' => 0,
 *         'persistent' => false,
 *         'auth' => '',
 *         'socket' => '',
 *         'defaultSerializer' => 'Php',
 *         'lifetime' => 3600,
 *         'serializer' => null,
 *         'prefix' => 'phalcon',
 *         'storageDir' => ''
 *     ]
 * ]
 */
PHP_METHOD(Phalcon_Cache_CacheFactory, load) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, name, options, _3, _4, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);

	ZEPHIR_SEPARATE_PARAM(config);


	_0 = Z_TYPE_P(config) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(config, phalcon_config_configinterface_ce);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&_1$$3, config, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, &_1$$3);
	}
	if (UNEXPECTED(Z_TYPE_P(config) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_exception_ce, "Config must be array or Phalcon\\Config object", "phalcon/Cache/CacheFactory.zep", 78);
		return;
	}
	if (UNEXPECTED(!(zephir_array_isset_string(config, SL("adapter"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_exception_ce, "You must provide 'adapter' option in factory config parameter.", "phalcon/Cache/CacheFactory.zep", 84);
		return;
	}
	ZEPHIR_OBS_VAR(&name);
	zephir_array_fetch_string(&name, config, SL("adapter"), PH_NOISY, "phalcon/Cache/CacheFactory.zep", 87);
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "options");
	ZEPHIR_CALL_CE_STATIC(&options, phalcon_helper_arr_ce, "get", &_2, 16, config, &_4, &_3);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, &name, &options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Constructs a new Cache instance.
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
PHP_METHOD(Phalcon_Cache_CacheFactory, newInstance) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *name_param = NULL, *options_param = NULL, adapter, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);
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


	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapterFactory"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&adapter, &_0, "newinstance", NULL, 0, &name, &options);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_cache_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 172, &adapter);
	zephir_check_call_status();
	RETURN_MM();

}

