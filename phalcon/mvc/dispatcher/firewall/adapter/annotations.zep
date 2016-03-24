
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


namespace Phalcon\Mvc\Dispatcher\Firewall\Adapter;

use Phalcon\Mvc\Dispatcher\Firewall\Adapter;
use Phalcon\Mvc\Dispatcher\Firewall\Exception;
use Phalcon\Events\Event;
use Phalcon\Acl\RoleAware;
use Phalcon\Mvc\DispatcherInterface;
use ReflectionClass;
use Phalcon\Annotations\AdapterInterface;
use Phalcon\Events\ManagerInterface;

/**
 * Phalcon\Mvc\Dispatcher\Firewall\Adapter\Annotations
 *
 * Firewall which depends on annotations and dispatcher
 */
class Annotations extends Adapter
{
	/**
	 * Adapter for annotations
	 * @var mixed
	 */
	protected _annotationsAdapter {get, set};

	/**
	 * Phalcon\Mvc\Dispatcher\Firewall\Adapter\Annotations constructor
	 *
	 * @param mixed annotationsAdapter
	 */
	public function __construct(<AdapterInterface> annotationsAdapter)
	{
		let this->_annotationsAdapter = annotationsAdapter;
	}

	protected function beforeExecuteRoute(<Event> event, <DispatcherInterface> dispatcher, var data)
	{
		var identity, role, controllerName, actionName, controllerAccess, actionAccess, defaultAccess, eventsManager, value;
		let this->_dispatcher = dispatcher;
		let defaultAccess = (bool)this->_defaultAccess;
		let identity = call_user_func(this->_roleCallback);
		let eventsManager = <ManagerInterface> this->_eventsManager;
		let controllerName = get_class(dispatcher->getActiveController());
		let actionName = dispatcher->getActionName();
		if typeof identity == "string" || typeof identity == "array" {
			let role = identity;
		}
		elseif typeof identity == "object" && identity instanceof RoleAware {
			let role = identity->getRoleName();
		}
		else {
			throw new Exception("When using firewall based on annotations you must pass role as string, array or object implementing 'RoleAware'.");
		}
		if this->_annotationsAdapter == null {
			throw new Exception("You need to set annotations adapter for firewall based on annotations configurator to work");
		}
		if typeof eventsManager == "object" {
			eventsManager->fire("firewall:beforeCheck",this);
		}
		let controllerAccess = this->checkControllerAnnotationAccess(controllerName, role);
		if typeof controllerAccess == "boolean" {
			let value = this->fireEventOrThrowException(role, actionName, controllerName, controllerAccess);
			if value === false {
				return false;
			}
		}
		else {
			let actionAccess = this->checkActionAnnotationAccess(controllerName, actionName, role);
			if typeof actionAccess == "boolean" {
				let value = this->fireEventOrThrowException(role, actionName, controllerName, actionAccess);
				if value === false {
					return false;
				}
			}
			else {
				let value = this->fireEventOrThrowException(role, actionName, controllerName, defaultAccess);
				if value === false {
					return false;
				}
			}
		}
	}

	protected function checkControllerAnnotationAccess(string controllerName, var role)
	{
		var annotationsAdapter, reflector, annotations;
		let annotationsAdapter = this->_annotationsAdapter;
		let reflector = annotationsAdapter->get(controllerName);
		let annotations = reflector->getClassAnnotations();
		return this->_checkAnnotations(annotations, role);
	}

	protected function checkActionAnnotationAccess(string controllerName, string actionName, var role)
	{
		var annotationsAdapter, annotations;
		let annotationsAdapter = this->_annotationsAdapter;
		let annotations = annotationsAdapter->getMethod(controllerName, actionName."Action");
		return this->_checkAnnotations(annotations, role);
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
		var numberArguments, annotationRoles;
		let numberArguments = annotation->numberArguments();
		if numberArguments === 1 {
			let annotationRoles = annotation->getArguments()[0];
			if typeof annotationRoles == "array" {
				if typeof role == "string" && in_array(role,annotationRoles) {
					return access;
				}
				elseif typeof role == "array" && (boolean)array_intersect(role,annotationRoles) {
					return access;
				}
				elseif access == false {
					return true;
				}
				return null;
			}
			elseif typeof annotationRoles == "string" {
				if typeof role == "string" && annotationRoles == role {
					return access;
				}
				elseif typeof role == "array" && in_array(annotationRoles,role) {
					return access;
				}
				elseif access == false {
					return true;
				}
				return null;
			}
			else {
				throw new Exception("Allowed or denied role must be provided as string or array of roles.");
			}
		}
		elseif numberArguments === 0 {
			return access;
		}
		else {
			throw new Exception("Allow or deny annotation expect one or none arguments");
		}
	}
}
