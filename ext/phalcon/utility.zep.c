
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Utility
 *
 * This class contains protected methods used throughout the framework
 */
ZEPHIR_INIT_CLASS(Phalcon_Utility) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Utility, phalcon, utility, phalcon_utility_method_entry, 0);

	return SUCCESS;

}

/**
 * Helper method to get an array element or a default
 */
PHP_METHOD(Phalcon_Utility, arrayGetDefault) {

	zval name;
	zval *parameters_param = NULL, *name_param = NULL, *defaultValue, defaultValue_sub, value;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &parameters_param, &name_param, &defaultValue);

	zephir_get_arrval(&parameters, parameters_param);
	zephir_get_strval(&name, name_param);


	if (EXPECTED(zephir_array_isset_fetch(&value, &parameters, &name, 1 TSRMLS_CC))) {
		RETURN_CTOR(&value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

