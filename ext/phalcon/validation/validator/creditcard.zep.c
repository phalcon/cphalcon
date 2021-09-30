
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"


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
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\CreditCard as CreditCardValidator;
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
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_CreditCard)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, CreditCard, phalcon, validation_validator_creditcard, phalcon_validation_abstractvalidator_ce, phalcon_validation_validator_creditcard_method_entry, 0);

	zend_declare_property_string(phalcon_validation_validator_creditcard_ce, SL("template"), "Field :field is not valid for a credit card number", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Constructor
 *
 * @param array options = [
 *     'message' => '',
 *     'template' => '',
 *     'allowEmpty' => false
 * ]
 */
PHP_METHOD(Phalcon_Validation_Validator_CreditCard, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_CALL_PARENT(NULL, phalcon_validation_validator_creditcard_ce, getThis(), "__construct", &_0, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_CreditCard, validate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, value, valid, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&valid);
	ZVAL_UNDEF(&_0$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);


	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&valid, this_ptr, "verifybyluhnalgorithm", NULL, 0, &value);
	zephir_check_call_status();
	if (!(zephir_is_true(&valid))) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "messagefactory", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_0$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

/**
 * is a simple checksum formula used to validate a variety of identification
 * numbers
 */
PHP_METHOD(Phalcon_Validation_Validator_CreditCard, verifyByLuhnAlgorithm)
{
	zend_string *_7;
	zend_ulong _6;
	zval digits, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *number_param = NULL, digit, position, hash, result, _0, _2, _3, *_4, _5, _10, _8$$3, _9$$4;
	zval number;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&digit);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&digits);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(number)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number_param);
	zephir_get_strval(&number, number_param);


	ZEPHIR_INIT_VAR(&hash);
	ZVAL_STRING(&hash, "");
	ZEPHIR_CALL_FUNCTION(&_0, "str_split", NULL, 109, &number);
	zephir_check_call_status();
	zephir_get_arrval(&_1, &_0);
	ZEPHIR_CPY_WRT(&digits, &_1);
	ZEPHIR_CALL_FUNCTION(&_3, "array_reverse", NULL, 0, &digits);
	zephir_check_call_status();
	zephir_is_iterable(&_3, 0, "phalcon/Validation/Validator/CreditCard.zep", 106);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_3), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&position);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&position, _7);
			} else {
				ZVAL_LONG(&position, _6);
			}
			ZEPHIR_INIT_NVAR(&digit);
			ZVAL_COPY(&digit, _4);
			ZEPHIR_INIT_NVAR(&_8$$3);
			if (zephir_safe_mod_zval_long(&position, 2)) {
				ZEPHIR_INIT_NVAR(&_8$$3);
				ZVAL_LONG(&_8$$3, (zephir_get_numberval(&digit) * 2));
			} else {
				ZEPHIR_CPY_WRT(&_8$$3, &digit);
			}
			zephir_concat_self(&hash, &_8$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&position, &_3, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&digit, &_3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_9$$4);
				if (zephir_safe_mod_zval_long(&position, 2)) {
					ZEPHIR_INIT_NVAR(&_9$$4);
					ZVAL_LONG(&_9$$4, (zephir_get_numberval(&digit) * 2));
				} else {
					ZEPHIR_CPY_WRT(&_9$$4, &digit);
				}
				zephir_concat_self(&hash, &_9$$4);
			ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&digit);
	ZEPHIR_INIT_NVAR(&position);
	ZEPHIR_CALL_FUNCTION(&_10, "str_split", NULL, 109, &hash);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "array_sum", NULL, 0, &_10);
	zephir_check_call_status();
	RETURN_MM_BOOL((zephir_safe_mod_zval_long(&result, 10) == 0));
}

