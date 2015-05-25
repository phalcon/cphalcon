
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
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Validation\Validator\Uniqueness
 *
 * Check that a field is unique in the related table
 *
 *<code>
 *use Phalcon\Validation\Validator\Uniqueness as UniquenessValidator;
 *
 *$validator->add('username', new UniquenessValidator(array(
 *    'model' => 'Users',
 *    'message' => ':field must be unique'
 *)));
 *</code>
 * 
 * Different attribute from the field
 *<code>
 *$validator->add('username', new UniquenessValidator(array(
 *    'model' => 'Users',
 *    'attribute' => 'nick'
 *)));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Uniqueness) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Uniqueness, phalcon, validation_validator_uniqueness, phalcon_validation_validator_ce, phalcon_validation_validator_uniqueness_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, validate) {

	zend_class_entry *_4, *_5;
	zval *_1 = NULL, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *attribute = NULL, *value = NULL, *model = NULL, *except = NULL, *number = NULL, *message = NULL, *label = NULL, *replacePairs, *_0 = NULL, *_2 = NULL, *_6 = NULL, *_7;

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
	ZVAL_STRING(_0, "model", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&model, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "attribute", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "except", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&except, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(model)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Model must be set", "phalcon/validation/validator/uniqueness.zep", 62);
		return;
	}
	if (ZEPHIR_IS_EMPTY(attribute)) {
		ZEPHIR_CPY_WRT(attribute, field);
	}
	if (zephir_is_true(except)) {
		ZEPHIR_INIT_VAR(_1);
		zephir_create_array(_1, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_VSVS(_2, attribute, "=:value: AND ", attribute, "!= :except:");
		zephir_array_fast_append(_1, _2);
		ZEPHIR_INIT_VAR(_3);
		zephir_create_array(_3, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&_3, SL("value"), &value, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_3, SL("except"), &except, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_1, SL("bind"), &_3, PH_COPY | PH_SEPARATE);
		_4 = zephir_fetch_class(model TSRMLS_CC);
		ZEPHIR_CALL_CE_STATIC(&number, _4, "count", NULL, 0, _1);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_1);
		zephir_create_array(_1, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_2);
		ZEPHIR_CONCAT_VS(_2, attribute, "=:value:");
		zephir_array_fast_append(_1, _2);
		ZEPHIR_INIT_NVAR(_3);
		zephir_create_array(_3, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_3, SL("value"), &value, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_1, SL("bind"), &_3, PH_COPY | PH_SEPARATE);
		_5 = zephir_fetch_class(model TSRMLS_CC);
		ZEPHIR_CALL_CE_STATIC(&number, _5, "count", NULL, 0, _1);
		zephir_check_call_status();
	}
	if (zephir_is_true(number)) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "Uniqueness", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_6, "strtr", NULL, 73, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_7);
		ZVAL_STRING(_7, "Uniqueness", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 425, _6, field, _7);
		zephir_check_temp_parameter(_7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _0);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

