
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * PhalconNG\Logger\LoggerFactory
 *
 * Logger factory
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_LoggerFactory) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger, LoggerFactory, phalcon, logger_loggerfactory, phalcon_logger_loggerfactory_method_entry, 0);

	return SUCCESS;

}

/**
 * Returns a Logger object
 *
 * @param string $name
 * @param array  $adapters
 *
 * @return Logger
 */
PHP_METHOD(Phalcon_Logger_LoggerFactory, newInstance) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval adapters;
	zval *name_param = NULL, *adapters_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&adapters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &adapters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!adapters_param) {
		ZEPHIR_INIT_VAR(&adapters);
		array_init(&adapters);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&adapters, adapters_param);
	}


	object_init_ex(return_value, phalcon_logger_logger_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 400, &name, &adapters);
	zephir_check_call_status();
	RETURN_MM();

}

