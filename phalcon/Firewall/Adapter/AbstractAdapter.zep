
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Firewall\Adapter;

use Closure;
use Phalcon\Acl\Enum;
use Phalcon\Acl\RoleAware;
use Phalcon\Cache\Adapter\AdapterInterface as CacheAdapterInterface;
use Phalcon\Di\DiInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Firewall\Exception;
use Phalcon\Mvc\Dispatcher;

/**
 * Adapter for Phalcon\Firewall adapters
 */
abstract class AbstractAdapter implements AdapterInterface, EventsAwareInterface
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
    protected alwaysResolvingRole = false;

    /**
     * Cache for caching access
     * @var <CacheAdapterInterface>
     */
    protected cache;

    /**
     * Default access
     * @var int
     */
    protected defaultAccess = Enum::DENY { get };

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
    public function getRoleCallback() -> <Closure>
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
     * Sets the cache adapter
     */
    public function setCache(<CacheAdapterInterface> cache) -> <AdapterInterface>
    {
        let this->cache = cache;

        if this->internalCache === null {
            let this->internalCache = cache->get("_PHF_");
        }

        return this;
    }

    /**
     * Sets the default access level (Phalcon\Acl\Enum::ALLOW or Phalcon\Acl\Enum::DENY)
     */
    public function setDefaultAccess(int defaultAccess) -> <AdapterInterface>
    {
        let this->defaultAccess = defaultAccess;

        return this;
    }

    /**
     * Sets the events manager
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> void
    {
        let this->eventsManager = eventsManager;
    }

    /**
     * Sets role callback to fetch role name
     */
    public function setRoleCallback(var callback) -> <AdapterInterface>
    {
        if !is_callable(callback) {
            throw new Exception("Role callback must be function.");
        }
        let this->roleCallback = callback;

        return this;
    }

    /**
     * Sets always resolving role option
     */
    public function setAlwaysResolvingRole(bool alwaysResolvingRole) -> void
    {
        let this->alwaysResolvingRole = alwaysResolvingRole;
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
    protected function handleException(<\Exception> exception)
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
    )
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

    /**
     * Throws an internal exception
     */
    protected function throwFirewallException(string message, int exceptionCode = 0) -> bool
    {
        var exception;

        let exception = new Exception(message, exceptionCode);

        if this->handleException(exception) === false {
            return false;
        }

        throw exception;
    }
}
