
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
	 * Active access which the list is checking if some operation can access it
	 *
	 * @var string
	 */
	private activeAccess { get };

	/**
	 * Access Granted
	 * @var bool
	 */
	private accessGranted = false;

	/**
	 * Operation which the list is checking if it's allowed to certain subject/access
	 *
	 * @var string
	 */
	private activeOperation { get };

	/**
	 * Subject which the list is checking if some operation can access it
	 *
	 * @var string
	 */
	private activeSubject { get };

	/**
	 * Default access
	 * @var bool
	 */
	private defaultAccess = false;

	/**
	 * Events manager
	 * @var mixed
	 */
	private eventsManager;

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
