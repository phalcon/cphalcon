
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
 * Consumes from several in-process queues at once. The round-robin poll loop
 * lives in AbstractSubscriptionConsumer.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Memory_MemorySubscriptionConsumer)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Queue\\Adapter\\Memory, MemorySubscriptionConsumer, phalcon, queue_adapter_memory_memorysubscriptionconsumer, phalcon_queue_adapter_abstractsubscriptionconsumer_ce, phalcon_queue_adapter_memory_memorysubscriptionconsumer_method_entry, 0);

	/**
	 * Retained for transports that may later need it for a native multi-queue
	 * receive; the shared poll loop does not use it.
	 *
	 * @var MemoryContext
	 */
	zend_declare_property_null(phalcon_queue_adapter_memory_memorysubscriptionconsumer_ce, SL("context"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemorySubscriptionConsumer, __construct)
{
	zval *context, context_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&context_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(context, phalcon_queue_adapter_memory_memorycontext_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &context);
	zephir_update_property_zval(this_ptr, ZEND_STRL("context"), context);
}

