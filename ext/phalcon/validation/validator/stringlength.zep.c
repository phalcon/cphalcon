
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Validation\Validator\StringLength
 *
 * Validates that a string has the specified maximum and minimum constraints
 * The test is passed if for a string's length L, min<=L<=max, i.e. L must
 * be at least min, and at most max.
 *
 * <code>
 * use Phalcon\Validation\Validator\StringLength as StringLength;
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
	zephir_fcall_cache_entry *_10 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, isSetMin, isSetMax, value, length, message, minimum, maximum, label, replacePairs, code, _0, _2$$4, _3$$6, _4$$9, _5$$10, _6$$11, _9$$11, _11$$11, _7$$12, _8$$13, _13$$14, _14$$15, _15$$16, _18$$16, _19$$16, _16$$17, _17$$18;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&validation_sub);
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
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_7$$12);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&_17$$18);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "A minimum or maximum must be set", "phalcon/validation/validator/stringlength.zep", 92);
		return;
	}
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, &field);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "label");
	ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&label) == IS_ARRAY) {
		zephir_array_fetch(&_2$$4, &label, &field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/stringlength.zep", 98 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&label, &_2$$4);
	}
	if (ZEPHIR_IS_EMPTY(&label)) {
		ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "code");
	ZEPHIR_CALL_METHOD(&code, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&code) == IS_ARRAY) {
		zephir_array_fetch(&_3$$6, &code, &field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/stringlength.zep", 106 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&code, &_3$$6);
	}
	if ((zephir_function_exists_ex(SL("mb_strlen") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&length, "mb_strlen", NULL, 380, &value);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&length);
		ZVAL_LONG(&length, zephir_fast_strlen_ev(&value));
	}
	if (zephir_is_true(&isSetMax)) {
		ZEPHIR_INIT_VAR(&_4$$9);
		ZVAL_STRING(&_4$$9, "max");
		ZEPHIR_CALL_METHOD(&maximum, this_ptr, "getoption", NULL, 0, &_4$$9);
		zephir_check_call_status();
		if (Z_TYPE_P(&maximum) == IS_ARRAY) {
			zephir_array_fetch(&_5$$10, &maximum, &field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/stringlength.zep", 123 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&maximum, &_5$$10);
		}
		if (ZEPHIR_GT(&length, &maximum)) {
			ZEPHIR_INIT_VAR(&_6$$11);
			ZVAL_STRING(&_6$$11, "messageMaximum");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_6$$11);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&replacePairs);
			zephir_create_array(&replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":max"), &maximum, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(&message) == IS_ARRAY) {
				zephir_array_fetch(&_7$$12, &message, &field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/stringlength.zep", 132 TSRMLS_CC);
				ZEPHIR_CPY_WRT(&message, &_7$$12);
			}
			if (ZEPHIR_IS_EMPTY(&message)) {
				ZEPHIR_INIT_VAR(&_8$$13);
				ZVAL_STRING(&_8$$13, "TooLong");
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_8$$13);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(&_6$$11);
			object_init_ex(&_6$$11, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_9$$11, "strtr", &_10, 26, &message, &replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_11$$11);
			ZVAL_STRING(&_11$$11, "TooLong");
			ZEPHIR_CALL_METHOD(NULL, &_6$$11, "__construct", &_12, 464, &_9$$11, &field, &_11$$11, &code);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_6$$11);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	if (zephir_is_true(&isSetMin)) {
		ZEPHIR_INIT_VAR(&_13$$14);
		ZVAL_STRING(&_13$$14, "min");
		ZEPHIR_CALL_METHOD(&minimum, this_ptr, "getoption", NULL, 0, &_13$$14);
		zephir_check_call_status();
		if (Z_TYPE_P(&minimum) == IS_ARRAY) {
			zephir_array_fetch(&_14$$15, &minimum, &field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/stringlength.zep", 159 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&minimum, &_14$$15);
		}
		if (ZEPHIR_LT(&length, &minimum)) {
			ZEPHIR_INIT_VAR(&_15$$16);
			ZVAL_STRING(&_15$$16, "messageMinimum");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_15$$16);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&replacePairs);
			zephir_create_array(&replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":min"), &minimum, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(&message) == IS_ARRAY) {
				zephir_array_fetch(&_16$$17, &message, &field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/stringlength.zep", 168 TSRMLS_CC);
				ZEPHIR_CPY_WRT(&message, &_16$$17);
			}
			if (ZEPHIR_IS_EMPTY(&message)) {
				ZEPHIR_INIT_VAR(&_17$$18);
				ZVAL_STRING(&_17$$18, "TooShort");
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_17$$18);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(&_15$$16);
			object_init_ex(&_15$$16, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_18$$16, "strtr", &_10, 26, &message, &replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_19$$16);
			ZVAL_STRING(&_19$$16, "TooShort");
			ZEPHIR_CALL_METHOD(NULL, &_15$$16, "__construct", &_12, 464, &_18$$16, &field, &_19$$16, &code);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_15$$16);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

