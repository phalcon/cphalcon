
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
 * Phalcon\Validation\Validator\Email
 *
 * Checks if a value has a correct e-mail format
 *
 * <code>
 * use Phalcon\Validation\Validator\Email as EmailValidator;
 *
 * $validator->add('email', new EmailValidator([
 *     'message' => 'The e-mail is not valid'
 * ]));
 *
 * $validator->add(['email', 'anotherEmail'], new EmailValidator([
 *     'message' => [
 *         'email' => 'The e-mail is not valid',
 *         'anotherEmail' => 'The another e-mail is not valid'
 *     ]
 * ]));
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Email) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Email, phalcon, validation_validator_email, phalcon_validation_validator_ce, phalcon_validation_validator_email_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Email, validate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *message = NULL, *label = NULL, *replacePairs = NULL, *code = NULL, _0, *_1 = NULL, *_2$$3 = NULL, *_7$$3 = NULL, *_8$$3, *_3$$4, *_4$$6, *_5$$7, *_6$$8;

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
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 274);
	ZEPHIR_CALL_FUNCTION(&_1, "filter_var", NULL, 197, value, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(label) == IS_ARRAY) {
			zephir_array_fetch(&_3$$4, label, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/email.zep", 62 TSRMLS_CC);
			ZEPHIR_CPY_WRT(label, _3$$4);
		}
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_2$$3);
		ZVAL_STRING(_2$$3, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_ARRAY) {
			zephir_array_fetch(&_4$$6, message, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/email.zep", 70 TSRMLS_CC);
			ZEPHIR_CPY_WRT(message, _4$$6);
		}
		ZEPHIR_INIT_VAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_VAR(_5$$7);
			ZVAL_STRING(_5$$7, "Email", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _5$$7);
			zephir_check_temp_parameter(_5$$7);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_2$$3);
		ZVAL_STRING(_2$$3, "code", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&code, this_ptr, "getoption", NULL, 0, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(code) == IS_ARRAY) {
			zephir_array_fetch(&_6$$8, code, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/email.zep", 79 TSRMLS_CC);
			ZEPHIR_CPY_WRT(code, _6$$8);
		}
		ZEPHIR_INIT_NVAR(_2$$3);
		object_init_ex(_2$$3, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "strtr", NULL, 26, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_8$$3);
		ZVAL_STRING(_8$$3, "Email", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 462, _7$$3, field, _8$$3, code);
		zephir_check_temp_parameter(_8$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _2$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

