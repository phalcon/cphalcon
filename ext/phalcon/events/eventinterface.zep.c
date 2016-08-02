
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Events\EventInterface
 *
 * Interface for Phalcon\Events\Event class
 */
ZEPHIR_INIT_CLASS(Phalcon_Events_EventInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Events, EventInterface, phalcon, events_eventinterface, phalcon_events_eventinterface_method_entry);

	return SUCCESS;

}

/**
 * Gets event data
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_EventInterface, getData);

/**
 * Sets event data
 * @param mixed data
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_EventInterface, setData);

/**
 * Gets event type
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_EventInterface, getType);

/**
 * Sets event type
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_EventInterface, setType);

/**
 * Stops the event preventing propagation
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_EventInterface, stop);

/**
 * Check whether the event is currently stopped
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_EventInterface, isStopped);

/**
 * Check whether the event is cancelable
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_EventInterface, isCancelable);

