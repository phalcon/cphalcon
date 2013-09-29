
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

#include "kernel/object.h"
#include "kernel/file.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/array.h"

/**
 * Phalcon\DI\Service
 *
 * Represents individually a service in the services container
 *
 *<code>
 * $service = new Phalcon\DI\Service('request', 'Phalcon\Http\Request');
 * $request = $service->resolve();
 *<code>
 *
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

	zend_class_implements(phalcon_di_service_ce TSRMLS_CC, 1, phalcon_di_serviceinterface_ce);

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

	phalcon_fetch_params(0, 2, 1, &name, &definition, &shared);
	
	if (!shared) {
		shared = PHALCON_GLOBAL(z_false);
	}
	
	phalcon_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_definition"), definition TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_shared"), shared TSRMLS_CC);
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

	phalcon_fetch_params(0, 1, 0, &shared);
	
	phalcon_update_property_this(this_ptr, SL("_shared"), shared TSRMLS_CC);
	
}

/**
 * Check whether the service is shared or not
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_DI_Service, isShared){


	RETURN_MEMBER(this_ptr, "_shared");
}

/**
 * Sets/Resets the shared instance related to the service
 *
 * @param mixed $sharedInstance
 */
PHP_METHOD(Phalcon_DI_Service, setSharedInstance){

	zval *shared_instance;

	phalcon_fetch_params(0, 1, 0, &shared_instance);
	
	phalcon_update_property_this(this_ptr, SL("_sharedInstance"), shared_instance TSRMLS_CC);
	
}

/**
 * Set the service definition
 *
 * @param mixed $definition
 */
PHP_METHOD(Phalcon_DI_Service, setDefinition){

	zval *definition;

	phalcon_fetch_params(0, 1, 0, &definition);
	
	phalcon_update_property_this(this_ptr, SL("_definition"), definition TSRMLS_CC);
	
}

/**
 * Returns the service definition
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_DI_Service, getDefinition){


	RETURN_MEMBER(this_ptr, "_definition");
}

/**
 * Resolves the service
 *
 * @param array $parameters
 * @param Phalcon\DiInterface $dependencyInjector
 * @return mixed
 */
PHP_METHOD(Phalcon_DI_Service, resolve){

	zval *parameters = NULL, *dependency_injector = NULL, *shared;
	zval *shared_instance, *found = NULL, *instance = NULL, *definition;
	zval *builder, *name, *exception_message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &parameters, &dependency_injector);
	
	if (!parameters) {
		parameters = PHALCON_GLOBAL(z_null);
	}
	
	if (!dependency_injector) {
		dependency_injector = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(shared);
	phalcon_read_property_this(&shared, this_ptr, SL("_shared"), PH_NOISY_CC);
	
	/** 
	 * Check if the service is shared
	 */
	if (zend_is_true(shared)) {
	
		shared_instance = phalcon_fetch_nproperty_this(this_ptr, SL("_sharedInstance"), PH_NOISY_CC);
		if (Z_TYPE_P(shared_instance) != IS_NULL) {
			RETURN_CTOR(shared_instance);
		}
	}
	
	found = PHALCON_GLOBAL(z_true);
	
	PHALCON_INIT_VAR(instance);
	
	definition = phalcon_fetch_nproperty_this(this_ptr, SL("_definition"), PH_NOISY_CC);
	if (Z_TYPE_P(definition) == IS_STRING) {
	
		/** 
		 * String definitions can be class names without implicit parameters
		 */
		if (phalcon_class_exists(definition, 1 TSRMLS_CC)) {
			if (Z_TYPE_P(parameters) == IS_ARRAY) { 
				if (phalcon_create_instance_params(instance, definition, parameters TSRMLS_CC) == FAILURE) {
					RETURN_MM();
				}
			} else {
				if (phalcon_create_instance(instance, definition TSRMLS_CC) == FAILURE) {
					RETURN_MM();
				}
			}
		} else {
			found = PHALCON_GLOBAL(z_false);
		}
	} else {
		/** 
		 * Object definitions can be a Closure or an already resolved instance
		 */
		if (likely(Z_TYPE_P(definition) == IS_OBJECT)) {
			if (phalcon_is_instance_of(definition, SL("Closure") TSRMLS_CC)) {
				if (Z_TYPE_P(parameters) == IS_ARRAY) { 
					PHALCON_CALL_USER_FUNC_ARRAY(instance, definition, parameters);
				} else {
					PHALCON_CALL_USER_FUNC(instance, definition);
				}
			} else {
				PHALCON_CPY_WRT(instance, definition);
			}
		} else {
			/** 
			 * Array definitions require a 'className' parameter
			 */
			if (Z_TYPE_P(definition) == IS_ARRAY) { 
				PHALCON_INIT_VAR(builder);
				object_init_ex(builder, phalcon_di_service_builder_ce);
	
				phalcon_call_method_p3(instance, builder, "build", dependency_injector, definition, parameters);
			} else {
				found = PHALCON_GLOBAL(z_false);
			}
		}
	}
	
	/** 
	 * If the service can't be built, we must throw an exception
	 */
	if (PHALCON_IS_FALSE(found)) {
		PHALCON_OBS_VAR(name);
		phalcon_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Service '", name, "' cannot be resolved");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
		return;
	}
	
	/** 
	 * Update the shared instance if the service is shared
	 */
	if (zend_is_true(shared)) {
		phalcon_update_property_this(this_ptr, SL("_sharedInstance"), instance TSRMLS_CC);
	}
	
	RETURN_CTOR(instance);
}

/**
 * Changes a parameter in the definition without resolve the service
 *
 * @param long $position
 * @param array $parameter
 * @return Phalcon\DI\Service
 */
PHP_METHOD(Phalcon_DI_Service, setParameter){

	zval *position, *parameter, *definition, *arguments = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &position, &parameter);
	
	PHALCON_OBS_VAR(definition);
	phalcon_read_property_this(&definition, this_ptr, SL("_definition"), PH_NOISY_CC);
	if (unlikely(Z_TYPE_P(definition) != IS_ARRAY)) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Definition must be an array to update its parameters");
		return;
	}
	
	if (unlikely(Z_TYPE_P(position) != IS_LONG)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Position must be integer");
		return;
	}
	
	if (unlikely(Z_TYPE_P(parameter) != IS_ARRAY)) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The parameter must be an array");
		return;
	}
	
	/** 
	 * Update the parameter
	 */
	if (phalcon_array_isset_string(definition, SS("arguments"))) {
		PHALCON_OBS_VAR(arguments);
		phalcon_array_fetch_string(&arguments, definition, SL("arguments"), PH_NOISY);
		phalcon_array_update_zval(&arguments, position, &parameter, PH_COPY | PH_SEPARATE);
	} else {
		PHALCON_INIT_NVAR(arguments);
		array_init_size(arguments, 1);
		phalcon_array_update_zval(&arguments, position, &parameter, PH_COPY | PH_SEPARATE);
	}
	
	/** 
	 * Re-update the arguments
	 */
	phalcon_array_update_string(&definition, SL("arguments"), &arguments, PH_COPY | PH_SEPARATE);
	
	/** 
	 * Re-update the definition
	 */
	phalcon_update_property_this(this_ptr, SL("_definition"), definition TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Returns a parameter in a specific position
 *
 * @param int $position
 * @return array
 */
PHP_METHOD(Phalcon_DI_Service, getParameter){

	zval *position, *definition, *arguments, *parameter;

	phalcon_fetch_params(0, 1, 0, &position);
	
	definition = phalcon_fetch_nproperty_this(this_ptr, SL("_definition"), PH_NOISY_CC);
	if (Z_TYPE_P(definition) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "Definition must be an array to obtain its parameters");
		return;
	}
	
	if (Z_TYPE_P(position) != IS_LONG) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "Position must be integer");
		return;
	}
	
	/** 
	 * Update the parameter
	 */
	if (phalcon_array_isset_string_fetch(&arguments, definition, SS("arguments"))) {
	
		if (phalcon_array_isset_fetch(&parameter, arguments, position)) {
			RETURN_ZVAL(parameter, 1, 0);
		}
	}
	
	RETURN_NULL();
}

/**
 * Restore the internal state of a service
 *
 * @param array $attributes
 * @return Phalcon\DI\Service
 */
PHP_METHOD(Phalcon_DI_Service, __set_state){

	zval *attributes, *name, *definition, *shared;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &attributes);
	
	if (phalcon_array_isset_string(attributes, SS("_name"))) {
		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_string(&name, attributes, SL("_name"), PH_NOISY);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The attribute '_name' is required");
		return;
	}
	if (phalcon_array_isset_string(attributes, SS("_definition"))) {
		PHALCON_OBS_VAR(definition);
		phalcon_array_fetch_string(&definition, attributes, SL("_definition"), PH_NOISY);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The attribute '_name' is required");
		return;
	}
	
	if (phalcon_array_isset_string(attributes, SS("_shared"))) {
		PHALCON_OBS_VAR(shared);
		phalcon_array_fetch_string(&shared, attributes, SL("_shared"), PH_NOISY);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The attribute '_shared' is required");
		return;
	}
	
	object_init_ex(return_value, phalcon_di_service_ce);
	phalcon_call_method_p3_noret(return_value, "__construct", name, definition, shared);
	
	RETURN_MM();
}

