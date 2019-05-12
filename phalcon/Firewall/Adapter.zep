
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Firewall;

use Phalcon\Acl;
use Phalcon\Acl\RoleAware;
use Phalcon\Cache\Adapter\AdapterInterface as CacheAdapterInterface;
use Phalcon\DiInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Mvc\Dispatcher;

/**
 * Phalcon\Firewall\Adapter
 *
 * Adapter for Phalcon\Firewall adapters
 */
abstract class Adapter implements AdapterInterface, EventsAwareInterface
{
	/**
	 * Storing active identity object implementing Phalcon/Acl/RoleAware
	 */
	protected activeIdentity { get };

	/**
	 * Storing active user role
	 */
	protected activeRole { get };

	/**
	 * Should role always be resolved using role callback or just once?
	 * @var bool
	 */
	protected alwaysResolvingRole = false { set };

	/**
	 * Cache for caching access
	 * @var <CacheAdapterInterface>
	 */
	protected cache;

	/**
	 * Default access
	 * @var int
	 */
	protected defaultAccess = Acl::DENY { get, set };

	/**
	 * Events manager
	 * @var mixed
	 */
	protected eventsManager;

	/**
	 * Internal cache for caching access during request time
	 * @var mixed
	 */
	protected internalCache;

	/**
	 * Anonymous function for getting user identity - this function must
	 * return string, array or object implementing Phalcon\Acl\RoleAware
	 * @var mixed
	 */
	protected roleCallback;

	/**
	 * Returns the internal event manager
	 */
	public function getEventsManager() -> <ManagerInterface>
	{
		return this->eventsManager;
	}

	/**
	 * Gets role callback to fetch role name
	 */
	public function getRoleCallback() -> <\Closure>
	{
		return this->roleCallback;
	}

	/**
	 * Gets always resolving role option
	 */
	public function isAlwaysResolvingRole() -> bool
	{
		return this->alwaysResolvingRole;
	}

	/**
	 * Sets the events manager
	 */
	public function setEventsManager(<ManagerInterface> eventsManager) -> <AdapterInterface>
	{
		let this->eventsManager = eventsManager;

		return this;
	}

	/**
	 * Sets role callback to fetch role name
	 */
	public function setRoleCallback(var callback) -> <AdapterInterface>
	{
		if !is_callable(callback){
			throw new Exception("Role callback must be function.");
		}
		let this->roleCallback = callback;

		return this;
	}

	protected function callRoleCallback(<DiInterface> container) -> void
	{
		var roleCallback, identity;

		let roleCallback = this->roleCallback,
		    identity     = {roleCallback}(container);

		if empty identity {
			throw new Exception("Function defined as roleCallback must return something.");
		}

		if typeof identity == "object" {
			if !(identity instanceof RoleAware) {
				throw new Exception("Role passed as object must implement 'Phalcon\\Acl\\RoleAware'");
			}
			let this->activeIdentity = identity,
			    this->activeRole     = identity->getRoleName();
		} else {
			let this->activeRole = identity;
		}
	}

	/**
	 * Gets access from cache
	 */
	protected function getAccessFromCache(
	    string! key,
	    array originalValues = null,
	    string roleCacheKey = null
    ) -> bool | null
	{
		var access;

		fetch access, this->internalCache[key];

		return access;
	}

	/**
	 * Handles a user exception
	 */
	protected function handleException(<\Exception> exception) -> bool | void
	{
		var eventsManager;
		let eventsManager = <ManagerInterface> this->eventsManager;
		if typeof eventsManager == "object" {
			if eventsManager->fire("firewall:beforeException", this, exception) === false {
				return false;
			}
		}
	}

	/**
	 * Fires event or throwing exception
	 */
	protected function fireEventOrThrowException(
	    var role,
	    string actionName,
	    string controllerName,
	    bool access
    ) -> void
	{
		var eventsManager, roleName;

		let eventsManager = this->eventsManager;
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

			return this->throwFirewallException(
			    "Role name " . roleName . " doesn't have access to action " .
			    actionName . " in controller " . controllerName,
			    403
            );
		}
	}

	/**
	* Saves access in cache and internal cache
	*/
	protected function saveAccessInCache(string! key, bool access) -> void
	{
		var cache;

		let this->internalCache[key] = access,
		    cache                    = this->cache;

		if cache != null {
			cache->set("_PHF_", this->internalCache);
		}
	}

	public function setCache(<CacheAdapterInterface> cache) -> <AdapterInterface>
	{
		let this->cache = cache;

		if this->internalCache === null {
			let this->internalCache = cache->get("_PHF_");
		}

		return this;
	}

	/**
	 * Throws an internal exception
	 */
	protected function throwFirewallException(string message, int exceptionCode = 0) -> bool | void
	{
		var exception;

		let exception = new Exception(message, exceptionCode);

		if this->handleException(exception) === false {
			return false;
		}

		throw exception;
	}
}
