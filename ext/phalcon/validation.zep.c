
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
#include "kernel/hash.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/string.h"


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
	zval *validators_param = NULL;
	zval *validators = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &validators_param);

	if (!validators_param) {
		ZEPHIR_INIT_VAR(validators);
		array_init(validators);
	} else {
		zephir_get_arrval(validators, validators_param);
	}


	if (1 == 1) {
		zephir_update_property_this(this_ptr, SL("_validators"), validators TSRMLS_CC);
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

	HashTable *_2;
	HashPosition _1;
	zend_bool _0;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *entity = NULL, *validators = NULL, *messages = NULL, *scope = NULL, *field = NULL, *validator = NULL, *status = NULL, **_3, *_4$$8 = NULL, *_6$$8 = NULL, *_7$$12 = NULL, *_8$$12 = NULL;

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
	if (Z_TYPE_P(validators) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "There are no validators to validate", "phalcon/validation.zep", 84);
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
	_0 = Z_TYPE_P(data) == IS_ARRAY;
	if (!(_0)) {
		_0 = Z_TYPE_P(data) == IS_OBJECT;
	}
	if (_0) {
		zephir_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	}
	zephir_is_iterable(validators, &_2, &_1, 0, 0, "phalcon/validation.zep", 150);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(scope, _3);
		if (Z_TYPE_P(scope) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The validator scope is not valid", "phalcon/validation.zep", 120);
			return;
		}
		ZEPHIR_OBS_NVAR(field);
		zephir_array_fetch_long(&field, scope, 0, PH_NOISY, "phalcon/validation.zep", 123 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(validator);
		zephir_array_fetch_long(&validator, scope, 1, PH_NOISY, "phalcon/validation.zep", 124 TSRMLS_CC);
		if (Z_TYPE_P(validator) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "One of the validators is not valid", "phalcon/validation.zep", 127);
			return;
		}
		ZEPHIR_CALL_METHOD(&_4$$8, this_ptr, "prechecking", &_5, 0, field, validator);
		zephir_check_call_status();
		if (zephir_is_true(_4$$8)) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&_6$$8, validator, "validate", NULL, 0, this_ptr, field);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_6$$8)) {
			ZEPHIR_INIT_NVAR(_8$$12);
			ZVAL_STRING(_8$$12, "cancelOnFail", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_7$$12, validator, "getoption", NULL, 0, _8$$12);
			zephir_check_temp_parameter(_8$$12);
			zephir_check_call_status();
			if (zephir_is_true(_7$$12)) {
				break;
			}
		}
	}
	ZEPHIR_OBS_NVAR(messages);
	zephir_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if ((zephir_method_exists_ex(this_ptr, SS("aftervalidation") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "aftervalidation", NULL, 0, data, entity, messages);
		zephir_check_call_status();
	}
	RETURN_CCTOR(messages);

}

/**
 * Adds a validator to a field
 */
PHP_METHOD(Phalcon_Validation, add) {

	zval *_0;
	zval *field_param = NULL, *validator;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field_param, &validator);

	zephir_get_strval(field, field_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, field);
	zephir_array_fast_append(_0, validator);
	zephir_update_property_array_append(this_ptr, SL("_validators"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Alias of `add` method
 */
PHP_METHOD(Phalcon_Validation, rule) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *validator;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field_param, &validator);

	zephir_get_strval(field, field_param);


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
	zval *validators = NULL, *_3$$4 = NULL;
	zval *field_param = NULL, *validators_param = NULL, *validator = NULL, **_2;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field_param, &validators_param);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}
	validators = validators_param;


	zephir_is_iterable(validators, &_1, &_0, 0, 0, "phalcon/validation.zep", 187);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(validator, _2);
		if (zephir_instance_of_ev(validator, phalcon_validation_validatorinterface_ce TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_3$$4);
			zephir_create_array(_3$$4, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(_3$$4, field);
			zephir_array_fast_append(_3$$4, validator);
			zephir_update_property_array_append(this_ptr, SL("_validators"), _3$$4 TSRMLS_CC);
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
	if (1 == 0) {
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_validation_exception_ce, "Entity must be an object", "phalcon/validation.zep", 241);
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
	zephir_update_property_this(this_ptr, SL("_defaultMessages"), _0 TSRMLS_CC);
	RETURN_MM_MEMBER(this_ptr, "_defaultMessages");

}

/**
 * Get default message for validator type
 *
 * @param string type
 */
PHP_METHOD(Phalcon_Validation, getDefaultMessage) {

	zval *type_param = NULL, *_0, *_1, *_2;
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
	if (!(zephir_array_isset(_0, type))) {
		RETURN_MM_STRING("", 1);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultMessages"), PH_NOISY_CC);
	zephir_array_fetch(&_2, _1, type, PH_NOISY | PH_READONLY, "phalcon/validation.zep", 305 TSRMLS_CC);
	RETURN_CTOR(_2);

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

	zval *field_param = NULL, *labels = NULL, *value = NULL;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}


	labels = zephir_fetch_nproperty_this(this_ptr, SL("_labels"), PH_NOISY_CC);
	if (Z_TYPE_P(labels) == IS_ARRAY) {
		if (zephir_array_isset_fetch(&value, labels, field, 1 TSRMLS_CC)) {
			RETURN_CTOR(value);
		}
	}
	RETURN_CTOR(field);

}

/**
 * Appends a message to the messages list
 */
PHP_METHOD(Phalcon_Validation, appendMessage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "appendmessage", NULL, 0, message);
	zephir_check_call_status();
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_validation_exception_ce, "Entity must be an object", "phalcon/validation.zep", 362);
		return;
	}
	_0 = Z_TYPE_P(data) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(data) != IS_OBJECT;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_validation_exception_ce, "Data to validate must be an array or object", "phalcon/validation.zep", 366);
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
	zval *field_param = NULL, *entity = NULL, *method = NULL, *value = NULL, *data = NULL, *values = NULL, *filters = NULL, *fieldFilters = NULL, *dependencyInjector = NULL, *filterService = NULL, *_0$$3, *_3$$19;
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "There is no data to validate", "phalcon/validation.zep", 413);
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
			zephir_array_fetch(&value, data, field, PH_NOISY, "phalcon/validation.zep", 427 TSRMLS_CC);
		}
	} else if (Z_TYPE_P(data) == IS_OBJECT) {
		if (zephir_isset_property_zval(data, field TSRMLS_CC)) {
			ZEPHIR_OBS_NVAR(value);
			zephir_read_property_zval(&value, data, field, PH_NOISY_CC);
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
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "A dependency injector is required to obtain the 'filter' service", "phalcon/validation.zep", 450);
						return;
					}
				}
				ZEPHIR_INIT_VAR(_3$$19);
				ZVAL_STRING(_3$$19, "filter", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&filterService, dependencyInjector, "getshared", NULL, 0, _3$$19);
				zephir_check_temp_parameter(_3$$19);
				zephir_check_call_status();
				if (Z_TYPE_P(filterService) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Returned 'filter' service is invalid", "phalcon/validation.zep", 456);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *validator, *_0 = NULL, *_1, *_2, *_3$$5 = NULL;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field_param, &validator);

	zephir_get_strval(field, field_param);


	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "allowEmpty", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_BOOL(_2, 0);
	ZEPHIR_CALL_METHOD(&_0, validator, "getoption", NULL, 0, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		if ((zephir_method_exists_ex(validator, SS("isallowempty") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_RETURN_CALL_METHOD(validator, "isallowempty", NULL, 0, this_ptr, field);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			ZEPHIR_CALL_METHOD(&_3$$5, this_ptr, "getvalue", NULL, 0, field);
			zephir_check_call_status();
			RETURN_MM_BOOL(ZEPHIR_IS_EMPTY(_3$$5));
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

