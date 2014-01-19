
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

#include "validation.h"
#include "validation/exception.h"
#include "validation/message/group.h"
#include "validation/validator.h"
#include "validation/validatorinterface.h"
#include "di/injectable.h"
#include "filterinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"

#include "interned-strings.h"

/**
 * Phalcon\Validation
 *
 * Allows to validate data using validators
 */
zend_class_entry *phalcon_validation_ce;

PHP_METHOD(Phalcon_Validation, __construct);
PHP_METHOD(Phalcon_Validation, validate);
PHP_METHOD(Phalcon_Validation, add);
PHP_METHOD(Phalcon_Validation, setFilters);
PHP_METHOD(Phalcon_Validation, getFilters);
PHP_METHOD(Phalcon_Validation, getValidators);
PHP_METHOD(Phalcon_Validation, getEntity);
PHP_METHOD(Phalcon_Validation, getMessages);
PHP_METHOD(Phalcon_Validation, appendMessage);
PHP_METHOD(Phalcon_Validation, bind);
PHP_METHOD(Phalcon_Validation, getValue);
PHP_METHOD(Phalcon_Validation, setDefaultMessages);
PHP_METHOD(Phalcon_Validation, getDefaultMessage);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, validators)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validate, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_add, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, validator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_setfilters, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_getfilters, 0, 0, 0)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_appendmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_bind, 0, 0, 2)
	ZEND_ARG_INFO(0, entity)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_getvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_setdefaultmessages, 0, 0, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_getdefaultmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_validation_method_entry[] = {
	PHP_ME(Phalcon_Validation, __construct, arginfo_phalcon_validation___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Validation, validate, arginfo_phalcon_validation_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, add, arginfo_phalcon_validation_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, setFilters, arginfo_phalcon_validation_setfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getFilters, arginfo_phalcon_validation_getfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getValidators, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getEntity, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, appendMessage, arginfo_phalcon_validation_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, bind, arginfo_phalcon_validation_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getValue, arginfo_phalcon_validation_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, setDefaultMessages, arginfo_phalcon_validation_setdefaultmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getDefaultMessage, arginfo_phalcon_validation_getdefaultmessage, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Validation initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation){

	PHALCON_REGISTER_CLASS_EX(Phalcon, Validation, validation, phalcon_di_injectable_ce, phalcon_validation_method_entry, 0);

	zend_declare_property_null(phalcon_validation_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_entity"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_validators"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_values"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_ce, SL("_defaultMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

int phalcon_validation_getdefaultmessage_helper(const zend_class_entry *ce, zval *return_value, zval *this_ptr, const char *type TSRMLS_DC)
{
	zval *t;
	if (is_phalcon_class(ce)) {
		zval *msg;
		zval *messages = phalcon_fetch_nproperty_this(this_ptr, SL("_defaultMessages"), PH_NOISY TSRMLS_CC);
		if (phalcon_array_isset_string_fetch(&msg, messages, type, strlen(type)+1)) {
			ZVAL_ZVAL(return_value, msg, 1, 0);
		}
		else {
			ZVAL_NULL(return_value);
		}

		return SUCCESS;
	}

	PHALCON_ALLOC_GHOST_ZVAL(t);
	ZVAL_STRING(t, type, 1);
	return phalcon_call_method_params(return_value, NULL, this_ptr, SL("getdefaultmessage"), zend_inline_hash_func(SS("getdefaultmessage")) TSRMLS_CC, 1, t);
}

/**
 * Phalcon\Validation constructor
 *
 * @param array $validators
 */
PHP_METHOD(Phalcon_Validation, __construct){

	zval *validators = NULL;

	phalcon_fetch_params(0, 0, 1, &validators);
	
	if (!validators) {
		validators = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(validators) != IS_NULL) {
		if (Z_TYPE_P(validators) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STRW(phalcon_validation_exception_ce, "Validators must be an array");
			return;
		}
		phalcon_update_property_this(this_ptr, SL("_validators"), validators TSRMLS_CC);
	}
	
	RETURN_ON_FAILURE(phalcon_call_method_params(NULL, NULL, getThis(), SL("setdefaultmessages"), zend_inline_hash_func(SS("setdefaultmessages")) TSRMLS_CC, 0));

	/*
	 * Check for an 'initialize' method
	 */
	if (phalcon_method_exists_ex(this_ptr, SS("initialize") TSRMLS_CC) == SUCCESS) {
		RETURN_ON_FAILURE(phalcon_call_method_params(NULL, NULL, this_ptr, SL("initialize"), zend_inline_hash_func(SS("initialize")) TSRMLS_CC, 0));
	}
}

/**
 * Validate a set of data according to a set of rules
 *
 * @param array|object $data
 * @param object $entity
 * @return Phalcon\Validation\Message\Group
 */
PHP_METHOD(Phalcon_Validation, validate){

	zval *data = NULL, *entity = NULL, *validators, *messages = NULL, *status = NULL;
	zval *scope = NULL, *attribute = NULL, *validator = NULL;
	zval *must_cancel = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &data, &entity);
	
	if (!data) {
		data = PHALCON_GLOBAL(z_null);
	}
	
	if (!entity) {
		entity = PHALCON_GLOBAL(z_null);
	}
	
	validators = phalcon_fetch_nproperty_this(this_ptr, SL("_validators"), PH_NOISY_CC);
	if (Z_TYPE_P(validators) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "There are no validators to validate");
		return;
	}
	
	/** 
	 * Clear pre-calculated values
	 */
	phalcon_update_property_null(this_ptr, SL("_values") TSRMLS_CC);
	
	/** 
	 * Implicitly creates a Phalcon\Validation\Message\Group object
	 */
	PHALCON_INIT_VAR(messages);
	object_init_ex(messages, phalcon_validation_message_group_ce);
	phalcon_call_method_noret(messages, "__construct");
	
	/** 
	 * Validation classes can implement the 'beforeValidation' callback
	 */
	if (phalcon_method_exists_ex(this_ptr, SS("beforevalidation") TSRMLS_CC) == SUCCESS) {
	
		PHALCON_INIT_VAR(status);
		phalcon_call_method_p3(status, this_ptr, "beforevalidation", data, entity, messages);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_CCTOR(status);
		}
	}
	
	phalcon_update_property_this(this_ptr, SL("_messages"), messages TSRMLS_CC);
	if (Z_TYPE_P(data) == IS_ARRAY || Z_TYPE_P(data) == IS_OBJECT) {
		phalcon_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	}
	
	phalcon_is_iterable(validators, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(scope);
	
		if (Z_TYPE_P(scope) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "The validator scope is not valid");
			return;
		}
	
		PHALCON_OBS_NVAR(attribute);
		phalcon_array_fetch_long(&attribute, scope, 0, PH_NOISY);
	
		PHALCON_OBS_NVAR(validator);
		phalcon_array_fetch_long(&validator, scope, 1, PH_NOISY);
		if (Z_TYPE_P(validator) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "One of the validators is not valid");
			return;
		}
	
		PHALCON_INIT_NVAR(status);
		phalcon_call_method_p2(status, validator, "validate", this_ptr, attribute);
	
		/** 
		 * Check if the validation must be canceled if this validator fails
		 */
		if (PHALCON_IS_FALSE(status)) {
			PHALCON_INIT_NVAR(must_cancel);
			if (FAILURE == phalcon_validation_validator_getoption_helper(Z_OBJCE_P(validator), must_cancel, validator, "cancelOnFail" TSRMLS_CC)) {
				RETURN_MM();
			}

			if (zend_is_true(must_cancel)) {
				break;
			}
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Get the messages generated by the validators
	 */
	PHALCON_OBS_NVAR(messages);
	phalcon_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (phalcon_method_exists_ex(this_ptr, SS("aftervalidation") TSRMLS_CC) == SUCCESS) {
		phalcon_call_method_p3_noret(this_ptr, "aftervalidation", data, entity, messages);
	}
	
	RETURN_CCTOR(messages);
}

/**
 * Adds a validator to a field
 *
 * @param string $attribute
 * @param Phalcon\Validation\ValidatorInterface
 * @return Phalcon\Validation
 */
PHP_METHOD(Phalcon_Validation, add){

	zval **attribute, **validator, *scope;

	phalcon_fetch_params_ex(2, 0, &attribute, &validator);

	PHALCON_ENSURE_IS_STRING(attribute);
	PHALCON_VERIFY_INTERFACE_EX(*validator, phalcon_validation_validatorinterface_ce, phalcon_validation_exception_ce, 0);
	
	PHALCON_ALLOC_GHOST_ZVAL(scope);
	array_init_size(scope, 2);
	phalcon_array_append(&scope, *attribute, 0);
	phalcon_array_append(&scope, *validator, 0);
	phalcon_update_property_array_append(this_ptr, SL("_validators"), scope TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Adds filters to the field
 *
 * @param string $attribute
 * @param array|string $attribute
 * @return Phalcon\Validation
 */
PHP_METHOD(Phalcon_Validation, setFilters){

	zval *attribute, *filters;

	phalcon_fetch_params(0, 2, 0, &attribute, &filters);
	
	phalcon_update_property_array(this_ptr, SL("_filters"), attribute, filters TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns all the filters or a specific one
 *
 * @param string $attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation, getFilters){

	zval *attribute = NULL, *filters, *attribute_filters;

	phalcon_fetch_params(0, 0, 1, &attribute);
	
	filters = phalcon_fetch_nproperty_this(this_ptr, SL("_filters"), PH_NOISY_CC);
	if (attribute && Z_TYPE_P(attribute) == IS_STRING) {
		if (phalcon_array_isset_fetch(&attribute_filters, filters, attribute)) {
			RETURN_ZVAL(attribute_filters, 1, 0);
		}

		RETURN_NULL();
	}
	
	RETURN_ZVAL(filters, 1, 0);
}

/**
 * Returns the validators added to the validation
 *
 * @return array
 */
PHP_METHOD(Phalcon_Validation, getValidators){


	RETURN_MEMBER(this_ptr, "_validators");
}

/**
 * Returns the bound entity
 *
 * @return object
 */
PHP_METHOD(Phalcon_Validation, getEntity){


	RETURN_MEMBER(this_ptr, "_entity");
}

/**
 * Returns the registered validators
 *
 * @return Phalcon\Validation\Message\Group
 */
PHP_METHOD(Phalcon_Validation, getMessages){


	RETURN_MEMBER(this_ptr, "_messages");
}

/**
 * Appends a message to the messages list
 *
 * @param Phalcon\Validation\MessageInterface $message
 * @return Phalcon\Validation
 */
PHP_METHOD(Phalcon_Validation, appendMessage){

	zval *message, *messages;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);
	
	messages = phalcon_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
	phalcon_call_method_p1_noret(messages, "appendmessage", message);
	RETURN_THIS();
}

/**
 * Assigns the data to an entity
 * The entity is used to obtain the validation values
 *
 * @param object $entity
 * @param object|array $data
 * @return Phalcon\Validation
 */
PHP_METHOD(Phalcon_Validation, bind){

	zval *entity, *data;

	phalcon_fetch_params(0, 2, 0, &entity, &data);
	
	if (Z_TYPE_P(entity) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_validation_exception_ce, "The entity must be an object");
		return;
	}
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		if (Z_TYPE_P(data) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_validation_exception_ce, "The data to validate must be an array or object");
			return;
		}
	}
	
	phalcon_update_property_this(this_ptr, SL("_entity"), entity TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Gets the a value to validate in the array/object data source
 *
 * @param string $attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation, getValue){

	zval *attribute, *entity, *method, *value = NULL, *data, *values;
	zval *filters, *field_filters, *service_name;
	zval *dependency_injector = NULL, *filter_service;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &attribute);
	
	PHALCON_OBS_VAR(entity);
	phalcon_read_property_this(&entity, this_ptr, SL("_entity"), PH_NOISY_CC);
	
	/** 
	 * If the entity is an object use it to retrieve the values
	 */
	if (Z_TYPE_P(entity) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(method);
		PHALCON_CONCAT_SV(method, "get", attribute);
		zend_str_tolower(Z_STRVAL_P(method), Z_STRLEN_P(method));
		if (phalcon_method_exists_ex(entity, Z_STRVAL_P(method), Z_STRLEN_P(method)+1 TSRMLS_CC) == SUCCESS) {
			PHALCON_INIT_VAR(value);
			phalcon_call_method(value, entity, Z_STRVAL_P(method));
		} else if (phalcon_method_exists_ex(entity, SS("readattribute") TSRMLS_CC) == SUCCESS) {
			PHALCON_INIT_VAR(value);
			phalcon_call_method_p1(value, entity, "readattribute", attribute);
		} else if (phalcon_isset_property_zval(entity, attribute TSRMLS_CC)) {
			PHALCON_OBS_VAR(value);
			phalcon_read_property_zval(&value, entity, attribute, PH_NOISY_CC);
		} else {
			PHALCON_INIT_VAR(value);
		}
	
		RETURN_CCTOR(value);
	}
	
	PHALCON_OBS_VAR(data);
	phalcon_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		if (Z_TYPE_P(data) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "There are no data to validate");
			return;
		}
	}
	
	/** 
	 * Check if there is a calculated value
	 */
	PHALCON_OBS_VAR(values);
	phalcon_read_property_this(&values, this_ptr, SL("_values"), PH_NOISY_CC);
	if (phalcon_array_isset(values, attribute)) {
		PHALCON_OBS_NVAR(value);
		phalcon_array_fetch(&value, values, attribute, PH_NOISY);
		RETURN_CCTOR(value);
	}
	
	PHALCON_INIT_NVAR(value);
	
	if (Z_TYPE_P(data) == IS_ARRAY) { 
		if (phalcon_array_isset(data, attribute)) {
			PHALCON_OBS_NVAR(value);
			phalcon_array_fetch(&value, data, attribute, PH_NOISY);
		}
	} else {
		if (Z_TYPE_P(data) == IS_OBJECT) {
			if (phalcon_isset_property_zval(data, attribute TSRMLS_CC)) {
				PHALCON_OBS_NVAR(value);
				phalcon_read_property_zval(&value, data, attribute, PH_NOISY_CC);
			}
		}
	}
	
	if (Z_TYPE_P(value) != IS_NULL) {
	
		PHALCON_OBS_VAR(filters);
		phalcon_read_property_this(&filters, this_ptr, SL("_filters"), PH_NOISY_CC);
		if (Z_TYPE_P(filters) == IS_ARRAY) { 
			if (phalcon_array_isset(filters, attribute)) {
	
				PHALCON_OBS_VAR(field_filters);
				phalcon_array_fetch(&field_filters, filters, attribute, PH_NOISY);
				if (zend_is_true(field_filters)) {
	
					PHALCON_INIT_VAR(service_name);
					PHALCON_ZVAL_MAYBE_INTERNED_STRING(service_name, phalcon_interned_filter);
	
					PHALCON_INIT_VAR(dependency_injector);
					phalcon_call_method(dependency_injector, this_ptr, "getdi");
					if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
	
						PHALCON_INIT_NVAR(dependency_injector);
						phalcon_call_static(dependency_injector, "phalcon\\di", "getdefault");
	
						if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
							PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "A dependency injector is required to obtain the 'filter' service");
							return;
						}
					}
	
					PHALCON_INIT_VAR(filter_service);
					phalcon_call_method_p1(filter_service, dependency_injector, "getshared", service_name);
					if (Z_TYPE_P(filter_service) != IS_OBJECT) {
						PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "Returned 'filter' service is invalid");
						return;
					}
	
					PHALCON_VERIFY_INTERFACE(filter_service, phalcon_filterinterface_ce);
					phalcon_call_method_p2(return_value, filter_service, "sanitize", value, field_filters);
					RETURN_MM();
				}
			}
		}
	
		/** 
		 * Cache the calculated value
		 */
		phalcon_update_property_array(this_ptr, SL("_values"), attribute, value TSRMLS_CC);
	
		RETURN_CCTOR(value);
	}
	
	RETURN_MM_NULL();
}

PHP_METHOD(Phalcon_Validation, setDefaultMessages)
{
	zval *messages = NULL, *m, *default_messages;

	phalcon_fetch_params(0, 0, 0, &messages);

	if (messages && Z_TYPE_P(messages) != IS_NULL && Z_TYPE_P(messages) != IS_ARRAY) {
		zend_throw_exception_ex(phalcon_validation_exception_ce, 0 TSRMLS_CC, "Messages must be an array");
		return;
	}

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(default_messages);
	array_init_size(default_messages, 22);

	add_assoc_stringl_ex(default_messages, SS("Alnum"),             SL("Field :field must contain only alphanumeric characters"), 1);
	add_assoc_stringl_ex(default_messages, SS("Alpha"),             SL("Field :field must contain only letters"), 1);
	add_assoc_stringl_ex(default_messages, SS("Between"),           SL(":field is not in the valid range"), 1);
	add_assoc_stringl_ex(default_messages, SS("Confirmation"),      SL("Values of :field and :with do not match"), 1);
	add_assoc_stringl_ex(default_messages, SS("Digit"),             SL("Field :field must be numeric"), 1);
	add_assoc_stringl_ex(default_messages, SS("Email"),             SL("Value of field :field is not a valid e-mail"), 1);
	add_assoc_stringl_ex(default_messages, SS("ExclusionIn"),       SL("Value of field :field must not be a part of the list: :domain"), 1);
	add_assoc_stringl_ex(default_messages, SS("FileValid"),         SL("File :field is not valid"), 1);
	add_assoc_stringl_ex(default_messages, SS("FileEmpty"),         SL("File :field must not be empty"), 1);
	add_assoc_stringl_ex(default_messages, SS("FileIniSize"),       SL("The uploaded file exceeds the maximum filesize"), 1);
	add_assoc_stringl_ex(default_messages, SS("FileSize"),          SL("Maximum filesize of file :field is :max"), 1);
	add_assoc_stringl_ex(default_messages, SS("FileType"),          SL("Type of :field is not valid"), 1);
	add_assoc_stringl_ex(default_messages, SS("FileMinResolution"), SL("Minimum resolution of :field is :min"), 1);
	add_assoc_stringl_ex(default_messages, SS("FileMaxResolution"), SL("Maximum resolution of :field is :max"), 1);
	add_assoc_stringl_ex(default_messages, SS("Identical"),         SL(":field does not have the expected value"), 1);
	add_assoc_stringl_ex(default_messages, SS("InclusionIn"),       SL("Value of field :field must be a part of the list: :domain"), 1);
	add_assoc_stringl_ex(default_messages, SS("PresenceOf"),        SL(":field is required"), 1);
	add_assoc_stringl_ex(default_messages, SS("Regex"),             SL("Value of field :field does not match the regular expression"), 1);
	add_assoc_stringl_ex(default_messages, SS("TooLong"),           SL("Value of field :field exceeds the maximum :max characters"), 1);
	add_assoc_stringl_ex(default_messages, SS("TooShort"),          SL("Value of field :field is less than the minimum :min characters"), 1);
	add_assoc_stringl_ex(default_messages, SS("Uniqueness"),        SL(":field is already taken"), 1);
	add_assoc_stringl_ex(default_messages, SS("Url"),               SL(":field is not a valid URL"), 1);

	if (!messages || Z_TYPE_P(messages) == IS_NULL) {
		phalcon_update_property_this(getThis(), SL("_defaultMessages"), default_messages TSRMLS_CC);
	}
	else {
		PHALCON_INIT_VAR(m);
		phalcon_fast_array_merge(m, &default_messages, &messages TSRMLS_CC);
		phalcon_update_property_this(getThis(), SL("_defaultMessages"), m TSRMLS_CC);
	}

	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Validation, getDefaultMessage)
{
	zval *type, *messages, *msg;

	phalcon_fetch_params(0, 1, 0, &type);

	messages = phalcon_fetch_nproperty_this(getThis(), SL("_defaultMessages"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_fetch(&msg, messages, type)) {
		RETURN_ZVAL(msg, 1, 0);
	}

	RETURN_NULL();
}
