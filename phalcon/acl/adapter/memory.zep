
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Acl\Adapter;

use Phalcon\Acl;
use Phalcon\Acl\Adapter;
use Phalcon\Acl\Role;
use Phalcon\Acl\RoleInterface;
use Phalcon\Acl\Component;
use Phalcon\Acl\Exception;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Acl\RoleAware;
use Phalcon\Acl\ComponentAware;
use Phalcon\Acl\RoleInterface;
use Phalcon\Acl\ComponentInterface;

/**
 * Phalcon\Acl\Adapter\Memory
 *
 * Manages ACL lists in memory
 *
 *<code>
 * $acl = new \Phalcon\Acl\Adapter\Memory();
 *
 * $acl->setDefaultAction(
 *     \Phalcon\Acl::DENY
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
 * foreach ($roles as $role){
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
 *</code>
 */
class Memory extends Adapter
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
	protected noArgumentsDefaultAction = Acl::DENY;

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
	 * Roles Names
	 *
	 * @var mixed
	 */
	protected rolesNames;

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
	 * Phalcon\Acl\Adapter\Memory constructor
	 */
	public function __construct()
	{
		let this->componentsNames = ["*": true];
		let this->accessList = ["*!*": true];
	}

	/**
     * Do a role inherit from another existing role
     *
     * Example:
     * <code>
     *
     * $acl->addRole("administrator", "consultant");
     * $acl->addRole("administrator", ["consultant", "consultant2"]);
     * </code>
     *
     * @param  array|string         accessInherits
     * @param  RoleInterface|string|array role
     */
	public function addInherit(string roleName, var roleToInherits) -> bool
	{
		var roleInheritName, rolesNames, roleToInherit, checkRoleToInherit,
		 checkRoleToInherits, usedRoleToInherits, roleToInheritList, usedRoleToInherit;

		let rolesNames = this->rolesNames;
		if !isset rolesNames[roleName] {
			throw new Exception("Role '" . roleName . "' does not exist in the role list");
		}

		if !isset this->roleInherits[roleName] {
            let this->roleInherits[roleName] = [];
        }
		/**
		 * Type conversion
         */
        if typeof roleToInherits != "array" {
            let roleToInheritList = [roleToInherits];
        }else{
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
            if !isset rolesNames[roleInheritName] {
                throw new Exception("Role '" . roleInheritName . "' (to inherit) does not exist in the role list");
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
                    array_push(checkRoleToInherits,usedRoleToInherit);
                }
                let usedRoleToInherits = [];
                while !empty checkRoleToInherits {
                    let checkRoleToInherit = array_shift(checkRoleToInherits);
                    
                    if isset usedRoleToInherits[checkRoleToInherit] {
                        continue;
                    }
                    let usedRoleToInherits[checkRoleToInherit]=true;
                    if roleName == checkRoleToInherit {
                        throw new Exception("Role '" . roleInheritName . "' (to inherit) is infinite loop ");
                    }
                    /**
                     * Push inherited roles
                     */
                    if isset this->roleInherits[checkRoleToInherit] {
                        for usedRoleToInherit in this->roleInherits[checkRoleToInherit] {
                            array_push(checkRoleToInherits,usedRoleToInherit);
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
	 * Example:
	 * <code>
	 * $acl->addRole(
	 *     new Phalcon\Acl\Role("administrator"),
	 *     "consultant"
	 * );
	 *
	 * $acl->addRole("administrator", "consultant");
	 * $acl->addRole("administrator", ["consultant", "consultant2"]);
	 * </code>
	 *
	 * @param  array|string         accessInherits
	 * @param  RoleInterface|string|array role
	 */
	public function addRole(role, accessInherits = null) -> bool
	{
		var roleName, roleObject;

		if typeof role == "object" && role instanceof RoleInterface {
			let roleName = role->getName();
			let roleObject = role;
		} elseif is_string(role) {
			let roleName = role;
			let roleObject = new Role(role);
		} else {
			throw new Exception("Role must be either an string or implement RoleInterface");
		}

		if isset this->rolesNames[roleName] {
			return false;
		}

		let this->roles[] = roleObject;
		let this->rolesNames[roleName] = true;

		if accessInherits != null {
			return this->addInherit(roleName, accessInherits);
		}

		return true;
	}

	/**
	 * Adds a component to the ACL list
	 *
	 * Access names can be a particular action, by example
	 * search, update, delete, etc or a list of them
	 *
	 * Example:
	 * <code>
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
	 * </code>
	 *
	 * @param   Phalcon\Acl\Component|string componentValue
	 * @param   array|string accessList
	 */
	public function addComponent(var componentValue, var accessList) -> bool
	{
		var componentName, componentObject;

		if typeof componentValue == "object" && componentValue instanceof ComponentInterface {
			let componentName   = componentValue->getName();
			let componentObject = componentValue;
		 } else {
			let componentName   = componentValue;
			let componentObject = new Component(componentName);
		 }

		 if !isset this->componentsNames[componentName] {
			let this->components[] = componentObject;
			let this->componentsNames[componentName] = true;
		 }

		 return this->addComponentAccess(componentName, accessList);
	}

	/**
	 * Adds access to components
	 *
	 * @param array|string accessList
	 */
	public function addComponentAccess(string componentName, var accessList) -> bool
	{
		var accessName, accessKey, exists;

		if !isset this->componentsNames[componentName] {
			throw new Exception("Component '" . componentName . "' does not exist in ACL");
		}

		if typeof accessList != "array" && typeof accessList != "string" {
			throw new Exception("Invalid value for accessList");
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
	 * Allow access to a role on a component
	 *
	 * You can use '*' as wildcard
	 *
	 * Example:
	 * <code>
	 * //Allow access to guests to search on customers
	 * $acl->allow("guests", "customers", "search");
	 *
	 * //Allow access to guests to search or create on customers
	 * $acl->allow("guests", "customers", ["search", "create"]);
	 *
	 * //Allow access to any role to browse on products
	 * $acl->allow("*", "products", "browse");
	 *
	 * //Allow access to any role to browse on any component
	 * $acl->allow("*", "*", "browse");
	 * </code>
	 */
	public function allow(string roleName, string componentName, var access, var func = null) -> void
	{
		var innerRoleName;

		if roleName != "*" {
			this->allowOrDeny(roleName, componentName, access, Acl::ALLOW, func);
		} else {
			for innerRoleName, _ in this->rolesNames {
				this->allowOrDeny(innerRoleName, componentName, access, Acl::ALLOW, func);
			}
		}
	}

	/**
	 * Deny access to a role on a component
	 *
	 * You can use '*' as wildcard
	 *
	 * Example:
	 * <code>
	 * //Deny access to guests to search on customers
	 * $acl->deny("guests", "customers", "search");
	 *
	 * //Deny access to guests to search or create on customers
	 * $acl->deny("guests", "customers", ["search", "create"]);
	 *
	 * //Deny access to any role to browse on products
	 * $acl->deny("*", "products", "browse");
	 *
	 * //Deny access to any role to browse on any component
	 * $acl->deny("*", "*", "browse");
	 * </code>
	 */
	public function deny(string roleName, string componentName, var access, var func = null) -> void
	{
		var innerRoleName;

		if roleName != "*" {
			this->allowOrDeny(roleName, componentName, access, Acl::DENY, func);
		} else {
			for innerRoleName, _ in this->rolesNames {
				this->allowOrDeny(innerRoleName, componentName, access, Acl::DENY, func);
			}
		}
	}

	/**
	 * Removes an access from a component
	 *
	 * @param array|string accessList
	 */
	public function dropComponentAccess(string componentName, var accessList) -> void
	{
		var accessName, accessKey;

		if typeof accessList == "array" {
			for accessName in accessList {
				let accessKey = componentName . "!" . accessName;
				if isset this->accessList[accessKey] {
					unset this->accessList[accessKey];
				}
			}
		} else {
			if typeof accessList == "string" {
				let accessKey = componentName . "!" . accessName;
				if isset this->accessList[accessKey] {
					unset this->accessList[accessKey];
				}
			}
		}
	 }

	/**
	 * Returns the default ACL access level for no arguments provided in
	 * isAllowed action if there exists func for accessKey
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
	 * <code>
	 * //Does andres have access to the customers component to create?
	 * $acl->isAllowed("andres", "Products", "create");
	 *
	 * //Do guests have access to any component to edit?
	 * $acl->isAllowed("guests", "*", "edit");
	 * </code>
	 *
	 * @param  RoleInterface|RoleAware|string roleName
	 * @param  ComponentInterface|ComponentAware|string componentName
	 */
	public function isAllowed(var roleName, var componentName, string access, array parameters = null) -> bool
	{
		var eventsManager, accessList, accessKey,
			haveAccess = null, rolesNames,
			funcAccess = null, componentObject = null, roleObject = null, funcList,
			reflectionFunction, reflectionParameters, parameterNumber, parametersForFunction,
			numberOfRequiredParameters, userParametersSizeShouldBe, reflectionClass, parameterToCheck,
			reflectionParameter, hasRole = false, hasComponent = false;

		if typeof roleName == "object" {
			if roleName instanceof RoleAware {
				let roleObject = roleName;
				let roleName = roleObject->getRoleName();
			} elseif roleName instanceof RoleInterface {
				let roleName = roleName->getName();
			} else {
				throw new Exception("Object passed as roleName must implement Phalcon\\Acl\\RoleAware or Phalcon\\Acl\\RoleInterface");
			}
		}

		if typeof componentName == "object" {
			if componentName instanceof ComponentAware {
				let componentObject = componentName;
				let componentName = componentObject->getComponentName();
			} elseif componentName instanceof ComponentInterface {
				let componentName = componentName->getName();
			} else {
				throw new Exception("Object passed as componentName must implement Phalcon\\Acl\\ComponentAware or Phalcon\\Acl\\ComponentInterface");
			}
		}

		let this->activeRole = roleName;
		let this->activeComponent = componentName;
		let this->activeAccess = access;
		let this->activeKey = null;
        let this->activeFunction = null;
        let this->activeFunctionCustomArgumentsCount = 0;

		let accessList = this->access;
		let eventsManager = <EventsManager> this->eventsManager;
		let funcList = this->func;

		if typeof eventsManager == "object" {
			if eventsManager->fire("acl:beforeCheckAccess", this) === false {
				return false;
			}
		}

		/**
		 * Check if the role exists
		 */
		let rolesNames = this->rolesNames;
		if !isset rolesNames[roleName] {
			return (this->defaultAccess == Acl::ALLOW);
		}

		/**
		 * Check if there is a direct combination for role-component-access
		 */
		let accessKey = this->canAccess(roleName, componentName, access);

		if accessKey != false && isset accessList[accessKey] {
			let haveAccess = accessList[accessKey];
			fetch funcAccess, funcList[accessKey];
		}

		/**
		 * Check in the inherits roles
		 */
		let this->accessGranted = haveAccess;
		if typeof eventsManager == "object" {
			eventsManager->fire("acl:afterCheckAccess", this);
		}

		let this->activeKey = accessKey;
		let this->activeFunction = funcAccess;

		if haveAccess == null {
			/**
			 * Change activeKey to most narrow if there was no access for any patterns found
			 */
			let this->activeKey = roleName . "!" . componentName . "!" . access;

			return this->defaultAccess == Acl::ALLOW;
		}

		/**
		 * If we have funcAccess then do all the checks for it
		 */
		if is_callable(funcAccess) {
			let reflectionFunction = new \ReflectionFunction(funcAccess);
			let reflectionParameters = reflectionFunction->getParameters();
			let parameterNumber = count(reflectionParameters);

			// No parameters, just return haveAccess and call function without array
			if parameterNumber === 0 {
				return haveAccess == Acl::ALLOW && call_user_func(funcAccess);
			}

			let parametersForFunction = [];
			let numberOfRequiredParameters = reflectionFunction->getNumberOfRequiredParameters();
			let userParametersSizeShouldBe = parameterNumber;

			for reflectionParameter in reflectionParameters {
				let reflectionClass = reflectionParameter->getClass();
				let parameterToCheck = reflectionParameter->getName();

				if reflectionClass !== null {
					// roleObject is this class
					if roleObject !== null && reflectionClass->isInstance(roleObject) && !hasRole {
						let hasRole = true;
						let parametersForFunction[] = roleObject;
						let userParametersSizeShouldBe--;

						continue;
					}

					// componentObject is this class
					if componentObject !== null && reflectionClass->isInstance(componentObject) && !hasComponent {
						let hasComponent = true;
						let parametersForFunction[] = componentObject;
						let userParametersSizeShouldBe--;

						continue;
					}

					// This is some user defined class, check if his parameter is instance of it
					if isset parameters[parameterToCheck] && typeof parameters[parameterToCheck] == "object" && !reflectionClass->isInstance(parameters[parameterToCheck]) {
						throw new Exception(
							"Your passed parameter doesn't have the same class as the parameter in defined function when check " . roleName . " can " . access . " " . componentName . ". Class passed: " . get_class(parameters[parameterToCheck])." , Class in defined function: " . reflectionClass->getName() . "."
						);
					}
				}

				if isset parameters[parameterToCheck] {
					// We can't check type of ReflectionParameter in PHP 5.x so we just add it as it is
					let parametersForFunction[] = parameters[parameterToCheck];
				}
			}

			let this->activeFunctionCustomArgumentsCount = userParametersSizeShouldBe;

			if count(parameters) > userParametersSizeShouldBe {
				trigger_error(
					"Number of parameters in array is higher than the number of parameters in defined function when check " . roleName . " can " . access . " " . componentName . ". Remember that more parameters than defined in function will be ignored.",
					E_USER_WARNING
				);
			}

			// We dont have any parameters so check default action
			if count(parametersForFunction) == 0 {
				if numberOfRequiredParameters > 0 {
					trigger_error(
						"You didn't provide any parameters when '" . roleName .
						"' can '" . access . "' '"  . componentName .
						"'. We will use default action when no arguments."
					);

					return haveAccess == Acl::ALLOW && this->noArgumentsDefaultAction == Acl::ALLOW;
				}

				// Number of required parameters == 0 so call funcAccess without any arguments
				return haveAccess == Acl::ALLOW && call_user_func(funcAccess);
			}

			// Check necessary parameters
			if count(parametersForFunction) >= numberOfRequiredParameters {
				return haveAccess == Acl::ALLOW && call_user_func_array(funcAccess, parametersForFunction);
			}

			// We don't have enough parameters
			throw new Exception(
				"You didn't provide all necessary parameters for defined function when check " .
				roleName . " can " . access . " " . componentName
			);
		}

		return haveAccess == Acl::ALLOW;
	}

	/**
	 * Check whether role exist in the roles list
	 */
	public function isRole(string roleName) -> bool
	{
		return isset this->rolesNames[roleName];
	}

	/**
	 * Check whether component exist in the components list
	 */
	public function isComponent(string componentName) -> bool
	{
		return isset this->componentsNames[componentName];
	}

	/**
	 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
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

		if !isset this->rolesNames[roleName] {
			throw new Exception("Role '" . roleName . "' does not exist in ACL");
		}

		if !isset this->componentsNames[componentName] {
			throw new Exception("Component '" . componentName . "' does not exist in ACL");
		}

		let accessList = this->accessList;

		if typeof access == "array" {

			for accessName in access {
				let accessKey = componentName . "!" . accessName;
				if !isset accessList[accessKey] {
					throw new Exception("Access '" . accessName . "' does not exist in component '" . componentName . "'");
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
				if !isset accessList[accessKey] {
					throw new Exception("Access '" . access . "' does not exist in component '" . componentName . "'");
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
        var accessList, accessKey,checkRoleToInherit,
        	checkRoleToInherits, usedRoleToInherits,
        	usedRoleToInherit;

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
                array_push(checkRoleToInherits,usedRoleToInherit);
            }
            let usedRoleToInherits = [];
            while !empty checkRoleToInherits {
                let checkRoleToInherit = array_shift(checkRoleToInherits);

                if isset usedRoleToInherits[checkRoleToInherit] {
                    continue;
                }
                let usedRoleToInherits[checkRoleToInherit]=true;

                let accessKey = checkRoleToInherit . "!" . componentName . "!" . access;
                /**
                 * Check if there is a direct combination in one of the inherited roles
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
                        array_push(checkRoleToInherits,usedRoleToInherit);
                    }
                }
            }
        }
        return false;
    }
}
