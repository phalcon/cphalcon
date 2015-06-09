
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
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * Phalcon\Config
 *
 * Phalcon\Config is designed to simplify the access to, and the use of, configuration data within applications.
 * It provides a nested object property based user interface for accessing this configuration data within
 * application code.
 *
 *<code>
 *	$config = new \Phalcon\Config(array(
 *		"database" => array(
 *			"adapter" => "Mysql",
 *			"host" => "localhost",
 *			"username" => "scott",
 *			"password" => "cheetah",
 *			"dbname" => "test_db"
 *		),
 *		"phalcon" => array(
 *			"controllersDir" => "../app/controllers/",
 *			"modelsDir" => "../app/models/",
 *			"viewsDir" => "../app/views/"
 *		)
 * ));
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Config) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Config, phalcon, config, phalcon_config_method_entry, 0);

	zend_class_implements(phalcon_config_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_config_ce TSRMLS_CC, 1, spl_ce_Countable);
	return SUCCESS;

}

/**
 * Phalcon\Config constructor
 */
PHP_METHOD(Phalcon_Config, __construct) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
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


	zephir_is_iterable(arrayConfig, &_1, &_0, 0, 0, "phalcon/config.zep", 62);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
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
 * var_dump(isset($config['database']));
 *</code>
 */
PHP_METHOD(Phalcon_Config, offsetExists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 57, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, _0);
	RETURN_MM_BOOL(zephir_isset_property_zval(this_ptr, index TSRMLS_CC));

}

/**
 * Gets an attribute from the configuration, if the attribute isn't defined returns null
 * If the value is exactly null or is not defined the default value will be used instead
 *
 *<code>
 * echo $config->get('controllersDir', '../app/controllers/');
 *</code>
 */
PHP_METHOD(Phalcon_Config, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, *defaultValue = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &index, &defaultValue);

	ZEPHIR_SEPARATE_PARAM(index);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 57, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, _0);
	if (zephir_isset_property_zval(this_ptr, index TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_zval(&_1, this_ptr, index, PH_NOISY_CC);
		RETURN_CCTOR(_1);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Gets an attribute using the array-syntax
 *
 *<code>
 * print_r($config['database']);
 *</code>
 */
PHP_METHOD(Phalcon_Config, offsetGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 57, index);
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
 * $config['database'] = array('type' => 'Sqlite');
 *</code>
 */
PHP_METHOD(Phalcon_Config, offsetSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, *value, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index, &value);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 57, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, _0);
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_config_ce);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 58, value);
		zephir_check_call_status();
		zephir_update_property_zval_zval(this_ptr, index, _1 TSRMLS_CC);
	} else {
		zephir_update_property_zval_zval(this_ptr, index, value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Unsets an attribute using the array-syntax
 *
 *<code>
 * unset($config['database']);
 *</code>
 */
PHP_METHOD(Phalcon_Config, offsetUnset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 57, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, _0);
	zephir_update_property_zval_zval(this_ptr, index, ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Merges a configuration into the current one
 *
 *<code>
 * $appConfig = new \Phalcon\Config(array('database' => array('host' => 'localhost')));
 * $globalConfig->merge($config2);
 *</code>
 */
PHP_METHOD(Phalcon_Config, merge) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *config;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_merge", NULL, 59, config);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Converts recursively the object to an array
 *
 *<code>
 *	print_r($config->toArray());
 *</code>
 */
PHP_METHOD(Phalcon_Config, toArray) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *value = NULL, *arrayConfig, *_0 = NULL, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(arrayConfig);
	array_init(arrayConfig);
	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 60, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/config.zep", 180);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if (Z_TYPE_P(value) == IS_OBJECT) {
			if ((zephir_method_exists_ex(value, SS("toarray") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&_4, value, "toarray", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&arrayConfig, key, &_4, PH_COPY | PH_SEPARATE);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 60, this_ptr);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Restores the state of a Phalcon\Config object
 */
PHP_METHOD(Phalcon_Config, __set_state) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	data = data_param;



	object_init_ex(return_value, phalcon_config_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 58, data);
	zephir_check_call_status();
	RETURN_MM();

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

	zephir_fcall_cache_entry *_8 = NULL, *_9 = NULL;
	zend_bool _4, _5;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *config, *instance = NULL, *key = NULL, *value = NULL, *number = NULL, *_0 = NULL, **_3, *_6 = NULL, *_7 = NULL;

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
	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 60, config);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/config.zep", 239);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		_4 = zephir_isset_property_zval(instance, key TSRMLS_CC);
		if (_4) {
			_4 = Z_TYPE_P(value) == IS_OBJECT;
		}
		_5 = _4;
		if (_5) {
			ZEPHIR_OBS_NVAR(_6);
			zephir_read_property_zval(&_6, instance, key, PH_NOISY_CC);
			_5 = Z_TYPE_P(_6) == IS_OBJECT;
		}
		if (_5) {
			ZEPHIR_OBS_NVAR(_7);
			zephir_read_property_zval(&_7, instance, key, PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_merge", &_8, 59, value, _7);
			zephir_check_call_status();
		} else {
			if (Z_TYPE_P(key) == IS_LONG) {
				ZEPHIR_CALL_FUNCTION(&key, "strval", &_9, 57, number);
				zephir_check_call_status();
				ZEPHIR_SEPARATE(number);
				zephir_increment(number);
			}
			zephir_update_property_zval_zval(instance, key, value TSRMLS_CC);
		}
	}
	RETVAL_ZVAL(instance, 1, 0);
	RETURN_MM();

}

