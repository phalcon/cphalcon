
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Phalcon\Validation\Validator\Numericality
 *
 * Check for a valid numeric value
 *
 *<code>
 *use Phalcon\Validation\Validator\Numericality;
 *
 *$validator->add('price', new Numericality(array(
 *   'message' => ':field is not numeric'
 *)));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Numericality) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Numericality, phalcon, validation_validator_numericality, phalcon_validation_validator_ce, phalcon_validation_validator_numericality_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Numericality, validate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, value, message, label, replacePairs, _0, _1, _2, _3$$3, _5$$3, _6$$3, _7$$3, _4$$5;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_4$$5);
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
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/^-?\\d+\\.?\\d*$/");
	zephir_preg_match(&_1, &_2, &value, &_0, 0, 0 , 0  TSRMLS_CC);
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "label");
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, &_3$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(&label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "message");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(&message)) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "Numericality");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_4$$5);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "strtr", NULL, 55, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "code");
		ZEPHIR_CALL_METHOD(&_6$$3, this_ptr, "getoption", NULL, 0, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "Numericality");
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 461, &_5$$3, &field, &_7$$3, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_3$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

