
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
 */
/**
 * Marker interface for a message destination: a Queue or a Topic.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_Destination)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Queue, Destination, phalcon, contracts_queue_destination, NULL);

	return SUCCESS;
}

