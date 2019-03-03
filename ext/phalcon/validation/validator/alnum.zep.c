
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
 * Phalcon\Validation\Validator\Alnum
 *
 * Check for alphanumeric character(s)
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Alnum as AlnumValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "username",
 *     new AlnumValidator(
 *         [
 *             "message" => ":field must contain only alphanumeric characters",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "username",
 *         "name",
 *     ],
 *     new AlnumValidator(
 *         [
 *             "message" => [
 *                 "username" => "username must contain only alphanumeric characters",
 *                 "name"     => "name must contain only alphanumeric characters",
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Alnum) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Alnum, phalcon, validation_validator_alnum, phalcon_validation_validator_ce, phalcon_validation_validator_alnum_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Alnum, validate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, value, message, label, replacePairs, code, _0, _1$$3, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "ctype_alnum", NULL, 449, &value);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Alnum");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&code, this_ptr, "preparecode", NULL, 0, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_messages_message_ce);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "strtr", NULL, 48, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Alnum");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 300, &_2$$3, field, &_3$$3, &code);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_1$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

