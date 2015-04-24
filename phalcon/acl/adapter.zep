
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
	protected _defaultAccess = true;

	/**
	 * Access Granted
	 * @var bool
	 */
	protected _accessGranted = false;

	/**
	 * Role which the list is checking if it's allowed to certain resource/access
	 * @var mixed
	 */
	protected _activeRole { get };

	/**
	 * Resource which the list is checking if some role can access it
	 * @var mixed
	 */
	protected _activeResource { get };

	/**
	 * Active access which the list is checking if some role can access it
	 * @var mixed
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
