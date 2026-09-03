
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * Allows to validate data using custom or built-in validators
 *
 * @phpstan-import-type filter_validation_combined_validators from FilterTypes
 * @phpstan-import-type filter_validation_data from FilterTypes
 * @phpstan-import-type filter_validation_default_messages from FilterTypes
 * @phpstan-import-type filter_validation_filters from FilterTypes
 * @phpstan-import-type filter_validation_labels from FilterTypes
 * @phpstan-import-type filter_validation_validators from FilterTypes
 * @phpstan-import-type filter_validation_values from FilterTypes
 * @phpstan-import-type filter_validation_whitelist from FilterTypes
 * @phpstan-import-type filter_validators from FilterTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter, Validation, phalcon, filter_validation, phalcon_di_injectable_ce, phalcon_filter_validation_method_entry, 0);

	/**
	 * Default messages for validators, keyed by validator class name
	 *
	 * Declared without an array initializer on purpose: an initialized static
	 * array makes Zephir emit a zephir_init_static_properties() function that
	 * fails to compile in the single-file build. It is null until first set
	 * and treated as an empty array by the accessors below.
	 *
	 * @phpstan-var filter_validation_default_messages
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("defaultMessages"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * @phpstan-var filter_validation_combined_validators
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_filter_validation_ce, SL("combinedFieldsValidators"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var filter_validation_data
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("data"), ZEND_ACC_PROTECTED);
	/**
	 * @var object|null
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("entity"), ZEND_ACC_PROTECTED);
	/**
	 * @phpstan-var filter_validation_filters
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_filter_validation_ce, SL("filters"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var filter_validation_labels
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_filter_validation_ce, SL("labels"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @var Messages
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_filter_validation_ce, SL("messages"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Messages\\Messages"));
	}

	/**
	 * List of validators
	 *
	 * @phpstan-var filter_validation_validators
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_filter_validation_ce, SL("validators"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Calculated values
	 *
	 * @phpstan-var filter_validation_values
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_filter_validation_ce, SL("values"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var filter_validation_whitelist
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_filter_validation_ce, SL("whitelist"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	zend_class_implements(phalcon_filter_validation_ce, 1, phalcon_filter_validation_validationinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Filter\Validation constructor
 *
 * @phpstan-param filter_validation_validators $validators
 */
PHP_METHOD(Phalcon_Filter_Validation, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validators_param = NULL, _0, _1, _2, _3, _4;
	zval validators;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validators);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("messages", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("validators", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("combinedFieldsValidators", 24, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(validators, validators_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &validators_param);
	if (!validators_param) {
		ZEPHIR_INIT_VAR(&validators);
		array_init(&validators);
	} else {
		zephir_get_arrval(&validators, validators_param);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_messages_messages_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 14);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 751, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, NULL, phalcon_18__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_FUNCTION(&_2, "array_filter", NULL, 31, &validators, &_1);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 752, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_NVAR(&_3);
	zephir_create_closure_ex(&_3, NULL, phalcon_19__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_FUNCTION(&_4, "array_filter", NULL, 31, &validators, &_3);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 753, &_4);
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("initialize")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the default message registered for a validator class, or an
 * empty string when none has been registered.
 *
 * @param string $validatorClassName
 *
 * @return string
 */
PHP_METHOD(Phalcon_Filter_Validation, getDefaultMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval validatorClassName_zv, defaultMessage, _0;
	zend_string *validatorClassName = NULL;

	ZVAL_UNDEF(&validatorClassName_zv);
	ZVAL_UNDEF(&defaultMessage);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(validatorClassName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&validatorClassName_zv);
	ZVAL_STR_COPY(&validatorClassName_zv, validatorClassName);
	zephir_memory_observe(&defaultMessage);
	zephir_read_static_property_ce(&_0, phalcon_filter_validation_ce, SL("defaultMessages"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&defaultMessage, &_0, &validatorClassName_zv, 0)) {
		RETURN_CCTOR(&defaultMessage);
	}
	RETURN_MM_STRING("");
}

/**
 * Registers default messages for validators, keyed by validator class
 * name. A registered default is used when a validator does not define its
 * own message; a message set on the validator instance still wins. Calls
 * are merged, so defaults can be registered incrementally.
 *
 * @phpstan-param filter_validation_default_messages $messages
 *
 * @phpstan-return filter_validation_default_messages
 */
PHP_METHOD(Phalcon_Filter_Validation, setDefaultMessages)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *messages_param = NULL, localMessages, _0, _1;
	zval messages;

	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&localMessages);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(messages, messages_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &messages_param);
	if (!messages_param) {
		ZEPHIR_INIT_VAR(&messages);
		array_init(&messages);
	} else {
		zephir_get_arrval(&messages, messages_param);
	}
	zephir_memory_observe(&localMessages);
	zephir_read_static_property_ce(&localMessages, phalcon_filter_validation_ce, SL("defaultMessages"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_array_merge(&_0, &localMessages, &messages);
	zephir_update_static_property_ce(phalcon_filter_validation_ce, ZEND_STRL("defaultMessages"), &_0);
	zephir_read_static_property_ce(&_1, phalcon_filter_validation_ce, SL("defaultMessages"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(&_1);
}

/**
 * Adds a validator to a field
 *
 * @param string|array       $field
 * @param ValidatorInterface $validator
 *
 * @phpstan-param mixed $field
 *
 * @phpstan-return static
 * @throws ValidationException
 */
PHP_METHOD(Phalcon_Filter_Validation, add)
{
	zend_bool _5$$5;
	zval _0$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *validator, validator_sub, singleField, *_1$$5, _2$$5, *_3$$5, _4$$5, _6$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator_sub);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_0$$4);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(field)
		Z_PARAM_OBJECT_OF_CLASS(validator, phalcon_filter_validation_validatorinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &field, &validator);
	if (Z_TYPE_P(field) == IS_ARRAY) {
		if (zephir_instance_of_ev(validator, phalcon_filter_validation_abstractcombinedfieldsvalidator_ce)) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_create_array(&_0$$4, 2, 0);
			zephir_array_fast_append(&_0$$4, field);
			zephir_array_fast_append(&_0$$4, validator);
			zephir_update_property_array_append(this_ptr, SL("combinedFieldsValidators"), &_0$$4);
		} else {
			if (Z_TYPE_P(field) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_2$$5);
				zephir_string_to_char_array(&_2$$5, field);
				_1$$5 = &_2$$5;
			} else {
				_1$$5 = field;
			}
			zephir_is_iterable(_1$$5, 0, "phalcon/Filter/Validation.zep", 205);
			if (Z_TYPE_P(_1$$5) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1$$5), _3$$5)
				{
					ZEPHIR_INIT_NVAR(&singleField);
					ZVAL_COPY(&singleField, _3$$5);
					zephir_update_property_array_multi(this_ptr, SL("validators"), validator, SL("za"), 2, &singleField);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1$$5, "rewind", NULL, 0);
				zephir_check_call_status();
				_5$$5 = 1;
				while (1) {
					if (_5$$5) {
						_5$$5 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _1$$5, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_4$$5, _1$$5, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_4$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&singleField, _1$$5, "current", NULL, 0);
					zephir_check_call_status();
						zephir_update_property_array_multi(this_ptr, SL("validators"), validator, SL("za"), 2, &singleField);
				}
			}
			ZEPHIR_INIT_NVAR(&singleField);
		}
	} else if (Z_TYPE_P(field) == IS_STRING) {
		zephir_update_property_array_multi(this_ptr, SL("validators"), validator, SL("za"), 2, field);
	} else {
		ZEPHIR_INIT_VAR(&_6$$9);
		object_init_ex(&_6$$9, phalcon_filter_validation_exceptions_invalidfieldtype_ce);
		ZEPHIR_CALL_METHOD(NULL, &_6$$9, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$9, "phalcon/Filter/Validation.zep", 209);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Appends a message to the messages list
 */
PHP_METHOD(Phalcon_Filter_Validation, appendMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("messages", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_messages_messageinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &message);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 751, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "appendmessage", NULL, 0, message);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Assigns the data to an entity
 * The entity is used to obtain the validation values
 *
 * ```php
 * $entity = new Author();
 * $fields = ['name', 'email', 'imageUrl'];
 * $validation = new AuthorValidation();
 * $validation->bind($entity, $_POST, $fields);
 * $validation->validate();
 * ```
 *
 * @param object $entity
 *
 * @phpstan-param mixed                       $entity
 * @phpstan-param filter_validation_data      $data
 * @phpstan-param filter_validation_whitelist $whitelist
 */
PHP_METHOD(Phalcon_Filter_Validation, bind)
{
	zend_string *_12;
	zend_ulong _11;
	zend_bool _0, _1, _2, _23, _13$$8, _24$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_15 = NULL, *_21 = NULL, *_26 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval whitelist;
	zval *entity, entity_sub, *data, data_sub, *whitelist_param = NULL, container, field, value, fieldFilters, filterService, filters, method, _4, _5, _8, *_9, *_10, _22, _3$$5, _6$$6, _7$$7, _16$$8, _17$$8, _18$$8, _19$$8, _20$$8, _14$$11, _27$$15, _28$$15, _29$$15, _30$$15, _31$$15, _25$$18;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&entity_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&fieldFilters);
	ZVAL_UNDEF(&filterService);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_31$$15);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&whitelist);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("whitelist", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("filters", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("entity", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(entity)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(whitelist, whitelist_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &entity, &data, &whitelist_param);
	if (!whitelist_param) {
		ZEPHIR_INIT_VAR(&whitelist);
		array_init(&whitelist);
	} else {
		zephir_get_arrval(&whitelist, whitelist_param);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 754, data);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setentity", NULL, 0, entity);
	zephir_check_call_status();
	_0 = Z_TYPE_P(data) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(data) != IS_OBJECT;
	}
	_1 = _0;
	if (!(_1)) {
		_1 = (Z_TYPE_P(entity) == IS_NULL);
	}
	_2 = _1;
	if (!(_2)) {
		_2 = ZEPHIR_IS_EMPTY(data);
	}
	if (UNEXPECTED(_2)) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_METHOD(&container, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&container) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$5);
			object_init_ex(&_3$$5, phalcon_filter_validation_exceptions_filterserviceunavailable_ce);
			ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$5, "phalcon/Filter/Validation.zep", 260);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "filter");
	ZEPHIR_CALL_METHOD(&_4, &container, "getshared", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&filterService, &_4);
	if (UNEXPECTED(Z_TYPE_P(&filterService) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_6$$6);
		object_init_ex(&_6$$6, phalcon_filter_validation_exceptions_invalidfilterservice_ce);
		ZEPHIR_CALL_METHOD(NULL, &_6$$6, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$6, "phalcon/Filter/Validation.zep", 265);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_EMPTY(&whitelist)) {
		zephir_read_property_cached(&_7$$7, this_ptr, _zephir_prop_1, 755, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&whitelist, &_7$$7);
	}
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_2, 756, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&filters, &_8);
	if (Z_TYPE_P(data) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_5);
		zephir_string_to_char_array(&_5, data);
		_9 = &_5;
	} else {
		_9 = data;
	}
	zephir_is_iterable(_9, 0, "phalcon/Filter/Validation.zep", 308);
	if (Z_TYPE_P(_9) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_9), _11, _12, _10)
		{
			ZEPHIR_INIT_NVAR(&field);
			if (_12 != NULL) { 
				ZVAL_STR_COPY(&field, _12);
			} else {
				ZVAL_LONG(&field, _11);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _10);
			if (Z_TYPE_P(&field) != IS_STRING) {
				continue;
			}
			_13$$8 = !(ZEPHIR_IS_EMPTY(&whitelist));
			if (_13$$8) {
				_13$$8 = !(zephir_fast_in_array(&field, &whitelist));
			}
			if (_13$$8) {
				continue;
			}
			ZEPHIR_OBS_NVAR(&fieldFilters);
			if (zephir_array_isset_fetch(&fieldFilters, &filters, &field, 0)) {
				ZEPHIR_CALL_METHOD(&_14$$11, &filterService, "sanitize", &_15, 0, &value, &fieldFilters);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&value, &_14$$11);
			}
			ZEPHIR_INIT_NVAR(&_16$$8);
			zephir_camelize(&_16$$8, &field, NULL );
			ZEPHIR_INIT_NVAR(&method);
			ZEPHIR_CONCAT_SV(&method, "set", &_16$$8);
			zephir_read_property_cached(&_17$$8, this_ptr, _zephir_prop_3, 757, PH_NOISY_CC | PH_READONLY);
			if ((zephir_method_exists(&_17$$8, &method)  == SUCCESS)) {
				ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, &method, NULL, 0, &value);
				zephir_check_call_status();
			} else {
				zephir_read_property_cached(&_18$$8, this_ptr, _zephir_prop_3, 757, PH_NOISY_CC | PH_READONLY);
				if ((zephir_method_exists_ex(&_18$$8, ZEND_STRL("writeattribute")) == SUCCESS)) {
					ZEPHIR_CALL_METHOD(NULL, entity, "writeattribute", NULL, 0, &field, &value);
					zephir_check_call_status();
				} else {
					zephir_read_property_cached(&_19$$8, this_ptr, _zephir_prop_3, 757, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_FUNCTION(&_20$$8, "property_exists", &_21, 10, &_19$$8, &field);
					zephir_check_call_status();
					if (zephir_is_true(&_20$$8)) {
						zephir_update_property_zval_zval(entity, &field, &value);
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _9, "rewind", NULL, 0);
		zephir_check_call_status();
		_23 = 1;
		while (1) {
			if (_23) {
				_23 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _9, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_22, _9, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_22)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, _9, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, _9, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&field) != IS_STRING) {
					continue;
				}
				_24$$15 = !(ZEPHIR_IS_EMPTY(&whitelist));
				if (_24$$15) {
					_24$$15 = !(zephir_fast_in_array(&field, &whitelist));
				}
				if (_24$$15) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&fieldFilters);
				if (zephir_array_isset_fetch(&fieldFilters, &filters, &field, 0)) {
					ZEPHIR_CALL_METHOD(&_25$$18, &filterService, "sanitize", &_26, 0, &value, &fieldFilters);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&value, &_25$$18);
				}
				ZEPHIR_INIT_NVAR(&_27$$15);
				zephir_camelize(&_27$$15, &field, NULL );
				ZEPHIR_INIT_NVAR(&method);
				ZEPHIR_CONCAT_SV(&method, "set", &_27$$15);
				zephir_read_property_cached(&_28$$15, this_ptr, _zephir_prop_3, 757, PH_NOISY_CC | PH_READONLY);
				if ((zephir_method_exists(&_28$$15, &method)  == SUCCESS)) {
					ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, &method, NULL, 0, &value);
					zephir_check_call_status();
				} else {
					zephir_read_property_cached(&_29$$15, this_ptr, _zephir_prop_3, 757, PH_NOISY_CC | PH_READONLY);
					if ((zephir_method_exists_ex(&_29$$15, ZEND_STRL("writeattribute")) == SUCCESS)) {
						ZEPHIR_CALL_METHOD(NULL, entity, "writeattribute", NULL, 0, &field, &value);
						zephir_check_call_status();
					} else {
						zephir_read_property_cached(&_30$$15, this_ptr, _zephir_prop_3, 757, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_FUNCTION(&_31$$15, "property_exists", &_21, 10, &_30$$15, &field);
						zephir_check_call_status();
						if (zephir_is_true(&_31$$15)) {
							zephir_update_property_zval_zval(entity, &field, &value);
						}
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&field);
	RETURN_THIS();
}

/**
 * Verify if validation fails by verifying if there are messages in the current validation
 */
PHP_METHOD(Phalcon_Filter_Validation, fails)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("messages", 8, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 751, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "count", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(&_1, 0)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);
}

/**
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter_Validation, getData)
{

	RETURN_MEMBER(getThis(), "data");
}

/**
 * Returns the bound entity
 *
 * @return object
 *
 * @phpstan-return object|null
 */
PHP_METHOD(Phalcon_Filter_Validation, getEntity)
{

	RETURN_MEMBER(getThis(), "entity");
}

/**
 * Returns all the filters or a specific one
 */
PHP_METHOD(Phalcon_Filter_Validation, getFilters)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval field_zv, filters, fieldFilters, _0;
	zend_string *field = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&fieldFilters);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("filters", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!field) {
		ZEPHIR_INIT_VAR(&field_zv);
	} else {
		zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 756, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&filters, &_0);
	if (!(!(ZEPHIR_IS_EMPTY(&field_zv)))) {
		RETURN_CCTOR(&filters);
	}
	zephir_memory_observe(&fieldFilters);
	if (!(zephir_array_isset_fetch(&fieldFilters, &filters, &field_zv, 0))) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&fieldFilters);
}

/**
 * Get label for field
 *
 * @param array|string $field
 *
 * @phpstan-param mixed $field
 */
PHP_METHOD(Phalcon_Filter_Validation, getLabel)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *field, field_sub, labels, value, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&labels);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("labels", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &field);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 758, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&labels, &_0);
	if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_fast_join_str(return_value, SL(", "), field);
		RETURN_MM();
	}
	if (zephir_array_isset_fetch(&value, &labels, field, 1)) {
		RETURN_CTOR(&value);
	}
	RETVAL_ZVAL(field, 1, 0);
	RETURN_MM();
}

/**
 * Returns the registered validators
 */
PHP_METHOD(Phalcon_Filter_Validation, getMessages)
{

	RETURN_MEMBER(getThis(), "messages");
}

/**
 * Returns the validators added to the validation
 *
 * @phpstan-return filter_validation_validators
 */
PHP_METHOD(Phalcon_Filter_Validation, getValidators)
{

	RETURN_MEMBER_TYPED(getThis(), "validators", IS_ARRAY);
}

/**
 * Gets the value to validate in the array/object data source
 *
 * @param string $field
 *
 * @return mixed
 * @throws ValidationException
 * @throws DiException
 */
PHP_METHOD(Phalcon_Filter_Validation, getValue)
{
	zend_bool isRawFetched = 0, _1$$5, _7$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field_zv, entity, method, value, data, filters, fieldFilters, container, filterService, _0, _2$$6, _3$$11, _4$$9, _5$$9, _6$$12, _8$$13, _9$$13;
	zend_string *field = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&entity);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&fieldFilters);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&filterService);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$11);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$12);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&_9$$13);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("entity", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("data", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("filters", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	isRawFetched = 0;
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 757, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&entity, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 754, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&data, &_0);
	if (Z_TYPE_P(&entity) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&value, this_ptr, "getvaluebyentity", NULL, 0, &entity, &field_zv);
		zephir_check_call_status();
		if (Z_TYPE_P(&value) == IS_NULL) {
			isRawFetched = 1;
			ZEPHIR_CALL_METHOD(&value, this_ptr, "getvaluebydata", NULL, 0, &data, &field_zv);
			zephir_check_call_status();
		}
	} else {
		_1$$5 = Z_TYPE_P(&data) != IS_ARRAY;
		if (_1$$5) {
			_1$$5 = Z_TYPE_P(&data) != IS_OBJECT;
		}
		if (UNEXPECTED(_1$$5)) {
			ZEPHIR_INIT_VAR(&_2$$6);
			object_init_ex(&_2$$6, phalcon_filter_validation_exceptions_nodatatovalidate_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$6, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$6, "phalcon/Filter/Validation.zep", 433);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&value, this_ptr, "getvaluebydata", NULL, 0, &data, &field_zv);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&value) == IS_NULL) {
		RETURN_MM_NULL();
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 756, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&filters, &_0);
	zephir_memory_observe(&fieldFilters);
	if (zephir_array_isset_fetch(&fieldFilters, &filters, &field_zv, 0)) {
		if (zephir_is_true(&fieldFilters)) {
			ZEPHIR_CALL_METHOD(&container, this_ptr, "getdi", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&container) == IS_NULL) {
				ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&container) == IS_NULL) {
					ZEPHIR_INIT_VAR(&_3$$11);
					object_init_ex(&_3$$11, phalcon_filter_validation_exceptions_filterserviceunavailable_ce);
					ZEPHIR_CALL_METHOD(NULL, &_3$$11, "__construct", NULL, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_3$$11, "phalcon/Filter/Validation.zep", 452);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_INIT_VAR(&_5$$9);
			ZVAL_STRING(&_5$$9, "filter");
			ZEPHIR_CALL_METHOD(&_4$$9, &container, "getshared", NULL, 0, &_5$$9);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&filterService, &_4$$9);
			if (UNEXPECTED(Z_TYPE_P(&filterService) != IS_OBJECT)) {
				ZEPHIR_INIT_VAR(&_6$$12);
				object_init_ex(&_6$$12, phalcon_filter_validation_exceptions_invalidfilterservice_ce);
				ZEPHIR_CALL_METHOD(NULL, &_6$$12, "__construct", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$12, "phalcon/Filter/Validation.zep", 459);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_4$$9, &filterService, "sanitize", NULL, 0, &value, &fieldFilters);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&value, &_4$$9);
			_7$$9 = Z_TYPE_P(&entity) == IS_OBJECT;
			if (_7$$9) {
				_7$$9 = isRawFetched == 0;
			}
			if (_7$$9) {
				ZEPHIR_INIT_VAR(&_8$$13);
				zephir_camelize(&_8$$13, &field_zv, NULL );
				ZEPHIR_INIT_VAR(&method);
				ZEPHIR_CONCAT_SV(&method, "set", &_8$$13);
				if ((zephir_method_exists(&entity, &method)  == SUCCESS)) {
					ZEPHIR_CALL_METHOD_ZVAL(NULL, &entity, &method, NULL, 0, &value);
					zephir_check_call_status();
				} else if ((zephir_method_exists_ex(&entity, ZEND_STRL("writeattribute")) == SUCCESS)) {
					ZEPHIR_CALL_METHOD(NULL, &entity, "writeattribute", NULL, 0, &field_zv, &value);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_FUNCTION(&_9$$13, "property_exists", NULL, 10, &entity, &field_zv);
					zephir_check_call_status();
					if (zephir_is_true(&_9$$13)) {
						zephir_update_property_zval_zval(&entity, &field_zv, &value);
					}
				}
			}
			RETURN_CCTOR(&value);
		}
	}
	if (Z_TYPE_P(&entity) != IS_OBJECT) {
		zephir_update_property_array(this_ptr, SL("values"), &field_zv, &value);
	}
	RETURN_CCTOR(&value);
}

/**
 * Gets the value to validate in the array/object data source
 */
PHP_METHOD(Phalcon_Filter_Validation, getValueByData)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *field = NULL;
	zval *data, data_sub, field_zv, value, values, _0, _1$$5, _2$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$7);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("values", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(data)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	data = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 759, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&values, &_0);
	zephir_memory_observe(&value);
	if (zephir_array_isset_fetch(&value, &values, &field_zv, 0)) {
		RETURN_CCTOR(&value);
	}
	if (Z_TYPE_P(data) == IS_ARRAY) {
		if (zephir_array_isset_value(data, &field_zv)) {
			zephir_array_fetch(&_1$$5, data, &field_zv, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation.zep", 507);
			RETURN_CTOR(&_1$$5);
		}
	}
	if (Z_TYPE_P(data) == IS_OBJECT) {
		if (zephir_isset_property_value_zval(data, &field_zv)) {
			zephir_memory_observe(&_2$$7);
			zephir_read_property_zval(&_2$$7, data, &field_zv, PH_NOISY_CC);
			RETURN_CCTOR(&_2$$7);
		}
	}
	RETURN_MM_NULL();
}

/**
 * Gets the value to validate in the object entity source
 */
PHP_METHOD(Phalcon_Filter_Validation, getValueByEntity)
{
	zval method;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *field = NULL;
	zval *entity, entity_sub, field_zv, _0, _1, _2$$5;

	ZVAL_UNDEF(&entity_sub);
	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&method);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(entity)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	entity = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	ZEPHIR_INIT_VAR(&_0);
	zephir_camelize(&_0, &field_zv, NULL );
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "get", &_0);
	zephir_get_strval(&method, &_1);
	if ((zephir_method_exists(entity, &method)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(entity, &method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_method_exists_ex(entity, ZEND_STRL("readattribute")) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD(entity, "readattribute", NULL, 0, &field_zv);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_isset_property_value_zval(entity, &field_zv)) {
		zephir_memory_observe(&_2$$5);
		zephir_read_property_zval(&_2$$5, entity, &field_zv, PH_NOISY_CC);
		RETURN_CCTOR(&_2$$5);
	}
	RETURN_MM_NULL();
}

/**
 * Alias of `add` method
 *
 * @param string|array       $field
 *
 * @phpstan-param mixed $field
 *
 * @todo remove this
 */
PHP_METHOD(Phalcon_Filter_Validation, rule)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *validator, validator_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(field)
		Z_PARAM_OBJECT_OF_CLASS(validator, phalcon_filter_validation_validatorinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &field, &validator);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "add", NULL, 0, field, validator);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds the validators to a field
 *
 * @phpstan-param filter_validators $validators
 */
PHP_METHOD(Phalcon_Filter_Validation, rules)
{
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval validators;
	zval *field, field_sub, *validators_param = NULL, validator, *_0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&validators);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(field)
		ZEPHIR_Z_PARAM_ARRAY(validators, validators_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &field, &validators_param);
	zephir_get_arrval(&validators, validators_param);
	zephir_is_iterable(&validators, 0, "phalcon/Filter/Validation.zep", 573);
	if (Z_TYPE_P(&validators) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _0)
		{
			ZEPHIR_INIT_NVAR(&validator);
			ZVAL_COPY(&validator, _0);
			if (zephir_instance_of_ev(&validator, phalcon_filter_validation_validatorinterface_ce)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_1, 0, field, &validator);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &validators, "rewind", NULL, 0);
		zephir_check_call_status();
		_3 = 1;
		while (1) {
			if (_3) {
				_3 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_2, &validators, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&validator, &validators, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_instance_of_ev(&validator, phalcon_filter_validation_validatorinterface_ce)) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_1, 0, field, &validator);
					zephir_check_call_status();
				}
		}
	}
	ZEPHIR_INIT_NVAR(&validator);
	RETURN_THIS();
}

/**
 * Sets the bound entity
 *
 * @param object $entity
 */
PHP_METHOD(Phalcon_Filter_Validation, setEntity)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *entity, entity_sub, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&entity_sub);
	ZVAL_UNDEF(&_0$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("entity", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(entity)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &entity);
	if (UNEXPECTED(Z_TYPE_P(entity) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_filter_validation_exceptions_validationentitynotobject_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Filter/Validation.zep", 584);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 757, entity);
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds filters to the field
 *
 * @param array|string $field
 * @param array|string $filters
 *
 * @phpstan-param mixed $field
 * @phpstan-param mixed $filters
 */
PHP_METHOD(Phalcon_Filter_Validation, setFilters)
{
	zend_bool _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *filters, filters_sub, singleField, *_0$$3, _1$$3, *_2$$3, _3$$3, _5$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$7);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(field)
		Z_PARAM_ZVAL(filters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &field, &filters);
	if (Z_TYPE_P(field) == IS_ARRAY) {
		if (Z_TYPE_P(field) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_string_to_char_array(&_1$$3, field);
			_0$$3 = &_1$$3;
		} else {
			_0$$3 = field;
		}
		zephir_is_iterable(_0$$3, 0, "phalcon/Filter/Validation.zep", 607);
		if (Z_TYPE_P(_0$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_0$$3), _2$$3)
			{
				ZEPHIR_INIT_NVAR(&singleField);
				ZVAL_COPY(&singleField, _2$$3);
				zephir_update_property_array(this_ptr, SL("filters"), &singleField, filters);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _0$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			_4$$3 = 1;
			while (1) {
				if (_4$$3) {
					_4$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _0$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_3$$3, _0$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&singleField, _0$$3, "current", NULL, 0);
				zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("filters"), &singleField, filters);
			}
		}
		ZEPHIR_INIT_NVAR(&singleField);
	} else if (Z_TYPE_P(field) == IS_STRING) {
		zephir_update_property_array(this_ptr, SL("filters"), field, filters);
	} else {
		ZEPHIR_INIT_VAR(&_5$$7);
		object_init_ex(&_5$$7, phalcon_filter_validation_exceptions_invalidfieldtype_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$7, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$7, "phalcon/Filter/Validation.zep", 610);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Adds labels for fields
 *
 * @phpstan-param filter_validation_labels $labels
 */
PHP_METHOD(Phalcon_Filter_Validation, setLabels)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *labels_param = NULL;
	zval labels;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&labels);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("labels", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(labels, labels_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &labels_param);
	zephir_get_arrval(&labels, labels_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 758, &labels);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the validator array
 *
 * @phpstan-param filter_validation_validators $validators
 */
PHP_METHOD(Phalcon_Filter_Validation, setValidators)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *validators_param = NULL;
	zval validators;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validators);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("validators", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(validators, validators_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &validators_param);
	zephir_get_arrval(&validators, validators_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 752, &validators);
	RETURN_THIS();
}

/**
 * Validate a set of data according to a set of rules
 *
 * You can use $validation->bind(entity, data, whitelist)->validate()
 * When you use bind(), the this->data is already set, so you can reuse it here
 *
 * ```php
 * // using bind() with $whitelist fields
 * $entity = new Author();
 * $fields = ['name', 'email', 'imageUrl'];
 * $validation = new AuthorValidation();
 * $validation->bind($entity, $_POST, $fields);
 * $validation->validate();
 *
 * // directly using validate
 * $validation = new AuthorValidation();
 * $validation->validate($_POST, $entity, $fields);
 * ```
 *
 * @param array|object $data
 *
 * @phpstan-param mixed $data
 * @phpstan-param object $entity
 * @phpstan-param filter_validation_whitelist $whitelist
 *
 * @return false|Messages
 */
PHP_METHOD(Phalcon_Filter_Validation, validate)
{
	zend_bool _31, _58, _4$$4, _24$$10, _41$$21;
	zend_string *_12;
	zend_ulong _11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_17 = NULL, *_19 = NULL, *_51 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval whitelist;
	zval *data = NULL, data_sub, *entity = NULL, entity_sub, *whitelist_param = NULL, __$null, combinedFieldsValidators, field, scope, status, validator, validatorData, validators, inputData, _0, _2, _3, *_8, _9, *_10, _30, *_47, _48, *_49, _57, _1$$3, _5$$5, _6$$8, _7$$8, *_13$$10, _14$$10, *_15$$10, _23$$10, _16$$12, _18$$11, _20$$11, _21$$14, _22$$14, _25$$17, _26$$16, _27$$16, _28$$19, _29$$19, *_32$$21, _33$$21, *_34$$21, _40$$21, _35$$23, _36$$22, _37$$22, _38$$25, _39$$25, _42$$28, _43$$27, _44$$27, _45$$30, _46$$30, _50$$33, _52$$34, _53$$32, _54$$32, _55$$36, _56$$36, _59$$39, _60$$40, _61$$38, _62$$38, _63$$42, _64$$42, _65$$44, _66$$44;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&entity_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&combinedFieldsValidators);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&scope);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&validatorData);
	ZVAL_UNDEF(&validators);
	ZVAL_UNDEF(&inputData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_57);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_29$$19);
	ZVAL_UNDEF(&_33$$21);
	ZVAL_UNDEF(&_40$$21);
	ZVAL_UNDEF(&_35$$23);
	ZVAL_UNDEF(&_36$$22);
	ZVAL_UNDEF(&_37$$22);
	ZVAL_UNDEF(&_38$$25);
	ZVAL_UNDEF(&_39$$25);
	ZVAL_UNDEF(&_42$$28);
	ZVAL_UNDEF(&_43$$27);
	ZVAL_UNDEF(&_44$$27);
	ZVAL_UNDEF(&_45$$30);
	ZVAL_UNDEF(&_46$$30);
	ZVAL_UNDEF(&_50$$33);
	ZVAL_UNDEF(&_52$$34);
	ZVAL_UNDEF(&_53$$32);
	ZVAL_UNDEF(&_54$$32);
	ZVAL_UNDEF(&_55$$36);
	ZVAL_UNDEF(&_56$$36);
	ZVAL_UNDEF(&_59$$39);
	ZVAL_UNDEF(&_60$$40);
	ZVAL_UNDEF(&_61$$38);
	ZVAL_UNDEF(&_62$$38);
	ZVAL_UNDEF(&_63$$42);
	ZVAL_UNDEF(&_64$$42);
	ZVAL_UNDEF(&_65$$44);
	ZVAL_UNDEF(&_66$$44);
	ZVAL_UNDEF(&whitelist);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("validators", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("combinedFieldsValidators", 24, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("values", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("messages", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("data", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("entity", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_ZVAL_OR_NULL(entity)
		ZEPHIR_Z_PARAM_ARRAY(whitelist, whitelist_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 3, &data, &entity, &whitelist_param);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!entity) {
		entity = &entity_sub;
		entity = &__$null;
	}
	if (!whitelist_param) {
		ZEPHIR_INIT_VAR(&whitelist);
		array_init(&whitelist);
	} else {
		zephir_get_arrval(&whitelist, whitelist_param);
	}
	ZEPHIR_INIT_VAR(&inputData);
	ZVAL_NULL(&inputData);
	zephir_memory_observe(&validatorData);
	zephir_read_property_cached(&validatorData, this_ptr, _zephir_prop_0, 752, PH_NOISY_CC);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 753, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&combinedFieldsValidators, &_0);
	if (UNEXPECTED(Z_TYPE_P(&validatorData) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_filter_validation_exceptions_novalidators_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Filter/Validation.zep", 674);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 759, &_2);
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, phalcon_messages_messages_ce);
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 14);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 751, &_3);
	if (Z_TYPE_P(data) != IS_NULL) {
		_4$$4 = Z_TYPE_P(data) != IS_ARRAY;
		if (_4$$4) {
			_4$$4 = Z_TYPE_P(data) != IS_OBJECT;
		}
		if (UNEXPECTED(_4$$4)) {
			ZEPHIR_INIT_VAR(&_5$$5);
			object_init_ex(&_5$$5, phalcon_filter_validation_exceptions_invalidvalidationdata_ce);
			ZEPHIR_CALL_METHOD(NULL, &_5$$5, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$5, "phalcon/Filter/Validation.zep", 689);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 754, data);
		ZEPHIR_CPY_WRT(&inputData, data);
	} else {
		zephir_read_property_cached(&_0, this_ptr, _zephir_prop_4, 754, PH_NOISY_CC | PH_READONLY);
		if (!(ZEPHIR_IS_EMPTY(&_0))) {
			ZEPHIR_OBS_NVAR(&inputData);
			zephir_read_property_cached(&inputData, this_ptr, _zephir_prop_4, 754, PH_NOISY_CC);
		}
	}
	if (Z_TYPE_P(entity) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "bind", NULL, 0, entity, &inputData, &whitelist);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("beforevalidation")) == SUCCESS)) {
		zephir_read_property_cached(&_6$$8, this_ptr, _zephir_prop_5, 757, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_7$$8, this_ptr, _zephir_prop_3, 751, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&status, this_ptr, "beforevalidation", NULL, 0, &inputData, &_6$$8, &_7$$8);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
			RETURN_CCTOR(&status);
		}
	}
	if (Z_TYPE_P(&validatorData) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_9);
		zephir_string_to_char_array(&_9, &validatorData);
		_8 = &_9;
	} else {
		_8 = &validatorData;
	}
	zephir_is_iterable(_8, 0, "phalcon/Filter/Validation.zep", 739);
	if (Z_TYPE_P(_8) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_8), _11, _12, _10)
		{
			ZEPHIR_INIT_NVAR(&field);
			if (_12 != NULL) { 
				ZVAL_STR_COPY(&field, _12);
			} else {
				ZVAL_LONG(&field, _11);
			}
			ZEPHIR_INIT_NVAR(&validators);
			ZVAL_COPY(&validators, _10);
			if (Z_TYPE_P(&validators) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_14$$10);
				zephir_string_to_char_array(&_14$$10, &validators);
				_13$$10 = &_14$$10;
			} else {
				_13$$10 = &validators;
			}
			zephir_is_iterable(_13$$10, 0, "phalcon/Filter/Validation.zep", 737);
			if (Z_TYPE_P(_13$$10) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_13$$10), _15$$10)
				{
					ZEPHIR_INIT_NVAR(&validator);
					ZVAL_COPY(&validator, _15$$10);
					if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
						ZEPHIR_INIT_NVAR(&_16$$12);
						object_init_ex(&_16$$12, phalcon_filter_validation_exceptions_invalidvalidator_ce);
						ZEPHIR_CALL_METHOD(NULL, &_16$$12, "__construct", &_17, 0);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_16$$12, "phalcon/Filter/Validation.zep", 717);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_18$$11, this_ptr, "prechecking", &_19, 0, &field, &validator);
					zephir_check_call_status();
					if (zephir_is_true(&_18$$11)) {
						continue;
					}
					ZEPHIR_CALL_METHOD(&_20$$11, &validator, "validate", NULL, 0, this_ptr, &field);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_20$$11)) {
						ZEPHIR_INIT_NVAR(&_22$$14);
						ZVAL_STRING(&_22$$14, "cancelOnFail");
						ZEPHIR_CALL_METHOD(&_21$$14, &validator, "getoption", NULL, 0, &_22$$14);
						zephir_check_call_status();
						if (zephir_is_true(&_21$$14)) {
							break;
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _13$$10, "rewind", NULL, 0);
				zephir_check_call_status();
				_24$$10 = 1;
				while (1) {
					if (_24$$10) {
						_24$$10 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _13$$10, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_23$$10, _13$$10, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_23$$10)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&validator, _13$$10, "current", NULL, 0);
					zephir_check_call_status();
						if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
							ZEPHIR_INIT_NVAR(&_25$$17);
							object_init_ex(&_25$$17, phalcon_filter_validation_exceptions_invalidvalidator_ce);
							ZEPHIR_CALL_METHOD(NULL, &_25$$17, "__construct", &_17, 0);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_25$$17, "phalcon/Filter/Validation.zep", 717);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD(&_26$$16, this_ptr, "prechecking", &_19, 0, &field, &validator);
						zephir_check_call_status();
						if (zephir_is_true(&_26$$16)) {
							continue;
						}
						ZEPHIR_CALL_METHOD(&_27$$16, &validator, "validate", NULL, 0, this_ptr, &field);
						zephir_check_call_status();
						if (ZEPHIR_IS_FALSE_IDENTICAL(&_27$$16)) {
							ZEPHIR_INIT_NVAR(&_29$$19);
							ZVAL_STRING(&_29$$19, "cancelOnFail");
							ZEPHIR_CALL_METHOD(&_28$$19, &validator, "getoption", NULL, 0, &_29$$19);
							zephir_check_call_status();
							if (zephir_is_true(&_28$$19)) {
								break;
							}
						}
				}
			}
			ZEPHIR_INIT_NVAR(&validator);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _8, "rewind", NULL, 0);
		zephir_check_call_status();
		_31 = 1;
		while (1) {
			if (_31) {
				_31 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _8, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_30, _8, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_30)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, _8, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&validators, _8, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&validators) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_33$$21);
					zephir_string_to_char_array(&_33$$21, &validators);
					_32$$21 = &_33$$21;
				} else {
					_32$$21 = &validators;
				}
				zephir_is_iterable(_32$$21, 0, "phalcon/Filter/Validation.zep", 737);
				if (Z_TYPE_P(_32$$21) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_32$$21), _34$$21)
					{
						ZEPHIR_INIT_NVAR(&validator);
						ZVAL_COPY(&validator, _34$$21);
						if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
							ZEPHIR_INIT_NVAR(&_35$$23);
							object_init_ex(&_35$$23, phalcon_filter_validation_exceptions_invalidvalidator_ce);
							ZEPHIR_CALL_METHOD(NULL, &_35$$23, "__construct", &_17, 0);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_35$$23, "phalcon/Filter/Validation.zep", 717);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD(&_36$$22, this_ptr, "prechecking", &_19, 0, &field, &validator);
						zephir_check_call_status();
						if (zephir_is_true(&_36$$22)) {
							continue;
						}
						ZEPHIR_CALL_METHOD(&_37$$22, &validator, "validate", NULL, 0, this_ptr, &field);
						zephir_check_call_status();
						if (ZEPHIR_IS_FALSE_IDENTICAL(&_37$$22)) {
							ZEPHIR_INIT_NVAR(&_39$$25);
							ZVAL_STRING(&_39$$25, "cancelOnFail");
							ZEPHIR_CALL_METHOD(&_38$$25, &validator, "getoption", NULL, 0, &_39$$25);
							zephir_check_call_status();
							if (zephir_is_true(&_38$$25)) {
								break;
							}
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _32$$21, "rewind", NULL, 0);
					zephir_check_call_status();
					_41$$21 = 1;
					while (1) {
						if (_41$$21) {
							_41$$21 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _32$$21, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_40$$21, _32$$21, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_40$$21)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&validator, _32$$21, "current", NULL, 0);
						zephir_check_call_status();
							if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
								ZEPHIR_INIT_NVAR(&_42$$28);
								object_init_ex(&_42$$28, phalcon_filter_validation_exceptions_invalidvalidator_ce);
								ZEPHIR_CALL_METHOD(NULL, &_42$$28, "__construct", &_17, 0);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_42$$28, "phalcon/Filter/Validation.zep", 717);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD(&_43$$27, this_ptr, "prechecking", &_19, 0, &field, &validator);
							zephir_check_call_status();
							if (zephir_is_true(&_43$$27)) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&_44$$27, &validator, "validate", NULL, 0, this_ptr, &field);
							zephir_check_call_status();
							if (ZEPHIR_IS_FALSE_IDENTICAL(&_44$$27)) {
								ZEPHIR_INIT_NVAR(&_46$$30);
								ZVAL_STRING(&_46$$30, "cancelOnFail");
								ZEPHIR_CALL_METHOD(&_45$$30, &validator, "getoption", NULL, 0, &_46$$30);
								zephir_check_call_status();
								if (zephir_is_true(&_45$$30)) {
									break;
								}
							}
					}
				}
				ZEPHIR_INIT_NVAR(&validator);
		}
	}
	ZEPHIR_INIT_NVAR(&validators);
	ZEPHIR_INIT_NVAR(&field);
	if (Z_TYPE_P(&combinedFieldsValidators) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_48);
		zephir_string_to_char_array(&_48, &combinedFieldsValidators);
		_47 = &_48;
	} else {
		_47 = &combinedFieldsValidators;
	}
	zephir_is_iterable(_47, 0, "phalcon/Filter/Validation.zep", 772);
	if (Z_TYPE_P(_47) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_47), _49)
		{
			ZEPHIR_INIT_NVAR(&scope);
			ZVAL_COPY(&scope, _49);
			if (UNEXPECTED(Z_TYPE_P(&scope) != IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(&_50$$33);
				object_init_ex(&_50$$33, phalcon_filter_validation_exceptions_invalidvalidatorscope_ce);
				ZEPHIR_CALL_METHOD(NULL, &_50$$33, "__construct", &_51, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_50$$33, "phalcon/Filter/Validation.zep", 741);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&field);
			zephir_array_fetch_long(&field, &scope, 0, PH_NOISY, "phalcon/Filter/Validation.zep", 744);
			ZEPHIR_OBS_NVAR(&validator);
			zephir_array_fetch_long(&validator, &scope, 1, PH_NOISY, "phalcon/Filter/Validation.zep", 745);
			if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
				ZEPHIR_INIT_NVAR(&_52$$34);
				object_init_ex(&_52$$34, phalcon_filter_validation_exceptions_invalidvalidator_ce);
				ZEPHIR_CALL_METHOD(NULL, &_52$$34, "__construct", &_17, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_52$$34, "phalcon/Filter/Validation.zep", 748);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_53$$32, this_ptr, "prechecking", &_19, 0, &field, &validator);
			zephir_check_call_status();
			if (zephir_is_true(&_53$$32)) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&_54$$32, &validator, "validate", NULL, 0, this_ptr, &field);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_54$$32)) {
				ZEPHIR_INIT_NVAR(&_56$$36);
				ZVAL_STRING(&_56$$36, "cancelOnFail");
				ZEPHIR_CALL_METHOD(&_55$$36, &validator, "getoption", NULL, 0, &_56$$36);
				zephir_check_call_status();
				if (zephir_is_true(&_55$$36)) {
					break;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _47, "rewind", NULL, 0);
		zephir_check_call_status();
		_58 = 1;
		while (1) {
			if (_58) {
				_58 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _47, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_57, _47, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_57)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&scope, _47, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&scope) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_59$$39);
					object_init_ex(&_59$$39, phalcon_filter_validation_exceptions_invalidvalidatorscope_ce);
					ZEPHIR_CALL_METHOD(NULL, &_59$$39, "__construct", &_51, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_59$$39, "phalcon/Filter/Validation.zep", 741);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&field);
				zephir_array_fetch_long(&field, &scope, 0, PH_NOISY, "phalcon/Filter/Validation.zep", 744);
				ZEPHIR_OBS_NVAR(&validator);
				zephir_array_fetch_long(&validator, &scope, 1, PH_NOISY, "phalcon/Filter/Validation.zep", 745);
				if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
					ZEPHIR_INIT_NVAR(&_60$$40);
					object_init_ex(&_60$$40, phalcon_filter_validation_exceptions_invalidvalidator_ce);
					ZEPHIR_CALL_METHOD(NULL, &_60$$40, "__construct", &_17, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_60$$40, "phalcon/Filter/Validation.zep", 748);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_61$$38, this_ptr, "prechecking", &_19, 0, &field, &validator);
				zephir_check_call_status();
				if (zephir_is_true(&_61$$38)) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&_62$$38, &validator, "validate", NULL, 0, this_ptr, &field);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_62$$38)) {
					ZEPHIR_INIT_NVAR(&_64$$42);
					ZVAL_STRING(&_64$$42, "cancelOnFail");
					ZEPHIR_CALL_METHOD(&_63$$42, &validator, "getoption", NULL, 0, &_64$$42);
					zephir_check_call_status();
					if (zephir_is_true(&_63$$42)) {
						break;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&scope);
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("aftervalidation")) == SUCCESS)) {
		zephir_read_property_cached(&_65$$44, this_ptr, _zephir_prop_5, 757, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_66$$44, this_ptr, _zephir_prop_3, 751, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "aftervalidation", NULL, 0, &inputData, &_65$$44, &_66$$44);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "messages");
}

/**
 * Internal validations, if it returns true, then skip the current validator
 *
 * @param array|string $field
 * @param ValidatorInterface $validator
 *
 * @phpstan-param mixed $field
 */
PHP_METHOD(Phalcon_Filter_Validation, preChecking)
{
	zend_bool _6$$3;
	zval results;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *validator, validator_sub, __$false, __$true, singleField, allowEmpty, value, *_0$$3, _1$$3, *_2$$3, _5$$3, _3$$4, _7$$6, _8$$8, _9$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&allowEmpty);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&results);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(field)
		Z_PARAM_OBJECT_OF_CLASS(validator, phalcon_filter_validation_validatorinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &field, &validator);
	ZEPHIR_INIT_VAR(&results);
	array_init(&results);
	if (Z_TYPE_P(field) == IS_ARRAY) {
		if (Z_TYPE_P(field) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_string_to_char_array(&_1$$3, field);
			_0$$3 = &_1$$3;
		} else {
			_0$$3 = field;
		}
		zephir_is_iterable(_0$$3, 0, "phalcon/Filter/Validation.zep", 802);
		if (Z_TYPE_P(_0$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_0$$3), _2$$3)
			{
				ZEPHIR_INIT_NVAR(&singleField);
				ZVAL_COPY(&singleField, _2$$3);
				ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "prechecking", &_4, 0, &singleField, validator);
				zephir_check_call_status();
				zephir_array_append(&results, &_3$$4, PH_SEPARATE, "phalcon/Filter/Validation.zep", 794);
				if (zephir_fast_in_array(&__$false, &results)) {
					RETURN_MM_BOOL(0);
				}
				RETURN_MM_BOOL(1);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _0$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			_6$$3 = 1;
			while (1) {
				if (_6$$3) {
					_6$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _0$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_5$$3, _0$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&singleField, _0$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_7$$6, this_ptr, "prechecking", &_4, 0, &singleField, validator);
					zephir_check_call_status();
					zephir_array_append(&results, &_7$$6, PH_SEPARATE, "phalcon/Filter/Validation.zep", 794);
					if (zephir_fast_in_array(&__$false, &results)) {
						RETURN_MM_BOOL(0);
					}
					RETURN_MM_BOOL(1);
			}
		}
		ZEPHIR_INIT_NVAR(&singleField);
	} else {
		ZEPHIR_INIT_VAR(&_8$$8);
		ZVAL_STRING(&_8$$8, "allowEmpty");
		ZVAL_BOOL(&_9$$8, 0);
		ZEPHIR_CALL_METHOD(&allowEmpty, validator, "getoption", NULL, 0, &_8$$8, &_9$$8);
		zephir_check_call_status();
		if (zephir_is_true(&allowEmpty)) {
			if ((zephir_method_exists_ex(validator, ZEND_STRL("isallowempty")) == SUCCESS)) {
				ZEPHIR_RETURN_CALL_METHOD(validator, "isallowempty", NULL, 0, this_ptr, field);
				zephir_check_call_status();
				RETURN_MM();
			}
			ZEPHIR_CALL_METHOD(&value, this_ptr, "getvalue", NULL, 0, field);
			zephir_check_call_status();
			if (Z_TYPE_P(&allowEmpty) == IS_ARRAY) {
				ZEPHIR_RETURN_CALL_FUNCTION("in_array", NULL, 89, &value, &allowEmpty, &__$true);
				zephir_check_call_status();
				RETURN_MM();
			}
			RETURN_MM_BOOL(ZEPHIR_IS_EMPTY(&value));
		}
	}
	RETURN_MM_BOOL(0);
}

void zephir_init_static_properties_Phalcon_Filter_Validation()
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_ce(phalcon_filter_validation_ce, ZEND_STRL("defaultMessages"), &_0);
	ZEPHIR_MM_RESTORE();
}

