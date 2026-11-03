
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "ext/date/php_date.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Factory creating logger objects
 *
 * @phpstan-import-type logger_adapter_config from LoggerTypes
 * @phpstan-import-type logger_adapters from LoggerTypes
 * @phpstan-import-type logger_factory_config from LoggerTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_LoggerFactory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger, LoggerFactory, phalcon, logger_loggerfactory, phalcon_factory_abstractconfigfactory_ce, phalcon_logger_loggerfactory_method_entry, 0);

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_logger_loggerfactory_ce, SL("adapterFactory"), &_zc0, ZEND_ACC_PRIVATE, 0, SL("Phalcon\\Logger\\AdapterFactory"));
	}

	return SUCCESS;
}

/**
 * Constructor
 */
PHP_METHOD(Phalcon_Logger_LoggerFactory, __construct)
{
	zval *factory, factory_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("adapterFactory", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(factory, phalcon_logger_adapterfactory_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &factory);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 971, factory);
}

/**
 * Factory to create an instance from a Config object
 *
 * The adapter list lives under `options`, not at the top level.
 *
 * @phpstan-param ConfigInterface|logger_factory_config $config
 *
 * @param array|ConfigInterface $config = [
 *     'name'    => 'messages',
 *     'options' => [
 *         'adapters' => [
 *             'adapter-name' => [
 *                 'adapter' => 'stream',
 *                 'name'    => 'file.log',
 *                 'options' => [
 *                     'mode'     => 'ab',
 *                     'option'   => null,
 *                     'facility' => null
 *                 ],
 *             ],
 *         ],
 *     ]
 * ]
 */
PHP_METHOD(Phalcon_Logger_LoggerFactory, load)
{
	zend_bool _14;
	zend_string *_8;
	zend_ulong _7;
	zval data;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, adapter, adapterClass, adapterFileName, adapterName, adapterOptions, adapters, name, timezone, options, _0, _1, _3, _4, *_5, *_6, _13, _9$$3, _10$$3, _11$$3, _12$$3, _15$$4, _16$$4, _17$$4, _18$$4;
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&data);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("adapterFactory", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config);
	ZEPHIR_SEPARATE_PARAM(config);
	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkConfig", NULL, 0, config);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(config, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "name");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkConfigElement", NULL, 0, config, &_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(config, &_0);
	zephir_memory_observe(&name);
	zephir_array_fetch_string(&name, config, SL("name"), PH_NOISY, "phalcon/Logger/LoggerFactory.zep", 73);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "timezone");
	ZEPHIR_CALL_METHOD(&timezone, this_ptr, "getArrVal", &_2, 0, config, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	array_init(&_1);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "options");
	ZEPHIR_CALL_METHOD(&options, this_ptr, "getArrVal", &_2, 0, config, &_3, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	array_init(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "adapters");
	ZEPHIR_CALL_METHOD(&adapters, this_ptr, "getArrVal", &_2, 0, &options, &_4, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(&adapters) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_4);
		zephir_string_to_char_array(&_4, &adapters);
		_5 = &_4;
	} else {
		_5 = &adapters;
	}
	zephir_is_iterable(_5, 0, "phalcon/Logger/LoggerFactory.zep", 92);
	if (Z_TYPE_P(_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_5), _7, _8, _6)
		{
			ZEPHIR_INIT_NVAR(&adapterName);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&adapterName, _8);
			} else {
				ZVAL_LONG(&adapterName, _7);
			}
			ZEPHIR_INIT_NVAR(&adapter);
			ZVAL_COPY(&adapter, _6);
			ZEPHIR_INIT_NVAR(&_9$$3);
			ZVAL_STRING(&_9$$3, "adapter");
			ZEPHIR_CALL_METHOD(&adapterClass, this_ptr, "getArrVal", &_2, 0, &adapter, &_9$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_9$$3);
			ZVAL_STRING(&_9$$3, "name");
			ZEPHIR_CALL_METHOD(&adapterFileName, this_ptr, "getArrVal", &_2, 0, &adapter, &_9$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_9$$3);
			array_init(&_9$$3);
			ZEPHIR_INIT_NVAR(&_10$$3);
			ZVAL_STRING(&_10$$3, "options");
			ZEPHIR_CALL_METHOD(&adapterOptions, this_ptr, "getArrVal", &_2, 0, &adapter, &_10$$3, &_9$$3);
			zephir_check_call_status();
			zephir_read_property_cached(&_11$$3, this_ptr, _zephir_prop_0, 971, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_12$$3, &_11$$3, "newInstance", NULL, 0, &adapterClass, &adapterFileName, &adapterOptions);
			zephir_check_call_status();
			zephir_array_update_zval(&data, &adapterName, &_12$$3, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _5, "rewind", NULL, 0);
		zephir_check_call_status();
		_14 = 1;
		while (1) {
			if (_14) {
				_14 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _5, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_13, _5, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_13)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&adapterName, _5, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&adapter, _5, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_15$$4);
				ZVAL_STRING(&_15$$4, "adapter");
				ZEPHIR_CALL_METHOD(&adapterClass, this_ptr, "getArrVal", &_2, 0, &adapter, &_15$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_15$$4);
				ZVAL_STRING(&_15$$4, "name");
				ZEPHIR_CALL_METHOD(&adapterFileName, this_ptr, "getArrVal", &_2, 0, &adapter, &_15$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_15$$4);
				array_init(&_15$$4);
				ZEPHIR_INIT_NVAR(&_16$$4);
				ZVAL_STRING(&_16$$4, "options");
				ZEPHIR_CALL_METHOD(&adapterOptions, this_ptr, "getArrVal", &_2, 0, &adapter, &_16$$4, &_15$$4);
				zephir_check_call_status();
				zephir_read_property_cached(&_17$$4, this_ptr, _zephir_prop_0, 971, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_18$$4, &_17$$4, "newInstance", NULL, 0, &adapterClass, &adapterFileName, &adapterOptions);
				zephir_check_call_status();
				zephir_array_update_zval(&data, &adapterName, &_18$$4, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&adapter);
	ZEPHIR_INIT_NVAR(&adapterName);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newInstance", NULL, 0, &name, &data, &timezone);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a Logger object
 *
 * @phpstan-param logger_adapters $adapters
 */
PHP_METHOD(Phalcon_Logger_LoggerFactory, newInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval adapters;
	zval name_zv, *adapters_param = NULL, *timezone = NULL, timezone_sub, __$null;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&timezone_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&adapters);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(adapters, adapters_param)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(timezone, php_date_get_timezone_ce())
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		adapters_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		timezone = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
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
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &name_zv, &adapters, timezone);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return class-string<\Exception>
 */
PHP_METHOD(Phalcon_Logger_LoggerFactory, getExceptionClass)
{

	RETURN_STRING("Phalcon\\Logger\\Exception");
}

/**
 * @param array       $collection
 * @param mixed       $index
 * @param mixed|null  $defaultValue
 * @param string|null $cast
 *
 * @return mixed|null
 */
PHP_METHOD(Phalcon_Logger_LoggerFactory, getArrVal)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *cast = NULL;
	zval *collection_param = NULL, *index, index_sub, *defaultValue = NULL, defaultValue_sub, cast_zv, __$null, value;
	zval collection;

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&cast_zv);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
		Z_PARAM_ZVAL(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_STR_OR_NULL(cast)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	collection_param = ZEND_CALL_ARG(execute_data, 1);
	index = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		defaultValue = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_get_arrval(&collection, collection_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!cast) {
		ZEPHIR_INIT_VAR(&cast_zv);
	} else {
		zephir_memory_observe(&cast_zv);
	ZVAL_STR_COPY(&cast_zv, cast);
	}
	ZEPHIR_CPY_WRT(&value, defaultValue);
	_0 = zephir_array_isset_value(&collection, index);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (1 == _0) {
		ZEPHIR_OBS_NVAR(&value);
		zephir_array_fetch(&value, &collection, index, PH_NOISY, "phalcon/Traits/Support/Helper/Arr/GetTrait.zep", 38);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (!(ZEPHIR_IS_EMPTY(&cast_zv))) {
		ZEPHIR_MAKE_REF(&value);
		ZEPHIR_CALL_FUNCTION(NULL, "settype", NULL, 17, &value, &cast_zv);
		ZEPHIR_UNREF(&value);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&value);
}

