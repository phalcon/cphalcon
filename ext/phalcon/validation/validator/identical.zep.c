
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Phalcon\Validation\Validator\Identical
 *
 * Checks if a value is identical to other
 *
 *<code>
 *use Phalcon\Validation\Validator\Identical;
 *
 *$validator->add('terms', new Identical(array(
 *   'accepted' => 'yes',
 *   'message' => 'Terms and conditions must be accepted'
 *)));
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Identical) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Identical, phalcon, validation_validator_identical, phalcon_validation_validator_ce, phalcon_validation_validator_identical_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Identical, validate) {

	zend_bool valid = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, message, label, replacePairs, value, _0, _1, _2$$3, _3$$3, _4$$4, _5$$4, _6$$5, _7$$5, _8$$6, _10$$6, _11$$6, _12$$6, _9$$8;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_9$$8);
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
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "accepted");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasoption", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "accepted");
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getoption", NULL, 0, &_3$$3);
		zephir_check_call_status();
		valid = ZEPHIR_IS_EQUAL(&value, &_2$$3);
	} else {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "value");
		ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "hasoption", NULL, 0, &_5$$4);
		zephir_check_call_status();
		if (zephir_is_true(&_4$$4)) {
			ZEPHIR_INIT_VAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "value");
			ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "getoption", NULL, 0, &_7$$5);
			zephir_check_call_status();
			valid = ZEPHIR_IS_EQUAL(&value, &_6$$5);
		}
	}
	if (!(valid)) {
		ZEPHIR_INIT_VAR(&_8$$6);
		ZVAL_STRING(&_8$$6, "label");
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, &_8$$6);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(&label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_8$$6);
		ZVAL_STRING(&_8$$6, "message");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_8$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(&message)) {
			ZEPHIR_INIT_VAR(&_9$$8);
			ZVAL_STRING(&_9$$8, "Identical");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_9$$8);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_8$$6);
		object_init_ex(&_8$$6, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_10$$6, "strtr", NULL, 55, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_12$$6);
		ZVAL_STRING(&_12$$6, "code");
		ZEPHIR_CALL_METHOD(&_11$$6, this_ptr, "getoption", NULL, 0, &_12$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_12$$6);
		ZVAL_STRING(&_12$$6, "Identical");
		ZEPHIR_CALL_METHOD(NULL, &_8$$6, "__construct", NULL, 461, &_10$$6, &field, &_12$$6, &_11$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_8$$6);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

