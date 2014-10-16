
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

/**
 * Phalcon\Mvc\Entity\Behavior
 *
 * This is an optional base class for entity behaviors
 */
abstract class Behavior implements BehaviorInterface
{
	protected _options;

	/**
	 * Phalcon\Mvc\Entity\Behavior
	 *
	 * @param array options
	 */
	public function __construct(options=null)
	{
		let this->_options = options;
	}

	/**
	 * Checks whether the behavior must take action on certain event
	 *
	 * @param string eventName
	 */
	protected function mustTakeAction(string! eventName)
	{
		return isset this->_options[eventName];
	}

	/**
	 * Returns the behavior options related to an event
	 *
	 * @param string eventName
	 * @return array
	 */
	protected function getOptions(string! eventName=null)
	{
		var options, eventOptions;

		let options = this->_options;
		if eventName !== null {
			if fetch eventOptions, options[eventName] {
				return eventOptions;
			}
			return null;
		}
		return options;
	}

	/**
	 * This method receives the notifications from the EventsManager
	 *
	 * @param string type
	 * @param Phalcon\Mvc\EntityInterface entity
	 */
	public function notify(string type, <EntityInterface> entity)
	{
		return null;
	}

	/**
	 * Acts as fallbacks when a missing method is called on the entity
	 *
	 * @param Phalcon\Mvc\EntityInterface entity
	 * @param string method
	 * @param array arguments
	 */
	public function missingMethod(<EntityInterface> entity, string! method, var arguments = null)
	{
		return null;
	}

}
