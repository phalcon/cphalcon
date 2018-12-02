
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *message = NULL, *label = NULL, *replacePairs = NULL, *code = NULL, _0, *_1 = NULL, *_2$$3 = NULL, *_3$$3 = NULL, *_4$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}


	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 274);
	ZEPHIR_CALL_FUNCTION(&_1, "filter_var", NULL, 212, value, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "Email", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&code, this_ptr, "preparecode", NULL, 0, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_2$$3);
		object_init_ex(_2$$3, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "strtr", NULL, 27, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_STRING(_4$$3, "Email", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 478, _3$$3, field, _4$$3, code);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _2$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

