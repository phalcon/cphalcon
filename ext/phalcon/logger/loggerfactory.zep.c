
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
 * Phalcon\Logger\LoggerFactory
 *
 * Logger factory
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_LoggerFactory) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger, LoggerFactory, phalcon, logger_loggerfactory, phalcon_logger_loggerfactory_method_entry, 0);

	/**
	 * @var AdapterFactory
	 */
	zend_declare_property_null(phalcon_logger_loggerfactory_ce, SL("adapterFactory"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Logger_LoggerFactory, __construct) {

	zval *factory, factory_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &factory);



	zephir_update_property_zval(this_ptr, SL("adapterFactory"), factory);

}

/**
 * Factory to create an instace from a Config object
 */
PHP_METHOD(Phalcon_Logger_LoggerFactory, load) {

	zend_bool _0;
	zval data;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, adapter, adapterClass, adapterFileName, adapterOptions, adapters, name, options, _3, _4, _5, *_6, _7, _1$$3, _8$$6, _9$$6, _10$$6, _11$$6, _12$$7, _13$$7, _14$$7, _15$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&adapterClass);
	ZVAL_UNDEF(&adapterFileName);
	ZVAL_UNDEF(&adapterOptions);
	ZVAL_UNDEF(&adapters);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);

	ZEPHIR_SEPARATE_PARAM(config);


	_0 = Z_TYPE_P(config) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(config, phalcon_config_ce);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&_1$$3, config, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, &_1$$3);
	}
	if (UNEXPECTED(Z_TYPE_P(config) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "Config must be array or Phalcon\\Config object", "phalcon/Logger/LoggerFactory.zep", 50);
		return;
	}
	if (UNEXPECTED(!(zephir_array_isset_string(config, SL("name"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "You must provide 'name' option in factory config parameter.", "phalcon/Logger/LoggerFactory.zep", 56);
		return;
	}
	ZEPHIR_OBS_VAR(&name);
	zephir_array_fetch_string(&name, config, SL("name"), PH_NOISY, "phalcon/Logger/LoggerFactory.zep", 59);
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "options");
	ZEPHIR_CALL_CE_STATIC(&options, phalcon_helper_arr_ce, "get", &_2, 15, config, &_4, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	array_init(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "adapters");
	ZEPHIR_CALL_CE_STATIC(&adapters, phalcon_helper_arr_ce, "get", &_2, 15, config, &_5, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	zephir_is_iterable(&adapters, 0, "phalcon/Logger/LoggerFactory.zep", 76);
	if (Z_TYPE_P(&adapters) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&adapters), _6)
		{
			ZEPHIR_INIT_NVAR(&adapter);
			ZVAL_COPY(&adapter, _6);
			ZEPHIR_INIT_NVAR(&_8$$6);
			ZVAL_STRING(&_8$$6, "adapter");
			ZEPHIR_CALL_CE_STATIC(&adapterClass, phalcon_helper_arr_ce, "get", &_2, 15, &adapter, &_8$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$6);
			ZVAL_STRING(&_8$$6, "name");
			ZEPHIR_CALL_CE_STATIC(&adapterFileName, phalcon_helper_arr_ce, "get", &_2, 15, &adapter, &_8$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$6);
			array_init(&_8$$6);
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "options");
			ZEPHIR_CALL_CE_STATIC(&adapterOptions, phalcon_helper_arr_ce, "get", &_2, 15, &adapter, &_9$$6, &_8$$6);
			zephir_check_call_status();
			zephir_read_property(&_10$$6, this_ptr, SL("adapterFactory"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_11$$6, &_10$$6, "newinstance", NULL, 0, &adapterClass, &adapterFileName, &adapterOptions);
			zephir_check_call_status();
			zephir_array_append(&data, &_11$$6, PH_SEPARATE, "phalcon/Logger/LoggerFactory.zep", 73);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &adapters, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &adapters, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&adapter, &adapters, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$7);
				ZVAL_STRING(&_12$$7, "adapter");
				ZEPHIR_CALL_CE_STATIC(&adapterClass, phalcon_helper_arr_ce, "get", &_2, 15, &adapter, &_12$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$7);
				ZVAL_STRING(&_12$$7, "name");
				ZEPHIR_CALL_CE_STATIC(&adapterFileName, phalcon_helper_arr_ce, "get", &_2, 15, &adapter, &_12$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$7);
				array_init(&_12$$7);
				ZEPHIR_INIT_NVAR(&_13$$7);
				ZVAL_STRING(&_13$$7, "options");
				ZEPHIR_CALL_CE_STATIC(&adapterOptions, phalcon_helper_arr_ce, "get", &_2, 15, &adapter, &_13$$7, &_12$$7);
				zephir_check_call_status();
				zephir_read_property(&_14$$7, this_ptr, SL("adapterFactory"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_15$$7, &_14$$7, "newinstance", NULL, 0, &adapterClass, &adapterFileName, &adapterOptions);
				zephir_check_call_status();
				zephir_array_append(&data, &_15$$7, PH_SEPARATE, "phalcon/Logger/LoggerFactory.zep", 73);
			ZEPHIR_CALL_METHOD(NULL, &adapters, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&adapter);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, &name, &data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a Logger object
 *
 * @param string $name
 * @param array  $adapters
 *
 * @return Logger
 */
PHP_METHOD(Phalcon_Logger_LoggerFactory, newInstance) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval adapters;
	zval *name_param = NULL, *adapters_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&adapters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &adapters_param);

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
	if (!adapters_param) {
		ZEPHIR_INIT_VAR(&adapters);
		array_init(&adapters);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&adapters, adapters_param);
	}


	object_init_ex(return_value, phalcon_logger_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 412, &name, &adapters);
	zephir_check_call_status();
	RETURN_MM();

}

