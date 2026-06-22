
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
 * Builds a Context: the entry point of every adapter.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_ConnectionFactory)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Queue, ConnectionFactory, phalcon, contracts_queue_connectionfactory, phalcon_contracts_queue_connectionfactory_method_entry);

	return SUCCESS;
}

/**
 * Creates a context (a session/connection to the transport).
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_ConnectionFactory, createContext);
