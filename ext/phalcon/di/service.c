
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
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
 * Phalcon\Di\Service
 *
 * Represents individually a service in the services container
 *
 *<code>
 * $service = new Phalcon\Di\Service('request', 'Phalcon\Http\Request');
 * $request = service->resolve();
 *<code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_Service) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Di, Service, phalcon, di_service, phalcon_di_service_method_entry, 0);

	zend_declare_property_null(phalcon_di_service_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_di_service_ce, SL("_definition"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_di_service_ce, SL("_shared"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_di_service_ce, SL("_sharedInstance"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_di_service_ce TSRMLS_CC, 1, phalcon_di_serviceinterface_ce);

	return SUCCESS;

}

/**
 * Phalcon\Di\Service
 *
 * @param string name
 * @param mixed definition
 * @param boolean shared
 */
PHP_METHOD(Phalcon_Di_Service, __construct) {

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
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_BOOL(_0, shared);
	zephir_update_property_this(this_ptr, SL("_shared"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the service's name
 *
 * @param string
 */
PHP_METHOD(Phalcon_Di_Service, getName) {


	RETURN_MEMBER(this_ptr, "_name");

}

/**
 * Sets if the service is shared or not
 *
 * @param boolean shared
 */
PHP_METHOD(Phalcon_Di_Service, setShared) {

	zval *shared_param = NULL, *_0;
	zend_bool shared;

	zephir_fetch_params(0, 1, 0, &shared_param);

		shared = zephir_get_boolval(shared_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_BOOL(_0, shared);
	zephir_update_property_this(this_ptr, SL("_shared"), _0 TSRMLS_CC);

}

/**
 * Check whether the service is shared or not
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Di_Service, isShared) {


	RETURN_MEMBER(this_ptr, "_shared");

}

/**
 * Sets/Resets the shared instance related to the service
 *
 * @param mixed sharedInstance
 */
PHP_METHOD(Phalcon_Di_Service, setSharedInstance) {

	zval *sharedInstance;

	zephir_fetch_params(0, 1, 0, &sharedInstance);



	zephir_update_property_this(this_ptr, SL("_sharedInstance"), sharedInstance TSRMLS_CC);

}

/**
 * Set the service definition
 *
 * @param mixed definition
 */
PHP_METHOD(Phalcon_Di_Service, setDefinition) {

	zval *definition;

	zephir_fetch_params(0, 1, 0, &definition);



	zephir_update_property_this(this_ptr, SL("_definition"), definition TSRMLS_CC);

}

/**
 * Returns the service definition
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Di_Service, getDefinition) {


	RETURN_MEMBER(this_ptr, "_definition");

}

/**
 * Resolves the service
 *
 * @param array parameters
 * @param Phalcon\DiInterface dependencyInjector
 * @return mixed
 */
PHP_METHOD(Phalcon_Di_Service, resolve) {

	zend_bool found;
	zval *parameters = NULL, *dependencyInjector = NULL, *shared, *definition, *sharedInstance, *instance = NULL, *builder, *_0 = NULL, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &parameters, &dependencyInjector);

	if (!parameters) {
		ZEPHIR_CPY_WRT(parameters, ZEPHIR_GLOBAL(global_null));
	}
	if (!dependencyInjector) {
		ZEPHIR_CPY_WRT(dependencyInjector, ZEPHIR_GLOBAL(global_null));
	}


	shared = zephir_fetch_nproperty_this(this_ptr, SL("_shared"), PH_NOISY_CC);
	if (zephir_is_true(shared)) {
		sharedInstance = zephir_fetch_nproperty_this(this_ptr, SL("_sharedInstance"), PH_NOISY_CC);
		if ((Z_TYPE_P(sharedInstance) != IS_NULL)) {
			ZEPHIR_MM_RESTORE();
			RETURN_ZVAL(sharedInstance, 1, 0);
		}
	}
	found = 1;
	ZEPHIR_INIT_VAR(instance);
	ZVAL_NULL(instance);
	definition = zephir_fetch_nproperty_this(this_ptr, SL("_definition"), PH_NOISY_CC);
	if ((Z_TYPE_P(definition) == IS_STRING)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "class_exists", definition);
		if (zephir_is_true(_0)) {
			if ((Z_TYPE_P(parameters) == IS_ARRAY)) {
				ZEPHIR_INIT_BNVAR(instance);
				if (zephir_fast_count_int(parameters TSRMLS_CC)) {
					if (zephir_create_instance_params(instance, definition, parameters TSRMLS_CC) == FAILURE) {
						return;
					}
				} else {
					if (zephir_create_instance(instance, definition TSRMLS_CC) == FAILURE) {
						return;
					}
				}
			} else {
				ZEPHIR_INIT_BNVAR(instance);
				if (zephir_create_instance(instance, definition TSRMLS_CC) == FAILURE) {
					return;
				}
			}
		} else {
			found = 0;
		}
	} else {
		if ((Z_TYPE_P(definition) == IS_OBJECT)) {
			if (zephir_is_instance_of(definition, SL("closure") TSRMLS_CC)) {
				ZEPHIR_INIT_BNVAR(instance);
				if ((Z_TYPE_P(parameters) == IS_ARRAY)) {
					zephir_call_func_p2(instance, "call_user_func_array", definition, parameters);
				} else {
					zephir_call_func_p1(instance, "call_user_func", definition);
				}
			} else {
				ZEPHIR_CPY_WRT(instance, definition);
			}
		} else {
			if ((Z_TYPE_P(definition) == IS_ARRAY)) {
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
	if (zephir_is_true(shared)) {
		zephir_update_property_this(this_ptr, SL("_sharedInstance"), instance TSRMLS_CC);
	}
	RETURN_CCTOR(instance);

}

/**
 * Changes a parameter in the definition without resolve the service
 *
 * @param int position
 * @param array parameter
 * @return Phalcon\Di\Service
 */
PHP_METHOD(Phalcon_Di_Service, setParameter) {

	zval *position_param = NULL, *parameter, *definition, *arguments;
	int position;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &position_param, &parameter);

		position = zephir_get_intval(position_param);


	ZEPHIR_OBS_VAR(definition);
	zephir_read_property_this(&definition, this_ptr, SL("_definition"), PH_NOISY_CC);
	if ((Z_TYPE_P(definition) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Definition must be an array to update its parameters");
		return;
	}
	if ((Z_TYPE_P(parameter) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The parameter must be an array");
		return;
	}
	ZEPHIR_OBS_VAR(arguments);
	if (zephir_array_isset_string_fetch(&arguments, definition, SS("arguments"), 0 TSRMLS_CC)) {
		zephir_array_update_long(&arguments, position, &parameter, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_INIT_BNVAR(arguments);
		array_init(arguments);
		zephir_array_update_long(&arguments, position, &parameter, PH_COPY);
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
PHP_METHOD(Phalcon_Di_Service, getParameter) {

	zval *position_param = NULL, *definition, *arguments, *parameter;
	int position;

	zephir_fetch_params(0, 1, 0, &position_param);

		position = zephir_get_intval(position_param);


	definition = zephir_fetch_nproperty_this(this_ptr, SL("_definition"), PH_NOISY_CC);
	if ((Z_TYPE_P(definition) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "Definition must be an array to obtain its parameters");
		return;
	}
	if (zephir_array_isset_string_fetch(&arguments, definition, SS("arguments"), 1 TSRMLS_CC)) {
		if (zephir_array_isset_long_fetch(&parameter, arguments, position, 1 TSRMLS_CC)) {
			RETURN_ZVAL(parameter, 1, 0);
		}
	}
	RETURN_NULL();

}

/**
 * Restore the internal state of a service
 *
 * @param array attributes
 * @return Phalcon\Di\Service
 */
PHP_METHOD(Phalcon_Di_Service, __set_state) {

	zval *attributes, *name, *definition, *shared;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes);



	if (!(zephir_array_isset_string_fetch(&name, attributes, SS("_name"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The attribute '_name' is required");
		return;
	}
	if (!(zephir_array_isset_string_fetch(&definition, attributes, SS("_definition"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The attribute '_name' is required");
		return;
	}
	if (!(zephir_array_isset_string_fetch(&shared, attributes, SS("_shared"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The attribute '_shared' is required");
		return;
	}
	object_init_ex(return_value, phalcon_di_service_ce);
	zephir_call_method_p3_noret(return_value, "__construct", name, definition, shared);
	RETURN_MM();

}

