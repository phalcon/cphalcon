
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
 * Base throwable contract for the Queue component. Every queue exception
 * implements it, so callers can catch all queue errors with a single type.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Exceptions_QueueThrowable)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Queue\\Exceptions, QueueThrowable, phalcon, queue_exceptions_queuethrowable, NULL);

	zend_class_implements(phalcon_queue_exceptions_queuethrowable_ce, 1, zend_ce_throwable);
	return SUCCESS;
}

