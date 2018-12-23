
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\BehaviorInterface;

/**
 * Phalcon\Mvc\Model\Behavior
 *
 * This is an optional base class for ORM behaviors
 */
abstract class Behavior implements BehaviorInterface
{
	protected _options;

	/**
	 * Phalcon\Mvc\Model\Behavior
	 */
	public function __construct(array options = [])
	{
		let this->_options = options;
	}

	/**
	 * Checks whether the behavior must take action on certain event
	 */
	protected function mustTakeAction(string! eventName) -> bool
	{
		return isset this->_options[eventName];
	}

	/**
	 * Returns the behavior options related to an event
	 *
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
	 */
	public function missingMethod(<ModelInterface> model, string method, array arguments = [])
	{
		return null;
	}
}
