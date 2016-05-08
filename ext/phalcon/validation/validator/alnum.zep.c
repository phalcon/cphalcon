
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
 * Phalcon\Validation\Validator\Alnum
 *
 * Check for alphanumeric character(s)
 *
 *<code>
 *use Phalcon\Validation\Validator\Alnum as AlnumValidator;
 *
 *$validator->add('username', new AlnumValidator(array(
 *   'message' => ':field must contain only alphanumeric characters'
 *)));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Alnum) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Alnum, phalcon, validation_validator_alnum, phalcon_validation_validator_ce, phalcon_validation_validator_alnum_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Alnum, validate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *message = NULL, *label = NULL, *replacePairs = NULL, *_0 = NULL, *_1$$3 = NULL, *_3$$3 = NULL, *_4$$3 = NULL, *_5$$3 = NULL, *_2$$5;

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
	ZEPHIR_CALL_FUNCTION(&_0, "ctype_alnum", NULL, 456, value);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_VAR(_2$$5);
			ZVAL_STRING(_2$$5, "Alnum", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _2$$5);
			zephir_check_temp_parameter(_2$$5);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_1$$3);
		object_init_ex(_1$$3, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "strtr", NULL, 55, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_5$$3);
		ZVAL_STRING(_5$$3, "code", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "getoption", NULL, 0, _5$$3);
		zephir_check_temp_parameter(_5$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_5$$3);
		ZVAL_STRING(_5$$3, "Alnum", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 455, _3$$3, field, _5$$3, _4$$3);
		zephir_check_temp_parameter(_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _1$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

