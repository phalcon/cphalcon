
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Events;

/**
 * Phalcon\Events\Manager
 *
 * Phalcon Events Manager, offers an easy way to intercept and manipulate, if needed,
 * the normal flow of operation. With the EventsManager the developer can create hooks or
 * plugins that will offer monitoring of data, manipulation, conditional execution and much more.
 */
interface ManagerInterface
{

	/**
	 * Attach a listener to the events manager
	 *
	 * @param object|callable handler
	 */
	public function attach(string! eventType, handler);

	/**
	 * Detach the listener from the events manager
	 *
	 * @param object handler
	 */
	public function detach(string! eventType, handler);

	/**
	 * Removes all events from the EventsManager
	 */
	public function detachAll(string! type = null);

	/**
	 * Fires an event in the events manager causing the active listeners to be notified about it
	 *
	 * @param object source
	 * @param mixed  data
	 * @return mixed
	 */
	public function fire(string! eventType, source, data = null);

	/**
	 * Check whether certain type of event has listeners
	 */
	public function hasListeners(string! type) -> bool;

	/**
	 * Returns all the attached listeners of a certain type
	 */
	public function getListeners(string! type) -> array;

}
