
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
	ZEPHIR_CALL_METHOD(&valid, this_ptr, "verifybyluhnalgorithm", NULL, 451, &value);
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
		ZEPHIR_CALL_FUNCTION(&_1$$3, "strtr", NULL, 48, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "CreditCard");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 300, &_1$$3, field, &_2$$3, &code);
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

	zend_string *_7;
	zend_ulong _6;
	zval digits, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *number_param = NULL, _0, digit, position, hash, _2, _3, *_4, _5, result, _10, _8$$3, _9$$4;
	zval number;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&digit);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&digits);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number_param);

	zephir_get_strval(&number, number_param);


	ZEPHIR_CALL_FUNCTION(&_0, "str_split", NULL, 63, &number);
	zephir_check_call_status();
	zephir_get_arrval(&_1, &_0);
	ZEPHIR_CPY_WRT(&digits, &_1);
	ZEPHIR_INIT_VAR(&hash);
	ZVAL_STRING(&hash, "");
	ZEPHIR_CALL_FUNCTION(&_3, "array_reverse", NULL, 206, &digits);
	zephir_check_call_status();
	zephir_is_iterable(&_3, 0, "phalcon/validation/validator/creditcard.zep", 102);
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
			ZEPHIR_INIT_LNVAR(_8$$3);
			if (zephir_safe_mod_zval_long(&position, 2 TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(&_8$$3);
				ZVAL_LONG(&_8$$3, (zephir_get_numberval(&digit) * 2));
			} else {
				ZEPHIR_CPY_WRT(&_8$$3, &digit);
			}
			zephir_concat_self(&hash, &_8$$3 TSRMLS_CC);
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
				ZEPHIR_INIT_LNVAR(_9$$4);
				if (zephir_safe_mod_zval_long(&position, 2 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(&_9$$4);
					ZVAL_LONG(&_9$$4, (zephir_get_numberval(&digit) * 2));
				} else {
					ZEPHIR_CPY_WRT(&_9$$4, &digit);
				}
				zephir_concat_self(&hash, &_9$$4 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&digit);
	ZEPHIR_INIT_NVAR(&position);
	ZEPHIR_CALL_FUNCTION(&_10, "str_split", NULL, 63, &hash);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "array_sum", NULL, 452, &_10);
	zephir_check_call_status();
	RETURN_MM_BOOL((zephir_safe_mod_zval_long(&result, 10 TSRMLS_CC) == 0));

}

