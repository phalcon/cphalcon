
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

	zend_declare_class_constant_string(phalcon_config_ce, SL("DEFAULT_PATH_DELIMITER"), "." TSRMLS_CC);

	zend_class_implements(phalcon_config_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_config_ce TSRMLS_CC, 1, spl_ce_Countable);
	return SUCCESS;

}

/**
 * Phalcon\Config constructor
 */
PHP_METHOD(Phalcon_Config, __construct) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrayConfig_param = NULL, *key = NULL, *value = NULL, **_2;
	zval *arrayConfig = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arrayConfig_param);

	if (!arrayConfig_param) {
		ZEPHIR_INIT_VAR(arrayConfig);
		array_init(arrayConfig);
	} else {
	arrayConfig = arrayConfig_param;
	}


	zephir_is_iterable(arrayConfig, &_1, &_0, 0, 0, "phalcon/config.zep", 67);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", &_3, 0, key, value);
		zephir_check_call_status();
	}
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
	zval *index = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 18, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, _0);
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
	zval *path_param = NULL, *defaultValue = NULL, *delimiter = NULL, *key = NULL, *keys = NULL, *config = NULL, *_0$$3, *_2$$7 = NULL, *_3$$5 = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &path_param, &defaultValue, &delimiter);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}
	if (!delimiter) {
		ZEPHIR_CPY_WRT(delimiter, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(delimiter);
	}


	if (zephir_isset_property_zval(this_ptr, path TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property_zval(&_0$$3, this_ptr, path, PH_NOISY_CC);
		RETURN_CCTOR(_0$$3);
	}
	if (ZEPHIR_IS_EMPTY(delimiter)) {
		ZEPHIR_CALL_SELF(&delimiter, "getpathdelimiter", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CPY_WRT(config, this_ptr);
	ZEPHIR_INIT_VAR(keys);
	zephir_fast_explode(keys, delimiter, path, LONG_MAX TSRMLS_CC);
	while (1) {
		if (!(!(ZEPHIR_IS_EMPTY(keys)))) {
			break;
		}
		ZEPHIR_MAKE_REF(keys);
		ZEPHIR_CALL_FUNCTION(&key, "array_shift", &_1, 19, keys);
		ZEPHIR_UNREF(keys);
		zephir_check_call_status();
		if (!(zephir_isset_property_zval(config, key TSRMLS_CC))) {
			break;
		}
		if (ZEPHIR_IS_EMPTY(keys)) {
			ZEPHIR_OBS_NVAR(_2$$7);
			zephir_read_property_zval(&_2$$7, config, key, PH_NOISY_CC);
			RETURN_CCTOR(_2$$7);
		}
		ZEPHIR_OBS_NVAR(_3$$5);
		zephir_read_property_zval(&_3$$5, config, key, PH_NOISY_CC);
		ZEPHIR_CPY_WRT(config, _3$$5);
		if (ZEPHIR_IS_EMPTY(config)) {
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
	zval *index = NULL, *defaultValue = NULL, *_0 = NULL, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &index, &defaultValue);

	ZEPHIR_SEPARATE_PARAM(index);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 18, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, _0);
	if (zephir_isset_property_zval(this_ptr, index TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_1$$3);
		zephir_read_property_zval(&_1$$3, this_ptr, index, PH_NOISY_CC);
		RETURN_CCTOR(_1$$3);
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
	zval *index = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 18, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, _0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, this_ptr, index, PH_NOISY_CC);
	RETURN_CCTOR(_1);

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
	zval *index = NULL, *value, *_0 = NULL, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index, &value);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 18, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, _0);
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, phalcon_config_ce);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 20, value);
		zephir_check_call_status();
		zephir_update_property_zval_zval(getThis(), index, _1$$3 TSRMLS_CC);
	} else {
		zephir_update_property_zval_zval(getThis(), index, value TSRMLS_CC);
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
	zval *index = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 18, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, _0);
	zephir_update_property_zval_zval(getThis(), index, ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
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
	zval *config;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_merge", NULL, 21, config);
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

	HashTable *_2;
	HashPosition _1;
	zval *key = NULL, *value = NULL, *arrayConfig = NULL, *_0 = NULL, **_3, *_4$$5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(arrayConfig);
	array_init(arrayConfig);
	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 22, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/config.zep", 243);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if (Z_TYPE_P(value) == IS_OBJECT) {
			if ((zephir_method_exists_ex(value, SS("toarray") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&_4$$5, value, "toarray", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&arrayConfig, key, &_4$$5, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&arrayConfig, key, &value, PH_COPY | PH_SEPARATE);
			}
		} else {
			zephir_array_update_zval(&arrayConfig, key, &value, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(arrayConfig);

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

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 22, this_ptr);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Restores the state of a Phalcon\Config object
 */
PHP_METHOD(Phalcon_Config, __set_state) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	data = data_param;


	object_init_ex(return_value, phalcon_config_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 20, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the default path delimiter
 */
PHP_METHOD(Phalcon_Config, setPathDelimiter) {

	zval *delimiter_param = NULL;
	zval *delimiter = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &delimiter_param);

	if (!delimiter_param) {
		ZEPHIR_INIT_VAR(delimiter);
		ZVAL_EMPTY_STRING(delimiter);
	} else {
	if (UNEXPECTED(Z_TYPE_P(delimiter_param) != IS_STRING && Z_TYPE_P(delimiter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'delimiter' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(delimiter_param) == IS_STRING)) {
		zephir_get_strval(delimiter, delimiter_param);
	} else {
		ZEPHIR_INIT_VAR(delimiter);
		ZVAL_EMPTY_STRING(delimiter);
	}
	}


	zephir_update_static_property_ce(phalcon_config_ce, SL("_pathDelimiter"), &delimiter TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the default path delimiter
 */
PHP_METHOD(Phalcon_Config, getPathDelimiter) {

	zval *delimiter = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(delimiter);
	zephir_read_static_property_ce(&delimiter, phalcon_config_ce, SL("_pathDelimiter") TSRMLS_CC);
	if (!(zephir_is_true(delimiter))) {
		ZEPHIR_INIT_NVAR(delimiter);
		ZVAL_STRING(delimiter, ".", 1);
	}
	RETURN_CCTOR(delimiter);

}

/**
 * Helper method for merge configs (forwarding nested config instance)
 *
 * @param Config config
 * @param Config instance = null
 *
 * @return Config merged config
 */
PHP_METHOD(Phalcon_Config, _merge) {

	zend_bool _5$$5, _6$$6;
	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, *instance = NULL, *key = NULL, *value = NULL, *number = NULL, *localObject = NULL, *property = NULL, *_0 = NULL, **_3, *_8$$8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &config, &instance);

	if (!instance) {
		ZEPHIR_CPY_WRT(instance, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(instance);
	}


	if (Z_TYPE_P(instance) != IS_OBJECT) {
		ZEPHIR_CPY_WRT(instance, this_ptr);
	}
	ZEPHIR_CALL_METHOD(&number, instance, "count", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 22, config);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/config.zep", 336);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		ZEPHIR_CALL_FUNCTION(&property, "strval", &_4, 18, key);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(localObject);
		if (zephir_fetch_property_zval(&localObject, instance, property, PH_SILENT_CC)) {
			_5$$5 = Z_TYPE_P(localObject) == IS_OBJECT;
			if (_5$$5) {
				_5$$5 = Z_TYPE_P(value) == IS_OBJECT;
			}
			if (_5$$5) {
				_6$$6 = zephir_instance_of_ev(localObject, phalcon_config_ce TSRMLS_CC);
				if (_6$$6) {
					_6$$6 = zephir_instance_of_ev(value, phalcon_config_ce TSRMLS_CC);
				}
				if (_6$$6) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_merge", &_7, 21, value, localObject);
					zephir_check_call_status();
					continue;
				}
			}
		}
		if (zephir_is_numeric(key)) {
			ZEPHIR_CALL_FUNCTION(&_8$$8, "strval", &_4, 18, key);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(key, _8$$8);
			while (1) {
				ZEPHIR_CALL_METHOD(&_8$$8, instance, "offsetexists", NULL, 0, key);
				zephir_check_call_status();
				if (!(zephir_is_true(_8$$8))) {
					break;
				}
				ZEPHIR_CALL_FUNCTION(&key, "strval", &_4, 18, number);
				zephir_check_call_status();
				ZEPHIR_SEPARATE(number);
				zephir_increment(number);
			}
		}
		zephir_update_property_zval_zval(instance, key, value TSRMLS_CC);
	}
	RETVAL_ZVAL(instance, 1, 0);
	RETURN_MM();

}

