
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
 * Phalcon's local mirror of PSR-14 StoppableEventInterface. Identical shape;
 * not extended from the PSR interface because the Zephir extension cannot
 * reference Composer-loaded interfaces at build time. A separate bridge
 * package exposes a PSR-14 adapter.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Events_Stoppable)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Events, Stoppable, phalcon, contracts_events_stoppable, phalcon_contracts_events_stoppable_method_entry);

	return SUCCESS;
}

/**
 * Returns true when the event must stop propagating to subsequent
 * listeners.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Stoppable, isPropagationStopped);
