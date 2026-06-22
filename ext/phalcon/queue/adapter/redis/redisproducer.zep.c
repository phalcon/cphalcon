
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
 * Sends messages to a Redis queue. Delivery delay is supported (via the
 * delayed sorted set); priority and time to live are not (the defaults from
 * AbstractProducer reject them).
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Redis_RedisProducer)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Queue\\Adapter\\Redis, RedisProducer, phalcon, queue_adapter_redis_redisproducer, phalcon_queue_adapter_abstractproducer_ce, phalcon_queue_adapter_redis_redisproducer_method_entry, 0);

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

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisProducer, send)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, delay = 0;
	zval *destination, destination_sub, *message, message_sub, _0, _1, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&destination_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(destination, phalcon_contracts_queue_destination_ce)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_contracts_queue_message_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &destination, &message);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "send to");
	ZEPHIR_CALL_CE_STATIC(NULL, phalcon_queue_adapter_queuedestinationguard_ce, "assertqueue", NULL, 0, destination, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("deliveryDelay"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_2) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_LONG(&_1, 0);
	} else {
		zephir_memory_observe(&_3);
		zephir_read_property(&_3, this_ptr, ZEND_STRL("deliveryDelay"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_LONG(&_1, zephir_get_intval(&_3));
	}
	delay = zephir_get_numberval(&_1);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("context"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, destination, "getqueuename", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_6, delay);
	ZEPHIR_CALL_METHOD(NULL, &_4, "pushmessage", NULL, 0, &_5, message, &_6);
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

