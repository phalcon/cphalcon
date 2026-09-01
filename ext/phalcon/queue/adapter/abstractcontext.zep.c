
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"


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
 * Shared transport-session base. Every transport builds the same destination
 * value objects (GenericQueue / GenericTopic) and the same uniquely named
 * temporary queue, so those factories live here once. Concrete contexts
 * implement the transport-specific factories (consumer, producer, message,
 * subscription consumer) and the storage operations.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_AbstractContext)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter, AbstractContext, phalcon, queue_adapter_abstractcontext, phalcon_queue_adapter_abstractcontext_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(phalcon_queue_adapter_abstractcontext_ce, 1, phalcon_contracts_queue_context_ce);
	return SUCCESS;
}

/**
 * Creates a queue destination by name.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractContext, createQueue)
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
	object_init_ex(return_value, phalcon_queue_adapter_genericqueue_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 75, &queueName_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a uniquely named temporary queue.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractContext, createTemporaryQueue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, _0, _1;

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_queue_adapter_genericqueue_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "phalcon_queue_");
	ZEPHIR_CALL_FUNCTION(&_1, "uniqid", NULL, 76, &_0, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 75, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Creates a topic destination by name.
 */
PHP_METHOD(Phalcon_Queue_Adapter_AbstractContext, createTopic)
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
	object_init_ex(return_value, phalcon_queue_adapter_generictopic_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 77, &topicName_zv);
	zephir_check_call_status();
	RETURN_MM();
}

