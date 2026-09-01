
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
 * Canonical contract for Phalcon\Events\EventsAwareInterface. Implemented by
 * components that accept an events manager and dispatch through it.
 *
 * Cross-references the legacy ManagerInterface (not the canonical Manager
 * contract) to preserve LSP for the many AbstractEventsAware subclasses that
 * already type-hint ManagerInterface. ManagerInterface extends Manager, so
 * this remains type-compatible with any code that needs the canonical surface.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Events_EventsAware)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Events, EventsAware, phalcon, contracts_events_eventsaware, phalcon_contracts_events_eventsaware_method_entry);

	return SUCCESS;
}

/**
 * Returns the internal events manager
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_EventsAware, getEventsManager);
/**
 * Sets the events manager
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_EventsAware, setEventsManager);
