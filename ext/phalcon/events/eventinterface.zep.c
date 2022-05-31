
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

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
 * Interface for Phalcon\Events\Event class
 */
ZEPHIR_INIT_CLASS(Phalcon_Events_EventInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Events, EventInterface, phalcon, events_eventinterface, phalcon_events_eventinterface_method_entry);

	return SUCCESS;
}

/**
 * Gets event data
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_EventInterface, getData);
/**
 * Gets event type
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_EventInterface, getType);
/**
 * Check whether the event is cancelable
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_EventInterface, isCancelable);
/**
 * Check whether the event is currently stopped
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_EventInterface, isStopped);
/**
 * Sets event data
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_EventInterface, setData);
/**
 * Sets event type
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_EventInterface, setType);
/**
 * Stops the event preventing propagation
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_EventInterface, stop);
