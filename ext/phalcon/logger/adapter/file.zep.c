
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/file.h"


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
 * File Path
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, getPath) {


	RETURN_MEMBER(this_ptr, "_path");

}

/**
 * Phalcon\Logger\Adapter\File constructor
 *
 * @param string name
 * @param array options
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *options = NULL, *mode = NULL, *handler = NULL, *_0;
	zval *name = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &options);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}
	ZEPHIR_INIT_VAR(mode);
	ZVAL_NULL(mode);


	if (Z_TYPE_P(options) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(mode);
		if (zephir_array_isset_string_fetch(&mode, options, SS("mode"), 0 TSRMLS_CC)) {
			if (zephir_memnstr_str(mode, SL("r"), "phalcon/logger/adapter/file.zep", 73)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "Logger must be opened in append or write mode", "phalcon/logger/adapter/file.zep", 74);
				return;
			}
		}
	}
	if (Z_TYPE_P(mode) == IS_NULL) {
		ZEPHIR_INIT_NVAR(mode);
		ZVAL_STRING(mode, "ab", 1);
	}
	ZEPHIR_CALL_FUNCTION(&handler, "fopen", NULL, 276, name, mode);
	zephir_check_call_status();
	if (Z_TYPE_P(handler) != IS_RESOURCE) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_logger_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "Can't open log file at '", name, "'");
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalcon/logger/adapter/file.zep", 88 TSRMLS_CC);
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
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, getFormatter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_formatter"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_logger_formatter_line_ce);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 281);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_formatter"), _1 TSRMLS_CC);
	}
	RETURN_MM_MEMBER(this_ptr, "_formatter");

}

/**
 * Writes the log to the file itself
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, logInternal) {

	zval *context = NULL;
	int type, time, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *type_param = NULL, *time_param = NULL, *context_param = NULL, *fileHandler, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3, *_4;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &message_param, &type_param, &time_param, &context_param);

	zephir_get_strval(message, message_param);
	type = zephir_get_intval(type_param);
	time = zephir_get_intval(time_param);
	zephir_get_arrval(context, context_param);


	ZEPHIR_OBS_VAR(fileHandler);
	zephir_read_property_this(&fileHandler, this_ptr, SL("_fileHandler"), PH_NOISY_CC);
	if (Z_TYPE_P(fileHandler) != IS_RESOURCE) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "Cannot send message to the log because it is invalid", "phalcon/logger/adapter/file.zep", 117);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getformatter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, type);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, time);
	ZEPHIR_CALL_METHOD(&_1, _0, "format", NULL, 0, message, _2, _3, context);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZEPHIR_GET_CONSTANT(_2, "PHP_EOL");
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VV(_4, _1, _2);
	zephir_fwrite(NULL, fileHandler, _4 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Closes the logger
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, close) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_fileHandler"), PH_NOISY_CC);
	RETURN_BOOL(zephir_fclose(_0 TSRMLS_CC));

}

/**
 * Opens the internal file handler after unserialization
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, __wakeup) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path, *mode = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(path);
	zephir_read_property_this(&path, this_ptr, SL("_path"), PH_NOISY_CC);
	if (Z_TYPE_P(path) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "Invalid data passed to Phalcon\\Logger\\Adapter\\File::__wakeup()", "phalcon/logger/adapter/file.zep", 140);
		return;
	}
	ZEPHIR_OBS_VAR(mode);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&mode, _0, SS("mode"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(mode);
		ZVAL_STRING(mode, "ab", 1);
	}
	if (Z_TYPE_P(mode) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "Invalid data passed to Phalcon\\Logger\\Adapter\\File::__wakeup()", "phalcon/logger/adapter/file.zep", 148);
		return;
	}
	if (zephir_memnstr_str(mode, SL("r"), "phalcon/logger/adapter/file.zep", 151)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "Logger must be opened in append or write mode", "phalcon/logger/adapter/file.zep", 152);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_1, "fopen", NULL, 276, path, mode);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_fileHandler"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

