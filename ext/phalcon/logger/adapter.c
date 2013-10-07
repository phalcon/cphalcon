
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"


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
 * Phalcon\Logger\Adapter
 *
 * Base class for Phalcon\Logger adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger, Adapter, phalcon, logger_adapter, phalcon_logger_adapter_method_entry, 0);

/**
	 * Tells if there is an active transaction or not
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(phalcon_logger_adapter_ce, SL("_transaction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Array with messages queued in the transacction
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
 *
 * @param int level
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, setLogLevel) {

	zval *level_param = NULL, *_0;
	int level;

	zephir_fetch_params(0, 1, 0, &level_param);

		level = zephir_get_intval(level_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, level);
	zephir_update_property_zval(this_ptr, SL("_logLevel"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the current log level
 *
 * @return int
 */
PHP_METHOD(Phalcon_Logger_Adapter, getLogLevel) {


	RETURN_MEMBER(this_ptr, "_logLevel");

}

/**
 * Sets the message formatter
 *
 * @param Phalcon\Logger\FormatterInterface formatter
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, setFormatter) {

	zval *formatter;

	zephir_fetch_params(0, 1, 0, &formatter);



	zephir_update_property_this(this_ptr, SL("_formatter"), formatter TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Starts a transaction
 *
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, begin) {


	zephir_update_property_this(this_ptr, SL("_transaction"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Commits the internal transaction
 *
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, commit) {

	zend_function *_4 = NULL, *_6 = NULL, *_8 = NULL, *_9 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *transaction, *queue, *message = NULL, **_2, *_3 = NULL, *_5 = NULL, *_7 = NULL;

	ZEPHIR_MM_GROW();

	transaction = zephir_fetch_nproperty_this(this_ptr, SL("_transaction"), PH_NOISY_CC);
	if (!(zephir_is_true(transaction))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "There is no active transaction");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_transaction"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	queue = zephir_fetch_nproperty_this(this_ptr, SL("_queue"), PH_NOISY_CC);
	if ((Z_TYPE_P(queue) == IS_ARRAY)) {
		zephir_is_iterable(queue, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(message, _2);
			ZEPHIR_INIT_NVAR(_3);
			zephir_call_method_cache(_3, message, "getmessage", &_4);
			ZEPHIR_INIT_NVAR(_5);
			zephir_call_method_cache(_5, message, "gettype", &_6);
			ZEPHIR_INIT_NVAR(_7);
			zephir_call_method_cache(_7, message, "gettime", &_8);
			zephir_call_method_p3_cache_noret(this_ptr, "loginternal", &_9, _3, _5, _7);
		}
	}
	RETURN_THIS();

}

/**
 * Rollbacks the internal transaction
 *
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, rollback) {

	zval *transaction, *_0;

	ZEPHIR_MM_GROW();

	transaction = zephir_fetch_nproperty_this(this_ptr, SL("_transaction"), PH_NOISY_CC);
	if (!(zephir_is_true(transaction))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "There is no active transaction");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_transaction"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_queue"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sends/Writes an emergence message to the log
 *
 * @param string message
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, emergence) {

	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

		zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	zephir_call_method_p2_noret(this_ptr, "log", message, _0);
	RETURN_THIS();

}

/**
 * Sends/Writes a debug message to the log
 *
 * @param string message
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, debug) {

	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

		zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 7);
	zephir_call_method_p2_noret(this_ptr, "log", message, _0);
	RETURN_THIS();

}

/**
 * Sends/Writes an error message to the log
 *
 * @param string message
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, error) {

	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

		zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 3);
	zephir_call_method_p2_noret(this_ptr, "log", message, _0);
	RETURN_THIS();

}

/**
 * Sends/Writes an info message to the log
 *
 * @param string message
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, info) {

	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

		zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 6);
	zephir_call_method_p2_noret(this_ptr, "log", message, _0);
	RETURN_THIS();

}

/**
 * Sends/Writes a notice message to the log
 *
 * @param string message
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, notice) {

	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

		zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 5);
	zephir_call_method_p2_noret(this_ptr, "log", message, _0);
	RETURN_THIS();

}

/**
 * Sends/Writes a warning message to the log
 *
 * @param string message
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, warning) {

	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

		zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 4);
	zephir_call_method_p2_noret(this_ptr, "log", message, _0);
	RETURN_THIS();

}

/**
 * Sends/Writes an alert message to the log
 *
 * @param string message
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, alert) {

	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

		zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2);
	zephir_call_method_p2_noret(this_ptr, "log", message, _0);
	RETURN_THIS();

}

/**
 * Logs messages to the internal loggger. Appends logs to the
 *
 * @param string message
 * @param int type
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, log) {

	int type;
	zval *message_param = NULL, *type_param = NULL, *timestamp, *transaction, *_0 = NULL, *_1, *_2;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &type_param);

		zephir_get_strval(message, message_param);
	if (!type_param) {
		type = 7;	} else {
		type = zephir_get_intval(type_param);
	}


	ZEPHIR_INIT_VAR(timestamp);
	zephir_call_func(timestamp, "time");
	transaction = zephir_fetch_nproperty_this(this_ptr, SL("_transaction"), PH_NOISY_CC);
	if (zephir_is_true(transaction)) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_logger_item_ce);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_LONG(_1, type);
		zephir_call_method_p3_noret(_0, "__construct", message, _1, timestamp);
		zephir_update_property_array_append(this_ptr, SL("_queue"), _0 TSRMLS_CC);
		RETURN_THIS();
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_logLevel"), PH_NOISY_CC);
	if (ZEPHIR_GE_LONG(_2, type)) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, type);
		zephir_call_method_p3_noret(this_ptr, "loginternal", message, _0, timestamp);
	}
	RETURN_THIS();

}

