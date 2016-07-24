
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
 * Phalcon\Validation\Validator\Identical
 *
 * Checks if a value is identical to other
 *
 * <code>
 * use Phalcon\Validation\Validator\Identical;
 *
 * $validator->add('terms', new Identical([
 *     'accepted' => 'yes',
 *     'message' => 'Terms and conditions must be accepted'
 * ]));
 *
 * $validator->add(['terms', 'anotherTerms'], new Identical([
 *     'accepted' => [
 *         'terms' => 'yes',
 *         'anotherTerms' => 'yes'
 *     ],
 *     'message' => [
 *         'terms' => 'Terms and conditions must be accepted',
 *         'anotherTerms' => 'Another terms  must be accepted'
 *     ]
 * ]));
 * </code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Identical) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Identical, phalcon, validation_validator_identical, phalcon_validation_validator_ce, phalcon_validation_validator_identical_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Identical, validate) {

	zend_bool valid = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *message = NULL, *label = NULL, *replacePairs = NULL, *value = NULL, *accepted = NULL, *valueOption = NULL, *code = NULL, *_0 = NULL, *_1, *_2$$3, *_3$$4, *_4$$5 = NULL, *_5$$5, *_6$$6, *_7$$7, *_8$$8 = NULL, *_13$$8 = NULL, *_14$$8, *_9$$9, *_10$$11, *_11$$12, *_12$$13;

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
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "accepted", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasoption", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "accepted", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&accepted, this_ptr, "getoption", NULL, 0, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(accepted) == IS_ARRAY) {
			zephir_array_fetch(&_3$$4, accepted, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/identical.zep", 67 TSRMLS_CC);
			ZEPHIR_CPY_WRT(accepted, _3$$4);
		}
		valid = ZEPHIR_IS_EQUAL(value, accepted);
	} else {
		ZEPHIR_INIT_VAR(_5$$5);
		ZVAL_STRING(_5$$5, "value", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_4$$5, this_ptr, "hasoption", NULL, 0, _5$$5);
		zephir_check_temp_parameter(_5$$5);
		zephir_check_call_status();
		if (zephir_is_true(_4$$5)) {
			ZEPHIR_INIT_VAR(_6$$6);
			ZVAL_STRING(_6$$6, "value", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&valueOption, this_ptr, "getoption", NULL, 0, _6$$6);
			zephir_check_temp_parameter(_6$$6);
			zephir_check_call_status();
			if (Z_TYPE_P(valueOption) == IS_ARRAY) {
				zephir_array_fetch(&_7$$7, valueOption, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/identical.zep", 74 TSRMLS_CC);
				ZEPHIR_CPY_WRT(valueOption, _7$$7);
			}
			valid = ZEPHIR_IS_EQUAL(value, valueOption);
		}
	}
	if (!(valid)) {
		ZEPHIR_INIT_VAR(_8$$8);
		ZVAL_STRING(_8$$8, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _8$$8);
		zephir_check_temp_parameter(_8$$8);
		zephir_check_call_status();
		if (Z_TYPE_P(label) == IS_ARRAY) {
			zephir_array_fetch(&_9$$9, label, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/identical.zep", 84 TSRMLS_CC);
			ZEPHIR_CPY_WRT(label, _9$$9);
		}
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_8$$8);
		ZVAL_STRING(_8$$8, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _8$$8);
		zephir_check_temp_parameter(_8$$8);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_ARRAY) {
			zephir_array_fetch(&_10$$11, message, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/identical.zep", 92 TSRMLS_CC);
			ZEPHIR_CPY_WRT(message, _10$$11);
		}
		ZEPHIR_INIT_VAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_VAR(_11$$12);
			ZVAL_STRING(_11$$12, "Identical", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _11$$12);
			zephir_check_temp_parameter(_11$$12);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_8$$8);
		ZVAL_STRING(_8$$8, "code", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&code, this_ptr, "getoption", NULL, 0, _8$$8);
		zephir_check_temp_parameter(_8$$8);
		zephir_check_call_status();
		if (Z_TYPE_P(code) == IS_ARRAY) {
			zephir_array_fetch(&_12$$13, code, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/identical.zep", 101 TSRMLS_CC);
			ZEPHIR_CPY_WRT(code, _12$$13);
		}
		ZEPHIR_INIT_NVAR(_8$$8);
		object_init_ex(_8$$8, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_13$$8, "strtr", NULL, 26, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_14$$8);
		ZVAL_STRING(_14$$8, "Identical", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _8$$8, "__construct", NULL, 462, _13$$8, field, _14$$8, code);
		zephir_check_temp_parameter(_14$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _8$$8);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

