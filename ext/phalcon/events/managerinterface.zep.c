
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
 * Phalcon\Events\ManagerInterface
 *
 * Interface for Phalcon\Events managers.
 */
ZEPHIR_INIT_CLASS(Phalcon_Events_ManagerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Events, ManagerInterface, phalcon, events_managerinterface, phalcon_events_managerinterface_method_entry);

	return SUCCESS;

}

/**
 * Attach a listener to the events manager
 *
 * @param object|callable handler
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_ManagerInterface, attach);
/**
 * Detach the listener from the events manager
 *
 * @param object handler
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_ManagerInterface, detach);
/**
 * Removes all events from the EventsManager
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_ManagerInterface, detachAll);
/**
 * Fires an event in the events manager causing the active listeners to be
 * notified about it
 *
 * @param object source
 * @param mixed  data
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_ManagerInterface, fire);
/**
 * Returns all the attached listeners of a certain type
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_ManagerInterface, getListeners);
/**
 * Check whether certain type of event has listeners
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_ManagerInterface, hasListeners);
