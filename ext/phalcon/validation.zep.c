
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
#include "kernel/variables.h"
#include "kernel/hash.h"
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

PHP_METHOD(Phalcon_Validation, setValidators) {

	zval *validators;

	zephir_fetch_params(0, 1, 0, &validators);



	zephir_update_property_this(this_ptr, SL("_validators"), validators TSRMLS_CC);

}

/**
 * Phalcon\Validation constructor
 */
PHP_METHOD(Phalcon_Validation, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *validators_param = NULL, *_0$$3 = NULL, *_1$$3 = NULL, *_3$$3 = NULL, *_4$$3 = NULL;
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
		zephir_create_closure_ex(_0$$3, NULL, phalcon_0__closure_ce, SS("__invoke") TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "array_filter", &_2, 460, validators, _0$$3);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_validators"), _1$$3 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_INIT_NVAR(_3$$3);
		zephir_create_closure_ex(_3$$3, NULL, phalcon_1__closure_ce, SS("__invoke") TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "array_filter", &_2, 460, validators, _3$$3);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_combinedFieldsValidators"), _4$$3 TSRMLS_CC);
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
	HashTable *_2, *_10$$16;
	HashPosition _1, _9$$16;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *entity = NULL, *validators = NULL, *messages = NULL, *scope = NULL, *field = NULL, *validator = NULL, *status = NULL, *combinedFieldsValidators = NULL, **_3, *_4$$10 = NULL, *_6$$10 = NULL, *_7$$14 = NULL, *_8$$14 = NULL, **_11$$16, *_12$$17 = NULL, *_13$$17 = NULL, *_14$$22 = NULL, *_15$$22 = NULL, *_16$$24;

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
	zephir_update_property_this(this_ptr, SL("_values"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
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
	zephir_update_property_this(this_ptr, SL("_messages"), messages TSRMLS_CC);
	if (Z_TYPE_P(data) != IS_NULL) {
		_0$$7 = Z_TYPE_P(data) == IS_ARRAY;
		if (!(_0$$7)) {
			_0$$7 = Z_TYPE_P(data) == IS_OBJECT;
		}
		if (_0$$7) {
			zephir_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
		} else {
			zephir_var_dump(&data TSRMLS_CC);
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Invalid data to validate", "phalcon/validation.zep", 128);
			return;
		}
	}
	zephir_is_iterable(validators, &_2, &_1, 0, 0, "phalcon/validation.zep", 162);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(scope, _3);
		if (Z_TYPE_P(scope) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The validator scope is not valid", "phalcon/validation.zep", 135);
			return;
		}
		ZEPHIR_OBS_NVAR(field);
		zephir_array_fetch_long(&field, scope, 0, PH_NOISY, "phalcon/validation.zep", 138 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(validator);
		zephir_array_fetch_long(&validator, scope, 1, PH_NOISY, "phalcon/validation.zep", 139 TSRMLS_CC);
		if (Z_TYPE_P(validator) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "One of the validators is not valid", "phalcon/validation.zep", 142);
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
	if (!(ZEPHIR_IS_EMPTY(combinedFieldsValidators))) {
		zephir_is_iterable(combinedFieldsValidators, &_10$$16, &_9$$16, 0, 0, "phalcon/validation.zep", 195);
		for (
		  ; zephir_hash_get_current_data_ex(_10$$16, (void**) &_11$$16, &_9$$16) == SUCCESS
		  ; zephir_hash_move_forward_ex(_10$$16, &_9$$16)
		) {
			ZEPHIR_GET_HVALUE(scope, _11$$16);
			if (Z_TYPE_P(scope) != IS_ARRAY) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The validator scope is not valid", "phalcon/validation.zep", 165);
				return;
			}
			ZEPHIR_OBS_NVAR(field);
			zephir_array_fetch_long(&field, scope, 0, PH_NOISY, "phalcon/validation.zep", 168 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(validator);
			zephir_array_fetch_long(&validator, scope, 1, PH_NOISY, "phalcon/validation.zep", 169 TSRMLS_CC);
			if (Z_TYPE_P(validator) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "One of the validators is not valid", "phalcon/validation.zep", 172);
				return;
			}
			if (Z_TYPE_P(validator) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "One of the validators is not valid", "phalcon/validation.zep", 176);
				return;
			}
			ZEPHIR_CALL_METHOD(&_12$$17, this_ptr, "prechecking", &_5, 0, field, validator);
			zephir_check_call_status();
			if (zephir_is_true(_12$$17)) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&_13$$17, validator, "validate", NULL, 0, this_ptr, field);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_13$$17)) {
				ZEPHIR_INIT_NVAR(_15$$22);
				ZVAL_STRING(_15$$22, "cancelOnFail", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_14$$22, validator, "getoption", NULL, 0, _15$$22);
				zephir_check_temp_parameter(_15$$22);
				zephir_check_call_status();
				if (zephir_is_true(_14$$22)) {
					break;
				}
			}
		}
	}
	if ((zephir_method_exists_ex(this_ptr, SS("aftervalidation") TSRMLS_CC) == SUCCESS)) {
		_16$$24 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "aftervalidation", NULL, 0, data, entity, _16$$24);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(this_ptr, "_messages");

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
			zephir_is_iterable(field, &_2$$5, &_1$$5, 0, 0, "phalcon/validation.zep", 222);
			for (
			  ; zephir_hash_get_current_data_ex(_2$$5, (void**) &_3$$5, &_1$$5) == SUCCESS
			  ; zephir_hash_move_forward_ex(_2$$5, &_1$$5)
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Field must be passed as array of fields or string", "phalcon/validation.zep", 228);
		return;
	}
	RETURN_THIS();

}

/**
 * Alias of `add` method
 */
PHP_METHOD(Phalcon_Validation, rule) {

	int ZEPHIR_LAST_CALL_STATUS;
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
	int ZEPHIR_LAST_CALL_STATUS;
	zval *validators = NULL;
	zval *field, *validators_param = NULL, *validator = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field, &validators_param);

	validators = validators_param;


	zephir_is_iterable(validators, &_1, &_0, 0, 0, "phalcon/validation.zep", 254);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
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
 * @param string field
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
		zephir_is_iterable(field, &_1$$3, &_0$$3, 0, 0, "phalcon/validation.zep", 271);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(singleField, _2$$3);
			zephir_update_property_array(this_ptr, SL("_filters"), singleField, filters TSRMLS_CC);
		}
	} else if (Z_TYPE_P(field) == IS_STRING) {
		zephir_update_property_array(this_ptr, SL("_filters"), field, filters TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Field must be passed as array of fields or string.", "phalcon/validation.zep", 276);
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

	

	RETURN_MEMBER(this_ptr, "_validators");

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_validation_exception_ce, "Entity must be an object", "phalcon/validation.zep", 319);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_entity"), entity TSRMLS_CC);

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
 */
PHP_METHOD(Phalcon_Validation, setDefaultMessages) {

	zval *messages_param = NULL, *defaultMessages = NULL, *_0$$3;
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
	if (zephir_fast_count_int(messages TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_fast_array_merge(_0$$3, &(defaultMessages), &(messages) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_defaultMessages"), _0$$3 TSRMLS_CC);
		RETURN_MM_MEMBER(this_ptr, "_defaultMessages");
	}
	zephir_update_property_this(this_ptr, SL("_defaultMessages"), defaultMessages TSRMLS_CC);
	RETURN_CCTOR(defaultMessages);

}

/**
 * Get default message for validator type
 */
PHP_METHOD(Phalcon_Validation, getDefaultMessage) {

	zval *type_param = NULL, *defaultMessage = NULL, *_0;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
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

	

	RETURN_MEMBER(this_ptr, "_messages");

}

/**
 * Adds labels for fields
 */
PHP_METHOD(Phalcon_Validation, setLabels) {

	zval *labels_param = NULL;
	zval *labels = NULL;

	zephir_fetch_params(0, 1, 0, &labels_param);

	labels = labels_param;


	zephir_update_property_this(this_ptr, SL("_labels"), labels TSRMLS_CC);

}

/**
 * Get label for field
 *
 * @param string field
 * @return string
 */
PHP_METHOD(Phalcon_Validation, getLabel) {

	zend_bool _0;
	zval *field, *labels = NULL, *value = NULL;

	zephir_fetch_params(0, 1, 0, &field);



	labels = zephir_fetch_nproperty_this(this_ptr, SL("_labels"), PH_NOISY_CC);
	_0 = Z_TYPE_P(labels) == IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(field) != IS_ARRAY;
	}
	if (_0) {
		if (zephir_array_isset_fetch(&value, labels, field, 1 TSRMLS_CC)) {
			RETURN_CTORW(value);
		}
	} else if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_fast_join_str(return_value, SL(", "), field TSRMLS_CC);
		return;
	}
	RETVAL_ZVAL(field, 1, 0);
	return;

}

/**
 * Appends a message to the messages list
 */
PHP_METHOD(Phalcon_Validation, appendMessage) {

	int ZEPHIR_LAST_CALL_STATUS;
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
	ZEPHIR_CALL_METHOD(NULL, messages, "appendmessage", NULL, 461, message);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_messages"), messages TSRMLS_CC);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_validation_exception_ce, "Entity must be an object", "phalcon/validation.zep", 459);
		return;
	}
	_0 = Z_TYPE_P(data) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(data) != IS_OBJECT;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_validation_exception_ce, "Data to validate must be an array or object", "phalcon/validation.zep", 463);
		return;
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

	zend_bool _1;
	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *entity = NULL, *method = NULL, *value = NULL, *data = NULL, *values = NULL, *filters = NULL, *fieldFilters = NULL, *dependencyInjector = NULL, *filterService = NULL, *_0$$3, *_3$$20;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	zephir_get_strval(field, field_param);


	ZEPHIR_OBS_VAR(entity);
	zephir_read_property_this(&entity, this_ptr, SL("_entity"), PH_NOISY_CC);
	if (Z_TYPE_P(entity) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_camelize(_0$$3, field, NULL  );
		ZEPHIR_INIT_VAR(method);
		ZEPHIR_CONCAT_SV(method, "get", _0$$3);
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
		RETURN_CCTOR(value);
	}
	ZEPHIR_OBS_VAR(data);
	zephir_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	_1 = Z_TYPE_P(data) != IS_ARRAY;
	if (_1) {
		_1 = Z_TYPE_P(data) != IS_OBJECT;
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "There is no data to validate", "phalcon/validation.zep", 508);
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
			zephir_array_fetch(&value, data, field, PH_NOISY, "phalcon/validation.zep", 520 TSRMLS_CC);
		}
	} else {
		if (Z_TYPE_P(data) == IS_OBJECT) {
			if (zephir_isset_property_zval(data, field TSRMLS_CC)) {
				ZEPHIR_OBS_NVAR(value);
				zephir_read_property_zval(&value, data, field, PH_NOISY_CC);
			}
		}
	}
	if (Z_TYPE_P(value) == IS_NULL) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(filters);
	zephir_read_property_this(&filters, this_ptr, SL("_filters"), PH_NOISY_CC);
	if (Z_TYPE_P(filters) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(fieldFilters);
		if (zephir_array_isset_fetch(&fieldFilters, filters, field, 0 TSRMLS_CC)) {
			if (zephir_is_true(fieldFilters)) {
				ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
					ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_2, 1);
					zephir_check_call_status();
					if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "A dependency injector is required to obtain the 'filter' service", "phalcon/validation.zep", 545);
						return;
					}
				}
				ZEPHIR_INIT_VAR(_3$$20);
				ZVAL_STRING(_3$$20, "filter", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&filterService, dependencyInjector, "getshared", NULL, 0, _3$$20);
				zephir_check_temp_parameter(_3$$20);
				zephir_check_call_status();
				if (Z_TYPE_P(filterService) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Returned 'filter' service is invalid", "phalcon/validation.zep", 551);
					return;
				}
				ZEPHIR_RETURN_CALL_METHOD(filterService, "sanitize", NULL, 0, value, fieldFilters);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
	}
	zephir_update_property_array(this_ptr, SL("_values"), field, value TSRMLS_CC);
	RETURN_CCTOR(value);

}

/**
 * Internal validations, if it returns true, then skip the current validator
 */
PHP_METHOD(Phalcon_Validation, preChecking) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field, *validator, *singleField = NULL, **_2$$3, *_3$$4 = NULL, *_4$$4 = NULL, *_5$$4 = NULL, *_6$$5 = NULL, *_8$$7 = NULL, *_9$$7, *_10$$7, *_11$$8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field, &validator);



	if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_is_iterable(field, &_1$$3, &_0$$3, 0, 0, "phalcon/validation.zep", 580);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(singleField, _2$$3);
			ZEPHIR_INIT_NVAR(_4$$4);
			ZVAL_STRING(_4$$4, "allowEmpty", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_BOOL(_5$$4, 0);
			ZEPHIR_CALL_METHOD(&_3$$4, validator, "getoption", NULL, 0, _4$$4, _5$$4);
			zephir_check_temp_parameter(_4$$4);
			zephir_check_call_status();
			if (zephir_is_true(_3$$4)) {
				if ((zephir_method_exists_ex(validator, SS("isallowempty") TSRMLS_CC) == SUCCESS)) {
					ZEPHIR_RETURN_CALL_METHOD(validator, "isallowempty", NULL, 0, this_ptr, singleField);
					zephir_check_call_status();
					RETURN_MM();
				}
				ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "getvalue", &_7, 0, singleField);
				zephir_check_call_status();
				RETURN_MM_BOOL(ZEPHIR_IS_EMPTY(_6$$5));
			}
		}
	} else {
		ZEPHIR_INIT_VAR(_9$$7);
		ZVAL_STRING(_9$$7, "allowEmpty", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_10$$7);
		ZVAL_BOOL(_10$$7, 0);
		ZEPHIR_CALL_METHOD(&_8$$7, validator, "getoption", NULL, 0, _9$$7, _10$$7);
		zephir_check_temp_parameter(_9$$7);
		zephir_check_call_status();
		if (zephir_is_true(_8$$7)) {
			if ((zephir_method_exists_ex(validator, SS("isallowempty") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_RETURN_CALL_METHOD(validator, "isallowempty", NULL, 0, this_ptr, field);
				zephir_check_call_status();
				RETURN_MM();
			}
			ZEPHIR_CALL_METHOD(&_11$$8, this_ptr, "getvalue", &_7, 0, field);
			zephir_check_call_status();
			RETURN_MM_BOOL(ZEPHIR_IS_EMPTY(_11$$8));
		}
	}
	RETURN_MM_BOOL(0);

}

zend_object_value zephir_init_properties_Phalcon_Validation(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_validators"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("_validators"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

