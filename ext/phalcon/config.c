
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
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Config
 *
 * Phalcon\Config is designed to simplify the access to, and the use of, configuration data within applications.
 * It provides a nested object property based user interface for accessing this configuration data within
 * application code.
 *
 *<code>
 *	$config = new Phalcon\Config(array(
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

	return SUCCESS;

}

/**
 * Phalcon\Config constructor
 *
 * @param	array arrayConfig
 */
PHP_METHOD(Phalcon_Config, __construct) {

	zend_function *_7 = NULL;
	HashTable *_1, *_4;
	HashPosition _0, _3;
	zend_bool hasNumericKey;
	zval *arrayConfig = NULL, *key = NULL, *value = NULL, *subkey = NULL, *subvalue = NULL, **_2, **_5, *_6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arrayConfig);

	if (!arrayConfig) {
		arrayConfig = ZEPHIR_GLOBAL(global_null);
	}


	if ((Z_TYPE_P(arrayConfig) != IS_ARRAY)) {
		if ((Z_TYPE_P(arrayConfig) != IS_NULL)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_config_exception_ce, "The configuration must be an Array");
			return;
		} else {
			RETURN_MM_NULL();
		}
	}
	zephir_is_iterable(arrayConfig, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if ((Z_TYPE_P(key) != IS_STRING)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_config_exception_ce, "Only string keys are allowed as configuration properties");
			return;
		}
		if ((Z_TYPE_P(value) == IS_ARRAY)) {
			hasNumericKey = 0;
			zephir_is_iterable(value, &_4, &_3, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
				; zend_hash_move_forward_ex(_4, &_3)
			) {
				ZEPHIR_GET_HMKEY(subkey, _4, _3);
				ZEPHIR_GET_HVALUE(subvalue, _5);
				if ((Z_TYPE_P(subkey) == IS_LONG)) {
					hasNumericKey = 1;
					break;
				}
			}
			if (hasNumericKey) {
				zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
			} else {
				ZEPHIR_INIT_LNVAR(_6);
				object_init_ex(_6, phalcon_config_ce);
				zephir_call_method_p1_cache_noret(_6, "__construct", &_7, value);
				zephir_update_property_zval_zval(this_ptr, key, _6 TSRMLS_CC);
			}
		} else {
			zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Allows to check whether an attribute is defined using the array-syntax
 *
 *<code>
 * var_dump(isset($config['database']));
 *</code>
 *
 * @param string index
 * @return boolean
 */
PHP_METHOD(Phalcon_Config, offsetExists) {

	zval *index_param = NULL;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	if (Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(index_param) == IS_STRING) {
		index = index_param;
	} else {
		ZEPHIR_INIT_VAR(index);
		ZVAL_EMPTY_STRING(index);
	}


	RETURN_MM_BOOL(0 == 0);

}

/**
 * Gets an attribute from the configuration, if the attribute isn't defined returns null
 * If the value is exactly null or is not defined the default value will be used instead
 *
 *<code>
 * echo $config->get('controllersDir', '../app/controllers/');
 *</code>
 *
 * @param string index
 * @param mixed defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Config, get) {

	zval *index, *defaultValue = NULL;

	zephir_fetch_params(0, 1, 1, &index, &defaultValue);

	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}



}

/**
 * Gets an attribute using the array-syntax
 *
 *<code>
 * print_r($config['database']);
 *</code>
 *
 * @param string index
 * @return string
 */
PHP_METHOD(Phalcon_Config, offsetGet) {

	zval *index_param = NULL, *_0;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	if (Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(index_param) == IS_STRING) {
		index = index_param;
	} else {
		ZEPHIR_INIT_VAR(index);
		ZVAL_EMPTY_STRING(index);
	}


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_zval(&_0, this_ptr, index, PH_NOISY_CC);
	RETURN_CCTOR(_0);

}

/**
 * Sets an attribute using the array-syntax
 *
 *<code>
 * $config['database'] = array('type' => 'Sqlite');
 *</code>
 *
 * @param string $index
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Config, offsetSet) {

	zval *index, *value;

	zephir_fetch_params(0, 2, 0, &index, &value);




}

/**
 * Unsets an attribute using the array-syntax
 *
 *<code>
 * unset($config['database']);
 *</code>
 *
 * @param string index
 */
PHP_METHOD(Phalcon_Config, offsetUnset) {

	zval *index;

	zephir_fetch_params(0, 1, 0, &index);



	RETURN_BOOL(1);

}

/**
 * Merges a configuration into the current one
 *
 *<code>
 *	$appConfig = new Phalcon\Config(array('database' => array('host' => 'localhost')));
 *	$globalConfig->merge($config2);
 *</code>
 *
 * @param Phalcon\Config $config
 */
PHP_METHOD(Phalcon_Config, merge) {

	zval *config;

	zephir_fetch_params(0, 1, 0, &config);




}

/**
 * Converts recursively the object to an array
 *
 *<code>
 *	print_r($config->toArray());
 *</code>
 *
 * @return array
 */
PHP_METHOD(Phalcon_Config, toArray) {

	HashTable *_2;
	HashPosition _1;
	zval *key = NULL, *value = NULL, *arrayConfig, *_0, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(arrayConfig);
	array_init(arrayConfig);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "get_object_vars", this_ptr);
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if ((Z_TYPE_P(value) == IS_OBJECT)) {
			if ((zephir_method_exists_ex(value, SS("toarray") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_INIT_NVAR(_4);
				zephir_call_method(_4, value, "toarray");
				zephir_array_update_zval(&arrayConfig, key, &_4, PH_COPY | PH_SEPARATE);
			}
		}
	}
	RETURN_CCTOR(arrayConfig);

}

/**
 * Restores the state of a Phalcon\Config object
 *
 * @param array data
 * @return Phalcon\Config
 */
PHP_METHOD(Phalcon_Config, __set_state) {

	zval *data;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	object_init_ex(return_value, phalcon_config_ce);
	zephir_call_method_p1_noret(return_value, "__construct", data);
	RETURN_MM();

}

