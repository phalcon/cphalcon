
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"


/**
 * Phalcon\Logger\Adapter\Syslog
 *
 * Sends logs to the system logger
 *
 *<code>
 *	$logger = new \Phalcon\Logger\Adapter\Syslog("ident", array(
 *		'option' => LOG_NDELAY,
 *		'facility' => LOG_MAIL
 *	));
 *	$logger->log("This is a message");
 *	$logger->log("This is an error", \Phalcon\Logger::ERROR);
 *	$logger->error("This is another error");
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Syslog) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Adapter, Syslog, phalcon, logger_adapter_syslog, phalcon_logger_adapter_ce, phalcon_logger_adapter_syslog_method_entry, 0);

	zend_declare_property_bool(phalcon_logger_adapter_syslog_ce, SL("_opened"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_logger_adapter_syslog_ce TSRMLS_CC, 1, phalcon_logger_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Logger\Adapter\Syslog constructor
 *
 * @param string name
 * @param array options
 */
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name, *options = NULL, *option = NULL, *facility = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_is_true(name)) {
		ZEPHIR_OBS_VAR(option);
		if (!(zephir_array_isset_string_fetch(&option, options, SS("option"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(option);
			ZVAL_LONG(option, 4);
		}
		ZEPHIR_OBS_VAR(facility);
		if (!(zephir_array_isset_string_fetch(&facility, options, SS("facility"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(facility);
			ZVAL_LONG(facility, 8);
		}
		ZEPHIR_CALL_FUNCTION(NULL, "openlog", NULL, 282, name, option, facility);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_opened"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the internal formatter
 */
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, getFormatter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_formatter"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_logger_formatter_syslog_ce);
		if (zephir_has_constructor(_1 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("_formatter"), _1 TSRMLS_CC);
	}
	RETURN_MM_MEMBER(this_ptr, "_formatter");

}

/**
 * Writes the log to the stream itself
 *
 * @param string message
 * @param int type
 * @param int time
 * @param array $context
 */
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, logInternal) {

	zval *context = NULL;
	int type, time, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *type_param = NULL, *time_param = NULL, *context_param = NULL, *appliedFormat = NULL, *_0 = NULL, *_1, *_2, *_3, *_4;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &message_param, &type_param, &time_param, &context_param);

	zephir_get_strval(message, message_param);
	type = zephir_get_intval(type_param);
	time = zephir_get_intval(time_param);
	zephir_get_arrval(context, context_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getformatter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, type);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, time);
	ZEPHIR_CALL_METHOD(&appliedFormat, _0, "format", NULL, 0, message, _1, _2, context);
	zephir_check_call_status();
	if (Z_TYPE_P(appliedFormat) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "The formatted message is not valid", "phalcon/logger/adapter/syslog.zep", 99);
		return;
	}
	zephir_array_fetch_long(&_3, appliedFormat, 0, PH_NOISY | PH_READONLY, "phalcon/logger/adapter/syslog.zep", 102 TSRMLS_CC);
	zephir_array_fetch_long(&_4, appliedFormat, 1, PH_NOISY | PH_READONLY, "phalcon/logger/adapter/syslog.zep", 102 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "syslog", NULL, 283, _3, _4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Closes the logger
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, close) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_opened"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_FUNCTION(NULL, "closelog", NULL, 284);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

