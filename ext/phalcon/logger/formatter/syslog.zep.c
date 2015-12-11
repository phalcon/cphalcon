
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"


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

	int type, timestamp, ZEPHIR_LAST_CALL_STATUS;
	zval *message = NULL, *type_param = NULL, *timestamp_param = NULL, *context = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &message, &type_param, &timestamp_param, &context);

	ZEPHIR_SEPARATE_PARAM(message);
	type = zephir_get_intval(type_param);
	timestamp = zephir_get_intval(timestamp_param);
	if (!context) {
		context = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(context) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "interpolate", NULL, 0, message, context);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(message, _0);
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, type);
	zephir_array_fast_append(return_value, _1);
	zephir_array_fast_append(return_value, message);
	RETURN_MM();

}

