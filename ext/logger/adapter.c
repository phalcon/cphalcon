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

#include "logger/adapter.h"
#include "logger/adapterinterface.h"
#include "logger/exception.h"
#include "logger/formatterinterface.h"
#include "logger/item.h"
#include "logger.h"
#include "psr/log/loggerinterface.h"
#include "psr/log/invalidargumentexception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"

/**
 * Phalcon\Logger\Adapter
 *
 * Base class for Phalcon\Logger adapters
 */
zend_class_entry *phalcon_logger_adapter_ce;

PHP_METHOD(Phalcon_Logger_Adapter, setLogLevel);
PHP_METHOD(Phalcon_Logger_Adapter, getLogLevel);
PHP_METHOD(Phalcon_Logger_Adapter, setFormatter);
PHP_METHOD(Phalcon_Logger_Adapter, isTransaction);
PHP_METHOD(Phalcon_Logger_Adapter, begin);
PHP_METHOD(Phalcon_Logger_Adapter, commit);
PHP_METHOD(Phalcon_Logger_Adapter, rollback);
PHP_METHOD(Phalcon_Logger_Adapter, emergency);
PHP_METHOD(Phalcon_Logger_Adapter, alert);
PHP_METHOD(Phalcon_Logger_Adapter, critical);
PHP_METHOD(Phalcon_Logger_Adapter, error);
PHP_METHOD(Phalcon_Logger_Adapter, warning);
PHP_METHOD(Phalcon_Logger_Adapter, notice);
PHP_METHOD(Phalcon_Logger_Adapter, info);
PHP_METHOD(Phalcon_Logger_Adapter, debug);
PHP_METHOD(Phalcon_Logger_Adapter, log);

static const zend_function_entry phalcon_logger_adapter_method_entry[] = {
	PHP_ME(Phalcon_Logger_Adapter, setLogLevel, arginfo_phalcon_logger_adapterinterface_setloglevel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, getLogLevel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, setFormatter, arginfo_phalcon_logger_adapterinterface_setformatter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, isTransaction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, begin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, rollback, NULL, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Logger_Adapter, emergence, emergency, arginfo_phalcon_logger_adapterinterface_emergency, ZEND_ACC_PUBLIC | ZEND_ACC_DEPRECATED)
	PHP_ME(Phalcon_Logger_Adapter, log, arginfo_phalcon_logger_adapterinterface_log, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, debug, arginfo_phalcon_logger_adapterinterface_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, info, arginfo_phalcon_logger_adapterinterface_info, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, notice, arginfo_phalcon_logger_adapterinterface_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, warning, arginfo_phalcon_logger_adapterinterface_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, error, arginfo_phalcon_logger_adapterinterface_error, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, critical, arginfo_phalcon_logger_adapterinterface_critical, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, alert, arginfo_phalcon_logger_adapterinterface_alert, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, emergency, arginfo_phalcon_logger_adapterinterface_emergency, ZEND_ACC_PUBLIC)
	ZEND_FENTRY(logInternal, NULL, arginfo_phalcon_logger_adapter_loginternal, ZEND_ACC_PROTECTED | ZEND_ACC_ABSTRACT)
	PHP_FE_END
};

/**
 * Phalcon\Logger\Adapter initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_Adapter){

	PHALCON_REGISTER_CLASS(Phalcon\\Logger, Adapter, logger_adapter, phalcon_logger_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_bool(phalcon_logger_adapter_ce, SL("_transaction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_ce, SL("_queue"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_ce, SL("_formatter"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_logger_adapter_ce, SL("_logLevel"), PHALCON_LOGGER_SPECIAL, ZEND_ACC_PROTECTED TSRMLS_CC);

	/* Prior to PHP 5.3.9, a class could not implement two interfaces
	 * that specified a method with the same name, since it would cause
	 * ambiguity. More recent versions of PHP allow this as long as
	 * the duplicate methods have the same signature.
	 */
#if PHP_VERSION_ID >= 50309
	if (PHALCON_GLOBAL(register_psr3_classes)) {
		zend_class_implements(phalcon_logger_adapter_ce TSRMLS_CC, 2, phalcon_logger_adapterinterface_ce, psr_log_loggerinterface_ce);
	}
	else {
		zend_class_implements(phalcon_logger_adapter_ce TSRMLS_CC, 1, phalcon_logger_adapterinterface_ce);
	}
#else
	zend_class_implements(phalcon_logger_adapter_ce TSRMLS_CC, 1, phalcon_logger_adapterinterface_ce);
#endif
	return SUCCESS;
}

static int phalcon_logger_adapter_string_level_to_int(const zval *level)
{
	const char *s = Z_STRVAL_P(level);
	size_t len    = (size_t)(Z_STRLEN_P(level));
	size_t i;

	struct sl {
		const char *str;
		size_t len;
		int level;
	};

	static struct sl lookup_table[] = {
		{ ZEND_STRL("emergency"), PHALCON_LOGGER_EMERGENCY },
		{ ZEND_STRL("alert"),     PHALCON_LOGGER_ALERT     },
		{ ZEND_STRL("critical"),  PHALCON_LOGGER_CRITICAL  },
		{ ZEND_STRL("error"),     PHALCON_LOGGER_ERROR     },
		{ ZEND_STRL("warning"),   PHALCON_LOGGER_WARNING   },
		{ ZEND_STRL("notice"),    PHALCON_LOGGER_NOTICE    },
		{ ZEND_STRL("info"),      PHALCON_LOGGER_INFO      },
		{ ZEND_STRL("debug"),     PHALCON_LOGGER_DEBUG     }
	};

	assert(Z_TYPE_P(level) == IS_STRING);

	for (i=0; i<sizeof(lookup_table)/sizeof(lookup_table[0]); ++i) {
		if (lookup_table[i].len == len && !memcmp(lookup_table[i].str, s, len)) {
			return lookup_table[i].level;
		}
	}

	{
		TSRMLS_FETCH();
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Unrecognized log level '%s'", s);
		return PHALCON_LOGGER_CUSTOM;
	}
}

/**
 * Filters the logs sent to the handlers that are less or equal than a specific level
 *
 * @param int $level
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, setLogLevel){

	zval **level, *lvl;

	phalcon_fetch_params_ex(1, 0, &level);
	if (Z_TYPE_PP(level) == IS_STRING) {
		PHALCON_ALLOC_GHOST_ZVAL(lvl);
		ZVAL_LONG(lvl, phalcon_logger_adapter_string_level_to_int(*level));
	}
	else if (Z_TYPE_PP(level) != IS_LONG) {
		PHALCON_ENSURE_IS_LONG(level);
		lvl = *level;
	}
	else {
		lvl = *level;
	}

	phalcon_update_property_this(this_ptr, SL("_logLevel"), lvl TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the current log level
 *
 * @return int
 */
PHP_METHOD(Phalcon_Logger_Adapter, getLogLevel){


	RETURN_MEMBER(this_ptr, "_logLevel");
}

/**
 * Sets the message formatter
 *
 * @param Phalcon\Logger\FormatterInterface $formatter
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, setFormatter){

	zval *formatter;
	zend_class_entry *exception = PHALCON_GLOBAL(register_psr3_classes) ? psr_log_invalidargumentexception_ce : phalcon_logger_exception_ce;

	phalcon_fetch_params(0, 1, 0, &formatter);
	PHALCON_VERIFY_INTERFACE_EX(formatter, phalcon_logger_formatterinterface_ce, exception, 0);

	phalcon_update_property_this(this_ptr, SL("_formatter"), formatter TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the current transaction
 *
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, isTransaction){

	RETURN_MEMBER(this_ptr, "_transaction");
}

/**
 * Starts a transaction
 *
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, begin){


	phalcon_update_property_bool(this_ptr, SL("_transaction"), 1 TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Commits the internal transaction
 *
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, commit){

	zval *transaction, *queue, *message_str = NULL;
	zval *type = NULL, *time = NULL, *context = NULL;

	transaction = phalcon_fetch_nproperty_this(this_ptr, SL("_transaction"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(transaction)) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_logger_exception_ce, "There is no active transaction");
		return;
	}
	
	phalcon_update_property_bool(this_ptr, SL("_transaction"), 0 TSRMLS_CC);
	
	/* Check if the queue has something to log */
	queue = phalcon_fetch_nproperty_this(this_ptr, SL("_queue"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(queue) == IS_ARRAY) { 
		HashPosition hp;
		zval **message;

		PHALCON_MM_GROW();

		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(queue), &hp);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(queue), (void**)&message, &hp) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(queue), &hp)
		) {
			PHALCON_CALL_METHOD(&message_str, *message, "getmessage");
			PHALCON_CALL_METHOD(&type, *message, "gettype");
			PHALCON_CALL_METHOD(&time, *message, "gettime");
			PHALCON_CALL_METHOD(&context, *message, "getcontext");
			PHALCON_CALL_METHOD(NULL, this_ptr, "loginternal", message_str, type, time, context);
		}

		if (Z_REFCOUNT_P(queue) == 1 || Z_ISREF_P(queue)) {
			zend_hash_clean(Z_ARRVAL_P(queue));
		}
		else {
			PHALCON_ALLOC_GHOST_ZVAL(queue);
			array_init(queue);
			phalcon_update_property_this(getThis(), SL("_queue"), queue TSRMLS_CC);
		}

		PHALCON_MM_RESTORE();
	}
	
	RETURN_THISW();
}

/**
 * Rollbacks the internal transaction
 *
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, rollback){

	zval *transaction, *queue;

	transaction = phalcon_fetch_nproperty_this(this_ptr, SL("_transaction"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(transaction)) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_logger_exception_ce, "There is no active transaction");
		return;
	}
	
	phalcon_update_property_bool(this_ptr, SL("_transaction"), 0 TSRMLS_CC);
	
	PHALCON_ALLOC_GHOST_ZVAL(queue);
	array_init_size(queue, 0);
	phalcon_update_property_this(this_ptr, SL("_queue"), queue TSRMLS_CC);
	
	RETURN_THISW();
}

static void phalcon_logger_adapter_log_helper(INTERNAL_FUNCTION_PARAMETERS, int level)
{
	zval **message, **context = NULL, *type;

	phalcon_fetch_params_ex(1, 1, &message, &context);
	PHALCON_ENSURE_IS_STRING(message);

	PHALCON_ALLOC_GHOST_ZVAL(type);
	ZVAL_LONG(type, level);

	if (!context) {
		context = &PHALCON_GLOBAL(z_null);
	}

	PHALCON_CALL_METHODW(NULL, getThis(), "log", type, *message, *context);
	RETURN_ZVAL(getThis(), 1, 0);
}

/**
 * Sends/Writes an emergency message to the log
 *
 * @param string $message
 * @param array $context
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, emergency){

	phalcon_logger_adapter_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PHALCON_LOGGER_EMERGENCY);
}

/**
 * Sends/Writes a debug message to the log
 *
 * @param string $message
 * @param array $context
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, debug){

	phalcon_logger_adapter_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PHALCON_LOGGER_DEBUG);
}

/**
 * Sends/Writes an error message to the log
 *
 * @param string $message
 * @param array $context
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, error){

	phalcon_logger_adapter_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PHALCON_LOGGER_ERROR);
}

/**
 * Sends/Writes an info message to the log
 *
 * @param string $message
 * @param array $context
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, info){

	phalcon_logger_adapter_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PHALCON_LOGGER_INFO);
}

/**
 * Sends/Writes a notice message to the log
 *
 * @param string $message
 * @param array $context
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, notice){

	phalcon_logger_adapter_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PHALCON_LOGGER_NOTICE);
}

/**
 * Sends/Writes a warning message to the log
 *
 * @param string $message
 * @param array $context
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, warning){

	phalcon_logger_adapter_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PHALCON_LOGGER_WARNING);
}

/**
 * Sends/Writes an alert message to the log
 *
 * @param string $message
 * @param array $context
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, alert){

	phalcon_logger_adapter_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PHALCON_LOGGER_ALERT);
}

/**
 * Sends/Writes a critical message to the log
 *
 * @param string $message
 * @param array $context
 * @return Phalcon\Logger\AdapterInterface
 */
PHP_METHOD(Phalcon_Logger_Adapter, critical){

	phalcon_logger_adapter_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PHALCON_LOGGER_CRITICAL);
}

/**
 * Logs messages to the internal logger. Appends messages to the log
 *
 * @param mixed type
 * @param string $message
 * @param array $context
 * @return Phalcon\Logger\Adapter
 */
PHP_METHOD(Phalcon_Logger_Adapter, log){

	zval **message = NULL, **type, **context = NULL, *timestamp, *transaction;
	zval *queue_item, *log_level, *level;
	int i_level;

	phalcon_fetch_params_ex(1, 2, &type, &message, &context);

	/*
	 * Backwards compatibility.
	 *
	 * PSR-3 says:
	 *
	 * public function log($level, $message, array $context = array());
	 *
	 * Our old definition:
	 *
	 * public function log($message, $level = null)
	 *
	 * Now we want to implement PSR-3
	 * Thus:
	 *   - when $message === null, $level is $message and $level is DEBUG
	 *   - when typeof($message) == 'int' && typeof($level) == 'string', then
	 *     $message is $level and $level is $message.
	 */
	if (message == NULL) {
		message = type;
		type    = NULL;
	}
	else if (Z_TYPE_PP(message) == IS_LONG && Z_TYPE_PP(type) == IS_STRING) {
		zval **tmp = message;
		message    = type;
		type       = tmp;
	}

	if (!context) {
		context = &PHALCON_GLOBAL(z_null);
	}

	if (!type) {
		i_level = PHALCON_LOGGER_DEBUG;
	}
	else if (Z_TYPE_PP(type) == IS_STRING) {
		i_level = phalcon_logger_adapter_string_level_to_int(*type);
	}
	else {
		PHALCON_ENSURE_IS_LONG(type);
		i_level = Z_LVAL_PP(type);
	}

	log_level = phalcon_fetch_nproperty_this(this_ptr, SL("_logLevel"), PH_NOISY TSRMLS_CC);

	/* Only log the message if this is allowed by the current log level */
	if (phalcon_get_intval(log_level) >= i_level) {
		PHALCON_MM_GROW();

		PHALCON_INIT_VAR(timestamp);
		ZVAL_LONG(timestamp, (long)time(NULL));

		PHALCON_INIT_VAR(level);
		ZVAL_LONG(level, i_level);

		transaction = phalcon_fetch_nproperty_this(this_ptr, SL("_transaction"), PH_NOISY TSRMLS_CC);
		if (zend_is_true(transaction)) {
			PHALCON_INIT_VAR(queue_item);
			object_init_ex(queue_item, phalcon_logger_item_ce);
			PHALCON_CALL_METHOD(NULL, queue_item, "__construct", *message, level, timestamp, *context);

			phalcon_update_property_array_append(this_ptr, SL("_queue"), queue_item TSRMLS_CC);
		}
		else {
			PHALCON_CALL_METHOD(NULL, this_ptr, "loginternal", *message, level, timestamp, *context);
		}

		PHALCON_MM_RESTORE();
	}

	RETURN_THISW();
}
