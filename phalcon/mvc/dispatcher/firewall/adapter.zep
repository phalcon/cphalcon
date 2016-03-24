
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2016 Phalcon Team (http://www.phalconphp.com)       |
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
 |          Wojciech Ślawski <jurigag@gmail.com>                          |
 +------------------------------------------------------------------------+
 */


namespace Phalcon\Mvc\Dispatcher\Firewall;

use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Mvc\Dispatcher\Firewall\AdapterInterface;
use Phalcon\Acl;
use Phalcon\Mvc\Dispatcher;

/**
 * Phalcon\Mvc\Dispatcher\Firewall\Adapter
 *
 * Adapter for Phalcon\Mvc\Dispatcher\Firewall adapters
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
	 * @var int
	 */
	protected _defaultAccess = Acl::DENY { get, set };

	/**
	 * Anonymous function for getting user identity - this function must return string, array or object implementing Phalcon\Acl\RoleAware
	 * @var mixed
	 */
	protected _roleCallback;

	/**
	 * Dispatcher
	 * @var mixed
	 */
	protected _dispatcher;

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

	public function getDispatcher() -> <Dispatcher>
	{
		return this->_dispatcher;
	}

	/**
	 * Sets role callback to fetch role name
	 */
	public function setRoleCallback(var callback)
	{
		if !is_callable(callback){
			throw new Exception("Role callback must be function.");
		}
		let this->_roleCallback = callback;
	}

	/**
	 * Gets role callback to fetch role name
	 */
	public function getRoleCallback()
	{
		return this->_roleCallback;
	}

	/**
	 * Throws an internal exception
	 */
	protected function _throwFirewallException(string message, int exceptionCode = 0)
	{
		var exception;

		let exception = new Exception(message, exceptionCode);

		if this->_handleException(exception) === false {
			return false;
		}

		throw exception;
	}

	/**
	 * Handles a user exception
	 */
	protected function _handleException(<\Exception> exception)
	{
		var eventsManager;
		let eventsManager = <ManagerInterface> this->_eventsManager;
		if typeof eventsManager == "object" {
			if eventsManager->fire("firewall:beforeException", this, exception) === false {
				return false;
			}
		}
	}

	protected function fireEventOrThrowException(var role, string actionName, string controllerName, boolean access)
	{
		var eventsManager, roleName;
		let eventsManager = this->_eventsManager;
		if access {
			if typeof eventsManager == "object" {
				eventsManager->fire("firewall:afterCheck",this);
			}
		}
		else {
			if typeof role == "array" {
				let roleName = implode(", ",role);
			}
			else {
				let roleName = role;
			}
			return this->_throwFirewallException("Role name ".roleName." doesn't have access to action ".actionName." in controller ".controllerName,403);
		}
	}
}
