
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
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"


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
/**
 * Phalcon\Validation\Validator
 *
 * This is a base class for validators
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Validation, Validator, phalcon, validation_validator, phalcon_validation_validator_method_entry, 0);

	zend_declare_property_null(phalcon_validation_validator_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Validation\Validator constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Validation_Validator, __construct) {

	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		ZEPHIR_CPY_WRT(options, ZEPHIR_GLOBAL(global_null));
	}


	if ((Z_TYPE_P(options) != IS_ARRAY)) {
		if ((Z_TYPE_P(options) != IS_NULL)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "The attribute must be a string");
			return;
		}
	} else {
		zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if an option is defined
 *
 * @param string key
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation_Validator, isSetOption) {

	zval *key_param = NULL, *options;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

		zephir_get_strval(key, key_param);


	ZEPHIR_OBS_VAR(options);
	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if ((Z_TYPE_P(options) == IS_ARRAY)) {
		RETURN_MM_BOOL(zephir_array_isset(options, key));
	}
	RETURN_MM_BOOL(0);

}

/**
 * Returns an option in the validator's options
 * Returns null if the option hasn't been set
 *
 * @param string key
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation_Validator, getOption) {

	zval *key_param = NULL, *options, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

		zephir_get_strval(key, key_param);


	ZEPHIR_OBS_VAR(options);
	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if ((Z_TYPE_P(options) == IS_ARRAY)) {
		ZEPHIR_OBS_VAR(value);
		if (zephir_array_isset_fetch(&value, options, key TSRMLS_CC)) {
			RETURN_CCTOR(value);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Sets an option in the validator
 *
 * @param string key
 * @param mixed value
 */
PHP_METHOD(Phalcon_Validation_Validator, setOption) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

		zephir_get_strval(key, key_param);


	zephir_update_property_array(this_ptr, SL("_options"), key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

