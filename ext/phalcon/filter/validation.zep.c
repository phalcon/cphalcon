
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
#include "kernel/main.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Allows to validate data using custom or built-in validators
 *
 * @phpstan-import-type filter_sanitizers from FilterTypes
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
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validators_param = NULL, _0, _1, _2, _4, _5;
	zval validators;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validators);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 769, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, NULL, phalcon_17__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_FUNCTION(&_2, "array_filter", &_3, 20, &validators, &_1);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 770, &_2);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_INIT_NVAR(&_4);
	zephir_create_closure_ex(&_4, NULL, phalcon_18__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_FUNCTION(&_5, "array_filter", &_3, 20, &validators, &_4);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 771, &_5);
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("initialize")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "initialize", &_zephir_call_cache[1]);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the default message registered for a validator class, or an
 * empty string when none has been registered.
 */
PHP_METHOD(Phalcon_Filter_Validation, getDefaultMessage)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval validatorClassName_zv, defaultMessage, _0;
	zend_string *validatorClassName = NULL;

	ZVAL_UNDEF(&validatorClassName_zv);
	ZVAL_UNDEF(&defaultMessage);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_static_property_cache _zephir_sprop_cache[1];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(validatorClassName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&validatorClassName_zv);
	ZVAL_STR_COPY(&validatorClassName_zv, validatorClassName);
	zephir_memory_observe(&defaultMessage);
	zephir_read_static_property_cached(&_0, phalcon_filter_validation_ce, phalcon_filter_validation_ce, SL("defaultMessages"), &_zephir_sprop_cache[0], PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_fetch(&defaultMessage, &_0, &validatorClassName_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
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
	ZEND_TLS zephir_static_property_cache _zephir_sprop_cache[3];
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
	zephir_read_static_property_cached(&localMessages, phalcon_filter_validation_ce, phalcon_filter_validation_ce, SL("defaultMessages"), &_zephir_sprop_cache[0], PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_array_merge(&_0, &localMessages, &messages);
	zephir_update_static_property_cached(phalcon_filter_validation_ce, phalcon_filter_validation_ce, SL("defaultMessages"), &_zephir_sprop_cache[1], &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_static_property_cached(&_1, phalcon_filter_validation_ce, phalcon_filter_validation_ce, SL("defaultMessages"), &_zephir_sprop_cache[2], PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&_1);
}

/**
 * Adds a validator to a field
 *
 * @param array|string $field
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			if (Z_TYPE_P(field) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_2$$5);
				zephir_string_to_char_array(&_2$$5, field);
				_1$$5 = &_2$$5;
			} else {
				_1$$5 = field;
			}
			zephir_is_iterable(_1$$5, 0, "phalcon/Filter/Validation.zep", 198);
			if (Z_TYPE_P(_1$$5) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1$$5), _3$$5)
				{
					ZEPHIR_INIT_NVAR(&singleField);
					ZVAL_COPY(&singleField, _3$$5);
					zephir_update_property_array_multi(this_ptr, SL("validators"), validator, SL("za"), 2, &singleField);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1$$5, "rewind", &_zephir_call_cache[0]);
				zephir_check_call_status();
				_5$$5 = 1;
				while (1) {
					if (_5$$5) {
						_5$$5 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _1$$5, "next", &_zephir_call_cache[1]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_4$$5, _1$$5, "valid", &_zephir_call_cache[2]);
					zephir_check_call_status();
					if (!zend_is_true(&_4$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&singleField, _1$$5, "current", &_zephir_call_cache[3]);
					zephir_check_call_status();
						zephir_update_property_array_multi(this_ptr, SL("validators"), validator, SL("za"), 2, &singleField);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&singleField);
		}
	} else if (Z_TYPE_P(field) == IS_STRING) {
		zephir_update_property_array_multi(this_ptr, SL("validators"), validator, SL("za"), 2, field);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_VAR(&_6$$9);
		object_init_ex(&_6$$9, phalcon_filter_validation_exceptions_invalidfieldtype_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_6$$9, "__construct", &_zephir_call_cache[4]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$9, "phalcon/Filter/Validation.zep", 202);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 769, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "appendMessage", &_zephir_call_cache[0], message);
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
	zend_bool _0, _1, _2, _24, _13$$8, _14$$8, _15$$8, _25$$15, _26$$15, _27$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_22 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval whitelist;
	zval *entity, entity_sub, *data, data_sub, *whitelist_param = NULL, container, field, value, fieldFilters, filterService, filters, method, _4, _5, _8, *_9, *_10, _23, _3$$5, _6$$6, _7$$7, _17$$8, _18$$8, _19$$8, _20$$8, _21$$8, _16$$11, _29$$15, _30$$15, _31$$15, _32$$15, _33$$15, _28$$18;
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
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_31$$15);
	ZVAL_UNDEF(&_32$$15);
	ZVAL_UNDEF(&_33$$15);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&whitelist);
	ZEND_TLS zephir_method_cache _zephir_call_cache[15];
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 772, data);
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "setEntity", &_zephir_call_cache[0], entity);
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
	ZEPHIR_CALL_METHOD_CACHED(&container, this_ptr, "getDI", &_zephir_call_cache[1]);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_CALL_CE_STATIC_CACHED(&container, phalcon_di_di_ce, "getDefault", &_zephir_call_cache[2]);
		zephir_check_call_status();
		if (Z_TYPE_P(&container) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$5);
			object_init_ex(&_3$$5, phalcon_filter_validation_exceptions_filterserviceunavailable_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_3$$5, "__construct", &_zephir_call_cache[3]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$5, "phalcon/Filter/Validation.zep", 253);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "filter");
	ZEPHIR_CALL_METHOD_CACHED(&_4, &container, "getShared", &_zephir_call_cache[4], &_5);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&filterService, &_4);
	if (UNEXPECTED(Z_TYPE_P(&filterService) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_6$$6);
		object_init_ex(&_6$$6, phalcon_filter_validation_exceptions_invalidfilterservice_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_6$$6, "__construct", &_zephir_call_cache[5]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$6, "phalcon/Filter/Validation.zep", 258);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_EMPTY(&whitelist)) {
		zephir_read_property_cached(&_7$$7, this_ptr, _zephir_prop_1, 773, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(Z_TYPE_P(&_7$$7) != IS_ARRAY)) {
			zephir_throw_variable_type_error(&_7$$7, "whitelist", "array");
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&whitelist, &_7$$7);
	}
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_2, 774, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&filters, &_8);
	if (Z_TYPE_P(data) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_5);
		zephir_string_to_char_array(&_5, data);
		_9 = &_5;
	} else {
		_9 = data;
	}
	zephir_is_iterable(_9, 0, "phalcon/Filter/Validation.zep", 301);
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
				_14$$8 = zephir_fast_in_array(&field, &whitelist);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_13$$8 = !(_14$$8);
			}
			if (_13$$8) {
				continue;
			}
			ZEPHIR_OBS_NVAR(&fieldFilters);
			_15$$8 = zephir_array_isset_fetch(&fieldFilters, &filters, &field, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_15$$8) {
				ZEPHIR_CALL_METHOD_CACHED(&_16$$11, &filterService, "sanitize", &_zephir_call_cache[6], &value, &fieldFilters);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&value, &_16$$11);
			}
			ZEPHIR_INIT_NVAR(&_17$$8);
			zephir_camelize(&_17$$8, &field, NULL );
			ZEPHIR_INIT_NVAR(&method);
			ZEPHIR_CONCAT_SV(&method, "set", &_17$$8);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_read_property_cached(&_18$$8, this_ptr, _zephir_prop_3, 775, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if ((zephir_method_exists(&_18$$8, &method)  == SUCCESS)) {
				ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, &method, NULL, 0, &value);
				zephir_check_call_status();
			} else {
				zephir_read_property_cached(&_19$$8, this_ptr, _zephir_prop_3, 775, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if ((zephir_method_exists_ex(&_19$$8, ZEND_STRL("writeattribute")) == SUCCESS)) {
					ZEPHIR_CALL_METHOD_CACHED(NULL, entity, "writeAttribute", &_zephir_call_cache[7], &field, &value);
					zephir_check_call_status();
				} else {
					zephir_read_property_cached(&_20$$8, this_ptr, _zephir_prop_3, 775, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_FUNCTION(&_21$$8, "property_exists", &_22, 7, &_20$$8, &field);
					zephir_check_call_status();
					if (zephir_is_true(&_21$$8)) {
						zephir_update_property_zval_zval(entity, &field, &value);
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _9, "rewind", &_zephir_call_cache[8]);
		zephir_check_call_status();
		_24 = 1;
		while (1) {
			if (_24) {
				_24 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _9, "next", &_zephir_call_cache[9]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_23, _9, "valid", &_zephir_call_cache[10]);
			zephir_check_call_status();
			if (!zend_is_true(&_23)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&field, _9, "key", &_zephir_call_cache[11]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, _9, "current", &_zephir_call_cache[12]);
			zephir_check_call_status();
				if (Z_TYPE_P(&field) != IS_STRING) {
					continue;
				}
				_25$$15 = !(ZEPHIR_IS_EMPTY(&whitelist));
				if (_25$$15) {
					_26$$15 = zephir_fast_in_array(&field, &whitelist);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_25$$15 = !(_26$$15);
				}
				if (_25$$15) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&fieldFilters);
				_27$$15 = zephir_array_isset_fetch(&fieldFilters, &filters, &field, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_27$$15) {
					ZEPHIR_CALL_METHOD_CACHED(&_28$$18, &filterService, "sanitize", &_zephir_call_cache[13], &value, &fieldFilters);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&value, &_28$$18);
				}
				ZEPHIR_INIT_NVAR(&_29$$15);
				zephir_camelize(&_29$$15, &field, NULL );
				ZEPHIR_INIT_NVAR(&method);
				ZEPHIR_CONCAT_SV(&method, "set", &_29$$15);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property_cached(&_30$$15, this_ptr, _zephir_prop_3, 775, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if ((zephir_method_exists(&_30$$15, &method)  == SUCCESS)) {
					ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, &method, NULL, 0, &value);
					zephir_check_call_status();
				} else {
					zephir_read_property_cached(&_31$$15, this_ptr, _zephir_prop_3, 775, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if ((zephir_method_exists_ex(&_31$$15, ZEND_STRL("writeattribute")) == SUCCESS)) {
						ZEPHIR_CALL_METHOD_CACHED(NULL, entity, "writeAttribute", &_zephir_call_cache[14], &field, &value);
						zephir_check_call_status();
					} else {
						zephir_read_property_cached(&_32$$15, this_ptr, _zephir_prop_3, 775, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_FUNCTION(&_33$$15, "property_exists", &_22, 7, &_32$$15, &field);
						zephir_check_call_status();
						if (zephir_is_true(&_33$$15)) {
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("messages", 8, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 769, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_1, &_0, "count", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(&_1, 0)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);
}

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
	zend_bool _1;
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 774, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&filters, &_0);
	if (!(!(ZEPHIR_IS_EMPTY(&field_zv)))) {
		RETURN_CCTOR(&filters);
	}
	zephir_memory_observe(&fieldFilters);
	_1 = zephir_array_isset_fetch(&fieldFilters, &filters, &field_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
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
	zend_bool _1;
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 776, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&labels, &_0);
	if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_fast_join_str(return_value, SL(", "), field);
		RETURN_MM();
	}
	zephir_memory_observe(&value);
	_1 = zephir_array_isset_fetch(&value, &labels, field, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		RETURN_CCTOR(&value);
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
 * @throws ValidationException
 * @throws DiException
 */
PHP_METHOD(Phalcon_Filter_Validation, getValue)
{
	zend_bool isRawFetched = 0, _3, _1$$5, _8$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field_zv, entity, method, value, data, filters, fieldFilters, container, filterService, _0, _2$$6, _4$$11, _5$$9, _6$$9, _7$$12, _9$$13, _10$$13;
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
	ZVAL_UNDEF(&_4$$11);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$12);
	ZVAL_UNDEF(&_9$$13);
	ZVAL_UNDEF(&_10$$13);
	ZEND_TLS zephir_method_cache _zephir_call_cache[11];
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 775, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&entity, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 772, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&data, &_0);
	if (Z_TYPE_P(&entity) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD_CACHED(&value, this_ptr, "getValueByEntity", &_zephir_call_cache[0], &entity, &field_zv);
		zephir_check_call_status();
		if (Z_TYPE_P(&value) == IS_NULL) {
			isRawFetched = 1;
			ZEPHIR_CALL_METHOD_CACHED(&value, this_ptr, "getValueByData", &_zephir_call_cache[1], &data, &field_zv);
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
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$6, "__construct", &_zephir_call_cache[2]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$6, "phalcon/Filter/Validation.zep", 420);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&value, this_ptr, "getValueByData", &_zephir_call_cache[3], &data, &field_zv);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&value) == IS_NULL) {
		RETURN_MM_NULL();
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 774, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&filters, &_0);
	zephir_memory_observe(&fieldFilters);
	_3 = zephir_array_isset_fetch(&fieldFilters, &filters, &field_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_3) {
		if (zephir_is_true(&fieldFilters)) {
			ZEPHIR_CALL_METHOD_CACHED(&container, this_ptr, "getDI", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (Z_TYPE_P(&container) == IS_NULL) {
				ZEPHIR_CALL_CE_STATIC_CACHED(&container, phalcon_di_di_ce, "getDefault", &_zephir_call_cache[5]);
				zephir_check_call_status();
				if (Z_TYPE_P(&container) == IS_NULL) {
					ZEPHIR_INIT_VAR(&_4$$11);
					object_init_ex(&_4$$11, phalcon_filter_validation_exceptions_filterserviceunavailable_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$11, "__construct", &_zephir_call_cache[6]);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_4$$11, "phalcon/Filter/Validation.zep", 439);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_INIT_VAR(&_6$$9);
			ZVAL_STRING(&_6$$9, "filter");
			ZEPHIR_CALL_METHOD_CACHED(&_5$$9, &container, "getShared", &_zephir_call_cache[7], &_6$$9);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&filterService, &_5$$9);
			if (UNEXPECTED(Z_TYPE_P(&filterService) != IS_OBJECT)) {
				ZEPHIR_INIT_VAR(&_7$$12);
				object_init_ex(&_7$$12, phalcon_filter_validation_exceptions_invalidfilterservice_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_7$$12, "__construct", &_zephir_call_cache[8]);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$12, "phalcon/Filter/Validation.zep", 446);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_5$$9, &filterService, "sanitize", &_zephir_call_cache[9], &value, &fieldFilters);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&value, &_5$$9);
			_8$$9 = Z_TYPE_P(&entity) == IS_OBJECT;
			if (_8$$9) {
				_8$$9 = isRawFetched == 0;
			}
			if (_8$$9) {
				ZEPHIR_INIT_VAR(&_9$$13);
				zephir_camelize(&_9$$13, &field_zv, NULL );
				ZEPHIR_INIT_VAR(&method);
				ZEPHIR_CONCAT_SV(&method, "set", &_9$$13);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if ((zephir_method_exists(&entity, &method)  == SUCCESS)) {
					ZEPHIR_CALL_METHOD_ZVAL(NULL, &entity, &method, NULL, 0, &value);
					zephir_check_call_status();
				} else if ((zephir_method_exists_ex(&entity, ZEND_STRL("writeattribute")) == SUCCESS)) {
					ZEPHIR_CALL_METHOD_CACHED(NULL, &entity, "writeAttribute", &_zephir_call_cache[10], &field_zv, &value);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_FUNCTION(&_10$$13, "property_exists", NULL, 7, &entity, &field_zv);
					zephir_check_call_status();
					if (zephir_is_true(&_10$$13)) {
						zephir_update_property_zval_zval(&entity, &field_zv, &value);
					}
				}
			}
			RETURN_CCTOR(&value);
		}
	}
	if (Z_TYPE_P(&entity) != IS_OBJECT) {
		zephir_update_property_array(this_ptr, SL("values"), &field_zv, &value);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CCTOR(&value);
}

/**
 * Gets the value to validate in the array/object data source
 */
PHP_METHOD(Phalcon_Filter_Validation, getValueByData)
{
	zend_bool _1, _2$$4, _4$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *field = NULL;
	zval *data, data_sub, field_zv, value, values, _0, _3$$5, _5$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$7);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 777, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&values, &_0);
	zephir_memory_observe(&value);
	_1 = zephir_array_isset_fetch(&value, &values, &field_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		RETURN_CCTOR(&value);
	}
	if (Z_TYPE_P(data) == IS_ARRAY) {
		_2$$4 = zephir_array_isset_value(data, &field_zv);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_2$$4) {
			zephir_memory_observe(&_3$$5);
			zephir_array_fetch(&_3$$5, data, &field_zv, PH_NOISY, "phalcon/Filter/Validation.zep", 494);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_CCTOR(&_3$$5);
		}
	}
	if (Z_TYPE_P(data) == IS_OBJECT) {
		_4$$6 = zephir_isset_property_value_zval(data, &field_zv);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_4$$6) {
			zephir_memory_observe(&_5$$7);
			zephir_read_property_zval(&_5$$7, data, &field_zv, PH_NOISY_CC);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_CCTOR(&_5$$7);
		}
	}
	RETURN_MM_NULL();
}

/**
 * Gets the value to validate in the object entity source
 */
PHP_METHOD(Phalcon_Filter_Validation, getValueByEntity)
{
	zend_bool _2;
	zval method;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *field = NULL;
	zval *entity, entity_sub, field_zv, _0, _1, _3$$5;

	ZVAL_UNDEF(&entity_sub);
	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&method);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_get_strval(&method, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if ((zephir_method_exists(entity, &method)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(entity, &method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_method_exists_ex(entity, ZEND_STRL("readattribute")) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_CACHED(entity, "readAttribute", &_zephir_call_cache[0], &field_zv);
		zephir_check_call_status();
		RETURN_MM();
	}
	_2 = zephir_isset_property_value_zval(entity, &field_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_2) {
		zephir_memory_observe(&_3$$5);
		zephir_read_property_zval(&_3$$5, entity, &field_zv, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&_3$$5);
	}
	RETURN_MM_NULL();
}

/**
 * Alias of `add` method
 *
 * @param array|string $field
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(field)
		Z_PARAM_OBJECT_OF_CLASS(validator, phalcon_filter_validation_validatorinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &field, &validator);
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "add", &_zephir_call_cache[0], field, validator);
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
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval validators;
	zval *field, field_sub, *validators_param = NULL, validator, *_0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&validators);
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(field)
		ZEPHIR_Z_PARAM_ARRAY(validators, validators_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &field, &validators_param);
	zephir_get_arrval(&validators, validators_param);
	zephir_is_iterable(&validators, 0, "phalcon/Filter/Validation.zep", 560);
	if (Z_TYPE_P(&validators) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _0)
		{
			ZEPHIR_INIT_NVAR(&validator);
			ZVAL_COPY(&validator, _0);
			if (zephir_instance_of_ev(&validator, phalcon_filter_validation_validatorinterface_ce)) {
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "add", &_zephir_call_cache[0], field, &validator);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &validators, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_2 = 1;
		while (1) {
			if (_2) {
				_2 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &validators, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_1, &validators, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&validator, &validators, "current", &_zephir_call_cache[4]);
			zephir_check_call_status();
				if (zephir_instance_of_ev(&validator, phalcon_filter_validation_validatorinterface_ce)) {
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "add", &_zephir_call_cache[5], field, &validator);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Filter/Validation.zep", 571);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 775, entity);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
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
		zephir_is_iterable(_0$$3, 0, "phalcon/Filter/Validation.zep", 594);
		if (Z_TYPE_P(_0$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_0$$3), _2$$3)
			{
				ZEPHIR_INIT_NVAR(&singleField);
				ZVAL_COPY(&singleField, _2$$3);
				zephir_update_property_array(this_ptr, SL("filters"), &singleField, filters);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _0$$3, "rewind", &_zephir_call_cache[0]);
			zephir_check_call_status();
			_4$$3 = 1;
			while (1) {
				if (_4$$3) {
					_4$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _0$$3, "next", &_zephir_call_cache[1]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_3$$3, _0$$3, "valid", &_zephir_call_cache[2]);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&singleField, _0$$3, "current", &_zephir_call_cache[3]);
				zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("filters"), &singleField, filters);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&singleField);
	} else if (Z_TYPE_P(field) == IS_STRING) {
		zephir_update_property_array(this_ptr, SL("filters"), field, filters);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_VAR(&_5$$7);
		object_init_ex(&_5$$7, phalcon_filter_validation_exceptions_invalidfieldtype_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_5$$7, "__construct", &_zephir_call_cache[4]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$7, "phalcon/Filter/Validation.zep", 597);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 776, &labels);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 770, &validators);
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
	zend_string *_13;
	zend_ulong _12;
	zend_bool _4, _30, _56, _5$$4, _23$$10, _40$$21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval whitelist;
	zval *data = NULL, data_sub, *entity = NULL, entity_sub, *whitelist_param = NULL, __$null, combinedFieldsValidators, field, scope, status, validator, validatorData, validators, inputData, _0, _2, _3, *_9, _10, *_11, _29, *_46, _47, *_48, _55, _1$$3, _6$$5, _7$$8, _8$$8, *_14$$10, _15$$10, *_16$$10, _22$$10, _17$$12, _18$$11, _19$$11, _20$$14, _21$$14, _24$$17, _25$$16, _26$$16, _27$$19, _28$$19, *_31$$21, _32$$21, *_33$$21, _39$$21, _34$$23, _35$$22, _36$$22, _37$$25, _38$$25, _41$$28, _42$$27, _43$$27, _44$$30, _45$$30, _49$$33, _50$$34, _51$$32, _52$$32, _53$$36, _54$$36, _57$$39, _58$$40, _59$$38, _60$$38, _61$$42, _62$$42, _63$$44, _64$$44;
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
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_47);
	ZVAL_UNDEF(&_55);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_27$$19);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_32$$21);
	ZVAL_UNDEF(&_39$$21);
	ZVAL_UNDEF(&_34$$23);
	ZVAL_UNDEF(&_35$$22);
	ZVAL_UNDEF(&_36$$22);
	ZVAL_UNDEF(&_37$$25);
	ZVAL_UNDEF(&_38$$25);
	ZVAL_UNDEF(&_41$$28);
	ZVAL_UNDEF(&_42$$27);
	ZVAL_UNDEF(&_43$$27);
	ZVAL_UNDEF(&_44$$30);
	ZVAL_UNDEF(&_45$$30);
	ZVAL_UNDEF(&_49$$33);
	ZVAL_UNDEF(&_50$$34);
	ZVAL_UNDEF(&_51$$32);
	ZVAL_UNDEF(&_52$$32);
	ZVAL_UNDEF(&_53$$36);
	ZVAL_UNDEF(&_54$$36);
	ZVAL_UNDEF(&_57$$39);
	ZVAL_UNDEF(&_58$$40);
	ZVAL_UNDEF(&_59$$38);
	ZVAL_UNDEF(&_60$$38);
	ZVAL_UNDEF(&_61$$42);
	ZVAL_UNDEF(&_62$$42);
	ZVAL_UNDEF(&_63$$44);
	ZVAL_UNDEF(&_64$$44);
	ZVAL_UNDEF(&whitelist);
	ZEND_TLS zephir_method_cache _zephir_call_cache[49];
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
	zephir_read_property_cached(&validatorData, this_ptr, _zephir_prop_0, 770, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 771, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&combinedFieldsValidators, &_0);
	if (UNEXPECTED(Z_TYPE_P(&validatorData) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_filter_validation_exceptions_novalidators_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Filter/Validation.zep", 661);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 777, &_2);
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, phalcon_messages_messages_ce);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_3, "__construct", &_zephir_call_cache[1]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 769, &_3);
	if (Z_TYPE_P(data) != IS_NULL) {
		_5$$4 = Z_TYPE_P(data) != IS_ARRAY;
		if (_5$$4) {
			_5$$4 = Z_TYPE_P(data) != IS_OBJECT;
		}
		if (UNEXPECTED(_5$$4)) {
			ZEPHIR_INIT_VAR(&_6$$5);
			object_init_ex(&_6$$5, phalcon_filter_validation_exceptions_invalidvalidationdata_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_6$$5, "__construct", &_zephir_call_cache[2]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$5, "phalcon/Filter/Validation.zep", 676);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 772, data);
		ZEPHIR_CPY_WRT(&inputData, data);
	} else {
		_4 = zephir_isempty_property_fast(this_ptr, _zephir_prop_4);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!(_4)) {
			ZEPHIR_OBS_NVAR(&inputData);
			zephir_read_property_cached(&inputData, this_ptr, _zephir_prop_4, 772, PH_NOISY_CC);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	if (Z_TYPE_P(entity) != IS_NULL) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "bind", &_zephir_call_cache[3], entity, &inputData, &whitelist);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("beforevalidation")) == SUCCESS)) {
		zephir_read_property_cached(&_7$$8, this_ptr, _zephir_prop_5, 775, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_8$$8, this_ptr, _zephir_prop_3, 769, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&status, this_ptr, "beforeValidation", &_zephir_call_cache[4], &inputData, &_7$$8, &_8$$8);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
			RETURN_CCTOR(&status);
		}
	}
	if (Z_TYPE_P(&validatorData) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_10);
		zephir_string_to_char_array(&_10, &validatorData);
		_9 = &_10;
	} else {
		_9 = &validatorData;
	}
	zephir_is_iterable(_9, 0, "phalcon/Filter/Validation.zep", 726);
	if (Z_TYPE_P(_9) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_9), _12, _13, _11)
		{
			ZEPHIR_INIT_NVAR(&field);
			if (_13 != NULL) { 
				ZVAL_STR_COPY(&field, _13);
			} else {
				ZVAL_LONG(&field, _12);
			}
			ZEPHIR_INIT_NVAR(&validators);
			ZVAL_COPY(&validators, _11);
			if (Z_TYPE_P(&validators) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_15$$10);
				zephir_string_to_char_array(&_15$$10, &validators);
				_14$$10 = &_15$$10;
			} else {
				_14$$10 = &validators;
			}
			zephir_is_iterable(_14$$10, 0, "phalcon/Filter/Validation.zep", 724);
			if (Z_TYPE_P(_14$$10) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_14$$10), _16$$10)
				{
					ZEPHIR_INIT_NVAR(&validator);
					ZVAL_COPY(&validator, _16$$10);
					if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
						ZEPHIR_INIT_NVAR(&_17$$12);
						object_init_ex(&_17$$12, phalcon_filter_validation_exceptions_invalidvalidator_ce);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_17$$12, "__construct", &_zephir_call_cache[5]);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_17$$12, "phalcon/Filter/Validation.zep", 704);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&_18$$11, this_ptr, "preChecking", &_zephir_call_cache[6], &field, &validator);
					zephir_check_call_status();
					if (zephir_is_true(&_18$$11)) {
						continue;
					}
					ZEPHIR_CALL_METHOD_CACHED(&_19$$11, &validator, "validate", &_zephir_call_cache[7], this_ptr, &field);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_19$$11)) {
						ZEPHIR_INIT_NVAR(&_21$$14);
						ZVAL_STRING(&_21$$14, "cancelOnFail");
						ZEPHIR_CALL_METHOD_CACHED(&_20$$14, &validator, "getOption", &_zephir_call_cache[8], &_21$$14);
						zephir_check_call_status();
						if (zephir_is_true(&_20$$14)) {
							break;
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _14$$10, "rewind", &_zephir_call_cache[9]);
				zephir_check_call_status();
				_23$$10 = 1;
				while (1) {
					if (_23$$10) {
						_23$$10 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _14$$10, "next", &_zephir_call_cache[10]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_22$$10, _14$$10, "valid", &_zephir_call_cache[11]);
					zephir_check_call_status();
					if (!zend_is_true(&_22$$10)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&validator, _14$$10, "current", &_zephir_call_cache[12]);
					zephir_check_call_status();
						if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
							ZEPHIR_INIT_NVAR(&_24$$17);
							object_init_ex(&_24$$17, phalcon_filter_validation_exceptions_invalidvalidator_ce);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_24$$17, "__construct", &_zephir_call_cache[13]);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_24$$17, "phalcon/Filter/Validation.zep", 704);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(&_25$$16, this_ptr, "preChecking", &_zephir_call_cache[14], &field, &validator);
						zephir_check_call_status();
						if (zephir_is_true(&_25$$16)) {
							continue;
						}
						ZEPHIR_CALL_METHOD_CACHED(&_26$$16, &validator, "validate", &_zephir_call_cache[15], this_ptr, &field);
						zephir_check_call_status();
						if (ZEPHIR_IS_FALSE_IDENTICAL(&_26$$16)) {
							ZEPHIR_INIT_NVAR(&_28$$19);
							ZVAL_STRING(&_28$$19, "cancelOnFail");
							ZEPHIR_CALL_METHOD_CACHED(&_27$$19, &validator, "getOption", &_zephir_call_cache[16], &_28$$19);
							zephir_check_call_status();
							if (zephir_is_true(&_27$$19)) {
								break;
							}
						}
				}
			}
			ZEPHIR_INIT_NVAR(&validator);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _9, "rewind", &_zephir_call_cache[17]);
		zephir_check_call_status();
		_30 = 1;
		while (1) {
			if (_30) {
				_30 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _9, "next", &_zephir_call_cache[18]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_29, _9, "valid", &_zephir_call_cache[19]);
			zephir_check_call_status();
			if (!zend_is_true(&_29)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&field, _9, "key", &_zephir_call_cache[20]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&validators, _9, "current", &_zephir_call_cache[21]);
			zephir_check_call_status();
				if (Z_TYPE_P(&validators) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_32$$21);
					zephir_string_to_char_array(&_32$$21, &validators);
					_31$$21 = &_32$$21;
				} else {
					_31$$21 = &validators;
				}
				zephir_is_iterable(_31$$21, 0, "phalcon/Filter/Validation.zep", 724);
				if (Z_TYPE_P(_31$$21) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_31$$21), _33$$21)
					{
						ZEPHIR_INIT_NVAR(&validator);
						ZVAL_COPY(&validator, _33$$21);
						if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
							ZEPHIR_INIT_NVAR(&_34$$23);
							object_init_ex(&_34$$23, phalcon_filter_validation_exceptions_invalidvalidator_ce);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_34$$23, "__construct", &_zephir_call_cache[22]);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_34$$23, "phalcon/Filter/Validation.zep", 704);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(&_35$$22, this_ptr, "preChecking", &_zephir_call_cache[23], &field, &validator);
						zephir_check_call_status();
						if (zephir_is_true(&_35$$22)) {
							continue;
						}
						ZEPHIR_CALL_METHOD_CACHED(&_36$$22, &validator, "validate", &_zephir_call_cache[24], this_ptr, &field);
						zephir_check_call_status();
						if (ZEPHIR_IS_FALSE_IDENTICAL(&_36$$22)) {
							ZEPHIR_INIT_NVAR(&_38$$25);
							ZVAL_STRING(&_38$$25, "cancelOnFail");
							ZEPHIR_CALL_METHOD_CACHED(&_37$$25, &validator, "getOption", &_zephir_call_cache[25], &_38$$25);
							zephir_check_call_status();
							if (zephir_is_true(&_37$$25)) {
								break;
							}
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _31$$21, "rewind", &_zephir_call_cache[26]);
					zephir_check_call_status();
					_40$$21 = 1;
					while (1) {
						if (_40$$21) {
							_40$$21 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _31$$21, "next", &_zephir_call_cache[27]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_39$$21, _31$$21, "valid", &_zephir_call_cache[28]);
						zephir_check_call_status();
						if (!zend_is_true(&_39$$21)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&validator, _31$$21, "current", &_zephir_call_cache[29]);
						zephir_check_call_status();
							if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
								ZEPHIR_INIT_NVAR(&_41$$28);
								object_init_ex(&_41$$28, phalcon_filter_validation_exceptions_invalidvalidator_ce);
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_41$$28, "__construct", &_zephir_call_cache[30]);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_41$$28, "phalcon/Filter/Validation.zep", 704);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD_CACHED(&_42$$27, this_ptr, "preChecking", &_zephir_call_cache[31], &field, &validator);
							zephir_check_call_status();
							if (zephir_is_true(&_42$$27)) {
								continue;
							}
							ZEPHIR_CALL_METHOD_CACHED(&_43$$27, &validator, "validate", &_zephir_call_cache[32], this_ptr, &field);
							zephir_check_call_status();
							if (ZEPHIR_IS_FALSE_IDENTICAL(&_43$$27)) {
								ZEPHIR_INIT_NVAR(&_45$$30);
								ZVAL_STRING(&_45$$30, "cancelOnFail");
								ZEPHIR_CALL_METHOD_CACHED(&_44$$30, &validator, "getOption", &_zephir_call_cache[33], &_45$$30);
								zephir_check_call_status();
								if (zephir_is_true(&_44$$30)) {
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
		ZEPHIR_INIT_VAR(&_47);
		zephir_string_to_char_array(&_47, &combinedFieldsValidators);
		_46 = &_47;
	} else {
		_46 = &combinedFieldsValidators;
	}
	zephir_is_iterable(_46, 0, "phalcon/Filter/Validation.zep", 759);
	if (Z_TYPE_P(_46) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_46), _48)
		{
			ZEPHIR_INIT_NVAR(&scope);
			ZVAL_COPY(&scope, _48);
			if (UNEXPECTED(Z_TYPE_P(&scope) != IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(&_49$$33);
				object_init_ex(&_49$$33, phalcon_filter_validation_exceptions_invalidvalidatorscope_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_49$$33, "__construct", &_zephir_call_cache[34]);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_49$$33, "phalcon/Filter/Validation.zep", 728);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&field);
			zephir_array_fetch_long(&field, &scope, 0, PH_NOISY, "phalcon/Filter/Validation.zep", 731);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&validator);
			zephir_array_fetch_long(&validator, &scope, 1, PH_NOISY, "phalcon/Filter/Validation.zep", 732);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
				ZEPHIR_INIT_NVAR(&_50$$34);
				object_init_ex(&_50$$34, phalcon_filter_validation_exceptions_invalidvalidator_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_50$$34, "__construct", &_zephir_call_cache[35]);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_50$$34, "phalcon/Filter/Validation.zep", 735);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_51$$32, this_ptr, "preChecking", &_zephir_call_cache[36], &field, &validator);
			zephir_check_call_status();
			if (zephir_is_true(&_51$$32)) {
				continue;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_52$$32, &validator, "validate", &_zephir_call_cache[37], this_ptr, &field);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_52$$32)) {
				ZEPHIR_INIT_NVAR(&_54$$36);
				ZVAL_STRING(&_54$$36, "cancelOnFail");
				ZEPHIR_CALL_METHOD_CACHED(&_53$$36, &validator, "getOption", &_zephir_call_cache[38], &_54$$36);
				zephir_check_call_status();
				if (zephir_is_true(&_53$$36)) {
					break;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _46, "rewind", &_zephir_call_cache[39]);
		zephir_check_call_status();
		_56 = 1;
		while (1) {
			if (_56) {
				_56 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _46, "next", &_zephir_call_cache[40]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_55, _46, "valid", &_zephir_call_cache[41]);
			zephir_check_call_status();
			if (!zend_is_true(&_55)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&scope, _46, "current", &_zephir_call_cache[42]);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&scope) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_57$$39);
					object_init_ex(&_57$$39, phalcon_filter_validation_exceptions_invalidvalidatorscope_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_57$$39, "__construct", &_zephir_call_cache[43]);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_57$$39, "phalcon/Filter/Validation.zep", 728);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&field);
				zephir_array_fetch_long(&field, &scope, 0, PH_NOISY, "phalcon/Filter/Validation.zep", 731);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&validator);
				zephir_array_fetch_long(&validator, &scope, 1, PH_NOISY, "phalcon/Filter/Validation.zep", 732);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
					ZEPHIR_INIT_NVAR(&_58$$40);
					object_init_ex(&_58$$40, phalcon_filter_validation_exceptions_invalidvalidator_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_58$$40, "__construct", &_zephir_call_cache[44]);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_58$$40, "phalcon/Filter/Validation.zep", 735);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_59$$38, this_ptr, "preChecking", &_zephir_call_cache[45], &field, &validator);
				zephir_check_call_status();
				if (zephir_is_true(&_59$$38)) {
					continue;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_60$$38, &validator, "validate", &_zephir_call_cache[46], this_ptr, &field);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_60$$38)) {
					ZEPHIR_INIT_NVAR(&_62$$42);
					ZVAL_STRING(&_62$$42, "cancelOnFail");
					ZEPHIR_CALL_METHOD_CACHED(&_61$$42, &validator, "getOption", &_zephir_call_cache[47], &_62$$42);
					zephir_check_call_status();
					if (zephir_is_true(&_61$$42)) {
						break;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&scope);
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("aftervalidation")) == SUCCESS)) {
		zephir_read_property_cached(&_63$$44, this_ptr, _zephir_prop_5, 775, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_64$$44, this_ptr, _zephir_prop_3, 769, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "afterValidation", &_zephir_call_cache[48], &inputData, &_63$$44, &_64$$44);
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
	zend_bool _6$$3, _4$$4, _8$$6;
	zval results;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *validator, validator_sub, __$false, __$true, singleField, allowEmpty, value, *_0$$3, _1$$3, *_2$$3, _5$$3, _3$$4, _7$$6, _9$$8, _10$$8;
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
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&results);
	ZEND_TLS zephir_method_cache _zephir_call_cache[9];
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
		zephir_is_iterable(_0$$3, 0, "phalcon/Filter/Validation.zep", 789);
		if (Z_TYPE_P(_0$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_0$$3), _2$$3)
			{
				ZEPHIR_INIT_NVAR(&singleField);
				ZVAL_COPY(&singleField, _2$$3);
				ZEPHIR_CALL_METHOD_CACHED(&_3$$4, this_ptr, "preChecking", &_zephir_call_cache[0], &singleField, validator);
				zephir_check_call_status();
				zephir_array_append(&results, &_3$$4, PH_SEPARATE, "phalcon/Filter/Validation.zep", 781);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_4$$4 = zephir_fast_in_array(&__$false, &results);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_4$$4) {
					RETURN_MM_BOOL(0);
				}
				RETURN_MM_BOOL(1);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _0$$3, "rewind", &_zephir_call_cache[1]);
			zephir_check_call_status();
			_6$$3 = 1;
			while (1) {
				if (_6$$3) {
					_6$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _0$$3, "next", &_zephir_call_cache[2]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_5$$3, _0$$3, "valid", &_zephir_call_cache[3]);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&singleField, _0$$3, "current", &_zephir_call_cache[4]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_7$$6, this_ptr, "preChecking", &_zephir_call_cache[5], &singleField, validator);
					zephir_check_call_status();
					zephir_array_append(&results, &_7$$6, PH_SEPARATE, "phalcon/Filter/Validation.zep", 781);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_8$$6 = zephir_fast_in_array(&__$false, &results);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_8$$6) {
						RETURN_MM_BOOL(0);
					}
					RETURN_MM_BOOL(1);
			}
		}
		ZEPHIR_INIT_NVAR(&singleField);
	} else {
		ZEPHIR_INIT_VAR(&_9$$8);
		ZVAL_STRING(&_9$$8, "allowEmpty");
		ZVAL_BOOL(&_10$$8, 0);
		ZEPHIR_CALL_METHOD_CACHED(&allowEmpty, validator, "getOption", &_zephir_call_cache[6], &_9$$8, &_10$$8);
		zephir_check_call_status();
		if (zephir_is_true(&allowEmpty)) {
			if ((zephir_method_exists_ex(validator, ZEND_STRL("isallowempty")) == SUCCESS)) {
				ZEPHIR_RETURN_CALL_METHOD_CACHED(validator, "isAllowEmpty", &_zephir_call_cache[7], this_ptr, field);
				zephir_check_call_status();
				RETURN_MM();
			}
			ZEPHIR_CALL_METHOD_CACHED(&value, this_ptr, "getValue", &_zephir_call_cache[8], field);
			zephir_check_call_status();
			if (Z_TYPE_P(&allowEmpty) == IS_ARRAY) {
				ZEPHIR_RETURN_CALL_FUNCTION("in_array", &_11, 36, &value, &allowEmpty, &__$true);
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
	ZEND_TLS zephir_static_property_cache _zephir_sprop_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_cached(phalcon_filter_validation_ce, phalcon_filter_validation_ce, SL("defaultMessages"), &_zephir_sprop_cache[0], &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

