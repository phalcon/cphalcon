
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
 * Marker contract for a consumer that supports a visibility timeout
 * (for example Beanstalk TTR or an SQS visibility timeout). Callers detect
 * support with `instanceof`. It carries no behavior and commits to no class
 * shape.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_VisibilityAware)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Queue, VisibilityAware, phalcon, contracts_queue_visibilityaware, NULL);

	return SUCCESS;
}

