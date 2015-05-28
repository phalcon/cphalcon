
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Mvc\Collection;

use Phalcon\Events\ManagerInterface as EventsManagerInterface;
use Phalcon\Mvc\CollectionInterface;
use Phalcon\Mvc\Collection\BehaviorInterface;

/**
 * Phalcon\Mvc\Collection\Manager
 *
 * This components controls the initialization of models, keeping record of relations
 * between the different models of the application.
 *
 * A CollectionManager is injected to a model via a Dependency Injector Container such as Phalcon\Di.
 *
 * <code>
 * $di = new \Phalcon\Di();
 *
 * $di->set('collectionManager', function(){
 *      return new \Phalcon\Mvc\Collection\Manager();
 * });
 *
 * robot = new Robots(di);
 * </code>
 */
interface ManagerInterface
{

	/**
	 * Sets a custom events manager for a specific model
	 */
	public function setCustomEventsManager(<CollectionInterface> model, <EventsManagerInterface> eventsManager);

	/**
	 * Returns a custom events manager related to a model
	 */
	public function getCustomEventsManager(<CollectionInterface> model) -> <EventsManagerInterface>;

	/**
	 * Initializes a model in the models manager
	 */
	public function initialize(<CollectionInterface> model);

	/**
	 * Check whether a model is already initialized
	 */
	public function isInitialized(string! modelName) -> boolean;

	/**
	 * Get the latest initialized model
	 */
	public function getLastInitialized() -> <CollectionInterface>;

	/**
	 * Sets a connection service for a specific model
	 */
	public function setConnectionService(<CollectionInterface> model, string! connectionService);

	/**
	 * Sets if a model must use implicit objects ids
	 */
	public function useImplicitObjectIds(<CollectionInterface> model, boolean useImplicitObjectIds);

	/**
	 * Checks if a model is using implicit object ids
	 */
	public function isUsingImplicitObjectIds(<CollectionInterface> model) -> boolean;

	/**
	 * Returns the connection related to a model
	 *
	 * @param Phalcon\Mvc\CollectionInterface model
	 * @return Phalcon\Db\AdapterInterface
	 */
	public function getConnection(<CollectionInterface> model);

	/**
	 * Receives events generated in the models and dispatches them to a events-manager if available
	 * Notify the behaviors that are listening in the model
	 */
	public function notifyEvent(string! eventName, <CollectionInterface> model);

	/**
	 * Binds a behavior to a collection
	 */
	public function addBehavior(<CollectionInterface> model, <BehaviorInterface> behavior);

}