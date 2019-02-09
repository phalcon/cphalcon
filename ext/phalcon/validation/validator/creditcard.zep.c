
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Validation\Validator\CreditCard
 *
 * Checks if a value has a valid credit card number
 *
 * <code>
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
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_CreditCard) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, CreditCard, phalcon, validation_validator_creditcard, phalcon_validation_validator_ce, phalcon_validation_validator_creditcard_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_CreditCard, validate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, message, label, replacePairs, value, valid, code, _0$$3, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&valid);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&valid, this_ptr, "verifybyluhnalgorithm", NULL, 477, &value);
	zephir_check_call_status();
	if (!(zephir_is_true(&valid))) {
		ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "CreditCard");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&code, this_ptr, "preparecode", NULL, 0, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_messages_message_ce);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "strtr", NULL, 50, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "CreditCard");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 316, &_1$$3, field, &_2$$3, &code);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_0$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * is a simple checksum formula used to validate a variety of identification numbers
 */
PHP_METHOD(Phalcon_Validation_Validator_CreditCard, verifyByLuhnAlgorithm) {

	zend_string *_6;
	zend_ulong _5;
	zval digits, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *number_param = NULL, _0, digit, position, hash, _2, _3, *_4, result, _8, _7$$3;
	zval number;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&digit);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&digits);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number_param);

	zephir_get_strval(&number, number_param);


	ZEPHIR_CALL_FUNCTION(&_0, "str_split", NULL, 64, &number);
	zephir_check_call_status();
	zephir_get_arrval(&_1, &_0);
	ZEPHIR_CPY_WRT(&digits, &_1);
	ZEPHIR_INIT_VAR(&hash);
	ZVAL_STRING(&hash, "");
	ZEPHIR_CALL_FUNCTION(&_3, "array_reverse", NULL, 208, &digits);
	zephir_check_call_status();
	zephir_is_iterable(&_3, 0, "phalcon/validation/validator/creditcard.zep", 102);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_3), _5, _6, _4)
	{
		ZEPHIR_INIT_NVAR(&position);
		if (_6 != NULL) { 
			ZVAL_STR_COPY(&position, _6);
		} else {
			ZVAL_LONG(&position, _5);
		}
		ZEPHIR_INIT_NVAR(&digit);
		ZVAL_COPY(&digit, _4);
		ZEPHIR_INIT_LNVAR(_7$$3);
		if (zephir_safe_mod_zval_long(&position, 2 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(&_7$$3);
			ZVAL_LONG(&_7$$3, (zephir_get_numberval(&digit) * 2));
		} else {
			ZEPHIR_CPY_WRT(&_7$$3, &digit);
		}
		zephir_concat_self(&hash, &_7$$3 TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&digit);
	ZEPHIR_INIT_NVAR(&position);
	ZEPHIR_CALL_FUNCTION(&_8, "str_split", NULL, 64, &hash);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "array_sum", NULL, 478, &_8);
	zephir_check_call_status();
	RETURN_MM_BOOL((zephir_safe_mod_zval_long(&result, 10 TSRMLS_CC) == 0));

}

