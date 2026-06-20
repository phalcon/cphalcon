
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/time.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Long-running operational shell around a QueueConsumer. Owns the outer loop,
 * the bounded lifetime (max messages / seconds / memory, plus jitter) and -
 * when ext-pcntl is available - graceful shutdown on SIGTERM/SIGINT/SIGQUIT.
 * The current message always finishes before the loop stops (drain, not
 * guillotine), because the stop flag is only checked between iterations.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Consumer_Worker)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Consumer, Worker, phalcon, queue_consumer_worker, phalcon_queue_consumer_worker_method_entry, 0);

	/**
	 * @var QueueConsumer
	 */
	zend_declare_property_null(phalcon_queue_consumer_worker_ce, SL("consumer"), ZEND_ACC_PROTECTED);
	/**
	 * @var WorkerOptions
	 */
	zend_declare_property_null(phalcon_queue_consumer_worker_ce, SL("options"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Consumer_Worker, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *consumer, consumer_sub, *options = NULL, options_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&consumer_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(consumer, phalcon_queue_consumer_queueconsumer_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(options, phalcon_queue_consumer_workeroptions_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &consumer, &options);
	if (!options) {
		options = &options_sub;
		ZEPHIR_CPY_WRT(options, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}
	if (Z_TYPE_P(options) == IS_NULL) {
		ZEPHIR_INIT_NVAR(options);
		object_init_ex(options, phalcon_queue_consumer_workeroptions_ce);
		ZEPHIR_CALL_METHOD(NULL, options, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("consumer"), consumer);
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), options);
	ZEPHIR_MM_RESTORE();
}

/**
 * Signal handler: requests a graceful stop.
 */
PHP_METHOD(Phalcon_Queue_Consumer_Worker, handleSignal)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *signal_param = NULL, _0;
	zend_long signal, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(signal)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &signal_param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("consumer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "stop", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Runs the worker until a lifetime bound trips or a stop is requested.
 * Returns the number of messages processed.
 */
PHP_METHOD(Phalcon_Queue_Consumer_Worker, run)
{
	zend_bool _15$$6, _17$$6, _14$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_19 = NULL;
	zval __$true, options, _0, _1, _2, _3, _4, _5, _20, _6$$4, _7$$5, _8$$5, _9$$5, _10$$6, _11$$6, _12$$6, _13$$6, _16$$6, _18$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS, deadline = 0, jitter = 0, maxMemory = 0, maxMessages = 0, maxSeconds = 0, processed = 0;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_18$$6);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
	processed = 0;
	ZEPHIR_CALL_METHOD(&_1, &options, "getmaxmessages", NULL, 0);
	zephir_check_call_status();
	maxMessages = zephir_get_intval(&_1);
	ZEPHIR_CALL_METHOD(&_2, &options, "getmaxseconds", NULL, 0);
	zephir_check_call_status();
	maxSeconds = zephir_get_intval(&_2);
	ZEPHIR_CALL_METHOD(&_3, &options, "getmaxmemory", NULL, 0);
	zephir_check_call_status();
	maxMemory = zephir_get_intval(&_3);
	ZEPHIR_CALL_METHOD(&_4, &options, "getjitter", NULL, 0);
	zephir_check_call_status();
	jitter = zephir_get_intval(&_4);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("consumer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, &_0, "start", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_5))) {
		RETURN_MM_LONG(0);
	}
	deadline = 0;
	if (maxSeconds > 0) {
		ZEPHIR_INIT_VAR(&_6$$4);
		zephir_time(&_6$$4);
		deadline = (zephir_get_numberval(&_6$$4) + maxSeconds);
		if (jitter > 0) {
			ZVAL_LONG(&_7$$5, 0);
			ZVAL_LONG(&_8$$5, jitter);
			ZEPHIR_CALL_FUNCTION(&_9$$5, "random_int", NULL, 0, &_7$$5, &_8$$5);
			zephir_check_call_status();
			deadline = (deadline + (zend_long) zephir_get_numberval(&_9$$5));
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "installsignalhandlers", NULL, 0);
	zephir_check_call_status();
	while (1) {
		zephir_read_property(&_10$$6, this_ptr, ZEND_STRL("consumer"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_11$$6, &_10$$6, "isstoprequested", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_11$$6)) {
			break;
		}
		zephir_read_property(&_12$$6, this_ptr, ZEND_STRL("consumer"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_13$$6, &_12$$6, "consumeonce", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_13$$6)) {
			processed++;
			_14$$8 = maxMessages > 0;
			if (_14$$8) {
				_14$$8 = processed >= maxMessages;
			}
			if (_14$$8) {
				break;
			}
		}
		_15$$6 = deadline > 0;
		if (_15$$6) {
			ZEPHIR_INIT_NVAR(&_16$$6);
			zephir_time(&_16$$6);
			_15$$6 = ZEPHIR_GE_LONG(&_16$$6, deadline);
		}
		if (_15$$6) {
			break;
		}
		_17$$6 = maxMemory > 0;
		if (_17$$6) {
			ZEPHIR_CALL_FUNCTION(&_18$$6, "memory_get_usage", &_19, 0, &__$true);
			zephir_check_call_status();
			_17$$6 = ZEPHIR_GE_LONG(&_18$$6, (maxMemory * 1048576));
		}
		if (_17$$6) {
			break;
		}
	}
	zephir_read_property(&_20, this_ptr, ZEND_STRL("consumer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_20, "end", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_LONG(processed);
}

/**
 * Installs graceful-shutdown signal handlers when ext-pcntl is available;
 * a no-op otherwise (the lifetime bounds still apply).
 */
PHP_METHOD(Phalcon_Queue_Consumer_Worker, installSignalHandlers)
{
	zval _0, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	if (!((zephir_function_exists_ex(ZEND_STRL("pcntl_async_signals")) == SUCCESS))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "pcntl_async_signals", NULL, 0, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "handleSignal");
	zephir_array_fast_append(&_0, &_1);
	ZVAL_LONG(&_2, 15);
	ZEPHIR_CALL_FUNCTION(NULL, "pcntl_signal", NULL, 0, &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0);
	zephir_array_fast_append(&_3, this_ptr);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "handleSignal");
	zephir_array_fast_append(&_3, &_1);
	ZVAL_LONG(&_2, 2);
	ZEPHIR_CALL_FUNCTION(NULL, "pcntl_signal", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0);
	zephir_array_fast_append(&_4, this_ptr);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "handleSignal");
	zephir_array_fast_append(&_4, &_1);
	ZVAL_LONG(&_2, 3);
	ZEPHIR_CALL_FUNCTION(NULL, "pcntl_signal", NULL, 0, &_2, &_4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

