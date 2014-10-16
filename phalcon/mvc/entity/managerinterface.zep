
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

namespace Phalcon\Mvc\Entity;

use Phalcon\Mvc\EntityInterface;

interface ManagerInterface
{
	/**
	 * Initializes an entity in the entity manager
	 *
	 * @param Phalcon\Mvc\EntityInterface entity
	 */
	public function initialize(<EntityInterface> entity);

	/**
	 * Check of a entity is already initialized
	 *
	 * @param string entityName
	 * @return boolean
	 */
	public function isInitialized(string! entityName) -> boolean;

	/**
	 * Get last initialized entity
	 *
	 * @return Phalcon\Mvc\EntityInterface
	 */
	public function getLastInitialized() -> <EntityInterface>;

	/**
	 * Binds a behavior to a entity
	 *
	 * @param Phalcon\Mvc\EntityInterface entity
	 * @param Phalcon\Mvc\Entity\BehaviorInterface behavior
	 */
	public function addBehavior(<EntityInterface> entity, <BehaviorInterface> behavior);

	/**
	 * Receives events generated in the entitys and dispatches them to a events-manager if available
	 * Notify the behaviors that are listening in the entity
	 *
	 * @param string eventName
	 * @param Phalcon\Mvc\EntityInterface entity
	 */
	public function notifyEvent(string! eventName, <EntityInterface> entity);

	/**
	 * Dispatch a event to the listeners and behaviors
	 * This method expects that the endpoint listeners/behaviors returns true
	 * meaning that a least one is implemented
	 *
	 * @param Phalcon\Mvc\EntityInterface entity
	 * @param string eventName
	 * @param array data
	 * @return boolean
	 */
	public function missingMethod(<EntityInterface> entity, string! eventName, array! data);

	/**
	 * Loads a entity throwing an exception if it doesn't exist
	 *
	 * @param  string entityName
	 * @param  boolean newInstance
	 * @return Phalcon\Mvc\EntityInterface
	 */
	public function load(string entityName, boolean newInstance=false);

	/**
	 * Sets if a entity must keep snapshots
	 *
	 * @param Phalcon\Mvc\EntityInterface entity
	 * @param boolean keepSnapshots
	 */
	public function keepSnapshots(<EntityInterface> entity, boolean keepSnapshots);

	/**
	 * Checks if a entity is keeping snapshots for the queried records
	 *
	 * @param Phalcon\Mvc\EntityInterface entity
	 * @return boolean
	 */
	public function isKeepingSnapshots(<EntityInterface> entity);

	/**
	 * Sets if a entity must use dynamic update instead of the all-field update
	 *
	 * @param Phalcon\Mvc\EntityInterface entity
	 * @param boolean dynamicUpdate
	 */
	public function useDynamicUpdate(<EntityInterface> entity, boolean dynamicUpdate);

	/**
	 * Checks if a entity is using dynamic update instead of all-field update
	 *
	 * @param Phalcon\Mvc\Entity entity
	 * @return boolean
	 */
	public function isUsingDynamicUpdate(<EntityInterface> entity);
}
