
#ifdef HAVE_CONFIG_H
#include "ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"


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
 * Phalcon\Validation
 *
 * Allows to validate data using validators
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon, Validation, phalcon, validation, phalcon_di_injectable_ce, phalcon_validation_method_entry, 0);

	zend_declare_property_null(phalcon_validation_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_entity"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_validators"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_values"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Validation constructor
 *
 * @param array validators
 */
PHP_METHOD(Phalcon_Validation, __construct) {

	zval *validators = NULL, _0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &validators);

	if (!validators) {
		ZEPHIR_CPY_WRT(validators, ZEPHIR_GLOBAL(global_null));
	}


	if (Z_TYPE_P(validators) != IS_NULL) {
		if (Z_TYPE_P(validators) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "Validators must be an array");
			return;
		}
		zephir_update_property_this(this_ptr, SL("_validators"), validators TSRMLS_CC);
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "initialize", 0);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p2(_1, "method_exists", this_ptr, &_0);
	if (zend_is_true(_1)) {
		zephir_call_method_noret(this_ptr, "initialize");
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Validate a set of data according to a set of rules
 *
 * @param array|object data
 * @param object entity
 * @return Phalcon\Validation\Message\Group
 */
PHP_METHOD(Phalcon_Validation, validate) {

	HashTable *_5;
	HashPosition _4;
	zval *data = NULL, *entity = NULL, *validators, *messages = NULL, *cancelOnFail, *scope = NULL, *attribute = NULL, *validator = NULL, *_0, _1 = zval_used_for_init, *_2, *_3 = NULL, **_6, *_7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data, &entity);

	if (!data) {
		ZEPHIR_CPY_WRT(data, ZEPHIR_GLOBAL(global_null));
	}
	if (!entity) {
		ZEPHIR_CPY_WRT(entity, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_OBS_VAR(validators);
	zephir_read_property_this(&validators, this_ptr, SL("_validators"), PH_NOISY_CC);
	if (Z_TYPE_P(validators) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "There are no validators to validate");
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_update_property_this(this_ptr, SL("_values"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(messages);
	object_init_ex(messages, phalcon_validation_message_group_ce);
	zephir_call_method_noret(messages, "__construct");
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "beforeValidation", 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p2(_2, "method_exists", this_ptr, &_1);
	if (zend_is_true(_2)) {
		ZEPHIR_INIT_VAR(_3);
		zephir_call_method_p3(_3, this_ptr, "beforevalidation", data, entity, messages);
		if (ZEPHIR_IS_FALSE(_3)) {
			RETURN_MM_BOOL(0);
		}
	}
	zephir_update_property_this(this_ptr, SL("_messages"), messages TSRMLS_CC);
	if (Z_TYPE_P(data) == IS_ARRAY) {
		zephir_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	} else {
		if (Z_TYPE_P(data) == IS_OBJECT) {
			zephir_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_VAR(cancelOnFail);
	ZVAL_STRING(cancelOnFail, "cancelOnFail", 1);
	zephir_is_iterable(validators, &_5, &_4, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
		; zend_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(scope, _6);
		if (Z_TYPE_P(scope) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "The validator scope is not valid");
			return;
		}
		ZEPHIR_OBS_NVAR(attribute);
		zephir_array_fetch_long(&attribute, scope, 0, PH_NOISY);
		ZEPHIR_OBS_NVAR(validator);
		zephir_array_fetch_long(&validator, scope, 1, PH_NOISY);
		if (Z_TYPE_P(validator) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "One of the validators is not valid");
			return;
		}
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_method_p2(_3, validator, "validate", this_ptr, attribute);
		if (ZEPHIR_IS_FALSE(_3)) {
			ZEPHIR_INIT_NVAR(_7);
			zephir_call_method_p1(_7, validator, "getoption", cancelOnFail);
			if (zend_is_true(_7)) {
				break;
			}
		}
	}
	ZEPHIR_OBS_NVAR(messages);
	zephir_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "afterValidation", 0);
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_func_p2(_3, "method_exists", this_ptr, &_1);
	if (zend_is_true(_3)) {
		zephir_call_method_p3_noret(this_ptr, "aftervalidation", data, entity, messages);
	}
	RETURN_CCTOR(messages);

}

/**
 * Adds a validator to a field
 *
 * @param string attribute
 * @param Phalcon\Validation\ValidatorInterface
 * @return Phalcon\Validation
 */
PHP_METHOD(Phalcon_Validation, add) {

	zval *attribute, *validator, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute, &validator);



	if (Z_TYPE_P(attribute) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "The attribute must be a string");
		return;
	}
	if (Z_TYPE_P(validator) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "The validator must be an object");
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_array_append(&_0, attribute, 0);
	zephir_array_append(&_0, validator, 0);
	zephir_update_property_array_append(this_ptr, SL("_validators"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds filters to the field
 *
 * @param string attribute
 * @param array|string attribute
 * @return Phalcon\Validation
 */
PHP_METHOD(Phalcon_Validation, setFilters) {

	zval *attribute, *filters;

	zephir_fetch_params(0, 2, 0, &attribute, &filters);



	zephir_update_property_array(this_ptr, SL("_filters"), attribute, filters TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns all the filters or a specific one
 *
 * @param string attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation, getFilters) {

	zval *attribute = NULL, *filters, *attributeFilters;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &attribute);

	if (!attribute) {
		ZEPHIR_CPY_WRT(attribute, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_OBS_VAR(filters);
	zephir_read_property_this(&filters, this_ptr, SL("_filters"), PH_NOISY_CC);
	if (Z_TYPE_P(attribute) == IS_STRING) {
		ZEPHIR_OBS_VAR(attributeFilters);
		if (zephir_array_isset_fetch(&attributeFilters, filters, attribute)) {
			RETURN_CCTOR(attributeFilters);
		}
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(filters);

}

/**
 * Returns the validators added to the validation
 *
 * @return array
 */
PHP_METHOD(Phalcon_Validation, getValidators) {


	RETURN_MEMBER(this_ptr, "_validators");

}

/**
 * Returns the bound entity
 *
 * @return object
 */
PHP_METHOD(Phalcon_Validation, getEntity) {


	RETURN_MEMBER(this_ptr, "_entity");

}

/**
 * Returns the registered validators
 *
 * @return Phalcon\Validation\Message\Group
 */
PHP_METHOD(Phalcon_Validation, getMessages) {


	RETURN_MEMBER(this_ptr, "_messages");

}

/**
 * Appends a message to the messages list
 *
 * @param Phalcon\Validation\MessageInterface message
 * @return Phalcon\Validation
 */
PHP_METHOD(Phalcon_Validation, appendMessage) {

	zval *message, *messages;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_OBS_VAR(messages);
	zephir_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	zephir_call_method_p1_noret(messages, "appendmessage", message);
	RETURN_THIS();

}

/**
 * Assigns the data to an entity
 * The entity is used to obtain the validation values
 *
 * @param string entity
 * @param string data
 * @return Phalcon\Validation
 */
PHP_METHOD(Phalcon_Validation, bind) {

	zval *entity, *data;

	zephir_fetch_params(0, 2, 0, &entity, &data);



	if (Z_TYPE_P(entity) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_validation_exception_ce, "The entity must be an object");
		return;
	}
	if (Z_TYPE_P(data) != IS_ARRAY) {
		if (Z_TYPE_P(data) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_STRW(phalcon_validation_exception_ce, "The data to validate must be an array or object");
			return;
		}
	}
	zephir_update_property_this(this_ptr, SL("_entity"), entity TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Gets the a value to validate in the array/object data source
 *
 * @param string attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation, getValue) {

	zval *attribute, *entity, *method, *value = NULL, *data, *values, *filters, *fieldFilters, *dependencyInjector, *filterService, *_0 = NULL, _1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute);



	ZEPHIR_OBS_VAR(entity);
	zephir_read_property_this(&entity, this_ptr, SL("_entity"), PH_NOISY_CC);
	if (Z_TYPE_P(entity) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(method);
		ZEPHIR_CONCAT_SV(method, "get", attribute);
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p2(_0, "method_exists", entity, method);
		if (zend_is_true(_0)) {
			ZEPHIR_INIT_VAR(value);
			zephir_call_method_zval(value, entity, method);
		} else {
			ZEPHIR_SINIT_VAR(_1);
			ZVAL_STRING(&_1, "readAttribute", 0);
			ZEPHIR_INIT_VAR(_2);
			zephir_call_func_p2(_2, "method_exists", entity, &_1);
			if (zend_is_true(_2)) {
				ZEPHIR_INIT_NVAR(value);
				zephir_call_method_p1(value, entity, "readattribute", attribute);
			} else {
				ZEPHIR_INIT_NVAR(value);
				if (0) {
					zephir_read_property(&value, entity, SL("attribute"), PH_NOISY_CC);
				} else {
					ZVAL_NULL(value);
				}
			}
		}
		RETURN_CCTOR(value);
	}
	ZEPHIR_OBS_VAR(data);
	zephir_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (Z_TYPE_P(data) != IS_ARRAY) {
		if (Z_TYPE_P(data) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "There is no data to validate");
			return;
		}
	}
	ZEPHIR_OBS_VAR(values);
	zephir_read_property_this(&values, this_ptr, SL("_values"), PH_NOISY_CC);
	ZEPHIR_OBS_NVAR(value);
	if (zephir_array_isset_fetch(&value, values, attribute)) {
		RETURN_CCTOR(value);
	}
	ZEPHIR_INIT_NVAR(value);
	ZVAL_NULL(value);
	if (Z_TYPE_P(data) == IS_ARRAY) {
		if (zephir_array_isset(data, attribute)) {
			ZEPHIR_OBS_NVAR(value);
			zephir_array_fetch(&value, data, attribute, PH_NOISY);
		}
	} else {
		if (Z_TYPE_P(data) == IS_OBJECT) {
			if (0) {
				ZEPHIR_OBS_NVAR(value);
				zephir_read_property(&value, data, SL("attribute"), PH_NOISY_CC);
			}
		}
	}
	if (Z_TYPE_P(value) != IS_NULL) {
		ZEPHIR_OBS_VAR(filters);
		zephir_read_property_this(&filters, this_ptr, SL("_filters"), PH_NOISY_CC);
		if (Z_TYPE_P(filters) == IS_ARRAY) {
			ZEPHIR_OBS_VAR(fieldFilters);
			if (zephir_array_isset_fetch(&fieldFilters, filters, attribute)) {
				if (zend_is_true(fieldFilters)) {
					ZEPHIR_INIT_VAR(dependencyInjector);
					zephir_call_method(dependencyInjector, this_ptr, "getdi");
					if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
						if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
							ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "A dependency injector is required to obtain the 'filter' service");
							return;
						}
					}
					ZEPHIR_INIT_NVAR(_0);
					ZVAL_STRING(_0, "filter", 1);
					ZEPHIR_INIT_VAR(filterService);
					zephir_call_method_p1(filterService, dependencyInjector, "getshared", _0);
					if (Z_TYPE_P(filterService) != IS_OBJECT) {
						ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "Returned 'filter' service is invalid");
						return;
					}
					zephir_call_method_p2(return_value, filterService, "sanitize", value, fieldFilters);
					RETURN_MM();
				}
			}
		}
		zephir_update_property_array(this_ptr, SL("_values"), attribute, value TSRMLS_CC);
		RETURN_CCTOR(value);
	}
	RETURN_MM_NULL();

}

