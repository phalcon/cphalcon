
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/hash.h"


/**
 * Phalcon\Validation\Validator\CreditCard
 *
 * Checks if a value has a valid credit card number
 *
 * <code>
 * use Phalcon\Validation\Validator\CreditCard as CreditCardValidator;
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, message, label, replacePairs, value, valid, code, _0$$3, _5$$3, _6$$3, _1$$4, _2$$6, _3$$7, _4$$8;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&valid);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&field);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(&field, field_param);
	} else {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_EMPTY_STRING(&field);
	}


	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, &field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&valid, this_ptr, "verifybyluhnalgorithm", NULL, 467, &value);
	zephir_check_call_status();
	if (!(zephir_is_true(&valid))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "label");
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, &_0$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(&label) == IS_ARRAY) {
			zephir_array_fetch(&_1$$4, &label, &field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/creditcard.zep", 75 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&label, &_1$$4);
		}
		if (ZEPHIR_IS_EMPTY(&label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "message");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_0$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(&message) == IS_ARRAY) {
			zephir_array_fetch(&_2$$6, &message, &field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/creditcard.zep", 83 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&message, &_2$$6);
		}
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(&message)) {
			ZEPHIR_INIT_VAR(&_3$$7);
			ZVAL_STRING(&_3$$7, "CreditCard");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_3$$7);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "code");
		ZEPHIR_CALL_METHOD(&code, this_ptr, "getoption", NULL, 0, &_0$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(&code) == IS_ARRAY) {
			zephir_array_fetch(&_4$$8, &code, &field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/creditcard.zep", 92 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&code, &_4$$8);
		}
		ZEPHIR_INIT_NVAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "strtr", NULL, 26, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "CreditCard");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 464, &_5$$3, &field, &_6$$3, &code);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_0$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * is a simple checksum formula used to validate a variety of identification numbers
 * @param  string number
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_CreditCard, verifyByLuhnAlgorithm) {

	zend_string *_7;
	zend_ulong _6;
	zval digits, _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *number, number_sub, _0, digit, position, hash, _3, _4, *_5, result, _9, _8$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&number_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&digit);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&digits);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number);



	ZEPHIR_CALL_FUNCTION(&_0, "str_split", &_1, 74, number);
	zephir_check_call_status();
	zephir_get_arrval(&_2, &_0);
	ZEPHIR_CPY_WRT(&digits, &_2);
	ZEPHIR_INIT_VAR(&hash);
	ZVAL_STRING(&hash, "");
	ZEPHIR_CALL_FUNCTION(&_4, "array_reverse", NULL, 468, &digits);
	zephir_check_call_status();
	zephir_is_iterable(&_4, 0, "phalcon/validation/validator/creditcard.zep", 118);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_4), _6, _7, _5)
	{
		ZEPHIR_INIT_NVAR(&position);
		if (_7 != NULL) { 
			ZVAL_STR_COPY(&position, _7);
		} else {
			ZVAL_LONG(&position, _6);
		}
		ZEPHIR_INIT_NVAR(&digit);
		ZVAL_COPY(&digit, _5);
		ZEPHIR_INIT_LNVAR(_8$$3);
		if (zephir_safe_mod_zval_long(&position, 2 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZVAL_LONG(&_8$$3, (zephir_get_numberval(&digit) * 2));
		} else {
			ZEPHIR_CPY_WRT(&_8$$3, &digit);
		}
		zephir_concat_self(&hash, &_8$$3 TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&digit);
	ZEPHIR_INIT_NVAR(&position);
	ZEPHIR_CALL_FUNCTION(&_9, "str_split", &_1, 74, &hash);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "array_sum", NULL, 469, &_9);
	zephir_check_call_status();
	RETURN_MM_BOOL((zephir_safe_mod_zval_long(&result, 10 TSRMLS_CC) == 0));

}

