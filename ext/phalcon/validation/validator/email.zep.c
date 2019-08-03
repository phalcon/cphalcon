
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
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Checks if a value has a correct e-mail format
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Email as EmailValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "email",
 *     new EmailValidator(
 *         [
 *             "message" => "The e-mail is not valid",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "email",
 *         "anotherEmail",
 *     ],
 *     new EmailValidator(
 *         [
 *             "message" => [
 *                 "email"        => "The e-mail is not valid",
 *                 "anotherEmail" => "The another e-mail is not valid",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Email) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Email, phalcon, validation_validator_email, phalcon_validation_abstractvalidator_ce, phalcon_validation_validator_email_method_entry, 0);

	zend_declare_property_string(phalcon_validation_validator_email_ce, SL("template"), "Field :field must be an email address", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Email, validate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, value, _0, _1, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 274);
	ZEPHIR_CALL_FUNCTION(&_1, "filter_var", NULL, 234, &value, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "messagefactory", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_2$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

