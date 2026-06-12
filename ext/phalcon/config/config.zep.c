
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * `Phalcon\Config` is designed to simplify the access to, and the use of,
 * configuration data within applications. It provides a nested object property
 * based user interface for accessing this configuration data within application
 * code.
 *
 *```php
 * $config = new \Phalcon\Config\Config(
 *     [
 *         "database" => [
 *             "adapter"  => "Mysql",
 *             "host"     => "localhost",
 *             "username" => "scott",
 *             "password" => "cheetah",
 *             "dbname"   => "test_db",
 *         ],
 *         "phalcon" => [
 *             "controllersDir" => "../app/controllers/",
 *             "modelsDir"      => "../app/models/",
 *             "viewsDir"       => "../app/views/",
 *         ],
 *     ]
 * );
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_Config)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config, Config, phalcon, config_config, phalcon_support_collection_ce, phalcon_config_config_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_config_config_ce, SL("pathDelimiter"), ".", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_config_config_ce, SL("DEFAULT_PATH_DELIMITER"), ".");

	zend_class_implements(phalcon_config_config_ce, 1, phalcon_config_configinterface_ce);
	return SUCCESS;
}

/**
 * Gets the default path delimiter
 *
 * @return string
 */
PHP_METHOD(Phalcon_Config_Config, getPathDelimiter)
{

	RETURN_MEMBER_TYPED(getThis(), "pathDelimiter", IS_STRING);
}

/**
 * Merges a configuration into the current one
 *
 *```php
 * $appConfig = new \Phalcon\Config\Config(
 *     [
 *         "database" => [
 *             "host" => "localhost",
 *         ],
 *     ]
 * );
 *
 * $globalConfig->merge($appConfig);
 *```
 *
 * @param array|ConfigInterface $toMerge
 *
 * @return ConfigInterface
 * @throws Exception
 */
PHP_METHOD(Phalcon_Config_Config, merge)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *toMerge, toMerge_sub, result, source, target, _1$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&toMerge_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&_1$$5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(toMerge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &toMerge);
	if (Z_TYPE_P(toMerge) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&target, toMerge);
	} else {
		_0 = Z_TYPE_P(toMerge) == IS_OBJECT;
		if (_0) {
			_0 = zephir_instance_of_ev(toMerge, phalcon_config_configinterface_ce);
		}
		if (_0) {
			ZEPHIR_CALL_METHOD(&target, toMerge, "toarray", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_1$$5);
			object_init_ex(&_1$$5, phalcon_config_exceptions_invalidmergedata_ce);
			ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 38);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$5, "phalcon/Config/Config.zep", 92);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD(&source, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "clear", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, this_ptr, "internalmerge", NULL, 39, &source, &target);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &result);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Returns a value from current config using a dot separated path.
 *
 *```php
 * echo $config->path("unknown.path", "default", ".");
 *```
 *
 * @param string      $path
 * @param mixed|null  $defaultValue
 * @param string|null $delimiter
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Config_Config, path)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval path_zv, *defaultValue = NULL, defaultValue_sub, delimiter_zv, __$null, config, key, keys, pathDelimiter, _0, _1$$4, _3$$5, _4$$5;
	zend_string *path = NULL, *delimiter = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&delimiter_zv);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&pathDelimiter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(path)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_STR_OR_NULL(delimiter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!delimiter) {
		ZEPHIR_INIT_VAR(&delimiter_zv);
	} else {
		zephir_memory_observe(&delimiter_zv);
	ZVAL_STR_COPY(&delimiter_zv, delimiter);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &path_zv);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &path_zv);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(&pathDelimiter, &delimiter_zv);
	if (1 == ZEPHIR_IS_EMPTY(&pathDelimiter)) {
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("pathDelimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&pathDelimiter, &_1$$4);
	}
	ZEPHIR_INIT_VAR(&config);
	if (zephir_clone(&config, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&keys);
	zephir_fast_explode(&keys, &pathDelimiter, &path_zv, LONG_MAX);
	while (1) {
		if (!(1 != ZEPHIR_IS_EMPTY(&keys))) {
			break;
		}
		ZEPHIR_MAKE_REF(&keys);
		ZEPHIR_CALL_FUNCTION(&key, "array_shift", &_2, 40, &keys);
		ZEPHIR_UNREF(&keys);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$5, &config, "has", NULL, 0, &key);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_3$$5)) {
			break;
		}
		if (1 == ZEPHIR_IS_EMPTY(&keys)) {
			ZEPHIR_RETURN_CALL_METHOD(&config, "get", NULL, 0, &key);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_CALL_METHOD(&_4$$5, &config, "get", NULL, 0, &key);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&config, &_4$$5);
		if (1 == ZEPHIR_IS_EMPTY(&config)) {
			break;
		}
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();
}

/**
 * Sets the default path delimiter
 *
 * @param string|null $delimiter
 *
 * @return ConfigInterface
 */
PHP_METHOD(Phalcon_Config_Config, setPathDelimiter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval delimiter_zv;
	zend_string *delimiter = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&delimiter_zv);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(delimiter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!delimiter) {
		ZEPHIR_INIT_VAR(&delimiter_zv);
	} else {
		zephir_memory_observe(&delimiter_zv);
	ZVAL_STR_COPY(&delimiter_zv, delimiter);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("pathDelimiter"), &delimiter_zv);
	RETURN_THIS();
}

/**
 * Converts recursively the object to an array
 *
 *```php
 * print_r(
 *     $config->toArray()
 * );
 *```
 *
 * @return array
 */
PHP_METHOD(Phalcon_Config_Config, toArray)
{
	zend_bool _6, _3$$3, _7$$5;
	zend_string *_2;
	zend_ulong _1;
	zval results;
	zval data, key, value, *_0, _5, _4$$4, _8$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&results);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&results);
	array_init(&results);
	ZEPHIR_CALL_PARENT(&data, phalcon_config_config_ce, getThis(), "toarray", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&data, 0, "phalcon/Config/Config.zep", 203);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&key, _2);
			} else {
				ZVAL_LONG(&key, _1);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			_3$$3 = Z_TYPE_P(&value) == IS_OBJECT;
			if (_3$$3) {
				_3$$3 = 1 == (zephir_method_exists_ex(&value, ZEND_STRL("toarray")) == SUCCESS);
			}
			if (_3$$3) {
				ZEPHIR_CALL_METHOD(&_4$$4, &value, "toarray", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&value, &_4$$4);
			}
			zephir_array_update_zval(&results, &key, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				_7$$5 = Z_TYPE_P(&value) == IS_OBJECT;
				if (_7$$5) {
					_7$$5 = 1 == (zephir_method_exists_ex(&value, ZEND_STRL("toarray")) == SUCCESS);
				}
				if (_7$$5) {
					ZEPHIR_CALL_METHOD(&_8$$6, &value, "toarray", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&value, &_8$$6);
				}
				zephir_array_update_zval(&results, &key, &value, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&results);
}

/**
 * Builds a new collection with the given data, carrying over the
 * configuration of the current one. Clone-based instead of
 * constructor-based: adapter subclasses (Ini, Json, Php, Yaml, Grouped)
 * define file-loading constructors that are incompatible with the
 * parent's `(array data, ...)` signature, so `filter()`, `map()`,
 * `sort()` and `where()` would otherwise fail on any adapter instance.
 *
 * @param array<int|string, mixed> $data
 *
 * @return static
 */
PHP_METHOD(Phalcon_Config_Config, cloneEmpty)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, copy;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&copy);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &data_param);
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}
	ZEPHIR_INIT_VAR(&copy);
	if (zephir_clone(&copy, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, &copy, "replace", NULL, 0, &data);
	zephir_check_call_status();
	RETURN_CCTOR(&copy);
}

/**
 * Performs a merge recursively
 *
 * @param array $source
 * @param array $target
 *
 * @return array
 */
PHP_METHOD(Phalcon_Config_Config, internalMerge)
{
	zend_bool _10, _3$$3, _4$$3, _11$$5, _12$$5;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *source_param = NULL, *target_param = NULL, key, value, *_0, _9, _5$$3, _6$$4, _7$$4, _13$$5, _14$$6, _15$$6;
	zval source, target;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(source, source_param)
		ZEPHIR_Z_PARAM_ARRAY(target, target_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &source_param, &target_param);
	zephir_get_arrval(&source, source_param);
	zephir_get_arrval(&target, target_param);
	zephir_is_iterable(&target, 0, "phalcon/Config/Config.zep", 255);
	if (Z_TYPE_P(&target) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&target), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&key, _2);
			} else {
				ZVAL_LONG(&key, _1);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			_3$$3 = Z_TYPE_P(&value) == IS_ARRAY;
			if (_3$$3) {
				_3$$3 = 1 == zephir_array_isset_value(&source, &key);
			}
			_4$$3 = _3$$3;
			if (_4$$3) {
				ZEPHIR_OBS_NVAR(&_5$$3);
				zephir_array_fetch(&_5$$3, &source, &key, PH_NOISY, "phalcon/Config/Config.zep", 245);
				_4$$3 = Z_TYPE_P(&_5$$3) == IS_ARRAY;
			}
			if (_4$$3) {
				zephir_array_fetch(&_7$$4, &source, &key, PH_NOISY | PH_READONLY, "phalcon/Config/Config.zep", 247);
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "internalmerge", &_8, 39, &_7$$4, &value);
				zephir_check_call_status();
				zephir_array_update_zval(&source, &key, &_6$$4, PH_COPY | PH_SEPARATE);
				continue;
			}
			zephir_array_update_zval(&source, &key, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &target, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &target, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, &target, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &target, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &target, "current", NULL, 0);
			zephir_check_call_status();
				_11$$5 = Z_TYPE_P(&value) == IS_ARRAY;
				if (_11$$5) {
					_11$$5 = 1 == zephir_array_isset_value(&source, &key);
				}
				_12$$5 = _11$$5;
				if (_12$$5) {
					ZEPHIR_OBS_NVAR(&_13$$5);
					zephir_array_fetch(&_13$$5, &source, &key, PH_NOISY, "phalcon/Config/Config.zep", 245);
					_12$$5 = Z_TYPE_P(&_13$$5) == IS_ARRAY;
				}
				if (_12$$5) {
					zephir_array_fetch(&_15$$6, &source, &key, PH_NOISY | PH_READONLY, "phalcon/Config/Config.zep", 247);
					ZEPHIR_CALL_METHOD(&_14$$6, this_ptr, "internalmerge", &_8, 39, &_15$$6, &value);
					zephir_check_call_status();
					zephir_array_update_zval(&source, &key, &_14$$6, PH_COPY | PH_SEPARATE);
					continue;
				}
				zephir_array_update_zval(&source, &key, &value, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&source);
}

/**
 * Sets the collection data
 *
 * Array values become nested Config objects carrying the `insensitive`,
 * `strictNull` and `type` flags of this instance. The `type` guard is
 * applied to leaf values only — arrays are not validated themselves;
 * the nested Config validates its own leaves.
 *
 * @param mixed $element
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Config_Config, setData)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element = NULL, element_sub, *value, value_sub, data, key, _0, _2$$4, _3$$4, _4$$4, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(element)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &element, &value);
	ZEPHIR_SEPARATE_PARAM(element);
	if (Z_TYPE_P(value) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "validatetype", NULL, 0, value);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&data, &_0);
	zephir_cast_to_string(&_1, element);
	ZEPHIR_CPY_WRT(element, &_1);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("insensitive"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_FUNCTION(&key, "mb_strtolower", NULL, 12, element);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&key, element);
	}
	zephir_update_property_array(this_ptr, SL("lowerKeys"), &key, element);
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_config_config_ce);
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("insensitive"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("strictNull"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 41, value, &_3$$4, &_4$$4, &_5$$4);
		zephir_check_call_status();
		zephir_array_update_zval(&data, element, &_2$$4, PH_COPY | PH_SEPARATE);
	} else {
		zephir_array_update_zval(&data, element, value, PH_COPY | PH_SEPARATE);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &data);
	ZEPHIR_MM_RESTORE();
}

