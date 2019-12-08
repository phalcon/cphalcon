
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Checks that two values have the same value
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Confirmation;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "password",
 *     new Confirmation(
 *         [
 *             "message" => "Password doesn't match confirmation",
 *             "with"    => "confirmPassword",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "password",
 *         "email",
 *     ],
 *     new Confirmation(
 *         [
 *             "message" => [
 *                 "password" => "Password doesn't match confirmation",
 *                 "email"    => "Email doesn't match confirmation",
 *             ],
 *             "with" => [
 *                 "password" => "confirmPassword",
 *                 "email"    => "confirmEmail",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Confirmation) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Confirmation, phalcon, validation_validator_confirmation, phalcon_validation_abstractvalidator_ce, phalcon_validation_validator_confirmation_method_entry, 0);

	zend_declare_property_string(phalcon_validation_validator_confirmation_ce, SL("template"), "Field :field must be the same as :with", ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Confirmation, validate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, fieldWith, value, valueWith, labelWith, replacePairs, _0, _2, _1$$3, _3$$4, _5$$4, _4$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&fieldWith);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&valueWith);
	ZVAL_UNDEF(&labelWith);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "with");
	ZEPHIR_CALL_METHOD(&fieldWith, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&fieldWith) == IS_ARRAY) {
		zephir_array_fetch(&_1$$3, &fieldWith, field, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/Confirmation.zep", 71);
		ZEPHIR_CPY_WRT(&fieldWith, &_1$$3);
	}
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&valueWith, validation, "getvalue", NULL, 0, &fieldWith);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "compare", NULL, 0, &value, &valueWith);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "labelWith");
		ZEPHIR_CALL_METHOD(&labelWith, this_ptr, "getoption", NULL, 0, &_3$$4);
		zephir_check_call_status();
		if (Z_TYPE_P(&labelWith) == IS_ARRAY) {
			zephir_array_fetch(&_4$$5, &labelWith, &fieldWith, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/Confirmation.zep", 81);
			ZEPHIR_CPY_WRT(&labelWith, &_4$$5);
		}
		if (ZEPHIR_IS_EMPTY(&labelWith)) {
			ZEPHIR_CALL_METHOD(&labelWith, validation, "getlabel", NULL, 0, &fieldWith);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		zephir_array_update_string(&replacePairs, SL(":with"), &labelWith, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "messagefactory", NULL, 0, validation, field, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_5$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Compare strings
 */
PHP_METHOD(Phalcon_Validation_Validator_Confirmation, compare) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *a_param = NULL, *b_param = NULL, _0, _1, _2, _3$$3, _4$$3, _5$$3;
	zval a, b;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&b);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &a_param, &b_param);

	zephir_get_strval(&a, a_param);
	zephir_get_strval(&b, b_param);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "ignoreCase");
	ZVAL_BOOL(&_2, 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		if (UNEXPECTED(!((zephir_function_exists_ex(ZEND_STRL("mb_strtolower")) == SUCCESS)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Extension 'mbstring' is required", "phalcon/Validation/Validator/Confirmation.zep", 112);
			return;
		}
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "mb_strtolower", NULL, 23, &a, &_3$$3);
		zephir_check_call_status();
		zephir_get_strval(&a, &_4$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "utf-8");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "mb_strtolower", NULL, 23, &b, &_3$$3);
		zephir_check_call_status();
		zephir_get_strval(&b, &_5$$3);
	}
	RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(&a, &b));

}

