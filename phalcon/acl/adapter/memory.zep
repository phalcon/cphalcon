
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
use Phalcon\Acl\Operation;
use Phalcon\Acl\OperationInterface;
use Phalcon\Acl\Subject;
use Phalcon\Acl\Exception;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Acl\OperationAware;
use Phalcon\Acl\SubjectAware;
use Phalcon\Acl\OperationInterface;
use Phalcon\Acl\SubjectInterface;

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
 * // Register operations
 * $operations = [
 *     "users"  => new \Phalcon\Acl\Operation("Users"),
 *     "guests" => new \Phalcon\Acl\Operation("Guests"),
 * ];
 * foreach ($operations as $operation) {
 *     $acl->addOperation($operation);
 * }
 *
 * // Private area subjects
 * $privateSubjects = [
 *     "companies" => ["index", "search", "new", "edit", "save", "create", "delete"],
 *     "products"  => ["index", "search", "new", "edit", "save", "create", "delete"],
 *     "invoices"  => ["index", "profile"],
 * ];
 *
 * foreach ($privateSubjects as $subjectName => $actions) {
 *     $acl->addSubject(
 *         new \Phalcon\Acl\Subject($subjectName),
 *         $actions
 *     );
 * }
 *
 * // Public area subjects
 * $publicSubjects = [
 *     "index"   => ["index"],
 *     "about"   => ["index"],
 *     "session" => ["index", "register", "start", "end"],
 *     "contact" => ["index", "send"],
 * ];
 *
 * foreach ($publicSubjects as $subjectName => $actions) {
 *     $acl->addSubject(
 *         new \Phalcon\Acl\Subject($subjectName),
 *         $actions
 *     );
 * }
 *
 * // Grant access to public areas to both users and guests
 * foreach ($operations as $operation){
 *     foreach ($publicSubjects as $subject => $actions) {
 *         $acl->allow($operation->getName(), $subject, "*");
 *     }
 * }
 *
 * // Grant access to private area to operation Users
 * foreach ($privateSubjects as $subject => $actions) {
 *     foreach ($actions as $action) {
 *         $acl->allow("Users", $subject, $action);
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
	 * Operations
	 *
	 * @var mixed
	 */
	protected operations;

	/**
	 * Operation Inherits
	 *
	 * @var mixed
	 */
	protected operationInherits;

	/**
	 * Operations Names
	 *
	 * @var mixed
	 */
	protected operationsNames;

	/**
	 * Subjects
	 *
	 * @var mixed
	 */
	protected subjects;

	/**
	 * Subject Names
	 *
	 * @var mixed
	 */
	protected subjectsNames;

	/**
	 * Phalcon\Acl\Adapter\Memory constructor
	 */
	public function __construct()
	{
		let this->subjectsNames = ["*": true];
		let this->accessList = ["*!*": true];
	}

	/**
     * Do a operation inherit from another existing operation
     *
     * Example:
     * <code>
     *
     * $acl->addOperation("administrator", "consultant");
     * $acl->addOperation("administrator", ["consultant", "consultant2"]);
     * </code>
     *
     * @param  array|string         accessInherits
     * @param  OperationInterface|string|array operation
     */
	public function addInherit(string operationName, var operationToInherits) -> bool
	{
		var operationInheritName, operationsNames, operationToInherit, checkOperationToInherit,
		 checkOperationToInherits, usedOperationToInherits, operationToInheritList, usedOperationToInherit;

		let operationsNames = this->operationsNames;
		if !isset operationsNames[operationName] {
			throw new Exception("Operation '" . operationName . "' does not exist in the operation list");
		}

		if !isset this->operationInherits[operationName] {
            let this->operationInherits[operationName] = [];
        }
		/**
		 * Type conversion
         */
        if typeof operationToInherits != "array" {
            let operationToInheritList = [operationToInherits];
        }else{
            let operationToInheritList = operationToInherits;
        }
        /**
         * inherits
         */
        for operationToInherit in operationToInheritList {
            if typeof operationToInherit == "object" && operationToInherit instanceof OperationInterface {
                let operationInheritName = operationToInherit->getName();
            } else {
                let operationInheritName = operationToInherit;
            }
            /**
             * Check if the operation to inherit is repeat
             */
            if in_array(operationInheritName, this->operationInherits[operationName]) {
                continue;
            }
            /**
             * Check if the operation to inherit is valid
             */
            if !isset operationsNames[operationInheritName] {
                throw new Exception("Operation '" . operationInheritName . "' (to inherit) does not exist in the operation list");
            }

            if operationName == operationInheritName {
                return false;
            }
            /**
             * Deep check if the operation to inherit is valid
             */
            if isset this->operationInherits[operationInheritName] {
                let checkOperationToInherits = [];
                for usedOperationToInherit in this->operationInherits[operationInheritName] {
                    array_push(checkOperationToInherits,usedOperationToInherit);
                }
                let usedOperationToInherits = [];
                while !empty checkOperationToInherits {
                    let checkOperationToInherit = array_shift(checkOperationToInherits);
                    
                    if isset usedOperationToInherits[checkOperationToInherit] {
                        continue;
                    }
                    let usedOperationToInherits[checkOperationToInherit]=true;
                    if operationName == checkOperationToInherit {
                        throw new Exception("Operation '" . operationInheritName . "' (to inherit) is infinite loop ");
                    }
                    /**
                     * Push inherited operations
                     */
                    if isset this->operationInherits[checkOperationToInherit] {
                        for usedOperationToInherit in this->operationInherits[checkOperationToInherit] {
                            array_push(checkOperationToInherits,usedOperationToInherit);
                        }
                    }
                }
            }

            let this->operationInherits[operationName][] = operationInheritName;
        }
		return true;
	}

	/**
	 * Adds a operation to the ACL list. Second parameter allows inheriting access data from other existing operation
	 *
	 * Example:
	 * <code>
	 * $acl->addOperation(
	 *     new Phalcon\Acl\Operation("administrator"),
	 *     "consultant"
	 * );
	 *
	 * $acl->addOperation("administrator", "consultant");
	 * $acl->addOperation("administrator", ["consultant", "consultant2"]);
	 * </code>
	 *
	 * @param  array|string         accessInherits
	 * @param  OperationInterface|string|array operation
	 */
	public function addOperation(operation, accessInherits = null) -> bool
	{
		var operationName, operationObject;

		if typeof operation == "object" && operation instanceof OperationInterface {
			let operationName = operation->getName();
			let operationObject = operation;
		} elseif is_string(operation) {
			let operationName = operation;
			let operationObject = new Operation(operation);
		} else {
			throw new Exception("Operation must be either an string or implement OperationInterface");
		}

		if isset this->operationsNames[operationName] {
			return false;
		}

		let this->operations[] = operationObject;
		let this->operationsNames[operationName] = true;

		if accessInherits != null {
			return this->addInherit(operationName, accessInherits);
		}

		return true;
	}

	/**
	 * Adds a subject to the ACL list
	 *
	 * Access names can be a particular action, by example
	 * search, update, delete, etc or a list of them
	 *
	 * Example:
	 * <code>
	 * // Add a subject to the the list allowing access to an action
	 * $acl->addSubject(
	 *     new Phalcon\Acl\Subject("customers"),
	 *     "search"
	 * );
	 *
	 * $acl->addSubject("customers", "search");
	 *
	 * // Add a subject  with an access list
	 * $acl->addSubject(
	 *     new Phalcon\Acl\Subject("customers"),
	 *     [
	 *         "create",
	 *         "search",
	 *     ]
	 * );
	 *
	 * $acl->addSubject(
	 *     "customers",
	 *     [
	 *         "create",
	 *         "search",
	 *     ]
	 * );
	 * </code>
	 *
	 * @param   Phalcon\Acl\Subject|string subjectValue
	 * @param   array|string accessList
	 */
	public function addSubject(var subjectValue, var accessList) -> bool
	{
		var subjectName, subjectObject;

		if typeof subjectValue == "object" && subjectValue instanceof SubjectInterface {
			let subjectName   = subjectValue->getName();
			let subjectObject = subjectValue;
		 } else {
			let subjectName   = subjectValue;
			let subjectObject = new Subject(subjectName);
		 }

		 if !isset this->subjectsNames[subjectName] {
			let this->subjects[] = subjectObject;
			let this->subjectsNames[subjectName] = true;
		 }

		 return this->addSubjectAccess(subjectName, accessList);
	}

	/**
	 * Adds access to subjects
	 *
	 * @param array|string accessList
	 */
	public function addSubjectAccess(string subjectName, var accessList) -> bool
	{
		var accessName, accessKey, exists;

		if !isset this->subjectsNames[subjectName] {
			throw new Exception("Subject '" . subjectName . "' does not exist in ACL");
		}

		if typeof accessList != "array" && typeof accessList != "string" {
			throw new Exception("Invalid value for accessList");
		}

		let exists = true;
		if typeof accessList == "array" {
			for accessName in accessList {
				let accessKey = subjectName . "!" . accessName;
				if !isset this->accessList[accessKey] {
					let this->accessList[accessKey] = exists;
				}
			}
		} else {
			let accessKey = subjectName . "!" . accessList;
			if !isset this->accessList[accessKey] {
				let this->accessList[accessKey] = exists;
			}
		}

		return true;
	}

	/**
	 * Allow access to a operation on a subject
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
	 * //Allow access to any operation to browse on products
	 * $acl->allow("*", "products", "browse");
	 *
	 * //Allow access to any operation to browse on any subject
	 * $acl->allow("*", "*", "browse");
	 * </code>
	 */
	public function allow(string operationName, string subjectName, var access, var func = null) -> void
	{
		var innerOperationName;

		if operationName != "*" {
			this->allowOrDeny(operationName, subjectName, access, Acl::ALLOW, func);
		} else {
			for innerOperationName, _ in this->operationsNames {
				this->allowOrDeny(innerOperationName, subjectName, access, Acl::ALLOW, func);
			}
		}
	}

	/**
	 * Deny access to a operation on a subject
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
	 * //Deny access to any operation to browse on products
	 * $acl->deny("*", "products", "browse");
	 *
	 * //Deny access to any operation to browse on any subject
	 * $acl->deny("*", "*", "browse");
	 * </code>
	 */
	public function deny(string operationName, string subjectName, var access, var func = null) -> void
	{
		var innerOperationName;

		if operationName != "*" {
			this->allowOrDeny(operationName, subjectName, access, Acl::DENY, func);
		} else {
			for innerOperationName, _ in this->operationsNames {
				this->allowOrDeny(innerOperationName, subjectName, access, Acl::DENY, func);
			}
		}
	}

	/**
	 * Removes an access from a subject
	 *
	 * @param array|string accessList
	 */
	public function dropSubjectAccess(string subjectName, var accessList) -> void
	{
		var accessName, accessKey;

		if typeof accessList == "array" {
			for accessName in accessList {
				let accessKey = subjectName . "!" . accessName;
				if isset this->accessList[accessKey] {
					unset this->accessList[accessKey];
				}
			}
		} else {
			if typeof accessList == "string" {
				let accessKey = subjectName . "!" . accessName;
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
	 * Return an array with every operation registered in the list
	 */
	public function getOperations() -> <OperationInterface[]>
	{
		return this->operations;
	}

	/**
	 * Return an array with every subject registered in the list
	 */
	public function getSubjects() -> <SubjectInterface[]>
	{
		return this->subjects;
	}
	
	/**
	 * Check whether a operation is allowed to access an action from a subject
	 *
	 * <code>
	 * //Does andres have access to the customers subject to create?
	 * $acl->isAllowed("andres", "Products", "create");
	 *
	 * //Do guests have access to any subject to edit?
	 * $acl->isAllowed("guests", "*", "edit");
	 * </code>
	 *
	 * @param  OperationInterface|OperationAware|string operationName
	 * @param  SubjectInterface|SubjectAware|string subjectName
	 */
	public function isAllowed(var operationName, var subjectName, string access, array parameters = null) -> bool
	{
		var eventsManager, accessList, accessKey,
			haveAccess = null, operationsNames,
			funcAccess = null, subjectObject = null, operationObject = null, funcList,
			reflectionFunction, reflectionParameters, parameterNumber, parametersForFunction,
			numberOfRequiredParameters, userParametersSizeShouldBe, reflectionClass, parameterToCheck,
			reflectionParameter, hasOperation = false, hasSubject = false;

		if typeof operationName == "object" {
			if operationName instanceof OperationAware {
				let operationObject = operationName;
				let operationName = operationObject->getOperationName();
			} elseif operationName instanceof OperationInterface {
				let operationName = operationName->getName();
			} else {
				throw new Exception("Object passed as operationName must implement Phalcon\\Acl\\OperationAware or Phalcon\\Acl\\OperationInterface");
			}
		}

		if typeof subjectName == "object" {
			if subjectName instanceof SubjectAware {
				let subjectObject = subjectName;
				let subjectName = subjectObject->getSubjectName();
			} elseif subjectName instanceof SubjectInterface {
				let subjectName = subjectName->getName();
			} else {
				throw new Exception("Object passed as subjectName must implement Phalcon\\Acl\\SubjectAware or Phalcon\\Acl\\SubjectInterface");
			}
		}

		let this->activeOperation = operationName;
		let this->activeSubject = subjectName;
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
		 * Check if the operation exists
		 */
		let operationsNames = this->operationsNames;
		if !isset operationsNames[operationName] {
			return (this->defaultAccess == Acl::ALLOW);
		}

		/**
		 * Check if there is a direct combination for operation-subject-access
		 */
		let accessKey = this->canAccess(operationName, subjectName, access);

		if accessKey != false && isset accessList[accessKey] {
			let haveAccess = accessList[accessKey];
			fetch funcAccess, funcList[accessKey];
		}

		/**
		 * Check in the inherits operations
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
			let this->activeKey = operationName . "!" . subjectName . "!" . access;

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
					// operationObject is this class
					if operationObject !== null && reflectionClass->isInstance(operationObject) && !hasOperation {
						let hasOperation = true;
						let parametersForFunction[] = operationObject;
						let userParametersSizeShouldBe--;

						continue;
					}

					// subjectObject is this class
					if subjectObject !== null && reflectionClass->isInstance(subjectObject) && !hasSubject {
						let hasSubject = true;
						let parametersForFunction[] = subjectObject;
						let userParametersSizeShouldBe--;

						continue;
					}

					// This is some user defined class, check if his parameter is instance of it
					if isset parameters[parameterToCheck] && typeof parameters[parameterToCheck] == "object" && !reflectionClass->isInstance(parameters[parameterToCheck]) {
						throw new Exception(
							"Your passed parameter doesn't have the same class as the parameter in defined function when check " . operationName . " can " . access . " " . subjectName . ". Class passed: " . get_class(parameters[parameterToCheck])." , Class in defined function: " . reflectionClass->getName() . "."
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
					"Number of parameters in array is higher than the number of parameters in defined function when check " . operationName . " can " . access . " " . subjectName . ". Remember that more parameters than defined in function will be ignored.",
					E_USER_WARNING
				);
			}

			// We dont have any parameters so check default action
			if count(parametersForFunction) == 0 {
				if numberOfRequiredParameters > 0 {
					trigger_error(
						"You didn't provide any parameters when '" . operationName .
						"' can '" . access . "' '"  . subjectName .
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
				operationName . " can " . access . " " . subjectName
			);
		}

		return haveAccess == Acl::ALLOW;
	}

	/**
	 * Check whether operation exist in the operations list
	 */
	public function isOperation(string operationName) -> bool
	{
		return isset this->operationsNames[operationName];
	}

	/**
	 * Check whether subject exist in the subjects list
	 */
	public function isSubject(string subjectName) -> bool
	{
		return isset this->subjectsNames[subjectName];
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
	 * Checks if a operation has access to a subject
	 */
	private function allowOrDeny(string operationName, string subjectName, var access, var action, var func = null) -> void
	{
		var accessList, accessName, accessKey;

		if !isset this->operationsNames[operationName] {
			throw new Exception("Operation '" . operationName . "' does not exist in ACL");
		}

		if !isset this->subjectsNames[subjectName] {
			throw new Exception("Subject '" . subjectName . "' does not exist in ACL");
		}

		let accessList = this->accessList;

		if typeof access == "array" {

			for accessName in access {
				let accessKey = subjectName . "!" . accessName;
				if !isset accessList[accessKey] {
					throw new Exception("Access '" . accessName . "' does not exist in subject '" . subjectName . "'");
				}
			}

			for accessName in access {

				let accessKey = operationName . "!" .subjectName . "!" . accessName;
				let this->access[accessKey] = action;
				if func != null {
				    let this->func[accessKey] = func;
				}
			}

		} else {

			if access != "*" {
				let accessKey = subjectName . "!" . access;
				if !isset accessList[accessKey] {
					throw new Exception("Access '" . access . "' does not exist in subject '" . subjectName . "'");
				}
			}

			let accessKey = operationName . "!" . subjectName . "!" . access;

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
	 * Check whether a operation is allowed to access an action from a subject
	 */
	private function canAccess(string operationName, string subjectName, string access) -> string | bool
    {
        var accessList, accessKey,checkOperationToInherit,
        	checkOperationToInherits, usedOperationToInherits,
        	usedOperationToInherit;

		let accessList = this->access;

        let accessKey = operationName . "!" . subjectName . "!" . access;

		/**
		 * Check if there is a direct combination for operation-subject-access
		 */
		if isset accessList[accessKey] {
			return accessKey;
		}
		/**
         * Check if there is a direct combination for operation-*-*
         */
        let accessKey = operationName . "!" . subjectName . "!*";
        if isset accessList[accessKey] {
            return accessKey;
        }
        /**
         * Check if there is a direct combination for operation-*-*
         */
        let accessKey = operationName . "!*!*";
        if isset accessList[accessKey] {
            return accessKey;
        }
        /**
         * Deep check if the operation to inherit is valid
         */
        if isset this->operationInherits[operationName] {
            let checkOperationToInherits = [];
            for usedOperationToInherit in this->operationInherits[operationName] {
                array_push(checkOperationToInherits,usedOperationToInherit);
            }
            let usedOperationToInherits = [];
            while !empty checkOperationToInherits {
                let checkOperationToInherit = array_shift(checkOperationToInherits);

                if isset usedOperationToInherits[checkOperationToInherit] {
                    continue;
                }
                let usedOperationToInherits[checkOperationToInherit]=true;

                let accessKey = checkOperationToInherit . "!" . subjectName . "!" . access;
                /**
                 * Check if there is a direct combination in one of the inherited operations
                 */
                if isset accessList[accessKey] {
                    return accessKey;
                }
                /**
                 * Check if there is a direct combination for operation-*-*
                 */
                let accessKey = checkOperationToInherit . "!" . subjectName . "!*";
                if isset accessList[accessKey] {
                    return accessKey;
                }
                /**
                 * Check if there is a direct combination for operation-*-*
                 */
                let accessKey = checkOperationToInherit . "!*!*";
                if isset accessList[accessKey] {
                    return accessKey;
                }
                /**
                 * Push inherited operations
                 */
                if isset this->operationInherits[checkOperationToInherit] {
                    for usedOperationToInherit in this->operationInherits[checkOperationToInherit] {
                        array_push(checkOperationToInherits,usedOperationToInherit);
                    }
                }
            }
        }
        return false;
    }
}
