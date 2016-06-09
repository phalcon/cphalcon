
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
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

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arrayConfig_param = NULL, key, value, *_0;
	zval arrayConfig;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&arrayConfig);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arrayConfig_param);

	if (!arrayConfig_param) {
		ZEPHIR_INIT_VAR(&arrayConfig);
		array_init(&arrayConfig);
	} else {
	ZEPHIR_OBS_VAR_ONCE(&arrayConfig);
	ZVAL_COPY(&arrayConfig, arrayConfig_param);
	}


	zephir_is_iterable(&arrayConfig, 0, "phalcon/config.zep", 62);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&arrayConfig), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", &_3, 0, &key, &value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
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
	zval *index = NULL, index_sub, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 15, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, &_0);
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
	zval *index = NULL, index_sub, *defaultValue = NULL, defaultValue_sub, __$null, _0, _1$$3;
	ZEPHIR_INIT_THIS();

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


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 15, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, &_0);
	if (zephir_isset_property_zval(this_ptr, index TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(&_1$$3);
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
 * print_r($config['database']);
 *</code>
 */
PHP_METHOD(Phalcon_Config, offsetGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, index_sub, _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 15, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, &_0);
	ZEPHIR_OBS_VAR(&_1);
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
	zval *index = NULL, index_sub, *value, value_sub, _0, _1$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index, &value);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 15, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, &_0);
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_config_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 16, value);
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
 * unset($config['database']);
 *</code>
 */
PHP_METHOD(Phalcon_Config, offsetUnset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, index_sub, __$null, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&index_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 15, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, &_0);
	zephir_update_property_zval_zval(this_ptr, index, &__$null TSRMLS_CC);
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
	zval *config, config_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&config_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_merge", NULL, 17, config);
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

	zend_string *_3;
	zend_ulong _2;
	zval key, value, arrayConfig, _0, *_1, _4$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&arrayConfig);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&arrayConfig);
	array_init(&arrayConfig);
	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 18, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/config.zep", 180);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		if (Z_TYPE_P(&value) == IS_OBJECT) {
			if ((zephir_method_exists_ex(&value, SL("toarray") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&_4$$5, &value, "toarray", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&arrayConfig, &key, &_4$$5, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&arrayConfig, &key, &value, PH_COPY | PH_SEPARATE);
			}
		} else {
			zephir_array_update_zval(&arrayConfig, &key, &value, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
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

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 18, this_ptr);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_fast_count_int(&_0 TSRMLS_CC));

}

/**
 * Restores the state of a Phalcon\Config object
 */
PHP_METHOD(Phalcon_Config, __set_state) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL;
	zval data;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	ZEPHIR_OBS_VAR_ONCE(&data);
	ZVAL_COPY(&data, data_param);


	object_init_ex(return_value, phalcon_config_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 16, &data);
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

	zend_bool _4$$5, _5$$6;
	zend_string *_3;
	zend_ulong _2;
	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *config, config_sub, *instance = NULL, instance_sub, __$null, key, value, number, localObject, _0, *_1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&instance_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&localObject);
	ZVAL_UNDEF(&_0);

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
	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 18, config);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/config.zep", 245);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		ZEPHIR_OBS_NVAR(&localObject);
		if (zephir_fetch_property_zval(&localObject, instance, &key, PH_SILENT_CC)) {
			_4$$5 = Z_TYPE_P(&localObject) == IS_OBJECT;
			if (_4$$5) {
				_4$$5 = Z_TYPE_P(&value) == IS_OBJECT;
			}
			if (_4$$5) {
				_5$$6 = zephir_instance_of_ev(&localObject, phalcon_config_ce TSRMLS_CC);
				if (_5$$6) {
					_5$$6 = zephir_instance_of_ev(&value, phalcon_config_ce TSRMLS_CC);
				}
				if (_5$$6) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_merge", &_6, 17, &value, &localObject);
					zephir_check_call_status();
					continue;
				}
			}
		}
		if (Z_TYPE_P(&key) == IS_LONG) {
			ZEPHIR_CALL_FUNCTION(&key, "strval", &_7, 15, &number);
			zephir_check_call_status();
			ZEPHIR_SEPARATE(&number);
			zephir_increment(&number);
		}
		zephir_update_property_zval_zval(instance, &key, &value TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETVAL_ZVAL(instance, 1, 0);
	RETURN_MM();

}

