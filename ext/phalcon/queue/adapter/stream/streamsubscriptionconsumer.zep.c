
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/time.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


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
 * Consumes from several filesystem queues at once, round-robin polling each
 * subscribed consumer and dispatching messages to its callback. A callback
 * returning false stops consumption.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Stream_StreamSubscriptionConsumer)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter\\Stream, StreamSubscriptionConsumer, phalcon, queue_adapter_stream_streamsubscriptionconsumer, phalcon_queue_adapter_stream_streamsubscriptionconsumer_method_entry, 0);

	/**
	 * @var StreamContext
	 */
	zend_declare_property_null(phalcon_queue_adapter_stream_streamsubscriptionconsumer_ce, SL("context"), ZEND_ACC_PROTECTED);
	/**
	 * Milliseconds slept between poll passes.
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_queue_adapter_stream_streamsubscriptionconsumer_ce, SL("pollInterval"), 200, ZEND_ACC_PROTECTED);
	/**
	 * Subscriptions keyed by queue name: [consumer, callback].
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_queue_adapter_stream_streamsubscriptionconsumer_ce, SL("subscriptions"), ZEND_ACC_PROTECTED);
	phalcon_queue_adapter_stream_streamsubscriptionconsumer_ce->create_object = zephir_init_properties_Phalcon_Queue_Adapter_Stream_StreamSubscriptionConsumer;

	zend_class_implements(phalcon_queue_adapter_stream_streamsubscriptionconsumer_ce, 1, phalcon_contracts_queue_subscriptionconsumer_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamSubscriptionConsumer, __construct)
{
	zval *context, context_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&context_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(context, phalcon_queue_adapter_stream_streamcontext_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &context);
	zephir_update_property_zval(this_ptr, ZEND_STRL("context"), context);
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamSubscriptionConsumer, consume)
{
	zend_bool _7$$4, _8$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_11 = NULL;
	zval *timeout_param = NULL, __$true, subscription, consumer, callback, message, result, _0, _1, _2, _3$$4, *_4$$4, _6$$4, _9$$4, _10$$4;
	zend_long timeout, ZEPHIR_LAST_CALL_STATUS, startTime = 0, sleep = 0;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&subscription);
	ZVAL_UNDEF(&consumer);
	ZVAL_UNDEF(&callback);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("subscriptions"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("pollInterval"), PH_NOISY_CC | PH_READONLY);
	sleep = (zephir_get_numberval(&_1) * 1000);
	ZEPHIR_INIT_VAR(&_2);
	zephir_microtime(&_2, &__$true);
	startTime = (zephir_get_numberval(&_2) * 1000);
	while (1) {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("subscriptions"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_3$$4, 0, "phalcon/Queue/Adapter/Stream/StreamSubscriptionConsumer.zep", 83);
		if (Z_TYPE_P(&_3$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3$$4), _4$$4)
			{
				ZEPHIR_INIT_NVAR(&subscription);
				ZVAL_COPY(&subscription, _4$$4);
				ZEPHIR_OBS_NVAR(&consumer);
				zephir_array_fetch_long(&consumer, &subscription, 0, PH_NOISY, "phalcon/Queue/Adapter/Stream/StreamSubscriptionConsumer.zep", 70);
				ZEPHIR_OBS_NVAR(&callback);
				zephir_array_fetch_long(&callback, &subscription, 1, PH_NOISY, "phalcon/Queue/Adapter/Stream/StreamSubscriptionConsumer.zep", 71);
				ZEPHIR_CALL_METHOD(&message, &consumer, "receivenowait", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&message) != IS_NULL) {
					ZEPHIR_CALL_FUNCTION(&result, "call_user_func", &_5, 353, &callback, &message, &consumer);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&result)) {
						RETURN_MM_NULL();
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			_7$$4 = 1;
			while (1) {
				if (_7$$4) {
					_7$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_3$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_6$$4, &_3$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&subscription, &_3$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&consumer);
					zephir_array_fetch_long(&consumer, &subscription, 0, PH_NOISY, "phalcon/Queue/Adapter/Stream/StreamSubscriptionConsumer.zep", 70);
					ZEPHIR_OBS_NVAR(&callback);
					zephir_array_fetch_long(&callback, &subscription, 1, PH_NOISY, "phalcon/Queue/Adapter/Stream/StreamSubscriptionConsumer.zep", 71);
					ZEPHIR_CALL_METHOD(&message, &consumer, "receivenowait", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&message) != IS_NULL) {
						ZEPHIR_CALL_FUNCTION(&result, "call_user_func", &_5, 353, &callback, &message, &consumer);
						zephir_check_call_status();
						if (ZEPHIR_IS_FALSE_IDENTICAL(&result)) {
							RETURN_MM_NULL();
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&subscription);
		_8$$4 = timeout > 0;
		if (_8$$4) {
			ZEPHIR_INIT_NVAR(&_9$$4);
			zephir_microtime(&_9$$4, &__$true);
			_8$$4 = ((zephir_get_numberval(&_9$$4) * 1000) - startTime) >= timeout;
		}
		if (_8$$4) {
			RETURN_MM_NULL();
		}
		ZVAL_LONG(&_10$$4, sleep);
		ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_11, 74, &_10$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamSubscriptionConsumer, subscribe)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *consumer, consumer_sub, *callback, callback_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&consumer_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(consumer, phalcon_contracts_queue_consumer_ce)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &consumer, &callback);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, consumer);
	zephir_array_fast_append(&_0, callback);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "resolvequeuename", NULL, 0, consumer);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("subscriptions"), &_1, &_0);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamSubscriptionConsumer, unsubscribe)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *consumer, consumer_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&consumer_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(consumer, phalcon_contracts_queue_consumer_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &consumer);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolvequeuename", NULL, 0, consumer);
	zephir_check_call_status();
	zephir_unset_property_array(this_ptr, ZEND_STRL("subscriptions"), &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("subscriptions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "resolvequeuename", NULL, 0, consumer);
	zephir_check_call_status();
	zephir_array_unset(&_1, &_2, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamSubscriptionConsumer, unsubscribeAll)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("subscriptions"), &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Resolves a consumer's queue name. The `consumer` parameter is typed
 * `var` so the call is dynamic; this avoids Zephir resolving the
 * Consumer::getQueue() return type's short name in the wrong namespace.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamSubscriptionConsumer, resolveQueueName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *consumer, consumer_sub, _0;

	ZVAL_UNDEF(&consumer_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(consumer)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &consumer);
	ZEPHIR_CALL_METHOD(&_0, consumer, "getqueue", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getqueuename", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Queue_Adapter_Stream_StreamSubscriptionConsumer(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("subscriptions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("subscriptions"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

