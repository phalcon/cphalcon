
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
 * For the full copyright and license information, please view the LICENSE
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_filter_validation_validator_creditcard_ce, getThis(), "__construct", &_zephir_call_cache[0], &options);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field);
	ZEPHIR_CALL_METHOD_CACHED(&value, validation, "getValue", &_zephir_call_cache[0], field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "allowEmpty", &_zephir_call_cache[1], field, &value);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD_CACHED(&_1, this_ptr, "rejectNonStringable", &_zephir_call_cache[2], validation, field, &value);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		RETURN_MM_BOOL(0);
	}
	zephir_cast_to_string(&_2, &value);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&valid, this_ptr, "verifyByLuhnAlgorithm", &_zephir_call_cache[3], &_2);
	zephir_check_call_status();
	if (!(zephir_is_true(&valid))) {
		ZEPHIR_CALL_METHOD_CACHED(&_3$$5, this_ptr, "messageFactory", &_zephir_call_cache[4], validation, field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, validation, "appendMessage", &_zephir_call_cache[5], &_3$$5);
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
	zend_bool _12;
	zend_ulong _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval number_zv, digit, digits, position, hash, result, _0, _1, *_3, _4, *_5, _11, _16, _17, _8$$4, _9$$4, _10$$4, _13$$5, _14$$5, _15$$5;
	zend_string *number = NULL, *_7;

	ZVAL_UNDEF(&number_zv);
	ZVAL_UNDEF(&digit);
	ZVAL_UNDEF(&digits);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(number)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&number_zv);
	ZVAL_STR_COPY(&number_zv, number);
	ZEPHIR_INIT_VAR(&hash);
	ZVAL_STRING(&hash, "");
	ZEPHIR_CALL_FUNCTION(&_0, "ctype_digit", NULL, 150, &number_zv);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_FUNCTION(&_1, "str_split", &_2, 67, &number_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&digits, "array_reverse", NULL, 80, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&digits) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &digits);
		_3 = &_4;
	} else {
		_3 = &digits;
	}
	zephir_is_iterable(_3, 0, "phalcon/Filter/Validation/Validator/CreditCard.zep", 117);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_3), _6, _7, _5)
		{
			ZEPHIR_INIT_NVAR(&position);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&position, _7);
			} else {
				ZVAL_LONG(&position, _6);
			}
			ZEPHIR_INIT_NVAR(&digit);
			ZVAL_COPY(&digit, _5);
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZEPHIR_INIT_NVAR(&_9$$4);
			zephir_mod_zval_long(&_9$$4, &position, 2);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_true(&_9$$4)) {
				ZEPHIR_INIT_NVAR(&_10$$4);
				ZVAL_LONG(&_10$$4, 2);
				ZEPHIR_INIT_NVAR(&_8$$4);
				mul_function(&_8$$4, &digit, &_10$$4);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&_8$$4, &digit);
			}
			zephir_concat_self(&hash, &_8$$4);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "rewind", &_zephir_call_cache[0]);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "next", &_zephir_call_cache[1]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_11, _3, "valid", &_zephir_call_cache[2]);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&position, _3, "key", &_zephir_call_cache[3]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&digit, _3, "current", &_zephir_call_cache[4]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZEPHIR_INIT_NVAR(&_14$$5);
				zephir_mod_zval_long(&_14$$5, &position, 2);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_is_true(&_14$$5)) {
					ZEPHIR_INIT_NVAR(&_15$$5);
					ZVAL_LONG(&_15$$5, 2);
					ZEPHIR_INIT_NVAR(&_13$$5);
					mul_function(&_13$$5, &digit, &_15$$5);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&_13$$5, &digit);
				}
				zephir_concat_self(&hash, &_13$$5);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&digit);
	ZEPHIR_INIT_NVAR(&position);
	ZEPHIR_CALL_FUNCTION(&_16, "str_split", &_2, 67, &hash);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "array_sum", NULL, 156, &_16);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_17);
	zephir_mod_zval_long(&_17, &result, 10);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(&_17, 0));
}

