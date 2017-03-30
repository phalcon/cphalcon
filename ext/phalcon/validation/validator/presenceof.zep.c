
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Phalcon\Validation\Validator\PresenceOf
 *
 * Validates that a value is not null or empty string
 *
 * <code>
 * use Phalcon\Validation\Validator\PresenceOf;
 *
 * $validator->add(
 *     "name",
 *     new PresenceOf(
 *         [
 *             "message" => "The name is required",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "name",
 *         "email",
 *     ],
 *     new PresenceOf(
 *         [
 *             "message" => [
 *                 "name"  => "The name is required",
 *                 "email" => "The email is required",
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_PresenceOf) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, PresenceOf, phalcon, validation_validator_presenceof, phalcon_validation_validator_ce, phalcon_validation_validator_presenceof_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_PresenceOf, validate) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *message = NULL, *label = NULL, *replacePairs = NULL, *code = NULL, *_1$$3 = NULL, *_6$$3 = NULL, *_7$$3, *_2$$4, *_3$$6, *_4$$7, *_5$$8;

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
	_0 = Z_TYPE_P(value) == IS_NULL;
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING_IDENTICAL(value, "");
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(label) == IS_ARRAY) {
			zephir_array_fetch(&_2$$4, label, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/presenceof.zep", 74 TSRMLS_CC);
			ZEPHIR_CPY_WRT(label, _2$$4);
		}
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_ARRAY) {
			zephir_array_fetch(&_3$$6, message, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/presenceof.zep", 82 TSRMLS_CC);
			ZEPHIR_CPY_WRT(message, _3$$6);
		}
		ZEPHIR_INIT_VAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_VAR(_4$$7);
			ZVAL_STRING(_4$$7, "PresenceOf", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _4$$7);
			zephir_check_temp_parameter(_4$$7);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, "code", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&code, this_ptr, "getoption", NULL, 0, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(code) == IS_ARRAY) {
			zephir_array_fetch(&_5$$8, code, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/presenceof.zep", 91 TSRMLS_CC);
			ZEPHIR_CPY_WRT(code, _5$$8);
		}
		ZEPHIR_INIT_NVAR(_1$$3);
		object_init_ex(_1$$3, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_6$$3, "strtr", NULL, 26, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_7$$3);
		ZVAL_STRING(_7$$3, "PresenceOf", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 465, _6$$3, field, _7$$3, code);
		zephir_check_temp_parameter(_7$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _1$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

