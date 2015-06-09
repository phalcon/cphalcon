
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
#include "kernel/file.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Stream) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Adapter, Stream, phalcon, logger_adapter_stream, phalcon_logger_adapter_ce, phalcon_logger_adapter_stream_method_entry, 0);

	/**
	 * File handler resource
	 *
	 * @var resource
	 */
	zend_declare_property_null(phalcon_logger_adapter_stream_ce, SL("_stream"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_logger_adapter_stream_ce TSRMLS_CC, 1, phalcon_logger_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Logger\Adapter\Stream constructor
 *
 * @param string name
 * @param array options
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *options = NULL, *mode = NULL, *stream = NULL, *_0;
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


	ZEPHIR_OBS_VAR(mode);
	if (zephir_array_isset_string_fetch(&mode, options, SS("mode"), 0 TSRMLS_CC)) {
		if (zephir_memnstr_str(mode, SL("r"), "phalcon/logger/adapter/stream.zep", 61)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "Stream must be opened in append or write mode", "phalcon/logger/adapter/stream.zep", 62);
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(mode);
		ZVAL_STRING(mode, "ab", 1);
	}
	ZEPHIR_CALL_FUNCTION(&stream, "fopen", NULL, 276, name, mode);
	zephir_check_call_status();
	if (!(zephir_is_true(stream))) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_logger_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "Can't open stream '", name, "'");
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalcon/logger/adapter/stream.zep", 73 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("_stream"), stream TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the internal formatter
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, getFormatter) {

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
 * Writes the log to the stream itself
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, logInternal) {

	zval *context = NULL;
	int type, time, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *type_param = NULL, *time_param = NULL, *context_param = NULL, *stream, *_0 = NULL, *_1 = NULL, *_2, *_3;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &message_param, &type_param, &time_param, &context_param);

	zephir_get_strval(message, message_param);
	type = zephir_get_intval(type_param);
	time = zephir_get_intval(time_param);
	zephir_get_arrval(context, context_param);


	ZEPHIR_OBS_VAR(stream);
	zephir_read_property_this(&stream, this_ptr, SL("_stream"), PH_NOISY_CC);
	if (Z_TYPE_P(stream) != IS_RESOURCE) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "Cannot send message to the log because it is invalid", "phalcon/logger/adapter/stream.zep", 100);
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
	zephir_fwrite(NULL, stream, _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Closes the logger
 */
PHP_METHOD(Phalcon_Logger_Adapter_Stream, close) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_stream"), PH_NOISY_CC);
	RETURN_BOOL(zephir_fclose(_0 TSRMLS_CC));

}

