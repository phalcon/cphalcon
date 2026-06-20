
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
 * A queue destination (point-to-point).
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_Queue)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Queue, Queue, phalcon, contracts_queue_queue, phalcon_contracts_queue_queue_method_entry);

	zend_class_implements(phalcon_contracts_queue_queue_ce, 1, phalcon_contracts_queue_destination_ce);
	return SUCCESS;
}

/**
 * Returns the queue name.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Queue, getQueueName);
