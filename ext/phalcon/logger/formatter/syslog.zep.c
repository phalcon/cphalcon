
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


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
/**
 * Phalcon\Logger\Formatter\Syslog
 *
 * Prepares a message to be used in a Syslog backend
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Syslog) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Formatter, Syslog, phalcon, logger_formatter_syslog, phalcon_logger_formatter_ce, phalcon_logger_formatter_syslog_method_entry, 0);

	zend_class_implements(phalcon_logger_formatter_syslog_ce TSRMLS_CC, 1, phalcon_logger_formatterinterface_ce);
	return SUCCESS;

}

/**
 * Applies a format to a message before sent it to the internal log
 *
 * @param string message
 * @param int type
 * @param int timestamp
 * @param array $context
 * @return array
 */
PHP_METHOD(Phalcon_Logger_Formatter_Syslog, format) {

	zval *context = NULL;
	int type, timestamp, ZEPHIR_LAST_CALL_STATUS;
	zval *message = NULL, *type_param = NULL, *timestamp_param = NULL, *context_param = NULL, *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &message, &type_param, &timestamp_param, &context_param);

	ZEPHIR_SEPARATE_PARAM(message);
	type = zephir_get_intval(type_param);
	timestamp = zephir_get_intval(timestamp_param);
	if (!context_param) {
	ZEPHIR_INIT_VAR(context);
	ZVAL_NULL(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_gettype(_0, context TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_0, "array")) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "interpolate", NULL, message, context);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(message, _1);
	}
	array_init_size(return_value, 3);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, type);
	zephir_array_fast_append(return_value, _2);
	zephir_array_fast_append(return_value, message);
	RETURN_MM();

}

