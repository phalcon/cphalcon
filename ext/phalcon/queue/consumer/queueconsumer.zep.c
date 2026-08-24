
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/time.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this component has been inspired by the queue-interop and
 * enqueue projects.
 *
 * @link    https://github.com/queue-interop/queue-interop
 * @license https://github.com/queue-interop/queue-interop/blob/master/LICENSE
 *
 * @link    https://github.com/php-enqueue/enqueue-dev
 * @license https://github.com/php-enqueue/enqueue-dev/blob/master/LICENSE
 */
/**
 * Lean consumption runner. Binds processors to queues, polls each bound queue
 * round-robin, and dispatches messages to their processors while firing the
 * lifecycle events on `Phalcon\Queue\Consumer\Events` through the events
 * manager. The long-running operational shell (lifetime, signals) lives in
 * `Phalcon\Queue\Consumer\Worker`, which drives `consumeOnce()` and shares the
 * stop signal through `stop()` / `isStopRequested()`.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Consumer_QueueConsumer)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Queue\\Consumer, QueueConsumer, phalcon, queue_consumer_queueconsumer, phalcon_events_abstracteventsaware_ce, phalcon_queue_consumer_queueconsumer_method_entry, 0);

	/**
	 * Bound processors keyed by queue name.
	 *
	 * @var array<string, BoundProcessor>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_queue_consumer_queueconsumer_ce, SL("bindings"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_queue_consumer_queueconsumer_ce, SL("context"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Contracts\\Queue\\Context"));
	}

	/**
	 * Milliseconds slept between poll passes when nothing was received.
	 */
	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 200);
		zephir_declare_typed_property(phalcon_queue_consumer_queueconsumer_ce, SL("pollInterval"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_queue_consumer_queueconsumer_ce, SL("shouldStop"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	zend_class_implements(phalcon_queue_consumer_queueconsumer_ce, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, __construct)
{
	zval *context, context_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&context_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("context", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(context, phalcon_contracts_queue_context_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &context);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1299, context);
}

/**
 * Binds a processor to a queue. Returns self for chaining.
 */
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, bind)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *queue, queue_sub, *processor, processor_sub, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue_sub);
	ZVAL_UNDEF(&processor_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("context", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(queue, phalcon_contracts_queue_queue_ce)
		Z_PARAM_OBJECT_OF_CLASS(processor, phalcon_contracts_queue_processor_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &queue, &processor);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_queue_consumer_boundprocessor_ce);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 1299, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "createconsumer", NULL, 0, queue);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, queue, processor, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, queue, "getqueuename", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("bindings"), &_3, &_0);
	RETURN_THIS();
}

/**
 * Runs the consumption loop, blocking up to timeout milliseconds (0 =
 * block until stopped). The simple loop; production setups use Worker.
 */
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, consume)
{
	zend_bool _4$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *timeout_param = NULL, __$true, _0, _1, _3$$4, _5$$4;
	zend_long timeout, ZEPHIR_LAST_CALL_STATUS, startTime = 0;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("shouldStop", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(timeout)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &timeout_param);
	if (!timeout_param) {
		timeout = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "start", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_microtime(&_1, &__$true);
	startTime = (zephir_get_numberval(&_1) * 1000);
	while (1) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "consumeonce", &_2, 0);
		zephir_check_call_status();
		zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_0, 1300, PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_3$$4)) {
			break;
		}
		_4$$4 = timeout > 0;
		if (_4$$4) {
			ZEPHIR_INIT_NVAR(&_5$$4);
			zephir_microtime(&_5$$4, &__$true);
			_4$$4 = ((zephir_get_numberval(&_5$$4) * 1000) - startTime) >= timeout;
		}
		if (_4$$4) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "end", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Polls every bound queue once, dispatching any messages found. Returns
 * the number of messages processed in this pass, so callers (the Worker)
 * can apply a message-count limit across several bound queues.
 */
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, consumeOnce)
{
	zend_bool _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, binding, consumer, message, _0, *_1, _7, _2$$3, _3$$3, _5$$3, _9$$7, _10$$7, _11$$7, _12$$11, _13$$11;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, processed = 0;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&binding);
	ZVAL_UNDEF(&consumer);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("bindings", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("shouldStop", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("pollInterval", 12, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	processed = 0;
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1301, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Queue/Consumer/QueueConsumer.zep", 138);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&binding);
			ZVAL_COPY(&binding, _1);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "queue:beforeReceive");
			ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "firemanagerevent", &_4, 0, &_3$$3, &binding);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_2$$3)) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&consumer, &binding, "getconsumer", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&message, &consumer, "receivenowait", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&message) == IS_NULL) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "queue:afterReceive");
			ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "firemanagerevent", &_4, 0, &_3$$3, &message);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_5$$3)) {
				if (1) {
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1300, &__$true);
				} else {
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1300, &__$false);
				}
				RETURN_MM_LONG(processed);
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "process", &_6, 0, &binding, &message);
			zephir_check_call_status();
			processed++;
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_7, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&binding, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_10$$7);
				ZVAL_STRING(&_10$$7, "queue:beforeReceive");
				ZEPHIR_CALL_METHOD(&_9$$7, this_ptr, "firemanagerevent", &_4, 0, &_10$$7, &binding);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_9$$7)) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&consumer, &binding, "getconsumer", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&message, &consumer, "receivenowait", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&message) == IS_NULL) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_10$$7);
				ZVAL_STRING(&_10$$7, "queue:afterReceive");
				ZEPHIR_CALL_METHOD(&_11$$7, this_ptr, "firemanagerevent", &_4, 0, &_10$$7, &message);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_11$$7)) {
					if (1) {
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1300, &__$true);
					} else {
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1300, &__$false);
					}
					RETURN_MM_LONG(processed);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "process", &_6, 0, &binding, &message);
				zephir_check_call_status();
				processed++;
		}
	}
	ZEPHIR_INIT_NVAR(&binding);
	if (processed == 0) {
		zephir_read_property_cached(&_12$$11, this_ptr, _zephir_prop_2, 1302, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_13$$11, (zephir_get_numberval(&_12$$11) * 1000));
		ZEPHIR_CALL_FUNCTION(NULL, "usleep", NULL, 74, &_13$$11);
		zephir_check_call_status();
	}
	RETURN_MM_LONG(processed);
}

/**
 * Fires the `queue:afterEnd` event. Called once the loop exits.
 */
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, end)
{
	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "queue:afterEnd");
	ZVAL_NULL(&_1);
	ZVAL_BOOL(&_2, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Whether a stop has been requested (by a signal, `stop()`, or an
 * `afterReceive` listener returning false).
 */
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, isStopRequested)
{

	RETURN_MEMBER(getThis(), "shouldStop");
}

/**
 * Sets the poll interval (in milliseconds).
 */
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, setPollInterval)
{
	zval *pollInterval_param = NULL, _0;
	zend_long pollInterval;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("pollInterval", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(pollInterval)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &pollInterval_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, pollInterval);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1302, &_0);
}

/**
 * Resets the stop flag and fires `queue:beforeStart`. Returns false when a
 * listener cancels the start.
 */
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, start)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, __$false, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("shouldStop", 10, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1300, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1300, &__$false);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "queue:beforeStart");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "firemanagerevent", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_0));
}

/**
 * Requests the consumption loop to stop after the current message.
 */
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, stop)
{
	zval __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("shouldStop", 10, 1);
	}
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1300, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1300, &__$false);
	}
}

/**
 * Applies a processor result (ACK / REJECT / REQUEUE) to the message.
 */
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, handleResult)
{
	zval outcome, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *consumer, consumer_sub, *message, message_sub, *result, result_sub, _1$$4, _2$$5;

	ZVAL_UNDEF(&consumer_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&result_sub);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&outcome);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(consumer, phalcon_contracts_queue_consumer_ce)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_contracts_queue_message_ce)
		Z_PARAM_ZVAL(result)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &consumer, &message, &result);
	zephir_cast_to_string(&_0, result);
	ZEPHIR_CPY_WRT(&outcome, &_0);
	if (ZEPHIR_IS_STRING_IDENTICAL(&outcome, "enqueue.ack")) {
		ZEPHIR_CALL_METHOD(NULL, consumer, "acknowledge", NULL, 0, message);
		zephir_check_call_status();
	} else if (ZEPHIR_IS_STRING_IDENTICAL(&outcome, "enqueue.requeue")) {
		ZVAL_BOOL(&_1$$4, 1);
		ZEPHIR_CALL_METHOD(NULL, consumer, "reject", NULL, 0, message, &_1$$4);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(&_2$$5, 0);
		ZEPHIR_CALL_METHOD(NULL, consumer, "reject", NULL, 0, message, &_2$$5);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Runs the processor for one message, firing the process events and
 * applying the outcome. A processor exception fires
 * `queue:processorException` and rejects the message.
 */
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, process)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *binding, binding_sub, *message, message_sub, consumer, processor, result, exception, _0, _1, _2$$4, _3$$4, _4$$4, _5$$5, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&binding_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&consumer);
	ZVAL_UNDEF(&processor);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("context", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(binding, phalcon_queue_consumer_boundprocessor_ce)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_contracts_queue_message_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &binding, &message);
	ZEPHIR_CALL_METHOD(&consumer, binding, "getconsumer", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&processor, binding, "getprocessor", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "queue:beforeProcess");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "firemanagerevent", NULL, 0, &_1, message);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		RETURN_MM_NULL();
	}

	/* try_start_1: */

		zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_0, 1299, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&result, &processor, "process", NULL, 0, message, &_2$$4);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "handleresult", NULL, 0, &consumer, message, &result);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "queue:afterProcess");
		ZVAL_BOOL(&_4$$4, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_3$$4, message, &_4$$4);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_OBJ(&_1, EG(exception));
		Z_ADDREF_P(&_1);
		if (zephir_is_instance_of(&_1, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&exception, &_1);
			ZEPHIR_INIT_VAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "queue:processorException");
			ZVAL_BOOL(&_6$$5, 0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_5$$5, &exception, &_6$$5);
			zephir_check_call_status();
			ZVAL_BOOL(&_6$$5, 0);
			ZEPHIR_CALL_METHOD(NULL, &consumer, "reject", NULL, 0, message, &_6$$5);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();
}

