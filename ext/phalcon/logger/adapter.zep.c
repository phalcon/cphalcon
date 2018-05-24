
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

	phalcon_logger_adapter_ce->create_object = zephir_init_properties_Phalcon_Logger_Adapter;

	zend_class_implements(phalcon_logger_adapter_ce TSRMLS_CC, 1, phalcon_logger_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Filters the logs sent to the handlers that are less or equal than a specific level
 */
PHP_METHOD(Phalcon_Logger_Adapter, setLogLevel) {

	zval *level_param = NULL, *_0;
	zend_long level;

	zephir_fetch_params(0, 1, 0, &level_param);

	level = zephir_get_intval(level_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, level);
	zephir_update_property_this(getThis(), SL("_logLevel"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the current log level
 */
PHP_METHOD(Phalcon_Logger_Adapter, getLogLevel) {

	

	RETURN_MEMBER(getThis(), "_logLevel");

}

/**
 * Sets the message formatter
 */
PHP_METHOD(Phalcon_Logger_Adapter, setFormatter) {

	zval *formatter;

	zephir_fetch_params(0, 1, 0, &formatter);



	zephir_update_property_this(getThis(), SL("_formatter"), formatter TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Starts a transaction
 */
PHP_METHOD(Phalcon_Logger_Adapter, begin) {

	

	if (1) {
		zephir_update_property_this(getThis(), SL("_transaction"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_transaction"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Commits the internal transaction
 */
PHP_METHOD(Phalcon_Logger_Adapter, commit) {

	HashTable *_3;
	HashPosition _2;
	zval *message = NULL, *_0, *_1, **_4, *_10, *_5$$4 = NULL, *_6$$4 = NULL, *_7$$4 = NULL, *_8$$4 = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_transaction"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "There is no active transaction", "phalcon/logger/adapter.zep", 107);
		return;
	}
	if (0) {
		zephir_update_property_this(getThis(), SL("_transaction"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_transaction"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_queue"), PH_NOISY_CC);
	zephir_is_iterable(_1, &_3, &_2, 0, 0, "phalcon/logger/adapter.zep", 125);
	for (
	  ; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zend_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(message, _4);
		ZEPHIR_CALL_METHOD(&_5$$4, message, "getmessage", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6$$4, message, "gettype", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7$$4, message, "gettime", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_8$$4, message, "getcontext", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loginternal", &_9, 0, _5$$4, _6$$4, _7$$4, _8$$4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_10);
	array_init(_10);
	zephir_update_property_this(getThis(), SL("_queue"), _10 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Rollbacks the internal transaction
 */
PHP_METHOD(Phalcon_Logger_Adapter, rollback) {

	zval *transaction = NULL, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(transaction);
	zephir_read_property_this(&transaction, this_ptr, SL("_transaction"), PH_NOISY_CC);
	if (!(zephir_is_true(transaction))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_logger_exception_ce, "There is no active transaction", "phalcon/logger/adapter.zep", 139);
		return;
	}
	if (0) {
		zephir_update_property_this(getThis(), SL("_transaction"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_transaction"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(getThis(), SL("_queue"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the whether the logger is currently in an active transaction or not
 */
PHP_METHOD(Phalcon_Logger_Adapter, isTransaction) {

	

	RETURN_MEMBER(getThis(), "_transaction");

}

/**
 * Sends/Writes a critical message to the log
 */
PHP_METHOD(Phalcon_Logger_Adapter, critical) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sends/Writes an emergency message to the log
 */
PHP_METHOD(Phalcon_Logger_Adapter, emergency) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sends/Writes a debug message to the log
 */
PHP_METHOD(Phalcon_Logger_Adapter, debug) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sends/Writes an error message to the log
 */
PHP_METHOD(Phalcon_Logger_Adapter, error) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sends/Writes an info message to the log
 */
PHP_METHOD(Phalcon_Logger_Adapter, info) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sends/Writes a notice message to the log
 */
PHP_METHOD(Phalcon_Logger_Adapter, notice) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sends/Writes a warning message to the log
 */
PHP_METHOD(Phalcon_Logger_Adapter, warning) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sends/Writes an alert message to the log
 */
PHP_METHOD(Phalcon_Logger_Adapter, alert) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Logs messages to the internal logger. Appends logs to the logger
 */
PHP_METHOD(Phalcon_Logger_Adapter, log) {

	zend_bool _0, _1$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *type, *message = NULL, *context_param = NULL, *timestamp = NULL, *toggledMessage = NULL, *toggledType = NULL, *_2, *_3$$8, *_4$$9;

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
		_1$$4 = Z_TYPE_P(type) == IS_STRING;
		if (_1$$4) {
			_1$$4 = Z_TYPE_P(message) == IS_NULL;
		}
		if (_1$$4) {
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
	if (ZEPHIR_GE(_2, toggledType)) {
		ZEPHIR_INIT_VAR(timestamp);
		zephir_time(timestamp);
		_3$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_transaction"), PH_NOISY_CC);
		if (zephir_is_true(_3$$8)) {
			ZEPHIR_INIT_VAR(_4$$9);
			object_init_ex(_4$$9, phalcon_logger_item_ce);
			ZEPHIR_CALL_METHOD(NULL, _4$$9, "__construct", NULL, 23, toggledMessage, toggledType, timestamp, context);
			zephir_check_call_status();
			zephir_update_property_array_append(this_ptr, SL("_queue"), _4$$9 TSRMLS_CC);
		} else {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "loginternal", NULL, 0, toggledMessage, toggledType, timestamp, context);
			zephir_check_call_status();
		}
	}
	RETURN_THIS();

}

zend_object_value zephir_init_properties_Phalcon_Logger_Adapter(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_queue"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_queue"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

