
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
#include "ext/spl/spl_iterators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Config
 *
 * Phalcon\Config is designed to simplify the access to, and the use of, configuration data within applications.
 * It provides a nested object property based user interface for accessing this configuration data within
 * application code.
 *
 *<code>
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
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Config) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Config, phalcon, config, phalcon_config_method_entry, 0);

	zend_declare_property_null(phalcon_config_ce, SL("_pathDelimiter"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zephir_declare_class_constant_string(phalcon_config_ce, SL("DEFAULT_PATH_DELIMITER"), ".");

	zend_class_implements(phalcon_config_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_config_ce TSRMLS_CC, 1, spl_ce_Countable);
	return SUCCESS;

}

/**
 * Phalcon\Config constructor
 */
PHP_METHOD(Phalcon_Config, __construct) {

	zend_string *_3;
	zend_ulong _2;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrayConfig_param = NULL, key, value, *_0, _1;
	zval arrayConfig;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrayConfig);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arrayConfig_param);

	if (!arrayConfig_param) {
		ZEPHIR_INIT_VAR(&arrayConfig);
		array_init(&arrayConfig);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&arrayConfig, arrayConfig_param);
	}


	zephir_is_iterable(&arrayConfig, 0, "phalcon/config.zep", 58);
	if (Z_TYPE_P(&arrayConfig) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&arrayConfig), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", &_4, 0, &key, &value);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &arrayConfig, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &arrayConfig, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &arrayConfig, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &arrayConfig, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", &_4, 0, &key, &value);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &arrayConfig, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Allows to check whether an attribute is defined using the array-syntax
 *
 *<code>
 * var_dump(
 *     isset($config["database"])
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Config, offsetExists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, index_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 10, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, &_0);
	RETURN_MM_BOOL(zephir_isset_property_zval(this_ptr, index TSRMLS_CC));

}

/**
 * Returns a value from current config using a dot separated path.
 *
 *<code>
 * echo $config->path("unknown.path", "default", ".");
 *</code>
 */
PHP_METHOD(Phalcon_Config, path) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *defaultValue = NULL, defaultValue_sub, *delimiter = NULL, delimiter_sub, __$null, key, keys, config, _0$$3, _2$$7, _3$$5;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&delimiter_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &path_param, &defaultValue, &delimiter);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}
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


	if (zephir_isset_property_zval(this_ptr, &path TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(&_0$$3);
		zephir_read_property_zval(&_0$$3, this_ptr, &path, PH_NOISY_CC);
		RETURN_CCTOR(&_0$$3);
	}
	if (ZEPHIR_IS_EMPTY(delimiter)) {
		ZEPHIR_CALL_SELF(delimiter, "getpathdelimiter", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CPY_WRT(&config, this_ptr);
	ZEPHIR_INIT_VAR(&keys);
	zephir_fast_explode(&keys, delimiter, &path, LONG_MAX TSRMLS_CC);
	while (1) {
		if (!(!(ZEPHIR_IS_EMPTY(&keys)))) {
			break;
		}
		ZEPHIR_MAKE_REF(&keys);
		ZEPHIR_CALL_FUNCTION(&key, "array_shift", &_1, 11, &keys);
		ZEPHIR_UNREF(&keys);
		zephir_check_call_status();
		if (!(zephir_isset_property_zval(&config, &key TSRMLS_CC))) {
			break;
		}
		if (ZEPHIR_IS_EMPTY(&keys)) {
			ZEPHIR_OBS_NVAR(&_2$$7);
			zephir_read_property_zval(&_2$$7, &config, &key, PH_NOISY_CC);
			RETURN_CCTOR(&_2$$7);
		}
		ZEPHIR_OBS_NVAR(&_3$$5);
		zephir_read_property_zval(&_3$$5, &config, &key, PH_NOISY_CC);
		ZEPHIR_CPY_WRT(&config, &_3$$5);
		if (ZEPHIR_IS_EMPTY(&config)) {
			break;
		}
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Gets an attribute from the configuration, if the attribute isn't defined returns null
 * If the value is exactly null or is not defined the default value will be used instead
 *
 *<code>
 * echo $config->get("controllersDir", "../app/controllers/");
 *</code>
 */
PHP_METHOD(Phalcon_Config, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, index_sub, *defaultValue = NULL, defaultValue_sub, __$null, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &index, &defaultValue);

	ZEPHIR_SEPARATE_PARAM(index);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 10, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, &_0);
	if (zephir_isset_property_zval(this_ptr, index TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(&_1$$3);
		zephir_read_property_zval(&_1$$3, this_ptr, index, PH_NOISY_CC);
		RETURN_CCTOR(&_1$$3);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Gets an attribute using the array-syntax
 *
 *<code>
 * print_r(
 *     $config["database"]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Config, offsetGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, index_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 10, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, &_0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property_zval(&_1, this_ptr, index, PH_NOISY_CC);
	RETURN_CCTOR(&_1);

}

/**
 * Sets an attribute using the array-syntax
 *
 *<code>
 * $config["database"] = [
 *     "type" => "Sqlite",
 * ];
 *</code>
 */
PHP_METHOD(Phalcon_Config, offsetSet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, index_sub, *value, value_sub, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index, &value);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 10, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, &_0);
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_config_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 12, value);
		zephir_check_call_status();
		zephir_update_property_zval_zval(this_ptr, index, &_1$$3 TSRMLS_CC);
	} else {
		zephir_update_property_zval_zval(this_ptr, index, value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Unsets an attribute using the array-syntax
 *
 *<code>
 * unset($config["database"]);
 *</code>
 */
PHP_METHOD(Phalcon_Config, offsetUnset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, index_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 10, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, &_0);
	zephir_update_property_zval_zval(this_ptr, index, &__$null TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Merges a configuration into the current one
 *
 *<code>
 * $appConfig = new \Phalcon\Config(
 *     [
 *         "database" => [
 *             "host" => "localhost",
 *         ],
 *     ]
 * );
 *
 * $globalConfig->merge($appConfig);
 *</code>
 */
PHP_METHOD(Phalcon_Config, merge) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *configParam, configParam_sub, config, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&configParam_sub);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &configParam);



	ZEPHIR_INIT_VAR(&_0);
	zephir_gettype(&_0, configParam TSRMLS_CC);
	do {
		if (ZEPHIR_IS_STRING(&_0, "array")) {
			ZEPHIR_INIT_VAR(&config);
			object_init_ex(&config, phalcon_config_ce);
			ZEPHIR_CALL_METHOD(NULL, &config, "__construct", NULL, 12, configParam);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&_0, "object")) {
			ZEPHIR_CPY_WRT(&config, configParam);
			break;
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "Invalid data type for merge.", "phalcon/config.zep", 216);
		return;
	} while(0);

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_merge", NULL, 13, &config);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Converts recursively the object to an array
 *
 *<code>
 * print_r(
 *     $config->toArray()
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Config, toArray) {

	zend_string *_4;
	zend_ulong _3;
	zval key, value, arrayConfig, _0, *_1, _2, _5$$5, _6$$10;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&arrayConfig);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$10);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&arrayConfig);
	array_init(&arrayConfig);
	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 14, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/config.zep", 247);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			if (Z_TYPE_P(&value) == IS_OBJECT) {
				if ((zephir_method_exists_ex(&value, SL("toarray") TSRMLS_CC) == SUCCESS)) {
					ZEPHIR_CALL_METHOD(&_5$$5, &value, "toarray", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&arrayConfig, &key, &_5$$5, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&arrayConfig, &key, &value, PH_COPY | PH_SEPARATE);
				}
			} else {
				zephir_array_update_zval(&arrayConfig, &key, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_0, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&value) == IS_OBJECT) {
					if ((zephir_method_exists_ex(&value, SL("toarray") TSRMLS_CC) == SUCCESS)) {
						ZEPHIR_CALL_METHOD(&_6$$10, &value, "toarray", NULL, 0);
						zephir_check_call_status();
						zephir_array_update_zval(&arrayConfig, &key, &_6$$10, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_zval(&arrayConfig, &key, &value, PH_COPY | PH_SEPARATE);
					}
				} else {
					zephir_array_update_zval(&arrayConfig, &key, &value, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&arrayConfig);

}

/**
 * Returns the count of properties set in the config
 *
 *<code>
 * print count($config);
 *</code>
 *
 * or
 *
 *<code>
 * print $config->count();
 *</code>
 */
PHP_METHOD(Phalcon_Config, count) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 14, this_ptr);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_fast_count_int(&_0 TSRMLS_CC));

}

/**
 * Restores the state of a Phalcon\Config object
 */
PHP_METHOD(Phalcon_Config, __set_state) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);


	object_init_ex(return_value, phalcon_config_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 12, &data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the default path delimiter
 */
PHP_METHOD(Phalcon_Config, setPathDelimiter) {

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
	if (UNEXPECTED(Z_TYPE_P(delimiter_param) != IS_STRING && Z_TYPE_P(delimiter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'delimiter' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(delimiter_param) == IS_STRING)) {
		zephir_get_strval(&delimiter, delimiter_param);
	} else {
		ZEPHIR_INIT_VAR(&delimiter);
		ZVAL_EMPTY_STRING(&delimiter);
	}
	}


	zend_update_static_property(phalcon_config_ce, ZEND_STRL("_pathDelimiter"), &delimiter);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the default path delimiter
 */
PHP_METHOD(Phalcon_Config, getPathDelimiter) {

	zval delimiter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&delimiter);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&delimiter);
	zephir_read_static_property_ce(&delimiter, phalcon_config_ce, SL("_pathDelimiter"), PH_NOISY_CC);
	if (!(zephir_is_true(&delimiter))) {
		ZEPHIR_INIT_NVAR(&delimiter);
		ZVAL_STRING(&delimiter, ".");
	}
	RETURN_CCTOR(&delimiter);

}

/**
 * Helper method for merge configs (forwarding nested config instance)
 */
PHP_METHOD(Phalcon_Config, _merge) {

	zend_bool _6$$5, _7$$6, _11$$11, _12$$12;
	zend_string *_4;
	zend_ulong _3;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, config_sub, *instance = NULL, instance_sub, __$null, key, value, number, localObject, property, _0, *_1, _2, _9$$8, _13$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&instance_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&localObject);
	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_13$$14);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &config, &instance);

	if (!instance) {
		instance = &instance_sub;
		ZEPHIR_CPY_WRT(instance, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(instance);
	}


	if (Z_TYPE_P(instance) != IS_OBJECT) {
		ZEPHIR_CPY_WRT(instance, this_ptr);
	}
	ZEPHIR_CALL_METHOD(&number, instance, "count", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 14, config);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/config.zep", 335);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_CALL_FUNCTION(&property, "strval", &_5, 10, &key);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&localObject);
			if (zephir_fetch_property_zval(&localObject, instance, &property, PH_SILENT_CC)) {
				_6$$5 = Z_TYPE_P(&localObject) == IS_OBJECT;
				if (_6$$5) {
					_6$$5 = Z_TYPE_P(&value) == IS_OBJECT;
				}
				if (_6$$5) {
					_7$$6 = zephir_instance_of_ev(&localObject, phalcon_config_ce TSRMLS_CC);
					if (_7$$6) {
						_7$$6 = zephir_instance_of_ev(&value, phalcon_config_ce TSRMLS_CC);
					}
					if (_7$$6) {
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "_merge", &_8, 13, &value, &localObject);
						zephir_check_call_status();
						continue;
					}
				}
			}
			if (zephir_is_numeric(&key)) {
				ZEPHIR_CALL_FUNCTION(&_9$$8, "strval", &_5, 10, &key);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&key, &_9$$8);
				while (1) {
					ZEPHIR_CALL_METHOD(&_9$$8, instance, "offsetexists", &_10, 0, &key);
					zephir_check_call_status();
					if (!(zephir_is_true(&_9$$8))) {
						break;
					}
					ZEPHIR_CALL_FUNCTION(&key, "strval", &_5, 10, &number);
					zephir_check_call_status();
					ZEPHIR_SEPARATE(&number);
					zephir_increment(&number);
				}
			}
			zephir_update_property_zval_zval(instance, &key, &value TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&property, "strval", &_5, 10, &key);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&localObject);
				if (zephir_fetch_property_zval(&localObject, instance, &property, PH_SILENT_CC)) {
					_11$$11 = Z_TYPE_P(&localObject) == IS_OBJECT;
					if (_11$$11) {
						_11$$11 = Z_TYPE_P(&value) == IS_OBJECT;
					}
					if (_11$$11) {
						_12$$12 = zephir_instance_of_ev(&localObject, phalcon_config_ce TSRMLS_CC);
						if (_12$$12) {
							_12$$12 = zephir_instance_of_ev(&value, phalcon_config_ce TSRMLS_CC);
						}
						if (_12$$12) {
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "_merge", &_8, 13, &value, &localObject);
							zephir_check_call_status();
							continue;
						}
					}
				}
				if (zephir_is_numeric(&key)) {
					ZEPHIR_CALL_FUNCTION(&_13$$14, "strval", &_5, 10, &key);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&key, &_13$$14);
					while (1) {
						ZEPHIR_CALL_METHOD(&_13$$14, instance, "offsetexists", &_10, 0, &key);
						zephir_check_call_status();
						if (!(zephir_is_true(&_13$$14))) {
							break;
						}
						ZEPHIR_CALL_FUNCTION(&key, "strval", &_5, 10, &number);
						zephir_check_call_status();
						ZEPHIR_SEPARATE(&number);
						zephir_increment(&number);
					}
				}
				zephir_update_property_zval_zval(instance, &key, &value TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETVAL_ZVAL(instance, 1, 0);
	RETURN_MM();

}

