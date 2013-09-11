
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

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
 * Phalcon\Mvc\Collection\Manager
 *
 * This components controls the initialization of models, keeping record of relations
 * between the different models of the application.
 *
 * A CollectionManager is injected to a model via a Dependency Injector Container such as Phalcon\DI.
 *
 * <code>
 * $di = new Phalcon\DI();
 *
 * $di->set('collectionManager', function(){
 *      return new Phalcon\Mvc\Collection\Manager();
 * });
 *
 * robot = new Robots(di);
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_ManagerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Collection, ManagerInterface, phalcon, mvc_collection_managerinterface, phalcon_mvc_collection_managerinterface_method_entry);


	return SUCCESS;

}

/**
 * Sets a custom events manager for a specific model
 *
 * @param Phalcon\Mvc\CollectionInterface model
 * @param Phalcon\Events\ManagerInterface eventsManager
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, setCustomEventsManager);
/**
 * Returns a custom events manager related to a model
 *
 * @param Phalcon\Mvc\CollectionInterface model
 * @return Phalcon\Events\ManagerInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, getCustomEventsManager);
/**
 * Initializes a model in the models manager
 *
 * @param Phalcon\Mvc\CollectionInterface model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, initialize);
/**
 * Check whether a model is already initialized
 *
 * @param string modelName
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, isInitialized);
/**
 * Get the latest initialized model
 *
 * @return Phalcon\Mvc\CollectionInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, getLastInitialized);
/**
 * Sets a connection service for a specific model
 *
 * @param Phalcon\Mvc\CollectionInterface model
 * @param string connectionService
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, setConnectionService);
/**
 * Sets if a model must use implicit objects ids
 *
 * @param Phalcon\Mvc\CollectionInterface model
 * @param boolean useImplicitObjectIds
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, useImplicitObjectIds);
/**
 * Checks if a model is using implicit object ids
 *
 * @param Phalcon\Mvc\CollectionInterface model
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, isUsingImplicitObjectIds);
/**
 * Returns the connection related to a model
 *
 * @param Phalcon\Mvc\CollectionInterface model
 * @return Phalcon\Db\AdapterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, getConnection);
/**
 * Receives events generated in the models and dispatches them to a events-manager if available
 * Notify the behaviors that are listening in the model
 *
 * @param string eventName
 * @param Phalcon\Mvc\CollectionInterface model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Collection_ManagerInterface, notifyEvent);
