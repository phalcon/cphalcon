
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

	zend_class_entry *_4$$5, *_8$$6;
	zval *_1$$5, *_3$$5, *_5$$6, *_7$$6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *attribute = NULL, *value = NULL, *model = NULL, *except = NULL, *number = NULL, *message = NULL, *label = NULL, *replacePairs = NULL, *_0 = NULL, *_2$$5, *_6$$6, *_9$$7 = NULL, *_11$$7 = NULL, *_12$$7, *_10$$9;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Model must be set", "phalcon/validation/validator/uniqueness.zep", 65);
		return;
	}
	if (ZEPHIR_IS_EMPTY(attribute)) {
		ZEPHIR_CPY_WRT(attribute, field);
	}
	if (zephir_is_true(except)) {
		ZEPHIR_INIT_VAR(_1$$5);
		zephir_create_array(_1$$5, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2$$5);
		ZEPHIR_CONCAT_VSVS(_2$$5, attribute, " = :value: AND ", attribute, " != :except:");
		zephir_array_fast_append(_1$$5, _2$$5);
		ZEPHIR_INIT_VAR(_3$$5);
		zephir_create_array(_3$$5, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&_3$$5, SL("value"), &value, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_3$$5, SL("except"), &except, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_1$$5, SL("bind"), &_3$$5, PH_COPY | PH_SEPARATE);
		_4$$5 = zephir_fetch_class(model TSRMLS_CC);
		ZEPHIR_CALL_CE_STATIC(&number, _4$$5, "count", NULL, 0, _1$$5);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_5$$6);
		zephir_create_array(_5$$6, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_6$$6);
		ZEPHIR_CONCAT_VS(_6$$6, attribute, " = :value:");
		zephir_array_fast_append(_5$$6, _6$$6);
		ZEPHIR_INIT_VAR(_7$$6);
		zephir_create_array(_7$$6, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_7$$6, SL("value"), &value, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_5$$6, SL("bind"), &_7$$6, PH_COPY | PH_SEPARATE);
		_8$$6 = zephir_fetch_class(model TSRMLS_CC);
		ZEPHIR_CALL_CE_STATIC(&number, _8$$6, "count", NULL, 0, _5$$6);
		zephir_check_call_status();
	}
	if (zephir_is_true(number)) {
		ZEPHIR_INIT_VAR(_9$$7);
		ZVAL_STRING(_9$$7, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _9$$7);
		zephir_check_temp_parameter(_9$$7);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_9$$7);
		ZVAL_STRING(_9$$7, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _9$$7);
		zephir_check_temp_parameter(_9$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_VAR(_10$$9);
			ZVAL_STRING(_10$$9, "Uniqueness", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _10$$9);
			zephir_check_temp_parameter(_10$$9);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_9$$7);
		object_init_ex(_9$$7, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_11$$7, "strtr", NULL, 55, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_12$$7);
		ZVAL_STRING(_12$$7, "Uniqueness", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _9$$7, "__construct", NULL, 434, _11$$7, field, _12$$7);
		zephir_check_temp_parameter(_12$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _9$$7);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

