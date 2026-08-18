
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
#include "kernel/fcall.h"
#include "kernel/time.h"
#include "kernel/operators.h"


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
 * Receives messages from a single Redis queue. `receive()` is overridden to
 * use the native blocking BRPOP (in one-second chunks, so due delayed
 * messages keep getting promoted) instead of the inherited polling loop.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Redis_RedisConsumer)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Queue\\Adapter\\Redis, RedisConsumer, phalcon, queue_adapter_redis_redisconsumer, phalcon_queue_adapter_abstractconsumer_ce, phalcon_queue_adapter_redis_redisconsumer_method_entry, 0);

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_queue_adapter_redis_redisconsumer_ce, SL("context"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Queue\\Adapter\\Redis\\RedisContext"));
	}

	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisConsumer, __construct)
{
	zval *context, context_sub, *queue, queue_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&context_sub);
	ZVAL_UNDEF(&queue_sub);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("context", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("queue", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(context, phalcon_queue_adapter_redis_rediscontext_ce)
		Z_PARAM_OBJECT_OF_CLASS(queue, phalcon_contracts_queue_queue_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &context, &queue);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1273, context);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1274, queue);
}

/**
 * No-op: a received message has already been removed from the queue.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisConsumer, acknowledge)
{
	zval *message, message_sub;

	ZVAL_UNDEF(&message_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_contracts_queue_message_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &message);
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisConsumer, receive)
{
	zend_bool _4$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *timeout_param = NULL, __$true, message, queueName, _0, _1$$3, _2$$4, _3$$4, _5$$4;
	zend_long timeout, ZEPHIR_LAST_CALL_STATUS, deadline = 0;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&queueName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("queue", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("context", 7, 1);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1274, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&queueName, &_0, "getqueuename", NULL, 0);
	zephir_check_call_status();
	deadline = 0;
	if (timeout > 0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_microtime(&_1$$3, &__$true);
		deadline = ((zephir_get_numberval(&_1$$3) * 1000) + timeout);
	}
	while (1) {
		zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_1, 1273, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_3$$4, 1);
		ZEPHIR_CALL_METHOD(&message, &_2$$4, "blockingpop", NULL, 0, &queueName, &_3$$4);
		zephir_check_call_status();
		if (Z_TYPE_P(&message) != IS_NULL) {
			RETURN_CCTOR(&message);
		}
		_4$$4 = deadline > 0;
		if (_4$$4) {
			ZEPHIR_INIT_NVAR(&_5$$4);
			zephir_microtime(&_5$$4, &__$true);
			_4$$4 = (zephir_get_numberval(&_5$$4) * 1000) >= deadline;
		}
		if (_4$$4) {
			RETURN_MM_NULL();
		}
	}
	RETURN_MM_NULL();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisConsumer, receiveNoWait)
{
	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("context", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("queue", 5, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1273, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1274, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "getqueuename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "popmessage", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisConsumer, reject)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool requeue;
	zval *message, message_sub, *requeue_param = NULL, _0$$3, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("context", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("queue", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_contracts_queue_message_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(requeue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &message, &requeue_param);
	if (!requeue_param) {
		requeue = 0;
	} else {
		}
	if (requeue) {
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 1273, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 1274, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2$$3, &_1$$3, "getqueuename", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "pushmessage", NULL, 0, &_2$$3, message);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

