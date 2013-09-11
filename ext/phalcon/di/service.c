
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/array.h"


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
/**
 * Phalcon\DI\Service
 *
 * Represents individually a service in the services container
 *
 *<code>
 * $service = new Phalcon\DI\Service('request', 'Phalcon\Http\Request');
 * $request = service->resolve();
 *<code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_DI_Service) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\DI, Service, phalcon, di_service, phalcon_di_service_method_entry, 0);

	zend_declare_property_null(phalcon_di_service_ce, SL("_name"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_di_service_ce, SL("_definition"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_di_service_ce, SL("_shared"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_di_service_ce, SL("_sharedInstance"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\DI\Service
 *
 * @param string name
 * @param mixed definition
 * @param boolean shared
 */
PHP_METHOD(Phalcon_DI_Service, __construct) {

	zend_bool shared;
	zval *name_param = NULL, *definition, *shared_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &definition, &shared_param);

		zephir_get_strval(name, name_param);
	if (!shared_param) {
		shared = 0;
	} else {
		shared = zephir_get_boolval(shared_param);
	}


	zephir_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_definition"), definition TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, shared);
	zephir_update_property_this(this_ptr, SL("_shared"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the service's name
 *
 * @param string
 */
PHP_METHOD(Phalcon_DI_Service, getName) {


	RETURN_MEMBER(this_ptr, "_name");

}

/**
 * Sets if the service is shared or not
 *
 * @param boolean shared
 */
PHP_METHOD(Phalcon_DI_Service, setShared) {

	zval *shared;

	zephir_fetch_params(0, 1, 0, &shared);



	zephir_update_property_this(this_ptr, SL("_shared"), shared TSRMLS_CC);

}

/**
 * Check whether the service is shared or not
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_DI_Service, isShared) {


	RETURN_MEMBER(this_ptr, "_shared");

}

/**
 * Sets/Resets the shared instance related to the service
 *
 * @param mixed sharedInstance
 */
PHP_METHOD(Phalcon_DI_Service, setSharedInstance) {

	zval *sharedInstance;

	zephir_fetch_params(0, 1, 0, &sharedInstance);



	zephir_update_property_this(this_ptr, SL("_sharedInstance"), sharedInstance TSRMLS_CC);

}

/**
 * Set the service definition
 *
 * @param mixed definition
 */
PHP_METHOD(Phalcon_DI_Service, setDefinition) {

	zval *definition;

	zephir_fetch_params(0, 1, 0, &definition);



	zephir_update_property_this(this_ptr, SL("_definition"), definition TSRMLS_CC);

}

/**
 * Returns the service definition
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_DI_Service, getDefinition) {


	RETURN_MEMBER(this_ptr, "_definition");

}

/**
 * Resolves the service
 *
 * @param array parameters
 * @param Phalcon\DiInterface dependencyInjector
 * @return mixed
 */
PHP_METHOD(Phalcon_DI_Service, resolve) {

	zend_bool found;
	zval *parameters = NULL, *dependencyInjector = NULL, *shared, *definition, *sharedInstance, *instance = NULL, *builder, *_0 = NULL, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &parameters, &dependencyInjector);

	if (!parameters) {
		ZEPHIR_INIT_VAR(parameters);
	}
	if (!dependencyInjector) {
		ZEPHIR_INIT_VAR(dependencyInjector);
	}


	ZEPHIR_OBS_VAR(shared);
	zephir_read_property_this(&shared, this_ptr, SL("_shared"), PH_NOISY_CC);
	if (zend_is_true(shared)) {
		ZEPHIR_OBS_VAR(sharedInstance);
		zephir_read_property_this(&sharedInstance, this_ptr, SL("_sharedInstance"), PH_NOISY_CC);
		if ((Z_TYPE_P(sharedInstance) != IS_NULL)) {
			RETURN_CCTOR(sharedInstance);
		}
	}
	found = 1;
	ZEPHIR_INIT_VAR(instance);
	ZVAL_NULL(instance);
	ZEPHIR_OBS_VAR(definition);
	zephir_read_property_this(&definition, this_ptr, SL("_definition"), PH_NOISY_CC);
	if (Z_TYPE_P(definition) == IS_STRING) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "class_exists", definition);
		if (zend_is_true(_0)) {
			if (Z_TYPE_P(parameters) == IS_ARRAY) {
				ZEPHIR_INIT_BNVAR(instance);
				if (zephir_fast_count_int(parameters TSRMLS_CC)) {
					zephir_call_func_p2(instance, "create_instance_params", definition, parameters);
				} else {
					zephir_call_func_p1(instance, "create_instance", definition);
				}
			} else {
				ZEPHIR_INIT_BNVAR(instance);
				zephir_call_func_p1(instance, "create_instance", definition);
			}
		} else {
			found = 0;
		}
	} else {
		if (Z_TYPE_P(definition) == IS_OBJECT) {
			if (0) {
				ZEPHIR_INIT_BNVAR(instance);
				if (Z_TYPE_P(parameters) == IS_ARRAY) {
					zephir_call_func_p2(instance, "call_user_func_array", definition, parameters);
				} else {
					zephir_call_func_p1(instance, "call_user_func", definition);
				}
			} else {
				ZEPHIR_CPY_WRT(instance, definition);
			}
		} else {
			if (Z_TYPE_P(definition) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(builder);
				object_init_ex(builder, phalcon_di_service_builder_ce);
				ZEPHIR_INIT_BNVAR(instance);
				zephir_call_method_p3(instance, builder, "build", dependencyInjector, definition, parameters);
			} else {
				found = 0;
			}
		}
	}
	if ((found == 0)) {
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, phalcon_di_exception_ce);
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_this(&_1, this_ptr, SL("_name"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SV(_2, "Service '", _1);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_VS(_3, _2, "' cannot be resolved");
		zephir_call_method_p1_noret(_0, "__construct", _3);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zend_is_true(shared)) {
		zephir_update_property_this(this_ptr, SL("_sharedInstance"), instance TSRMLS_CC);
	}
	RETURN_CCTOR(instance);

}

/**
 * Changes a parameter in the definition without resolve the service
 *
 * @param long position
 * @param array parameter
 * @return Phalcon\DI\Service
 */
PHP_METHOD(Phalcon_DI_Service, setParameter) {

	zval *position_param = NULL, *parameter, *definition, *arguments;
	int position;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &position_param, &parameter);

		position = zephir_get_intval(position_param);


	ZEPHIR_OBS_VAR(definition);
	zephir_read_property_this(&definition, this_ptr, SL("_definition"), PH_NOISY_CC);
	if (Z_TYPE_P(definition) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Definition must be an array to update its parameters");
		return;
	}
	if (Z_TYPE_P(parameter) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The parameter must be an array");
		return;
	}
	ZEPHIR_OBS_VAR(arguments);
	if (zephir_array_isset_string_fetch(&arguments, definition, SS("arguments"))) {
		zephir_array_update_long(&arguments, position, &parameter, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_INIT_BNVAR(arguments);
		array_init(arguments);
		zephir_array_update_long(&arguments, position, &parameter, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_string(&definition, SL("arguments"), &arguments, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("_definition"), definition TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns a parameter in a specific position
 *
 * @param int position
 * @return array
 */
PHP_METHOD(Phalcon_DI_Service, getParameter) {

	zval *position_param = NULL, *definition, arguments, *parameter;
	int position;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &position_param);

		position = zephir_get_intval(position_param);


	ZEPHIR_OBS_VAR(definition);
	zephir_read_property_this(&definition, this_ptr, SL("_definition"), PH_NOISY_CC);
	if (Z_TYPE_P(definition) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Definition must be an array to obtain its parameters");
		return;
	}
	ZEPHIR_OBS_VAR(arguments);
	if (zephir_array_isset_string_fetch(&arguments, definition, SS("arguments"))) {
		ZEPHIR_OBS_VAR(parameter);
		if (zephir_array_isset_long_fetch(&parameter, arguments, position)) {
			RETURN_CCTOR(parameter);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Restore the internal state of a service
 *
 * @param array attributes
 * @return Phalcon\DI\Service
 */
PHP_METHOD(Phalcon_DI_Service, __set_state) {

	zval *attributes, *name, *definition, *shared;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes);



	ZEPHIR_OBS_VAR(name);
	if (!(zephir_array_isset_string_fetch(&name, attributes, SS("_name")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The attribute '_name' is required");
		return;
	}
	ZEPHIR_OBS_VAR(definition);
	if (!(zephir_array_isset_string_fetch(&definition, attributes, SS("_definition")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The attribute '_name' is required");
		return;
	}
	ZEPHIR_OBS_VAR(shared);
	if (!(zephir_array_isset_string_fetch(&shared, attributes, SS("_shared")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The attribute '_shared' is required");
		return;
	}
	object_init_ex(return_value, phalcon_di_service_ce);
	zephir_call_method_p3_noret(return_value, "__construct", name, definition, shared);
	RETURN_MM();

}

