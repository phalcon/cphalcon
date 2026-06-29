
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 * Optional capability contract for a transport that can report statistics for
 * a queue (for example ready, delayed and buried job counts). Callers detect
 * support with `instanceof`.
 *
 * The array returned by getStats() is ADAPTER-NATIVE: its keys and their
 * semantics are defined by the implementing adapter and are NOT guaranteed to
 * be uniform across adapters. It is an inspection surface, not a portable or
 * normalized schema. Each implementation documents the exact keys it returns.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_Inspectable)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Queue, Inspectable, phalcon, contracts_queue_inspectable, phalcon_contracts_queue_inspectable_method_entry);

	return SUCCESS;
}

/**
 * Returns statistics for the given queue.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Inspectable, getStats);
