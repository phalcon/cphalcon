
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Validation\Validator\ExclusionIn
 *
 * Check if a value is not included into a list of values
 *
 * <code>
 * use Phalcon\Validation\Validator\ExclusionIn;
 *
 * $validator->add(
 *     "status",
 *     new ExclusionIn(
 *         [
 *             "message" => "The status must not be A or B",
 *             "domain"  => [
 *                 "A",
 *                 "B",
 *             ],
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "status",
 *         "type",
 *     ],
 *     new ExclusionIn(
 *         [
 *             "message" => [
 *                 "status" => "The status must not be A or B",
 *                 "type"   => "The type must not be 1 or "'
 *             ],
 *             "domain" => [
 *                 "status" => [
 *                     "A",
 *                     "B",
 *                 ],
 *                 "type"   => [1, 2],
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_ExclusionIn) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, ExclusionIn, phalcon, validation_validator_exclusionin, phalcon_validation_validator_ce, phalcon_validation_validator_exclusionin_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_ExclusionIn, validate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *domain = NULL, *message = NULL, *label = NULL, *replacePairs = NULL, *strict = NULL, *fieldDomain = NULL, *code = NULL, *_0 = NULL, *_1 = NULL, *_4 = NULL, *_2$$6, *_3$$7, *_5$$9 = NULL, *_10$$9 = NULL, *_11$$9, *_6$$10, *_7$$12, *_8$$13, *_9$$14;

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
	ZVAL_STRING(_0, "domain", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&domain, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(fieldDomain);
	if (zephir_array_isset_fetch(&fieldDomain, domain, field, 0 TSRMLS_CC)) {
		if (Z_TYPE_P(fieldDomain) == IS_ARRAY) {
			ZEPHIR_CPY_WRT(domain, fieldDomain);
		}
	}
	if (Z_TYPE_P(domain) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'domain' must be an array", "phalcon/validation/validator/exclusionin.zep", 93);
		return;
	}
	ZEPHIR_INIT_VAR(strict);
	ZVAL_BOOL(strict, 0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "strict", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "hasoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_VAR(_2$$6);
		ZVAL_STRING(_2$$6, "strict", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&strict, this_ptr, "getoption", NULL, 0, _2$$6);
		zephir_check_temp_parameter(_2$$6);
		zephir_check_call_status();
		if (Z_TYPE_P(strict) == IS_ARRAY) {
			zephir_array_fetch(&_3$$7, strict, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/exclusionin.zep", 102 TSRMLS_CC);
			ZEPHIR_CPY_WRT(strict, _3$$7);
		}
		if (Z_TYPE_P(strict) != IS_BOOL) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'strict' must be a boolean", "phalcon/validation/validator/exclusionin.zep", 106);
			return;
		}
	}
	ZEPHIR_CALL_FUNCTION(&_4, "in_array", NULL, 380, value, domain, strict);
	zephir_check_call_status();
	if (zephir_is_true(_4)) {
		ZEPHIR_INIT_VAR(_5$$9);
		ZVAL_STRING(_5$$9, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _5$$9);
		zephir_check_temp_parameter(_5$$9);
		zephir_check_call_status();
		if (Z_TYPE_P(label) == IS_ARRAY) {
			zephir_array_fetch(&_6$$10, label, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/exclusionin.zep", 117 TSRMLS_CC);
			ZEPHIR_CPY_WRT(label, _6$$10);
		}
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_5$$9);
		ZVAL_STRING(_5$$9, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _5$$9);
		zephir_check_temp_parameter(_5$$9);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_ARRAY) {
			zephir_array_fetch(&_7$$12, message, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/exclusionin.zep", 125 TSRMLS_CC);
			ZEPHIR_CPY_WRT(message, _7$$12);
		}
		ZEPHIR_INIT_VAR(replacePairs);
		zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_5$$9);
		zephir_fast_join_str(_5$$9, SL(", "), domain TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":domain"), &_5$$9, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_VAR(_8$$13);
			ZVAL_STRING(_8$$13, "ExclusionIn", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _8$$13);
			zephir_check_temp_parameter(_8$$13);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_5$$9);
		ZVAL_STRING(_5$$9, "code", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&code, this_ptr, "getoption", NULL, 0, _5$$9);
		zephir_check_temp_parameter(_5$$9);
		zephir_check_call_status();
		if (Z_TYPE_P(code) == IS_ARRAY) {
			zephir_array_fetch(&_9$$14, code, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/exclusionin.zep", 134 TSRMLS_CC);
			ZEPHIR_CPY_WRT(code, _9$$14);
		}
		ZEPHIR_INIT_NVAR(_5$$9);
		object_init_ex(_5$$9, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_10$$9, "strtr", NULL, 26, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_11$$9);
		ZVAL_STRING(_11$$9, "ExclusionIn", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _5$$9, "__construct", NULL, 465, _10$$9, field, _11$$9, code);
		zephir_check_temp_parameter(_11$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _5$$9);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

