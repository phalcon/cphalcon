
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Acl\Adapter;

use Phalcon\Acl\Enum;
use Phalcon\Acl\Role;
use Phalcon\Acl\RoleInterface;
use Phalcon\Acl\Component;
use Phalcon\Acl\Exception;
use Phalcon\Acl\RoleAwareInterface;
use Phalcon\Acl\ComponentAwareInterface;
use Phalcon\Acl\ComponentInterface;
use ReflectionFunction;

/**
 * Manages ACL lists in memory
 *
 *```php
 * $acl = new \Phalcon\Acl\Adapter\Memory();
 *
 * $acl->setDefaultAction(
 *     \Phalcon\Acl\Enum::DENY
 * );
 *
 * // Register roles
 * $roles = [
 *     "users"  => new \Phalcon\Acl\Role("Users"),
 *     "guests" => new \Phalcon\Acl\Role("Guests"),
 * ];
 * foreach ($roles as $role) {
 *     $acl->addRole($role);
 * }
 *
 * // Private area components
 * $privateComponents = [
 *     "companies" => ["index", "search", "new", "edit", "save", "create", "delete"],
 *     "products"  => ["index", "search", "new", "edit", "save", "create", "delete"],
 *     "invoices"  => ["index", "profile"],
 * ];
 *
 * foreach ($privateComponents as $componentName => $actions) {
 *     $acl->addComponent(
 *         new \Phalcon\Acl\Component($componentName),
 *         $actions
 *     );
 * }
 *
 * // Public area components
 * $publicComponents = [
 *     "index"   => ["index"],
 *     "about"   => ["index"],
 *     "session" => ["index", "register", "start", "end"],
 *     "contact" => ["index", "send"],
 * ];
 *
 * foreach ($publicComponents as $componentName => $actions) {
 *     $acl->addComponent(
 *         new \Phalcon\Acl\Component($componentName),
 *         $actions
 *     );
 * }
 *
 * // Grant access to public areas to both users and guests
 * foreach ($roles as $role) {
 *     foreach ($publicComponents as $component => $actions) {
 *         $acl->allow($role->getName(), $component, "*");
 *     }
 * }
 *
 * // Grant access to private area to role Users
 * foreach ($privateComponents as $component => $actions) {
 *     foreach ($actions as $action) {
 *         $acl->allow("Users", $component, $action);
 *     }
 * }
 *```
 */
class Memory extends AbstractAdapter
{
    /**
     * Access
     *
     * @var mixed
     */
    protected access;

    /**
     * Access List
     *
     * @var mixed
     */
    protected accessList;

    /**
     * Returns latest function used to acquire access
     *
     * @var mixed
     */
    protected activeFunction { get };

    /**
     * Returns number of additional arguments(excluding role and resource) for active function
     *
     * @var int
     */
    protected activeFunctionCustomArgumentsCount = 0 { get };

    /**
     * Returns latest key used to acquire access
     *
     * @var string|null
     */
    protected activeKey { get };

    /**
     * Components
     *
     * @var mixed
     */
    protected components;

    /**
     * Component Names
     *
     * @var mixed
     */
    protected componentsNames;

    /**
     * Function List
     *
     * @var mixed
     */
    protected func;

    /**
     * Default action for no arguments is allow
     *
     * @var mixed
     */
    protected noArgumentsDefaultAction = Enum::DENY;

    /**
     * Roles
     *
     * @var mixed
     */
    protected roles;

    /**
     * Role Inherits
     *
     * @var mixed
     */
    protected roleInherits;

    /**
     * Phalcon\Acl\Adapter\Memory constructor
     */
    public function __construct()
    {
        let this->componentsNames = ["*": true];
        let this->accessList = ["*!*": true];
    }

    /**
     * Adds a component to the ACL list
     *
     * Access names can be a particular action, by example
     * search, update, delete, etc or a list of them
     *
     * Example:
     * ```php
     * // Add a component to the the list allowing access to an action
     * $acl->addComponent(
     *     new Phalcon\Acl\Component("customers"),
     *     "search"
     * );
     *
     * $acl->addComponent("customers", "search");
     *
     * // Add a component  with an access list
     * $acl->addComponent(
     *     new Phalcon\Acl\Component("customers"),
     *     [
     *         "create",
     *         "search",
     *     ]
     * );
     *
     * $acl->addComponent(
     *     "customers",
     *     [
     *         "create",
     *         "search",
     *     ]
     * );
     * ```
     */
    public function addComponent(var componentValue, var accessList) -> bool
    {
        var componentName, componentObject;

        if typeof componentValue == "object" && componentValue instanceof ComponentInterface {
            let componentObject = componentValue;
        } else {
            let componentObject = new Component(componentValue);
        }

        let componentName = componentObject->getName();

        if !isset this->componentsNames[componentName] {
            let this->components[componentName]      = componentObject;
            let this->componentsNames[componentName] = true;
        }

        return this->addComponentAccess(componentName, accessList);
    }

    /**
     * Adds access to components
     */
    public function addComponentAccess(string componentName, var accessList) -> bool
    {
        var accessName;
        string accessKey;
        bool exists;

        this->checkExists(this->componentsNames, componentName, "Component");

        if unlikely (typeof accessList != "array" && typeof accessList != "string") {
            throw new Exception("Invalid value for the accessList");
        }

        let exists = true;

        if typeof accessList == "array" {
            for accessName in accessList {
                let accessKey = componentName . "!" . accessName;

                if !isset this->accessList[accessKey] {
                    let this->accessList[accessKey] = exists;
                }
            }
        } else {
            let accessKey = componentName . "!" . accessList;

            if !isset this->accessList[accessKey] {
                let this->accessList[accessKey] = exists;
            }
        }

        return true;
    }

    /**
     * Do a role inherit from another existing role
     *
     * ```php
     * $acl->addRole("administrator", "consultant");
     * $acl->addRole("administrator", ["consultant", "consultant2"]);
     * ```
     */
    public function addInherit(string roleName, var roleToInherits) -> bool
    {
        var roleInheritName, roleToInherit, checkRoleToInherit,
            roleToInheritList, usedRoleToInherit;
        array checkRoleToInherits, usedRoleToInherits;

        this->checkExists(this->roles, roleName, "Role", "role list");

        if !isset this->roleInherits[roleName] {
            let this->roleInherits[roleName] = [];
        }

        /**
         * Type conversion
         */
        if typeof roleToInherits != "array" {
            let roleToInheritList = [roleToInherits];
        } else {
            let roleToInheritList = roleToInherits;
        }

        /**
         * inherits
         */
        for roleToInherit in roleToInheritList {
            if typeof roleToInherit == "object" && roleToInherit instanceof RoleInterface {
                let roleInheritName = roleToInherit->getName();
            } else {
                let roleInheritName = roleToInherit;
            }

            /**
             * Check if the role to inherit is repeat
             */
            if in_array(roleInheritName, this->roleInherits[roleName]) {
                continue;
            }

            /**
             * Check if the role to inherit is valid
             */
            if unlikely !isset this->roles[roleInheritName] {
                throw new Exception(
                    "Role '" . roleInheritName .
                    "' (to inherit) does not exist in the role list"
                );
            }

            if roleName == roleInheritName {
                return false;
            }

            /**
             * Deep check if the role to inherit is valid
             */
            if isset this->roleInherits[roleInheritName] {
                let checkRoleToInherits = [];

                for usedRoleToInherit in this->roleInherits[roleInheritName] {
                    array_push(checkRoleToInherits, usedRoleToInherit);
                }

                let usedRoleToInherits = [];

                while !empty checkRoleToInherits {
                    let checkRoleToInherit = array_shift(checkRoleToInherits);

                    if isset usedRoleToInherits[checkRoleToInherit] {
                        continue;
                    }

                    let usedRoleToInherits[checkRoleToInherit] = true;

                    if unlikely roleName == checkRoleToInherit {
                        throw new Exception(
                            "Role '" . roleInheritName .
                            "' (to inherit) produces an infinite loop"
                        );
                    }

                    /**
                     * Push inherited roles
                     */
                    if isset this->roleInherits[checkRoleToInherit] {
                        for usedRoleToInherit in this->roleInherits[checkRoleToInherit] {
                            array_push(checkRoleToInherits, usedRoleToInherit);
                        }
                    }
                }
            }

            let this->roleInherits[roleName][] = roleInheritName;
        }

        return true;
    }

    /**
     * Adds a role to the ACL list. Second parameter allows inheriting access data from other existing role
     *
     * ```php
     * $acl->addRole(
     *     new Phalcon\Acl\Role("administrator"),
     *     "consultant"
     * );
     *
     * $acl->addRole("administrator", "consultant");
     * $acl->addRole("administrator", ["consultant", "consultant2"]);
     * ```
     */
    public function addRole(role, accessInherits = null) -> bool
    {
        var roleName, roleObject;

        if typeof role == "object" && role instanceof RoleInterface {
            let roleObject = role;
        } elseif is_string(role) {
            let roleObject = new Role(role);
        } else {
            throw new Exception(
                "Role must be either a string or implement RoleInterface"
            );
        }

        let roleName = roleObject->getName();

        if isset this->roles[roleName] {
            return false;
        }

        let this->roles[roleName] = roleObject;

        if null !== accessInherits {
            return this->addInherit(roleName, accessInherits);
        }

        return true;
    }

    /**
     * Allow access to a role on a component. You can use `*` as wildcard
     *
     * ```php
     * // Allow access to guests to search on customers
     * $acl->allow("guests", "customers", "search");
     *
     * // Allow access to guests to search or create on customers
     * $acl->allow("guests", "customers", ["search", "create"]);
     *
     * // Allow access to any role to browse on products
     * $acl->allow("*", "products", "browse");
     *
     * // Allow access to any role to browse on any component
     * $acl->allow("*", "*", "browse");
     */
    public function allow(string roleName, string componentName, var access, var func = null) -> void
    {
        var role, rolesArray;

        let rolesArray = [roleName];
        if ("*" === roleName) {
            let rolesArray = array_keys(this->roles);
        }

        for role in rolesArray {
            this->allowOrDeny(
                role,
                componentName,
                access,
                Enum::ALLOW,
                func
            );
        }
    }

    /**
     * Deny access to a role on a component. You can use `*` as wildcard
     *
     * ```php
     * // Deny access to guests to search on customers
     * $acl->deny("guests", "customers", "search");
     *
     * // Deny access to guests to search or create on customers
     * $acl->deny("guests", "customers", ["search", "create"]);
     *
     * // Deny access to any role to browse on products
     * $acl->deny("*", "products", "browse");
     *
     * // Deny access to any role to browse on any component
     * $acl->deny("*", "*", "browse");
     * ```
     */
    public function deny(string roleName, string componentName, var access, var func = null) -> void
    {
        var role, rolesArray;

        let rolesArray = [roleName];
        if ("*" === roleName) {
            let rolesArray = array_keys(this->roles);
        }

        for role in rolesArray {
            this->allowOrDeny(
                role,
                componentName,
                access,
                Enum::DENY,
                func
            );
        }
    }

    /**
     * Removes an access from a component
     */
    public function dropComponentAccess(string componentName, var accessList) -> void
    {
        var accessName;
        string accessKey;
        array localAccess = [];

        if typeof accessList == "string" {
            let localAccess = [accessList];
        } else {
            let localAccess = accessList;
        }

        if typeof accessList == "array" {
            for accessName in localAccess {
                let accessKey = componentName . "!" . accessName;

                if isset this->accessList[accessKey] {
                    unset this->accessList[accessKey];
                }
            }
        }
     }

    /**
     * Returns the default ACL access level for no arguments provided in
     * `isAllowed` action if a `func` (callable) exists for `accessKey`
     */
    public function getNoArgumentsDefaultAction() -> int
    {
        return this->noArgumentsDefaultAction;
    }

    /**
     * Return an array with every role registered in the list
     */
    public function getRoles() -> <RoleInterface[]>
    {
        return this->roles;
    }

    /**
     * Return an array with every component registered in the list
     */
    public function getComponents() -> <ComponentInterface[]>
    {
        return this->components;
    }

    /**
     * Check whether a role is allowed to access an action from a component
     *
     * ```php
     * // Does andres have access to the customers component to create?
     * $acl->isAllowed("andres", "Products", "create");
     *
     * // Do guests have access to any component to edit?
     * $acl->isAllowed("guests", "*", "edit");
     * ```
     */
    public function isAllowed(var roleName, var componentName, string access, array parameters = null) -> bool
    {
        var accessKey, accessList, componentObject = null, haveAccess = null,
            funcAccess = null, funcList, numberOfRequiredParameters,
            reflectionFunction, reflectionParameters, parameterNumber,
            parameterToCheck, parametersForFunction, reflectionClass,
            reflectionParameter, roleObject = null,
            userParametersSizeShouldBe;

        bool hasComponent = false, hasRole = false;

        if typeof roleName == "object" {
            if roleName instanceof RoleAwareInterface {
                let roleObject = roleName,
                    roleName   = roleObject->getRoleName();
            } elseif roleName instanceof RoleInterface {
                let roleName = roleName->getName();
            } else {
                throw new Exception(
                    "Object passed as roleName must implement " .
                    "Phalcon\\Acl\\RoleAwareInterface or Phalcon\\Acl\\RoleInterface"
                );
            }
        }

        if typeof componentName == "object" {
            if componentName instanceof ComponentAwareInterface {
                let componentObject = componentName,
                    componentName   = componentObject->getComponentName();
            } elseif componentName instanceof ComponentInterface {
                let componentName = componentName->getName();
            } else {
                throw new Exception(
                    "Object passed as componentName must implement " .
                    "Phalcon\\Acl\\ComponentAwareInterface or Phalcon\\Acl\\ComponentInterface"
                );
            }
        }

        let this->activeRole      = roleName,
            this->activeComponent = componentName,
            this->activeAccess    = access,
            this->activeKey       = null,
            this->activeKey       = null,
            this->activeFunction  = null,
            accessList            = this->access,
            funcList              = this->func;

        let this->activeFunctionCustomArgumentsCount = 0;

        if (false === this->fireManagerEvent("acl:beforeCheckAccess", this)) {
            return false;
        }

        /**
         * Check if the role exists
         */
        if !isset this->roles[roleName] {
            return (this->defaultAccess == Enum::ALLOW);
        }

        /**
         * Check if there is a direct combination for role-component-access
         */
        let accessKey = this->canAccess(roleName, componentName, access);

        if null !== accessKey && isset accessList[accessKey] {
            let haveAccess = accessList[accessKey];

            fetch funcAccess, funcList[accessKey];
        }

        /**
         * Check in the inherits roles
         */
        let this->accessGranted = haveAccess;

        this->fireManagerEvent("acl:afterCheckAccess", this);

        let this->activeKey      = accessKey,
            this->activeFunction = funcAccess;

        if haveAccess == null {
            /**
             * Change activeKey to most narrow if there was no access for any
             * patterns found
             */
            let this->activeKey = roleName . "!" . componentName . "!" . access;

            return this->defaultAccess == Enum::ALLOW;
        }

        /**
         * If we have funcAccess then do all the checks for it
         */
        if is_callable(funcAccess) {
            let reflectionFunction   = new ReflectionFunction(funcAccess),
                reflectionParameters = reflectionFunction->getParameters(),
                parameterNumber      = count(reflectionParameters);

            /**
             * No parameters, just return haveAccess and call function without
             * array
             */
            if parameterNumber === 0 {
                return haveAccess == Enum::ALLOW && call_user_func(funcAccess);
            }

            let parametersForFunction      = [],
                numberOfRequiredParameters = reflectionFunction->getNumberOfRequiredParameters(),
                userParametersSizeShouldBe = parameterNumber;

            for reflectionParameter in reflectionParameters {
                let reflectionClass  = reflectionParameter->getClass(),
                    parameterToCheck = reflectionParameter->getName();

                if reflectionClass !== null {
                    // roleObject is this class
                    if (roleObject !== null &&
                        reflectionClass->isInstance(roleObject) &&
                        !hasRole
                    ) {
                        let hasRole                 = true,
                            parametersForFunction[] = roleObject;
                        let userParametersSizeShouldBe--;

                        continue;
                    }

                    // componentObject is this class
                    if (componentObject !== null &&
                        reflectionClass->isInstance(componentObject) &&
                        !hasComponent
                    ) {
                        let hasComponent            = true,
                            parametersForFunction[] = componentObject;
                        let userParametersSizeShouldBe--;

                        continue;
                    }

                    /**
                     * This is some user defined class, check if his parameter
                     * is instance of it
                     */
                    if unlikely (isset(parameters[parameterToCheck]) &&
                        is_object(parameters[parameterToCheck]) &&
                        !reflectionClass->isInstance(parameters[parameterToCheck])
                    ) {
                        throw new Exception(
                            "Your passed parameter doesn't have the " .
                            "same class as the parameter in defined function " .
                            "when checking if " . roleName . " can " . access .
                            " " . componentName . ". Class passed: " .
                            get_class(parameters[parameterToCheck]) .
                            " , Class in defined function: " .
                            reflectionClass->getName() . "."
                        );
                    }
                }

                if isset parameters[parameterToCheck] {
                    /**
                     * We can't check type of ReflectionParameter in PHP 5.x so
                     * we just add it as it is
                     */
                    let parametersForFunction[] = parameters[parameterToCheck];
                }
            }

            let this->activeFunctionCustomArgumentsCount = userParametersSizeShouldBe;

            if unlikely count(parameters) > userParametersSizeShouldBe {
                trigger_error(
                    "Number of parameters in array is higher than " .
                    "the number of parameters in defined function when checking if '" .
                    roleName . "' can '" . access . "' '" . componentName .
                    "'. Extra parameters will be ignored.",
                    E_USER_WARNING
                );
            }

            // We dont have any parameters so check default action
            if count(parametersForFunction) == 0 {
                if unlikely numberOfRequiredParameters > 0 {
                    trigger_error(
                        "You did not provide any parameters when '" . roleName .
                        "' can '" . access . "' '"  . componentName .
                        "'. We will use default action when no arguments."
                    );

                    return haveAccess == Enum::ALLOW && this->noArgumentsDefaultAction == Enum::ALLOW;
                }

                /**
                 * Number of required parameters == 0 so call funcAccess without
                 * any arguments
                 */
                return haveAccess == Enum::ALLOW && call_user_func(funcAccess);
            }

            // Check necessary parameters
            if count(parametersForFunction) >= numberOfRequiredParameters {
                return haveAccess == Enum::ALLOW && call_user_func_array(funcAccess, parametersForFunction);
            }

            // We don't have enough parameters
            throw new Exception(
                "You did not provide all necessary parameters for the " .
                "defined function when checking if '" . roleName . "' can '" .
                access . "' for '" . componentName . "'."
            );
        }

        return haveAccess == Enum::ALLOW;
    }

    /**
     * Check whether role exist in the roles list
     */
    public function isRole(string roleName) -> bool
    {
        return isset this->roles[roleName];
    }

    /**
     * Check whether component exist in the components list
     */
    public function isComponent(string componentName) -> bool
    {
        return isset this->componentsNames[componentName];
    }

    /**
     * Sets the default access level (`Phalcon\Enum::ALLOW` or `Phalcon\Enum::DENY`)
     * for no arguments provided in isAllowed action if there exists func for
     * accessKey
     */
    public function setNoArgumentsDefaultAction(int defaultAccess) -> void
    {
        let this->noArgumentsDefaultAction = defaultAccess;
    }

    /**
     * Checks if a role has access to a component
     */
    private function allowOrDeny(string roleName, string componentName, var access, var action, var func = null) -> void
    {
        var accessList, accessName, accessKey;

        this->checkExists(this->roles, roleName, "Role");
        this->checkExists(this->componentsNames, componentName, "Component");

        let accessList = this->accessList;

        if typeof access == "array" {
            for accessName in access {
                let accessKey = componentName . "!" . accessName;

                if unlikely !isset accessList[accessKey] {
                    throw new Exception(
                        "Access '" . accessName .
                        "' does not exist in component '" . componentName . "'"
                    );
                }
            }

            for accessName in access {
                let accessKey = roleName . "!" .componentName . "!" . accessName;
                let this->access[accessKey] = action;

                if func != null {
                    let this->func[accessKey] = func;
                }
            }
        } else {
            if access != "*" {
                let accessKey = componentName . "!" . access;

                if unlikely !isset accessList[accessKey] {
                    throw new Exception(
                        "Access '" . access .
                        "' does not exist in component '" . componentName . "'"
                    );
                }
            }

            let accessKey = roleName . "!" . componentName . "!" . access;

            /**
             * Define the access action for the specified accessKey
             */
            let this->access[accessKey] = action;

            if func != null {
                let this->func[accessKey] = func;
            }
        }
    }

    /**
     * Check whether a role is allowed to access an action from a component
     */
    private function canAccess(string roleName, string componentName, string access) -> string | bool
    {
        var accessList, checkRoleToInherit, usedRoleToInherit;
        array usedRoleToInherits, checkRoleToInherits;
        string accessKey;

        let accessList = this->access;

        let accessKey = roleName . "!" . componentName . "!" . access;

        /**
         * Check if there is a direct combination for role-component-access
         */
        if isset accessList[accessKey] {
            return accessKey;
        }

        /**
         * Check if there is a direct combination for role-*-*
         */
        let accessKey = roleName . "!" . componentName . "!*";

        if isset accessList[accessKey] {
            return accessKey;
        }

        /**
         * Check if there is a direct combination for role-*-*
         */
        let accessKey = roleName . "!*!*";

        if isset accessList[accessKey] {
            return accessKey;
        }

        /**
         * Deep check if the role to inherit is valid
         */
        if isset this->roleInherits[roleName] {
            let checkRoleToInherits = [];

            for usedRoleToInherit in this->roleInherits[roleName] {
                array_push(checkRoleToInherits, usedRoleToInherit);
            }

            let usedRoleToInherits = [];

            while !empty checkRoleToInherits {
                let checkRoleToInherit = array_shift(checkRoleToInherits);

                if isset usedRoleToInherits[checkRoleToInherit] {
                    continue;
                }

                let usedRoleToInherits[checkRoleToInherit] = true;

                let accessKey = checkRoleToInherit . "!" . componentName . "!" . access;

                /**
                 * Check if there is a direct combination in one of the
                 * inherited roles
                 */
                if isset accessList[accessKey] {
                    return accessKey;
                }

                /**
                 * Check if there is a direct combination for role-*-*
                 */
                let accessKey = checkRoleToInherit . "!" . componentName . "!*";

                if isset accessList[accessKey] {
                    return accessKey;
                }

                /**
                 * Check if there is a direct combination for role-*-*
                 */
                let accessKey = checkRoleToInherit . "!*!*";

                if isset accessList[accessKey] {
                    return accessKey;
                }

                /**
                 * Push inherited roles
                 */
                if isset this->roleInherits[checkRoleToInherit] {
                    for usedRoleToInherit in this->roleInherits[checkRoleToInherit] {
                        array_push(checkRoleToInherits, usedRoleToInherit);
                    }
                }
            }
        }

        return false;
    }

    /**
     * @param array  $collection
     * @param string $element
     * @param string $elementName
     * @param string $suffix
     *
     * @throws Exception
     */
    private function checkExists(
        array collection,
        string element,
        string elementName,
        string suffix = "ACL"
    ) -> void {
        if (true !== isset(collection[element])) {
            throw new Exception(
                elementName . " '" . element .
                "' does not exist in the " . suffix
            );
        }
    }
}
