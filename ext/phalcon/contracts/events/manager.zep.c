
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
 * Canonical contract for Phalcon\Events\Manager.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Events_Manager)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Events, Manager, phalcon, contracts_events_manager, phalcon_contracts_events_manager_method_entry);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_contracts_events_manager_ce, SL("DEFAULT_PRIORITY"), 100);

	return SUCCESS;
}

/**
 * Registers an event subscriber. The subscriber's getSubscribedEvents()
 * map is parsed and each entry is attached through the regular listener
 * pipeline.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Manager, addSubscriber);
/**
 * Returns whether priority ordering is currently enabled.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Manager, arePrioritiesEnabled);
/**
 * Attach a listener to the events manager.
 *
 * @param object|callable handler
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Manager, attach);
/**
 * Removes every registered subscriber and detaches each listener they
 * contributed. Listeners attached via attach() are untouched.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Manager, clearSubscribers);
/**
 * Toggle response collection on/off.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Manager, collectResponses);
/**
 * Detach a listener from the events manager.
 *
 * @param object|callable handler
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Manager, detach);
/**
 * Removes all listeners - globally or for a single event type.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Manager, detachAll);
/**
 * Toggle priority ordering on/off.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Manager, enablePriorities);
/**
 * Fires an event, notifying the active listeners.
 *
 * @param object source
 * @param mixed  data
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Manager, fire);
/**
 * Returns all listeners attached to the given event type.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Manager, getListeners);
/**
 * Returns the responses recorded during the last fire (when collecting).
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Manager, getResponses);
/**
 * Returns the list of registered subscriber instances.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Manager, getSubscribers);
/**
 * Check whether the given event type has any listeners.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Manager, hasListeners);
/**
 * Check whether the manager is currently collecting responses.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Manager, isCollecting);
/**
 * Returns true when the given handler is an object or callable.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Manager, isValidHandler);
/**
 * Removes a previously registered subscriber. Detaches every listener the
 * subscriber declared via getSubscribedEvents(). Idempotent.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Events_Manager, removeSubscriber);
