
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


namespace Phalcon\Firewall\Adapter;

use Phalcon\Firewall\Adapter;
use Phalcon\Firewall\Exception;
use Phalcon\Events\Event;
use Phalcon\Mvc\DispatcherInterface;
use ReflectionClass;
use Phalcon\Annotations\AdapterInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Cache\BackendInterface;

/**
 * Phalcon\Firewall\Adapter\Annotations
 *
 * Firewall which depends on annotations and dispatcher
 */
class Annotations extends Adapter
{
	/**
	 * Adapter for annotations
	 * @var mixed
	 */
	protected _annotationsAdapter { get, set };

	/**
	 * Number of active active arguments in active annotation
	 * @var int
	 */
	protected _activeArgumentsNumber = 0;

	/**
	 * Dispatcher
	 * @var mixed
	 */
	protected _dispatcher;

	/**
	 * Role for which access was granted
	 */
	protected _resolvedRole;

	/**
	 * Phalcon\Firewall\Adapter\Annotations constructor
	 *
	 * @param mixed annotationsAdapter
	 */
	public function __construct(<AdapterInterface> annotationsAdapter)
	{
		let this->_annotationsAdapter = annotationsAdapter;
	}

	/**
	 * Gets dispatcher
	 */
	public function getDispatcher() -> <Dispatcher>
	{
		return this->_dispatcher;
	}

	public function beforeExecuteRoute(<Event> event, <DispatcherInterface> dispatcher, var data)
	{
		var role, controllerName, actionName, defaultAccess, eventsManager, value, cacheKey, controllerClass,
			singleRole, access, dependencyInjector;

		let this->_activeArgumentsNumber = 0;
		let this->_dispatcher = dispatcher;
		let defaultAccess = (bool)this->_defaultAccess;
		let eventsManager = <ManagerInterface> this->_eventsManager;
		let controllerName = dispatcher->getControllerName();
		let controllerClass = dispatcher->getControllerClass();
		let actionName = dispatcher->getActionName();
		let this->_resolvedRole = null;
		let dependencyInjector = dispatcher->getDI();

		if this->_activeRole == null || this->_alwaysResolvingRole {
			let this->_activeRole = null;
			let this->_activeIdentity = null;
			this->callRoleCallback(dependencyInjector);
		}

		let role = this->_activeRole;
		if typeof role == "array" {
			for singleRole in role {
				let cacheKey = singleRole."!".controllerName."!".actionName;
				let access = this->getAccessFromCache(cacheKey);
				if typeof access == "boolean" {
					break;
				}
			}
		} else {
			let cacheKey = role."!".controllerName."!".actionName;
			let access = this->getAccessFromCache(cacheKey);
		}

		if typeof role != "string" && typeof role != "array" {
			throw new Exception("When using firewall based on annotations you must pass role as string, array or object implementing 'RoleAware'.");
		}

		if this->_annotationsAdapter == null {
			throw new Exception("You need to set annotations adapter for firewall based on annotations configurator to work");
		}
		if typeof eventsManager == "object" {
			eventsManager->fire("firewall:beforeCheck", this);
		}

		if typeof access != "boolean" {
			let access = this->checkControllerAnnotationAccess(controllerClass, controllerName, role);
			if typeof access != "boolean" {
				let access = this->checkActionAnnotationAccess(controllerClass, controllerName, actionName, role);
			}

			if typeof access != "boolean" {
				let access = defaultAccess;
				if typeof role == "array" {
                	for singleRole in role {
						this->saveAccessInCache(singleRole."!".controllerName."!".actionName, access);
					}
				} else {
					this->saveAccessInCache(role."!".controllerName."!".actionName, access);
				}
			}
		}

		let value = this->fireEventOrThrowException(role, actionName, controllerName, access);

		if value === false {
			return false;
		}
	}

	protected function checkControllerAnnotationAccess(string controllerClass, string controllerName, var role)
	{
		var annotationsAdapter, reflector, annotations, access, singleRole, resolvedRole;

		let annotationsAdapter = this->_annotationsAdapter;
		let reflector = annotationsAdapter->get(controllerClass);
		let annotations = reflector->getClassAnnotations();

		let access = this->_checkAnnotations(annotations, role);

		if typeof access == "boolean" {
			if this->_activeArgumentsNumber > 0 {
				let resolvedRole = this->_resolvedRole;
				if typeof resolvedRole == "array" {
					for singleRole in resolvedRole {
						this->saveAccessInCache(singleRole."!".controllerName."!*", access);
					}
				} else {
					this->saveAccessInCache(resolvedRole."!".controllerName."!*", access);
				}
			} else {
				this->saveAccessInCache("*!".controllerName."!*", access);
			}
		}

		return access;
	}

	protected function checkActionAnnotationAccess(string controllerClass, string controllerName, string actionName, var role)
	{
		var annotationsAdapter, annotations, access, singleRole, resolvedRole;

		let annotationsAdapter = this->_annotationsAdapter;
		let annotations = annotationsAdapter->getMethod(controllerClass, actionName."Action");

		let access = this->_checkAnnotations(annotations, role);

		if typeof access == "boolean" {
			if this->_activeArgumentsNumber > 0 {
				let resolvedRole = this->_resolvedRole;
				if typeof resolvedRole == "array" {
					for singleRole in resolvedRole {
						this->saveAccessInCache(singleRole."!".controllerName."!".actionName, access);
					}
				} else {
					this->saveAccessInCache(resolvedRole."!".controllerName."!".actionName, access);
				}
			} else {
				this->saveAccessInCache("*!".controllerName."!".actionName, access);
			}
		}

		return access;
	}

	protected function _checkAnnotations(var annotations, var role)
	{
		var returnAllow;

		if !empty annotations {
			if annotations->has("Allow") {
				let returnAllow = this->_handleAnnotation(annotations->get("Allow"), true, role);
				if typeof returnAllow == "boolean" {
					return returnAllow;
				}
			}
			if annotations->has("Deny") {
				let returnAllow = this->_handleAnnotation(annotations->get("Deny"), false, role);
				if typeof returnAllow == "boolean" {
					return returnAllow;
				}
			}
		}

		return null;
	}

	protected function _handleAnnotation(var annotation, boolean access, var role)
	{
		var numberArguments, annotationRoles, roleIntersect;

		let numberArguments = annotation->numberArguments();
		let this->_activeArgumentsNumber = numberArguments;
		if numberArguments === 1 {
			let annotationRoles = annotation->getArguments()[0];
			if typeof annotationRoles == "array" {
				if typeof role == "string" && in_array(role, annotationRoles) {
					let this->_resolvedRole = role;
					return access;
				} elseif typeof role == "array" {
					let roleIntersect = array_intersect(role, annotationRoles);
					if (boolean)roleIntersect {
						let this->_resolvedRole = roleIntersect;
						return access;
					}
				} elseif access == false {
					let this->_resolvedRole = role;
					return true;
				}

				return null;
			} elseif typeof annotationRoles == "string" {
				if typeof role == "string" && annotationRoles == role {
					let this->_resolvedRole = role;
					return access;
				} elseif typeof role == "array" && in_array(annotationRoles, role) {
					let this->_resolvedRole = annotationRoles;
					return access;
				} elseif access == false {
					let this->_resolvedRole = role;
					return true;
				}

				return null;
			} else {
				throw new Exception("Allowed or denied role must be provided as string or array of roles.");
			}
		} elseif numberArguments === 0 {
			let this->_resolvedRole = role;
			return access;
		} else {
			throw new Exception("Allow or deny annotation expect one or none arguments");
		}
	}

	protected function getAccessFromCache(string! key, array originalValues = null, string roleCacheKey = null) -> boolean|null
	{
		var explodedKey, access;

		let access = parent::getAccessFromCache(key);

		if access !== null {
			return access;
		}

		let explodedKey = explode("!", key);

		/**
		 * Try role-resource-*
		 */
		let access = parent::getAccessFromCache(explodedKey[0]."!".explodedKey[1]."!*");

		if access !== null {
			return access;
		}

		/**
		 * Try *-resource-action
		 */

		let access = parent::getAccessFromCache("*!".explodedKey[1]."!".explodedKey[2]);

		if access !== null {
			return access;
		}

		/**
		 * Try *-resource-*
		 */

		let access = parent::getAccessFromCache("*!".explodedKey[1]."!*");

		return access;
	}
}
