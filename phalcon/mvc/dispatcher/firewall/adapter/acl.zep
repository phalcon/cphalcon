
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
use Phalcon\Di;
use Phalcon\Events\ManagerInterface;

/**
 * Phalcon\Mvc\Dispatcher\Firewall\Adapter\Acl
 *
 * Firewall which depends on acl an dispatcher
 */
class Acl extends Adapter
{
	/**
	 * Acl service name
	 * @var string
	 */
	protected _aclServiceName { get, set };

	/**
	 * Name of parameter in function defined in isAllowed method - must be same for every function currently
	 * @var string
	 */
	protected _boundModelParameterName { get, set};

	/**
	 * Bound model
	 * @var object
	 */
	protected _boundModel = null;

	/**
	 * Parameter for using with multi module application
	 * @var boolean
	 */
	protected _multiModuleConfiguration = false;

	/**
	 * Separator between module name and controller prefix
	 * @var string
	 */
	protected _moduleSeparator = ":" {get, set};

	/**
	 * Phalcon\Mvc\Dispatcher\Firewall\Adapter\Acl constructor
	 *
	 * @param string aclServiceName
	 * @param string boundModelParameterName
	 */
	public function __construct(string aclServiceName, string boundModelParameterName = null)
	{
		let this->_aclServiceName = aclServiceName;
		let this->_boundModelParameterName = boundModelParameterName;
	}

	/**
	 * Returns multiModuleConfiguration
	 * @return boolean
	 */
	public function isMultiModuleConfiguration() -> boolean
	{
		return this->_multiModuleConfiguration;
	}

	/**
	 * Sets multiModuleConfiguration
	 */
	public function useMultiModuleConfiguration(boolean multiModuleConfiguration)
	{
		let this->_multiModuleConfiguration = multiModuleConfiguration;
		return this;
	}

	protected function afterBinding(<Event> event, <DispatcherInterface> dispatcher, var data)
	{
		if empty this->_boundModelParameterName {
			throw new Exception("You need to set 'boundModelParameterName' to use ACL Firewall on dispatch:afterBinding event");
		}
		var boundModel;
		let boundModel = dispatcher->getBoundModel();
		if boundModel != null {
			let this->_boundModel = boundModel;
		}
		let this->_dispatcher = dispatcher;
		return this->handleDispatcher(dispatcher);
	}

	protected function beforeExecuteRoute(<Event> event, <DispatcherInterface> dispatcher, var data)
	{
		let this->_dispatcher = dispatcher;
		return this->handleDispatcher(dispatcher);
	}

	protected function handleDispatcher(<DispatcherInterface> dispatcher)
	{
		var role, identity, actionName, eventsManager, acl, aclServiceName, aclRole, aclAccess, defaultAccess, parameters, boundModelParameterName, value, dependencyInjector, controllerName, moduleName, moduleSeparator;
		string resourceName; // there were some seg fault when result from ucfirst was assigned to var
		let dependencyInjector = dispatcher->getDI();
		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injector container is required to obtain ACL service");
		}
		let defaultAccess = (bool)this->_defaultAccess;
		let parameters = [];
		let identity = call_user_func(this->_roleCallback);
		let eventsManager = <ManagerInterface> this->_eventsManager;
		let controllerName = get_class(dispatcher->getActiveController());
		if !this->_multiModuleConfiguration {
			let resourceName = ucfirst(dispatcher->getControllerName());
		}
		else {
			let moduleSeparator = this->_moduleSeparator;
			let moduleName = dispatcher->getModuleName();
			let resourceName = moduleName.moduleSeparator.ucfirst(dispatcher->getControllerName());
		}
		let actionName = dispatcher->getActionName();
		if empty identity {
			throw new Exception("Function defined as roleCallback must return something.");
		}
		if typeof identity == "string" {
			let role = identity;
		}
		elseif typeof identity == "object" {
			if !(identity instanceof RoleAware) {
				throw new Exception("Role passed as object must implement 'Phalcon\\Acl\\RoleAware'");
			}
			let role = identity;
		}
		else {
			throw new Exception("When using ACL service as firewall configuration you can only pass role as string or object implementing 'Phalcon\\Acl\\RoleAware'.");
		}
		let aclServiceName = this->_aclServiceName;
		let acl = dependencyInjector->get(aclServiceName);
		if typeof acl != "object" || !(acl instanceof \Phalcon\Acl\AdapterInterface) {
			throw new Exception("You need to add acl service to dependency injector container which is implementing 'Phalcon\\Acl\\AdapterInterface'");
		}
		// handle role as object
		if typeof identity == "object" {
			let aclRole = role->getRoleName();
		}
		else {
			let aclRole = role;
		}
		// check if role exist
		if !acl->isRole(aclRole) {
			throw new Exception("Role ".aclRole." doesn't exist in ACL");
		}
		// if resource doesn't exist check defaultAccess
		if !acl->isResource(resourceName) {
			let value = this->fireEventOrThrowException(aclRole, actionName, controllerName, defaultAccess);
			if value === false {
				return false;
			}
		}
		if this->_boundModel != null {
			let boundModelParameterName = this->_boundModelParameterName;
			let parameters[boundModelParameterName] = this->_boundModel;
		}
		if empty parameters {
			let aclAccess = acl->isAllowed(role, resourceName, actionName);
		}
		else {
			let aclAccess = acl->isAllowed(role, resourceName, actionName, parameters);
		}
		if aclAccess {
			if typeof eventsManager == "object" {
				eventsManager->fire("firewall:afterCheck",this);
			}
		}
		else {
			// well, acl is returning false if actionName will not exist, so in this case we will check default access
			let value = this->fireEventOrThrowException(aclRole, actionName, controllerName, defaultAccess);
			if value === false {
				return false;
			}
		}
	}
}
