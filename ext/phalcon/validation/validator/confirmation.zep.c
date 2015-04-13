
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
#include "kernel/object.h"
#include "kernel/exception.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Validation\Validator\Confirmation
 *
 * Checks that two values have the same value
 *
 *<code>
 *use Phalcon\Validation\Validator\Confirmation;
 *
 *$validator->add('password', new Confirmation(array(
 *   'message' => 'Password doesn\'t match confirmation',
 *   'with' => 'confirmPassword'
 *)));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Confirmation) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Confirmation, phalcon, validation_validator_confirmation, phalcon_validation_validator_ce, phalcon_validation_validator_confirmation_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 *
 * @param Phalcon\Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_Confirmation, validate) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *fieldWith = NULL, *value = NULL, *valueWith = NULL, *message = NULL, *label = NULL, *labelWith = NULL, *replacePairs, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	zephir_get_strval(field, field_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "with", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&fieldWith, this_ptr, "getoption", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&valueWith, validation, "getvalue", NULL, fieldWith);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "compare", NULL, value, valueWith);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "labelWith", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&labelWith, this_ptr, "getoption", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(labelWith)) {
			ZEPHIR_CALL_METHOD(&labelWith, validation, "getlabel", NULL, fieldWith);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		array_init_size(replacePairs, 3);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replacePairs, SL(":with"), &labelWith, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "Confirmation", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_2, "strtr", &_3, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "Confirmation", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2, field, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, _0);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Compare strings
 *
 * @param string a
 * @param string b
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_Confirmation, compare) {

	zephir_fcall_cache_entry *_6 = NULL;
	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *a_param = NULL, *b_param = NULL, *_0 = NULL, *_1 = NULL, *_3 = NULL, _4 = zval_used_for_init, *_5 = NULL, *_7 = NULL;
	zval *a = NULL, *b = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &a_param, &b_param);

	zephir_get_strval(a, a_param);
	zephir_get_strval(b, b_param);


	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "caseSensitive", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "issetoption", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_2 = zephir_is_true(_0);
	if (_2) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "caseSensitive", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "getoption", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		_2 = !zephir_is_true(_3);
	}
	if (_2) {
		if (!((zephir_function_exists_ex(SS("mb_strtolower") TSRMLS_CC) == SUCCESS))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Extension 'mbstring' is required", "phalcon/validation/validator/confirmation.zep", 97);
			return;
		}
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "mb_strtolower", &_6, a, &_4);
		zephir_check_call_status();
		zephir_get_strval(a, _5);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_7, "mb_strtolower", &_6, b, &_4);
		zephir_check_call_status();
		zephir_get_strval(b, _7);
	}
	RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(a, b));

}

