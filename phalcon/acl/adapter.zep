
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Acl;

use Phalcon\Events\ManagerInterface;
use Phalcon\Events\EventsAwareInterface;

/**
 * Phalcon\Acl\Adapter
 *
 * Adapter for Phalcon\Acl adapters
 */
abstract class Adapter implements AdapterInterface, EventsAwareInterface
{
	/**
	 * Events manager
	 * @var mixed
	 */
	protected _eventsManager;

	/**
	 * Default access
	 * @var bool
	 */
	protected _defaultAccess = false;

	/**
	 * Access Granted
	 * @var bool
	 */
	protected _accessGranted = false;

	/**
	 * Operation which the list is checking if it's allowed to certain subject/access
	 *
	 * @var string
	 */
	protected _activeOperation { get };

	/**
	 * Subject which the list is checking if some operation can access it
	 *
	 * @var string
	 */
	protected _activeSubject { get };

	/**
	 * Active access which the list is checking if some operation can access it
	 *
	 * @var string
	 */
	protected _activeAccess { get };

	/**
	 * Sets the events manager
	 */
	public function setEventsManager(<ManagerInterface> eventsManager)
	{
		let this->_eventsManager = eventsManager;
	}

	/**
	 * Returns the internal event manager
	 */
	public function getEventsManager() -> <ManagerInterface>
	{
		return this->_eventsManager;
	}

	/**
	 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
	 */
	public function setDefaultAction(int defaultAccess)
	{
		let this->_defaultAccess = defaultAccess;
	}

	/**
	 * Returns the default ACL access level
	 */
	public function getDefaultAction() -> int
	{
		return this->_defaultAccess;
	}
}
