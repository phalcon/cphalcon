
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


namespace Phalcon\Firewall;

use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Acl;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Cache\BackendInterface;
use Phalcon\DiInterface;
use Phalcon\Acl\RoleAware;

/**
 * Phalcon\Firewall\Adapter
 *
 * Adapter for Phalcon\Firewall adapters
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
	 * Internal cache for caching access during request time
	 * @var mixed
	 */
	protected _internalCache;

	/**
	 * Cache for caching access
	 * @var \Phalcon\Cache\BackendInterface
	 */
	protected _cache;

	/**
	 * Storing active user role
	 */
	protected _activeRole { get };

	/**
	 * Storing active identity object implementing Phalcon/Acl/RoleAware
	 */
	protected _activeIdentity { get };

	/**
	 * Should role always be resolved using role callback or just once?
	 * @var bool
	 */
	protected _alwaysResolvingRole = false { set };

	/**
	 * Sets the events manager
	 */
	public function setEventsManager(<ManagerInterface> eventsManager) -> <AdapterInterface>
	{
		let this->_eventsManager = eventsManager;

		return this;
	}

	/**
	 * Returns the internal event manager
	 */
	public function getEventsManager() -> <ManagerInterface>
	{
		return this->_eventsManager;
	}

	/**
	 * Sets role callback to fetch role name
	 */
	public function setRoleCallback(var callback) -> <AdapterInterface>
	{
		if !is_callable(callback){
			throw new Exception("Role callback must be function.");
		}
		let this->_roleCallback = callback;

		return this;
	}

	/**
	 * Gets role callback to fetch role name
	 */
	public function getRoleCallback() -> <\Closure>
	{
		return this->_roleCallback;
	}

	/**
	 * Gets always resolving role option
	 */
	public function isAlwaysResolvingRole() -> bool
	{
		return this->_alwaysResolvingRole;
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

	/**
	 * Fires event or throwing exception
	 */
	protected function fireEventOrThrowException(var role, string actionName, string controllerName, boolean access)
	{
		var eventsManager, roleName;
		let eventsManager = this->_eventsManager;
		if access {
			if typeof eventsManager == "object" {
				eventsManager->fire("firewall:afterCheck",this);
			}
		} else {
			if typeof role == "array" {
				let roleName = implode(", ",role);
			} else {
				let roleName = role;
			}
			return this->_throwFirewallException("Role name ".roleName." doesn't have access to action ".actionName." in controller ".controllerName, 403);
		}
	}

	/**
	* Saves access in cache and internal cache
	*/
	protected function saveAccessInCache(string! key, boolean access) -> void
	{
		var cache;

		let this->_internalCache[key] = access;

		let cache = this->_cache;

		if cache != null {
			cache->save("_PHF_", this->_internalCache);
		}
	}

	/**
	 * Gets access from cache
	 */
	protected function getAccessFromCache(string! key, array originalValues = null, string roleCacheKey = null) -> boolean|null
	{
		var access;

		fetch access, this->_internalCache[key];

		return access;
	}

	protected function callRoleCallback(<DiInterface> dependencyInjector) -> void
	{
		var roleCallback, identity;

		let roleCallback = this->_roleCallback;

		let identity = {roleCallback}(dependencyInjector);

		if empty identity {
			throw new Exception("Function defined as roleCallback must return something.");
		}

		if typeof identity == "object" {
			if !(identity instanceof RoleAware) {
				throw new Exception("Role passed as object must implement 'Phalcon\\Acl\\RoleAware'");
			}
			let this->_activeIdentity = identity;
			let this->_activeRole = identity->getRoleName();
		} else {
			let this->_activeRole = identity;
		}
	}

	public function setCache(<BackendInterface> cache) -> <AdapterInterface>
	{
		let this->_cache = cache;

		if this->_internalCache === null {
			let this->_internalCache = cache->get("_PHF_");
		}

		return this;
	}
}
