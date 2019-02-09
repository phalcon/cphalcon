
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
 * Helper method to check an array for an element. If it exists it returns it,
 * if not, it returns the supplied default value
 *
 * This is really necessary evil here since we do not have traits with Zephir.
 * Once we do, this will definitely be removed from being a static.
 */
PHP_METHOD(Phalcon_Utility, arrayGetDefault) {

	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &parameters_param, &defaultValue);

	zephir_get_strval(&name, name_param);
	zephir_get_arrval(&parameters, parameters_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	if (EXPECTED(zephir_array_isset_fetch(&value, &parameters, &name, 1 TSRMLS_CC))) {
		RETURN_CTOR(&value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

