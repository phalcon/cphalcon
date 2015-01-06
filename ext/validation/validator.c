/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "validation/validator.h"
#include "validation/validatorinterface.h"
#include "validation/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"

#include "interned-strings.h"

/**
 * Phalcon\Validation\Validator
 *
 * This is a base class for validators
 */
zend_class_entry *phalcon_validation_validator_ce;

PHP_METHOD(Phalcon_Validation_Validator, __construct);
PHP_METHOD(Phalcon_Validation_Validator, isSetOption);
PHP_METHOD(Phalcon_Validation_Validator, getOption);
PHP_METHOD(Phalcon_Validation_Validator, setOption);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_validation_validator_method_entry[] = {
	PHP_ME(Phalcon_Validation_Validator, __construct, arginfo_phalcon_validation_validator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Validation_Validator, isSetOption, arginfo_phalcon_validation_validatorinterface_issetoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator, getOption, arginfo_phalcon_validation_validatorinterface_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator, setOption, arginfo_phalcon_validation_validatorinterface_setoption, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Validation\Validator initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation_Validator){

	PHALCON_REGISTER_CLASS(Phalcon\\Validation, Validator, validation_validator, phalcon_validation_validator_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_validation_validator_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_validation_validator_ce TSRMLS_CC, 1, phalcon_validation_validatorinterface_ce);

	return SUCCESS;
}

int phalcon_validation_validator_getoption_helper(const zend_class_entry *ce, zval **result, zval *this_ptr, const char *option TSRMLS_DC)
{
	zval *opt;
	zval *params[1];

	if (is_phalcon_class(ce)) {
		zval *value;
		zval *options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);

		MAKE_STD_ZVAL(*result);
		if (phalcon_array_isset_string_fetch(&value, options, option, strlen(option)+1)) {
			ZVAL_ZVAL(*result, value, 1, 0);
		}
		else {
			ZVAL_NULL(*result);
		}

		return SUCCESS;
	}

	PHALCON_ALLOC_GHOST_ZVAL(opt);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(opt, option);
	params[0] = opt;

	ALLOC_INIT_ZVAL(*result);
	return phalcon_return_call_method(*result, NULL, this_ptr, "getoption", 1, params TSRMLS_CC);
}

/**
 * Phalcon\Validation\Validator constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Validation_Validator, __construct){

	zval *options = NULL;

	phalcon_fetch_params(0, 0, 1, &options);
	
	if (!options) {
		options = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		if (Z_TYPE_P(options) != IS_NULL) {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_validation_exception_ce, "Options must be an array");
			return;
		}
	} else {
		phalcon_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	}
}

/**
 * Checks if an option is defined
 *
 * @param string $key
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation_Validator, isSetOption){

	zval *key, *options;

	phalcon_fetch_params(0, 1, 0, &key);
	
	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);
	RETURN_BOOL(phalcon_array_isset(options, key));
}

/**
 * Returns an option in the validator's options
 * Returns null if the option hasn't been set
 *
 * @param string $key
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation_Validator, getOption){

	zval **key;
	zval *tmp = NULL;

	phalcon_fetch_params_ex(1, 0, &key);
	PHALCON_ENSURE_IS_STRING(key);
	phalcon_validation_validator_getoption_helper(phalcon_validation_validator_ce, &tmp, getThis(), Z_STRVAL_PP(key) TSRMLS_CC);
	RETURN_ZVAL(tmp, 1, 1);
}

/**
 * Sets an option in the validator
 *
 * @param string $key
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Validation_Validator, setOption){

	zval *key, *value;

	phalcon_fetch_params(0, 2, 0, &key, &value);
	
	phalcon_update_property_array(this_ptr, SL("_options"), key, value TSRMLS_CC);
	
}
