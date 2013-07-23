
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
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/object.h"

/**
 * Phalcon\Logger\Adapter\Stream
 *
 * Sends logs to a valid PHP stream
 *
 *<code>
 *	$logger = new \Phalcon\Logger\Adapter\Stream("php://stderr");
 *	$logger->log("This is a message");
 *	$logger->log("This is an error", \Phalcon\Logger::ERROR);
 *	$logger->error("This is another error");
 *</code>
 */


/**
 * Phalcon\Logger\Adapter\Stream initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_Adapter_Stream){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Logger\\Adapter, Stream, logger_adapter_stream, "phalcon\\logger\\adapter", phalcon_logger_adapter_stream_method_entry, 0);

	zend_declare_property_null(phalcon_logger_adapter_stream_ce, SL("_stream"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_logger_adapter_stream_ce TSRMLS_CC, 1, phalcon_logger_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Logger\Adapter\Stream constructor
 *
 * @param string $name
 * @param array $options
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, __construct){

	zval *name, *options = NULL, *mode = NULL, *stream, *exception_message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &name, &options);
	
	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	if (phalcon_array_isset_string(options, SS("mode"))) {
	
		PHALCON_OBS_VAR(mode);
		phalcon_array_fetch_string(&mode, options, SL("mode"), PH_NOISY);
		if (phalcon_memnstr_str(mode, SL("r"))) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "Stream must be opened in append or write mode");
			return;
		}
	} else {
		PHALCON_INIT_NVAR(mode);
		ZVAL_STRING(mode, "ab", 1);
	}
	
	/** 
	 * We use 'fopen' to respect to open-basedir directive
	 */
	PHALCON_INIT_VAR(stream);
	phalcon_call_func_p2(stream, "fopen", name, mode);
	if (!zend_is_true(stream)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Can't open stream '", name, "'");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_logger_exception_ce, exception_message);
		return;
	}
	
	phalcon_update_property_this(this_ptr, SL("_stream"), stream TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the internal formatter
 *
 * @return Phalcon\Logger\Formatter\Line
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, getFormatter){

	zval *formatter = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(formatter);
	phalcon_read_property_this(&formatter, this_ptr, SL("_formatter"), PH_NOISY_CC);
	if (Z_TYPE_P(formatter) != IS_OBJECT) {
		PHALCON_INIT_NVAR(formatter);
		object_init_ex(formatter, phalcon_logger_formatter_line_ce);
		phalcon_call_method_noret(formatter, "__construct");
	
		phalcon_update_property_this(this_ptr, SL("_formatter"), formatter TSRMLS_CC);
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
PHP_METHOD(Phalcon_Logger_Adapter_Stream, logInternal){

	zval *message, *type, *time, *stream, *formatter, *applied_format;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &message, &type, &time);
	
	PHALCON_OBS_VAR(stream);
	phalcon_read_property_this(&stream, this_ptr, SL("_stream"), PH_NOISY_CC);
	if (!zend_is_true(stream)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "Cannot send message to the log because it is invalid");
		return;
	}
	
	PHALCON_INIT_VAR(formatter);
	phalcon_call_method(formatter, this_ptr, "getformatter");
	
	PHALCON_INIT_VAR(applied_format);
	phalcon_call_method_p3(applied_format, formatter, "format", message, type, time);
	phalcon_call_func_p2_noret("fwrite", stream, applied_format);
	
	PHALCON_MM_RESTORE();
}

/**
 * Closes the logger
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, close){

	zval *stream;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(stream);
	phalcon_read_property_this(&stream, this_ptr, SL("_stream"), PH_NOISY_CC);
	phalcon_call_func_p1(return_value, "fclose", stream);
	RETURN_MM();
}

