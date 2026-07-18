
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
 * Binds a processor to a queue, together with the consumer that reads it.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Consumer_BoundProcessor)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Consumer, BoundProcessor, phalcon, queue_consumer_boundprocessor, phalcon_queue_consumer_boundprocessor_method_entry, 0);

	/**
	 * @var ConsumerInterface
	 */
	zend_declare_property_null(phalcon_queue_consumer_boundprocessor_ce, SL("consumer"), ZEND_ACC_PROTECTED);
	/**
	 * @var ProcessorInterface
	 */
	zend_declare_property_null(phalcon_queue_consumer_boundprocessor_ce, SL("processor"), ZEND_ACC_PROTECTED);
	/**
	 * @var QueueInterface
	 */
	zend_declare_property_null(phalcon_queue_consumer_boundprocessor_ce, SL("queue"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Consumer_BoundProcessor, __construct)
{
	zval *queue, queue_sub, *processor, processor_sub, *consumer, consumer_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue_sub);
	ZVAL_UNDEF(&processor_sub);
	ZVAL_UNDEF(&consumer_sub);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("queue", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("processor", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("consumer", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(queue, phalcon_contracts_queue_queue_ce)
		Z_PARAM_OBJECT_OF_CLASS(processor, phalcon_contracts_queue_processor_ce)
		Z_PARAM_OBJECT_OF_CLASS(consumer, phalcon_contracts_queue_consumer_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &queue, &processor, &consumer);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1269, queue);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1270, processor);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1271, consumer);
}

PHP_METHOD(Phalcon_Queue_Consumer_BoundProcessor, getConsumer)
{

	RETURN_MEMBER(getThis(), "consumer");
}

PHP_METHOD(Phalcon_Queue_Consumer_BoundProcessor, getProcessor)
{

	RETURN_MEMBER(getThis(), "processor");
}

PHP_METHOD(Phalcon_Queue_Consumer_BoundProcessor, getQueue)
{

	RETURN_MEMBER(getThis(), "queue");
}

