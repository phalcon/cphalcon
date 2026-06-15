
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
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


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
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter, Validation, phalcon, filter_validation, phalcon_di_injectable_ce, phalcon_filter_validation_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("combinedFieldsValidators"), ZEND_ACC_PROTECTED);
	/**
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("data"), ZEND_ACC_PROTECTED);
	/**
	 * @var object|null
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("entity"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("filters"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("whitelist"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("labels"), ZEND_ACC_PROTECTED);
	/**
	 * @var Messages
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("messages"), ZEND_ACC_PROTECTED);
	/**
	 * List of validators
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("validators"), ZEND_ACC_PROTECTED);
	/**
	 * Calculated values
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_filter_validation_ce, SL("values"), ZEND_ACC_PROTECTED);
	phalcon_filter_validation_ce->create_object = zephir_init_properties_Phalcon_Filter_Validation;

	zend_class_implements(phalcon_filter_validation_ce, 1, phalcon_filter_validation_validationinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Filter\Validation constructor
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 10);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("messages"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, NULL, phalcon_16__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_FUNCTION(&_2, "array_filter", NULL, 31, &validators, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("validators"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_NVAR(&_3);
	zephir_create_closure_ex(&_3, NULL, phalcon_17__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_FUNCTION(&_4, "array_filter", NULL, 31, &validators, &_3);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("combinedFieldsValidators"), &_4);
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("initialize")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds a validator to a field
 *
 * @param string|array       $field
 * @param ValidatorInterface $validator
 *
 * @return static
 */
PHP_METHOD(Phalcon_Filter_Validation, add)
{
	zend_bool _3$$5;
	zval _0$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *validator, validator_sub, singleField, *_1$$5, _2$$5, _4$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator_sub);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$9);
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
			zephir_is_iterable(field, 0, "phalcon/Filter/Validation.zep", 136);
			if (Z_TYPE_P(field) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(field), _1$$5)
				{
					ZEPHIR_INIT_NVAR(&singleField);
					ZVAL_COPY(&singleField, _1$$5);
					zephir_update_property_array_multi(this_ptr, SL("validators"), validator, SL("za"), 2, &singleField);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, field, "rewind", NULL, 0);
				zephir_check_call_status();
				_3$$5 = 1;
				while (1) {
					if (_3$$5) {
						_3$$5 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, field, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_2$$5, field, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_2$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&singleField, field, "current", NULL, 0);
					zephir_check_call_status();
						zephir_update_property_array_multi(this_ptr, SL("validators"), validator, SL("za"), 2, &singleField);
				}
			}
			ZEPHIR_INIT_NVAR(&singleField);
		}
	} else if (Z_TYPE_P(field) == IS_STRING) {
		zephir_update_property_array_multi(this_ptr, SL("validators"), validator, SL("za"), 2, field);
	} else {
		ZEPHIR_INIT_VAR(&_4$$9);
		object_init_ex(&_4$$9, phalcon_filter_validation_exceptions_invalidfieldtype_ce);
		ZEPHIR_CALL_METHOD(NULL, &_4$$9, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$9, "phalcon/Filter/Validation.zep", 140);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Appends a message to the messages list
 *
 * @param MessageInterface $message
 */
PHP_METHOD(Phalcon_Filter_Validation, appendMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_messages_messageinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &message);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
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
 * @param object $entity the entity object to assign data to
 * @param array|object $data the data that needs to be validated
 * @param array $whitelist only allow these fields to be mutated when entity is used
 */
PHP_METHOD(Phalcon_Filter_Validation, bind)
{
	zend_string *_11;
	zend_ulong _10;
	zend_bool _0, _1, _2, _22, _12$$8, _23$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_14 = NULL, *_20 = NULL, *_25 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval whitelist;
	zval *entity, entity_sub, *data, data_sub, *whitelist_param = NULL, container, field, value, fieldFilters, filterService, filters, method, _4, _5, _8, *_9, _21, _3$$5, _6$$6, _7$$7, _15$$8, _16$$8, _17$$8, _18$$8, _19$$8, _13$$11, _26$$15, _27$$15, _28$$15, _29$$15, _30$$15, _24$$18;
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
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_24$$18);
	ZVAL_UNDEF(&whitelist);
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), data);
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
			zephir_throw_exception_debug(&_3$$5, "phalcon/Filter/Validation.zep", 191);
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
		zephir_throw_exception_debug(&_6$$6, "phalcon/Filter/Validation.zep", 196);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_EMPTY(&whitelist)) {
		zephir_read_property(&_7$$7, this_ptr, ZEND_STRL("whitelist"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&whitelist, &_7$$7);
	}
	zephir_read_property(&_8, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&filters, &_8);
	zephir_is_iterable(data, 0, "phalcon/Filter/Validation.zep", 239);
	if (Z_TYPE_P(data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(data), _10, _11, _9)
		{
			ZEPHIR_INIT_NVAR(&field);
			if (_11 != NULL) { 
				ZVAL_STR_COPY(&field, _11);
			} else {
				ZVAL_LONG(&field, _10);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _9);
			if (Z_TYPE_P(&field) != IS_STRING) {
				continue;
			}
			_12$$8 = !(ZEPHIR_IS_EMPTY(&whitelist));
			if (_12$$8) {
				_12$$8 = !(zephir_fast_in_array(&field, &whitelist));
			}
			if (_12$$8) {
				continue;
			}
			ZEPHIR_OBS_NVAR(&fieldFilters);
			if (zephir_array_isset_fetch(&fieldFilters, &filters, &field, 0)) {
				ZEPHIR_CALL_METHOD(&_13$$11, &filterService, "sanitize", &_14, 0, &value, &fieldFilters);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&value, &_13$$11);
			}
			ZEPHIR_INIT_NVAR(&_15$$8);
			zephir_camelize(&_15$$8, &field, NULL );
			ZEPHIR_INIT_NVAR(&method);
			ZEPHIR_CONCAT_SV(&method, "set", &_15$$8);
			zephir_read_property(&_16$$8, this_ptr, ZEND_STRL("entity"), PH_NOISY_CC | PH_READONLY);
			if ((zephir_method_exists(&_16$$8, &method)  == SUCCESS)) {
				ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, &method, NULL, 0, &value);
				zephir_check_call_status();
			} else {
				zephir_read_property(&_17$$8, this_ptr, ZEND_STRL("entity"), PH_NOISY_CC | PH_READONLY);
				if ((zephir_method_exists_ex(&_17$$8, ZEND_STRL("writeattribute")) == SUCCESS)) {
					ZEPHIR_CALL_METHOD(NULL, entity, "writeattribute", NULL, 0, &field, &value);
					zephir_check_call_status();
				} else {
					zephir_read_property(&_18$$8, this_ptr, ZEND_STRL("entity"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_FUNCTION(&_19$$8, "property_exists", &_20, 14, &_18$$8, &field);
					zephir_check_call_status();
					if (zephir_is_true(&_19$$8)) {
						zephir_update_property_zval_zval(entity, &field, &value);
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, data, "rewind", NULL, 0);
		zephir_check_call_status();
		_22 = 1;
		while (1) {
			if (_22) {
				_22 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, data, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_21, data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_21)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, data, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&field) != IS_STRING) {
					continue;
				}
				_23$$15 = !(ZEPHIR_IS_EMPTY(&whitelist));
				if (_23$$15) {
					_23$$15 = !(zephir_fast_in_array(&field, &whitelist));
				}
				if (_23$$15) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&fieldFilters);
				if (zephir_array_isset_fetch(&fieldFilters, &filters, &field, 0)) {
					ZEPHIR_CALL_METHOD(&_24$$18, &filterService, "sanitize", &_25, 0, &value, &fieldFilters);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&value, &_24$$18);
				}
				ZEPHIR_INIT_NVAR(&_26$$15);
				zephir_camelize(&_26$$15, &field, NULL );
				ZEPHIR_INIT_NVAR(&method);
				ZEPHIR_CONCAT_SV(&method, "set", &_26$$15);
				zephir_read_property(&_27$$15, this_ptr, ZEND_STRL("entity"), PH_NOISY_CC | PH_READONLY);
				if ((zephir_method_exists(&_27$$15, &method)  == SUCCESS)) {
					ZEPHIR_CALL_METHOD_ZVAL(NULL, entity, &method, NULL, 0, &value);
					zephir_check_call_status();
				} else {
					zephir_read_property(&_28$$15, this_ptr, ZEND_STRL("entity"), PH_NOISY_CC | PH_READONLY);
					if ((zephir_method_exists_ex(&_28$$15, ZEND_STRL("writeattribute")) == SUCCESS)) {
						ZEPHIR_CALL_METHOD(NULL, entity, "writeattribute", NULL, 0, &field, &value);
						zephir_check_call_status();
					} else {
						zephir_read_property(&_29$$15, this_ptr, ZEND_STRL("entity"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_FUNCTION(&_30$$15, "property_exists", &_20, 14, &_29$$15, &field);
						zephir_check_call_status();
						if (zephir_is_true(&_30$$15)) {
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
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
 * @param string field
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &field);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("labels"), PH_NOISY_CC | PH_READONLY);
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
 */
PHP_METHOD(Phalcon_Filter_Validation, getValidators)
{

	RETURN_MEMBER_TYPED(getThis(), "validators", IS_ARRAY);
}

/**
 * Gets the a value to validate in the object entity source
 *
 * @param mixed $entity
 * @param string $field
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
 * Gets the a value to validate in the array/object data source
 *
 * @param mixed $data
 * @param string $field
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
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(data)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	data = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("values"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&values, &_0);
	zephir_memory_observe(&value);
	if (zephir_array_isset_fetch(&value, &values, &field_zv, 0)) {
		RETURN_CCTOR(&value);
	}
	if (Z_TYPE_P(data) == IS_ARRAY) {
		if (zephir_array_isset_value(data, &field_zv)) {
			zephir_array_fetch(&_1$$5, data, &field_zv, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation.zep", 364);
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
 * Gets the a value to validate in the array/object data source
 *
 * @param string $field
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	isRawFetched = 0;
	zephir_read_property(&_0, this_ptr, ZEND_STRL("entity"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&entity, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
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
			zephir_throw_exception_debug(&_2$$6, "phalcon/Filter/Validation.zep", 401);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&value, this_ptr, "getvaluebydata", NULL, 0, &data, &field_zv);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&value) == IS_NULL) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
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
					zephir_throw_exception_debug(&_3$$11, "phalcon/Filter/Validation.zep", 420);
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
				zephir_throw_exception_debug(&_6$$12, "phalcon/Filter/Validation.zep", 427);
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
					ZEPHIR_CALL_FUNCTION(&_9$$13, "property_exists", NULL, 14, &entity, &field_zv);
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
 * Alias of `add` method
 *
 * @param string|array       $field
 * @param ValidatorInterface $validator
 *
 * @return static
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
	ZEPHIR_OBS_COPY_OR_DUP(&validators, validators_param);
	zephir_is_iterable(&validators, 0, "phalcon/Filter/Validation.zep", 485);
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
 * @param object entity
 */
PHP_METHOD(Phalcon_Filter_Validation, setEntity)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *entity, entity_sub, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&entity_sub);
	ZVAL_UNDEF(&_0$$3);
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
		zephir_throw_exception_debug(&_0$$3, "phalcon/Filter/Validation.zep", 496);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("entity"), entity);
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds filters to the field
 *
 * @param string field
 * @param array|string filters
 */
PHP_METHOD(Phalcon_Filter_Validation, setFilters)
{
	zend_bool _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *filters, filters_sub, singleField, *_0$$3, _1$$3, _3$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$7);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(field)
		Z_PARAM_ZVAL(filters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &field, &filters);
	if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_is_iterable(field, 0, "phalcon/Filter/Validation.zep", 516);
		if (Z_TYPE_P(field) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(field), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&singleField);
				ZVAL_COPY(&singleField, _0$$3);
				zephir_update_property_array(this_ptr, SL("filters"), &singleField, filters);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, field, "rewind", NULL, 0);
			zephir_check_call_status();
			_2$$3 = 1;
			while (1) {
				if (_2$$3) {
					_2$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, field, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_1$$3, field, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&singleField, field, "current", NULL, 0);
				zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("filters"), &singleField, filters);
			}
		}
		ZEPHIR_INIT_NVAR(&singleField);
	} else if (Z_TYPE_P(field) == IS_STRING) {
		zephir_update_property_array(this_ptr, SL("filters"), field, filters);
	} else {
		ZEPHIR_INIT_VAR(&_3$$7);
		object_init_ex(&_3$$7, phalcon_filter_validation_exceptions_invalidfieldtype_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$7, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$7, "phalcon/Filter/Validation.zep", 519);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Adds labels for fields
 */
PHP_METHOD(Phalcon_Filter_Validation, setLabels)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *labels_param = NULL;
	zval labels;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&labels);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(labels, labels_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &labels_param);
	ZEPHIR_OBS_COPY_OR_DUP(&labels, labels_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("labels"), &labels);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Filter_Validation, setValidators)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *validators_param = NULL;
	zval validators;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validators);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(validators, validators_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &validators_param);
	zephir_get_arrval(&validators, validators_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("validators"), &validators);
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
 * @param array|object $data the data that needs to be validated
 * @param object $entity the entity object to assign data to
 * @param array $whitelist only allow these fields to be mutated when entity is used
 *
 * @return Messages|false
 */
PHP_METHOD(Phalcon_Filter_Validation, validate)
{
	zend_bool _27, _50, _4$$4, _20$$10, _35$$21;
	zend_string *_10;
	zend_ulong _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL, *_15 = NULL, *_43 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval whitelist;
	zval *data = NULL, data_sub, *entity = NULL, entity_sub, *whitelist_param = NULL, __$null, combinedFieldsValidators, field, scope, status, validator, validatorData, validators, inputData, _0, _2, _3, *_8, _26, *_41, _49, _1$$3, _5$$5, _6$$8, _7$$8, *_11$$10, _19$$10, _12$$12, _14$$11, _16$$11, _17$$14, _18$$14, _21$$17, _22$$16, _23$$16, _24$$19, _25$$19, *_28$$21, _34$$21, _29$$23, _30$$22, _31$$22, _32$$25, _33$$25, _36$$28, _37$$27, _38$$27, _39$$30, _40$$30, _42$$33, _44$$34, _45$$32, _46$$32, _47$$36, _48$$36, _51$$39, _52$$40, _53$$38, _54$$38, _55$$42, _56$$42, _57$$44, _58$$44;
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
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_49);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$14);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_24$$19);
	ZVAL_UNDEF(&_25$$19);
	ZVAL_UNDEF(&_34$$21);
	ZVAL_UNDEF(&_29$$23);
	ZVAL_UNDEF(&_30$$22);
	ZVAL_UNDEF(&_31$$22);
	ZVAL_UNDEF(&_32$$25);
	ZVAL_UNDEF(&_33$$25);
	ZVAL_UNDEF(&_36$$28);
	ZVAL_UNDEF(&_37$$27);
	ZVAL_UNDEF(&_38$$27);
	ZVAL_UNDEF(&_39$$30);
	ZVAL_UNDEF(&_40$$30);
	ZVAL_UNDEF(&_42$$33);
	ZVAL_UNDEF(&_44$$34);
	ZVAL_UNDEF(&_45$$32);
	ZVAL_UNDEF(&_46$$32);
	ZVAL_UNDEF(&_47$$36);
	ZVAL_UNDEF(&_48$$36);
	ZVAL_UNDEF(&_51$$39);
	ZVAL_UNDEF(&_52$$40);
	ZVAL_UNDEF(&_53$$38);
	ZVAL_UNDEF(&_54$$38);
	ZVAL_UNDEF(&_55$$42);
	ZVAL_UNDEF(&_56$$42);
	ZVAL_UNDEF(&_57$$44);
	ZVAL_UNDEF(&_58$$44);
	ZVAL_UNDEF(&whitelist);
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
	zephir_read_property(&validatorData, this_ptr, ZEND_STRL("validators"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("combinedFieldsValidators"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&combinedFieldsValidators, &_0);
	if (UNEXPECTED(Z_TYPE_P(&validatorData) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_filter_validation_exceptions_novalidators_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Filter/Validation.zep", 574);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("values"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, phalcon_messages_messages_ce);
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 10);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("messages"), &_3);
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
			zephir_throw_exception_debug(&_5$$5, "phalcon/Filter/Validation.zep", 589);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("data"), data);
		ZEPHIR_CPY_WRT(&inputData, data);
	} else {
		zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		if (!(ZEPHIR_IS_EMPTY(&_0))) {
			ZEPHIR_OBS_NVAR(&inputData);
			zephir_read_property(&inputData, this_ptr, ZEND_STRL("data"), PH_NOISY_CC);
		}
	}
	if (Z_TYPE_P(entity) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "bind", NULL, 0, entity, &inputData, &whitelist);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("beforevalidation")) == SUCCESS)) {
		zephir_read_property(&_6$$8, this_ptr, ZEND_STRL("entity"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_7$$8, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&status, this_ptr, "beforevalidation", NULL, 0, &inputData, &_6$$8, &_7$$8);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
			RETURN_CCTOR(&status);
		}
	}
	zephir_is_iterable(&validatorData, 0, "phalcon/Filter/Validation.zep", 639);
	if (Z_TYPE_P(&validatorData) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&validatorData), _9, _10, _8)
		{
			ZEPHIR_INIT_NVAR(&field);
			if (_10 != NULL) { 
				ZVAL_STR_COPY(&field, _10);
			} else {
				ZVAL_LONG(&field, _9);
			}
			ZEPHIR_INIT_NVAR(&validators);
			ZVAL_COPY(&validators, _8);
			zephir_is_iterable(&validators, 0, "phalcon/Filter/Validation.zep", 637);
			if (Z_TYPE_P(&validators) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _11$$10)
				{
					ZEPHIR_INIT_NVAR(&validator);
					ZVAL_COPY(&validator, _11$$10);
					if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
						ZEPHIR_INIT_NVAR(&_12$$12);
						object_init_ex(&_12$$12, phalcon_filter_validation_exceptions_invalidvalidator_ce);
						ZEPHIR_CALL_METHOD(NULL, &_12$$12, "__construct", &_13, 0);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_12$$12, "phalcon/Filter/Validation.zep", 617);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_14$$11, this_ptr, "prechecking", &_15, 0, &field, &validator);
					zephir_check_call_status();
					if (zephir_is_true(&_14$$11)) {
						continue;
					}
					ZEPHIR_CALL_METHOD(&_16$$11, &validator, "validate", NULL, 0, this_ptr, &field);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_16$$11)) {
						ZEPHIR_INIT_NVAR(&_18$$14);
						ZVAL_STRING(&_18$$14, "cancelOnFail");
						ZEPHIR_CALL_METHOD(&_17$$14, &validator, "getoption", NULL, 0, &_18$$14);
						zephir_check_call_status();
						if (zephir_is_true(&_17$$14)) {
							break;
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &validators, "rewind", NULL, 0);
				zephir_check_call_status();
				_20$$10 = 1;
				while (1) {
					if (_20$$10) {
						_20$$10 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_19$$10, &validators, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_19$$10)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&validator, &validators, "current", NULL, 0);
					zephir_check_call_status();
						if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
							ZEPHIR_INIT_NVAR(&_21$$17);
							object_init_ex(&_21$$17, phalcon_filter_validation_exceptions_invalidvalidator_ce);
							ZEPHIR_CALL_METHOD(NULL, &_21$$17, "__construct", &_13, 0);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_21$$17, "phalcon/Filter/Validation.zep", 617);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD(&_22$$16, this_ptr, "prechecking", &_15, 0, &field, &validator);
						zephir_check_call_status();
						if (zephir_is_true(&_22$$16)) {
							continue;
						}
						ZEPHIR_CALL_METHOD(&_23$$16, &validator, "validate", NULL, 0, this_ptr, &field);
						zephir_check_call_status();
						if (ZEPHIR_IS_FALSE_IDENTICAL(&_23$$16)) {
							ZEPHIR_INIT_NVAR(&_25$$19);
							ZVAL_STRING(&_25$$19, "cancelOnFail");
							ZEPHIR_CALL_METHOD(&_24$$19, &validator, "getoption", NULL, 0, &_25$$19);
							zephir_check_call_status();
							if (zephir_is_true(&_24$$19)) {
								break;
							}
						}
				}
			}
			ZEPHIR_INIT_NVAR(&validator);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &validatorData, "rewind", NULL, 0);
		zephir_check_call_status();
		_27 = 1;
		while (1) {
			if (_27) {
				_27 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &validatorData, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_26, &validatorData, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_26)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, &validatorData, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&validators, &validatorData, "current", NULL, 0);
			zephir_check_call_status();
				zephir_is_iterable(&validators, 0, "phalcon/Filter/Validation.zep", 637);
				if (Z_TYPE_P(&validators) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _28$$21)
					{
						ZEPHIR_INIT_NVAR(&validator);
						ZVAL_COPY(&validator, _28$$21);
						if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
							ZEPHIR_INIT_NVAR(&_29$$23);
							object_init_ex(&_29$$23, phalcon_filter_validation_exceptions_invalidvalidator_ce);
							ZEPHIR_CALL_METHOD(NULL, &_29$$23, "__construct", &_13, 0);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_29$$23, "phalcon/Filter/Validation.zep", 617);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD(&_30$$22, this_ptr, "prechecking", &_15, 0, &field, &validator);
						zephir_check_call_status();
						if (zephir_is_true(&_30$$22)) {
							continue;
						}
						ZEPHIR_CALL_METHOD(&_31$$22, &validator, "validate", NULL, 0, this_ptr, &field);
						zephir_check_call_status();
						if (ZEPHIR_IS_FALSE_IDENTICAL(&_31$$22)) {
							ZEPHIR_INIT_NVAR(&_33$$25);
							ZVAL_STRING(&_33$$25, "cancelOnFail");
							ZEPHIR_CALL_METHOD(&_32$$25, &validator, "getoption", NULL, 0, &_33$$25);
							zephir_check_call_status();
							if (zephir_is_true(&_32$$25)) {
								break;
							}
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &validators, "rewind", NULL, 0);
					zephir_check_call_status();
					_35$$21 = 1;
					while (1) {
						if (_35$$21) {
							_35$$21 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_34$$21, &validators, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_34$$21)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&validator, &validators, "current", NULL, 0);
						zephir_check_call_status();
							if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
								ZEPHIR_INIT_NVAR(&_36$$28);
								object_init_ex(&_36$$28, phalcon_filter_validation_exceptions_invalidvalidator_ce);
								ZEPHIR_CALL_METHOD(NULL, &_36$$28, "__construct", &_13, 0);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_36$$28, "phalcon/Filter/Validation.zep", 617);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD(&_37$$27, this_ptr, "prechecking", &_15, 0, &field, &validator);
							zephir_check_call_status();
							if (zephir_is_true(&_37$$27)) {
								continue;
							}
							ZEPHIR_CALL_METHOD(&_38$$27, &validator, "validate", NULL, 0, this_ptr, &field);
							zephir_check_call_status();
							if (ZEPHIR_IS_FALSE_IDENTICAL(&_38$$27)) {
								ZEPHIR_INIT_NVAR(&_40$$30);
								ZVAL_STRING(&_40$$30, "cancelOnFail");
								ZEPHIR_CALL_METHOD(&_39$$30, &validator, "getoption", NULL, 0, &_40$$30);
								zephir_check_call_status();
								if (zephir_is_true(&_39$$30)) {
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
	zephir_is_iterable(&combinedFieldsValidators, 0, "phalcon/Filter/Validation.zep", 672);
	if (Z_TYPE_P(&combinedFieldsValidators) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&combinedFieldsValidators), _41)
		{
			ZEPHIR_INIT_NVAR(&scope);
			ZVAL_COPY(&scope, _41);
			if (UNEXPECTED(Z_TYPE_P(&scope) != IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(&_42$$33);
				object_init_ex(&_42$$33, phalcon_filter_validation_exceptions_invalidvalidatorscope_ce);
				ZEPHIR_CALL_METHOD(NULL, &_42$$33, "__construct", &_43, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_42$$33, "phalcon/Filter/Validation.zep", 641);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&field);
			zephir_array_fetch_long(&field, &scope, 0, PH_NOISY, "phalcon/Filter/Validation.zep", 644);
			ZEPHIR_OBS_NVAR(&validator);
			zephir_array_fetch_long(&validator, &scope, 1, PH_NOISY, "phalcon/Filter/Validation.zep", 645);
			if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
				ZEPHIR_INIT_NVAR(&_44$$34);
				object_init_ex(&_44$$34, phalcon_filter_validation_exceptions_invalidvalidator_ce);
				ZEPHIR_CALL_METHOD(NULL, &_44$$34, "__construct", &_13, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_44$$34, "phalcon/Filter/Validation.zep", 648);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_45$$32, this_ptr, "prechecking", &_15, 0, &field, &validator);
			zephir_check_call_status();
			if (zephir_is_true(&_45$$32)) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&_46$$32, &validator, "validate", NULL, 0, this_ptr, &field);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_46$$32)) {
				ZEPHIR_INIT_NVAR(&_48$$36);
				ZVAL_STRING(&_48$$36, "cancelOnFail");
				ZEPHIR_CALL_METHOD(&_47$$36, &validator, "getoption", NULL, 0, &_48$$36);
				zephir_check_call_status();
				if (zephir_is_true(&_47$$36)) {
					break;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &combinedFieldsValidators, "rewind", NULL, 0);
		zephir_check_call_status();
		_50 = 1;
		while (1) {
			if (_50) {
				_50 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &combinedFieldsValidators, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_49, &combinedFieldsValidators, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_49)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&scope, &combinedFieldsValidators, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&scope) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_51$$39);
					object_init_ex(&_51$$39, phalcon_filter_validation_exceptions_invalidvalidatorscope_ce);
					ZEPHIR_CALL_METHOD(NULL, &_51$$39, "__construct", &_43, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_51$$39, "phalcon/Filter/Validation.zep", 641);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&field);
				zephir_array_fetch_long(&field, &scope, 0, PH_NOISY, "phalcon/Filter/Validation.zep", 644);
				ZEPHIR_OBS_NVAR(&validator);
				zephir_array_fetch_long(&validator, &scope, 1, PH_NOISY, "phalcon/Filter/Validation.zep", 645);
				if (UNEXPECTED(Z_TYPE_P(&validator) != IS_OBJECT)) {
					ZEPHIR_INIT_NVAR(&_52$$40);
					object_init_ex(&_52$$40, phalcon_filter_validation_exceptions_invalidvalidator_ce);
					ZEPHIR_CALL_METHOD(NULL, &_52$$40, "__construct", &_13, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_52$$40, "phalcon/Filter/Validation.zep", 648);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_53$$38, this_ptr, "prechecking", &_15, 0, &field, &validator);
				zephir_check_call_status();
				if (zephir_is_true(&_53$$38)) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&_54$$38, &validator, "validate", NULL, 0, this_ptr, &field);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_54$$38)) {
					ZEPHIR_INIT_NVAR(&_56$$42);
					ZVAL_STRING(&_56$$42, "cancelOnFail");
					ZEPHIR_CALL_METHOD(&_55$$42, &validator, "getoption", NULL, 0, &_56$$42);
					zephir_check_call_status();
					if (zephir_is_true(&_55$$42)) {
						break;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&scope);
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("aftervalidation")) == SUCCESS)) {
		zephir_read_property(&_57$$44, this_ptr, ZEND_STRL("entity"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_58$$44, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "aftervalidation", NULL, 0, &inputData, &_57$$44, &_58$$44);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "messages");
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "count", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(&_1, 0)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);
}

/**
 * Internal validations, if it returns true, then skip the current validator
 *
 * @param array|string $field
 * @param ValidatorInterface $validator
 */
PHP_METHOD(Phalcon_Filter_Validation, preChecking)
{
	zend_bool _4$$3;
	zval results;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *validator, validator_sub, __$false, __$true, singleField, allowEmpty, value, *_0$$3, _3$$3, _1$$4, _5$$6, _6$$8, _7$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&allowEmpty);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
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
		zephir_is_iterable(field, 0, "phalcon/Filter/Validation.zep", 712);
		if (Z_TYPE_P(field) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(field), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&singleField);
				ZVAL_COPY(&singleField, _0$$3);
				ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "prechecking", &_2, 0, &singleField, validator);
				zephir_check_call_status();
				zephir_array_append(&results, &_1$$4, PH_SEPARATE, "phalcon/Filter/Validation.zep", 704);
				if (zephir_fast_in_array(&__$false, &results)) {
					RETURN_MM_BOOL(0);
				}
				RETURN_MM_BOOL(1);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, field, "rewind", NULL, 0);
			zephir_check_call_status();
			_4$$3 = 1;
			while (1) {
				if (_4$$3) {
					_4$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, field, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_3$$3, field, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&singleField, field, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_5$$6, this_ptr, "prechecking", &_2, 0, &singleField, validator);
					zephir_check_call_status();
					zephir_array_append(&results, &_5$$6, PH_SEPARATE, "phalcon/Filter/Validation.zep", 704);
					if (zephir_fast_in_array(&__$false, &results)) {
						RETURN_MM_BOOL(0);
					}
					RETURN_MM_BOOL(1);
			}
		}
		ZEPHIR_INIT_NVAR(&singleField);
	} else {
		ZEPHIR_INIT_VAR(&_6$$8);
		ZVAL_STRING(&_6$$8, "allowEmpty");
		ZVAL_BOOL(&_7$$8, 0);
		ZEPHIR_CALL_METHOD(&allowEmpty, validator, "getoption", NULL, 0, &_6$$8, &_7$$8);
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
				ZEPHIR_RETURN_CALL_FUNCTION("in_array", NULL, 75, &value, &allowEmpty, &__$true);
				zephir_check_call_status();
				RETURN_MM();
			}
			RETURN_MM_BOOL(ZEPHIR_IS_EMPTY(&value));
		}
	}
	RETURN_MM_BOOL(0);
}

zend_object *zephir_init_properties_Phalcon_Filter_Validation(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _8, _10, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("values"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("values"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("validators"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("validators"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("labels"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("labels"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("whitelist"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("whitelist"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("filters"), &_9$$7);
		}
		zephir_read_property_ex(&_10, this_ptr, ZEND_STRL("combinedFieldsValidators"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("combinedFieldsValidators"), &_11$$8);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

