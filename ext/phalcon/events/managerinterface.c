
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
 * Phalcon\Events\Manager
 *
 * Phalcon Events Manager, offers an easy way to intercept and manipulate, if needed,
 * the normal flow of operation. With the EventsManager the developer can create hooks or
 * plugins that will offer monitoring of data, manipulation, conditional execution and much more.
 */
ZEPHIR_INIT_CLASS(Phalcon_Events_ManagerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Events, ManagerInterface, phalcon, events_managerinterface, phalcon_events_managerinterface_method_entry);


	return SUCCESS;

}

/**
 * Attach a listener to the events manager
 *
 * @param string eventType
 * @param object handler
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_ManagerInterface, attach);

/**
 * Removes all events from the EventsManager
 *
 * @param string type
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_ManagerInterface, dettachAll);

/**
 * Fires a event in the events manager causing that the acive listeners will be notified about it
 *
 * @param string eventType
 * @param object source
 * @param mixed  data
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_ManagerInterface, fire);

/**
 * Returns all the attached listeners of a certain type
 *
 * @param string type
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Events_ManagerInterface, getListeners);

