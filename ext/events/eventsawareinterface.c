
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "events/eventsawareinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_events_eventsawareinterface_ce;

static const zend_function_entry phalcon_events_eventsawareinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Events_EventsAwareInterface, setEventsManager, arginfo_phalcon_events_eventsawareinterface_seteventsmanager)
	PHP_ABSTRACT_ME(Phalcon_Events_EventsAwareInterface, getEventsManager, arginfo_phalcon_events_eventsawareinterface_geteventsmanager)
	PHP_FE_END
};


/**
 * Phalcon\Events\EventsAwareInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Events_EventsAwareInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Events, EventsAwareInterface, events_eventsawareinterface, phalcon_events_eventsawareinterface_method_entry);

	return SUCCESS;
}

/**
 * Sets the events manager
 *
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHALCON_DOC_METHOD(Phalcon_Events_EventsAwareInterface, setEventsManager);

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHALCON_DOC_METHOD(Phalcon_Events_EventsAwareInterface, getEventsManager);
