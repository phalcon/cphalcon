
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

/**
 * Phalcon\Acl\Adapter
 *
 * Adapter for Phalcon\Acl adapters
 */

class Adapter
{
	/**
	 * Events manager
	 * "@var mixed
	 */
	protected _eventsManager;

	/**
	 * Default access
	 * "@var bool
	 */
	protected _defaultAccess = true;

	/**
	 * Access Granted
	 * "@var bool
	 */
	protected _accessGranted = false;

	/**
	 * Events manager
	 * "@var mixed
	 */
	protected _activeRole;

	/**
	 * Active resource
	 * "@var mixed
	 */
	protected _activeResource;

	/**
	 * Active Access
	 * "@var mixed
	 */
	protected _activeAccess;

	/**
	 * Sets the events manager
	 *
	 * @param Phalcon\Events\ManagerInterface eventsManager
	 */
	public function setEventsManager(<Phalcon\Events\ManagerInterface> eventsManager)
	{
		let this->_eventsManager = eventsManager;
	}

	/**
	 * Returns the internal event manager
	 *
	 * @return Phalcon\Events\ManagerInterface
	 */
	public function getEventsManager()
	{
		return this->_eventsManager;
	}

	/**
	 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
	 *
	 * @param int defaultAccess
	 */
	public function setDefaultAction(int defaultAccess)
	{
		let this->_defaultAccess = defaultAccess;
	}

	/**
	 * Returns the default ACL access level
	 *
	 * @return int
	 */
	public function getDefaultAction()
	{
		return this->_defaultAccess;
	}

	/**
	 * Returns the role which the list is checking if it's allowed to certain resource/access
	 *
	 * @return string
	 */
	public function getActiveRole()
	{
		return this->_activeRole;
	}

	/**
	 * Returns the resource which the list is checking if some role can access it
	 *
	 * @return string
	 */
	public function getActiveResource()
	{
		return this->_activeResource;
	}

	/**
	 * Returns the access which the list is checking if some role can access it
	 *
	 * @return string
	 */
	public function getActiveAccess()
	{
		return this->_activeAccess;
	}
}
