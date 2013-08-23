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
		let resourcesNames = ["*" => true];
		let this->_resourcesNames = resourcesNames;
		
		let access_list = ["*!*" => true];
		let this->_accessList = access_list;
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
		if typeof role == "object" {
			let roleName = role->getName();
			let object = role;
		} else {
			let roleName = role;
			let object = new Phalcon\Acl\Role(role);
		}
		
		let rolesNames = this->_rolesNames;
		if isset rolessNames[roleName] {
			return false;
		}
		 
		let exists = true;
		let this->_roles[]= object;
		let this->_rolesNames[]= roleName;
		
		let defaultAccess = this->_defaultAccess;
		
		let key = role . "!*!*";
		let this->_access = key;
		
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
		let rolesNames = this->_rolesNames;
		
		if !rolesNames[roleName] {
			let exceptionMessage = "Role '" . roleName . "' does not exist in the role list";
			throw new Phalcon\Acl\Exception(exceptionMessage);
		}
		 
		if typeof roleToInherit == "object" {
			let roleInheritName = roleToInherit->getName();
		} else {
			let roleInheritName = roleToInherit;
		}
		 
		/** 
		* Check if the role to inherit is valid
		*/
		if !rolesNames[roleInheritName] {
			let exceptionMessage = "Role '" . roleInheritName . "' (to inherit) does not exist in the role list";
			throw new Phalcon\Acl\Exception(exceptionMessage);
		}
		
		if roleName == roleInheritName {
			return false;
		}
		
		let rolesInherits = this->_roleInherits;
		if !rolesInherits[roleName] {
			let this->_roleInherits = roleName;
		}
		
		let _roleInherits = this->_roleInherits;
		let _roleInherits[roleName][] = _roleInherits;
		
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
		 let rolesName = this->_rolesNames;
		 if isset rolesNames[roleName] {
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
		 let resourcesNames = this->_resourcesNames;
		 if isset resourcesNames[resourceName] {
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
		 if typeof resource == "object" {
			 let resourceName = resource->getName();
			 let object = resource;
		 } else {
			 let resourceName = resource;
			 let object = new Phalcon\Acl\Resource(resourceName);
		 }
		 
		 let resourcesNames = this->_resourcesNames;
		 if isset resourcesNames[resourceName] {
			let exists = true;
			let this->_resources[]= object;
			let this->_resourcesNames[resourceName] = exists;
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
	 	let resourcesNames = this->_resourcesNames;
	 	if isset resourcesNames[resourceName] {
	 		let exceptionMessage = "Resource '" . resource_name . "' does not exist in ACL";
	 		throw new  Phalcon\Acl\Exception(exceptionMessage);
	 	}
	 	
	 	let exists = true;
	 	let internalAccessList = this->accessList;
	 	
	 	if typeof accessList == "array" {
	 		for accessName in accessList {
	 			let accessKey = resourceName . "!" . accessName;
	 			if isset internalAccessList[accessKey] {
	 				let this->_accessList[accessKey] = exists;
	 			}
	 		}
	 	} else {
	 		if typeof accessList == "string" {
	 			let accessKey = resourceName . "!" . accessName;
	 			if isset internalAccessList[accessKey] {
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
	 	let internalAccessList = this->accessList;
	 	
	 	if typeof accessList == "array" {
	 		for accessName in accessList {
	 			let accessKey = resourceName . "!" . accessName;
	 			if isset internalAccessList[accessKey] {
	 				unset this->_accessList[accessKey];
	 			}
	 		}
	 	} else {
	 		if typeof accessList == "string" {
	 			let accessKey = resourceName . "!" . accessName;
	 			if isset internalAccessList[accessKey] {
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
	 	let rolesNames = this->_rolesNames;
	 	if isset rolesNames[roleName] {
	 		let exceptionMessage = "Role \"" . role_name . "\" does not exist in ACL";
	 		throw new  Phalcon\Acl\Exception(exceptionMessage);
	 	}
	 	
	 	let resourcesNames = this->_resourcesNames;
	 	if isset resourcesNames[resourceName] {
	 		let exceptionMessage = "Resource '" . resource_name . "' does not exist in ACL";
	 		throw new  Phalcon\Acl\Exception(exceptionMessage);
	 	}
	 	
	 	let defaultAccess = this->_defaultAccess;
	 	let accessList = this->_accessList;
	 	
	 	let internalAccess = this->_access;
	 	if typeof access == "array" {
	 		
	 		for accessName in access {
	 			let accessKey = resourceName . "!" . accessName;
	 			if !isset internalAccessList[accessKey] {
	 				let exceptionMessage = "Acccess '" . accessName . "' does not exist in resource '" . resourceName . "'";
	 				throw new  Phalcon\Acl\Exception(exceptionMessage);
	 			}
	 		}
	 		
	 		for accessName in access {
	 			let accessKey = roleName . "!" .resourceName . "!" . accessName;
	 			let this->_access[accessKey] = action;
	 			
	 			if accessName != "*" {
	 				let accessKeyAll = roleName . "!" . resourceName . "!*";
	 				if isset internalAccess[accessKeyAll] {
		 				let this->_access[accessKeyAll] = defaultAccess ;
		 			}
	 			}
	 		}
	 	} else {
	 		if access != "*" {
	 			let accessKey = resourceName . "!" . access;
	 			if !isset accessList[accessKey] {
	 				let exceptionMessage = "Acccess '" . access . "' does not exist in resource '" . resourceName . "'";
	 				throw new  Phalcon\Acl\Exception(exceptionMessage);
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
				 if !isset internalAccess[accessKey] {
				 	let this->_access[accessKey] = defaultAccess; 
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
	 	return this->_allowordeny(roleName, resourceName, access, action);
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
	 	let action = 0;
	 	return this->_allowordeny(roleName, resourceName, access, action);
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
	 	let _activeRole = role;
	 	let _activeResource = resource;
	 	let _activeAccess = resource;
	 	
	 	let eventsManager = this->_eventsManager;
	 	if typeof eventsManager == "object" {
	 		let eventName = "acl:beforeCheckAccess";
	 		let status = eventsManager->fire(eventName, this);
	 		
	 		if !status {
	 			return status;
	 		}
		
	 	}
	 	
	 	let defaultAccess = this->_defaultAccess;
	 	
	 	/** 
		 * Check if the role exists
		 */
		 let rolesNames = this->_rolesNames;
		 if !isset rolesNames[role] {
		 	return defaultAccess;
		 }
		 
		 let accessList = this->_access;
		 let accesskey = role . "!" . resource . "!" . access;
		 
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
		 	if isset roleInherits[role] {
		 		let inheritedRoles = roleInherits[role];
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
			 			let accessKey = inheritedRole, "!", resource, "!*";
			 			
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
			 			let accessKey = inheritedRole, "!*!*";
			 			
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
		
		this->_accessGranted = haveAccess;
		
		if typeof eventsManager == "object" {
			let eventName = "acl:afterCheckAccess";
			eventsManager->fire(eventName,this);
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
