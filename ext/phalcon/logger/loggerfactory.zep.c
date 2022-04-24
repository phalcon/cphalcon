
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "ext/date/php_date.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Factory creating logger objects
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_LoggerFactory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger, LoggerFactory, phalcon, logger_loggerfactory, phalcon_factory_abstractconfigfactory_ce, phalcon_logger_loggerfactory_method_entry, 0);

	/**
	 * @var AdapterFactory
	 */
	zend_declare_property_null(phalcon_logger_loggerfactory_ce, SL("adapterFactory"), ZEND_ACC_PRIVATE);
	return SUCCESS;
}

/**
 * @param AdapterFactory $factory
 */
PHP_METHOD(Phalcon_Logger_LoggerFactory, __construct)
{
	zval *factory, factory_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(factory, phalcon_logger_adapterfactory_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &factory);


	zephir_update_property_zval(this_ptr, ZEND_STRL("adapterFactory"), factory);
}

/**
 * Factory to create an instance from a Config object
 *
 * @param array|ConfigInterface $config = [
 *     'name'     => 'messages',
 *     'adapters' => [
 *         'adapter-name' => [
 *              'adapter' => 'stream',
 *              'name'    => 'file.log',
 *              'options' => [
 *                  'mode'     => 'ab',
 *                  'option'   => null,
 *                  'facility' => null
 *              ],
 *         ],
 *     ]
 * ]
 */
PHP_METHOD(Phalcon_Logger_LoggerFactory, load)
{
	zend_string *_7;
	zend_ulong _6;
	zval data;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, adapter, adapterClass, adapterFileName, adapterName, adapterOptions, adapters, name, timezone, options, _0, _1, _2, _3, *_4, _5, _8$$3, _9$$3, _10$$3, _11$$3, _12$$4, _13$$4, _14$$4, _15$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&adapterClass);
	ZVAL_UNDEF(&adapterFileName);
	ZVAL_UNDEF(&adapterName);
	ZVAL_UNDEF(&adapterOptions);
	ZVAL_UNDEF(&adapters);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&timezone);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);
	ZEPHIR_SEPARATE_PARAM(config);


	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkconfig", NULL, 0, config);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(config, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "name");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkconfigelement", NULL, 0, config, &_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(config, &_0);
	ZEPHIR_OBS_VAR(&name);
	zephir_array_fetch_string(&name, config, SL("name"), PH_NOISY, "phalcon/Logger/LoggerFactory.zep", 62);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "timezone");
	ZEPHIR_CALL_METHOD(&timezone, this_ptr, "getarrval", NULL, 0, config, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	array_init(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "options");
	ZEPHIR_CALL_METHOD(&options, this_ptr, "getarrval", NULL, 0, config, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	array_init(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "adapters");
	ZEPHIR_CALL_METHOD(&adapters, this_ptr, "getarrval", NULL, 0, &options, &_3, &_2);
	zephir_check_call_status();
	zephir_is_iterable(&adapters, 0, "phalcon/Logger/LoggerFactory.zep", 81);
	if (Z_TYPE_P(&adapters) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&adapters), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&adapterName);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&adapterName, _7);
			} else {
				ZVAL_LONG(&adapterName, _6);
			}
			ZEPHIR_INIT_NVAR(&adapter);
			ZVAL_COPY(&adapter, _4);
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZVAL_STRING(&_8$$3, "adapter");
			ZEPHIR_CALL_METHOD(&adapterClass, this_ptr, "getarrval", NULL, 0, &adapter, &_8$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZVAL_STRING(&_8$$3, "name");
			ZEPHIR_CALL_METHOD(&adapterFileName, this_ptr, "getarrval", NULL, 0, &adapter, &_8$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$3);
			array_init(&_8$$3);
			ZEPHIR_INIT_NVAR(&_9$$3);
			ZVAL_STRING(&_9$$3, "options");
			ZEPHIR_CALL_METHOD(&adapterOptions, this_ptr, "getarrval", NULL, 0, &adapter, &_9$$3, &_8$$3);
			zephir_check_call_status();
			zephir_read_property(&_10$$3, this_ptr, ZEND_STRL("adapterFactory"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_11$$3, &_10$$3, "newinstance", NULL, 0, &adapterClass, &adapterFileName, &adapterOptions);
			zephir_check_call_status();
			zephir_array_update_zval(&data, &adapterName, &_11$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &adapters, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &adapters, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&adapterName, &adapters, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&adapter, &adapters, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$4);
				ZVAL_STRING(&_12$$4, "adapter");
				ZEPHIR_CALL_METHOD(&adapterClass, this_ptr, "getarrval", NULL, 0, &adapter, &_12$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$4);
				ZVAL_STRING(&_12$$4, "name");
				ZEPHIR_CALL_METHOD(&adapterFileName, this_ptr, "getarrval", NULL, 0, &adapter, &_12$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$4);
				array_init(&_12$$4);
				ZEPHIR_INIT_NVAR(&_13$$4);
				ZVAL_STRING(&_13$$4, "options");
				ZEPHIR_CALL_METHOD(&adapterOptions, this_ptr, "getarrval", NULL, 0, &adapter, &_13$$4, &_12$$4);
				zephir_check_call_status();
				zephir_read_property(&_14$$4, this_ptr, ZEND_STRL("adapterFactory"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_15$$4, &_14$$4, "newinstance", NULL, 0, &adapterClass, &adapterFileName, &adapterOptions);
				zephir_check_call_status();
				zephir_array_update_zval(&data, &adapterName, &_15$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &adapters, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&adapter);
	ZEPHIR_INIT_NVAR(&adapterName);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, &name, &data, &timezone);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a Logger object
 *
 * @param string            $name
 * @param array             $adapters
 * @param DateTimeZone|null $timezone
 *
 * @return Logger
 */
PHP_METHOD(Phalcon_Logger_LoggerFactory, newInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval adapters;
	zval *name_param = NULL, *adapters_param = NULL, *timezone = NULL, timezone_sub, __$null;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&timezone_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&adapters);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(adapters)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(timezone, php_date_get_timezone_ce())
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &name_param, &adapters_param, &timezone);
	zephir_get_strval(&name, name_param);
	if (!adapters_param) {
		ZEPHIR_INIT_VAR(&adapters);
		array_init(&adapters);
	} else {
		zephir_get_arrval(&adapters, adapters_param);
	}
	if (!timezone) {
		timezone = &timezone_sub;
		timezone = &__$null;
	}


	object_init_ex(return_value, phalcon_logger_logger_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 491, &name, &adapters, timezone);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @todo Remove this when we get traits
 */
PHP_METHOD(Phalcon_Logger_LoggerFactory, getArrVal)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *collection_param = NULL, *index, index_sub, *defaultValue = NULL, defaultValue_sub, __$null, value;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_ZVAL(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &collection_param, &index, &defaultValue);
	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	if (UNEXPECTED(!(zephir_array_isset_fetch(&value, &collection, index, 1)))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CTOR(&value);
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Logger_LoggerFactory, getExceptionClass)
{
	zval *this_ptr = getThis();



	RETURN_STRING("Phalcon\\Logger\\Exception");
}

