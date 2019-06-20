
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "Zend/zend_closures.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Di\Service
 *
 * Represents individually a service in the services container
 *
 *<code>
 * $service = new \Phalcon\Di\Service(
 *     "request",
 *     \Phalcon\Http\Request::class
 * );
 *
 * $request = service->resolve();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_Service) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Di, Service, phalcon, di_service, phalcon_di_service_method_entry, 0);

	zend_declare_property_null(phalcon_di_service_ce, SL("definition"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_di_service_ce, SL("resolved"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_di_service_ce, SL("shared"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_di_service_ce, SL("sharedInstance"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_di_service_ce TSRMLS_CC, 1, phalcon_di_serviceinterface_ce);
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

	zephir_fetch_params(0, 1, 1, &definition, &shared_param);

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
 * Restore the internal state of a service
 */
PHP_METHOD(Phalcon_Di_Service, __set_state) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, definition, shared;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&shared);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	ZEPHIR_OBS_VAR(&definition);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&definition, &attributes, SL("_definition"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The attribute '_definition' is required", "phalcon/Di/Service.zep", 67);
		return;
	}
	ZEPHIR_OBS_VAR(&shared);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&shared, &attributes, SL("_shared"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The attribute '_shared' is required", "phalcon/Di/Service.zep", 71);
		return;
	}
	object_init_ex(return_value, phalcon_di_service_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 83, &definition, &shared);
	zephir_check_call_status();
	RETURN_MM();

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Definition must be an array to obtain its parameters", "phalcon/Di/Service.zep", 99);
		return;
	}
	if (zephir_array_isset_string_fetch(&arguments, &definition, SL("arguments"), 1)) {
		if (zephir_array_isset_long_fetch(&parameter, &arguments, position, 1 TSRMLS_CC)) {
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

	zend_class_entry *_4$$13;
	zend_bool found = 0, _2$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, *container = NULL, container_sub, __$true, __$false, __$null, shared, definition, sharedInstance, instance, builder, _0, _1$$3, _3$$13, _5$$20;
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
	ZVAL_UNDEF(&_3$$13);
	ZVAL_UNDEF(&_5$$20);

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
		if (zephir_class_exists(&definition, 1 TSRMLS_CC)) {
			_2$$6 = Z_TYPE_P(parameters) == IS_ARRAY;
			if (_2$$6) {
				_2$$6 = ((zephir_fast_count_int(parameters TSRMLS_CC)) ? 1 : 0);
			}
			if (_2$$6) {
				ZEPHIR_INIT_NVAR(&instance);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&instance, &definition, parameters TSRMLS_CC);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&instance);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&instance, &definition TSRMLS_CC);
				zephir_check_call_status();
			}
		} else {
			found = 0;
		}
	} else {
		if (Z_TYPE_P(&definition) == IS_OBJECT) {
			if (zephir_instance_of_ev(&definition, zend_ce_closure TSRMLS_CC)) {
				if (Z_TYPE_P(container) == IS_OBJECT) {
					_4$$13 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
					ZEPHIR_CALL_CE_STATIC(&_3$$13, _4$$13, "bind", NULL, 0, &definition, container);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&definition, &_3$$13);
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
				if (zephir_has_constructor(&builder TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, &builder, "__construct", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&instance, &builder, "build", NULL, 211, container, &definition, parameters);
				zephir_check_call_status();
			} else {
				found = 0;
			}
		}
	}
	if (UNEXPECTED(found == 0)) {
		ZEPHIR_INIT_VAR(&_5$$20);
		object_init_ex(&_5$$20, phalcon_di_exception_serviceresolutionexception_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$20, "__construct", NULL, 1);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$20, "phalcon/Di/Service.zep", 221 TSRMLS_CC);
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

	zephir_fetch_params(0, 1, 0, &definition);



	zephir_update_property_zval(this_ptr, SL("definition"), definition);

}

/**
 * Changes a parameter in the definition without resolve the service
 */
PHP_METHOD(Phalcon_Di_Service, setParameter) {

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Definition must be an array to update its parameters", "phalcon/Di/Service.zep", 256);
		return;
	}
	ZEPHIR_OBS_VAR(&arguments);
	if (zephir_array_isset_string_fetch(&arguments, &definition, SL("arguments"), 0)) {
		zephir_array_update_long(&arguments, position, &parameter, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	} else {
		ZEPHIR_INIT_VAR(&_1$$5);
		zephir_create_array(&_1$$5, 1, 0 TSRMLS_CC);
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

	zephir_fetch_params(0, 1, 0, &shared_param);

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

	zephir_fetch_params(0, 1, 0, &sharedInstance);



	zephir_update_property_zval(this_ptr, SL("sharedInstance"), sharedInstance);

}

