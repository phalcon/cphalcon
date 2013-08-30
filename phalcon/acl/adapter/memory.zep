
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

namespace Phalcon\Acl\Adapter;

/**
 * Phalcon\Acl\Adapter\Memory
 *
 * Manages ACL lists in memory
 *
 *<code>
 *
 *	$acl = new Phalcon\Acl\Adapter\Memory();
 *
 *	$acl->setDefaultAction(Phalcon\Acl::DENY);
 *
 *	//Register roles
 *	$roles = array(
 *		'users' => new Phalcon\Acl\Role('Users'),
 *		'guests' => new Phalcon\Acl\Role('Guests')
 *	);
 *	foreach ($roles as $role) {
 *		$acl->addRole($role);
 *	}
 *
 *	//Private area resources
 *  $privateResources = array(
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
 *  foreach ($publicResources as $resource => $actions) {
 *		$acl->addResource(new Phalcon\Acl\Resource($resource), $actions);
 *	}
 *
 *  //Grant access to public areas to both users and guests
 *	foreach ($roles as $role){
 *		foreach ($publicResources as $resource => $actions) {
 *			$acl->allow($role->getName(), $resource, '*');
 *		}
 *	}
 *
 *	//Grant access to private area to role Users
 *  foreach ($privateResources as $resource => $actions) {
 * 		foreach ($actions as $action) {
 *			$acl->allow('Users', $resource, $action);
 *		}
 *	}
 *
 *</code>
 */

class Memory
{

	/**
	 * Roles Names
	 * "@var mixed
	 */
	protected _rolesNames;

	/**
	 * Roles
	 * "@var mixed
	 */
	protected _roles;

	/**
	 * Resource Names
	 * "@var mixed
	 */
	protected _resourcesNames;

	/**
	 * Resources
	 * "@var mixed
	 */
	protected _resources;

	/**
	 * Access
	 * "@var mixed
	 */
	protected _access;

	/**
	 * Role Inherits
	 * "@var mixed
	 */
	protected _roleInherits;

	/**
	 * Access List
	 * "@var mixed
	 */
	protected _accessList;

	/**
	 * Phalcon\Acl\Adapter\Memory constructor
	 *
	 */
	 public function __construct()
	 {
	 	let this->_resourcesNames = ["*" => true];
		let this->_accessList = ["*!*" => true];
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
	 * @param  Phalcon\Acl\RoleInterface $role
	 * @param  array|string $accessInherits
	 * @return boolean
	 */
	 public function addRole(role, accessInherits)
	 {
	 	var roleName, object, defaultAccess;

		if typeof role == "object" {
			let roleName = role->getName();
			let object = role;
		} else {
			let roleName = role;
			let object = new Phalcon\Acl\Role(role);
		}

		if isset this->_rolesNames[roleName] {
			return false;
		}

		let this->_roles[] = object;
		let this->_rolesNames[] = roleName;

		let this->_access[] = roleName . "!*!*";

		if accessInherits == null {
			return this->addInherit(roleName, accessInherits);
		}

		return true;
	 }

	 /**
	 * Do a role inherit from another existing role
	 *
	 * @param string $roleName
	 * @param string $roleToInherit
	 */
	 public function addInherit(roleName, roleToInherit)
	 {
	 	var roleInheritName, rolesInherits, _roleInherits;

	 	let rolesNames = this->_rolesNames;
		if !rolesNames[roleName] {
			throw new Phalcon\Acl\Exception("Role '" . roleName . "' does not exist in the role list");
		}

		if typeof roleToInherit == "object" {
			let roleInheritName = roleToInherit->getName();
		} else {
			let roleInheritName = roleToInherit;
		}

		/**
		 * Check if the role to inherit is valid
		 */
		if !isset rolesNames[roleInheritName] {
			throw new Phalcon\Acl\Exception("Role '" . roleInheritName . "' (to inherit) does not exist in the role list");
		}

		if roleName == roleInheritName {
			return false;
		}

		if !this->_roleInherits[roleName] {
			let this->_roleInherits[roleName] = true;
		}

		let this->_roleInherits[roleName][] = this->_roleInherits;

		return true;
	 }

	 /**
	 * Check whether role exist in the roles list
	 *
	 * @param  string $roleName
	 * @return boolean
	 */
	 public function isRole(roleName)
	 {
	 	if isset this->_rolesNames[roleName] {
			return true;
		}
		return false;
	 }

	 /**
	 * Check whether resource exist in the resources list
	 *
	 * @param  string $resourceName
	 * @return boolean
	 */
	 public function isResource(resourceName)
	 {
	 	if isset this->_resourcesNames[resourceName] {
			return true;
		}
		return false;
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
	 * @param   Phalcon\Acl\Resource $resource
	 * @param   array $accessList
	 * @return  boolean
	 */
	 public function addResource(resource, accessList)
	 {
	 	var resourceName, object;

		if typeof resource == "object" {
			let resourceName = resource->getName();
			let object = resource;
		 } else {
			let resourceName = resource;
			let object = new Phalcon\Acl\Resource(resourceName);
		 }

		 if isset this->_resourcesNames[resourceName] {
			let this->_resources[]= object;
			let this->_resourcesNames[resourceName] = true;
		 }

		 return this->addResourceAccess(resourceName,accessList);
	 }

	 /**
	 * Adds access to resources
	 *
	 * @param string $resourceName
	 * @param mixed $accessList
	 */
	 public function addResourceAccess(resourceName, accessList)
	 {
	 	var accessName, accessKey;

	 	if isset this->_resourcesNames[resourceName] {
	 		throw new Phalcon\Acl\Exception("Resource '" . resourceName . "' does not exist in ACL");
	 	}

	 	if typeof accessList == "array" {
	 		for accessName in accessList {
	 			let accessKey = resourceName . "!" . accessName;
	 			if isset accessList[accessKey] {
	 				let this->_accessList[accessKey] = exists;
	 			}
	 		}
	 	} else {
	 		if typeof accessList == "string" {
	 			let accessKey = resourceName . "!" . accessName;
	 			if isset accessList[accessKey] {
	 				let this->_accessList[accessKey] = exists;
	 			}
	 		}
	 	}
	 }

	 /**
	 * Removes an access from a resource
	 *
	 * @param string $resourceName
	 * @param mixed $accessList
	 */
	 public function dropResourceAccess(resourceName, accessList)
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
	 *
	 * @param string $roleName
	 * @param string $resourceName
	 * @param string $access
	 * @param string $action
	 */
	 public function _allowOrDeny(roleName, resourceName, access, action)
	 {
	 	var defaultAccess, accessList, internalAccess,
	 		accessName, accessKey, accessKeyAll;

	 	if isset this->_rolesNames[roleName] {
	 		throw new Phalcon\Acl\Exception("Role \"" . roleName . "\" does not exist in ACL");
	 	}

	 	if isset this->_resourcesNames[resourceName] {
	 		throw new Phalcon\Acl\Exception("Resource '" . resourceName . "' does not exist in ACL");
	 	}

	 	let defaultAccess = this->_defaultAccess;
	 	let accessList = this->_access;

	 	if typeof access == "array" {

	 		for accessName in access {
	 			let accessKey = resourceName . "!" . accessName;
	 			if !isset accessList[accessKey] {
	 				throw new Phalcon\Acl\Exception("Acccess '" . accessName . "' does not exist in resource '" . resourceName . "'");
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
	 				throw new Phalcon\Acl\Exception("Acccess '" . access . "' does not exist in resource '" . resourceName . "'");
	 			}
	 		}

	 		let accessKey = roleName . "!" . resourceName . "!" . access;

	 		/**
			 * Define the access action for the specified accessKey
			 */
			 let this->_access[accesskey] = action;

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
	 *
	 * @param string $roleName
	 * @param string $resourceName
	 * @param mixed $access
	 */
	 public function allow(roleName, resourceName, access)
	 {
	 	return this->_allowordeny(roleName, resourceName, access, Phalcon\Acl::ALLOW);
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
	 *
	 * @param string $roleName
	 * @param string $resourceName
	 * @param mixed $access
	 * @return boolean
	 */
	 public function deny(roleName, resourceName, access)
	 {
	 	return this->_allowordeny(roleName, resourceName, access, Phalcon\Acl::DENY);
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
	 *
	 * @param  string $role
	 * @param  string $resource
	 * @param  string $access
	 * @return boolean
	 */
	 public function isAllowed(role, resource, access)
	 {
	 	var eventsManager, accessList, eventName, status, accessKey, haveAccess, roleInherits, inheritedRole;

	 	let this->_activeRole = role;
	 	let this->_activeResource = resource;
	 	let this->_activeAccess = resource;
	 	let accessList = this->_access;
	 	let eventsManager = this->_eventsManager;

	 	if typeof eventsManager == "object" {
	 		if eventsManager->fire("acl:beforeCheckAccess", this) === false {
	 			return status;
	 		}
	 	}

	 	/**
		 * Check if the role exists
		 */
		 if !isset this->_rolesNames[role] {
		 	return this->_defaultAccess;
		 }

		 let accessKey = role . "!" . resource . "!" . access;

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

		 	if isset this->_roleInherits[role] {
		 		let inheritedRoles = this->_roleInherits[role];
		 	}

		 	if typeof inheritedRoles == "array" {
		 		for inheritedRole in inheritedRoles {
		 			let accessKey = inheritedRole . "!" . resource . "!" . access;

		 			/**
					 * Check if there is a direct combination in one of the inherited roles
					 */
					 if isset accessList[accessKey] {
					 	let haveAccess = accessList[accessKey];
					 }
		 		}
		 	}
		 }

		 /**
		 * If access wasn't found yet, try role-resource-*
		 */
		 if haveAccess == null {

		 	let accessKey =  role . "!" . resource . "!*";

		 	/**
			 * In the direct role
			 */
			 if isset accessList[accessKey] {
			 	let haveAccess = accessList[accessKey];
			 } else {
			 	if typeof inheritedRoles == "array" {
			 		for inheritedRole in inheritedRoles {
			 			let accessKey = inheritedRole . "!" . resource . "!*";

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

		 	let accessKey =  role, "!*!*";

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
			return 0;
		}

		return haveAccess;
	 }

	 /**
	 * Return an array with every role registered in the list
	 *
	 * @return Phalcon\Acl\Role[]
	 */
	 public function getRoles()
	 {
	 	return this->_roles;
	 }

	 /**
	 * Return an array with every resource registered in the list
	 *
	 * @return Phalcon\Acl\Resource[]
	 */
	 public function getResources()
	 {
	 	return this->_resources;
	 }
}
