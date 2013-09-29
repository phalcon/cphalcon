
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"

/**
 * Phalcon\Validation\Validator
 *
 * This is a base class for validators
 */


/**
 * Phalcon\Validation\Validator initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation_Validator){

	PHALCON_REGISTER_CLASS(Phalcon\\Validation, Validator, validation_validator, phalcon_validation_validator_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_validation_validator_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
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
			PHALCON_THROW_EXCEPTION_STRW(phalcon_validation_exception_ce, "The attribute must be a string");
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

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key);
	
	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		if (phalcon_array_isset(options, key)) {
			RETURN_MM_TRUE;
		}
	}
	
	RETURN_MM_FALSE;
}

/**
 * Returns an option in the validator's options
 * Returns null if the option hasn't been set
 *
 * @param string $key
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation_Validator, getOption){

	zval *key, *options, *value;

	phalcon_fetch_params(0, 1, 0, &key);
	
	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (phalcon_array_isset_fetch(&value, options, key)) {
		RETURN_ZVAL(value, 1, 0);
	}
	
	RETURN_NULL();
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

