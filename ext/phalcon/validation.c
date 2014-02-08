
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
	zend_declare_property_null(phalcon_validation_ce, SL("_defaultMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_labels"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_values"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Validation constructor
 *
 * @param array validators
 */
PHP_METHOD(Phalcon_Validation, __construct) {

	zval *validators = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &validators);

	if (!validators) {
		validators = ZEPHIR_GLOBAL(global_null);
	}


	if ((Z_TYPE_P(validators) != IS_NULL)) {
		if ((Z_TYPE_P(validators) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "Validators must be an array");
			return;
		}
		zephir_update_property_this(this_ptr, SL("_validators"), validators TSRMLS_CC);
	}
	zephir_call_method_noret(this_ptr, "setdefaultmessages");
	if ((zephir_method_exists_ex(this_ptr, SS("initialize") TSRMLS_CC) == SUCCESS)) {
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

	HashTable *_2;
	HashPosition _1;
	zval *data = NULL, *entity = NULL, *validators, *messages = NULL, *scope = NULL, *field = NULL, *validator = NULL, *notCachedCall = NULL, *_0 = NULL, **_3, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data, &entity);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}
	if (!entity) {
		entity = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(validators);
	zephir_read_property_this(&validators, this_ptr, SL("_validators"), PH_NOISY_CC);
	if ((Z_TYPE_P(validators) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "There are no validators to validate");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_values"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_INIT_VAR(messages);
	object_init_ex(messages, phalcon_validation_message_group_ce);
	zephir_call_method_noret(messages, "__construct");
	if ((zephir_method_exists_ex(this_ptr, SS("beforevalidation") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_method_p3(_0, this_ptr, "beforevalidation", data, entity, messages);
		if (ZEPHIR_IS_FALSE(_0)) {
			RETURN_CCTOR(messages);
		}
	}
	zephir_update_property_this(this_ptr, SL("_messages"), messages TSRMLS_CC);
	if ((Z_TYPE_P(data) == IS_ARRAY)) {
		zephir_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	} else {
		if ((Z_TYPE_P(data) == IS_OBJECT)) {
			zephir_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
		}
	}
	zephir_is_iterable(validators, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(scope, _3);
		if ((Z_TYPE_P(scope) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "The validator scope is not valid");
			return;
		}
		ZEPHIR_OBS_NVAR(field);
		zephir_array_fetch_long(&field, scope, 0, PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(validator);
		zephir_array_fetch_long(&validator, scope, 1, PH_NOISY TSRMLS_CC);
		if ((Z_TYPE_P(validator) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "One of the validators is not valid");
			return;
		}
		ZEPHIR_INIT_NVAR(notCachedCall);
		ZVAL_STRING(notCachedCall, "validate", 1);
		ZEPHIR_INIT_NVAR(_0);
		zephir_call_method_zval_p2(_0, validator, notCachedCall, this_ptr, field);
		if (ZEPHIR_IS_FALSE(_0)) {
			ZEPHIR_INIT_NVAR(notCachedCall);
			ZVAL_STRING(notCachedCall, "getOption", 1);
			ZEPHIR_INIT_NVAR(_4);
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_STRING(_5, "cancelOnFail", 1);
			zephir_call_method_zval_p1(_4, validator, notCachedCall, _5);
			if (zephir_is_true(_4)) {
				break;
			}
		}
	}
	ZEPHIR_OBS_NVAR(messages);
	zephir_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if ((zephir_method_exists_ex(this_ptr, SS("aftervalidation") TSRMLS_CC) == SUCCESS)) {
		zephir_call_method_p3_noret(this_ptr, "aftervalidation", data, entity, messages);
	}
	RETURN_CCTOR(messages);

}

/**
 * Adds a validator to a field
 *
 * @param string field
 * @param Phalcon\Validation\ValidatorInterface validator
 * @return Phalcon\Validation
 */
PHP_METHOD(Phalcon_Validation, add) {

	zval *_0;
	zval *field_param = NULL, *validator;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field_param, &validator);

		zephir_get_strval(field, field_param);


	if ((Z_TYPE_P(validator) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "The validator must be an object");
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	zephir_array_fast_append(_0, field);
	zephir_array_fast_append(_0, validator);
	zephir_update_property_array_append(this_ptr, SL("_validators"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds filters to the field
 *
 * @param string field
 * @param array|string field
 * @return Phalcon\Validation
 */
PHP_METHOD(Phalcon_Validation, setFilters) {

	zval *field_param = NULL, *filters;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field_param, &filters);

		zephir_get_strval(field, field_param);


	zephir_update_property_array(this_ptr, SL("_filters"), field, filters TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns all the filters or a specific one
 *
 * @param string field
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation, getFilters) {

	zval *field = NULL, *filters, *fieldFilters;

	zephir_fetch_params(0, 0, 1, &field);

	if (!field) {
		field = ZEPHIR_GLOBAL(global_null);
	}


	filters = zephir_fetch_nproperty_this(this_ptr, SL("_filters"), PH_NOISY_CC);
	if ((Z_TYPE_P(field) == IS_STRING)) {
		if (zephir_array_isset_fetch(&fieldFilters, filters, field, 1 TSRMLS_CC)) {
			RETURN_CTORW(fieldFilters);
		}
		RETURN_NULL();
	}
	RETURN_CTORW(filters);

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
 * Adds default messages to validators
 *
 * @param array messages
 * @return array
 */
PHP_METHOD(Phalcon_Validation, setDefaultMessages) {

	zval *messages = NULL, *defaultMessages, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &messages);

	if (!messages) {
		ZEPHIR_CPY_WRT(messages, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(messages);
	}


	if ((Z_TYPE_P(messages) == IS_NULL)) {
		ZEPHIR_INIT_NVAR(messages);
		array_init(messages);
	}
	if ((Z_TYPE_P(messages) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "Messages must be an array");
		return;
	}
	ZEPHIR_INIT_VAR(defaultMessages);
	array_init_size(defaultMessages, 29);
	add_assoc_stringl_ex(defaultMessages, SS("Alnum"), SL("Field :field must contain only letters and numbers"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("Alpha"), SL("Field :field must contain only letters"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("Between"), SL("Field :field must be within the range of :min to :max"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("Confirmation"), SL("Field :field must be the same as :with"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("Digit"), SL("Field :field must be numeric"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("Email"), SL("Field :field must be an email address"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("ExclusionIn"), SL("Field :field must not be a part of list: :domain"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("FileEmpty"), SL("Field :field must not be empty"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("FileIniSize"), SL("File :field exceeds the maximum file size"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("FileMaxResolution"), SL("File :field must not exceed :max resolution"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("FileMinResolution"), SL("File :field must be at least :min resolution"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("FileSize"), SL("File :field exceeds the size of :max"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("FileType"), SL("File :field must be of type: :types"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("FileValid"), SL("Field :field is not valid"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("Identical"), SL("Field :field does not have the expected value"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("InclusionIn"), SL("Field :field must be a part of list: :domain"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("PresenceOf"), SL("Field :field is required"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("Regex"), SL("Field :field does not match the required format"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("TooLong"), SL("Field :field must not exceed :max characters long"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("TooShort"), SL("Field :field must be at least :min characters long"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("Uniqueness"), SL("Field :field must be unique"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("Url"), SL("Field :field must be a url"), 1);
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_array_merge(_0, &(defaultMessages), &(messages) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_defaultMessages"), _0 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "_defaultMessages");

}

/**
 * Get default message for validator type
 *
 * @param string type
 * @return string
 */
PHP_METHOD(Phalcon_Validation, getDefaultMessage) {

	zval *type_param = NULL, *_0, *_1;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(type_param) == IS_STRING) {
		type = type_param;
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultMessages"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, type, PH_NOISY | PH_READONLY TSRMLS_CC);
	RETURN_CTOR(_1);

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
 * Adds labels for fields
 *
 * @param array labels
 */
PHP_METHOD(Phalcon_Validation, setLabels) {

	zval *labels;

	zephir_fetch_params(0, 1, 0, &labels);



	if ((Z_TYPE_P(labels) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_validation_exception_ce, "Labels must be an array");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_labels"), labels TSRMLS_CC);

}

/**
 * Get label for field
 *
 * @param string field
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation, getLabel) {

	zval *field_param = NULL, *labels, *value;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	if (Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(field_param) == IS_STRING) {
		field = field_param;
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}


	labels = zephir_fetch_nproperty_this(this_ptr, SL("_labels"), PH_NOISY_CC);
	if ((Z_TYPE_P(labels) == IS_ARRAY)) {
		if (zephir_array_isset_fetch(&value, labels, field, 1 TSRMLS_CC)) {
			RETURN_CTOR(value);
		}
	}
	RETURN_MM_NULL();

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



	if ((Z_TYPE_P(entity) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_validation_exception_ce, "The entity must be an object");
		return;
	}
	if ((Z_TYPE_P(data) != IS_ARRAY)) {
		if ((Z_TYPE_P(data) != IS_OBJECT)) {
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
 * @param string field
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation, getValue) {

	zval *field_param = NULL, *entity, *method = NULL, *value = NULL, *data, *values, *filters, *fieldFilters, *dependencyInjector = NULL, *filterService, *_1;
	zval *field = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

		zephir_get_strval(field, field_param);


	entity = zephir_fetch_nproperty_this(this_ptr, SL("_entity"), PH_NOISY_CC);
	if ((Z_TYPE_P(entity) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "get", field);
		ZEPHIR_CPY_WRT(method, _0);
		if ((zephir_method_exists(entity, method TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_INIT_VAR(value);
			zephir_call_method_zval(value, entity, method);
		} else {
			if ((zephir_method_exists_ex(entity, SS("readattribute") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_INIT_NVAR(value);
				zephir_call_method_p1(value, entity, "readattribute", field);
			} else {
				ZEPHIR_INIT_NVAR(value);
				if (zephir_isset_property_zval(entity, field TSRMLS_CC)) {
					zephir_read_property_zval(&value, entity, field, PH_NOISY_CC);
				} else {
					ZVAL_NULL(value);
				}
			}
		}
		RETURN_CCTOR(value);
	}
	data = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	if ((Z_TYPE_P(data) != IS_ARRAY)) {
		if ((Z_TYPE_P(data) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "There is no data to validate");
			return;
		}
	}
	values = zephir_fetch_nproperty_this(this_ptr, SL("_values"), PH_NOISY_CC);
	ZEPHIR_OBS_NVAR(value);
	if (zephir_array_isset_fetch(&value, values, field, 0 TSRMLS_CC)) {
		RETURN_CCTOR(value);
	}
	ZEPHIR_INIT_NVAR(value);
	ZVAL_NULL(value);
	if ((Z_TYPE_P(data) == IS_ARRAY)) {
		if (zephir_array_isset(data, field)) {
			ZEPHIR_OBS_NVAR(value);
			zephir_array_fetch(&value, data, field, PH_NOISY TSRMLS_CC);
		}
	} else {
		if ((Z_TYPE_P(data) == IS_OBJECT)) {
			if (zephir_isset_property_zval(data, field TSRMLS_CC)) {
				ZEPHIR_OBS_NVAR(value);
				zephir_read_property_zval(&value, data, field, PH_NOISY_CC);
			}
		}
	}
	if ((Z_TYPE_P(value) != IS_NULL)) {
		filters = zephir_fetch_nproperty_this(this_ptr, SL("_filters"), PH_NOISY_CC);
		if ((Z_TYPE_P(filters) == IS_ARRAY)) {
			if (zephir_array_isset_fetch(&fieldFilters, filters, field, 1 TSRMLS_CC)) {
				if (zephir_is_true(fieldFilters)) {
					ZEPHIR_INIT_VAR(dependencyInjector);
					zephir_call_method(dependencyInjector, this_ptr, "getdi");
					if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
						ZEPHIR_INIT_NVAR(dependencyInjector);
						zephir_call_static(dependencyInjector, "Phalcon\\Di", "getdefault");
						if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
							ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "A dependency injector is required to obtain the 'filter' service");
							return;
						}
					}
					ZEPHIR_INIT_VAR(_1);
					ZVAL_STRING(_1, "filter", 1);
					ZEPHIR_INIT_VAR(filterService);
					zephir_call_method_p1(filterService, dependencyInjector, "getshared", _1);
					if ((Z_TYPE_P(filterService) != IS_OBJECT)) {
						ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "Returned 'filter' service is invalid");
						return;
					}
					zephir_call_method_p2(return_value, filterService, "sanitize", value, fieldFilters);
					RETURN_MM();
				}
			}
		}
		zephir_update_property_array(this_ptr, SL("_values"), field, value TSRMLS_CC);
		RETURN_CCTOR(value);
	}
	RETURN_MM_NULL();

}

