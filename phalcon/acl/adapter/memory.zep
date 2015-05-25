
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

namespace Phalcon\Acl\Adapter;

use Phalcon\Acl;
use Phalcon\Acl\Adapter;
use Phalcon\Acl\Role;
use Phalcon\Acl\Resource;
use Phalcon\Acl\Exception;
use Phalcon\Events\Manager as EventsManager;

/**
 * Phalcon\Acl\Adapter\Memory
 *
 * Manages ACL lists in memory
 *
 *<code>
 *
 *	$acl = new \Phalcon\Acl\Adapter\Memory();
 *
 *	$acl->setDefaultAction(Phalcon\Acl::DENY);
 *
 *	//Register roles
 *	$roles = array(
 *		'users' => new \Phalcon\Acl\Role('Users'),
 *		'guests' => new \Phalcon\Acl\Role('Guests')
 *	);
 *	foreach ($roles as $role) {
 *		$acl->addRole($role);
 *	}
 *
 *	//Private area resources
 *	$privateResources = array(
 *		'companies' => array('index', 'search', 'new', 'edit', 'save', 'create', 'delete'),
 *		'products' => array('index', 'search', 'new', 'edit', 'save', 'create', 'delete'),
 *		'invoices' => array('index', 'profile')
 *	);
 *	foreach ($privateResources as $resource => $actions) {
 *		$acl->addResource(new Phalcon\Acl\Resource($resource), $actions);
 *	}
 *
 *	//Public area resources
 *	$publicResources = array(
 *		'index' => array('index'),
 *		'about' => array('index'),
 *		'session' => array('index', 'register', 'start', 'end'),
 *		'contact' => array('index', 'send')
 *	);
 *	foreach ($publicResources as $resource => $actions) {
 *		$acl->addResource(new Phalcon\Acl\Resource($resource), $actions);
 *	}
 *
 *	//Grant access to public areas to both users and guests
 *	foreach ($roles as $role){
 *		foreach ($publicResources as $resource => $actions) {
 *			$acl->allow($role->getName(), $resource, '*');
 *		}
 *	}
 *
 *	//Grant access to private area to role Users
 *	foreach ($privateResources as $resource => $actions) {
 * 		foreach ($actions as $action) {
 *			$acl->allow('Users', $resource, $action);
 *		}
 *	}
 *
 *</code>
 */
class Memory extends Adapter
{

	/**
	 * Roles Names
	 *
	 * @var mixed
	 */
	protected _rolesNames;

	/**
	 * Roles
	 *
	 * @var mixed
	 */
	protected _roles;

	/**
	 * Resource Names
	 *
	 * @var mixed
	 */
	protected _resourcesNames;

	/**
	 * Resources
	 *
	 * @var mixed
	 */
	protected _resources;

	/**
	 * Access
	 *
	 * @var mixed
	 */
	protected _access;

	/**
	 * Role Inherits
	 *
	 * @var mixed
	 */
	protected _roleInherits;

	/**
	 * Access List
	 *
	 * @var mixed
	 */
	protected _accessList;

	/**
	 * Phalcon\Acl\Adapter\Memory constructor
	 */
	public function __construct()
	{
		let this->_resourcesNames = ["*": true];
		let this->_accessList = ["*!*": true];
	}

	/**
	 * Adds a role to the ACL list. Second parameter allows inheriting access data from other existing role
	 *
	 * Example:
	 * <code>
	 * 	$acl->addRole(new Phalcon\Acl\Role('administrator'), 'consultant');
	 * 	$acl->addRole('administrator', 'consultant');
	 * </code>
	 *
	 * @param  array|string accessInherits
	 */
	public function addRole(role, accessInherits = null) -> boolean
	{
		var roleName, roleObject;

		if typeof role == "object" {
			let roleName = role->getName();
			let roleObject = role;
		} else {
			let roleName = role;
			let roleObject = new Role(role);
		}

		if isset this->_rolesNames[roleName] {
			return false;
		}

		let this->_roles[] = roleObject;
		let this->_rolesNames[roleName] = true;
		let this->_access[roleName . "!*!*"] = this->_defaultAccess;

		if accessInherits != null {
			return this->addInherit(roleName, accessInherits);
		}

		return true;
	}

	/**
	 * Do a role inherit from another existing role
	 */
	public function addInherit(string roleName, var roleToInherit) -> boolean
	{
		var roleInheritName, rolesNames, deepInheritName;

		let rolesNames = this->_rolesNames;
		if !isset rolesNames[roleName] {
			throw new Exception("Role '" . roleName . "' does not exist in the role list");
		}

		if typeof roleToInherit == "object" {
			let roleInheritName = roleToInherit->getName();
		} else {
			let roleInheritName = roleToInherit;
		}

		/**
		 * Deep inherits
		 */
		if isset this->_roleInherits[roleInheritName] {
			for deepInheritName in this->_roleInherits[roleInheritName] {
				this->addInherit(roleName, deepInheritName);
			}
		}

		/**
		 * Check if the role to inherit is valid
		 */
		if !isset rolesNames[roleInheritName] {
			throw new Exception("Role '" . roleInheritName . "' (to inherit) does not exist in the role list");
		}

		if roleName == roleInheritName {
			return false;
		}

		if !isset this->_roleInherits[roleName] {
			let this->_roleInherits[roleName] = true;
		}

		let this->_roleInherits[roleName][] = roleInheritName;

		return true;
	}

	/**
	 * Check whether role exist in the roles list
	 */
	public function isRole(string roleName) -> boolean
	{
		return isset this->_rolesNames[roleName];
	}

	/**
	 * Check whether resource exist in the resources list
	 */
	public function isResource(string resourceName) -> boolean
	{
		return isset this->_resourcesNames[resourceName];
	}

	/**
	 * Adds a resource to the ACL list
	 *
	 * Access names can be a particular action, by example
	 * search, update, delete, etc or a list of them
	 *
	 * Example:
	 * <code>
	 * //Add a resource to the the list allowing access to an action
	 * $acl->addResource(new Phalcon\Acl\Resource('customers'), 'search');
	 * $acl->addResource('customers', 'search');
	 *
	 * //Add a resource  with an access list
	 * $acl->addResource(new Phalcon\Acl\Resource('customers'), array('create', 'search'));
	 * $acl->addResource('customers', array('create', 'search'));
	 * </code>
	 *
	 * @param   Phalcon\Acl\Resource|string resourceValue
	 * @param   array|string accessList
	 */
	public function addResource(var resourceValue, var accessList) -> boolean
	{
		var resourceName, resourceObject;

		if typeof resourceValue == "object" {
			let resourceName   = resourceValue->getName();
			let resourceObject = resourceValue;
		 } else {
			let resourceName   = resourceValue;
			let resourceObject = new $Resource(resourceName);
		 }

		 if !isset this->_resourcesNames[resourceName] {
			let this->_resources[] = resourceObject;
			let this->_resourcesNames[resourceName] = true;
		 }

		 return this->addResourceAccess(resourceName, accessList);
	}

	/**
	 * Adds access to resources
	 *
	 * @param array|string accessList
	 */
	public function addResourceAccess(string resourceName, var accessList) -> boolean
	{
		var accessName, accessKey, exists;

		if !isset this->_resourcesNames[resourceName] {
			throw new Exception("Resource '" . resourceName . "' does not exist in ACL");
		}

		if typeof accessList != "array" && typeof accessList != "string" {
			throw new Exception("Invalid value for accessList");
		}

		let exists = true;
		if typeof accessList == "array" {
			for accessName in accessList {
				let accessKey = resourceName . "!" . accessName;
				if !isset accessList[accessKey] {
					let this->_accessList[accessKey] = exists;
				}
			}
		} else {
			let accessKey = resourceName . "!" . accessList;
			if !isset accessList[accessKey] {
				let this->_accessList[accessKey] = exists;
			}
		}

		return true;
	}

	/**
	 * Removes an access from a resource
	 *
	 * @param array|string accessList
	 */
	public function dropResourceAccess(string resourceName, var accessList)
	{
		var accessName, accessKey;

		if typeof accessList == "array" {
			for accessName in accessList {
				let accessKey = resourceName . "!" . accessName;
				if isset accessList[accessKey] {
					unset this->_accessList[accessKey];
				}
			}
		} else {
			if typeof accessList == "string" {
				let accessKey = resourceName . "!" . accessName;
				if isset accessList[accessKey] {
					unset this->_accessList[accessKey];
				}
			}
		}
	 }

	/**
	 * Checks if a role has access to a resource
	 */
	protected function _allowOrDeny(string roleName, string resourceName, var access, var action)
	{
		var defaultAccess, accessList, accessName, accessKey, accessKeyAll, internalAccess;

		if !isset this->_rolesNames[roleName] {
			throw new Exception("Role '" . roleName . "' does not exist in ACL");
		}

		if !isset this->_resourcesNames[resourceName] {
			throw new Exception("Resource '" . resourceName . "' does not exist in ACL");
		}

		let defaultAccess = this->_defaultAccess;
		let accessList = this->_accessList;
		let internalAccess = this->_access;

		if typeof access == "array" {

			for accessName in access {
				let accessKey = resourceName . "!" . accessName;
				if !isset accessList[accessKey] {
					throw new Exception("Access '" . accessName . "' does not exist in resource '" . resourceName . "'");
				}
			}

			for accessName in access {

				let accessKey = roleName . "!" .resourceName . "!" . accessName;
				let this->_access[accessKey] = action;

				if accessName != "*" {
					let accessKeyAll = roleName . "!" . resourceName . "!*";
					if isset accessList[accessKeyAll] {
						let this->_access[accessKeyAll] = defaultAccess;
					}
				}
			}

		} else {

			if access != "*" {
				let accessKey = resourceName . "!" . access;
				if !isset accessList[accessKey] {
					throw new Exception("Access '" . access . "' does not exist in resource '" . resourceName . "'");
				}
			}

			let accessKey = roleName . "!" . resourceName . "!" . access;

			/**
			 * Define the access action for the specified accessKey
			 */
			let this->_access[accessKey] = action;

			if access != "*" {
				let accessKey = roleName . "!" . resourceName . "!*";

				/**
				 * If there is no default action for all the rest actions in the resource set the
				 * default one
				 */
				if !isset accessList[accessKey] {
					let this->_access[accessKey] = this->_defaultAccess;
				}
			}

		}
	}

	/**
	 * Allow access to a role on a resource
	 *
	 * You can use '*' as wildcard
	 *
	 * Example:
	 * <code>
	 * //Allow access to guests to search on customers
	 * $acl->allow('guests', 'customers', 'search');
	 *
	 * //Allow access to guests to search or create on customers
	 * $acl->allow('guests', 'customers', array('search', 'create'));
	 *
	 * //Allow access to any role to browse on products
	 * $acl->allow('*', 'products', 'browse');
	 *
	 * //Allow access to any role to browse on any resource
	 * $acl->allow('*', '*', 'browse');
	 * </code>
	 */
	public function allow(string roleName, string resourceName, var access)
	{
		var innerRoleName;

		if roleName != "*" {
			return this->_allowOrDeny(roleName, resourceName, access, Acl::ALLOW);
		} else {
			for innerRoleName, _ in this->_rolesNames {
				this->_allowOrDeny(innerRoleName, resourceName, access, Acl::ALLOW);
			}
		}
	}

	/**
	 * Deny access to a role on a resource
	 *
	 * You can use '*' as wildcard
	 *
	 * Example:
	 * <code>
	 * //Deny access to guests to search on customers
	 * $acl->deny('guests', 'customers', 'search');
	 *
	 * //Deny access to guests to search or create on customers
	 * $acl->deny('guests', 'customers', array('search', 'create'));
	 *
	 * //Deny access to any role to browse on products
	 * $acl->deny('*', 'products', 'browse');
	 *
	 * //Deny access to any role to browse on any resource
	 * $acl->deny('*', '*', 'browse');
	 * </code>
	 */
	public function deny(string roleName, string resourceName, var access)
	{
		var innerRoleName;

		if roleName != "*" {
			return this->_allowordeny(roleName, resourceName, access, Acl::DENY);
		} else {
			for innerRoleName, _ in this->_rolesNames {
				this->_allowordeny(innerRoleName, resourceName, access, Acl::DENY);
			}
		}
	}

	/**
	 * Check whether a role is allowed to access an action from a resource
	 *
	 * <code>
	 * //Does andres have access to the customers resource to create?
	 * $acl->isAllowed('andres', 'Products', 'create');
	 *
	 * //Do guests have access to any resource to edit?
	 * $acl->isAllowed('guests', '*', 'edit');
	 * </code>
	 */
	public function isAllowed(string roleName, string resourceName, string access) -> boolean
	{
		var eventsManager, accessList, accessKey,
			haveAccess = null, roleInherits, inheritedRole, rolesNames,
			inheritedRoles;

		let this->_activeRole = roleName;
		let this->_activeResource = resourceName;
		let this->_activeAccess = access;
		let accessList = this->_access;
		let eventsManager = <EventsManager> this->_eventsManager;

		if typeof eventsManager == "object" {
			if eventsManager->fire("acl:beforeCheckAccess", this) === false {
				return false;
			}
		}

		/**
		 * Check if the role exists
		 */
		let rolesNames = this->_rolesNames;
		if !isset rolesNames[roleName] {
			return (this->_defaultAccess == Acl::ALLOW);
		}

		let accessKey = roleName . "!" . resourceName . "!" . access;

		/**
		 * Check if there is a direct combination for role-resource-access
		 */
		if isset accessList[accessKey] {
			let haveAccess = accessList[accessKey];
		}

		/**
		 * Check in the inherits roles
		 */
		if haveAccess == null {

			let roleInherits = this->_roleInherits;
			if fetch inheritedRoles, roleInherits[roleName] {
				if typeof inheritedRoles == "array" {
					for inheritedRole in inheritedRoles {
						let accessKey = inheritedRole . "!" . resourceName . "!" . access;

						/**
						 * Check if there is a direct combination in one of the inherited roles
						 */
						if isset accessList[accessKey] {
							let haveAccess = accessList[accessKey];
						}
					}
				}
			}
		}

		/**
		 * If access wasn't found yet, try role-resource-*
		 */
		if haveAccess == null {

			let accessKey =  roleName . "!" . resourceName . "!*";

			/**
			 * In the direct role
			 */
			if isset accessList[accessKey] {
				let haveAccess = accessList[accessKey];
			} else {
				if typeof inheritedRoles == "array" {
					for inheritedRole in inheritedRoles {
						let accessKey = inheritedRole . "!" . resourceName . "!*";

						/**
						 * In the inherited roles
						 */
						if isset accessList[accessKey] {
							let haveAccess = accessList[accessKey];
							break;
						}
					}
				}
			}
		}

		/**
		 * If access wasn't found yet, try role-*-*
		 */
		if haveAccess == null {

			let accessKey =  roleName . "!*!*";

			/**
			 * Try in the direct role
			 */
			if isset accessList[accessKey] {
				let haveAccess = accessList[accessKey];
			} else {
				if typeof inheritedRoles == "array" {
					for inheritedRole in inheritedRoles {
						let accessKey = inheritedRole . "!*!*";

						/**
						 * In the inherited roles
						 */
						 if isset accessList[accessKey] {
							let haveAccess = accessList[accessKey];
							break;
						 }
					}
				}
			}
		}

		let this->_accessGranted = haveAccess;
		if typeof eventsManager == "object" {
			eventsManager->fire("acl:afterCheckAccess", this);
		}

		if haveAccess == null {
			return false;
		}

		return (haveAccess == Acl::ALLOW);
	}

	/**
	 * Return an array with every role registered in the list
	 */
	public function getRoles() -> <Role[]>
	{
		return this->_roles;
	}

	/**
	 * Return an array with every resource registered in the list
	 */
	public function getResources() -> <$Resource[]>
	{
		return this->_resources;
	}
}
