
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

namespace Phalcon\Mvc\Model;

use Phalcon\Mvc\ModelInterface;

/**
 * Phalcon\Mvc\Model\Behavior
 *
 * This is an optional base class for ORM behaviors
 */
abstract class Behavior
{
	protected _options;

	/**
	 * Phalcon\Mvc\Model\Behavior
	 *
	 * @param array options
	 */
	public function __construct(options = null)
	{
		let this->_options = options;
	}

	/**
	 * Checks whether the behavior must take action on certain event
	 */
	protected function mustTakeAction(string! eventName) -> boolean
	{
		return isset this->_options[eventName];
	}

	/**
	 * Returns the behavior options related to an event
	 *
	 * @param string eventName
	 * @return array
	 */
	protected function getOptions(string! eventName = null)
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
	 */
	public function notify(string type, <ModelInterface> model)
	{
		return null;
	}

	/**
	 * Acts as fallbacks when a missing method is called on the model
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param string method
	 * @param array arguments
	 */
	public function missingMethod(<ModelInterface> model, string method, arguments = null)
	{
		return null;
	}
}
