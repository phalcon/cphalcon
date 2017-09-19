
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *message = NULL, *label = NULL, *replacePairs = NULL, *value = NULL, *valid = NULL, *code = NULL, *_0$$3 = NULL, *_1$$3 = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}


	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&valid, this_ptr, "verifybyluhnalgorithm", NULL, 479, value);
	zephir_check_call_status();
	if (!(zephir_is_true(valid))) {
		ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "CreditCard", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, _0$$3);
		zephir_check_temp_parameter(_0$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&code, this_ptr, "preparecode", NULL, 0, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_0$$3);
		object_init_ex(_0$$3, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "strtr", NULL, 27, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "CreditCard", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 475, _1$$3, field, _2$$3, code);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _0$$3);
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

	HashTable *_6;
	HashPosition _5;
	zval *digits = NULL, *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *number, *_0 = NULL, *digit = NULL, *position = NULL, *hash = NULL, *_3 = NULL, *_4 = NULL, **_7, *result = NULL, *_9 = NULL, *_8$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number);



	ZEPHIR_CALL_FUNCTION(&_0, "str_split", &_1, 74, number);
	zephir_check_call_status();
	zephir_get_arrval(_2, _0);
	ZEPHIR_CPY_WRT(digits, _2);
	ZEPHIR_INIT_VAR(hash);
	ZVAL_STRING(hash, "", 1);
	ZEPHIR_CALL_FUNCTION(&_4, "array_reverse", NULL, 452, digits);
	zephir_check_call_status();
	zephir_is_iterable(_4, &_6, &_5, 0, 0, "phalcon/validation/validator/creditcard.zep", 110);
	for (
	  ; zend_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zend_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HMKEY(position, _6, _5);
		ZEPHIR_GET_HVALUE(digit, _7);
		ZEPHIR_INIT_LNVAR(_8$$3);
		if (zephir_safe_mod_zval_long(position, 2 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_8$$3);
			ZVAL_LONG(_8$$3, (zephir_get_numberval(digit) * 2));
		} else {
			ZEPHIR_CPY_WRT(_8$$3, digit);
		}
		zephir_concat_self(&hash, _8$$3 TSRMLS_CC);
	}
	ZEPHIR_CALL_FUNCTION(&_9, "str_split", &_1, 74, hash);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "array_sum", NULL, 480, _9);
	zephir_check_call_status();
	RETURN_MM_BOOL((zephir_safe_mod_zval_long(result, 10 TSRMLS_CC) == 0));

}

