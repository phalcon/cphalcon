
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

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
 */
PHALCON_DOC_METHOD(Phalcon_Events_ManagerInterface, dettachAll);
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
