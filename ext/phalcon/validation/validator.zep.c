
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 * Phalcon\Validation\Validator
 *
 * This is a base class for validators
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Validation, Validator, phalcon, validation_validator, phalcon_validation_validator_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_validation_validator_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_validation_validator_ce TSRMLS_CC, 1, phalcon_validation_validatorinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Validation\Validator constructor
 */
PHP_METHOD(Phalcon_Validation_Validator, __construct) {

	zval *options_param = NULL;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
	options = options_param;
	}


	zephir_update_property_this(getThis(), SL("_options"), options TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if an option has been defined

 * @deprecated since 2.1.0
 * @see \Phalcon\Validation\Validator::hasOption()
 */
PHP_METHOD(Phalcon_Validation_Validator, isSetOption) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, key));

}

/**
 * Checks if an option is defined
 */
PHP_METHOD(Phalcon_Validation_Validator, hasOption) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, key));

}

/**
 * Returns an option in the validator's options
 * Returns null if the option hasn't set
 */
PHP_METHOD(Phalcon_Validation_Validator, getOption) {

	zend_bool _0$$4;
	zval *key_param = NULL, *defaultValue = NULL, *options = NULL, *value = NULL, *fieldValue = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(options) == IS_ARRAY) {
		if (zephir_array_isset_fetch(&value, options, key, 1 TSRMLS_CC)) {
			_0$$4 = ZEPHIR_IS_STRING(key, "attribute");
			if (_0$$4) {
				_0$$4 = Z_TYPE_P(value) == IS_ARRAY;
			}
			if (_0$$4) {
				if (zephir_array_isset_fetch(&fieldValue, value, key, 1 TSRMLS_CC)) {
					RETURN_CTOR(fieldValue);
				}
			}
			RETURN_CTOR(value);
		}
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Sets an option in the validator
 */
PHP_METHOD(Phalcon_Validation_Validator, setOption) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	zephir_update_property_array(this_ptr, SL("_options"), key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator, validate) {

}

/**
 * Prepares a label for the field.
 */
PHP_METHOD(Phalcon_Validation_Validator, prepareLabel) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *label = NULL, *_0, *_1$$3;

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


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "label", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(label) == IS_ARRAY) {
		zephir_array_fetch(&_1$$3, label, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator.zep", 110 TSRMLS_CC);
		ZEPHIR_CPY_WRT(label, _1$$3);
	}
	if (ZEPHIR_IS_EMPTY(label)) {
		ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
		zephir_check_call_status();
	}
	RETURN_CCTOR(label);

}

/**
 * Prepares a validation message.
 */
PHP_METHOD(Phalcon_Validation_Validator, prepareMessage) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL, *type = NULL, *option = NULL;
	zval *validation, *field_param = NULL, *type_param = NULL, *option_param = NULL, *message = NULL, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &validation, &field_param, &type_param, &option_param);

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
	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}
	if (!option_param) {
		ZEPHIR_INIT_VAR(option);
		ZVAL_STRING(option, "message", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(option_param) != IS_STRING && Z_TYPE_P(option_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'option' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(option_param) == IS_STRING)) {
		zephir_get_strval(option, option_param);
	} else {
		ZEPHIR_INIT_VAR(option);
		ZVAL_EMPTY_STRING(option);
	}
	}


	ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, option);
	zephir_check_call_status();
	if (Z_TYPE_P(message) == IS_ARRAY) {
		zephir_array_fetch(&_0$$3, message, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator.zep", 129 TSRMLS_CC);
		ZEPHIR_CPY_WRT(message, _0$$3);
	}
	if (ZEPHIR_IS_EMPTY(message)) {
		ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, type);
		zephir_check_call_status();
	}
	RETURN_CCTOR(message);

}

/**
 * Prepares a validation code.
 */
PHP_METHOD(Phalcon_Validation_Validator, prepareCode) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *code = NULL, *_0, *_1$$3;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

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


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "code", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&code, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(code) == IS_ARRAY) {
		zephir_array_fetch(&_1$$3, code, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator.zep", 148 TSRMLS_CC);
		ZEPHIR_CPY_WRT(code, _1$$3);
	}
	RETURN_CCTOR(code);

}

