
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
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Validation\Validator\InclusionIn
 *
 * Check if a value is included into a list of values
 *
 *<code>
 *use Phalcon\Validation\Validator\InclusionIn;
 *
 *$validator->add('status', new InclusionIn(array(
 *   'message' => 'The status must be A or B',
 *   'domain' => array('A', 'B')
 *)));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_InclusionIn) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, InclusionIn, phalcon, validation_validator_inclusionin, phalcon_validation_validator_ce, phalcon_validation_validator_inclusionin_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_InclusionIn, validate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *domain = NULL, *message = NULL, *label = NULL, *replacePairs = NULL, *strict = NULL, *_0 = NULL, *_1 = NULL, *_3 = NULL, *_2$$4, *_4$$6 = NULL, *_6$$6 = NULL, *_7$$6 = NULL, *_8$$6 = NULL, *_5$$8;

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
	if (Z_TYPE_P(domain) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'domain' must be an array", "phalcon/validation/validator/inclusionin.zep", 58);
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
		if (Z_TYPE_P(strict) != IS_BOOL) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'strict' must be a boolean", "phalcon/validation/validator/inclusionin.zep", 64);
			return;
		}
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_STRING(_2$$4, "strict", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&strict, this_ptr, "getoption", NULL, 0, _2$$4);
		zephir_check_temp_parameter(_2$$4);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&_3, "in_array", NULL, 359, value, domain, strict);
	zephir_check_call_status();
	if (!(zephir_is_true(_3))) {
		ZEPHIR_INIT_VAR(_4$$6);
		ZVAL_STRING(_4$$6, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _4$$6);
		zephir_check_temp_parameter(_4$$6);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_4$$6);
		ZVAL_STRING(_4$$6, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _4$$6);
		zephir_check_temp_parameter(_4$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4$$6);
		zephir_fast_join_str(_4$$6, SL(", "), domain TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":domain"), &_4$$6, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_VAR(_5$$8);
			ZVAL_STRING(_5$$8, "InclusionIn", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _5$$8);
			zephir_check_temp_parameter(_5$$8);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_4$$6);
		object_init_ex(_4$$6, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_6$$6, "strtr", NULL, 54, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_8$$6);
		ZVAL_STRING(_8$$6, "code", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_7$$6, this_ptr, "getoption", NULL, 0, _8$$6);
		zephir_check_temp_parameter(_8$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_8$$6);
		ZVAL_STRING(_8$$6, "InclusionIn", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _4$$6, "__construct", NULL, 440, _6$$6, field, _8$$6, _7$$6);
		zephir_check_temp_parameter(_8$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _4$$6);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

