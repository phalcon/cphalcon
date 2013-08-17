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
	 
	 
}
