
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
 * Receives messages from a single in-process queue. `receive()` is the
 * polling loop inherited from AbstractConsumer.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Memory_MemoryConsumer)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Queue\\Adapter\\Memory, MemoryConsumer, phalcon, queue_adapter_memory_memoryconsumer, phalcon_queue_adapter_abstractconsumer_ce, phalcon_queue_adapter_memory_memoryconsumer_method_entry, 0);

	/**
	 * @var MemoryContext
	 */
	zend_declare_property_null(phalcon_queue_adapter_memory_memoryconsumer_ce, SL("context"), ZEND_ACC_PROTECTED);
	/**
	 * @var QueueInterface
	 */
	zend_declare_property_null(phalcon_queue_adapter_memory_memoryconsumer_ce, SL("queue"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * MemoryConsumer constructor.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryConsumer, __construct)
{
	zval *context, context_sub, *queue, queue_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&context_sub);
	ZVAL_UNDEF(&queue_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(context, phalcon_queue_adapter_memory_memorycontext_ce)
		Z_PARAM_OBJECT_OF_CLASS(queue, phalcon_contracts_queue_queue_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &context, &queue);
	zephir_update_property_zval(this_ptr, ZEND_STRL("context"), context);
	zephir_update_property_zval(this_ptr, ZEND_STRL("queue"), queue);
}

/**
 * No-op: a received message has already been removed from the queue.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryConsumer, acknowledge)
{
	zval *message, message_sub;

	ZVAL_UNDEF(&message_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_contracts_queue_message_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &message);
}

/**
 * Returns the queue this consumer reads from.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryConsumer, getQueue)
{

	RETURN_MEMBER(getThis(), "queue");
}

/**
 * Removes and returns the next message, or null when the queue is empty.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryConsumer, receiveNoWait)
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

	zephir_read_property(&_0, this_ptr, ZEND_STRL("context"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("queue"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "getqueuename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "popmessage", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Rejects the message. When requeue is true it is put back on the queue.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryConsumer, reject)
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
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("context"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("queue"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2$$3, &_1$$3, "getqueuename", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "pushmessage", NULL, 0, &_2$$3, message);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

