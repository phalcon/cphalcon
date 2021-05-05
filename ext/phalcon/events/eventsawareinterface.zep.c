
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
 * Phalcon\Events\EventsAwareInterface
 *
 * This interface must for those classes that accept an EventsManager and
 * dispatch events
 */
ZEPHIR_INIT_CLASS(Phalcon_Events_EventsAwareInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Events, EventsAwareInterface, phalcon, events_eventsawareinterface, phalcon_events_eventsawareinterface_method_entry);

	return SUCCESS;
}

/**
 * Returns the internal event manager
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_EventsAwareInterface, getEventsManager);
/**
 * Sets the events manager
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_EventsAwareInterface, setEventsManager);
