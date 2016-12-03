
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


namespace Phalcon\Firewall\Adapter\Micro;

use Phalcon\Firewall\Adapter;
use Phalcon\Firewall\Exception;
use Phalcon\Events\Event;
use Phalcon\Acl\RoleAware;
use Phalcon\Mvc\Micro;
use Phalcon\Di;
use Phalcon\Events\ManagerInterface;
use Phalcon\Cache\BackendInterface
use Phalcon\Mvc\Router;

/**
 * Phalcon\Mvc\Dispatcher\Firewall\Adapter\Micro\Acl
 *
 * Firewall for Phalcon\Mvc\Micro which depends on acl
 */
class Acl extends Adapter
{
	/**
	 * Acl service name
	 * @var string
	 */
	protected _aclServiceName { get, set };

	/**
	 * By default using route names which are required, you can change it to false to use route patterns
	 * @var boolean
	 */
	protected _routeNameConfiguration = true { set };

	/**
	 * Resource name used to acquire access, be default it's Micro
	 * @var string
	 */
	protected _resourceName = "Micro" { get, set };

	/**
	 * Router object
	 * @var mixed
	 */
	protected _router;

	/**
	 * Micro object
	 * @var mixed
	 */
	protected _micro;

	/**
	 * Function returning string for role cache key
	 * @var string
	 */
	protected _roleCacheCallback { get, set };

	/**
	 * Bound models
	 * @var array
	 */
	protected _boundModels;

	/**
	 * Property used for setting different key names in associated acl function than got from Binder
	 */
	protected _boundModelsKeyMap { get, set };

	/**
	 * Phalcon\Firewall\Adapter\Micro\Acl constructor
	 *
	 * @param string aclServiceName
	 * @param string boundModelParameterName
	 */
	public function __construct(string aclServiceName, array boundModelsKeyMap = null)
	{
		let this->_aclServiceName = aclServiceName;
		let this->_boundModelsKeyMap = boundModelsKeyMap;
	}

	/**
	 * Gets micro
	 */
	public function getMicro() -> <Micro>
	{
		return this->_micro;
	}

	/**
	 * Gets route name configuration
	 */
	public function isRouteNameConfiguration() -> boolean
	{
		return this->_routeNameConfiguration;
	}

	protected function afterBinding(<Event> event, <Micro> micro, var data)
	{
		let this->_boundModels = micro->getBoundModels();
		let this->_router = micro->getRouter();
		let this->_micro = micro;

		return this->handleRouter(micro);
	}

	protected function beforeExecuteRoute(<Event> event, <Micro> micro, var data)
	{
		let this->_router = micro->getRouter();
		let this->_micro = micro;

		return this->handleRouter(micro);
	}

	protected function handleRouter(<Micro> micro)
	{
		var role, identity, eventsManager, acl, aclServiceName, aclRole, aclAccess, defaultAccess, resourceName,
			parameters, boundModelParameterName, value, dependencyInjector, boundModel, boundModelKey, boundModels,
			boundModelsKeyMap, boundModelKeyMap, cacheKey, originalValues, value, route, routePattern, routeUrl,
			roleCacheKey;
		string resourceName; // there were some seg fault when result from ucfirst was assigned to var

		let dependencyInjector = micro->getDI();
		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injector container is required to obtain ACL service");
		}

		let defaultAccess = (bool)this->_defaultAccess;
		let parameters = [];
		let eventsManager = <ManagerInterface> this->_eventsManager;
		let route = this->_router->getMatchedRoute();
		let boundModels = this->_boundModels;
		let boundModelsKeyMap = this->_boundModelsKeyMap;

		if this->_routeNameConfiguration {
			let actionName = route->getName();
		} else {
			let actionName = route->getPattern();
		}
		this->callRoleCallback();

		let aclRole = this->_activeRole;
		let resourceName = this->_resourceName;

		if typeof aclRole != "string" {
			throw new Exception("When using ACL service as firewall configuration you can pass role only as string or object implementing 'Phalcon\\Acl\\RoleAware'.");
		}

		// handle role as object
		if typeof this->_activeIdentity == "object" {
			let role = this->_activeIdentity;
		} else {
			let role = aclRole;
		}

		let cacheKey = aclRole."!".resourceName."!".actionName;
		let originalValues = micro->getModelBinder()->getOriginalValues();
		if typeof role == "object" && this->_roleCacheCallback != null {
			let roleCacheKey = {this->_roleCacheCallback}();
		}
		let aclAccess = this->getAccessFromCache(cacheKey, originalValues, roleCacheKey);

		if aclAccess === null {
			let aclServiceName = this->_aclServiceName;
			let acl = dependencyInjector->get(aclServiceName);
			if typeof acl != "object" || !(acl instanceof \Phalcon\Acl\AdapterInterface) {
				throw new Exception("You need to add acl service to dependency injector container which is implementing 'Phalcon\\Acl\\AdapterInterface'");
			}

			// check if role exist
			if !acl->isRole(aclRole) {
				throw new Exception("Role ".aclRole." doesn't exist in ACL");
			}

			// if resource doesn't exist check against firewall defaultAccess
			if !acl->isResource(resourceName) {
				let value = this->fireEventOrThrowException(aclRole, actionName, resourceName, defaultAccess);
				if value === false {
					return false;
				}
			}

			if boundModels != [] {
				for boundModelKey, boundModel in boundModels {
					if fetch boundModelKeyMap, boundModelsKeyMap[boundModelKey] {
						let parameters[boundModelKeyMap] = boundModel;
					} else {
						let parameters[boundModelKey] = boundModel;
					}
				}
			}

			if empty parameters {
				let aclAccess = acl->isAllowed(role, resourceName, actionName);
			} else {
				let aclAccess = acl->isAllowed(role, resourceName, actionName, parameters);
			}

			let cacheKey = acl->getActiveKey();

			if acl->getActiveFunction() != null {
				if acl->getActiveFunctionCustomArgumentsCount > 0 && !empty parameters {
					let cacheKey .= "!".join("!", originalValues);
				}
				if this->_roleCacheCallback != null && typeof role == "object" {
					let roleCacheKey = {this->_roleCacheCallback}(role);
					let cacheKey .= "!".roleCacheKey;
				}
			}

			this->saveAccessInCache(cacheKey, aclAccess);
		}

		let value = this->fireEventOrThrowException(aclRole, actionName, controllerName, aclAccess);

		if value === false {
			return false;
		}
	}

	protected function saveAccessInCache(string! key, boolean access) -> void
	{
		var explodedKey, activeRole;

		let explodedKey = explode("!", key);
		let activeRole = this->_activeRole;

		/**
		 * We are not saving info about inherited role, if access was got from inherited role, save it as an actual role to keep things simple
		 */
		if explodedKey[0] != activeRole {
			let explodedKey[0] = activeRole;
			let key = join("!", explodedKey);
		}

		parent::saveAccessInCache(key, access);
	}

	protected function getAccessFromCache(string! key, array originalValues = null, string roleCacheKey = null) -> boolean|null
	{
		var explodedKey, access, keyWithValues, originalKeysJoin;

		if roleCacheKey != null {
			let roleCacheKey = "!".roleCacheKey;
		}

		let explodedKey = explode("!", key);

		/**
		 * If this is inherited role we change it to our active role to keep things simpler
		 */
		if explodedKey[0] != this->_activeRole {
			let explodedKey[0] = this->_activeRole;
			let key = join("!", explodedKey);
		}

		/**
		 * If there is original values from binding then use it first
		 */
		if originalValues != [] {
			let originalKeysJoin = join("!", originalValues);
			let keyWithValues = key."!".originalValues.roleCacheKey;
			let access = parent::getAccessFromCache(keyWithValues);

			if access !== null {
				return access;
			}

			let access = parent::getAccessFromCache(explodedKey[0]."!".explodedKey[1]."!*!".originalKeysJoin.roleCacheKey);

			if access !== null {
				return access
			}
			let access = parent::getAccessFromCache(explodedKey[0]."!*!*!".originalKeysJoin.roleCacheKey);
		}

		if access !== null {
			return access;
		}

		let access = parent::getAccessFromCache(key.roleCacheKey);

		if access !== null {
			return access;
		}

		/**
		 * Try role-resource-*
		 */

		let access = parent::getAccessFromCache(explodedKey[0]."!".explodedKey[1]."!*".roleCacheKey);

		if access !== null {
			return access;
		}

		/**
		 * Try role-*-*
		 */

		let access = parent::getAccessFromCache(explodedKey[0]."!*!*".roleCacheKey);

		return access;
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
			if this->_routeNameConfiguration {
				return this->_throwFirewallException("Role name ".roleName." doesn't have access to route called ".actionName, 403);
			} else {
				return this->_throwFirewallException("Role name ".roleName." doesn't have access to route with pattern ".actionName, 403);
			}
		}
	}
}
