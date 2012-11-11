
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#include "kernel/object.h"
#include "kernel/file.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\DI
 *
 * Represents a service in the services container
 */


/**
 * Phalcon\DI\Service initializer
 */
PHALCON_INIT_CLASS(Phalcon_DI_Service){

	PHALCON_REGISTER_CLASS(Phalcon\\DI, Service, di_service, phalcon_di_service_method_entry, 0);

	zend_declare_property_null(phalcon_di_service_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_di_service_ce, SL("_definition"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_di_service_ce, SL("_shared"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_di_service_ce, SL("_sharedInstance"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\DI\Service
 *
 * @param string $name
 * @param mixed $definition
 * @param boolean $shared
 */
PHP_METHOD(Phalcon_DI_Service, __construct){

	zval *name, *definition, *shared = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &name, &definition, &shared) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!shared) {
		PHALCON_INIT_NVAR(shared);
		ZVAL_BOOL(shared, 0);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_name"), name TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_definition"), definition TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_shared"), shared TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the service's name
 *
 * @param string
 */
PHP_METHOD(Phalcon_DI_Service, getName){


	RETURN_MEMBER(this_ptr, "_name");
}

/**
 * Sets if the service is shared or not
 *
 * @param boolean $shared
 */
PHP_METHOD(Phalcon_DI_Service, setShared){

	zval *shared;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &shared) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_shared"), shared TSRMLS_CC);
	
}

/**
 * Check whether the service is shared or not
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_DI_Service, getShared){


	RETURN_MEMBER(this_ptr, "_shared");
}

/**
 * Set the service definition
 *
 * @param mixed $definition
 */
PHP_METHOD(Phalcon_DI_Service, setDefinition){

	zval *definition;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &definition) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_definition"), definition TSRMLS_CC);
	
}

/**
 * Returns the service definition
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_DI_Service, getDefitinion){


	RETURN_MEMBER(this_ptr, "_definition");
}

/**
 * Resolves the service
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_DI_Service, resolve){

	zval *parameters = NULL, *shared, *shared_instance;
	zval *found = NULL, *instance = NULL, *definition, *class_name;
	zval *name, *exception_message;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
	}
	
	PHALCON_INIT_VAR(shared);
	phalcon_read_property(&shared, this_ptr, SL("_shared"), PH_NOISY_CC);
	if (zend_is_true(shared)) {
		PHALCON_INIT_VAR(shared_instance);
		phalcon_read_property(&shared_instance, this_ptr, SL("_sharedInstance"), PH_NOISY_CC);
		if (Z_TYPE_P(shared_instance) != IS_NULL) {
	
			RETURN_CCTOR(shared_instance);
		}
	}
	
	PHALCON_INIT_VAR(found);
	ZVAL_BOOL(found, 1);
	
	PHALCON_INIT_VAR(instance);
	
	PHALCON_INIT_VAR(definition);
	phalcon_read_property(&definition, this_ptr, SL("_definition"), PH_NOISY_CC);
	if (Z_TYPE_P(definition) == IS_STRING) {
		if (phalcon_class_exists(definition TSRMLS_CC)) {
			if (Z_TYPE_P(parameters) == IS_ARRAY) { 
				if (phalcon_fast_count_ev(parameters TSRMLS_CC)) {
					if (phalcon_create_instance_params(instance, definition, parameters TSRMLS_CC) == FAILURE) {
						return;
					}
				} else {
					PHALCON_INIT_NVAR(instance);
					if (phalcon_create_instance(instance, definition TSRMLS_CC) == FAILURE) {
						return;
					}
				}
			} else {
				PHALCON_INIT_NVAR(instance);
				if (phalcon_create_instance(instance, definition TSRMLS_CC) == FAILURE) {
					return;
				}
			}
		} else {
			ZVAL_BOOL(found, 0);
		}
	} else {
		if (Z_TYPE_P(definition) == IS_OBJECT) {
			if (phalcon_is_instance_of(definition, SL("Closure") TSRMLS_CC)) {
				if (Z_TYPE_P(parameters) == IS_ARRAY) { 
					PHALCON_INIT_NVAR(instance);
					PHALCON_CALL_USER_FUNC_ARRAY(instance, definition, parameters);
				} else {
					PHALCON_INIT_NVAR(instance);
					PHALCON_CALL_USER_FUNC(instance, definition);
				}
			} else {
				PHALCON_CPY_WRT(instance, definition);
			}
		} else {
			if (Z_TYPE_P(definition) == IS_ARRAY) { 
				eval_int = phalcon_array_isset_string(definition, SS("className"));
				if (!eval_int) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Invalid service definition. Missing 'className' parameter");
					return;
				}
	
				PHALCON_INIT_VAR(class_name);
				phalcon_array_fetch_string(&class_name, definition, SL("className"), PH_NOISY_CC);
				if (Z_TYPE_P(parameters) == IS_ARRAY) { 
					if (phalcon_fast_count_ev(parameters TSRMLS_CC)) {
						PHALCON_INIT_NVAR(instance);
						if (phalcon_create_instance_params(instance, class_name, parameters TSRMLS_CC) == FAILURE) {
							return;
						}
					} else {
						PHALCON_INIT_NVAR(instance);
						if (phalcon_create_instance(instance, class_name TSRMLS_CC) == FAILURE) {
							return;
						}
					}
				} else {
					PHALCON_INIT_NVAR(instance);
					if (phalcon_create_instance(instance, class_name TSRMLS_CC) == FAILURE) {
						return;
					}
				}
	
	
				RETURN_CCTOR(instance);
			} else {
				ZVAL_BOOL(found, 0);
			}
		}
	}
	
	if (PHALCON_IS_FALSE(found)) {
		PHALCON_INIT_VAR(name);
		phalcon_read_property(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Service '", name, "' cannot be resolved");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
		return;
	}
	
	if (zend_is_true(shared)) {
		phalcon_update_property_zval(this_ptr, SL("_sharedInstance"), instance TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(instance);
}

