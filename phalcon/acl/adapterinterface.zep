
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

namespace Phalcon\Acl;

/**
 * Phalcon\Acl\AdapterInterface
 *
 * Interface for Phalcon\Acl adapters
 */
interface AdapterInterface
{

	/**
	 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
	 */
	public function setDefaultAction(int defaultAccess);

	/**
	 * Returns the default ACL access level
	 */
	public function getDefaultAction() -> int;

	/**
	 * Adds a role to the ACL list. Second parameter lets to inherit access data from other existing role
	 */
	public function addRole(role, accessInherits = null) -> boolean;

	/**
	 * Do a role inherit from another existing role
	 */
	public function addInherit(string roleName, roleToInherit) -> boolean;

	/**
	 * Check whether role exist in the roles list
	 */
	public function isRole(string roleName) -> boolean;

	/**
	 * Check whether resource exist in the resources list
	 */
	public function isResource(string resourceName) -> boolean;

	/**
	 * Adds a resource to the ACL list
	 *
	 * Access names can be a particular action, by example
	 * search, update, delete, etc or a list of them
	 */
	public function addResource(resourceObject, accessList) -> boolean;

	/**
	 * Adds access to resources
	 */
	public function addResourceAccess(string resourceName, accessList);

	/**
	 * Removes an access from a resource
	 */
	public function dropResourceAccess(string resourceName, accessList);

	/**
	 * Allow access to a role on a resource
	 */
	public function allow(string roleName, string resourceName, access);

	/**
	 * Deny access to a role on a resource
	 */
	public function deny(string roleName, string resourceName, access);

	/**
	 * Check whether a role is allowed to access an action from a resource
	 */
	public function isAllowed(string roleName, string resourceName, access) -> boolean;

	/**
	 * Returns the role which the list is checking if it's allowed to certain resource/access
	 */
	public function getActiveRole() -> string;

	/**
	 * Returns the resource which the list is checking if some role can access it
	 */
	public function getActiveResource() -> string;

	/**
	 * Returns the access which the list is checking if some role can access it
	 */
	public function getActiveAccess() -> string;

	/**
	 * Return an array with every role registered in the list
	 */
	public function getRoles() -> <RoleInterface[]>;

	/**
	 * Return an array with every resource registered in the list
	 */
	public function getResources() -> <ResourceInterface[]>;
}
