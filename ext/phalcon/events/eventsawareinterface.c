
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Events\EventsAwareInterface
 *
 * This interface must for those classes that accept an EventsManager and dispatch events
 */
ZEPHIR_INIT_CLASS(Phalcon_Events_EventsAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Events, EventsAwareInterface, phalcon, events_eventsawareinterface, phalcon_events_eventsawareinterface_method_entry);


	return SUCCESS;

}

/**
 * Sets the events manager
 *
 * @param Phalcon\Events\ManagerInterface eventsManager
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_EventsAwareInterface, setEventsManager);

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_EventsAwareInterface, getEventsManager);

