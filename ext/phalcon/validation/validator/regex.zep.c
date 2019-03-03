
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Validation\Validator\Regex
 *
 * Allows validate if the value of a field matches a regular expression
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Regex as RegexValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "created_at",
 *     new RegexValidator(
 *         [
 *             "pattern" => "/^[0-9]{4}[-\/](0[1-9]|1[12])[-\/](0[1-9]|[12][0-9]|3[01])$/",
 *             "message" => "The creation date is invalid",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "created_at",
 *         "name",
 *     ],
 *     new RegexValidator(
 *         [
 *             "pattern" => [
 *                 "created_at" => "/^[0-9]{4}[-\/](0[1-9]|1[12])[-\/](0[1-9]|[12][0-9]|3[01])$/",
 *                 "name"       => "/^[a-z]$/",
 *             ],
 *             "message" => [
 *                 "created_at" => "The creation date is invalid",
 *                 "name"       => "The name is invalid",
 *             ]
 *         ]
 *     )
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Regex) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Regex, phalcon, validation_validator_regex, phalcon_validation_validator_ce, phalcon_validation_validator_regex_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Regex, validate) {

	zend_bool failed = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, matches, message, value, label, replacePairs, code, pattern, _0, _1$$3, _2$$4, _3$$6, _4$$6, _5$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_INIT_VAR(&matches);
	ZVAL_NULL(&matches);
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "pattern");
	ZEPHIR_CALL_METHOD(&pattern, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&pattern) == IS_ARRAY) {
		zephir_array_fetch(&_1$$3, &pattern, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/regex.zep", 75 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&pattern, &_1$$3);
	}
	ZEPHIR_INIT_NVAR(&_0);
	zephir_preg_match(&_0, &pattern, &value, &matches, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(&_0)) {
		zephir_array_fetch_long(&_2$$4, &matches, 0, PH_NOISY | PH_READONLY, "phalcon/validation/validator/regex.zep", 79 TSRMLS_CC);
		failed = !ZEPHIR_IS_EQUAL(&_2$$4, &value);
	} else {
		failed = 1;
	}
	if (failed == 1) {
		ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$6);
		ZVAL_STRING(&_3$$6, "Regex");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, &_3$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&code, this_ptr, "preparecode", NULL, 0, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_3$$6);
		object_init_ex(&_3$$6, phalcon_messages_message_ce);
		ZEPHIR_CALL_FUNCTION(&_4$$6, "strtr", NULL, 48, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$6);
		ZVAL_STRING(&_5$$6, "Regex");
		ZEPHIR_CALL_METHOD(NULL, &_3$$6, "__construct", NULL, 300, &_4$$6, field, &_5$$6, &code);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_3$$6);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

