
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
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
 * $config = new \Phalcon\Config(
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
ZEPHIR_INIT_CLASS(Phalcon_Config) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon, Config, phalcon, config, phalcon_collection_ce, phalcon_config_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_config_ce, SL("pathDelimiter"), ZEND_ACC_PROTECTED);

	zephir_declare_class_constant_string(phalcon_config_ce, SL("DEFAULT_PATH_DELIMITER"), ".");

	return SUCCESS;

}

/**
 * Gets the default path delimiter
 *
 * @return string
 */
PHP_METHOD(Phalcon_Config, getPathDelimiter) {

	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("pathDelimiter"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, ".");
		zephir_update_property_zval(this_ptr, SL("pathDelimiter"), &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "pathDelimiter");

}

/**
 * Merges a configuration into the current one
 *
 *```php
 * $appConfig = new \Phalcon\Config(
 *     [
 *         "database" => [
 *             "host" => "localhost",
 *         ],
 *     ]
 * );
 *
 * $globalConfig->merge($appConfig);
 *```
 */
PHP_METHOD(Phalcon_Config, merge) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *toMerge, toMerge_sub, config, result, source, target;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&toMerge_sub);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&target);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &toMerge);



	_0 = Z_TYPE_P(toMerge) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(toMerge, phalcon_config_ce);
	}
	if (Z_TYPE_P(toMerge) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&config);
		object_init_ex(&config, phalcon_config_ce);
		ZEPHIR_CALL_METHOD(NULL, &config, "__construct", NULL, 21, toMerge);
		zephir_check_call_status();
	} else if (_0) {
		ZEPHIR_CPY_WRT(&config, toMerge);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "Invalid data type for merge.", "phalcon/Config.zep", 88);
		return;
	}
	ZEPHIR_CALL_METHOD(&source, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&target, &config, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, this_ptr, "internalmerge", NULL, 22, &source, &target);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "clear", NULL, 0);
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
 */
PHP_METHOD(Phalcon_Config, path) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *defaultValue = NULL, defaultValue_sub, *delimiter = NULL, delimiter_sub, __$null, config, key, keys, _0, _2$$5, _3$$5;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&delimiter_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &path_param, &defaultValue, &delimiter);

	zephir_get_strval(&path, path_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!delimiter) {
		delimiter = &delimiter_sub;
		ZEPHIR_CPY_WRT(delimiter, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(delimiter);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &path);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &path);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (EXPECTED(ZEPHIR_IS_EMPTY(delimiter))) {
		ZEPHIR_CALL_METHOD(delimiter, this_ptr, "getpathdelimiter", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&config);
	if (zephir_clone(&config, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&keys);
	zephir_fast_explode(&keys, delimiter, &path, LONG_MAX);
	while (1) {
		if (!(!(ZEPHIR_IS_EMPTY(&keys)))) {
			break;
		}
		ZEPHIR_MAKE_REF(&keys);
		ZEPHIR_CALL_FUNCTION(&key, "array_shift", &_1, 23, &keys);
		ZEPHIR_UNREF(&keys);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$5, &config, "has", NULL, 0, &key);
		zephir_check_call_status();
		if (!(zephir_is_true(&_2$$5))) {
			break;
		}
		if (ZEPHIR_IS_EMPTY(&keys)) {
			ZEPHIR_RETURN_CALL_METHOD(&config, "get", NULL, 0, &key);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_CALL_METHOD(&_3$$5, &config, "get", NULL, 0, &key);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&config, &_3$$5);
		if (ZEPHIR_IS_EMPTY(&config)) {
			break;
		}
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Sets the default path delimiter
 */
PHP_METHOD(Phalcon_Config, setPathDelimiter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *delimiter_param = NULL;
	zval delimiter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&delimiter);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &delimiter_param);

	if (!delimiter_param) {
		ZEPHIR_INIT_VAR(&delimiter);
		ZVAL_STRING(&delimiter, "");
	} else {
		zephir_get_strval(&delimiter, delimiter_param);
	}


	zephir_update_property_zval(this_ptr, SL("pathDelimiter"), &delimiter);
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
 */
PHP_METHOD(Phalcon_Config, toArray) {

	zend_bool _5$$3, _7$$5;
	zend_string *_4;
	zend_ulong _3;
	zval results;
	zval data, key, value, *_1, _2, _6$$4, _8$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&results);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&results);
	array_init(&results);
	ZEPHIR_CALL_PARENT(&data, phalcon_config_ce, getThis(), "toarray", &_0, 0);
	zephir_check_call_status();
	zephir_is_iterable(&data, 0, "phalcon/Config.zep", 178);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			_5$$3 = Z_TYPE_P(&value) == IS_OBJECT;
			if (_5$$3) {
				_5$$3 = (zephir_method_exists_ex(&value, SL("toarray")) == SUCCESS);
			}
			if (_5$$3) {
				ZEPHIR_CALL_METHOD(&_6$$4, &value, "toarray", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&value, &_6$$4);
			}
			zephir_array_update_zval(&results, &key, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				_7$$5 = Z_TYPE_P(&value) == IS_OBJECT;
				if (_7$$5) {
					_7$$5 = (zephir_method_exists_ex(&value, SL("toarray")) == SUCCESS);
				}
				if (_7$$5) {
					ZEPHIR_CALL_METHOD(&_8$$6, &value, "toarray", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&value, &_8$$6);
				}
				zephir_array_update_zval(&results, &key, &value, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&results);

}

/**
 * Performs a merge recursively
 */
PHP_METHOD(Phalcon_Config, internalMerge) {

	zend_bool _4$$3, _5$$3, _10$$7, _11$$7;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *source_param = NULL, *target_param = NULL, key, value, *_0, _1, _6$$3, _7$$4, _8$$4, _12$$7, _13$$8, _14$$8;
	zval source, target;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &source_param, &target_param);

	zephir_get_arrval(&source, source_param);
	zephir_get_arrval(&target, target_param);


	zephir_is_iterable(&target, 0, "phalcon/Config.zep", 198);
	if (Z_TYPE_P(&target) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&target), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			_4$$3 = Z_TYPE_P(&value) == IS_ARRAY;
			if (_4$$3) {
				_4$$3 = zephir_array_isset(&source, &key);
			}
			_5$$3 = _4$$3;
			if (_5$$3) {
				ZEPHIR_OBS_NVAR(&_6$$3);
				zephir_array_fetch(&_6$$3, &source, &key, PH_NOISY, "phalcon/Config.zep", 189);
				_5$$3 = Z_TYPE_P(&_6$$3) == IS_ARRAY;
			}
			if (_5$$3) {
				zephir_array_fetch(&_8$$4, &source, &key, PH_NOISY | PH_READONLY, "phalcon/Config.zep", 190);
				ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "internalmerge", &_9, 22, &_8$$4, &value);
				zephir_check_call_status();
				zephir_array_update_zval(&source, &key, &_7$$4, PH_COPY | PH_SEPARATE);
			} else if (Z_TYPE_P(&key) == IS_LONG) {
				zephir_array_append(&source, &value, PH_SEPARATE, "phalcon/Config.zep", 192);
			} else {
				zephir_array_update_zval(&source, &key, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &target, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &target, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &target, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &target, "current", NULL, 0);
			zephir_check_call_status();
				_10$$7 = Z_TYPE_P(&value) == IS_ARRAY;
				if (_10$$7) {
					_10$$7 = zephir_array_isset(&source, &key);
				}
				_11$$7 = _10$$7;
				if (_11$$7) {
					ZEPHIR_OBS_NVAR(&_12$$7);
					zephir_array_fetch(&_12$$7, &source, &key, PH_NOISY, "phalcon/Config.zep", 189);
					_11$$7 = Z_TYPE_P(&_12$$7) == IS_ARRAY;
				}
				if (_11$$7) {
					zephir_array_fetch(&_14$$8, &source, &key, PH_NOISY | PH_READONLY, "phalcon/Config.zep", 190);
					ZEPHIR_CALL_METHOD(&_13$$8, this_ptr, "internalmerge", &_9, 22, &_14$$8, &value);
					zephir_check_call_status();
					zephir_array_update_zval(&source, &key, &_13$$8, PH_COPY | PH_SEPARATE);
				} else if (Z_TYPE_P(&key) == IS_LONG) {
					zephir_array_append(&source, &value, PH_SEPARATE, "phalcon/Config.zep", 192);
				} else {
					zephir_array_update_zval(&source, &key, &value, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &target, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&source);

}

/**
 * Sets the collection data
 */
PHP_METHOD(Phalcon_Config, setData) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element = NULL, element_sub, *value, value_sub, data, key, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element, &value);

	ZEPHIR_SEPARATE_PARAM(element);


	zephir_get_strval(&_0, element);
	ZEPHIR_CPY_WRT(element, &_0);
	zephir_read_property(&_1, this_ptr, SL("insensitive"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_CALL_FUNCTION(&key, "mb_strtolower", NULL, 24, element);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&key, element);
	}
	zephir_update_property_array(this_ptr, SL("lowerKeys"), &key, element);
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&data);
		object_init_ex(&data, phalcon_config_ce);
		ZEPHIR_CALL_METHOD(NULL, &data, "__construct", NULL, 21, value);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&data, value);
	}
	zephir_update_property_array(this_ptr, SL("data"), element, &data);
	ZEPHIR_MM_RESTORE();

}

