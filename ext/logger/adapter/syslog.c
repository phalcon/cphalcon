
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

#include "kernel/array.h"
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


/**
 * Phalcon\Logger\Adapter\Syslog initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_Adapter_Syslog){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Logger\\Adapter, Syslog, logger_adapter_syslog, "phalcon\\logger\\adapter", phalcon_logger_adapter_syslog_method_entry, 0);

	zend_declare_property_bool(phalcon_logger_adapter_syslog_ce, SL("_opened"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_logger_adapter_syslog_ce TSRMLS_CC, 1, phalcon_logger_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Logger\Adapter\Syslog constructor
 *
 * @param string $name
 * @param array $options
 */
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, __construct){

	zval *name, *options = NULL, *option = NULL, *facility = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &name, &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	/** 
	 * We use 'fopen' to respect to open-basedir directive
	 */
	if (zend_is_true(name)) {
		if (phalcon_array_isset_string(options, SS("option"))) {
			PHALCON_OBS_VAR(option);
			phalcon_array_fetch_string(&option, options, SL("option"), PH_NOISY_CC);
		} else {
			/** 
			 * Open the log in LOG_ODELAY mode
			 */
			PHALCON_INIT_NVAR(option);
			ZVAL_LONG(option, 4);
		}
		if (phalcon_array_isset_string(options, SS("facility"))) {
			PHALCON_OBS_VAR(facility);
			phalcon_array_fetch_string(&facility, options, SL("facility"), PH_NOISY_CC);
		} else {
			/** 
			 * By default the facility is LOG_USER
			 */
			PHALCON_INIT_NVAR(facility);
			ZVAL_LONG(facility, 8);
		}
	
		PHALCON_CALL_FUNC_PARAMS_3_NORETURN("openlog", name, option, facility);
		phalcon_update_property_bool(this_ptr, SL("_opened"), 1 TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the internal formatter
 *
 * @return Phalcon\Logger\Formatter\Line
 */
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, getFormatter){

	zval *formatter = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(formatter);
	phalcon_read_property_this(&formatter, this_ptr, SL("_formatter"), PH_NOISY_CC);
	if (Z_TYPE_P(formatter) != IS_OBJECT) {
		PHALCON_INIT_NVAR(formatter);
		object_init_ex(formatter, phalcon_logger_formatter_syslog_ce);
		phalcon_update_property_zval(this_ptr, SL("_formatter"), formatter TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(formatter);
}

/**
 * Writes the log to the stream itself
 *
 * @param string $message
 * @param int $type
 * @param int $time
 */
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, logInternal){

	zval *message, *type, *time, *formatter, *applied_format;
	zval *syslog_type, *syslog_message;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &message, &type, &time) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(formatter);
	PHALCON_CALL_METHOD(formatter, this_ptr, "getformatter");
	
	PHALCON_INIT_VAR(applied_format);
	PHALCON_CALL_METHOD_PARAMS_3(applied_format, formatter, "format", message, type, time);
	if (Z_TYPE_P(applied_format) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "The formatted message is not valid");
		return;
	}
	
	PHALCON_OBS_VAR(syslog_type);
	phalcon_array_fetch_long(&syslog_type, applied_format, 0, PH_NOISY_CC);
	
	PHALCON_OBS_VAR(syslog_message);
	phalcon_array_fetch_long(&syslog_message, applied_format, 1, PH_NOISY_CC);
	PHALCON_CALL_FUNC_PARAMS_2_NORETURN("syslog", syslog_type, syslog_message);
	
	PHALCON_MM_RESTORE();
}

/**
  * Closes the logger
  *
  * @return boolean
  */
PHP_METHOD(Phalcon_Logger_Adapter_Syslog, close){

	zval *opened;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(opened);
	phalcon_read_property_this(&opened, this_ptr, SL("_opened"), PH_NOISY_CC);
	if (zend_is_true(opened)) {
		PHALCON_CALL_FUNC_NORETURN("closelog");
	}
	
	PHALCON_MM_RESTORE();
}

