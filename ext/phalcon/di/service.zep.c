
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "Zend/zend_closures.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * Phalcon\Di\Service
 *
 * Represents individually a service in the services container
 *
 *<code>
 * $service = new \Phalcon\Di\Service('request', 'Phalcon\Http\Request');
 * $request = service->resolve();
 *<code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_Service) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Di, Service, phalcon, di_service, phalcon_di_service_method_entry, 0);

	zend_declare_property_null(phalcon_di_service_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_di_service_ce, SL("_definition"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_di_service_ce, SL("_shared"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_di_service_ce, SL("_resolved"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

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
	zval *name_param = NULL, *definition, *shared_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &definition, &shared_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!shared_param) {
		shared = 0;
	} else {
		shared = zephir_get_boolval(shared_param);
	}


	zephir_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_definition"), definition TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_shared"), shared ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the service's name
 */
PHP_METHOD(Phalcon_Di_Service, getName) {


	RETURN_MEMBER(this_ptr, "_name");

}

/**
 * Sets if the service is shared or not
 */
PHP_METHOD(Phalcon_Di_Service, setShared) {

	zval *shared_param = NULL;
	zend_bool shared;

	zephir_fetch_params(0, 1, 0, &shared_param);

	shared = zephir_get_boolval(shared_param);


	zephir_update_property_this(this_ptr, SL("_shared"), shared ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);

}

/**
 * Check whether the service is shared or not
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

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool found;
	zval *parameters = NULL, *dependencyInjector = NULL, *shared, *definition, *sharedInstance, *instance = NULL, *builder, *reflection = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &parameters, &dependencyInjector);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}
	if (!dependencyInjector) {
		dependencyInjector = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(shared);
	zephir_read_property_this(&shared, this_ptr, SL("_shared"), PH_NOISY_CC);
	if (zephir_is_true(shared)) {
		ZEPHIR_OBS_VAR(sharedInstance);
		zephir_read_property_this(&sharedInstance, this_ptr, SL("_sharedInstance"), PH_NOISY_CC);
		if (Z_TYPE_P(sharedInstance) != IS_NULL) {
			RETURN_CCTOR(sharedInstance);
		}
	}
	found = 1;
	ZEPHIR_INIT_VAR(instance);
	ZVAL_NULL(instance);
	ZEPHIR_OBS_VAR(definition);
	zephir_read_property_this(&definition, this_ptr, SL("_definition"), PH_NOISY_CC);
	if (Z_TYPE_P(definition) == IS_STRING) {
		if (zephir_class_exists(definition, 1 TSRMLS_CC)) {
			if (Z_TYPE_P(parameters) == IS_ARRAY) {
				if (zephir_fast_count_int(parameters TSRMLS_CC)) {
					if (zephir_is_php_version(50600)) {
						ZEPHIR_INIT_VAR(reflection);
						object_init_ex(reflection, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
						ZEPHIR_CALL_METHOD(NULL, reflection, "__construct", NULL, 15, definition);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&instance, reflection, "newinstanceargs", NULL, 142, parameters);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(instance);
						ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(instance, definition, parameters TSRMLS_CC);
						zephir_check_call_status();
					}
				} else {
					if (zephir_is_php_version(50600)) {
						ZEPHIR_INIT_NVAR(reflection);
						object_init_ex(reflection, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
						ZEPHIR_CALL_METHOD(NULL, reflection, "__construct", NULL, 15, definition);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&instance, reflection, "newinstance", NULL, 143);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(instance);
						ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(instance, definition TSRMLS_CC);
						zephir_check_call_status();
					}
				}
			} else {
				if (zephir_is_php_version(50600)) {
					ZEPHIR_INIT_NVAR(reflection);
					object_init_ex(reflection, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
					ZEPHIR_CALL_METHOD(NULL, reflection, "__construct", NULL, 15, definition);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&instance, reflection, "newinstance", NULL, 143);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(instance);
					ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(instance, definition TSRMLS_CC);
					zephir_check_call_status();
				}
			}
		} else {
			found = 0;
		}
	} else {
		if (Z_TYPE_P(definition) == IS_OBJECT) {
			if (zephir_instance_of_ev(definition, zend_ce_closure TSRMLS_CC)) {
				if (Z_TYPE_P(parameters) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(instance);
					ZEPHIR_CALL_USER_FUNC_ARRAY(instance, definition, parameters);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(instance);
					ZEPHIR_CALL_USER_FUNC(instance, definition);
					zephir_check_call_status();
				}
			} else {
				ZEPHIR_CPY_WRT(instance, definition);
			}
		} else {
			if (Z_TYPE_P(definition) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(builder);
				object_init_ex(builder, phalcon_di_service_builder_ce);
				if (zephir_has_constructor(builder TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, builder, "__construct", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&instance, builder, "build", NULL, 149, dependencyInjector, definition, parameters);
				zephir_check_call_status();
			} else {
				found = 0;
			}
		}
	}
	if (found == 0) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_di_exception_ce);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Service '", _1, "' cannot be resolved");
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalcon/di/service.zep", 212 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_is_true(shared)) {
		zephir_update_property_this(this_ptr, SL("_sharedInstance"), instance TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("_resolved"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_CCTOR(instance);

}

/**
 * Changes a parameter in the definition without resolve the service
 */
PHP_METHOD(Phalcon_Di_Service, setParameter) {

	zval *parameter = NULL;
	zval *position_param = NULL, *parameter_param = NULL, *definition, *arguments = NULL;
	int position;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &position_param, &parameter_param);

	position = zephir_get_intval(position_param);
	parameter = parameter_param;



	ZEPHIR_OBS_VAR(definition);
	zephir_read_property_this(&definition, this_ptr, SL("_definition"), PH_NOISY_CC);
	if (Z_TYPE_P(definition) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Definition must be an array to update its parameters", "phalcon/di/service.zep", 236);
		return;
	}
	ZEPHIR_OBS_VAR(arguments);
	if (zephir_array_isset_string_fetch(&arguments, definition, SS("arguments"), 0 TSRMLS_CC)) {
		zephir_array_update_long(&arguments, position, &parameter, PH_COPY | PH_SEPARATE, "phalcon/di/service.zep", 243);
	} else {
		ZEPHIR_INIT_NVAR(arguments);
		zephir_create_array(arguments, 1, 0 TSRMLS_CC);
		zephir_array_update_long(&arguments, position, &parameter, PH_COPY, "phalcon/di/service.zep", 245);
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &position_param);

	position = zephir_get_intval(position_param);


	ZEPHIR_OBS_VAR(definition);
	zephir_read_property_this(&definition, this_ptr, SL("_definition"), PH_NOISY_CC);
	if (Z_TYPE_P(definition) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Definition must be an array to obtain its parameters", "phalcon/di/service.zep", 273);
		return;
	}
	if (zephir_array_isset_string_fetch(&arguments, definition, SS("arguments"), 1 TSRMLS_CC)) {
		if (zephir_array_isset_long_fetch(&parameter, arguments, position, 1 TSRMLS_CC)) {
			RETURN_CTOR(parameter);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Returns true if the service was resolved
 */
PHP_METHOD(Phalcon_Di_Service, isResolved) {


	RETURN_MEMBER(this_ptr, "_resolved");

}

/**
 * Restore the internal state of a service
 */
PHP_METHOD(Phalcon_Di_Service, __set_state) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, *name, *definition, *shared;
	zval *attributes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	attributes = attributes_param;



	ZEPHIR_OBS_VAR(name);
	if (!(zephir_array_isset_string_fetch(&name, attributes, SS("_name"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The attribute '_name' is required", "phalcon/di/service.zep", 304);
		return;
	}
	ZEPHIR_OBS_VAR(definition);
	if (!(zephir_array_isset_string_fetch(&definition, attributes, SS("_definition"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The attribute '_definition' is required", "phalcon/di/service.zep", 308);
		return;
	}
	ZEPHIR_OBS_VAR(shared);
	if (!(zephir_array_isset_string_fetch(&shared, attributes, SS("_shared"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The attribute '_shared' is required", "phalcon/di/service.zep", 312);
		return;
	}
	object_init_ex(return_value, phalcon_di_service_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 141, name, definition, shared);
	zephir_check_call_status();
	RETURN_MM();

}

