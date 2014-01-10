
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

#include "mvc/collection/managerinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_mvc_collection_managerinterface_ce;

static const zend_function_entry phalcon_mvc_collection_managerinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, setCustomEventsManager, arginfo_phalcon_mvc_collection_managerinterface_setcustomeventsmanager)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, getCustomEventsManager, arginfo_phalcon_mvc_collection_managerinterface_getcustomeventsmanager)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, initialize, arginfo_phalcon_mvc_collection_managerinterface_initialize)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, isInitialized, arginfo_phalcon_mvc_collection_managerinterface_isinitialized)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, getLastInitialized, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, setConnectionService, arginfo_phalcon_mvc_collection_managerinterface_setconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, useImplicitObjectIds, arginfo_phalcon_mvc_collection_managerinterface_useimplicitobjectids)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, isUsingImplicitObjectIds, arginfo_phalcon_mvc_collection_managerinterface_isusingimplicitobjectids)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, getConnection, arginfo_phalcon_mvc_collection_managerinterface_getconnection)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, notifyEvent, arginfo_phalcon_mvc_collection_managerinterface_notifyevent)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Collection\ManagerInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_ManagerInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Collection, ManagerInterface, mvc_collection_managerinterface, phalcon_mvc_collection_managerinterface_method_entry);

	return SUCCESS;
}

/**
 * Sets a custom events manager for a specific model
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, setCustomEventsManager);

/**
 * Returns a custom events manager related to a model
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 * @return Phalcon\Events\ManagerInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, getCustomEventsManager);

/**
 * Initializes a model in the models manager
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, initialize);

/**
 * Check whether a model is already initialized
 *
 * @param string $modelName
 * @return bool
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, isInitialized);

/**
 * Get the latest initialized model
 *
 * @return Phalcon\Mvc\CollectionInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, getLastInitialized);

/**
 * Sets a connection service for a specific model
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 * @param string $connectionService
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, setConnectionService);

/**
 * Sets if a model must use implicit objects ids
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 * @param boolean $useImplicitObjectIds
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, useImplicitObjectIds);

/**
 * Checks if a model is using implicit object ids
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, isUsingImplicitObjectIds);

/**
 * Returns the connection related to a model
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 * @return Phalcon\Db\AdapterInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, getConnection);

/**
 * Receives events generated in the models and dispatches them to a events-manager if available
 * Notify the behaviors that are listening in the model
 *
 * @param string $eventName
 * @param Phalcon\Mvc\CollectionInterface $model
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, notifyEvent);
