
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"

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


/**
 * Phalcon\Config initializer
 */
PHALCON_INIT_CLASS(Phalcon_Config){

	PHALCON_REGISTER_CLASS(Phalcon, Config, config, phalcon_config_method_entry, 0);

	zend_class_implements(phalcon_config_ce TSRMLS_CC, 1, zend_ce_arrayaccess);

	return SUCCESS;
}

/**
 * Phalcon\Config constructor
 *
 * @param array $arrayConfig
 */
PHP_METHOD(Phalcon_Config, __construct){

	zval *array_config = NULL, *value = NULL, *key = NULL, *config_value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &array_config);
	
	if (!array_config) {
		PHALCON_INIT_VAR(array_config);
	}
	
	/** 
	 * Throw exceptions if bad parameters are passed
	 */
	if (Z_TYPE_P(array_config) != IS_ARRAY) { 
		if (Z_TYPE_P(array_config) != IS_NULL) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_config_exception_ce, "The configuration must be an Array");
			return;
		} else {
			RETURN_MM_NULL();
		}
	}
	
	phalcon_is_iterable(array_config, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);
	
		/** 
		 * Phalcon\Config does not support numeric keys as properties
		 */
		if (Z_TYPE_P(key) != IS_STRING) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_config_exception_ce, "Only string keys are allowed as configuration properties");
			return;
		}
		if (Z_TYPE_P(value) == IS_ARRAY) { 
	
			/** 
			 * Check if sub-arrays contains numeric keys
			 */
			if (!phalcon_has_numeric_keys(value)) {
				PHALCON_INIT_NVAR(config_value);
				object_init_ex(config_value, phalcon_config_ce);
				phalcon_call_method_p1_noret(config_value, "__construct", value);
	
				phalcon_update_property_zval_zval(this_ptr, key, config_value TSRMLS_CC);
			} else {
				phalcon_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
			}
		} else {
			/** 
			 * Assign normal keys as properties
			 */
			phalcon_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	
	PHALCON_MM_RESTORE();
}

/**
 * Allows to check whether an attribute is defined using the array-syntax
 *
 *<code>
 * var_dump(isset($config['database']));
 *</code>
 *
 * @param string $index
 * @return boolean
 */
PHP_METHOD(Phalcon_Config, offsetExists){

	zval *index;

	phalcon_fetch_params(0, 1, 0, &index);
	
	if (phalcon_isset_property_zval(this_ptr, index TSRMLS_CC)) {
		RETURN_TRUE;
	}
	RETURN_FALSE;
}

/**
 * Gets an attribute from the configuration, if the attribute isn't defined returns null
 * If the value is exactly null or is not defined the default value will be used instead
 *
 *<code>
 * echo $config->get('controllersDir', '../app/controllers/');
 *</code>
 *
 * @param string $index
 * @param mixed $defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Config, get){

	zval *index, *default_value = NULL, *value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &index, &default_value);
	
	if (!default_value) {
		PHALCON_INIT_VAR(default_value);
	}
	
	if (phalcon_isset_property_zval(this_ptr, index TSRMLS_CC)) {
	
		PHALCON_OBS_VAR(value);
		phalcon_read_property_zval(&value, this_ptr, index, PH_NOISY_CC);
		if (PHALCON_IS_NOT_EMPTY(value)) {
			RETURN_CCTOR(value);
		}
	}
	
	RETURN_CCTOR(default_value);
}

/**
 * Gets an attribute using the array-syntax
 *
 *<code>
 * print_r($config['database']);
 *</code>
 *
 * @param string $index
 * @return string
 */
PHP_METHOD(Phalcon_Config, offsetGet){

	zval *index, *value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &index);
	
	PHALCON_OBS_VAR(value);
	phalcon_read_property_zval(&value, this_ptr, index, PH_NOISY_CC);
	RETURN_CCTOR(value);
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
PHP_METHOD(Phalcon_Config, offsetSet){

	zval *index, *value, *array_value = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &index, &value);
	
	if (Z_TYPE_P(index) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_config_exception_ce, "Index key must be string");
		return;
	}
	if (Z_TYPE_P(value) == IS_ARRAY) { 
		PHALCON_INIT_VAR(array_value);
		object_init_ex(array_value, phalcon_config_ce);
		phalcon_call_method_p1_noret(array_value, "__construct", value);
	
	} else {
		PHALCON_CPY_WRT(array_value, value);
	}
	
	phalcon_update_property_zval_zval(this_ptr, index, array_value TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Unsets an attribute using the array-syntax
 *
 *<code>
 * unset($config['database']);
 *</code>
 *
 * @param string $index
 */
PHP_METHOD(Phalcon_Config, offsetUnset){

	zval *index;

	phalcon_fetch_params(0, 1, 0, &index);
#if PHP_VERSION_ID < 50400
	Z_OBJ_HANDLER_P(getThis(), unset_property)(getThis(), index TSRMLS_CC);
#else
	Z_OBJ_HANDLER_P(getThis(), unset_property)(getThis(), index, 0 TSRMLS_CC);
#endif
	
	RETURN_TRUE;
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
PHP_METHOD(Phalcon_Config, merge){

	zval *config, *array_config, *value = NULL, *key = NULL, *active_value = NULL;
	zval *other_array = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &config);
	
	if (Z_TYPE_P(config) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_config_exception_ce, "Configuration must be an Object");
		return;
	}
	
	PHALCON_INIT_VAR(array_config);
	phalcon_call_func_p1(array_config, "get_object_vars", config);
	
	phalcon_is_iterable(array_config, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);
	
		if (phalcon_isset_property_zval(this_ptr, key TSRMLS_CC)) {
	
			/** 
			 * The key is already defined in the object, we have to merge it
			 */
			PHALCON_OBS_NVAR(active_value);
			phalcon_read_property_zval(&active_value, this_ptr, key, PH_NOISY_CC);

			if (Z_TYPE_P(value) == IS_OBJECT && Z_TYPE_P(active_value) == IS_OBJECT) {
				if (phalcon_method_exists_ex(active_value, SS("merge") TSRMLS_CC) == SUCCESS) { /* Path AAA in the test */
					phalcon_call_method_p1_noret(active_value, "merge", value);
				}
				else { /* Path AAB in the test */
					phalcon_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
				}
			}
			else if (Z_TYPE_P(value) == IS_OBJECT && Z_TYPE_P(active_value) == IS_ARRAY) { /* Path AB in the test */
				PHALCON_INIT_NVAR(other_array);
				phalcon_call_func_p1(other_array, "get_object_vars", value);
				phalcon_array_merge_recursive_n(&active_value, other_array);
				phalcon_update_property_zval_zval(this_ptr, key, active_value TSRMLS_CC);
			}
			else if (Z_TYPE_P(value) == IS_ARRAY && Z_TYPE_P(active_value) == IS_OBJECT) { /* Path AC in the test */
				PHALCON_INIT_NVAR(other_array);
				phalcon_call_func_p1(other_array, "get_object_vars", active_value);
				phalcon_array_merge_recursive_n(&other_array, value);
				phalcon_update_property_zval_zval(this_ptr, key, other_array TSRMLS_CC);
			}
			else if (Z_TYPE_P(value) == IS_ARRAY && Z_TYPE_P(active_value) == IS_ARRAY) { /* Path AD in the test */
				phalcon_array_merge_recursive_n(&active_value, value);
				phalcon_update_property_zval_zval(this_ptr, key, active_value TSRMLS_CC);
			}
			else { /* Path AE in the test */
				phalcon_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
			}
		}
		else { /* Path B in the test */
			/**
			 * The key is not defined in the object, add it
			 */
			phalcon_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	
	PHALCON_MM_RESTORE();
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
PHP_METHOD(Phalcon_Config, toArray){

	zval *array_config, *value = NULL, *key = NULL, *array_value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(array_config);
	phalcon_call_func_p1(array_config, "get_object_vars", this_ptr);
	
	phalcon_is_iterable(array_config, &ah0, &hp0, 1, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);
	
		if (Z_TYPE_P(value) == IS_OBJECT) {
			if (phalcon_method_exists_ex(value, SS("toarray") TSRMLS_CC) == SUCCESS) {
				PHALCON_INIT_NVAR(array_value);
				phalcon_call_method(array_value, value, "toarray");
				phalcon_array_update_zval(&array_config, key, &array_value, PH_COPY | PH_SEPARATE);
			}
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	zend_hash_destroy(ah0);
	efree(ah0);
	
	RETURN_CCTOR(array_config);
}

/**
 * Restores the state of a Phalcon\Config object
 *
 * @param array $data
 * @return Phalcon\Config
 */
PHP_METHOD(Phalcon_Config, __set_state){

	zval *data, *config;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &data);
	
	PHALCON_INIT_VAR(config);
	object_init_ex(config, phalcon_config_ce);
	phalcon_call_method_p1_noret(config, "__construct", data);
	
	RETURN_CTOR(config);
}
