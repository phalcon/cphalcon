
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
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/string.h"
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
 * Phalcon\Validation\Validator\StringLength
 *
 * Validates that a string has the specified maximum and minimum constraints
 * The test is passed if for a string's length L, min<=L<=max, i.e. L must
 * be at least min, and at most max.
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\StringLength as StringLength;
 *
 * $validator = new Validation();
 *
 * $validation->add(
 *     "name_last",
 *     new StringLength(
 *         [
 *             "max"            => 50,
 *             "min"            => 2,
 *             "messageMaximum" => "We don't like really long names",
 *             "messageMinimum" => "We want more than just their initials",
 *         ]
 *     )
 * );
 *
 * $validation->add(
 *     [
 *         "name_last",
 *         "name_first",
 *     ],
 *     new StringLength(
 *         [
 *             "max" => [
 *                 "name_last"  => 50,
 *                 "name_first" => 40,
 *             ],
 *             "min" => [
 *                 "name_last"  => 2,
 *                 "name_first" => 4,
 *             ],
 *             "messageMaximum" => [
 *                 "name_last"  => "We don't like really long last names",
 *                 "name_first" => "We don't like really long first names",
 *             ],
 *             "messageMinimum" => [
 *                 "name_last"  => "We don't like too short last names",
 *                 "name_first" => "We don't like too short first names",
 *             ]
 *         ]
 *     )
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_StringLength) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, StringLength, phalcon, validation_validator_stringlength, phalcon_validation_validator_ce, phalcon_validation_validator_stringlength_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_StringLength, validate) {

	zend_bool _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, isSetMin, isSetMax, value, length, message, minimum, maximum, label, replacePairs, code, _0, _2$$6, _3$$7, _4$$8, _5$$8, _6$$8, _7$$9, _8$$10, _9$$11, _10$$11, _11$$11, _12$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&isSetMin);
	ZVAL_UNDEF(&isSetMax);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&minimum);
	ZVAL_UNDEF(&maximum);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "min");
	ZEPHIR_CALL_METHOD(&isSetMin, this_ptr, "hasoption", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "max");
	ZEPHIR_CALL_METHOD(&isSetMax, this_ptr, "hasoption", NULL, 0, &_0);
	zephir_check_call_status();
	_1 = !zephir_is_true(&isSetMin);
	if (_1) {
		_1 = !zephir_is_true(&isSetMax);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "A minimum or maximum must be set", "phalcon/validation/validator/stringlength.zep", 86);
		return;
	}
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&code, this_ptr, "preparecode", NULL, 0, field);
	zephir_check_call_status();
	if ((zephir_function_exists_ex(SL("mb_strlen") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&length, "mb_strlen", NULL, 213, &value);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&length);
		ZVAL_LONG(&length, zephir_fast_strlen_ev(&value));
	}
	if (zephir_is_true(&isSetMax)) {
		ZEPHIR_INIT_VAR(&_2$$6);
		ZVAL_STRING(&_2$$6, "max");
		ZEPHIR_CALL_METHOD(&maximum, this_ptr, "getoption", NULL, 0, &_2$$6);
		zephir_check_call_status();
		if (Z_TYPE_P(&maximum) == IS_ARRAY) {
			zephir_array_fetch(&_3$$7, &maximum, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/stringlength.zep", 107 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&maximum, &_3$$7);
		}
		if (ZEPHIR_GT(&length, &maximum)) {
			ZEPHIR_INIT_VAR(&_4$$8);
			ZVAL_STRING(&_4$$8, "TooLong");
			ZEPHIR_INIT_VAR(&_5$$8);
			ZVAL_STRING(&_5$$8, "messageMaximum");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, &_4$$8, &_5$$8);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&replacePairs);
			zephir_create_array(&replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":max"), &maximum, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_4$$8);
			object_init_ex(&_4$$8, phalcon_messages_message_ce);
			ZEPHIR_CALL_FUNCTION(&_6$$8, "strtr", NULL, 48, &message, &replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_5$$8);
			ZVAL_STRING(&_5$$8, "TooLong");
			ZEPHIR_CALL_METHOD(NULL, &_4$$8, "__construct", NULL, 300, &_6$$8, field, &_5$$8, &code);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_4$$8);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	if (zephir_is_true(&isSetMin)) {
		ZEPHIR_INIT_VAR(&_7$$9);
		ZVAL_STRING(&_7$$9, "min");
		ZEPHIR_CALL_METHOD(&minimum, this_ptr, "getoption", NULL, 0, &_7$$9);
		zephir_check_call_status();
		if (Z_TYPE_P(&minimum) == IS_ARRAY) {
			zephir_array_fetch(&_8$$10, &minimum, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/stringlength.zep", 133 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&minimum, &_8$$10);
		}
		if (ZEPHIR_LT(&length, &minimum)) {
			ZEPHIR_INIT_VAR(&_9$$11);
			ZVAL_STRING(&_9$$11, "TooShort");
			ZEPHIR_INIT_VAR(&_10$$11);
			ZVAL_STRING(&_10$$11, "messageMinimum");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, &_9$$11, &_10$$11);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_11$$11);
			zephir_create_array(&_11$$11, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&_11$$11, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_11$$11, SL(":min"), &minimum, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&replacePairs, &_11$$11);
			ZEPHIR_INIT_NVAR(&_9$$11);
			object_init_ex(&_9$$11, phalcon_messages_message_ce);
			ZEPHIR_CALL_FUNCTION(&_12$$11, "strtr", NULL, 48, &message, &replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_10$$11);
			ZVAL_STRING(&_10$$11, "TooShort");
			ZEPHIR_CALL_METHOD(NULL, &_9$$11, "__construct", NULL, 300, &_12$$11, field, &_10$$11, &code);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_9$$11);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

