
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
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
 * Shared subscription-consumer implementation. Implements the round-robin poll
 * loop that dispatches each subscribed consumer's messages to its callback; a
 * callback returning false stops consumption. The loop relies only on the
 * consumer's `receiveNoWait()`, so it is transport-agnostic. Concrete adapters
 * keep just the constructor that captures their context and poll interval.
 *
 * @phpstan-import-type queue_subscriptions from QueueTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Traits_SubscriptionConsumerTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Queue\\Adapter\\Traits, SubscriptionConsumerTrait, phalcon, queue_adapter_traits_subscriptionconsumertrait, phalcon_queue_adapter_traits_subscriptionconsumertrait_method_entry);

	/**
	 * Milliseconds slept between poll passes.
	 */
	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 200);
		zephir_declare_typed_property(phalcon_queue_adapter_traits_subscriptionconsumertrait_ce, SL("pollInterval"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	/**
	 * Subscriptions keyed by queue name: [consumer, callback].
	 *
	 * @phpstan-var queue_subscriptions
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_queue_adapter_traits_subscriptionconsumertrait_ce, SL("subscriptions"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	return SUCCESS;
}

/**
 * Polls every subscription, dispatching each message to its callback,
 * blocking up to timeout milliseconds (0 = block until a callback
 * returns false).
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_SubscriptionConsumerTrait, consume)
{
	zend_bool _8$$4, _9$$4;
	zval _4$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_12 = NULL;
	zval *timeout_param = NULL, __$true, subscription, consumer, callback, message, result, _0, _1, _2, _3$$4, *_5$$4, _7$$4, _10$$4, _11$$4;
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
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_4$$4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("subscriptions", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("pollInterval", 12, 1);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1299, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		RETURN_MM_NULL();
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1300, PH_NOISY_CC | PH_READONLY);
	sleep = (zephir_get_numberval(&_1) * 1000);
	ZEPHIR_INIT_VAR(&_2);
	zephir_microtime(&_2, &__$true);
	startTime = (zephir_get_numberval(&_2) * 1000);
	while (1) {
		ZEPHIR_OBS_NVAR(&_3$$4);
		zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_0, 1299, PH_NOISY_CC);
		zephir_get_arrval(&_4$$4, &_3$$4);
		zephir_is_iterable(&_4$$4, 0, "phalcon/Queue/Adapter/Traits/SubscriptionConsumerTrait.zep", 78);
		if (Z_TYPE_P(&_4$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4$$4), _5$$4)
			{
				ZEPHIR_INIT_NVAR(&subscription);
				ZVAL_COPY(&subscription, _5$$4);
				ZEPHIR_OBS_NVAR(&consumer);
				zephir_array_fetch_long(&consumer, &subscription, 0, PH_NOISY, "phalcon/Queue/Adapter/Traits/SubscriptionConsumerTrait.zep", 65);
				ZEPHIR_OBS_NVAR(&callback);
				zephir_array_fetch_long(&callback, &subscription, 1, PH_NOISY, "phalcon/Queue/Adapter/Traits/SubscriptionConsumerTrait.zep", 66);
				ZEPHIR_CALL_METHOD(&message, &consumer, "receivenowait", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&message) != IS_NULL) {
					ZEPHIR_CALL_FUNCTION(&result, "call_user_func", &_6, 82, &callback, &message, &consumer);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&result)) {
						RETURN_MM_NULL();
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_4$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			_8$$4 = 1;
			while (1) {
				if (_8$$4) {
					_8$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_4$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_7$$4, &_4$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_7$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&subscription, &_4$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&consumer);
					zephir_array_fetch_long(&consumer, &subscription, 0, PH_NOISY, "phalcon/Queue/Adapter/Traits/SubscriptionConsumerTrait.zep", 65);
					ZEPHIR_OBS_NVAR(&callback);
					zephir_array_fetch_long(&callback, &subscription, 1, PH_NOISY, "phalcon/Queue/Adapter/Traits/SubscriptionConsumerTrait.zep", 66);
					ZEPHIR_CALL_METHOD(&message, &consumer, "receivenowait", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&message) != IS_NULL) {
						ZEPHIR_CALL_FUNCTION(&result, "call_user_func", &_6, 82, &callback, &message, &consumer);
						zephir_check_call_status();
						if (ZEPHIR_IS_FALSE_IDENTICAL(&result)) {
							RETURN_MM_NULL();
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&subscription);
		_9$$4 = timeout > 0;
		if (_9$$4) {
			ZEPHIR_INIT_NVAR(&_10$$4);
			zephir_microtime(&_10$$4, &__$true);
			_9$$4 = ((zephir_get_numberval(&_10$$4) * 1000) - startTime) >= timeout;
		}
		if (_9$$4) {
			RETURN_MM_NULL();
		}
		ZVAL_LONG(&_11$$4, sleep);
		ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_12, 74, &_11$$4);
		zephir_check_call_status();
	}
}

/**
 * Subscribes a consumer; the callback receives each delivered message.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_SubscriptionConsumerTrait, subscribe)
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

/**
 * Removes a previously subscribed consumer.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_SubscriptionConsumerTrait, unsubscribe)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *consumer, consumer_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&consumer_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("subscriptions", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(consumer, phalcon_contracts_queue_consumer_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &consumer);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolvequeuename", NULL, 0, consumer);
	zephir_check_call_status();
	zephir_unset_property_array(this_ptr, ZEND_STRL("subscriptions"), &_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 1299, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "resolvequeuename", NULL, 0, consumer);
	zephir_check_call_status();
	zephir_array_unset(&_1, &_2, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();
}

/**
 * Removes every subscribed consumer.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_SubscriptionConsumerTrait, unsubscribeAll)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("subscriptions", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1299, &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Resolves a consumer's queue name. The `consumer` parameter is typed
 * `var` so the call is dynamic; this avoids Zephir resolving the
 * Consumer::getQueue() return type's short name in the wrong namespace.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Traits_SubscriptionConsumerTrait, resolveQueueName)
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

