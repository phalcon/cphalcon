
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
	 * Do a operation inherit from another existing operation
	 */
	public function addInherit(string operationName, operationToInherit) -> bool;

	/**
	 * Adds a operation to the ACL list. Second parameter lets to inherit access data from other existing operation
	 */
	public function addOperation(operation, accessInherits = null) -> bool;

	/**
	 * Adds a subject to the ACL list
	 *
	 * Access names can be a particular action, by example
	 * search, update, delete, etc or a list of them
	 */
	public function addSubject(subjectObject, accessList) -> bool;

	/**
	 * Adds access to subjects
	 */
	public function addSubjectAccess(string subjectName, accessList) -> void;

	/**
	 * Allow access to a operation on a subject
	 */
	public function allow(string operationName, string subjectName, access, func = null) -> void;

	/**
	 * Deny access to a operation on a subject
	 */
	public function deny(string operationName, string subjectName, access, func = null) -> void;

	/**
	 * Removes an access from a subject
	 */
	public function dropSubjectAccess(string subjectName, accessList) -> void;

	/**
	 * Returns the access which the list is checking if some operation can access it
	 */
	public function getActiveAccess() -> string;

	/**
	 * Returns the operation which the list is checking if it's allowed to certain subject/access
	 */
	public function getActiveOperation() -> string;

	/**
	 * Returns the subject which the list is checking if some operation can access it
	 */
	public function getActiveSubject() -> string;

	/**
	 * Returns the default ACL access level
	 */
	public function getDefaultAction() -> int;

	/**
	 * Returns the default ACL access level for no arguments provided in
	  *isAllowed action if there exists func for accessKey
	 */
	public function getNoArgumentsDefaultAction() -> int;

	/**
	 * Return an array with every operation registered in the list
	 */
	public function getOperations() -> <OperationInterface[]>;

	/**
	 * Return an array with every subject registered in the list
	 */
	public function getSubjects() -> <SubjectInterface[]>;

	/**
	 * Check whether a operation is allowed to access an action from a subject
	 */
	public function isAllowed(operationName, subjectName, string access, array parameters = null) -> bool;

	/**
	 * Check whether subject exist in the subjects list
	 */
	public function isSubject(string subjectName) -> bool;

	/**
	 * Check whether operation exist in the operations list
	 */
	public function isOperation(string operationName) -> bool;


	/**
	 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
	 */
	public function setDefaultAction(int defaultAccess) -> void;

	/**
	 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
	 * for no arguments provided in isAllowed action if there exists func for accessKey
	 */
	public function setNoArgumentsDefaultAction(int defaultAccess) -> void;
}
