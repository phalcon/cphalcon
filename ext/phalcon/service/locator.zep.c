
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
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Service\Locator
 *
 * Lazy loads, stores and exposes objects
 */
ZEPHIR_INIT_CLASS(Phalcon_Service_Locator) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Service, Locator, phalcon, service_locator, phalcon_service_locator_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_service_locator_ce, SL("services"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_service_locator_ce, SL("mapper"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_service_locator_ce->create_object = zephir_init_properties_Phalcon_Service_Locator;

	zend_class_implements(phalcon_service_locator_ce TSRMLS_CC, 1, phalcon_service_locatorinterface_ce);
	return SUCCESS;

}

/**
 * Key value pairs with name as the key and a callable as the value for
 * the service object
 */
PHP_METHOD(Phalcon_Service_Locator, __construct) {

	zval *mapper_param = NULL;
	zval mapper;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mapper);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &mapper_param);

	if (!mapper_param) {
		ZEPHIR_INIT_VAR(&mapper);
		array_init(&mapper);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&mapper, mapper_param);
	}


	zephir_update_property_zval(this_ptr, SL("mapper"), &mapper);
	ZEPHIR_MM_RESTORE();

}

/**
 * Services being called via magic methods
 */
PHP_METHOD(Phalcon_Service_Locator, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, service;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &parameters_param);

	zephir_get_strval(&name, name_param);
	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_CALL_METHOD(&service, this_ptr, "get", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &service, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get a service. If it is not in the mapper array, create a new object,
 * set it and then return it.
 */
PHP_METHOD(Phalcon_Service_Locator, get) {

	zend_class_entry *_6$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, definition, service, _0, _3, _7, _8, _1$$3, _4$$4, _5$$5;
	zval name, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &name);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_service_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "The service ", &name, " has not been found in the locator");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 4, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/service/locator.zep", 61 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	if (1 != zephir_array_isset(&_3, &name)) {
		zephir_read_property(&_4$$4, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&definition, &_4$$4, &name, PH_NOISY | PH_READONLY, "phalcon/service/locator.zep", 65 TSRMLS_CC);
		if (Z_TYPE_P(&definition) == IS_STRING) {
			ZEPHIR_INIT_VAR(&service);
			zephir_fetch_safe_class(&_5$$5, &definition);
			_6$$5 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_5$$5), Z_STRLEN_P(&_5$$5), ZEND_FETCH_CLASS_AUTO);
			object_init_ex(&service, _6$$5);
			if (zephir_has_constructor(&service TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, &service, "__construct", NULL, 0);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_CPY_WRT(&service, &definition);
		}
		zephir_update_property_array(this_ptr, SL("services"), &name, &service);
	}
	zephir_read_property(&_7, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_8, &_7, &name, PH_NOISY | PH_READONLY, "phalcon/service/locator.zep", 76 TSRMLS_CC);
	RETURN_CTOR(&_8);

}

/**
 * Checks if a service exists in the map array
 */
PHP_METHOD(Phalcon_Service_Locator, has) {

	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));

}

/**
 * Set a new service to the mapper array
 */
PHP_METHOD(Phalcon_Service_Locator, set) {

	zval *name_param = NULL, *service, service_sub, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&service_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &service);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_update_property_array(this_ptr, SL("mapper"), &name, service);
	zephir_read_property(&_0, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Phalcon_Service_Locator(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("mapper"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("services"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

