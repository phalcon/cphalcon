
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Phalcon\Validation\Validator\Regex
 *
 * Allows validate if the value of a field matches a regular expression
 *
 * <code>
 * use Phalcon\Validation\Validator\Regex as RegexValidator;
 *
 * $validator->add('created_at', new RegexValidator([
 *     'pattern' => '/^[0-9]{4}[-\/](0[1-9]|1[12])[-\/](0[1-9]|[12][0-9]|3[01])$/',
 *     'message' => 'The creation date is invalid'
 * ]));
 *
 * $validator->add(['created_at', 'name'], new RegexValidator([
 *     'pattern' => [
 *         'created_at' => '/^[0-9]{4}[-\/](0[1-9]|1[12])[-\/](0[1-9]|[12][0-9]|3[01])$/',
 *         'name' => '/^[a-z]$/'
 *     ],
 *     'message' => [
 *         'created_at' => 'The creation date is invalid',
 *         'name' => ' 'The name is invalid'
 *     ]
 * ]));
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
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *matches = NULL, *message = NULL, *value = NULL, *label = NULL, *replacePairs = NULL, *code = NULL, *pattern = NULL, *_0 = NULL, *_1$$3, *_2$$4, *_3$$6 = NULL, *_8$$6 = NULL, *_9$$6, *_4$$7, *_5$$9, *_6$$10, *_7$$11;

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


	ZEPHIR_INIT_VAR(matches);
	ZVAL_NULL(matches);
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "pattern", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&pattern, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(pattern) == IS_ARRAY) {
		zephir_array_fetch(&_1$$3, pattern, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/regex.zep", 68 TSRMLS_CC);
		ZEPHIR_CPY_WRT(pattern, _1$$3);
	}
	ZEPHIR_INIT_NVAR(_0);
	zephir_preg_match(_0, pattern, value, matches, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_0)) {
		zephir_array_fetch_long(&_2$$4, matches, 0, PH_NOISY | PH_READONLY, "phalcon/validation/validator/regex.zep", 72 TSRMLS_CC);
		failed = !ZEPHIR_IS_EQUAL(_2$$4, value);
	} else {
		failed = 1;
	}
	if (failed == 1) {
		ZEPHIR_INIT_VAR(_3$$6);
		ZVAL_STRING(_3$$6, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _3$$6);
		zephir_check_temp_parameter(_3$$6);
		zephir_check_call_status();
		if (Z_TYPE_P(label) == IS_ARRAY) {
			zephir_array_fetch(&_4$$7, label, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/regex.zep", 81 TSRMLS_CC);
			ZEPHIR_CPY_WRT(label, _4$$7);
		}
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_3$$6);
		ZVAL_STRING(_3$$6, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _3$$6);
		zephir_check_temp_parameter(_3$$6);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_ARRAY) {
			zephir_array_fetch(&_5$$9, message, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/regex.zep", 89 TSRMLS_CC);
			ZEPHIR_CPY_WRT(message, _5$$9);
		}
		ZEPHIR_INIT_VAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_VAR(_6$$10);
			ZVAL_STRING(_6$$10, "Regex", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _6$$10);
			zephir_check_temp_parameter(_6$$10);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_3$$6);
		ZVAL_STRING(_3$$6, "code", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&code, this_ptr, "getoption", NULL, 0, _3$$6);
		zephir_check_temp_parameter(_3$$6);
		zephir_check_call_status();
		if (Z_TYPE_P(code) == IS_ARRAY) {
			zephir_array_fetch(&_7$$11, code, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/regex.zep", 98 TSRMLS_CC);
			ZEPHIR_CPY_WRT(code, _7$$11);
		}
		ZEPHIR_INIT_NVAR(_3$$6);
		object_init_ex(_3$$6, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_8$$6, "strtr", NULL, 26, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_9$$6);
		ZVAL_STRING(_9$$6, "Regex", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _3$$6, "__construct", NULL, 462, _8$$6, field, _9$$6, code);
		zephir_check_temp_parameter(_9$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _3$$6);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

