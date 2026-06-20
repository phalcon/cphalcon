
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
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
 * In-process transport session. Owns the named FIFO queues that this
 * context's producers and consumers share.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Memory_MemoryContext)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter\\Memory, MemoryContext, phalcon, queue_adapter_memory_memorycontext, phalcon_queue_adapter_memory_memorycontext_method_entry, 0);

	/**
	 * Named queues: queue name => list of messages (FIFO).
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_queue_adapter_memory_memorycontext_ce, SL("queues"), ZEND_ACC_PROTECTED);
	phalcon_queue_adapter_memory_memorycontext_ce->create_object = zephir_init_properties_Phalcon_Queue_Adapter_Memory_MemoryContext;

	zend_class_implements(phalcon_queue_adapter_memory_memorycontext_ce, 1, phalcon_contracts_queue_context_ce);
	return SUCCESS;
}

/**
 * Closes the context and drops every stored message.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryContext, close)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("queues"), &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Creates a consumer for the given queue destination.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryContext, createConsumer)
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_exceptions_invaliddestinationexception_ce, "The Memory transport can only consume from a Queue destination", "phalcon/Queue/Adapter/Memory/MemoryContext.zep", 61);
		return;
	}
	object_init_ex(return_value, phalcon_queue_adapter_memory_memoryconsumer_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, this_ptr, destination);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a message.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryContext, createMessage)
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
	object_init_ex(return_value, phalcon_queue_adapter_memory_memorymessage_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &body_zv, &properties, &headers);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a producer.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryContext, createProducer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_queue_adapter_memory_memoryproducer_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a queue destination by name.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryContext, createQueue)
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
	object_init_ex(return_value, phalcon_queue_adapter_memory_memoryqueue_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &queueName_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a subscription consumer.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryContext, createSubscriptionConsumer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_queue_adapter_memory_memorysubscriptionconsumer_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a uniquely named temporary queue.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryContext, createTemporaryQueue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, _0, _1;

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_queue_adapter_memory_memoryqueue_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "phalcon_queue_");
	ZEPHIR_CALL_FUNCTION(&_1, "uniqid", NULL, 0, &_0, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a topic destination by name.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryContext, createTopic)
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
	object_init_ex(return_value, phalcon_queue_adapter_memory_memorytopic_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &topicName_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Removes the front message from a queue, or null when it is empty.
 * Internal transport API used by MemoryConsumer.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryContext, popMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval queueName_zv, messages, message, _0;
	zend_string *queueName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queueName_zv);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(queueName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&queueName_zv);
	ZVAL_STR_COPY(&queueName_zv, queueName);
	zephir_memory_observe(&messages);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("queues"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&messages, &_0, &queueName_zv, 0))) {
		RETURN_MM_NULL();
	}
	if (ZEPHIR_IS_EMPTY(&messages)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_MAKE_REF(&messages);
	ZEPHIR_CALL_FUNCTION(&message, "array_shift", NULL, 41, &messages);
	ZEPHIR_UNREF(&messages);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("queues"), &queueName_zv, &messages);
	RETURN_CCTOR(&message);
}

/**
 * Removes all messages from the given queue.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryContext, purgeQueue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *queue, queue_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(queue, phalcon_contracts_queue_queue_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &queue);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&_1, queue, "getqueuename", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("queues"), &_1, &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Appends a message to the back of a queue.
 * Internal transport API used by MemoryProducer.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryContext, pushMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval queueName_zv, *message, message_sub, messages, _0;
	zend_string *queueName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queueName_zv);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(queueName)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_contracts_queue_message_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	message = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&queueName_zv);
	ZVAL_STR_COPY(&queueName_zv, queueName);
	zephir_memory_observe(&messages);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("queues"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&messages, &_0, &queueName_zv, 0))) {
		ZEPHIR_INIT_NVAR(&messages);
		array_init(&messages);
	}
	zephir_array_append(&messages, message, PH_SEPARATE, "phalcon/Queue/Adapter/Memory/MemoryContext.zep", 157);
	zephir_update_property_array(this_ptr, SL("queues"), &queueName_zv, &messages);
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_Phalcon_Queue_Adapter_Memory_MemoryContext(zend_class_entry *class_type)
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("queues"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("queues"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

