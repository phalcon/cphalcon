
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
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


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
 * Sends messages to a Redis queue. Delivery delay is supported (via the
 * delayed sorted set); priority and time to live are not.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Redis_RedisProducer)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter\\Redis, RedisProducer, phalcon, queue_adapter_redis_redisproducer, phalcon_queue_adapter_redis_redisproducer_method_entry, 0);

	/**
	 * @var RedisContext
	 */
	zend_declare_property_null(phalcon_queue_adapter_redis_redisproducer_ce, SL("context"), ZEND_ACC_PROTECTED);
	/**
	 * Delivery delay in milliseconds, or null when not set.
	 *
	 * @var int | null
	 */
	zend_declare_property_null(phalcon_queue_adapter_redis_redisproducer_ce, SL("deliveryDelay"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_queue_adapter_redis_redisproducer_ce, 1, phalcon_contracts_queue_producer_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisProducer, __construct)
{
	zval *context, context_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&context_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(context, phalcon_queue_adapter_redis_rediscontext_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &context);
	zephir_update_property_zval(this_ptr, ZEND_STRL("context"), context);
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisProducer, getDeliveryDelay)
{

	RETURN_MEMBER(getThis(), "deliveryDelay");
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisProducer, getPriority)
{

	RETURN_NULL();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisProducer, getTimeToLive)
{

	RETURN_NULL();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisProducer, send)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, delay = 0;
	zval *destination, destination_sub, *message, message_sub, _0, _1, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&destination_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(destination, phalcon_contracts_queue_destination_ce)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_contracts_queue_message_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &destination, &message);
	if (UNEXPECTED(!((zephir_instance_of_ev(destination, phalcon_contracts_queue_queue_ce))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_exceptions_invaliddestinationexception_ce, "The Redis transport can only send to a Queue destination", "phalcon/Queue/Adapter/Redis/RedisProducer.zep", 75);
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("deliveryDelay"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_1) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, 0);
	} else {
		zephir_memory_observe(&_2);
		zephir_read_property(&_2, this_ptr, ZEND_STRL("deliveryDelay"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, zephir_get_intval(&_2));
	}
	delay = zephir_get_numberval(&_0);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("context"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, destination, "getqueuename", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_5, delay);
	ZEPHIR_CALL_METHOD(NULL, &_3, "pushmessage", NULL, 0, &_4, message, &_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisProducer, setDeliveryDelay)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *deliveryDelay = NULL, deliveryDelay_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&deliveryDelay_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(deliveryDelay)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &deliveryDelay);
	if (!deliveryDelay) {
		deliveryDelay = &deliveryDelay_sub;
		deliveryDelay = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(deliveryDelay) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_NULL(&_0);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, zephir_get_intval(deliveryDelay));
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("deliveryDelay"), &_0);
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisProducer, setPriority)
{
	zval *priority = NULL, priority_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&priority_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(priority)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(0, 1, &priority);
	if (!priority) {
		priority = &priority_sub;
		priority = &__$null;
	}
	if (UNEXPECTED(Z_TYPE_P(priority) != IS_NULL)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_queue_exceptions_prioritynotsupportedexception_ce, "The Redis transport does not support message priority", "phalcon/Queue/Adapter/Redis/RedisProducer.zep", 95);
		return;
	}
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisProducer, setTimeToLive)
{
	zval *timeToLive = NULL, timeToLive_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&timeToLive_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(timeToLive)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(0, 1, &timeToLive);
	if (!timeToLive) {
		timeToLive = &timeToLive_sub;
		timeToLive = &__$null;
	}
	if (UNEXPECTED(Z_TYPE_P(timeToLive) != IS_NULL)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_queue_exceptions_timetolivenotsupportedexception_ce, "The Redis transport does not support a time to live", "phalcon/Queue/Adapter/Redis/RedisProducer.zep", 106);
		return;
	}
	RETURN_THISW();
}

