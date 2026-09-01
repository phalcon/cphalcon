
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
 * Contract for event subscriber classes. A subscriber declares the events it
 * wants to listen to via a static map; Events\Manager parses the map and
 * attaches each entry as a regular listener.
 *
 * Accepted value shapes per event key:
 *
 *   'event:name' => 'methodName'
 *   'event:name' => ['methodName', priority]
 *   'event:name' => [
 *       ['methodName1'],
 *       ['methodName2', priority],
 *   ]
 *
 * Keys can be either a Phalcon event string (e.g. "db:beforeQuery") or a
 * fully qualified event class name.
 *
 * Wildcard subscriptions: Phalcon's manager fires both the prefix queue and
 * the full-name queue (e.g. "db" is fired before "db:beforeQuery"). To
 * subscribe to every event of a component, use the prefix as the key:
 *
 *   'db' => 'onAnyDbEvent'   // fires for db:beforeQuery, db:afterQuery, ...
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Events_Subscriber)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Events, Subscriber, phalcon, contracts_events_subscriber, phalcon_contracts_events_subscriber_method_entry);

	return SUCCESS;
}

/**
 * Returns a map of event name => listener config. Called once per
 * Manager::addSubscriber() / removeSubscriber() call.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Subscriber, getSubscribedEvents);
