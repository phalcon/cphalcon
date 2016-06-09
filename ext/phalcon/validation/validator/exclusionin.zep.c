
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
 * Phalcon\Validation\Validator\ExclusionIn
 *
 * Check if a value is not included into a list of values
 *
 *<code>
 *use Phalcon\Validation\Validator\ExclusionIn;
 *
 *$validator->add('status', new ExclusionIn(array(
 *   'message' => 'The status must not be A or B',
 *   'domain' => array('A', 'B')
 *)));
 *</code>
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
	zval field;
	zval *validation, validation_sub, *field_param = NULL, value, domain, message, label, replacePairs, strict, _0, _1, _3, _2$$4, _4$$6, _6$$6, _7$$6, _8$$6, _5$$8;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&strict);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_5$$8);
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
	ZVAL_STRING(&_0, "domain");
	ZEPHIR_CALL_METHOD(&domain, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&domain) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'domain' must be an array", "phalcon/validation/validator/exclusionin.zep", 58);
		return;
	}
	ZEPHIR_INIT_VAR(&strict);
	ZVAL_BOOL(&strict, 0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "strict");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "hasoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		if (((Z_TYPE_P(&strict) == IS_TRUE || Z_TYPE_P(&strict) == IS_FALSE) != 1)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'strict' must be a boolean", "phalcon/validation/validator/exclusionin.zep", 65);
			return;
		}
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "strict");
		ZEPHIR_CALL_METHOD(&strict, this_ptr, "getoption", NULL, 0, &_2$$4);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&_3, "in_array", NULL, 378, &value, &domain, &strict);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZEPHIR_INIT_VAR(&_4$$6);
		ZVAL_STRING(&_4$$6, "label");
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, &_4$$6);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(&label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_4$$6);
		ZVAL_STRING(&_4$$6, "message");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_4$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_4$$6);
		zephir_fast_join_str(&_4$$6, SL(", "), &domain TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":domain"), &_4$$6, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(&message)) {
			ZEPHIR_INIT_VAR(&_5$$8);
			ZVAL_STRING(&_5$$8, "ExclusionIn");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_5$$8);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_4$$6);
		object_init_ex(&_4$$6, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_6$$6, "strtr", NULL, 55, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$6);
		ZVAL_STRING(&_8$$6, "code");
		ZEPHIR_CALL_METHOD(&_7$$6, this_ptr, "getoption", NULL, 0, &_8$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_8$$6);
		ZVAL_STRING(&_8$$6, "ExclusionIn");
		ZEPHIR_CALL_METHOD(NULL, &_4$$6, "__construct", NULL, 461, &_6$$6, &field, &_8$$6, &_7$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_4$$6);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

