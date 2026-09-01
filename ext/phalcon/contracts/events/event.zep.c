
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
 * Canonical contract for Phalcon\Events\Event.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Events_Event)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Events, Event, phalcon, contracts_events_event, phalcon_contracts_events_event_method_entry);

	return SUCCESS;
}

/**
 * Gets event data
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Event, getData);
/**
 * Gets event type
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Event, getType);
/**
 * Check whether the event is cancelable
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Event, isCancelable);
/**
 * Check whether the event is currently stopped
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Event, isStopped);
/**
 * Sets event data
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Event, setData);
/**
 * Sets event type
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Event, setType);
/**
 * Stops the event preventing propagation
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Event, stop);
