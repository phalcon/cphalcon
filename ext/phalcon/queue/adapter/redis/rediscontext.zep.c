
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/time.h"
#include "kernel/string.h"


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
 * Redis transport session (ext-redis). Each queue is a Redis list; messages
 * are LPUSHed on send and RPOP/BRPOPed on receive, giving FIFO delivery.
 * Delayed messages live in a companion sorted set (`<key>:delayed`) scored by
 * their due time in milliseconds, and are promoted into the list once due.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Redis_RedisContext)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter\\Redis, RedisContext, phalcon, queue_adapter_redis_rediscontext, phalcon_queue_adapter_redis_rediscontext_method_entry, 0);

	/**
	 * Milliseconds slept between poll passes by a subscription consumer.
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_queue_adapter_redis_rediscontext_ce, SL("pollInterval"), 200, ZEND_ACC_PROTECTED);
	/**
	 * Key prefix applied to every queue (and its delayed companion set).
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_queue_adapter_redis_rediscontext_ce, SL("prefix"), "phalcon_queue:", ZEND_ACC_PROTECTED);
	/**
	 * The connected ext-redis client.
	 *
	 * @var \Redis
	 */
	zend_declare_property_null(phalcon_queue_adapter_redis_rediscontext_ce, SL("redis"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_queue_adapter_redis_rediscontext_ce, 1, phalcon_contracts_queue_context_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long pollInterval;
	zend_string *prefix = NULL;
	zval *redis, redis_sub, prefix_zv, *pollInterval_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&redis_sub);
	ZVAL_UNDEF(&prefix_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(redis)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(prefix)
		Z_PARAM_LONG(pollInterval)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	redis = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		pollInterval_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (!prefix) {
		prefix = zend_string_init(ZEND_STRL("phalcon_queue:"), 0);
		zephir_memory_observe(&prefix_zv);
		ZVAL_STR(&prefix_zv, prefix);
	} else {
		zephir_memory_observe(&prefix_zv);
	ZVAL_STR_COPY(&prefix_zv, prefix);
	}
	if (!pollInterval_param) {
		pollInterval = 200;
	} else {
		}
	zephir_update_property_zval(this_ptr, ZEND_STRL("redis"), redis);
	zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &prefix_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, pollInterval);
	zephir_update_property_zval(this_ptr, ZEND_STRL("pollInterval"), &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Blocking pop from the back of a queue list. Promotes any due delayed
 * messages first, then blocks up to timeout seconds. Internal transport
 * API used by RedisConsumer.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, blockingPop)
{
	zend_bool _4;
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long timeout, ZEPHIR_LAST_CALL_STATUS;
	zval queueName_zv, *timeout_param = NULL, result, _0, _2, _3, _5$$3;
	zend_string *queueName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queueName_zv);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(queueName)
		Z_PARAM_LONG(timeout)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	timeout_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&queueName_zv);
	ZVAL_STR_COPY(&queueName_zv, queueName);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "promote", NULL, 0, &queueName_zv);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("redis"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "listkey", NULL, 0, &queueName_zv);
	zephir_check_call_status();
	zephir_array_fast_append(&_1, &_2);
	ZVAL_LONG(&_3, timeout);
	ZEPHIR_CALL_METHOD(&result, &_0, "brpop", NULL, 0, &_1, &_3);
	zephir_check_call_status();
	_4 = Z_TYPE_P(&result) == IS_ARRAY;
	if (_4) {
		_4 = zephir_fast_count_int(&result) >= 2;
	}
	if (_4) {
		zephir_array_fetch_long(&_5$$3, &result, 1, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Redis/RedisContext.zep", 82);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "unserializemessage", NULL, 0, &_5$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, close)
{

}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, createConsumer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *destination, destination_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&destination_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(destination, phalcon_contracts_queue_destination_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &destination);
	if (UNEXPECTED(!((zephir_instance_of_ev(destination, phalcon_contracts_queue_queue_ce))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_exceptions_invaliddestinationexception_ce, "The Redis transport can only consume from a Queue destination", "phalcon/Queue/Adapter/Redis/RedisContext.zep", 97);
		return;
	}
	object_init_ex(return_value, phalcon_queue_adapter_redis_redisconsumer_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, this_ptr, destination);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, createMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval properties, headers;
	zval body_zv, *properties_param = NULL, *headers_param = NULL;
	zend_string *body = NULL;

	ZVAL_UNDEF(&body_zv);
	ZVAL_UNDEF(&properties);
	ZVAL_UNDEF(&headers);
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(body)
		ZEPHIR_Z_PARAM_ARRAY(properties, properties_param)
		ZEPHIR_Z_PARAM_ARRAY(headers, headers_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		properties_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		headers_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (!body) {
		body = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&body_zv);
		ZVAL_STR(&body_zv, body);
	} else {
		zephir_memory_observe(&body_zv);
	ZVAL_STR_COPY(&body_zv, body);
	}
	if (!properties_param) {
		ZEPHIR_INIT_VAR(&properties);
		array_init(&properties);
	} else {
		zephir_get_arrval(&properties, properties_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}
	object_init_ex(return_value, phalcon_queue_adapter_redis_redismessage_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &body_zv, &properties, &headers);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, createProducer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_queue_adapter_redis_redisproducer_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, createQueue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval queueName_zv;
	zend_string *queueName = NULL;

	ZVAL_UNDEF(&queueName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(queueName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&queueName_zv);
	ZVAL_STR_COPY(&queueName_zv, queueName);
	object_init_ex(return_value, phalcon_queue_adapter_redis_redisqueue_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &queueName_zv);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, createSubscriptionConsumer)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_queue_adapter_redis_redissubscriptionconsumer_ce);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pollInterval"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, this_ptr, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, createTemporaryQueue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, _0, _1;

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_queue_adapter_redis_redisqueue_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "phalcon_queue_");
	ZEPHIR_CALL_FUNCTION(&_1, "uniqid", NULL, 0, &_0, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, createTopic)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval topicName_zv;
	zend_string *topicName = NULL;

	ZVAL_UNDEF(&topicName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(topicName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&topicName_zv);
	ZVAL_STR_COPY(&topicName_zv, topicName);
	object_init_ex(return_value, phalcon_queue_adapter_redis_redistopic_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &topicName_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Non-blocking pop from the back of a queue list, or null when empty.
 * Promotes any due delayed messages first. Internal transport API used
 * by RedisConsumer.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, popMessage)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval queueName_zv, payload, _0, _1;
	zend_string *queueName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queueName_zv);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(queueName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&queueName_zv);
	ZVAL_STR_COPY(&queueName_zv, queueName);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "promote", NULL, 0, &queueName_zv);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("redis"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "listkey", NULL, 0, &queueName_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&payload, &_0, "rpop", NULL, 0, &_1);
	zephir_check_call_status();
	_2 = ZEPHIR_IS_FALSE_IDENTICAL(&payload);
	if (!(_2)) {
		_2 = Z_TYPE_P(&payload) == IS_NULL;
	}
	if (_2) {
		RETURN_MM_NULL();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "unserializemessage", NULL, 0, &payload);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, purgeQueue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *queue, queue_sub, queueName, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue_sub);
	ZVAL_UNDEF(&queueName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(queue, phalcon_contracts_queue_queue_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &queue);
	ZEPHIR_CALL_METHOD(&queueName, queue, "getqueuename", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("redis"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "listkey", NULL, 0, &queueName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "del", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("redis"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "delayedkey", NULL, 0, &queueName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_2, "del", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Sends a message to a queue. With a positive delay (milliseconds) the
 * message is parked in the delayed set; otherwise it is pushed onto the
 * front of the list. Internal transport API used by RedisProducer.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, pushMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long delay, ZEPHIR_LAST_CALL_STATUS, score = 0;
	zval queueName_zv, *message, message_sub, *delay_param = NULL, __$true, payload, member, _6, _7, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3;
	zend_string *queueName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queueName_zv);
	ZVAL_UNDEF(&message_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&member);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(queueName)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_contracts_queue_message_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(delay)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	message = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		delay_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&queueName_zv);
	ZVAL_STR_COPY(&queueName_zv, queueName);
	if (!delay_param) {
		delay = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(&payload, this_ptr, "serializemessage", NULL, 0, message);
	zephir_check_call_status();
	if (delay > 0) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "now", NULL, 0);
		zephir_check_call_status();
		score = (zephir_get_numberval(&_0$$3) + delay);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "uniqid", NULL, 0, &_1$$3, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&member);
		ZEPHIR_CONCAT_VSV(&member, &_2$$3, "|", &payload);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("redis"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "delayedkey", NULL, 0, &queueName_zv);
		zephir_check_call_status();
		ZVAL_LONG(&_5$$3, score);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "zadd", NULL, 0, &_4$$3, &_5$$3, &member);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("redis"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "listkey", NULL, 0, &queueName_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_6, "lpush", NULL, 0, &_7, &payload);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, delayedKey)
{
	zval queueName_zv, _0;
	zend_string *queueName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queueName_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(queueName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&queueName_zv, queueName);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VVS(return_value, &_0, &queueName_zv, ":delayed");
	return;
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, listKey)
{
	zval queueName_zv, _0;
	zend_string *queueName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queueName_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(queueName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&queueName_zv, queueName);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VV(return_value, &_0, &queueName_zv);
	return;
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, now)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, _0;

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	zephir_microtime(&_0, &__$true);
	RETURN_MM_LONG((zephir_get_numberval(&_0) * 1000));
}

/**
 * Moves every due message from the delayed set onto the queue list. The
 * ZREM acts as an atomic claim, so a message promoted by one process is
 * never promoted again by another.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, promote)
{
	zend_bool _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval queueName_zv, delayedKey, listKey, due, member, payload, position, _0, _1, _2, *_3, _9, _4$$4, _5$$4, _6$$5, _7$$5, _8$$5, _11$$6, _12$$6, _13$$7, _14$$7, _15$$7;
	zend_string *queueName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queueName_zv);
	ZVAL_UNDEF(&delayedKey);
	ZVAL_UNDEF(&listKey);
	ZVAL_UNDEF(&due);
	ZVAL_UNDEF(&member);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(queueName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&queueName_zv);
	ZVAL_STR_COPY(&queueName_zv, queueName);
	ZEPHIR_CALL_METHOD(&delayedKey, this_ptr, "delayedkey", NULL, 0, &queueName_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&listKey, this_ptr, "listkey", NULL, 0, &queueName_zv);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("redis"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "now", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(&due, &_0, "zrangebyscore", NULL, 0, &delayedKey, &_2, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&due) != IS_ARRAY) {
		RETURN_MM_NULL();
	}
	zephir_is_iterable(&due, 0, "phalcon/Queue/Adapter/Redis/RedisContext.zep", 227);
	if (Z_TYPE_P(&due) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&due), _3)
		{
			ZEPHIR_INIT_NVAR(&member);
			ZVAL_COPY(&member, _3);
			zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("redis"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_5$$4, &_4$$4, "zrem", NULL, 0, &delayedKey, &member);
			zephir_check_call_status();
			if (ZEPHIR_GT_LONG(&_5$$4, 0)) {
				ZEPHIR_INIT_NVAR(&_6$$5);
				ZVAL_STRING(&_6$$5, "|");
				ZEPHIR_INIT_NVAR(&position);
				zephir_fast_strpos(&position, &member, &_6$$5, 0 );
				ZVAL_LONG(&_7$$5, (zephir_get_numberval(&position) + 1));
				ZEPHIR_INIT_NVAR(&payload);
				zephir_substr(&payload, &member, zephir_get_intval(&_7$$5), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				zephir_read_property(&_8$$5, this_ptr, ZEND_STRL("redis"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &_8$$5, "lpush", NULL, 0, &listKey, &payload);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &due, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &due, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, &due, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&member, &due, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_11$$6, this_ptr, ZEND_STRL("redis"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_12$$6, &_11$$6, "zrem", NULL, 0, &delayedKey, &member);
				zephir_check_call_status();
				if (ZEPHIR_GT_LONG(&_12$$6, 0)) {
					ZEPHIR_INIT_NVAR(&_13$$7);
					ZVAL_STRING(&_13$$7, "|");
					ZEPHIR_INIT_NVAR(&position);
					zephir_fast_strpos(&position, &member, &_13$$7, 0 );
					ZVAL_LONG(&_14$$7, (zephir_get_numberval(&position) + 1));
					ZEPHIR_INIT_NVAR(&payload);
					zephir_substr(&payload, &member, zephir_get_intval(&_14$$7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					zephir_read_property(&_15$$7, this_ptr, ZEND_STRL("redis"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_15$$7, "lpush", NULL, 0, &listKey, &payload);
					zephir_check_call_status();
				}
		}
	}
	ZEPHIR_INIT_NVAR(&member);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, serializeMessage)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, _1;

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_contracts_queue_message_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &message);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_CALL_METHOD(&_1, message, "getbody", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("body"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, message, "getproperties", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("properties"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, message, "getheaders", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("headers"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 23, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, unserializeMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval payload_zv, data, _0, _1, _2;
	zend_string *payload = NULL;

	ZVAL_UNDEF(&payload_zv);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(payload)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&payload_zv);
	ZVAL_STR_COPY(&payload_zv, payload);
	ZEPHIR_CALL_FUNCTION(&data, "unserialize", NULL, 28, &payload_zv);
	zephir_check_call_status();
	if (Z_TYPE_P(&data) != IS_ARRAY) {
		RETURN_MM_NULL();
	}
	object_init_ex(return_value, phalcon_queue_adapter_redis_redismessage_ce);
	zephir_array_fetch_string(&_0, &data, SL("body"), PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Redis/RedisContext.zep", 250);
	zephir_array_fetch_string(&_1, &data, SL("properties"), PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Redis/RedisContext.zep", 250);
	zephir_array_fetch_string(&_2, &data, SL("headers"), PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Redis/RedisContext.zep", 250);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

