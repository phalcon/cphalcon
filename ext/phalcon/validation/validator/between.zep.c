
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
 * Phalcon\Validation\Validator\Between
 *
 * Validates that a value is between an inclusive range of two values.
 * For a value x, the test is passed if minimum<=x<=maximum.
 *
 *<code>
 *use Phalcon\Validation\Validator\Between;
 *
 *validator->add('name', new Between(array(
 *   'minimum' => 0,
 *   'maximum' => 100,
 *   'message' => 'The price must be between 0 and 100'
 *)));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Between) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Between, phalcon, validation_validator_between, phalcon_validation_validator_ce, phalcon_validation_validator_between_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Between, validate) {

	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *minimum = NULL, *maximum = NULL, *message = NULL, *label = NULL, *replacePairs = NULL, *_0 = NULL, *_2$$3 = NULL, *_4$$3 = NULL, *_5$$3 = NULL, *_6$$3 = NULL, *_3$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}


	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "minimum", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&minimum, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "maximum", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&maximum, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_1 = ZEPHIR_LT(value, minimum);
	if (!(_1)) {
		_1 = ZEPHIR_GT(value, maximum);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_2$$3);
		ZVAL_STRING(_2$$3, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		zephir_create_array(replacePairs, 3, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replacePairs, SL(":min"), &minimum, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replacePairs, SL(":max"), &maximum, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_VAR(_3$$5);
			ZVAL_STRING(_3$$5, "Between", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _3$$5);
			zephir_check_temp_parameter(_3$$5);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_2$$3);
		object_init_ex(_2$$3, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "strtr", NULL, 55, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6$$3);
		ZVAL_STRING(_6$$3, "code", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "getoption", NULL, 0, _6$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6$$3);
		ZVAL_STRING(_6$$3, "Between", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 455, _4$$3, field, _6$$3, _5$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _2$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

