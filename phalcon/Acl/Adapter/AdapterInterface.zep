
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Acl\Adapter;

use Phalcon\Acl\ComponentInterface;
use Phalcon\Acl\RoleInterface;

/**
 * Interface for Phalcon\Acl adapters
 */
interface AdapterInterface
{
    /**
     * Do a role inherit from another existing role
     */
    public function addInherit(string roleName, roleToInherits) -> bool;

    /**
     * Adds a role to the ACL list. Second parameter lets to inherit access data
     * from other existing role
     */
    public function addRole(role, accessInherits = null) -> bool;

    /**
     * Adds a component to the ACL list
     *
     * Access names can be a particular action, by example
     * search, update, delete, etc or a list of them
     */
    public function addComponent(componentValue, accessList) -> bool;

    /**
     * Adds access to components
     */
    public function addComponentAccess(string componentName, accessList) -> bool;

    /**
     * Allow access to a role on a component
     */
    public function allow(string roleName, string componentName, access, func = null) -> void;

    /**
     * Deny access to a role on a component
     */
    public function deny(string roleName, string componentName, access, func = null) -> void;

    /**
     * Removes an access from a component
     */
    public function dropComponentAccess(string componentName, accessList) -> void;

    /**
     * Returns the access which the list is checking if some role can access it
     */
    public function getActiveAccess() -> null | string;

    /**
     * Returns the role which the list is checking if it's allowed to certain
     * component/access
     */
    public function getActiveRole() -> null | string;

    /**
     * Returns the component which the list is checking if some role can access
     * it
     */
    public function getActiveComponent() -> null | string;

    /**
     * Returns the default ACL access level
     */
    public function getDefaultAction() -> int;

    /**
     * Returns the default ACL access level for no arguments provided in
     * isAllowed action if there exists func for accessKey
     */
    public function getNoArgumentsDefaultAction() -> int;

    /**
     * Return an array with every role registered in the list
     */
    public function getRoles() -> <RoleInterface[]>;

    /**
     * Return an array with every component registered in the list
     */
    public function getComponents() -> <ComponentInterface[]>;

    /**
     * Returns the inherited roles for a passed role name. If no role name
     * has been specified it will return the whole array. If the role has not
     * been found it returns an empty array
     */
    public function getInheritedRoles(string roleName = "") -> array;

    /**
     * Check whether a role is allowed to access an action from a component
     */
    public function isAllowed(roleName, componentName, string access, array parameters = null) -> bool;

    /**
     * Check whether component exist in the components list
     */
    public function isComponent(string componentName) -> bool;

    /**
     * Check whether role exist in the roles list
     */
    public function isRole(string roleName) -> bool;

    /**
     * Sets the default access level (Phalcon\Ac\Enuml::ALLOW or Phalcon\Acl\Enum::DENY)
     */
    public function setDefaultAction(int defaultAccess) -> void;

    /**
     * Sets the default access level (Phalcon\Acl\Enum::ALLOW or Phalcon\Acl\Enum::DENY)
     * for no arguments provided in isAllowed action if there exists func for
     * accessKey
     */
    public function setNoArgumentsDefaultAction(int defaultAccess) -> void;
}
