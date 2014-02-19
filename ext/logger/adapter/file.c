
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

#include "logger/adapter/file.h"
#include "logger/adapter.h"
#include "logger/adapterinterface.h"
#include "logger/exception.h"
#include "logger/formatter/line.h"
#include "psr/log/invalidargumentexception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/object.h"

/**
 * Phalcon\Logger\Adapter\File
 *
 * Adapter to store logs in plain text files
 *
 *<code>
 *	$logger = new \Phalcon\Logger\Adapter\File("app/logs/test.log");
 *	$logger->log("This is a message");
 *	$logger->log("This is an error", \Phalcon\Logger::ERROR);
 *	$logger->error("This is another error");
 *	$logger->close();
 *</code>
 */
zend_class_entry *phalcon_logger_adapter_file_ce;

PHP_METHOD(Phalcon_Logger_Adapter_File, __construct);
PHP_METHOD(Phalcon_Logger_Adapter_File, getFormatter);
PHP_METHOD(Phalcon_Logger_Adapter_File, logInternal);
PHP_METHOD(Phalcon_Logger_Adapter_File, close);
PHP_METHOD(Phalcon_Logger_Adapter_File, getPath);
PHP_METHOD(Phalcon_Logger_Adapter_File, __wakeup);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_logger_adapter_file_method_entry[] = {
	PHP_ME(Phalcon_Logger_Adapter_File, __construct, arginfo_phalcon_logger_adapter_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Logger_Adapter_File, getFormatter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_File, logInternal, arginfo_phalcon_logger_adapter_loginternal, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Logger_Adapter_File, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_File, getPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_File, __wakeup, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Logger\Adapter\File initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_Adapter_File){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Logger\\Adapter, File, logger_adapter_file, phalcon_logger_adapter_ce, phalcon_logger_adapter_file_method_entry, 0);

	zend_declare_property_null(phalcon_logger_adapter_file_ce, SL("_fileHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_file_ce, SL("_path"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_file_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_logger_adapter_file_ce TSRMLS_CC, 1, phalcon_logger_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Logger\Adapter\File constructor
 *
 * @param string $name
 * @param array $options
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, __construct){

	zval **name, **options = NULL, *mode = NULL, *handler = NULL;
	zend_class_entry *exception = PHALCON_GLOBAL(register_psr3_classes) ? psr_log_invalidargumentexception_ce : phalcon_logger_exception_ce;

	phalcon_fetch_params_ex(1, 1, &name, &options);
	PHALCON_ENSURE_IS_STRING(name);

	PHALCON_MM_GROW();

	if (!options) {
		options = &PHALCON_GLOBAL(z_null);
	}
	
	if (phalcon_array_isset_string_fetch(&mode, *options, SS("mode"))) {
		if (phalcon_memnstr_str(mode, SL("r"))) {
			PHALCON_THROW_EXCEPTION_STR(exception, "Logger must be opened in append or write mode");
			return;
		}
	} else {
		PHALCON_INIT_VAR(mode);
		ZVAL_STRING(mode, "ab", 1);
	}
	
	/** 
	 * We use 'fopen' to respect to open-basedir directive
	 */
	PHALCON_CALL_FUNCTION(&handler, "fopen", *name, mode);
	if (Z_TYPE_P(handler) != IS_RESOURCE) {
		zend_throw_exception_ex(exception, 0 TSRMLS_CC, "Cannot open log file '%s'", Z_STRVAL_PP(name));
	}
	else {
		phalcon_update_property_this(this_ptr, SL("_path"), *name TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_options"), *options TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_fileHandler"), handler TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the internal formatter
 *
 * @return Phalcon\Logger\Formatter\Line
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, getFormatter){

	zval *formatter = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(formatter);
	phalcon_read_property_this(&formatter, this_ptr, SL("_formatter"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(formatter) != IS_OBJECT) {
		PHALCON_INIT_NVAR(formatter);
		object_init_ex(formatter, phalcon_logger_formatter_line_ce);
		PHALCON_CALL_METHOD(NULL, formatter, "__construct");
	
		phalcon_update_property_this(this_ptr, SL("_formatter"), formatter TSRMLS_CC);
	}
	
	RETURN_CTOR(formatter);
}

/**
 * Writes the log to the file itself
 *
 * @param string $message
 * @param int $type
 * @param int $time
 * @param array $context
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, logInternal){

	zval *message, *type, *time, *file_handler, *formatter = NULL, *context;
	zval *applied_format = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &message, &type, &time, &context);
	
	file_handler = phalcon_fetch_nproperty_this(this_ptr, SL("_fileHandler"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(file_handler) != IS_RESOURCE) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "Cannot send message to the log because it is invalid");
		return;
	}
	
	PHALCON_CALL_METHOD(&formatter, this_ptr, "getformatter");
	PHALCON_CALL_METHOD(&applied_format, formatter, "format", message, type, time, context);
	PHALCON_CALL_FUNCTION(NULL, "fwrite", file_handler, applied_format);
	
	PHALCON_MM_RESTORE();
}

/**
 * Closes the logger
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, close){

	zval *file_handler;

	PHALCON_MM_GROW();

	file_handler = phalcon_fetch_nproperty_this(this_ptr, SL("_fileHandler"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_FUNCTION("fclose", file_handler);
	RETURN_MM();
}

/**
 * Returns the file path
 *
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, getPath) {

	RETURN_MEMBER(getThis(), "_path");
}

/**
 * Opens the internal file handler after unserialization
 *
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, __wakeup){

	zval *path, *options, *mode = NULL, *file_handler = NULL;
	zend_class_entry *exception = PHALCON_GLOBAL(register_psr3_classes) ? psr_log_invalidargumentexception_ce : phalcon_logger_exception_ce;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(path);
	phalcon_read_property_this(&path, this_ptr, SL("_path"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(path) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(exception, "Invalid data passed to Phalcon\\Logger\\Adapter\\File::__wakeup()");
		return;
	}

	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_string(options, SS("mode"))) {
		PHALCON_OBS_VAR(mode);
		phalcon_array_fetch_string(&mode, options, SL("mode"), PH_NOISY);
		if (Z_TYPE_P(mode) != IS_STRING) {
			PHALCON_THROW_EXCEPTION_STR(exception, "Invalid data passed to Phalcon\\Logger\\Adapter\\File::__wakeup()");
			return;
		}
	} else {
		PHALCON_INIT_NVAR(mode);
		ZVAL_STRING(mode, "ab", 1);
	}

	/**
	 * Re-open the file handler if the logger was serialized
	 */
	PHALCON_CALL_FUNCTION(&file_handler, "fopen", path, mode);
	phalcon_update_property_this(this_ptr, SL("_fileHandler"), file_handler TSRMLS_CC);

	PHALCON_MM_RESTORE();
}
