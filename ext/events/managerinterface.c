
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

#include "events/managerinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_events_managerinterface_ce;

static const zend_function_entry phalcon_events_managerinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Events_ManagerInterface, attach, arginfo_phalcon_events_managerinterface_attach)
	PHP_ABSTRACT_ME(Phalcon_Events_ManagerInterface, detachAll, arginfo_phalcon_events_managerinterface_detachall)
	PHP_ABSTRACT_ME(Phalcon_Events_ManagerInterface, fire, arginfo_phalcon_events_managerinterface_fire)
	PHP_ABSTRACT_ME(Phalcon_Events_ManagerInterface, getListeners, arginfo_phalcon_events_managerinterface_getlisteners)
	PHP_FE_END
};


/**
 * Phalcon\Events\ManagerInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Events_ManagerInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Events, ManagerInterface, events_managerinterface, phalcon_events_managerinterface_method_entry);

	return SUCCESS;
}

/**
 * Attach a listener to the events manager
 *
 * @param string $eventType
 * @param object $handler
 */
PHALCON_DOC_METHOD(Phalcon_Events_ManagerInterface, attach);

/**
 * Removes all events from the EventsManager
 *
 * @param string $type
 */
PHALCON_DOC_METHOD(Phalcon_Events_ManagerInterface, detachAll);

/**
 * Fires a event in the events manager causing that the acive listeners will be notified about it
 *
 * @param string $eventType
 * @param object $source
 * @param mixed  $data
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Events_ManagerInterface, fire);

/**
 * Returns all the attached listeners of a certain type
 *
 * @param string $type
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Events_ManagerInterface, getListeners);
