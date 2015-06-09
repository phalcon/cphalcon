
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/time.h"


/**
 * Phalcon\Logger\Adapter
 *
 * Base class for Phalcon\Logger adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger, Adapter, phalcon, logger_adapter, phalcon_logger_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Tells if there is an active transaction or not
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(phalcon_logger_adapter_ce, SL("_transaction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Array with messages queued in the transaction
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_logger_adapter_ce, SL("_queue"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Formatter
	 *
	 * @var object
	 */
	zend_declare_property_null(phalcon_logger_adapter_ce, SL("_formatter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Log level
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_logger_adapter_ce, SL("_logLevel"), 9, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Filters the logs sent to the handlers that are less or equal than a specific level
 */
PHP_METHOD(Phalcon_Logger_Adapter, setLogLevel) {

	zval *level_param = NULL, *_0;
	int level;

	zephir_fetch_params(0, 1, 0, &level_param);

	level = zephir_get_intval(level_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, level);
	zephir_update_property_this(this_ptr, SL("_logLevel"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the current log level
 */
PHP_METHOD(Phalcon_Logger_Adapter, getLogLevel) {


	RETURN_MEMBER(this_ptr, "_logLevel");

}

/**
 * Sets the message formatter
 */
PHP_METHOD(Phalcon_Logger_Adapter, setFormatter) {

	zval *formatter;

	zephir_fetch_params(0, 1, 0, &formatter);



	zephir_update_property_this(this_ptr, SL("_formatter"), formatter TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Starts a transaction
 */
PHP_METHOD(Phalcon_Logger_Adapter, begin) {


	zephir_update_property_this(this_ptr, SL("_transaction"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Commits the internal transaction
 */
PHP_METHOD(Phalcon_Logger_Adapter, commit) {

	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *queue, *message = NULL, *_0, **_3, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_transaction"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "There is no active transaction", "phalcon/logger/adapter.zep", 107);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_transaction"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_OBS_VAR(queue);
	zephir_read_property_this(&queue, this_ptr, SL("_queue"), PH_NOISY_CC);
	if (Z_TYPE_P(queue) == IS_ARRAY) {
		zephir_is_iterable(queue, &_2, &_1, 0, 0, "phalcon/logger/adapter.zep", 125);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(message, _3);
			ZEPHIR_CALL_METHOD(&_4, message, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_5, message, "gettype", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_6, message, "gettime", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7, message, "getcontext", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "loginternal", &_8, 0, _4, _5, _6, _7);
			zephir_check_call_status();
		}
	}
	RETURN_THIS();

}

/**
 * Rollbacks the internal transaction
 */
PHP_METHOD(Phalcon_Logger_Adapter, rollback) {

	zval *transaction, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(transaction);
	zephir_read_property_this(&transaction, this_ptr, SL("_transaction"), PH_NOISY_CC);
	if (!(zephir_is_true(transaction))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "There is no active transaction", "phalcon/logger/adapter.zep", 139);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_transaction"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_queue"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sends/Writes a critical message to the log
 */
PHP_METHOD(Phalcon_Logger_Adapter, critical) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (unlikely(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!context_param) {
	ZEPHIR_INIT_VAR(context);
	array_init(context);
	} else {
	context = context_param;

	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sends/Writes an emergency message to the log
 */
PHP_METHOD(Phalcon_Logger_Adapter, emergency) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (unlikely(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!context_param) {
	ZEPHIR_INIT_VAR(context);
	array_init(context);
	} else {
	context = context_param;

	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sends/Writes a debug message to the log
 */
PHP_METHOD(Phalcon_Logger_Adapter, debug) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (unlikely(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!context_param) {
	ZEPHIR_INIT_VAR(context);
	array_init(context);
	} else {
	context = context_param;

	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 7);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sends/Writes an error message to the log
 */
PHP_METHOD(Phalcon_Logger_Adapter, error) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (unlikely(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!context_param) {
	ZEPHIR_INIT_VAR(context);
	array_init(context);
	} else {
	context = context_param;

	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 3);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sends/Writes an info message to the log
 */
PHP_METHOD(Phalcon_Logger_Adapter, info) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (unlikely(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!context_param) {
	ZEPHIR_INIT_VAR(context);
	array_init(context);
	} else {
	context = context_param;

	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 6);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sends/Writes a notice message to the log
 */
PHP_METHOD(Phalcon_Logger_Adapter, notice) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (unlikely(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!context_param) {
	ZEPHIR_INIT_VAR(context);
	array_init(context);
	} else {
	context = context_param;

	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 5);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sends/Writes a warning message to the log
 */
PHP_METHOD(Phalcon_Logger_Adapter, warning) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (unlikely(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!context_param) {
	ZEPHIR_INIT_VAR(context);
	array_init(context);
	} else {
	context = context_param;

	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 4);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sends/Writes an alert message to the log
 */
PHP_METHOD(Phalcon_Logger_Adapter, alert) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (unlikely(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!context_param) {
	ZEPHIR_INIT_VAR(context);
	array_init(context);
	} else {
	context = context_param;

	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Logs messages to the internal logger. Appends logs to the logger
 * @param mixed type
 * @param mixed message
 * @param mixed context
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, log) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0, _1;
	zval *context = NULL;
	zval *type, *message = NULL, *context_param = NULL, *timestamp, *toggledMessage = NULL, *toggledType = NULL, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &type, &message, &context_param);

	if (!message) {
		message = ZEPHIR_GLOBAL(global_null);
	}
	if (!context_param) {
	ZEPHIR_INIT_VAR(context);
	array_init(context);
	} else {
	context = context_param;

	}


	_0 = Z_TYPE_P(type) == IS_STRING;
	if (_0) {
		_0 = Z_TYPE_P(message) == IS_LONG;
	}
	if (_0) {
		ZEPHIR_CPY_WRT(toggledMessage, type);
		ZEPHIR_CPY_WRT(toggledType, message);
	} else {
		_1 = Z_TYPE_P(type) == IS_STRING;
		if (_1) {
			_1 = Z_TYPE_P(message) == IS_NULL;
		}
		if (_1) {
			ZEPHIR_CPY_WRT(toggledMessage, type);
			ZEPHIR_CPY_WRT(toggledType, message);
		} else {
			ZEPHIR_CPY_WRT(toggledMessage, message);
			ZEPHIR_CPY_WRT(toggledType, type);
		}
	}
	if (Z_TYPE_P(toggledType) == IS_NULL) {
		ZEPHIR_INIT_NVAR(toggledType);
		ZVAL_LONG(toggledType, 7);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_logLevel"), PH_NOISY_CC);
	if (ZEPHIR_GE(_2, type)) {
		ZEPHIR_INIT_VAR(timestamp);
		zephir_time(timestamp);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_transaction"), PH_NOISY_CC);
		if (zephir_is_true(_3)) {
			ZEPHIR_INIT_VAR(_4);
			object_init_ex(_4, phalcon_logger_item_ce);
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 280, toggledMessage, toggledType, timestamp, context);
			zephir_check_call_status();
			zephir_update_property_array_append(this_ptr, SL("_queue"), _4 TSRMLS_CC);
		} else {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "loginternal", NULL, 0, toggledMessage, toggledType, timestamp, context);
			zephir_check_call_status();
		}
	}
	RETURN_THIS();

}

