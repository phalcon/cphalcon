
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
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "Zend/zend_closures.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Represents individually a service in the services container
 *
 *```php
 * $service = new \Phalcon\Di\Service(
 *     "request",
 *     \Phalcon\Http\Request::class
 * );
 *
 * $request = service->resolve();
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_Service) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Di, Service, phalcon, di_service, phalcon_di_service_method_entry, 0);

	zend_declare_property_null(phalcon_di_service_ce, SL("definition"), ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_di_service_ce, SL("resolved"), 0, ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_di_service_ce, SL("shared"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_di_service_ce, SL("sharedInstance"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_di_service_ce, 1, phalcon_di_serviceinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Di\Service
 */
PHP_METHOD(Phalcon_Di_Service, __construct) {

	zend_bool shared;
	zval *definition, definition_sub, *shared_param = NULL, __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definition_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 1, &definition, &shared_param);

	if (!shared_param) {
		shared = 0;
	} else {
		shared = zephir_get_boolval(shared_param);
	}


	zephir_update_property_zval(this_ptr, SL("definition"), definition);
	if (shared) {
		zephir_update_property_zval(this_ptr, SL("shared"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("shared"), &__$false);
	}

}

/**
 * Returns the service definition
 */
PHP_METHOD(Phalcon_Di_Service, getDefinition) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "definition");

}

/**
 * Returns a parameter in a specific position
 *
 * @return array
 */
PHP_METHOD(Phalcon_Di_Service, getParameter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *position_param = NULL, definition, arguments, parameter, _0;
	zend_long position;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&parameter);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &position_param);

	position = zephir_get_intval(position_param);


	zephir_read_property(&_0, this_ptr, SL("definition"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&definition, &_0);
	if (UNEXPECTED(Z_TYPE_P(&definition) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Definition must be an array to obtain its parameters", "phalcon/Di/Service.zep", 76);
		return;
	}
	if (zephir_array_isset_string_fetch(&arguments, &definition, SL("arguments"), 1)) {
		if (zephir_array_isset_long_fetch(&parameter, &arguments, position, 1)) {
			RETURN_CTOR(&parameter);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Returns true if the service was resolved
 */
PHP_METHOD(Phalcon_Di_Service, isResolved) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "resolved");

}

/**
 * Check whether the service is shared or not
 */
PHP_METHOD(Phalcon_Di_Service, isShared) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "shared");

}

/**
 * Resolves the service
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Di_Service, resolve) {

	zend_class_entry *_4$$14;
	zend_bool found = 0, _2$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, *container = NULL, container_sub, __$true, __$false, __$null, shared, definition, sharedInstance, instance, builder, _0, _1$$3, _3$$14, _5$$21;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&container_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&shared);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&sharedInstance);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$14);
	ZVAL_UNDEF(&_5$$21);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &parameters, &container);

	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}
	if (!container) {
		container = &container_sub;
		container = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("shared"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&shared, &_0);
	if (zephir_is_true(&shared)) {
		zephir_read_property(&_1$$3, this_ptr, SL("sharedInstance"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&sharedInstance, &_1$$3);
		if (Z_TYPE_P(&sharedInstance) != IS_NULL) {
			RETURN_CCTOR(&sharedInstance);
		}
	}
	found = 1;
	ZEPHIR_INIT_VAR(&instance);
	ZVAL_NULL(&instance);
	zephir_read_property(&_0, this_ptr, SL("definition"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&definition, &_0);
	if (Z_TYPE_P(&definition) == IS_STRING) {
		if (Z_TYPE_P(container) != IS_NULL) {
			ZEPHIR_CALL_METHOD(&instance, container, "get", NULL, 0, &definition, parameters);
			zephir_check_call_status();
		} else if (zephir_class_exists(&definition, 1)) {
			_2$$7 = Z_TYPE_P(parameters) == IS_ARRAY;
			if (_2$$7) {
				_2$$7 = ((zephir_fast_count_int(parameters)) ? 1 : 0);
			}
			if (_2$$7) {
				ZEPHIR_INIT_NVAR(&instance);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&instance, &definition, parameters);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&instance);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&instance, &definition);
				zephir_check_call_status();
			}
		} else {
			found = 0;
		}
	} else {
		if (Z_TYPE_P(&definition) == IS_OBJECT) {
			if (zephir_instance_of_ev(&definition, zend_ce_closure)) {
				if (Z_TYPE_P(container) == IS_OBJECT) {
					_4$$14 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
					ZEPHIR_CALL_CE_STATIC(&_3$$14, _4$$14, "bind", NULL, 0, &definition, container);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&definition, &_3$$14);
				}
				if (Z_TYPE_P(parameters) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&instance);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&instance, &definition, parameters);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&instance);
					ZEPHIR_CALL_USER_FUNC(&instance, &definition);
					zephir_check_call_status();
				}
			} else {
				ZEPHIR_CPY_WRT(&instance, &definition);
			}
		} else {
			if (Z_TYPE_P(&definition) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(&builder);
				object_init_ex(&builder, phalcon_di_service_builder_ce);
				if (zephir_has_constructor(&builder)) {
					ZEPHIR_CALL_METHOD(NULL, &builder, "__construct", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&instance, &builder, "build", NULL, 224, container, &definition, parameters);
				zephir_check_call_status();
			} else {
				found = 0;
			}
		}
	}
	if (UNEXPECTED(found == 0)) {
		ZEPHIR_INIT_VAR(&_5$$21);
		object_init_ex(&_5$$21, phalcon_di_exception_serviceresolutionexception_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$21, "__construct", NULL, 6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$21, "phalcon/Di/Service.zep", 199);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_is_true(&shared)) {
		zephir_update_property_zval(this_ptr, SL("sharedInstance"), &instance);
	}
	if (1) {
		zephir_update_property_zval(this_ptr, SL("resolved"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("resolved"), &__$false);
	}
	RETURN_CCTOR(&instance);

}

/**
 * Set the service definition
 */
PHP_METHOD(Phalcon_Di_Service, setDefinition) {

	zval *definition, definition_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definition_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &definition);



	zephir_update_property_zval(this_ptr, SL("definition"), definition);

}

/**
 * Changes a parameter in the definition without resolve the service
 */
PHP_METHOD(Phalcon_Di_Service, setParameter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval parameter;
	zval *position_param = NULL, *parameter_param = NULL, definition, arguments, _0, _1$$5;
	zend_long position;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&parameter);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &position_param, &parameter_param);

	position = zephir_get_intval(position_param);
	ZEPHIR_OBS_COPY_OR_DUP(&parameter, parameter_param);


	zephir_read_property(&_0, this_ptr, SL("definition"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&definition, &_0);
	if (UNEXPECTED(Z_TYPE_P(&definition) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Definition must be an array to update its parameters", "phalcon/Di/Service.zep", 234);
		return;
	}
	ZEPHIR_OBS_VAR(&arguments);
	if (zephir_array_isset_string_fetch(&arguments, &definition, SL("arguments"), 0)) {
		zephir_array_update_long(&arguments, position, &parameter, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	} else {
		ZEPHIR_INIT_VAR(&_1$$5);
		zephir_create_array(&_1$$5, 1, 0);
		zephir_array_update_long(&_1$$5, position, &parameter, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
		ZEPHIR_CPY_WRT(&arguments, &_1$$5);
	}
	zephir_array_update_string(&definition, SL("arguments"), &arguments, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("definition"), &definition);
	RETURN_THIS();

}

/**
 * Sets if the service is shared or not
 */
PHP_METHOD(Phalcon_Di_Service, setShared) {

	zval *shared_param = NULL, __$true, __$false;
	zend_bool shared;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 0, &shared_param);

	shared = zephir_get_boolval(shared_param);


	if (shared) {
		zephir_update_property_zval(this_ptr, SL("shared"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("shared"), &__$false);
	}

}

/**
 * Sets/Resets the shared instance related to the service
 */
PHP_METHOD(Phalcon_Di_Service, setSharedInstance) {

	zval *sharedInstance, sharedInstance_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sharedInstance_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &sharedInstance);



	zephir_update_property_zval(this_ptr, SL("sharedInstance"), sharedInstance);

}

