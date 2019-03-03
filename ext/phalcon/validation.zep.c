
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_data");

}

PHP_METHOD(Phalcon_Validation, setValidators) {

	zval *validators, validators_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validators_sub);

	zephir_fetch_params(0, 1, 0, &validators);



	zephir_update_property_zval(this_ptr, SL("_validators"), validators);
	RETURN_THISW();

}

/**
 * Phalcon\Validation constructor
 */
PHP_METHOD(Phalcon_Validation, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validators_param = NULL, _0$$3, _1$$3, _2$$3, _3$$3;
	zval validators;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validators);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &validators_param);

	if (!validators_param) {
		ZEPHIR_INIT_VAR(&validators);
		array_init(&validators);
	} else {
		zephir_get_arrval(&validators, validators_param);
	}


	if (zephir_fast_count_int(&validators TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_NVAR(&_0$$3);
		zephir_create_closure_ex(&_0$$3, NULL, phalcon_26__closure_ce, SL("__invoke"));
		ZEPHIR_CALL_FUNCTION(&_1$$3, "array_filter", NULL, 446, &validators, &_0$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_validators"), &_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		zephir_create_closure_ex(&_2$$3, NULL, phalcon_27__closure_ce, SL("__invoke"));
		ZEPHIR_CALL_FUNCTION(&_3$$3, "array_filter", NULL, 446, &validators, &_2$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_combinedFieldsValidators"), &_3$$3);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultmessages", NULL, 0);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, SL("initialize") TSRMLS_CC) == SUCCESS)) {
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
 */
PHP_METHOD(Phalcon_Validation, validate) {

	zend_bool _0$$7;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, *entity = NULL, entity_sub, __$null, validators, messages, scope, field, validator, status, combinedFieldsValidators, *_1, _2, *_12, _13, _3$$10, _5$$10, _6$$14, _7$$14, _8$$16, _9$$16, _10$$20, _11$$20, _14$$22, _15$$22, _16$$26, _17$$26, _18$$28, _19$$28, _20$$32, _21$$32, _22$$34;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&entity_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&validators);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&scope);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&combinedFieldsValidators);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_3$$10);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_6$$14);
	ZVAL_UNDEF(&_7$$14);
	ZVAL_UNDEF(&_8$$16);
	ZVAL_UNDEF(&_9$$16);
	ZVAL_UNDEF(&_10$$20);
	ZVAL_UNDEF(&_11$$20);
	ZVAL_UNDEF(&_14$$22);
	ZVAL_UNDEF(&_15$$22);
	ZVAL_UNDEF(&_16$$26);
	ZVAL_UNDEF(&_17$$26);
	ZVAL_UNDEF(&_18$$28);
	ZVAL_UNDEF(&_19$$28);
	ZVAL_UNDEF(&_20$$32);
	ZVAL_UNDEF(&_21$$32);
	ZVAL_UNDEF(&_22$$34);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data, &entity);

	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!entity) {
		entity = &entity_sub;
		entity = &__$null;
	}


	ZEPHIR_OBS_VAR(&validators);
	zephir_read_property(&validators, this_ptr, SL("_validators"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&combinedFieldsValidators);
	zephir_read_property(&combinedFieldsValidators, this_ptr, SL("_combinedFieldsValidators"), PH_NOISY_CC);
	if (Z_TYPE_P(&validators) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "There are no validators to validate", "phalcon/validation.zep", 85);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("_values"), &__$null);
	ZEPHIR_INIT_VAR(&messages);
	object_init_ex(&messages, phalcon_messages_messages_ce);
	ZEPHIR_CALL_METHOD(NULL, &messages, "__construct", NULL, 2);
	zephir_check_call_status();
	if (Z_TYPE_P(entity) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setentity", NULL, 0, entity);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(this_ptr, SL("beforevalidation") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&status, this_ptr, "beforevalidation", NULL, 0, data, entity, &messages);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
			RETURN_CCTOR(&status);
		}
	}
	zephir_update_property_zval(this_ptr, SL("_messages"), &messages);
	if (Z_TYPE_P(data) != IS_NULL) {
		_0$$7 = Z_TYPE_P(data) == IS_ARRAY;
		if (!(_0$$7)) {
			_0$$7 = Z_TYPE_P(data) == IS_OBJECT;
		}
		if (_0$$7) {
			zephir_update_property_zval(this_ptr, SL("_data"), data);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Invalid data to validate", "phalcon/validation.zep", 118);
			return;
		}
	}
	zephir_is_iterable(&validators, 0, "phalcon/validation.zep", 152);
	if (Z_TYPE_P(&validators) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _1)
		{
			ZEPHIR_INIT_NVAR(&scope);
			ZVAL_COPY(&scope, _1);
			if (Z_TYPE_P(&scope) != IS_ARRAY) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The validator scope is not valid", "phalcon/validation.zep", 125);
				return;
			}
			ZEPHIR_OBS_NVAR(&field);
			zephir_array_fetch_long(&field, &scope, 0, PH_NOISY, "phalcon/validation.zep", 128 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&validator);
			zephir_array_fetch_long(&validator, &scope, 1, PH_NOISY, "phalcon/validation.zep", 129 TSRMLS_CC);
			if (Z_TYPE_P(&validator) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "One of the validators is not valid", "phalcon/validation.zep", 132);
				return;
			}
			ZEPHIR_CALL_METHOD(&_3$$10, this_ptr, "prechecking", &_4, 0, &field, &validator);
			zephir_check_call_status();
			if (zephir_is_true(&_3$$10)) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&_5$$10, &validator, "validate", NULL, 0, this_ptr, &field);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_5$$10)) {
				ZEPHIR_INIT_NVAR(&_7$$14);
				ZVAL_STRING(&_7$$14, "cancelOnFail");
				ZEPHIR_CALL_METHOD(&_6$$14, &validator, "getoption", NULL, 0, &_7$$14);
				zephir_check_call_status();
				if (zephir_is_true(&_6$$14)) {
					break;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &validators, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &validators, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&scope, &validators, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&scope) != IS_ARRAY) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The validator scope is not valid", "phalcon/validation.zep", 125);
					return;
				}
				ZEPHIR_OBS_NVAR(&field);
				zephir_array_fetch_long(&field, &scope, 0, PH_NOISY, "phalcon/validation.zep", 128 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&validator);
				zephir_array_fetch_long(&validator, &scope, 1, PH_NOISY, "phalcon/validation.zep", 129 TSRMLS_CC);
				if (Z_TYPE_P(&validator) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "One of the validators is not valid", "phalcon/validation.zep", 132);
					return;
				}
				ZEPHIR_CALL_METHOD(&_8$$16, this_ptr, "prechecking", &_4, 0, &field, &validator);
				zephir_check_call_status();
				if (zephir_is_true(&_8$$16)) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&_9$$16, &validator, "validate", NULL, 0, this_ptr, &field);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_9$$16)) {
					ZEPHIR_INIT_NVAR(&_11$$20);
					ZVAL_STRING(&_11$$20, "cancelOnFail");
					ZEPHIR_CALL_METHOD(&_10$$20, &validator, "getoption", NULL, 0, &_11$$20);
					zephir_check_call_status();
					if (zephir_is_true(&_10$$20)) {
						break;
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&scope);
	zephir_is_iterable(&combinedFieldsValidators, 0, "phalcon/validation.zep", 184);
	if (Z_TYPE_P(&combinedFieldsValidators) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&combinedFieldsValidators), _12)
		{
			ZEPHIR_INIT_NVAR(&scope);
			ZVAL_COPY(&scope, _12);
			if (Z_TYPE_P(&scope) != IS_ARRAY) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The validator scope is not valid", "phalcon/validation.zep", 154);
				return;
			}
			ZEPHIR_OBS_NVAR(&field);
			zephir_array_fetch_long(&field, &scope, 0, PH_NOISY, "phalcon/validation.zep", 157 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&validator);
			zephir_array_fetch_long(&validator, &scope, 1, PH_NOISY, "phalcon/validation.zep", 158 TSRMLS_CC);
			if (Z_TYPE_P(&validator) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "One of the validators is not valid", "phalcon/validation.zep", 161);
				return;
			}
			ZEPHIR_CALL_METHOD(&_14$$22, this_ptr, "prechecking", &_4, 0, &field, &validator);
			zephir_check_call_status();
			if (zephir_is_true(&_14$$22)) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&_15$$22, &validator, "validate", NULL, 0, this_ptr, &field);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_15$$22)) {
				ZEPHIR_INIT_NVAR(&_17$$26);
				ZVAL_STRING(&_17$$26, "cancelOnFail");
				ZEPHIR_CALL_METHOD(&_16$$26, &validator, "getoption", NULL, 0, &_17$$26);
				zephir_check_call_status();
				if (zephir_is_true(&_16$$26)) {
					break;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &combinedFieldsValidators, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_13, &combinedFieldsValidators, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_13)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&scope, &combinedFieldsValidators, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&scope) != IS_ARRAY) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The validator scope is not valid", "phalcon/validation.zep", 154);
					return;
				}
				ZEPHIR_OBS_NVAR(&field);
				zephir_array_fetch_long(&field, &scope, 0, PH_NOISY, "phalcon/validation.zep", 157 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&validator);
				zephir_array_fetch_long(&validator, &scope, 1, PH_NOISY, "phalcon/validation.zep", 158 TSRMLS_CC);
				if (Z_TYPE_P(&validator) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "One of the validators is not valid", "phalcon/validation.zep", 161);
					return;
				}
				ZEPHIR_CALL_METHOD(&_18$$28, this_ptr, "prechecking", &_4, 0, &field, &validator);
				zephir_check_call_status();
				if (zephir_is_true(&_18$$28)) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&_19$$28, &validator, "validate", NULL, 0, this_ptr, &field);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_19$$28)) {
					ZEPHIR_INIT_NVAR(&_21$$32);
					ZVAL_STRING(&_21$$32, "cancelOnFail");
					ZEPHIR_CALL_METHOD(&_20$$32, &validator, "getoption", NULL, 0, &_21$$32);
					zephir_check_call_status();
					if (zephir_is_true(&_20$$32)) {
						break;
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &combinedFieldsValidators, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&scope);
	if ((zephir_method_exists_ex(this_ptr, SL("aftervalidation") TSRMLS_CC) == SUCCESS)) {
		zephir_read_property(&_22$$34, this_ptr, SL("_messages"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "aftervalidation", NULL, 0, data, entity, &_22$$34);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "_messages");

}

/**
 * Adds a validator to a field
 */
PHP_METHOD(Phalcon_Validation, add) {

	zval _0$$4, _3$$6, _4$$7, _5$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *validator, validator_sub, singleField, *_1$$5, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator_sub);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field, &validator);



	if (Z_TYPE_P(field) == IS_ARRAY) {
		if (zephir_instance_of_ev(validator, phalcon_validation_combinedfieldsvalidator_ce TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_create_array(&_0$$4, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&_0$$4, field);
			zephir_array_fast_append(&_0$$4, validator);
			zephir_update_property_array_append(this_ptr, SL("_combinedFieldsValidators"), &_0$$4);
			ZEPHIR_INIT_NVAR(&_0$$4);
		} else {
			zephir_is_iterable(field, 0, "phalcon/validation.zep", 206);
			if (Z_TYPE_P(field) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(field), _1$$5)
				{
					ZEPHIR_INIT_NVAR(&singleField);
					ZVAL_COPY(&singleField, _1$$5);
					ZEPHIR_INIT_NVAR(&_3$$6);
					zephir_create_array(&_3$$6, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(&_3$$6, &singleField);
					zephir_array_fast_append(&_3$$6, validator);
					zephir_update_property_array_append(this_ptr, SL("_validators"), &_3$$6);
					ZEPHIR_INIT_NVAR(&_3$$6);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, field, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_2$$5, field, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_2$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&singleField, field, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_4$$7);
						zephir_create_array(&_4$$7, 2, 0 TSRMLS_CC);
						zephir_array_fast_append(&_4$$7, &singleField);
						zephir_array_fast_append(&_4$$7, validator);
						zephir_update_property_array_append(this_ptr, SL("_validators"), &_4$$7);
						ZEPHIR_INIT_NVAR(&_4$$7);
					ZEPHIR_CALL_METHOD(NULL, field, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&singleField);
		}
	} else if (Z_TYPE_P(field) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5$$8);
		zephir_create_array(&_5$$8, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_5$$8, field);
		zephir_array_fast_append(&_5$$8, validator);
		zephir_update_property_array_append(this_ptr, SL("_validators"), &_5$$8);
		ZEPHIR_INIT_NVAR(&_5$$8);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Field must be passed as array of fields or string", "phalcon/validation.zep", 212);
		return;
	}
	RETURN_THIS();

}

/**
 * Alias of `add` method
 */
PHP_METHOD(Phalcon_Validation, rule) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *validator, validator_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator_sub);

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

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval validators;
	zval *field, field_sub, *validators_param = NULL, validator, *_0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&validators);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field, &validators_param);

	ZEPHIR_OBS_COPY_OR_DUP(&validators, validators_param);


	zephir_is_iterable(&validators, 0, "phalcon/validation.zep", 238);
	if (Z_TYPE_P(&validators) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&validators), _0)
		{
			ZEPHIR_INIT_NVAR(&validator);
			ZVAL_COPY(&validator, _0);
			if (zephir_instance_of_ev(&validator, phalcon_validation_validatorinterface_ce TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_2, 0, field, &validator);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &validators, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &validators, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&validator, &validators, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_instance_of_ev(&validator, phalcon_validation_validatorinterface_ce TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_2, 195, field, &validator);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &validators, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&validator);
	RETURN_THIS();

}

/**
 * Adds filters to the field
 *
 * @param string field
 * @param array|string filters
 */
PHP_METHOD(Phalcon_Validation, setFilters) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *filters, filters_sub, singleField, *_0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field, &filters);



	if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_is_iterable(field, 0, "phalcon/validation.zep", 254);
		if (Z_TYPE_P(field) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(field), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&singleField);
				ZVAL_COPY(&singleField, _0$$3);
				zephir_update_property_array(this_ptr, SL("_filters"), &singleField, filters);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, field, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, field, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&singleField, field, "current", NULL, 0);
				zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("_filters"), &singleField, filters);
				ZEPHIR_CALL_METHOD(NULL, field, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&singleField);
	} else if (Z_TYPE_P(field) == IS_STRING) {
		zephir_update_property_array(this_ptr, SL("_filters"), field, filters);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Field must be passed as array of fields or string.", "phalcon/validation.zep", 259);
		return;
	}
	RETURN_THIS();

}

/**
 * Returns all the filters or a specific one
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation, getFilters) {

	zend_bool _0;
	zval *field_param = NULL, filters, fieldFilters;
	zval field;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&fieldFilters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &field_param);

	if (!field_param) {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_STRING(&field, "");
	} else {
		zephir_get_strval(&field, field_param);
	}


	zephir_read_property(&filters, this_ptr, SL("_filters"), PH_NOISY_CC | PH_READONLY);
	_0 = ZEPHIR_IS_STRING_IDENTICAL(&field, "");
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING_IDENTICAL(&field, "");
	}
	if (_0) {
		RETURN_CTOR(&filters);
	}
	if (!(zephir_array_isset_fetch(&fieldFilters, &filters, &field, 1 TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	RETURN_CTOR(&fieldFilters);

}

/**
 * Returns the validators added to the validation
 */
PHP_METHOD(Phalcon_Validation, getValidators) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_validators");

}

/**
 * Sets the bound entity
 *
 * @param object entity
 */
PHP_METHOD(Phalcon_Validation, setEntity) {

	zval *entity, entity_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&entity_sub);

	zephir_fetch_params(0, 1, 0, &entity);



	if (Z_TYPE_P(entity) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_validation_exception_ce, "Entity must be an object", "phalcon/validation.zep", 301);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("_entity"), entity);

}

/**
 * Returns the bound entity
 *
 * @return object
 */
PHP_METHOD(Phalcon_Validation, getEntity) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_entity");

}

/**
 * Adds default messages to validators
 */
PHP_METHOD(Phalcon_Validation, setDefaultMessages) {

	zval *messages_param = NULL, defaultMessages, _0;
	zval messages;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&defaultMessages);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &messages_param);

	if (!messages_param) {
		ZEPHIR_INIT_VAR(&messages);
		array_init(&messages);
	} else {
		zephir_get_arrval(&messages, messages_param);
	}


	ZEPHIR_INIT_VAR(&defaultMessages);
	zephir_create_array(&defaultMessages, 25, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&defaultMessages, SL("Alnum"), SL("Field :field must contain only letters and numbers"));
	add_assoc_stringl_ex(&defaultMessages, SL("Alpha"), SL("Field :field must contain only letters"));
	add_assoc_stringl_ex(&defaultMessages, SL("Between"), SL("Field :field must be within the range of :min to :max"));
	add_assoc_stringl_ex(&defaultMessages, SL("Confirmation"), SL("Field :field must be the same as :with"));
	add_assoc_stringl_ex(&defaultMessages, SL("Digit"), SL("Field :field must be numeric"));
	add_assoc_stringl_ex(&defaultMessages, SL("Email"), SL("Field :field must be an email address"));
	add_assoc_stringl_ex(&defaultMessages, SL("ExclusionIn"), SL("Field :field must not be a part of list: :domain"));
	add_assoc_stringl_ex(&defaultMessages, SL("FileEmpty"), SL("Field :field must not be empty"));
	add_assoc_stringl_ex(&defaultMessages, SL("FileIniSize"), SL("File :field exceeds the maximum file size"));
	add_assoc_stringl_ex(&defaultMessages, SL("FileMaxResolution"), SL("File :field must not exceed :max resolution"));
	add_assoc_stringl_ex(&defaultMessages, SL("FileMinResolution"), SL("File :field must be at least :min resolution"));
	add_assoc_stringl_ex(&defaultMessages, SL("FileSize"), SL("File :field exceeds the size of :max"));
	add_assoc_stringl_ex(&defaultMessages, SL("FileType"), SL("File :field must be of type: :types"));
	add_assoc_stringl_ex(&defaultMessages, SL("FileValid"), SL("Field :field is not valid"));
	add_assoc_stringl_ex(&defaultMessages, SL("Identical"), SL("Field :field does not have the expected value"));
	add_assoc_stringl_ex(&defaultMessages, SL("InclusionIn"), SL("Field :field must be a part of list: :domain"));
	add_assoc_stringl_ex(&defaultMessages, SL("Numericality"), SL("Field :field does not have a valid numeric format"));
	add_assoc_stringl_ex(&defaultMessages, SL("PresenceOf"), SL("Field :field is required"));
	add_assoc_stringl_ex(&defaultMessages, SL("Regex"), SL("Field :field does not match the required format"));
	add_assoc_stringl_ex(&defaultMessages, SL("TooLong"), SL("Field :field must not exceed :max characters long"));
	add_assoc_stringl_ex(&defaultMessages, SL("TooShort"), SL("Field :field must be at least :min characters long"));
	add_assoc_stringl_ex(&defaultMessages, SL("Uniqueness"), SL("Field :field must be unique"));
	add_assoc_stringl_ex(&defaultMessages, SL("Url"), SL("Field :field must be a url"));
	add_assoc_stringl_ex(&defaultMessages, SL("CreditCard"), SL("Field :field is not valid for a credit card number"));
	add_assoc_stringl_ex(&defaultMessages, SL("Date"), SL("Field :field is not a valid date"));
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_array_merge(&_0, &defaultMessages, &messages TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_defaultMessages"), &_0);
	RETURN_MM_MEMBER(getThis(), "_defaultMessages");

}

/**
 * Get default message for validator type
 */
PHP_METHOD(Phalcon_Validation, getDefaultMessage) {

	zval *type_param = NULL, defaultMessage, _0;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&defaultMessage);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	zephir_read_property(&_0, this_ptr, SL("_defaultMessages"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&defaultMessage, &_0, &type, 1 TSRMLS_CC)) {
		RETURN_CTOR(&defaultMessage);
	}
	RETURN_MM_STRING("");

}

/**
 * Returns the registered validators
 */
PHP_METHOD(Phalcon_Validation, getMessages) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_messages");

}

/**
 * Adds labels for fields
 */
PHP_METHOD(Phalcon_Validation, setLabels) {

	zval *labels_param = NULL;
	zval labels;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&labels);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &labels_param);

	ZEPHIR_OBS_COPY_OR_DUP(&labels, labels_param);


	zephir_update_property_zval(this_ptr, SL("_labels"), &labels);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get label for field
 *
 * @param string field
 */
PHP_METHOD(Phalcon_Validation, getLabel) {

	zval *field, field_sub, labels, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&labels);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field);



	ZEPHIR_OBS_VAR(&labels);
	zephir_read_property(&labels, this_ptr, SL("_labels"), PH_NOISY_CC);
	if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_fast_join_str(return_value, SL(", "), field TSRMLS_CC);
		RETURN_MM();
	}
	if (zephir_array_isset_fetch(&value, &labels, field, 1 TSRMLS_CC)) {
		RETURN_CTOR(&value);
	}
	RETVAL_ZVAL(field, 1, 0);
	RETURN_MM();

}

/**
 * Appends a message to the messages list
 */
PHP_METHOD(Phalcon_Validation, appendMessage) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, messages;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&messages);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_OBS_VAR(&messages);
	zephir_read_property(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (Z_TYPE_P(&messages) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&messages);
		object_init_ex(&messages, phalcon_messages_messages_ce);
		ZEPHIR_CALL_METHOD(NULL, &messages, "__construct", NULL, 2);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &messages, "appendmessage", NULL, 447, message);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_messages"), &messages);
	RETURN_THIS();

}

/**
 * Assigns the data to an entity
 * The entity is used to obtain the validation values
 *
 * @param object entity
 * @param array|object data
 */
PHP_METHOD(Phalcon_Validation, bind) {

	zend_bool _0;
	zval *entity, entity_sub, *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&entity_sub);
	ZVAL_UNDEF(&data_sub);

	zephir_fetch_params(0, 2, 0, &entity, &data);



	if (Z_TYPE_P(entity) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_validation_exception_ce, "Entity must be an object", "phalcon/validation.zep", 437);
		return;
	}
	_0 = Z_TYPE_P(data) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(data) != IS_OBJECT;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_validation_exception_ce, "Data to validate must be an array or object", "phalcon/validation.zep", 441);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("_entity"), entity);
	zephir_update_property_zval(this_ptr, SL("_data"), data);
	RETURN_THISW();

}

/**
 * Gets the a value to validate in the array/object data source
 */
PHP_METHOD(Phalcon_Validation, getValue) {

	zend_bool _0$$10;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, entity, method, value, data, values, filters, fieldFilters, dependencyInjector, filterService, camelizedField, _2$$20, _3$$20, _4$$28;
	zval field;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&entity);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&fieldFilters);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&filterService);
	ZVAL_UNDEF(&camelizedField);
	ZVAL_UNDEF(&_2$$20);
	ZVAL_UNDEF(&_3$$20);
	ZVAL_UNDEF(&_4$$28);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	zephir_get_strval(&field, field_param);


	ZEPHIR_OBS_VAR(&entity);
	zephir_read_property(&entity, this_ptr, SL("_entity"), PH_NOISY_CC);
	if (Z_TYPE_P(&entity) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&camelizedField);
		zephir_camelize(&camelizedField, &field, NULL  );
		ZEPHIR_INIT_VAR(&method);
		ZEPHIR_CONCAT_SV(&method, "get", &camelizedField);
		if ((zephir_method_exists(&entity, &method TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_CALL_METHOD_ZVAL(&value, &entity, &method, NULL, 0);
			zephir_check_call_status();
		} else {
			if ((zephir_method_exists_ex(&entity, SL("readattribute") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&value, &entity, "readattribute", NULL, 0, &field);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&value);
				if (zephir_isset_property_zval(&entity, &field TSRMLS_CC)) {
					zephir_read_property_zval(&value, &entity, &field, PH_NOISY_CC);
				} else {
					ZVAL_NULL(&value);
				}
			}
		}
	} else {
		ZEPHIR_OBS_VAR(&data);
		zephir_read_property(&data, this_ptr, SL("_data"), PH_NOISY_CC);
		_0$$10 = Z_TYPE_P(&data) != IS_ARRAY;
		if (_0$$10) {
			_0$$10 = Z_TYPE_P(&data) != IS_OBJECT;
		}
		if (_0$$10) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "There is no data to validate", "phalcon/validation.zep", 483);
			return;
		}
		ZEPHIR_OBS_VAR(&values);
		zephir_read_property(&values, this_ptr, SL("_values"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&value);
		if (zephir_array_isset_fetch(&value, &values, &field, 0 TSRMLS_CC)) {
			RETURN_CCTOR(&value);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_NULL(&value);
		if (Z_TYPE_P(&data) == IS_ARRAY) {
			if (zephir_array_isset(&data, &field)) {
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch(&value, &data, &field, PH_NOISY, "phalcon/validation.zep", 495 TSRMLS_CC);
			}
		} else {
			if (Z_TYPE_P(&data) == IS_OBJECT) {
				if (zephir_isset_property_zval(&data, &field TSRMLS_CC)) {
					ZEPHIR_OBS_NVAR(&value);
					zephir_read_property_zval(&value, &data, &field, PH_NOISY_CC);
				}
			}
		}
	}
	if (Z_TYPE_P(&value) == IS_NULL) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(&filters);
	zephir_read_property(&filters, this_ptr, SL("_filters"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&fieldFilters);
	if (zephir_array_isset_fetch(&fieldFilters, &filters, &field, 0 TSRMLS_CC)) {
		if (zephir_is_true(&fieldFilters)) {
			ZEPHIR_CALL_METHOD(&dependencyInjector, this_ptr, "getdi", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
				ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_1, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "A dependency injector is required to obtain the 'filter' service", "phalcon/validation.zep", 520);
					return;
				}
			}
			ZEPHIR_INIT_VAR(&_3$$20);
			ZVAL_STRING(&_3$$20, "filter");
			ZEPHIR_CALL_METHOD(&_2$$20, &dependencyInjector, "getshared", NULL, 0, &_3$$20);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&filterService, &_2$$20);
			if (Z_TYPE_P(&filterService) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Returned 'filter' service is invalid", "phalcon/validation.zep", 527);
				return;
			}
			ZEPHIR_CALL_METHOD(&_2$$20, &filterService, "sanitize", NULL, 0, &value, &fieldFilters);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&value, &_2$$20);
			if (Z_TYPE_P(&entity) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(&method);
				ZEPHIR_CONCAT_SV(&method, "set", &camelizedField);
				if ((zephir_method_exists(&entity, &method TSRMLS_CC)  == SUCCESS)) {
					ZEPHIR_CALL_METHOD_ZVAL(NULL, &entity, &method, NULL, 0, &value);
					zephir_check_call_status();
				} else {
					if ((zephir_method_exists_ex(&entity, SL("writeattribute") TSRMLS_CC) == SUCCESS)) {
						ZEPHIR_CALL_METHOD(NULL, &entity, "writeattribute", NULL, 0, &field, &value);
						zephir_check_call_status();
					} else {
						ZEPHIR_CALL_FUNCTION(&_4$$28, "property_exists", NULL, 315, &entity, &field);
						zephir_check_call_status();
						if (zephir_is_true(&_4$$28)) {
							zephir_update_property_zval_zval(&entity, &field, &value TSRMLS_CC);
						}
					}
				}
			}
			RETURN_CCTOR(&value);
		}
	}
	if (Z_TYPE_P(&entity) != IS_OBJECT) {
		zephir_update_property_array(this_ptr, SL("_values"), &field, &value);
	}
	RETURN_CCTOR(&value);

}

/**
 * Internal validations, if it returns true, then skip the current validator
 */
PHP_METHOD(Phalcon_Validation, preChecking) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *validator, validator_sub, singleField, allowEmpty, emptyValue, value, result, *_0$$3, _1$$3, _3$$8, _4$$8, *_5$$11, _6$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator_sub);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&allowEmpty);
	ZVAL_UNDEF(&emptyValue);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_6$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field, &validator);



	if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_is_iterable(field, 0, "phalcon/validation.zep", 575);
		if (Z_TYPE_P(field) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(field), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&singleField);
				ZVAL_COPY(&singleField, _0$$3);
				ZEPHIR_CALL_METHOD(&result, this_ptr, "prechecking", &_2, 448, &singleField, validator);
				zephir_check_call_status();
				if (zephir_is_true(&result)) {
					RETURN_CCTOR(&result);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, field, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, field, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&singleField, field, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&result, this_ptr, "prechecking", &_2, 448, &singleField, validator);
					zephir_check_call_status();
					if (zephir_is_true(&result)) {
						RETURN_CCTOR(&result);
					}
				ZEPHIR_CALL_METHOD(NULL, field, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&singleField);
	} else {
		ZEPHIR_INIT_VAR(&_3$$8);
		ZVAL_STRING(&_3$$8, "allowEmpty");
		ZVAL_BOOL(&_4$$8, 0);
		ZEPHIR_CALL_METHOD(&allowEmpty, validator, "getoption", NULL, 0, &_3$$8, &_4$$8);
		zephir_check_call_status();
		if (zephir_is_true(&allowEmpty)) {
			if ((zephir_method_exists_ex(validator, SL("isallowempty") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_RETURN_CALL_METHOD(validator, "isallowempty", NULL, 0, this_ptr, field);
				zephir_check_call_status();
				RETURN_MM();
			}
			ZEPHIR_CALL_METHOD(&value, this_ptr, "getvalue", NULL, 0, field);
			zephir_check_call_status();
			if (Z_TYPE_P(&allowEmpty) == IS_ARRAY) {
				zephir_is_iterable(&allowEmpty, 0, "phalcon/validation.zep", 589);
				if (Z_TYPE_P(&allowEmpty) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&allowEmpty), _5$$11)
					{
						ZEPHIR_INIT_NVAR(&emptyValue);
						ZVAL_COPY(&emptyValue, _5$$11);
						if (ZEPHIR_IS_IDENTICAL(&emptyValue, &value)) {
							RETURN_MM_BOOL(1);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &allowEmpty, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_6$$11, &allowEmpty, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_6$$11)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&emptyValue, &allowEmpty, "current", NULL, 0);
						zephir_check_call_status();
							if (ZEPHIR_IS_IDENTICAL(&emptyValue, &value)) {
								RETURN_MM_BOOL(1);
							}
						ZEPHIR_CALL_METHOD(NULL, &allowEmpty, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&emptyValue);
				RETURN_MM_BOOL(0);
			}
			RETURN_MM_BOOL(ZEPHIR_IS_EMPTY(&value));
		}
	}
	RETURN_MM_BOOL(0);

}

zend_object *zephir_init_properties_Phalcon_Validation(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_labels"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_labels"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("_filters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("_filters"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("_combinedFieldsValidators"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("_combinedFieldsValidators"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("_validators"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("_validators"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

