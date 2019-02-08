
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
	 * Active access which the list is checking if some role can access it
	 *
	 * @var string
	 */
	protected activeAccess { get };

	/**
	 * Access Granted
	 * @var bool
	 */
	protected accessGranted = false;

	/**
	 * Role which the list is checking if it's allowed to certain component/access
	 *
	 * @var string
	 */
	protected activeRole { get };

	/**
	 * Component which the list is checking if some role can access it
	 *
	 * @var string
	 */
	protected activeComponent { get };

	/**
	 * Default access
	 * @var bool
	 */
	protected defaultAccess = false;

	/**
	 * Events manager
	 * @var mixed
	 */
	protected eventsManager;

	/**
	 * Returns the default ACL access level
	 */
	public function getDefaultAction() -> int
	{
		return this->defaultAccess;
	}

	/**
	 * Returns the internal event manager
	 */
	public function getEventsManager() -> <ManagerInterface>
	{
		return this->eventsManager;
	}

	/**
	 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
	 */
	public function setDefaultAction(int defaultAccess)
	{
		let this->defaultAccess = defaultAccess;
	}

	/**
	 * Sets the events manager
	 */
	public function setEventsManager(<ManagerInterface> eventsManager)
	{
		let this->eventsManager = eventsManager;
	}
}
