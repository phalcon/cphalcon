
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Checks if a value has a valid credit card number
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\CreditCard as CreditCardValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "creditCard",
 *     new CreditCardValidator(
 *         [
 *             "message" => "The credit card number is not valid",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "creditCard",
 *         "secondCreditCard",
 *     ],
 *     new CreditCardValidator(
 *         [
 *             "message" => [
 *                 "creditCard"       => "The credit card number is not valid",
 *                 "secondCreditCard" => "The second credit card number is not valid",
 *             ],
 *         ]
 *     )
 * );
 * ```
 *
 * @phpstan-import-type filter_validator_options from FilterTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_CreditCard)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator, CreditCard, phalcon, filter_validation_validator_creditcard, phalcon_filter_validation_abstractvalidator_ce, phalcon_filter_validation_validator_creditcard_method_entry, 0);

	/**
	 * @var string|null
	 */
	zend_declare_property_string(phalcon_filter_validation_validator_creditcard_ce, SL("template"), "Field :field is not valid for a credit card number", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Constructor
 *
 * @phpstan-param filter_validator_options $options
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_CreditCard, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL;
	zval options;

	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_filter_validation_validator_creditcard_ce, getThis(), "__construct", NULL, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_CreditCard, validate)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, value, valid, _0, _1, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&valid);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field);
	ZEPHIR_CALL_METHOD(&value, validation, "getValue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "allowEmpty", NULL, 0, field, &value);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "rejectNonStringable", NULL, 0, validation, field, &value);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		RETURN_MM_BOOL(0);
	}
	zephir_cast_to_string(&_2, &value);
	ZEPHIR_CALL_METHOD(&valid, this_ptr, "verifyByLuhnAlgorithm", NULL, 0, &_2);
	zephir_check_call_status();
	if (!(zephir_is_true(&valid))) {
		ZEPHIR_CALL_METHOD(&_3$$5, this_ptr, "messageFactory", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendMessage", NULL, 0, &_3$$5);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

/**
 * is a simple checksum formula used to validate a variety of identification
 * numbers
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_CreditCard, verifyByLuhnAlgorithm)
{
	zend_bool _11;
	zend_ulong _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval number_zv, digit, digits, position, hash, result, _0, _1, *_2, _3, *_4, _10, _15, _16, _7$$4, _8$$4, _9$$4, _12$$5, _13$$5, _14$$5;
	zend_string *number = NULL, *_6;

	ZVAL_UNDEF(&number_zv);
	ZVAL_UNDEF(&digit);
	ZVAL_UNDEF(&digits);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(number)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&number_zv);
	ZVAL_STR_COPY(&number_zv, number);
	ZEPHIR_INIT_VAR(&hash);
	ZVAL_STRING(&hash, "");
	ZEPHIR_CALL_FUNCTION(&_0, "ctype_digit", NULL, 0, &number_zv);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_FUNCTION(&_1, "str_split", NULL, 216, &number_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&digits, "array_reverse", NULL, 273, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&digits) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_string_to_char_array(&_3, &digits);
		_2 = &_3;
	} else {
		_2 = &digits;
	}
	zephir_is_iterable(_2, 0, "phalcon/Filter/Validation/Validator/CreditCard.zep", 117);
	if (Z_TYPE_P(_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_2), _5, _6, _4)
		{
			ZEPHIR_INIT_NVAR(&position);
			if (_6 != NULL) { 
				ZVAL_STR_COPY(&position, _6);
			} else {
				ZVAL_LONG(&position, _5);
			}
			ZEPHIR_INIT_NVAR(&digit);
			ZVAL_COPY(&digit, _4);
			ZEPHIR_INIT_NVAR(&_7$$4);
			ZEPHIR_INIT_NVAR(&_8$$4);
			zephir_mod_zval_long(&_8$$4, &position, 2);
			if (zephir_is_true(&_8$$4)) {
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZVAL_LONG(&_9$$4, 2);
				ZEPHIR_INIT_NVAR(&_7$$4);
				mul_function(&_7$$4, &digit, &_9$$4);
			} else {
				ZEPHIR_CPY_WRT(&_7$$4, &digit);
			}
			zephir_concat_self(&hash, &_7$$4);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _2, "rewind", NULL, 0);
		zephir_check_call_status();
		_11 = 1;
		while (1) {
			if (_11) {
				_11 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _2, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_10, _2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&position, _2, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&digit, _2, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZEPHIR_INIT_NVAR(&_13$$5);
				zephir_mod_zval_long(&_13$$5, &position, 2);
				if (zephir_is_true(&_13$$5)) {
					ZEPHIR_INIT_NVAR(&_14$$5);
					ZVAL_LONG(&_14$$5, 2);
					ZEPHIR_INIT_NVAR(&_12$$5);
					mul_function(&_12$$5, &digit, &_14$$5);
				} else {
					ZEPHIR_CPY_WRT(&_12$$5, &digit);
				}
				zephir_concat_self(&hash, &_12$$5);
		}
	}
	ZEPHIR_INIT_NVAR(&digit);
	ZEPHIR_INIT_NVAR(&position);
	ZEPHIR_CALL_FUNCTION(&_15, "str_split", NULL, 216, &hash);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "array_sum", NULL, 0, &_15);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_16);
	zephir_mod_zval_long(&_16, &result, 10);
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(&_16, 0));
}

