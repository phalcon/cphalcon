
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Acl\Adapter;

use Phalcon\Acl\ComponentInterface;
use Phalcon\Acl\RoleInterface;
use Phalcon\Contracts\Acl\AclTypes;

/**
 * Canonical contract for Phalcon\Acl adapters
 *
 * @phpstan-import-type acl_access_list from AclTypes
 * @phpstan-import-type acl_component_name from AclTypes
 * @phpstan-import-type acl_components from AclTypes
 * @phpstan-import-type acl_role_name from AclTypes
 * @phpstan-import-type acl_role_to_inherit from AclTypes
 * @phpstan-import-type acl_roles from AclTypes
 */
interface Adapter
{
    /**
     * Adds a component to the ACL list
     *
     * Access names can be a particular action, for instance `search`, `update`
     * `delete` etc. or a list of them.
     *
     * @phpstan-param ComponentInterface|string $componentValue
     * @phpstan-param acl_access_list           $accessList
     */
    public function addComponent(componentValue, accessList) -> bool;

    /**
     * Adds access to components
     *
     * @phpstan-param acl_access_list $accessList
     */
    public function addComponentAccess(string componentName, accessList) -> bool;



    /**
     * Add a role which inherits from an existing role
     *
     * @phpstan-param acl_role_to_inherit $roleToInherits
     */
    public function addInherit(string roleName, roleToInherits) -> bool;

    /**
     * Adds a role to the ACL list. The second parameter lets to inherit access
     * from an existing role
     *
     * @phpstan-param RoleInterface|string     $role
     * @phpstan-param acl_role_to_inherit|null $accessInherits
     */
    public function addRole(role, accessInherits = null) -> bool;


    /**
     * Allow access to a role on a component. You can use `*` as wildcard
     *
     * @phpstan-param acl_access_list $access
     *
     * @phpstan-param callable|null $func
     */
    public function allow(string roleName, string componentName, access, func = null) -> void;

    /**
     * Deny access to a role on a component. You can use `*` as wildcard
     *
     * @phpstan-param acl_access_list $access
     *
     * @phpstan-param callable|null $func
     */
    public function deny(string roleName, string componentName, access, func = null) -> void;

    /**
     * Removes access from a component
     *
     * @phpstan-param acl_access_list $accessList
     */
    public function dropComponentAccess(string componentName, accessList) -> void;

    /**
     * Returns the access which the list is checking if a role can access it
     */
    public function getActiveAccess() -> string | null;

    /**
     * Returns the component which the list is checking if some role can access
     * it
     */
    public function getActiveComponent() -> string | null;

    /**
     * Returns the role which the list is checking if it's allowed to certain
     * component/access
     */
    public function getActiveRole() -> string | null;

    /**
     * Return an array with every component registered in the list
     *
     * @phpstan-return acl_components
     */
    public function getComponents() -> <ComponentInterface[]>;

    /**
     * Returns the default action
     */
    public function getDefaultAction() -> int;

    /**
     * Returns the inherited roles for a passed role name. If no role name
     * has been specified it will return the whole array. If the role has not
     * been found it returns an empty array
     *
     * @return array<int|string, array<int, string>|string>
     */
    public function getInheritedRoles(string roleName = "") -> array;

    /**
     * Returns the default ACL access level for no arguments provided in
     * `isAllowed` action if a `function` (callable) exists for `accessKey`
     */
    public function getNoArgumentsDefaultAction() -> int;

    /**
     * Return an array with every role registered in the list
     *
     * @phpstan-return acl_roles
     */
    public function getRoles() -> <RoleInterface[]>;

    /**
     * Check whether a role is allowed to access an action from a component
     *
     * @phpstan-param acl_role_name      $roleName
     * @phpstan-param acl_component_name $componentName
     */
    public function isAllowed(roleName, componentName, string access, array parameters = null) -> bool;

    /**
     * Check whether a component exists in the components list
     */
    public function isComponent(string componentName) -> bool;

    /**
     * Check whether role exist in the roles list
     */
    public function isRole(string roleName) -> bool;

    /**
     * Sets the default access level
     * (Phalcon\Acl\Enum::ALLOW or Phalcon\Acl\Enum::DENY)
     */
    public function setDefaultAction(int defaultAccess) -> void;

    /**
     * Sets the default access level (Phalcon\Acl\Enum::ALLOW or
     * Phalcon\Acl\Enum::DENY) for no arguments provided in isAllowed action if
     * there exists func for accessKey
     */
    public function setNoArgumentsDefaultAction(int defaultAccess) -> void;
}
