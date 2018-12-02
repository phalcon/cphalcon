
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Phalcon\Validation
 *
 * Allows to validate data using custom or built-in validators
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon, Validation, phalcon, validation, phalcon_di_injectable_ce, phalcon_validation_method_entry, 0);

	zend_declare_property_null(phalcon_validation_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_ce, SL("_entity"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_ce, SL("_validators"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_ce, SL("_combinedFieldsValidators"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_ce, SL("_defaultMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_ce, SL("_labels"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_ce, SL("_values"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_validation_ce->create_object = zephir_init_properties_Phalcon_Validation;

	zend_class_implements(phalcon_validation_ce TSRMLS_CC, 1, phalcon_validationinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Validation, getData) {

	

	RETURN_MEMBER(getThis(), "_data");

}

PHP_METHOD(Phalcon_Validation, setValidators) {

	zval *validators;

	zephir_fetch_params(0, 1, 0, &validators);



	zephir_update_property_this(getThis(), SL("_validators"), validators TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Phalcon\Validation constructor
 */
PHP_METHOD(Phalcon_Validation, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validators_param = NULL, *_0$$3 = NULL, *_1$$3 = NULL, *_2$$3 = NULL, *_3$$3 = NULL;
	zval *validators = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &validators_param);

	if (!validators_param) {
		ZEPHIR_INIT_VAR(validators);
		array_init(validators);
	} else {
		zephir_get_arrval(validators, validators_param);
	}


	if (zephir_fast_count_int(validators TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZEPHIR_INIT_NVAR(_0$$3);
		zephir_create_closure_ex(_0$$3, NULL, phalcon_1__closure_ce, SS("__invoke") TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "array_filter", NULL, 475, validators, _0$$3);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_validators"), _1$$3 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_INIT_NVAR(_2$$3);
		zephir_create_closure_ex(_2$$3, NULL, phalcon_2__closure_ce, SS("__invoke") TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "array_filter", NULL, 475, validators, _2$$3);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_combinedFieldsValidators"), _3$$3 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultmessages", NULL, 0);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, SS("initialize") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Validate a set of data according to a set of rules
 *
 * @param array|object data
 * @param object entity
 * @return \Phalcon\Validation\Message\Group
 */
PHP_METHOD(Phalcon_Validation, validate) {

	zend_bool _0$$7;
	HashTable *_2, *_10;
	HashPosition _1, _9;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *entity = NULL, *validators = NULL, *messages = NULL, *scope = NULL, *field = NULL, *validator = NULL, *status = NULL, *combinedFieldsValidators = NULL, **_3, **_11, *_4$$10 = NULL, *_6$$10 = NULL, *_7$$14 = NULL, *_8$$14 = NULL, *_12$$16 = NULL, *_13$$16 = NULL, *_14$$20 = NULL, *_15$$20 = NULL, *_16$$22;

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
	ZEPHIR_OBS_VAR(combinedFieldsValidators);
	zephir_read_property_this(&combinedFieldsValidators, this_ptr, SL("_combinedFieldsValidators"), PH_NOISY_CC);
	if (Z_TYPE_P(validators) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "There are no validators to validate", "phalcon/validation.zep", 94);
		return;
	}
	zephir_update_property_this(getThis(), SL("_values"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_INIT_VAR(messages);
	object_init_ex(messages, phalcon_validation_message_group_ce);
	ZEPHIR_CALL_METHOD(NULL, messages, "__construct", NULL, 3);
	zephir_check_call_status();
	if (Z_TYPE_P(entity) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setentity", NULL, 0, entity);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(this_ptr, SS("beforevalidation") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&status, this_ptr, "beforevalidation", NULL, 0, data, entity, messages);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(status)) {
			RETURN_CCTOR(status);
		}
	}
	zephir_update_property_this(getThis(), SL("_messages"), messages TSRMLS_CC);
	if (Z_TYPE_P(data) != IS_NULL) {
		_0$$7 = Z_TYPE_P(data) == IS_ARRAY;
		if (!(_0$$7)) {
			_0$$7 = Z_TYPE_P(data) == IS_OBJECT;
		}
		if (_0$$7) {
			zephir_update_property_this(getThis(), SL("_data"), data TSRMLS_CC);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Invalid data to validate", "phalcon/validation.zep", 127);
			return;
		}
	}
	zephir_is_iterable(validators, &_2, &_1, 0, 0, "phalcon/validation.zep", 161);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(scope, _3);
		if (Z_TYPE_P(scope) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The validator scope is not valid", "phalcon/validation.zep", 134);
			return;
		}
		ZEPHIR_OBS_NVAR(field);
		zephir_array_fetch_long(&field, scope, 0, PH_NOISY, "phalcon/validation.zep", 137 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(validator);
		zephir_array_fetch_long(&validator, scope, 1, PH_NOISY, "phalcon/validation.zep", 138 TSRMLS_CC);
		if (Z_TYPE_P(validator) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "One of the validators is not valid", "phalcon/validation.zep", 141);
			return;
		}
		ZEPHIR_CALL_METHOD(&_4$$10, this_ptr, "prechecking", &_5, 0, field, validator);
		zephir_check_call_status();
		if (zephir_is_true(_4$$10)) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&_6$$10, validator, "validate", NULL, 0, this_ptr, field);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_6$$10)) {
			ZEPHIR_INIT_NVAR(_8$$14);
			ZVAL_STRING(_8$$14, "cancelOnFail", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_7$$14, validator, "getoption", NULL, 0, _8$$14);
			zephir_check_temp_parameter(_8$$14);
			zephir_check_call_status();
			if (zephir_is_true(_7$$14)) {
				break;
			}
		}
	}
	zephir_is_iterable(combinedFieldsValidators, &_10, &_9, 0, 0, "phalcon/validation.zep", 193);
	for (
	  ; zend_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
	  ; zend_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HVALUE(scope, _11);
		if (Z_TYPE_P(scope) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The validator scope is not valid", "phalcon/validation.zep", 163);
			return;
		}
		ZEPHIR_OBS_NVAR(field);
		zephir_array_fetch_long(&field, scope, 0, PH_NOISY, "phalcon/validation.zep", 166 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(validator);
		zephir_array_fetch_long(&validator, scope, 1, PH_NOISY, "phalcon/validation.zep", 167 TSRMLS_CC);
		if (Z_TYPE_P(validator) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "One of the validators is not valid", "phalcon/validation.zep", 170);
			return;
		}
		ZEPHIR_CALL_METHOD(&_12$$16, this_ptr, "prechecking", &_5, 0, field, validator);
		zephir_check_call_status();
		if (zephir_is_true(_12$$16)) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&_13$$16, validator, "validate", NULL, 0, this_ptr, field);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_13$$16)) {
			ZEPHIR_INIT_NVAR(_15$$20);
			ZVAL_STRING(_15$$20, "cancelOnFail", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_14$$20, validator, "getoption", NULL, 0, _15$$20);
			zephir_check_temp_parameter(_15$$20);
			zephir_check_call_status();
			if (zephir_is_true(_14$$20)) {
				break;
			}
		}
	}
	if ((zephir_method_exists_ex(this_ptr, SS("aftervalidation") TSRMLS_CC) == SUCCESS)) {
		_16$$22 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "aftervalidation", NULL, 0, data, entity, _16$$22);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "_messages");

}

/**
 * Adds a validator to a field
 */
PHP_METHOD(Phalcon_Validation, add) {

	HashTable *_2$$5;
	HashPosition _1$$5;
	zval *_0$$4, *_4$$6 = NULL, *_5$$7;
	zval *field, *validator, *singleField = NULL, **_3$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field, &validator);



	if (Z_TYPE_P(field) == IS_ARRAY) {
		if (zephir_instance_of_ev(validator, phalcon_validation_combinedfieldsvalidator_ce TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_0$$4);
			zephir_create_array(_0$$4, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(_0$$4, field);
			zephir_array_fast_append(_0$$4, validator);
			zephir_update_property_array_append(this_ptr, SL("_combinedFieldsValidators"), _0$$4 TSRMLS_CC);
		} else {
			zephir_is_iterable(field, &_2$$5, &_1$$5, 0, 0, "phalcon/validation.zep", 215);
			for (
			  ; zend_hash_get_current_data_ex(_2$$5, (void**) &_3$$5, &_1$$5) == SUCCESS
			  ; zend_hash_move_forward_ex(_2$$5, &_1$$5)
			) {
				ZEPHIR_GET_HVALUE(singleField, _3$$5);
				ZEPHIR_INIT_NVAR(_4$$6);
				zephir_create_array(_4$$6, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(_4$$6, singleField);
				zephir_array_fast_append(_4$$6, validator);
				zephir_update_property_array_append(this_ptr, SL("_validators"), _4$$6 TSRMLS_CC);
			}
		}
	} else if (Z_TYPE_P(field) == IS_STRING) {
		ZEPHIR_INIT_VAR(_5$$7);
		zephir_create_array(_5$$7, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_5$$7, field);
		zephir_array_fast_append(_5$$7, validator);
		zephir_update_property_array_append(this_ptr, SL("_validators"), _5$$7 TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Field must be passed as array of fields or string", "phalcon/validation.zep", 221);
		return;
	}
	RETURN_THIS();

}

/**
 * Alias of `add` method
 */
PHP_METHOD(Phalcon_Validation, rule) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, *validator;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field, &validator);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, field, validator);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds the validators to a field
 */
PHP_METHOD(Phalcon_Validation, rules) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validators = NULL;
	zval *field, *validators_param = NULL, *validator = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field, &validators_param);

	validators = validators_param;


	zephir_is_iterable(validators, &_1, &_0, 0, 0, "phalcon/validation.zep", 247);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(validator, _2);
		if (zephir_instance_of_ev(validator, phalcon_validation_validatorinterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_3, 0, field, validator);
			zephir_check_call_status();
		}
	}
	RETURN_THIS();

}

/**
 * Adds filters to the field
 *
 * @param array|string field
 * @param array|string filters
 * @return \Phalcon\Validation
 */
PHP_METHOD(Phalcon_Validation, setFilters) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zval *field, *filters, *singleField = NULL, **_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field, &filters);



	if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_is_iterable(field, &_1$$3, &_0$$3, 0, 0, "phalcon/validation.zep", 264);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(singleField, _2$$3);
			zephir_update_property_array(this_ptr, SL("_filters"), singleField, filters TSRMLS_CC);
		}
	} else if (Z_TYPE_P(field) == IS_STRING) {
		zephir_update_property_array(this_ptr, SL("_filters"), field, filters TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Field must be passed as array of fields or string.", "phalcon/validation.zep", 269);
		return;
	}
	RETURN_THIS();

}

/**
 * Returns all the filters or a specific one
 *
 * @param string field
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation, getFilters) {

	zend_bool _0;
	zval *field_param = NULL, *filters = NULL, *fieldFilters = NULL;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &field_param);

	if (!field_param) {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	} else {
		zephir_get_strval(field, field_param);
	}


	filters = zephir_fetch_nproperty_this(this_ptr, SL("_filters"), PH_NOISY_CC);
	_0 = ZEPHIR_IS_STRING_IDENTICAL(field, "");
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING_IDENTICAL(field, "");
	}
	if (_0) {
		RETURN_CTOR(filters);
	}
	if (!(zephir_array_isset_fetch(&fieldFilters, filters, field, 1 TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	RETURN_CTOR(fieldFilters);

}

/**
 * Returns the validators added to the validation
 */
PHP_METHOD(Phalcon_Validation, getValidators) {

	

	RETURN_MEMBER(getThis(), "_validators");

}

/**
 * Sets the bound entity
 *
 * @param object entity
 */
PHP_METHOD(Phalcon_Validation, setEntity) {

	zval *entity;

	zephir_fetch_params(0, 1, 0, &entity);



	if (Z_TYPE_P(entity) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_validation_exception_ce, "Entity must be an object", "phalcon/validation.zep", 312);
		return;
	}
	zephir_update_property_this(getThis(), SL("_entity"), entity TSRMLS_CC);

}

/**
 * Returns the bound entity
 *
 * @return object
 */
PHP_METHOD(Phalcon_Validation, getEntity) {

	

	RETURN_MEMBER(getThis(), "_entity");

}

/**
 * Adds default messages to validators
 */
PHP_METHOD(Phalcon_Validation, setDefaultMessages) {

	zval *messages_param = NULL, *defaultMessages = NULL, *_0;
	zval *messages = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &messages_param);

	if (!messages_param) {
		ZEPHIR_INIT_VAR(messages);
		array_init(messages);
	} else {
		zephir_get_arrval(messages, messages_param);
	}


	ZEPHIR_INIT_VAR(defaultMessages);
	zephir_create_array(defaultMessages, 25, 0 TSRMLS_CC);
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
	add_assoc_stringl_ex(defaultMessages, SS("Numericality"), SL("Field :field does not have a valid numeric format"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("PresenceOf"), SL("Field :field is required"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("Regex"), SL("Field :field does not match the required format"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("TooLong"), SL("Field :field must not exceed :max characters long"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("TooShort"), SL("Field :field must be at least :min characters long"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("Uniqueness"), SL("Field :field must be unique"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("Url"), SL("Field :field must be a url"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("CreditCard"), SL("Field :field is not valid for a credit card number"), 1);
	add_assoc_stringl_ex(defaultMessages, SS("Date"), SL("Field :field is not a valid date"), 1);
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_array_merge(_0, &(defaultMessages), &(messages) TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_defaultMessages"), _0 TSRMLS_CC);
	RETURN_MM_MEMBER(getThis(), "_defaultMessages");

}

/**
 * Get default message for validator type
 */
PHP_METHOD(Phalcon_Validation, getDefaultMessage) {

	zval *type_param = NULL, *defaultMessage = NULL, *_0;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultMessages"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&defaultMessage, _0, type, 1 TSRMLS_CC)) {
		RETURN_CTOR(defaultMessage);
	}
	RETURN_MM_STRING("", 1);

}

/**
 * Returns the registered validators
 */
PHP_METHOD(Phalcon_Validation, getMessages) {

	

	RETURN_MEMBER(getThis(), "_messages");

}

/**
 * Adds labels for fields
 */
PHP_METHOD(Phalcon_Validation, setLabels) {

	zval *labels_param = NULL;
	zval *labels = NULL;

	zephir_fetch_params(0, 1, 0, &labels_param);

	labels = labels_param;


	zephir_update_property_this(getThis(), SL("_labels"), labels TSRMLS_CC);

}

/**
 * Get label for field
 *
 * @param string field
 * @return string
 */
PHP_METHOD(Phalcon_Validation, getLabel) {

	zval *field, *labels = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field);



	ZEPHIR_OBS_VAR(labels);
	zephir_read_property_this(&labels, this_ptr, SL("_labels"), PH_NOISY_CC);
	if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_fast_join_str(return_value, SL(", "), field TSRMLS_CC);
		RETURN_MM();
	}
	if (zephir_array_isset_fetch(&value, labels, field, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(field, 1, 0);
	RETURN_MM();

}

/**
 * Appends a message to the messages list
 */
PHP_METHOD(Phalcon_Validation, appendMessage) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, *messages = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_OBS_VAR(messages);
	zephir_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (Z_TYPE_P(messages) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(messages);
		object_init_ex(messages, phalcon_validation_message_group_ce);
		ZEPHIR_CALL_METHOD(NULL, messages, "__construct", NULL, 3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, messages, "appendmessage", NULL, 476, message);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_messages"), messages TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Assigns the data to an entity
 * The entity is used to obtain the validation values
 *
 * @param object entity
 * @param array|object data
 * @return \Phalcon\Validation
 */
PHP_METHOD(Phalcon_Validation, bind) {

	zend_bool _0;
	zval *entity, *data;

	zephir_fetch_params(0, 2, 0, &entity, &data);



	if (Z_TYPE_P(entity) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_validation_exception_ce, "Entity must be an object", "phalcon/validation.zep", 450);
		return;
	}
	_0 = Z_TYPE_P(data) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(data) != IS_OBJECT;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_validation_exception_ce, "Data to validate must be an array or object", "phalcon/validation.zep", 454);
		return;
	}
	zephir_update_property_this(getThis(), SL("_entity"), entity TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_data"), data TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Gets the a value to validate in the array/object data source
 *
 * @param string field
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation, getValue) {

	zend_bool _0$$10;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *entity = NULL, *method = NULL, *value = NULL, *data = NULL, *values = NULL, *filters = NULL, *fieldFilters = NULL, *dependencyInjector = NULL, *filterService = NULL, *camelizedField = NULL, *_2$$20, *_3$$20 = NULL, *_4$$28 = NULL;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	zephir_get_strval(field, field_param);


	ZEPHIR_OBS_VAR(entity);
	zephir_read_property_this(&entity, this_ptr, SL("_entity"), PH_NOISY_CC);
	if (Z_TYPE_P(entity) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(camelizedField);
		zephir_camelize(camelizedField, field, NULL  );
		ZEPHIR_INIT_VAR(method);
		ZEPHIR_CONCAT_SV(method, "get", camelizedField);
		if ((zephir_method_exists(entity, method TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_CALL_METHOD_ZVAL(&value, entity, method, NULL, 0);
			zephir_check_call_status();
		} else {
			if ((zephir_method_exists_ex(entity, SS("readattribute") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&value, entity, "readattribute", NULL, 0, field);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(value);
				if (zephir_isset_property_zval(entity, field TSRMLS_CC)) {
					zephir_read_property_zval(&value, entity, field, PH_NOISY_CC);
				} else {
					ZVAL_NULL(value);
				}
			}
		}
	} else {
		ZEPHIR_OBS_VAR(data);
		zephir_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
		_0$$10 = Z_TYPE_P(data) != IS_ARRAY;
		if (_0$$10) {
			_0$$10 = Z_TYPE_P(data) != IS_OBJECT;
		}
		if (_0$$10) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "There is no data to validate", "phalcon/validation.zep", 499);
			return;
		}
		ZEPHIR_OBS_VAR(values);
		zephir_read_property_this(&values, this_ptr, SL("_values"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(value);
		if (zephir_array_isset_fetch(&value, values, field, 0 TSRMLS_CC)) {
			RETURN_CCTOR(value);
		}
		ZEPHIR_INIT_NVAR(value);
		ZVAL_NULL(value);
		if (Z_TYPE_P(data) == IS_ARRAY) {
			if (zephir_array_isset(data, field)) {
				ZEPHIR_OBS_NVAR(value);
				zephir_array_fetch(&value, data, field, PH_NOISY, "phalcon/validation.zep", 511 TSRMLS_CC);
			}
		} else {
			if (Z_TYPE_P(data) == IS_OBJECT) {
				if (zephir_isset_property_zval(data, field TSRMLS_CC)) {
					ZEPHIR_OBS_NVAR(value);
					zephir_read_property_zval(&value, data, field, PH_NOISY_CC);
				}
			}
		}
	}
	if (Z_TYPE_P(value) == IS_NULL) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(filters);
	zephir_read_property_this(&filters, this_ptr, SL("_filters"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(fieldFilters);
	if (zephir_array_isset_fetch(&fieldFilters, filters, field, 0 TSRMLS_CC)) {
		if (zephir_is_true(fieldFilters)) {
			ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
				ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_1, 1);
				zephir_check_call_status();
				if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "A dependency injector is required to obtain the 'filter' service", "phalcon/validation.zep", 536);
					return;
				}
			}
			ZEPHIR_INIT_VAR(_2$$20);
			ZVAL_STRING(_2$$20, "filter", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&filterService, dependencyInjector, "getshared", NULL, 0, _2$$20);
			zephir_check_temp_parameter(_2$$20);
			zephir_check_call_status();
			if (Z_TYPE_P(filterService) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Returned 'filter' service is invalid", "phalcon/validation.zep", 542);
				return;
			}
			ZEPHIR_CALL_METHOD(&_3$$20, filterService, "sanitize", NULL, 0, value, fieldFilters);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(value, _3$$20);
			if (Z_TYPE_P(entity) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(method);
				ZEPHIR_CONCAT_SV(method, "set", camelizedField);
				if ((zephir_method_exists(entity, method TSRMLS_CC)  == SUCCESS)) {
					ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, method, NULL, 0, value);
					zephir_check_call_status();
				} else {
					if ((zephir_method_exists_ex(entity, SS("writeattribute") TSRMLS_CC) == SUCCESS)) {
						ZEPHIR_CALL_METHOD(NULL, entity, "writeattribute", NULL, 0, field, value);
						zephir_check_call_status();
					} else {
						ZEPHIR_CALL_FUNCTION(&_4$$28, "property_exists", NULL, 341, entity, field);
						zephir_check_call_status();
						if (zephir_is_true(_4$$28)) {
							zephir_update_property_zval_zval(entity, field, value TSRMLS_CC);
						}
					}
				}
			}
			RETURN_CCTOR(value);
		}
	}
	if (Z_TYPE_P(entity) != IS_OBJECT) {
		zephir_update_property_array(this_ptr, SL("_values"), field, value TSRMLS_CC);
	}
	RETURN_CCTOR(value);

}

/**
 * Internal validations, if it returns true, then skip the current validator
 */
PHP_METHOD(Phalcon_Validation, preChecking) {

	zval *_13$$13;
	zend_bool _9$$10, _10$$10, _11$$7;
	HashTable *_1$$3, *_7$$9;
	HashPosition _0$$3, _6$$9;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, *validator, *singleField = NULL, *allowEmpty = NULL, *emptyValue = NULL, *value = NULL, *result = NULL, **_2$$3, *_4$$6, *_5$$6, **_8$$9, *raw$$7 = NULL, *_12$$13 = NULL, *_14$$13 = NULL, *_15$$13 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field, &validator);



	if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_is_iterable(field, &_1$$3, &_0$$3, 0, 0, "phalcon/validation.zep", 591);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(singleField, _2$$3);
			ZEPHIR_CALL_METHOD(&result, this_ptr, "prechecking", &_3, 477, singleField, validator);
			zephir_check_call_status();
			if (zephir_is_true(result)) {
				RETURN_CCTOR(result);
			}
		}
	} else {
		ZEPHIR_INIT_VAR(_4$$6);
		ZVAL_STRING(_4$$6, "allowEmpty", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_5$$6);
		ZVAL_BOOL(_5$$6, 0);
		ZEPHIR_CALL_METHOD(&allowEmpty, validator, "getoption", NULL, 0, _4$$6, _5$$6);
		zephir_check_temp_parameter(_4$$6);
		zephir_check_call_status();
		if (zephir_is_true(allowEmpty)) {
			if ((zephir_method_exists_ex(validator, SS("isallowempty") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_RETURN_CALL_METHOD(validator, "isallowempty", NULL, 0, this_ptr, field);
				zephir_check_call_status();
				RETURN_MM();
			}
			ZEPHIR_CALL_METHOD(&value, this_ptr, "getvalue", NULL, 0, field);
			zephir_check_call_status();
			if (Z_TYPE_P(allowEmpty) == IS_ARRAY) {
				zephir_is_iterable(allowEmpty, &_7$$9, &_6$$9, 0, 0, "phalcon/validation.zep", 611);
				for (
				  ; zend_hash_get_current_data_ex(_7$$9, (void**) &_8$$9, &_6$$9) == SUCCESS
				  ; zend_hash_move_forward_ex(_7$$9, &_6$$9)
				) {
					ZEPHIR_GET_HVALUE(emptyValue, _8$$9);
					_9$$10 = Z_TYPE_P(emptyValue) == IS_OBJECT;
					if (_9$$10) {
						_9$$10 = Z_TYPE_P(value) == IS_OBJECT;
					}
					_10$$10 = _9$$10;
					if (_10$$10) {
						_10$$10 = ZEPHIR_IS_EQUAL(emptyValue, value);
					}
					if (ZEPHIR_IS_IDENTICAL(emptyValue, value)) {
						RETURN_MM_BOOL(1);
					} else if (_10$$10) {
						RETURN_MM_BOOL(1);
					}
				}
				RETURN_MM_BOOL(0);
			}
			_11$$7 = Z_TYPE_P(value) == IS_OBJECT;
			if (_11$$7) {
				_11$$7 = (zephir_method_exists_ex(value, SS("__tostring") TSRMLS_CC) == SUCCESS);
			}
			if (UNEXPECTED(_11$$7)) {
				ZEPHIR_CALL_METHOD(&_12$$13, value, "__tostring", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(raw$$7);
				zephir_fast_strtolower(raw$$7, _12$$13);
				ZEPHIR_INIT_VAR(_13$$13);
				zephir_create_array(_13$$13, 3, 0 TSRMLS_CC);
				ZEPHIR_INIT_VAR(_14$$13);
				ZVAL_STRING(_14$$13, "null", 1);
				zephir_array_fast_append(_13$$13, _14$$13);
				ZEPHIR_INIT_NVAR(_14$$13);
				ZVAL_STRING(_14$$13, "false", 1);
				zephir_array_fast_append(_13$$13, _14$$13);
				ZEPHIR_INIT_NVAR(_14$$13);
				ZVAL_STRING(_14$$13, "", 1);
				zephir_array_fast_append(_13$$13, _14$$13);
				ZEPHIR_CALL_FUNCTION(&_15$$13, "in_array", NULL, 397, raw$$7, _13$$13, ZEPHIR_GLOBAL(global_true));
				zephir_check_call_status();
				if (zephir_is_true(_15$$13)) {
					RETURN_MM_BOOL(1);
				}
			}
			RETURN_MM_BOOL(ZEPHIR_IS_EMPTY(value));
		}
	}
	RETURN_MM_BOOL(0);

}

zend_object_value zephir_init_properties_Phalcon_Validation(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_4, *_6, *_1$$3, *_3$$4, *_5$$5, *_7$$6;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_labels"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_labels"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_filters"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(getThis(), SL("_filters"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_combinedFieldsValidators"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(getThis(), SL("_combinedFieldsValidators"), _5$$5 TSRMLS_CC);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_validators"), PH_NOISY_CC);
		if (Z_TYPE_P(_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(_7$$6);
			array_init(_7$$6);
			zephir_update_property_this(getThis(), SL("_validators"), _7$$6 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

