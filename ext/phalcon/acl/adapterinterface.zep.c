
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Acl\AdapterInterface
 *
 * Interface for Phalcon\Acl adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Acl, AdapterInterface, phalcon, acl_adapterinterface, phalcon_acl_adapterinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, setDefaultAction);

/**
 * Returns the default ACL access level
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, getDefaultAction);

/**
 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
 * for no arguments provided in isAllowed action if there exists func for accessKey
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, setNoArgumentsDefaultAction);

/**
 * Returns the default ACL access level for no arguments provided in
 *isAllowed action if there exists func for accessKey
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, getNoArgumentsDefaultAction);

/**
 * Adds a operation to the ACL list. Second parameter lets to inherit access data from other existing operation
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, addOperation);

/**
 * Do a operation inherit from another existing operation
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, addInherit);

/**
 * Check whether operation exist in the operations list
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, isOperation);

/**
 * Check whether subject exist in the subjects list
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, isSubject);

/**
 * Adds a subject to the ACL list
 *
 * Access names can be a particular action, by example
 * search, update, delete, etc or a list of them
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, addSubject);

/**
 * Adds access to subjects
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, addSubjectAccess);

/**
 * Removes an access from a subject
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, dropSubjectAccess);

/**
 * Allow access to a operation on a subject
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, allow);

/**
 * Deny access to a operation on a subject
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, deny);

/**
 * Check whether a operation is allowed to access an action from a subject
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, isAllowed);

/**
 * Returns the operation which the list is checking if it's allowed to certain subject/access
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, getActiveOperation);

/**
 * Returns the subject which the list is checking if some operation can access it
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, getActiveSubject);

/**
 * Returns the access which the list is checking if some operation can access it
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, getActiveAccess);

/**
 * Return an array with every operation registered in the list
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, getOperations);

/**
 * Return an array with every subject registered in the list
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_AdapterInterface, getSubjects);

