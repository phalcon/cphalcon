
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_File) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Adapter, File, phalcon, logger_adapter_file, phalcon_logger_adapter_ce, phalcon_logger_adapter_file_method_entry, 0);

/**
	 * File handler resource
	 *
	 * @var resource
	 */
	zend_declare_property_null(phalcon_logger_adapter_file_ce, SL("_fileHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * File Path
	 */
	zend_declare_property_null(phalcon_logger_adapter_file_ce, SL("_path"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Path options
	 */
	zend_declare_property_null(phalcon_logger_adapter_file_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_logger_adapter_file_ce TSRMLS_CC, 1, phalcon_logger_adapterinterface_ce);

	return SUCCESS;

}

/**
 * Phalcon\Logger\Adapter\File constructor
 *
 * @param string name
 * @param array options
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, __construct) {

	zval *name_param = NULL, *options = NULL, *mode = NULL, *handler, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &options);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if ((Z_TYPE_P(options) == IS_ARRAY)) {
		ZEPHIR_OBS_VAR(mode);
		if (zephir_array_isset_string_fetch(&mode, options, SS("mode"), 0 TSRMLS_CC)) {
			if (zephir_memnstr_str(mode, SL("r"), "phalcon/logger/adapter/file.zep", 67)) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "Logger must be opened in append or write mode");
				return;
			}
		}
	} else {
		ZEPHIR_INIT_NVAR(mode);
		ZVAL_STRING(mode, "ab", 1);
	}
	ZEPHIR_INIT_VAR(handler);
	zephir_call_func_p2(handler, "fopen", name, mode);
	if (!(zephir_is_true(handler))) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_logger_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "Can't open log file at '", name, "'");
		zephir_call_method_p1_noret(_0, "__construct", _1);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("_path"), name TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_fileHandler"), handler TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the internal formatter
 *
 * @return Phalcon\Logger\FormatterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, getFormatter) {

	zval *formatter;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(formatter);
	zephir_read_property_this(&formatter, this_ptr, SL("_formatter"), PH_NOISY_CC);
	if ((Z_TYPE_P(formatter) != IS_OBJECT)) {
		ZEPHIR_INIT_BNVAR(formatter);
		object_init_ex(formatter, phalcon_logger_formatter_line_ce);
		zephir_call_method_noret(formatter, "__construct");
		zephir_update_property_this(this_ptr, SL("_formatter"), formatter TSRMLS_CC);
	}
	RETURN_CCTOR(formatter);

}

/**
 * Writes the log to the file itself
 *
 * @param string message
 * @param int type
 * @param int time
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, logInternal) {

	int type, time;
	zval *message_param = NULL, *type_param = NULL, *time_param = NULL, *fileHandler, *formatter, *_0, *_1, *_2;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &message_param, &type_param, &time_param);

		if (Z_TYPE_P(message_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		message = message_param;

		type = zephir_get_intval(type_param);
		time = zephir_get_intval(time_param);


	fileHandler = zephir_fetch_nproperty_this(this_ptr, SL("_fileHandler"), PH_NOISY_CC);
	if (!(zephir_is_true(fileHandler))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "Cannot send message to the log because it is invalid");
		return;
	}
	ZEPHIR_INIT_VAR(formatter);
	zephir_call_method(formatter, this_ptr, "getformatter");
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, type);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, time);
	zephir_call_method_p3(_0, formatter, "format", message, _1, _2);
	zephir_call_func_p2_noret("fwrite", fileHandler, _0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Closes the logger
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, close) {

	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_fileHandler"), PH_NOISY_CC);
	zephir_call_func_p1(return_value, "fclose", _0);
	RETURN_MM();

}

/**
 * Opens the internal file handler after unserialization
 *
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, __wakeup) {

	zval *path, *options, *mode, *_0;

	ZEPHIR_MM_GROW();

	path = zephir_fetch_nproperty_this(this_ptr, SL("_path"), PH_NOISY_CC);
	if ((Z_TYPE_P(path) != IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "Invalid data passed to Phalcon\\Logger\\Adapter\\File::__wakeup()");
		return;
	}
	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(mode);
	if (!(zephir_array_isset_string_fetch(&mode, options, SS("mode"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_BNVAR(mode);
		ZVAL_STRING(mode, "ab", 1);
	}
	if ((Z_TYPE_P(mode) != IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "Invalid data passed to Phalcon\\Logger\\Adapter\\File::__wakeup()");
		return;
	}
	if (zephir_memnstr_str(mode, SL("r"), "phalcon/logger/adapter/file.zep", 157)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "Logger must be opened in append or write mode");
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p2(_0, "fopen", path, mode);
	zephir_update_property_this(this_ptr, SL("_fileHandler"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

